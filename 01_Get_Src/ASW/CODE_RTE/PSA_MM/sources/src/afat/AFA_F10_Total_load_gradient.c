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
/* !File            : AFA_F10_Total_load_gradient.c                           */
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
/*   Model name       : AFA_F10_Total_load_gradient.mdl                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F10_Total_load_gradient.h"
#include "AFA_F10_Total_load_gradient_private.h"
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


#define AFAT_START_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt32 AFA_rTotLdGrd_pDsThr;         /* '<S1>/Data Type Conversion2' */

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F10_Total_load_gradient' */
void mr_AFA_F10_Total_load_gradient(const UInt16 *rtu_AFA_facSlopEfcGrd_pDsThr,
  const UInt16 *rtu_AFA_rTotLdExCorFil, const UInt32
  *rtu_AFA_facOfsEfcGrd_pDsThr, const UInt16 *rtu_AFA_rMassAirScv, UInt32
  *rty_AFA_rTotLdGrd_pDsThr)
{
  Float32 localDivide;
  Float32d localtmp;

  /* Product: '<S1>/Divide' incorporates:
   *  Sum: '<Root>/Sum10'
   *  Sum: '<Root>/Sum8'
   */
  localDivide = ((((Float32)(*rtu_AFA_facOfsEfcGrd_pDsThr)) * 2.328306437E-004F)
                 + (((Float32)(*rtu_AFA_facSlopEfcGrd_pDsThr)) *
                    1.525878906E-004F)) / ((((Float32)(*rtu_AFA_rTotLdExCorFil))
    * 6.103515625E-005F) + (((Float32)(*rtu_AFA_rMassAirScv)) *
    6.103515625E-005F));

  /* Outputs for atomic SubSystem: '<S1>/If Action Subsystem3' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Constant2'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  Saturate: '<S3>/Saturation'
   */
  if (localDivide != localDivide) {
    localDivide = 0.0F;
  } else {
    localDivide = rt_SATURATE(localDivide, -3.000000005E+038F, 3.000000005E+038F);
  }

  /* end of Outputs for SubSystem: '<S1>/If Action Subsystem3' */

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  localtmp = ((Float32d)localDivide) / 2.3283064365386963E-004F;
  if (localtmp < 4.294967296E+009F) {
    if (localtmp >= 0.0F) {
      AFA_rTotLdGrd_pDsThr = (UInt32)localtmp;
    } else {
      AFA_rTotLdGrd_pDsThr = 0U;
    }
  } else {
    AFA_rTotLdGrd_pDsThr = MAX_uint32_T;
  }

  /* SignalConversion: '<Root>/Signal1' */
  (*rty_AFA_rTotLdGrd_pDsThr) = AFA_rTotLdGrd_pDsThr;
}

/* Model initialize function */
void mr_AFA_F10_Total_loa_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
