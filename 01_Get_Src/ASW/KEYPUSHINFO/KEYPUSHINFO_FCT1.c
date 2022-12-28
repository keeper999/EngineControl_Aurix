/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KEYPUSHINFO                                             */
/* !Description     : KEYPUSHINFO component.                                  */
/*                                                                            */
/* !Module          : KEYPUSHINFO                                             */
/* !Description     : BASIC SOFTWARE PROCESSING REQUIREMENTS FOR KEY PUSH     */
/*                    INFORMATION.                                            */
/*                                                                            */
/* !File            : KEYPUSHINFO_FCT1.C                                      */
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
/*   1 / KEYPUSHINFO_vidInitOutput                                            */
/*   2 / KEYPUSHINFO_vidInit                                                  */
/*   3 / KEYPUSHINFO_vidEventSelc                                             */
/*   4 / KEYPUSHINFO_vidKeyPushAcq                                            */
/*   5 / KEYPUSHINFO_vidKeyPushTreat                                          */
/*   6 / KEYPUSHINFO_vidKeyFunct                                              */
/*   7 / KEYPUSHINFO_vidPushFunct                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6543971 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/KEYPUSHINFO/KEYPUSHINFO_FCT1.C_v  $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KEYPUSHINFO.h"
#include "KEYPUSHINFO_L.h"
#include "KEYPUSHINFO_IM.h"
#include "DIOHAL.H"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KEYPUSHINFO_vidInitOutput                                  */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_ctSdlStp_C;                                               */
/*  output uint8 Ext_ctSdl;                                                   */
/*  output boolean Ext_bDemLineRaw;                                           */
/*  output boolean Ext_bKeyLine;                                              */
/*  output boolean Ext_bPushLine;                                             */
/*  output uint8 KEYPUSHINFO_u8AntiBounceCntKey;                              */
/*  output uint8 KEYPUSHINFO_u8AntiBounceCntPush;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KEYPUSHINFO_vidInitOutput(void)
{
   Ext_ctSdl = (uint8)MATHSRV_udtMIN(Ext_ctSdlStp_C, 2);
   VEMS_vidSET(Ext_bDemLineRaw, 0);
   Ext_bKeyLine = 0;
   Ext_bPushLine = 0;
   KEYPUSHINFO_u8AntiBounceCntKey = 0;
   KEYPUSHINFO_u8AntiBounceCntPush = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KEYPUSHINFO_vidInit                                        */
/* !Description :  Initialisation.                                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bDrvStrtReq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KEYPUSHINFO_vidInit(void)
{
   VEMS_vidSET(Ext_bDrvStrtReq, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KEYPUSHINFO_vidEventSelc                                   */
/* !Description :  Ce bloc permet de créer un événement de 10ms a partir d'un */
/*                 événement de 5 ms.                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KEYPUSHINFO_vidKeyPushAcq();                             */
/*  input uint8 Ext_ctSdl;                                                    */
/*  input uint8 Ext_ctSdlStp_C;                                               */
/*  output uint8 Ext_ctSdl;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KEYPUSHINFO_vidEventSelc(void)
{
   uint16 u16LocalExtCtSdl;


   if (Ext_ctSdl >= Ext_ctSdlStp_C)
   {
      Ext_ctSdl = 0;
      KEYPUSHINFO_vidKeyPushAcq();
   }
   else
   {
      u16LocalExtCtSdl = (uint16)(Ext_ctSdl + 1);
      Ext_ctSdl = (uint8)MATHSRV_udtMIN(u16LocalExtCtSdl, 2);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KEYPUSHINFO_vidKeyPushAcq                                  */
/* !Description :  Ce bloc décrit l'information Key/Push acquis de l'API.     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_11_02247_003.01                                     */
/*                 VEMS_R_11_02247_004.01                                     */
/*                 VEMS_R_11_02247_009.01                                     */
/*                 VEMS_R_11_02247_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KEYPUSHINFO_vidKeyPushTreat();                           */
/*  input boolean ECU_bWkuMain;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KEYPUSHINFO_vidKeyPushAcq(void)
{
   boolean bLocalECU_bWkuMain;


   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   if (bLocalECU_bWkuMain != 0)
   {
      KEYPUSHINFO_vidKeyPushTreat();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KEYPUSHINFO_vidKeyPushTreat                                */
/* !Description :  Ce bloc vérifie les conditions qui permettent la filtration*/
/*                 du signal acquis de l'API (Ext_bDemLineRaw).               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_11_02247_001.01                                     */
/*                 VEMS_R_11_02247_002.01                                     */
/*                 VEMS_R_11_02247_007.01                                     */
/*                 VEMS_R_11_02247_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void KEYPUSHINFO_vidKeyFunct();                               */
/*  extf argret void KEYPUSHINFO_vidPushFunct();                              */
/*  input boolean Cf_bKeyLine;                                                */
/*  input boolean Cf_bPushLine;                                               */
/*  input boolean Acquisition_keypush_tor;                                    */
/*  input boolean Ext_bInvDemLine_C;                                          */
/*  input boolean Ext_bKeyLine;                                               */
/*  input boolean Ext_bPushLine;                                              */
/*  output boolean Ext_bDemLineRaw;                                           */
/*  output boolean Ext_bDrvStrtReq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KEYPUSHINFO_vidKeyPushTreat(void)
{
   boolean bLocalAcquisition_keypush_tor;
   boolean bLocalCf_bKeyLine;
   boolean bLocalCf_bPushLine;


   VEMS_vidGET(Cf_bKeyLine, bLocalCf_bKeyLine);
   VEMS_vidGET(Cf_bPushLine, bLocalCf_bPushLine);
   VEMS_vidGET(Acquisition_keypush_tor, bLocalAcquisition_keypush_tor);
   if (Ext_bInvDemLine_C != 0)
   {
      bLocalAcquisition_keypush_tor = !bLocalAcquisition_keypush_tor;
      VEMS_vidSET(Ext_bDemLineRaw, bLocalAcquisition_keypush_tor);
   }
   else
   {
      VEMS_vidSET(Ext_bDemLineRaw, bLocalAcquisition_keypush_tor);
   }

   if (bLocalCf_bKeyLine != 0)
   {
      KEYPUSHINFO_vidKeyFunct();
   }
   if (bLocalCf_bPushLine != 0)
   {
      KEYPUSHINFO_vidPushFunct();
   }
   if (  (Ext_bKeyLine != 0)
      || (Ext_bPushLine != 0))
   {
      VEMS_vidSET(Ext_bDrvStrtReq, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bDrvStrtReq, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KEYPUSHINFO_vidKeyFunct                                    */
/* !Description :  Ce bloc décrit la filtration de l'information Key acquis de*/
/*                 l'API.                                                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_11_02247_005.01                                     */
/*                 VEMS_R_11_02247_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bDemLineRaw;                                            */
/*  input boolean Ext_bKeyLine;                                               */
/*  input uint8 Ext_numDebHighKeyLine_C;                                      */
/*  input uint8 Ext_numDebLowKeyLine_C;                                       */
/*  input uint8 KEYPUSHINFO_u8AntiBounceCntKey;                               */
/*  output uint8 KEYPUSHINFO_u8AntiBounceCntKey;                              */
/*  output boolean Ext_bKeyLine;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KEYPUSHINFO_vidKeyFunct(void)
{
   boolean bLocalExt_bDemLineRaw;
   uint8   u8LocalThreshold;
   uint16  u16LocalAntiBounceCntKey;


   VEMS_vidGET(Ext_bDemLineRaw, bLocalExt_bDemLineRaw);
   if (bLocalExt_bDemLineRaw != Ext_bKeyLine)
   {
      if (bLocalExt_bDemLineRaw != 0)
      {
         u8LocalThreshold = Ext_numDebHighKeyLine_C;
      }
      else
      {
         u8LocalThreshold = Ext_numDebLowKeyLine_C;
      }
      u16LocalAntiBounceCntKey = (uint16)(KEYPUSHINFO_u8AntiBounceCntKey + 1);
      KEYPUSHINFO_u8AntiBounceCntKey =
         (uint8)MATHSRV_udtMIN(u16LocalAntiBounceCntKey, 255);
      if (KEYPUSHINFO_u8AntiBounceCntKey >= u8LocalThreshold)
      {
         Ext_bKeyLine = bLocalExt_bDemLineRaw;
         KEYPUSHINFO_u8AntiBounceCntKey = 0;
      }
   }
   else
   {
      KEYPUSHINFO_u8AntiBounceCntKey = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KEYPUSHINFO_vidPushFunct                                   */
/* !Description :  Ce bloc décrit la filtration de l'information Push acquis  */
/*                 de l'API.                                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_11_02247_011.01                                     */
/*                 VEMS_R_11_02247_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bDemLineRaw;                                            */
/*  input boolean Ext_bPushLine;                                              */
/*  input uint8 Ext_numDebHighPushLine_C;                                     */
/*  input uint8 Ext_numDebLowPushLine_C;                                      */
/*  input uint8 KEYPUSHINFO_u8AntiBounceCntPush;                              */
/*  output uint8 KEYPUSHINFO_u8AntiBounceCntPush;                             */
/*  output boolean Ext_bPushLine;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KEYPUSHINFO_vidPushFunct(void)
{
   boolean bLocalExt_bDemLineRaw;
   uint8   u8LocalThreshold;
   uint16  u16LocalAntiBounceCntPush;


   VEMS_vidGET(Ext_bDemLineRaw, bLocalExt_bDemLineRaw);
   if (bLocalExt_bDemLineRaw != Ext_bPushLine)
   {
      if (bLocalExt_bDemLineRaw != 0)
      {
         u8LocalThreshold = Ext_numDebHighPushLine_C;
      }
      else
      {
         u8LocalThreshold = Ext_numDebLowPushLine_C;
      }
      u16LocalAntiBounceCntPush = (uint16)(KEYPUSHINFO_u8AntiBounceCntPush + 1);
      KEYPUSHINFO_u8AntiBounceCntPush =
         (uint8)MATHSRV_udtMIN(u16LocalAntiBounceCntPush, 255);
      if (KEYPUSHINFO_u8AntiBounceCntPush >= u8LocalThreshold)
      {
         Ext_bPushLine = bLocalExt_bDemLineRaw;
         KEYPUSHINFO_u8AntiBounceCntPush = 0;
      }
   }
   else
   {
      KEYPUSHINFO_u8AntiBounceCntPush = 0;
   }
}

/*------------------------------- end of file --------------------------------*/