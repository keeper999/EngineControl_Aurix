/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSERVODIAG                                            */
/* !Description     : THRSERVODIAG Component                                  */
/*                                                                            */
/* !Module          : THRSERVODIAG                                            */
/* !Description     : Diagnostic de l'asservissement de la position du        */
/*                    Papillon Motorisé                                       */
/*                                                                            */
/* !File            : THRSERVODIAG_FCT1.c                                     */
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
/*   1 / THRSERVODIAG_vidInitOutput                                           */
/*   2 / THRSERVODIAG_vidSerFailDetection                                     */
/*   3 / THRSERVODIAG_vidDifThrDgDataCal                                      */
/*   4 / THRSERVODIAG_vidDifThrPoDgFrAfSl                                     */
/*   5 / THRSERVODIAG_vidDifThrPosDiag                                        */
/*                                                                            */
/* !Reference   : V02 NT 08 04530 / 5                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSERVODIAG/THRSERVODIAG_FC$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   04 Apr 2013 $*/
/* $Author::   etsasson                               $$Date::   04 Apr 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRSERVODIAG.h"
#include "THRSERVODIAG_L.h"
#include "THRSERVODIAG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVODIAG_vidInitOutput                                 */
/* !Description :  Initialisation des variables internes au module            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  output uint16 Tpac_filtered_position_error_sc;                            */
/*  output uint32 THRSERVODIAG_u32FiltPosErrorMem;                            */
/*  output uint8 THRSERVODIAG_u8TpacThrCtrlStPrev;                            */
/*  output uint16 THRSERVODIAG_u16ServFailDiagTemp;                           */
/*  output boolean THRSERVODIAG_bServoFailDiagOut;                            */
/*  output boolean THRSERVODIAG_bAbsPosErrORng_Prev;                          */
/*  output boolean Thr_bAbsPosnErrORng;                                       */
/*  output uint16 THRSERVODIAG_u16ServFailDetTempo;                           */
/*  output uint16 THRSERVODIAG_u16ServFailDetTemp2;                           */
/*  output boolean THRSERVODIAG_bServoFailDetectOut;                          */
/*  output boolean THRSERVODIAG_bServoFailDetecOut2;                          */
/*  output boolean THRSERVODIAG_bCtlrIntORng_Prev;                            */
/*  output boolean Thr_bCtlrIntORng;                                          */
/*  output uint16 THRSERVODIAG_u16IntegrFailTempo;                            */
/*  output uint16 THRSERVODIAG_u16IntegrFailTemp2;                            */
/*  output boolean THRSERVODIAG_bEnaFailDetPrev;                              */
/*  output boolean THRSERVODIAG_bIntegralFailOut;                             */
/*  output boolean THRSERVODIAG_bIntegralFailOut2;                            */
/*  output uint16 THRSERVODIAG_u16PosnMaxErrThd;                              */
/*  output boolean THRSERVODIAG_bposnMaxErrTimerPrv;                          */
/*  output boolean THRSERVODIAG_bposnMaxErrTimer;                             */
/*  output boolean THRSERVODIAG_bCtlrIntORngTimerPr;                          */
/*  output boolean THRSERVODIAG_bCtlrIntORngTimer;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVODIAG_vidInitOutput(void)
{
   uint8 u8LocalTpac_throttle_control_st;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_st);
   Tpac_filtered_position_error_sc = 0;
   THRSERVODIAG_u32FiltPosErrorMem = 0;

   THRSERVODIAG_u8TpacThrCtrlStPrev = u8LocalTpac_throttle_control_st;
   THRSERVODIAG_u16ServFailDiagTemp = 0;
   THRSERVODIAG_bServoFailDiagOut = 0;

   THRSERVODIAG_bAbsPosErrORng_Prev = 0;
   Thr_bAbsPosnErrORng = 0;
   THRSERVODIAG_u16ServFailDetTempo = 0;
   THRSERVODIAG_u16ServFailDetTemp2 = 0;
   THRSERVODIAG_bServoFailDetectOut = 0;
   THRSERVODIAG_bServoFailDetecOut2 = 0;

   THRSERVODIAG_bCtlrIntORng_Prev = 0;
   Thr_bCtlrIntORng = 0;
   THRSERVODIAG_u16IntegrFailTempo = 0;
   THRSERVODIAG_u16IntegrFailTemp2 = 0;
   THRSERVODIAG_bEnaFailDetPrev = 0;
   THRSERVODIAG_bIntegralFailOut = 0;
   THRSERVODIAG_bIntegralFailOut2 = 0;

   THRSERVODIAG_u16PosnMaxErrThd = 0;

   THRSERVODIAG_bposnMaxErrTimerPrv = 0;
   THRSERVODIAG_bposnMaxErrTimer = 0;

   THRSERVODIAG_bCtlrIntORngTimerPr = 0;
   THRSERVODIAG_bCtlrIntORngTimer = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVODIAG_vidSerFailDetection                           */
/* !Description :  Pour empêcher des pannes intempestives en apprentissage de */
/*                 butées ou en fin d’apprentissage, on autorise le diagnostic*/
/*                 d’asservissement du papillon lorsque l'automate est passé  */
/*                 en état TPAC_CONTROL(boucle fermée) depuis une             */
/*                 temporisation.                                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSERVODIAG_vidDifThrDgDataCal();                       */
/*  extf argret void THRSERVODIAG_vidDifThrPoDgFrAfSl();                      */
/*  extf argret void THRSERVODIAG_vidDifThrPosDiag();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVODIAG_vidSerFailDetection(void)
{
   THRSERVODIAG_vidDifThrDgDataCal();
   THRSERVODIAG_vidDifThrPoDgFrAfSl();
   THRSERVODIAG_vidDifThrPosDiag();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVODIAG_vidDifThrDgDataCal                            */
/* !Description :  Ce bloc engendre les données et les conditions nécessaires */
/*                 à la réalisation des diagnostics de l’asservissement du    */
/*                 papillon motorisé.                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf MATHSRV_u16FirstOrderFilterGu8(????);                                */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input sint16 Tpac_position_error;                                         */
/*  input uint8 THRSERVODIAG_u8TpacThrCtrlStPrev;                             */
/*  input uint16 Tpac_servo_failure_diag_delay;                               */
/*  input uint16 THRSERVODIAG_u16ServFailDiagTemp;                            */
/*  input boolean THRSERVODIAG_bServoFailDiagOut;                             */
/*  input boolean Enable_servoing_failure_detect;                             */
/*  input boolean THRSERVODIAG_bEnaFailDetPrev;                               */
/*  input uint8 Tpac_position_error_filter_gain;                              */
/*  input uint32 THRSERVODIAG_u32FiltPosErrorMem;                             */
/*  output uint16 THRSERVODIAG_u16ServFailDiagTemp;                           */
/*  output boolean THRSERVODIAG_bServoFailDiagOut;                            */
/*  output boolean Enable_servoing_failure_detect;                            */
/*  output boolean Thr_bMonRunORngServo;                                      */
/*  output uint16 Tpac_filtered_position_error_sc;                            */
/*  output uint32 THRSERVODIAG_u32FiltPosErrorMem;                            */
/*  output boolean Tpac_bClCtlErrSignPos;                                     */
/*  output boolean THRSERVODIAG_bEnaFailDetPrev;                              */
/*  output uint8 THRSERVODIAG_u8TpacThrCtrlStPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVODIAG_vidDifThrDgDataCal(void)
{
   boolean bLocalInhDiag_inhThrServoDiag;
   uint8   u8LocalTpac_throttle_control_st;
   uint16  u16LocalCounter;
   uint16  u16LocalFiltred;
   uint16  u16LocalABS1;
   sint16  s16LocalTpac_position_error;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_st);
   VEMS_vidGET(Tpac_position_error, s16LocalTpac_position_error);
   bLocalInhDiag_inhThrServoDiag =
      GDGAR_bGetFRM(FRM_FRM_INHDIAG_INHTHRSERVODIAG);
   if (  (THRSERVODIAG_u8TpacThrCtrlStPrev != TPAC_CONTROL)
      && (u8LocalTpac_throttle_control_st == TPAC_CONTROL))
   {
      THRSERVODIAG_u16ServFailDiagTemp =
         (uint16)MATHSRV_udtMIN(Tpac_servo_failure_diag_delay, 256);
      if (THRSERVODIAG_u16ServFailDiagTemp == 0)
      {
         THRSERVODIAG_bServoFailDiagOut = 1;
      }
      else
      {
         THRSERVODIAG_bServoFailDiagOut = 0;
      }
   }
   else
   {
      if (THRSERVODIAG_u16ServFailDiagTemp > 0)
      {
         u16LocalCounter = (uint16)(THRSERVODIAG_u16ServFailDiagTemp - 1);
         THRSERVODIAG_u16ServFailDiagTemp =
            (uint16)MATHSRV_udtMIN(u16LocalCounter, 256);
         if (THRSERVODIAG_u16ServFailDiagTemp == 0)
         {
            THRSERVODIAG_bServoFailDiagOut = 1;
         }
         else
         {
            THRSERVODIAG_bServoFailDiagOut = 0;
         }
      }
   }
   if (  (u8LocalTpac_throttle_control_st == TPAC_CONTROL)
      && (THRSERVODIAG_bServoFailDiagOut != 0))
   {
      Enable_servoing_failure_detect = 1;
   }
   else
   {
      Enable_servoing_failure_detect = 0;
   }

   if (  (Enable_servoing_failure_detect != 0)
      && (bLocalInhDiag_inhThrServoDiag == 0))
   {
      Thr_bMonRunORngServo = 1;
   }
   else
   {
      Thr_bMonRunORngServo = 0;
   }
   if (  (Enable_servoing_failure_detect != 0)
      && (THRSERVODIAG_bEnaFailDetPrev == 0))
   {
      Tpac_filtered_position_error_sc = 0;
      THRSERVODIAG_u32FiltPosErrorMem = 0;
   }
   else
   {
      u16LocalABS1 = (uint16)MATHSRV_udtABS(s16LocalTpac_position_error);
      u16LocalFiltred =
         MATHSRV_u16FirstOrderFilterGu8(Tpac_position_error_filter_gain,
                                        &THRSERVODIAG_u32FiltPosErrorMem,
                                        u16LocalABS1);
      Tpac_filtered_position_error_sc =
         (uint16)MATHSRV_udtMIN(u16LocalFiltred, 1024);
   }
   if (s16LocalTpac_position_error < 0)
   {
      Tpac_bClCtlErrSignPos = 1;
   }
   else
   {
      Tpac_bClCtlErrSignPos = 0;
   }
   THRSERVODIAG_bEnaFailDetPrev = Enable_servoing_failure_detect;
   THRSERVODIAG_u8TpacThrCtrlStPrev = u8LocalTpac_throttle_control_st;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVODIAG_vidDifThrPoDgFrAfSl                           */
/* !Description :  La surveillance de l’écart de boucle pour les services     */
/*                 après vente est réalisée par une comparaison de la valeur  */
/*                 absolue de l’erreur (ou de l’intégrale de l’erreur)        */
/*                 d’asservissement à un seuil calibrable.                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 Thr_VehSpdThdHi_C;                                            */
/*  input uint16 Thr_posnMaxErrHi_C;                                          */
/*  input uint8 Thr_VehSpdThdLo_C;                                            */
/*  input uint16 Thr_posnMaxErrLo_C;                                          */
/*  input boolean Thr_bMonRunORngServo;                                       */
/*  input uint16 Tpac_filtered_position_error_sc;                             */
/*  input uint16 THRSERVODIAG_u16PosnMaxErrThd;                               */
/*  input sint16 Tpac_integral_output;                                        */
/*  input uint16 Tpac_integral_failure_jc_thresh;                             */
/*  input boolean THRSERVODIAG_bAbsPosErrORng_Prev;                           */
/*  input boolean Thr_bAbsPosnErrORng;                                        */
/*  input uint16 Tpac_servo_failure_detect_delay;                             */
/*  input uint16 THRSERVODIAG_u16ServFailDetTempo;                            */
/*  input boolean THRSERVODIAG_bCtlrIntORng_Prev;                             */
/*  input boolean Thr_bCtlrIntORng;                                           */
/*  input uint16 Tpac_integral_failure_delay;                                 */
/*  input uint16 THRSERVODIAG_u16IntegrFailTempo;                             */
/*  input boolean THRSERVODIAG_bServoFailDetectOut;                           */
/*  input boolean THRSERVODIAG_bIntegralFailOut;                              */
/*  output uint16 THRSERVODIAG_u16PosnMaxErrThd;                              */
/*  output boolean Thr_bAbsPosnErrORng;                                       */
/*  output boolean Thr_bCtlrIntORng;                                          */
/*  output uint16 THRSERVODIAG_u16ServFailDetTempo;                           */
/*  output boolean THRSERVODIAG_bServoFailDetectOut;                          */
/*  output uint16 THRSERVODIAG_u16IntegrFailTempo;                            */
/*  output boolean THRSERVODIAG_bIntegralFailOut;                             */
/*  output boolean Thr_bDgoORngServo;                                         */
/*  output boolean THRSERVODIAG_bAbsPosErrORng_Prev;                          */
/*  output boolean THRSERVODIAG_bCtlrIntORng_Prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVODIAG_vidDifThrPoDgFrAfSl(void)
{
   uint8  u8LocalVitesse_vehicule;
   uint16 u16LocalABS1;
   uint16 u16LocalIntegerTempo;
   uint16 u16LocalServTempo;
   sint16 s16LocalTpac_integral_output;


   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   if (u8LocalVitesse_vehicule > Thr_VehSpdThdHi_C)
   {
      THRSERVODIAG_u16PosnMaxErrThd = Thr_posnMaxErrHi_C;
   }
   else
   {
      if (u8LocalVitesse_vehicule <= Thr_VehSpdThdLo_C)
      {
         THRSERVODIAG_u16PosnMaxErrThd = Thr_posnMaxErrLo_C;
      }
   }

   if (Thr_bMonRunORngServo != 0)
   {
      if (Tpac_filtered_position_error_sc >= THRSERVODIAG_u16PosnMaxErrThd)
      {
         Thr_bAbsPosnErrORng = 1;
      }
      else
      {
         Thr_bAbsPosnErrORng = 0;
      }

      VEMS_vidGET(Tpac_integral_output, s16LocalTpac_integral_output);
      u16LocalABS1 = (uint16)MATHSRV_udtABS(s16LocalTpac_integral_output);
      if (u16LocalABS1 >= Tpac_integral_failure_jc_thresh)
      {
         Thr_bCtlrIntORng = 1;
      }
      else
      {
         Thr_bCtlrIntORng = 0;
      }
   }
   else
   {
      Thr_bCtlrIntORng = 0;
      Thr_bAbsPosnErrORng = 0;
   }

   if (  (THRSERVODIAG_bAbsPosErrORng_Prev == 0)
      && (Thr_bAbsPosnErrORng != 0))
   {
      THRSERVODIAG_u16ServFailDetTempo =
         (uint16)MATHSRV_udtMIN(Tpac_servo_failure_detect_delay, 256);
      if (THRSERVODIAG_u16ServFailDetTempo == 0)
      {
         THRSERVODIAG_bServoFailDetectOut = 1;
      }
      else
      {
         THRSERVODIAG_bServoFailDetectOut = 0;
      }
   }
   else
   {
      if (THRSERVODIAG_u16ServFailDetTempo > 0)
      {
         u16LocalServTempo = (uint16)(THRSERVODIAG_u16ServFailDetTempo - 1);
         THRSERVODIAG_u16ServFailDetTempo =
            (uint16)MATHSRV_udtMIN(u16LocalServTempo, 256);
         if (THRSERVODIAG_u16ServFailDetTempo == 0)
         {
            THRSERVODIAG_bServoFailDetectOut = 1;
         }
         else
         {
            THRSERVODIAG_bServoFailDetectOut = 0;
         }
      }
   }
   if (  (THRSERVODIAG_bCtlrIntORng_Prev == 0)
      && (Thr_bCtlrIntORng != 0))
   {
      THRSERVODIAG_u16IntegrFailTempo =
         (uint16)MATHSRV_udtMIN(Tpac_integral_failure_delay, 256);
      if (THRSERVODIAG_u16IntegrFailTempo == 0)
      {
         THRSERVODIAG_bIntegralFailOut = 1;
      }
      else
      {
         THRSERVODIAG_bIntegralFailOut = 0;
      }
   }
   else
   {
      if (THRSERVODIAG_u16IntegrFailTempo > 0)
      {
         u16LocalIntegerTempo = (uint16)(THRSERVODIAG_u16IntegrFailTempo - 1);
         THRSERVODIAG_u16IntegrFailTempo =
            (uint16)MATHSRV_udtMIN(u16LocalIntegerTempo, 256);
         if (THRSERVODIAG_u16IntegrFailTempo == 0)
         {
            THRSERVODIAG_bIntegralFailOut = 1;
         }
         else
         {
            THRSERVODIAG_bIntegralFailOut = 0;
         }
      }
   }
   if (  (  (Thr_bAbsPosnErrORng != 0)
         && (THRSERVODIAG_bServoFailDetectOut != 0))
      || (  (Thr_bCtlrIntORng != 0)
         && (THRSERVODIAG_bIntegralFailOut != 0)))
   {
      Thr_bDgoORngServo = 1;
   }
   else
   {
      Thr_bDgoORngServo = 0;
   }
   THRSERVODIAG_bAbsPosErrORng_Prev = Thr_bAbsPosnErrORng;
   THRSERVODIAG_bCtlrIntORng_Prev = Thr_bCtlrIntORng;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSERVODIAG_vidDifThrPosDiag                              */
/* !Description :  ce diagnostic permet de prévenir contre les dérives        */
/*                 positives et négatives de l’écart (consigne-mesure) de     */
/*                 commande du BPM.                                           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean Tpac_bClCtlErrSignPos;                                      */
/*  input uint8 Thr_VehSpdThdHiDifPos_C;                                      */
/*  input uint16 Thr_posnMaxErrHiDifPos_C;                                    */
/*  input uint8 Thr_VehSpdThdLoDifPos_C;                                      */
/*  input uint16 Thr_posnMaxErrLoDifPos_C;                                    */
/*  input uint16 Tpac_servo_Dft_detect_Dly_DifPos;                            */
/*  input uint16 Tpac_integral_failure_Dly_DifPos;                            */
/*  input uint16 Tpac_integral_Dft_jc_Thd_DifPos;                             */
/*  input uint8 Thr_VehSpdThdHiDifNeg_C;                                      */
/*  input uint16 Thr_posnMaxErrHiDifNeg_C;                                    */
/*  input uint8 Thr_VehSpdThdLoDifNeg_C;                                      */
/*  input uint16 Thr_posnMaxErrLoDifNeg_C;                                    */
/*  input uint16 Tpac_servo_Dft_detect_Dly_DifNeg;                            */
/*  input uint16 Tpac_integral_failure_Dly_DifNeg;                            */
/*  input uint16 Tpac_integral_Dft_jc_Thd_DifNeg;                             */
/*  input boolean Thr_bMonRunORngServo;                                       */
/*  input uint16 Tpac_filtered_position_error_sc;                             */
/*  input uint16 THRSERVODIAG_u16PosnMaxErrThd;                               */
/*  input sint16 Tpac_integral_output;                                        */
/*  input boolean THRSERVODIAG_bposnMaxErrTimerPrv;                           */
/*  input boolean THRSERVODIAG_bposnMaxErrTimer;                              */
/*  input uint16 THRSERVODIAG_u16ServFailDetTemp2;                            */
/*  input boolean THRSERVODIAG_bCtlrIntORngTimerPr;                           */
/*  input boolean THRSERVODIAG_bCtlrIntORngTimer;                             */
/*  input uint16 THRSERVODIAG_u16IntegrFailTemp2;                             */
/*  input boolean THRSERVODIAG_bServoFailDetecOut2;                           */
/*  input boolean THRSERVODIAG_bIntegralFailOut2;                             */
/*  output uint16 THRSERVODIAG_u16PosnMaxErrThd;                              */
/*  output boolean THRSERVODIAG_bposnMaxErrTimer;                             */
/*  output boolean THRSERVODIAG_bCtlrIntORngTimer;                            */
/*  output uint16 THRSERVODIAG_u16ServFailDetTemp2;                           */
/*  output boolean THRSERVODIAG_bServoFailDetecOut2;                          */
/*  output uint16 THRSERVODIAG_u16IntegrFailTemp2;                            */
/*  output boolean THRSERVODIAG_bIntegralFailOut2;                            */
/*  output boolean Thr_bDgoORngServoDifPos;                                   */
/*  output boolean Thr_bDgoORngServoDifNeg;                                   */
/*  output boolean THRSERVODIAG_bposnMaxErrTimerPrv;                          */
/*  output boolean THRSERVODIAG_bCtlrIntORngTimerPr;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSERVODIAG_vidDifThrPosDiag(void)
{
   boolean bLocalORngServo;
   uint8   u8LocalVitesse_vehicule;
   uint16  u16LocalABS1;
   uint16  u16LocalIntegerTempo;
   uint16  u16LocalServTempo;
   uint16  u16LocalDuration1;
   uint16  u16LocalDuration2;
   uint16  u16LocalIntegralDftJc;
   sint16  s16LocalTpac_integral_output;


   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   if (Tpac_bClCtlErrSignPos != 0)
   {
      if (u8LocalVitesse_vehicule > Thr_VehSpdThdHiDifPos_C)
      {
         THRSERVODIAG_u16PosnMaxErrThd = Thr_posnMaxErrHiDifPos_C;
      }
      else
      {
         if (u8LocalVitesse_vehicule <= Thr_VehSpdThdLoDifPos_C)
         {
            THRSERVODIAG_u16PosnMaxErrThd = Thr_posnMaxErrLoDifPos_C;
         }
      }
      u16LocalDuration1 = Tpac_servo_Dft_detect_Dly_DifPos;
      u16LocalDuration2 = Tpac_integral_failure_Dly_DifPos;
      u16LocalIntegralDftJc = Tpac_integral_Dft_jc_Thd_DifPos;
   }
   else
   {
      if (u8LocalVitesse_vehicule > Thr_VehSpdThdHiDifNeg_C)
      {
         THRSERVODIAG_u16PosnMaxErrThd = Thr_posnMaxErrHiDifNeg_C;
      }
      else
      {
         if (u8LocalVitesse_vehicule <= Thr_VehSpdThdLoDifNeg_C)
         {
            THRSERVODIAG_u16PosnMaxErrThd = Thr_posnMaxErrLoDifNeg_C;
         }
      }
      u16LocalDuration1 = Tpac_servo_Dft_detect_Dly_DifNeg;
      u16LocalDuration2 = Tpac_integral_failure_Dly_DifNeg;
      u16LocalIntegralDftJc = Tpac_integral_Dft_jc_Thd_DifNeg;
   }

   if (Thr_bMonRunORngServo != 0)
   {
      if (Tpac_filtered_position_error_sc >= THRSERVODIAG_u16PosnMaxErrThd)
      {
         THRSERVODIAG_bposnMaxErrTimer = 1;
      }
      else
      {
         THRSERVODIAG_bposnMaxErrTimer = 0;
      }
      VEMS_vidGET(Tpac_integral_output, s16LocalTpac_integral_output);
      u16LocalABS1 = (uint16)MATHSRV_udtABS(s16LocalTpac_integral_output);
      if (u16LocalABS1 >= u16LocalIntegralDftJc)
      {
         THRSERVODIAG_bCtlrIntORngTimer = 1;
      }
      else
      {
         THRSERVODIAG_bCtlrIntORngTimer = 0;
      }
   }
   else
   {
      THRSERVODIAG_bCtlrIntORngTimer = 0;
      THRSERVODIAG_bposnMaxErrTimer = 0;
   }

   if (  (THRSERVODIAG_bposnMaxErrTimerPrv == 0)
      && (THRSERVODIAG_bposnMaxErrTimer != 0))
   {
      THRSERVODIAG_u16ServFailDetTemp2 =
         (uint16)MATHSRV_udtMIN(u16LocalDuration1, 256);
      if (THRSERVODIAG_u16ServFailDetTemp2 == 0)
      {
         THRSERVODIAG_bServoFailDetecOut2 = 1;
      }
      else
      {
         THRSERVODIAG_bServoFailDetecOut2 = 0;
      }
   }
   else
   {
      if (THRSERVODIAG_u16ServFailDetTemp2 > 0)
      {
         u16LocalServTempo = (uint16)(THRSERVODIAG_u16ServFailDetTemp2 - 1);
         THRSERVODIAG_u16ServFailDetTemp2 =
            (uint16)MATHSRV_udtMIN(u16LocalServTempo, 256);
         if (THRSERVODIAG_u16ServFailDetTemp2 == 0)
         {
            THRSERVODIAG_bServoFailDetecOut2 = 1;
         }
         else
         {
            THRSERVODIAG_bServoFailDetecOut2 = 0;
         }
      }
   }
   if (  (THRSERVODIAG_bCtlrIntORngTimerPr == 0)
      && (THRSERVODIAG_bCtlrIntORngTimer != 0))
   {
      THRSERVODIAG_u16IntegrFailTemp2 =
         (uint16)MATHSRV_udtMIN(u16LocalDuration2, 256);
      if (THRSERVODIAG_u16IntegrFailTemp2 == 0)
      {
         THRSERVODIAG_bIntegralFailOut2 = 1;
      }
      else
      {
         THRSERVODIAG_bIntegralFailOut2 = 0;
      }
   }
   else
   {
      if (THRSERVODIAG_u16IntegrFailTemp2 > 0)
      {
         u16LocalIntegerTempo = (uint16)(THRSERVODIAG_u16IntegrFailTemp2 - 1);
         THRSERVODIAG_u16IntegrFailTemp2 =
            (uint16)MATHSRV_udtMIN(u16LocalIntegerTempo, 256);
         if (THRSERVODIAG_u16IntegrFailTemp2 == 0)
         {
            THRSERVODIAG_bIntegralFailOut2 = 1;
         }
         else
         {
            THRSERVODIAG_bIntegralFailOut2 = 0;
         }
      }
   }
   if (  (  (THRSERVODIAG_bposnMaxErrTimer != 0)
         && (THRSERVODIAG_bServoFailDetecOut2 != 0))
      || (  (THRSERVODIAG_bCtlrIntORngTimer != 0)
         && (THRSERVODIAG_bIntegralFailOut2 != 0)))
   {
      bLocalORngServo = 1;
   }
   else
   {
      bLocalORngServo = 0;
   }
   if (Tpac_bClCtlErrSignPos != 0)
   {
      Thr_bDgoORngServoDifPos = bLocalORngServo;
      Thr_bDgoORngServoDifNeg = 0;
   }
   else
   {
      Thr_bDgoORngServoDifPos = 0;
      Thr_bDgoORngServoDifNeg = bLocalORngServo;
   }
   THRSERVODIAG_bposnMaxErrTimerPrv = THRSERVODIAG_bposnMaxErrTimer;
   THRSERVODIAG_bCtlrIntORngTimerPr = THRSERVODIAG_bCtlrIntORngTimer;
}
/*----------------------------- end of file ----------------------------------*/