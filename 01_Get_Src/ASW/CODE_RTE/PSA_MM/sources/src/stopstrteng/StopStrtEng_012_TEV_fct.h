/**************************************************************************************************\
 *** 
 *** Simulink model       : CSCT_CGMT09_3185_2_0
 *** TargetLink subsystem : CSCT_CGMT09_3185_2_0/F0_CSCT_CGMT09_3185
 *** Codefile             : stopstrteng_012_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-05-11 10:59:53
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
 *** TargetLink version      : 3.0.1_RC3 from 13-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _STOPSTRTENG_012_TEV_FCT_H_
#define _STOPSTRTENG_012_TEV_FCT_H_

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
extern AR_IF_GLOBAL_8BIT UInt8 StopStrtEng_012_Ext_stFuTypCf_in /* 
   Description: Type de carburant
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;

#define STOPSTRTENG_STOP_SEC_GLOBAL_8BIT
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_GLOBAL_BOOLEAN
#include "StopStrtEng_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_StopStrtEng_012_TEV_StaCtl_bPTProt_in /* 
   Description: Protection GMP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaCtl_bEngPrepAcv /* 
   Description: Pr�paration moteur active
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaCtl_bEngPrepEngAuth /* 
   Description: Autorisation du moteur de lancer le d�marrage car la pr�paration est termin�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaCtl_bEngRunPrepReq /* 
   Description: Demande de d�marrage pour besoin pr�paration moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaCtl_bEngStrtAuth /* 
   Description: Autorisation de d�marrer
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaCtl_bPrepStrtAuth /* 
   Description: Autorisation de lancer le d�marrage car la pr�paration est termin�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_012_CoEmCkg_bWaitStrtReq_in /* 
   Description: Mise en attente du d�marrage / Demande d'allumage voyant "Pr�chauffage" du SEEM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_012_CoPTSt_bMainEngStopReq_in /* 
   Description: Demande d'arr�t moteur valid�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_012_Ext_bGslEngPrepReq_in /* 
   Description: Besoin de pr�paration pour les moteurs essence
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_012_FRM_bInhSta_in /* 
   Description: Demande de reconfiguration pour l'inhibition de l'activation du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_012_GlwCtl_bEngRunAuth_in /* 
   Description: Autorisation du d�marrage du MTH
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_012_GlwCtl_bEngRunReq_in /* 
   Description: Besoin de d�marrage du moteur thermique par les bougies
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_012_Sfty_bInhDrvTraSfty_in /* 
   Description: Flux s�curitaire emp�chant le d�marrage
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
extern Void StopStrtEng_011_MSE_ini(Void);
extern Void StopStrtEng_012_TEV_fct(Void);


#endif/*_STOPSTRTENG_012_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
