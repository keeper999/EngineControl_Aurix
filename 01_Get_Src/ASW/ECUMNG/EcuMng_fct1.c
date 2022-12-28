/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ECUMNG                                                  */
/* !Description     : ECUMNG component                                        */
/*                                                                            */
/* !Module          : ECUMNG                                                  */
/* !Description     : ETAT ELECTRIQUE DU CALCULATEUR                          */
/*                                                                            */
/* !File            : ecumng_fct1.c                                           */
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
/*   1 / ECUMNG_vidEcuMng_Init                                                */
/*   2 / ECUMNG_vidManagePowerOn                                              */
/*   3 / ECUMNG_vidManager                                                    */
/*   4 / ECUMNG_vidSurveillance                                               */
/*   5 / ECUMNG_vidFctPrinDegrad                                              */
/*   6 / ECUMNG_vidPwrlEndAuth                                                */
/*   7 / ECUMNG_vidRcdStateSelection                                          */
/*   8 / ECUMNG_vidInitOutput                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6642215 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ECUST/ECUMNG/EcuMng_fct1.c_v    $*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   22 Jul 2014 $*/
/* $Author::   mbenfrad                               $$Date::   22 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ECUMNG.h"
#include "ECUMNG_L.h"
#include "ECUMNG_IM.h"
#include "RSTSRV.h"
#include "GDGAR.h"
#include "SAIMMO.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidEcuMng_Init                                      */
/* !Description :  Init function                                              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RSTSRV_udtReadResetState(void)uint8;                     */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 EcuSt_ctHotRst_Count;                                        */
/*  input boolean Rcd_mode_active;                                            */
/*  input bool POWER_ON;                                                      */
/*  input bool RCD_POWER_ON;                                                  */
/*  input bool WAITING_FOR_ANTICIPATION;                                      */
/*  input uint16 Rcd_waiting_for_anticip_delay;                               */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input bool RCD_TRANSIT;                                                   */
/*  output uint8 EcuSt_stTypRst;                                              */
/*  output boolean EcuSt_bDetHotRst;                                          */
/*  output uint16 EcuSt_ctHotRst_Count;                                       */
/*  output boolean Rcd_cond_for_power_on_default;                             */
/*  output boolean EcuSt_fin_wr_eeprom;                                       */
/*  output boolean EcuSt_EcuStpEna;                                           */
/*  output boolean EcuSt_bPwrlEnd;                                            */
/*  output uint8 EcuSt_stPwr_EcuMng_prev;                                     */
/*  output boolean ECUMNG_bAcv_Diag_Hot_Rst;                                  */
/*  output boolean Ext_bUnlockReq;                                            */
/*  output st08 Power_conditions_state;                                       */
/*  output bool POWER_ON;                                                     */
/*  output uint16 Rcd_waiting_for_anticip_count;                              */
/*  output bool WAITING_FOR_ANTICIPATION;                                     */
/*  output uint8 EcuSt_stPwr_EcuMng;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidEcuMng_Init(void)
{
   boolean bLocalEcuSt_bAcvRcdMod_EcuMng;
   uint8   u8LocalEcuSt_stTypRst;
   uint8   u8LocalEcuSt_stPwr_EcuMng;
   uint16  u16LocalCount;
   uint16  u16LocalEcuSt_ctHotRst_Count;


   u8LocalEcuSt_stTypRst = RSTSRV_udtReadResetState();

   VEMS_vidSET(EcuSt_stTypRst, u8LocalEcuSt_stTypRst);
   VEMS_vidGET(EcuSt_ctHotRst_Count, u16LocalEcuSt_ctHotRst_Count);

   if (u8LocalEcuSt_stTypRst != RSTSRV_udtNORMAL_STARTUP_RESET)
   {
      VEMS_vidSET(EcuSt_bDetHotRst, 1);
      if (u16LocalEcuSt_ctHotRst_Count < 65535)
      {
         u16LocalEcuSt_ctHotRst_Count =
            (uint16)(u16LocalEcuSt_ctHotRst_Count + 1);
         VEMS_vidSET(EcuSt_ctHotRst_Count, u16LocalEcuSt_ctHotRst_Count);
      }
   }
   else
   {
      VEMS_vidSET(EcuSt_bDetHotRst, 0);
   }

   Rcd_cond_for_power_on_default = 0;
   EcuSt_fin_wr_eeprom = 0;
   EcuSt_EcuStpEna = 0;
   EcuSt_bPwrlEnd = 0;
   EcuSt_stPwr_EcuMng_prev = 0;
   ECUMNG_bAcv_Diag_Hot_Rst = 0;
   u8LocalEcuSt_stPwr_EcuMng = 0;
   if (Rcd_mode_active == 0)
   {
      VEMS_vidSET(Ext_bUnlockReq, 1);
      VEMS_vidSET(Power_conditions_state, POWER_ON);
      VEMS_vidSET(Rcd_waiting_for_anticip_count, 0);
      u8LocalEcuSt_stPwr_EcuMng = RCD_POWER_ON;
   }
   else
   {
      VEMS_vidSET(Ext_bUnlockReq, 0);
      VEMS_vidSET(Power_conditions_state, WAITING_FOR_ANTICIPATION);
      u16LocalCount = (uint16)MATHSRV_udtMIN(Rcd_waiting_for_anticip_delay,
                                             62500);
      VEMS_vidSET(Rcd_waiting_for_anticip_count, u16LocalCount);
      VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);
      if (bLocalEcuSt_bAcvRcdMod_EcuMng == 0)
      {
         u8LocalEcuSt_stPwr_EcuMng = RCD_TRANSIT;
      }
   }
   EcuSt_stPwr_EcuMng = u8LocalEcuSt_stPwr_EcuMng;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidManagePowerOn                                    */
/* !Description :  On Key on event, Power_conditions_state is set to POWER_ON */
/*                 state and the immobilizer event SAIMMO_Init is generated.  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SAIMMO_init();                                           */
/*  input bool POWER_ON;                                                      */
/*  input boolean Rcd_mode_active;                                            */
/*  input bool RCD_POWER_ON;                                                  */
/*  output boolean Ext_bUnlockReq;                                            */
/*  output st08 Power_conditions_state;                                       */
/*  output bool POWER_ON;                                                     */
/*  output uint16 Rcd_waiting_for_anticip_count;                              */
/*  output boolean Rcd_cond_for_power_on_default;                             */
/*  output uint8 EcuSt_stPwr_EcuMng;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidManagePowerOn(void)
{
   VEMS_vidSET(Ext_bUnlockReq,1);
   SAIMMO_init();
   VEMS_vidSET(Power_conditions_state, POWER_ON);
   if(Rcd_mode_active == 0)
   {
      VEMS_vidSET(Rcd_waiting_for_anticip_count, 0);
      Rcd_cond_for_power_on_default = 0;
      EcuSt_stPwr_EcuMng = RCD_POWER_ON;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidManager                                          */
/* !Description :  Manager d’état.                                            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_R_10_04100_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ECUMNG_vidWaitAnticipationTrans();                       */
/*  extf argret void ECUMNG_vidPowerOnTrans();                                */
/*  extf argret void ECUMNG_vidWaitRstrtDelayTrans();                         */
/*  extf argret void ECUMNG_vidPwrLatchDelayTrans();                          */
/*  extf argret void ECUMNG_vidSleepingTrans();                               */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EcuSt_EveFct_WaitForPwrl();                              */
/*  extf argret void EcuSt_EveEcuSt_EcuMng();                                 */
/*  input uint8 EcuSt_stPwr_EcuMng;                                           */
/*  input st08 Power_conditions_state;                                        */
/*  input boolean Srv_bRstSw_DiagSrv;                                         */
/*  input bool WAITING_FOR_ANTICIPATION;                                      */
/*  input bool POWER_ON;                                                      */
/*  input bool WAITING_FOR_RESTART_DELAY;                                     */
/*  input bool WAITING_FOR_POWER_LATCH_DELAY;                                 */
/*  input bool SLEEPING;                                                      */
/*  input uint8 EcuSt_stPwr_EcuMng_prev;                                      */
/*  output uint8 EcuSt_stPwr_EcuMng_prev;                                     */
/*  output st08 Power_conditions_state;                                       */
/*  output bool POWER_ON;                                                     */
/*  output boolean EcuSt_EcuStpEna;                                           */
/*  output boolean Srv_bRstSw_DiagSrv_Prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidManager(void)
{
   boolean bLocalSrv_bRstSw_DiagSrv;
   uint8   u8Local_Power_conditions_state;


   EcuSt_stPwr_EcuMng_prev = EcuSt_stPwr_EcuMng;
   VEMS_vidGET(Power_conditions_state, u8Local_Power_conditions_state);
   VEMS_vidGET(Srv_bRstSw_DiagSrv, bLocalSrv_bRstSw_DiagSrv);
   /* QAC Deviation : problem of indentation. This warning is to ignore
      because we respect the VEES presenting rule (PON EEM INS 06 0004).*/

   if (bLocalSrv_bRstSw_DiagSrv == 0)
   {
      switch (u8Local_Power_conditions_state)
      {
         case WAITING_FOR_ANTICIPATION:
            ECUMNG_vidWaitAnticipationTrans();
         break;
         case POWER_ON:
            ECUMNG_vidPowerOnTrans();
         break;
         case WAITING_FOR_RESTART_DELAY:
            ECUMNG_vidWaitRstrtDelayTrans();
         break;
         case WAITING_FOR_POWER_LATCH_DELAY:
            ECUMNG_vidPwrLatchDelayTrans();
         break;
         case SLEEPING:
            ECUMNG_vidSleepingTrans();
         break;
         default:
            SWFAIL_vidSoftwareErrorHook();
            VEMS_vidSET(Power_conditions_state, POWER_ON);
            EcuSt_EcuStpEna = 0;
         break;
      }
   }
   else
   {
      EcuSt_EveFct_WaitForPwrl();
      ECUMNG_vidPwrLatchDelayTrans();
   }
   if (EcuSt_stPwr_EcuMng_prev != EcuSt_stPwr_EcuMng)
   {
      EcuSt_EveEcuSt_EcuMng();
   }
   Srv_bRstSw_DiagSrv_Prev = bLocalSrv_bRstSw_DiagSrv;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidSurveillance                                     */
/* !Description :  After RCD signal deactivating and awakening requests by the*/
/*                 BSI, the ECU monitors their progress during a minimum      */
/*                 period before going to SLEEPING state.                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Rcd_signal;                                                 */
/*  input boolean Rcd_anticipation_adc;                                       */
/*  input boolean Rcd_preparation_moteur;                                     */
/*  input boolean Rcd_mes_huile_moteur;                                       */
/*  input boolean Rcd_post_ventil_mot;                                        */
/*  input boolean Clef_de_contact;                                            */
/*  input uint16 Rcd_waiting_for_anticip_count;                               */
/*  input boolean Rcd_mode_active;                                            */
/*  input uint16 Rcd_waiting_for_anticip_delay;                               */
/*  output uint16 Rcd_waiting_for_anticip_count;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidSurveillance(void)
{
   boolean bLocal_Clef_de_contact;
   boolean bLocal_Rcd_anticipation_adc;
   boolean bLocal_Rcd_mes_huile_moteur;
   boolean bLocal_Rcd_post_ventil_mot;
   boolean bLocal_Rcd_preparation_moteur;
   boolean bLocal_Rcd_signal;
   uint16  u16LocalRcd_wait_anticip_count;


   VEMS_vidGET(Rcd_signal, bLocal_Rcd_signal);
   VEMS_vidGET(Rcd_anticipation_adc, bLocal_Rcd_anticipation_adc);
   VEMS_vidGET(Rcd_preparation_moteur, bLocal_Rcd_preparation_moteur);
   VEMS_vidGET(Rcd_mes_huile_moteur, bLocal_Rcd_mes_huile_moteur);
   VEMS_vidGET(Rcd_post_ventil_mot, bLocal_Rcd_post_ventil_mot);
   VEMS_vidGET(Clef_de_contact, bLocal_Clef_de_contact);
   VEMS_vidGET(Rcd_waiting_for_anticip_count, u16LocalRcd_wait_anticip_count);

   if (Rcd_mode_active != 0)
   {
      if (  (bLocal_Rcd_signal == 0)
         && (bLocal_Rcd_anticipation_adc == 0)
         && (bLocal_Rcd_preparation_moteur == 0)
         && (bLocal_Rcd_mes_huile_moteur == 0)
         && (bLocal_Rcd_post_ventil_mot == 0)
         && (bLocal_Clef_de_contact == 0))
      {
         if (u16LocalRcd_wait_anticip_count > 0)
         {
            u16LocalRcd_wait_anticip_count =
               (uint16)(u16LocalRcd_wait_anticip_count - 1);
            u16LocalRcd_wait_anticip_count =
               (uint16)MATHSRV_udtMIN(u16LocalRcd_wait_anticip_count, 62500);
            VEMS_vidSET(Rcd_waiting_for_anticip_count,
                        u16LocalRcd_wait_anticip_count);
         }
         else
         {
            VEMS_vidSET(Rcd_waiting_for_anticip_count, 0);
         }
      }
      else
      {
         u16LocalRcd_wait_anticip_count =
            (uint16)MATHSRV_udtMIN(Rcd_waiting_for_anticip_delay, 62500);
         VEMS_vidSET(Rcd_waiting_for_anticip_count,
                     u16LocalRcd_wait_anticip_count);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidFctPrinDegrad                                    */
/* !Description :  This function, called in POWER_ON (EcuSt_SdlMid_EcuMng_3), */
/*                 produces a flag gathering the conditions to set the ECU in */
/*                 degraded main awakening.                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16Channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Rcd_reveil_principal;                                       */
/*  input boolean Rcd_signal;                                                 */
/*  output boolean Rcd_cond_for_power_on_default;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidFctPrinDegrad(void)
{
   boolean bLocalAcvEcuPwrOnDft;
   boolean bLocal_Clef_de_contact;
   boolean bLocal_Rcd_reveil_principal;
   boolean bLocal_Rcd_signal;

   if (Rcd_mode_active != 0)
   {
      bLocalAcvEcuPwrOnDft = GDGAR_bGetFRM(FRM_FRM_ACVECUPWRONDFT);

      if (bLocalAcvEcuPwrOnDft != 0)
      {
         Rcd_cond_for_power_on_default = 1;
      }
      else
      {
         VEMS_vidGET(Clef_de_contact, bLocal_Clef_de_contact);
         VEMS_vidGET(Rcd_reveil_principal, bLocal_Rcd_reveil_principal);
         VEMS_vidGET(Rcd_signal, bLocal_Rcd_signal);
         if (  (bLocal_Clef_de_contact == 0)
            || (  (bLocal_Rcd_reveil_principal != 0)
               && (bLocal_Rcd_signal != 0)))
         {
            Rcd_cond_for_power_on_default = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidPwrlEndAuth                                      */
/* !Description :  On EcuSt_EvePwrlEnd_EcuMng, the Powerlatch end is          */
/*                 authorized.                                                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean EcuSt_bPwrlEnd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidPwrlEndAuth(void)
{
   EcuSt_bPwrlEnd = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidRcdStateSelection                                */
/* !Description :  The Rcd state is selected between the state determinated by*/
/*                 the Valeo strategy or by RCD software component.This       */
/*                 selection is realized on reset event, Key On event, Key Of */
/*                 event and on middle timing event.                          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ECUMNG_vidRCDConfig();                                   */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ECUMNG_vidAPCConfig();                                   */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input uint8 UCE_stSt;                                                     */
/*  input boolean Rcd_mode_active;                                            */
/*  input uint8 Rcd_PwrSt;                                                    */
/*  input uint8 Apc_PwrSt;                                                    */
/*  input uint8 EcuSt_stPwr_EcuMng;                                           */
/*  output st09 Rcd_power_state;                                              */
/*  output uint8 Rcd_PwrSt;                                                   */
/*  output uint8 Apc_PwrSt;                                                   */
/*  output uint8 EcuSt_stPwr_EcuMng;                                          */
/*  output uint8 Ext_stSt;                                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidRcdStateSelection(void)
{
   boolean bLocalEcuSt_bAcvRcdMod_EcuMng;
   uint8   u8LocalUCE_stSt;


   VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);
   VEMS_vidGET(UCE_stSt, u8LocalUCE_stSt);
   if (bLocalEcuSt_bAcvRcdMod_EcuMng != 0)
   {
      if (Rcd_mode_active != 0)
      {
         ECUMNG_vidRCDConfig();
         VEMS_vidSET(Rcd_power_state, Rcd_PwrSt);
      }
      else
      {
         ECUMNG_vidAPCConfig();
         VEMS_vidSET(Rcd_power_state, Apc_PwrSt);
      }
   }
   else
   {
      VEMS_vidSET(Rcd_power_state, EcuSt_stPwr_EcuMng);
   }
   u8LocalUCE_stSt = (uint8)MATHSRV_udtMIN(u8LocalUCE_stSt, 15);
   VEMS_vidSET(Ext_stSt, u8LocalUCE_stSt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidInitOutput                                       */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Srv_bRstSw_DiagSrv_Prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidInitOutput(void)
{
   Srv_bRstSw_DiagSrv_Prev = 0;
}
/*------------------------------- end of file --------------------------------*/