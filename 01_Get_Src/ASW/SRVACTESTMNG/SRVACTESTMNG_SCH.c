/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SRVACTESTMNG                                            */
/* !Description     : SRVACTESTMNG component.                                 */
/*                                                                            */
/* !Module          : SRVACTESTMNG                                            */
/* !Description     : MANAGEUR DES TESTS ACTIONNEURS.                         */
/*                                                                            */
/* !File            : SRVACTESTMNG_SCH.C                                      */
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
/*   1 / Srv_EveRst_ActrTstMng                                                */
/*   2 / Srv_SdlMid_ActrTstMng                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5074355 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SRVACTESTMNG/SRVACTESTMNG_SCH.C_$*/
/* $Revision::   1.6      $$Author::   pbakabad       $$Date::   Apr 11 2013 $*/
/* $Author::   pbakabad                               $$Date::   Apr 11 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SRVACTESTMNG.h"
#include "SRVACTESTMNG_L.h"
#include "SRVACTESTMNG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRst_ActrTstMng                                      */
/* !Description :  Evènement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SRVACTESTMNG_vidInitOutput();                            */
/*  extf argret void SRVACTESTMNG_vidActrTstAcvChart();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveRst_ActrTstMng                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRst_ActrTstMng(void)
{
   SRVACTESTMNG_vidInitOutput();
   SRVACTESTMNG_vidActrTstAcvChart();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_SdlMid_ActrTstMng                                      */
/* !Description :  Moniteur moyen de la fonction test actionneur              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SRVACTESTMNG_vidActrTstCdn();                            */
/*  extf argret void SRVACTESTMNG_vidActrTstCmpl();                           */
/*  extf argret void SRVACTESTMNG_vidActrTstAcvChart();                       */
/*  extf argret void SRVACTESTMNG_vidActrTstRes();                            */
/*  input uint8 SRVACTESTMNG_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_SdlMid_ActrTstMng                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_SdlMid_ActrTstMng(void)
{
   if (SRVACTESTMNG_u8Inhib != 0x5A)
   {
      SRVACTESTMNG_vidActrTstCdn();
      SRVACTESTMNG_vidActrTstCmpl();
      SRVACTESTMNG_vidActrTstAcvChart();
      SRVACTESTMNG_vidActrTstRes();
   }
}

/*---------------------------- end of file -----------------------------------*/