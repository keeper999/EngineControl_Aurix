/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : DCM_MANU_ACTUATOR_TST_MNG.c                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DCM_MANU_EveRst_ActrTstRc                                            */
/*   2 / DCM_MANU_EveAckActrTstDmd                                            */
/*   3 / DCM_MANU_EveSessChg_ActrTstRc                                        */
/*   4 / DCM_MANU_StartActuatorTst                                            */
/*   5 / DCM_MANU_StopActuatorTst                                             */
/*   6 / DCM_MANU_ReqResActuatorTst                                           */
/*   7 / DCM_MANU_ActTstStateMachineTransition                                */
/*   8 / DCM_MANU_ActuatorTestCheckCond                                       */
/*   9 / DCM_MANU_ActTstResAnalyse                                            */
/*   10 / DCM_MANU_Start_Rc_Acttest_Factor_Mngmt                              */
/*   11 / DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt                      */
/*   12 / DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5074350 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveRst_ActrTstRc                                  */
/* !Description :  Evènement reset pour les tests actionneur.                 */
/* !Number      :  ACTUATOR_TST_MNG.1                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DCM_MANU_EveSessChg_ActrTstRc();                         */
/*  output uint8 Srv_stActrTstCode;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveRst_ActrTstRc(void)
{
   /* Outputs Variables */
   VEMS_vidSET(Srv_stActrTstCode, 0);
   DCM_MANU_EveSessChg_ActrTstRc();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveAckActrTstDmd                                  */
/* !Description :  Fonction appelée par Srv_EveAckActrTstDmd_ActrTstMn.       */
/* !Number      :  ACTUATOR_TST_MNG.2                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Srv_bActrTstDmd;                                           */
/*  output boolean Srv_bActrTstDmdWithCndVld;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveAckActrTstDmd(void)
{
   VEMS_vidSET(Srv_bActrTstDmd, FALSE);
   VEMS_vidSET(Srv_bActrTstDmdWithCndVld, FALSE);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_EveSessChg_ActrTstRc                              */
/* !Description :  Evènement informant les tests actionneurs que la session a */
/*                 changé?                                                    */
/* !Number      :  ACTUATOR_TST_MNG.3                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_EveAckActrTstDmd();                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Srv_bActrTstRunning;                                       */
/*  output boolean Srv_bActrTstStop;                                          */
/*  output uint8 Srv_stActrTstCodePrev;                                       */
/*  output uint8 Srv_stRcActrTst;                                             */
/*  output boolean Srv_bRcStart_ActrTst;                                      */
/*  output boolean Srv_bRcStop_ActrTst;                                       */
/*  output boolean Srv_bRcReq_ActrTst;                                        */
/*  output uint8 DCM_MANU_CodeTestBobine_prev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_EveSessChg_ActrTstRc(void)
{
   /* Outputs Variables */
   DCM_MANU_EveAckActrTstDmd();
   VEMS_vidSET(Srv_bActrTstRunning, FALSE);
   VEMS_vidSET(Srv_bActrTstStop, TRUE);
   /* Locals Variables */
   Srv_stActrTstCodePrev = 0;
   Srv_stRcActrTst = RC_WAITING;
   Srv_bRcStart_ActrTst = FALSE;
   Srv_bRcStop_ActrTst = FALSE;
   Srv_bRcReq_ActrTst = FALSE;
   DCM_MANU_CodeTestBobine_prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_StartActuatorTst                                  */
/* !Description :  Evenement interne pour avertir le manager qu'une demande de*/
/*                 démarrage d'un test donné a éé reçu.                       */
/* !Number      :  ACTUATOR_TST_MNG.4                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DCM_MANU_ActTstStateMachineTransition();                 */
/*  extf argret Std_ReturnType  DCM_MANU_ActTstResAnalyse(argin uint8         */
/* *ErrorCodeOut, argin uint8 *RoutineStatusOut, argin uint8 *OutputParam);   */
/*  output uint8 Srv_stActrTstCode;                                           */
/*  output boolean Srv_bRcStart_ActrTst;                                      */
/*  output boolean Srv_bRcStop_ActrTst;                                       */
/*  output boolean Srv_bRcReq_ActrTst;                                        */
/*  output uint8 Srv_stRcActrTst;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_StartActuatorTst
(
   uint8 code_test_in,
   uint8* ErrorCodeOut,
   uint8* RoutineStatusOut,
   uint8* OutputParam
)
{
   uint8 u8LocalReturn;

   /* Psitionnement des variables */
   VEMS_vidSET(Srv_stActrTstCode, code_test_in);
   Srv_bRcStart_ActrTst = TRUE;
   Srv_bRcStop_ActrTst = FALSE;
   Srv_bRcReq_ActrTst = FALSE;
   Srv_stRcActrTst = RC_WAITING;

   /* Lancement de la machine d'état */
   DCM_MANU_ActTstStateMachineTransition();

   /* Analyse du résultat */
   u8LocalReturn = DCM_MANU_ActTstResAnalyse( ErrorCodeOut,
                                              RoutineStatusOut,
                                              OutputParam );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_StopActuatorTst                                   */
/* !Description :  Fonction appelée lors de la réception de la sous fonction  */
/*                 stop routine                                               */
/* !Number      :  ACTUATOR_TST_MNG.5                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DCM_MANU_ActTstStateMachineTransition();                 */
/*  extf argret Std_ReturnType  DCM_MANU_ActTstResAnalyse(argin uint8         */
/* *ErrorCodeOut, argin uint8 *RoutineStatusOut, argin uint8 *OutputParam);   */
/*  output uint8 Srv_stActrTstCode;                                           */
/*  output boolean Srv_bRcStart_ActrTst;                                      */
/*  output boolean Srv_bRcStop_ActrTst;                                       */
/*  output boolean Srv_bRcReq_ActrTst;                                        */
/*  output uint8 Srv_stRcActrTst;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_StopActuatorTst
(
   uint8 code_test_in,
   uint8* ErrorCodeOut,
   uint8* RoutineStatusOut,
   uint8* OutputParam
)
{
   uint8 u8LocalReturn;

   /* Psitionnement des variables */
   VEMS_vidSET(Srv_stActrTstCode, code_test_in);
   Srv_bRcStart_ActrTst = FALSE;
   Srv_bRcStop_ActrTst = TRUE;
   Srv_bRcReq_ActrTst = FALSE;
   Srv_stRcActrTst = RC_WAITING;

   /* Lancement de la machine d'état */
   DCM_MANU_ActTstStateMachineTransition();

   /* Analyse du résultat */
   u8LocalReturn = DCM_MANU_ActTstResAnalyse( ErrorCodeOut,
                                              RoutineStatusOut,
                                              OutputParam );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_ReqResActuatorTst                                 */
/* !Description :  Fonction appelée lors de la réception d'une sous fonction  */
/*                 Request Result.                                            */
/* !Number      :  ACTUATOR_TST_MNG.6                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DCM_MANU_ActTstStateMachineTransition();                 */
/*  extf argret Std_ReturnType  DCM_MANU_ActTstResAnalyse(argin uint8         */
/* *ErrorCodeOut, argin uint8 *RoutineStatusOut, argin uint8 *OutputParam);   */
/*  output uint8 Srv_stActrTstCode;                                           */
/*  output boolean Srv_bRcStart_ActrTst;                                      */
/*  output boolean Srv_bRcStop_ActrTst;                                       */
/*  output boolean Srv_bRcReq_ActrTst;                                        */
/*  output uint8 Srv_stRcActrTst;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_ReqResActuatorTst
(
   uint8 code_test_in,
   uint8* ErrorCodeOut,
   uint8* RoutineStatusOut,
   uint8* OutputParam
)
{
   uint8 u8LocalReturn;

   /* Psitionnement des variables */
   VEMS_vidSET(Srv_stActrTstCode, code_test_in);
   Srv_bRcStart_ActrTst = FALSE;
   Srv_bRcStop_ActrTst = FALSE;
   Srv_bRcReq_ActrTst = TRUE;
   Srv_stRcActrTst = RC_WAITING;

   /* Lancement de la machine d'état */
   DCM_MANU_ActTstStateMachineTransition();

   /* Analyse du résultat */
   u8LocalReturn = DCM_MANU_ActTstResAnalyse( ErrorCodeOut,
                                              RoutineStatusOut,
                                              OutputParam );

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_ActTstStateMachineTransition                      */
/* !Description :  Evènement pilotant la machine d'état des tests actionneurs */
/*                 côté com.                                                  */
/* !Number      :  ACTUATOR_TST_MNG.7                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret boolean  DCM_MANU_ActuatorTestCheckCond(argin uint8           */
/* u8TstCode_par);                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Srv_stActrTstCode;                                            */
/*  input st92 Srv_stActrTstStatus;                                           */
/*  input boolean Srv_bRcStart_ActrTst;                                       */
/*  input bool ACTION_EN_COURS;                                               */
/*  input uint8 Srv_stActrTstCodePrev;                                        */
/*  input boolean Srv_bRcStop_ActrTst;                                        */
/*  input boolean Srv_bRcReq_ActrTst;                                         */
/*  input bool PILOTAGE_NON_LANCE;                                            */
/*  input bool PROBLEME;                                                      */
/*  output uint8 Srv_stRcActrTst;                                             */
/*  output uint8 Srv_stActrTstCodePrev;                                       */
/*  output boolean Srv_bActrTstDmd;                                           */
/*  output boolean Srv_bActrTstRunning;                                       */
/*  output boolean Srv_bActrTstStop;                                          */
/*  output boolean Srv_bActrTstDmdWithCndVld;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_ActTstStateMachineTransition(void)
{
   uint8   u8LocalTstCode;
   uint8   u8LocalActrTstStatus;
   boolean bLocalTestEnable;

   VEMS_vidGET(Srv_stActrTstCode, u8LocalTstCode);
   VEMS_vidGET(Srv_stActrTstStatus, u8LocalActrTstStatus);

   if( TRUE == Srv_bRcStart_ActrTst )
   {
      if( ( ACTION_EN_COURS == u8LocalActrTstStatus ) &&
          ( Srv_stActrTstCodePrev == u8LocalTstCode ) )
      {
         /* Le test actionneur est déjà lancé */
         Srv_stRcActrTst = RC_STRT_AFTER_STRT;
      }
      else
      {
         Srv_stActrTstCodePrev = u8LocalTstCode;
         VEMS_vidSET(Srv_bActrTstDmd, TRUE);
         bLocalTestEnable = DCM_MANU_ActuatorTestCheckCond( u8LocalTstCode );
         if( TRUE == bLocalTestEnable )
         {
            VEMS_vidSET(Srv_bActrTstRunning, TRUE);
            VEMS_vidSET(Srv_bActrTstStop, FALSE);
            VEMS_vidSET(Srv_bActrTstDmdWithCndVld, TRUE);
            /* Lancement du test */
            Srv_stRcActrTst = RC_RUNNING;
         }
         else
         {
            /* Dans ce cas, la machine a changé d'état. */
         }
      }
   }
   else if( TRUE == Srv_bRcStop_ActrTst )
   {
      if( ( ( ACTION_EN_COURS == u8LocalActrTstStatus   ) ||
            ( ARRET_DU_PILOTAGE == u8LocalActrTstStatus ) ) &&
          ( Srv_stActrTstCodePrev == u8LocalTstCode       ) )
      {
         /* Le test est stoppé */
         Srv_stRcActrTst = RC_STOPPED;
         VEMS_vidSET(Srv_bActrTstRunning, FALSE);
         VEMS_vidSET(Srv_bActrTstStop, TRUE);
      }
      else
      {
         /* Une demande de stop a été envoyée alors
         qu'aucun test n'est en cours.*/
         Srv_stRcActrTst = RC_REQ_SEQU_ERROR;
      }
   }
   else if( TRUE == Srv_bRcReq_ActrTst )
   {
      if( ( PILOTAGE_NON_LANCE == u8LocalActrTstStatus ) ||
          ( Srv_stActrTstCodePrev != u8LocalTstCode    ) )
      {
         Srv_stRcActrTst = RC_REQ_SEQU_ERROR;
      }
      else if( ( ARRET_DU_PILOTAGE == u8LocalActrTstStatus ) &&
               ( Srv_stActrTstCodePrev == u8LocalTstCode   ) )
      {
         /* Le test est stoppé */
         Srv_stRcActrTst = RC_STOPPED;
         VEMS_vidSET(Srv_bActrTstRunning, FALSE);
         VEMS_vidSET(Srv_bActrTstStop, TRUE);
      }
      else if( ( PROBLEME == u8LocalActrTstStatus        ) &&
               ( Srv_stActrTstCodePrev == u8LocalTstCode ) )
      {
         /* Le test est terminé sur un problème */
         Srv_stRcActrTst = RC_FINISHED_NOK;
         VEMS_vidSET(Srv_bActrTstRunning, FALSE);
      }
      else if( ( ACTION_TERMINEE_OK == u8LocalActrTstStatus ) &&
               ( Srv_stActrTstCodePrev == u8LocalTstCode    ) )
      {
         Srv_stRcActrTst = RC_FINISHED_OK;
         VEMS_vidSET(Srv_bActrTstRunning, FALSE);
      }
      else if( ( ACTION_EN_COURS == u8LocalActrTstStatus ) &&
               ( Srv_stActrTstCodePrev == u8LocalTstCode ) )
      {
         Srv_stRcActrTst = RC_RUNNING;
      }
      else
      {
         /* Cas impossible */
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_ActuatorTestCheckCond                             */
/* !Description :  Cette fonction effectue le test des conditions applicatives*/
/*                 avant de lancer un test actionneur.                        */
/* !Number      :  ACTUATOR_TST_MNG.8                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret boolean  DCM_MANU_ActuatorTestCheckCond_Farsp();              */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 ActrTstMng_VVehiMax;                                          */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 ActrTstMng_UBatMax;                                          */
/*  input uint16 ActrTstMng_UBatMin;                                          */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Srv_bInhBoostGDI;                                           */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input boolean Ext_bBrkPedPrss;                                            */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 ActrTstMng_nEngRunMaxTestHpPmp_C;                            */
/*  input uint16 ActrTstMng_nEngRunMinTestHpPmp_C;                            */
/*  input uint16 Ext_pFuMes;                                                  */
/*  input uint8 Srv_ctActrTstHpPmp;                                           */
/*  input uint8 Srv_ctActrTstHpPmpMax_C;                                      */
/*  input uint16 ActrTstMng_pFuMaxHpPmp_C;                                    */
/*  input uint8 ActrTstMng_tCoMesMinTestHpPmp_C;                              */
/*  input uint16 ActrTstMng_nEngRunMaxTest_C;                                 */
/*  input uint16 ActrTstMng_nEngRunMinTest_C;                                 */
/*  input boolean Ext_bOilPres;                                               */
/*  input boolean Ext_bPresExCmSen;                                           */
/*  input boolean Ext_bPresInCmSen;                                           */
/*  input uint8 ActrTstMng_tCoMesMinTest_C;                                   */
/*  input uint16 ActrTstMng_nEngStopMaxTest_C;                                */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean Inj_bInjTestDone;                                           */
/*  input boolean Srv_bTestCdn;                                               */
/*  input boolean Srv_bAcvUnloadRail;                                         */
/*  input boolean Ctrl_bTreatAdHeatRly;                                       */
/*  input uint8 ThMgt_rSpdFanReq;                                             */
/*  input boolean Ext_bFSFCf;                                                 */
/*  input uint8 ShdFlap_stPosn;                                               */
/*  input uint16 ActrTstMng_pFuMaxTestInj_C;                                  */
/*  output uint8 Srv_ctActrTstHpPmp;                                          */
/*  output uint8 Srv_stRcActrTst;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean DCM_MANU_ActuatorTestCheckCond
(
   uint8 u8TstCode_par
)
{
   sint32             s32LocalTmp;
   uint16             u16LocalVehSpd;
   uint16             u16LocalExt_nEng;
   uint16             u16LocalAccP_rAccP;
   uint16             u16LocalExtpFuMes;
   sint16             s16LocalBattMes;
   sint16             s16LocaltCoMes;
   sint32             s32LocaltCoMes;
   uint8              u8LocalCoPt_noEgdGearCord;
   uint8              u8LocalCoPTStstEng;
   uint8              u8LocalThMgt_rSpdFanReq;
   uint8              u8LocalShdFlap_stPosn;
   GDFRM_tenuGDUState u8LocalGDU_stDgoOvld_ThrCm;
   boolean            bLocalbWkuMain;
   boolean            bLocalSrv_bInhBoostGDI;
   boolean            bLocalBrkPedPrss;
   boolean            bLocalCluPedPrss;
   boolean            bLocalOilPres;
   boolean            bLocalPresExCmSen;
   boolean            bLocalInjTestDone;
   boolean            bLocalTestCdn;
   boolean            bLocalTestEnable;
   boolean            bLocalPresInCmSen;
   boolean            bLocalFrm_bInhActrTstHpPmp;
   boolean            bLocalSrv_bAcvUnloadRail;
   boolean            bLocalCtrl_bTreatAdHeatRly;
   boolean            bLocalExt_bFSFCf;
   boolean            bLocal1;
   boolean            bLocal2;

   VEMS_vidGET(Veh_spdVeh, u16LocalVehSpd);
   u16LocalVehSpd = (uint16)(u16LocalVehSpd / 128);

   if( u16LocalVehSpd <= (uint16)ActrTstMng_VVehiMax )
   {
      VEMS_vidGET(Ext_uBattMes, s16LocalBattMes);
      s32LocalTmp = (ActrTstMng_UBatMax * 59)/25;

      if( (sint32)s16LocalBattMes <= s32LocalTmp )
      {
         s32LocalTmp = (ActrTstMng_UBatMin * 59)/25;

         if( (sint32)s16LocalBattMes >= s32LocalTmp )
         {
            VEMS_vidGET(ECU_bWkuMain, bLocalbWkuMain);
            VEMS_vidGET(Srv_bInhBoostGDI, bLocalSrv_bInhBoostGDI);

            if(( bLocalbWkuMain != FALSE )
               && (bLocalSrv_bInhBoostGDI == 0))
            {
               if( ( CODE_TEST_VVT_ADM == u8TstCode_par ) ||
                   ( CODE_TEST_VVT_ECH == u8TstCode_par ) ||
                   ( CODE_TEST_TURBO == u8TstCode_par)    ||
                   ( CODE_TEST_HPPMP == u8TstCode_par)    ||
                   ( CODE_TEST_FARSP == u8TstCode_par))
               {
                  VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);

                  if(u16LocalAccP_rAccP == 0)
                  {
                     VEMS_vidGET( CoPt_noEgdGearCord,
                                        u8LocalCoPt_noEgdGearCord );

                     if(u8LocalCoPt_noEgdGearCord == 0)
                     {
                        VEMS_vidGET(Ext_bBrkPedPrss, bLocalBrkPedPrss);
                        if(bLocalBrkPedPrss == 0)
                        {
                           VEMS_vidGET(Ext_bCluPedPrss, bLocalCluPedPrss);
                           if(bLocalCluPedPrss == 0)
                           {
                              VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
                              VEMS_vidGET(Ext_tCoMes, s16LocaltCoMes);
                              s32LocaltCoMes = (sint32)(s16LocaltCoMes + 40);

                              /* code CODE_TEST_HPPMP */
                              if(CODE_TEST_HPPMP == u8TstCode_par)
                              {

                                 if( u16LocalExt_nEng <=
                                              ActrTstMng_nEngRunMaxTestHpPmp_C )
                                 {
                                    if( u16LocalExt_nEng >=
                                       ActrTstMng_nEngRunMinTestHpPmp_C )
                                    {
                                       VEMS_vidGET(
                                          Ext_pFuMes, u16LocalExtpFuMes);
                                       bLocalFrm_bInhActrTstHpPmp =
                                          GDGAR_bGetFRM(
                                             FRM_FRM_INHACTRTSTHPPMP);

                                       if( (Srv_ctActrTstHpPmp <=
                                          Srv_ctActrTstHpPmpMax_C) &&
                                           (bLocalFrm_bInhActrTstHpPmp == 0) &&
                                           (u16LocalExtpFuMes <
                                             ActrTstMng_pFuMaxHpPmp_C) )
                                       {
                                          if( s32LocaltCoMes >
                                             ActrTstMng_tCoMesMinTestHpPmp_C)
                                          {
                                             if (Srv_ctActrTstHpPmp < 255)
                                             {
                                                Srv_ctActrTstHpPmp ++;
                                             }
                                             bLocalTestEnable = TRUE;
                                          }
                                          else
                                          {
                                             bLocalTestEnable = FALSE;
                                             Srv_stRcActrTst =
                                                RC_WATER_TEMP_TOO_LOW;
                                          }
                                       }
                                       else
                                       {
                                          bLocalTestEnable = FALSE;
                                          Srv_stRcActrTst = RC_COND_NOK;
                                       }
                                    }
                                    else
                                    {
                                       bLocalTestEnable = FALSE;
                                       Srv_stRcActrTst =
                                          RC_ENGINE_RUNNING_TOO_LOW;
                                    }
                                 }
                                 else
                                 {
                                    bLocalTestEnable = FALSE;
                                    Srv_stRcActrTst =
                                       RC_ENGINE_RUNNING_TOO_HIGH;
                                 }
                              }
                              /* code CODE_TEST_FARSP */
                              else if(CODE_TEST_FARSP == u8TstCode_par)
                              {
                                 bLocalTestEnable =
                                    DCM_MANU_ActuatorTestCheckCond_Farsp();
                              }
                              /* */
                              else
                              {
                                 if(u16LocalExt_nEng <=
                                    ActrTstMng_nEngRunMaxTest_C)
                                 {
                                    if(u16LocalExt_nEng >=
                                       ActrTstMng_nEngRunMinTest_C)
                                    {
                                       if( (u8TstCode_par ==
                                          CODE_TEST_VVT_ADM) ||
                                           (u8TstCode_par ==
                                             CODE_TEST_VVT_ECH)
                                       )
                                       {
                                          VEMS_vidGET(Ext_bOilPres,
                                             bLocalOilPres);
                                          if(bLocalOilPres == TRUE)
                                          {
                                             VEMS_vidGET(Ext_bPresExCmSen,
                                                bLocalPresExCmSen);
                                             VEMS_vidGET(Ext_bPresInCmSen,
                                                bLocalPresInCmSen);
                                             if( ((bLocalPresExCmSen != FALSE)
                                                || (u8TstCode_par !=
                                                   CODE_TEST_VVT_ECH) )
                                                 && ((bLocalPresInCmSen !=
                                                   FALSE)
                                                   || (u8TstCode_par !=
                                                   CODE_TEST_VVT_ADM))
                                             )
                                             {
                                                bLocalTestEnable = TRUE;
                                             }
                                             else
                                             {
                                                bLocalTestEnable = FALSE;
                                                Srv_stRcActrTst = RC_COND_NOK;
                                             }
                                          }
                                          else
                                          {
                                             bLocalTestEnable = FALSE;
                                             Srv_stRcActrTst = RC_COND_NOK;
                                          }
                                       }
                                       else
                                       {
                                          if(u8TstCode_par == CODE_TEST_TURBO)
                                          {
                                             if(s32LocaltCoMes >=
                                                ActrTstMng_tCoMesMinTest_C)
                                             {
                                                bLocalTestEnable = TRUE;
                                             }
                                             else
                                             {
                                                bLocalTestEnable = FALSE;
                                                Srv_stRcActrTst =
                                                   RC_WATER_TEMP_TOO_LOW;
                                             }
                                          }
                                          else
                                          {
                                             /* Cas impossible */
                                             SWFAIL_vidSoftwareErrorHook();
                                          }
                                       }
                                    }
                                    else
                                    {
                                       bLocalTestEnable = FALSE;
                                       Srv_stRcActrTst =
                                          RC_ENGINE_RUNNING_TOO_LOW;
                                    }
                                 }
                                 else
                                 {
                                    bLocalTestEnable = FALSE;
                                    Srv_stRcActrTst =
                                       RC_ENGINE_RUNNING_TOO_HIGH;
                                 }
                              }
                           }
                           else
                           {
                              bLocalTestEnable = FALSE;
                              Srv_stRcActrTst = RC_COND_NOK;
                           }
                        }
                        else
                        {
                           bLocalTestEnable = FALSE;
                           Srv_stRcActrTst = RC_COND_NOK;
                        }
                     }
                     else
                     {
                        bLocalTestEnable = FALSE;
                        Srv_stRcActrTst = RC_GEAR;
                     }
                  }
                  else
                  {
                     if(u16LocalAccP_rAccP > 0)
                     {
                        bLocalTestEnable = FALSE;
                        Srv_stRcActrTst = RC_PEDAL_TOO_HIGH;
                     }
                     else
                     {
                        /* Cas impossible */
                        SWFAIL_vidSoftwareErrorHook();
                     }
                  }
               }
               /* Branche Gauche */
               else
               {
                  VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

                  if( u16LocalExt_nEng <= ActrTstMng_nEngStopMaxTest_C )
                  {
                     VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTStstEng);
                     VEMS_vidGET(Inj_bInjTestDone, bLocalInjTestDone);
                     VEMS_vidGET(Ext_pFuMes, u16LocalExtpFuMes);
                     VEMS_vidGET(Srv_bTestCdn, bLocalTestCdn);
                     VEMS_vidGET(Srv_bAcvUnloadRail, bLocalSrv_bAcvUnloadRail);
                     VEMS_vidGET(Ctrl_bTreatAdHeatRly,
                                                bLocalCtrl_bTreatAdHeatRly);
                     VEMS_vidGET(ThMgt_rSpdFanReq, u8LocalThMgt_rSpdFanReq);
                     VEMS_vidGET(Ext_bFSFCf, bLocalExt_bFSFCf);
                     VEMS_vidGET(ShdFlap_stPosn, u8LocalShdFlap_stPosn);
                     u8LocalGDU_stDgoOvld_ThrCm =
                           GDGAR_tenuGetStDgo(GD_DFT_OVLD_THRCMD);

                     if(  ( 1 == u8LocalCoPTStstEng )
                          &&  ( (   ( FALSE == bLocalInjTestDone) &&
                                    (bLocalSrv_bAcvUnloadRail == FALSE) &&
                                    (Srv_ctActrTstHpPmp == 0))
                                ||  (  (CODE_TEST_BOBINE_1 != u8TstCode_par) &&
                                       (CODE_TEST_BOBINE_2 != u8TstCode_par) &&
                                       (CODE_TEST_BOBINE_3 != u8TstCode_par) &&
                                       (CODE_TEST_BOBINE_4 != u8TstCode_par) )))
                     {
                        bLocal1 = 1;
                     }
                     else
                     {
                        bLocal1 = 0;
                     }
                     if( ( bLocal1 != 0)
                       && ( ( u16LocalExtpFuMes <
                                    ActrTstMng_pFuMaxTestInj_C      ) ||
                          ( ( CODE_TEST_INJECTEUR_1 != u8TstCode_par ) &&
                          ( CODE_TEST_INJECTEUR_2 != u8TstCode_par ) &&
                          ( CODE_TEST_INJECTEUR_3 != u8TstCode_par ) &&
                          ( CODE_TEST_INJECTEUR_4 != u8TstCode_par ) ))
                       && ( ( ( ( bLocalExt_bFSFCf == FALSE) &&
                              (u8LocalShdFlap_stPosn == 0)) ||
                            ( CODE_TEST_MEAP != u8TstCode_par) )))
                     {
                        bLocal2 = 1;
                     }
                     else
                     {
                        bLocal2 = 0;
                     }
                     if(  ( bLocal2 != 0)
                       && ( ( TRUE == bLocalTestCdn ) &&
                          ( ( CODE_TEST_PAP_MOT != u8TstCode_par ) ||
                          ( GDU_ETAT_PRESENT !=
                                    u8LocalGDU_stDgoOvld_ThrCm    ) ) )
                       && ( ( ( bLocalCtrl_bTreatAdHeatRly == TRUE) &&
                              (u8LocalThMgt_rSpdFanReq == 0)) ||
                            ( CODE_TEST_CTP != u8TstCode_par) ))
                     {
                        bLocalTestEnable = TRUE;
                     }
                     else
                     {
                        bLocalTestEnable = FALSE;
                        Srv_stRcActrTst = RC_COND_NOK;
                     }
                  }
                  else
                  {
                     bLocalTestEnable = FALSE;
                     Srv_stRcActrTst = RC_ENGINE_RUNNING;
                  }
               }
            }
            else /* Srv_RcInhBoostGDI et Srv_RcNotWake */
            {
               bLocalTestEnable = FALSE;
               Srv_stRcActrTst = RC_COND_NOK;
            }
         }
         else
         {
            bLocalTestEnable = FALSE;
            Srv_stRcActrTst = RC_VOLT_TOO_LOW;
         }
      }
      else
      {
         bLocalTestEnable = FALSE;
         Srv_stRcActrTst = RC_VOLT_TOO_HIGH;
      }
   }
   else
   {
      bLocalTestEnable = FALSE;
      Srv_stRcActrTst = RC_VEHICULE_SPEED;
   }

   return bLocalTestEnable;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_ActTstResAnalyse                                  */
/* !Description :  Fonction analysant le résultat des la machine d'état.      */
/* !Number      :  ACTUATOR_TST_MNG.9                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Srv_stRcActrTst;                                              */
/*  input uint8 Srv_stTestDftCdn;                                             */
/*  input st91 Srv_stActrTstFeedback;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_ActTstResAnalyse
(
   uint8* ErrorCodeOut,
   uint8* RoutineStatusOut,
   uint8* OutputParam
)
{
   uint8          u8Localparam;
   uint8          u8LocalErrorCode;
   uint8          u8LocalRoutineStatus;
   Std_ReturnType u8LocalReturn;

   switch( Srv_stRcActrTst )
   {
      case RC_COND_NOK:
      case RC_STRT_AFTER_STRT:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      break;

      case RC_REQ_SEQU_ERROR:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      break;

      case RC_ENGINE_RUNNING:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_ENGINEISRUNNING;
      break;

      case RC_VEHICULE_SPEED:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_VEHICLESPEEDTOOHIGH;
      break;

      case RC_VOLT_TOO_HIGH:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_VOLTAGETOOHIGH;
      break;

      case RC_VOLT_TOO_LOW:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_VOLTAGETOOLOW;
      break;

      case RC_ENGINE_RUNNING_TOO_HIGH:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_RPMTOOHIGH;
      break;

      case RC_ENGINE_RUNNING_TOO_LOW:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_RPMTOOLOW;
      break;

      case RC_GEAR:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_TRANSMISSIONRANGENOTINNEUTRAL;
      break;

      case RC_PEDAL_TOO_HIGH:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_THROTTLE_PEDALTOOHIGH;
      break;

      case RC_WATER_TEMP_TOO_LOW:
      u8Localparam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_TEMPERATURETOOLOW;
      break;

      case RC_FINISHED_NOK:
      u8LocalReturn = E_OK;
      VEMS_vidGET(Srv_stTestDftCdn, u8Localparam);
      u8LocalRoutineStatus = 0x03;
      u8LocalErrorCode = 0x00;
      break;

      case RC_FINISHED_OK:
      u8LocalReturn = E_OK;
      VEMS_vidGET(Srv_stActrTstFeedback, u8Localparam);
      u8LocalRoutineStatus = 0x02;
      u8LocalErrorCode = 0x00;
      break;

      case RC_RUNNING:
      u8Localparam = 0x00;
      u8LocalReturn = E_OK;
      u8LocalRoutineStatus = 0x01;
      u8LocalErrorCode = 0x00;
      break;

      case RC_STOPPED:
      u8Localparam = 0x00;
      u8LocalReturn = E_OK;
      u8LocalRoutineStatus = 0x04;
      u8LocalErrorCode = 0x00;
      break;

      case RC_INIT:
      case RC_WAITING:
      default:
      /* generalReject */
      /* Cas impossible */
      SWFAIL_vidSoftwareErrorHook();
      u8Localparam = 0x00;
      u8LocalReturn = E_NOT_OK;
      u8LocalErrorCode = DCM_E_GENERALREJECT;
      u8LocalRoutineStatus = 0x00;
      break;
   }

   *ErrorCodeOut = u8LocalErrorCode;
   *RoutineStatusOut = u8LocalRoutineStatus;
   *OutputParam = u8Localparam;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_Start_Rc_Acttest_Factor_Mngmt                     */
/* !Description :  Fonction appelée sur réception de requête de type Start    */
/*                 Routine pour les tests actionneurs.                        */
/* !Number      :  ACTUATOR_TST_MNG.10                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf argret Std_ReturnType  DCM_MANU_StartActuatorTst(argin uint8         */
/* code_test_in, argin uint8 *ErrorCodeOut, argin uint8 *RoutineStatusOut,    */
/* argin uint8 *OutputParam);                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_Start_Rc_Acttest_Factor_Mngmt
(
   uint8 code_test,
   uint8* routine_status,
   uint16* last_param_lgth,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalVar;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   u8LocalVar = DCM_MANU_CheckADCCondition( SRV_LAMBDA, &u8LocalErrorCode );

   if( E_OK == u8LocalVar )
   {
      u8LocalVar =
         DCM_MANU_StartActuatorTst( code_test,
                                    &u8LocalErrorCode,
                                    &u8LocalRoutineStatus,
                                    &u8LocalOutputParam );

      if( E_OK == u8LocalVar )
      {
         /* Test OK */
         u8LocalReturn = E_OK;
         /* Taille du dernier parametre en bits (u8LocalRoutineStatus) */
         u16LocalCurrentDataLgth = 8;
      }
      else
      {
         /* Le test ne peut pas se lancer */
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0x00;
         u16LocalCurrentDataLgth = 0;
      }
   }
   else
   {
      /* Les conditions ADC ne sont pas bonnes */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
   }

   *ErrorCode = u8LocalErrorCode;
   *routine_status = u8LocalRoutineStatus;
   *last_param_lgth = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt             */
/* !Description :  Focntion appelée sur réception de requête Request Result   */
/*                 pour les tests actionneurs uniquement.                     */
/* !Number      :  ACTUATOR_TST_MNG.11                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf argret Std_ReturnType  DCM_MANU_ReqResActuatorTst(argin uint8        */
/* code_test_in, argin uint8 *ErrorCodeOut, argin uint8 *RoutineStatusOut,    */
/* argin uint8 *OutputParam);                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt
(
   uint8 code_test,
   uint8* routine_status,
   uint8* output_param,
   uint16* last_param_lgth,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalVar;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   u8LocalVar = DCM_MANU_CheckADCCondition( SRV_LAMBDA, &u8LocalErrorCode );

   if( E_OK == u8LocalVar )
   {
      u8LocalVar = DCM_MANU_ReqResActuatorTst( code_test,
                                               &u8LocalErrorCode,
                                               &u8LocalRoutineStatus,
                                               &u8LocalOutputParam );

      if( E_OK == u8LocalVar )
      {
         /* Pas de problème dans le test concerné */
         u8LocalReturn = E_OK;
         /* Si la routine est en FINISHED_OK ou en FINISHED_NOK */
         if( ( TERMINE_OK == u8LocalRoutineStatus  ) ||
             ( TERMINE_NOK == u8LocalRoutineStatus ) )
         {
            /* Taille en bits du dernier parametre (Param_Supl) */
            u16LocalCurrentDataLgth = 8;
         }
         else
         {
            /* Taille en bits du dernier parametre (Param_Supl) */
            u16LocalCurrentDataLgth = 0;
         }
      }
      else
      {
         /* Problème dans le test concerné */
         u8LocalReturn = E_NOT_OK;
         u8LocalOutputParam = 0x00;
         u8LocalRoutineStatus = 0x00;
         u16LocalCurrentDataLgth = 0;
      }
   }
   else
   {
      /* Les conditions ADC ne sont pas bonnes */
      u8LocalReturn = E_NOT_OK;
      u8LocalOutputParam = 0x00;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
   }

   *ErrorCode = u8LocalErrorCode;
   *output_param = u8LocalOutputParam;
   *routine_status = u8LocalRoutineStatus;
   *last_param_lgth = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt                      */
/* !Description :  Fonction appelée sur réception de requête Stop Routine.    */
/*                 Uniquement pour les tests actionneurs…                     */
/* !Number      :  ACTUATOR_TST_MNG.12                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf argret Std_ReturnType  DCM_MANU_StopActuatorTst(argin uint8          */
/* code_test_in, argin uint8 *ErrorCodeOut, argin uint8 *RoutineStatusOut,    */
/* argin uint8 *OutputParam);                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt
(
   uint8 code_test,
   uint8* routine_status,
   uint16* last_param_lgth,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                       u16LocalCurrentDataLgth;
   Std_ReturnType               u8LocalVar;
   Std_ReturnType               u8LocalReturn;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;
   uint8                        u8LocalOutputParam;
   uint8                        u8LocalRoutineStatus;

   u8LocalVar = DCM_MANU_CheckADCCondition( SRV_LAMBDA, &u8LocalErrorCode );

   if( E_OK == u8LocalVar )
   {
      u8LocalVar = DCM_MANU_StopActuatorTst( code_test,
                                             &u8LocalErrorCode,
                                             &u8LocalRoutineStatus,
                                             &u8LocalOutputParam );

      if( E_OK == u8LocalVar )
      {
         /* Pas de problème dans le test concerné */
         u8LocalReturn = E_OK;
         /* Taille du dernier parametre en bits (State_Routine) */
         u16LocalCurrentDataLgth = 8;
      }
      else
      {
         /* Problème dans le test concerné */
         u8LocalReturn = E_NOT_OK;
         u8LocalRoutineStatus = 0x00;
         u16LocalCurrentDataLgth = 0;
      }
   }
   else
   {
      /* Les conditions ADC ne sont pas bonnes */
      u8LocalReturn = E_NOT_OK;
      u8LocalRoutineStatus = 0x00;
      u16LocalCurrentDataLgth = 0;
   }

   *ErrorCode = u8LocalErrorCode;
   *routine_status = u8LocalRoutineStatus;
   *last_param_lgth = u16LocalCurrentDataLgth;

   return u8LocalReturn;
}