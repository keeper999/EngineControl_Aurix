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
/* !File            : CMDPWMACT_DT_SCH.C                                      */
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
/*   1 / Wg_EveRst_CmdPwmAct                                                  */
/*   2 / DmpVlvAct_EveRst_CmdPwmAct                                           */
/*   3 / DmpVlvAct_SdlFast_CmdPwmAct                                          */
/*   4 / OilSysHw_SdlFast_CmdPwmAct                                           */
/*   5 / CoT_SdlSlow_CmdPwmAct                                                */
/*   6 / Wg_SdlMid_CmdPwmAct                                                  */
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
#include "CMDPWMACT_DT.h"
#include "CMDPWMACT_DT_L.h"
#include "CMDPWMACT_DT_IM.h"
#include "CMDPWMACT_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_EveRst_CmdPwmAct                                        */
/* !Description :  Reset event                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CMDPWMACT_DT_vidCmdPwmWgcCmd();                          */
/*  input boolean Ctrl_bTrbAct_rCtl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_EveRst_CmdPwmAct                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_EveRst_CmdPwmAct(void)
{
   boolean bLocalCtrl_bTrbAct_rCtl;


   VEMS_vidGET(Ctrl_bTrbAct_rCtl, bLocalCtrl_bTrbAct_rCtl);
   if (bLocalCtrl_bTrbAct_rCtl != 0)
   {
      CMDPWMACT_DT_vidCmdPwmWgcCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvAct_EveRst_CmdPwmAct                                 */
/* !Description :  Reset event                                                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWMACT_DT_vidCmdPwmDmpVlvCmd();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlvAct_EveRst_CmdPwmAct                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvAct_EveRst_CmdPwmAct(void)
{
   CMDPWMACT_DT_vidCmdPwmDmpVlvCmd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvAct_SdlFast_CmdPwmAct                                */
/* !Description :  Fast monitor for the DmpVlvAct function                    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWMACT_DT_vidCmdPwmDmpVlvCmd();                       */
/*  input uint8 CMDPWMACT_DT_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlvAct_SdlFast_CmdPwmAct                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvAct_SdlFast_CmdPwmAct(void)
{
   if (CMDPWMACT_DT_u8Inhib != 0x5A)
   {
      CMDPWMACT_DT_vidCmdPwmDmpVlvCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OilSysHw_SdlFast_CmdPwmAct                                 */
/* !Description :  Quick Service Monitor of OilSysHw                          */
/* !Number      :  SCH.4                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CMDPWMACT_DT_vidCmdPwmCtlPmpReq();                       */
/*  input uint8 CMDPWMACT_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bOilPmpCmd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : OilSysHw_SdlFast_CmdPwmAct                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OilSysHw_SdlFast_CmdPwmAct(void)
{
   boolean bLocalCtrl_bOilPmpCmd;


   if (CMDPWMACT_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bOilPmpCmd, bLocalCtrl_bOilPmpCmd);
      if (bLocalCtrl_bOilPmpCmd != 0)
      {
         CMDPWMACT_DT_vidCmdPwmCtlPmpReq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_SdlSlow_CmdPwmAct                                      */
/* !Description :  Slow scheduler                                             */
/* !Number      :  SCH.5                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CMDPWMACT_DT_vidCmdPwmTrbWaPmp();                        */
/*  input uint8 CMDPWMACT_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bAcv_TrbCoWaPmp;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_SdlSlow_CmdPwmAct                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_SdlSlow_CmdPwmAct(void)
{
   boolean bLocalCtrl_bAcv_TrbCoWaPmp;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;


   if (CMDPWMACT_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_TrbCoWaPmp, bLocalCtrl_bAcv_TrbCoWaPmp);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);

      if (  (bLocalCtrl_bAcv_TrbCoWaPmp != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalUCE_bPwrlAcv != 0)))
      {
         CMDPWMACT_DT_vidCmdPwmTrbWaPmp();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_SdlMid_CmdPwmAct                                        */
/* !Description :  Middle monitor for AirPres function                        */
/* !Number      :  SCH.6                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CMDPWMACT_DT_vidCmdPwmWgcCmd();                          */
/*  input uint8 CMDPWMACT_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bTrbAct_rCtl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_SdlMid_CmdPwmAct                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_SdlMid_CmdPwmAct(void)
{
   boolean bLocalCtrl_bTrbAct_rCtl;


   if (CMDPWMACT_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bTrbAct_rCtl, bLocalCtrl_bTrbAct_rCtl);
      if (bLocalCtrl_bTrbAct_rCtl != 0)
      {
         CMDPWMACT_DT_vidCmdPwmWgcCmd();
      }
   }
}
/*-------------------------------- end of file -------------------------------*/