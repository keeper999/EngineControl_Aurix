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
**   $FILENAME   : Dio_PBCfg.c $                                              **
**                                                                            **
**   $CC VERSION : \main\23 $                                                 **
**                                                                            **
**   DATE, TIME  : 2014-09-29, 11:35:27                                       **
**                                                                            **
**   GENERATOR   : Build b131017-0205                                         **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : DIO configuration generated out of ECU configuration       **
**                  file                                                      **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                             Includes                                       **
*******************************************************************************/

/* Include Port Module File */
#include "Dio.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*
  Information on MISRA-2004 violations:
  - MISRA Rule 19.1: Only preprocessor statements and comments before 
    '#include'Inclusion of the file MemMap.h is done for memory mapping of 
    the code and data. This is violation of MISRA Rule 19.1, but cannot 
    be avoided.
*/

/* Memory mapping of the DIO configuration */
#define DIO_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/*
      Configuration of DIO Channel groups 
      DioConfig 1
*/
/* No Groups are configured */

static const Dio_PortChannelIdType Dio_kPortChannelConfig_0[] =
{
  { /* Port0 */
     DIO_PORT_CONFIGURED,
     (0x17ffU)
  },
  { /* Port1 */
     DIO_PORT_CONFIGURED,
     (0x00f8U)
  },
  { /* Port2 */
     DIO_PORT_CONFIGURED,
     (0x0d9dU)
  },
  { /* Port10 */
     DIO_PORT_CONFIGURED,
     (0x0090U)
  },
  { /* Port11 */
     DIO_PORT_CONFIGURED,
     (0x01b2U)
  },
  { /* Port12 */
     DIO_PORT_CONFIGURED,
     (0x0003U)
  },
  { /* Port13 */
     DIO_PORT_CONFIGURED,
     (0x0000U)
  },
  { /* Port14 */
     DIO_PORT_CONFIGURED,
     (0x0000U)
  },
  { /* Port15 */
     DIO_PORT_CONFIGURED,
     (0x0100U)
  },
  { /* Port20 */
     DIO_PORT_CONFIGURED,
     (0x4000U)
  },
  { /* Port21 */
     DIO_PORT_CONFIGURED,
     (0x0000U)
  },
  { /* Port22 */
     DIO_PORT_CONFIGURED,
     (0x0682U)
  },
  { /* Port23 */
     DIO_PORT_CONFIGURED,
     (0x00cdU)
  },
  { /* Port32 */
     DIO_PORT_CONFIGURED,
     (0x0080U)
  },
  { /* Port33 */
     DIO_PORT_CONFIGURED,
     (0xcabbU)
  },
  { /* Port34 */
     DIO_PORT_CONFIGURED,
     (0x001eU)
  },
  { /* Port40 */
     DIO_PORT_CONFIGURED,
     (0x0000U)
  }
};


const Dio_ConfigType Dio_ConfigRoot[1] =
{
  {
    /* Dio Port and Channelconfiguration set 0 */
    &Dio_kPortChannelConfig_0[0],
    /* Dio Channelgroup configuration set 0 */
    NULL_PTR,
    /* Configured number of Dio Channelgroups for configuration set 0 */
    DIO_CHANNELGROUPCOUNT_0
  }
};

#define DIO_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
