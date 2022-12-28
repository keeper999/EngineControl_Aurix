/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CMDPWM                                                  */
/* !Description     : CMDPWM component.                                       */
/*                                                                            */
/* !Module          : CMDPWM                                                  */
/* !Description     : SPECIFICATION DES COMMANDES EN PWM  ENVOYEES AU BSW     */
/*                                                                            */
/* !File            : CMDPWM_FCT1.C                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CMDPWM_vidCmdPwmCstr                                                 */
/*   2 / CMDPWM_vidCmdPwmPropFuPmp                                            */
/*   3 / CMDPWM_vidCmdPwmVlvActEx                                             */
/*   4 / CMDPWM_vidCmdPwmVlvActIn                                             */
/*   5 / CMDPWM_vidF00InitCmdPwmPropFuPmP                                     */
/*   6 / CMDPWM_vidF00_Init_CmdPwmVlvAct                                      */
/*   7 / CMDPWM_vidCmdPwmCoFan                                                */
/*   8 / CMDPWM_vidCmdPwmECTCmd                                               */
/*   9 / CMDPWM_vidCmd_tpac                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_6669891 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CMDPWM/CMDPWM_FCT1.C_v            $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   29 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   29 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CMDPWM.h"
#include "CMDPWM_L.h"
#include "CMDPWM_IM.h"
#include "PWMHAL.h"
#include "HBHAL.h"
#include "CMDPWM_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidCmdPwmCstr                                       */
/* !Description :  Fréquence du signal pwm ainsi que la consigne RCO de       */
/*                 commande de l'électrovanne de la purge canister envoyé au  */
/*                 BSW.                                                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/* udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                      */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutycycle);                                  */
/*  input uint16 Commande_purge_pwm_freq;                                     */
/*  input uint16 Commande_purge_pwm_rco;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidCmdPwmCstr(void)
{
   uint16 u16LocalCommande_purge_pwm_freq;
   uint16 u16LocalCommande_purge_pwm_rco;

   VEMS_vidGET(Commande_purge_pwm_freq, u16LocalCommande_purge_pwm_freq);
   VEMS_vidGET(Commande_purge_pwm_rco, u16LocalCommande_purge_pwm_rco);

   PWMHAL_vidWriteFrequency(CH_PWM_CANISTER_PURGE,
                            u16LocalCommande_purge_pwm_freq);
   PWMHAL_vidWrite(CH_PWM_CANISTER_PURGE, u16LocalCommande_purge_pwm_rco);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidCmdPwmPropFuPmp                                  */
/* !Description :  Signal de commande de la pompe proportionnelle envoyé au   */
/*                 BSW.                                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutycycle);                                  */
/*  input uint16 Commande_pompe_ess_pwm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidCmdPwmPropFuPmp(void)
{
   uint16 u16LocalCommande_pompe_ess_pwm;

   VEMS_vidGET(Commande_pompe_ess_pwm, u16LocalCommande_pompe_ess_pwm);
   PWMHAL_vidWrite(CH_PWM_FUEL_PUMP, u16LocalCommande_pompe_ess_pwm);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidCmdPwmVlvActEx                                   */
/* !Description :  Acquisition de la valeur du signal RCO appliqué à la       */
/*                 commande VVT échappement et envoyé au BSW.                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutycycle);                                  */
/*  input uint16 Commande_vvt_ech_pwm_rco;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidCmdPwmVlvActEx(void)
{
   uint16 u16LocalCommande_vvt_ech_pwm_rco;

   VEMS_vidGET(Commande_vvt_ech_pwm_rco, u16LocalCommande_vvt_ech_pwm_rco);
   PWMHAL_vidWrite(CH_PWM_EXHAUST_VVT, u16LocalCommande_vvt_ech_pwm_rco);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidCmdPwmVlvActIn                                   */
/* !Description :  Valeur du signal RCO appliqué à la commande VVT admission  */
/*                 et envoyé au BSW.                                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutycycle);                                  */
/*  input uint16 Commande_vvt_adm_pwm_rco;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidCmdPwmVlvActIn(void)
{
   uint16 u16LocalCommande_vvt_adm_pwm_rco;

   VEMS_vidGET(Commande_vvt_adm_pwm_rco, u16LocalCommande_vvt_adm_pwm_rco);
   PWMHAL_vidWrite(CH_PWM_INTAKE_VVT, u16LocalCommande_vvt_adm_pwm_rco);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidF00InitCmdPwmPropFuPmP                           */
/* !Description :  Valeur récupérée de la fréquence ainsi que la valeur d'init*/
/*                 de la commande de la pompe proportionnelle envoyé au BSW.  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/*  udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                     */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutycycle);                                  */
/*  input uint16 FuPmp_frqStPropFuPmp_C;                                      */
/*  input uint16 FuPmp_rFlowFuTnkPmpIni_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidF00InitCmdPwmPropFuPmP(void)
{
   PWMHAL_vidWriteFrequency(CH_PWM_FUEL_PUMP, FuPmp_frqStPropFuPmp_C);
   PWMHAL_vidWrite(CH_PWM_FUEL_PUMP, FuPmp_rFlowFuTnkPmpIni_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidF00_Init_CmdPwmVlvAct                            */
/* !Description :  Fréquence du signal RCO de commande VVT admission et       */
/*                 échappement envoyé au BSW.                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/*  udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                     */
/*  input uint16 Frequency_vvt_adm_cal;                                       */
/*  input uint16 Frequency_vvt_echap_cal;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidF00_Init_CmdPwmVlvAct(void)
{
   PWMHAL_vidWriteFrequency(CH_PWM_INTAKE_VVT, Frequency_vvt_adm_cal);
   PWMHAL_vidWriteFrequency(CH_PWM_EXHAUST_VVT, Frequency_vvt_echap_cal);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidCmdPwmCoFan                                      */
/* !Description :  Valeur récupérée de la fréquence ainsi que la valeur d'init*/
/*                 de la commande CMD_GMV1 envoyé au BSW.                     */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/* udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                      */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutycycle);                                  */
/*  input uint16 Commande_GMV_C;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidCmdPwmCoFan(void)
{
   uint16  u16LocalCommande_GMV_C;


   VEMS_vidGET(Commande_GMV_C, u16LocalCommande_GMV_C);

   PWMHAL_vidWriteFrequency(CH_PWM_GMV1, 2000);
   PWMHAL_vidWrite(CH_PWM_GMV1, u16LocalCommande_GMV_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidCmdPwmECTCmd                                     */
/* !Description :  Fréquence du signal RCO de commande du thermostat envoyé au*/
/*                 BSW.                                                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutycycle);                                  */
/*  input uint16 Commande_ectdrv_pwm_rco;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidCmdPwmECTCmd(void)
{
   uint16  u16LocalCommande_ectdrv_pwm_rco;


   VEMS_vidGET(Commande_ectdrv_pwm_rco, u16LocalCommande_ectdrv_pwm_rco);
   PWMHAL_vidWrite(CH_PWM_THERMOSTAT_PILOTE, u16LocalCommande_ectdrv_pwm_rco);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidCmd_tpac                                         */
/* !Description :  Function reponsable de la commande du throttle.            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HBHAL_vidWrite(argin uint8 u8Channel, argin              */
/* HBHAL_tudtSetPoint udtSetPoint);                                           */
/*  input sint16 Commande_bpm_pwm_rco;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidCmd_tpac(void)
{
   sint16  s16LocalCommande_bpm_pwm_rco;


   VEMS_vidGET(Commande_bpm_pwm_rco, s16LocalCommande_bpm_pwm_rco);
   s16LocalCommande_bpm_pwm_rco =
      (sint16)MATHSRV_udtCLAMP(s16LocalCommande_bpm_pwm_rco, -16384, 16384);
   HBHAL_vidWrite(CH_HB_CMD_THR, (sint32)s16LocalCommande_bpm_pwm_rco);
}
/*-------------------------------- end of file -------------------------------*/