/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : DCM_MANU_Reset.c                                        */
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
/*   1 / DCM_MANU_ResetInit                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DCM$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_ResetInit                                         */
/* !Description :  Intialisation de la variable lié à la requête de reset     */
/* !Number      :  Reset.1                                                    */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Afts_stSpcFactSTTReq_eep;                                     */
/*  input boolean Afts_bInhIniRunReq_eep;                                     */
/*  input boolean Afts_bInhStSoCBatt_eep;                                     */
/*  output boolean Srv_bRstSw_DiagSrv;                                        */
/*  output uint8 DCM_MANU_PFuCtl_agWdPmpCmdReq;                               */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output boolean DCM_MANU_bSaEnable;                                        */
/*  output uint8 DCM_MANU_Data_DADAPT[33];                                    */
/*  output uint8 Srv_ctActrTstHpPmp;                                          */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*  output uint16 Srv_tiRcSttEnd;                                             */
/*  output boolean Afts_bRstMemCoReqRStrt;                                    */
/*  output boolean Srv_bInhThr;                                               */
/*  output boolean Afts_bLrnRstReq_rOfsSoC;                                   */
/*  output boolean Afts_bRstReqStcBatt;                                       */
/*  output boolean Afts_bLrnRstReq_uEmPredRstrt;                              */
/*  output boolean Afts_bLrnRstReq_iElNwStop;                                 */
/*  output boolean Afts_bRstReq_ctStaAcv;                                     */
/*  output boolean Afts_bRstCntDiagCluP;                                      */
/*  output boolean Srv_bInhSftyLvl2;                                          */
/*  output boolean Srv_bInhBoostGDI;                                          */
/*  output uint32 DCM_MANU_Code_Antidemarrage;                                */
/*  output uint8 DCM_MANU_Option_Appairage;                                   */
/*  output uint8 Afts_stSpcFactSTTReq;                                        */
/*  output uint8 Afts_stSpcFactSTTReq_eep;                                    */
/*  output boolean Afts_bInhIniRunReq;                                        */
/*  output boolean Afts_bInhIniRunReq_eep;                                    */
/*  output boolean Afts_bInhStSoCBatt;                                        */
/*  output boolean Afts_bInhStSoCBatt_eep;                                    */
/*  output boolean DCM_MANU_Srv_bInhBoostGDI_prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_ResetInit(void)
{
   uint8 u8LocalIndex;

   VEMS_vidSET(Srv_bRstSw_DiagSrv, FALSE);
   DCM_MANU_PFuCtl_agWdPmpCmdReq = 0;
   DCM_MANU_ErrorCode = 0;
   DCM_MANU_bEnaNack = FALSE;
   DCM_MANU_bSaEnable = FALSE;

   for(u8LocalIndex = 0; u8LocalIndex < 33; u8LocalIndex++)
   {
      DCM_MANU_Data_DADAPT[u8LocalIndex] = 0;
   }

   Srv_ctActrTstHpPmp = 0;
   Srv_tiRcRstEnd = 0;
   Srv_tiRcSttEnd = 0;
   VEMS_vidSET(Afts_bRstMemCoReqRStrt, FALSE);
   VEMS_vidSET(Srv_bInhThr, FALSE);
   VEMS_vidSET(Afts_bLrnRstReq_rOfsSoC, FALSE);
   VEMS_vidSET(Afts_bRstReqStcBatt, FALSE);
   VEMS_vidSET(Afts_bLrnRstReq_uEmPredRstrt, FALSE);
   VEMS_vidSET(Afts_bLrnRstReq_iElNwStop, FALSE);
   VEMS_vidSET(Afts_bRstReq_ctStaAcv, FALSE);
   VEMS_vidSET(Afts_bRstCntDiagCluP, FALSE);
   VEMS_vidSET(Srv_bInhSftyLvl2, FALSE);
   VEMS_vidSET(Srv_bInhBoostGDI, FALSE);
   VEMS_vidSET(DCM_MANU_Code_Antidemarrage, 0);
   VEMS_vidSET(DCM_MANU_Option_Appairage, 0);

   VEMS_vidSET(Afts_stSpcFactSTTReq, Afts_stSpcFactSTTReq_eep);
   VEMS_vidSET(Afts_bInhIniRunReq, Afts_bInhIniRunReq_eep);
   VEMS_vidSET(Afts_bInhStSoCBatt, Afts_bInhStSoCBatt_eep);

   DCM_MANU_Srv_bInhBoostGDI_prev = FALSE;
}