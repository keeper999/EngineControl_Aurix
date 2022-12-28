/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstCtlPmp                                            */
/* !Description     : Test actionneur Electrovanne Pompe à Huile              */
/*                                                                            */
/* !Module          : ActTstCtlPmp                                            */
/*                                                                            */
/* !File            : ActTstCtlPmp.c                                          */
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
/* !Reference       : V02NT1105535 / 01                                       */
/* !OtherRefs       : VEMS V02 ECU#057658                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Jan 17 11:14:52 2012                              */
/*   Model name       : ActTstCtlPmp_AUTOCODE.mdl                             */
/*   Model version    : 1.31                                                  */
/*   Root subsystem   : /ActTstCtlPmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/ACTTSTCTLPMP/ActTstCtlPmp.c_$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActTstCtlPmp.h"
#include "ActTstCtlPmp_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S4>/F01_CtlPmpTstChart' */
#define IN_NO_ACTIVE_CHILD             (0U)
#define IN_OIL_ACTRTEST_END            (1U)
#define IN_OIL_ACTRTEST_IDLE           (2U)
#define IN_OIL_ACTRTEST_MAX            (1U)
#define IN_OIL_ACTRTEST_MIN            (2U)
#define IN_TestEnCours                 (3U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTTSTCTLPMP_START_SEC_VAR_UNSPECIFIED
#include "ActTstCtlPmp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_ActTstCtlPmp ActTstCtlPmp_B;

/* Block states (auto storage) */
D_Work_ActTstCtlPmp ActTstCtlPmp_DWork;

#define ACTTSTCTLPMP_STOP_SEC_VAR_UNSPECIFIED
#include "ActTstCtlPmp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define ACTTSTCTLPMP_START_SEC_CODE
#include "ActTstCtlPmp_MemMap.h"

void ActTstCtlPmp_ASYNC1(int controlPortIdx)
{
  ActTstCtlPmp_F01_CtlPmpTst();
}

/* Output and update for function-call system: '<S1>/F01_CtlPmpTst' */
void ActTstCtlPmp_F01_CtlPmpTst(void)
{
  Boolean localLogicalOperator;

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET1 */
  VEMS_vidGET(Srv_bActrTstEna, ActTstCtlPmp_B.VEMS_vidGET1);

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET */
  VEMS_vidGET(Code_test_action, ActTstCtlPmp_B.VEMS_vidGET);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S4>/CODE_TEST_OILPMP'
   *  RelationalOperator: '<S4>/Relational Operator'
   */
  localLogicalOperator = (ActTstCtlPmp_B.VEMS_vidGET1 &&
    (ActTstCtlPmp_B.VEMS_vidGET == CODE_TEST_OILPMP));

  /* *
   * Block requirements for '<S4>/F01_CtlPmpTstChart':
   *  1. SubSystem "F01_CtlPmpTstChart" !Trace_To : VEMS_E_11_05535_001.01 ;
   */

  /* Stateflow: '<S4>/F01_CtlPmpTstChart' incorporates:
   *  Constant: '<S4>/ActrTstCtlPmp_OffTime_C'
   *  Constant: '<S4>/ActrTstCtlPmp_OnTime_C'
   *  Constant: '<S4>/ActrTstCtlPmp_Tempo_C'
   *  Constant: '<S4>/ActrTstCtlPmp_TotTime_C'
   *  Constant: '<S4>/OIL_ACTRTEST_END'
   *  Constant: '<S4>/OIL_ACTRTEST_IDLE'
   *  Constant: '<S4>/OIL_ACTRTEST_MAX'
   *  Constant: '<S4>/OIL_ACTRTEST_MIN'
   *  Constant: '<S4>/Oil_SampleTiMid_SC'
   *  Constant: '<S4>/Oil_rSpPosnActrTstPos1_C'
   *  Constant: '<S4>/Oil_rSpPosnActrTstPos2_C'
   */
  /* Gateway: ActTstCtlPmp/F01_CtlPmpTst/F01_CtlPmpTstChart */
  /* During: ActTstCtlPmp/F01_CtlPmpTst/F01_CtlPmpTstChart */
  if (ActTstCtlPmp_DWork.is_active_c2_ActTstCtlPmp == 0) {
    /* Entry: ActTstCtlPmp/F01_CtlPmpTst/F01_CtlPmpTstChart */
    ActTstCtlPmp_DWork.is_active_c2_ActTstCtlPmp = 1U;

    /* Transition: '<S5>:10' */
    /* Entry 'OIL_ACTRTEST_IDLE': '<S5>:1' */
    ActTstCtlPmp_DWork.is_c2_ActTstCtlPmp = IN_OIL_ACTRTEST_IDLE;
    Oil_stActrTst = OIL_ACTRTEST_IDLE;
    ActTstCtlPmp_B.Oil_bCtlPmpTstCmpl_l = FALSE;
    ActTstCtlPmp_B.Oil_rSpPosnActrTst_a = 0U;
    ActTstCtlPmp_B.Oil_bActrTstInProgs_l = FALSE;
  } else {
    switch (ActTstCtlPmp_DWork.is_c2_ActTstCtlPmp) {
     case IN_OIL_ACTRTEST_END:
      /* During 'OIL_ACTRTEST_END': '<S5>:3' */
      if ((((SInt32)localLogicalOperator) == 1) && (ActrTstCtlPmp_Tempo <= 0))
      {
        /* Transition: '<S5>:9' */
        /* Exit 'OIL_ACTRTEST_END': '<S5>:3' */
        /* Entry 'OIL_ACTRTEST_IDLE': '<S5>:1' */
        ActTstCtlPmp_DWork.is_c2_ActTstCtlPmp = IN_OIL_ACTRTEST_IDLE;
        Oil_stActrTst = OIL_ACTRTEST_IDLE;
        ActTstCtlPmp_B.Oil_bCtlPmpTstCmpl_l = FALSE;
        ActTstCtlPmp_B.Oil_rSpPosnActrTst_a = 0U;
        ActTstCtlPmp_B.Oil_bActrTstInProgs_l = FALSE;
      } else {
        ActrTstCtlPmp_Tempo = (UInt16)(rt_MAX((ActrTstCtlPmp_Tempo << 3) -
          ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
      }
      break;

     case IN_OIL_ACTRTEST_IDLE:
      /* During 'OIL_ACTRTEST_IDLE': '<S5>:1' */
      if (((SInt32)localLogicalOperator) == 1) {
        /* Transition: '<S5>:6' */
        /* Exit 'OIL_ACTRTEST_IDLE': '<S5>:1' */
        /* Entry 'TestEnCours': '<S5>:2' */
        ActTstCtlPmp_DWork.is_c2_ActTstCtlPmp = IN_TestEnCours;
        ActrTstCtlPmp_CumulTime = (UInt16)((((SInt32)(((UInt32)
          (Oil_SampleTiMid_SC * 205)) >> 8)) + (ActrTstCtlPmp_TotTime_C << 3)) >>
          3);
        ActTstCtlPmp_B.Oil_bActrTstInProgs_l = TRUE;

        /* Entry 'OIL_ACTRTEST_MAX': '<S5>:4' */
        ActTstCtlPmp_DWork.is_TestEnCours = IN_OIL_ACTRTEST_MAX;
        Oil_stActrTst = OIL_ACTRTEST_MAX;
        ActTstCtlPmp_B.Oil_rSpPosnActrTst_a = Oil_rSpPosnActrTstPos1_C;
        ActrTstCtlPmp_IntTime = ActrTstCtlPmp_OnTime_C;
        ActrTstCtlPmp_CumulTime = (UInt16)(rt_MAX((ActrTstCtlPmp_CumulTime <<
          3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >> 3);
      }
      break;

     case IN_TestEnCours:
      /* During 'TestEnCours': '<S5>:2' */
      if ((((SInt32)localLogicalOperator) == 1) && (((UInt32)
            (ActrTstCtlPmp_CumulTime << 11)) <= ((UInt32)(Oil_SampleTiMid_SC *
             205)))) {
        /* Transition: '<S5>:8' */
        /* Exit 'OIL_ACTRTEST_MAX': '<S5>:4' */
        ActTstCtlPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;

        /* Exit 'OIL_ACTRTEST_MIN': '<S5>:5' */
        /* Exit 'TestEnCours': '<S5>:2' */
        /* Entry 'OIL_ACTRTEST_END': '<S5>:3' */
        ActTstCtlPmp_DWork.is_c2_ActTstCtlPmp = IN_OIL_ACTRTEST_END;
        Oil_stActrTst = OIL_ACTRTEST_END;
        ActTstCtlPmp_B.Oil_bCtlPmpTstCmpl_l = TRUE;
        ActTstCtlPmp_B.Oil_rSpPosnActrTst_a = 0U;
        ActTstCtlPmp_B.Oil_bActrTstInProgs_l = FALSE;
        ActrTstCtlPmp_Tempo = ActrTstCtlPmp_Tempo_C;
      } else if (((SInt32)localLogicalOperator) == 0) {
        /* Transition: '<S5>:7' */
        /* Exit 'OIL_ACTRTEST_MAX': '<S5>:4' */
        ActTstCtlPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;

        /* Exit 'OIL_ACTRTEST_MIN': '<S5>:5' */
        /* Exit 'TestEnCours': '<S5>:2' */
        /* Entry 'OIL_ACTRTEST_IDLE': '<S5>:1' */
        ActTstCtlPmp_DWork.is_c2_ActTstCtlPmp = IN_OIL_ACTRTEST_IDLE;
        Oil_stActrTst = OIL_ACTRTEST_IDLE;
        ActTstCtlPmp_B.Oil_bCtlPmpTstCmpl_l = FALSE;
        ActTstCtlPmp_B.Oil_rSpPosnActrTst_a = 0U;
        ActTstCtlPmp_B.Oil_bActrTstInProgs_l = FALSE;
      } else {
        switch (ActTstCtlPmp_DWork.is_TestEnCours) {
         case IN_OIL_ACTRTEST_MAX:
          /* During 'OIL_ACTRTEST_MAX': '<S5>:4' */
          if (((UInt32)(ActrTstCtlPmp_IntTime << 11)) <= ((UInt32)
               (Oil_SampleTiMid_SC * 205))) {
            /* Transition: '<S5>:11' */
            /* Exit 'OIL_ACTRTEST_MAX': '<S5>:4' */
            /* Entry 'OIL_ACTRTEST_MIN': '<S5>:5' */
            ActTstCtlPmp_DWork.is_TestEnCours = IN_OIL_ACTRTEST_MIN;
            Oil_stActrTst = OIL_ACTRTEST_MIN;
            ActTstCtlPmp_B.Oil_rSpPosnActrTst_a = Oil_rSpPosnActrTstPos2_C;
            ActrTstCtlPmp_IntTime = ActrTstCtlPmp_OffTime_C;
            ActrTstCtlPmp_CumulTime = (UInt16)(rt_MAX((ActrTstCtlPmp_CumulTime
              << 3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)),
              0) >> 3);
          } else {
            ActrTstCtlPmp_CumulTime = (UInt16)(rt_MAX((ActrTstCtlPmp_CumulTime
              << 3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)),
              0) >> 3);
            ActrTstCtlPmp_IntTime = (UInt16)(rt_MAX((ActrTstCtlPmp_IntTime <<
              3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >>
              3);
          }
          break;

         case IN_OIL_ACTRTEST_MIN:
          /* During 'OIL_ACTRTEST_MIN': '<S5>:5' */
          if (((UInt32)(ActrTstCtlPmp_IntTime << 11)) <= ((UInt32)
               (Oil_SampleTiMid_SC * 205))) {
            /* Transition: '<S5>:12' */
            /* Exit 'OIL_ACTRTEST_MIN': '<S5>:5' */
            /* Entry 'OIL_ACTRTEST_MAX': '<S5>:4' */
            ActTstCtlPmp_DWork.is_TestEnCours = IN_OIL_ACTRTEST_MAX;
            Oil_stActrTst = OIL_ACTRTEST_MAX;
            ActTstCtlPmp_B.Oil_rSpPosnActrTst_a = Oil_rSpPosnActrTstPos1_C;
            ActrTstCtlPmp_IntTime = ActrTstCtlPmp_OnTime_C;
            ActrTstCtlPmp_CumulTime = (UInt16)(rt_MAX((ActrTstCtlPmp_CumulTime
              << 3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)),
              0) >> 3);
          } else {
            ActrTstCtlPmp_CumulTime = (UInt16)(rt_MAX((ActrTstCtlPmp_CumulTime
              << 3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)),
              0) >> 3);
            ActrTstCtlPmp_IntTime = (UInt16)(rt_MAX((ActrTstCtlPmp_IntTime <<
              3) - ((SInt32)(((UInt32)(Oil_SampleTiMid_SC * 205)) >> 8)), 0) >>
              3);
          }
          break;
        }
      }
      break;

     default:
      /* Transition: '<S5>:10' */
      /* Entry 'OIL_ACTRTEST_IDLE': '<S5>:1' */
      ActTstCtlPmp_DWork.is_c2_ActTstCtlPmp = IN_OIL_ACTRTEST_IDLE;
      Oil_stActrTst = OIL_ACTRTEST_IDLE;
      ActTstCtlPmp_B.Oil_bCtlPmpTstCmpl_l = FALSE;
      ActTstCtlPmp_B.Oil_rSpPosnActrTst_a = 0U;
      ActTstCtlPmp_B.Oil_bActrTstInProgs_l = FALSE;
      break;
    }
  }

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(Oil_bActrTstInProgs, ActTstCtlPmp_B.Oil_bActrTstInProgs_l);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(Oil_bCtlPmpTstCmpl, ActTstCtlPmp_B.Oil_bCtlPmpTstCmpl_l);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(Oil_rSpPosnActrTst, ActTstCtlPmp_B.Oil_rSpPosnActrTst_a);
}

/* Output and update for exported function: Oil_EveRst_ActrTstCtlPmp */
void Oil_EveRst_ActrTstCtlPmp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' */
  ActTstCtlPmp_ASYNC1(0);
}

/* Output and update for exported function: Oil_SdlMid_ActrTstCtlPmp */
void Oil_SdlMid_ActrTstCtlPmp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' */
  ActTstCtlPmp_ASYNC1(1);
}

/* Model initialize function */
void ActTstCtlPmp_initialize(void)
{
  /* (no initialization code required) */
}

#define ACTTSTCTLPMP_STOP_SEC_CODE
#include "ActTstCtlPmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
