/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : ActrTstHPPmp                                            */
/* !Description     : ACTRTSTHPPmp- HP PUMP ACTUATOR TEST                     */
/*                                                                            */
/* !Module          : ActrTstHPPmp                                            */
/*                                                                            */
/* !File            : ActrTstHPPmp.c                                          */
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
/* !Reference       : PTS_DOC_5075814 / 01                                    */
/* !OtherRefs       : VEMS V02 ECU#060533                                     */
/* !OtherRefs       : VEMS V02 ECU#065248                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Mar 05 11:01:47 2013                              */
/*   Model name       : ActrTstHPPmp_AUTOCODE.mdl                             */
/*   Model version    : 1.89                                                  */
/*   Root subsystem   : /ActrTstHPPmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/ACTRTSTHPPMP/ActrTstHPPmp$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ActrTstHPPmp.h"
#include "ActrTstHPPmp_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S7>/HPPmpActrTstChart' */
#define IN_HPPMP_ACTRTEST_END          (1U)
#define IN_HPPMP_ACTRTEST_INIT         (2U)
#define IN_HPPMP_ACTRTEST_PHASE_0      (1U)
#define IN_HPPMP_ACTRTEST_PHASE_1      (2U)
#define IN_HPPMP_ACTRTEST_PHASE_1_BIS  (3U)
#define IN_HPPMP_ACTRTEST_PHASE_2      (4U)
#define IN_HPPMP_ACTRTEST_PHASE_3      (5U)
#define IN_NO_ACTIVE_CHILD             (0U)
#define IN_TestEnCours                 (3U)
#define IN_test                        (6U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define ACTRTSTHPPMP_START_SEC_VAR_UNSPECIFIED
#include "ActrTstHPPmp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_ActrTstHPPmp ActrTstHPPmp_B;

/* Block states (auto storage) */
D_Work_ActrTstHPPmp ActrTstHPPmp_DWork;

#define ACTRTSTHPPMP_STOP_SEC_VAR_UNSPECIFIED
#include "ActrTstHPPmp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define ACTRTSTHPPMP_START_SEC_CODE
#include "ActrTstHPPmp_MemMap.h"

void ActrTstHPPmp_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S1>/F00_HPPmpTst_Init' */
void ActrTstHPPmp_F00_HPPmpTst_Init(void)
{
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(ActrTstHPPmp_bActrTstInProgs, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(ActrTstHPPmp_bActrTstCmpl, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET7 */
  VEMS_vidSET(ActrTstHPPmp_stActrTst, HPPMP_ACTRTEST_INIT);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(ActrTstHPPmp_agWdPmpCmdReq, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET3 */
  VEMS_vidSET(ActrTstHPPmp_bInjAuthReq, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET6 */
  VEMS_vidSET(ActrTstHPPmp_bPrailPresIncFail, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET5 */
  VEMS_vidSET(ActrTstHPPmp_bPrailLeak, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET4 */
  VEMS_vidSET(ActrTstHPPmp_bItActrTstReq, FALSE);
}

/* Output and update for exported function: PFuCtl_EveRst_ActrTstHPPmp */
void PFuCtl_EveRst_ActrTstHPPmp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_HPPmpTst_Init'
   */
  ActrTstHPPmp_F00_HPPmpTst_Init();
}

/* Output and update for function-call system: '<S1>/F01_HPPmpTst' */
void ActrTstHPPmp_F01_HPPmpTst(void)
{
  Boolean localLogicalOperator;

  /* Outputs for enable SubSystem: '<S5>/F01_HPPmpTst' incorporates:
   *  Constant: '<S5>/ACTRTSTHPPMP_u8Inhib'
   *  Constant: '<S5>/Constant1'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (ACTRTSTHPPMP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_pFuRailSplMes, ActrTstHPPmp_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET2 */
    VEMS_vidGET(Srv_bActrTstEna, ActrTstHPPmp_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
    VEMS_vidGET(Code_test_action, ActrTstHPPmp_B.VEMS_vidGET);

    /* Logic: '<S7>/Logical Operator' incorporates:
     *  Constant: '<S7>/CODE_TEST_HPPMP'
     *  RelationalOperator: '<S7>/Relational Operator'
     */
    localLogicalOperator = (ActrTstHPPmp_B.VEMS_vidGET2 &&
      (ActrTstHPPmp_B.VEMS_vidGET == CODE_TEST_HPPMP));

    /* Stateflow: '<S7>/HPPmpActrTstChart' incorporates:
     *  Constant: '<S7>/ActrTstHPPmp_Tempo2_C'
     *  Constant: '<S7>/ActrTstHPPmp_TempoMax_C'
     *  Constant: '<S7>/ActrTstHPPmp_TempoMax_C1'
     *  Constant: '<S7>/ActrTstHPPmp_agWdReq_C'
     *  Constant: '<S7>/ActrTstHPPmp_pRailSpThdHi_C'
     *  Constant: '<S7>/ActrTstHPPmp_pRailSpThdLo_C'
     *  Constant: '<S7>/ActrTstHPPmp_pRailSpThd_C'
     *  Constant: '<S7>/HPPMP_ACTRTEST_END'
     *  Constant: '<S7>/HPPMP_ACTRTEST_INIT'
     *  Constant: '<S7>/HPPMP_ACTRTEST_PHASE_0'
     *  Constant: '<S7>/HPPMP_ACTRTEST_PHASE_1'
     *  Constant: '<S7>/HPPMP_ACTRTEST_PHASE_1_BIS'
     *  Constant: '<S7>/HPPMP_ACTRTEST_PHASE_2'
     *  Constant: '<S7>/HPPMP_ACTRTEST_PHASE_3'
     */
    /* Gateway: ActrTstHPPmp/F01_HPPmpTst/F01_HPPmpTst/F01_HPPmpActrTst/HPPmpActrTstChart */
    /* During: ActrTstHPPmp/F01_HPPmpTst/F01_HPPmpTst/F01_HPPmpActrTst/HPPmpActrTstChart */
    if (ActrTstHPPmp_DWork.is_active_c2_ActrTstHPPmp == 0) {
      /* Entry: ActrTstHPPmp/F01_HPPmpTst/F01_HPPmpTst/F01_HPPmpActrTst/HPPmpActrTstChart */
      ActrTstHPPmp_DWork.is_active_c2_ActrTstHPPmp = 1U;

      /* Transition: '<S9>:10' */
      /* Entry 'HPPMP_ACTRTEST_INIT': '<S9>:8' */
      ActrTstHPPmp_DWork.is_c2_ActrTstHPPmp = IN_HPPMP_ACTRTEST_INIT;
      ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_INIT;
      ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
      ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
      ActrTstHPPmp_B.ActrTstHPPmp_bActrTstInProgs_e = FALSE;
      ActrTstHPPmp_B.ActrTstHPPmp_bActrTstCmpl_o = FALSE;
      ActrTstHPPmp_Tempo_Phase0 = 0U;
      ActrTstHPPmp_Tempo_Phase1 = 0U;
      ActrTstHPPmp_Tempo_Phase2 = ActrTstHPPmp_Tempo2_C;
      ActrTstHPPmp_Tempo_Phase3 = 0U;
    } else {
      switch (ActrTstHPPmp_DWork.is_c2_ActrTstHPPmp) {
       case IN_HPPMP_ACTRTEST_END:
        /* During 'HPPMP_ACTRTEST_END': '<S9>:2' */
        if ((((SInt32)localLogicalOperator) == 1) && (ActrTstHPPmp_ctRstActTst ==
             0)) {
          /* Transition: '<S9>:62' */
          /* Exit 'HPPMP_ACTRTEST_END': '<S9>:2' */
          /* Entry 'HPPMP_ACTRTEST_INIT': '<S9>:8' */
          ActrTstHPPmp_DWork.is_c2_ActrTstHPPmp = IN_HPPMP_ACTRTEST_INIT;
          ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_INIT;
          ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
          ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
          ActrTstHPPmp_B.ActrTstHPPmp_bActrTstInProgs_e = FALSE;
          ActrTstHPPmp_B.ActrTstHPPmp_bActrTstCmpl_o = FALSE;
          ActrTstHPPmp_Tempo_Phase0 = 0U;
          ActrTstHPPmp_Tempo_Phase1 = 0U;
          ActrTstHPPmp_Tempo_Phase2 = ActrTstHPPmp_Tempo2_C;
          ActrTstHPPmp_Tempo_Phase3 = 0U;
        } else {
          ActrTstHPPmp_ctRstActTst = (UInt8)rt_MAX(ActrTstHPPmp_ctRstActTst -
            1, 0);
        }
        break;

       case IN_HPPMP_ACTRTEST_INIT:
        /* During 'HPPMP_ACTRTEST_INIT': '<S9>:8' */
        if (((SInt32)localLogicalOperator) == 1) {
          /* Transition: '<S9>:13' */
          /* Exit 'HPPMP_ACTRTEST_INIT': '<S9>:8' */
          /* Entry 'TestEnCours': '<S9>:5' */
          ActrTstHPPmp_DWork.is_c2_ActrTstHPPmp = IN_TestEnCours;
          ActrTstHPPmp_B.ActrTstHPPmp_bActrTstInProgs_e = TRUE;

          /* Transition: '<S9>:20' */
          /* Entry 'test': '<S9>:57' */
          ActrTstHPPmp_DWork.is_TestEnCours = IN_test;
        }
        break;

       case IN_TestEnCours:
        /* During 'TestEnCours': '<S9>:5' */
        if (((SInt32)localLogicalOperator) == 0) {
          /* Transition: '<S9>:16' */
          switch (ActrTstHPPmp_DWork.is_TestEnCours) {
           case IN_HPPMP_ACTRTEST_PHASE_1:
            /* Exit 'HPPMP_ACTRTEST_PHASE_1': '<S9>:3' */
            ActrTstHPPmp_pFuRailMesEnd1 = ActrTstHPPmp_B.VEMS_vidGET1;
            ActrTstHPPmp_pRailPresDiff = (UInt16)rt_ABS
              (ActrTstHPPmp_pFuRailMesEnd1 - ActrTstHPPmp_pFuRailMesBeg1);
            ActrTstHPPmp_pRailPerPmp = ((Float32)(((UInt32)
              ActrTstHPPmp_pRailPresDiff) / ActrTstHPPmp_Tempo_Phase1)) *
              781.25F;
            ActrTstHPPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;
            break;

           case IN_HPPMP_ACTRTEST_PHASE_2:
            /* Exit 'HPPMP_ACTRTEST_PHASE_2': '<S9>:1' */
            ActrTstHPPmp_pFuRailMesEnd2 = ActrTstHPPmp_B.VEMS_vidGET1;
            ActrTstHPPmp_pRailPresDif2 = (UInt16)rt_ABS
              (ActrTstHPPmp_pFuRailMesEnd2 - ActrTstHPPmp_pFuRailMesBeg2);
            ActrTstHPPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;
            break;

           default:
            ActrTstHPPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;

            /* Exit 'HPPMP_ACTRTEST_PHASE_0': '<S9>:4' */
            /* Exit 'HPPMP_ACTRTEST_PHASE_1_BIS': '<S9>:6' */
            /* Exit 'HPPMP_ACTRTEST_PHASE_3': '<S9>:7' */
            /* Exit 'test': '<S9>:57' */
            break;
          }

          /* Exit 'TestEnCours': '<S9>:5' */
          /* Entry 'HPPMP_ACTRTEST_INIT': '<S9>:8' */
          ActrTstHPPmp_DWork.is_c2_ActrTstHPPmp = IN_HPPMP_ACTRTEST_INIT;
          ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_INIT;
          ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
          ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
          ActrTstHPPmp_B.ActrTstHPPmp_bActrTstInProgs_e = FALSE;
          ActrTstHPPmp_B.ActrTstHPPmp_bActrTstCmpl_o = FALSE;
          ActrTstHPPmp_Tempo_Phase0 = 0U;
          ActrTstHPPmp_Tempo_Phase1 = 0U;
          ActrTstHPPmp_Tempo_Phase2 = ActrTstHPPmp_Tempo2_C;
          ActrTstHPPmp_Tempo_Phase3 = 0U;
        } else if ((((ActrTstHPPmp_Tempo_Phase0 + ActrTstHPPmp_Tempo_Phase1Bis)
                     + ((UInt32)ActrTstHPPmp_Tempo2_C)) +
                    ActrTstHPPmp_Tempo_Phase3) > ((UInt32)
                    ActrTstHPPmp_TempoMax_C)) {
          /* Transition: '<S9>:15' */
          switch (ActrTstHPPmp_DWork.is_TestEnCours) {
           case IN_HPPMP_ACTRTEST_PHASE_1:
            /* Exit 'HPPMP_ACTRTEST_PHASE_1': '<S9>:3' */
            ActrTstHPPmp_pFuRailMesEnd1 = ActrTstHPPmp_B.VEMS_vidGET1;
            ActrTstHPPmp_pRailPresDiff = (UInt16)rt_ABS
              (ActrTstHPPmp_pFuRailMesEnd1 - ActrTstHPPmp_pFuRailMesBeg1);
            ActrTstHPPmp_pRailPerPmp = ((Float32)(((UInt32)
              ActrTstHPPmp_pRailPresDiff) / ActrTstHPPmp_Tempo_Phase1)) *
              781.25F;
            ActrTstHPPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;
            break;

           case IN_HPPMP_ACTRTEST_PHASE_2:
            /* Exit 'HPPMP_ACTRTEST_PHASE_2': '<S9>:1' */
            ActrTstHPPmp_pFuRailMesEnd2 = ActrTstHPPmp_B.VEMS_vidGET1;
            ActrTstHPPmp_pRailPresDif2 = (UInt16)rt_ABS
              (ActrTstHPPmp_pFuRailMesEnd2 - ActrTstHPPmp_pFuRailMesBeg2);
            ActrTstHPPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;
            break;

           default:
            ActrTstHPPmp_DWork.is_TestEnCours = (UInt8)IN_NO_ACTIVE_CHILD;

            /* Exit 'HPPMP_ACTRTEST_PHASE_0': '<S9>:4' */
            /* Exit 'HPPMP_ACTRTEST_PHASE_1_BIS': '<S9>:6' */
            /* Exit 'HPPMP_ACTRTEST_PHASE_3': '<S9>:7' */
            /* Exit 'test': '<S9>:57' */
            break;
          }

          /* Exit 'TestEnCours': '<S9>:5' */
          /* Entry 'HPPMP_ACTRTEST_END': '<S9>:2' */
          ActrTstHPPmp_DWork.is_c2_ActrTstHPPmp = IN_HPPMP_ACTRTEST_END;
          ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_END;
          ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
          ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
          ActrTstHPPmp_B.ActrTstHPPmp_bActrTstInProgs_e = FALSE;
          ActrTstHPPmp_B.ActrTstHPPmp_bActrTstCmpl_o = TRUE;
          ActrTstHPPmp_ctRstActTst = ActrTstHPPmp_ctRstActTst_C;
        } else {
          switch (ActrTstHPPmp_DWork.is_TestEnCours) {
           case IN_HPPMP_ACTRTEST_PHASE_0:
            /* During 'HPPMP_ACTRTEST_PHASE_0': '<S9>:4' */
            if (ActrTstHPPmp_B.VEMS_vidGET1 < ActrTstHPPmp_pRailSpThd_C) {
              /* Transition: '<S9>:17' */
              /* Exit 'HPPMP_ACTRTEST_PHASE_0': '<S9>:4' */
              /* Entry 'HPPMP_ACTRTEST_PHASE_1': '<S9>:3' */
              ActrTstHPPmp_DWork.is_TestEnCours = IN_HPPMP_ACTRTEST_PHASE_1;
              ActrTstHPPmp_pFuRailMesBeg1 = ActrTstHPPmp_B.VEMS_vidGET1;
              ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_PHASE_1;
              ActrTstHPPmp_Tempo_Phase1 = 1U;
              ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
              ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n =
                ActrTstHPPmp_agWdReq_C;
            } else {
              ActrTstHPPmp_Tempo_Phase0 = ActrTstHPPmp_Tempo_Phase0 + 1U;
            }
            break;

           case IN_HPPMP_ACTRTEST_PHASE_1:
            /* During 'HPPMP_ACTRTEST_PHASE_1': '<S9>:3' */
            if (ActrTstHPPmp_B.VEMS_vidGET1 > ActrTstHPPmp_pRailSpThdHi_C) {
              /* Transition: '<S9>:12' */
              /*  Priority 1 */
              /* Exit 'HPPMP_ACTRTEST_PHASE_1': '<S9>:3' */
              ActrTstHPPmp_pFuRailMesEnd1 = ActrTstHPPmp_B.VEMS_vidGET1;
              ActrTstHPPmp_pRailPresDiff = (UInt16)rt_ABS
                (ActrTstHPPmp_pFuRailMesEnd1 - ActrTstHPPmp_pFuRailMesBeg1);
              ActrTstHPPmp_pRailPerPmp = ((Float32)(((UInt32)
                ActrTstHPPmp_pRailPresDiff) / ActrTstHPPmp_Tempo_Phase1)) *
                781.25F;

              /* Entry 'HPPMP_ACTRTEST_PHASE_1_BIS': '<S9>:6' */
              ActrTstHPPmp_DWork.is_TestEnCours = IN_HPPMP_ACTRTEST_PHASE_1_BIS;
              ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h =
                HPPMP_ACTRTEST_PHASE_1_BIS;
              ActrTstHPPmp_Tempo_Phase1Bis = ActrTstHPPmp_Tempo_Phase1;
              ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = TRUE;
              ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
            } else if ((ActrTstHPPmp_B.VEMS_vidGET1 <
                        ActrTstHPPmp_pRailSpThdHi_C) &&
                       (ActrTstHPPmp_B.VEMS_vidGET1 >
                        ActrTstHPPmp_pRailSpThdLo_C)) {
              /* Transition: '<S9>:11' */
              /* Exit 'HPPMP_ACTRTEST_PHASE_1': '<S9>:3' */
              ActrTstHPPmp_pFuRailMesEnd1 = ActrTstHPPmp_B.VEMS_vidGET1;
              ActrTstHPPmp_pRailPresDiff = (UInt16)rt_ABS
                (ActrTstHPPmp_pFuRailMesEnd1 - ActrTstHPPmp_pFuRailMesBeg1);
              ActrTstHPPmp_pRailPerPmp = ((Float32)(((UInt32)
                ActrTstHPPmp_pRailPresDiff) / ActrTstHPPmp_Tempo_Phase1)) *
                781.25F;

              /* Entry 'HPPMP_ACTRTEST_PHASE_2': '<S9>:1' */
              ActrTstHPPmp_DWork.is_TestEnCours = IN_HPPMP_ACTRTEST_PHASE_2;
              ActrTstHPPmp_pFuRailMesBeg2 = ActrTstHPPmp_B.VEMS_vidGET1;
              ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_PHASE_2;
              ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
              ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
            } else {
              ActrTstHPPmp_Tempo_Phase1 = ActrTstHPPmp_Tempo_Phase1 + 1U;
            }
            break;

           case IN_HPPMP_ACTRTEST_PHASE_1_BIS:
            /* During 'HPPMP_ACTRTEST_PHASE_1_BIS': '<S9>:6' */
            if (ActrTstHPPmp_B.VEMS_vidGET1 < ActrTstHPPmp_pRailSpThdHi_C) {
              /* Transition: '<S9>:9' */
              /* Exit 'HPPMP_ACTRTEST_PHASE_1_BIS': '<S9>:6' */
              /* Entry 'HPPMP_ACTRTEST_PHASE_2': '<S9>:1' */
              ActrTstHPPmp_DWork.is_TestEnCours = IN_HPPMP_ACTRTEST_PHASE_2;
              ActrTstHPPmp_pFuRailMesBeg2 = ActrTstHPPmp_B.VEMS_vidGET1;
              ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_PHASE_2;
              ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
              ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
            } else {
              ActrTstHPPmp_Tempo_Phase1Bis = ActrTstHPPmp_Tempo_Phase1Bis + 1U;
            }
            break;

           case IN_HPPMP_ACTRTEST_PHASE_2:
            /* During 'HPPMP_ACTRTEST_PHASE_2': '<S9>:1' */
            if (ActrTstHPPmp_Tempo_Phase2 == 0U) {
              /* Transition: '<S9>:14' */
              /* Exit 'HPPMP_ACTRTEST_PHASE_2': '<S9>:1' */
              ActrTstHPPmp_pFuRailMesEnd2 = ActrTstHPPmp_B.VEMS_vidGET1;
              ActrTstHPPmp_pRailPresDif2 = (UInt16)rt_ABS
                (ActrTstHPPmp_pFuRailMesEnd2 - ActrTstHPPmp_pFuRailMesBeg2);

              /* Entry 'HPPMP_ACTRTEST_PHASE_3': '<S9>:7' */
              ActrTstHPPmp_DWork.is_TestEnCours = IN_HPPMP_ACTRTEST_PHASE_3;
              ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_PHASE_3;
              ActrTstHPPmp_Tempo_Phase3 = 1U;
              ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = TRUE;
              ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
            } else {
              ActrTstHPPmp_Tempo_Phase2 = ActrTstHPPmp_Tempo_Phase2 - 1U;
            }
            break;

           case IN_HPPMP_ACTRTEST_PHASE_3:
            /* During 'HPPMP_ACTRTEST_PHASE_3': '<S9>:7' */
            ActrTstHPPmp_Tempo_Phase3 = ActrTstHPPmp_Tempo_Phase3 + 1U;
            break;

           case IN_test:
            /* During 'test': '<S9>:57' */
            if (ActrTstHPPmp_B.VEMS_vidGET1 > ActrTstHPPmp_pRailSpThd_C) {
              /* Transition: '<S9>:18' */
              /*  Priority 1 */
              /* Exit 'test': '<S9>:57' */
              /* Entry 'HPPMP_ACTRTEST_PHASE_0': '<S9>:4' */
              ActrTstHPPmp_DWork.is_TestEnCours = IN_HPPMP_ACTRTEST_PHASE_0;
              ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_PHASE_0;
              ActrTstHPPmp_Tempo_Phase0 = 1U;
              ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = TRUE;
              ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
            } else {
              if (ActrTstHPPmp_B.VEMS_vidGET1 < ActrTstHPPmp_pRailSpThd_C) {
                /* Transition: '<S9>:19' */
                /*  Priority 2 */
                /* Exit 'test': '<S9>:57' */
                /* Entry 'HPPMP_ACTRTEST_PHASE_1': '<S9>:3' */
                ActrTstHPPmp_DWork.is_TestEnCours = IN_HPPMP_ACTRTEST_PHASE_1;
                ActrTstHPPmp_pFuRailMesBeg1 = ActrTstHPPmp_B.VEMS_vidGET1;
                ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_PHASE_1;
                ActrTstHPPmp_Tempo_Phase1 = 1U;
                ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
                ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n =
                  ActrTstHPPmp_agWdReq_C;
              }
            }
            break;

           default:
            /* Transition: '<S9>:20' */
            /* Entry 'test': '<S9>:57' */
            ActrTstHPPmp_DWork.is_TestEnCours = IN_test;
            break;
          }
        }
        break;

       default:
        /* Transition: '<S9>:10' */
        /* Entry 'HPPMP_ACTRTEST_INIT': '<S9>:8' */
        ActrTstHPPmp_DWork.is_c2_ActrTstHPPmp = IN_HPPMP_ACTRTEST_INIT;
        ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h = HPPMP_ACTRTEST_INIT;
        ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d = FALSE;
        ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n = 0U;
        ActrTstHPPmp_B.ActrTstHPPmp_bActrTstInProgs_e = FALSE;
        ActrTstHPPmp_B.ActrTstHPPmp_bActrTstCmpl_o = FALSE;
        ActrTstHPPmp_Tempo_Phase0 = 0U;
        ActrTstHPPmp_Tempo_Phase1 = 0U;
        ActrTstHPPmp_Tempo_Phase2 = ActrTstHPPmp_Tempo2_C;
        ActrTstHPPmp_Tempo_Phase3 = 0U;
        break;
      }
    }

    /* RelationalOperator: '<S8>/Relational Operator3' incorporates:
     *  Constant: '<S8>/ActrTstHPPmp_pRailPerPmp_C'
     *  DataTypeConversion: '<S8>/Data Type Conversion1'
     */
    ActrTstHPPmp_B.RelationalOperator3 = (ActrTstHPPmp_pRailPerPmp > (((Float32)
      ActrTstHPPmp_pRailPerPmp_C) * 781.25F));

    /* RelationalOperator: '<S8>/Relational Operator4' incorporates:
     *  Constant: '<S8>/ActrTstHPPmp_pRailPresDif2_C'
     */
    ActrTstHPPmp_B.RelationalOperator4 = (ActrTstHPPmp_pRailPresDif2 >
      ActrTstHPPmp_pRailPresDif2_C);

    /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
     *  Constant: '<S8>/ActrTstHPPmp_Tempo_Phase1_C'
     */
    ActrTstHPPmp_B.RelationalOperator1 = (ActrTstHPPmp_Tempo_Phase1 > ((UInt32)
      ActrTstHPPmp_Tempo_Phase1_C));

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
    VEMS_vidSET(ActrTstHPPmp_agWdPmpCmdReq,
                ActrTstHPPmp_B.ActrTstHPPmp_agWdPmpCmdReq_n);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
    VEMS_vidSET(ActrTstHPPmp_bActrTstCmpl,
                ActrTstHPPmp_B.ActrTstHPPmp_bActrTstCmpl_o);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET2 */
    VEMS_vidSET(ActrTstHPPmp_bActrTstInProgs,
                ActrTstHPPmp_B.ActrTstHPPmp_bActrTstInProgs_e);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET3 */
    VEMS_vidSET(ActrTstHPPmp_bInjAuthReq,
                ActrTstHPPmp_B.ActrTstHPPmp_bInjAuthReq_d);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET4 */
    VEMS_vidSET(ActrTstHPPmp_bItActrTstReq, ActrTstHPPmp_B.RelationalOperator1);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET5 */
    VEMS_vidSET(ActrTstHPPmp_bPrailLeak, ActrTstHPPmp_B.RelationalOperator4);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET6 */
    VEMS_vidSET(ActrTstHPPmp_bPrailPresIncFail,
                ActrTstHPPmp_B.RelationalOperator3);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET7 */
    VEMS_vidSET(ActrTstHPPmp_stActrTst, ActrTstHPPmp_B.ActrTstHPPmp_stActrTst_h);
  }

  /* end of Outputs for SubSystem: '<S5>/F01_HPPmpTst' */
}

/* Output and update for exported function: PFuCtl_EveSpl_ActrTstHPPmp */
void PFuCtl_EveSpl_ActrTstHPPmp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_HPPmpTst'
   */
  ActrTstHPPmp_F01_HPPmpTst();
}

/* Model initialize function */
void ActrTstHPPmp_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
}

#define ACTRTSTHPPMP_STOP_SEC_CODE
#include "ActrTstHPPmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
