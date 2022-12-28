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
/* !File            : AFAMgtT_Init.c                                          */
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
/*   Model name       : AFAMgtT_Init.mdl                                      */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   25 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT_Init.h"
#include "AFAMgtT_Init_private.h"

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

/* Output and update for referenced model: 'AFAMgtT_Init' */
void mr_AFAMgtT_Init(Boolean *rty_AFAMgt_bInhAFA, Boolean
                     *rty_AFAMgt_bAdpEfcReq, Boolean *rty_AFAMgt_bAuthAdpReq,
                     Boolean *rty_AFAMgt_bAdpObsReq, Boolean
                     *rty_AFAMgt_bIdcInjrMdlCnd, Boolean
                     *rty_AFAMgt_bIdcTmpObsCnd)
{
  /* Constant: '<Root>/Constant' */
  (*rty_AFAMgt_bInhAFA) = FALSE;

  /* Constant: '<Root>/Constant1' */
  (*rty_AFAMgt_bAdpEfcReq) = FALSE;

  /* Constant: '<Root>/Constant2' */
  (*rty_AFAMgt_bAuthAdpReq) = FALSE;

  /* Constant: '<Root>/Constant3' */
  (*rty_AFAMgt_bAdpObsReq) = FALSE;

  /* Constant: '<Root>/Constant4' */
  (*rty_AFAMgt_bIdcInjrMdlCnd) = FALSE;

  /* Constant: '<Root>/Constant5' */
  (*rty_AFAMgt_bIdcTmpObsCnd) = FALSE;
}

/* Model initialize function */
void mr_AFAMgtT_Init_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
