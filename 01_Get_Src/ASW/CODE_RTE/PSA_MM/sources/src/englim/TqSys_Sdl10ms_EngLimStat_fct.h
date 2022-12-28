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
 ***  %name: TqSys_Sdl10ms_EngLimStat_fct.h %
 *** 
 ***  %version: 11.0.build3 %
 *** 
 ***  %date_modified: Tue Feb 14 16:34:09 2012 %
 *** 
 *** 
 ***  %derived_by: e343811 %
 ***  %release: TqStruct/10.0 %
 ***  %full_filespec: TqSys_Sdl10ms_EngLimStat_fct.h-11.0.build3:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : CSMT_CGMT06_1928
 *** TargetLink subsystem : CSMT_CGMT06_1928/F0_LimitStat
 *** Codefile             : tqsys_sdl10ms_englimstat_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2012-02-14 16:25:12
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
 *** Share fcns between TL subsystems    : enabled
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
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _TQSYS_SDL10MS_ENGLIMSTAT_FCT_H_
#define _TQSYS_SDL10MS_ENGLIMSTAT_FCT_H_

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

#define ENGLIM_START_SEC_GLOBAL_16BIT
#include "EngLim_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 EngLim_Eng_nCkFil_in /* 
   Unit       : RPM
   Description: R�gime moteur filtr�
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
extern AR_IF_GLOBAL_16BIT SInt16 EngLim_tqCkEfcStatLimIt_out /* 
   Description: Couple de limitation statique CME
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;

#define ENGLIM_STOP_SEC_GLOBAL_16BIT
#include "EngLim_MemMap.h"

#define ENGLIM_START_SEC_GLOBAL_8BIT
#include "EngLim_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT SInt8 EngLim_CoPt_noEgdGearCordIt_in /* 
   Description: Rapport de boite engag� interne SC
   LSB: 2^0 OFF:  0 MIN/MAX:  -1 .. 8 */;
extern AR_IF_GLOBAL_8BIT UInt8 EngLim_Ext_stGBxCf_in /* 
   Description: Type de boite de vitesse
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;

#define ENGLIM_STOP_SEC_GLOBAL_8BIT
#include "EngLim_MemMap.h"

#define ENGLIM_START_SEC_GLOBAL_BOOLEAN
#include "EngLim_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean EngLim_FRM_bLimRvEngLim_in /* 
   Description: Bit de d�faut sur l'information rapport de boite
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define ENGLIM_STOP_SEC_GLOBAL_BOOLEAN
#include "EngLim_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void TqSys_Sdl10ms_EngLimStat_fct(Void);
extern Void TqSys_Sdl10ms_EngLimStat_ini(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void EngLim_1928_FctVarInit(Void);


#endif/*_TQSYS_SDL10MS_ENGLIMSTAT_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/