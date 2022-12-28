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
/* !File            : AFAMgtT_F03_check_air_mode_stability.c                  */
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
/*   Model name       : AFAMgtT_F03_check_air_mode_stability.mdl              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Jul 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT_F03_check_air_mode_stability.h"
#include "AFAMgtT_F03_check_air_mode_stability_private.h"
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

/* Output and update for referenced model: 'AFAMgtT_F03_check_air_mode_stability' */
void mr_AFAMgtT_F03_check_air_mode_s(const Boolean *rtu_FRM_bInhInMNomMod,
  const Boolean *rtu_AFAMgt_bEveRstStab1, const Boolean *rtu_AFAMgt_bInhAF1,
  const UInt32 *rtu_AFAMgt_tiCntStabAirModPrev, const Boolean
  *rtu_AFAMgt_bInhAirModPrev, Boolean *rty_AFAMgt_bIdcStabAirMod, UInt32
  *rty_AFAMgt_tiCntStabAirMod, Boolean *rty_AFAMgt_bInhAirModTmp)
{
  UInt32 localtmp;

  /* If: '<Root>/If' incorporates:
   *  ActionPort: '<S1>/Action Port'
   *  ActionPort: '<S2>/Action Port'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  SubSystem: '<Root>/F01_Afa_air_mode_stable_no_check'
   *  SubSystem: '<Root>/F02_Afa_air_mode_stable_check'
   *
   * Block requirements for '<Root>/F01_Afa_air_mode_stable_no_check':
   *  1. SubSystem "F01_Afa_air_mode_stable_no_check" !Trace_To : VEMS_R_11 _04434_037.01 ;
   *
   * Block requirements for '<Root>/F02_Afa_air_mode_stable_check':
   *  1. SubSystem "F02_Afa_air_mode_stable_check" !Trace_To : VEMS_R_11 _04434_038.01 ;
   */
  if (((((SInt32)(*rtu_FRM_bInhInMNomMod)) != ((SInt32)
         (*rtu_AFAMgt_bInhAirModPrev))) || (*rtu_AFAMgt_bEveRstStab1)) ||
      (*rtu_AFAMgt_bInhAF1)) {
    /* Constant: '<S1>/Constant4' */
    (*rty_AFAMgt_bIdcStabAirMod) = FALSE;

    /* SignalConversion: '<S1>/Signal Conversion' incorporates:
     *  Constant: '<S1>/AFAMgt_tiMinDlyStabAirMod_C'
     */
    (*rty_AFAMgt_tiCntStabAirMod) = AFAMgt_tiMinDlyStabAirMod_C;
  } else {
    /* If: '<S2>/If' incorporates:
     *  ActionPort: '<S3>/Action Port'
     *  ActionPort: '<S4>/Action Port'
     *  Constant: '<S2>/Constant'
     *  RelationalOperator: '<S2>/Relational Operator2'
     *  SubSystem: '<S2>/F01_Afa_air_mode_stable'
     *  SubSystem: '<S2>/F02_Afa_air_mode_stable_Wait'
     *
     * Block requirements for '<S2>/F01_Afa_air_mode_stable':
     *  1. SubSystem "F01_Afa_air_mode_stable" !Trace_To : VEMS_R_11 _04434_039.01 ;
     *
     * Block requirements for '<S2>/F02_Afa_air_mode_stable_Wait':
     *  1. SubSystem "F02_Afa_air_mode_stable_Wait" !Trace_To : VEMS_R_11 _04434_040.01 ;
     */
    if ((*rtu_AFAMgt_tiCntStabAirModPrev) <= 0U) {
      /* Constant: '<S3>/Constant4' */
      (*rty_AFAMgt_bIdcStabAirMod) = TRUE;

      /* SignalConversion: '<S3>/Signal Conversion' */
      (*rty_AFAMgt_tiCntStabAirMod) = (*rtu_AFAMgt_tiCntStabAirModPrev);
    } else {
      /* Constant: '<S4>/Constant4' */
      (*rty_AFAMgt_bIdcStabAirMod) = FALSE;

      /* Sum: '<S4>/Add1' incorporates:
       *  Constant: '<S4>/AFAMgt_tiSampleSlow_SC'
       */
      localtmp = (*rtu_AFAMgt_tiCntStabAirModPrev) - ((((UInt32)
        AFAMgt_tiSampleSlow_SC) * 52429U) >> 19);
      if (localtmp > (*rtu_AFAMgt_tiCntStabAirModPrev)) {
        localtmp = 0U;
      }

      (*rty_AFAMgt_tiCntStabAirMod) = localtmp;
    }
  }

  /* SignalConversion: '<Root>/Signal Conversion1' */
  (*rty_AFAMgt_bInhAirModTmp) = (*rtu_FRM_bInhInMNomMod);
}

/* Model initialize function */
void mr_AFAMgtT_F03_check_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
