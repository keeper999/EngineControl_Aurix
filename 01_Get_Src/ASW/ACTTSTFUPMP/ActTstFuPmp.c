/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActTstFuPmp                                             */
/* !Description     : Test actionneur Pompe de Gavage                         */
/*                                                                            */
/* !Module          : ActTstFuPmp                                             */
/*                                                                            */
/* !File            : ActTstFuPmp.c                                           */
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
/* !Reference       : V02NT1105537 / 01                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Jan 17 08:03:35 2012                              */
/*   Model name       : ActTstFuPmp_AUTOCODE.mdl                              */
/*   Model version    : 1.68                                                  */
/*   Root subsystem   : /ActTstFuPmp                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUPMP/ACTTSTFUPMP/ActTstFuPmp.c_$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActTstFuPmp.h"
#include "ActTstFuPmp_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S4>/F01_FuTnkPmpChart' */
#define IN_FUPMP_ACTRTEST_END          (1U)
#define IN_FUPMP_ACTRTEST_IDLE         (2U)
#define IN_FUPMP_ACTRTEST_MAX          (1U)
#define IN_FUPMP_ACTRTEST_MIN          (2U)
#define IN_NO_ACTIVE_CHILD             (0U)
#define IN_TestEnCours                 (3U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTTSTFUPMP_START_SEC_VAR_UNSPECIFIED
#include "ActTstFuPmp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_ActTstFuPmp ActTstFuPmp_B;

/* Block states (auto storage) */
D_Work_ActTstFuPmp ActTstFuPmp_DWork;

#define ACTTSTFUPMP_STOP_SEC_VAR_UNSPECIFIED
#include "ActTstFuPmp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define ACTTSTFUPMP_START_SEC_CODE
#include "ActTstFuPmp_MemMap.h"

void ActTstFuPmp_ASYNC1(int controlPortIdx)
{
  ActTstFuPmp_F01_FuTnkPmpTst();
}

/* Output and update for function-call system: '<S1>/F01_FuTnkPmpTst' */
void ActTstFuPmp_F01_FuTnkPmpTst(void)
{
  Boolean localLogicalOperator;

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET1 */
  VEMS_vidGET(Srv_bActrTstEna, ActTstFuPmp_B.VEMS_vidGET1);

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET */
  VEMS_vidGET(Code_test_action, ActTstFuPmp_B.VEMS_vidGET);

  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S4>/CODE_TEST_FUPMP'
   *  RelationalOperator: '<S4>/Relational Operator'
   */
  localLogicalOperator = (ActTstFuPmp_B.VEMS_vidGET1 &&
    (ActTstFuPmp_B.VEMS_vidGET == CODE_TEST_FUPMP));

  /* *
   * Block requirements for '<S4>/F01_FuTnkPmpChart':
   *  1. SubSystem "F01_FuTnkPmpChart" !Trace_To : VEMS_E_11_05537_001.01 ;
   *  2. SubSystem "F01_FuTnkPmpChart" !Trace_To : VEMS_E_11_05537_002.01 ;
   *  3. SubSystem "F01_FuTnkPmpChart" !Trace_To : VEMS_E_11_05537_003.01 ;
   */

  /* Stateflow: '<S4>/F01_FuTnkPmpChart' incorporates:
   *  Constant: '<S4>/ActrTstFuTnkPmp_OffTime_C'
   *  Constant: '<S4>/ActrTstFuTnkPmp_OnTime_C'
   *  Constant: '<S4>/ActrTstFuTnkPmp_Tempo_C'
   *  Constant: '<S4>/ActrTstFuTnkPmp_TotTime_C'
   *  Constant: '<S4>/FUPMP_ACTRTEST_END'
   *  Constant: '<S4>/FUPMP_ACTRTEST_IDLE'
   *  Constant: '<S4>/FUPMP_ACTRTEST_MAX'
   *  Constant: '<S4>/FUPMP_ACTRTEST_MIN'
   *  Constant: '<S4>/FuPmp_SampleTiMid_SC'
   *  Constant: '<S4>/FuPmp_rSpPosnActrTstPos1_C'
   *  Constant: '<S4>/FuPmp_rSpPosnActrTstPos2_C'
   */
  /* Gateway: ActTstFuPmp/F01_FuTnkPmpTst/F01_FuTnkPmpChart */
  /* During: ActTstFuPmp/F01_FuTnkPmpTst/F01_FuTnkPmpChart */
  if (ActTstFuPmp_DWork.is_active_c2_ActTstFuPmp == 0) {
    /* Entry: ActTstFuPmp/F01_FuTnkPmpTst/F01_FuTnkPmpChart */
    ActTstFuPmp_DWork.is_active_c2_ActTstFuPmp = 1U;

    /* Transition: '<S5>:12' */
    /* Entry 'FUPMP_ACTRTEST_IDLE': '<S5>:4' */
    ActTstFuPmp_DWork.is_c2_ActTstFuPmp = IN_FUPMP_ACTRTEST_IDLE;
    FuPmp_stActrTst = FUPMP_ACTRTEST_IDLE;
    ActTstFuPmp_B.FuPmp_bFuTnkPmpTstCmpl_g = FALSE;
    ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m = 0U;
    ActTstFuPmp_B.FuPmp_bActrTstInProgs_a = FALSE;
  } else {
    switch (ActTstFuPmp_DWork.is_c2_ActTstFuPmp) {
     case IN_FUPMP_ACTRTEST_END:
      /* During 'FUPMP_ACTRTEST_END': '<S5>:2' */
      if ((((SInt32)localLogicalOperator) == 1) && (ActrTstFuTnkPmp_Tempo <= 0))
      {
        /* Transition: '<S5>:9' */
        /* Exit 'FUPMP_ACTRTEST_END': '<S5>:2' */
        /* Entry 'FUPMP_ACTRTEST_IDLE': '<S5>:4' */
        ActTstFuPmp_DWork.is_c2_ActTstFuPmp = IN_FUPMP_ACTRTEST_IDLE;
        FuPmp_stActrTst = FUPMP_ACTRTEST_IDLE;
        ActTstFuPmp_B.FuPmp_bFuTnkPmpTstCmpl_g = FALSE;
        ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m = 0U;
        ActTstFuPmp_B.FuPmp_bActrTstInProgs_a = FALSE;
      } else {
        ActrTstFuTnkPmp_Tempo = (UInt16)(rt_MAX((ActrTstFuTnkPmp_Tempo << 5) -
          ((SInt32)(((UInt32)(FuPmp_SampleTiMid_SC * 205)) >> 8)), 0) >> 5);
      }
      break;

     case IN_FUPMP_ACTRTEST_IDLE:
      /* During 'FUPMP_ACTRTEST_IDLE': '<S5>:4' */
      if (((SInt32)localLogicalOperator) == 1) {
        /* Transition: '<S5>:10' */
        /* Exit 'FUPMP_ACTRTEST_IDLE': '<S5>:4' */
        /* Entry 'TestEnCours': '<S5>:5' */
        ActTstFuPmp_DWork.is_c2_ActTstFuPmp = IN_TestEnCours;
        ActrTstFuTnkPmp_CumulTime = (UInt16)((UInt32)(((SInt32)(((UInt32)
          (FuPmp_SampleTiMid_SC * 205)) >> 13)) + ActrTstFuTnkPmp_TotTime_C));
        ActTstFuPmp_B.FuPmp_bActrTstInProgs_a = TRUE;

        /* Entry 'FUPMP_ACTRTEST_MAX': '<S5>:3' */
        ActTstFuPmp_DWork.is_TestEnCours = IN_FUPMP_ACTRTEST_MAX;
        FuPmp_stActrTst = FUPMP_ACTRTEST_MAX;
        ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m = FuPmp_rSpPosnActrTstPos1_C;
        ActrTstFuTnkPmp_IntTime = ActrTstFuTnkPmp_OnTime_C;
        ActrTstFuTnkPmp_CumulTime = (UInt16)(rt_MAX((ActrTstFuTnkPmp_CumulTime
          << 5) - ((SInt32)(((UInt32)(FuPmp_SampleTiMid_SC * 205)) >> 8)), 0)
          >> 5);
      }
      break;

     case IN_TestEnCours:
      /* During 'TestEnCours': '<S5>:5' */
      if ((((SInt32)localLogicalOperator) == 1) && (((UInt32)
            (ActrTstFuTnkPmp_CumulTime << 13)) <= ((UInt32)
            (FuPmp_SampleTiMid_SC * 205)))) {
        /* Transition: '<S5>:6' */
        /* Exit 'FUPMP_ACTRTEST_MAX': '<S5>:3' */
        ActTstFuPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;

        /* Exit 'FUPMP_ACTRTEST_MIN': '<S5>:1' */
        /* Exit 'TestEnCours': '<S5>:5' */
        /* Entry 'FUPMP_ACTRTEST_END': '<S5>:2' */
        ActTstFuPmp_DWork.is_c2_ActTstFuPmp = IN_FUPMP_ACTRTEST_END;
        FuPmp_stActrTst = FUPMP_ACTRTEST_END;
        ActTstFuPmp_B.FuPmp_bFuTnkPmpTstCmpl_g = TRUE;
        ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m = 0U;
        ActTstFuPmp_B.FuPmp_bActrTstInProgs_a = FALSE;
        ActrTstFuTnkPmp_Tempo = ActrTstFuTnkPmp_Tempo_C;
      } else if (((SInt32)localLogicalOperator) == 0) {
        /* Transition: '<S5>:11' */
        /* Exit 'FUPMP_ACTRTEST_MAX': '<S5>:3' */
        ActTstFuPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;

        /* Exit 'FUPMP_ACTRTEST_MIN': '<S5>:1' */
        /* Exit 'TestEnCours': '<S5>:5' */
        /* Entry 'FUPMP_ACTRTEST_IDLE': '<S5>:4' */
        ActTstFuPmp_DWork.is_c2_ActTstFuPmp = IN_FUPMP_ACTRTEST_IDLE;
        FuPmp_stActrTst = FUPMP_ACTRTEST_IDLE;
        ActTstFuPmp_B.FuPmp_bFuTnkPmpTstCmpl_g = FALSE;
        ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m = 0U;
        ActTstFuPmp_B.FuPmp_bActrTstInProgs_a = FALSE;
      } else {
        switch (ActTstFuPmp_DWork.is_TestEnCours) {
         case IN_FUPMP_ACTRTEST_MAX:
          /* During 'FUPMP_ACTRTEST_MAX': '<S5>:3' */
          if (((UInt32)(ActrTstFuTnkPmp_IntTime << 13)) <= ((UInt32)
               (FuPmp_SampleTiMid_SC * 205))) {
            /* Transition: '<S5>:8' */
            /* Exit 'FUPMP_ACTRTEST_MAX': '<S5>:3' */
            /* Entry 'FUPMP_ACTRTEST_MIN': '<S5>:1' */
            ActTstFuPmp_DWork.is_TestEnCours = IN_FUPMP_ACTRTEST_MIN;
            FuPmp_stActrTst = FUPMP_ACTRTEST_MIN;
            ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m = FuPmp_rSpPosnActrTstPos2_C;
            ActrTstFuTnkPmp_IntTime = ActrTstFuTnkPmp_OffTime_C;
            ActrTstFuTnkPmp_CumulTime = (UInt16)(rt_MAX
              ((ActrTstFuTnkPmp_CumulTime << 5) - ((SInt32)(((UInt32)
              (FuPmp_SampleTiMid_SC * 205)) >> 8)), 0) >> 5);
          } else {
            ActrTstFuTnkPmp_CumulTime = (UInt16)(rt_MAX
              ((ActrTstFuTnkPmp_CumulTime << 5) - ((SInt32)(((UInt32)
              (FuPmp_SampleTiMid_SC * 205)) >> 8)), 0) >> 5);
            ActrTstFuTnkPmp_IntTime = (UInt16)(rt_MAX((ActrTstFuTnkPmp_IntTime
              << 5) - ((SInt32)(((UInt32)(FuPmp_SampleTiMid_SC * 205)) >> 8)),
              0) >> 5);
          }
          break;

         case IN_FUPMP_ACTRTEST_MIN:
          /* During 'FUPMP_ACTRTEST_MIN': '<S5>:1' */
          if (((UInt32)(ActrTstFuTnkPmp_IntTime << 13)) <= ((UInt32)
               (FuPmp_SampleTiMid_SC * 205))) {
            /* Transition: '<S5>:7' */
            /* Exit 'FUPMP_ACTRTEST_MIN': '<S5>:1' */
            /* Entry 'FUPMP_ACTRTEST_MAX': '<S5>:3' */
            ActTstFuPmp_DWork.is_TestEnCours = IN_FUPMP_ACTRTEST_MAX;
            FuPmp_stActrTst = FUPMP_ACTRTEST_MAX;
            ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m = FuPmp_rSpPosnActrTstPos1_C;
            ActrTstFuTnkPmp_IntTime = ActrTstFuTnkPmp_OnTime_C;
            ActrTstFuTnkPmp_CumulTime = (UInt16)(rt_MAX
              ((ActrTstFuTnkPmp_CumulTime << 5) - ((SInt32)(((UInt32)
              (FuPmp_SampleTiMid_SC * 205)) >> 8)), 0) >> 5);
          } else {
            ActrTstFuTnkPmp_CumulTime = (UInt16)(rt_MAX
              ((ActrTstFuTnkPmp_CumulTime << 5) - ((SInt32)(((UInt32)
              (FuPmp_SampleTiMid_SC * 205)) >> 8)), 0) >> 5);
            ActrTstFuTnkPmp_IntTime = (UInt16)(rt_MAX((ActrTstFuTnkPmp_IntTime
              << 5) - ((SInt32)(((UInt32)(FuPmp_SampleTiMid_SC * 205)) >> 8)),
              0) >> 5);
          }
          break;
        }
      }
      break;

     default:
      /* Transition: '<S5>:12' */
      /* Entry 'FUPMP_ACTRTEST_IDLE': '<S5>:4' */
      ActTstFuPmp_DWork.is_c2_ActTstFuPmp = IN_FUPMP_ACTRTEST_IDLE;
      FuPmp_stActrTst = FUPMP_ACTRTEST_IDLE;
      ActTstFuPmp_B.FuPmp_bFuTnkPmpTstCmpl_g = FALSE;
      ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m = 0U;
      ActTstFuPmp_B.FuPmp_bActrTstInProgs_a = FALSE;
      break;
    }
  }

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(FuPmp_bActrTstInProgs, ActTstFuPmp_B.FuPmp_bActrTstInProgs_a);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(FuPmp_bFuTnkPmpTstCmpl, ActTstFuPmp_B.FuPmp_bFuTnkPmpTstCmpl_g);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(FuPmp_rSpPosnActrTst, ActTstFuPmp_B.FuPmp_rSpPosnActrTst_m);
}

/* Output and update for exported function: FuPmp_EveRst_ActrTstFuTnkPmp */
void FuPmp_EveRst_ActrTstFuTnkPmp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' */
  ActTstFuPmp_ASYNC1(0);
}

/* Output and update for exported function: FuPmp_SdlMid_ActrTstFuTnkPmp */
void FuPmp_SdlMid_ActrTstFuTnkPmp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' */
  ActTstFuPmp_ASYNC1(1);
}

/* Model initialize function */
void ActTstFuPmp_initialize(void)
{
  /* (no initialization code required) */
}

#define ACTTSTFUPMP_STOP_SEC_CODE
#include "ActTstFuPmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
