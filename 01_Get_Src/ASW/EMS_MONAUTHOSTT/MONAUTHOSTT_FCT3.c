/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MONAUTHOSTT                                             */
/* !Description     : MONAUTHOSTT Component                                   */
/*                                                                            */
/* !Module          : MONAUTHOSTT                                             */
/* !Description     : SAFETY TMS : STT Chaine de Traction                     */
/*                                                                            */
/* !File            : MONAUTHOSTT_FCT3.C                                      */
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
/*   1 / MONAUTHOSTT_vidCoordAutDemRedem                                      */
/*   2 / MONAUTHOSTT_vidCrdDemdAutDmRdmN1                                     */
/*   3 / MONAUTHOSTT_vidCompGenDefautSTT                                      */
/*   4 / MONAUTHOSTT_vidMergeSTTConfig                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5199597 / 01                                        */
/* !OtherRefs   : 01460_10_03769 / 1.3                                        */
/* !OtherRefs   : VEMS V02 ECU#047008                                         */
/* !OtherRefs   : VEMS V02 ECU#060257                                         */
/* !OtherRefs   : VEMS V02 ECU#065855                                         */
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
#include "MONAUTHOSTT.h"
#include "MONAUTHOSTT_L.h"
#include "MONAUTHOSTT_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidCoordAutDemRedem                            */
/* !Description :  Coordination dem / redem sécurisée                         */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean MONAUTHOSTT_bRStrtAuthSTTMerge;                             */
/*  input boolean SftyMgt_bStrtAuth;                                          */
/*  output boolean SftyMgt_bStrtRStrtAuth;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidCoordAutDemRedem(void)
{
   if (  (MONAUTHOSTT_bRStrtAuthSTTMerge != 0)
      || (SftyMgt_bStrtAuth != 0))
   {
      SftyMgt_bStrtRStrtAuth = 1;
   }
   else
   {
      SftyMgt_bStrtRStrtAuth = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidCrdDemdAutDmRdmN1                           */
/* !Description :  Coordination autorisation Dem / redem niveau applicatif    */
/*                 (CMM et SEEM)                                              */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bInhCoStrtRStrt;                                    */
/*  input boolean SftyMgt_bStaReq;                                            */
/*  output boolean SftyMgt_bStrtRStrtReqCord;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidCrdDemdAutDmRdmN1(void)
{
   boolean bLocalSftyMgt_bInhCoStrtRStrt;
   boolean bLocalSftyMgt_bStaReq;


   VEMS_vidGET(SftyMgt_bInhCoStrtRStrt, bLocalSftyMgt_bInhCoStrtRStrt);
   VEMS_vidGET(SftyMgt_bStaReq, bLocalSftyMgt_bStaReq);

   if (  (bLocalSftyMgt_bInhCoStrtRStrt != 0)
      && (bLocalSftyMgt_bStaReq == 0))
   {
      SftyMgt_bStrtRStrtReqCord = 0;
   }
   else
   {
      SftyMgt_bStrtRStrtReqCord = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidCompGenDefautSTT                            */
/* !Description :  Comparaison de la demande dem / redem sécurisée avec la    */
/*                 demande niveau applicatif, filtre anti-rebond et           */
/*                 calibration de la remontée du défaut.                      */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDftSTTDrvTra_C;                                 */
/*  input boolean SftyMgt_bStrtRStrtAuth;                                     */
/*  input boolean SftyMgt_bStrtRStrtReqCord;                                  */
/*  input uint8 SftyMgt_tiDlyOnDftSTT_C;                                      */
/*  input uint16 MONAUTHOSTT_u16Counter3;                                     */
/*  output uint16 MONAUTHOSTT_u16Counter3;                                    */
/*  output boolean SftyMgt_bDgoSTTDrvTra;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidCompGenDefautSTT(void)
{
   boolean bLocalActiveDelay;
   uint16  u16LocalMinTurnOnDelaySimple;
   uint16  u16LocalSumTurnOnDelaySimple;


   if (SftyMgt_bInhDftSTTDrvTra_C != 0)
   {
      bLocalActiveDelay = 0;
   }
   else
   {
      if (  (SftyMgt_bStrtRStrtAuth == 0)
         && (SftyMgt_bStrtRStrtReqCord != 0))
      {
         bLocalActiveDelay = 1;
      }
      else
      {
         bLocalActiveDelay = 0;
      }
   }

   /*Turn_On_Delay_Simple*/
   u16LocalSumTurnOnDelaySimple = (uint16)(SftyMgt_tiDlyOnDftSTT_C + 1);
   if (bLocalActiveDelay == 0)
   {
      MONAUTHOSTT_u16Counter3 = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple =
         (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16Counter3,
                                u16LocalSumTurnOnDelaySimple);
      MONAUTHOSTT_u16Counter3 = (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }
   if (MONAUTHOSTT_u16Counter3 >= u16LocalSumTurnOnDelaySimple)
   {
      SftyMgt_bDgoSTTDrvTra = 1;
   }
   else
   {
      SftyMgt_bDgoSTTDrvTra = 0;
   }
   /*fin Turn_On_Delay_Simple*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidMergeSTTConfig                              */
/* !Description :  Synthèse finale du défaut.                                 */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoDrvTraFRM;                                      */
/*  input boolean SftyMgt_bDgoSTTDrvTra;                                      */
/*  input boolean SftyMgt_bDgoDrvTraSfty;                                     */
/*  output boolean SftyMgt_bDftSTT;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidMergeSTTConfig(void)
{
   boolean bLocalSftyMgt_bDftSTT;


   if (  (SftyMgt_bDgoDrvTraFRM !=0)
      || (SftyMgt_bDgoSTTDrvTra != 0)
      || (SftyMgt_bDgoDrvTraSfty != 0))
   {
      bLocalSftyMgt_bDftSTT = 1;
   }
   else
   {
      bLocalSftyMgt_bDftSTT = 0;
   }
   VEMS_vidSET(SftyMgt_bDftSTT, bLocalSftyMgt_bDftSTT);
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/