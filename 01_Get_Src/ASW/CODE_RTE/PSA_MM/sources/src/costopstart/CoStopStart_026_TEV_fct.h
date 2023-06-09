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
 ***  %name: CoStopStart_026_TEV_fct.h %
 *** 
 ***  %version: 11.1 %
 *** 
 ***  %date_modified: Thu Jan 19 13:42:04 2012 %
 *** 
 *** 
 ***  %derived_by: e375697 %
 ***  %release: CoStopStart/11.0 %
 ***  %full_filespec: CoStopStart_026_TEV_fct.h-11.1:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : TL_01460_10_03534
 *** TargetLink subsystem : TL_01460_10_03534/CoStopStart_026
 *** Codefile             : costopstart_026_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2012-01-19 12:30:41
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
 *** Style definition file               : C:\dSPACE301\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE301\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSource
 ***                                       CodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _COSTOPSTART_026_TEV_FCT_H_
#define _COSTOPSTART_026_TEV_FCT_H_

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

#define COSTOPSTART_START_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_026_CoEmSTT_stEngRStrtReq_in /* 
   Description: Demande de redémarrage par le SEEM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 4 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_026_CoEmSTT_stEngStopAuth_in /* 
   Description: Autorisation de stop par le SEEM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT_IRV: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern UInt8 MonEE_stRstrtReq /* 
   Description: Niveau de priorité de demande de redémarrage automatique EE Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bCompTqRStrt_out /* 
   Description: Pour APV. Résultat de la comparaison des couples de redem nécessaire et disponible
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_026_CoPtUH_bFbSpcFactSTTReq1_in /* 
   Description: Pour APV. Retour sur la dmd des inhibitions des interdictions d'arrêt Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_026_CoReqRStrt_bEngRStrtReq_in /* 
   Description: Dde Redem sur redémarrabilité
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_026_CoReqRStrt_bEngStopAuth_in /* 
   Description: Autorisation Stop sur redémarrabilité
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN_IRV: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern Boolean MonEE_bStopAuth /* 
   Description: Autorisation par le systeme EE de l'arret moteur Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void CoStopStart_025_MSE_ini(Void);
extern Void CoStopStart_026_TEV_fct(Void);


#endif/*_COSTOPSTART_026_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
