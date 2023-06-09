/**************************************************************************************************\
 ***
 *** Simulink model       : CSMT_CGMT06_2171_v3_0
 *** TargetLink subsystem : CSMT_CGMT06_2171_v3_0/F00_Calcul_Initial_PMH
 *** Codefile             : tqtreat_008_dre_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-01-28 09:44:34
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
 *** TargetLink version      : 3.0.1_RC3 from 13-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _TQTREAT_008_DRE_FCT_H_
#define _TQTREAT_008_DRE_FCT_H_

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

#define TQTREAT_START_SEC_GLOBAL_16BIT
#include "TqTreat_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 TqTreat_008_Ext_nEng_in /*
   Unit       : RPM
   Description: R�gime moteur mesur� sur une phase moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_IF_GLOBAL_16BIT UInt16 TqTreat_008_TqDem_facGainFilTrv_nCk_in /* 
   Unit       : -
   Description: Gain de filtrage du r�gime moteur
   LSB: 2^-10 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_16BIT UInt16 TreatTDC_nCkFil_out /*
   Unit       : RPM
   Description: R�gime moteur filtr� au PMH
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
extern AR_IF_GLOBAL_16BIT SInt16 TreatTDC_nCkGrdFil_out /*
   Unit       : RPM/s
   Description: D�riv�e filtr�e de r�gime moteur au PMH
   LSB: 2^-2 OFF:  0 MIN/MAX:  -8000 .. 8000 */;
extern AR_IF_GLOBAL_16BIT SInt16 TreatTDC_nCkGrd_out /*
   Unit       : RPM/s
   Description: D�riv�e de r�gime moteur au PMH
   LSB: 2^-2 OFF:  0 MIN/MAX:  -8000 .. 8000 */;
extern AR_IF_GLOBAL_16BIT SInt16 TreatTDC_nCkTDCDelta_out /*
   Unit       : RPM
   Description: Gradient de R�gime moteur au PMH
   LSB: 2^-2 OFF:  0 MIN/MAX:  -8000 .. 8000 */;

#define TQTREAT_STOP_SEC_GLOBAL_16BIT
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_GLOBAL_8BIT
#include "TqTreat_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 TqTreat_008_Ext_tiTDC_in /*
   Unit       : s
   Description: Temps entre 2 PMH (1/2 tour moteur)
   LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 0.1 */;

#define TQTREAT_STOP_SEC_GLOBAL_8BIT
#include "TqTreat_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void TqTreat_007_MSE_ini(Void);
extern Void TqTreat_008_DRE_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other modules)
\******************************************************************************/
extern Void TqTreat_007_FctVarInit(Void);


#endif/*_TQTREAT_008_DRE_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
