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
 ***  %name: CoStopStart_010_TEV_fct.h %
 *** 
 ***  %version: 11.4 %
 *** 
 ***  %date_modified: Wed Jun  6 11:49:48 2012 %
 *** 
 *** 
 ***  %derived_by: u349799 %
 ***  %release: CoStopStart/11.0 %
 ***  %full_filespec: CoStopStart_010_TEV_fct.h-11.4:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : TL_01460_10_03526
 *** TargetLink subsystem : TL_01460_10_03526/CoStopStart_010
 *** Codefile             : costopstart_010_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2012-06-05 11:13:00
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
 *** Style definition file               : C:\dSPACE_TL_3.0.1\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE_TL_3.0.1\Matlab\Tl\XML\CodeGen\Stylesheets\TL_C
 ***                                       SourceCodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0 from 27-Jun-2008
 *** Code generator version  : Build Id 3.0.0.19 from 2008-06-09 16:55:48
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _COSTOPSTART_010_TEV_FCT_H_
#define _COSTOPSTART_010_TEV_FCT_H_

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

#define COSTOPSTART_START_SEC_GLOBAL_16BIT
#include "CoStopStart_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 CoStopStart_010_Ext_spdVehSecu_in /* 
   Unit       : km/h
   Description: vitesse v�hicule s�curis�e
   LSB: 2^-7 OFF:  0 MIN/MAX:  0 .. 500 */;
extern AR_IF_GLOBAL_16BIT SInt16 CoStopStart_010_Ext_tOilGBx_in /* 
   Unit       : �C
   Description: Temperature Oil Gear Box
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 250 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoStopStart_010_Veh_spdVeh_in /* 
   Unit       : km/h
   Description: vitesse v�hicule. La provenance est fonction de l'architecture Electique
   LSB: 2^-7 OFF:  0 MIN/MAX:  0 .. 500 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 CoPtUH_stMaxRStrtReq_out /* 
   Description: Classe la plus �lev�e des demandes de Redemarrage Automatique pr�sentes
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_010_CoPtUH_stPwt_in /* 
   Description: Etat GMP UH Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 15 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_010_Ext_stGBxCf_in /* 
   Description: Type de boite
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_IF_GLOBAL_8BIT UInt8 RE_CoStopStart_010_TEV_DgoFct_stRstrtReq_in /* 
   Description: Niveau de priorit� de la demande de red�marrage automatique par diagnostic courroie 
   glissante Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_IF_GLOBAL_8BIT UInt8 RE_CoStopStart_010_TEV_MonDrv_stRstrtReq_in /* 
   Description: Niveau de priorit� de demande de red�marrage automatique Conducteur Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_IF_GLOBAL_8BIT UInt8 RE_CoStopStart_010_TEV_MonEE_stRstrtReq_in /* 
   Description: Niveau de priorit� de demande de red�marrage automatique EE Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_IF_GLOBAL_8BIT UInt8 RE_CoStopStart_010_TEV_MonEng_stRstrtReq_in /* 
   Description: Niveau de priorit� de demande de red�marrage automatique Engine Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_IF_GLOBAL_8BIT UInt8 RE_CoStopStart_010_TEV_MonGB_stRstrtReq_in /* 
   Description: Niveau de priorit� de demande de red�marrage automatique BV Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_IF_GLOBAL_8BIT UInt8 RE_CoStopStart_010_TEV_MonVeh_stRstrtReq_in /* 
   Description: Niveau de priorit� de demande de red�marrage automatique v�hicule Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bRStrtReqAvl_out /* 
   Description: Demande de red�marrage pr�sente
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bRStrtTypAT_out /* 
   Description: Typage de red�marrage pour BVA
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_010_FRM_bAcvFastRStrtCoPtUH_in /* 
   Description: Reconfiguration type 2.2 (redemarrage urgent)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_010_FRM_bAcvRStrtCoPtUH_in /* 
   Description: Reconfiguration type 2.1 (redem classique)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_010_FRM_bInhspdVehCoPtUH_in /* 
   Description: Info impliquant une reconfiguration li�e � un d�faut sur l'info vitesse v�hicule
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_CoStopStart_010_TEV_MonDrv_bRstrtAntReq_in /* 
   Description: Redem anticip�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_CoStopStart_010_TEV_MonDrv_bRstrtReq_in /* 
   Description: Demande par le conducteur du redemarrage moteur Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_CoStopStart_010_TEV_MonGB_bMAPRstrtAuth_in /* 
   Description: Autorisation de red�marrage sp�cifique MAP Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_CoStopStart_010_TEV_MonGB_bRstrtAuth_in /* 
   Description: Autorisation de redemarrage par la boite de vitesse Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_CoStopStart_010_TEV_MonGB_bRstrtTypATReq_in /* 
   Description: Position levier BVA en Drive Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_CoStopStart_010_TEV_MonVeh_bRstrtAuth_in /* 
   Description: Autorisation de red�marrage Emove trait�e Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN_IRV: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern Boolean CoRStrt_bRstrtReq /* 
   Description: Demande de redemarrage moteur validee Dim = 1x1
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
extern Void CoStopStart_009_MSE_ini(Void);
extern Void CoStopStart_010_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void CoStopStart_010_FctVarInit(Void);


#endif/*_COSTOPSTART_010_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
