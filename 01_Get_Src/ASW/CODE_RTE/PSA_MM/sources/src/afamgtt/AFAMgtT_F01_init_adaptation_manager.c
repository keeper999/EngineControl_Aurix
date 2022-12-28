/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software Component                              */
/*                                                                            */
/* !File            : AFAMgtT_F01_init_adaptation_manager.c                   */
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
/*   Model name       : AFAMgtT_F01_init_adaptation_manager.mdl               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   adelvare                               $$Date::   22 Aug 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT_F01_init_adaptation_manager.h"
#include "AFAMgtT_F01_init_adaptation_manager_private.h"
#include "AFAMgtT.h"
/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

/* Output and update for referenced model: 'AFAMgtT_F01_init_adaptation_manager' */
void mr_AFAMgtT_F01_init_adaptation_(const Boolean *rtu_FRM_bAcvAdpValRstReq,
  const Boolean *rtu_AFAMgt_bAcvAdpRstDiag_NV, const Boolean
  *rtu_FRM_bAcvAdpClcStRstReq, Boolean *rty_AFAMgt_bAdpOfsRstReq, UInt32
  *rty_AFAMgt_tiDlyLstObs1, Boolean *rty_AFAMgt_bAcvAdpRstDiag, Boolean
  *rty_AFAMgt_bAdpClcRstReq)
{
  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Logic: '<Root>/Logical Operator'
   *  SignalConversion: '<Root>/Signal Conversion4'
   *  SignalConversion: '<Root>/Signal Conversion5'
   */
  if ((*rtu_AFAMgt_bAcvAdpRstDiag_NV) || (*rtu_FRM_bAcvAdpValRstReq)) {
    (*rty_AFAMgt_bAdpOfsRstReq) = TRUE;
    (*rty_AFAMgt_bAdpClcRstReq) = TRUE;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Constant: '<Root>/Constant7'
     *  SignalConversion: '<Root>/Signal Conversion4'
     */
    if ((*rtu_FRM_bAcvAdpClcStRstReq)) {
      (*rty_AFAMgt_bAdpClcRstReq) = TRUE;
    } else {
      (*rty_AFAMgt_bAdpClcRstReq) = FALSE;
    }

    (*rty_AFAMgt_bAdpOfsRstReq) = FALSE;
  }

  /* SignalConversion: '<Root>/Signal Conversion3' */
  (*rty_AFAMgt_bAcvAdpRstDiag) = FALSE;

  /* Lookup2D: '<S1>/Look-Up Table (2-D)'
   * About '<S1>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Input1  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U32  2^-8  FSlope 1.28
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U32_U16_U16( &((*rty_AFAMgt_tiDlyLstObs1)), (&(AFAMgt_tiDlyLstObsThd_M
    [0])), 0U, (&(Inj_concFuStmErr_A[0])), 8U, 0U, (&(Inj_concFuStm_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S1>/Data Type Duplicate2'
   *
   * Regarding '<S1>/Data Type Duplicate2':
   *   Unused code path elimination
   */
}

/* Model initialize function */
void mr_AFAMgtT_F01_init__initialize(void)
{
  /* (no initialization code required) */
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
