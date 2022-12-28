/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGSFTYLVL2                                            */
/* !Description     : DIAGSFTYLVL2 Component.                                 */
/*                                                                            */
/* !Module          : DIAGSFTYLVL2                                            */
/* !Description     : SAFETY TMS: Diagnostics des capteurs/Trames CAN pour le */
/*                    safety niveau 2.                                        */
/*                                                                            */
/* !File            : DIAGSFTYLVL2_SCH.C                                      */
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
/*   1 / SftyMgt_EveRst_DiagSftyLvl2                                          */
/*   2 / SftyMgt_SdlMid_DiagSftyLvl2                                          */
/*   3 / SftyMgt_EveRxn329_DiagSftyLvl2                                       */
/*   4 / SftyMgt_EveRxn349_DiagSftyLvl2                                       */
/*   5 / SftyMgt_EveRxn34D_DiagSftyLvl2                                       */
/*   6 / SftyMgt_EveRxn38D_DiagSftyLvl2                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5147426 / 04                                        */
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
#include "DIAGSFTYLVL2.h"
#include "DIAGSFTYLVL2_L.h"
#include "DIAGSFTYLVL2_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRst_DiagSftyLvl2                                */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGSFTYLVL2_vidInitOutput();                            */
/*  extf argret void DIAGSFTYLVL2_vidInit();                                  */
/*  extf argret void DIAGSFTYLVL2_vidF329SftyLevel2();                        */
/*  extf argret void DIAGSFTYLVL2_vidF349SftyLevel2();                        */
/*  extf argret void DIAGSFTYLVL2_vidF34DSftyLevel2();                        */
/*  extf argret void DIAGSFTYLVL2_vidF38DSftyLevel2();                        */
/*  extf argret void DIAGSFTYLVL2_vidSensDiagSftyLvl2();                      */
/*  input boolean SftyMgt_bAcvDiagCanSftyLvl2;                                */
/*  input boolean Diag_on;                                                    */
/*  input boolean Ext_bAcv_F329SftyLvl2_C;                                    */
/*  input boolean Ext_bAcv_F349SftyLvl2_C;                                    */
/*  input boolean Ext_bAcv_F34DSftyLvl2_C;                                    */
/*  input boolean Ext_bAcv_F38DSftyLvl2_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRst_DiagSftyLvl2                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRst_DiagSftyLvl2(void)
{
   boolean bLocalSftyMgt_AcvDiagCanSftyLvl2;
   boolean bLocalDiag_on;


   VEMS_vidGET(SftyMgt_bAcvDiagCanSftyLvl2, bLocalSftyMgt_AcvDiagCanSftyLvl2);
   VEMS_vidGET(Diag_on, bLocalDiag_on);

   DIAGSFTYLVL2_vidInitOutput();

   /*F03_Init*/
   DIAGSFTYLVL2_vidInit();

   /*F01_F329SftyLevel2*/
   if (  (Ext_bAcv_F329SftyLvl2_C != 0)
      && (bLocalSftyMgt_AcvDiagCanSftyLvl2 != 0))
   {
      DIAGSFTYLVL2_vidF329SftyLevel2();
   }

   /*F02_F349SftyLevel2*/
   if (  (Ext_bAcv_F349SftyLvl2_C != 0)
      && (bLocalSftyMgt_AcvDiagCanSftyLvl2 != 0))
   {
      DIAGSFTYLVL2_vidF349SftyLevel2();
   }

   /*F03_F34DSftyLevel2*/
   if (  (Ext_bAcv_F34DSftyLvl2_C != 0)
      && (bLocalSftyMgt_AcvDiagCanSftyLvl2 != 0)
      && (bLocalDiag_on != 0))
   {
      DIAGSFTYLVL2_vidF34DSftyLevel2();
   }

   /*F04_F38DSftyLevel2*/
   if (  (Ext_bAcv_F38DSftyLvl2_C != 0)
      && (bLocalSftyMgt_AcvDiagCanSftyLvl2 != 0))
   {
      DIAGSFTYLVL2_vidF38DSftyLevel2();
   }

   /*F02_SensDiagSftyLvl2*/
   DIAGSFTYLVL2_vidSensDiagSftyLvl2();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_DiagSftyLvl2                                */
/* !Description :  Moniteur moyen de la fonction                              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidSensDiagSftyLvl2();                      */
/*  extf argret void DIAGSFTYLVL2_vidActDiagCanSftyL2();                      */
/*  input uint8 DIAGSFTYLVL2_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_DiagSftyLvl2                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_DiagSftyLvl2(void)
{
   /*F02_SensDiagSftyLvl2*/
   if (DIAGSFTYLVL2_u8Inhib != 0x5A)
   {
      DIAGSFTYLVL2_vidSensDiagSftyLvl2();
      DIAGSFTYLVL2_vidActDiagCanSftyL2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRxn329_DiagSftyLvl2                             */
/* !Description :  Evénement de réception de la trame 329h                    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGSFTYLVL2_vidF329SftyLevel2();                        */
/*  input boolean SftyMgt_bAcvDiagCanSftyLvl2;                                */
/*  input uint8 DIAGSFTYLVL2_u8Inhib;                                         */
/*  input boolean Ext_bAcv_F329SftyLvl2_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRxn329_DiagSftyLvl2                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRxn329_DiagSftyLvl2(void)
{
   boolean bLocalSftyMgt_AcvDiagCanSftyLvl2;


   VEMS_vidGET(SftyMgt_bAcvDiagCanSftyLvl2, bLocalSftyMgt_AcvDiagCanSftyLvl2);

   /*F01_F329SftyLevel2*/
   if (  (DIAGSFTYLVL2_u8Inhib != 0x5A)
      && (Ext_bAcv_F329SftyLvl2_C != 0)
      && (bLocalSftyMgt_AcvDiagCanSftyLvl2 != 0))
   {
      DIAGSFTYLVL2_vidF329SftyLevel2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRxn349_DiagSftyLvl2                             */
/* !Description :  Evenement de reception de la trame 349h                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGSFTYLVL2_vidF349SftyLevel2();                        */
/*  input boolean SftyMgt_bAcvDiagCanSftyLvl2;                                */
/*  input uint8 DIAGSFTYLVL2_u8Inhib;                                         */
/*  input boolean Ext_bAcv_F349SftyLvl2_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRxn349_DiagSftyLvl2                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRxn349_DiagSftyLvl2(void)
{
   boolean bLocalSftyMgt_AcvDiagCanSftyLvl2;


   VEMS_vidGET(SftyMgt_bAcvDiagCanSftyLvl2, bLocalSftyMgt_AcvDiagCanSftyLvl2);

   /*F02_F349SftyLevel2*/
   if (  (DIAGSFTYLVL2_u8Inhib != 0x5A)
      && (Ext_bAcv_F349SftyLvl2_C != 0)
      && (bLocalSftyMgt_AcvDiagCanSftyLvl2 != 0))
   {
      DIAGSFTYLVL2_vidF349SftyLevel2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRxn34D_DiagSftyLvl2                             */
/* !Description :  Evénement de réception de trame 34Dh                       */
/* !Number      :  SCH.5                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGSFTYLVL2_vidF34DSftyLevel2();                        */
/*  input boolean SftyMgt_bAcvDiagCanSftyLvl2;                                */
/*  input boolean Diag_on;                                                    */
/*  input uint8 DIAGSFTYLVL2_u8Inhib;                                         */
/*  input boolean Ext_bAcv_F34DSftyLvl2_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRxn34D_DiagSftyLvl2                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRxn34D_DiagSftyLvl2(void)
{
   boolean bLocalSftyMgt_AcvDiagCanSftyLvl2;
   boolean bLocalDiag_on;


   VEMS_vidGET(SftyMgt_bAcvDiagCanSftyLvl2, bLocalSftyMgt_AcvDiagCanSftyLvl2);
   VEMS_vidGET(Diag_on, bLocalDiag_on);


   /*F03_F34DSftyLevel2*/
   if (  (DIAGSFTYLVL2_u8Inhib != 0x5A)
      && (Ext_bAcv_F34DSftyLvl2_C != 0)
      && (bLocalSftyMgt_AcvDiagCanSftyLvl2 != 0)
      && (bLocalDiag_on != 0))
   {
      DIAGSFTYLVL2_vidF34DSftyLevel2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRxn38D_DiagSftyLvl2                             */
/* !Description :  Evénement de réception de la trame 38Dh                    */
/* !Number      :  SCH.6                                                      */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGSFTYLVL2_vidF38DSftyLevel2();                        */
/*  input boolean SftyMgt_bAcvDiagCanSftyLvl2;                                */
/*  input uint8 DIAGSFTYLVL2_u8Inhib;                                         */
/*  input boolean Ext_bAcv_F38DSftyLvl2_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRxn38D_DiagSftyLvl2                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRxn38D_DiagSftyLvl2(void)
{
   boolean bLocalSftyMgt_AcvDiagCanSftyLvl2;


   VEMS_vidGET(SftyMgt_bAcvDiagCanSftyLvl2, bLocalSftyMgt_AcvDiagCanSftyLvl2);
   /*F04_F38DSftyLevel2*/
   if (  (DIAGSFTYLVL2_u8Inhib != 0x5A)
      && (Ext_bAcv_F38DSftyLvl2_C != 0)
      && (bLocalSftyMgt_AcvDiagCanSftyLvl2 != 0))
   {
      DIAGSFTYLVL2_vidF38DSftyLevel2();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/