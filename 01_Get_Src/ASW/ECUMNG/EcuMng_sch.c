/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ECUMNG                                                  */
/* !Description     : ECUMNG component                                        */
/*                                                                            */
/* !Module          : ECUMNG                                                  */
/* !Description     : ETAT ELECTRIQUE DU CALCULATEUR                          */
/*                                                                            */
/* !File            : ecumng_sch.c                                            */
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
/*   1 / EcuSt_EveRst_EcuMng                                                  */
/*   2 / EcuSt_SdlMid_EcuMng                                                  */
/*   3 / EcuSt_EvePtlWku_Wku                                                  */
/*   4 / EcuSt_EveKOn_EcuMng                                                  */
/*   5 / EcuSt_EveKOf_EcuMng                                                  */
/*   6 / EcuSt_EvePwrlEnd_EcuMng                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6642215 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ECUST/ECUMNG/EcuMng_sch.c_v     $*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   22 Jul 2014 $*/
/* $Author::   mbenfrad                               $$Date::   22 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "ECUMNG.h"
#include "ECUMNG_L.h"
#include "ECUMNG_IM.h"
#include "ECUMNG_I.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveRst_EcuMng                                        */
/* !Description :  Foonction d'accroche à l'event EcuSt_EveRst_EcuMng.        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_04100_001.01                                     */
/*                 VEMS_E_10_04100_002.01                                     */
/*                 VEMS_E_10_04100_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ECUMNG_vidEcuMng_Init();                                 */
/*  extf argret void ECUMNG_vidRcdStateSelection();                           */
/*  extf argret void ECUMNG_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveRst_EcuMng                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveRst_EcuMng(void)
{
   ECUMNG_vidEcuMng_Init();
   ECUMNG_vidRcdStateSelection();
   ECUMNG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_SdlMid_EcuMng                                        */
/* !Description :  Fonction d'accroche à l'event EcuSt_SdlMid_EcuMng          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_04100_001.01                                     */
/*                 VEMS_E_10_04100_002.01                                     */
/*                 VEMS_E_10_04100_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ECUMNG_vidSurveillance();                                */
/*  extf argret void ECUMNG_vidbisAcvDiagHotRst();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void ECUMNG_vidManager();                                     */
/*  extf argret void ECUMNG_vidFctPrinDegrad();                               */
/*  extf argret void ECUMNG_vidRcdStateSelection();                           */
/*  input uint8 ECUMNG_u8Inhib;                                               */
/*  input boolean EcuSt_bDgoHotRst;                                           */
/*  input boolean EcuSt_bMonRunHotRst;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_SdlMid_EcuMng                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_SdlMid_EcuMng(void)
{
   if (ECUMNG_u8Inhib != 0x5A)
   {
      /*EcuSt_SdlMid_EcuMng_1*/
      ECUMNG_vidSurveillance();
      /*EcuSt_SdlMid_EcuMng_1b*/
      ECUMNG_vidbisAcvDiagHotRst();
      /*EcuSt_SdlMid_EcuMng_1t*/
      GDGAR_vidGdu(GD_DFT_HOTRST,
                   EcuSt_bDgoHotRst,
                   EcuSt_bMonRunHotRst,
                   DIAG_DISPO);
      /*EcuSt_SdlMid_EcuMng_2*/
      ECUMNG_vidManager();
      /*EcuSt_SdlMid_EcuMng_3*/
      ECUMNG_vidFctPrinDegrad();
      /*EcuSt_SdlMid_EcuMng_4*/
      ECUMNG_vidRcdStateSelection();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EvePtlWku_Wku                                        */
/* !Description :  Focntion d'accroche à l'event EcuSt_EvePtlWku_Wku          */
/* !Number      :  SCH.3                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_04100_001.01                                     */
/*                 VEMS_E_10_04100_002.01                                     */
/*                 VEMS_E_10_04100_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ECUMNG_vidSurveillance();                                */
/*  input uint8 ECUMNG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EvePtlWku_Wku                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EvePtlWku_Wku(void)
{
   if (ECUMNG_u8Inhib != 0x5A)
   {
      ECUMNG_vidSurveillance();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveKOn_EcuMng                                        */
/* !Description :  Focntion d'accroche à l'event EcuSt_EveKOn_EcuMnG          */
/* !Number      :  SCH.4                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_04100_001.01                                     */
/*                 VEMS_E_10_04100_002.01                                     */
/*                 VEMS_E_10_04100_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ECUMNG_vidManagePowerOn();                               */
/*  extf argret void ECUMNG_vidManager();                                     */
/*  extf argret void ECUMNG_vidRcdStateSelection();                           */
/*  input uint8 ECUMNG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveKOn_EcuMng                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveKOn_EcuMng(void)
{
   if (ECUMNG_u8Inhib != 0x5A)
   {
      /*EcuSt_EveKOn_EcuMng_1*/
      ECUMNG_vidManagePowerOn();
      /*EcuSt_EveKOn_EcuMng_2*/
      ECUMNG_vidManager();
      /*EcuSt_EveKOn_EcuMng_3*/
      ECUMNG_vidRcdStateSelection();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveKOf_EcuMng                                        */
/* !Description :  Fonction d'accroche à l'event EcuSt_EveKOf_EcuMng          */
/* !Number      :  SCH.5                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_04100_001.01                                     */
/*                 VEMS_E_10_04100_002.01                                     */
/*                 VEMS_E_10_04100_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ECUMNG_vidManager();                                     */
/*  extf argret void ECUMNG_vidRcdStateSelection();                           */
/*  input uint8 ECUMNG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveKOf_EcuMng                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveKOf_EcuMng(void)
{
   if (ECUMNG_u8Inhib != 0x5A)
   {
      /*EcuSt_EveKOf_EcuMng_1*/
      ECUMNG_vidManager();
      /*EcuSt_EveKOf_EcuMng_2*/
      ECUMNG_vidRcdStateSelection();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EvePwrlEnd_EcuMng                                    */
/* !Description :  Evénement d'entrée dans la tâche d’écriture en EEPROM en   */
/*                 fin de powerlatch                                          */
/* !Number      :  SCH.6                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_04100_001.01                                     */
/*                 VEMS_E_10_04100_002.01                                     */
/*                 VEMS_E_10_04100_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ECUMNG_vidPwrlEndAuth();                                 */
/*  input uint8 ECUMNG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EvePwrlEnd_EcuMng                                        */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EvePwrlEnd_EcuMng(void)
{
   if (ECUMNG_u8Inhib != 0x5A)
   {
      ECUMNG_vidPwrlEndAuth();
   }
}
/*------------------------------- end of file --------------------------------*/