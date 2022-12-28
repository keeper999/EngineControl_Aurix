/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* !LINKSTO Base.ModuleInfo.HeaderFile,1 */

#if (!defined BASE_MODULES_H)
#define BASE_MODULES_H



/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/


/** \brief Enable status of the module PduR */
#define BASE_PDUR_ENABLED  STD_ON
#ifndef BASE_PDUR_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * PduR */
#define BASE_PDUR_CONFIG_PTR (&PduRRoutingTables)
#endif

/** \brief Enable status of the module Icu */
#define BASE_ICU_ENABLED  STD_ON
#ifndef BASE_ICU_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Icu */
#define BASE_ICU_CONFIG_PTR (&IcuConfigSet_0)
#endif

/** \brief Enable status of the module Spi */
#define BASE_SPI_ENABLED  STD_ON
#ifndef BASE_SPI_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Spi */
#define BASE_SPI_CONFIG_PTR (&SpiDriver_0)
#endif

/** \brief Enable status of the module Port */
#define BASE_PORT_ENABLED  STD_ON
#ifndef BASE_PORT_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Port */
#define BASE_PORT_CONFIG_PTR (&PortConfigSet_0)
#endif

/** \brief Enable status of the module Pwm */
#define BASE_PWM_ENABLED  STD_ON
#ifndef BASE_PWM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Pwm */
#define BASE_PWM_CONFIG_PTR (&PwmChannelConfigSet_0)
#endif

/** \brief Enable status of the module Can */
#define BASE_CAN_ENABLED  STD_ON
#ifndef BASE_CAN_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Can */
#define BASE_CAN_CONFIG_PTR (&CanConfigSet_0)
#endif

/** \brief Enable status of the module CanIf */
#define BASE_CANIF_ENABLED  STD_ON
#ifndef BASE_CANIF_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * CanIf */
#define BASE_CANIF_CONFIG_PTR (&CanIfInitCfg)
#endif

/** \brief Enable status of the module LinIf */
#define BASE_LINIF_ENABLED  STD_ON
#ifndef BASE_LINIF_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * LinIf */
#define BASE_LINIF_CONFIG_PTR (&LinIfGlobalConfig)
#endif

/** \brief Enable status of the module Com */
#define BASE_COM_ENABLED  STD_ON
#ifndef BASE_COM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Com */
#define BASE_COM_CONFIG_PTR (&ComConfig)
#endif

/** \brief Enable status of the module Mcu */
#define BASE_MCU_ENABLED  STD_ON
#ifndef BASE_MCU_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Mcu */
#define BASE_MCU_CONFIG_PTR (&McuModuleConfiguration_0)
#endif

/** \brief Enable status of the module Dio */
#define BASE_DIO_ENABLED  STD_ON
#ifndef BASE_DIO_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Dio */
#define BASE_DIO_CONFIG_PTR (&DioConfig_0)
#endif

/** \brief Enable status of the module CanTp */
#define BASE_CANTP_ENABLED  STD_ON

/** \brief Enable status of the module Msc */
#define BASE_MSC_ENABLED  STD_ON
#ifndef BASE_MSC_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Msc */
#define BASE_MSC_CONFIG_PTR (&MscConfigSet_0)
#endif

/** \brief Enable status of the module ComM */
#define BASE_COMM_ENABLED  STD_ON
#ifndef BASE_COMM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * ComM */
#define BASE_COMM_CONFIG_PTR (&ComMConfigSet)
#endif

/** \brief Enable status of the module NvM */
#define BASE_NVM_ENABLED  STD_ON

/** \brief Enable status of the module EcuC */
#define BASE_ECUC_ENABLED  STD_ON

/** \brief Enable status of the module Fee */
#define BASE_FEE_ENABLED  STD_ON

/** \brief Enable status of the module CanSM */
#define BASE_CANSM_ENABLED  STD_ON
#ifndef BASE_CANSM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * CanSM */
#define BASE_CANSM_CONFIG_PTR (&CanSMConfiguration)
#endif

/** \brief Enable status of the module Gpt */
#define BASE_GPT_ENABLED  STD_ON
#ifndef BASE_GPT_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Gpt */
#define BASE_GPT_CONFIG_PTR (&GptChannelConfigSet_0)
#endif

/** \brief Enable status of the module EcuM */
#define BASE_ECUM_ENABLED  STD_ON
#ifndef BASE_ECUM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * EcuM */
#define BASE_ECUM_CONFIG_PTR (&EcuMConfiguration_0)
#endif

/** \brief Enable status of the module Fls */
#define BASE_FLS_ENABLED  STD_ON
#ifndef BASE_FLS_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Fls */
#define BASE_FLS_CONFIG_PTR (&FlsConfigSet_0)
#endif

/** \brief Enable status of the module Wdg */
#define BASE_WDG_ENABLED  STD_ON
#ifndef BASE_WDG_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Wdg */
#define BASE_WDG_CONFIG_PTR (&WdgSettingsConfig_0)
#endif

/** \brief Enable status of the module MemIf */
#define BASE_MEMIF_ENABLED  STD_ON

/** \brief Enable status of the module Crc */
#define BASE_CRC_ENABLED  STD_ON

/** \brief Enable status of the module Lin */
#define BASE_LIN_ENABLED  STD_ON
#ifndef BASE_LIN_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Lin */
#define BASE_LIN_CONFIG_PTR (&LinGlobalConfig_0)
#endif

/** \brief Enable status of the module LinSM */
#define BASE_LINSM_ENABLED  STD_ON
#ifndef BASE_LINSM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * LinSM */
#define BASE_LINSM_CONFIG_PTR (&LinSMConfigSet)
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( BASE_MODULES_H ) */
/*==================[end of file]============================================*/
