/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : MonEngStrt                                              */
/* !Description     : Surveillance du démarrage                               */
/*                                                                            */
/* !Module          : MonEngStrt                                              */
/*                                                                            */
/* !File            : MonEngStrt.c                                            */
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
/* !Reference       : PTS_DOC_5489216 / 01                                    */
/* !OtherRefs       : VEMS V02 ECU#066788                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Sep 12 10:47:43 2013                              */
/*   Model name       : MonEngStrt_AUTOCODE.mdl                               */
/*   Model version    : 1.202                                                 */
/*   Root subsystem   : /MonEngStrt                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/MONENGSTRT/MonEngStrt.c_v $*/
/* $Revision::   1.5                                                         $*/
/* $Author::   etsasson                               $$Date::   27 Sep 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "MonEngStrt.h"
#include "MonEngStrt_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S19>/F02_Etat_Diag' */
#define IN_ENGINE_MONSTRT_PFUEL        (1U)
#define IN_ENGST_MONSTRT_ENDED         (1U)
#define IN_ENGST_MONSTRT_IDLE          (2U)
#define IN_ENGST_MONSTRT_PRES          (2U)
#define IN_ENGST_MONSTRT_RUNNING       (3U)
#define IN_ENGST_MONSTRT_STARTED       (3U)
#define IN_ENGST_MONSTRT_SYNCHRONYZED  (4U)
#define IN_ENGST_MONSTRT_UNLOCKED      (5U)
#define IN_NO_ACTIVE_CHILD             (0U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define MONENGSTRT_START_SEC_VAR_UNSPECIFIED
#include "MonEngStrt_MemMap.h"

/* Block signals (auto storage) */
BlockIO_MonEngStrt MonEngStrt_B;

/* Block states (auto storage) */
D_Work_MonEngStrt MonEngStrt_DWork;

/* Forward declaration for local functions */
static void exit_internal_ENGST_MONSTRT_RUN(rtB_F00_autorisationDiag_MonEng
  *localB, rtDW_F00_autorisationDiag_MonEn *localDW);

#define MONENGSTRT_STOP_SEC_VAR_UNSPECIFIED
#include "MonEngStrt_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define MONENGSTRT_START_SEC_CODE
#include "MonEngStrt_MemMap.h"

void MonEngStrt_ASYNC1(int controlPortIdx)
{
}

/* Function for Stateflow: '<S19>/F02_Etat_Diag' */
static void exit_internal_ENGST_MONSTRT_RUN(rtB_F00_autorisationDiag_MonEng
  *localB, rtDW_F00_autorisationDiag_MonEn *localDW)
{
  switch (localDW->is_ENGST_MONSTRT_RUNNING) {
   case IN_ENGST_MONSTRT_PRES:
    /* Exit 'ENGST_MONSTRT_PRES': '<S20>:3' */
    localB->EngSt_tiDlySync_j = (UInt16)((UInt32)(localB->EngSt_tiDlySync_j
      + localB->DTConv_UFix_To_Single_1));
    localB->EngSt_tiDlyPFuMin_a = (UInt16)((UInt32)
      (localB->EngSt_tiDlyPFuMin_a + localB->DTConv_UFix_To_Single_1));
    localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)(localB->EngSt_tiDlyStrt_j
      + localB->DTConv_UFix_To_Single_1));
    localDW->is_ENGST_MONSTRT_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;
    break;

   case IN_ENGST_MONSTRT_SYNCHRONYZED:
    /* Exit 'ENGST_MONSTRT_SYNCHRONYZED': '<S20>:6' */
    localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)(localB->EngSt_tiDlyStrt_j
      + localB->DTConv_UFix_To_Single_1));
    localDW->is_ENGST_MONSTRT_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;
    break;

   case IN_ENGST_MONSTRT_UNLOCKED:
    /* Exit 'ENGST_MONSTRT_UNLOCKED': '<S20>:5' */
    localB->EngSt_tiDlyPFuMin_a = (UInt16)((UInt32)
      (localB->EngSt_tiDlyPFuMin_a + localB->DTConv_UFix_To_Single_1));
    localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)(localB->EngSt_tiDlyStrt_j
      + localB->DTConv_UFix_To_Single_1));
    localDW->is_ENGST_MONSTRT_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;
    break;

   default:
    localDW->is_ENGST_MONSTRT_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;

    /* Exit 'ENGINE_MONSTRT_PFUEL': '<S20>:8' */
    /* Exit 'ENGST_MONSTRT_STARTED': '<S20>:1' */
    break;
  }
}

/*
 * Output and update for atomic system:
 *    '<S7>/F00_autorisationDiag'
 *    '<S16>/F00_autorisationDiag'
 */
void MonEngStrt_F00_autorisationDiag(Boolean rtu_First_crank, Boolean
  rtu_EngSt_bCmdCranking, UInt16 rtu_IMMO_stEcuLockStTyp, Boolean
  rtu_Moteur_synchronise, UInt8 rtu_Vehicle_active_state, Boolean
  rtu_EngSt_bMonEngStrtEnd, Boolean rtu_Ctrl_bAcv_PFuAcq, Boolean
  rtu_InjSys_bDetPFuThdInjHPst, Boolean rtu_FRM_bInhMonEngStrt,
  rtB_F00_autorisationDiag_MonEng *localB, rtDW_F00_autorisationDiag_MonEn
  *localDW)
{
  SInt32 localtmp;

  /* DataTypeConversion: '<S19>/DTConv_UFix_To_Single_1' incorporates:
   *  Constant: '<S19>/EngSt_SampleTiFast_SC'
   */
  localtmp = EngSt_SampleTiFast_SC * 205;
  localB->DTConv_UFix_To_Single_1 = (UInt8)((((UInt32)(localtmp & 1024)) !=
    0U) + ((SInt32)(((UInt32)localtmp) >> 11)));

  /* Stateflow: '<S19>/F02_Etat_Diag' incorporates:
   *  Constant: '<S19>/ENGST_MONSTRT_ENDED'
   *  Constant: '<S19>/ENGST_MONSTRT_IDLE'
   *  Constant: '<S19>/ENGST_MONSTRT_RUNNING'
   *  Constant: '<S19>/ENGST_MONSTRT_RUNNING1'
   *  Constant: '<S19>/ENGST_MONSTRT_RUNNING2'
   *  Constant: '<S19>/ENGST_MONSTRT_RUNNING3'
   *  Constant: '<S19>/ENGST_MONSTRT_RUNNING4'
   *  Constant: '<S19>/IMMO_ECU_UNLOCKED'
   *  Constant: '<S19>/VS_RUNNING'
   *  Constant: '<S19>/VS_RUNNING1'
   */
  /* Gateway: MonEngStrt/F02_autorisationDiag_Rst/F00_autorisationDiag/F02_Etat_Diag */
  /* During: MonEngStrt/F02_autorisationDiag_Rst/F00_autorisationDiag/F02_Etat_Diag */
  if (localDW->is_active_c1_MonEngStrt == 0) {
    /* Entry: MonEngStrt/F02_autorisationDiag_Rst/F00_autorisationDiag/F02_Etat_Diag */
    localDW->is_active_c1_MonEngStrt = 1U;

    /* Transition: '<S20>:11' */
    /* Entry 'ENGST_MONSTRT_IDLE': '<S20>:2' */
    localDW->is_c1_MonEngStrt = IN_ENGST_MONSTRT_IDLE;
    localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_IDLE;
    localB->EngSt_bAcvStrtDiag_k = FALSE;
    localB->EngSt_bMonWaitORngEngSt_m = FALSE;
    localB->EngSt_tiDlyUnlockADC_p = 0U;
    localB->EngSt_tiDlySync_j = 0U;
    localB->EngSt_tiDlyPFuMin_a = 0U;
    localB->EngSt_tiDlyStrt_j = 0U;
  } else {
    switch (localDW->is_c1_MonEngStrt) {
     case IN_ENGST_MONSTRT_ENDED:
      /* During 'ENGST_MONSTRT_ENDED': '<S20>:4' */
      localB->EngSt_bAcvStrtDiag_k = FALSE;
      localB->EngSt_tiDlyUnlockADC_p = 0U;
      localB->EngSt_tiDlySync_j = 0U;
      localB->EngSt_tiDlyPFuMin_a = 0U;
      localB->EngSt_tiDlyStrt_j = 0U;
      break;

     case IN_ENGST_MONSTRT_IDLE:
      /* During 'ENGST_MONSTRT_IDLE': '<S20>:2' */
      if (((((SInt32)rtu_First_crank) == 0) && (((SInt32)
             rtu_EngSt_bCmdCranking) == 1)) && (((SInt32)rtu_FRM_bInhMonEngStrt)
           == 0)) {
        /* Transition: '<S20>:9' */
        /* Exit 'ENGST_MONSTRT_IDLE': '<S20>:2' */
        /* Entry 'ENGST_MONSTRT_RUNNING': '<S20>:7' */
        localDW->is_c1_MonEngStrt = IN_ENGST_MONSTRT_RUNNING;
        localB->EngSt_bAcvStrtDiag_k = TRUE;
        localB->EngSt_bMonWaitORngEngSt_m = TRUE;

        /* Transition: '<S20>:16' */
        /* Entry 'ENGST_MONSTRT_PRES': '<S20>:3' */
        localDW->is_ENGST_MONSTRT_RUNNING = IN_ENGST_MONSTRT_PRES;
        localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_PRES;
      }
      break;

     case IN_ENGST_MONSTRT_RUNNING:
      /* During 'ENGST_MONSTRT_RUNNING': '<S20>:7' */
      /* Transition: '<S20>:52' */
      if ((((SInt32)rtu_FRM_bInhMonEngStrt) == 1) || (rtu_Vehicle_active_state ==
           VS_STALL)) {
        /* Transition: '<S20>:58' */
        exit_internal_ENGST_MONSTRT_RUN(localB, localDW);

        /* Exit 'ENGST_MONSTRT_RUNNING': '<S20>:7' */
        /* Entry 'ENGST_MONSTRT_IDLE': '<S20>:2' */
        localDW->is_c1_MonEngStrt = IN_ENGST_MONSTRT_IDLE;
        localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_IDLE;
        localB->EngSt_bAcvStrtDiag_k = FALSE;
        localB->EngSt_bMonWaitORngEngSt_m = FALSE;
        localB->EngSt_tiDlyUnlockADC_p = 0U;
        localB->EngSt_tiDlySync_j = 0U;
        localB->EngSt_tiDlyPFuMin_a = 0U;
        localB->EngSt_tiDlyStrt_j = 0U;
      } else if (((((SInt32)rtu_FRM_bInhMonEngStrt) == 0) &&
                  (rtu_Vehicle_active_state != VS_STALL)) && (((SInt32)
                   rtu_EngSt_bMonEngStrtEnd) == 1)) {
        /* Transition: '<S20>:56' */
        /* Transition: '<S20>:57' */
        exit_internal_ENGST_MONSTRT_RUN(localB, localDW);

        /* Exit 'ENGST_MONSTRT_RUNNING': '<S20>:7' */
        /* Entry 'ENGST_MONSTRT_ENDED': '<S20>:4' */
        localDW->is_c1_MonEngStrt = IN_ENGST_MONSTRT_ENDED;
        localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_ENDED;
        localB->EngSt_bAcvStrtDiag_k = TRUE;
        localB->EngSt_bMonWaitORngEngSt_m = FALSE;
      } else {
        switch (localDW->is_ENGST_MONSTRT_RUNNING) {
         case IN_ENGINE_MONSTRT_PFUEL:
          /* During 'ENGINE_MONSTRT_PFUEL': '<S20>:8' */
          if (rtu_Vehicle_active_state == VS_RUNNING) {
            /* Transition: '<S20>:13' */
            /* Exit 'ENGINE_MONSTRT_PFUEL': '<S20>:8' */
            /* Entry 'ENGST_MONSTRT_STARTED': '<S20>:1' */
            localDW->is_ENGST_MONSTRT_RUNNING = IN_ENGST_MONSTRT_STARTED;
            localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_STARTED;
          } else {
            localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlyStrt_j + localB->DTConv_UFix_To_Single_1));
          }
          break;

         case IN_ENGST_MONSTRT_PRES:
          /* During 'ENGST_MONSTRT_PRES': '<S20>:3' */
          if (rtu_IMMO_stEcuLockStTyp == IMMO_ECU_UNLOCKED) {
            /* Transition: '<S20>:10' */
            /* Exit 'ENGST_MONSTRT_PRES': '<S20>:3' */
            localB->EngSt_tiDlySync_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlySync_j + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlyPFuMin_a = (UInt16)((UInt32)
              (localB->EngSt_tiDlyPFuMin_a + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlyStrt_j + localB->DTConv_UFix_To_Single_1));

            /* Entry 'ENGST_MONSTRT_UNLOCKED': '<S20>:5' */
            localDW->is_ENGST_MONSTRT_RUNNING = IN_ENGST_MONSTRT_UNLOCKED;
            localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_UNLOCKED;
          } else {
            localB->EngSt_tiDlyUnlockADC_p = (UInt16)((UInt32)
              (localB->EngSt_tiDlyUnlockADC_p + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlySync_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlySync_j + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlyPFuMin_a = (UInt16)((UInt32)
              (localB->EngSt_tiDlyPFuMin_a + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlyStrt_j + localB->DTConv_UFix_To_Single_1));
          }
          break;

         case IN_ENGST_MONSTRT_STARTED:
          /* During 'ENGST_MONSTRT_STARTED': '<S20>:1' */
          if (rtu_Vehicle_active_state == VS_RUNNING) {
            /* Transition: '<S20>:19' */
            /* Exit 'ENGST_MONSTRT_STARTED': '<S20>:1' */
            localDW->is_ENGST_MONSTRT_RUNNING = (UInt8)IN_NO_ACTIVE_CHILD;

            /* Exit 'ENGST_MONSTRT_RUNNING': '<S20>:7' */
            /* Entry 'ENGST_MONSTRT_ENDED': '<S20>:4' */
            localDW->is_c1_MonEngStrt = IN_ENGST_MONSTRT_ENDED;
            localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_ENDED;
            localB->EngSt_bAcvStrtDiag_k = TRUE;
            localB->EngSt_bMonWaitORngEngSt_m = FALSE;
          }
          break;

         case IN_ENGST_MONSTRT_SYNCHRONYZED:
          /* During 'ENGST_MONSTRT_SYNCHRONYZED': '<S20>:6' */
          if ((((SInt32)rtu_Ctrl_bAcv_PFuAcq) == 0) &&
              (rtu_Vehicle_active_state == VS_RUNNING)) {
            /* Transition: '<S20>:18' */
            /* Exit 'ENGST_MONSTRT_SYNCHRONYZED': '<S20>:6' */
            localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlyStrt_j + localB->DTConv_UFix_To_Single_1));

            /* Entry 'ENGST_MONSTRT_STARTED': '<S20>:1' */
            localDW->is_ENGST_MONSTRT_RUNNING = IN_ENGST_MONSTRT_STARTED;
            localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_STARTED;
          } else if (((SInt32)rtu_InjSys_bDetPFuThdInjHPst) == 1) {
            /* Transition: '<S20>:17' */
            /* Exit 'ENGST_MONSTRT_SYNCHRONYZED': '<S20>:6' */
            localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlyStrt_j + localB->DTConv_UFix_To_Single_1));

            /* Entry 'ENGINE_MONSTRT_PFUEL': '<S20>:8' */
            localDW->is_ENGST_MONSTRT_RUNNING = IN_ENGINE_MONSTRT_PFUEL;
            localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_PFUEL;
          } else {
            localB->EngSt_tiDlyPFuMin_a = (UInt16)((UInt32)
              (localB->EngSt_tiDlyPFuMin_a + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlyStrt_j + localB->DTConv_UFix_To_Single_1));
          }
          break;

         case IN_ENGST_MONSTRT_UNLOCKED:
          /* During 'ENGST_MONSTRT_UNLOCKED': '<S20>:5' */
          if (((SInt32)rtu_Moteur_synchronise) == 1) {
            /* Transition: '<S20>:12' */
            /* Exit 'ENGST_MONSTRT_UNLOCKED': '<S20>:5' */
            localB->EngSt_tiDlyPFuMin_a = (UInt16)((UInt32)
              (localB->EngSt_tiDlyPFuMin_a + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlyStrt_j + localB->DTConv_UFix_To_Single_1));

            /* Entry 'ENGST_MONSTRT_SYNCHRONYZED': '<S20>:6' */
            localDW->is_ENGST_MONSTRT_RUNNING = IN_ENGST_MONSTRT_SYNCHRONYZED;
            localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_SYNCHRONYZED;
          } else {
            localB->EngSt_tiDlySync_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlySync_j + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlyPFuMin_a = (UInt16)((UInt32)
              (localB->EngSt_tiDlyPFuMin_a + localB->DTConv_UFix_To_Single_1));
            localB->EngSt_tiDlyStrt_j = (UInt16)((UInt32)
              (localB->EngSt_tiDlyStrt_j + localB->DTConv_UFix_To_Single_1));
          }
          break;

         default:
          /* Transition: '<S20>:16' */
          /* Entry 'ENGST_MONSTRT_PRES': '<S20>:3' */
          localDW->is_ENGST_MONSTRT_RUNNING = IN_ENGST_MONSTRT_PRES;
          localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_PRES;
          break;
        }
      }
      break;

     default:
      /* Transition: '<S20>:11' */
      /* Entry 'ENGST_MONSTRT_IDLE': '<S20>:2' */
      localDW->is_c1_MonEngStrt = IN_ENGST_MONSTRT_IDLE;
      localB->EngSt_stMonEngStrt_e = ENGST_MONSTRT_IDLE;
      localB->EngSt_bAcvStrtDiag_k = FALSE;
      localB->EngSt_bMonWaitORngEngSt_m = FALSE;
      localB->EngSt_tiDlyUnlockADC_p = 0U;
      localB->EngSt_tiDlySync_j = 0U;
      localB->EngSt_tiDlyPFuMin_a = 0U;
      localB->EngSt_tiDlyStrt_j = 0U;
      break;
    }
  }

  /* DataStoreWrite: '<S19>/Data Store Write2' */
  EngSt_stMonEngStrt = localB->EngSt_stMonEngStrt_e;
}

/* Output and update for function-call system: '<S1>/F02_autorisationDiag_Rst' */
void MonEng_F02_autorisationDiag_Rst(void)
{
  /* S-Function "vems_vidGET" Block: <S7>/VEMS_vidGET2 */
  VEMS_vidGET(First_crank, MonEngStrt_B.VEMS_vidGET2_k);

  /* SignalConversion: '<S7>/Signal Conversion7' */
  MonEngStrt_B.SignalConversion7_c = EngSt_bCmdCranking;

  /* S-Function "vems_vidGET" Block: <S7>/VEMS_vidGET3 */
  VEMS_vidGET(IMMO_stEcuLockStTyp, MonEngStrt_B.VEMS_vidGET3_p);

  /* S-Function "vems_vidGET" Block: <S7>/VEMS_vidGET4 */
  VEMS_vidGET(Moteur_synchronise, MonEngStrt_B.VEMS_vidGET4_b);

  /* S-Function "vems_vidGET" Block: <S7>/VEMS_vidGET5 */
  VEMS_vidGET(Vehicle_active_state, MonEngStrt_B.VEMS_vidGET5_c);

  /* SignalConversion: '<S7>/Signal Conversion8' */
  MonEngStrt_B.SignalConversion8_m = EngSt_bMonEngStrtEnd;

  /* S-Function "vems_vidGET" Block: <S7>/VEMS_vidGET7 */
  VEMS_vidGET(Ctrl_bAcv_PFuAcq, MonEngStrt_B.VEMS_vidGET7_i);

  /* S-Function "vems_vidGET" Block: <S7>/VEMS_vidGET8 */
  VEMS_vidGET(InjSys_bDetPFuThdInjHPst, MonEngStrt_B.VEMS_vidGET8_f);

  /* SignalConversion: '<S7>/Signal Conversion9' incorporates:
   *  Inport: '<Root>/FRM_bInhMonEngStrt'
   */
  MonEngStrt_B.SignalConversion9_b = GDGAR_bGetFRM(FRM_FRM_INHMONENGSTRT);

  /* Outputs for atomic SubSystem: '<S7>/F00_autorisationDiag' */
  MonEngStrt_F00_autorisationDiag(MonEngStrt_B.VEMS_vidGET2_k,
    MonEngStrt_B.SignalConversion7_c, MonEngStrt_B.VEMS_vidGET3_p,
    MonEngStrt_B.VEMS_vidGET4_b, MonEngStrt_B.VEMS_vidGET5_c,
    MonEngStrt_B.SignalConversion8_m, MonEngStrt_B.VEMS_vidGET7_i,
    MonEngStrt_B.VEMS_vidGET8_f, MonEngStrt_B.SignalConversion9_b,
    &MonEngStrt_B.F00_autorisationDiag, &MonEngStrt_DWork.F00_autorisationDiag);

  /* end of Outputs for SubSystem: '<S7>/F00_autorisationDiag' */

  /* SignalConversion: '<S7>/Signal Conversion1' */
  EngSt_tiDlyPFuMin = MonEngStrt_B.F00_autorisationDiag.EngSt_tiDlyPFuMin_a;

  /* SignalConversion: '<S7>/Signal Conversion2' */
  EngSt_tiDlyUnlockADC =
    MonEngStrt_B.F00_autorisationDiag.EngSt_tiDlyUnlockADC_p;

  /* SignalConversion: '<S7>/Signal Conversion3' */
  EngSt_bAcvStrtDiag = MonEngStrt_B.F00_autorisationDiag.EngSt_bAcvStrtDiag_k;

  /* SignalConversion: '<S7>/Signal Conversion4' */
  EngSt_tiDlyStrt = MonEngStrt_B.F00_autorisationDiag.EngSt_tiDlyStrt_j;

  /* SignalConversion: '<S7>/Signal Conversion5' */
  EngSt_bMonWaitORngEngSt =
    MonEngStrt_B.F00_autorisationDiag.EngSt_bMonWaitORngEngSt_m;

  /* S-Function "vems_vidSET" Block: <S7>/VEMS_vidSET2 */
  VEMS_vidSET(EngSt_tiDlySync,
              MonEngStrt_B.F00_autorisationDiag.EngSt_tiDlySync_j);
}

/* Output and update for function-call system: '<S1>/F00_Init' */
void MonEngStrt_F00_Init(void)
{
  /* NVRAM Read for EBDT Block <S4>/EepromReadAccess */
  VEMS_vidGET(Flev_fuel_level_in_eep, MonEngStrt_B.EepromReadAccess);

  /* SignalConversion: '<S4>/Signal Conversion' */
  EngSt_volFuInit = MonEngStrt_B.EepromReadAccess;

  /* S-Function "vems_vidGET" Block: <S4>/VEMS_vidGET */
  VEMS_vidGET(Tension_batterie_brute, MonEngStrt_B.VEMS_vidGET);

  /* SignalConversion: '<S4>/Signal Conversion1' */
  EngSt_uBattInit = MonEngStrt_B.VEMS_vidGET;

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(EngSt_bStrtDiagCf, EngSt_bStrtDiagCf_C);
}

/* Initial conditions for exported function: EngSt_EveRst_MonEngStrt */
void EngSt_EveRst_MonEngStrt_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/demux_fc2'
   */
}

/* Start for exported function: EngSt_EveRst_MonEngStrt */
void EngSt_EveRst_MonEngStrt_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc2'
   */

  /* Start for S-Function (fcncallgen): '<S14>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F00_Init'
   *  Start for SubSystem: '<S1>/F02_autorisationDiag_Rst'
   *
   * Block requirements for '<S1>/F00_Init':
   *  1. SubSystem "F00_Init" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  2. SubSystem "F00_Init" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  3. SubSystem "F00_Init" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  4. SubSystem "F00_Init" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/F02_autorisationDiag_Rst':
   *  1. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_004.01 ;
   *  2. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_005.01 ;
   *  3. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_006.01 ;
   *  4. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_007.02 ;
   *  5. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_008.02 ;
   *  6. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_015.01 ;
   *  7. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_016.01 ;
   *  8. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_019.01 ;
   *  9. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  10. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  11. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  12. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_014.01 ;
   */
}

/* Output and update for exported function: EngSt_EveRst_MonEngStrt */
void EngSt_EveRst_MonEngStrt(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc2'
   */

  /* S-Function (fcncallgen): '<S14>/gen' incorporates:
   *  SubSystem: '<S1>/F00_Init'
   *  SubSystem: '<S1>/F02_autorisationDiag_Rst'
   *
   * Block requirements for '<S1>/F00_Init':
   *  1. SubSystem "F00_Init" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  2. SubSystem "F00_Init" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  3. SubSystem "F00_Init" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  4. SubSystem "F00_Init" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/F02_autorisationDiag_Rst':
   *  1. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_004.01 ;
   *  2. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_005.01 ;
   *  3. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_006.01 ;
   *  4. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_007.02 ;
   *  5. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_008.02 ;
   *  6. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_015.01 ;
   *  7. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_016.01 ;
   *  8. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_019.01 ;
   *  9. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  10. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  11. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  12. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_014.01 ;
   */
  MonEng_F02_autorisationDiag_Rst();
  MonEngStrt_F00_Init();
}

/* Output and update for function-call system: '<S1>/F01_CmdCranking' */
void MonEngStrt_F01_CmdCranking(void)
{
  Boolean localRelationalOperator1;

  /* Outputs for enable SubSystem: '<S5>/F00_CmdCranking' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/MONENGSTRT_u8Inhib'
   *  EnablePort: '<S15>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (MONENGSTRT_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET1 */
    VEMS_vidGET(Tension_batterie_brute, MonEngStrt_B.VEMS_vidGET1_l);

    /* RelationalOperator: '<S15>/Relational Operator1' incorporates:
     *  Constant: '<S15>/EngSt_uBattThdCmdCrk_C'
     */
    localRelationalOperator1 = (MonEngStrt_B.VEMS_vidGET1_l <
      EngSt_uBattThdCmdCrk_C);

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET */
    VEMS_vidGET(Dml_cmd_cranking, MonEngStrt_B.VEMS_vidGET_k);

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Dml_cmd_cranking_manu_inh'
     */
    if (Dml_cmd_cranking_manu_inh) {
      EngSt_bCmdCranking = localRelationalOperator1;
    } else {
      EngSt_bCmdCranking = MonEngStrt_B.VEMS_vidGET_k;
    }
  }

  /* end of Outputs for SubSystem: '<S5>/F00_CmdCranking' */
}

/* Output and update for function-call system: '<S1>/F02_autorisationDiag_Fast' */
void MonEn_F02_autorisationDiag_Fast(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_c;

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/MONENGSTRT_u8Inhib'
   */
  localRelationalOperator_c = (MONENGSTRT_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S6>/F00_autorisationDiag_Fast' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (localRelationalOperator_c) {
    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET2 */
    VEMS_vidGET(First_crank, MonEngStrt_B.VEMS_vidGET2_b);

    /* SignalConversion: '<S16>/Signal Conversion7' */
    MonEngStrt_B.SignalConversion7 = EngSt_bCmdCranking;

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET3 */
    VEMS_vidGET(IMMO_stEcuLockStTyp, MonEngStrt_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET4 */
    VEMS_vidGET(Moteur_synchronise, MonEngStrt_B.VEMS_vidGET4_e);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET5 */
    VEMS_vidGET(Vehicle_active_state, MonEngStrt_B.VEMS_vidGET5);

    /* SignalConversion: '<S16>/Signal Conversion8' */
    MonEngStrt_B.SignalConversion8 = EngSt_bMonEngStrtEnd;

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET7 */
    VEMS_vidGET(Ctrl_bAcv_PFuAcq, MonEngStrt_B.VEMS_vidGET7_m);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_bDetPFuThdInjHPst, MonEngStrt_B.VEMS_vidGET8_b);

    /* SignalConversion: '<S16>/Signal Conversion9' incorporates:
     *  Inport: '<Root>/FRM_bInhMonEngStrt'
     */
    MonEngStrt_B.SignalConversion9 = GDGAR_bGetFRM(FRM_FRM_INHMONENGSTRT);

    /* Outputs for atomic SubSystem: '<S16>/F00_autorisationDiag' */
    MonEngStrt_F00_autorisationDiag(MonEngStrt_B.VEMS_vidGET2_b,
      MonEngStrt_B.SignalConversion7, MonEngStrt_B.VEMS_vidGET3,
      MonEngStrt_B.VEMS_vidGET4_e, MonEngStrt_B.VEMS_vidGET5,
      MonEngStrt_B.SignalConversion8, MonEngStrt_B.VEMS_vidGET7_m,
      MonEngStrt_B.VEMS_vidGET8_b, MonEngStrt_B.SignalConversion9,
      &MonEngStrt_B.F00_autorisationDiag_a,
      &MonEngStrt_DWork.F00_autorisationDiag_a);

    /* end of Outputs for SubSystem: '<S16>/F00_autorisationDiag' */

    /* SignalConversion: '<S16>/Signal Conversion1' */
    EngSt_tiDlyPFuMin = MonEngStrt_B.F00_autorisationDiag_a.EngSt_tiDlyPFuMin_a;

    /* SignalConversion: '<S16>/Signal Conversion2' */
    EngSt_tiDlyUnlockADC =
      MonEngStrt_B.F00_autorisationDiag_a.EngSt_tiDlyUnlockADC_p;

    /* SignalConversion: '<S16>/Signal Conversion3' */
    EngSt_bAcvStrtDiag =
      MonEngStrt_B.F00_autorisationDiag_a.EngSt_bAcvStrtDiag_k;

    /* SignalConversion: '<S16>/Signal Conversion4' */
    EngSt_tiDlyStrt = MonEngStrt_B.F00_autorisationDiag_a.EngSt_tiDlyStrt_j;

    /* SignalConversion: '<S16>/Signal Conversion5' */
    EngSt_bMonWaitORngEngSt =
      MonEngStrt_B.F00_autorisationDiag_a.EngSt_bMonWaitORngEngSt_m;

    /* S-Function "vems_vidSET" Block: <S16>/VEMS_vidSET2 */
    VEMS_vidSET(EngSt_tiDlySync,
                MonEngStrt_B.F00_autorisationDiag_a.EngSt_tiDlySync_j);
  }

  /* end of Outputs for SubSystem: '<S6>/F00_autorisationDiag_Fast' */
}

/* Output and update for function-call system: '<S1>/F03_Diagnostic' */
void MonEngStrt_F03_Diagnostic(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_cy;
  Boolean localOU2_d;
  Float32 localExt_tCoMes_EngSt_bkptTcoSt;
  Float32 localfractionTmp_0d;
  UInt32 localExt_tCoMes_EngSt_bkptTco_e;
  Float32 localAdd2;
  Boolean localLogicalOperator1_b;
  Boolean localLogicalOperator3;
  UInt16 localtmp;
  SInt32 localtmp_0;
  UInt8 locallocalDataTypeConversion;

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/MONENGSTRT_u8Inhib'
   */
  localRelationalOperator_cy = (MONENGSTRT_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S8>/F00_Diagnostic' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (localRelationalOperator_cy) {
    /* S-Function "vems_vidGET" Block: <S21>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_tCoMes, MonEngStrt_B.VEMS_vidGET2);

    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    localtmp_0 = MonEngStrt_B.VEMS_vidGET2 + 50;
    if (localtmp_0 <= 0) {
      locallocalDataTypeConversion = 0U;
    } else if (localtmp_0 > 255) {
      locallocalDataTypeConversion = MAX_uint8_T;
    } else {
      locallocalDataTypeConversion = (UInt8)localtmp_0;
    }

    /* S-Function "vems_vidGET" Block: <S21>/VEMS_vidGET7 */
    VEMS_vidGET(Flev_low_fuel_level, MonEngStrt_B.VEMS_vidGET7);

    /* PreLookup: '<S24>/Prelookup' */
    localExt_tCoMes_EngSt_bkptTco_e = plook_u32u8f_binc
      (locallocalDataTypeConversion, (&(EngSt_bkptTcoStrt_A[0])), 5U,
       &localExt_tCoMes_EngSt_bkptTcoSt);

    /* S-Function "vems_vidGET" Block: <S21>/VEMS_vidGET9 */
    VEMS_vidGET(Vehicle_active_state, MonEngStrt_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S21>/VEMS_vidGET4 */
    VEMS_vidGET(EngSt_bStrtDiagCf, MonEngStrt_B.VEMS_vidGET4);

    /* Outputs for atomic SubSystem: '<S21>/F00_Cdn' */

    /* Logic: '<S22>/OU2' */
    localOU2_d = !MonEngStrt_B.VEMS_vidGET7;

    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/EngSt_volFuInitMin_C'
     *  Logic: '<S22>/Logical Operator2'
     *  RelationalOperator: '<S22>/Relational Operator3'
     */
    if (MonEngStrt_B.VEMS_vidGET4) {
      EngSt_bFuLvlOK = ((EngSt_volFuInit > EngSt_volFuInitMin_C) && (localOU2_d));
    } else {
      EngSt_bFuLvlOK = localOU2_d;
    }

    /* Interpolation_n-D: '<S25>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_tCoMes_EngSt_bkptTcoSt;
    localfractionTmp_0d = intrp1d_iu16n7ff_u32f_l_ns
      (localExt_tCoMes_EngSt_bkptTco_e, localfractionTmp_0d,
       (&(EngSt_tiStrtLim_T[0])));

    /* Logic: '<S22>/Logical Operator1' incorporates:
     *  Constant: '<S22>/VS_RUNNING'
     *  Constant: '<S26>/offset'
     *  Constant: '<S26>/offset1'
     *  Constant: '<S26>/one_on_slope'
     *  DataTypeConversion: '<S26>/OutDTConv'
     *  Product: '<S26>/Product4'
     *  RelationalOperator: '<S22>/Relational Operator1'
     *  RelationalOperator: '<S22>/Relational Operator2'
     *  Sum: '<S26>/Add1'
     *  Sum: '<S26>/Add2'
     */
    localAdd2 = (100.0F * localfractionTmp_0d) + 0.5F;
    if (localAdd2 < 65536.0F) {
      if (localAdd2 >= 0.0F) {
        localtmp = (UInt16)localAdd2;
      } else {
        localtmp = 0U;
      }
    } else {
      localtmp = MAX_uint16_T;
    }

    EngSt_bMonEngStrtEnd = ((EngSt_tiDlyStrt > localtmp) &&
      (MonEngStrt_B.VEMS_vidGET9 != VS_RUNNING));

    /* end of Outputs for SubSystem: '<S21>/F00_Cdn' */
    /* S-Function "vems_vidGET" Block: <S21>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_nEng, MonEngStrt_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S21>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_bAcvHPst, MonEngStrt_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S21>/VEMS_vidGET */
    VEMS_vidGET(Ctrl_bAcv_PFuAcq, MonEngStrt_B.VEMS_vidGET_d);

    /* S-Function "vems_vidGET" Block: <S21>/VEMS_vidGET3 */
    VEMS_vidGET(EngSt_tiDlySync, MonEngStrt_B.VEMS_vidGET3_h);

    /* Outputs for atomic SubSystem: '<S21>/F01_Diagnostic' *
     * Block requirements for '<S21>/F01_Diagnostic':
     *  1. SubSystem "F01_Diagnostic" !Trace_To : VEMS_R_09_06162_009.02 ;
     *  2. SubSystem "F01_Diagnostic" !Trace_To : VEMS_E_09_06162_017.01 ;
     */

    /* Outputs for atomic SubSystem: '<S23>/F01_MonRunADC' *
     * Block requirements for '<S23>/F01_MonRunADC':
     *  1. SubSystem "F01_MonRunADC" !Trace_To : VEMS_R_09_06162_010.02 ;
     */

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/EngSt_nEngUnlockADCLim_C'
     *  Inport: '<Root>/FRM_bInhStrtDiagADC'
     *  Logic: '<S27>/Logical Operator'
     *  Logic: '<S27>/OU1'
     *  RelationalOperator: '<S27>/Relational Operator1'
     */
    if (MonEngStrt_B.VEMS_vidGET4) {
      EngSt_bMonRunORngUnlockEngSt = (((MonEngStrt_B.VEMS_vidGET1 >
        EngSt_nEngUnlockADCLim_C) && (!GDGAR_bGetFRM(FRM_FRM_INHSTRTDIAGADC))) &&
        EngSt_bAcvStrtDiag);
    } else {
      EngSt_bMonRunORngUnlockEngSt = EngSt_bAcvStrtDiag;
    }

    /* end of Outputs for SubSystem: '<S23>/F01_MonRunADC' */

    /* Outputs for atomic SubSystem: '<S23>/F01_MonRunStrt' */

    /* Logic: '<S28>/Logical Operator' */
    EngSt_bMonRunORngStrtEngSt = (EngSt_bFuLvlOK && EngSt_bAcvStrtDiag);

    /* end of Outputs for SubSystem: '<S23>/F01_MonRunStrt' */

    /* Outputs for atomic SubSystem: '<S23>/F02_MonRunSync' *
     * Block requirements for '<S23>/F02_MonRunSync':
     *  1. SubSystem "F02_MonRunSync" !Trace_To : VEMS_R_09_06162_011.02 ;
     */

    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/EngSt_nEngSyncLim_C'
     *  Constant: '<S29>/EngSt_uBattSyncLim_C'
     *  Inport: '<Root>/FRM_bInhStrtDiagSync'
     *  Logic: '<S29>/Logical Operator1'
     *  Logic: '<S29>/OU1'
     *  RelationalOperator: '<S29>/Relational Operator2'
     *  RelationalOperator: '<S29>/Relational Operator4'
     */
    if (MonEngStrt_B.VEMS_vidGET4) {
      EngSt_bMonRunORngSyncEngSt = ((((MonEngStrt_B.VEMS_vidGET1 >
        EngSt_nEngSyncLim_C) && (EngSt_uBattInit > EngSt_uBattSyncLim_C)) &&
        (!GDGAR_bGetFRM(FRM_FRM_INHSTRTDIAGSYNC))) && EngSt_bAcvStrtDiag);
    } else {
      EngSt_bMonRunORngSyncEngSt = EngSt_bAcvStrtDiag;
    }

    /* end of Outputs for SubSystem: '<S23>/F02_MonRunSync' */

    /* Outputs for atomic SubSystem: '<S23>/F03_MonRunPFu' *
     * Block requirements for '<S23>/F03_MonRunPFu':
     *  1. SubSystem "F03_MonRunPFu" !Trace_To : VEMS_R_09_06162_018.01 ;
     */

    /* Logic: '<S30>/Logical Operator1' incorporates:
     *  Constant: '<S30>/EngSt_nEngPFuLim_C'
     *  Constant: '<S30>/EngSt_uBattPFuLim_C'
     *  Inport: '<Root>/FRM_bInhStrtDiagPFu'
     *  Logic: '<S30>/OU1'
     *  RelationalOperator: '<S30>/Relational Operator2'
     *  RelationalOperator: '<S30>/Relational Operator4'
     */
    EngSt_bMonRunORngPFuEngSt = ((((((((MonEngStrt_B.VEMS_vidGET1 >
      EngSt_nEngPFuLim_C) && (EngSt_uBattInit > EngSt_uBattPFuLim_C)) &&
      EngSt_bFuLvlOK) && MonEngStrt_B.VEMS_vidGET8) &&
      MonEngStrt_B.VEMS_vidGET_d) && (!GDGAR_bGetFRM(FRM_FRM_INHSTRTDIAGPFU))) &&
      EngSt_bAcvStrtDiag) && MonEngStrt_B.VEMS_vidGET4);

    /* end of Outputs for SubSystem: '<S23>/F03_MonRunPFu' */

    /* Outputs for enable SubSystem: '<S23>/F04_DgoStrtDiag' incorporates:
     *  EnablePort: '<S31>/Enable'
     *  Logic: '<S23>/Logical Operator'
     *  Logic: '<S23>/Logical Operator1'
     *  Logic: '<S23>/OU1'
     *
     * Block requirements for '<S23>/F04_DgoStrtDiag':
     *  1. SubSystem "F04_DgoStrtDiag" !Trace_To : VEMS_R_09_06162_012.02 ;
     */
    if (MonEngStrt_B.VEMS_vidGET4 || (EngSt_bAcvStrtDiag &&
         (!EngSt_bMonWaitORngEngSt))) {
      /* Interpolation_n-D: '<S32>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_tCoMes_EngSt_bkptTcoSt;
      localAdd2 = intrp1d_iu16n7ff_u32f_l_ns(localExt_tCoMes_EngSt_bkptTco_e,
        localfractionTmp_0d, (&(EngSt_tiSyncLim_T[0])));

      /* Interpolation_n-D: '<S33>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_tCoMes_EngSt_bkptTcoSt;
      localfractionTmp_0d = intrp1d_iu16n7ff_u32f_l_ns
        (localExt_tCoMes_EngSt_bkptTco_e, localfractionTmp_0d,
         (&(EngSt_tiPFuMinLim_T[0])));

      /* Logic: '<S31>/Logical Operator' incorporates:
       *  Constant: '<S31>/EngSt_tiUnlockADCLim_C'
       *  RelationalOperator: '<S31>/Relational Operator'
       */
      localOU2_d = ((EngSt_bMonRunORngUnlockEngSt && EngSt_bMonEngStrtEnd) &&
                    (EngSt_tiDlyUnlockADC > EngSt_tiUnlockADCLim_C));

      /* Logic: '<S31>/Logical Operator1' incorporates:
       *  Constant: '<S34>/offset'
       *  Constant: '<S34>/offset1'
       *  Constant: '<S34>/one_on_slope'
       *  DataTypeConversion: '<S34>/OutDTConv'
       *  Product: '<S34>/Product4'
       *  RelationalOperator: '<S31>/Relational Operator3'
       *  Sum: '<S34>/Add1'
       *  Sum: '<S34>/Add2'
       */
      localAdd2 = (100.0F * localAdd2) + 0.5F;
      if (localAdd2 < 65536.0F) {
        if (localAdd2 >= 0.0F) {
          localtmp = (UInt16)localAdd2;
        } else {
          localtmp = 0U;
        }
      } else {
        localtmp = MAX_uint16_T;
      }

      localLogicalOperator1_b = ((EngSt_bMonRunORngSyncEngSt &&
        EngSt_bMonEngStrtEnd) && (MonEngStrt_B.VEMS_vidGET3_h > localtmp));

      /* Logic: '<S31>/Logical Operator3' incorporates:
       *  Constant: '<S35>/offset'
       *  Constant: '<S35>/offset1'
       *  Constant: '<S35>/one_on_slope'
       *  DataTypeConversion: '<S35>/OutDTConv'
       *  Product: '<S35>/Product4'
       *  RelationalOperator: '<S31>/Relational Operator1'
       *  Sum: '<S35>/Add1'
       *  Sum: '<S35>/Add2'
       */
      localAdd2 = (100.0F * localfractionTmp_0d) + 0.5F;
      if (localAdd2 < 65536.0F) {
        if (localAdd2 >= 0.0F) {
          localtmp = (UInt16)localAdd2;
        } else {
          localtmp = 0U;
        }
      } else {
        localtmp = MAX_uint16_T;
      }

      localLogicalOperator3 = ((EngSt_bMonRunORngPFuEngSt &&
        EngSt_bMonEngStrtEnd) && (EngSt_tiDlyPFuMin > localtmp));

      /* Logic: '<S31>/Logical Operator2' incorporates:
       *  Logic: '<S31>/OU1'
       *  Logic: '<S31>/OU2'
       *  Logic: '<S31>/OU3'
       */
      EngSt_bDgoORngStrtEngSt = ((((EngSt_bMonRunORngStrtEngSt &&
        EngSt_bMonEngStrtEnd) && (!localOU2_d)) && (!localLogicalOperator1_b)) &&
                                 (!localLogicalOperator3));

      /* SignalConversion: '<S31>/Signal Conversion1' */
      EngSt_bDgoORngUnlockEngSt = localOU2_d;

      /* SignalConversion: '<S31>/Signal Conversion2' */
      EngSt_bDgoORngPFuEngSt = localLogicalOperator3;

      /* SignalConversion: '<S31>/Signal Conversion4' */
      EngSt_bDgoORngSyncEngSt = localLogicalOperator1_b;
    }

    /* end of Outputs for SubSystem: '<S23>/F04_DgoStrtDiag' */

    /* end of Outputs for SubSystem: '<S21>/F01_Diagnostic' */
  }

  /* end of Outputs for SubSystem: '<S8>/F00_Diagnostic' */
}

/* Start for exported function: EngSt_SdlFast_MonEngStrt */
void EngSt_SdlFast_MonEngStrt_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   */

  /* Start for S-Function (fcncallgen): '<S13>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F01_CmdCranking'
   *  Start for SubSystem: '<S1>/F02_autorisationDiag_Fast'
   *  Start for SubSystem: '<S1>/F03_Diagnostic'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu1'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu2'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu3'
   *
   * Block requirements for '<S1>/F01_CmdCranking':
   *  1. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_003.01 ;
   *  2. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  3. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  4. SubSystem "F01_CmdCranking" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  5. SubSystem "F01_CmdCranking" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/F02_autorisationDiag_Fast':
   *  1. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_004.01 ;
   *  2. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_005.01 ;
   *  3. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_006.01 ;
   *  4. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_007.02 ;
   *  5. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_008.02 ;
   *  6. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_015.01 ;
   *  7. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_016.01 ;
   *  8. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_019.01 ;
   *  9. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  10. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  11. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  12. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/F03_Diagnostic':
   *  1. SubSystem "F03_Diagnostic" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  2. SubSystem "F03_Diagnostic" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  3. SubSystem "F03_Diagnostic" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  4. SubSystem "F03_Diagnostic" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu':
   *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  2. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  3. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  4. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu1':
   *  1. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  2. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_E_09_06162_014.01 ;
   *  3. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  4. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_R_09_06162_002.02 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu2':
   *  1. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  2. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  3. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  4. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu3':
   *  1. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  2. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_E_09_06162_014.01 ;
   *  3. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  4. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_R_09_06162_002.02 ;
   */
}

/* Output and update for exported function: EngSt_SdlFast_MonEngStrt */
void EngSt_SdlFast_MonEngStrt(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S13>/gen' incorporates:
   *  SubSystem: '<S1>/F01_CmdCranking'
   *  SubSystem: '<S1>/F02_autorisationDiag_Fast'
   *  SubSystem: '<S1>/F03_Diagnostic'
   *  SubSystem: '<S1>/GDGAR_vidGdu'
   *  SubSystem: '<S1>/GDGAR_vidGdu1'
   *  SubSystem: '<S1>/GDGAR_vidGdu2'
   *  SubSystem: '<S1>/GDGAR_vidGdu3'
   *
   * Block requirements for '<S1>/F01_CmdCranking':
   *  1. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_003.01 ;
   *  2. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  3. SubSystem "F01_CmdCranking" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  4. SubSystem "F01_CmdCranking" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  5. SubSystem "F01_CmdCranking" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/F02_autorisationDiag_Fast':
   *  1. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_004.01 ;
   *  2. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_005.01 ;
   *  3. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_006.01 ;
   *  4. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_007.02 ;
   *  5. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_008.02 ;
   *  6. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_015.01 ;
   *  7. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_016.01 ;
   *  8. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_019.01 ;
   *  9. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  10. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  11. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  12. SubSystem "F02_autorisationDiag" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/F03_Diagnostic':
   *  1. SubSystem "F03_Diagnostic" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  2. SubSystem "F03_Diagnostic" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  3. SubSystem "F03_Diagnostic" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  4. SubSystem "F03_Diagnostic" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu':
   *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  2. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  3. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  4. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu1':
   *  1. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  2. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_E_09_06162_014.01 ;
   *  3. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  4. SubSystem "GDGAR_vidGdu1" !Trace_To : VEMS_R_09_06162_002.02 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu2':
   *  1. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  2. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_R_09_06162_002.02 ;
   *  3. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  4. SubSystem "GDGAR_vidGdu2" !Trace_To : VEMS_E_09_06162_014.01 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu3':
   *  1. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_E_09_06162_013.01 ;
   *  2. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_E_09_06162_014.01 ;
   *  3. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_R_09_06162_001.02 ;
   *  4. SubSystem "GDGAR_vidGdu3" !Trace_To : VEMS_R_09_06162_002.02 ;
   */
  MonEngStrt_F01_CmdCranking();
  MonEn_F02_autorisationDiag_Fast();
  MonEngStrt_F03_Diagnostic();

  /* Outputs for atomic SubSystem: '<S9>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S36>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGUNLOCKENGST, EngSt_bDgoORngUnlockEngSt,
               EngSt_bMonRunORngUnlockEngSt, EngSt_bMonWaitORngEngSt);

  /* end of Outputs for SubSystem: '<S9>/GDGAR_vidGdu' */

  /* Outputs for atomic SubSystem: '<S10>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S37>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGSYNCENGST, EngSt_bDgoORngSyncEngSt,
               EngSt_bMonRunORngSyncEngSt, EngSt_bMonWaitORngEngSt);

  /* end of Outputs for SubSystem: '<S10>/GDGAR_vidGdu' */

  /* Outputs for atomic SubSystem: '<S11>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S38>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGPFUENGST, EngSt_bDgoORngPFuEngSt,
               EngSt_bMonRunORngPFuEngSt, EngSt_bMonWaitORngEngSt);

  /* end of Outputs for SubSystem: '<S11>/GDGAR_vidGdu' */

  /* Outputs for atomic SubSystem: '<S12>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S39>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNGSTRTENGST, EngSt_bDgoORngStrtEngSt,
               EngSt_bMonRunORngStrtEngSt, EngSt_bMonWaitORngEngSt);

  /* end of Outputs for SubSystem: '<S12>/GDGAR_vidGdu' */
}

/* Model initialize function */
void MonEngStrt_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  EngSt_EveRst_MonEngStrt_Start();
  EngSt_SdlFast_MonEngStrt_Start();

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   */
  EngSt_EveRst_MonEngStrt_Init();
}

#define MONENGSTRT_STOP_SEC_CODE
#include "MonEngStrt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
