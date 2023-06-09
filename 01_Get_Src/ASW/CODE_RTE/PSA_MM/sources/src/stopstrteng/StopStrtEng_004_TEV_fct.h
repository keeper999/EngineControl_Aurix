/**************************************************************************************************\
 *** 
 *** Simulink model       : CSMT_CGMT07_1415_2_0
 *** TargetLink subsystem : CSMT_CGMT07_1415_2_0/StopStrtEng_004
 *** Codefile             : stopstrteng_004_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-06-07 10:22:07
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
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _STOPSTRTENG_004_TEV_FCT_H_
#define _STOPSTRTENG_004_TEV_FCT_H_

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

#define STOPSTRTENG_START_SEC_GLOBAL_16BIT
#include "StopStrtEng_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 StopStrtEng_004_Ext_nEng_in /* 
   Description: R�gime moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_IF_GLOBAL_16BIT UInt16 StopStrtEng_004_Ext_rCluPHiFreq_in /* 
   Unit       : %
   Description: Position de la commande d'embrayage Haute Fr�quence
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;

#define STOPSTRTENG_STOP_SEC_GLOBAL_16BIT
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_GLOBAL_8BIT
#include "StopStrtEng_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 CoPTSt_stDrvTra_out /* 
   Description: Information sur l'�tat de la cha�ne de traction
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_IF_GLOBAL_8BIT UInt8 StopStrtEng_004_Ext_stGBxCf_in /* 
   Description: D�finit le type de boite de vitesse / Defines the gearbox type - 0:BVM 1:BVA 2:BVMP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_IF_GLOBAL_8BIT UInt8 StopStrtEng_004_Ext_stStrtCf_in /* 
   Description: Type de d�marrage : comprend le type de cl� et si le d�marrage est impulsionnel ou m
   aintenu
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define STOPSTRTENG_STOP_SEC_GLOBAL_8BIT
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_GLOBAL_BOOLEAN
#include "StopStrtEng_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPTSt_bDgoSftyORngAMT_out /* 
   Description: Passe � 1 lorsqu'il y a incoherence entre l'information filaire et l'information CAN
    venant de la AMT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPTSt_bDgoSftyORngAT_out /* 
   Description: Passe � 1 lorsqu'il y a incoherence entre l'information filaire et l'information CAN
    venant de la AT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPTSt_bMonRunSftyORngAMT_out /* 
   Description: Etat du diagnostic liee aux incoherences entre les messages venant de la AMT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPTSt_bMonRunSftyORngAT_out /* 
   Description: Etat du diagnostic liee aux incoherences entre les messages venant de la AT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_004_ECU_bWkuMain_in /* 
   Description: Etat de r�veil principal ou principal degrade du CMM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_004_Ext_bATParkNeut_in /* 
   Description: Indique en filaire si le levier de vitesse de la AT est en position Park ou Neutre
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_004_Ext_bCluPedPrss_in /* 
   Description: Bool�en position embrayage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_004_Ext_bDgoSenPN_in /* 
   Description: D�faut contact PN
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_004_Ext_bDrvTraAMT_in /* 
   Description: indique en filaire si l'embrayage de la AMT est ouvert
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_004_Ext_bInhStrtAMT_in /* 
   Description: Interdiction d�marrage BVMP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEng_004_FRM_bAcvDrvTraInvld_in /* 
   Description: Flag de reconfiguration dans le cas dysfonctionnel
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
extern Void StopStrtEng_003_MSE_ini(Void);
extern Void StopStrtEng_004_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void StopStrtEng_004_FctVarInit(Void);


#endif/*_STOPSTRTENG_004_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
