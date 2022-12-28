/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : TrbActGsl                                               */
/* !Component       : TrbActGslSoftware Component                             */
/*                                                                            */
/* !Module          : TrbActGsl                                               */
/*                                                                            */
/* !File            : TrbActGsl_nvm.h                                         */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive:   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M15-TrbActGsl/5-SOFT-LIV/TrbActGsl_nvm.h_v  $
   $Revision:   1.1  $
   $Author:   adelvare  $
  *****************************************************************************/
/*                   File generated by an automatic coding tool               */
/**************************** </AUTO_FILE_HEADER> *****************************/

/****************************** <MONO INCLUSION> ******************************/
#ifndef TRBACTGSL_NVM_H_
#define TRBACTGSL_NVM_H_

/***************************** <NEEDED INCLUSION> *****************************/
#include "Rte_type.h"

/***************************** <TYPE DECLARATION> *****************************/
typedef struct
{
  SInt16 TrbAct_rRCOReqAdpOfs_NV;
  UInt16 TrbAct_rRCOReqAdpRate_NV;
} TrbActGsl_stNV_Z1_CONST_16BIT;

/************************* <EXTERNAL DATA STRUCTURE> **************************/
#define TrbActGsl_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TrbActGsl_MemMap.h"
extern VAR(TrbActGsl_stNV_Z1_CONST_16BIT, AUTOMATIC) TrbActGsl_sNV_Z1_CONST_16BIT;
#define TrbActGsl_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TrbActGsl_MemMap.h"

#define TrbActGsl_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "TrbActGsl_MemMap.h"
extern CONST(TrbActGsl_stNV_Z1_CONST_16BIT, AUTOMATIC) TrbActGsl_sNV_Z1_CONST_16BIT_r;
#define TrbActGsl_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "TrbActGsl_MemMap.h"

/****************************** <MONO INCLUSION> ******************************/
#endif /* TRBACTGSL_NVM_H_ */ 
