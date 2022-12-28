/**************************************************************************************************\
 *** 
 *** Simulink model       : ProdElEng_07_1020_TL
 *** TargetLink subsystem : ProdElEng_07_1020_TL/ProdElEng_006
 *** Codefile             : prodeleng_006_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-05-23 09:15:43
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

#ifndef _PRODELENG_006_TEV_FCT_H_
#define _PRODELENG_006_TEV_FCT_H_

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

struct tag_SBFS_CordTqUHFrz_006_tp {
   unsigned int C0062_CALC : 1;
   unsigned int C0063_ACV : 1;
   unsigned int C0064_FREEZ : 1;
   unsigned int C0065_RELEASE : 1;
   unsigned int C0066_GrdLim : 1;
   unsigned int C0067_INIT : 1;
}; /* Type of structure containing bitfields for Stateflow chart  */
/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

#define PRODELENG_START_SEC_GLOBAL_16BIT
#include "ProdElEng_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT SInt16 ProdElEng_006_TqCmp_tqAltLoss_in /* 
   Unit       : N.m
   Description: Couple pr�lev� par l'alternateur 
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;

#define PRODELENG_STOP_SEC_GLOBAL_16BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_GLOBAL_8BIT
#include "ProdElEng_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEng_006_CoPTSt_stEng_in /* 
   Unit       : -
   Description: Etat moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 15 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEng_006_TqLimUH_stReqUnBlsVoltCtl_in /* 
   Unit       : -
   Description: Demande de d�lestage Volt Control
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;

#define PRODELENG_STOP_SEC_GLOBAL_8BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_GLOBAL_BOOLEAN
#include "ProdElEng_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEng_006_FRM_bInhTqLimUHTqMchFrz_in /* 
   Description: Inhibition de la requ�te de figeage Couple AltR UH
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_ProdElEng_006_TEV_TqSys_bTqAltFrzReq_in /* 
   Description: Demande coordonn�e de figeage du couple AltR 
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_ProdElEng_006_TEV_TqSys_bTqAltRlsReq_in /* 
   Description: Demande coordonn�e de d�lestage AltR
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define PRODELENG_STOP_SEC_GLOBAL_BOOLEAN
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_GLOBAL_BOOLEAN
#include "ProdElEng_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN_IRV: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern Boolean TqLimUH_bESPUnBlsAltReq /* 
   Description: Flag � vrai si une demande de d�lestage AltR est effective
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern Boolean TqLimUH_bOutFrzUHGrdLim /* 
   Description: Flag � vrai si une demande de limitation de gradient couple AltR est effective
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern Boolean TqLimUH_bTqAltFrzReq /* 
   Description: Flag � vrai si une demande de figeage couple AltR est effective
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define PRODELENG_STOP_SEC_GLOBAL_BOOLEAN
#include "ProdElEng_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void ProdElEng_005_MSE_ini(Void);
extern Void ProdElEng_006_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void ProdElEng_006_FctVarInit(Void);


#endif/*_PRODELENG_006_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/