/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : ProdElEng.h
* Description   : Interface AUTOSAR du module ProdElEng avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 16-May-2011(10:9:19)
*******************************************************************************/

#ifndef _PRODELENG_H_
#define _PRODELENG_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define PRODELENG_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ProdElEng_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PRODELENG_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PRODELENG_ModuleVersion_Minor_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PRODELENG_ModuleVersion_Build_MP;
#define PRODELENG_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ProdElEng_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define PRODELENG_START_SEC_CALIB_BOOLEAN
#include "ProdElEng_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_012_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_014_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TqLimUH_bFrzReqTqVoltCtl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TqLimUH_bReqClsCnv_B;
#define PRODELENG_STOP_SEC_CALIB_BOOLEAN
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_CALIB_8BIT
#include "ProdElEng_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_stReqBlsVoltCtl_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_stReqUnBlsVoltCtl_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_stDrivTyp_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_bfAcvConstFrntTra1_B;
#define PRODELENG_STOP_SEC_CALIB_8BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_CALIB_16BIT
#include "ProdElEng_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 TqLimUH_grdLimVoltCtlDynMax_B;
#define PRODELENG_STOP_SEC_CALIB_16BIT
#include "ProdElEng_MemMap.h"

#endif/*_PRODELENG_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

