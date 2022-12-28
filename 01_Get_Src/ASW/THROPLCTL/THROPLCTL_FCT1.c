/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THROPLCTL                                               */
/* !Description     : THROPLCTL Component.                                    */
/*                                                                            */
/* !Module          : THROPLCTL                                               */
/* !Description     : COMMANDE EN BOUCLE OUVERTE DU PAPILLON                  */
/*                                                                            */
/* !File            : THROPLCTL_FCT1.C                                        */
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
/*   1 / THROPLCTL_vidInitOutput                                              */
/*   2 / THROPLCTL_vidInit                                                    */
/*   3 / THROPLCTL_vidConditions                                              */
/*   4 / THROPLCTL_vidInitOpeningRamp                                         */
/*   5 / THROPLCTL_vidInitClosingRamp                                         */
/*   6 / THROPLCTL_vidInitExitLowThrust                                       */
/*   7 / THROPLCTL_vidInitMcwInh                                              */
/*   8 / THROPLCTL_vidCalcMcwInh                                              */
/*   9 / THROPLCTL_vidInitMcpInh                                              */
/*                                                                            */
/* !Reference   : V02 NT 08 04793 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THROPLCTL/THROPLCTL_FCT1.C_v$*/
/* $Revision::   1.1      $$Author::   FMERAH1        $$Date::   Apr 19 2012 $*/
/* $Author::   FMERAH1                                $$Date::   Apr 19 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THROPLCTL.h"
#include "THROPLCTL_L.h"
#include "THROPLCTL_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidInitOutput                                    */
/* !Description :  Initialisation des sorties du composant software ThrOplCtl */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 THROPLCTL_u8TpacThrotCtrlStPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidInitOutput(void)
{
   THROPLCTL_u8TpacThrotCtrlStPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidInit                                          */
/* !Description :  Lors de la recherche de butée, la tension de commande est  */
/*                 initialisée à une valeur correspondant à la butée  haute   */
/*                 lorsque le contact entre le volet et la butée haute est    */
/*                 autorisé                                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Tpac_open_loop_control;                                    */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidInit(void)
{
   VEMS_vidSET(Tpac_open_loop_control, 1);
   VEMS_vidSET(Tpac_open_loop_control_voltage,
               (sint16)TPAC_NULL_CONTROL_VOLTAGE);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidConditions                                    */
/* !Description :  Bloc permettant la genération du flag de commande en boucle*/
/*                 ouverte du PAPMOT et l'appel des deux événements de passage*/
/*                 d'une commande en boucle ouverte à une commande en boucle  */
/*                 fermée du papillon                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THROPLCTL_vidInitExitLowThrust();                        */
/*  extf argret void THROPLCTL_vidInitClosingRamp();                          */
/*  extf argret void THROPLCTL_vidInitOpeningRamp();                          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Thr_EveOplCllEna_ThrSpPosn();                            */
/*  extf argret void Thr_EveOplCllEna_ThrAbsSpPosn();                         */
/*  input boolean Tpac_open_loop_control;                                     */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input uint8 THROPLCTL_u8TpacThrotCtrlStPrev;                              */
/*  input boolean Thr_FLrnClCtl_bAcv;                                         */
/*  output boolean Tpac_open_loop_control;                                    */
/*  output uint8 THROPLCTL_u8TpacThrotCtrlStPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidConditions(void)
{
   boolean bLocalThr_FLrnClCtl_bAcv;
   boolean bLocalOpenLoopCtrl;
   boolean bLocalControlState;
   uint8   u8LocalTpac_thr_control_state;


   VEMS_vidGET(Tpac_open_loop_control, bLocalOpenLoopCtrl);
   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);
   switch (u8LocalTpac_thr_control_state)
   {
      case TPAC_LIMP_HOME :
         bLocalControlState = 1;
         break;

      case TPAC_MCW_INHIBIT_TEST :
         bLocalControlState = 1;
         break;

      case TPAC_EXIT_LOW_THRUST :
         if (THROPLCTL_u8TpacThrotCtrlStPrev != TPAC_EXIT_LOW_THRUST)
         {
            THROPLCTL_vidInitExitLowThrust();
         }
         bLocalControlState = 1;
         break;

      case TPAC_CLOSING_RAMP :
         if (THROPLCTL_u8TpacThrotCtrlStPrev != TPAC_CLOSING_RAMP)
         {
            THROPLCTL_vidInitClosingRamp();
         }
         bLocalControlState = 1;
         break;

      case TPAC_HIGH_THRUST_SEARCH :
         if (THROPLCTL_u8TpacThrotCtrlStPrev != TPAC_HIGH_THRUST_SEARCH)
         {
            THROPLCTL_vidInitOpeningRamp();
         }
         bLocalControlState = 1;
         break;

      case TPAC_WAIT_FOR_ADC:
         bLocalControlState = 1;
         break;

      default:
         bLocalControlState = 0;
         break;
   }
   VEMS_vidGET(Thr_FLrnClCtl_bAcv, bLocalThr_FLrnClCtl_bAcv);
   if (  (bLocalControlState != 0)
      && (bLocalThr_FLrnClCtl_bAcv == 0))
   {
      VEMS_vidSET(Tpac_open_loop_control, 1);
   }
   else
   {
      VEMS_vidSET(Tpac_open_loop_control, 0);
      if (bLocalOpenLoopCtrl != 0)
      {
         Thr_EveOplCllEna_ThrSpPosn();
         Thr_EveOplCllEna_ThrAbsSpPosn();
      }
   }
   THROPLCTL_u8TpacThrotCtrlStPrev = u8LocalTpac_thr_control_state;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidInitOpeningRamp                               */
/* !Description :  Lors de la recherche de butée haute, la tension de commande*/
/*                 est initialisée à une valeur nulle de manière à appliquer  */
/*                 un couple nul.                                             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidInitOpeningRamp(void)
{
   VEMS_vidSET(Tpac_open_loop_control_voltage, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidInitClosingRamp                               */
/* !Description :  Lors de la recherche de butée, la tension de commande est  */
/*                 initialisée à une valeur de la butée haute lorsque le      */
/*                 contact entre le volet et la butée haute est               */
/*                 autorisé.Lorsque la recherche de butée haute est inhibé on */
/*                 initialise la tension de commande à 0.                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Tpac_open_thrust_search_inh;                                */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidInitClosingRamp(void)
{
   sint16 s16LocalTpac_loop_ctrl_vltg;


   if (Tpac_open_thrust_search_inh != 0)
   {
      s16LocalTpac_loop_ctrl_vltg = (sint16)TPAC_NULL_CONTROL_VOLTAGE;
      VEMS_vidSET(Tpac_open_loop_control_voltage, s16LocalTpac_loop_ctrl_vltg);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidInitExitLowThrust                             */
/* !Description :  Lors de la sortie de butée basse, la tension de commande   */
/*                 est initialisée à la valeur correspondant à la butée basse.*/
/*                 On initialise aussi la temporisation de sortie de butée    */
/*                 basse.                                                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Tpac_closed_thrust_control_volt;                             */
/*  input uint8 Tpac_exit_low_thrust_delay2;                                  */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*  output sint16 Tpac_closed_thrust_control_volt;                            */
/*  output uint8 Tpac_exit_low_thrust_tempo;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidInitExitLowThrust(void)
{
/*3_Init_exit_low_thrust*/
   VEMS_vidSET(Tpac_open_loop_control_voltage, Tpac_closed_thrust_control_volt);
   Tpac_exit_low_thrust_tempo =
      (uint8)MATHSRV_udtMIN(Tpac_exit_low_thrust_delay2, 250);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidInitMcwInh                                    */
/* !Description :  Pour le test de «l’inhibit» du microcontrôleur secondaire, */
/*                 on applique une tension calibrable de manière à faire      */
/*                 dévier le papillon de sa position d’équilibre. Si          */
/*                 «l’inhibit» est opérationnel, le papillon doit être en     */
/*                 position limphome.                                         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THROPLCTL_vidCalcMcwInh();                               */
/*  input st01 Tpac_throttle_control_state;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidInitMcwInh(void)
{
   uint8   u8LocalTpac_thr_control_state;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);

   if (u8LocalTpac_thr_control_state == TPAC_MCW_INHIBIT_TEST)
   {
      THROPLCTL_vidCalcMcwInh();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidCalcMcwInh                                    */
/* !Description :  Pour test 1 de « l’inhibit » du microcontrôleur secondaire,*/
/*                 on applique 0 V.Pour test 2, on applique une tension       */
/*                 calibrable de manière à faire dévier le papillon de sa     */
/*                 position  d’équilibre.                                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Tpim_filtered_inhibit_input;                                */
/*  input boolean Thr_bAcv_TestInhThr;                                        */
/*  input sint16 Tpac_mcw_inh_test_control_volt;                              */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*  output sint16 Tpac_mcw_inh_test_control_volt;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidCalcMcwInh(void)
{
   boolean bLocalTpim_filtered_inhib_input;
   boolean bLocalThr_bAcv_TestInhThr;
   sint16  s16LocalTpac_loop_ctrl_vltg;


   VEMS_vidGET(Tpim_filtered_inhibit_input, bLocalTpim_filtered_inhib_input);
   VEMS_vidGET(Thr_bAcv_TestInhThr, bLocalThr_bAcv_TestInhThr);

   if (  (bLocalThr_bAcv_TestInhThr != 0)
      && (bLocalTpim_filtered_inhib_input != 0))
   {
      VEMS_vidSET(Tpac_open_loop_control_voltage,
                  Tpac_mcw_inh_test_control_volt);
   }
   else
   {
      s16LocalTpac_loop_ctrl_vltg = (sint16)TPAC_NULL_CONTROL_VOLTAGE;
      VEMS_vidSET(Tpac_open_loop_control_voltage,
                  s16LocalTpac_loop_ctrl_vltg);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidInitMcpInh                                    */
/* !Description :  Lorsque le système entre en limp-home, on initialise la    */
/*                 tension en boucle ouverte de commande.                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidInitMcpInh(void)
{
   uint8   u8LocalTpac_thr_control_state;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);
   if (u8LocalTpac_thr_control_state == TPAC_LIMP_HOME)
   {
      VEMS_vidSET(Tpac_open_loop_control_voltage,
                 (sint16)TPAC_NULL_CONTROL_VOLTAGE);
   }
}

/*----------------------------- end of file ----------------------------------*/