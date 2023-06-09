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
 ***  %name: ThMgt_004_calibrations.h %
 *** 
 ***  %version: 15.2.build1 %
 *** 
 ***  %date_modified: Fri Nov 15 09:48:19 2013 %
 *** 
 *** 
 ***  %derived_by: u299919 %
 ***  %release: ThMgt/14.2 %
 ***  %full_filespec: ThMgt_004_calibrations.h-15.2.build1:incl:3 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : mdl_100ms
 *** TargetLink subsystem : mdl_100ms/ThMgt
 *** Codefile             : thmgt_004_calibrations.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2013-11-14 15:20:51
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

#ifndef _THMGT_004_CALIBRATIONS_H_
#define _THMGT_004_CALIBRATIONS_H_

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

#define THMGT_START_SEC_CALIB_16BIT
#include "ThMgt_MemMap.h"
/******************************************************************************\
   AR_MERGEABLE_CALIB_16BIT: Mergeable Calib 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_agStrWhlInpByp_C /* 
   Unit       : �
   Description: Angle de volant
   LSB: 0.1 OFF:  0 MIN/MAX:  -780 .. 780 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_agvStrWhlInpByp_C /* 
   Unit       : deg/s
   Description: Vitesse de rotation de volant
   LSB: 2^2 OFF:  0 MIN/MAX:  0 .. 1060 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_facDecRateLimAntiBoil_C /* 
   Description: facteur de limitation de pente d�croissante du couple de limitation
   LSB: 2^0 OFF:  0 MIN/MAX:  -20000 .. 0 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_facIncRateLimAntiBoil_C /* 
   Description: facteur de limitation de pente croisasnte du couple de limitation
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 20000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_mfDsEGRCoEstimInpByp_C /* 
   Unit       : kg/h
   Description: D�bit de gaz EGR
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_mfEgDftThMgt_C /* 
   Unit       : kg/h
   Description: D�bit de gaz EGR
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_mfEgEstimInpByp_C /* 
   Unit       : kg/h
   Description: D�bit massique des gaz d'�chappement
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_nEngInpByp_C /* 
   Unit       : RPM
   Description: R�gime moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_pAirExtMesInpByp_C /* 
   Unit       : mBar
   Description: Pression atmosph�rique
   LSB: 2^0 OFF:  0 MIN/MAX:  500 .. 1500 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_rIntHiAdpKnkProt_C /* 
   Unit       : �C
   Description: Coefficient positif du filtrage
   LSB: 2^-10 OFF:  0 MIN/MAX:  -1 .. 1 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_rIntHiTAirKnkProt_C /* 
   Unit       : �C
   Description: Coefficient positif du filtrage
   LSB: 2^-10 OFF:  0 MIN/MAX:  -1 .. 1 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_rIntLoAdpKnkProt_C /* 
   Unit       : �C
   Description: Coefficient n�gatif du filtrage
   LSB: 2^-10 OFF:  0 MIN/MAX:  -1 .. 1 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_rIntLoTAirKnkProt_C /* 
   Unit       : �C
   Description: Coefficient n�gatif du filtrage
   LSB: 2^-10 OFF:  0 MIN/MAX:  -1 .. 1 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_rOilDilInpByp_C /* 
   Unit       : %
   Description: Taux de dilution estim�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_rOpEGRCoBypReqInpByp_C /* 
   Unit       : %
   Description: Commande de base du bypass echangeur EGR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_rOpEGRInpByp_C /* 
   Unit       : %
   Description: Position vanne EGR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_tAirExtThdAdpKnkProt_C /* 
   Unit       : �C
   Description: Seuil de temp�rature d'air ext�rieur
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_tAirExtThdTAirKnkProt_C /* 
   Unit       : �C
   Description: Seuil de temp�rature d'air ext�rieur
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tCoHysAntiBoil_C /* 
   Unit       : �C
   Description: Hyst�r�sis de temp�rature d'eau
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 30 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_tECTLoAdpKnkProt_C /* 
   Unit       : �C
   Description: Consigne basse de r�gulation de temp�rature d'eau
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_tECTLoAntiBoil_C /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_tECTLoTAirKnkProt_C /* 
   Unit       : �C
   Description: Consigne basse de r�gulation de temp�rature d'eau
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiEngStrtAntiBoil_C /* 
   Unit       : s
   Description: Temporisation pour d�marrage moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 300 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiFilPwr1AntiBoil_C /* 
   Unit       : s
   Description: Constante de temps de filtrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 600 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiFilPwr2AntiBoil_C /* 
   Unit       : s
   Description: Constante de temps de filtrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 600 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiFilTCoAntiBoil_C /* 
   Unit       : s
   Description: Constante de temps de filtrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 600 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiFilTCoRegAntiBoil_C /* 
   Unit       : s
   Description: Constante de temps de filtrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 300 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiLimAcvDlyAntiBoil_C /* 
   Unit       : s
   Description: Temporisation d'activation de la limitation de couple
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 300 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiPwrTqFastFilAntiBoil_C /* 
   Unit       : s
   Description: Constante de temps de filtrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 300 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqIdcAirReqGenInpByp_C /* 
   Unit       : N.m
   Description: Couple moteur indiqu� final
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqIdcDftThMgt_C /* 
   Unit       : N.m
   Description: Couple moteur indiqu�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqIdcEngCurInpByp_C /* 
   Unit       : N.m
   Description: -
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqIdcFldInpByp_C /* 
   Unit       : N.m
   Description: Couple moteur indiqu� pleine charge
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqIdcInpByp_C /* 
   Unit       : N.m
   Description: Couple moteur indiqu�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqIdcMaxAntiBoil_C /* 
   Unit       : N.m
   Description: Couple moteur indiqu�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqMaxResInpByp_C /* 
   Unit       : N.m
   Description: -
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;

#define THMGT_STOP_SEC_CALIB_16BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CALIB_32BIT
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_32BIT: Mergeable Calib 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_MERGEABLE_CALIB_32BIT UInt32 ThMgt_pwrIniAntiBoil_C /* 
   Unit       : W
   Description: Valeur d'initialisation du filtre de la puissance
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 250000 */;
extern AR_MERGEABLE_CALIB_32BIT SInt32 ThMgt_pwrTqHiThdDifAntiBoil_C /* 
   Unit       : W/N.m
   Description: seuil haut de diff�rence de puissance ou CMI
   LSB: 2^-4 OFF:  0 MIN/MAX:  -250000 .. 250000 */;
extern AR_MERGEABLE_CALIB_32BIT SInt32 ThMgt_pwrTqLoThdDifAntiBoil_C /* 
   Unit       : W/N.m
   Description: seuil bas de diff�rence de puissance ou CMI
   LSB: 2^-4 OFF:  0 MIN/MAX:  -250000 .. 250000 */;
extern AR_MERGEABLE_CALIB_32BIT UInt32 ThMgt_tiEngStopInpByp_C /* 
   Unit       : s
   Description: Temps d'arr�t moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 864000 */;

#define THMGT_STOP_SEC_CALIB_32BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CALIB_8BIT
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_ctRblInjCutOffPtlInpByp_C /* 
   Description: Vecteur des compteurs de coupures d'injection par cylindre dues au rumble
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_noEgdGearCordInpByp_C /* 
   Description: Rapport de boite de vitesse engag�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_stCmbTdOffInpByp_C /* 
   Description: Compromis prestation r�alis� par la combustion
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 15 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_stCplInpByp_C /* 
   Description: Etat du couplage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define THMGT_STOP_SEC_CALIB_8BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CALIB_BOOLEAN
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_BOOLEAN: Mergeable Calib 1 bit for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bActPwrNormFilAntiBoil_C /* 
   Description: activation de la d�tection de puissance/CMI d�croissante
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bAcvNoEgdGearDftInpByp_C /* 
   Description: Activation du num�ro de rapport de boite engag� par d�faut
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bAcvRatLimTqAntiBoil_C /* 
   Description: Activation de la limitation de pente d�croissante du couple de limitation
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bAcvTrbWaPmpInpByp_C /* 
   Description: Activation de la pompe turbo
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bAcvTrqLimInpByp_C /* 
   Description: Activation de la limitation de sur-r�gime par le couple (mode atypique essence)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bDeacManLimAntiBoil_C /* 
   Description: D�sactivation de la limitation de couple (mode manuel)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bExThermoProtInpByp_C /* 
   Description: Demande de protection thermique composants (mode atypique essence)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bInhDgoAntiBoil_C /* 
   Description: Inhibition du diagnostic de limitation de couple
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPFltRgnReqInpByp_C /* 
   Description: Demande de r�g�n�ration FAP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPFltRgnSrvReqInpByp_C /* 
   Description: Demande de r�g�n�ration FAP apr�s-vente
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bSel1TCoRegFilAntiBoil_C /* 
   Description: S�lection de la consigne de Teau filtr�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bSel1TqIdcAntiBoil_C /* 
   Description: S�lection du couple moteur indiqu� estim�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bSelPwrDifAntiBoil_C /* 
   Description: s�lection de la puissance au lieu du CMI
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bSelPwrNormFilAntiBoil_C /* 
   Unit       : s
   Description: Selection du temps de filrage par d�faut
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bSelTCoRegFilAntiBoil_C /* 
   Description: S�lection de la consigne de Teau filtr�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bSelTqMaxResAntiBoil_C /* 
   Description: S�lection de la r�serve de couple maximale
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bTqTxInpByp_C /* 
   Description: Etat transmission de couple
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_prm_bSel01InpByp_C[7] /* 
   Description: S�lection des bypass
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_prm_bSel41InpByp_C[10] /* 
   Description: S�lection des bypass
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_prm_bSel42InpByp_C[9] /* 
   Description: S�lection des bypass
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define THMGT_STOP_SEC_CALIB_BOOLEAN
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CARTO_16BIT
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CARTO_16BIT: Mergeable Carto 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_MERGEABLE_CARTO_16BIT UInt16 ThMgt_nEngAntiBoil_no6x_A[8] /* 
   Unit       : RPM
   Description: R�gime moteur en tr/min
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_MERGEABLE_CARTO_16BIT SInt16 ThMgt_tAirUsInVlvKnkProt_no1_T[8] /* 
   Unit       : �C
   Description: Temp�rature estim�e du m�lange entrant cylindre pour le calcul de la charge
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 1000 */;
extern AR_MERGEABLE_CARTO_16BIT SInt16 ThMgt_tCoHiThdAntiBoil_no3_T[5] /* 
   Unit       : �C
   Description: Seuil de temp�rature d'eau
   LSB: 0.1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CARTO_16BIT SInt16 ThMgt_tCoHiThdAntiBoil_no5_T[5] /* 
   Unit       : �C
   Description: Seuil de temp�rature d'eau
   LSB: 0.1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CARTO_16BIT SInt16 ThMgt_tCoRegAntiBoil_no3x_A[5] /* 
   Unit       : �C
   Description: Consigne de r�gulation de temp�rature d'eau
   LSB: 0.1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CARTO_16BIT SInt16 ThMgt_tCoRegAntiBoil_no5x_A[5] /* 
   Unit       : �C
   Description: Consigne de r�gulation de temp�rature d'eau
   LSB: 0.1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CARTO_16BIT UInt16 ThMgt_tiPwrFilAntiBoil_no7_T[6] /* 
   Unit       : s
   Description: Constante de temps de filtrage
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 600 */;
extern AR_MERGEABLE_CARTO_16BIT UInt16 ThMgt_tqIdcAntiBoil_no7x_A[6] /* 
   Unit       : N.m
   Description: Couple moteur indiqu�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_MERGEABLE_CARTO_16BIT UInt16 ThMgt_tqMinLimAntiBoil_no6_T[8] /* 
   Unit       : N.m
   Description: Couple de limitation anti-�bullition minimum (strat�gie active)
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;

#define THMGT_STOP_SEC_CARTO_16BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CARTO_8BIT
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CARTO_8BIT: Mergeable Carto 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CARTO_8BIT UInt8 ThMgt_spdVehKnkProt_no1x_A[8] /* 
   Unit       : km/h
   Description: Vitesse v�hicule
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;

#define THMGT_STOP_SEC_CARTO_8BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_INTERNAL_VAR_16BIT
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_16BIT: Display 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 AirSysByp_rOpEGRCoBypReq /* 
   Unit       : %
   Description: Commande de base du bypass echangeur EGR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 AntiBoil_agvEng /* 
   Unit       : rad/s
   Description: R�gime moteur (rad/s)
   LSB: 0.1047 OFF:  0 MIN/MAX:  0 .. 750 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 AntiBoil_tCoHiThdAntiBoil /* 
   Unit       : �C
   Description: Seuil haut de temp�rature d'eau pour l'activation de la strat�gie anti-�bullition
   LSB: 0.1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 AntiBoil_tCoMesFil /* 
   Unit       : �C
   Description: Temp�rature d'eau filtr�e
   LSB: 0.1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 AntiBoil_tCoRegFil /* 
   Unit       : �C
   Description: Temp�rature d'eau de r�gulation filtr�
   LSB: 0.1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 AntiBoil_tECTReq /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin anti-�bullition)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 AntiBoil_tECTReqDly /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin anti-�bullition)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 AntiBoil_tiPwrFil /* 
   Unit       : s
   Description: Constante de temps de filtrage de la puissance
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 600 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 AntiBoil_tqIdcLim /* 
   Unit       : N.m
   Description: Couple moteur plafond
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 AntiBoil_tqIdcLimWoutRes /* 
   Unit       : W
   Description: Couple moteur plafond sans la reserve de couple maximale
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 AntiBoil_tqIdcMinLim /* 
   Unit       : N.m
   Description: Couple de limitation anti-�bullition minimum (strat�gie active)
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 EGRVlvByp_rOp /* 
   Unit       : %
   Description: Position vanne EGR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 EngLimByp_tqIdcEngCur /* 
   Description: Couple moteur indique realise a l avance courante essence
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 EngMByp_mfDsEGRCoEstim /* 
   Unit       : kg/h
   Description: D�bit de gaz EGR
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 EngMByp_mfEgEstim /* 
   Unit       : kg/h
   Description: D�bit massique des gaz d'�chappement
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 ExtByp_nEng /* 
   Unit       : RPM
   Description: R�gime moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 ExtByp_pAirExtMes /* 
   Unit       : mBar
   Description: Pression atmosph�rique
   LSB: 2^0 OFF:  0 MIN/MAX:  500 .. 1500 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 InpClc_tqIdcEstim /* 
   Unit       : N.m
   Description: Couple moteur indiqu�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 InpClc_tqIdcFld /* 
   Unit       : N.m
   Description: Couple moteur indiqu� pleine charge
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 KnkProt_rInt1 /* 
   Unit       : -
   Description: Valeur du filtre de condition de d�rive de l'adaptatif
   LSB: 2^-10 OFF:  0 MIN/MAX:  0 .. 10 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 KnkProt_rInt2 /* 
   Unit       : -
   Description: Valeur du filtre de condition de T�air soupape
   LSB: 2^-10 OFF:  0 MIN/MAX:  0 .. 10 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 KnkProt_tECTAdpReq /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin d�rive de l'adaptatif)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 KnkProt_tECTTAirReq /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin T� d'air soupape)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 OAMByp_rOilDil /* 
   Unit       : %
   Description: Taux de dilution estim�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_AirSysByp_rOpEGRCoBypReq_out /* 
   Unit       : %
   Description: Commande de base du bypass echangeur EGR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 RE004_AntiBoil_tCoMesFil_out /* 
   Unit       : �C
   Description: Temp�rature d'eau filtr�e
   LSB: 0.1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 RE004_AntiBoil_tECTReqDly_out /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin anti-�bullition)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_EGRVlvByp_rOp_out /* 
   Unit       : %
   Description: Position vanne EGR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_EngLimByp_tqIdcEngCur_out /* 
   Unit       : N.m
   Description: Couple moteur indique realise a l avance courante essence
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_EngMByp_mfDsEGRCoEstim_out /* 
   Unit       : kg/h
   Description: D�bit de gaz EGR
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_EngMByp_mfEgEstim_out /* 
   Unit       : kg/h
   Description: D�bit massique des gaz d'�chappement
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_ExtByp_nEng_out /* 
   Unit       : RPM
   Description: R�gime moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_ExtByp_pAirExtMes_out /* 
   Unit       : bar
   Description: Vitesse de rotation de volant filtr�e
   LSB: 2^0 OFF:  0 MIN/MAX:  500 .. 1500 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_InpClc_tqIdcEstim_out /* 
   Unit       : N.m
   Description: Couple moteur indiqu�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_InpClc_tqIdcFld_out /* 
   Unit       : N.m
   Description: Couple moteur indiqu� pleine charge
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 RE004_KnkProt_tECTAdpReq_out /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin d�rive de l'adaptatif)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 RE004_KnkProt_tECTTAirReq_out /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin T� d'air soupape)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_OAMByp_rOilDil_out /* 
   Unit       : -
   Description: Taux de dilution estim�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 RE004_PwtFil_tCoRegFil3_in /* 
   Unit       : �C
   Description: Temp�rature d'eau de r�gulation filtr�
   LSB: 2^-6 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 RE004_StgByp_agStrWhl_out /* 
   Unit       : deg
   Description: Angle de volant
   LSB: 0.1 OFF:  0 MIN/MAX:  -780 .. 780 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_StgByp_agvStrWhl_out /* 
   Unit       : deg/s
   Description: Vitesse de rotation de volant
   LSB: 2^2 OFF:  0 MIN/MAX:  0 .. 1060 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 RE004_TqSysByp_tqIdcAirReqGen_out /* 
   Unit       : N.m
   Description: Couple moteur indiqu� final
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 StgByp_agStrWhl /* 
   Unit       : �
   Description: Angle de volant
   LSB: 0.1 OFF:  0 MIN/MAX:  -780 .. 780 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 StgByp_agvStrWhl /* 
   Unit       : �/s
   Description: Vitesse de rotation de volant
   LSB: 2^2 OFF:  0 MIN/MAX:  0 .. 1060 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 TqResByp_tqMaxRes /* 
   Description: Reserve de couple maximale essence
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 TqSysByp_tqIdcAirReqGen /* 
   Unit       : N.m
   Description: Couple moteur indiqu� final
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;

#define THMGT_STOP_SEC_INTERNAL_VAR_16BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_INTERNAL_VAR_32BIT

#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_32BIT: Display 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 AntiBoil_pwr /* 
   Unit       : W
   Description: Puissance moteur
   LSB: 2^-14 OFF:  0 MIN/MAX:  0 .. 250000 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 AntiBoil_pwrFil /* 
   Unit       : W
   Description: Puissance moteur filtr�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 250000 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 AntiBoil_pwrLim /* 
   Unit       : W
   Description: Puissance moteur plafond
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 250000 */;
extern AR_INTERNAL_VAR_DISP_32BIT SInt32 AntiBoil_pwrTqDif /* 
   Unit       : W/N.m
   LSB: 2^-12 OFF:  0 MIN/MAX:  -250000 .. 250000 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 EOMByp_tiEngStop /* 
   Unit       : s
   Description: Temps d'arr�t moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 864000 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 RE004_EOMByp_tiEngStop_out /* 
   Unit       : s
   Description: Temps d'arr�t moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 864000 */;

#define THMGT_STOP_SEC_INTERNAL_VAR_32BIT

#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_INTERNAL_VAR_8BIT
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_8BIT: Display 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 CoPtByp_noEgdGearCord /* 
   Description: Rapport de boite de vitesse engag�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 CoPtByp_stCpl /* 
   Description: Etat du couplage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 EOMByp_stCmbTdOff /* 
   Description: Compromis prestation r�alis� par la combustion
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 15 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 KnkMgtByp_ctRblInjCutOffPtl /* 
   Description: Vecteur des compteurs de coupures d'injection par cylindre dues au rumble
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 RE004_CoPtByp_noEgdGearCord_out /* 
   Description: Rapport de boite de vitesse engag�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 RE004_CoPtByp_stCpl_out /* 
   Description: Etat du couplage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 RE004_EOMByp_stCmbTdOff_out /* 
   Description: Compromis prestation r�alis� par la combustion
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 15 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 RE004_KnkMgtByp_ctRblInjCutOffPtl_out /* 
   Description: Vecteur des compteurs de coupures d'injection par cylindre dues au rumble
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;

#define THMGT_STOP_SEC_INTERNAL_VAR_8BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_BOOLEAN: Display Boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean AntiBoil_bAcvTqIdcLimReq /*
   Description: Demande d'activation de la consigne de limitation de couple */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean AntiBoil_bRatCorPwrFilIni /*
   Description: Initialisation du filtre du coefficient de correction de puissance */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean AntiBoil_bRatCorPwrFilIniDly /*
   Description: Initialisation du filtre du coefficient de correction de puissance */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean CoPtByp_bTqTx /*
   Description: Etat transmission de couple */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean ESLimByp_bAcvTrqLim /*
   Description: Activation de la limitation de sur-r�gime par le couple (mode atypique essence) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FRMByp_bAcvNoEgdGearDft /*
   Description: Activation du num�ro de rapport de boite engag� par d�faut (gestion du chauffage par
    augmentation de ralenti) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean FRMByp_bAcvTrbWaPmp /*
   Description: Activation de la pompe turbo */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean InpClc_bPFltRgnReq /*
   Description: Demande de r�g�n�ration FAP */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean KnkProt_bCndTAir /*
   Description: Condition brute de tem�rature d'air */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean PFltByp_bPFltRgnSrvReq /*
   Description: Demande de r�g�n�ration FAP apr�s vente */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE004_AntiBoil_bRatCorPwrFilIniDly_out /* 
   Description: Initialisation du filtre du coefficient de correction de puissance
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE004_CoPtByp_bTqTx_out /* 
   Description: Etat transmission de couple
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE004_ESLimByp_bAcvTrqLim_out /* 
   Description: Activation de la limitation de sur-r�gime par le couple (mode atypique essence)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE004_FRMByp_bAcvNoEgdGearDft_out /* 
   Description: Activation du num�ro de rapport de boite engag� par d�faut (gestion du chauffage par
    augmentation de ralenti)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE004_FRMByp_bAcvTrbWaPmp_out /* 
   Description: Activation de la pompe turbo
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE004_InpClc_bPFltRgnReq_out /* 
   Description: Demande de r�g�n�ration FAP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE004_PFltByp_bPFltRgnSrvReq_out /* 
   Description: Demande de r�g�n�ration FAP apr�s vente
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE004_TPMByp_bExThermoProt_out /* 
   Description: Demande de protection thermique composants (mode atypique essence)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean TPMByp_bExThermoProt /*
   Description: Demande de protection thermique composants (mode atypique essence) */;

#define THMGT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ThMgt_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

#endif/*_THMGT_004_CALIBRATIONS_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
