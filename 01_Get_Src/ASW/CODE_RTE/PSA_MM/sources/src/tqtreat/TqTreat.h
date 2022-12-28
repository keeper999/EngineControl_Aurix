/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : TqTreat.h
* Description   : Interface AUTOSAR du module TqTreat avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 27-Jan-2011(11:54:38)
*******************************************************************************/

#ifndef _TQTREAT_H_
#define _TQTREAT_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define TQTREAT_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TqTreat_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqTreat_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqTreat_ModuleVersion_Minor_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqTreat_ModuleVersion_Build_MP;
#define TQTREAT_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TqTreat_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define TQTREAT_START_SEC_CALIB_BOOLEAN
#include "TqTreat_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TQTREAT_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TqSys_bAcvVehSpdCtlLim_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TqSys_bAcvVehSpdCtlReg_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TqSys_bTypFu_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoBrk_bAcvBrk_B;
#define TQTREAT_STOP_SEC_CALIB_BOOLEAN
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_CALIB_8BIT
#include "TqTreat_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqSys_idxTqAccu_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqSys_stTypPwtCf_B;
#define TQTREAT_STOP_SEC_CALIB_8BIT
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_CALIB_16BIT
#include "TqTreat_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 Eng_nCkFil_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 TreatTenms_nCkRaw_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 TreatTDC_nCkFil_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEng1_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEng2_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiEngCrankStrt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiEngRunStrt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEngAvr_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEngClc0_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEngClc1_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 TreatTenms_nCkGrd_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 TreatTenms_nCkTDCDelta_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 TreatTenms_nCkGrdFil_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 TreatTDC_nCkTDCDelta_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 TreatTDC_nCkGrd_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 TreatTDC_nCkGrdFil_B;
#define TQTREAT_STOP_SEC_CALIB_16BIT
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_CALIB_32BIT
#include "TqTreat_MemMap.h"
extern AR_MERGEABLE_CALIB_32BIT UInt32 EOM_tiEngModStp_B;
extern AR_MERGEABLE_CALIB_32BIT UInt32 EOM_tiEngRun_B;
#define TQTREAT_STOP_SEC_CALIB_32BIT
#include "TqTreat_MemMap.h"

#endif/*_TQTREAT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

