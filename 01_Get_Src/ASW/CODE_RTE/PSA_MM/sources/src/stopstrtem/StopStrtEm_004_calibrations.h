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
 ***  %name: StopStrtEm_004_calibrations.h %
 *** 
 ***  %version: 4.8 %
 *** 
 ***  %date_modified: Fri May 24 12:28:02 2013 %
 *** 
 *** 
 ***  %derived_by: u261238 %
 ***  %release: StopStrtEm/5.0 %
 ***  %full_filespec: StopStrtEm_004_calibrations.h-4.8:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : StopStrtEm_004
 *** TargetLink subsystem : StopStrtEm_004/StopStrtEm_004
 *** Codefile             : stopstrtem_004_calibrations.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2013-05-23 14:12:57
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
 *** TargetLink version      : 3.0.1p1 from 06-Oct-2009
 *** Code generator version  : Build Id 3.0.1.8 from 2009-03-10 10:34:41
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _STOPSTRTEM_004_CALIBRATIONS_H_
#define _STOPSTRTEM_004_CALIBRATIONS_H_

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

#define STOPSTRTEM_START_SEC_CALIB_16BIT
#include "StopStrtEm_MemMap.h"
/******************************************************************************\
   AR_MERGEABLE_CALIB_16BIT: Mergeable Calib 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_nProt1Thd11_C /* 
   Unit       : rpm
   Description: Seuil de r�gime moteur D11 pour la protection 1 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_nProt1Thd12_C /* 
   Unit       : rpm
   Description: Seuil de r�gime moteur D12 pour la protection 1 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_nProt8DftValThd_C /* 
   Unit       : RPM
   Description: R�gime moteur max du d�marreur en cas de d�faut sur l'information temp�rature eau mo
   teur de la protection 8 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_nStrtDslThd_C /* 
   Unit       : RPM
   Description: Seuil de r�gime moteur pour moteur diesel pour la protection 9 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_nStrtGslThd_C /* 
   Unit       : RPM
   Description: Seuil de r�gime moteur pour moteur essence pour la protection 9 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tMaxThd_C /* 
   Unit       : K
   Description: Seuil de temp�rature critique du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  200 .. 600 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tStaSatMax_C[3] /* 
   Unit       : K
   Description: Saturation maximum des temp�ratures estim�es d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  200 .. 600 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tStaSatMin_C[3] /* 
   Unit       : K
   Description: Saturation minimum de la matrice dynamique estimateur temp�ratures d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  200 .. 600 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiAcvMaxThd_C /* 
   Unit       : s
   Description: Seuil de temps maximum d'activation du d�marreur
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 200 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyOffProt1_C /* 
   Unit       : s
   Description: Majoration s�curitaire du temps d'activation de la protection 1 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyOffProt3_C /* 
   Unit       : s
   Description: Majoration s�curitaire du temps d'activation de la protection 3 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyOffProt4_C /* 
   Unit       : s
   Description: Majoration s�curitaire du temps d'activation de la protection 4 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyOffProt8_C /* 
   Unit       : s
   Description: Majoration s�curitaire du temps d'activation de la protection 8 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyOffProt9_C /* 
   Description: Majoration s�curitaire du temps d'activation de la protection 9 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyOffProt_C /* 
   Unit       : s
   Description: Majoration s�curitaire du temps d'activation de la protection 9 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyOnStaRun_C /* 
   Unit       : s
   Description: Tempo de retard sur l'information d�marrage en cours pour prendre en compte le temps
    n�cessaire � l'initiation de production de couple
   LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyStaCmdDgo_C /* 
   Unit       : s
   Description: Retard s�curitaire pour communiquer le diagnostic sur l'�tat de fonctionnalit� du DM
   TC (tempo diag BICD)
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiDlyStaCmdInfo_C /* 
   Unit       : s
   Description: Retard s�curitaire pour communiquer le diagnostic de l'information sur l'�tat de fon
   ctionnalit� du DMTC
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiMaxSatThd_C /* 
   Unit       : s
   Description: Seuil de temps maximum d'activation du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 200 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiOffDiagElCmd_C /* 
   Unit       : s
   Description: Majoration s�curitaire du temps d'activation du diagnostic de la ligne de commande o
   u du d�marreur pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiProt1Thd1104_C /* 
   Unit       : s
   Description: Tempo D11-04 de la protection 1 pour le d�marrage pour archi 2004 / 2010 STT
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiProt1Thd1110_C /* 
   Unit       : s
   Description: Tempo D11-10 de la protection 1 pour le d�marrage pour archi 2010 non STT
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiProt1Thd12_C /* 
   Unit       : s
   Description: Tempo D12 de la protection 1 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiProt8Thd81_C /* 
   Unit       : s
   Description: Tempo D81 de la protection 8 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiStaCmdDlyOff_C /* 
   Unit       : s
   Description: Retard sur le passage � non fonctionnel du retour d'�tat BICD
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_uDiagElCmdThd_C /* 
   Unit       : V
   Description: Seuil de tension batterie pour le diagnostic de la ligne de commande ou du d�marreur
    pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 32 */;

#define STOPSTRTEM_STOP_SEC_CALIB_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_32BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_32BIT: Mergeable Calib 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_MERGEABLE_CALIB_32BIT SInt32 StaStrtMgt_facDynMatSatMax_C /* 
   Unit       : 1/s
   Description: Saturation maximum de la matrice dynamique estimateur temp�ratures d�marreur
   LSB: 2^-20 OFF:  0 MIN/MAX:  -100 .. 100 */;
extern AR_MERGEABLE_CALIB_32BIT SInt32 StaStrtMgt_facDynMatSatMin_C /* 
   Unit       : 1/s
   Description: Saturation minimum de la matrice dynamique estimateur temp�ratures d�marreur
   LSB: 2^-20 OFF:  0 MIN/MAX:  -100 .. 100 */;
extern AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_noStaWarnDelta_C /* 
   Unit       : -
   Description: Delta du nombre d'activation du d�marreur pour pr�venir le client en APV avant le fr
   anchissement du seuil durabilit� d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000000 */;
extern AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_tiStaIniThd1_C /* 
   Unit       : s
   Description: Seuil 1 de temps d'arr�t du calculateur pour recaler les temp�ratures du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 100000 */;
extern AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_tiStaIniThd2_C /* 
   Unit       : s
   Description: Seuil 2 de temps d'arr�t du calculateur pour recaler les temp�ratures du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 100000 */;

#define STOPSTRTEM_STOP_SEC_CALIB_32BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_8BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_idxEngNSynt_C /* 
   Unit       : s
   Description: Choix des r�gimes moteur pour d�finir la synth�se r�gime moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_idxTDeltaStra_C /* 
   Description: Choix de la strat�gie de recalage de l'estimation des temp�ratures d�marreur � la so
   rtie de veille
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_idxTiMaxStra_C /* 
   Description: Choix de la strat�gie d'estimation du temps maximum d'activation du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_noNotNullCkgInc_C /* 
   Description: Valeur de l'incr�ment du compteur nombre de red�marrage du d�marreur � r�gime moteur
    non nul 
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 50 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_noNullCkgInc_C /* 
   Description: Valeur de l'incr�ment du compteur nombre de red�marrage du d�marreur � r�gime moteur
    nul
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 50 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_noStaCmdInfoThd_C /* 
   Unit       : -
   Description: Nombre minimum d'�chec du test de l'information sur l'�tat de fonctionnalit� du DMTC
    pour remonter un d�faut
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_noTSta_C /* 
   Unit       : -
   Description: Choix de la temp�rature critique d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 3 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_tiDlyAcvSta_C /* 
   Unit       : s
   Description: Tempo de retard sur front descendant de l'information d�marrage en cours pour archit
   ectures 2010 non STT
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_tiDlyOffStaReq_C /* 
   Unit       : s
   Description: Retard s�curitaire � la d�sactivation du d�marreur en AEE2004/2010 STT ou de l'autor
   isation d'activation du d�marreur en AEE2010 non STT
   LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 0.2 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_tiDlyOnStaReq_C /* 
   Unit       : s
   Description: Retard s�curitaire de l'activation du d�marreur en AEE2004/2010 STT ou de l'autorisa
   tion d'activation du d�marreur en AEE2010 non STT
   LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 0.2 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_tiDlyStaReq_C /* 
   Unit       : s
   Description: Tempo de retard sur front descendant de l'information d�marrage en cours pour archit
   ectures 2004 et 2010 EVO
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_tiOnDiagElCmd_C /* 
   Unit       : s
   Description: Retard s�curitaire pour la d�tection de la chute de tension pour le diagnostic de la
    ligne de commande ou du d�marreur pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_tiProt4NThd4_C /* 
   Unit       : s
   Description: Tempo D4 de la protection 4 pour le d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2 */;

#define STOPSTRTEM_STOP_SEC_CALIB_8BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_BOOLEAN
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_BOOLEAN: Mergeable Calib 1 bit for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bInhDiagElCmd_C /* 
   Description: Inhibition du diagnostic de la ligne de commande ou du d�marreur pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bInhManProt10_C /* 
   Description: Inhibition de la protection 10 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bInhManProt1_C /* 
   Description: Inhibition de la protection 1 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bInhManProt3_C /* 
   Description: Inhibition de la protection 3 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bInhManProt4_C /* 
   Description: Inhibition de la protection 4 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bInhManProt8_C /* 
   Description: Inhibition de la protection 8 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bInhManProt9_C /* 
   Description: Inhibition de la protection 9 pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define STOPSTRTEM_STOP_SEC_CALIB_BOOLEAN
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CARTO_16BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CARTO_16BIT: Mergeable Carto 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_MERGEABLE_CARTO_16BIT UInt16 StaStrtMgt_nCkFil_A[12] /* 
   Unit       : RPM
   Description: Points d'appui (x), r�gime moteur filtr� envoy� � 10ms
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 8000 */;
extern AR_MERGEABLE_CARTO_16BIT UInt16 StaStrtMgt_nStaStrtMgtMax_T[12] /* 
   Unit       : RPM
   Description: Valeur de la table (y), seuil de r�gime moteur max du d�marreur de la protection 8 p
   our le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_MERGEABLE_CARTO_16BIT UInt16 StaStrtMgt_rOldStaWhlStop_T[8] /* 
   Unit       : -
   Description: Valeur de la table (y), ratio entre le temps d'attente d'arr�t du pignon du d�marreu
   r vieux par rapport au neuf
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_MERGEABLE_CARTO_16BIT SInt16 StaStrtMgt_tCoMesProt10_A[12] /* 
   Unit       : �C
   Description: Points d'appui (x), temp�rature eau moteur de la protection 10 pour le d�marrage
   LSB: 2^-1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CARTO_16BIT SInt16 StaStrtMgt_tCoMesStrtProt8_A[12] /* 
   Unit       : �C
   Description: Points d'appui (x), temp�rature eau moteur de la protection 8 pour le d�marrage
   LSB: 2^-1 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_MERGEABLE_CARTO_16BIT UInt16 StaStrtMgt_tiStaAcv_A[8] /* 
   Unit       : s
   Description: Points d'appui (x), dur�e d'activation du d�marreur
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 200 */;
extern AR_MERGEABLE_CARTO_16BIT UInt16 StaStrtMgt_tiStaHeatDly_T[8] /* 
   Unit       : s
   Description: Valeur de la table (y), dur�e du prolongement de l'�chauffement du d�marreur
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 20 */;
extern AR_MERGEABLE_CARTO_16BIT UInt16 StaStrtMgt_tiStaWhlStopWait_T[12] /* 
   Unit       : s
   Description: Valeur de la table (y), temps d'attente d'arr�t du pignon du d�marreur neuf pour le 
   d�marrage
   LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 10 */;

#define STOPSTRTEM_STOP_SEC_CARTO_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CARTO_32BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CARTO_32BIT: Mergeable Carto 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_ctStaAcv_A[8] /* 
   Unit       : -
   Description: Points d'appui (x), nombre d'activation du moteur du d�marreur pour le d�marrage et 
   le red�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000000 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_ctTiAcvLim_A[8] /* 
   Unit       : s
   Description: Points d'appui (x), temps pour d�terminer le seuil limite d'activation du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5270400 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_dstVehAcvLim_A[8] /* 
   Unit       : km
   Description: Points d'appui (x), distance parcourue pour d�terminer le seuil limite d'activation 
   du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 500000 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facCmdMat11_T[8] /* 
   Unit       : 1/s
   Description: Valeur de la table (y), terme 1-1 de la matrice de commande estimateur temp�ratures 
   d�marreur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facCmdMat21_T[8] /* 
   Unit       : 1/s
   Description: Valeur de la table (y), terme 2-1 de la matrice de commande estimateur temp�ratures 
   d�marreur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facCmdMat22_M[8][8] /* 
   Unit       : K/s
   Description: Valeur de la table, terme 2-2 de la matrice de commande estimateur temp�ratures d�ma
   rreur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facCmdMat31_T[8] /* 
   Unit       : 1/s
   Description: Valeur de la table (y), terme 3-1 de la matrice de commande estimateur temp�ratures 
   d�marreur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facDynMat12_M[8][8] /* 
   Unit       : K/s
   Description: Valeur de la table, terme 1-2 de la matrice dynamique estimateur temp�ratures d�marr
   eur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facDynMat13_M[8][8] /* 
   Unit       : K/s
   Description: Valeur de la table, terme 1-3 de la matrice dynamique estimateur temp�ratures d�marr
   eur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facDynMat21_M[8][8] /* 
   Unit       : K/s
   Description: Valeur de la table, terme 2-1 de la matrice dynamique estimateur temp�ratures d�marr
   eur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facDynMat23_M[8][8] /* 
   Unit       : K/s
   Description: Valeur de la table, terme 2-3 de la matrice dynamique estimateur temp�ratures d�marr
   eur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facDynMat31_M[8][8] /* 
   Unit       : K/s
   Description: Valeur de la table, terme 3-1 de la matrice dynamique estimateur temp�ratures d�marr
   eur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_facDynMat32_M[8][8] /* 
   Unit       : K/s
   Description: Valeur de la table, terme 3-2 de la matrice dynamique estimateur temp�ratures d�marr
   eur
   LSB: 0.0001 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_noDstAcvLimThd_T[8] /* 
   Unit       : -
   Description: Valeur de la table (y), seuil limite d'activation du d�marreur li� � la distance
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000000 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_noTiAcvLimThd_T[8] /* 
   Unit       : -
   Description: Valeur de la table (y), seuil limite d'activation du d�marreur li� au temps
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000000 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_tProt10X_A[8] /* 
   Unit       : K
   Description: Points d'appui carto 2D (x), temp�rature pour d�terminer les termes de l'estimateur 
   de temp�ratures d�marreur
   LSB: 2^-17 OFF:  0 MIN/MAX:  200 .. 600 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_tProt10Y_A[8] /* 
   Unit       : K
   Description: Points d'appui carto 2D (y), temp�rature pour d�terminer les termes de l'estimateur 
   de temp�ratures d�marreur
   LSB: 2^-17 OFF:  0 MIN/MAX:  200 .. 600 */;
extern AR_MERGEABLE_CARTO_32BIT UInt32 StaStrtMgt_tiMinAcv_T[12] /* 
   Unit       : s
   Description: Valeur de la table (y), tempo min commande du d�marreur de la protection 10 pour le 
   d�marrage
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 60 */;

#define STOPSTRTEM_STOP_SEC_CARTO_32BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_INTERNAL_VAR_16BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_16BIT: Display 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 StaStrtMgt_nEngSynt_MP /* 
   Unit       : -
   Description: Point de mesure sur le r�gime moteur synth�se
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 16383.75 */;

#define STOPSTRTEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_INTERNAL_VAR_32BIT

#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_32BIT: Display 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_ctDeltaTi_MP /* 
   Unit       : s
   Description: Compteur du temps d'extinction du calculateur
   LSB: 2^-9 OFF:  0 MIN/MAX:  0 .. 86400 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_ctLastConnTiDif_MP /* 
   Unit       : min
   Description: Point de mesure sur la diff�rence entre le temps courant et le temps lors de la dern
   i�re connexion
   LSB: 2^-9 OFF:  0 MIN/MAX:  0 .. 8388607.99804688 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_ctRunTi_MP /* 
   Unit       : min
   Description: Point de mesure de temps courant
   LSB: 2^-9 OFF:  0 MIN/MAX:  0 .. 8388607.99804688 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_ctStaSaveThd /* 
   Unit       : -
   Description: Seuil d'avertissement APV li� � la durabilit� d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 4294967295 */;
extern AR_INTERNAL_VAR_DISP_32BIT SInt32 StaStrtMgt_ctStaTi_MP /* 
   Unit       : -
   Description: Point de mesure sur le temps depuis le d�but de vie du d�marreur sur le v�hicule
   LSB: 2^0 OFF:  0 MIN/MAX:  -2147483648 .. 2147483647 */;
extern AR_INTERNAL_VAR_DISP_32BIT SInt32 StaStrtMgt_ctStaWarnThd /* 
   Unit       : -
   Description: Seuil de durabilit� d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  -2147483648 .. 2147483647 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_ctTotTi_MP /* 
   Unit       : min
   Description: Point de mesure sur le temps total du v�hicule
   LSB: 2^-9 OFF:  0 MIN/MAX:  0 .. 8388607.99804688 */;
extern AR_INTERNAL_VAR_DISP_32BIT SInt32 StaStrtMgt_dstVehStaMes_MP /* 
   Unit       : km
   Description: Point de mesure sur la distance parcourue par le v�hicule depuis le d�but de vie du 
   d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  -2147483648 .. 2147483647 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_noDstAcvLimThd_MP /* 
   Unit       : -
   Description: Point de mesure sur le seuil limite d'activation du d�marreur li� � la distance
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 4294967295 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_noStaAcvLimThd_MP /* 
   Unit       : -
   Description: Point de mesure sur le seuil limite d'activation du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000000 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_noTiAcvLimThd_MP /* 
   Unit       : -
   Description: Point de mesure sur le seuil limite d'activation du d�marreur li� au temps
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000000 */;
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 StaStrtMgt_tSta_MP[3] /* 
   Unit       : K
   Description: Temp�ratures estim�es du d�marreur
   LSB: 2^-17 OFF:  0 MIN/MAX:  0 .. 32767.9999923706 */;

#define STOPSTRTEM_STOP_SEC_INTERNAL_VAR_32BIT

#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_INTERNAL_VAR_8BIT
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_8BIT: Display 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 StaStrtMgt_noStrtProt_MP /* 
   Description: Point de mesure indiquant les protections activ�es pour le d�marrage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 63 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 StaStrtMgt_stInhStaDmgTiDst_MP /* 
   Unit       : -
   Description: Point de mesure sur l'inhibition de l'utilisation du temps et de la distance pour li
   miter l'endommagement du d�marreur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define STOPSTRTEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_INTERNAL_VAR_BOOLEAN
#include "StopStrtEm_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_BOOLEAN: Display Boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean StaStrtMgt_bInfoStaRun_MP /*
   Description: Point de mesure sur l'information d�marrage en cours */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean StaStrtMgt_bStrtProt_MP /*
   Description: Point de mesure sur l'activation des protections pour le d�marrage */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean StaStrtMgt_bTiLossNoDet_MP /*
   Description: Point de mesure sur la non d�tection de la perte de l'information du temps */;

#define STOPSTRTEM_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "StopStrtEm_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

#endif/*_STOPSTRTEM_004_CALIBRATIONS_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
