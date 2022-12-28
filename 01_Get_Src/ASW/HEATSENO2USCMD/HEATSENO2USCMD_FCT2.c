/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2USCMD                                          */
/* !Description     : HEATSENO2USCMD Component                                */
/*                                                                            */
/* !Module          : HEATSENO2USCMD                                          */
/* !Description     : COMMANDE DU CHAUFFAGE SONDE O2 ON/OFF AMONT             */
/*                                                                            */
/* !File            : HEATSENO2USCMD_FCT2.c                                   */
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
/*   1 / HEATSENO2USCMD_vidDriverCmd                                          */
/*   2 / HEATSENO2USCMD_vidLsUsHeatTst                                        */
/*                                                                            */
/* !Reference   : V02 NT 09 04308 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HEATSENO2/HEATSENO2USCMD/HEATSEN$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "HEATSENO2USCMD.H"
#include "HEATSENO2USCMD_l.h"
#include "HEATSENO2USCMD_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidDriverCmd                                */
/* !Description :  fonction de calcul de la sortie calculateur commandant le  */
/*                 transistor de gestion du chauffage de la sonde             */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Lshd_upstr_rco_periode;                                      */
/*  input uint16 HEATSENO2USCMD_u16RcoPeriodPrev;                             */
/*  input uint16 Lshd_upstr_period_counter;                                   */
/*  input uint16 Lshd_upstr_t_on_uavn0;                                       */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrReq;                                 */
/*  input boolean Ext_bAcvHeatWkuLsSys;                                       */
/*  output uint16 HEATSENO2USCMD_u16RcoPeriodPrev;                            */
/*  output uint16 Lshd_upstr_period_counter;                                  */
/*  output boolean Lshd_upstr_period_updating;                                */
/*  output boolean LsSys_bLsUsMainOxCHeatPwrCmd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidDriverCmd(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalExt_bAcvHeatWkuLsSys;
   uint8   u8LocalLsSys_rLsUsMainOxCHeatPwr;
   uint16  u16LocalDuration;
   uint16  u16localCounter;
   sint16  s16LocalRcoPeriod;


   if (Lshd_upstr_rco_periode > 0)
   {
      u16LocalDuration = (uint16)(Lshd_upstr_rco_periode - 1);
   }
   else
   {
      u16LocalDuration = 0;
   }

   if (  (HEATSENO2USCMD_u16RcoPeriodPrev != 0)
      && (Lshd_upstr_period_counter == 0))
   {
      HEATSENO2USCMD_u16RcoPeriodPrev = 0;
      Lshd_upstr_period_counter =
         (uint16)MATHSRV_udtMIN(u16LocalDuration, 510);
      if (Lshd_upstr_period_counter == 0)
      {
         Lshd_upstr_period_updating = 1;
      }
      else
      {
         Lshd_upstr_period_updating = 0;
      }
   }
   else
   {
      HEATSENO2USCMD_u16RcoPeriodPrev =
         (uint16)MATHSRV_udtMIN(Lshd_upstr_period_counter, 510);
      if (Lshd_upstr_period_counter > 0)
      {
         u16localCounter = (uint16)(Lshd_upstr_period_counter - 1);
         Lshd_upstr_period_counter =
            (uint16)MATHSRV_udtMIN(u16localCounter, 510);
         if (Lshd_upstr_period_counter == 0)
         {
            Lshd_upstr_period_updating = 1;
         }
         else
         {
            Lshd_upstr_period_updating = 0;
         }
      }
   }

   s16LocalRcoPeriod = (sint16)(Lshd_upstr_rco_periode - Lshd_upstr_t_on_uavn0);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(LsSys_rLsUsMainOxCHeatPwrReq, u8LocalLsSys_rLsUsMainOxCHeatPwr);
   VEMS_vidGET(Ext_bAcvHeatWkuLsSys, bLocalExt_bAcvHeatWkuLsSys);
   if (  (Lshd_upstr_period_counter >= s16LocalRcoPeriod)
      && (u8LocalLsSys_rLsUsMainOxCHeatPwr > 0)
      && (  (bLocalClef_de_contact != 0)
         || (bLocalExt_bAcvHeatWkuLsSys != 0)))
   {
      LsSys_bLsUsMainOxCHeatPwrCmd = 1;
   }
   else
   {
      LsSys_bLsUsMainOxCHeatPwrCmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidLsUsHeatTst                              */
/* !Description :  Ce bloc provisionne l’interface permettant d’effectuer le  */
/*                 test actionneur chauffage sonde O2 amont.                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean HeatSenO2_bUsPwrRlyCmd;                                     */
/*  input boolean HeatSenO2_bUsTstCmd;                                        */
/*  input boolean LsSys_bLsUsMainOxCHeatPwrCmd;                               */
/*  output boolean Chauf_o2_amont_demande_on;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidLsUsHeatTst(void)
{
   boolean bLocalHeatSenO2_bUsPwrRlyCmd;
   boolean bLocalHeatSenO2_bUsTstCmd;
   boolean bLocalChauf_o2_amont_demande_on;


   VEMS_vidGET(HeatSenO2_bUsPwrRlyCmd, bLocalHeatSenO2_bUsPwrRlyCmd);
   if (bLocalHeatSenO2_bUsPwrRlyCmd != 0)
   {
      VEMS_vidGET(HeatSenO2_bUsTstCmd, bLocalHeatSenO2_bUsTstCmd);
      VEMS_vidSET(Chauf_o2_amont_demande_on, bLocalHeatSenO2_bUsTstCmd);
   }
   else
   {
      bLocalChauf_o2_amont_demande_on = LsSys_bLsUsMainOxCHeatPwrCmd;
      VEMS_vidSET(Chauf_o2_amont_demande_on, bLocalChauf_o2_amont_demande_on);
   }
}

/*------------------------------- end of file --------------------------------*/