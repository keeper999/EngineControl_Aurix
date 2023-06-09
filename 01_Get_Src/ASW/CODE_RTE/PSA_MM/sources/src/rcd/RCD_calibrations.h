/**************************************************************************************************\
 *** 
 *** Simulink model       : RCD_TL_et_SL
 *** TargetLink subsystem : RCD_TL_et_SL/RCD
 *** Codefile             : rcd_calibrations.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2010-12-20 15:56:25
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
 *** Style definition file               : C:\dSPACE301\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE301\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSource
 ***                                       CodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0.1_RC3 from 13-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _RCD_CALIBRATIONS_H_
#define _RCD_CALIBRATIONS_H_

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

#define RCD_START_SEC_CALIB_16BIT
#include "RCD_MemMap.h"
/******************************************************************************\
   AR_MERGEABLE_CALIB_16BIT: Mergeable Calib 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiDegMainWkuDeac_C /* 
   Unit       : s
   Description: Temporisation au bout de laquelle on force la sortie du r�veil principal d�grad�
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiMainDisrdDet_C /* 
   Unit       : s
   Description: D�lai de confirmation de l'anomalie R�veil principal
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiMainIncstDet_C /* 
   Unit       : s
   Description: D�lai de confirmation de l'incoh�rence R�veil principal
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiMainTransForc_C /* 
   Unit       : s
   Description: Temporisation au bout de laquelle on force l'entr�e en r�veil principal
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiMainWkuReh_C /* 
   Unit       : s
   Description: D�lai de r�habilitation du R�veil principal nominal
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiMaxTiComLatch_C /* 
   Unit       : s
   Description: Dur�e maximum de l'�tat COM Latch
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiMaxTiIntPtlWku_C /* 
   Unit       : s
   Description: Dur�e de pilotage de la ligne RCD � l'�tat haut � l'activation d'un r�veil partiel m
   aitre
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 4000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiMaxTiShutDownPrep_C /* 
   Unit       : s
   Description: Dur�e maximum de la pr�paration � la mise en veille
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiMinTiShutDownPrep_C /* 
   Description: Dur�e minimum de la pr�paration � la mise en veille
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiPtlWkuX1Lock_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel X1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiPtlWkuX2Lock_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel X2
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiPtlWkuX3Lock_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel X3
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiPtlWkuX4Lock_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel X4
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiPtlWkuX5Lock_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel X5
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiPtlWkuX6Lock_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel X6
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiPtlWkuX7Lock_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel X7
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiPtlWkuX8Lock_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel X8
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1000 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiRCDLineCmdAcv_C /* 
   Unit       : s
   Description: D�lai de confirmation du d�faut ligne RCD en court-circuit � la masse
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 10 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiRCDLineScgDet_C /* 
   Unit       : s
   Description: D�lai de r�habilitation du d�faut ligne RCD en court-circuit � la masse
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 10 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiRCDLineScgReh_C /* 
   Unit       : s
   Description: Dur�e pendant laquelle la ligne RCD est pilot�e � l'�tat haut lors d'une demande d'a
   ctivation d'un r�veil partiel ma�tre
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 10 */;
extern AR_MERGEABLE_CALIB_16BIT UInt16 UCE_tiTransitoryDeac_C /* 
   Unit       : s
   Description: Dur�e au bout de laquelle on force la sortie de l'�tat transitoire
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 100 */;

#define RCD_STOP_SEC_CALIB_16BIT
#include "RCD_MemMap.h"

#define RCD_START_SEC_CALIB_8BIT
#include "RCD_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_noUCETyp_C /* 
   Description: Type de l'ECU (RCD type 1, RCD type ou APC)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 10 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_spdThdDegDeac_C /* 
   Unit       : km/h
   Description: Seuil de Vitesse permettant de valider la sortie du r�veil principal d�grad�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_spdThdNomDeac_C /* 
   Unit       : km/h
   Description: Seuil de Vitesse permettant de valider la sortie du r�veil principal nominal
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMainWkuAcv_C /* 
   Unit       : s
   Description: D�lai d'activation du R�veil principal nominal
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMaxTiMstPtlWkuY1_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel Y1
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMaxTiMstPtlWkuY2_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel Y2
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMaxTiMstPtlWkuY3_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel Y3
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMaxTiMstPtlWkuY4_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel Y4
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMaxTiMstPtlWkuY5_C /* 
   Unit       : s
   Description: Dur�e maximum du r�veil partiel Y5
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMinTiMstPtlWkuY1_C /* 
   Unit       : s
   Description: Dur�e minimum du r�veil partiel Y1
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMinTiMstPtlWkuY2_C /* 
   Unit       : s
   Description: Dur�e minimum du r�veil partiel Y2
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMinTiMstPtlWkuY3_C /* 
   Unit       : s
   Description: Dur�e minimum du r�veil partiel Y3
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMinTiMstPtlWkuY4_C /* 
   Unit       : s
   Description: Dur�e minimum du r�veil partiel Y4
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiMinTiMstPtlWkuY5_C /* 
   Unit       : s
   Description: Dur�e minimum du r�veil partiel Y5
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiNomMainWkuDeac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du R�veil principal nominal
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX1Acv_C /* 
   Unit       : s
   Description: D�lai d'activation du r�veil partiel X1
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX1Deac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du r�veil partiel X1
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX2Acv_C /* 
   Unit       : s
   Description: D�lai d'activation du r�veil partiel X2
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX2Deac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du r�veil partiel X2
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX3Acv_C /* 
   Unit       : s
   Description: D�lai d'activation du r�veil partiel X3
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX3Deac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du r�veil partiel X3
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX4Acv_C /* 
   Unit       : s
   Description: D�lai d'activation du r�veil partiel X4
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX4Deac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du r�veil partiel X4
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX5Acv_C /* 
   Unit       : s
   Description: D�lai d'activation du r�veil partiel X5
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX5Deac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du r�veil partiel X5
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX6Acv_C /* 
   Unit       : s
   Description: D�lai d'activation du r�veil partiel X6
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX6Deac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du r�veil partiel X6
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX7Acv_C /* 
   Unit       : s
   Description: D�lai d'activation du r�veil partiel X7
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX7Deac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du r�veil partiel X7
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX8Acv_C /* 
   Unit       : s
   Description: D�lai d'activation du r�veil partiel X8
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_tiPtlWkuX8Deac_C /* 
   Unit       : s
   Description: D�lai de d�sactivation du r�veil partiel X8
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_8BIT UInt8 _UCE_tiExtdMainWku_C /* 
   Unit       : s
   Description: D�lai d'extension du R�veil principal "�tendu" (cf UCE_bExtdWkuMain)
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 1 */;

#define RCD_STOP_SEC_CALIB_8BIT
#include "RCD_MemMap.h"

#define RCD_START_SEC_CALIB_BOOLEAN
#include "RCD_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_BOOLEAN: Mergeable Calib 1 bit for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuX1_C /* 
   Description: Calibration d'inhibition du r�veil partiel X1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuX2_C /* 
   Description: Calibration d'inhibition du r�veil partiel X2
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuX3_C /* 
   Description: Calibration d'inhibition du r�veil partiel X3
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuX4_C /* 
   Description: Calibration d'inhibition du r�veil partiel X4
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuX5_C /* 
   Description: Calibration d'inhibition du r�veil partiel X5
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuX6_C /* 
   Description: Calibration d'inhibition du r�veil partiel X6
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuX7_C /* 
   Description: Calibration d'inhibition du r�veil partiel X7
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuX8_C /* 
   Description: Calibration d'inhibition du r�veil partiel X8
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuY1_C /* 
   Description: Calibration d'inhibition du r�veil partiel Y1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuY2_C /* 
   Description: Calibration d'inhibition du r�veil partiel Y2
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuY3_C /* 
   Description: Calibration d'inhibition du r�veil partiel Y3
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuY4_C /* 
   Description: Calibration d'inhibition du r�veil partiel Y4
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bInhPtlWkuY5_C /* 
   Description: Calibration d'inhibition du r�veil partiel Y5
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bSlavePtlWkuX1AcvMod_C /* 
   Description: Calibration permettant d'activer le r�veil partiel esclave X1 sans tenir compte de l
   '�tat de la ligne RCD
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bSlavePtlWkuX2AcvMod_C /* 
   Description: Calibration permettant d'activer le r�veil partiel esclave X2 sans tenir compte de l
   '�tat de la ligne RCD
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bSlavePtlWkuX3AcvMod_C /* 
   Description: Calibration permettant d'activer le r�veil partiel esclave X3 sans tenir compte de l
   '�tat de la ligne RCD
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bSlavePtlWkuX4AcvMod_C /* 
   Description: Calibration permettant d'activer le r�veil partiel esclave X4 sans tenir compte de l
   '�tat de la ligne RCD
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bSlavePtlWkuX5AcvMod_C /* 
   Description: Calibration permettant d'activer le r�veil partiel esclave X5 sans tenir compte de l
   '�tat de la ligne RCD
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bSlavePtlWkuX6AcvMod_C /* 
   Description: Calibration permettant d'activer le r�veil partiel esclave X6 sans tenir compte de l
   '�tat de la ligne RCD
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bSlavePtlWkuX7AcvMod_C /* 
   Description: Calibration permettant d'activer le r�veil partiel esclave X7 sans tenir compte de l
   '�tat de la ligne RCD
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bSlavePtlWkuX8AcvMod_C /* 
   Description: Calibration permettant d'activer le r�veil partiel esclave X8 sans tenir compte de l
   '�tat de la ligne RCD
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define RCD_STOP_SEC_CALIB_BOOLEAN
#include "RCD_MemMap.h"

#define RCD_START_SEC_INTERNAL_VAR_8BIT
#include "RCD_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_8BIT: Display 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 UCE_bfMstPtlWkuAcv /* 
   Description: Vecteur compos� des p bool�ens d'activation des r�veils partiels maitres
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 UCE_bfSlavePtlWkuAcv /* 
   Description: Vecteur compos� des n bool�ens d'activation des r�veils partiels esclaves
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 UCE_stSt_MP;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 UCE_stWkuMainRelSt_MP;

#define RCD_STOP_SEC_INTERNAL_VAR_8BIT
#include "RCD_MemMap.h"

#define RCD_START_SEC_INTERNAL_VAR_BOOLEAN
#include "RCD_MemMap.h"

/******************************************************************************\
   AR_INTERNAL_VAR_DISP_BOOLEAN: Display Boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bComLatchDeac /*
   Description: D�sactivation de l'�tat COM Latch */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bDegMainWkuAcv /*
   Description: Activation du R�veil principal d�grad� */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bDegMainWkuDeac /*
   Description: D�sactivation du r�veil principal d�grad� */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bIntPtlWkuDeac /*
   Description: D�sactivation de l'�tat r�veil partiel interne */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMainWkuAcv /*
   Description: Activation du r�veil principal (config APC) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMainWkuDisrdDet /*
   Description: D�tection de l'anomalie r�veil principal */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMainWkuDisrdReh /*
   Description: R�habilitation de l'anomalie r�veil principal */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMainWkuForcDeac /*
   Description: D�sactivation forc�e du r�veil principal (config APC) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMainWkuIncstDet /*
   Description: D�tection de l'incoh�rence r�veil principal */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMainWkuIncstReh /*
   Description: R�habilitation de l'incoh�rence r�veil principal */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMainWkuNomDeac /*
   Description: D�sactivation du r�veil principal (config APC) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuAcv /*
   Description: Synth�se des activations des r�veils partiels maitres */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuDeac /*
   Description: Synth�se des d�sactivations des r�veils partiels maitres */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY1Acv /*
   Description: Activation du r�veil partiel maitre Y1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY1HldReq /*
   Description: Demande de maintien du r�veil partiel maitre Y1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY1Req /*
   Description: Demande d'activation du r�veil partiel maitre Y1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY2Acv /*
   Description: Activation du r�veil partiel maitre Y2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY2HldReq /*
   Description: Demande de maintien du r�veil partiel maitre Y2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY2Nd /*
   Description: Besoin d'activation du r�veil partiel maitre Y2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY2Req /*
   Description: Demande d'activation du r�veil partiel maitre Y2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY3Acv /*
   Description: Activation du r�veil partiel maitre Y3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY3HldReq /*
   Description: Demande de maintien du r�veil partiel maitre Y3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY3Nd /*
   Description: Besoin d'activation du r�veil partiel maitre Y3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY3Req /*
   Description: Demande d'activation du r�veil partiel maitre Y3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY4Acv /*
   Description: Activation du r�veil partiel maitre Y4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY4HldReq /*
   Description: Demande de maintien du r�veil partiel maitre Y4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY4Nd /*
   Description: Besoin d'activation du r�veil partiel maitre Y4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY4Req /*
   Description: Demande d'activation du r�veil partiel maitre Y4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY5Acv /*
   Description: Activation du r�veil partiel maitre Y5 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY5HldReq /*
   Description: Demande de maintien du r�veil partiel maitre Y5 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY5Nd /*
   Description: Besoin d'activation du r�veil partiel maitre Y5 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bMstPtlWkuY5Req /*
   Description: Demande d'activation du r�veil partiel maitre Y5 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bNomMainWkuAcv /*
   Description: Activation du R�veil principal nominal */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bNomMainWkuDeac /*
   Description: D�sactivation du r�veil principal nominal */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bNomMainWkuReh /*
   Description: R�habilitation du R�veil principal nominal (depuis le r�veil principal d�grad�) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bPtlWkuAcv /*
   Description: Synth�se des activations des r�veils partiels (maitres et esclaves) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bPtlWkuDeac /*
   Description: Synth�se des d�sactivations des r�veils partiels (maitres et esclaves) */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bRCDLineScgDet /*
   Description: D�tection d'un court circuit � la masse sur la ligne RCD */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bRCDLineScgReh /*
   Description: R�habilitation du d�faut court circuit � la masse sur la ligne RCD */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuAcv /*
   Description: Synth�se des activations des r�veils partiels esclaves */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuDeac /*
   Description: Synth�se des d�sactivations des r�veils partiels esclaves */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX1Acv /*
   Description: Activation du r�veil partiel esclave X1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX1Req /*
   Description: Demande d'activation du r�veil partiel esclave X1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX1St /*
   Description: Etat du r�veil partiel esclave X1 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX2Acv /*
   Description: Activation du r�veil partiel esclave X2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX2Req /*
   Description: Demande d'activation du r�veil partiel esclave X2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX2St /*
   Description: Etat du r�veil partiel esclave X2 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX3Acv /*
   Description: Activation du r�veil partiel esclave X3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX3Req /*
   Description: Demande d'activation du r�veil partiel esclave X3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX3St /*
   Description: Etat du r�veil partiel esclave X3 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX4Acv /*
   Description: Activation du r�veil partiel esclave X4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX4Req /*
   Description: Demande d'activation du r�veil partiel esclave X4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX4St /*
   Description: Etat du r�veil partiel esclave X4 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX5Acv /*
   Description: Activation du r�veil partiel esclave X5 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX5Req /*
   Description: Demande d'activation du r�veil partiel esclave X5 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX5St /*
   Description: Etat du r�veil partiel esclave X5 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX6Acv /*
   Description: Activation du r�veil partiel esclave X6 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX6Req /*
   Description: Demande d'activation du r�veil partiel esclave X6 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX6St /*
   Description: Etat du r�veil partiel esclave X6 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX7Acv /*
   Description: Activation du r�veil partiel esclave X7 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX7Req /*
   Description: Demande d'activation du r�veil partiel esclave X7 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX7St /*
   Description: Etat du r�veil partiel esclave X7 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX8Acv /*
   Description: Activation du r�veil partiel esclave X8 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX8Req /*
   Description: Demande d'activation du r�veil partiel esclave X8 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bSlavePtlWkuX8St /*
   Description: Etat du r�veil partiel esclave X8 */;
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean UCE_bTransitoryDeac /*
   Description: D�sactivation de l'�tat transitoire */;

#define RCD_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "RCD_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

#endif/*_RCD_CALIBRATIONS_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
