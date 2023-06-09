/**************************************************************************************************\
 *** 
 ***                            P. C. A.
 *** 
 ***                     Peugeot Citroen Automobile
 *** 
 ***         This file is the property of PCA. All rights are reserved
 ***         by PCA and this file must not be copied or disclosed
 ***        (in whole or in part) without prior written consent of PCA.
 *** 
 *** *******************************************************************************
 *** 
 ***  %name: StopStrtEm_002_calibrations.h %
 *** 
 ***  %version: 3.1 %
 *** 
 ***  %date_modified: Fri Apr 12 12:23:34 2013 %
 *** 
 *** 
 ***  %derived_by: u261238 %
 ***  %release: StopStrtEm/5.0 %
 ***  %full_filespec: StopStrtEm_002_calibrations.h-3.1:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : StopStrtEm_002
 *** TargetLink subsystem : StopStrtEm_002/StopStrtEm_002
 *** Codefile             : stopstrtem_002_calibrations.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2013-04-02 14:14:09
 ***
 *** CODE GENERATOR OPTIONS:
 *** Compiler                            : <unknown>
 *** Target                              : Generic
 *** ANSI-C compatible code              : yes
 *** Optimization level                  : 2
 *** Constant style                      : decimal
 *** Clean code option                   : enabled
 *** Logging mode                        : Do not log anything
 *** Linker sections                     : enabled
 *** Assembler statements                : disabled
 *** Variable name length                : 31 chars
 *** Use global bitfields                : disabled
 *** Stateflow: use of bitfields         : enabled
 *** State activity encoding limit       : 5
 *** Omit zero inits in restart function : disabled
 *** Share fcns between TL subsystems    : disabled
 *** Generate 64bit functions            : enabled
 *** Inlining Threshold                  : 6
 *** Line break limit                    : 100
 *** Target optimized boolean data type  : enabled
 *** Keep saturation elements            : disabled
 *** Extended variable sharing           : disabled
 *** Style definition file               : C:\dSPACE301\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE301\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSource
 ***                                       CodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0.1p1 from 06-Oct-2009
 *** Code generator version  : Build Id 3.0.1.8 from 2009-03-10 10:34:41
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _STOPSTRTEM_002_CALIBRATIONS_H_
#define _STOPSTRTEM_002_CALIBRATIONS_H_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

#define STOPSTRTEM_START_SEC_CALIB_16BIT
#include "StopStrtEm_MemMap.h"
/******************************************************************************\
   AR_MERGEABLE_CALIB_16BIT: Mergeable Calib 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoEmCkg_tiHiLoTq_C /* 
   Unit       : "s"
   Description: Temps entre fort boost et petit boost
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoEmCkg_tiHiTq_C /* 
   Unit       : "s"
   Description: Temps max fort boost
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoEmCkg_tiLoTq_C /* 
   Unit       : "s"
   Description: Temps max faible boost
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 600 */;

#define STOPSTRTEM_STOP_SEC_CALIB_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_INTERNAL_VAR_8BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_8BIT: Display 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 CoEmCkg_stAltWithStaFbCmd_MP /* 
   Description: Point de mesure sur le retour de commande SEEM en STT_A avec démarreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define STOPSTRTEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "StopStrtEm_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

#endif/*_STOPSTRTEM_002_CALIBRATIONS_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
