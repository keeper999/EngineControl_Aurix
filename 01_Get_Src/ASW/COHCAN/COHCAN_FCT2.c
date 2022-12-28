/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COHCAN                                                  */
/* !Description     : COHCAN Component                                        */
/*                                                                            */
/* !Module          : COHCAN                                                  */
/* !Description     : COHERENCE CAN INFOS_EOBD_BSI                            */
/*                                                                            */
/* !File            : COHCAN_FCT2.C                                           */
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
/*   1 / COHCAN_vidDiagFuLvlDft                                               */
/*   2 / COHCAN_vidDiagStCluAC                                                */
/*   3 / COHCAN_vidWindowCluAC                                                */
/*   4 / COHCAN_vidDiagCluAC                                                  */
/*                                                                            */
/* !Reference   : V02 NT 12 00919 / 02                                        */
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

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "COHCAN.h"
#include "COHCAN_L.h"
#include "COHCAN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagFuLvlDft                                     */
/* !Description :  Cette sous fonction réalise le diagnostic fuel low         */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bFuLvlDft;                                              */
/*  output boolean Ext_bDgoStFuLvlDft;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagFuLvlDft(void)
{
   boolean bLocalExt_bFuLvlDft;


   VEMS_vidGET(Ext_bFuLvlDft, bLocalExt_bFuLvlDft);
   Ext_bDgoStFuLvlDft = bLocalExt_bFuLvlDft;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagStCluAC                                      */
/* !Description :  Cette fonction, appelée sur réception de la trame 50E,     */
/*                 spécifie les conditions d’activation ainsi que l’activation*/
/*                 elle-même, du diagnostic de cohérence.                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidWindowCluAC();                                 */
/*  extf argret void COHCAN_vidDiagCluAC();                                   */
/*  input boolean Ext_bMonRunCoh_stCluAC;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagStCluAC(void)
{
   COHCAN_vidWindowCluAC();
   if (Ext_bMonRunCoh_stCluAC != 0)
   {
      COHCAN_vidDiagCluAC();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidWindowCluAC                                      */
/* !Description :  Le moniteur de diagnostic de la Clim                       */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean UCE_bWkuMain;                                               */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  output boolean Ext_bMonRunCoh_stCluAC;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidWindowCluAC(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalInhDiag_stCluAC;
   uint8   u8LocalCoPTSt_stEng;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   bLocalInhDiag_stCluAC = GDGAR_bGetFRM(FRM_FRM_INHDIAG_STCLUAC);

   if (  (u8LocalCoPTSt_stEng == Engine_Running)
      && (bLocalUCE_bWkuMain != 0)
      && (bLocalInhDiag_stCluAC == 0))
   {
      Ext_bMonRunCoh_stCluAC = 1;
   }
   else
   {
      Ext_bMonRunCoh_stCluAC = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidDiagCluAC                                        */
/* !Description :  Cette sous fonction réalise le diagnostic de la Clim       */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean AC_bACClu;                                                  */
/*  input uint8 AC_pwrAC;                                                     */
/*  input boolean COHCAN_bAC_bACClu_prev;                                     */
/*  input boolean COHCAN_bTimerInit_prev;                                     */
/*  input uint8 Ext_tiACClu_C;                                                */
/*  input uint8 Ext_tiACClu;                                                  */
/*  input boolean COHCAN_bTimeOut;                                            */
/*  output uint8 Ext_tiACClu;                                                 */
/*  output boolean COHCAN_bTimeOut;                                           */
/*  output boolean COHCAN_bAC_bACClu_prev;                                    */
/*  output boolean COHCAN_bTimerInit_prev;                                    */
/*  output boolean Ext_bDgoCoh_stCluAC;                                       */
/*  output boolean Ext_bDgoCoh_stPwrAC;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidDiagCluAC(void)
{
   boolean bLocalAC_bACClu;
   boolean bLocalTimerInit;
   uint8   u8LocalAC_pwrAC;


   VEMS_vidGET(AC_bACClu, bLocalAC_bACClu);
   VEMS_vidGET(AC_pwrAC, u8LocalAC_pwrAC);

   if (  (bLocalAC_bACClu != 0)
      && (COHCAN_bAC_bACClu_prev == 0))
   {
      bLocalTimerInit = 1;
   }
   else
   {
      bLocalTimerInit = 0;
   }
   /*Timer*/
   if (  (COHCAN_bTimerInit_prev == 0)
      && (bLocalTimerInit != 0))
   {
      Ext_tiACClu = (uint8)MATHSRV_udtMIN(Ext_tiACClu_C, 200);
      if (Ext_tiACClu == 0)
      {
         COHCAN_bTimeOut = 1;
      }
      else
      {
         COHCAN_bTimeOut = 0;
      }
   }
   else
   {
      if (Ext_tiACClu > 0)
      {
         Ext_tiACClu = (uint8)(Ext_tiACClu - 1);
         if (Ext_tiACClu == 0)
         {
            COHCAN_bTimeOut = 1;
         }
         else
         {
            COHCAN_bTimeOut = 0;
         }
      }
   }

   COHCAN_bAC_bACClu_prev = bLocalAC_bACClu;
   COHCAN_bTimerInit_prev = bLocalTimerInit;
   /*BasculeRS*/
   if (bLocalAC_bACClu == 0)
   {
      if (u8LocalAC_pwrAC == 0)
      {
         Ext_bDgoCoh_stCluAC = 0;
         Ext_bDgoCoh_stPwrAC = 0;
      }
      else
      {
         Ext_bDgoCoh_stPwrAC = 1;
      }
   }
   else
   {
      if(u8LocalAC_pwrAC == 0)
      {
         if (COHCAN_bTimeOut != 0)
         {
            Ext_bDgoCoh_stCluAC = 1;
         }
      }
      else
      {
         Ext_bDgoCoh_stPwrAC = 0;
      }
   }
}
/*----------------------------------end of file-------------------------------*/