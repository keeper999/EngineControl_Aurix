/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA                                                     */
/* !Description     : AFA Software Component                                  */
/*                                                                            */
/* !File            : AFA_F06_Specific_VVT_angle.c                            */
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
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AFA_F06_Specific_VVT_angle.mdl                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F06_Specific_VVT_angle.h"
#include "AFA_F06_Specific_VVT_angle_private.h"
#include "AFAT.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt16 AFA_agCkPosnVlvOvlp;          /* '<Root>/Divide' */
SInt16 AFA_agCkVlvOvlp;               /* '<Root>/Sum' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F06_Specific_VVT_angle' */
void mr_AFA_F06_Specific_VVT_angle(const SInt16 *rtu_AFA_agCkClsExVlvEstimRef1_,
  const SInt16 *rtu_AFA_agCkOpInVlvEstimRef1_, SInt16 *rty_AFA_agCkVlvOvlp,
  UInt16 *rty_AFA_agCkPosnVlvOvlp)
{
  Float32d localtmp;
  SInt32 localtmp_0;

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Sum: '<Root>/Sum1'
   */
  localtmp = ((((Float32d)((((Float32)(*rtu_AFA_agCkOpInVlvEstimRef1_)) * 0.0625F)
    + (((Float32)(*rtu_AFA_agCkClsExVlvEstimRef1_)) * 0.0625F))) / 2.0F) + 96.0F)
    / 0.09375F;
  if (localtmp >= 0.0F) {
    AFA_agCkPosnVlvOvlp = (UInt16)localtmp;
  } else {
    AFA_agCkPosnVlvOvlp = 0U;
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_agCkPosnVlvOvlp) = AFA_agCkPosnVlvOvlp;

  /* Sum: '<Root>/Sum' */
  localtmp_0 = ((*rtu_AFA_agCkClsExVlvEstimRef1_) * 21845) -
    ((*rtu_AFA_agCkOpInVlvEstimRef1_) * 21845);
  localtmp_0 = (localtmp_0 >= 0) ? ((SInt32)(((UInt32)localtmp_0) >> 15U)) :
    (~((SInt32)(((UInt32)(~localtmp_0)) >> 15U)));
  if (localtmp_0 > 32767) {
    AFA_agCkVlvOvlp = MAX_int16_T;
  } else if (localtmp_0 <= -32768) {
    AFA_agCkVlvOvlp = MIN_int16_T;
  } else {
    AFA_agCkVlvOvlp = (SInt16)localtmp_0;
  }

  /* SignalConversion: '<Root>/Signal2' */
  (*rty_AFA_agCkVlvOvlp) = AFA_agCkVlvOvlp;
}

/* Model initialize function */
void mr_AFA_F06_Specific__initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* exported global signals */
  AFA_agCkPosnVlvOvlp = 1024U;
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
