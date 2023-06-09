/**************************************************************************************************\
 *** 
 *** Simulink model       : CSMT_CMGT08_2978_4_0
 *** TargetLink subsystem : CSMT_CMGT08_2978_4_0/StopStrtEng_018
 *** Codefile             : stopstrteng_018_calibrations.c
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-05-18 12:46:26
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
 *** Style definition file               : C:\dSPACE\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSourceCod
 ***                                       eSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** SUBSYS                   CORRESPONDING SIMULINK SUBSYSTEM
 *** S0181                    CSMT_CMGT08_2978_4_0/StopStrtEng_018
 *** S0182                    StopStrtEng_018/TurnOffDelay1
 *** S0183                    StopStrtEng_018/TurnOffDelay1/Counter
 *** 
 *** SF-NODE   CORRESPONDING STATEFLOW NODE                           DESCRIPTION
 *** 
 *** TargetLink version      : 3.0.1_RC3 from 13-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _STOPSTRTENG_018_CALIBRATIONS_C_
#define _STOPSTRTENG_018_CALIBRATIONS_C_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "StopStrtEng_018_calibrations.h"
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

#define STOPSTRTENG_START_SEC_CALIB_16BIT
#include "StopStrtEng_MemMap.h"
/******************************************************************************\
   AR_MERGEABLE_CALIB_16BIT: Mergeable Calib 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
AR_MERGEABLE_CALIB_16BIT UInt16 CoStrt_tiDrvStrtReq_C = 3 /* 0.03 */ /* 
   Unit       : s
   Description: Temps de prise en compte de l'arr�t de la demande de d�marrage conducteur pour palie
   r aux micros coupures
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 5 */;

#define STOPSTRTENG_STOP_SEC_CALIB_16BIT
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_CALIB_8BIT
#include "StopStrtEng_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_MERGEABLE_CALIB_8BIT UInt8 CoStrt_stCfCoStrt_C = 0 /* 
   Description: Choix de la configuration de CoStrt
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define STOPSTRTENG_STOP_SEC_CALIB_8BIT
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_CALIB_BOOLEAN
#include "StopStrtEng_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_BOOLEAN: Mergeable Calib 1 bit for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoStrt_bAcvAuth_C = 1 /* 
   Description: Activation du calcul de l'autorisation de d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define STOPSTRTENG_STOP_SEC_CALIB_BOOLEAN
#include "StopStrtEng_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INLINE FUNCTIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

#endif/*_STOPSTRTENG_018_CALIBRATIONS_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
