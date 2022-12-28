/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstTrbWaPmp                                          */
/* !Description     : Test actionneur Pompe à Eau Turbo                       */
/*                                                                            */
/* !Module          : ActTstTrbWaPmp                                          */
/*                                                                            */
/* !File            : ActTstTrbWaPmp.c                                        */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : V02NT1105649 / 01                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Jan 17 08:17:12 2012                              */
/*   Model name       : ActTstTrbWaPmp_AUTOCODE.mdl                           */
/*   Model version    : 1.34                                                  */
/*   Root subsystem   : /ActTstTrbWaPmp                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ACTTSTTRBWAPMP/ActTstTrbWaPmp.c_$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActTstTrbWaPmp.h"
#include "ActTstTrbWaPmp_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S4>/F01_TrbWaPmpTstChart' */
#define IN_NO_ACTIVE_CHILD             (0U)
#define IN_THMGT_ACTRTEST_END          (1U)
#define IN_THMGT_ACTRTEST_IDLE         (2U)
#define IN_THMGT_ACTRTEST_MAX          (1U)
#define IN_THMGT_ACTRTEST_MIN          (2U)
#define IN_TestEnCours                 (3U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTTSTTRBWAPMP_START_SEC_VAR_UNSPECIFIED
#include "ActTstTrbWaPmp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_ActTstTrbWaPmp ActTstTrbWaPmp_B;

/* Block states (auto storage) */
D_Work_ActTstTrbWaPmp ActTstTrbWaPmp_DWork;

#define ACTTSTTRBWAPMP_STOP_SEC_VAR_UNSPECIFIED
#include "ActTstTrbWaPmp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define ACTTSTTRBWAPMP_START_SEC_CODE
#include "ActTstTrbWaPmp_MemMap.h"

void ActTstTrbWaPmp_ASYNC1(int controlPortIdx)
{
  ActTstTrbWaPmp_F01_TrbWaPmpTst();
}

/* Output and update for function-call system: '<S1>/F01_TrbWaPmpTst' */
void ActTstTrbWaPmp_F01_TrbWaPmpTst(void)
{
  Boolean localLogicalOperator;

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET4 */
  VEMS_vidGET(Srv_bActrTstEna, ActTstTrbWaPmp_B.VEMS_vidGET4);

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET5 */
  VEMS_vidGET(Code_test_action, ActTstTrbWaPmp_B.VEMS_vidGET5);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S4>/CODE_TEST_WTRPMP'
   *  RelationalOperator: '<S4>/Relational Operator'
   */
  localLogicalOperator = (ActTstTrbWaPmp_B.VEMS_vidGET4 &&
    (ActTstTrbWaPmp_B.VEMS_vidGET5 == CODE_TEST_WTRPMP));

  /* *
   * Block requirements for '<S4>/F01_TrbWaPmpTstChart':
   *  1. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422_228.01 ;
   *  2. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422_229.01 ;
   *  3. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422_230.01 ;
   *  4. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04421_231.01 ;
   *  5. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422_232.01 ;
   *  6. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422_233.01 ;
   *  7. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422.234.01 ;
   *  8. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422.237.01 ;
   *  9. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422_239.01 ;
   *  10. SubSystem "F01_TrbWaPmpTstChart" !Trace_To : VEMS_R_11_04422_240.01 ;
   */

  /* Stateflow: '<S4>/F01_TrbWaPmpTstChart' incorporates:
   *  Constant: '<S4>/ActrTstTrbWaPmp_OffTime_C'
   *  Constant: '<S4>/ActrTstTrbWaPmp_OnTime_C'
   *  Constant: '<S4>/ActrTstTrbWaPmp_Tempo_C'
   *  Constant: '<S4>/ActrTstTrbWaPmp_TotTime_C'
   *  Constant: '<S4>/THMGT_ACTRTEST_END'
   *  Constant: '<S4>/THMGT_ACTRTEST_IDLE'
   *  Constant: '<S4>/THMGT_ACTRTEST_MAX'
   *  Constant: '<S4>/THMGT_ACTRTEST_MIN'
   *  Constant: '<S4>/ThMgt_SampleTiMid_SC'
   */
  /* Gateway: ActTstTrbWaPmp/F01_TrbWaPmpTst/F01_TrbWaPmpTstChart */
  /* During: ActTstTrbWaPmp/F01_TrbWaPmpTst/F01_TrbWaPmpTstChart */
  if (ActTstTrbWaPmp_DWork.is_active_c3_ActTstTrbWaPmp == 0) {
    /* Entry: ActTstTrbWaPmp/F01_TrbWaPmpTst/F01_TrbWaPmpTstChart */
    ActTstTrbWaPmp_DWork.is_active_c3_ActTstTrbWaPmp = 1U;

    /* Transition: '<S5>:10' */
    /* Entry 'THMGT_ACTRTEST_IDLE': '<S5>:1' */
    ActTstTrbWaPmp_DWork.is_c3_ActTstTrbWaPmp = IN_THMGT_ACTRTEST_IDLE;
    ThMgt_stActrTst = THMGT_ACTRTEST_IDLE;
    ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpTstCmpl_k = FALSE;
    ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p = FALSE;
    ActTstTrbWaPmp_B.ThMgt_bActrTstInProgs_m = FALSE;
  } else {
    switch (ActTstTrbWaPmp_DWork.is_c3_ActTstTrbWaPmp) {
     case IN_THMGT_ACTRTEST_END:
      /* During 'THMGT_ACTRTEST_END': '<S5>:3' */
      if ((((SInt32)localLogicalOperator) == 1) && (ActrTstTrbWaPmp_Tempo <= 0))
      {
        /* Transition: '<S5>:9' */
        /* Exit 'THMGT_ACTRTEST_END': '<S5>:3' */
        /* Entry 'THMGT_ACTRTEST_IDLE': '<S5>:1' */
        ActTstTrbWaPmp_DWork.is_c3_ActTstTrbWaPmp = IN_THMGT_ACTRTEST_IDLE;
        ThMgt_stActrTst = THMGT_ACTRTEST_IDLE;
        ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpTstCmpl_k = FALSE;
        ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p = FALSE;
        ActTstTrbWaPmp_B.ThMgt_bActrTstInProgs_m = FALSE;
      } else {
        ActrTstTrbWaPmp_Tempo = (UInt16)(rt_MAX((ActrTstTrbWaPmp_Tempo << 6) -
          ((SInt32)(((UInt32)(ThMgt_SampleTiMid_SC * 41)) >> 6)), 0) >> 6);
      }
      break;

     case IN_THMGT_ACTRTEST_IDLE:
      /* During 'THMGT_ACTRTEST_IDLE': '<S5>:1' */
      if (((SInt32)localLogicalOperator) == 1) {
        /* Transition: '<S5>:6' */
        /* Exit 'THMGT_ACTRTEST_IDLE': '<S5>:1' */
        /* Entry 'TestEnCours': '<S5>:2' */
        ActTstTrbWaPmp_DWork.is_c3_ActTstTrbWaPmp = IN_TestEnCours;
        ActrTstTrbWaPmp_CumulTime = (UInt16)((UInt32)(((SInt32)(((UInt32)
          (ThMgt_SampleTiMid_SC * 41)) >> 12)) + ActrTstTrbWaPmp_TotTime_C));
        ActTstTrbWaPmp_B.ThMgt_bActrTstInProgs_m = TRUE;

        /* Entry 'THMGT_ACTRTEST_MAX': '<S5>:4' */
        ActTstTrbWaPmp_DWork.is_TestEnCours = IN_THMGT_ACTRTEST_MAX;
        ThMgt_stActrTst = THMGT_ACTRTEST_MAX;
        ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p = TRUE;
        ActrTstTrbWaPmp_IntTime = ActrTstTrbWaPmp_OnTime_C;
        ActrTstTrbWaPmp_CumulTime = (UInt16)(rt_MAX((ActrTstTrbWaPmp_CumulTime
          << 6) - ((SInt32)(((UInt32)(ThMgt_SampleTiMid_SC * 41)) >> 6)), 0) >>
          6);
      }
      break;

     case IN_TestEnCours:
      /* During 'TestEnCours': '<S5>:2' */
      if ((((SInt32)localLogicalOperator) == 1) && (((UInt32)
            (ActrTstTrbWaPmp_CumulTime << 12)) <= ((UInt32)
            (ThMgt_SampleTiMid_SC * 41)))) {
        /* Transition: '<S5>:8' */
        /* Exit 'THMGT_ACTRTEST_MAX': '<S5>:4' */
        ActTstTrbWaPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;

        /* Exit 'THMGT_ACTRTEST_MIN': '<S5>:5' */
        /* Exit 'TestEnCours': '<S5>:2' */
        /* Entry 'THMGT_ACTRTEST_END': '<S5>:3' */
        ActTstTrbWaPmp_DWork.is_c3_ActTstTrbWaPmp = IN_THMGT_ACTRTEST_END;
        ThMgt_stActrTst = THMGT_ACTRTEST_END;
        ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpTstCmpl_k = TRUE;
        ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p = FALSE;
        ActTstTrbWaPmp_B.ThMgt_bActrTstInProgs_m = FALSE;
        ActrTstTrbWaPmp_Tempo = ActrTstTrbWaPmp_Tempo_C;
      } else if (((SInt32)localLogicalOperator) == 0) {
        /* Transition: '<S5>:7' */
        /* Exit 'THMGT_ACTRTEST_MAX': '<S5>:4' */
        ActTstTrbWaPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;

        /* Exit 'THMGT_ACTRTEST_MIN': '<S5>:5' */
        /* Exit 'TestEnCours': '<S5>:2' */
        /* Entry 'THMGT_ACTRTEST_IDLE': '<S5>:1' */
        ActTstTrbWaPmp_DWork.is_c3_ActTstTrbWaPmp = IN_THMGT_ACTRTEST_IDLE;
        ThMgt_stActrTst = THMGT_ACTRTEST_IDLE;
        ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpTstCmpl_k = FALSE;
        ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p = FALSE;
        ActTstTrbWaPmp_B.ThMgt_bActrTstInProgs_m = FALSE;
      } else {
        switch (ActTstTrbWaPmp_DWork.is_TestEnCours) {
         case IN_THMGT_ACTRTEST_MAX:
          /* During 'THMGT_ACTRTEST_MAX': '<S5>:4' */
          if (((UInt32)(ActrTstTrbWaPmp_IntTime << 12)) <= ((UInt32)
               (ThMgt_SampleTiMid_SC * 41))) {
            /* Transition: '<S5>:11' */
            /* Exit 'THMGT_ACTRTEST_MAX': '<S5>:4' */
            /* Entry 'THMGT_ACTRTEST_MIN': '<S5>:5' */
            ActTstTrbWaPmp_DWork.is_TestEnCours = IN_THMGT_ACTRTEST_MIN;
            ThMgt_stActrTst = THMGT_ACTRTEST_MIN;
            ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p = FALSE;
            ActrTstTrbWaPmp_IntTime = ActrTstTrbWaPmp_OffTime_C;
            ActrTstTrbWaPmp_CumulTime = (UInt16)(rt_MAX
              ((ActrTstTrbWaPmp_CumulTime << 6) - ((SInt32)(((UInt32)
              (ThMgt_SampleTiMid_SC * 41)) >> 6)), 0) >> 6);
          } else {
            ActrTstTrbWaPmp_CumulTime = (UInt16)(rt_MAX
              ((ActrTstTrbWaPmp_CumulTime << 6) - ((SInt32)(((UInt32)
              (ThMgt_SampleTiMid_SC * 41)) >> 6)), 0) >> 6);
            ActrTstTrbWaPmp_IntTime = (UInt8)(rt_MAX((ActrTstTrbWaPmp_IntTime <<
              6) - ((SInt32)(((UInt32)(ThMgt_SampleTiMid_SC * 41)) >> 6)), 0)
              >> 6);
          }
          break;

         case IN_THMGT_ACTRTEST_MIN:
          /* During 'THMGT_ACTRTEST_MIN': '<S5>:5' */
          if (((UInt32)(ActrTstTrbWaPmp_IntTime << 12)) <= ((UInt32)
               (ThMgt_SampleTiMid_SC * 41))) {
            /* Transition: '<S5>:12' */
            /* Exit 'THMGT_ACTRTEST_MIN': '<S5>:5' */
            /* Entry 'THMGT_ACTRTEST_MAX': '<S5>:4' */
            ActTstTrbWaPmp_DWork.is_TestEnCours = IN_THMGT_ACTRTEST_MAX;
            ThMgt_stActrTst = THMGT_ACTRTEST_MAX;
            ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p = TRUE;
            ActrTstTrbWaPmp_IntTime = ActrTstTrbWaPmp_OnTime_C;
            ActrTstTrbWaPmp_CumulTime = (UInt16)(rt_MAX
              ((ActrTstTrbWaPmp_CumulTime << 6) - ((SInt32)(((UInt32)
              (ThMgt_SampleTiMid_SC * 41)) >> 6)), 0) >> 6);
          } else {
            ActrTstTrbWaPmp_CumulTime = (UInt16)(rt_MAX
              ((ActrTstTrbWaPmp_CumulTime << 6) - ((SInt32)(((UInt32)
              (ThMgt_SampleTiMid_SC * 41)) >> 6)), 0) >> 6);
            ActrTstTrbWaPmp_IntTime = (UInt8)(rt_MAX((ActrTstTrbWaPmp_IntTime <<
              6) - ((SInt32)(((UInt32)(ThMgt_SampleTiMid_SC * 41)) >> 6)), 0)
              >> 6);
          }
          break;
        }
      }
      break;

     default:
      /* Transition: '<S5>:10' */
      /* Entry 'THMGT_ACTRTEST_IDLE': '<S5>:1' */
      ActTstTrbWaPmp_DWork.is_c3_ActTstTrbWaPmp = IN_THMGT_ACTRTEST_IDLE;
      ThMgt_stActrTst = THMGT_ACTRTEST_IDLE;
      ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpTstCmpl_k = FALSE;
      ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p = FALSE;
      ActTstTrbWaPmp_B.ThMgt_bActrTstInProgs_m = FALSE;
      break;
    }
  }

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(ThMgt_bTrbWaPmpReqActrTst,
              ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpReqActrTst_p);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(ThMgt_bActrTstInProgs, ActTstTrbWaPmp_B.ThMgt_bActrTstInProgs_m);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(ThMgt_bTrbWaPmpTstCmpl, ActTstTrbWaPmp_B.ThMgt_bTrbWaPmpTstCmpl_k);
}

/* Output and update for exported function: ThMgt_EveRst_ActrTstTrbWaPmp */
void ThMgt_EveRst_ActrTstTrbWaPmp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' */
  ActTstTrbWaPmp_ASYNC1(0);
}

/* Output and update for exported function: ThMgt_SdlMid_ActrTstTrbWaPmp */
void ThMgt_SdlMid_ActrTstTrbWaPmp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' */
  ActTstTrbWaPmp_ASYNC1(1);
}

/* Model initialize function */
void ActTstTrbWaPmp_initialize(void)
{
  /* (no initialization code required) */
}

#define ACTTSTTRBWAPMP_STOP_SEC_CODE
#include "ActTstTrbWaPmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
