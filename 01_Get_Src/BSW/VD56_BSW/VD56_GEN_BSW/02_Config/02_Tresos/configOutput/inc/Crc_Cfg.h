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
**  FILENAME  : Crc_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\12 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:19                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CRC configuration generated out of ECU configuration       **
**                 file (Crc.bmd)                                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
  

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
 #define CRC_RUNTIME_MODE 0x00
 #define CRC_TABLE_MODE 0x01
 #define CRC_HARDWARE_MODE 0x02

/*Macro for Initial Values of CRC*/
  #define CRC_INITIAL_VALUE8 0xFFU
  #define CRC_INITIAL_VALUE8H2F 0xFFU
  #define CRC_INITIAL_VALUE16 0xFFFFU
  #define CRC_INITIAL_VALUE32 0xFFFFFFFFU


/*
         Container : CRCGeneral
*/

/*Vendor specific information*/
 #define CRC_VENDOR_ID (17U)
 #define CRC_MODULE_ID (201U)
 #define CRC_INSTANCE_ID (0U)

/*Autosar specific information*/
 #define CRC_AR_MAJOR_VERSION  (4U)
 #define CRC_AR_MINOR_VERSION  (0U)
 #define CRC_AR_PATCH_VERSION  (3U)

/*Release specific information*/
 #define CRC_SW_MAJOR_VERSION  (3U)
 #define CRC_SW_MINOR_VERSION  (0U)
 #define CRC_SW_PATCH_VERSION  (2U)
/*Macro for versioninfoapi*/
 #define CRC_VERSION_INFO_API  (STD_OFF)
 

 #define CRC_16_MODE CRC_TABLE_MODE 
/*Macro for selection of 32 bit CRC method */

 #define CRC_32_MODE CRC_TABLE_MODE 

/*Macro for selection of 8 bit CRC method with 0x1D polynomial*/

 #define CRC_8_MODE CRC_TABLE_MODE

/*Macro for selection of 8 bit CRC method with 0x2F polynomial*/

 #define CRC_8H2F_MODE CRC_TABLE_MODE


/*
    Configuration : CRC_SAFETY_ENABLE
    Pre-processor switch to enable/disable the CRC driver safety features.
*/
#define CRC_SAFETY_ENABLE (STD_OFF)


