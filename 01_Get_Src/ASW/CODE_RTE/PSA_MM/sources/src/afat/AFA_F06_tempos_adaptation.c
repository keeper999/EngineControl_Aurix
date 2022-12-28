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
/* !File            : AFA_F06_tempos_adaptation.c                             */
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
/*   Model name       : AFA_F06_tempos_adaptation.mdl                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   adelvare                               $$Date::   10 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F06_tempos_adaptation.h"
#include "AFA_F06_tempos_adaptation_private.h"
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

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Output and update for referenced model: 'AFA_F06_tempos_adaptation' */
void mr_AFA_F06_tempos_adaptation(const UInt32 *rtu_AFA_tiDlyLstObsPrev,
  UInt32 *rty_AFA_tiDlyLstObs)
{
  UInt32 localtmp;

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/AFA_tiSampleSlow_SC'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  localtmp = ((UInt32)AFA_tiSampleSlow_SC) * 52429U;
  localtmp = ((UInt32)(((localtmp & 262144U) != 0U) + ((SInt32)(localtmp >>
    19U)))) + (*rtu_AFA_tiDlyLstObsPrev);
  if (localtmp < (*rtu_AFA_tiDlyLstObsPrev)) {
    localtmp = MAX_uint32_T;
  }

  (*rty_AFA_tiDlyLstObs) = localtmp;
}

/* Model initialize function */
void mr_AFA_F06_tempos_ad_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
