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
/* !File            : SAIMMO_FCT2.C                                           */
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
/*   1 / SAIMMO_EveRxn0E0                                                     */
/*   2 / SAIMMO_EveRxn0A8                                                     */
/*   3 / Ext_sendBLockECUCANImmo                                              */
/*   4 / Ext_sendNoSeedImmo                                                   */
/*   5 / SAIMMO_vidCallIsCanTx                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5060905 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SAIMMO/SAIMMO_FCT2.c_v          $*/
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

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_EveRxn0E0                                           */
/* !Description :  Function called by the ISCAN on the frame 0E0 reception.   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Immo_KeyMgt(argin uint32 Ext_noKeyCtlUnit, argin uint8   */
/* Ext_noRcvSrvTypImmo);                                                      */
/*  input Struct_ObjCode_NVM SAIMMO_ObjCode;                                  */
/*  input uint8 ISCAN_u8F0E0Pos2;                                             */
/*  input uint8 ISCAN_u8F0E0Pos3;                                             */
/*  input uint8 ISCAN_u8F0E0Pos4;                                             */
/*  input uint8 ISCAN_u8F0E0Pos5;                                             */
/*  input uint8 ISCAN_u8F0E0Pos1;                                             */
/*  output boolean SAIMMO_bUnlockAutho;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_EveRxn0E0(void)
{
   uint32 u32LocalClefUCH;          /* UCC or UCH key                         */
   uint32 u32LocalworkingData;      /* working data                           */
   uint8  u8LocalISCAN_u8F0E0Pos1;
   uint8  u8LocalISCAN_u8F0E0Pos2;
   uint8  u8LocalISCAN_u8F0E0Pos3;
   uint8  u8LocalISCAN_u8F0E0Pos4;
   uint8  u8LocalISCAN_u8F0E0Pos5;


   if((SAIMMO_ObjCode.AdcTyp == SAIMMO_ADC_CAN_CLIENT_AUTO)
    ||(SAIMMO_ObjCode.AdcTyp == SAIMMO_ADC_CAN_CLIENT_MANUEL))
   {
      /* build of u32LocalClefUCH */
      VEMS_vidGET(ISCAN_u8F0E0Pos2, u8LocalISCAN_u8F0E0Pos2);
      u32LocalClefUCH = u8LocalISCAN_u8F0E0Pos2;
      u32LocalClefUCH = (u32LocalClefUCH << 24);
      VEMS_vidGET(ISCAN_u8F0E0Pos3, u8LocalISCAN_u8F0E0Pos3);
      u32LocalworkingData = u8LocalISCAN_u8F0E0Pos3;
      u32LocalClefUCH = u32LocalClefUCH | (u32LocalworkingData << 16);
      VEMS_vidGET(ISCAN_u8F0E0Pos4, u8LocalISCAN_u8F0E0Pos4);
      u32LocalworkingData = u8LocalISCAN_u8F0E0Pos4;
      u32LocalClefUCH = u32LocalClefUCH | (u32LocalworkingData << 8);
      VEMS_vidGET(ISCAN_u8F0E0Pos5, u8LocalISCAN_u8F0E0Pos5);
      u32LocalworkingData = u8LocalISCAN_u8F0E0Pos5;
      u32LocalClefUCH = u32LocalClefUCH | (u32LocalworkingData);

      VEMS_vidGET(ISCAN_u8F0E0Pos1, u8LocalISCAN_u8F0E0Pos1);
      /* call IMMO function */
      Immo_KeyMgt(u32LocalClefUCH, u8LocalISCAN_u8F0E0Pos1);

      /* autorisation déverrouillage */
      if (u8LocalISCAN_u8F0E0Pos1 == 4)
      {
         SAIMMO_bUnlockAutho = 1;
      }
      else
      {
         SAIMMO_bUnlockAutho = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_EveRxn0A8                                           */
/* !Description :  Function called by the ISCAN on the frame 0A8 reception.   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Immo_KeyMgt(argin uint32 Ext_noKeyCtlUnit, argin uint8   */
/* Ext_noRcvSrvTypImmo);                                                      */
/*  input Struct_ObjCode_NVM SAIMMO_ObjCode;                                  */
/*  input uint8 ISCAN_u8F0A8Pos2;                                             */
/*  input uint8 ISCAN_u8F0A8Pos3;                                             */
/*  input uint8 ISCAN_u8F0A8Pos4;                                             */
/*  input uint8 ISCAN_u8F0A8Pos5;                                             */
/*  input uint8 ISCAN_u8F0A8Pos1;                                             */
/*  output boolean SAIMMO_bUnlockAutho;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_EveRxn0A8(void)
{
   uint32 u32LocalClefUCH;          /* UCC or UCH key                         */
   uint32 u32LocalworkingData;      /* working data                           */
   uint8  u8LocalISCAN_u8F0A8Pos1;
   uint8  u8LocalISCAN_u8F0A8Pos2;
   uint8  u8LocalISCAN_u8F0A8Pos3;
   uint8  u8LocalISCAN_u8F0A8Pos4;
   uint8  u8LocalISCAN_u8F0A8Pos5;

   if((SAIMMO_ObjCode.AdcTyp == SAIMMO_ADC_CAN_PSA_AUTO)
    ||(SAIMMO_ObjCode.AdcTyp == SAIMMO_ADC_CAN_PSA_MANUEL))
   {
      /* build of u32LocalClefUCH */
      VEMS_vidGET(ISCAN_u8F0A8Pos2, u8LocalISCAN_u8F0A8Pos2);
      u32LocalClefUCH = u8LocalISCAN_u8F0A8Pos2;
      u32LocalClefUCH = (u32LocalClefUCH << 24);
      VEMS_vidGET(ISCAN_u8F0A8Pos3, u8LocalISCAN_u8F0A8Pos3);
      u32LocalworkingData = u8LocalISCAN_u8F0A8Pos3;
      u32LocalClefUCH = u32LocalClefUCH | (u32LocalworkingData << 16);
      VEMS_vidGET(ISCAN_u8F0A8Pos4, u8LocalISCAN_u8F0A8Pos4);
      u32LocalworkingData = u8LocalISCAN_u8F0A8Pos4;
      u32LocalClefUCH = u32LocalClefUCH | (u32LocalworkingData << 8);
      VEMS_vidGET(ISCAN_u8F0A8Pos5, u8LocalISCAN_u8F0A8Pos5);
      u32LocalworkingData = u8LocalISCAN_u8F0A8Pos5;
      u32LocalClefUCH = u32LocalClefUCH | (u32LocalworkingData);

      VEMS_vidGET(ISCAN_u8F0A8Pos1, u8LocalISCAN_u8F0A8Pos1);
      /* call IMMO function */
      Immo_KeyMgt(u32LocalClefUCH, u8LocalISCAN_u8F0A8Pos1);

      /* autorisation déverrouillage */
      if (u8LocalISCAN_u8F0A8Pos1 == 4)
      {
         SAIMMO_bUnlockAutho = 1;
      }
      else
      {
         SAIMMO_bUnlockAutho = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_sendBLockECUCANImmo                                    */
/* !Description :  Request to send the ECU lock State on the CAN network.     */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SAIMMO_vidCallIsCanTx();                                 */
/*  input uint8 SAIMMO_u8TypeContinuFrame;                                    */
/*  output uint8 SAIMMO_IscanBufferPos1;                                      */
/*  output uint8 SAIMMO_IscanBufferPos2;                                      */
/*  output uint8 SAIMMO_IscanBufferPos3;                                      */
/*  output uint8 SAIMMO_IscanBufferPos4;                                      */
/*  output uint8 SAIMMO_IscanBufferPos5;                                      */
/*  output uint8 SAIMMO_u8TypeContinuFrame;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_sendBLockECUCANImmo
(
   boolean Immo_bLockECUCAN
)
{
   if ( (Immo_bLockECUCAN == 0x00) /* Etat déverrouillé */
      && (SAIMMO_u8TypeContinuFrame == SAIMMO_CAN_FRAME_SEND) )
   {
      /* Aucune action */
   }
   else
   {
      /* update sending buffer */
      VEMS_vidSET(SAIMMO_IscanBufferPos1, SAIMMO_CAN_FRAME_ECU_STATE);
      VEMS_vidSET(SAIMMO_IscanBufferPos2, Immo_bLockECUCAN);
      VEMS_vidSET(SAIMMO_IscanBufferPos3, 0);
      VEMS_vidSET(SAIMMO_IscanBufferPos4, 0);
      VEMS_vidSET(SAIMMO_IscanBufferPos5, 0);
      /* Stop all the automatique request */
      SAIMMO_u8TypeContinuFrame = SAIMMO_CAN_FRAME_STOP;

      SAIMMO_vidCallIsCanTx();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_sendNoSeedImmo                                         */
/* !Description :  Request to send the seed on the CAN Network. The type of   */
/*                 send could be : stop transmission, send one frame or send  */
/*                 periodical.                                                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SAIMMO_vidCallIsCanTx();                                 */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  output uint8 SAIMMO_IscanBufferPos1;                                      */
/*  output uint8 SAIMMO_IscanBufferPos2;                                      */
/*  output uint8 SAIMMO_IscanBufferPos3;                                      */
/*  output uint8 SAIMMO_IscanBufferPos4;                                      */
/*  output uint8 SAIMMO_IscanBufferPos5;                                      */
/*  output uint8 SAIMMO_u8TypeContinuFrame;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_sendNoSeedImmo
(
   uint32 Immo_noSeed,
   uint8 Immo_stCANEmiTyp
)
{
   uint8   u8LocalSAIMMO_IscanBufferPos1;
   uint8   u8LocalSAIMMO_IscanBufferPos2;
   uint8   u8LocalSAIMMO_IscanBufferPos3;
   uint8   u8LocalSAIMMO_IscanBufferPos4;
   uint8   u8LocalSAIMMO_IscanBufferPos5;

   switch (Immo_stCANEmiTyp)
   {
      case SAIMMO_CAN_STOP_SEND_FRAME:
         /* buffer reset for ISCAN */
         VEMS_vidSET(SAIMMO_IscanBufferPos1, 0);
         VEMS_vidSET(SAIMMO_IscanBufferPos2, 0);
         VEMS_vidSET(SAIMMO_IscanBufferPos3, 0);
         VEMS_vidSET(SAIMMO_IscanBufferPos4, 0);
         VEMS_vidSET(SAIMMO_IscanBufferPos5, 0);
         /* Stop all the automatique request, whatever its type */
         SAIMMO_u8TypeContinuFrame = SAIMMO_CAN_FRAME_STOP;
         break;

      case SAIMMO_CAN_SEND_ONE_FRAME:

         /* Mise à jour du buffer d'émission */
         u8LocalSAIMMO_IscanBufferPos1 = SAIMMO_CAN_FRAME_ASK_UNLOCK_AUTHO;
         VEMS_vidSET(SAIMMO_IscanBufferPos1, u8LocalSAIMMO_IscanBufferPos1);
         /* immoseed */
         u8LocalSAIMMO_IscanBufferPos2 =
                              ((uint8)((Immo_noSeed & 0xFF000000uL) >> 24));
         VEMS_vidSET(SAIMMO_IscanBufferPos2, u8LocalSAIMMO_IscanBufferPos2);
         u8LocalSAIMMO_IscanBufferPos3 =
                              ((uint8)((Immo_noSeed & 0x00FF0000) >> 16));
         VEMS_vidSET(SAIMMO_IscanBufferPos3, u8LocalSAIMMO_IscanBufferPos3);
         u8LocalSAIMMO_IscanBufferPos4 =
                              ((uint8)((Immo_noSeed & 0x0000FF00) >> 8));
         VEMS_vidSET(SAIMMO_IscanBufferPos4, u8LocalSAIMMO_IscanBufferPos4);
         u8LocalSAIMMO_IscanBufferPos5 = ((uint8)(Immo_noSeed & 0x000000FF));
         VEMS_vidSET(SAIMMO_IscanBufferPos5, u8LocalSAIMMO_IscanBufferPos5);
         /* Stop all the automatique request, whatever its type */
         SAIMMO_u8TypeContinuFrame = SAIMMO_CAN_FRAME_STOP;

         SAIMMO_vidCallIsCanTx();
         break;

      case SAIMMO_CAN_SEND_START:
         u8LocalSAIMMO_IscanBufferPos1 = SAIMMO_CAN_FRAME_ASK_UNLOCK_AUTHO;
         VEMS_vidSET(SAIMMO_IscanBufferPos1, u8LocalSAIMMO_IscanBufferPos1);
         /* immoseed */
         u8LocalSAIMMO_IscanBufferPos2 =
                              ((uint8)((Immo_noSeed & 0xFF000000uL) >> 24));
         VEMS_vidSET(SAIMMO_IscanBufferPos2, u8LocalSAIMMO_IscanBufferPos2);
         u8LocalSAIMMO_IscanBufferPos3 =
                              ((uint8)((Immo_noSeed & 0x00FF0000) >> 16));
         VEMS_vidSET(SAIMMO_IscanBufferPos3, u8LocalSAIMMO_IscanBufferPos3);
         u8LocalSAIMMO_IscanBufferPos4 =
                              ((uint8)((Immo_noSeed & 0x0000FF00) >> 8));
         VEMS_vidSET(SAIMMO_IscanBufferPos4, u8LocalSAIMMO_IscanBufferPos4);
         u8LocalSAIMMO_IscanBufferPos5 = ((uint8)(Immo_noSeed & 0x000000FF));
         VEMS_vidSET(SAIMMO_IscanBufferPos5, u8LocalSAIMMO_IscanBufferPos5);

         /* put the param to send periodically the request */
         SAIMMO_u8TypeContinuFrame = SAIMMO_CAN_FRAME_SEND;
         break;

      default:
         /* buffer reset for ISCAN */
         VEMS_vidSET(SAIMMO_IscanBufferPos1, 0);
         VEMS_vidSET(SAIMMO_IscanBufferPos2, 0);
         VEMS_vidSET(SAIMMO_IscanBufferPos3, 0);
         VEMS_vidSET(SAIMMO_IscanBufferPos4, 0);
         VEMS_vidSET(SAIMMO_IscanBufferPos5, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_vidCallIsCanTx                                      */
/* !Description :  Call the right function (client or PSA) to send data on    */
/*                 ISCAN.                                                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Can_EveSaimmo_TxFrame072();                              */
/*  extf argret void Can_EveSaimmo_TxFrame0E8();                              */
/*  input Struct_ObjCode_NVM SAIMMO_ObjCode;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_vidCallIsCanTx(void)
{
   if (  (SAIMMO_ObjCode.AdcTyp == SAIMMO_ADC_CAN_PSA_AUTO)
      || (SAIMMO_ObjCode.AdcTyp == SAIMMO_ADC_CAN_PSA_MANUEL))
   {
      Can_EveSaimmo_TxFrame072();
   }
   else
   {
      Can_EveSaimmo_TxFrame0E8();
   }
}

/*-------------------------------- end of file -------------------------------*/