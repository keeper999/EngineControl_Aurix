/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSCMD                                          */
/* !Description     : HEATSENO2DSCMD Component                                */
/*                                                                            */
/* !Module          : HEATSENO2DSCMD                                          */
/* !Description     : COMMANDE DU CHAUFFAGE SONDE O2 ON/OFF AVAL              */
/*                                                                            */
/* !File            : HEATSENO2DSCMD_FCT2.C                                   */
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
/*   1 / HEATSENO2DSCMD_vidDriverCmd                                          */
/*   2 / HEATSENO2DSCMD_vidLsUsHeatTst                                        */
/*                                                                            */
/* !Reference   : V02 NT 09 04727 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/HEATSENO2/HEATSENO2DSCMD/HEATSENO2$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   24 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   24 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2DSCMD.H"
#include "HEATSENO2DSCMD_l.h"
#include "HEATSENO2DSCMD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidDriverCmd                                */
/* !Description :  fonction de  calcul de la sortie calculateur commandant le */
/*                 transistor de gestion du chauffage de la sonde             */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Lshd_dwstr_rco_periode;                                      */
/*  input uint16 HEATSENO2DSCMD_u16RcoPeriodPrev;                             */
/*  input uint16 Lshd_dwstr_period_counter;                                   */
/*  input uint16 Lshd_dwstr_t_on_uavn0;                                       */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrReq;                                 */
/*  input boolean Clef_de_contact;                                            */
/*  output uint16 HEATSENO2DSCMD_u16RcoPeriodPrev;                            */
/*  output uint16 Lshd_dwstr_period_counter;                                  */
/*  output boolean Lshd_dwstr_period_updating;                                */
/*  output boolean LsSys_bLsDsMainOxCHeatPwrCmd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidDriverCmd(void)
{
   boolean bLocalClef_de_contact;
   uint8   u8LocalLsSys_rLsDsMainOxCHeatPwr;
   uint16  u16LocalDuration;
   uint16  u16LocalCounter;
   sint16  s16LocalRcoPeriod;


   if (Lshd_dwstr_rco_periode > 0)
   {
      u16LocalDuration = (uint16)(Lshd_dwstr_rco_periode - 1);
   }
   else
   {
      u16LocalDuration = 0;
   }
   if (  (HEATSENO2DSCMD_u16RcoPeriodPrev != 0)
      && (Lshd_dwstr_period_counter == 0))
   {
      HEATSENO2DSCMD_u16RcoPeriodPrev = 0;
      Lshd_dwstr_period_counter =
         (uint16)MATHSRV_udtMIN(u16LocalDuration, 510);
      if (Lshd_dwstr_period_counter == 0)
      {
         Lshd_dwstr_period_updating = 1;
      }
      else
      {
         Lshd_dwstr_period_updating = 0;
      }
   }
   else
   {
      HEATSENO2DSCMD_u16RcoPeriodPrev =
         (uint16)MATHSRV_udtMIN(Lshd_dwstr_period_counter, 510);
      if (Lshd_dwstr_period_counter > 0)
      {
         u16LocalCounter = (uint16)(Lshd_dwstr_period_counter - 1);
         Lshd_dwstr_period_counter =
            (uint16)MATHSRV_udtMIN(u16LocalCounter, 510);
         if (Lshd_dwstr_period_counter == 0)
         {
            Lshd_dwstr_period_updating = 1;
         }
         else
         {
            Lshd_dwstr_period_updating = 0;
         }
      }
   }

   s16LocalRcoPeriod = (sint16)(Lshd_dwstr_rco_periode - Lshd_dwstr_t_on_uavn0);
   VEMS_vidGET(LsSys_rLsDsMainOxCHeatPwrReq,u8LocalLsSys_rLsDsMainOxCHeatPwr);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   if (  (Lshd_dwstr_period_counter >= s16LocalRcoPeriod)
      && (u8LocalLsSys_rLsDsMainOxCHeatPwr > 0)
      && (bLocalClef_de_contact != 0 )  )
   {
      LsSys_bLsDsMainOxCHeatPwrCmd = 1;
   }
   else
   {
      LsSys_bLsDsMainOxCHeatPwrCmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidLsUsHeatTst                              */
/* !Description :  Ce bloc provisionne l’interface permettant d’effectuer le  */
/*                 test actionneur chauffage sonde O2 aval.                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean HeatSenO2_bDsPwrRlyCmd;                                     */
/*  input boolean HeatSenO2_bDsTstCmd;                                        */
/*  input boolean LsSys_bLsDsMainOxCHeatPwrCmd;                               */
/*  output boolean Chauf_o2_aval_demande_on;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidLsUsHeatTst(void)
{
   boolean bLocalHeatSenO2_bDsPwrRlyCmd;
   boolean bLocalHeatSenO2_bDsTstCmd;
   boolean bLocalChauf_o2_aval_demande_on;


   VEMS_vidGET(HeatSenO2_bDsPwrRlyCmd, bLocalHeatSenO2_bDsPwrRlyCmd);
   if (bLocalHeatSenO2_bDsPwrRlyCmd != 0)
   {
      VEMS_vidGET(HeatSenO2_bDsTstCmd, bLocalHeatSenO2_bDsTstCmd);
      VEMS_vidSET(Chauf_o2_aval_demande_on,bLocalHeatSenO2_bDsTstCmd);
   }
   else
   {
      bLocalChauf_o2_aval_demande_on = LsSys_bLsDsMainOxCHeatPwrCmd;
      VEMS_vidSET(Chauf_o2_aval_demande_on, bLocalChauf_o2_aval_demande_on);
   }
}

/*------------------------------- end of file --------------------------------*/