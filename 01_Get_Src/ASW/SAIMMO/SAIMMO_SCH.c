/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SAIMMO                                                  */
/* !Description     : SAIMMO Component                                        */
/*                                                                            */
/* !Module          : SAIMMO                                                  */
/* !Description     : Structure d'accueil pour le module IMMO                 */
/*                                                                            */
/* !File            : SAIMMO_SCH.C                                            */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / SAIMMO_EveRst                                                        */
/*   2 / SAIMMO_SdlMid                                                        */
/*   3 / SAIMMO_vidSdlFast                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5060905 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SAIMMO/SAIMMO_SCH.c_v           $*/
/* $Revision::   1.7      $$Author::   etsasson       $$Date::   06 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "saimmo_im.h"
#include "saimmo.h"
#include "saimmo_l.h"
#include "VEMS.H"
#include "DEVHAL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_EveRst                                              */
/* !Description :  Function called on reset. It calls IMMO's function (if     */
/*                 necessary) and intializes the internal SAIMMO data.        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SAIMMO_bActived;                                           */
/*  output uint8 SAIMMO_u8CptObjCode;                                         */
/*  output uint8 SAIMMO_u8CptObjEtat;                                         */
/*  output uint8 SAIMMO_u8TypeContinuFrame;                                   */
/*  output uint16 IMMO_stEcuLockStTyp;                                        */
/*  output uint8 IMMO_stEcuPairOffStTyp;                                      */
/*  output uint8 SAIMMO_IscanBufferPos1;                                      */
/*  output uint8 SAIMMO_IscanBufferPos2;                                      */
/*  output uint8 SAIMMO_IscanBufferPos3;                                      */
/*  output uint8 SAIMMO_IscanBufferPos4;                                      */
/*  output uint8 SAIMMO_IscanBufferPos5;                                      */
/*  output boolean SAIMMO_bTmpSwitchMode_prev;                                */
/*  output boolean Immo_bEngStopReq;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SAIMMO_EveRst                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_EveRst(void)
{
   /* Reset of internal data */
   SAIMMO_bActived = 0;
   SAIMMO_u8CptObjCode = SAIMMO_u8NVMSRV_NOT_TESTED;
   SAIMMO_u8CptObjEtat = SAIMMO_u8NVMSRV_NOT_TESTED;
   SAIMMO_u8TypeContinuFrame = SAIMMO_CAN_FRAME_STOP;
   VEMS_vidSET(IMMO_stEcuLockStTyp, IMMO_ECU_LOCKED);
   VEMS_vidSET(IMMO_stEcuPairOffStTyp, IMMO_ECU_VIRGIN);
   VEMS_vidSET(SAIMMO_IscanBufferPos1, 0);
   VEMS_vidSET(SAIMMO_IscanBufferPos2, 0);
   VEMS_vidSET(SAIMMO_IscanBufferPos3, 0);
   VEMS_vidSET(SAIMMO_IscanBufferPos4, 0);
   VEMS_vidSET(SAIMMO_IscanBufferPos5, 0);
   SAIMMO_bTmpSwitchMode_prev = 0;
   VEMS_vidSET(Immo_bEngStopReq, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_SdlMid                                              */
/* !Description :  Call on event "sdlMid". It sequences the IMMO tasks at the */
/*                 Sdl_Mid recurence.                                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Immo_100ms();                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Immo_Init();                                             */
/*  extf argret boolean  DEVHAL_bCheckEmulCard();                             */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/* argin boolean bMode);                                                      */
/*  input boolean SAIMMO_bActived;                                            */
/*  input boolean Ext_bUnlockReq;                                             */
/*  input boolean SAIMMO_bTmpSwitchMode;                                      */
/*  input boolean SAIMMO_bTmpSwitchMode_prev;                                 */
/*  output boolean SAIMMO_bActived;                                           */
/*  output Struct_ObjCode_NVM SAIMMO_ObjCode;                                 */
/*  output Struct_ObjEtat_NVM SAIMMO_ObjEtat;                                 */
/*  output boolean SAIMMO_bTmpSwitchMode_prev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SAIMMO_SdlMid                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_SdlMid(void)
{
   boolean bLocalUnlockReq;
   boolean bLocalCheckEmulCard;

   /* if the module is not activated, we launch the IMMO initialization and
      set Activation data to TRUE. Otherwise we launch the periodical
      function.
      */
   if (SAIMMO_bActived != FALSE)
   {
      Immo_100ms();
   }
   else
   {  /* Modification faite car nous lancions l'init alors que bUnlockreq
         valait "0" et l'immo s'initialisait mal. Une issue pour l'analyse du
         problème est en cours : VEMS V02 ECU#043061 */
      VEMS_vidGET(Ext_bUnlockReq, bLocalUnlockReq);
      if (bLocalUnlockReq != 0)
      {
         Immo_Init();
         SAIMMO_bActived = TRUE;
      }
   }

   bLocalCheckEmulCard = DEVHAL_bCheckEmulCard();

   if ( (SAIMMO_bTmpSwitchMode!=0)
   && (SAIMMO_bTmpSwitchMode_prev==0)
   && (bLocalCheckEmulCard!=0) )
   {
      SAIMMO_ObjCode.AdcCode = 0x11111111;
      SAIMMO_ObjCode.AdcTyp = 0xFF;
      SAIMMO_ObjEtat.EcuPairOffSt = SAIMMO_ETAT_PROG_ETUDE;

      NVMSRV_vidWrite(NVMSRV_udtOBJ_SAIMMO_CODE, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_SAIMMO_ETAT, NVMSRV_bSAVE_NOW);
   }
   SAIMMO_bTmpSwitchMode_prev = SAIMMO_bTmpSwitchMode;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_vidSdlFast                                          */
/* !Description :  Call on event "sdlFast". It sequences the IMMO tasks at the*/
/*                 Sdl_fast recurence.                                        */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SAIMMO_vidChkWrEep();                                    */
/*  extf argret void SAIMMO_vidUpdateSaimmoExit();                            */
/*  extf argret void SAIMMO_vidSendCAN();                                     */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean SAIMMO_bActived;                                            */
/*  output boolean Immo_bEngStopReq;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SAIMMO_EveRst                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_vidSdlFast(void)
{
   uint8   u8LocalCoPTStEng;
   boolean bLocalEngStopReq;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTStEng);
   if (u8LocalCoPTStEng != 6)
   {
      bLocalEngStopReq = 0;
   }
   else
   {
      bLocalEngStopReq = 1;
   }
   VEMS_vidSET(Immo_bEngStopReq, bLocalEngStopReq);

   SAIMMO_vidChkWrEep();

   if (SAIMMO_bActived != FALSE)
   {
      SAIMMO_vidUpdateSaimmoExit();
   }

   SAIMMO_vidSendCAN();
}

/*-------------------------------- end of file -------------------------------*/