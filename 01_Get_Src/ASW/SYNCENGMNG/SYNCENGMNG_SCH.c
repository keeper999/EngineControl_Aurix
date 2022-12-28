/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCENGMNG                                              */
/* !Description     : SYNCENGMNG component.                                   */
/*                                                                            */
/* !Module          : SYNCENGMNG                                              */
/* !Description     : GESTION DE LA SYNCHRONISATION MOTEUR.                   */
/*                                                                            */
/* !File            : SYNCENGMNG_SCH.C                                        */
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
/*   1 / Sync_EveRst_EngSyncMng                                               */
/*   2 / Sync_EveCkSnOn_EngSyncMng                                            */
/*   3 / Sync_EveCkSnOf_EngSyncMng                                            */
/*   4 / Sync_EveKOn_EngSyncMng                                               */
/*   5 / Sync_EveKOf_EngSyncMng                                               */
/*                                                                            */
/* !Reference: V02 NT 09 03299 / 03                                           */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCENGMNG/SYNCENGMNG_SCH.C_v$*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   02 Apr 2010 $*/
/* $Author::   hmelloul                               $$Date::   02 Apr 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "SYNCENGMNG.h"
#include "SYNCENGMNG_L.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : Sync_EveRst_EngSyncMng                                      */
/* !Description : Fonction d'accroche au moniteur reset.                      */
/* !Number      : SCH.1                                                       */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret void SYNCENGMNG_vidInitOutput();                             */
/*   extf argret void SYNCENGMNG_vidInitSync();                               */
/*   extf argret void SYNCENGMNG_vidIniAPI();                                 */
/*   extf argret void SYNCENGMNG_vidEngSyncLost();                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_EveRst_EngSyncMng                                         */
/* !Trigger  : Sync_EveRst_EngSyncMng                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_EngSyncMng(void)
{
   SYNCENGMNG_vidInitOutput();
   SYNCENGMNG_vidInitSync();
   SYNCENGMNG_vidIniAPI();
   SYNCENGMNG_vidEngSyncLost();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : Sync_EveCkSnOn_EngSyncMng                                   */
/* !Description : Evénnement synchronisation trouvée                          */
/* !Number      : SCH.2                                                       */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret void SYNCENGMNG_vidEngSyncVld();                             */
/*   input uint8 SYNCENGMNG_u8Inhib;                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_EveCkSnOn_EngSyncMng                                      */
/* !Trigger  : Sync_EveCkSnOn_EngSyncMng                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOn_EngSyncMng(void)
{
   if(SYNCENGMNG_u8Inhib != 0x5A)
   {
      SYNCENGMNG_vidEngSyncVld();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : Sync_EveCkSnOf_EngSyncMng                                   */
/* !Description : Evennement perte de synchronisation                         */
/* !Number      : SCH.3                                                       */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret void SYNCENGMNG_vidEngSyncLost();                            */
/*   input uint8 SYNCENGMNG_u8Inhib;                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_EveCkSnOf_EngSyncMng                                      */
/* !Trigger  : Sync_EveCkSnOf_EngSyncMng                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOf_EngSyncMng(void)
{
   if(SYNCENGMNG_u8Inhib != 0x5A)
   {
      SYNCENGMNG_vidEngSyncLost();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : Sync_EveKOn_EngSyncMng                                      */
/* !Description : Evènement clé Off -> On                                     */
/* !Number      : SCH.4                                                       */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret void SYNCENGMNG_vidInitSync();                               */
/*   input uint8 SYNCENGMNG_u8Inhib;                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_EveKOn_EngSyncMng                                         */
/* !Trigger  : Sync_EveKOn_EngSyncMng                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveKOn_EngSyncMng(void)
{
   if(SYNCENGMNG_u8Inhib != 0x5A)
   {
      SYNCENGMNG_vidInitSync();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : Sync_EveKOf_EngSyncMng                                      */
/* !Description : Evènement clé On -> Off                                     */
/* !Number      : SCH.5                                                       */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret void SYNCENGMNG_vidInitDesync();                             */
/*   input uint8 SYNCENGMNG_u8Inhib;                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Sync_EveKOf_EngSyncMng                                         */
/* !Trigger  : Sync_EveKOf_EngSyncMng                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveKOf_EngSyncMng(void)
{
   if(SYNCENGMNG_u8Inhib != 0x5A)
   {
      SYNCENGMNG_vidInitDesync();
   }
}
/*------------------------------- end of file --------------------------------*/