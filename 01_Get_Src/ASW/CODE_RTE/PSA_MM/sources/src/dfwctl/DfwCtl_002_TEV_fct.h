/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name: DfwCtl_002_TEV_fct.h %
*
* %version: 1.3.build4 %
*
* %date_modified: Thu Nov 17 16:46:27 2011 %
*
*
* %derived_by: e360487 %
* %release: DfwCtl/1.0 %
* %full_filespec: DfwCtl_002_TEV_fct.h-1.3.build4:incl:1 %
*
*******************************************************************************/
/**************************************************************************************************\
 *** 
 *** Simulink model       : CGMP_CMOD00_0028_v4_1_TL
 *** TargetLink subsystem : CGMP_CMOD00_0028_v4_1_TL/DfwCtl
 *** Codefile             : dfwctl_002_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-06-28 10:09:28
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

#ifndef _DFWCTL_002_TEV_FCT_H_
#define _DFWCTL_002_TEV_FCT_H_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "DfwCtl_nvm.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/

struct tag_SBFS_F02_02_01_Protection_state_calculation_DfwCtl_tp {
   unsigned int CDfwCtl2_Nominal : 1;
   unsigned int CDfwCtl3_Clutc__nd_oscillations : 1;
   unsigned int CDfwCtl4_Oscillations : 1;
}; /* Type of structure containing bitfields for Stateflow chart  */
/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

#define DFWCTL_START_SEC_GLOBAL_16BIT
#include "DfwCtl_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 DfwCtl_Ext_nEng_in /* 
   Unit       : RPM
   Description: R�gime moteur mesur� sur une phase moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_IF_GLOBAL_16BIT UInt16 DfwCtl_Ext_rCluPHiFreq_in /* 
   Unit       : %
   Description: Information fine de la course d'�metteur embrayage
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT SInt16 DfwCtl_Ext_tCoMes_in /* 
   Unit       : �C
   Description: Information standard SSTG Temp�rature d'eau 
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 DfwCtl_PredEs_nFast_in /* 
   Unit       : RPM
   Description: R�gime rapide
   LSB: 2^0 OFF:  0 MIN/MAX:  -500 .. 1000 */;
extern AR_IF_GLOBAL_16BIT UInt16 DfwCtl_Veh_spdVeh_in /* 
   Unit       : km/h
   Description: Vitesse v�hicule
   LSB: 2^-7 OFF:  0 MIN/MAX:  0 .. 500 */;
extern AR_IF_GLOBAL_16BIT UInt16 DfwCtl_noOverOscDetProtAcv_out /* 
   Description: Aggravated resonance detection number
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 65535 */;
extern AR_IF_GLOBAL_16BIT UInt16 DfwCtl_noProtAdp_out /* 
   Description: Resonance detection number
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 65535 */;

#define DFWCTL_STOP_SEC_GLOBAL_16BIT
#include "DfwCtl_MemMap.h"

#define DFWCTL_START_SEC_GLOBAL_8BIT
#include "DfwCtl_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 DfwCtl_CoStrtRStrt_stEngStrtReq_in /* 
   Description: Synth�se des demandes de d�marrage et red�marrage pour le MTH
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;

#define DFWCTL_STOP_SEC_GLOBAL_8BIT
#include "DfwCtl_MemMap.h"

#define DFWCTL_START_SEC_GLOBAL_BOOLEAN
#include "DfwCtl_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_Afts_bRstDfwChg_in /* 
   Description: DoubleFlyWheel changing flag
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_CoSync_bDetNNull_in /* 
   Description: D�tection d'un r�gime nul
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_Ext_bCluPedPrss_in /* 
   Description: Information switch d'embrayage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_Ext_bDirRotCk_in /* 
   Description: Sens de rotation (Si capteur bidirectionnel)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_FRM_bInhOscDet_in /* 
   Description: Oscillation detection inhibition flag
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_PredEs_bVldFastN_in /* 
   Description: Validation du calcul du r�gime rapide
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_bAcvLimTqIdl_out /* 
   Description: Limitation torque request activation flag
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_bDgoProtAdp_out /* 
   Description: DFW protection diagnosis result
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_bInhInjProtDfw_out /* 
   Description: Cut off injection request activation flag
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean DfwCtl_bMonRunProtAdp_out /* 
   Description: DFW protection diagnosis activation flag
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define DFWCTL_STOP_SEC_GLOBAL_BOOLEAN
#include "DfwCtl_MemMap.h"

#define DFWCTL_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "DFWCTL_MemMap.h"

/******************************************************************************\
   AR_EXT_VAR_SAVED_Z1CST_16BIT: Non Volatile memory 16bits const structure Zone 1 for AUTOSAR modul
   es | Width: N.A.
\******************************************************************************/
//extern AR_EXT_VAR_SAVED_Z1CST_16BIT Struct_CONST_16BIT DfwCtl_sNV_Z1_CST_16BIT;

#define DFWCTL_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "DFWCTL_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void DfwCtl_001_MSE_ini(Void);
extern Void DfwCtl_002_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void DfwCtl_FctVarInit(Void);


#endif/*_DFWCTL_002_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
