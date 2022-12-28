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
/* !File            : THROPLCTL_FCT2.C                                        */
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
/*   1 / THROPLCTL_vidCalcOpeningRamp                                         */
/*   2 / THROPLCTL_vidCalcClosingRamp                                         */
/*   3 / THROPLCTL_vidCalcExitLowThrust                                       */
/*   4 / THROPLCTL_CalcWaitAdc                                                */
/*                                                                            */
/* !Reference   : V02 NT 08 04793 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THROPLCTL/THROPLCTL_FCT2.C_v$*/
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
/* !Function    :  THROPLCTL_vidCalcOpeningRamp                               */
/* !Description :  Pendant la recherche de butées, la tension appliquée est   */
/*                 une rampe calibrable, de manière à contrôler la vitesse    */
/*                 d’accostage sur butée, et saturée de manière à maîtriser le*/
/*                 couple appliqué sur la butée.                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input uint8 Tpac_open_loop_control_volt_step;                             */
/*  input sint16 Tpac_open_loop_control_voltage;                              */
/*  input sint16 Tpac_open_thrust_control_volt;                               */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidCalcOpeningRamp(void)
{
   uint8  u8LocalTpac_thr_control_state;
   sint16 s16LocalTpac_loop_ctrl_vltg;
   uint16 u16LocalVolt;
   sint32 s32LocalVolt;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);
   if (u8LocalTpac_thr_control_state == TPAC_HIGH_THRUST_SEARCH)
   {
      /* Changement d'unité de "Tpac_open_loop_control_volt_step"             */
      /* "Tpac_open_loop_control_volt_step" est en V/sec                      */
      /* Cette fonction est appelée tous les "Thr_SdlMid_OplCtl" --> 10 msec  */
      /* Pour ramener "Tpac_open_loop_control_volt_step" en V/10 msec         */
      /*                                                  --> Diviser par 100 */

      /* Changement de résolution de "Tpac_open_loop_control_volt_step"       */
      /* 1 dec = 0.078125 V                                                   */
      /* Il faut le convertir avec la même résolution que                     */
      /* "Tpac_open_loop_control_voltage" --> 1 dec = 0.000625 V              */
      /* 0.000625 V = 0.078125 V / 125                                        */

      /* Pour prendre en compte les changements d'unité et de résolution:     */
      /* Tpac_open_loop_control_volt_step * 125 / 100  = 5/4                  */

      u16LocalVolt =(uint16)(((Tpac_open_loop_control_volt_step * 5) + 2) / 4);
      VEMS_vidGET(Tpac_open_loop_control_voltage, s16LocalTpac_loop_ctrl_vltg);
      s32LocalVolt = (sint32)(u16LocalVolt + s16LocalTpac_loop_ctrl_vltg);

/*       s32LocalVolt = (sint32)Tpac_open_loop_control_voltage
                   + ((sint32)(uint32)Tpac_open_loop_control_volt_step); */
      s16LocalTpac_loop_ctrl_vltg =
         (sint16)MATHSRV_udtMIN(s32LocalVolt,
                                (sint32)Tpac_open_thrust_control_volt);
      VEMS_vidSET(Tpac_open_loop_control_voltage, s16LocalTpac_loop_ctrl_vltg);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidCalcClosingRamp                               */
/* !Description :  La tension appliquée pour sortir de la butée haute est une */
/*                 rampe décroissante calibrée, de manière à contrôler la     */
/*                 vitesse d’accostage sur butée, et saturée de manière à     */
/*                 maîtriser le couple appliqué sur la butée basse mécanique. */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input uint8 Tpac_open_loop_control_volt_step;                             */
/*  input sint16 Tpac_open_loop_control_voltage;                              */
/*  input sint16 Tpac_closed_thrust_control_volt;                             */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidCalcClosingRamp(void)
{
   uint8  u8LocalTpac_thr_control_state;
   sint16 s16LocalTpac_loop_ctrl_vltg;
   uint16 u16LocalVolt;
   sint32 s32LocalVolt;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);
   if (u8LocalTpac_thr_control_state == TPAC_CLOSING_RAMP)
   {
      /* Voir coeff appliqué à "Tpac_open_loop_control_volt_step" dans        */
      /* THROPLCTL_vidCalcOpeningRamp()                                       */
      u16LocalVolt = (uint16)(((Tpac_open_loop_control_volt_step * 5) + 2) / 4);
      VEMS_vidGET(Tpac_open_loop_control_voltage, s16LocalTpac_loop_ctrl_vltg);
      s32LocalVolt = (sint32)(s16LocalTpac_loop_ctrl_vltg - u16LocalVolt);

      s16LocalTpac_loop_ctrl_vltg =
         (sint16)MATHSRV_udtMAX(s32LocalVolt,
                                (sint32)Tpac_closed_thrust_control_volt);
      VEMS_vidSET(Tpac_open_loop_control_voltage, s16LocalTpac_loop_ctrl_vltg);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_vidCalcExitLowThrust                             */
/* !Description :  On pourra appliquer une pente élevée pendant un délai      */
/*                 courtde sorte que la tension de commande corresponde à une */
/*                 impulsion; ou bien la pente sera plus lente pour «         */
/*                 accompagner» le volet jusqu’au limp-home.                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  FMERAH1                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input sint16 Tpac_open_loop_control_voltage;                              */
/*  input uint8 Tpac_exit_low_thrust_tempo;                                   */
/*  input uint8 Tpac_exit_low_thrust_volt_step2;                              */
/*  input uint8 Tpac_exit_low_thrust_volt_step;                               */
/*  input sint16 Tpac_exit_low_thrust_volt_max;                               */
/*  output uint8 Tpac_exit_low_thrust_tempo;                                  */
/*  output sint16 Tpac_open_loop_control_voltage;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THROPLCTL_vidCalcExitLowThrust(void)
{
   uint8  u8LocalTpac_thr_control_state;
   uint8  u8LocalTpacExitLowThrustTempo;
   sint16 s16LocalTpac_loop_ctrl_vltg;
   sint32 s32LocalVolt;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);
   if (u8LocalTpac_thr_control_state == TPAC_EXIT_LOW_THRUST)
   {
      VEMS_vidGET(Tpac_open_loop_control_voltage, s16LocalTpac_loop_ctrl_vltg);
      if (Tpac_exit_low_thrust_tempo == 0)
      {
         /* Changement d'unité de "Tpac_exit_low_thrust_volt_step2"           */
         /* "Tpac_exit_low_thrust_volt_step2" est en V/sec                    */
         /* Cette fonction est appelée tous les "Thr_SdlMid_OplCtl"           */
         /*                                                       --> 10 msec */
         /* Pour ramener "Tpac_exit_low_thrust_volt_step2" en V/10 msec       */
         /*                                               --> Diviser par 100 */

         /* Changement de résolution de "Tpac_exit_low_thrust_volt_step2"     */
         /* 1 dec = 2 V                                                       */
         /* Il faut le convertir avec la même résolution que                  */
         /* "Tpac_open_loop_control_voltage" --> 1 dec = 0.000625 V           */
         /* 0.000625 V = 2 V / 3200                                           */

         /* Pour prendre en compte les changements d'unité et de résolution:  */
         /* Tpac_exit_low_thrust_volt_step2 * 3200 / 100                      */

         s32LocalVolt = s16LocalTpac_loop_ctrl_vltg
                      - (sint16)(Tpac_exit_low_thrust_volt_step2 * 32);
         s16LocalTpac_loop_ctrl_vltg = (sint16)MATHSRV_udtMAX(s32LocalVolt, 0);
      }
      else
      {
         s32LocalVolt = s16LocalTpac_loop_ctrl_vltg
                      + (sint16)(Tpac_exit_low_thrust_volt_step * 32);
         s16LocalTpac_loop_ctrl_vltg =
            (sint16)MATHSRV_udtMIN(s32LocalVolt, Tpac_exit_low_thrust_volt_max);

         u8LocalTpacExitLowThrustTempo = (uint8)(Tpac_exit_low_thrust_tempo
                                                - 1);
         Tpac_exit_low_thrust_tempo =
                     (uint8)MATHSRV_udtMIN(u8LocalTpacExitLowThrustTempo, 250);
      }
      VEMS_vidSET(Tpac_open_loop_control_voltage, s16LocalTpac_loop_ctrl_vltg);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THROPLCTL_CalcWaitAdc                                      */
/* !Description :  Lorsque le système entre en limp-home, on initialise la    */
/*                 tension en boucle ouverte de commande. On applique  0 V    */
/*                 pour avoir un couple nul.                                  */
/* !Number      :  FCT2.4                                                     */
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
void THROPLCTL_CalcWaitAdc(void)
{
   uint8  u8LocalTpac_thr_control_state;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_thr_control_state);
   if (u8LocalTpac_thr_control_state == TPAC_WAIT_FOR_ADC)
   {
      VEMS_vidSET(Tpac_open_loop_control_voltage,
                  (sint16)TPAC_NULL_CONTROL_VOLTAGE);
   }
}

/*----------------------------- end of file ----------------------------------*/