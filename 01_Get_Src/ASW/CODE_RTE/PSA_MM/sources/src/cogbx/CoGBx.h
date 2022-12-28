/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : CoGBx.h
* Description   : Interface AUTOSAR du module CoGBx avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 25-Aug-2010(11:31:55)
*******************************************************************************/

#ifndef _COGBX_H_
#define _COGBX_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define COGBX_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CoGBx_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoGBx_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoGBx_ModuleVersion_Minor_MP;
#define COGBX_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CoGBx_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define COGBX_START_SEC_CALIB_BOOLEAN
#include "CoGBx_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean COGBX_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean Clu_bCluPedxVV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean Clu_bDrvTra_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean Clu_bCluPedEng_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSIPcordAirSys_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bCluDiEgdCord_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bRvsCord_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSIPCord_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean Tra_bGearManVld_B;
#define COGBX_STOP_SEC_CALIB_BOOLEAN
#include "CoGBx_MemMap.h"

#define COGBX_START_SEC_CALIB_8BIT
#include "CoGBx_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqDem_rGearRatAftRng_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noEgdGearCordExtd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noEgdGearCord_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noGearCord_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noGearCordDrivFil_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noTarGearCord_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 Tra_noGearMan_B;
extern AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noEgdGearCordIt_B;
extern AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noTarGearCordIt_B;
#define COGBX_STOP_SEC_CALIB_8BIT
#include "CoGBx_MemMap.h"

#define COGBX_START_SEC_CALIB_32BIT
#include "CoGBx_MemMap.h"
extern AR_MERGEABLE_CALIB_32BIT UInt32 CoPt_spdVehGearRatCord_B;
#define COGBX_STOP_SEC_CALIB_32BIT
#include "CoGBx_MemMap.h"

#endif/*_COGBX_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

