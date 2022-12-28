/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CMDPWMACT_DT                                            */
/* !Description     : CMDPWMACT_DT Component.                                 */
/*                                                                            */
/* !Module          : CMDPWMACT_DT                                            */
/* !Description     : SPECIFICATION OF PWM COMMANDS SENT TO BSW               */
/*                                                                            */
/* !File            : CMDPWMACT_DT_FCT1.C                                     */
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
/*   1 / CMDPWMACT_DT_vidCmdPwmTrbWaPmp                                       */
/*   2 / CMDPWMACT_DT_vidCmdPwmDmpVlvCmd                                      */
/*   3 / CMDPWMACT_DT_vidCmdPwmWgcCmd                                         */
/*   4 / CMDPWMACT_DT_vidCmdPwmCtlPmpReq                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6913248 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CMDPWMACT_DT.h"
#include "CMDPWMACT_DT_L.h"
#include "CMDPWMACT_DT_IM.h"
#include "PWMHAL.h"
#include "CMDPWMACT_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWMACT_DT_vidCmdPwmTrbWaPmp                             */
/* !Description :  The water pump commands (PWM frequency and duty cycle) are */
/*                 transmitted through the basic layer via the PWDHAL service */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/* udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                      */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutyCycle);                                  */
/*  input uint16 Commande_water_pump_pwm_freq;                                */
/*  input uint16 Commande_water_pump_pwm_rco;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWMACT_DT_vidCmdPwmTrbWaPmp(void)
{
   uint16 u16LocalCmd_water_pump_pwm_freq;
   uint16 u16LocalCmd_water_pump_pwm_rco;
   uint32 u32LocalCmd_water_pump_pwm_rco;


   VEMS_vidGET(Commande_water_pump_pwm_freq, u16LocalCmd_water_pump_pwm_freq);
   VEMS_vidGET(Commande_water_pump_pwm_rco, u16LocalCmd_water_pump_pwm_rco);

   u32LocalCmd_water_pump_pwm_rco = ( (u16LocalCmd_water_pump_pwm_rco * 4096)
                                    / 125);
   u16LocalCmd_water_pump_pwm_rco =
      (uint16)MATHSRV_udtMIN(u32LocalCmd_water_pump_pwm_rco, 65535);

   PWMHAL_vidWriteFrequency(CH_PWM_WATER_PUMP, u16LocalCmd_water_pump_pwm_freq);
   PWMHAL_vidWrite(CH_PWM_WATER_PUMP, u16LocalCmd_water_pump_pwm_rco);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWMACT_DT_vidCmdPwmDmpVlvCmd                            */
/* !Description :  The Dump-Valve commands  (PWM frequency and duty cycle) are*/
/*                  transmitted through the basic layer via the PWDHAL service*/
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutyCycle);                                  */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/* udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                      */
/*  input uint16 Commande_DmpVlv_pwm_rco;                                     */
/*  input uint16 Commande_DmpVlv_pwm_freq;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWMACT_DT_vidCmdPwmDmpVlvCmd(void)
{
   uint16 u16LocalCmd_DmpVlv_pwm_rco;
   uint16 u16LocalCmd_DmpVlv_pwm_freq;


   VEMS_vidGET(Commande_DmpVlv_pwm_rco, u16LocalCmd_DmpVlv_pwm_rco);
   VEMS_vidGET(Commande_DmpVlv_pwm_freq, u16LocalCmd_DmpVlv_pwm_freq);

   PWMHAL_vidWrite(CH_PWM_DUMP_VALVE, u16LocalCmd_DmpVlv_pwm_rco);
   PWMHAL_vidWriteFrequency(CH_PWM_DUMP_VALVE, u16LocalCmd_DmpVlv_pwm_freq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWMACT_DT_vidCmdPwmWgcCmd                               */
/* !Description :  The waste gate signal commands (PWM frequency and duty     */
/*                 cycle) are transmitted through the basic layer via the     */
/*                 PWDHAL service                                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutyCycle);                                  */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/* udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                      */
/*  input uint16 WgCmd_DutyCycTrbAct_rCtl;                                    */
/*  input uint16 WgcCmd_frqTrbAct_rCtl;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWMACT_DT_vidCmdPwmWgcCmd(void)
{
   uint16 u16LocalWgCmd_DutyCycTrbAct_rCtl;
   uint16 u16LocalWgcCmd_frqTrbAct_rCtl;


   VEMS_vidGET(WgCmd_DutyCycTrbAct_rCtl, u16LocalWgCmd_DutyCycTrbAct_rCtl);
   VEMS_vidGET(WgcCmd_frqTrbAct_rCtl, u16LocalWgcCmd_frqTrbAct_rCtl);

   PWMHAL_vidWrite(CH_PWM_WASTEGATE_PNEUMATIQUE,
                   u16LocalWgCmd_DutyCycTrbAct_rCtl);
   PWMHAL_vidWriteFrequency(CH_PWM_WASTEGATE_PNEUMATIQUE,
                            u16LocalWgcCmd_frqTrbAct_rCtl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWMACT_DT_vidCmdPwmCtlPmpReq                            */
/* !Description :  The oil pump solenoid valve load commands (PWM frequency   */
/*                 and duty cycle) are transmitted through the basic layer via*/
/*                 the PWDHAL service                                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PWMHAL_vidWrite(argin PWMHAL_tudtChannel udtChannel,     */
/* argin PWMHAL_tudtDutyCycle udtDutyCycle);                                  */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/* udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                      */
/*  input uint16 Oil_rPmpCmdAppl;                                             */
/*  input uint16 OilSysHw_frqPmpCmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWMACT_DT_vidCmdPwmCtlPmpReq(void)
{
   uint16 u16LocalOil_rPmpCmdAppl;
   uint16 u16LocalOilSysHw_frqPmpCmd;
   uint32 u32LocalOil_rPmpCmdAppl;


   VEMS_vidGET(Oil_rPmpCmdAppl, u16LocalOil_rPmpCmdAppl);
   VEMS_vidGET(OilSysHw_frqPmpCmd, u16LocalOilSysHw_frqPmpCmd);

   u32LocalOil_rPmpCmdAppl = ((u16LocalOil_rPmpCmdAppl * 4096) / 125);
   u16LocalOil_rPmpCmdAppl = (uint16)MATHSRV_udtMIN(u32LocalOil_rPmpCmdAppl,
                                                    65535);

   PWMHAL_vidWrite(CH_PWM_CTLPMPREQ, u16LocalOil_rPmpCmdAppl);
   PWMHAL_vidWriteFrequency(CH_PWM_CTLPMPREQ, u16LocalOilSysHw_frqPmpCmd);
}
/*-------------------------------- end of file -------------------------------*/
