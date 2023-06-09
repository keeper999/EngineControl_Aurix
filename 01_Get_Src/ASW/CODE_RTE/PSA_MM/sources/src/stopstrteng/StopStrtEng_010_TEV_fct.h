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
 ***  %name: StopStrtEng_010_TEV_fct.h %
 *** 
 ***  %version: 5.2.build1 %
 *** 
 ***  %date_modified: Fri Apr 27 11:50:36 2012 %
 *** 
 *** 
 ***  %derived_by: u349799 %
 ***  %release: StopStrtEng/5.0 %
 ***  %full_filespec: StopStrtEng_010_TEV_fct.h-5.2.build1:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : CSCT_CGMT09_1660_4_0
 *** TargetLink subsystem : CSCT_CGMT09_1660_4_0/StopStrtEng_010
 *** Codefile             : stopstrteng_010_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2012-04-27 09:42:44
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
 *** Style definition file               : C:\dSPACE_TL_3.0.1\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE_TL_3.0.1\Matlab\Tl\XML\CodeGen\Stylesheets\TL_C
 ***                                       SourceCodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _STOPSTRTENG_010_TEV_FCT_H_
#define _STOPSTRTENG_010_TEV_FCT_H_

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

#define STOPSTRTENG_START_SEC_GLOBAL_8BIT
#include "StopStrtEng_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 CoStrtRStrt_stAcvReq_out /* 
   Description: Synth�se des consignes de d�marrage et red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStrtRStrt_stEngStrtReq_out /* 
   Description: Synth�se des demandes de d�marrage et red�marrage pour le MTH
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStrtRStrt_stStopCutReq_out /* 
   Description: Synth�se des demandes d'arr�t et de coupure pour le MTH
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_IF_GLOBAL_8BIT UInt8 StopStrtEng_010_CoEmSTT_tiVSSTmrStrtAuth_in /* 
   Unit       : s
   Description: Dur�e souhait�e de mise en s�rie du DMT pour un premier d�marrage
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 6.3 */;
extern AR_IF_GLOBAL_8BIT UInt8 StopStrtEng_010_CoPTStNew_stEng_in /* 
   Description: Nouvel �tat moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 9 */;

#define STOPSTRTENG_STOP_SEC_GLOBAL_8BIT
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_GLOBAL_BOOLEAN
#include "StopStrtEng_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStrtRStrt_bInh_out /* 
   Description: Synth�se des inhibitions de d�marrage et red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStrtRStrt_bVSSNwAcvAuth_out /* 
   Description: Synth�se des autorisations de maintien DMTR
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_StopStrtEng_010_TEV_CoPTSt_bEngStopReq_in /* 
   Description: Demande v�hicule de coupure moteur valid�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_StopStrtEng_010_TEV_CoPTSt_bEngStrtGlblReq_in /* 
   Description: Demande de d�marrage GMP vers moteur Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_StopStrtEng_010_TEV_CoSTT_bEngCutOffReq_in /* 
   Description: Demande valid�e de coupure moteur STT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_StopStrtEng_010_TEV_CoSTT_bEngRStrtReq_in /* 
   Description: Demande STT  de red�marrage du moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_StopStrtEng_010_TEV_CoSTT_bEngStopReq_in /* 
   Description: Demande valid�e d'arr�t moteur STT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_StopStrtEng_010_TEV_CoStrt_bStrtReq_in /* 
   Description: Flux de commande du premier d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_StopStrtEng_010_TEV_StopStrtEng_bVSSNwAcvAuth_in /* 
   Description: Autorisation de maintien DMTR venant du DAGMP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_Afts_bSpcFactOffDeacInh_in /* 
   Description: Interdiction mode sp�cifique pour Inhibition Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_Afts_bSpcFactOnDeacInh_in /* 
   Description: Interdiction mode sp�cifique pour Inhibition Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtASE_bAltRStrtTypASEReq_in /* 
   Description: Demande de sortie calage type red�marrage pour l'alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtASE_bAltStrtTypASEReq_in /* 
   Description: Demande de sortie calage type d�marrage pour l'alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtASE_bCdnInhRStrt_in /* 
   Description: Condition d'inhibition pour sortie calage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtASE_bEngCutOffReq_in /* 
   Description: Demande de coupure du moteur thermique par la fonction Sortie Calage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtASE_bEngRStrtTypASEReq_in /* 
   Description: Demande de sortie calage type red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtASE_bEngStallReq_in /* 
   Description: Demande de calage par la fonction Sortie Calage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtASE_bEngStrtTypASEReq_in /* 
   Description: Demande de sortie calage type d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtASE_bVSSNwAcvAuth_in /* 
   Description: Autorisation de maintien DMTR venant de la fonction Sortie Calage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtUH_bAltRStrtReq_in /* 
   Description: Demande de Red�marrage pour l'alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtUH_bCdnInhRStrt_in /* 
   Description: Condition Inhibition du red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoPtUH_bVSSNwAcvAuth_in /* 
   Description: Autorisation de maintien DMTR
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_CoStrt_bStrtAuth_in /* 
   Description: Flux d'autorisation du premier d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_010_ECU_bWkuMain_in /* 
   Description: Etat de r�veil principal ou principal d�grad� du CMM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define STOPSTRTENG_STOP_SEC_GLOBAL_BOOLEAN
#include "StopStrtEng_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void StopStrtEng_009_MSE_ini(Void);
extern Void StopStrtEng_010_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void StopStrtEng_010_FctVarInit(Void);


#endif/*_STOPSTRTENG_010_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
