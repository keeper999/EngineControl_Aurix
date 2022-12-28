/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYMGTIFTQ                                             */
/* !Description     : SFTYMGTIFTQ component.                                  */
/*                                                                            */
/* !Module          : SFTYMGTIFTQ                                             */
/* !Description     : SAFETY TMS: interface avec LDA/LDB de la structure      */
/*                    d'accueil                                               */
/*                                                                            */
/* !File            : SFTYMGTIFTQ_FCT4.C                                      */
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
/*   1 / SFTYMGTIFTQ_vidRstSw                                                 */
/*   2 / SFTYMGTIFTQ_vidInerface                                              */
/*   3 / SFTYMGTIFTQ_vidF329RxLvl2                                            */
/*   4 / SFTYMGTIFTQ_vidF329SftyLevel2                                        */
/*   5 / SFTYMGTIFTQ_vidF349RxLvl2                                            */
/*   6 / SFTYMGTIFTQ_vidF349SftyLevel2                                        */
/*   7 / SFTYMGTIFTQ_vidF34DSftyLevel2                                        */
/*   8 / SFTYMGTIFTQ_vidF38DRxLvl2                                            */
/*   9 / SFTYMGTIFTQ_vidF38DSftyLevel2                                        */
/*   10 / SFTYMGTIFTQ_vidEnabEngStopReq                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5147394 / 02                                        */
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
#include "SFTYMGTIFTQ.h"
#include "SFTYMGTIFTQ_L.h"
#include "SFTYMGTIFTQ_IM.h"
#include "OSEK_COM.h"
#include "MCWDG.h"
#include "RSTSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidRstSw                                       */
/* !Description :  Reset du soft                                              */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RSTSRV_vidPerformReset(argin RSTSRV_tudtResetType        */
/*  udtRequestedResetType);                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidRstSw(void)
{
   RSTSRV_vidPerformReset(RSTSRV_udtSOFTWARE_RESET);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidInerface                                    */
/* !Description :  Le booléen Sfty3_bRstEndRcvRun permet de forcer la variable*/
/*                 Sfty3_bEndRcvRun à 0.                                      */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SFTYMGTIFTQ_vidEnabEngStopReq();                         */
/*  input boolean SftyMgt_bRstEndRcvRun_C;                                    */
/*  input boolean EcuSt_bDetHotRst;                                           */
/*  input boolean Thr_bEndTestInh_CpuSfty;                                    */
/*  output boolean Sfty3_bEndRcvRun;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidInerface(void)
{
   boolean bLocalEcuSt_bDetHotRst;
   boolean bLocalEndTestInh_CpuSfty;


   if (SftyMgt_bRstEndRcvRun_C != 0)
   {
      VEMS_vidSET(Sfty3_bEndRcvRun, 0);
   }
   else
   {
      VEMS_vidGET(EcuSt_bDetHotRst, bLocalEcuSt_bDetHotRst);
      VEMS_vidSET(Sfty3_bEndRcvRun, bLocalEcuSt_bDetHotRst);
   }
   VEMS_vidGET(Thr_bEndTestInh_CpuSfty, bLocalEndTestInh_CpuSfty);
   if (bLocalEndTestInh_CpuSfty != 0)
   {
      SFTYMGTIFTQ_vidEnabEngStopReq();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidF329RxLvl2                                  */
/* !Description :  Ce bloc décrit la production du message et de la longueur  */
/*                 de la trame 329. Les 2 variables SftyMgt_F329MsgData et    */
/*                 SftyMgt_F329LocalLength sont utilisées pour vérifier le    */
/*                 Checksum de la trame                                       */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 SftyMgt_F329LocalLength;                                      */
/*  input uint8 SftyMgt_F329MsgData[8];                                       */
/*  output uint8 SftyMgt_F329LocalLength;                                     */
/*  output uint8 SftyMgt_F329MsgData[8];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidF329RxLvl2(void)
{
   uint8        au8LocalSftyMgt_F329MsgData[8];
   /*QAC Warnig : Msg(2:3132) --> no impact*/
   uint8        udtLocalAdress;
   uint8        u8LocalSftyMgt_F329LocalLength;
   Length       u16LocalSftyMgt_F329LocalLength;
   StatusType   udtLocalMessageStatus;
   /*QAC Warning : Msg(3:3203) --> the macro returns a value that is not used
   --> no impact*/

   VEMS_vidGET(SftyMgt_F329LocalLength, u16LocalSftyMgt_F329LocalLength);
   VEMS_vidGET1DArray(SftyMgt_F329MsgData,
                      8,
                      au8LocalSftyMgt_F329MsgData);
   /*QAC Warning : Msg(3:3198) --> the local variable is always set before
   being used --> no impact*/
   udtLocalMessageStatus = ReceiveMessageFrom(MESSAGE_RX_329,
                                              &au8LocalSftyMgt_F329MsgData[0],
                                              &u16LocalSftyMgt_F329LocalLength,
                                              &udtLocalAdress);
   u8LocalSftyMgt_F329LocalLength =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_F329LocalLength, 255);
   VEMS_vidSET(SftyMgt_F329LocalLength, u8LocalSftyMgt_F329LocalLength);
   VEMS_vidSET1DArray(SftyMgt_F329MsgData,
                      8,
                      au8LocalSftyMgt_F329MsgData);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidF329SftyLevel2                              */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes de la    */
/*                 Trame CAN 329.                                             */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftCks_F329;                                       */
/*  input boolean SftyMgt_bDftSftyPrcFaild_F329;                              */
/*  output boolean SftyMgt_bInpChkF329;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidF329SftyLevel2(void)
{
   boolean bLocalSftyMgt_bDftCks_F329;
   boolean bLocalDftSftyPrcFaildF329;
   boolean bLocalAcvTreatSftyLvl2FHCanF329;


   bLocalAcvTreatSftyLvl2FHCanF329 =
      GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2FHCANF329);

   VEMS_vidGET(SftyMgt_bDftCks_F329, bLocalSftyMgt_bDftCks_F329);
   VEMS_vidGET(SftyMgt_bDftSftyPrcFaild_F329, bLocalDftSftyPrcFaildF329);

   if (  (  (bLocalSftyMgt_bDftCks_F329 != 0)
         && (bLocalAcvTreatSftyLvl2FHCanF329 == 0))
      || (  (bLocalDftSftyPrcFaildF329 != 0)
         && (bLocalAcvTreatSftyLvl2FHCanF329 == 0)))
   {
      SftyMgt_bInpChkF329 = 1;
   }
   else
   {
      SftyMgt_bInpChkF329 = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidF349RxLvl2                                  */
/* !Description :  Ce bloc décrit la production du message et de la longueur  */
/*                 de la trame 349. Les 2 variables SftyMgt_F349MsgData et    */
/*                 SftyMgt_F349LocalLength sont utilisées pour vérifier le    */
/*                 Checksum de la trame                                       */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 SftyMgt_F349LocalLength;                                      */
/*  input uint8 SftyMgt_F349MsgData[8];                                       */
/*  output uint8 SftyMgt_F349LocalLength;                                     */
/*  output uint8 SftyMgt_F349MsgData[8];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidF349RxLvl2(void)
{
   uint8        au8LocalSftyMgt_F349MsgData[8];
   /*QAC Warnig : Msg(2:3132) --> no impact*/
   uint8        udtLocalAdress;
   uint8        u8LocalSftyMgt_F349LocalLength;
   Length       u16LocalSftyMgt_F349LocalLength;
   StatusType   udtLocalMessageStatus;
   /*QAC Warning : Msg(3:3203) --> the macro returns a value that is not used
   --> no impact*/

   VEMS_vidGET(SftyMgt_F349LocalLength, u8LocalSftyMgt_F349LocalLength);
   VEMS_vidGET1DArray(SftyMgt_F349MsgData,
                      8,
                      au8LocalSftyMgt_F349MsgData);
   /*QAC Warning : Msg(3:3198) --> the local variable is always set before
   being used --> no impact*/
   udtLocalMessageStatus = ReceiveMessageFrom(MESSAGE_RX_349,
                                              &au8LocalSftyMgt_F349MsgData[0],
                                              &u16LocalSftyMgt_F349LocalLength,
                                              &udtLocalAdress);
   u8LocalSftyMgt_F349LocalLength =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_F349LocalLength, 255);
   VEMS_vidSET(SftyMgt_F349LocalLength, u8LocalSftyMgt_F349LocalLength);
   VEMS_vidSET1DArray(SftyMgt_F349MsgData,
                      8,
                      au8LocalSftyMgt_F349MsgData);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidF349SftyLevel2                              */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes de la    */
/*                 Trame CAN 349.                                             */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftCks_F349;                                       */
/*  input boolean SftyMgt_bDftSftyPrcFaild_F349;                              */
/*  output boolean SftyMgt_bInpChkF349;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidF349SftyLevel2(void)
{
   boolean bLocalSftyMgt_bDftCks_F349;
   boolean bLocalDftSftyPrcFaild_F349;
   boolean bLocal_AcvTreatSftyLvl2FHCanF349;


   bLocal_AcvTreatSftyLvl2FHCanF349 =
      GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2FHCANF349);

   VEMS_vidGET(SftyMgt_bDftCks_F349, bLocalSftyMgt_bDftCks_F349);
   VEMS_vidGET(SftyMgt_bDftSftyPrcFaild_F349, bLocalDftSftyPrcFaild_F349);

   if (  (  (bLocalSftyMgt_bDftCks_F349 != 0)
         && (bLocal_AcvTreatSftyLvl2FHCanF349 == 0))
      || (  (bLocalDftSftyPrcFaild_F349 != 0)
         && (bLocal_AcvTreatSftyLvl2FHCanF349 == 0)))
   {
      SftyMgt_bInpChkF349 = 1;
   }
   else
   {
      SftyMgt_bInpChkF349 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidF34DSftyLevel2                              */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes de la    */
/*                 Trame CAN 34D.                                             */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  input boolean SftyMgt_bDftSftyTqCoh_F34D;                                 */
/*  input boolean SftyMgt_bDftSftyPrcFaild_F34D;                              */
/*  output boolean SftyMgt_bInpChkF34D;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidF34DSftyLevel2(void)
{
   boolean bLocalSftyMgt_bDftSftyTqCoh_F34D;
   boolean bLocal_AcvTreatSftyLvl2CanF34D;
   boolean bLocalDftSftyPrcFaild_F34D;


   VEMS_vidGET(SftyMgt_bDftSftyTqCoh_F34D, bLocalSftyMgt_bDftSftyTqCoh_F34D);
   VEMS_vidGET(SftyMgt_bDftSftyPrcFaild_F34D, bLocalDftSftyPrcFaild_F34D);
   bLocal_AcvTreatSftyLvl2CanF34D =
      GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2FHCANF34D);

   if (  (bLocal_AcvTreatSftyLvl2CanF34D == 0)
      && (  (bLocalSftyMgt_bDftSftyTqCoh_F34D != 0)
         || (bLocalDftSftyPrcFaild_F34D != 0)))
   {
      SftyMgt_bInpChkF34D = 1;
   }
   else
   {
      SftyMgt_bInpChkF34D = 0;
   }

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidF38DRxLvl2                                  */
/* !Description :  Ce bloc décrit la production du message et de la longueur  */
/*                 de la trame 38D. Les 2 variables SftyMgt_F38DMsgData et    */
/*                 SftyMgt_F38DLocalLength sont utilisées pour vérifier le    */
/*                 Checksum de la trame                                       */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 SftyMgt_F38DLocalLength;                                      */
/*  input uint8 SftyMgt_F38DMsgData[8];                                       */
/*  output uint8 SftyMgt_F38DLocalLength;                                     */
/*  output uint8 SftyMgt_F38DMsgData[8];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidF38DRxLvl2(void)
{
   uint8        au8LocalSftyMgt_F38DMsgData[8];
   /*QAC Warnig : Msg(2:3132) --> no impact*/
   uint8        udtLocalAdress;
   uint8        u8LocalSftyMgt_F38DLocalLength;
   Length       u16LocalSftyMgt_F38DLocalLength;
   StatusType   udtLocalMessageStatus;
   /*QAC Warning : Msg(3:3203) --> the macro returns a value that is not used
   --> no impact*/

   VEMS_vidGET(SftyMgt_F38DLocalLength, u8LocalSftyMgt_F38DLocalLength);
   VEMS_vidGET1DArray(SftyMgt_F38DMsgData,
                      8,
                      au8LocalSftyMgt_F38DMsgData);
   /*QAC Warning : Msg(3:3198) --> the local variable is always set before
   being used --> no impact*/
   udtLocalMessageStatus = ReceiveMessageFrom(MESSAGE_RX_38D,
                                              &au8LocalSftyMgt_F38DMsgData[0],
                                              &u16LocalSftyMgt_F38DLocalLength,
                                              &udtLocalAdress);
   u8LocalSftyMgt_F38DLocalLength =
      (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_F38DLocalLength, 255);
   VEMS_vidSET(SftyMgt_F38DLocalLength, u8LocalSftyMgt_F38DLocalLength);
   VEMS_vidSET1DArray(SftyMgt_F38DMsgData,
                      8,
                      au8LocalSftyMgt_F38DMsgData);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidF38DSftyLevel2                              */
/* !Description :  Ce block produit le résultat des diagnostics safety level 2*/
/*                 réalisés sur les entrées sécuritaires provenantes de la    */
/*                 Trame CAN 38D.                                             */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bDftCks_F38D;                                       */
/*  input boolean SftyMgt_bDftSftyPrcFaild_F38D;                              */
/*  output boolean SftyMgt_bInpChkF38D;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidF38DSftyLevel2(void)
{
   boolean bLocalSftyMgt_bDftCks_F38D;
   boolean bLocalDftSftyPrcFaild_F38D;
   boolean bLocal_AcvTreatSftyLvl2FHCanF38D;


   bLocal_AcvTreatSftyLvl2FHCanF38D =
      GDGAR_bGetFRM(FRM_FRM_ACVTREATSFTYLVL2FHCANF38D);

   VEMS_vidGET(SftyMgt_bDftCks_F38D, bLocalSftyMgt_bDftCks_F38D);
   VEMS_vidGET(SftyMgt_bDftSftyPrcFaild_F38D, bLocalDftSftyPrcFaild_F38D);

   if (  (  (bLocalSftyMgt_bDftCks_F38D != 0)
         && (bLocal_AcvTreatSftyLvl2FHCanF38D == 0))
      || (  (bLocalDftSftyPrcFaild_F38D != 0)
         && (bLocal_AcvTreatSftyLvl2FHCanF38D == 0)))
   {
      SftyMgt_bInpChkF38D = 1;
   }
   else
   {
      SftyMgt_bInpChkF38D = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMGTIFTQ_vidEnabEngStopReq                              */
/* !Description :  DEMANDE D'ARRET MOTEUR SFTY NIVEAU 3                       */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret boolean  MCWDG_bReadInhibitState(argin uint8 u8McwInhPin);    */
/*  input boolean SftyMgt_bInhEngStopReq_C;                                   */
/*  output boolean Sfty3_bEngStopReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMGTIFTQ_vidEnabEngStopReq(void)
{
   boolean bLocalInhibitState;


   if (SftyMgt_bInhEngStopReq_C != 0)
   {
      VEMS_vidSET(Sfty3_bEngStopReq, 0);
   }
   else
   {
      bLocalInhibitState = MCWDG_bReadInhibitState(MCWDG_u8MCW_INHIBITION_OUT2);
      if (bLocalInhibitState == MCWDG_bMCW_INHIBIT_ACTIVE)
      {
         VEMS_vidSET(Sfty3_bEngStopReq, 1);
      }
      else
      {
         VEMS_vidSET(Sfty3_bEngStopReq, 0);
      }
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/