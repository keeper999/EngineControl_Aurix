/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CKMNGIF                                                 */
/* !Description     : CKMNGIF component.                                      */
/*                                                                            */
/* !Module          : CKMNGIF                                                 */
/* !Description     : Interface Gestion Roue Dentée Vilebrequin.              */
/*                                                                            */
/* !File            : CKMNGIF_SCH2.C                                          */
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
/*   1 / Sync_EveCkOf_CkMngIf                                                 */
/*   2 / Sync_EveCkOn_CkMngIf                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6884590 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#069167                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/CKMNGIF/CkMngIf_sch2.c_v     $*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   31 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "CKMNGIF.h"
#include "CKMNGIF_IM.h"
#include "CKMNGIF_L.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkOf_CkMngIf                                       */
/* !Description :  Détection fin de rotation moteur                           */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidEngineRotNoDetection();                       */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkOf_CkMngIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkOf_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidEngineRotNoDetection();
      }

   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkOn_CkMngIf                                       */
/* !Description :  Détection rotation moteur                                  */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03007_001.01                                     */
/*                 VEMS_E_11_03007_002.01                                     */
/*                 VEMS_E_11_03007_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidEngineRotDetection();                         */
/*  input uint8 CKMNGIF_u8Inhib;                                              */
/*  input boolean Ctrl_bAcv_EngMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkOn_CkMngIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkOn_CkMngIf(void)
{
   boolean bLocalCtrl_bAcv_EngMes;


   if (CKMNGIF_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_EngMes, bLocalCtrl_bAcv_EngMes);
      if (bLocalCtrl_bAcv_EngMes != 0)
      {
         CKMNGIF_vidEngineRotDetection();
      }
   }
}
/*------------------------------- end of file --------------------------------*/