/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GOBD                                                    */
/* !Description     : GOBD Component                                          */
/*                                                                            */
/* !Module          : GOBD                                                    */
/* !Description     : Gestionnaire OBD                                        */
/*                                                                            */
/* !File            : GOBD_SCH.C                                              */
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
/*   1 / GOBD_vidMngEveSldSlow                                                */
/*   2 / GOBD_vidMngEveKOn                                                    */
/*   3 / GOBD_vidMngEveKOf                                                    */
/*   4 / GOBD_vidMngEveRst                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5075502 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GOBD/GOBD_SCH.c_v            $*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   11 Feb 2014 $*/
/* $Author::   mbenfrad                               $$Date::   11 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GOBD.h"
#include "GOBD_L.h"
#include "GOBD_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidMngEveSldSlow                                      */
/* !Description :  API called on the slow recurrence by the scheduler.        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  PTS_R_5075502_001.01                                       */
/*                 PTS_R_5075502_002.01                                       */
/*                 PTS_R_5075502_003.01                                       */
/*                 PTS_R_5075502_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidTiSinceEngStrt();                                */
/*  input uint8 GOBD_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GOBD_vidMngEveSldSlow                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidMngEveSldSlow(void)
{
   if(GOBD_u8Inhib != 0x5A)
   {
      GOBD_vidTiSinceEngStrt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidMngEveKOn                                          */
/* !Description :  API called on the event Key On by the scheduler.           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  PTS_R_5075502_001.01                                       */
/*                 PTS_R_5075502_002.01                                       */
/*                 PTS_R_5075502_003.01                                       */
/*                 PTS_R_5075502_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidSetKeyOBD();                                     */
/*  extf argret void GOBD_vidExitEveKeyOBD();                                 */
/*  extf argret void GOBD_vidInitTiSinceEngStrt();                            */
/*  input uint8 GOBD_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GOBD_vidMngEveKOn                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidMngEveKOn(void)
{
   if(GOBD_u8Inhib != 0x5A)
   {
      GOBD_vidSetKeyOBD();
      GOBD_vidExitEveKeyOBD();
      GOBD_vidInitTiSinceEngStrt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidMngEveKOf                                          */
/* !Description :  API called on the event Key Off by the scheduler.          */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  PTS_R_5075502_001.01                                       */
/*                 PTS_R_5075502_002.01                                       */
/*                 PTS_R_5075502_003.01                                       */
/*                 PTS_R_5075502_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidRstKeyOBD();                                     */
/*  extf argret void GOBD_vidWriteCntAcv(argin boolean bValue);               */
/*  input uint8 GOBD_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GOBD_vidMngEveKOf                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidMngEveKOf(void)
{
   if(GOBD_u8Inhib != 0x5A)
   {
      GOBD_vidRstKeyOBD();
      GOBD_vidWriteCntAcv(FALSE);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidMngEveRst                                          */
/* !Description :  API called on the event reset by the scheduler.            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  PTS_R_5075502_001.01                                       */
/*                 PTS_R_5075502_002.01                                       */
/*                 PTS_R_5075502_003.01                                       */
/*                 PTS_R_5075502_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidInit();                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GOBD_vidMngEveRst                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidMngEveRst(void)
{
   GOBD_vidInit();
}
/*------------------------------- end of file --------------------------------*/