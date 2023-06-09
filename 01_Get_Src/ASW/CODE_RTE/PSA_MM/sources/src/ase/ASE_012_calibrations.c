/**************************************************************************************************\
 *** 
 *** Simulink model       : MgtASE_01460_10_02175_TL
 *** TargetLink subsystem : MgtASE_01460_10_02175_TL/ASE_012
 *** Codefile             : ase_012_calibrations.c
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-05-20 11:30:03
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
 *** Style definition file               : C:\dSPACE301\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE301\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSource
 ***                                       CodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** SUBSYS                   CORRESPONDING SIMULINK SUBSYSTEM
 *** S0121                    MgtASE_01460_10_02175_TL/ASE_012
 *** S0122                    ASE_012/F01_Traitement_booleen
 *** S0123                    ASE_012/F02_Gestion_Dde_Redem_SCAr_MTh
 *** S0124                    ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM
 *** S0125                    ASE_012/F01_Traitement_booleen/Traitement_booleen
 *** S0126                    ASE_012/F01_Traitement_booleen/Traitement_booleen1
 *** S0127                    ASE_012/F01_Traitement_booleen/Traitement_booleen2
 *** S0128                    ASE_012/F01_Traitement_booleen/Traitement_booleen3
 *** S0129                    ASE_012/F02_Gestion_Dde_Redem_SCAr_MTh/BasculeRS
 *** S01210                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/BasculeRS
 *** S01211                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay
 *** S01212                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay
 *** S01213                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1
 *** S01214                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/BasculeRSspecifiq
 ***                          ue
 *** S01215                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/DetectSat
 *** S01216                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Turnoffdelay_Part
 *** S01217                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/falling_edge
 *** S01218                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/rising_edge2
 *** S01219                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/BasculeRSspecifiqu
 ***                          e
 *** S01220                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/DetectSat
 *** S01221                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Turnondelay_Part
 *** S01222                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/rising_edge
 *** S01223                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/rising_edge2
 *** S01224                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/BasculeRSspecifiq
 ***                          ue
 *** S01225                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/DetectSat
 *** S01226                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Turnondelay_Part
 *** S01227                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/rising_edge
 *** S01228                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/rising_edge2
 *** 
 *** SF-NODE   CORRESPONDING STATEFLOW NODE                           DESCRIPTION
 *** 
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _ASE_012_CALIBRATIONS_C_
#define _ASE_012_CALIBRATIONS_C_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "ASE_012_calibrations.h"
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
AR_MERGEABLE_CALIB_16BIT UInt16 MgtASE_tiAltRstrtTypASEReq_C = 0 /* 
   Unit       : s
   Description: Tempo SCAr d�but maintien DMTR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 5 */;
AR_MERGEABLE_CALIB_16BIT UInt16 MgtASE_tiDlyVSSNwEndAcv_C = 200 /* 2. */ /* 
   Unit       : s
   Description: Tempo SCAr fin maintien DMTR 
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 10 */;

#define ASE_STOP_SEC_CALIB_16BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_CALIB_8BIT
#include "ASE_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_MERGEABLE_CALIB_8BIT UInt8 MgtASE_stModEngRstrtAutnAvl_C = 0 /* 
   Description: Traitement bool�en  de la Capacit� red�marrage Autonome en application Essence
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
AR_MERGEABLE_CALIB_8BIT UInt8 MgtASE_stModEngRstrtClsCluCdn_C = 0 /* 
   Description: Traitement bool�en de la condition de pilotage du red�marrage CdT ferm�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
AR_MERGEABLE_CALIB_8BIT UInt8 MgtASE_stModEngStrtSuc_C = 0 /* 
   Description: Traitement bool�en de Fin Besoin Assistance SEEM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
AR_MERGEABLE_CALIB_8BIT UInt8 MgtASE_stModRstrtAutnAvlPARM_C = 0 /* 
   Description: Traitement bool�en  de la Capacit� red�marrage Autonome en application Diesel
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
AR_MERGEABLE_CALIB_8BIT UInt8 MgtASE_tiCdnInhRstrt_C = 4 /* 0.04 */ /* 
   Unit       : s
   Description: Tempo condition d'inhibition pour sortie calage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 0.5 */;

#define ASE_STOP_SEC_CALIB_8BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ASE_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_BOOLEAN: Display Boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASE_bAltRstrtReqSet_MP /*
   Description: Set de la bascule lancement tempo demande de sortie calage type red�marrage pour l'a
   lternateur */;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASE_bAltRstrtTypASEReq_MP /*
   Description: Lancement tempo demande de sortie calage type red�marrage pour l'alternateur */;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASE_bEngRstrtAutnAvl /*
   Description: Capacit� red�marrage Autonome pour application Essence */;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASE_bEngRstrtClsCluCdn /*
   Description: Condition de pilotage du red�marrage CdT ferm�e apr�s traitement */;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASE_bEngRstrtTypASEReq_MP /*
   Description: Set de la bascule demande de sortie calage type red�marrage */;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASE_bEngStrtSuc /*
   Description: Signal indiquant que le d�marrage au sens large est r�ussi */;
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MgtASE_bRstrtAutnAvlPARM /*
   Description: Capacit� red�marrage Autonome pour application Diesel */;

#define ASE_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ASE_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INLINE FUNCTIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

#endif/*_ASE_012_CALIBRATIONS_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
