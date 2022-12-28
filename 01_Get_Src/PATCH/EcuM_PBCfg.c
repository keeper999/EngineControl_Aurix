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
**   $FILENAME   : EcuM_PBCfg.c $                                             **
**                                                                            **
**   $CC VERSION : \main\38 $                                                 **
**                                                                            **
**   DATE, TIME: 2014-08-19, 15:41:11                                         **
**                                                                            **
**   GENERATOR : Build b120625-0327                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : EcuM configuration generated from ECU configuration file  **
**                                                                            **
**   SPECIFICATION(S) : AUTOSAR_SWS_ECU_StateManager.pdf, AS4.0               **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"

#include "Mcu.h"

#ifdef ECUM_USES_GPT
#include "Gpt.h"
#endif
#ifdef ECUM_USES_PORT
#include "Port.h"
#endif
#ifdef ECUM_USES_DIO
#include "Dio.h"
#endif
#ifdef ECUM_USES_DMA
#include "Dma.h"
#endif
#ifdef ECUM_USES_SPI
#include "Spi.h"
#endif
#ifdef ECUM_USES_ADC
#include "Adc.h"
#endif
#ifdef ECUM_USES_FLS
#include "Fls_17_Pmu.h"
#endif
#ifdef ECUM_USES_FEE
#include "Fee.h"
#endif
#ifdef ECUM_USES_CAN
#include "Can_17_MCanP.h"
#endif
#ifdef ECUM_USES_PWM
#include "Pwm_17_Gtm.h"
#endif
#ifdef ECUM_USES_FADC
#include "Fadc.h"
#endif
#ifdef ECUM_USES_ICU
#include "Icu_17_GtmCcu6.h"
#endif
#ifdef ECUM_USES_WDG
#include "Wdg_17_Scu.h"
#endif
#ifdef ECUM_USES_MLI
#include "Mli.h"
#endif
#ifdef ECUM_USES_SCI
#include "Sci.h"
#endif
#ifdef ECUM_USES_MCHK
#include "Mchk.h"
#endif
#ifdef ECUM_USES_MSC
#include "Msc.h"
#endif
#ifdef ECUM_USES_FR_17_ERAY
#include "Fr_17_Eray.h"
#endif
#ifdef ECUM_USES_LIN
#include "Lin_17_AscLin.h"
#endif
#ifdef ECUM_USES_UART
#include "Uart.h"
#endif
#ifdef ECUM_USES_ETH
#include "Eth_17_EthMac.h"
#endif
#ifdef ECUM_USES_CRC
#include "Crc_.h"
#endif
#ifdef ECUM_USES_RAMTST
#include "RamTst_Api.h"
#endif
#ifdef ECUM_USES_CANTRCV_17_6250GV33
#include "CanTrcv_17_6250GV33.h"
#endif
#ifdef ECUM_USES_CANTRCV_17_6251G
#include "CanTrcv_17_6251G.h"
#endif
#ifdef ECUM_USES_FLSLOADER
#include "FlsLoader.h"
#endif
#ifdef ECUM_USES_SENT
#include "Sent.h"
#endif
#ifdef ECUM_USES_IOM
#include "Iom.h"
#endif
#ifdef ECUM_USES_HSSL
#include "Hssl.h"
#endif
#ifdef ECUM_USES_DSADC
#include "Dsadc.h"
#endif
#ifdef ECUM_USES_SMU
#include "Smu.h"
#endif
#ifdef ECUM_USES_I2C
#include "I2c.h"
#endif
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
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_POSTBUILDCFG
#include "MemMap.h"


const EcuM_ConfigType EcuM_ConfigAlternative[] = 
{
  {
    /* Identifier of post-build time configuration */
    0,
    /* Hash Identifier of pre compile time configuration */
    0xffffffff,

    &Mcu_ConfigRoot[0],
    &Port_ConfigRoot[0],
    &Dio_ConfigRoot[0],
    &Icu_ConfigRoot[0],

    &Pwm_ConfigRoot[0],

    &Gpt_ConfigRoot[0],
    &Spi_ConfigRoot[0],
    &Msc_ConfigRoot[0],
    &Wdg_ConfigRoot[0],

    0xFF                  /* EcuM Internal Data */
  }
};




#define ECUM_STOP_SEC_POSTBUILDCFG
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
