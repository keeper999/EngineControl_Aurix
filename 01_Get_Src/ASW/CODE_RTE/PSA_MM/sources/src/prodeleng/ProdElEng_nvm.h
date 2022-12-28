/******************************************************************************\

 Fichier a creer manuellement


\****************************************************************************/

#ifndef _PRODELENG_NVM__H_
#define _PRODELENG_NVM__H_
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "ProdElEng_014_TEV_fct.h"
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
typedef struct
{
UInt32 TqLimUH_dstTraAcvDrv_NV;
} ProdElEng_StructNvm_1;
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/
//NVRAM Data with recovery values are constants
#define PRODELENG_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEng_MemMap.h"
extern ProdElEng_StructNvm_1 ProdElEng_sNV_Z1_CST_32BIT_1;
#define PRODELENG_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEng_MemMap.h"
extern const ProdElEng_StructNvm_1 ProdElEng_sNV_Z1_CST_32BIT_1_r;
#define PRODELENG_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "ProdElEng_MemMap.h"

#endif/*_PRODELENG_NVM__H_ */
/*----------------------------------------------------------------------------*/
/*  END OF FILE */
/*-----------*/
