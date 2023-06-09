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
 ***  %name: ThMgt_003_TEV_fct.h %
 *** 
 ***  %version: 15.2.build1 %
 *** 
 ***  %date_modified: Thu Nov 14 17:48:10 2013 %
 *** 
 *** 
 ***  %derived_by: u299919 %
 ***  %release: ThMgt/14.2 %
 ***  %full_filespec: ThMgt_003_TEV_fct.h-15.2.build1:incl:3 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : mdl_200ms
 *** TargetLink subsystem : mdl_200ms/ThMgt
 *** Codefile             : thmgt_003_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2013-10-29 10:59:40
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

#ifndef _THMGT_003_TEV_FCT_H_
#define _THMGT_003_TEV_FCT_H_

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

#define THMGT_START_SEC_GLOBAL_16BIT
#include "ThMgt_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 RE003_AirSysByp_rOpEGRCoBypReq_in /* 
   Unit       : %
   Description: Commande de base du bypass echangeur EGR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_AntiBoil_tECTReqDly_in /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin anti-�bullition)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_AtyModMgt_tECTReq_in /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin mode atypique)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_CoAftsMgt_tECTAftsReq_in /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin APV)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT UInt16 RE003_EGRVlvByp_rOp_in /* 
   Unit       : %
   Description: Position vanne EGR
   LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT UInt16 RE003_EngMByp_mfDsEGRCoEstim_in /* 
   Unit       : kg/h
   Description: D�bit de gaz EGR
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_IF_GLOBAL_16BIT UInt16 RE003_EngMByp_mfEgEstim_in /* 
   Unit       : kg/h
   Description: D�bit massique des gaz d'�chappement
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 1400 */;
extern AR_IF_GLOBAL_16BIT UInt16 RE003_ExtByp_nEng_in /* 
   Unit       : RPM
   Description: R�gime moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tAirExtMes_in /* 
   Unit       : �C
   Description: Temp�rature d'air ext�rieur
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tAirUsCmprMes_in /* 
   Unit       : �C
   Description: Temp�rature d'air avant compresseur
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tCoMes_in /* 
   Unit       : �C
   Description: Temp�rature d'eau moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tDsThrMes_in /* 
   Unit       : �C
   Description: Temp�rature d'air apr�s papillon 
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tECTSp_in /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (ext�rieure)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tFuMes_in /* 
   Unit       : �C
   Description: Temp�rature du carburant
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tOilMes_in /* 
   Unit       : �C
   Description: Temp�rature de l'huile moteur
   LSB: 0.1 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tUsPFlt_in /* 
   Unit       : �C
   Description: Temp�rature amont FAP
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 1000 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_ExtByp_tUsThrMes_in /* 
   Unit       : �C
   Description: Temp�rature d'air avant papillon
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_GBxCo_tECTReqDly_in /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin BVA)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_InpClc_tAirInMes_in /* 
   Unit       : �C
   Description: Temp�rature d'air d'admission
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_InpClc_tCAC_in /* 
   Unit       : �C
   Description: Temp�rature de RAS
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 200 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_InpClc_tEg_in /* 
   Unit       : �C
   Description: Temp�rature de gaz d'�chappement
   LSB: 2^0 OFF:  0 MIN/MAX:  -50 .. 1250 */;
extern AR_IF_GLOBAL_16BIT UInt16 RE003_InpClc_tqIdcEstim_in /* 
   Unit       : N.m
   Description: Couple moteur indiqu�
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 2000 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_KnkProt_tECTAdpReq_in /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin d�rive de l'adaptatif)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_KnkProt_tECTTAirReq_in /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP (besoin T� d'air soupape)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_StgByp_agStrWhl_in /* 
   Unit       : deg
   Description: Angle de volant
   LSB: 0.1 OFF:  0 MIN/MAX:  -780 .. 780 */;
extern AR_IF_GLOBAL_16BIT UInt16 RE003_StgByp_agvStrWhl_in /* 
   Unit       : deg/s
   Description: Vitesse de rotation de volant
   LSB: 2^2 OFF:  0 MIN/MAX:  0 .. 1060 */;
extern AR_IF_GLOBAL_16BIT SInt16 RE003_UndHoTMgt_tECTReq_in /* 
   Unit       : �C
   Description: Consigne de temp�rature ThP  (besoin sous-capot)
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT SInt16 ThMgt_tCoReg_out /* 
   Unit       : �C
   Description: Temp�rature d'eau de r�gulation
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT UInt16 ThMgt_wThFil_out /* 
   Unit       : J
   Description: Energie thermique filtr�e Dim = 1x1
   LSB: 10 OFF:  0 MIN/MAX:  0 .. 25000 */;

#define THMGT_STOP_SEC_GLOBAL_16BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_GLOBAL_32BIT
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_32BIT: Global 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_IF_GLOBAL_32BIT UInt32 RE003_EOMByp_tiEngStop_in /* 
   Unit       : s
   Description: Temps d'arr�t moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 864000 */;

#define THMGT_STOP_SEC_GLOBAL_32BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_GLOBAL_8BIT
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 ThMgt_RE003_CoPTSt_stEng_in /* 
   Description: Anciens �tats moteur reconstruits � partir des nouveaux
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 15 */;
extern AR_IF_GLOBAL_8BIT UInt8 ThMgt_RE003_CoPtFH_stPwt_in /* 
   Description: �tat GMP Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 15 */;
extern AR_IF_GLOBAL_8BIT UInt8 ThMgt_RE003_Ext_spdVeh_in /* 
   Unit       : km/h
   Description: vitesse v�hicule avec r�solution diff�rente, ce flux est le flux utilis� pour les pa
   ram�tres EOBD envoy�s sur le CAN
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;
extern AR_IF_GLOBAL_8BIT UInt8 ThMgt_RE003_Ext_stACTypCf_in /* 
   Description: Pr�sence et type de climatisation (R�fri)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_IF_GLOBAL_8BIT UInt8 ThMgt_RE003_Ext_stGBxCf_in /* 
   Description: Type de boite de vitesse
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_IF_GLOBAL_8BIT UInt8 ThMgt_RE003_Ext_stVSSCf_in /* 
   Description: Configuration du DMT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

#define THMGT_STOP_SEC_GLOBAL_8BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_GLOBAL_BOOLEAN
#include "ThMgt_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean RE003_AtyModMgt_bLoTCoRegReq_in /* 
   Description: Demande de temp�rature basse de r�gulation (besoin mode atypique)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE003_CoVlvCtl_bRstStopHldDly_in /* 
   Description: Remise � z�ro du maintien en stop
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE003_FRMByp_bAcvLoTCoReg_in /* 
   Description: Activation d'une consigne de r�gulation basse (ThP et GHEM)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE003_FRMByp_bAcvVeryLoTCoReg_in /* 
   Description: Activation d'une consigne de r�gulation tr�s basse (ThP et GHEM)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE003_FRMByp_bInhTCoColdDiag_in /* 
   Description: Inhibition du diagnostic de temp�rature d'eau � froid
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE003_OilDilProt_bLoTCoRegReq_in /* 
   Description: Demande de temp�rature basse de r�gulation (besoin dilution)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE003_UndHoTMgt_bLoTCoRegReq_in /* 
   Description: Demande de temp�rature basse de r�gulation (besoin sous-capot)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ThMgt_RE003_Ext_bACCf_in /* 
   Description: Configuration de la climatisation (euro 5) Dim 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ThMgt_RE003_Ext_bFSFCf_in /* 
   Description: Flag de t�l�codage MEAP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ThMgt_RE003_Ext_bKeyOff_in /* 
   Description: Etat de la coupure du contact
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ThMgt_bDgoTCoOverEstim_out /* 
   Description: Diagnostic de temp�rature d'eau sur-estim�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ThMgt_bDgoTCoUndEstim_out /* 
   Description: Diagnostic de temp�rature d'eau sous-estim�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ThMgt_bMonRunTCoOverEstim_out /* 
   Description: Diagnostic de temp�rature d'eau sur-estim�e en cours de r�alisation
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ThMgt_bMonRunTCoUndEstim_out /* 
   Description: Diagnostic de temp�rature d'eau sous-estim�e en cours de r�alisation
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define THMGT_STOP_SEC_GLOBAL_BOOLEAN
#include "ThMgt_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void ThMgt_003_TEV_fct(Void);
extern Void ThMgt_003_TEV_ini(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void ThMgt_003_FctVarInit(Void);


#endif/*_THMGT_003_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
