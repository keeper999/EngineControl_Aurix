/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : POSTEQUSRV                                              */
/* !Description     : POSTEQUSRV Component                                    */
/*                                                                            */
/* !Module          : POSTEQUSRV                                              */
/* !Description     : COHERENCE CAN INFOS_EOBD_BSI                            */
/*                                                                            */
/* !File            : POSTEQUSRV_SCH.C                                        */
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
/*   1 / Srv_EveRst_PostEqu                                                   */
/*   2 / Srv_SdlFast_PostEquSrv                                               */
/*   3 / Srv_EvePostEqu_PostEquSrv                                            */
/*   4 / Srv_EveSa_PostEquSrv                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5074440 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066576                                         */
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
#include "POSTEQUSRV.h"
#include "POSTEQUSRV_L.h"
#include "POSTEQUSRV_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRst_PostEqu                                         */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_12_04585_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void POSTEQUSRV_vidInitOutput();                              */
/*  extf argret void POSTEQUSRV_vidInitEEP();                                 */
/*  extf argret void POSTEQUSRV_vidVarCodMng();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveRst_PostEqu                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRst_PostEqu(void)
{
   POSTEQUSRV_vidInitOutput();
   POSTEQUSRV_vidInitEEP();
   POSTEQUSRV_vidVarCodMng();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_SdlFast_PostEquSrv                                     */
/* !Description :  Moniteur rapide de la fonction service                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_12_04585_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void POSTEQUSRV_vidVarCodMng();                               */
/*  extf argret void POSTEQUSRV_vidInfoWrite();                               */
/*  input uint8 POSTEQUSRV_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_SdlFast_PostEquSrv                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_SdlFast_PostEquSrv(void)
{
   if (POSTEQUSRV_u8Inhib != 0x5A)
   {
      POSTEQUSRV_vidVarCodMng();
      POSTEQUSRV_vidInfoWrite();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EvePostEqu_PostEquSrv                                  */
/* !Description :  Runnable de la fonction Post Equipement                    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_12_04585_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void POSTEQUSRV_vidDataVerification();                        */
/*  extf argret void POSTEQUSRV_vidVarCodMng();                               */
/*  extf argret void POSTEQUSRV_vidInfoWrite();                               */
/*  input uint8 POSTEQUSRV_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EvePostEqu_PostEquSrv                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EvePostEqu_PostEquSrv(void)
{
   if (POSTEQUSRV_u8Inhib != 0x5A)
   {
      POSTEQUSRV_vidDataVerification();
      POSTEQUSRV_vidVarCodMng();
      POSTEQUSRV_vidInfoWrite();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveSa_PostEquSrv                                       */
/* !Description :  Runnable des fonctions de Security Access                  */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_12_04585_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void POSTEQUSRV_vidVarCodMng();                               */
/*  input uint8 POSTEQUSRV_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveSa_PostEquSrv                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveSa_PostEquSrv(void)
{
   if (POSTEQUSRV_u8Inhib != 0x5A)
   {
      POSTEQUSRV_vidVarCodMng();
   }
}
/*-------------------------------- end of file -------------------------------*/