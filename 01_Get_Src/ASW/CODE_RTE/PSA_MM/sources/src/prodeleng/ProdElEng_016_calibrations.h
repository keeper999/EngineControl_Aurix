/**************************************************************************************************\
 *** 
 *** Simulink model       : ProdElEng_07_1021_TL
 *** TargetLink subsystem : ProdElEng_07_1021_TL/ProdElEng_016
 *** Codefile             : prodeleng_016_calibrations.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-05-23 09:13:23
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
 *** Extended variable sharing           : enabled
 *** Style definition file               : C:\dSPACE30\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE30\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSourceC
 ***                                       odeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _PRODELENG_016_CALIBRATIONS_H_
#define _PRODELENG_016_CALIBRATIONS_H_

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

#define PRODELENG_START_SEC_CALIB_8BIT
#include "ProdElEng_MemMap.h"
/******************************************************************************\
   AR_MERGEABLE_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_stEngRunAntiStallUH_C /* 
   Unit       : -
   Description: Constante �tat moteur tournant
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 15 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_tiGrdLimDeac_C /* 
   Unit       : s
   Description: Temps d'activation de la non limitation du gradient de couple AltR (d�fini la dur�e 
   d'activation de l'�tat ACTIVATION de l'automate)
   LSB: 0.05 OFF:  0 MIN/MAX:  0 .. 12.7 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_tiMaxAntiStallAcv_C /* 
   Unit       : s
   Description: Temporisation d'application maximum de la requ�te d'anti-calage apr�s activation (un
   e fois dans l'�tat AntiStall_Acv)
   LSB: 0.05 OFF:  0 MIN/MAX:  0 .. 12.7 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_tiMinAntiStallOff_C /* 
   Unit       : s
   Description: Temporisation minimum d'application de la requ�te d'anti-calage apr�s activation (da
   ns AntiStall_Acv de l'automate)
   LSB: 0.05 OFF:  0 MIN/MAX:  0 .. 12.7 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_tiMinESPOff_C /* 
   Unit       : s
   Description: Temporisation minimum d'application de la requ�te de d�lestage AltR pour r�gulation 
   ESP apr�s activation (une fois dans l'�tat AntiStall_Acv de l'automate)
   LSB: 0.05 OFF:  0 MIN/MAX:  0 .. 12.7 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_tiWaitAntiStallDeac_C /* 
   Unit       : s
   Description: Temporisation mini d'attente avant d'autoriser � nouveau une requ�te d'assistance an
   ti-calage moteur par UH
   LSB: 0.05 OFF:  0 MIN/MAX:  0 .. 12.7 */;

#define PRODELENG_STOP_SEC_CALIB_8BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_INTERNAL_VAR_16BIT
#include "ProdElEng_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_16BIT: Display 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 TqLimUH_stCoAntiStallUH /* 
   Unit       : -
   Description: Etat courant de l'automate de coordination
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 4 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 TqLimUH_tiCurStMchAntiStall /* 
   Unit       : s
   Description: Valeur de la tempo en cours de l'automate
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 16 */;

#define PRODELENG_STOP_SEC_INTERNAL_VAR_16BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_INTERNAL_VAR_8BIT
#include "ProdElEng_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_8BIT: Display 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 TqLimUH_tiMinAntiStallOff /* 
   Unit       : s
   Description: Variable de la temporisation minimum d'attente avant nouvelle requ�te
   LSB: 0.05 OFF:  0 MIN/MAX:  0 .. 12.7 */;

#define PRODELENG_STOP_SEC_INTERNAL_VAR_8BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ProdElEng_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_BOOLEAN: Display Boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean TqLimUH_bAntiStallUHAcv /*
   Description: Flag � vrai si une situation de risque de calage moteur thermique est identifi�e */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean TqLimUH_bAntiStallUHDeac /*
   Description: Flag � vrai quand le moteur thermique est sorti de la situation de calage */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean TqLimUH_bCndAntiStallOff_MP;

#define PRODELENG_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ProdElEng_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

#endif/*_PRODELENG_016_CALIBRATIONS_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
