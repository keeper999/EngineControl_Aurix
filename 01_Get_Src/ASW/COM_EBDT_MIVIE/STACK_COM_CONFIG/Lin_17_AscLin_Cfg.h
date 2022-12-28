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
**  FILENAME  : Lin_17_AscLin_Cfg.h                                           **
**                                                                            **
**  $CC VERSION : \main\31 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-30, 16:07:52                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  MODULE DECRIPTION : Lin_17_AscLin.bmd/.xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Lin configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_LIN_Driver, Release 4.0.3                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
  TRACEABILITY : [cover parentID= DS_AS_LIN224,
DS_NAS_PR127] [/cover] 
*******************************************************************************/
#ifndef LIN_CFG_H 
#define LIN_CFG_H 
  

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*Section to Generate Autosar Specific Version Information*/


#define LIN_17_ASCLIN_AR_RELEASE_MAJOR_VERSION  (4U)
#define LIN_17_ASCLIN_AR_RELEASE_MINOR_VERSION  (0U)
#define LIN_17_ASCLIN_AR_RELEASE_REVISION_VERSION  (3U)

/*Section to Generate Vendor Specific Version Information*/
/* Vendor specific implementation version information */
#define LIN_17_ASCLIN_SW_MAJOR_VERSION   (2U)
#define LIN_17_ASCLIN_SW_MINOR_VERSION   (0U)
#define LIN_17_ASCLIN_SW_PATCH_VERSION   (3U)


/*
         Container : LinGeneralConfiguration
*/

/*
Configuration: LIN_DEV_ERROR_DETECT 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled
The detection of all development errors is configurable (On / Off) 
at precompile time. The switch LIN_DEV_ERROR_DETECT (see chapter 10) shall
activate or deactivate the detection of all development errors.

If the switch LIN_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled. 
*/
#define LIN_DEV_ERROR_DETECT  (STD_ON)


/*
Configuration: LIN_VERSION_INFO_API 
- if STD_ON, Function Lin_GetVersionInfo is available  
- if STD_OFF,Function Lin_GetVersionInfo is not available 
*/
#define LIN_VERSION_INFO_API  (STD_OFF)

/*
Configuration: LIN_PB_FIXEDADDR 
- if STD_ON, Fixed Address feature is Enabled 
- if STD_OFF,Fixed Address feature is Disabled
*/
#define LIN_PB_FIXEDADDR  (STD_OFF)

/*
Configuration: LIN_INDEX 
*/
#define LIN_INDEX  (0U)

/* Number of ASCLIN busses */
#define LIN_MAX_HW_UNIT (4U)

#define LIN_ASCLIN0 (0U)
#define LIN_ASCLIN1 (1U)
#define LIN_ASCLIN2 (2U)
#define LIN_ASCLIN3 (3U)




/* 
Configuration : LIN_MAXIMUM_CHANNEL 
It is the maximum lin channels configured.
*/
#define LIN_MAXIMUM_CHANNEL (1U)


/*
Configuration: LIN_ASCLINx_USED 
- if STD_ON, ASCLINx is used   
- if STD_OFF,ASCLINx is not used  
*/

#define LIN_ASCLIN0_USED  (STD_OFF)

#define LIN_ASCLIN1_USED  (STD_OFF)
#define LIN_ASCLIN2_USED  (STD_OFF)
#define LIN_ASCLIN3_USED  (STD_ON)


/* Module Debug Support */
#define LIN_DEBUG_SUPPORT  (STD_OFF)

/* LinChannelWakeupSupport is disabled for all the channels 
                                                     on all the config sets */
#define LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT  (STD_OFF)

#define LIN_ASCLIN_CLC (0x08U)


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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* LIN_CFG_H */

