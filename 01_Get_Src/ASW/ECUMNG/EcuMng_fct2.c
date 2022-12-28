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
/* !File            : ecumng_fct2.c                                           */
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
/*   1 / ECUMNG_vidWaitAnticipationTrans                                      */
/*   2 / ECUMNG_vidPowerOnTrans                                               */
/*   3 / ECUMNG_vidWaitRstrtDelayTrans                                        */
/*   4 / ECUMNG_vidPwrLatchDelayTrans                                         */
/*   5 / ECUMNG_vidSleepingTrans                                              */
/*   6 / ECUMNG_vidInterneCmm                                                 */
/*   7 / ECUMNG_vidRCDConfig                                                  */
/*   8 / ECUMNG_vidAPCConfig                                                  */
/*   9 / ECUMNG_NVMSRV_vidInit                                                */
/*   10 / ECUMNG_vidbRstSrvRstEepromCount                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6642215 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ECUST/ECUMNG/EcuMng_fct2.c_v    $*/
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
#include "ECUMNG_I.H"
#include "SAIMMO.h"
#include "RSTSRV.h"
#include "NVMSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidWaitAnticipationTrans                            */
/* !Description :  Fonction de gestion de transition de l'état                */
/*                 WAITING_FOR_ANTICIPATION                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SAIMMO_init();                                           */
/*  input boolean Rcd_anticipation_adc;                                       */
/*  input boolean Rcd_mes_huile_moteur;                                       */
/*  input boolean Rcd_post_ventil_mot;                                        */
/*  input boolean Rcd_preparation_moteur;                                     */
/*  input boolean Rcd_signal;                                                 */
/*  input uint16 Rcd_waiting_for_anticip_count;                               */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input bool RCD_SLEEPING;                                                  */
/*  input bool SLEEPING;                                                      */
/*  input bool RCD_ANTICIPATION;                                              */
/*  input bool RCD_TRANSIT;                                                   */
/*  output boolean Ext_bUnlockReq;                                            */
/*  output uint8 EcuSt_stPwr_EcuMng;                                          */
/*  output st08 Power_conditions_state;                                       */
/*  output bool SLEEPING;                                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidWaitAnticipationTrans(void)
{
   boolean bLocal_Rcd_anticipation_adc;
   boolean bLocal_Rcd_mes_huile_moteur;
   boolean bLocal_Rcd_post_ventil_mot;
   boolean bLocal_Rcd_preparation_moteur;
   boolean bLocal_Rcd_signal;
   boolean bLocalEcuSt_bAcvRcdMod_EcuMng;
   uint16  u16LocalRcd_wait_anticip_count;


   VEMS_vidGET(Rcd_anticipation_adc, bLocal_Rcd_anticipation_adc);
   VEMS_vidGET(Rcd_mes_huile_moteur, bLocal_Rcd_mes_huile_moteur);
   VEMS_vidGET(Rcd_post_ventil_mot, bLocal_Rcd_post_ventil_mot);
   VEMS_vidGET(Rcd_preparation_moteur, bLocal_Rcd_preparation_moteur);
   VEMS_vidGET(Rcd_signal, bLocal_Rcd_signal);
   VEMS_vidGET(Rcd_waiting_for_anticip_count, u16LocalRcd_wait_anticip_count);
   VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);

   if (  (u16LocalRcd_wait_anticip_count == 0)
      && (bLocal_Rcd_signal == 0))
   {
      VEMS_vidSET(Ext_bUnlockReq, 0);
      if (bLocalEcuSt_bAcvRcdMod_EcuMng == 0)
      {
         EcuSt_stPwr_EcuMng = RCD_SLEEPING;
      }
      VEMS_vidSET(Power_conditions_state, SLEEPING);
   }
   else
   {
      if (bLocal_Rcd_anticipation_adc != 0)
      {
         VEMS_vidSET(Ext_bUnlockReq, 1);
         SAIMMO_init();
      }
      else
      {
         VEMS_vidSET(Ext_bUnlockReq, 0);
      }
      if (bLocalEcuSt_bAcvRcdMod_EcuMng == 0)
      {
         if (  (bLocal_Rcd_anticipation_adc != 0)
            || (bLocal_Rcd_preparation_moteur != 0)
            || (bLocal_Rcd_mes_huile_moteur != 0)
            || (bLocal_Rcd_post_ventil_mot != 0))
         {
            EcuSt_stPwr_EcuMng = RCD_ANTICIPATION;
         }
         else
         {
            EcuSt_stPwr_EcuMng = RCD_TRANSIT;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidPowerOnTrans                                     */
/* !Description :  Fonction de gestion de transition de l'état POWER_ON       */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ECUMNG_vidInterneCmm();                                  */
/*  extf argret void ECUMNG_vidFctPrinDegrad();                               */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 Rcd_retour_power_on_count;                                    */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input uint16 Engine_restart_delay;                                        */
/*  input bool WAITING_FOR_RESTART_DELAY;                                     */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Rcd_cond_for_power_on_default;                              */
/*  input bool RCD_POWER_ON_DEFAULT;                                          */
/*  input bool RCD_POWER_ON;                                                  */
/*  output boolean Ext_bUnlockReq;                                            */
/*  output uint16 Power_cond_delay_count;                                     */
/*  output st08 Power_conditions_state;                                       */
/*  output bool WAITING_FOR_RESTART_DELAY;                                    */
/*  output uint8 EcuSt_stPwr_EcuMng;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidPowerOnTrans(void)
{
   boolean bLocal_Clef_de_contact;
   boolean bLocal_Rcd_retour_power_on_count;
   boolean bLocalEcuSt_bAcvRcdMod_EcuMng;


   VEMS_vidGET(Clef_de_contact, bLocal_Clef_de_contact);
   VEMS_vidGET(Rcd_retour_power_on_count, bLocal_Rcd_retour_power_on_count);
   VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);

   if (bLocal_Clef_de_contact == 0)
   {
      VEMS_vidSET(Ext_bUnlockReq, 0);
      Power_cond_delay_count =
         (uint16)MATHSRV_udtMIN(Engine_restart_delay, 62500);
      VEMS_vidSET(Power_conditions_state, WAITING_FOR_RESTART_DELAY);

      ECUMNG_vidInterneCmm();
   }
   else
   {
      if (Rcd_mode_active != 0)
      {
         VEMS_vidSET(Ext_bUnlockReq, 1);
         ECUMNG_vidFctPrinDegrad();
         if (bLocalEcuSt_bAcvRcdMod_EcuMng == 0)
         {
            if (Rcd_cond_for_power_on_default != 0)
            {
               EcuSt_stPwr_EcuMng = RCD_POWER_ON_DEFAULT;
            }
            else
            {
               if (bLocal_Rcd_retour_power_on_count == 0)
               {
                  EcuSt_stPwr_EcuMng = RCD_POWER_ON;
               }
               else
               {
                  EcuSt_stPwr_EcuMng = RCD_POWER_ON_DEFAULT;
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidWaitRstrtDelayTrans                              */
/* !Description :  Fonction de gestion de transition de l'état                */
/*                 Waiting_for_restart_delay                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ECUMNG_vidInterneCmm();                                  */
/*  input boolean Date_emf_available_mux;                                     */
/*  input uint8 Forcage_power_latch_emf;                                      */
/*  input uint8 Manu_inh_gestion_power_latch_emf;                             */
/*  input uint16 Power_latch_emf_delay_max;                                   */
/*  input uint16 Power_latch_no_emf_delay_max;                                */
/*  input uint16 Power_cond_delay_count;                                      */
/*  input bool WAITING_FOR_POWER_LATCH_DELAY;                                 */
/*  input uint16 Power_latch_delay_max;                                       */
/*  input uint16 Rcd_wait_open_pwr_relay_delay;                               */
/*  input uint16 Rcd_wait_wr_in_eeprom_delay;                                 */
/*  output uint16 Power_latch_delay_max;                                      */
/*  output uint16 Power_cond_delay_count;                                     */
/*  output boolean Ext_bUnlockReq;                                            */
/*  output st08 Power_conditions_state;                                       */
/*  output bool WAITING_FOR_POWER_LATCH_DELAY;                                */
/*  output uint16 Rcd_wait_open_pwr_relay_count;                              */
/*  output uint16 Rcd_wait_wr_in_eeprom_count;                                */
/*  output boolean EcuSt_EcuStpEna;                                           */
/*  output boolean EcuSt_bPwrlEnd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidWaitRstrtDelayTrans(void)
{
   boolean bLocal_Date_emf_available_mux;
   uint16  u16LocalCount;


   VEMS_vidGET(Date_emf_available_mux, bLocal_Date_emf_available_mux);

   if ( (  (bLocal_Date_emf_available_mux != 0)
        || (Forcage_power_latch_emf != 0))
      && (Manu_inh_gestion_power_latch_emf == 0))
   {
      Power_latch_delay_max = (uint16)MATHSRV_udtMIN(Power_latch_emf_delay_max,
                                                     62500);
   }
   else
   {
      Power_latch_delay_max =
         (uint16)MATHSRV_udtMIN(Power_latch_no_emf_delay_max, 62500);
   }

   if (Power_cond_delay_count > 0)
   {
      u16LocalCount = (uint16)(Power_cond_delay_count - 1);
      Power_cond_delay_count = (uint16)MATHSRV_udtMIN(u16LocalCount, 62500);
   }
   else
   {
      Power_cond_delay_count = 0;
   }
   if (Power_cond_delay_count == 0)
   {
      VEMS_vidSET(Ext_bUnlockReq, 0);
      VEMS_vidSET(Power_conditions_state, WAITING_FOR_POWER_LATCH_DELAY);
      Power_cond_delay_count = (uint16)MATHSRV_udtMAX(Power_latch_delay_max,
                                                      POWER_LATCH_12_SEC);
      Rcd_wait_open_pwr_relay_count =
         (uint16)MATHSRV_udtMIN(Rcd_wait_open_pwr_relay_delay, 62500);
      Rcd_wait_wr_in_eeprom_count =
         (uint16)MATHSRV_udtMIN(Rcd_wait_wr_in_eeprom_delay, 62500);
      EcuSt_EcuStpEna = 1;
      EcuSt_bPwrlEnd = 0;
   }
   ECUMNG_vidInterneCmm();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidPwrLatchDelayTrans                               */
/* !Description :  Fonction de gestion de transition de l'état                */
/*                 Waiting_for_power_latch_delay                              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ECUMNG_vidbRstSrvRstEepromCount();                       */
/*  extf argret void ActivateTask(argin uint8 Taskid);                        */
/*  extf argret void NVMSRV_bAllSaved()boolean;                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void RSTSRV_vidPerformReset(argin RSTSRV_tudtResetType        */
/* udtRequestedResetType);                                                    */
/*  extf argret void EcuSt_EveFct_WaitForPwrl();                              */
/*  extf argret void ECUMNG_vidInterneCmm();                                  */
/*  input boolean ThMgt_bPwrHldReq;                                           */
/*  input boolean Jbsi_autorise_fin_power_latch;                              */
/*  input boolean Saf_power_latch;                                            */
/*  input boolean Toil_power_latch;                                           */
/*  input boolean Srv_bRstSw_DiagSrv;                                         */
/*  input boolean UCE_bShutDownAuth;                                          */
/*  input boolean EcuSt_SrvPwrlSt;                                            */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input uint16 Power_cond_delay_count;                                      */
/*  input uint16 Rcd_wait_open_pwr_relay_count;                               */
/*  input uint16 Power_latch_delay_max;                                       */
/*  input uint16 Power_latch_delay;                                           */
/*  input boolean Srv_bRstSw_DiagSrv_Prev;                                    */
/*  input boolean EcuSt_EcuStpEna;                                            */
/*  input boolean EcuSt_bPwrlEnd;                                             */
/*  input uint16 Rcd_wait_wr_in_eeprom_count;                                 */
/*  input boolean EcuSt_fin_wr_eeprom;                                        */
/*  input boolean Rcd_mode_active;                                            */
/*  input bool WAITING_FOR_ANTICIPATION;                                      */
/*  input bool SLEEPING;                                                      */
/*  output uint16 Power_cond_delay_count;                                     */
/*  output uint16 Rcd_wait_open_pwr_relay_count;                              */
/*  output boolean EcuSt_EcuStpEna;                                           */
/*  output boolean EcuSt_FinWrEepromTemp;                                     */
/*  output boolean EcuSt_fin_wr_eeprom;                                       */
/*  output boolean Ext_bUnlockReq;                                            */
/*  output boolean EcuSt_bRstSw;                                              */
/*  output st08 Power_conditions_state;                                       */
/*  output bool WAITING_FOR_ANTICIPATION;                                     */
/*  output bool SLEEPING;                                                     */
/*  output uint16 Rcd_wait_wr_in_eeprom_count;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidPwrLatchDelayTrans(void)
{
   boolean  bLocalThMgt_bPwrHldReq;
   boolean  bLocalJbsi_autor_fin_power_latch;
   boolean  bLocal_Saf_power_latch;
   boolean  bLocal_Toil_power_latch;
   boolean  bLocalSrv_bRstSw_DiagSrv;
   boolean  bLocalEcuSt_SrvPwrlSt;
   boolean  bLocalUCE_bShutDownAuth;
   boolean  bLocalEcuSt_bAcvRcdMod_EcuMng;
   boolean  bLocalEcuSt_FinWrEepromTemp;
   uint16   u16LocalCount;
   uint32   u32LocalCount;
   sint32   s32LocalCalc;


   VEMS_vidGET(ThMgt_bPwrHldReq, bLocalThMgt_bPwrHldReq);
   VEMS_vidGET(Jbsi_autorise_fin_power_latch,
               bLocalJbsi_autor_fin_power_latch);
   VEMS_vidGET(Saf_power_latch, bLocal_Saf_power_latch);
   VEMS_vidGET(Toil_power_latch, bLocal_Toil_power_latch);
   VEMS_vidGET(Srv_bRstSw_DiagSrv, bLocalSrv_bRstSw_DiagSrv);
   VEMS_vidGET(UCE_bShutDownAuth, bLocalUCE_bShutDownAuth);
   VEMS_vidGET(EcuSt_SrvPwrlSt, bLocalEcuSt_SrvPwrlSt);
   VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);

   if (Power_cond_delay_count > 0)
   {
      u16LocalCount = (uint16)(Power_cond_delay_count - 1);
      Power_cond_delay_count = (uint16)MATHSRV_udtMIN(u16LocalCount, 62500);
   }
   else
   {
      Power_cond_delay_count = 0;
   }

   if (bLocalThMgt_bPwrHldReq == 0)
   {
      if (Rcd_wait_open_pwr_relay_count >= 1)
      {
         u16LocalCount = (uint16)(Rcd_wait_open_pwr_relay_count - 1);
         Rcd_wait_open_pwr_relay_count = (uint16)MATHSRV_udtMIN(u16LocalCount,
                                                                62500);
      }
      else
      {
         Rcd_wait_open_pwr_relay_count = 0;
      }
   }

   s32LocalCalc = (sint32)(Power_latch_delay_max - Power_latch_delay);
   u32LocalCount = (uint32)MATHSRV_udtMAX(s32LocalCalc, 0);

   if (  (bLocalSrv_bRstSw_DiagSrv != 0)
      || ( (  (Power_cond_delay_count == 0)
           || (  (Power_cond_delay_count <= u32LocalCount)
              && (bLocal_Toil_power_latch != 0)))
         && (bLocalThMgt_bPwrHldReq == 0)
         && (bLocal_Saf_power_latch != 0)
         && (bLocalJbsi_autor_fin_power_latch != 0)
         && (Rcd_wait_open_pwr_relay_count == 0)))
   {
      if (  (bLocalSrv_bRstSw_DiagSrv != 0)
         && (Srv_bRstSw_DiagSrv_Prev == 0))
      {
         ECUMNG_vidbRstSrvRstEepromCount();
         EcuSt_EcuStpEna = 0;
         ActivateTask(OSTSK_S_EEST);
      }
      else
      {
         if (EcuSt_EcuStpEna != 0)
         {
            EcuSt_EcuStpEna = 0;
            ActivateTask(OSTSK_S_EEST);
         }
      }
      bLocalEcuSt_FinWrEepromTemp = NVMSRV_bAllSaved();
      VEMS_vidSET(EcuSt_FinWrEepromTemp, bLocalEcuSt_FinWrEepromTemp);
      if (  (bLocalEcuSt_FinWrEepromTemp != 0)
         && (bLocalEcuSt_SrvPwrlSt!= 0)
         && (EcuSt_bPwrlEnd != 0))
      {
         EcuSt_fin_wr_eeprom = 1;
      }
      else
      {
         EcuSt_fin_wr_eeprom = 0;
      }
      if (  (Rcd_wait_wr_in_eeprom_count == 0)
         || (EcuSt_fin_wr_eeprom != 0))
      {
         VEMS_vidSET(Ext_bUnlockReq, 0);
         if (bLocalSrv_bRstSw_DiagSrv != 0)
         {
            VEMS_vidSET(EcuSt_bRstSw, 1);
            RSTSRV_vidPerformReset(RSTSRV_udtSOFTWARE_RESET);
         }
         else
         {
            if (Rcd_mode_active != 0)
            {
               if (  (  (bLocalUCE_bShutDownAuth != 0)
                     && (bLocalEcuSt_bAcvRcdMod_EcuMng != 0))
                  || (bLocalEcuSt_bAcvRcdMod_EcuMng == 0))
               {
                  VEMS_vidSET(Power_conditions_state, WAITING_FOR_ANTICIPATION);
               }
            }
            else
            {
               VEMS_vidSET(Power_conditions_state, SLEEPING);
            }
         }
      }
      else
      {
         u16LocalCount = (uint16)(Rcd_wait_wr_in_eeprom_count - 1);
         Rcd_wait_wr_in_eeprom_count = (uint16)MATHSRV_udtMIN(u16LocalCount,
                                                              62500);
      }
   }
   EcuSt_EveFct_WaitForPwrl();
   ECUMNG_vidInterneCmm();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidSleepingTrans                                    */
/* !Description :  Dans cet état le calculateur demande au LDB la coupure du  */
/*                 relais principal. La demande de coupure du relais principal*/
/*                 par l'API DIOHAL_vidWrite(MAIN_RELAY, STD_OFF) entraine    */
/*                 l'arret de l'OS et de toutes les IT                        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIOHAL_vidWrite(uint8 u8Channel, boolean bVal);          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidSleepingTrans(void)
{
   DIOHAL_vidWrite(MAIN_RELAY, STD_OFF);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidInterneCmm                                       */
/* !Description :  This function is called after the main awakening to inform */
/*                 the BSI if the ECU is in partial awakening, in internal    */
/*                 partial awakening, or simply transient.                    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Rcd_anticipation_adc;                                       */
/*  input boolean Rcd_mes_huile_moteur;                                       */
/*  input boolean Rcd_post_ventil_mot;                                        */
/*  input boolean Rcd_preparation_moteur;                                     */
/*  input uint16 Rcd_waiting_for_anticip_count;                               */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input boolean Rcd_signal;                                                 */
/*  input bool RCD_ANTICIPATION;                                              */
/*  input bool RCD_POWER_LATCH;                                               */
/*  input bool RCD_TRANSIT;                                                   */
/*  output boolean Ext_bUnlockReq;                                            */
/*  output uint8 EcuSt_stPwr_EcuMng;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidInterneCmm(void)
{
   boolean bLocal_Rcd_anticipation_adc;
   boolean bLocal_Rcd_mes_huile_moteur;
   boolean bLocal_Rcd_post_ventil_mot;
   boolean bLocal_Rcd_preparation_moteur;
   boolean bLocalEcuSt_bAcvRcdMod_EcuMng;
   boolean bLocalRcd_signal;
   uint16  u16Local_Rcd_wait_anticip_count;


   VEMS_vidGET(Rcd_anticipation_adc,bLocal_Rcd_anticipation_adc);
   VEMS_vidGET(Rcd_mes_huile_moteur,bLocal_Rcd_mes_huile_moteur);
   VEMS_vidGET(Rcd_post_ventil_mot,bLocal_Rcd_post_ventil_mot);
   VEMS_vidGET(Rcd_preparation_moteur,bLocal_Rcd_preparation_moteur);
   VEMS_vidGET(Rcd_waiting_for_anticip_count, u16Local_Rcd_wait_anticip_count);
   VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);
   VEMS_vidGET(Rcd_signal, bLocalRcd_signal);

   if (bLocal_Rcd_anticipation_adc != 0)
   {
      VEMS_vidSET(Ext_bUnlockReq, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bUnlockReq, 0);
   }

   if (bLocalEcuSt_bAcvRcdMod_EcuMng == 0)
   {
      if (  (  (bLocal_Rcd_anticipation_adc != 0)
            || (bLocal_Rcd_preparation_moteur != 0)
            || (bLocal_Rcd_mes_huile_moteur != 0)
            || (bLocal_Rcd_post_ventil_mot != 0))
         && (bLocalRcd_signal != 0))
      {
         EcuSt_stPwr_EcuMng = RCD_ANTICIPATION;
      }
      else
      {
         if (u16Local_Rcd_wait_anticip_count == 0)
         {
            EcuSt_stPwr_EcuMng = RCD_POWER_LATCH;
         }
         else
         {
            EcuSt_stPwr_EcuMng = RCD_TRANSIT;
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidRCDConfig                                        */
/* !Description :  cette fonction permet d'assurer le calcul de l'état        */
/*                 UCE_stSt selon la configuration RCD.                       */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 UCE_stSt;                                                     */
/*  input bool RCD_ANTICIPATION;                                              */
/*  input bool RCD_POWER_ON;                                                  */
/*  input bool RCD_TRANSIT;                                                   */
/*  input bool RCD_POWER_ON_DEFAULT;                                          */
/*  input bool RCD_POWER_LATCH;                                               */
/*  input bool RCD_SLEEPING;                                                  */
/*  output uint8 Rcd_PwrSt;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidRCDConfig(void)
{
   uint8  u8LocalUCE_stSt;


   VEMS_vidGET(UCE_stSt, u8LocalUCE_stSt);
   if (u8LocalUCE_stSt == RCD_PARTIAL_WAKEUP)
   {
      Rcd_PwrSt = RCD_ANTICIPATION;
   }
   else
   {
      if (u8LocalUCE_stSt == RCD_INTERNAL_PARTIAL_WAKEUP)
      {
         Rcd_PwrSt = RCD_ANTICIPATION;
      }
      else
      {
         if (u8LocalUCE_stSt == RCD_MAIN_WAKEUP)
         {
            Rcd_PwrSt = RCD_POWER_ON;
         }
         else
         {
            if (u8LocalUCE_stSt == RCD_TRANSITORY)
            {
               Rcd_PwrSt = RCD_TRANSIT;
            }
            else
            {
               if (u8LocalUCE_stSt == RCD_DEGRADED_MAIN_WAKEUP)
               {
                  Rcd_PwrSt = RCD_POWER_ON_DEFAULT;
               }
               else
               {
                  if (u8LocalUCE_stSt == RCD_SHUTDOWN_PREPARATION)
                  {
                     Rcd_PwrSt = RCD_POWER_LATCH;
                  }
                  else
                  {
                     Rcd_PwrSt = RCD_SLEEPING;
                  }
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidAPCConfig                                        */
/* !Description :  cette fonction permet d'assurer le calcul de l'état        */
/*                 UCE_stSt selon la configuration APC.                       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 UCE_stSt;                                                     */
/*  input bool RCD_ANTICIPATION;                                              */
/*  input bool RCD_POWER_ON;                                                  */
/*  input bool RCD_POWER_LATCH;                                               */
/*  input bool RCD_SLEEPING;                                                  */
/*  output uint8 Apc_PwrSt;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidAPCConfig(void)
{
   uint8  u8LocalUCE_stSt;


   VEMS_vidGET(UCE_stSt, u8LocalUCE_stSt);
   if (u8LocalUCE_stSt == RCD_COM_LATCH)
   {
      Apc_PwrSt = RCD_ANTICIPATION;
   }
   else
   {
      if (u8LocalUCE_stSt == RCD_INTERNAL_PARTIAL_WAKEUP_APC)
      {
         Apc_PwrSt = RCD_ANTICIPATION;
      }
      else
      {
         if (u8LocalUCE_stSt == RCD_MAIN_WAKEUP_APC)
         {
            Apc_PwrSt = RCD_POWER_ON;
         }
         else
         {
            if (u8LocalUCE_stSt == RCD_SHUTDOWN_PREPARATION_APC)
            {
               Apc_PwrSt = RCD_POWER_LATCH;
            }
            else
            {
               Apc_PwrSt = RCD_SLEEPING;
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_NVMSRV_vidInit                                      */
/* !Description :  La variable EcuSt_ctHotRst_Count est initialisée à la      */
/*                 réinitialisation  de l' EEPROM avec la                     */
/*                 calibrationEcuSt_ctHotRst_Count_Init.                      */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 EcuSt_ctHotRst_Count_Init;                                   */
/*  output uint16 EcuSt_ctHotRst_Count;                                       */
/*  output uint16 EcuSt_ctHotRst_Count_Init;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_NVMSRV_vidInit(void)
{
   VEMS_vidSET(EcuSt_ctHotRst_Count, EcuSt_ctHotRst_Count_Init);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidbRstSrvRstEepromCount                            */
/* !Description :  In case of a software reset Boolean (Srv_bRstSw_DiagSrv )  */
/*                 rising edge,the counter of maximum delay required to write */
/*                 in EEPROM Rcd_wait_wr_in_eeprom_count is reset to          */
/*                 calibration Rcd_wait_wr_in_eeprom_delay.                   */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Rcd_wait_wr_in_eeprom_delay;                                 */
/*  output uint16 Rcd_wait_wr_in_eeprom_count;                                */
/*  output boolean EcuSt_bPwrlEnd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidbRstSrvRstEepromCount(void)
{
   Rcd_wait_wr_in_eeprom_count =
               (uint16)MATHSRV_udtMIN(Rcd_wait_wr_in_eeprom_delay, 62500);
   EcuSt_bPwrlEnd = 0;
}

/*------------------------------- end of file --------------------------------*/