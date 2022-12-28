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
/* !File            : AFAMgtT_F01_adaptation_observations_delay.c             */
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
/*   Model name       : AFAMgtT_F01_adaptation_observations_delay.mdl         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   05 May 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT_F01_adaptation_observations_delay.h"
#include "AFAMgtT_F01_adaptation_observations_delay_private.h"
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

/* Output and update for referenced model: 'AFAMgtT_F01_adaptation_observations_delay' */
void mr_AFAMgtT_F01_adaptation_obser(const Boolean *rtu_AFA_bAuthClsCanPurg,
  const UInt16 *rtu_CanPurg_concFuStmErr, const UInt16
  *rtu_CanPurg_concFuStmEstim, UInt32 *rty_AFAMgt_tiDlyLstObs2)
{
  /* local block i/o variables */
  UInt32 localLookUpTable2D;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/AFAMgt_tiDlyLstObsDftThd_C'
   *  Inport: '<Root>/CanPurg_concFuStmErr'
   *  Inport: '<Root>/CanPurg_concFuStmEstim'
   *  Lookup2D: '<S1>/Look-Up Table (2-D)'
   */
  if ((*rtu_AFA_bAuthClsCanPurg)) {
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
    Look2D_U32_U16_U16( &(localLookUpTable2D), (&(AFAMgt_tiDlyLstObsThd_M[0])),
                       (*rtu_CanPurg_concFuStmErr), (&(Inj_concFuStmErr_A[0])),
                       8U, (*rtu_CanPurg_concFuStmEstim), (&(Inj_concFuStm_A[0])),
                       8U);

    /* DataTypeDuplicate Block: '<S1>/Data Type Duplicate2'
     *
     * Regarding '<S1>/Data Type Duplicate2':
     *   Unused code path elimination
     */
    (*rty_AFAMgt_tiDlyLstObs2) = localLookUpTable2D;
  } else {
    (*rty_AFAMgt_tiDlyLstObs2) = AFAMgt_tiDlyLstObsDftThd_C;
  }
}

/* Model initialize function */
void mr_AFAMgtT_F01_adapt_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
