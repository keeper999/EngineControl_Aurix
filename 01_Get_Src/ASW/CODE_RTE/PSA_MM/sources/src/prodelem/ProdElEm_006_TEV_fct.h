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
 ***  %name: ProdElEm_006_TEV_fct.h %
 *** 
 ***  %version: 4.6 %
 *** 
 ***  %date_modified: Fri Feb 10 18:43:48 2012 %
 *** 
 *** 
 ***  %derived_by: e378489 %
 ***  %release: ProdElEm/4.0 %
 ***  %full_filespec: ProdElEm_006_TEV_fct.h-4.6:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : mdl_01552_09_00346_ElProdMgt
 *** TargetLink subsystem : mdl_01552_09_00346_ElProdMgt/ProdElEm_006
 *** Codefile             : prodelem_006_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2012-02-10 10:53:12
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

#ifndef _PRODELEM_006_TEV_FCT_H_
#define _PRODELEM_006_TEV_FCT_H_

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

struct tag_SBFS_F02_chart_Memorisation_correction_Ufloat_006_tp {
   unsigned int C0061_F02_char__ction_Ufloat_ns : 3;
}; /* Type of structure containing bitfields for Stateflow chart  */
/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

#define PRODELEM_START_SEC_GLOBAL_16BIT
#include "ProdElEm_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 ElProdMgt_iExctMax_out /* 
   Unit       : A
   Description: Valeur max du courant d'excitation
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 16 */;
extern AR_IF_GLOBAL_16BIT SInt16 ElProdMgt_rSoCErrEstim_out /* 
   Unit       : %
   Description: Erreur estim�e par ElProdMgt sur le SOC du BECB
   LSB: 2^-4 OFF:  0 MIN/MAX:  -25 .. 25 */;
extern AR_IF_GLOBAL_16BIT UInt16 ElProdMgt_tqAltEstim_out /* 
   Unit       : N.m
   Description: Estimation du couple pr�lev� par l'alternateur
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 30 */;
extern AR_IF_GLOBAL_16BIT UInt16 ElProdMgt_uBattSp_out /* 
   Unit       : V
   Description: Consigne de tension de r�gulation ramen�e aux bornes de la batterie
   LSB: 2^-7 OFF:  0 MIN/MAX:  10.6015625 .. 16 */;
extern AR_IF_GLOBAL_16BIT UInt16 ElProdMgt_uElProdSp_out /* 
   Unit       : V
   Description: Consigne de tension de production
   LSB: 2^-7 OFF:  0 MIN/MAX:  10.6015625 .. 16 */;
extern AR_IF_GLOBAL_16BIT SInt16 ElProdMgt_uOfsLossCor_out /* 
   Unit       : N.m
   Description: Estimation du couple pr�lev� par l'alternateur
   LSB: 2^-7 OFF:  0 MIN/MAX:  -1 .. 1 */;
extern AR_IF_GLOBAL_16BIT SInt16 ElProdMgt_uOfs_uElProdSp_out /* 
   Unit       : V
   Description: Offset sur la consigne de tension de production
   LSB: 2^-7 OFF:  0 MIN/MAX:  -5 .. 5 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_BatMgt_rBattSoCCor_in /* 
   Unit       : %
   Description: Etat de charge de la batterie 12V corrig� par BatMgt
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT SInt16 ProdElEm_006_BatMgt_tBattMes_in /* 
   Unit       : �C
   Description: Temp�rature mesur�e de la batterie 12V renvoy�e par BatMgt
   LSB: 2^-1 OFF:  0 MIN/MAX:  -30 .. 85 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_BatMgt_uBattMes_in /* 
   Unit       : V
   Description: Tension mesur�e aux bornes de la batterie 12V renvoy�e par BatMgt
   LSB: 2^-7 OFF:  0 MIN/MAX:  5 .. 18 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_CoOptmEl_rBattSoCSp_in /* 
   Unit       : %
   Description: Consigne de SOC de r�gulation
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_CoOptmEl_uMax_in /* 
   Unit       : V
   Description: Tension max � limiter par le producteur d'�nergie
   LSB: 2^-7 OFF:  0 MIN/MAX:  10.6015625 .. 16 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_CoOptmEl_uMinInc_in /* 
   Unit       : V
   Description: Tension min augment�e � garantir par le producteur d'�nergie
   LSB: 2^-7 OFF:  0 MIN/MAX:  10.6015625 .. 16 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_Eng_nCkFil_in /* 
   Unit       : RPM
   Description: R�gime moteur filtr� envoy� � 10ms
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_Ext_facRatTqAltCf_in /* 
   Unit       : -
   Description: Coefficient de d�multiplication - tous type ALTERNATEUR
   LSB: 2^-7 OFF:  0 MIN/MAX:  0 .. 10 */;
extern AR_IF_GLOBAL_16BIT SInt16 ProdElEm_006_Ext_tCoMes_in /* 
   Unit       : �C
   Description: Temp�rature d eau / coolant temperature. toujours pr�sent. voir CSMT_CGMT_08_0941
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 214 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_RvAltMgt_uRvAltMes_in /* 
   Unit       : V
   Description: Tension mesur�e aux bornes de l'alternateur r�versible
   LSB: 2^-4 OFF:  0 MIN/MAX:  10.625 .. 16 */;
extern AR_IF_GLOBAL_16BIT UInt16 ProdElEm_006_TqLimUH_grdLimVoltCtlDynMax_in /* 
   Unit       : RPM.N.m/s
   Description: Limitation de gradient de couple AR Volt Control adapt�e
   LSB: 250 OFF:  0 MIN/MAX:  1000 .. 125000 */;

#define PRODELEM_STOP_SEC_GLOBAL_16BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_GLOBAL_32BIT
#include "ProdElEm_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_32BIT: Global 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_IF_GLOBAL_32BIT SInt32 ProdElEm_006_BatMgt_iBattMes_in /* 
   Unit       : A
   Description: Courant de la batterie 12V renvoy� par BatMgt
   LSB: 2^-10 OFF:  0 MIN/MAX:  -1500 .. 1500 */;

#define PRODELEM_STOP_SEC_GLOBAL_32BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_GLOBAL_8BIT
#include "ProdElEm_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 ElProdMgt_iAltEstim_out /* 
   Unit       : A
   Description: Courant d�bit� par l'alternateur standard ou pilot� en mode g�n�rateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 255 */;
extern AR_IF_GLOBAL_8BIT UInt8 ElProdMgt_stProdPrgChDi_nEng_out /* 
   Description: D�sactivation de la charge progressive � partir d'un certain r�gime moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 15 */;
extern AR_IF_GLOBAL_8BIT UInt8 ElProdMgt_stProdPrgCh_out /* 
   Description: Valeur de la charge progressive du producteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 15 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_CoOptmEl_grdNegSlop_in /* 
   Unit       : V/s
   Description: Pente n�gative maximale de la tension � limiter par le SEEM
   LSB: 2^-4 OFF:  0 MIN/MAX:  0.0625 .. 10 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_CoOptmEl_grdPosSlop_in /* 
   Unit       : V/s
   Description: Pente positive maximale de la tension � limiter par le SEEM
   LSB: 2^-4 OFF:  0 MIN/MAX:  0.0625 .. 10 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_CoOptmEl_iElNw_in /* 
   Description: Configuration du producteur d'�nergie �lectrique 12V
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 250 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_CoOptmEl_stOptmElCf_in /* 
   Description: Flux de configuration de FEEGO SEEM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_CoOptmEl_stOptmElStra_in /* 
   Description: Etat de la strat�gie FEEGO SEEM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_CoOptmEl_stPrevElProdReq_in /* 
   Description: Etat pr�c�dant la demande de production �lectrique
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_CoOptmEl_stPrgChReq_in /* 
   Description: Valeur de la charge progressive requise par la synth�se des contraintes �lectriques
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 15 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_CoOptmEl_stStraVoltBatt_in /* 
   Description: Strat�gie de calcul des tensions suivant les modes d�grad�s
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_Ext_iAltExct_in /* 
   Unit       : A
   Description: Courant d'excitation alternateur
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 25.4 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_Ext_idxCtlAltProvIdf_in /* 
   Description: Identifiant fournisseur alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_Ext_rAltCycOp_in /* 
   Unit       : %
   Description: niveau de production de l'alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_Ext_stAltClasCf_in /* 
   Description: Configuration de la classe d'alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_Ext_stElProdCf_in /* 
   Description: Configuration du producteur d'�nergie �lectrique 12V
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_IF_GLOBAL_8BIT SInt8 ProdElEm_006_Ext_tAir_in /* 
   Description: Temp�rature d'air ext�rieure
   LSB: 2^0 OFF:  0 MIN/MAX:  -40 .. 100 */;
extern AR_IF_GLOBAL_8BIT UInt8 ProdElEm_006_RvAltMgt_nRvAltMes_in /* 
   Unit       : RPM
   Description: R�gime alternateur r�versible mesur�
   LSB: 75 OFF:  0 MIN/MAX:  0 .. 19050 */;

#define PRODELEM_STOP_SEC_GLOBAL_8BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_GLOBAL_BOOLEAN
#include "ProdElEm_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean ElProdMgt_bAcvCoefFilDftAlt_out /* 
   Description: Activation du coefficient de filtrage du couple sur pr�sence d'un d�faut alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ElProdMgt_bDgoCorLoss_out /* 
   Description: R�sultat diagnostic sur la compensation des pertes en lignes et dispersion producteu
   r
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ElProdMgt_bDgoCorSpCur_out /* 
   Description: R�sultat diagnostic de la boucle de courant de la batterie 12V
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ElProdMgt_bMonRunCorLoss_out /* 
   Description: Diag actif sur la compensation des pertes en lignes et dispersion producteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ElProdMgt_bMonRunCorSpCur_out /* 
   Description: Diag actif de la boucle de courant de la batterie 12V
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bAcvElProdMgtStraDftCom_in /* 
   Description: Flag de reconfiguration activant le calcul du courant d'excitation sur d�faut de com
   munication avec l'alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bAcvElProdMgtStraDftEl_in /* 
   Description: Flag de reconfiguration activant le calcul du courant d'excitation sur d�faut �lectr
   ique de l'alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bAcvElProdMgtStraDftMec_in /* 
   Description: Flag de reconfiguration activant le calcul du courant d'excitation sur d�faut m�cani
   que de l'alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bInhElProdMgtAltOfsSpMes_in /* 
   Description: Flag de reconfiguration inhibant le calcul de la dispersion alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bInhElProdMgtAltProvIdf_in /* 
   Description: Flag de reconfiguration inhibant la prise en compte du fournisseur de l'alternateur 
   pilot� pour le calcul du couple pr�lev�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bInhElProdMgtAltVoltSp_in /* 
   Description: Flag de reconfiguration inhibant la r�gulation de la tension alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bInhElProdMgtCorOfsLoss_in /* 
   Description: Flag de reconfiguration inhibant la correction des pertes en ligne et dispersion alt
   ernateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bInhElProdMgtCorVoltSp_in /* 
   Description: Flag de reconfiguration inhibant la correction de la tension de floating
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bInhElProdMgtDiagCorLoss_in /* 
   Description: Flag de reconfiguration inhibant le diagnostic sur la compensation des pertes en lig
   ne et/ou dispersion alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_FRM_bInhElProdMgtTqAltLoss_in /* 
   Description: Flag de reconfiguration inhibant le calcul du couple pr�lev� par l'alternateur stand
   ard
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean ProdElEm_006_RvAltMgt_bIdcVldCurGenMod_in /* 
   Description: Flag de reconfiguration inhibant le calcul de la dispersion alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define PRODELEM_STOP_SEC_GLOBAL_BOOLEAN
#include "ProdElEm_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void ProdElEm_005_MSE_ini(Void);
extern Void ProdElEm_006_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void ProdElEm_006_FctVarInit(Void);


#endif/*_PRODELEM_006_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
