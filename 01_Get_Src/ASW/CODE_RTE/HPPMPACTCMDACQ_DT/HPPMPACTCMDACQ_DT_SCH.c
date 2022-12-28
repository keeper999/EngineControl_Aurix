/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HPPMPACTCMDACQ_DT                                       */
/* !Description     : HPPMPACTCMDACQ_DT Component                             */
/*                                                                            */
/* !Module          : HPPMPACTCMDACQ_DT                                       */
/* !Description     : PMPHAL acquisition                                      */
/*                                                                            */
/* !File            : HPPMPACTCMDACQ_DT_SCH.c                                 */
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
/*   1 / PFuCtl_EveRTSt_HPPmpActCmdAcq                                        */
/*   2 / PFuCtl_EveRst_HPPmpActCmdAcq                                         */
/*   3 / PFuCtl_EveSpl_HPPmpActCmdAcq                                         */
/*   4 / PFuCtl_EveStTR_HPPmpActCmdAcq                                        */
/*   5 / PFuCtl_SdlFast_HPPmpActCmdAcq                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6882935 / 01                                        */
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
#include "HPPMPACTCMDACQ_DT.h"
#include "HPPMPACTCMDACQ_DT_L.h"
#include "HPPMPACTCMDACQ_DT_IM.h"
#include "HPPMPACTCMDACQ_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_EveRTSt_HPPmpActCmdAcq                              */
/* !Description :  Rot-to-Stall Event for HPPmpActCmd                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPCmd_Init();                      */
/*  input uint8 HPPMPACTCMDACQ_DT_u8Inhib;                                    */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : PFuCtl_EveRTSt_HPPmpActCmdAcq                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_EveRTSt_HPPmpActCmdAcq(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (HPPMPACTCMDACQ_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);
      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         HPPMPACTCMDACQ_DT_vidHPPCmd_Init();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_EveRst_HPPmpActCmdAcq                               */
/* !Description :  Reset Event for HPPmpActCmd                                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPCmd_Ena();                       */
/*  extf argret void HPPMPACTCMDACQ_DT_vidbStopHPPCmd();                      */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : PFuCtl_EveRst_HPPmpActCmdAcq                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_EveRst_HPPmpActCmdAcq(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);
   if (bLocalCtrl_bAcv_HpPmp != 0)
   {
      HPPMPACTCMDACQ_DT_vidHPPCmd_Ena();
      HPPMPACTCMDACQ_DT_vidbStopHPPCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_EveSpl_HPPmpActCmdAcq                               */
/* !Description :  Spill Event for HPPmpActCmd                                */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPApplCmd();                       */
/*  extf argret void HPPMPACTCMDACQ_DT_vidbStopHPPCmd();                      */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPContnCmd();                      */
/*  input uint8 HPPMPACTCMDACQ_DT_u8Inhib;                                    */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : PFuCtl_EveSpl_HPPmpActCmdAcq                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_EveSpl_HPPmpActCmdAcq(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (HPPMPACTCMDACQ_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);
      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         HPPMPACTCMDACQ_DT_vidHPPApplCmd();
         HPPMPACTCMDACQ_DT_vidbStopHPPCmd();
         HPPMPACTCMDACQ_DT_vidHPPContnCmd();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_EveStTR_HPPmpActCmdAcq                              */
/* !Description :  Stall-to-Rot Event for HPPmpActCmd                         */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPCmd_Ena();                       */
/*  extf argret void HPPMPACTCMDACQ_DT_vidbStopHPPCmd();                      */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPApplCmd();                       */
/*  input uint8 HPPMPACTCMDACQ_DT_u8Inhib;                                    */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : PFuCtl_EveStTR_HPPmpActCmdAcq                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_EveStTR_HPPmpActCmdAcq(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (HPPMPACTCMDACQ_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);
      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         HPPMPACTCMDACQ_DT_vidHPPCmd_Ena();
         HPPMPACTCMDACQ_DT_vidbStopHPPCmd();
         HPPMPACTCMDACQ_DT_vidHPPApplCmd();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_SdlFast_HPPmpActCmdAcq                              */
/* !Description :  Fast scheduler for HPPmpActCmd                             */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPMPACTCMDACQ_DT_vidHPPContnCmd();                      */
/*  input uint8 HPPMPACTCMDACQ_DT_u8Inhib;                                    */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : PFuCtl_SdlFast_HPPmpActCmdAcq                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_SdlFast_HPPmpActCmdAcq(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (HPPMPACTCMDACQ_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);
      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         HPPMPACTCMDACQ_DT_vidHPPContnCmd();
      }
   }
}

/*------------------------------end of file-----------------------------------*/