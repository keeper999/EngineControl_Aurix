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
**  $FILENAME   : Can_17_MCanP_Cfg.h $                                       **
**                                                                            **
**  $CC VERSION : \main\18 $                                                 **
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
**                   file (Can_17_MCanP.bmd)                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_AS_CAN047,
                   DS_NAS_PR446,DS_AS403_PR2849]                              **
**                                                                            **
**  [/cover]                                                                 **/


#ifndef CAN_17_MCANP_CFG_H
#define CAN_17_MCANP_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

/* Autosar specification version */

#define CAN_17_MCANP_AS_VERSION (403)
#define CAN_17_MCANP_AR_RELEASE_MAJOR_VERSION  (4U)
#define CAN_17_MCANP_AR_RELEASE_MINOR_VERSION  (0U)
#define CAN_17_MCANP_AR_RELEASE_REVISION_VERSION  (3U)

/* Vendor specific implementation version information */
#define CAN_17_MCANP_SW_MAJOR_VERSION  (2U)
#define CAN_17_MCANP_SW_MINOR_VERSION  (2U)
#define CAN_17_MCANP_SW_PATCH_VERSION  (2U)


/*******************************************************************************
**                     Configuration options                                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* CAN ModuleR is available. i.e Additional 2 nodes/128 message objects are present */	
#define CAN_MOD_R_AVAILABLE

/* Number of Kernels avaialble in the device */
#define CAN_NUM_KERNELS_IN_DEVICE  (2U)

/* Number of CAN Controllers available in the device */
#define CAN_NUM_CONTROLLERS_IN_DEVICE  (6U)

/* Maximum number of CAN Controllers configured in a ConfigSet */
#define CAN_NUM_CONTROLLER_MAX         (4U)

/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_TX_HARDWARE_OBJECTS_MAX    (35U)

/* Maximum number of receive hardware objects configured in a ConfigSet */
#define CAN_RX_HARDWARE_OBJECTS_MAX    (46U)

/* Maximum number of Rx FIFO configurations in a ConfigSet */
#define CAN_NUM_RX_FIFO_MAX            (0U)

/* Configured Message Identifier Type */
/* STD_ON  : Only Standard Message Identifiers are configured */
/* STD_OFF : At least one Extended/Mixed Message Identifier is configured */
#define CAN_STANDARD_ID_ONLY           (STD_ON) 

/*******************************************************************************
**                      CAN General Information                               **
*******************************************************************************/

/* Configuration: CAN_17_MCANP_INSTANCE_ID
 - Specifies the InstanceId of this module instance
*/
#define CAN_17_MCANP_INSTANCE_ID                (0U)

/* Configuration: CAN_DEV_ERROR_DETECT
 - STD_ON  - DET is enabled
 - STD_OFF - DET is disabled
*/      
#define CAN_DEV_ERROR_DETECT           (STD_ON)

/* Configuration: CAN_VERSION_INFO_API
 - STD_ON  - Can_17_MCanP_GetVersionInfo API is enabled
 - STD_OFF - Can_17_MCanP_GetVersionInfo API is disabled
*/      
#define CAN_VERSION_INFO_API           (STD_OFF)

/* Configuration: CAN_MULTIPLEXED_TRANSMISSION
 - STD_ON  - Multiplexed transmission feature is enabled
 - STD_OFF - Multiplexed transmission feature is disabled
*/      
#define CAN_MULTIPLEXED_TRANSMISSION   (STD_OFF)

/* Configuration: CAN_TIMEOUT_DURATION
 - Specifies the maximum number of loops for blocking function until 
   a timeout is raised in short term wait loops
*/
#define CAN_TIMEOUT_DURATION    (400U)

/* Configuration: CAN_PB_FIXEDADDR
 - STD_ON  - PB fixed address optimization is enabled 
 - STD_OFF - PB fixed address optimization is disabled 
*/
#define CAN_PB_FIXEDADDR               (STD_ON)

/* Configuration: CAN_DEBUG_SUPPORT
 - STD_ON  - Debug support is enabled 
 - STD_OFF - Debug support is disabled 
*/
#define CAN_DEBUG_SUPPORT              (STD_OFF)

/* Configuration: CAN_CHANGE_BAUDRATE_API
 - STD_ON  - Can_17_MCanP_CheckBaudrate and Can_17_MCanP_ChangeBaudrate 
             APIs are enabled
 - STD_OFF - Can_17_MCanP_CheckBaudrate and Can_17_MCanP_ChangeBaudrate 
             APIs are disabled
*/
#define CAN_CHANGE_BAUDRATE_API              (STD_ON)

/* CAN Hardware Timeout DEM */
#define CAN_E_TIMEOUT_DEM_REPORT   (CAN_DISABLE_DEM_REPORT)


/******************************************************************************/
                    /* CAN Controller Configurations */
/******************************************************************************/

/******************************************************************************/
              /* CONTROLLER_0_MULTICANPLUS_NODE0 Configuration */
/******************************************************************************/

/* CONTROLLER_0_MULTICANPLUS_NODE0 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER0_ACTIVATION           (STD_ON)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER0        (CAN_POLLING)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER0        (CAN_POLLING)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER0        (CAN_NO_PROCESSING)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER0        (CAN_POLLING)

/******************************************************************************/
              /* CONTROLLER_1_MULTICANPLUS_NODE1 Configuration */
/******************************************************************************/

/* CONTROLLER_1_MULTICANPLUS_NODE1 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER1_ACTIVATION           (STD_ON)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER1        (CAN_POLLING)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER1        (CAN_POLLING)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER1        (CAN_NO_PROCESSING)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER1        (CAN_POLLING)

/******************************************************************************/
              /* CONTROLLER_2_MULTICANPLUS_NODE2 Configuration */
/******************************************************************************/

/* CONTROLLER_2_MULTICANPLUS_NODE2 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER2_ACTIVATION           (STD_ON)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER2        (CAN_NO_PROCESSING)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/******************************************************************************/
              /* CONTROLLER_3_MULTICANPLUS_NODE3 Configuration */
/******************************************************************************/

/* CONTROLLER_3_MULTICANPLUS_NODE3 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER3_ACTIVATION           (STD_ON)

/* CONTROLLER_3_MULTICANPLUS_NODE3 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER3        (CAN_POLLING)

/* CONTROLLER_3_MULTICANPLUS_NODE3 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER3        (CAN_POLLING)

/* CONTROLLER_3_MULTICANPLUS_NODE3 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER3        (CAN_NO_PROCESSING)

/* CONTROLLER_3_MULTICANPLUS_NODE3 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER3        (CAN_POLLING)

/******************************************************************************/
              /* CONTROLLER_4_MULTICANPLUS_NODE0 Configuration */
/******************************************************************************/

#define CAN_HWCONTROLLER4_ACTIVATION           (STD_OFF)

/******************************************************************************/
              /* CONTROLLER_5_MULTICANPLUS_NODE1 Configuration */
/******************************************************************************/

#define CAN_HWCONTROLLER5_ACTIVATION           (STD_OFF)

/****************** End Of CAN Controller Configurations **********************/

/* Configuration: CAN_WAKEUP_CONFIGURED
 - STD_ON  - At least one of the CAN controllers supports wakeup
 - STD_OFF - None of the CAN controllers supports wakeup
*/      
#define CAN_WAKEUP_CONFIGURED                  (STD_OFF)

/* Configuration: CAN_LPDU_RX_CALLOUT
 - STD_ON  - L-PDU receive callout support enabled
 - STD_OFF - L-PDU receive callout support disabled
*/      
#define CAN_LPDU_RX_CALLOUT                    (STD_OFF)

/*******************************************************************************
    Symbolic Name Defintions of CAN Controllers and CAN Hardware Objects
*******************************************************************************/

/*******************************************************************************
    CanConfigSet_0 -> Symbolic Name Defintions of CAN Controllers 
*******************************************************************************/

#ifdef Can_17_MCanPConf_CanController_CAN_2 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CAN_2 != 0U)
    #error Can_17_MCanPConf_CanController_CAN_2 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanController_CAN_2   (0U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CAN_2 */
#ifdef Can_17_MCanPConf_CanController_CAN_1 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CAN_1 != 1U)
    #error Can_17_MCanPConf_CanController_CAN_1 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanController_CAN_1   (1U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CAN_1 */
#ifdef Can_17_MCanPConf_CanController_CAN_DEVAID /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CAN_DEVAID != 2U)
    #error Can_17_MCanPConf_CanController_CAN_DEVAID is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanController_CAN_DEVAID   (2U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CAN_DEVAID */
#ifdef Can_17_MCanPConf_CanController_CAN_3 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CAN_3 != 3U)
    #error Can_17_MCanPConf_CanController_CAN_3 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanController_CAN_3   (3U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CAN_3 */

/*******************************************************************************
    CanConfigSet_0 -> Symbolic Name Defintions of CAN Hardware Objects 
*******************************************************************************/

#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_572_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_572_HOH != 0U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_572_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_572_HOH   (0U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_572_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CLIM_50E_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CLIM_50E_HOH != 43U)
    #error Can_17_MCanPConf_CanHardwareObject_CLIM_50E_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CLIM_50E_HOH   (43U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CLIM_50E_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_V2_BSI_552_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_V2_BSI_552_HOH != 1U)
    #error Can_17_MCanPConf_CanHardwareObject_V2_BSI_552_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_V2_BSI_552_HOH   (1U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_V2_BSI_552_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_DIRA_495_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_DIRA_495_HOH != 2U)
    #error Can_17_MCanPConf_CanHardwareObject_DIRA_495_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_DIRA_495_HOH   (2U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_DIRA_495_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_4F2_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_4F2_HOH != 3U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_4F2_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_4F2_HOH   (3U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_4F2_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_V2_BV_3C9_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_V2_BV_3C9_HOH != 4U)
    #error Can_17_MCanPConf_CanHardwareObject_V2_BV_3C9_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_V2_BV_3C9_HOH   (4U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_V2_BV_3C9_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_7F2_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_7F2_HOH != 5U)
    #error Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_7F2_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_7F2_HOH   (5U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_7F2_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CRASH_4C8_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CRASH_4C8_HOH != 6U)
    #error Can_17_MCanPConf_CanHardwareObject_CRASH_4C8_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CRASH_4C8_HOH   (6U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CRASH_4C8_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_DAT_BSI_532_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_DAT_BSI_532_HOH != 7U)
    #error Can_17_MCanPConf_CanHardwareObject_DAT_BSI_532_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_DAT_BSI_532_HOH   (7U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_DAT_BSI_532_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_NEW_JDD_55F_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_NEW_JDD_55F_HOH != 8U)
    #error Can_17_MCanPConf_CanHardwareObject_NEW_JDD_55F_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_NEW_JDD_55F_HOH   (8U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_NEW_JDD_55F_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_VDS_BSI_492_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_VDS_BSI_492_HOH != 9U)
    #error Can_17_MCanPConf_CanHardwareObject_VDS_BSI_492_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_VDS_BSI_492_HOH   (9U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_VDS_BSI_492_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_V2_BV_489_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_V2_BV_489_HOH != 10U)
    #error Can_17_MCanPConf_CanHardwareObject_V2_BV_489_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_V2_BV_489_HOH   (10U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_V2_BV_489_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_ABR_50D_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_ABR_50D_HOH != 11U)
    #error Can_17_MCanPConf_CanHardwareObject_ABR_50D_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_ABR_50D_HOH   (11U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_ABR_50D_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_5B2_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_5B2_HOH != 12U)
    #error Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_5B2_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_5B2_HOH   (12U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CONTEXTE_1_5B2_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_592_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_592_HOH != 13U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_592_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_592_HOH   (13U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_592_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CDS_34D_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CDS_34D_HOH != 15U)
    #error Can_17_MCanPConf_CanHardwareObject_CDS_34D_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CDS_34D_HOH   (15U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CDS_34D_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_792_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_792_HOH != 16U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_792_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_792_HOH   (16U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_792_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_FRE_30D_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_FRE_30D_HOH != 17U)
    #error Can_17_MCanPConf_CanHardwareObject_FRE_30D_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_FRE_30D_HOH   (17U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_FRE_30D_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_ELECTRON_BSI_092_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_ELECTRON_BSI_092_HOH != 18U)
    #error Can_17_MCanPConf_CanHardwareObject_ELECTRON_BSI_092_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_ELECTRON_BSI_092_HOH   (18U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_ELECTRON_BSI_092_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7DF_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7DF_HOH != 19U)
    #error Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7DF_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7DF_HOH   (19U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7DF_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CC_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CC_HOH != 46U)
    #error Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CC_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CC_HOH   (46U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CC_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_UDS_ON_CAN_7FF_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_UDS_ON_CAN_7FF_HOH != 20U)
    #error Can_17_MCanPConf_CanHardwareObject_UDS_ON_CAN_7FF_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_UDS_ON_CAN_7FF_HOH   (20U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_UDS_ON_CAN_7FF_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_ABR_44D_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_ABR_44D_HOH != 21U)
    #error Can_17_MCanPConf_CanHardwareObject_ABR_44D_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_ABR_44D_HOH   (21U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_ABR_44D_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_VOL_305_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_VOL_305_HOH != 22U)
    #error Can_17_MCanPConf_CanHardwareObject_VOL_305_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_VOL_305_HOH   (22U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_VOL_305_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_6A8_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_6A8_HOH != 23U)
    #error Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_6A8_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_6A8_HOH   (23U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_6A8_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_48E_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_48E_HOH != 24U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_48E_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_48E_HOH   (24U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_48E_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_CMM_0A8_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_CMM_0A8_HOH != 25U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_CMM_0A8_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_CMM_0A8_HOH   (25U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_CMM_0A8_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_UCC_CMM_0E0_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_UCC_CMM_0E0_HOH != 26U)
    #error Can_17_MCanPConf_CanHardwareObject_UCC_CMM_0E0_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_UCC_CMM_0E0_HOH   (26U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_UCC_CMM_0E0_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_STT_BV_329_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_STT_BV_329_HOH != 27U)
    #error Can_17_MCanPConf_CanHardwareObject_STT_BV_329_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_STT_BV_329_HOH   (27U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_STT_BV_329_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_FRE_3CD_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_FRE_3CD_HOH != 28U)
    #error Can_17_MCanPConf_CanHardwareObject_FRE_3CD_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_FRE_3CD_HOH   (28U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_FRE_3CD_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_JDD_CAN_BSI_772_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_JDD_CAN_BSI_772_HOH != 29U)
    #error Can_17_MCanPConf_CanHardwareObject_JDD_CAN_BSI_772_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_JDD_CAN_BSI_772_HOH   (29U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_JDD_CAN_BSI_772_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_V2_BVA_349_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_V2_BVA_349_HOH != 30U)
    #error Can_17_MCanPConf_CanHardwareObject_V2_BVA_349_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_V2_BVA_349_HOH   (30U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_V2_BVA_349_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CE_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CE_HOH != 52U)
    #error Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CE_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CE_HOH   (52U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CE_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_EASY_MOVE_3AD_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_EASY_MOVE_3AD_HOH != 31U)
    #error Can_17_MCanPConf_CanHardwareObject_EASY_MOVE_3AD_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_EASY_MOVE_3AD_HOH   (31U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_EASY_MOVE_3AD_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_WMI_BSI_4D2_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_WMI_BSI_4D2_HOH != 32U)
    #error Can_17_MCanPConf_CanHardwareObject_WMI_BSI_4D2_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_WMI_BSI_4D2_HOH   (32U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_WMI_BSI_4D2_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_DMTR_57C_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_DMTR_57C_HOH != 33U)
    #error Can_17_MCanPConf_CanHardwareObject_DMTR_57C_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_DMTR_57C_HOH   (33U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_DMTR_57C_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_612_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_612_HOH != 34U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_612_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_612_HOH   (34U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_612_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_VIS_BSI_4B2_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_VIS_BSI_4B2_HOH != 35U)
    #error Can_17_MCanPConf_CanHardwareObject_VIS_BSI_4B2_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_VIS_BSI_4B2_HOH   (35U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_VIS_BSI_4B2_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_ABR_38D_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_ABR_38D_HOH != 36U)
    #error Can_17_MCanPConf_CanHardwareObject_ABR_38D_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_ABR_38D_HOH   (36U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_ABR_38D_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E0_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E0_HOH != 37U)
    #error Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E0_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E0_HOH   (37U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E0_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_412_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_412_HOH != 38U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_412_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_412_HOH   (38U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_412_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_BSI_432_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_BSI_432_HOH != 39U)
    #error Can_17_MCanPConf_CanHardwareObject_BSI_432_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_BSI_432_HOH   (39U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_BSI_432_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CD_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CD_HOH != 47U)
    #error Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CD_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CD_HOH   (47U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CD_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CF_HOH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CF_HOH != 48U)
    #error Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CF_HOH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CF_HOH   (48U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_OUTIL_PRTCLE_CCP_7CF_HOH */
#ifdef Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_DynSig_Counter_FC /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_DynSig_Counter_FC != 40U)
    #error Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_DynSig_Counter_FC is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_DynSig_Counter_FC   (40U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_DynSig_Counter_FC */
#ifdef Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_DM_DynSig /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_DM_DynSig != 41U)
    #error Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_DM_DynSig is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_DM_DynSig   (41U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_DM_DynSig */
#ifdef Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_TMS_N_Timess_FC /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_TMS_N_Timess_FC != 42U)
    #error Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_TMS_N_Timess_FC is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_TMS_N_Timess_FC   (42U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIF_Tx_TMS_N_Timess_FC */
#ifdef Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_PDU_2 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_PDU_2 != 14U)
    #error Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_PDU_2 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_PDU_2   (14U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_Com_CanTp_CanIf_Rx_PDU_2 */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_7A8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_7A8_HTH != 49U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_7A8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_7A8_HTH   (49U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_7A8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_788_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_788_HTH != 50U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_788_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_788_HTH   (50U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_788_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_NEW_JDD_CMM_768_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_NEW_JDD_CMM_768_HTH != 51U)
    #error Can_17_MCanPConf_CanHardwareObject_NEW_JDD_CMM_768_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_NEW_JDD_CMM_768_HTH   (51U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_NEW_JDD_CMM_768_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_438_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_438_HTH != 54U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_438_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_438_HTH   (54U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_438_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_BV_2E8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_BV_2E8_HTH != 55U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_BV_2E8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_BV_2E8_HTH   (55U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_BV_2E8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_3B8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_3B8_HTH != 56U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_3B8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_3B8_HTH   (56U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_3B8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_348_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_348_HTH != 57U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_348_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_348_HTH   (57U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_348_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_1E8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_1E8_HTH != 58U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_1E8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_1E8_HTH   (58U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_1E8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_488_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_488_HTH != 59U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_488_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_488_HTH   (59U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_488_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_STT_CMM_3C8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_STT_CMM_3C8_HTH != 60U)
    #error Can_17_MCanPConf_CanHardwareObject_STT_CMM_3C8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_STT_CMM_3C8_HTH   (60U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_STT_CMM_3C8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_468_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_468_HTH != 61U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_468_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_468_HTH   (61U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_468_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_588_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_588_HTH != 62U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_588_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_588_HTH   (62U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_588_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_108_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_108_HTH != 63U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_108_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_108_HTH   (63U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_108_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_208_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_208_HTH != 64U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_208_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_208_HTH   (64U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_208_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_388_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_388_HTH != 65U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_388_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_388_HTH   (65U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_388_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_608_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_608_HTH != 66U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_608_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_608_HTH   (66U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_608_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_EAC_CMM_UCC_0E8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_EAC_CMM_UCC_0E8_HTH != 67U)
    #error Can_17_MCanPConf_CanHardwareObject_EAC_CMM_UCC_0E8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_EAC_CMM_UCC_0E8_HTH   (67U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_EAC_CMM_UCC_0E8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_JDD_CAN_CMM_768_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_JDD_CAN_CMM_768_HTH != 68U)
    #error Can_17_MCanPConf_CanHardwareObject_JDD_CAN_CMM_768_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_JDD_CAN_CMM_768_HTH   (68U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_JDD_CAN_CMM_768_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_EAC_CMM_BSI_072_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_EAC_CMM_BSI_072_HTH != 69U)
    #error Can_17_MCanPConf_CanHardwareObject_EAC_CMM_BSI_072_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_EAC_CMM_BSI_072_HTH   (69U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_EAC_CMM_BSI_072_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_RQD_CMM_UCC_0E8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_RQD_CMM_UCC_0E8_HTH != 70U)
    #error Can_17_MCanPConf_CanHardwareObject_RQD_CMM_UCC_0E8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_RQD_CMM_UCC_0E8_HTH   (70U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_RQD_CMM_UCC_0E8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_5F8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_5F8_HTH != 71U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_5F8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_5F8_HTH   (71U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_5F8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_RQD_CMM_BSI_072_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_RQD_CMM_BSI_072_HTH != 72U)
    #error Can_17_MCanPConf_CanHardwareObject_RQD_CMM_BSI_072_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_RQD_CMM_BSI_072_HTH   (72U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_RQD_CMM_BSI_072_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E8_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E8_HTH != 73U)
    #error Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E8_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E8_HTH   (73U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_EOBD_ON_CAN_7E8_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_228_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_228_HTH != 74U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_228_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_228_HTH   (74U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_228_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_688_HTH /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_688_HTH != 75U)
    #error Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_688_HTH is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_688_HTH   (75U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_DIAG_ON_CAN_688_HTH */
#ifdef Can_17_MCanPConf_CanHardwareObject_CCP_105 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CCP_105 != 76U)
    #error Can_17_MCanPConf_CanHardwareObject_CCP_105 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CCP_105   (76U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CCP_105 */
#ifdef Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_7 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_7 != 77U)
    #error Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_7 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_7   (77U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_7 */
#ifdef Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_10 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_10 != 78U)
    #error Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_10 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_10   (78U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_10 */
#ifdef Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_9 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_9 != 79U)
    #error Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_9 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_9   (79U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_9 */
#ifdef Can_17_MCanPConf_CanHardwareObject_CMM_Ccp_100 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CMM_Ccp_100 != 45U)
    #error Can_17_MCanPConf_CanHardwareObject_CMM_Ccp_100 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CMM_Ccp_100   (45U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CMM_Ccp_100 */
#ifdef Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_6 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_6 != 80U)
    #error Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_6 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_6   (80U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CanHardwareObject_6 */
#ifdef Can_17_MCanPConf_CanHardwareObject_CCP_728 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CCP_728 != 53U)
    #error Can_17_MCanPConf_CanHardwareObject_CCP_728 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CCP_728   (53U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CCP_728 */
#ifdef Can_17_MCanPConf_CanHardwareObject_CCP_708 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_CCP_708 != 44U)
    #error Can_17_MCanPConf_CanHardwareObject_CCP_708 is already defined with a different value
  #endif  
#else
  #define Can_17_MCanPConf_CanHardwareObject_CCP_708   (44U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_CCP_708 */

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /* CAN_17_MCANP_CFG_H */
