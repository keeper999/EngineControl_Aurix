/**************************************************************************************************\
 *** 
 *** Simulink model       : MgtASECut_01460_10_02173_TL
 *** TargetLink subsystem : MgtASECut_01460_10_02173_TL/ASE_008
 *** Codefile             : ase_008_calibrations.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-05-20 11:10:09
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

#ifndef _ASE_008_CALIBRATIONS_H_
#define _ASE_008_CALIBRATIONS_H_

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

#define ASE_START_SEC_CALIB_16BIT
#include "ASE_MemMap.h"
/******************************************************************************\
   AR_MERGEABLE_CALIB_16BIT: Mergeable Calib 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_MERGEABLE_CALIB_16BIT UInt16 MgtASECut_spdEngCutOffReq_C /* 
   Unit       : km/h
   Description: Seuil de vitesse pour coupure SCAr
   LSB: 2^-7 OFF:  0 MIN/MAX:  0 .. 500 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 MgtASECut_spdRstrtAuth_C /* 
   Unit       : km/h
   Description: Seuil de vitesse pour red�marrage de classe 3
   LSB: 2^-7 OFF:  0 MIN/MAX:  0 .. 50 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 MgtASECut_tiDlyWait1_C /* 
   Unit       : s
   Description: Temps minimum � partir duquel une demande de coupure est valid�e en �tat Cal� ou Cal
   age en cours sur maintien d'une demande de red�marrage automatique de classe 1 (Tattente1)
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 180 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 MgtASECut_tiDlyWait2_C /* 
   Unit       : s
   Description: Temps minimum � partir duquel une demande de coupure est valid�e en �tat Cal� ou Cal
   age en cours sur maintien d'une demande de red�marrage automatique de classe 2 (Tattente2)
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 5 */;

#define ASE_STOP_SEC_CALIB_16BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_CALIB_8BIT
#include "ASE_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_8BIT UInt8 MgtASECut_stModAcvCutCoPtUH_C /* 
   Description: Traitement bool�en de la demande de coupure si moteur en stop (FRM type 3)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 MgtASECut_stModRstrtMchAuth_C /* 
   Description: Traitement bool�en de l'autorisation boite de vitesse pour le pilotage MEL en red�ma
   rrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 MgtASECut_tiDlyCutReq1_C /* 
   Unit       : s
   Description: Temps minimum � partir duquel une demande de coupure par Sous Ensemble Electro Moteu
   r ou V�hicule est valid�e (Tmax1)
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 MgtASECut_tiDlyCutReq2_C /* 
   Unit       : s
   Description: Temps minimum � partir duquel une demande de coupure est valid�e sans l'autorisation
    de red�marrage Chaine de Traction (Tmax2)
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 MgtASECut_tiDlyCutReqIni_C /* 
   Unit       : s
   Description: Temporisation pour initialisation de la demande de coupure en Off
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 0.1 */;

#define ASE_STOP_SEC_CALIB_8BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_CALIB_8BIT
#include "ASE_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_EXT_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoASE_stModDrvTraOp_C /* 
   Description: Traitement bool�en de l'�tat de la Chaine de Traction 
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoStall_stModAcvCutCoPtASE_C /* 
   Description: Traitement bool�en de la demande de coupure si moteur cal� (FRM SCAr type 3)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define ASE_STOP_SEC_CALIB_8BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_CALIB_BOOLEAN
#include "ASE_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_BOOLEAN: Mergeable Calib 1 bit for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean MgtASECut_bAcvHiSpdEngCutReq_C /* 
   Description: Activation de la strat�gie de demande de coupure SCAr sur vitesse haute
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean MgtASECut_bElMecIntrRstrt_C /* 
   Description: Gestion Multishoot Sous Ensemble Electro Moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define ASE_STOP_SEC_CALIB_BOOLEAN
#include "ASE_MemMap.h"

#define ASE_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ASE_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_BOOLEAN: Display Boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bAcvCutCoPtASE /*
   Description: Reconfiguration SCA type 3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bAcvCutCoPtUH /*
   Description: Reconfiguration type 3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bDrvTraOp /*
   Description: Etat CDT (Autorisation de red�marrage par sous-syst�me CdT) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngASEHiReq_MP /*
   Description: Demande de red�marrage de classe 3 ou 4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutOffReqASE /*
   Description: Demande coupure en Etat GMP SCA en Sortie calage */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutOffReqCutIp /*
   Description: Demande coupure en Etat GMP SCA en Coupure en cours */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutOffReqOff /*
   Description: Demande coupure en Etat GMP SCA Off */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutOffReqStall /*
   Description: Demande coupure en Etat GMP SCA Cal� et Calage ec */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutOffReqSynt /*
   Description: Synth�se des demandes de Coupure hors Tempo Tattente1 et 2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutReqASE31_MP /*
   Description: Temporisation d'attente 1 ou 2 �coul�e OU pas d'autorisation d'entr�e en SCAr */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutReqASE32_MP /*
   Description: Pas d'autorisation de red�marage moteur OU temporisation de red�marrage manqu� �coul
   �e OU pr�sence d'une demande de red�marrage de classe 3 ou 4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutReqASE3_MP /*
   Description: 3�me condition de demande de coupure */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutReqOff_MP /*
   Description: Activation demande coupure en Etat GMP SCA Off */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bEngCutReqStall_MP /*
   Description: Activation demande coupure en Etat GMP SCA Cal� et Calage en cours */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bRstrtMchAuth /*
   Description: Autorisation boite de vitesse pour le pilotage MEL en red�marrage */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bWaitTmp1 /*
   Description: Temporisation d'attente 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bWaitTmp1Set_MP /*
   Description: Condition de lancement de la temporisation d'attente 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bWaitTmp1_MP /*
   Description: Lancement de la temporisation d'attente 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bWaitTmp2 /*
   Description: Temporisation d'attente 2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bWaitTmp2Set_MP /*
   Description: Condition de lancement de la temporisation d'attente 2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASECut_bWaitTmp2_MP /*
   Description: Lancement de la temporisation d'attente 2 */;

#define ASE_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ASE_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

#endif/*_ASE_008_CALIBRATIONS_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
