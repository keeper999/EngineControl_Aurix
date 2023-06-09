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
 ***  %name: CoStopStart_016_TEV_fct.h %
 *** 
 ***  %version: 11.4 %
 *** 
 ***  %date_modified: Fri Jul 27 11:23:21 2012 %
 *** 
 *** 
 ***  %derived_by: u349799 %
 ***  %release: CoStopStart/11.0 %
 ***  %full_filespec: CoStopStart_016_TEV_fct.h-11.4:incl:1 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : TL_01460_10_03529
 *** TargetLink subsystem : TL_01460_10_03529/CoStopStart_016
 *** Codefile             : costopstart_016_tev_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2012-07-24 15:17:10
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
 *** Style definition file               : C:\dSPACE_TL_3.0.1\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE_TL_3.0.1\Matlab\Tl\XML\CodeGen\Stylesheets\TL_C
 ***                                       SourceCodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _COSTOPSTART_016_TEV_FCT_H_
#define _COSTOPSTART_016_TEV_FCT_H_

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

struct tag_SBFS_F06_01_01_Confirmation_Chgt_de_Rapport_016_tp {
   unsigned int C0162_Blob_principal_ns : 3;
   unsigned int C0162_Blob_principal : 1;
}; /* Type of structure containing bitfields for Stateflow chart  */
/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

#define COSTOPSTART_START_SEC_GLOBAL_16BIT
#include "CoStopStart_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT UInt16 CoPtUH_nEngClc_out /* 
   Unit       : RPM
   Description: Information sur le r�gime moteur recalcul�e � partir du r�gime alternateur
   LSB: 2^1 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoPtUH_rMaxCluGc_out /* 
   Unit       : %
   Description: Pour APV. Position max de l'embrayage pendant chgt de rapport
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoPtUH_rMinCluRStrt_out /* 
   Unit       : %
   Description: Pour APV. Position mini d'embrayage pdt redem
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT SInt16 CoStopStart_016_CoOptmEl_tqAlt_in /* 
   Unit       : N.m
   Description: Couple pr�lev� machine �lectrique g�n�rique
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoStopStart_016_Ext_nEng_in /* 
   Unit       : RPM
   Description: R�gime moteur valeur brut PMH. toujours pr�sent. voir CSMT_CGMT_08_0941
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoStopStart_016_Ext_rCluPHiFreq_in /* 
   Unit       : %
   Description: Provision pour diversit� besoin sur mesure physique capteur embrayage propostionnel.
    valeur de remlpacement : 0. cas ou STTx BVA/BVMP. voir CSMT_CGMT_08_0941. valeur de remlpacement
    : 0. cas ou STTx BVA/BVMP. voir CSMT_CGMT_08_0941
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoStopStart_016_RvAltMgt_nRvAltMv_in /* 
   Unit       : RPM
   Description: R�gime alternateur r�versible moyenn� sur fen�tre glissante
   LSB: 20 OFF:  0 MIN/MAX:  0 .. 20440 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoStopStart_016_RvAltMgt_tqRvAltGenModMv_in /* 
   Unit       : N.m
   Description: Couple pr�lev� par l'alternateur r�versible en mode g�n�rateur moyenn� sur fen�tre g
   lissante
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 30 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoStopStart_016_TqSys_nTarIdl_in /* 
   Unit       : RPM
   Description: R�gime de ralenti cible final / Final idle target
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
extern AR_IF_GLOBAL_16BIT SInt16 CoStopStart_016_TqSys_tqCkEngReal_in /* 
   Unit       : N.m
   Description: Couple effectif r�alis� instantan� avec post � post moyenn�
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;
extern AR_IF_GLOBAL_16BIT UInt16 CoStopStart_016_Veh_spdVeh_in /* 
   Unit       : km/h
   Description: vitesse v�hicule. La provenance est fonction de l'architecture Electique
   LSB: 2^-7 OFF:  0 MIN/MAX:  0 .. 500 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_32BIT
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_32BIT: Global 32 bits for AUTOSAR modules | Width: 32
\******************************************************************************/
extern AR_IF_GLOBAL_32BIT UInt32 CoStopStart_016_CoPt_spdVehGearRatCord_in /* 
   Unit       : km/h/1000RPM
   Description: Rationde vitesse / r�gime Dim = 1*1
   LSB: 2^-10 OFF:  0 MIN/MAX:  0 .. 255 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_32BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_8BIT UInt8 CoPtUH_noGearTmpBeg_out /* 
   Description: Pour APV. Rapport avant chgt de rapport
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 6 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoPtUH_noGearTmpEnd_out /* 
   Description: Pour APV. Rapport apr�s chgt de rapport
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 6 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoPtUH_stTestPosClu_out /* 
   Description: R�sultat test position embrayage Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_CoPTStNew_stEng_in /* 
   Description: Nouvel �tat moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 9 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_CoPtASE_stPwt_in /* 
   Description: Etats GMP SCAr
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 10 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_CoPtUH_stPwt_in /* 
   Description: Etat GMP UH Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 15 */;
extern AR_IF_GLOBAL_8BIT SInt8 CoStopStart_016_CoReqCha_rSlopStab_in /* 
   Description: Pente statique
   LSB: 2^0 OFF:  0 MIN/MAX:  -30 .. 30 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_CoReqCha_stEngRStrtInh_in /* 
   Description: Demande d'inhibition de red�marrage pour Easymove
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_Ext_stGBxCf_in /* 
   Description: Type de boite
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 2 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_RvAltMgt_nRvAltMes_in /* 
   Unit       : RPM
   Description: R�gime alternateur r�versible mesur�
   LSB: 75 OFF:  0 MIN/MAX:  0 .. 19050 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_RvAltMgt_tqRstrtMaxEstim_in /* 
   Unit       : N.m
   Description: Couple maximum de red�marrage de l'alternateur r�versible estim�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 100 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_TqLimUH_stDrivTyp_in /* 
   Description: Type de roulage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7 */;
extern AR_IF_GLOBAL_8BIT UInt8 CoStopStart_016_Tra_noGearMan_in /* 
   Description: Rapport final (valid�) / Final (validated) gear ratio data
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 8 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT_IRV: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
extern UInt8 DgoFct_stRstrtReq /* 
   Description: Niveau de priorit� de la demande de red�marrage automatique par diagnostic courroie 
   glissante Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 5 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bBltStopAuth_out /* 
   Description: Autorisation arret par glissement fa�ade Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bDgoBlt_out /* 
   Description: R�sultat diagnostic courroie alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bDgoLgEngRStrtInh_out /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 
   1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bDgoORngGcClu_out /* 
   Description: R�sultat Diag Chgment rap pour Embrayage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bDgoORngGcMinClu_out /* 
   Description: R�sultat Diag Chgment rap pour position mbrayage PD1 jamais franchi
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bDgoORngGcNeut_out /* 
   Description: R�sultat Diag Chgment rap pour Point Mort
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bDgoORngGearEnaClu_out /* 
   Description: R�sultat Diag en rapport �tabli. pour embrayage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bDgoORngGearMinClu_out /* 
   Description: R�sultat Diag en rapport �tabli, pour v�rifier position embrayage PD1 toujours franc
   hi
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bDgoORngGearNeut_out /* 
   Description: R�sultat Diag en rapport �tabli. pour Point Mort Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bMonRunBlt_out /* 
   Description: Diag Actif courroie alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bMonRunLgEngRStrtInh_out /* LSB: 2^0 OFF:  0 MIN/MAX:  0 
   .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bMonRunORngGcClu_out /* 
   Description: Diag Actif Chgment rap pour Embrayage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bMonRunORngGcMinClu_out /* 
   Description: Diag Actif Chgment rap pour position embrayage PD1 jamais franchi
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bMonRunORngGcNeut_out /* 
   Description: Diag Actif Chgment rap pour Point Mort
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bMonRunORngGearEnaClu_out /* 
   Description: Diag actif. en rapport �tabli. pour embrayage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bMonRunORngGearMinClu_out /* 
   Description: Diag actif, en rapport �tabli, pour v�rifier position embrayage PD1 toujours franchi
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bMonRunORngGearNeut_out /* 
   Description: Diag actif. en rapport �tabli. pour Point Mort Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bRStrtReqDgoBlt_out /* 
   Description: Demande de red�marrage par FGC
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoPtUH_bTestPrvtBltAcv_out /* 
   Description: Test pr�ventif courroie actif
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_016_ECU_bWkuMain_in /* 
   Description: Etat du r�veil principal (ou principal d�grad�) du CMM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_016_Ext_bNeut_in /* 
   Description: Etat capteur Point Mort
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_016_Ext_bPush_in /* 
   Description: Etat Push STT
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_016_FRM_bInhDgoBltCoPtUH_in /* 
   Description: Reconfiguration inhibant les diagnostics fonctionnels
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_016_FRM_bInhDgoCluNeutCoPtUH_in /* LSB: 2^0 OFF:  0 
   MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean CoStopStart_016_Tra_bGearManVld_in /* 
   Description: Le rapport de bo�te manuelle est valid / Valid manual gear box
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean RE_CoStopStart_016_TEV_MonDrv_bRstrtReq_in /* 
   Description: Demande par le conducteur du redemarrage moteur Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN_IRV: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern Boolean DgoFct_bHealDiagCfLvl1 /* 
   Description: R�sultat test curatif niveau 1 Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern Boolean DgoFct_bSTTOff /* 
   Description: Demande passage � Eco Off par le diagnostic courroie glissante Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define COSTOPSTART_STOP_SEC_GLOBAL_BOOLEAN
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_SEC_NVM_INIT_BOOLEAN: Var Boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_SEC_NVM_INIT_BOOLEAN Boolean DgoFct_bMemValHealLvl1_NV_init;
extern AR_SEC_NVM_INIT_BOOLEAN Boolean DgoFct_bMemValPrvtLvl1_NV_init;
extern AR_SEC_NVM_INIT_BOOLEAN Boolean DgoFct_noMemValHealLvl2_NV_init;

#define COSTOPSTART_STOP_SEC_VAR_BOOLEAN
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void CoStopStart_015_MSE_ini(Void);
extern Void CoStopStart_016_TEV_fct(Void);

/******************************************************************************\
   UserGlobalRestart: static function(s) (invisible for other module)
\******************************************************************************/
extern Void CoStopStart_016_FctVarInit(Void);


#endif/*_COSTOPSTART_016_TEV_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
