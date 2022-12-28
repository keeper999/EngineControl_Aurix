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
/* !File            : SAIMMO_FCT5.C                                           */
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
/*   1 / SAIMMO_ETAT__nvmini                                                  */
/*   2 / SAIMMO_CODE__nvmini                                                  */
/*   3 / SAIMMO_init                                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5060905 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SAIMMO/SAIMMO_FCT5.c_v          $*/
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

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_ETAT__nvmini                                        */
/* !Description :  init the EEPROM object SAIMMO_ETAT if it is in default and */
/*                 if the first init has never been done.                     */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_038.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Srv_EveFirstInitDone_NvmDiag();                          */
/*  extf argret uint8  NVMSRV_u8GetStatus(argin NVMSRV_tudtObjectList         */
/* udtObject);                                                                */
/*  input boolean NvmDiag_bFirstInitDone;                                     */
/*  output Struct_ObjEtat_NVM SAIMMO_ObjEtat;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_ETAT__nvmini(void)
{
   uint8 u8LocalNVMSRVStatusLastObj;

   Srv_EveFirstInitDone_NvmDiag();

   u8LocalNVMSRVStatusLastObj = NVMSRV_u8GetStatus(NVMSRV_udtOBJ_SAIMMO_ETAT);
   if (  (NvmDiag_bFirstInitDone == FALSE)
      && (u8LocalNVMSRVStatusLastObj == NVMSRV_u8DEFAULT)  )
   {
      SAIMMO_ObjEtat.EcuPairOffSt = SAIMMO_ETAT_PROG_LIVRAISON;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_CODE__nvmini                                        */
/* !Description :  Init the EEPROM object SAIMMO_CODE if it is in default and */
/*                 if the first init has never been done.                     */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_039.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Srv_EveFirstInitDone_NvmDiag();                          */
/*  extf argret uint8  NVMSRV_u8GetStatus(argin NVMSRV_tudtObjectList         */
/* udtObject);                                                                */
/*  input boolean NvmDiag_bFirstInitDone;                                     */
/*  output Struct_ObjCode_NVM SAIMMO_ObjCode;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_CODE__nvmini(void)
{
   uint8 u8LocalNVMSRVStatusLastObj;

   Srv_EveFirstInitDone_NvmDiag();

   u8LocalNVMSRVStatusLastObj = NVMSRV_u8GetStatus(NVMSRV_udtOBJ_SAIMMO_CODE);
   if (  (NvmDiag_bFirstInitDone == FALSE)
      && (u8LocalNVMSRVStatusLastObj == NVMSRV_u8DEFAULT)  )
   {
      SAIMMO_ObjCode.AdcCode = 0x11111111;
      SAIMMO_ObjCode.AdcTyp = 0xFF;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_init                                                */
/* !Description :  Call the IMMO module function if the module hanve not been */
/*                 already activated.                                         */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Immo_Init();                                             */
/*  input boolean SAIMMO_bActived;                                            */
/*  output boolean SAIMMO_bActived;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_init(void)
{
   if ( SAIMMO_bActived != TRUE )
   {
      Immo_Init();
      SAIMMO_bActived = TRUE;
   }
}

/*-------------------------------- end of file -------------------------------*/