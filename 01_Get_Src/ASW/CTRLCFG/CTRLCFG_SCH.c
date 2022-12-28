/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CTRLCFG                                                 */
/* !Description     : CTRLCFG Component                                       */
/*                                                                            */
/* !Module          : CTRLCFG                                                 */
/* !Description     : CONFIGURATION FLOW MANAGEMENT                           */
/*                                                                            */
/* !File            : CTRLCFG_SCH.c                                           */
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
/*   1 / Cf_EveRst_CtrlCfg                                                    */
/*   2 / Cf_SdlFast_CtrlCfg                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5068500 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CTRLCFG/CTRLCFG_SCH.C_v         $*/
/* $Revision::   1.16     $$Author::   pbakabad       $$Date::   Jul 01 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 01 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CTRLCFG.h"
#include "CTRLCFG_L.h"
#include "CTRLCFG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_CtrlCfg                                          */
/* !Description :  Event reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CTRLCFG_vidCtrlCfg();                                    */
/*  extf argret void CTRLCFG_vidCtrlCfg2();                                   */
/*  extf argret void CTRLCFG_vidFrameCfg();                                   */
/*  extf argret void CTRLCFG_vidFrameCfg2();                                  */
/*  extf argret void CTRLCFG_vidFrameCfg3();                                  */
/*  extf argret void CTRLCFG_vidOther_Frames_Param();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_CtrlCfg                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_CtrlCfg(void)
{
   CTRLCFG_vidCtrlCfg();
   CTRLCFG_vidCtrlCfg2();
   CTRLCFG_vidFrameCfg();
   CTRLCFG_vidFrameCfg2();
   CTRLCFG_vidFrameCfg3();
   CTRLCFG_vidOther_Frames_Param();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_CtrlCfg                                         */
/* !Description :  Fast monitoring                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CTRLCFG_vidCtrlCfg();                                    */
/*  extf argret void CTRLCFG_vidCtrlCfg2();                                   */
/*  extf argret void CTRLCFG_vidFrameCfg();                                   */
/*  extf argret void CTRLCFG_vidFrameCfg2();                                  */
/*  extf argret void CTRLCFG_vidFrameCfg3();                                  */
/*  extf argret void CTRLCFG_vidOther_Frames_Param();                         */
/*  input uint8 CTRLCFG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_CtrlCfg                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_CtrlCfg(void)
{
   if (CTRLCFG_u8Inhib != 0x5A)
   {
      CTRLCFG_vidCtrlCfg();
      CTRLCFG_vidCtrlCfg2();
      CTRLCFG_vidFrameCfg();
      CTRLCFG_vidFrameCfg2();
      CTRLCFG_vidFrameCfg3();
      CTRLCFG_vidOther_Frames_Param();
   }
}
/*------------------------------- end of file --------------------------------*/