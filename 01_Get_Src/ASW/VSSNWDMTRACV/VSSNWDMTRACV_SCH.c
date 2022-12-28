/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VSSNWDMTRACV                                            */
/* !Description     : VSSNWDMTRACV Component                                  */
/*                                                                            */
/* !Module          : VSSNWDMTRACV                                            */
/* !Description     : PILOTAGE DEMANDE MAINTIENT DMTR (DISPOSITIF DE MAINTIENT*/
/*                    EN TENSION RESEAU)                                      */
/*                                                                            */
/* !File            : VSSNWDMTRACV_SCH.C                                      */
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
/*   1 / VSSNWDMTRACV_vidEntryInit                                            */
/*   2 / Pwr_SdlMid_VoltHldDev                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6525894 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/VSSNWDMTRACV/VSSNWDMTRACV_SCH.C_v $*/
/* $Revision::   1.4      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
/* $Author::   fsanchez2                              $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VSSNWDMTRACV.h"
#include "VSSNWDMTRACV_L.h"
#include "VSSNWDMTRACV_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSSNWDMTRACV_vidEntryInit                                  */
/* !Description :  evènement d'initialisation des variables                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VSSNWDMTRACV_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VSSNWDMTRACV_vidInitOutput                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSSNWDMTRACV_vidEntryInit(void)
{
   VSSNWDMTRACV_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlMid_VoltHldDev                                      */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VSSNWDMTRACV_vidCallMng();                               */
/*  input uint8 VSSNWDMTRACV_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_SdlMid_VoltHldDev                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlMid_VoltHldDev(void)
{
   if (VSSNWDMTRACV_u8Inhib != 0x5A)
   {
      VSSNWDMTRACV_vidCallMng();
   }
}
/*------------------------------- end of file --------------------------------*/