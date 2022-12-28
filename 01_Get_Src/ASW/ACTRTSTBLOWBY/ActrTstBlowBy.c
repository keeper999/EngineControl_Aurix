/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActrTstBlowBy                                           */
/* !Description     : Test actionneur Blow By                                 */
/*                                                                            */
/* !Module          : ActrTstBlowBy                                           */
/*                                                                            */
/* !File            : ActrTstBlowBy.c                                         */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : V02NT1105795 / 02                                       */
/* !OtherRefs       : VEMS V02 ECU#064675                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Jan 17 11:16:37 2013                              */
/*   Model name       : ActrTstBlowBy_AUTOCODE.mdl                            */
/*   Model version    : 1.78                                                  */
/*   Root subsystem   : /ActrTstBlowBy                                        */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/ACTRTSTBLOWBY/ActrTstBlowBy.$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActrTstBlowBy.h"
#include "ActrTstBlowBy_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S4>/F01_BlowBy1TstChart' */
#define IN_NO_ACTIVE_CHILD             (0U)
#define IN_OIL_ACTRTEST_BB1_END        (1U)
#define IN_OIL_ACTRTEST_BB1_IDLE       (2U)
#define IN_OIL_ACTRTEST_BB1_MAX        (1U)
#define IN_OIL_ACTRTEST_BB1_MIN        (2U)
#define IN_TestEnCoursBB1              (3U)

/* Named constants for Stateflow: '<S5>/F01_BlowBy2TstChart' */
#define IN_NO_ACTIVE_CHILD_a           (0U)
#define IN_OIL_ACTRTEST_BB2_END        (1U)
#define IN_OIL_ACTRTEST_BB2_IDLE       (2U)
#define IN_OIL_ACTRTEST_BB2_MAX        (1U)
#define IN_OIL_ACTRTEST_BB2_MIN        (2U)
#define IN_TestEnCoursBB2              (3U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTRTSTBLOWBY_START_SEC_VAR_UNSPECIFIED
#include "ActrTstBlowBy_MemMap.h"

/* Block signals (auto storage) */
BlockIO_ActrTstBlowBy ActrTstBlowBy_B;

/* Block states (auto storage) */
D_Work_ActrTstBlowBy ActrTstBlowBy_DWork;

#define ACTRTSTBLOWBY_STOP_SEC_VAR_UNSPECIFIED
#include "ActrTstBlowBy_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define ACTRTSTBLOWBY_START_SEC_CODE
#include "ActrTstBlowBy_MemMap.h"

void ActrTstBlowBy_ASYNC1(int controlPortIdx)
{
  ActrTstBlowBy_F01_BlowBy1Tst();
  ActrTstBlowBy_F02_BlowBy2Tst();
}

/* Output and update for function-call system: '<S1>/F01_BlowBy1Tst' */
void ActrTstBlowBy_F01_BlowBy1Tst(void)
{
  Boolean localLogicalOperator_i;

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET1 */
  VEMS_vidGET(Srv_bActrTstEna, ActrTstBlowBy_B.VEMS_vidGET1_n);

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET */
  VEMS_vidGET(Code_test_action, ActrTstBlowBy_B.VEMS_vidGET_e);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S4>/CODE_TEST_BLOW_BY_1'
   *  RelationalOperator: '<S4>/Relational Operator'
   */
  localLogicalOperator_i = (ActrTstBlowBy_B.VEMS_vidGET1_n &&
    (ActrTstBlowBy_B.VEMS_vidGET_e == CODE_TEST_BLOW_BY_1));

  /* *
   * Block requirements for '<S4>/F01_BlowBy1TstChart':
   *  1. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_108.01 ;
   *  2. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_109.01 ;
   *  3. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_110.01 ;
   *  4. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04421_111.01 ;
   *  5. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_112.01 ;
   *  6. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_113.01 ;
   *  7. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_114.01 ;
   *  8. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_116.01 ;
   *  9. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_115.01 ;
   *  10. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_118.01 ;
   *  11. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_121.01 ;
   *  12. SubSystem "F01_BlowBy1TstChart" !Trace_To : VEMS_R_11_04422_122.01 ;
   */

  /* Stateflow: '<S4>/F01_BlowBy1TstChart' incorporates:
   *  Constant: '<S4>/ActrTstBlowBy1_OffTime_C'
   *  Constant: '<S4>/ActrTstBlowBy1_OnTime_C'
   *  Constant: '<S4>/ActrTstBlowBy1_Tempo_C'
   *  Constant: '<S4>/ActrTstBlowBy1_TotTime_C'
   *  Constant: '<S4>/OIL_ACTRTEST_BB1_END'
   *  Constant: '<S4>/OIL_ACTRTEST_BB1_IDLE'
   *  Constant: '<S4>/OIL_ACTRTEST_BB1_MAX'
   *  Constant: '<S4>/OIL_ACTRTEST_BB1_MIN'
   *  Constant: '<S4>/Oil_SampleTiMid_SC'
   */
  /* Gateway: ActrTstBlowBy/F01_BlowBy1Tst/F01_BlowBy1TstChart */
  /* During: ActrTstBlowBy/F01_BlowBy1Tst/F01_BlowBy1TstChart */
  if (ActrTstBlowBy_DWork.is_active_c2_ActrTstBlowBy == 0) {
    /* Entry: ActrTstBlowBy/F01_BlowBy1Tst/F01_BlowBy1TstChart */
    ActrTstBlowBy_DWork.is_active_c2_ActrTstBlowBy = 1U;

    /* Transition: '<S8>:10' */
    /* Entry 'OIL_ACTRTEST_BB1_IDLE': '<S8>:1' */
    ActrTstBlowBy_DWork.is_c2_ActrTstBlowBy = IN_OIL_ACTRTEST_BB1_IDLE;
    Oil_stActrTstBB1 = OIL_ACTRTEST_BB1_IDLE;
    ActrTstBlowBy_B.Oil_bBlowByTstCmpl_n = FALSE;
    ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o = FALSE;
    ActrTstBlowBy_B.Oil_bActrTstInProgsBB1_n = FALSE;
  } else {
    switch (ActrTstBlowBy_DWork.is_c2_ActrTstBlowBy) {
     case IN_OIL_ACTRTEST_BB1_END:
      /* During 'OIL_ACTRTEST_BB1_END': '<S8>:3' */
      if ((((SInt32)localLogicalOperator_i) == 1) && (ActrTstBlowBy1_Tempo <= 0))
      {
        /* Transition: '<S8>:9' */
        /* Exit 'OIL_ACTRTEST_BB1_END': '<S8>:3' */
        /* Entry 'OIL_ACTRTEST_BB1_IDLE': '<S8>:1' */
        ActrTstBlowBy_DWork.is_c2_ActrTstBlowBy = IN_OIL_ACTRTEST_BB1_IDLE;
        Oil_stActrTstBB1 = OIL_ACTRTEST_BB1_IDLE;
        ActrTstBlowBy_B.Oil_bBlowByTstCmpl_n = FALSE;
        ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o = FALSE;
        ActrTstBlowBy_B.Oil_bActrTstInProgsBB1_n = FALSE;
      } else {
        ActrTstBlowBy1_Tempo = (UInt16)(rt_MAX((ActrTstBlowBy1_Tempo << 3) -
          ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
      }
      break;

     case IN_OIL_ACTRTEST_BB1_IDLE:
      /* During 'OIL_ACTRTEST_BB1_IDLE': '<S8>:1' */
      if (((SInt32)localLogicalOperator_i) == 1) {
        /* Transition: '<S8>:6' */
        /* Exit 'OIL_ACTRTEST_BB1_IDLE': '<S8>:1' */
        /* Entry 'TestEnCoursBB1': '<S8>:2' */
        ActrTstBlowBy_DWork.is_c2_ActrTstBlowBy = IN_TestEnCoursBB1;
        ActrTstBlowBy1_CumulTime = (UInt16)((UInt32)(((SInt32)(((UInt32)
          (Oil_SampleTiMid_SC * 205)) >> 11)) + ActrTstBlowBy1_TotTime_C));
        ActrTstBlowBy_B.Oil_bActrTstInProgsBB1_n = TRUE;

        /* Entry 'OIL_ACTRTEST_BB1_MAX': '<S8>:4' */
        ActrTstBlowBy_DWork.is_TestEnCoursBB1 = IN_OIL_ACTRTEST_BB1_MAX;
        Oil_stActrTstBB1 = OIL_ACTRTEST_BB1_MAX;
        ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o = TRUE;
        ActrTstBlowBy1_IntTime = ActrTstBlowBy1_OnTime_C;
        ActrTstBlowBy1_CumulTime = (UInt16)(rt_MAX((ActrTstBlowBy1_CumulTime <<
          3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
      }
      break;

     case IN_TestEnCoursBB1:
      /* During 'TestEnCoursBB1': '<S8>:2' */
      if ((((SInt32)localLogicalOperator_i) == 1) && (((UInt32)
            (ActrTstBlowBy1_CumulTime << 11)) <= ((UInt32)(Oil_SampleTiMid_SC *
             205)))) {
        /* Transition: '<S8>:8' */
        /* Exit 'OIL_ACTRTEST_BB1_MAX': '<S8>:4' */
        ActrTstBlowBy_DWork.is_TestEnCoursBB1 = (UInt8)IN_NO_ACTIVE_CHILD;

        /* Exit 'OIL_ACTRTEST_BB1_MIN': '<S8>:5' */
        /* Exit 'TestEnCoursBB1': '<S8>:2' */
        /* Entry 'OIL_ACTRTEST_BB1_END': '<S8>:3' */
        ActrTstBlowBy_DWork.is_c2_ActrTstBlowBy = IN_OIL_ACTRTEST_BB1_END;
        Oil_stActrTstBB1 = OIL_ACTRTEST_BB1_END;
        ActrTstBlowBy_B.Oil_bBlowByTstCmpl_n = TRUE;
        ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o = FALSE;
        ActrTstBlowBy_B.Oil_bActrTstInProgsBB1_n = FALSE;
        ActrTstBlowBy1_Tempo = ActrTstBlowBy1_Tempo_C;
      } else if (((SInt32)localLogicalOperator_i) == 0) {
        /* Transition: '<S8>:7' */
        /* Exit 'OIL_ACTRTEST_BB1_MAX': '<S8>:4' */
        ActrTstBlowBy_DWork.is_TestEnCoursBB1 = (UInt8)IN_NO_ACTIVE_CHILD;

        /* Exit 'OIL_ACTRTEST_BB1_MIN': '<S8>:5' */
        /* Exit 'TestEnCoursBB1': '<S8>:2' */
        /* Entry 'OIL_ACTRTEST_BB1_IDLE': '<S8>:1' */
        ActrTstBlowBy_DWork.is_c2_ActrTstBlowBy = IN_OIL_ACTRTEST_BB1_IDLE;
        Oil_stActrTstBB1 = OIL_ACTRTEST_BB1_IDLE;
        ActrTstBlowBy_B.Oil_bBlowByTstCmpl_n = FALSE;
        ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o = FALSE;
        ActrTstBlowBy_B.Oil_bActrTstInProgsBB1_n = FALSE;
      } else {
        switch (ActrTstBlowBy_DWork.is_TestEnCoursBB1) {
         case IN_OIL_ACTRTEST_BB1_MAX:
          /* During 'OIL_ACTRTEST_BB1_MAX': '<S8>:4' */
          if (((UInt32)(ActrTstBlowBy1_IntTime << 11)) <= ((UInt32)
               (Oil_SampleTiMid_SC * 205))) {
            /* Transition: '<S8>:11' */
            /* Exit 'OIL_ACTRTEST_BB1_MAX': '<S8>:4' */
            /* Entry 'OIL_ACTRTEST_BB1_MIN': '<S8>:5' */
            ActrTstBlowBy_DWork.is_TestEnCoursBB1 = IN_OIL_ACTRTEST_BB1_MIN;
            Oil_stActrTstBB1 = OIL_ACTRTEST_BB1_MIN;
            ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o = FALSE;
            ActrTstBlowBy1_IntTime = ActrTstBlowBy1_OffTime_C;
            ActrTstBlowBy1_CumulTime = (UInt16)(rt_MAX
              ((ActrTstBlowBy1_CumulTime << 3) - ((SInt32)(((UInt32)
              (Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
          } else {
            ActrTstBlowBy1_CumulTime = (UInt16)(rt_MAX
              ((ActrTstBlowBy1_CumulTime << 3) - ((SInt32)(((UInt32)
              (Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
            ActrTstBlowBy1_IntTime = (UInt16)(rt_MAX((ActrTstBlowBy1_IntTime <<
              3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >>
              3);
          }
          break;

         case IN_OIL_ACTRTEST_BB1_MIN:
          /* During 'OIL_ACTRTEST_BB1_MIN': '<S8>:5' */
          if (((UInt32)(ActrTstBlowBy1_IntTime << 11)) <= ((UInt32)
               (Oil_SampleTiMid_SC * 205))) {
            /* Transition: '<S8>:12' */
            /* Exit 'OIL_ACTRTEST_BB1_MIN': '<S8>:5' */
            /* Entry 'OIL_ACTRTEST_BB1_MAX': '<S8>:4' */
            ActrTstBlowBy_DWork.is_TestEnCoursBB1 = IN_OIL_ACTRTEST_BB1_MAX;
            Oil_stActrTstBB1 = OIL_ACTRTEST_BB1_MAX;
            ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o = TRUE;
            ActrTstBlowBy1_IntTime = ActrTstBlowBy1_OnTime_C;
            ActrTstBlowBy1_CumulTime = (UInt16)(rt_MAX
              ((ActrTstBlowBy1_CumulTime << 3) - ((SInt32)(((UInt32)
              (Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
          } else {
            ActrTstBlowBy1_CumulTime = (UInt16)(rt_MAX
              ((ActrTstBlowBy1_CumulTime << 3) - ((SInt32)(((UInt32)
              (Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
            ActrTstBlowBy1_IntTime = (UInt16)(rt_MAX((ActrTstBlowBy1_IntTime <<
              3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >>
              3);
          }
          break;
        }
      }
      break;

     default:
      /* Transition: '<S8>:10' */
      /* Entry 'OIL_ACTRTEST_BB1_IDLE': '<S8>:1' */
      ActrTstBlowBy_DWork.is_c2_ActrTstBlowBy = IN_OIL_ACTRTEST_BB1_IDLE;
      Oil_stActrTstBB1 = OIL_ACTRTEST_BB1_IDLE;
      ActrTstBlowBy_B.Oil_bBlowByTstCmpl_n = FALSE;
      ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o = FALSE;
      ActrTstBlowBy_B.Oil_bActrTstInProgsBB1_n = FALSE;
      break;
    }
  }

  /* Outputs for enable SubSystem: '<S4>/TEST_BLOW_BY_1' incorporates:
   *  Constant: '<S4>/CODE_TEST_BLOW_BY_2'
   *  EnablePort: '<S9>/Enable'
   *  RelationalOperator: '<S4>/Relational Operator1'
   */
  if (ActrTstBlowBy_B.VEMS_vidGET_e == CODE_TEST_BLOW_BY_1) {
    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET1 */
    VEMS_vidSET(Oil_bBlowByTstCmpl, ActrTstBlowBy_B.Oil_bBlowByTstCmpl_n);
  }

  /* end of Outputs for SubSystem: '<S4>/TEST_BLOW_BY_1' */
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(Oil_bBlowBy1ReqActrTst, ActrTstBlowBy_B.Oil_bBlowBy1ReqActrTst_o);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(Oil_bActrTstInProgsBB1, ActrTstBlowBy_B.Oil_bActrTstInProgsBB1_n);
}

/* Output and update for function-call system: '<S1>/F02_BlowBy2Tst' */
void ActrTstBlowBy_F02_BlowBy2Tst(void)
{
  Boolean localLogicalOperator;

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET1 */
  VEMS_vidGET(Srv_bActrTstEna, ActrTstBlowBy_B.VEMS_vidGET1);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET */
  VEMS_vidGET(Code_test_action, ActrTstBlowBy_B.VEMS_vidGET);

  /* Logic: '<S5>/Logical Operator' incorporates:
   *  Constant: '<S5>/CODE_TEST_BLOW_BY_2'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  localLogicalOperator = (ActrTstBlowBy_B.VEMS_vidGET1 &&
    (ActrTstBlowBy_B.VEMS_vidGET == CODE_TEST_BLOW_BY_2));

  /* *
   * Block requirements for '<S5>/F01_BlowBy2TstChart':
   *  1. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_123.01 ;
   *  2. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_124.01 ;
   *  3. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_125.01 ;
   *  4. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04421_126.01 ;
   *  5. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_127.01 ;
   *  6. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_128.01 ;
   *  7. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_129.01 ;
   *  8. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_131.01 ;
   *  9. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_130.01 ;
   *  10. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_133.01 ;
   *  11. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_135.01 ;
   *  12. SubSystem "F01_BlowBy2TstChart" !Trace_To : VEMS_R_11_04422_136.01 ;
   */

  /* Stateflow: '<S5>/F01_BlowBy2TstChart' incorporates:
   *  Constant: '<S5>/ActrTstBlowBy2_OffTime_C'
   *  Constant: '<S5>/ActrTstBlowBy2_OnTime_C'
   *  Constant: '<S5>/ActrTstBlowBy2_Tempo_C'
   *  Constant: '<S5>/ActrTstBlowBy2_TotTime_C'
   *  Constant: '<S5>/OIL_ACTRTEST_BB2_END'
   *  Constant: '<S5>/OIL_ACTRTEST_BB2_IDLE'
   *  Constant: '<S5>/OIL_ACTRTEST_BB2_MAX'
   *  Constant: '<S5>/OIL_ACTRTEST_BB2_MIN'
   *  Constant: '<S5>/Oil_SampleTiMid_SC'
   */
  /* Gateway: ActrTstBlowBy/F02_BlowBy2Tst/F01_BlowBy2TstChart */
  /* During: ActrTstBlowBy/F02_BlowBy2Tst/F01_BlowBy2TstChart */
  if (ActrTstBlowBy_DWork.is_active_c1_ActrTstBlowBy == 0) {
    /* Entry: ActrTstBlowBy/F02_BlowBy2Tst/F01_BlowBy2TstChart */
    ActrTstBlowBy_DWork.is_active_c1_ActrTstBlowBy = 1U;

    /* Transition: '<S10>:10' */
    /* Entry 'OIL_ACTRTEST_BB2_IDLE': '<S10>:1' */
    ActrTstBlowBy_DWork.is_c1_ActrTstBlowBy = IN_OIL_ACTRTEST_BB2_IDLE;
    Oil_stActrTstBB2 = OIL_ACTRTEST_BB2_IDLE;
    ActrTstBlowBy_B.Oil_bBlowByTstCmpl_l = FALSE;
    ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l = FALSE;
    ActrTstBlowBy_B.Oil_bActrTstInProgsBB2_m = FALSE;
  } else {
    switch (ActrTstBlowBy_DWork.is_c1_ActrTstBlowBy) {
     case IN_OIL_ACTRTEST_BB2_END:
      /* During 'OIL_ACTRTEST_BB2_END': '<S10>:3' */
      if ((((SInt32)localLogicalOperator) == 1) && (ActrTstBlowBy2_Tempo <= 0))
      {
        /* Transition: '<S10>:9' */
        /* Exit 'OIL_ACTRTEST_BB2_END': '<S10>:3' */
        /* Entry 'OIL_ACTRTEST_BB2_IDLE': '<S10>:1' */
        ActrTstBlowBy_DWork.is_c1_ActrTstBlowBy = IN_OIL_ACTRTEST_BB2_IDLE;
        Oil_stActrTstBB2 = OIL_ACTRTEST_BB2_IDLE;
        ActrTstBlowBy_B.Oil_bBlowByTstCmpl_l = FALSE;
        ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l = FALSE;
        ActrTstBlowBy_B.Oil_bActrTstInProgsBB2_m = FALSE;
      } else {
        ActrTstBlowBy2_Tempo = (UInt16)(rt_MAX((ActrTstBlowBy2_Tempo << 3) -
          ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
      }
      break;

     case IN_OIL_ACTRTEST_BB2_IDLE:
      /* During 'OIL_ACTRTEST_BB2_IDLE': '<S10>:1' */
      if (((SInt32)localLogicalOperator) == 1) {
        /* Transition: '<S10>:6' */
        /* Exit 'OIL_ACTRTEST_BB2_IDLE': '<S10>:1' */
        /* Entry 'TestEnCoursBB2': '<S10>:2' */
        ActrTstBlowBy_DWork.is_c1_ActrTstBlowBy = IN_TestEnCoursBB2;
        ActrTstBlowBy2_CumulTime = (UInt16)((UInt32)(((SInt32)(((UInt32)
          (Oil_SampleTiMid_SC * 205)) >> 11)) + ActrTstBlowBy2_TotTime_C));
        ActrTstBlowBy_B.Oil_bActrTstInProgsBB2_m = TRUE;

        /* Entry 'OIL_ACTRTEST_BB2_MAX': '<S10>:4' */
        ActrTstBlowBy_DWork.is_TestEnCoursBB2 = IN_OIL_ACTRTEST_BB2_MAX;
        Oil_stActrTstBB2 = OIL_ACTRTEST_BB2_MAX;
        ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l = TRUE;
        ActrTstBlowBy2_IntTime = ActrTstBlowBy2_OnTime_C;
        ActrTstBlowBy2_CumulTime = (UInt16)(rt_MAX((ActrTstBlowBy2_CumulTime <<
          3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
      }
      break;

     case IN_TestEnCoursBB2:
      /* During 'TestEnCoursBB2': '<S10>:2' */
      if ((((SInt32)localLogicalOperator) == 1) && (((UInt32)
            (ActrTstBlowBy2_CumulTime << 11)) <= ((UInt32)(Oil_SampleTiMid_SC *
             205)))) {
        /* Transition: '<S10>:8' */
        /* Exit 'OIL_ACTRTEST_BB2_MAX': '<S10>:4' */
        ActrTstBlowBy_DWork.is_TestEnCoursBB2 = (UInt8)IN_NO_ACTIVE_CHILD_a;

        /* Exit 'OIL_ACTRTEST_BB2_MIN': '<S10>:5' */
        /* Exit 'TestEnCoursBB2': '<S10>:2' */
        /* Entry 'OIL_ACTRTEST_BB2_END': '<S10>:3' */
        ActrTstBlowBy_DWork.is_c1_ActrTstBlowBy = IN_OIL_ACTRTEST_BB2_END;
        Oil_stActrTstBB2 = OIL_ACTRTEST_BB2_END;
        ActrTstBlowBy_B.Oil_bBlowByTstCmpl_l = TRUE;
        ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l = FALSE;
        ActrTstBlowBy_B.Oil_bActrTstInProgsBB2_m = FALSE;
        ActrTstBlowBy2_Tempo = ActrTstBlowBy2_Tempo_C;
      } else if (((SInt32)localLogicalOperator) == 0) {
        /* Transition: '<S10>:7' */
        /* Exit 'OIL_ACTRTEST_BB2_MAX': '<S10>:4' */
        ActrTstBlowBy_DWork.is_TestEnCoursBB2 = (UInt8)IN_NO_ACTIVE_CHILD_a;

        /* Exit 'OIL_ACTRTEST_BB2_MIN': '<S10>:5' */
        /* Exit 'TestEnCoursBB2': '<S10>:2' */
        /* Entry 'OIL_ACTRTEST_BB2_IDLE': '<S10>:1' */
        ActrTstBlowBy_DWork.is_c1_ActrTstBlowBy = IN_OIL_ACTRTEST_BB2_IDLE;
        Oil_stActrTstBB2 = OIL_ACTRTEST_BB2_IDLE;
        ActrTstBlowBy_B.Oil_bBlowByTstCmpl_l = FALSE;
        ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l = FALSE;
        ActrTstBlowBy_B.Oil_bActrTstInProgsBB2_m = FALSE;
      } else {
        switch (ActrTstBlowBy_DWork.is_TestEnCoursBB2) {
         case IN_OIL_ACTRTEST_BB2_MAX:
          /* During 'OIL_ACTRTEST_BB2_MAX': '<S10>:4' */
          if (((UInt32)(ActrTstBlowBy2_IntTime << 11)) <= ((UInt32)
               (Oil_SampleTiMid_SC * 205))) {
            /* Transition: '<S10>:11' */
            /* Exit 'OIL_ACTRTEST_BB2_MAX': '<S10>:4' */
            /* Entry 'OIL_ACTRTEST_BB2_MIN': '<S10>:5' */
            ActrTstBlowBy_DWork.is_TestEnCoursBB2 = IN_OIL_ACTRTEST_BB2_MIN;
            Oil_stActrTstBB2 = OIL_ACTRTEST_BB2_MIN;
            ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l = FALSE;
            ActrTstBlowBy2_IntTime = ActrTstBlowBy2_OffTime_C;
            ActrTstBlowBy2_CumulTime = (UInt16)(rt_MAX
              ((ActrTstBlowBy2_CumulTime << 3) - ((SInt32)(((UInt32)
              (Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
          } else {
            ActrTstBlowBy2_CumulTime = (UInt16)(rt_MAX
              ((ActrTstBlowBy2_CumulTime << 3) - ((SInt32)(((UInt32)
              (Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
            ActrTstBlowBy2_IntTime = (UInt16)(rt_MAX((ActrTstBlowBy2_IntTime <<
              3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >>
              3);
          }
          break;

         case IN_OIL_ACTRTEST_BB2_MIN:
          /* During 'OIL_ACTRTEST_BB2_MIN': '<S10>:5' */
          if (((UInt32)(ActrTstBlowBy2_IntTime << 11)) <= ((UInt32)
               (Oil_SampleTiMid_SC * 205))) {
            /* Transition: '<S10>:12' */
            /* Exit 'OIL_ACTRTEST_BB2_MIN': '<S10>:5' */
            /* Entry 'OIL_ACTRTEST_BB2_MAX': '<S10>:4' */
            ActrTstBlowBy_DWork.is_TestEnCoursBB2 = IN_OIL_ACTRTEST_BB2_MAX;
            Oil_stActrTstBB2 = OIL_ACTRTEST_BB2_MAX;
            ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l = TRUE;
            ActrTstBlowBy2_IntTime = ActrTstBlowBy2_OnTime_C;
            ActrTstBlowBy2_CumulTime = (UInt16)(rt_MAX
              ((ActrTstBlowBy2_CumulTime << 3) - ((SInt32)(((UInt32)
              (Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
          } else {
            ActrTstBlowBy2_CumulTime = (UInt16)(rt_MAX
              ((ActrTstBlowBy2_CumulTime << 3) - ((SInt32)(((UInt32)
              (Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
            ActrTstBlowBy2_IntTime = (UInt16)(rt_MAX((ActrTstBlowBy2_IntTime <<
              3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >>
              3);
          }
          break;
        }
      }
      break;

     default:
      /* Transition: '<S10>:10' */
      /* Entry 'OIL_ACTRTEST_BB2_IDLE': '<S10>:1' */
      ActrTstBlowBy_DWork.is_c1_ActrTstBlowBy = IN_OIL_ACTRTEST_BB2_IDLE;
      Oil_stActrTstBB2 = OIL_ACTRTEST_BB2_IDLE;
      ActrTstBlowBy_B.Oil_bBlowByTstCmpl_l = FALSE;
      ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l = FALSE;
      ActrTstBlowBy_B.Oil_bActrTstInProgsBB2_m = FALSE;
      break;
    }
  }

  /* Outputs for enable SubSystem: '<S5>/TEST_BLOW_BY_2' incorporates:
   *  Constant: '<S5>/CODE_TEST_BLOW_BY_1'
   *  EnablePort: '<S11>/Enable'
   *  Logic: '<S5>/Logical Operator1'
   *  RelationalOperator: '<S5>/Relational Operator1'
   */
  if (!(ActrTstBlowBy_B.VEMS_vidGET == CODE_TEST_BLOW_BY_1)) {
    /* S-Function "vems_vidSET" Block: <S11>/VEMS_vidSET1 */
    VEMS_vidSET(Oil_bBlowByTstCmpl, ActrTstBlowBy_B.Oil_bBlowByTstCmpl_l);
  }

  /* end of Outputs for SubSystem: '<S5>/TEST_BLOW_BY_2' */
  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET1 */
  VEMS_vidSET(Oil_bBlowBy2ReqActrTst, ActrTstBlowBy_B.Oil_bBlowBy2ReqActrTst_l);

  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET2 */
  VEMS_vidSET(Oil_bActrTstInProgsBB2, ActrTstBlowBy_B.Oil_bActrTstInProgsBB2_m);
}

/* Initial conditions for exported function: Oil_EveRst_ActrTstBlowBy */
void Oil_EveRst_ActrTstBlowBy_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/demux_fc'
   */

  /* InitializeConditions for S-Function (fcncallgen): '<S6>/gen' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/F01_BlowBy1Tst'
   *  InitializeConditions for SubSystem: '<S1>/F02_BlowBy2Tst'
   */
}

/* Start for exported function: Oil_EveRst_ActrTstBlowBy */
void Oil_EveRst_ActrTstBlowBy_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc'
   */

  /* Start for S-Function (fcncallgen): '<S6>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F01_BlowBy1Tst'
   *  Start for SubSystem: '<S1>/F02_BlowBy2Tst'
   */
}

/* Output and update for exported function: Oil_EveRst_ActrTstBlowBy */
void Oil_EveRst_ActrTstBlowBy(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc'
   */

  /* S-Function (fcncallgen): '<S6>/gen' */
  ActrTstBlowBy_ASYNC1(0);
  
}

/* Output and update for exported function: Oil_SdlMid_ActrTstBlowBy */
void Oil_SdlMid_ActrTstBlowBy(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S7>/gen' */
  ActrTstBlowBy_ASYNC1(1);
  
}

/* Model initialize function */
void ActrTstBlowBy_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  Oil_EveRst_ActrTstBlowBy_Start();

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   */
  Oil_EveRst_ActrTstBlowBy_Init();
}

#define ACTRTSTBLOWBY_STOP_SEC_CODE
#include "ActrTstBlowBy_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
