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
/* !File            : AFAMgtT_F01_AFAAdpCndChk.c                              */
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
/*   Model name       : AFAMgtT_F01_AFAAdpCndChk.mdl                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Jul 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT_F01_AFAAdpCndChk.h"
#include "AFAMgtT_F01_AFAAdpCndChk_private.h"
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

/* Output and update for referenced model: 'AFAMgtT_F01_AFAAdpCndChk' */
void mr_AFAMgtT_F01_AFAAdpCndChk(const UInt16 *rtu_AFA_noAdpEfc, const UInt8
  *rtu_AFA_noObsDone, const Boolean *rtu_AFA_bIdcCohLstObs, Boolean
  *rty_AFAMgt_bAdpEfc1)
{
  /* Outputs for atomic SubSystem: '<Root>/AFAMgtT_F01_AFAAdpCndChk' *
   * Block requirements for '<Root>/AFAMgtT_F01_AFAAdpCndChk':
   *  1. SubSystem "AFAMgtT_F01_AFAAdpCndChk" !Trace_To : VEMS_R_11 _04434_053.01 ;
   */

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Constant: '<S1>/AFAMgt_noFirstObsDoneThd_C'
   *  Constant: '<S1>/AFAMgt_noObsDoneThd_C'
   *  Constant: '<S1>/Constant16'
   *  Logic: '<S1>/Logical Operator'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  RelationalOperator: '<S1>/Relational Operator1'
   *  RelationalOperator: '<S1>/Relational Operator2'
   */
  (*rty_AFAMgt_bAdpEfc1) = (((((*rtu_AFA_noAdpEfc) > 0) || (((UInt32)
    (*rtu_AFA_noObsDone)) > ((UInt32)AFAMgt_noFirstObsDoneThd_C))) &&
    (((UInt32)(*rtu_AFA_noObsDone)) > ((UInt32)AFAMgt_noObsDoneThd_C))) && (*
    rtu_AFA_bIdcCohLstObs));

  /* end of Outputs for SubSystem: '<Root>/AFAMgtT_F01_AFAAdpCndChk' */
}

/* Model initialize function */
void mr_AFAMgtT_F01_AFAAd_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
