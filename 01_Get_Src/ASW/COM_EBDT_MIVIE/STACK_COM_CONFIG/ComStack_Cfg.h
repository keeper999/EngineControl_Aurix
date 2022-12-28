/* !Deviation: [0288] Violates MISRA Rule 5: "Only those characters and escape
    sequences which are defined in the ISO C standard shall be used."
    PVCS needs the "Dollar Sign" and Doxygen needs the "At Sign", and both are
    only used within a commented area so no harm could be done.
 */
/* PRQA S 0288 ++*/
/******************************************************************************/
/* @File            :   ComStack_Cfg.h                                        */
/*                                                                            */
/* @Designed by     :   Nader Galal                        @Date : 27/03/11   */
/*                                                                            */
/* @Coded by        :   Nader Galal                        @Date : 27/03/11   */
/*                                                                            */
/* @Coding language : C                                                       */
/*                                                                            */
/* @COPYRIGHT 2002 VALEO ELECTRONIC AND CONNECTIVE SYSTEMS.                   */
/* all rights reserved                                                        */
/******************************************************************************/
/* @DESIGN MODIFICATION LOG :                                                 */
/******************************************************************************/
/* @Modified by     :                                      @Date :            */
/*                                                                            */
/* @TFR             :                                                         */
/*                                                                            */
/* Version :                                                                  */
/*    @Issued on    :                                                         */
/*    @Corrected in :                                                         */
/*                                                                            */
/* @Description     :                                                         */
/******************************************************************************/
/* @CODE MODIFICATION LOG :                                                   */
/******************************************************************************/
/* @Modified by     :                                      @Date :            */
/*                                                                            */
/* @TFR             :                                                         */
/*                                                                            */
/* Version :                                                                  */
/*    @Issued on    :                                                         */
/*    @Corrected in :                                                         */
/*                                                                            */
/* @Description     :                                                         */
/******************************************************************************/
/* PRQA S 0288 --*/
/******************************************************************************/
/*! \file
*
* \par
*   Externals of the module ComStack_Cfg. \n
*   This file contains the externals of the module ComStack_Cfg. */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup  Std Component
* COMPONENT_DESCRIPTION
* \{
*/

/*! \defgroup ComStack_Cfg Module
* This is the grouping of ComStack_Cfg module members.
* \{
*/
/******************************************************************************/

/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*
$Header::
*/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.0.0 R1.0.0 AR4.0                                            */
/* Done by    : Nader Galal                                   Date : 27/03/11 */
/* Description: Initial Creation based on AUTOSAR Specification R4.0 Rev2.    */
/******************************************************************************/
/******************************************************************************/
/* !VnrOff : Names imposed by AUTOSAR Specification                           */
/******************************************************************************/
/******************************************************************************/
/*! \Description: AUTOSAR Communication Stack Configuration Header File:
                 ComStack_Cfg.h
                 This header file does not contain any project or supplier
                 specific information
                 ComStack_Cfg.h shall be generated by the generator to generate
                 the type definition of the PduIdType and PduLengthType from the
                 EcuC Virtual Layer based on the configuration e.g. typedef
                 uint8 PduIdType if number of PDUs are less than 256.
   \Trace_To COMTYPE003, COMTYPE004                                           */
/******************************************************************************/
/******************************************************************************/

/*! \Description: Protection against multiple inclusion
    \Trace_To COMTYPE016                                                      */
/******************************************************************************/
#ifndef COMSTACK_CFG_H
#define COMSTACK_CFG_H


/******************************************************************************/
/*!  \Description  a conditional compilation to enrich the PduInfoType type 
*******************************************************************************/
#define COMSTACK_coENABLE    1
#define COMSTACK_coDISABLE   0

#define COMSTACK_coPDU_INFO_TYPE_ADD_CANID              COMSTACK_coDISABLE


/******************************************************************************/
/*! \Description Vendor ID of the dedicated implementation of this module
                 according to the AutOSAR vendor list.                      \n\n
    \Range 38                                                               \n\n
    \Unit uint16
    \Trace_To COMTYPE001_PI
*******************************************************************************/
#define     COMSTACKTYPE_CFG_VENDOR_ID                       (uint16)(38)
/******************************************************************************/
/*! \Description Module ID of the dedicated implementation of this module
                 according to the AutOSAR module list.                      \n\n
    \Range 0                                                               \n\n
    \Unit uint16
    \Trace_To COMTYPE001_PI
*******************************************************************************/
#define     COMSTACKTYPE_CFG_MODULE_ID                       (uint16)(0)
/******************************************************************************/
/*! \Description Major version number of AutOSAR specification on which the
                 current implementation is based.                           \n\n
    \Range 4                                                                \n\n
    \Unit uint8
    \Trace_To COMTYPE001_PI
*******************************************************************************/
#define     COMSTACKTYPE_CFG_AR_RELEASE_MAJOR_VERSION        (4U)
/******************************************************************************/
/*! \Description Minor version number of AutOSAR specification on which the
                 current implementation is based.                           \n\n
    \Range 0                                                                \n\n
    \Unit uint8
    \Trace_To COMTYPE001_PI
*******************************************************************************/
#define     COMSTACKTYPE_CFG_AR_RELEASE_MINOR_VERSION        (0U)
/******************************************************************************/
/*! \Description Patch level version number of AutOSAR specification on
                 which the current implementation is based.                 \n\n
    \Range 2                                                                \n\n
    \Unit uint8
    \Trace_To COMTYPE001_PI
*******************************************************************************/
#define     COMSTACKTYPE_CFG_AR_RELEASE_REVISION_VERSION     (2U)
/******************************************************************************/
/*! \Description Major version number of the "VIAS_3_AUTOSAR Platform
                 Development R4.0 - ESW Variant" project implementation of
                 the module. The numbering is vendor specific.              \n\n
    \Range 1                                                                \n\n
    \Unit uint8
    \Trace_To COMTYPE001_PI
*******************************************************************************/
#define     COMSTACKTYPE_CFG_SW_MAJOR_VERSION                (1U)
/******************************************************************************/
/*! \Description Minor version number of the "VIAS_3_AUTOSAR Platform
                 Development R4.0 - ESW Variant" project implementation of
                 the module. The numbering is vendor specific.              \n\n
    \Range 0                                                                \n\n
    \Unit uint8
    \Trace_To COMTYPE001_PI
*******************************************************************************/
#define     COMSTACKTYPE_CFG_SW_MINOR_VERSION                (0U)
/******************************************************************************/
/*! \Description Patch level version number of the "VIAS_3_AUTOSAR Platform
                 Development R4.0 - ESW Variant" project implementation of
                 the module.                                                \n\n
    \Range 0                                                                \n\n
    \Unit uint8
    \Trace_To COMTYPE001_PI
*******************************************************************************/
#define     COMSTACKTYPE_CFG_SW_PATCH_VERSION                (0U)

/******************************************************************************/
/*! \Description The PDU ID Type. \n
             Is used within the entire AUTOSAR Com Stack except \n
             for bus drivers \n\n
    \Range       0...<PduIdmax> \n\n
    \Trace_To COMTYPE005, COMTYPE006, COMTYPE007, COMTYPE014
*******************************************************************************/
typedef     uint8       PduIdType;

/******************************************************************************/
/*! \Description The PDU Length Type.\n\n
                 Is used within the entire AUTOSAR Com Stack except for bus \n
                 drivers.\n\n
                 Variables of this type serve as length information of a PDU.\n
                 The length information is provided in number of bytes.\n\n
    \Range       0...<PduLengthmax> \n\n
    \Trace_To COMTYPE008, COMTYPE010, COMTYPE017
*******************************************************************************/
typedef     uint16       PduLengthType;

#endif /* COMSTACK_CFG_H */

/** \} */ /* end of ComStack_Cfg module group */
/** \} */ /* end of Std Component group */
      