/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRPOSNSPLRN                                            */
/* !Description     : ThrPosnSpLrn component                                  */
/*                                                                            */
/* !Module          : THRPOSNSPLRN                                            */
/* !Description     : CALCUL DES CONSIGNES SPECIFIQUES DE POSITION PAPILLON   */
/*                    MOTORISE EN BOUCLE FERMEE                               */
/*                                                                            */
/* !File            : THRPOSNSPLRN_FCT2.C                                     */
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
/*   1 / THRPOSNSPLRN_vidAutomate                                             */
/*   2 / THRPOSNSPLRN_vidDuringHighThrust                                     */
/*   3 / THRPOSNSPLRN_vidDuringLowThrust                                      */
/*   4 / THRPOSNSPLRN_vidDuringMcwInhTest                                     */
/*   5 / THRPOSNSPLRN_vidDuringLimpHome                                       */
/*   6 / THRPOSNSPLRN_vidDurExitLowThrust                                     */
/*   7 / THRPOSNSPLRN_vidTransFromCenter                                      */
/*   8 / THRPOSNSPLRN_vidCalibration                                          */
/*   9 / THRPOSNSPLRN_vidSlewRate                                             */
/*   10 / THRPOSNSPLRN_vidFinalSpcSp                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 00303 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRPOSNSPLRN/THRPOSNSPLRN_FC$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   01 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRPOSNSPLRN.h"
#include "THRPOSNSPLRN_L.h"
#include "THRPOSNSPLRN_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidAutomate                                   */
/* !Description :  Fonction de management.                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSNSPLRN_vidTransFromCenter();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRPOSNSPLRN_vidCalibration();                           */
/*  extf argret void THRPOSNSPLRN_vidDuringHighThrust();                      */
/*  extf argret void THRPOSNSPLRN_vidDuringLowThrust();                       */
/*  extf argret void THRPOSNSPLRN_vidDuringMcwInhTest();                      */
/*  extf argret void THRPOSNSPLRN_vidDuringLimpHome();                        */
/*  extf argret void THRPOSNSPLRN_vidDurExitLowThrust();                      */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input uint8 ThrPosnSpLrn_u8State;                                         */
/*  input boolean Thr_FLrnClCtl_bManInh_C;                                    */
/*  input uint16 Thr_FLrnClCtl_posnIniLoThruSp;                               */
/*  input uint16 Thr_FLrnClCtl_vIniLoThru;                                    */
/*  input uint8 Thr_FLrnClCtl_titempo;                                        */
/*  output uint8 Thr_FLrnClCtl_titempo;                                       */
/*  output uint8 ThrPosnSpLrn_u8State;                                        */
/*  output boolean Thr_FLrnClCtl_bAcv;                                        */
/*  output uint16 Thr_FLrnClCtl_posnTar;                                      */
/*  output uint16 Thr_FLrnClCtl_vTar;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidAutomate(void)
{
   uint8 u8LocalTpacThrottleControlState;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);
   if (ThrPosnSpLrn_u8State == THRPOSNSPLRN_INIT)
   {  /* sortie de l'etat d'THRPOSNSPLRN_INIT */
      if (  (u8LocalTpacThrottleControlState != TPAC_WAIT_FOR_ADC)
         && (u8LocalTpacThrottleControlState != TPAC_CONTROL)
         && (u8LocalTpacThrottleControlState != TPAC_RESTOR_MOBILITY)
         && (Thr_FLrnClCtl_bManInh_C == 0))
      {
         Thr_FLrnClCtl_titempo = 0;
         THRPOSNSPLRN_vidTransFromCenter();
      }
   }
   else
   {
      if (  (u8LocalTpacThrottleControlState == TPAC_WAIT_FOR_ADC)
         || (u8LocalTpacThrottleControlState == TPAC_CONTROL)
         || (u8LocalTpacThrottleControlState == TPAC_RESTOR_MOBILITY)
         || (Thr_FLrnClCtl_bManInh_C != 0))
      {  /* retour vers l'état d'THRPOSNSPLRN_INIT */
         ThrPosnSpLrn_u8State = THRPOSNSPLRN_INIT;
         VEMS_vidSET(Thr_FLrnClCtl_bAcv, 0);
         THRPOSNSPLRN_vidCalibration();
         Thr_FLrnClCtl_posnTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnIniLoThruSp, 1024);
         Thr_FLrnClCtl_vTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vIniLoThru, 1024);
      }
      else /* l'automate est vivant :) --> CASE LEARNING */
      {  /* Vérification si nous changeons d'état */
         switch(ThrPosnSpLrn_u8State)
         {
            case THRPOSNSPLRN_HIGH_THRUST_SEARCH:
               THRPOSNSPLRN_vidDuringHighThrust();
               break;

            case THRPOSNSPLRN_LOW_THRUST_SEARCH:
               THRPOSNSPLRN_vidDuringLowThrust();
               break;

            case THRPOSNSPLRN_MCW_INHIBIT_TEST:
               THRPOSNSPLRN_vidDuringMcwInhTest();
               break;

            case THRPOSNSPLRN_LIMP_HOME:
               THRPOSNSPLRN_vidDuringLimpHome();
               break;

            case THRPOSNSPLRN_EXIT_LOW_THRUST:
               THRPOSNSPLRN_vidDurExitLowThrust();
               break;

            default:
               ThrPosnSpLrn_u8State = THRPOSNSPLRN_INIT;
               VEMS_vidSET(Thr_FLrnClCtl_bAcv, 0);
               THRPOSNSPLRN_vidCalibration();
               Thr_FLrnClCtl_posnTar =
                  (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnIniLoThruSp, 1024);
               Thr_FLrnClCtl_vTar =
                  (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vIniLoThru, 1024);
               break;
         }
      }
      /* TIMER */
      if (Thr_FLrnClCtl_titempo >= 1)
      {
         Thr_FLrnClCtl_titempo = (uint8)(Thr_FLrnClCtl_titempo - 1);
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidDuringHighThrust                           */
/* !Description :  Fonction gérant les actions durant l'état                  */
/*                 High_Thrust_Search.                                        */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSNSPLRN_vidCalibration();                           */
/*  extf argret void THRPOSNSPLRN_vidTransFromCenter();                       */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Thr_FLrnClCtl_bTempoEnd;                                    */
/*  input uint8 Thr_FLrnClCtl_titempo;                                        */
/*  input uint16 Thr_FLrnClCtl_posnHiThruSp;                                  */
/*  input uint16 Thr_FLrnClCtl_vHiThru;                                       */
/*  output uint16 Thr_FLrnClCtl_posnTar;                                      */
/*  output uint16 Thr_FLrnClCtl_vTar;                                         */
/*  output boolean Thr_FLrnClCtl_bTempoEnd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidDuringHighThrust(void)
{
   uint8  u8LocalTpacThrottleControlState;

   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);
   if (Thr_FLrnClCtl_bTempoEnd == 0)
   {
      if(Thr_FLrnClCtl_titempo == 0)
      {
         THRPOSNSPLRN_vidCalibration();
         Thr_FLrnClCtl_posnTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnHiThruSp, 1024);
         Thr_FLrnClCtl_vTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vHiThru, 1024);
         Thr_FLrnClCtl_bTempoEnd = 1;
      }
   }

   if (Thr_FLrnClCtl_bTempoEnd != 0) /* Tempo is done */
   {
      if(u8LocalTpacThrottleControlState != TPAC_HIGH_THRUST_SEARCH)
      {
         THRPOSNSPLRN_vidTransFromCenter();
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidDuringLowThrust                            */
/* !Description :  Fonction gérant les actions durant l'état Low Thrust       */
/*                 Search.                                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSNSPLRN_vidCalibration();                           */
/*  extf argret void THRPOSNSPLRN_vidTransFromCenter();                       */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Thr_FLrnClCtl_bTempoEnd;                                    */
/*  input uint8 Thr_FLrnClCtl_titempo;                                        */
/*  input uint16 Thr_FLrnClCtl_posnLoThruSp;                                  */
/*  input uint16 Thr_FLrnClCtl_vLoThru;                                       */
/*  output uint16 Thr_FLrnClCtl_posnTar;                                      */
/*  output uint16 Thr_FLrnClCtl_vTar;                                         */
/*  output boolean Thr_FLrnClCtl_bTempoEnd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidDuringLowThrust(void)
{
   uint8  u8LocalTpacThrottleControlState;

   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);
   if (Thr_FLrnClCtl_bTempoEnd == 0)
   {
      if(Thr_FLrnClCtl_titempo == 0)
      {
         THRPOSNSPLRN_vidCalibration();
         Thr_FLrnClCtl_posnTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnLoThruSp, 1024);
         Thr_FLrnClCtl_vTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vLoThru, 1024);
         Thr_FLrnClCtl_bTempoEnd = 1;
      }
   }
   if (Thr_FLrnClCtl_bTempoEnd != 0) /* Tempo is done */
   {
      if(u8LocalTpacThrottleControlState != TPAC_CLOSING_RAMP)
      {
         THRPOSNSPLRN_vidTransFromCenter();
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidDuringMcwInhTest                           */
/* !Description :  Fonction gérant les actions durant l'état McwInhibitTest   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSNSPLRN_vidTransFromCenter();                       */
/*  input st01 Tpac_throttle_control_state;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidDuringMcwInhTest(void)
{
   uint8  u8LocalTpacThrottleControlState;

   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);

   if(u8LocalTpacThrottleControlState != TPAC_MCW_INHIBIT_TEST)
   {
      THRPOSNSPLRN_vidTransFromCenter();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidDuringLimpHome                             */
/* !Description :  fonction gérant les actions pendant l'état Limp Home.      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSNSPLRN_vidTransFromCenter();                       */
/*  input st01 Tpac_throttle_control_state;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidDuringLimpHome(void)
{
   uint8  u8LocalTpacThrottleControlState;

   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);
   if(u8LocalTpacThrottleControlState != TPAC_LIMP_HOME)
   {
      THRPOSNSPLRN_vidTransFromCenter();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidDurExitLowThrust                           */
/* !Description :  Fonction gérant les actions pendant l'état Exit Low Trust. */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSNSPLRN_vidCalibration();                           */
/*  extf argret void THRPOSNSPLRN_vidTransFromCenter();                       */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Thr_FLrnClCtl_bTempoEnd;                                    */
/*  input uint8 Thr_FLrnClCtl_titempo;                                        */
/*  input uint16 Thr_FLrnClCtl_posnReturnLihSp;                               */
/*  input uint16 Thr_FLrnClCtl_vReturnLih;                                    */
/*  output uint16 Thr_FLrnClCtl_posnTar;                                      */
/*  output uint16 Thr_FLrnClCtl_vTar;                                         */
/*  output boolean Thr_FLrnClCtl_bTempoEnd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidDurExitLowThrust(void)
{
   uint8  u8LocalTpacThrottleControlState;

   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);
   if (Thr_FLrnClCtl_bTempoEnd == 0)
   {
      if(Thr_FLrnClCtl_titempo == 0)
      {
         THRPOSNSPLRN_vidCalibration();
         Thr_FLrnClCtl_posnTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnReturnLihSp, 1024);
         Thr_FLrnClCtl_vTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vReturnLih, 1024);
         Thr_FLrnClCtl_bTempoEnd = 1;
      }
   }
   if (Thr_FLrnClCtl_bTempoEnd != 0) /* Tempo is done */
   {
      if(u8LocalTpacThrottleControlState != TPAC_EXIT_LOW_THRUST)
      {
         THRPOSNSPLRN_vidTransFromCenter();
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidTransFromCenter                            */
/* !Description :  Fonction gérant les transitions.                           */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSNSPLRN_vidCalibration();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input uint8 Thr_FLrnClCtl_tiDlyIniHiThru_C;                               */
/*  input uint16 Thr_FLrnClCtl_vIniHiThru;                                    */
/*  input uint16 Thr_FLrnClCtl_posnIniHiThruSp;                               */
/*  input uint8 Thr_FLrnClCtl_tiDlyIniLoThru_C;                               */
/*  input uint16 Thr_FLrnClCtl_posnIniLoThruSp;                               */
/*  input uint16 Thr_FLrnClCtl_vIniLoThru;                                    */
/*  input uint8 Thr_FLrnClCtl_tiDlyExiLoThru_C;                               */
/*  input uint16 Thr_FLrnClCtl_posnExiLoThruSp;                               */
/*  input uint16 Thr_FLrnClCtl_vExiLoThru;                                    */
/*  output uint8 Thr_FLrnClCtl_titempo;                                       */
/*  output uint8 ThrPosnSpLrn_u8State;                                        */
/*  output uint16 Thr_FLrnClCtl_vTar;                                         */
/*  output uint16 Thr_FLrnClCtl_posnTar;                                      */
/*  output boolean Thr_FLrnClCtl_bAcv;                                        */
/*  output boolean Thr_FLrnClCtl_bTempoEnd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidTransFromCenter(void)
{
   uint8  u8LocalTpacThrottleControlState;

   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpacThrottleControlState);
   switch(u8LocalTpacThrottleControlState)
   {
      case TPAC_HIGH_THRUST_SEARCH:
         Thr_FLrnClCtl_titempo =
            (uint8)MATHSRV_udtMIN(Thr_FLrnClCtl_tiDlyIniHiThru_C, 204);
         ThrPosnSpLrn_u8State = THRPOSNSPLRN_HIGH_THRUST_SEARCH;
         /* entry  event Thr_FLrnClCtl_EveIniHiThru; */
         THRPOSNSPLRN_vidCalibration();
         Thr_FLrnClCtl_vTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vIniHiThru, 1024);
         Thr_FLrnClCtl_posnTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnIniHiThruSp, 1024);
         /* entry init */
         VEMS_vidSET(Thr_FLrnClCtl_bAcv, 1);
         Thr_FLrnClCtl_bTempoEnd = 0;
      break;

      case TPAC_CLOSING_RAMP:
         Thr_FLrnClCtl_titempo =
            (uint8)MATHSRV_udtMIN(Thr_FLrnClCtl_tiDlyIniLoThru_C, 204);
         ThrPosnSpLrn_u8State = THRPOSNSPLRN_LOW_THRUST_SEARCH;
         /* entry event Thr_FLrnClCtl_EveIniLoThru; */
         THRPOSNSPLRN_vidCalibration();
         Thr_FLrnClCtl_posnTar =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnIniLoThruSp, 1024);
         Thr_FLrnClCtl_vTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vIniLoThru, 1024);
         /* entry init */
         VEMS_vidSET(Thr_FLrnClCtl_bAcv, 1);
         Thr_FLrnClCtl_bTempoEnd = 0;
      break;

      case TPAC_MCW_INHIBIT_TEST:
         ThrPosnSpLrn_u8State = THRPOSNSPLRN_MCW_INHIBIT_TEST;
         VEMS_vidSET(Thr_FLrnClCtl_bAcv, 0);
         Thr_FLrnClCtl_bTempoEnd = 0;
      break;

      case TPAC_LIMP_HOME:
         ThrPosnSpLrn_u8State = THRPOSNSPLRN_LIMP_HOME;
         /* event */
         VEMS_vidSET(Thr_FLrnClCtl_bAcv, 0);
         Thr_FLrnClCtl_bTempoEnd = 0;
      break;

      case TPAC_EXIT_LOW_THRUST:
         Thr_FLrnClCtl_titempo =
            (uint8)MATHSRV_udtMIN(Thr_FLrnClCtl_tiDlyExiLoThru_C, 204);
         ThrPosnSpLrn_u8State = THRPOSNSPLRN_EXIT_LOW_THRUST;
         /* entry event Thr_FLrnClCtl_EveExiLoThru; */
         THRPOSNSPLRN_vidCalibration();
         Thr_FLrnClCtl_posnTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnExiLoThruSp, 1024);
         Thr_FLrnClCtl_vTar =
            (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vExiLoThru, 1024);
         /* entry init */
         VEMS_vidSET(Thr_FLrnClCtl_bAcv, 1);
         Thr_FLrnClCtl_bTempoEnd = 0;
      break;

      default:
         SWFAIL_vidSoftwareErrorHook();
      break;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidCalibration                                */
/* !Description :  Cette fonction permet de différencier les calibrations de  */
/*                 la fonction nettoyage de celle utilisées par la fonction   */
/*                 d’apprentissage.                                           */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Thr_bFClnInProgs;                                           */
/*  input boolean Tpac_FCln_enable;                                           */
/*  input uint16 Thr_FClnClCtl_posnExiLoThruSp_C;                             */
/*  input uint16 Thr_FClnClCtl_posnHiThruSp_C;                                */
/*  input uint16 Thr_FClnClCtl_posnLoThruSp_C;                                */
/*  input uint16 Thr_FClnClCtl_posnReturnLihSp_C;                             */
/*  input uint16 Thr_FClnClCtl_posnIniLoThruSp_C;                             */
/*  input uint16 Thr_FClnClCtl_posnIniHiThruSp_C;                             */
/*  input uint16 Thr_FLrnClCtl_vExiLoThru_C;                                  */
/*  input uint16 Thr_FClnClCtl_vHiThru_C;                                     */
/*  input uint16 Thr_FClnClCtl_vIniHiThru_C;                                  */
/*  input uint16 Thr_FClnClCtl_vIniLoThru_C;                                  */
/*  input uint16 Thr_FClnClCtl_vLoThru_C;                                     */
/*  input uint16 Thr_FClnClCtl_vReturnLih_C;                                  */
/*  input uint16 Thr_FLrnClCtl_posnExiLoThruSp_C;                             */
/*  input uint16 Thr_FLrnClCtl_posnHiThruSp_C;                                */
/*  input uint16 Thr_FLrnClCtl_posnLoThruSp_C;                                */
/*  input uint16 Thr_FLrnClCtl_posnReturnLihSp_C;                             */
/*  input uint16 Thr_FLrnClCtl_posnIniLoThruSp_C;                             */
/*  input uint16 Thr_FLrnClCtl_posnIniHiThruSp_C;                             */
/*  input uint16 Thr_FClnClCtl_vExiLoThru_C;                                  */
/*  input uint16 Thr_FLrnClCtl_vHiThru_C;                                     */
/*  input uint16 Thr_FLrnClCtl_vIniHiThru_C;                                  */
/*  input uint16 Thr_FLrnClCtl_vIniLoThru_C;                                  */
/*  input uint16 Thr_FLrnClCtl_vLoThru_C;                                     */
/*  input uint16 Thr_FLrnClCtl_vReturnLih_C;                                  */
/*  output uint16 Thr_FLrnClCtl_posnExiLoThruSp;                              */
/*  output uint16 Thr_FLrnClCtl_posnHiThruSp;                                 */
/*  output uint16 Thr_FLrnClCtl_posnLoThruSp;                                 */
/*  output uint16 Thr_FLrnClCtl_posnReturnLihSp;                              */
/*  output uint16 Thr_FLrnClCtl_posnIniLoThruSp;                              */
/*  output uint16 Thr_FLrnClCtl_posnIniHiThruSp;                              */
/*  output uint16 Thr_FLrnClCtl_vExiLoThru;                                   */
/*  output uint16 Thr_FLrnClCtl_vHiThru;                                      */
/*  output uint16 Thr_FLrnClCtl_vIniHiThru;                                   */
/*  output uint16 Thr_FLrnClCtl_vIniLoThru;                                   */
/*  output uint16 Thr_FLrnClCtl_vLoThru;                                      */
/*  output uint16 Thr_FLrnClCtl_vReturnLih;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidCalibration(void)
{
   boolean  bLocalThr_bFClnInProgs;
   boolean  bLocalTpac_FCln_enable;


   VEMS_vidGET(Thr_bFClnInProgs, bLocalThr_bFClnInProgs);
   VEMS_vidGET(Tpac_FCln_enable, bLocalTpac_FCln_enable);

   if (  (bLocalThr_bFClnInProgs != 0)
      && (bLocalTpac_FCln_enable != 0))
   {
      Thr_FLrnClCtl_posnExiLoThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_posnExiLoThruSp_C, 1024);
      Thr_FLrnClCtl_posnHiThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_posnHiThruSp_C, 1024);
      Thr_FLrnClCtl_posnLoThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_posnLoThruSp_C, 1024);
      Thr_FLrnClCtl_posnReturnLihSp =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_posnReturnLihSp_C, 1024);
      Thr_FLrnClCtl_posnIniLoThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_posnIniLoThruSp_C, 1024);
      Thr_FLrnClCtl_posnIniHiThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_posnIniHiThruSp_C, 1024);
      Thr_FLrnClCtl_vExiLoThru =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vExiLoThru_C, 1024);
      Thr_FLrnClCtl_vHiThru =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_vHiThru_C, 1024);
      Thr_FLrnClCtl_vIniHiThru =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_vIniHiThru_C, 1024);
      Thr_FLrnClCtl_vIniLoThru =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_vIniLoThru_C, 1024);
      Thr_FLrnClCtl_vLoThru =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_vLoThru_C, 1024);
      Thr_FLrnClCtl_vReturnLih =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_vReturnLih_C, 1024);
   }
   else
   {
      Thr_FLrnClCtl_posnExiLoThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnExiLoThruSp_C, 1024);
      Thr_FLrnClCtl_posnHiThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnHiThruSp_C, 1024);
      Thr_FLrnClCtl_posnLoThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnLoThruSp_C, 1024);
      Thr_FLrnClCtl_posnReturnLihSp =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnReturnLihSp_C, 1024);
      Thr_FLrnClCtl_posnIniLoThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnIniLoThruSp_C, 1024);
      Thr_FLrnClCtl_posnIniHiThruSp =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnIniHiThruSp_C, 1024);
      Thr_FLrnClCtl_vExiLoThru =
         (uint16)MATHSRV_udtMIN(Thr_FClnClCtl_vExiLoThru_C, 1024);
      Thr_FLrnClCtl_vHiThru =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vHiThru_C, 1024);
      Thr_FLrnClCtl_vIniHiThru =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vIniHiThru_C, 1024);
      Thr_FLrnClCtl_vIniLoThru =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vIniLoThru_C, 1024);
      Thr_FLrnClCtl_vLoThru =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vLoThru_C, 1024);
      Thr_FLrnClCtl_vReturnLih =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_vReturnLih_C, 1024);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidSlewRate                                   */
/* !Description :  La consigne de position papillon pour l’apprentissage des  */
/*                 butées (ou pour le nettoyage du BPM) est appliquée dès que */
/*                 Thr_FLrnClCtl_bAcv passe à 1.                              */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16SlewFilter(????);                                         */
/*  input boolean Thr_FLrnClCtl_bAcv;                                         */
/*  input uint16 Thr_FLrnClCtl_vTar;                                          */
/*  input uint16 Thr_SampleTiMid_physVal;                                     */
/*  input uint16 Thr_FLrnClCtl_posnSp;                                        */
/*  input uint16 Thr_FLrnClCtl_posnTar;                                       */
/*  output uint16 Thr_SampleTiMid_physVal;                                    */
/*  output uint16 Thr_FLrnClCtl_posnSp;                                       */
/*  output uint16 Thr_FClnClCtl_posnSp;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidSlewRate(void)
{
   boolean  bLocalThr_FLrnClCtl_bAcv;
   uint16   u16LocalSlewRateOutput;
   uint16   u16LocalSlewRateIncValue;
   uint16   u16LocalThr_FLrnClCtl_posnSp;


   VEMS_vidGET(Thr_FLrnClCtl_bAcv, bLocalThr_FLrnClCtl_bAcv);

   if (bLocalThr_FLrnClCtl_bAcv != 0)
   {
      Thr_SampleTiMid_physVal = Thr_SampleTiMid_SC;
      u16LocalSlewRateIncValue = (uint16)( ( Thr_FLrnClCtl_vTar
                                           * Thr_SampleTiMid_physVal)
                                         / 1000);
      u16LocalSlewRateOutput = Thr_FLrnClCtl_posnSp;
      u16LocalSlewRateOutput = MATHSRV_u16SlewFilter(u16LocalSlewRateOutput,
                                                     Thr_FLrnClCtl_posnTar,
                                                     u16LocalSlewRateIncValue,
                                                     u16LocalSlewRateIncValue);
   }
   else
   {
      u16LocalSlewRateOutput = Thr_FLrnClCtl_posnTar;
   }
   u16LocalThr_FLrnClCtl_posnSp =
      (uint16)MATHSRV_udtMIN(u16LocalSlewRateOutput, 1024);
   Thr_FLrnClCtl_posnSp = u16LocalThr_FLrnClCtl_posnSp;
   Thr_FClnClCtl_posnSp = u16LocalThr_FLrnClCtl_posnSp;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSNSPLRN_vidFinalSpcSp                                 */
/* !Description :  Une consigne spécifique correspondant à l’une des fonctions*/
/*                 (apprentissage, nettoyage ou restauration de la mobilité)  */
/*                 est calculée.                                              */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bMblRstorInProgs;                                       */
/*  input boolean Thr_FLrnClCtl_bAcv;                                         */
/*  input uint16 Thr_FMblRstorClCtl_posnSp;                                   */
/*  input uint16 Thr_FLrnClCtl_posnSp;                                        */
/*  output uint16 Thr_FSpcReqClCtl_posnSp;                                    */
/*  output boolean Thr_FSpcReqClCtl_bAcv;                                     */
/*  output boolean Thr_FClnClCtl_bAcv;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSNSPLRN_vidFinalSpcSp(void)
{
   boolean  bLocalThr_bMblRstorInProgs;
   boolean  bLocalThr_FLrnClCtl_bAcv;
   uint16   u16LocalThrFSpcReqClCtlPosnSp;


   VEMS_vidGET(Thr_bMblRstorInProgs, bLocalThr_bMblRstorInProgs);
   VEMS_vidGET(Thr_FLrnClCtl_bAcv, bLocalThr_FLrnClCtl_bAcv);

   if (bLocalThr_bMblRstorInProgs != 0)
   {
      u16LocalThrFSpcReqClCtlPosnSp =
         (uint16)MATHSRV_udtMIN(Thr_FMblRstorClCtl_posnSp, 1024);
   }
   else
   {
      u16LocalThrFSpcReqClCtlPosnSp =
         (uint16)MATHSRV_udtMIN(Thr_FLrnClCtl_posnSp, 1024);
   }
   VEMS_vidSET(Thr_FSpcReqClCtl_posnSp, u16LocalThrFSpcReqClCtlPosnSp);
   if (  (bLocalThr_bMblRstorInProgs != 0)
      || (bLocalThr_FLrnClCtl_bAcv != 0))
   {
      VEMS_vidSET(Thr_FSpcReqClCtl_bAcv, 1);
   }
   else
   {
      VEMS_vidSET(Thr_FSpcReqClCtl_bAcv, 0);
   }
   VEMS_vidSET(Thr_FClnClCtl_bAcv, bLocalThr_FLrnClCtl_bAcv);
}
/*----------------------------- end of file ----------------------------------*/