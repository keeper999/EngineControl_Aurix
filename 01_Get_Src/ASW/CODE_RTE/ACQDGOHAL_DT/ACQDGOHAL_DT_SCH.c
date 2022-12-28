/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQDGOHAL_DT                                            */
/* !Description     : ACQDGOHAL_DT Component.                                 */
/*                                                                            */
/* !Module          : ACQDGOHAL_DT                                            */
/* !Description     : Acquisition of Diagnoses States and results for specific*/
/*                    components                                              */
/*                                                                            */
/* !File            : ACQDGOHAL_DT_SCH.C                                      */
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
/*   1 / Ext_EveRst_AcqDgoHaL                                                 */
/*   2 / AC_SdlSlow_AdHeatCmdDiag                                             */
/*   3 / ASIC_SdlFast_diagasicgdiDiag                                         */
/*   4 / CoT_SdlSlow_TrbWaPmpDiag                                             */
/*   5 / DmpVlvAct_SdlFast_DmpVlvCmdDiag                                      */
/*   6 / OilSysHw_SdlFast_CtlPmpReqDiag                                       */
/*   7 / Oil_SdlFast_OilLvlAcqDiag                                            */
/*   8 / PFuCtl_SdlMid_HPPmpActCmdDiag                                        */
/*   9 / Wg_SdlMid_WgcCmdDiag                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6854092 / 01                                        */
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
#include "ACQDGOHAL_DT.h"
#include "ACQDGOHAL_DT_L.h"
#include "ACQDGOHAL_DT_IM.h"
#include "ACQDGOHAL_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_EveRst_AcqDgoHaL                                       */
/* !Description :  Event reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_DT_vidDgoHalInit();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Ext_EveRst_AcqDgoHaL                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_EveRst_AcqDgoHaL(void)
{
   ACQDGOHAL_DT_vidDgoHalInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_SdlSlow_AdHeatCmdDiag                                   */
/* !Description :  Slow monitoring for additional heating command function    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_DT_vidDgoHalCTP();                             */
/*  input uint8 ACQDGOHAL_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bTreatAdHeatRly;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_SdlSlow_AdHeatCmdDiag                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_SdlSlow_AdHeatCmdDiag(void)
{
   boolean bLocalCtrl_bTreatAdHeatRly;
   boolean bLocalECU_bWkuMain;


   if (ACQDGOHAL_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bTreatAdHeatRly, bLocalCtrl_bTreatAdHeatRly);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      if (  (bLocalCtrl_bTreatAdHeatRly != 0)
         && (bLocalECU_bWkuMain != 0))
      {
         ACQDGOHAL_DT_vidDgoHalCTP();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ASIC_SdlFast_diagasicgdiDiag                               */
/* !Description :  Fast scheduler for the ASIC GDI diagnosis                  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_DT_vidDgoHalASICGDI();                         */
/*  input uint8 ACQDGOHAL_DT_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ASIC_SdlFast_diagasicgdiDiag                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ASIC_SdlFast_diagasicgdiDiag(void)
{
   if (ACQDGOHAL_DT_u8Inhib != 0x5A)
   {
      ACQDGOHAL_DT_vidDgoHalASICGDI();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_SdlSlow_TrbWaPmpDiag                                   */
/* !Description :  Slow scheduler                                             */
/* !Number      :  SCH.4                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_DT_vidDgoHalTrbWaPmp();                        */
/*  input uint8 ACQDGOHAL_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bAcv_TrbCoWaPmp;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_SdlSlow_TrbWaPmpDiag                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_SdlSlow_TrbWaPmpDiag(void)
{
   boolean bLocalCtrl_bAcv_TrbCoWaPmp;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;


   if (ACQDGOHAL_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_TrbCoWaPmp, bLocalCtrl_bAcv_TrbCoWaPmp);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
      if (  (bLocalCtrl_bAcv_TrbCoWaPmp != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalUCE_bPwrlAcv != 0)))
      {
         ACQDGOHAL_DT_vidDgoHalTrbWaPmp();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvAct_SdlFast_DmpVlvCmdDiag                            */
/* !Description :  Fast monitor for the DmpVlvAct function                    */
/* !Number      :  SCH.5                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_DT_vidDgoHalDmpVlvCmd();                       */
/*  input uint8 ACQDGOHAL_DT_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlvAct_SdlFast_DmpVlvCmdDiag                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvAct_SdlFast_DmpVlvCmdDiag(void)
{
   if (ACQDGOHAL_DT_u8Inhib != 0x5A)
   {
      ACQDGOHAL_DT_vidDgoHalDmpVlvCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OilSysHw_SdlFast_CtlPmpReqDiag                             */
/* !Description :  Quick Service Monitor of OilSysHw                          */
/* !Number      :  SCH.6                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_DT_vidDgoHalCtlPmpReq();                       */
/*  input uint8 ACQDGOHAL_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bOilPmpCmd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : OilSysHw_SdlFast_CtlPmpReqDiag                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OilSysHw_SdlFast_CtlPmpReqDiag(void)
{
   boolean bLocalCtrl_bOilPmpCmd;


   if (ACQDGOHAL_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bOilPmpCmd, bLocalCtrl_bOilPmpCmd);
      if (bLocalCtrl_bOilPmpCmd != 0)
      {
         ACQDGOHAL_DT_vidDgoHalCtlPmpReq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlFast_OilLvlAcqDiag                                  */
/* !Description :  Fast scheduler                                             */
/* !Number      :  SCH.7                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_DT_vidDgoHalOilLvlAcq();                       */
/*  input uint8 ACQDGOHAL_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bAcv_uEngOilLvl;                                       */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean UCE_bPwrlAcv;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlFast_OilLvlAcqDiag                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlFast_OilLvlAcqDiag(void)
{
   boolean bLocalCtrl_bAcv_uEngOilLvl;
   boolean bLocalDIAGCAN_bIntegElectronique;
   boolean bLocalUCE_bPwrlAcv;


   if (ACQDGOHAL_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_uEngOilLvl, bLocalCtrl_bAcv_uEngOilLvl);
      VEMS_vidGET(DIAGCAN_bIntegratioElectronique,
                  bLocalDIAGCAN_bIntegElectronique);
      VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
      if (  (bLocalCtrl_bAcv_uEngOilLvl != 0)
         && (bLocalDIAGCAN_bIntegElectronique == 0)
         && (bLocalUCE_bPwrlAcv != 0))
      {
         ACQDGOHAL_DT_vidDgoHalOilLvlAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_SdlMid_HPPmpActCmdDiag                              */
/* !Description :  Intermediate scheduler for HPPmpActCmd                     */
/* !Number      :  SCH.8                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_DT_vidDgoHlHPPmpActCmd();                      */
/*  input uint8 ACQDGOHAL_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PFuCtl_SdlMid_HPPmpActCmdDiag                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_SdlMid_HPPmpActCmdDiag(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (ACQDGOHAL_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);
      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         ACQDGOHAL_DT_vidDgoHlHPPmpActCmd();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_SdlMid_WgcCmdDiag                                       */
/* !Description :  Middle monitor for AirPres function                        */
/* !Number      :  SCH.9                                                      */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_DT_vidDgoHalCmdWgc();                          */
/*  input uint8 ACQDGOHAL_DT_u8Inhib;                                         */
/*  input boolean Ctrl_bTrbAct_rCtl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_SdlMid_WgcCmdDiag                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_SdlMid_WgcCmdDiag(void)
{
   boolean bLocalCtrl_bTrbAct_rCtl;


   if (ACQDGOHAL_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bTrbAct_rCtl, bLocalCtrl_bTrbAct_rCtl);
      if (bLocalCtrl_bTrbAct_rCtl != 0)
      {
         ACQDGOHAL_DT_vidDgoHalCmdWgc();
      }
   }
}
/*-------------------------------- end of file -------------------------------*/