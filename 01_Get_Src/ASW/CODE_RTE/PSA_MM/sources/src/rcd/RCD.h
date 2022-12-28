/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : RCD.h
* Description   : Interface AUTOSAR du module RCD avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 12-May-2010(12:3:18)
*******************************************************************************/

#ifndef _RCD_H_
#define _RCD_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define RCD_START_SEC_CONST_VERSION_MODULE_8BIT
#include "RCD_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 RCD_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 RCD_ModuleVersion_Minor_MP;
#define RCD_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "RCD_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define RCD_START_SEC_CALIB_BOOLEAN
#include "RCD_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RCD_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bLINComReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bRCDLineCmd_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bShutDownAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bPwrlAcv_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bWkuMain_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bExtdWkuMain_B;
#define RCD_STOP_SEC_CALIB_BOOLEAN
#include "RCD_MemMap.h"

#define RCD_START_SEC_CALIB_8BIT
#include "RCD_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_stCAN2ComReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_stCAN3ComReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_bfMstPtlWkuReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_stCAN1ComReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 UCE_bfSlavePtlWkuSt_B;
#define RCD_STOP_SEC_CALIB_8BIT
#include "RCD_MemMap.h"

#endif/*_RCD_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

