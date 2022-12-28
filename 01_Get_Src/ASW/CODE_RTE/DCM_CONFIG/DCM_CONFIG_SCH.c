/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TELECODAGE                                              */
/*                                                                            */
/* !Module          : TELECODAGE                                              */
/*                                                                            */
/* !File            : DCM_CONFIG_SCH.c                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DCM_CONFIG_EveRst                                                    */
/*   2 / DCM_CONFIG_Eve_5ms                                                   */
/*   3 / DCM_CONFIG_SdlMid_RcRst                                              */
/*   4 / DCM_CONFIG_sdlFast_DiagSrv                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 5                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_CONFIG_S$*/
/* $Revision::   1.0      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "DCM.H"
#include "Dcm_Cbk.h"
#include "DCM_MANU.h"
#include "STD_TYPES.h"
#include "DCM_CONFIG.h"
#include "DCM_CONFIG_L.h"
#include "DCM_CONFIG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_CONFIG_EveRst                                          */
/* !Description :  Evène Reset du DCM                                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_Reset();                                        */
/*  extf argret void Dcm_Init(argout uint8 *Dcm_kstrPbConfig);                */
/*  extf argret void Dcm_ComM_FullComModeEntered(argin uint8 NetworkId);      */
/*  input uint8 DCM_CONFIG_u8Inhib;                                           */
/*  input uint8 Dcm_kstrPbConfig;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DCM_CONFIG_EveRst                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_CONFIG_EveRst(void)
{
   if( DCM_CONFIG_u8Inhib != 0x5A )
   {
      DCM_MANU_Reset();
      Dcm_Init(&Dcm_kstrPbConfig);
      Dcm_ComM_FullComModeEntered(0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_CONFIG_Eve_5ms                                         */
/* !Description :  Moniteur schedule à 5ms du DCM                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Dcm_MainFunction();                                      */
/*  input uint8 DCM_CONFIG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DCM_CONFIG_EveRst                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_CONFIG_Eve_5ms(void)
{
   if( DCM_CONFIG_u8Inhib != 0x5A )
   {
      Dcm_MainFunction();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_CONFIG_SdlMid_RcRst                                    */
/* !Description :  Moniteur moyen du DCM                                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SrvRc_SdlMid_RcRst();                                    */
/*  input uint8 DCM_CONFIG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_CONFIG_SdlMid_RcRst(void)
{
   if( DCM_CONFIG_u8Inhib != 0x5A )
   {
      SrvRc_SdlMid_RcRst();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_CONFIG_sdlFast_DiagSrv                                 */
/* !Description :  Moniteur rapide de la fonction Srv                         */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SrvRc_SdlFast_DiagSrv();                                 */
/*  input uint8 DCM_CONFIG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_CONFIG_sdlFast_DiagSrv(void)
{
   if( DCM_CONFIG_u8Inhib != 0x5A )
   {
      SrvRc_SdlFast_DiagSrv();
   }
}