/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCOILMNG                                               */
/* !Description     : IGCOILMNG component.                                    */
/*                                                                            */
/* !Module          : IGCOILMNG                                               */
/* !Description     : COMMANDE ET DIAGNOSTIC DES BOBINES D’ALLUMAGE           */
/*                                                                            */
/* !File            : IGCOILMNG_SCH.C                                         */
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
/*   1 / IgCmd_EveRst_IgCoilMng                                               */
/*   2 / IgCmd_SdlSlow_IgCoilMng                                              */
/*   3 / IgCmd_SdlFast_IgCoilMng                                              */
/*   4 / IgCmd_EveICD_IgCoilMng                                               */
/*   5 / IgCmd_EveStTR_IgCoilMng                                              */
/*   6 / IgCmd_EveSyncAccu_IgCoilMng                                          */
/*   7 / IgCmd_EveCkSnOf_IgCoilMng                                            */
/*   8 / IgSys_EveCkSnOn_IgCoilMng                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6668934 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/IGCOILMNG/IGCOILMNG_SCH.C_v       $*/
/* $Revision::   1.14     $$Author::   achebino       $$Date::   02 Jul 2014 $*/
/* $Author::   achebino                               $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "IGCOILMNG.h"
#include "IGCOILMNG_L.h"
#include "IGCOILMNG_IM.h"
#include "IGCOILMNG_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveRst_IgCoilMng                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidInitOutput();                               */
/*  extf argret void IGCOILMNG_vidDisable();                                  */
/*  extf argret void IGCOILMNG_vidInitilization();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveRst_IgCoilMng                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveRst_IgCoilMng(void)
{
   IGCOILMNG_vidInitOutput();
   IGCOILMNG_vidDisable();
   IGCOILMNG_vidInitilization();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_SdlSlow_IgCoilMng                                    */
/* !Description :  Moniteur lent de la fonction IgCmd                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidCalcIcdRatioEnergy();                       */
/*  input uint8 IGCOILMNG_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_SdlSlow_IgCoilMng                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_SdlSlow_IgCoilMng(void)
{
   if (IGCOILMNG_u8Inhib != 0x5A)
   {
      IGCOILMNG_vidCalcIcdRatioEnergy();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_SdlFast_IgCoilMng                                    */
/* !Description :  Moniteur rapide de la fonction IgCmd                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidCallDiagSdlFast();                          */
/*  input uint8 IGCOILMNG_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_SdlFast_IgCoilMng                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_SdlFast_IgCoilMng(void)
{
   if (IGCOILMNG_u8Inhib != 0x5A)
   {
      IGCOILMNG_vidCallDiagSdlFast();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveICD_IgCoilMng                                     */
/* !Description :  Evénement de commande du driver des bobines d'allumage     */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidCalcIcdState();                             */
/*  extf argret void IGCOILMNG_vidCalcDwellTime();                            */
/*  extf argret void IGCOILMNG_vidAgIgMng();                                  */
/*  extf argret void IGCOILMNG_vidCallDiagICD();                              */
/*  input uint8 IGCOILMNG_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveICD_IgCoilMng                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveICD_IgCoilMng(void)
{
   if (IGCOILMNG_u8Inhib != 0x5A)
   {
      IGCOILMNG_vidCalcIcdState();
      IGCOILMNG_vidCalcDwellTime();
      IGCOILMNG_vidAgIgMng();
      IGCOILMNG_vidCallDiagICD();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveStTR_IgCoilMng                                    */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidCalcDwellTime();                            */
/*  input uint8 IGCOILMNG_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveStTR_IgCoilMng                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveStTR_IgCoilMng(void)
{
   if (IGCOILMNG_u8Inhib != 0x5A)
   {
      IGCOILMNG_vidCalcDwellTime();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveSyncAccu_IgCoilMng                                */
/* !Description :  Evénement indiquant le passage en synchronisation précise  */
/*                 du moteur                                                  */
/* !Number      :  SCH.6                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILMNG_vidEnable();                                   */
/*  input uint8 IGCOILMNG_u8Inhib;                                            */
/*  input boolean Ext_bDirRotCk;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveSyncAccu_IgCoilMng                                    */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveSyncAccu_IgCoilMng(void)
{
   boolean bLocalExt_bDirRotCk;


   if (IGCOILMNG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bDirRotCk, bLocalExt_bDirRotCk);

      if (bLocalExt_bDirRotCk != 0)
      {
         IGCOILMNG_vidEnable();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveCkSnOf_IgCoilMng                                  */
/* !Description :  Evènement synchronisation perdue                           */
/* !Number      :  SCH.7                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidDisable();                                  */
/*  input uint8 IGCOILMNG_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveCkSnOf_IgCoilMng                                      */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveCkSnOf_IgCoilMng(void)
{
   if (IGCOILMNG_u8Inhib != 0x5A)
   {
      IGCOILMNG_vidDisable();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveCkSnOn_IgCoilMng                                  */
/* !Description :  Evènement d'appel de l'enable du driver allumage pour      */
/*                 couvrir les cas de redémarrages STT rapides.               */
/* !Number      :  SCH.8                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILMNG_vidEnable();                                   */
/*  input uint8 IGCOILMNG_u8Inhib;                                            */
/*  input boolean Sync_bEngSyncAccu;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveCkSnOn_IgCoilMng                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveCkSnOn_IgCoilMng(void)
{
   boolean  bLocalSync_bEngSyncAccu;


   if (IGCOILMNG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Sync_bEngSyncAccu, bLocalSync_bEngSyncAccu);
      if (bLocalSync_bEngSyncAccu != 0)
      {
         IGCOILMNG_vidEnable();
      }
   }
}
/*---------------------------------end of file--------------------------------*/