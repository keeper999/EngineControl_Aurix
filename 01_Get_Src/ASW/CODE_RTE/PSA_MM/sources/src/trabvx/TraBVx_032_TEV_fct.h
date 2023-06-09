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
* %name: TraBVx_032_TEV_fct.h %
*
* %version: 14.0.build1 %
*
* %date_modified: Tue Jun 19 10:10:47 2012 %
*
*
* %derived_by: u391752 %
* %release: TqStruct/14.0 %
* %full_filespec: TraBVx_032_TEV_fct.h-14.0.build1:incl:2 %
*
*******************************************************************************/
/**************************************************************************************************\
 *** 
 *** Simulink model       : RE_032
 *** TargetLink subsystem : RE_032/F00_Regulation_Regime_BV
 *** Codefile             : trabvx_032_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2012-01-19 16:22:50
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

#ifndef _TRABVX_032_TEV_FCT_H_
#define _TRABVX_032_TEV_FCT_H_

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

#define TRABVX_START_SEC_GLOBAL_16BIT
#include "TraBVx_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT SInt16 CoPt_tqIdcAirCord_nCross_out /* 
   Unit       : N.m
   Description: Couple indiqu� air coordonn� avec la demande de relance en r�gime et la fonction de 
   croisement de r�gime
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT SInt16 CoPt_tqIdcAirGslCord_nReg_out /* 
   Unit       : N.m
   Description: Couple air coordonn� avec les demandes de relance boite
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT SInt16 Re_TraBVx_032_TEV_CoPt_nErrNReg_irv_out /* 
   Unit       : N.m
   Description: Ecart de r�gime de r�gulation
   LSB: 2^0 OFF:  0 MIN/MAX:  -8000 .. 8000 */;
extern AR_IF_GLOBAL_16BIT SInt16 Re_TraBVx_032_TEV_CoPt_tqIdcNReg_irv_in /* 
   Unit       : N.m
   Description: Couple de r�gulation de r�gime boite
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT SInt16 Re_TraBVx_032_TEV_CoPt_tqIniNReg_irv_out /* 
   Unit       : N.m
   Description: Couple de r�gulation de r�gime boite pour la branche lente
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT UInt16 TraBVx_032_CoPt_nTar_in /* 
   Unit       : RPM
   Description: R�gime cible en r�gulation par la BV
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
extern AR_IF_GLOBAL_16BIT UInt16 TraBVx_032_CoPt_nTrb_in /* 
   Unit       : RPM
   Description: R�gime turbine
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
extern AR_IF_GLOBAL_16BIT SInt16 TraBVx_032_CoPt_tqIdcAirCordLim_tqGBx_in /* 
   Unit       : N.m
   Description: Couple issu des limitations statiques BV, converti en CMI
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT SInt16 TraBVx_032_CoPt_tqIdcAirMaxGBx_in /* 
   Unit       : N.m
   Description: Couple indiqu� max admissible par la BVA branche air
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT UInt16 TraBVx_032_CoVSCtl_rAccPEngTrv_in /* 
   Unit       : %
   Description: Position p�dale coordonn�e
   LSB: 2^-7 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT UInt16 TraBVx_032_Ext_nEng_in /* 
   Unit       : RPM
   Description: R�gime moteur au PMH
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_IF_GLOBAL_16BIT SInt16 TraBVx_032_TqCmp_tqSumLossCmp_in /* 
   Unit       : N.m
   Description: Couple de pertes globales � compenser
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT SInt16 TraBVx_032_TqEst_tqIdcStrt_in /* 
   Unit       : N.m
   Description: Couple moyen indiqu� r�el estim� lors de la phase de d�marrage
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;

#define TRABVX_STOP_SEC_GLOBAL_16BIT
#include "TraBVx_MemMap.h"

#define TRABVX_START_SEC_GLOBAL_8BIT
#include "TraBVx_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 Re_TraBVx_032_TEV_CoPt_noTypPIDGain_irv_in /* 
   Description: Type de r�gulation de r�gime
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 4 */;
extern AR_IF_GLOBAL_8BIT SInt8 TraBVx_032_CoPt_noEgdGearCordIt_in /* 
   Description: Rapport de boite engag� coordonn� pour la structure couple
   LSB: 2^0 OFF:  0 MIN/MAX:  -1 .. 8 */;
extern AR_IF_GLOBAL_8BIT SInt8 TraBVx_032_CoPt_noTarGearCordIt_in /* 
   Description: Rapport cible
   LSB: 2^0 OFF:  0 MIN/MAX:  -1 .. 8 */;
extern AR_IF_GLOBAL_8BIT UInt8 TraBVx_032_Ext_stTraTypCf_in /* 
   Description: Type de boite automatique ou pilot�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_IF_GLOBAL_8BIT UInt8 TraBVx_032_TqSys_idxTqAccu_in /* 
   Description: Indice de pr�cision de couple
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 10 */;

#define TRABVX_STOP_SEC_GLOBAL_8BIT
#include "TraBVx_MemMap.h"

#define TRABVX_START_SEC_GLOBAL_BOOLEAN
#include "TraBVx_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean Re_TraBVx_032_TEV_CoPt_bInhNCross_irv_in /* 
   Description: Demande d'inhibition de la strat�gie de croisement de r�gime
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean Re_TraBVx_032_TEV_CoPt_bVldAcvNReg_irv_in /* 
   Unit       : N.m
   Description: Couple de r�gulation de r�gime boite
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean TraBVx_032_CoPt_bAcvNCross_in /* 
   Description: Strat�gie de croisement de r�gime activ�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean TraBVx_032_CoPt_bAcvNRegReq_in /* 
   Description: Demande d'activation de la r�gulation de r�gime
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean TraBVx_032_TqSys_bTqSysAcv_in /* 
   Description: Structure couple active
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean TraBVx_032_TqSys_bTypFu_in /* 
   Description: Type de carburant
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define TRABVX_STOP_SEC_GLOBAL_BOOLEAN
#include "TraBVx_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void TraBVx_032_MSE_ini(Void);
extern Void TraBVx_032_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void TraBVx_032_FctVarInit(Void);

#endif/*_TRABVX_032_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
