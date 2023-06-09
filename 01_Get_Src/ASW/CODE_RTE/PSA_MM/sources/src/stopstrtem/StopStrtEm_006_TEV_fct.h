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
 ***  %name: StopStrtEm_006_TEV_fct.h %
 *** 
 ***  %version: 4.1 %
 *** 
 ***  %date_modified: Thu Jan  5 11:29:29 2012 %
 *** 
 *** 
 ***  %derived_by: e375697 %
 ***  %release: StopStrtEm/4.0 %
 ***  %full_filespec: StopStrtEm_006_TEV_fct.h-4.1:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : StopStrtEm_006
 *** TargetLink subsystem : StopStrtEm_006/StopStrtEm_006
 *** Codefile             : stopstrtem_006_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2012-01-06 16:57:37
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
 *** Style definition file               : C:\Dspace301\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\Dspace301\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSource
 ***                                       CodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _STOPSTRTEM_006_TEV_FCT_H_
#define _STOPSTRTEM_006_TEV_FCT_H_

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

#define STOPSTRTEM_START_SEC_GLOBAL_16BIT
#include "StopStrtEm_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 StaRstrtMgt_nStaEgdHiThd_out /* 
   Unit       : RPM
   Description: R�gime maxi pour engager depuis la commande d'engagement
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 500 */;
extern AR_IF_GLOBAL_16BIT UInt16 StaRstrtMgt_nStaEgdLoThd_out /* 
   Unit       : RPM
   Description: R�gime mini pour engager depuis la commande d'engagement
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 500 */;
extern AR_IF_GLOBAL_16BIT SInt16 StopStrtEm_006_CoEmCkg_nFast_in /* 
   Unit       : RPM
   Description: R�gime rapide renvoy� par CoEmCkg
   LSB: 2^0 OFF:  0 MIN/MAX:  -500 .. 1000 */;
extern AR_IF_GLOBAL_16BIT UInt16 StopStrtEm_006_Eng_nCkFil_in /* 
   Unit       : RPM
   Description: R�gime moteur filtr� envoy� � 10ms
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
extern AR_IF_GLOBAL_16BIT UInt16 StopStrtEm_006_Ext_nEng_in /* 
   Unit       : RPM
   Description: R�gime Moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_IF_GLOBAL_16BIT SInt16 StopStrtEm_006_Ext_tCoMes_in /* 
   Unit       : �C
   Description: Temp�rature eau moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 StopStrtEm_006_Ext_uBattMes_in /* 
   Unit       : V
   Description: Tension de la batterie 12V (CMM)
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 32 */;
extern AR_IF_GLOBAL_16BIT UInt16 StopStrtEm_006_StaStrtMgt_tiMaxAcv_in /* 
   Unit       : s
   Description: Temps maximum d'activation d�marreur
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 200 */;
extern AR_IF_GLOBAL_16BIT UInt16 StopStrtEm_006_StaStrtMgt_tiStaAcvCnt_in /* 
   Unit       : s
   Description: Temps du compteur d'activation du d�marreur
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1200 */;

#define STOPSTRTEM_STOP_SEC_GLOBAL_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_GLOBAL_32BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_32BIT: Global 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_IF_GLOBAL_32BIT UInt32 StopStrtEm_006_StaStrtMgt_ctStaAcv_in /* 
   Unit       : -
   Description: Compteur du nombre d'activation du moteur du d�marreur pour le d�marrage et le red�m
   arrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000000 */;

#define STOPSTRTEM_STOP_SEC_GLOBAL_32BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_GLOBAL_8BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 StaRstrtMgt_stStaRstrtFbCmd_out /* 
   Description: Retour de commande du d�marreur pour le red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_IF_GLOBAL_8BIT UInt8 StaRstrtMgt_tiStaEgdHiThd_out /* 
   Unit       : s
   Description: Temps maxi pour engager depuis la commande d'engagement
   LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 0.25 */;
extern AR_IF_GLOBAL_8BIT UInt8 StaRstrtMgt_tiStaEgdLoThd_out /* 
   Unit       : s
   Description: Temps mini pour engager depuis la commande d'engagement
   LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 0.25 */;
extern AR_IF_GLOBAL_8BIT UInt8 StopStrtEm_006_Ext_stFuTypCf_in /* 
   Description: type de combustible
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_IF_GLOBAL_8BIT UInt8 StopStrtEm_006_Ext_stVSSCf_in /* 
   Description: Configuration du DMT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define STOPSTRTEM_STOP_SEC_GLOBAL_8BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_GLOBAL_BOOLEAN
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean StaRstrtMgt_bDftElCmd_out /* 
   Description: D�faut sur la commande �lectrique du d�marreur au red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaRstrtMgt_bInfoCplReq_out /* 
   Description: Information demande d'engagement du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaRstrtMgt_bInfoCplSt_out /* 
   Description: Information �tat d'engagement du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaRstrtMgt_bInfoStaRun_out /* 
   Description: Information red�marrage en cours
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaRstrtMgt_bProt10StopInh_out /* 
   Description: Inhibition du stop par la protection 10 red�marrage du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaRstrtMgt_bRstrtProt10_out /* 
   Description: Protection 10 active pour le red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaRstrtMgt_bRstrtProt4_out /* 
   Description: Protection 4 active pour le red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StaRstrtMgt_bStaReq_out /* 
   Description: Autorisation de red�marrage : repr�sente l'activation du d�marreur en AEE2004 et l'a
   utorisation d'activation du d�marreur en AEE2010
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_CoEmCkg_bDetSlowN_in /* 
   Description: D�tection de r�gime faible compris entre 2 seuils renvoy� par CoEmCkg
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_CoEmCkg_bStaRstrtReq_in /* 
   Description: Demande de d�marrage par d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_CoEmCkg_bVldFastN_in /* 
   Description: Validation du calcul du r�gime rapide renvoy� par CoEmCkg
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_CoEmSTT_bVSSAcvSt_in /* 
   Description: Etat du maintien du DMT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_CoSync_bStuckEngStaAcv_in /* 
   Description: Risque moteur bloqu� et machine �lectrique active
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_ECU_bWkuMain_in /* 
   Description: Etat de r�veil principal ou principal degrade du CMM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_Ext_bArchiCf_in /* 
   Description: Type Architecture electrique
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_Ext_bSTTCf_in /* 
   Description: Activation de la fonction STT, par t�l�codage ou calibration
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_FRM_bAcvStaRstrtMgtDftValThd_in /* 
   Description: Flag de reconfiguration activant l'utilisation d'une valeur par d�faut pour les seui
   ls fonctions de la temp�rature d'eau moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_FRM_bAcvStaRstrtMgtDiagElCmd_in /* 
   Description: Flag de reconfiguration activant le diagnostic sur les probl�mes �lectriques � la so
   rtie du CMM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean StopStrtEm_006_FRM_bInhStaRstrtMgtVoltFall_in /* 
   Description: Flag de reconfiguration inhibant la strat�gie de d�tection de chute de tension
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define STOPSTRTEM_STOP_SEC_GLOBAL_BOOLEAN
#include "StopStrtEm_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void StopStrtEm_005_MSE_ini(Void);
extern Void StopStrtEm_006_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void StopStrtEm_006_FctVarInit(Void);


#endif/*_STOPSTRTEM_006_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
