/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Msc_Cfg.h                                                    **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  DATE, TIME: 2014-09-29, 11:35:18                                         **
**                                                                           **
**  GENERATOR : Build b131017-0205                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : MSC configuration generated out of ECU configuration      **
**                 file (Msc.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
    TRACEBILITY :[cover parentID = DS_NAS_PR446,SAS_NAS_MSC_PR1071][/cover]  **
**                                                                           **
******************************************************************************/
#ifndef MSC_CFG_H 
#define MSC_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


#define MSC_VENDOR_ID                   ((uint16)17U)
#define MSC_MODULE_ID                   ((uint16)255U)
#define MSC_MODULE_INSTANCE             ((uint8)0U)

/*SW Version Information*/
#define MSC_SW_MAJOR_VERSION            (1U)
#define MSC_SW_MINOR_VERSION            (0U)
#define MSC_SW_PATCH_VERSION            (1U)

/*Number of MSC modules present in the controller*/
#define MSC_NUM_OF_MODULES              (3U)

/* Derived Configuration for MscDevErrorDetect */
#define MSC_DEV_ERROR_DETECT            (STD_ON)

/* Derived Configuration for MscVersionInfoApi */
#define MSC_VERSION_INFO_API            (STD_OFF)

/* Derived Configuration for MscPassiveFrameCounterApi */
#define MSC_PASSIVE_TIME_FRAME_API      (STD_OFF)

/* Derived Configuration for MscDeInitApi */
#define MSC_DEINIT_API                  (STD_OFF)

/* Derived Configuration MscEmergencyDataApi*/
#define MSC_EMERGENCY_DATA_API          (STD_OFF)

/* Derived Configuration MscDebugSupport*/
#define MSC_DEBUG_SUPPORT               (STD_OFF)

/* Derived Configuration MscPBFixedAddress*/
#define MSC_PB_FIXEDADDR                (STD_OFF)


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

#endif  /*End of MSC_CFG_H */


