/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGIDLEINTERFACE                                        */
/* !Description     : ENGIDLEINTERFACE Component                              */
/*                                                                            */
/* !Module          : ENGIDLEINTERFACE                                        */
/* !Description     : INTERFACE RALENTI MOTEUR ESSENCE                        */
/*                                                                            */
/* !File            : ENGIDLEINTERFACE_SCH.C                                  */
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
/*   1 / ENGIDLEINTERFACE_vidEntryInit                                        */
/*   2 / IdlSys_EveSync_GslIdlCtl                                             */
/*                                                                            */
/* !Reference   : V02 NT 10 04614 / 02                                        */
/* !OtherRefs   : 01460_10_01449 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/Projets/LIBPSA/LOG/Ref/MOD_VEMS/TqStruct/ENGIDLEINTERFACE/$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ENGIDLEINTERFACE.h"
#include "ENGIDLEINTERFACE_L.h"
#include "ENGIDLEINTERFACE_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGIDLEINTERFACE_vidEntryInit                              */
/* !Description :  Evénement reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_04614_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGIDLEINTERFACE_vidInitOutput(void);                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ENGIDLEINTERFACE_vidEntryInit                                  */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGIDLEINTERFACE_vidEntryInit(void)
{
   ENGIDLEINTERFACE_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IdlSys_EveSync_GslIdlCtl                                   */
/* !Description :  Evénement du module ENGIDLEINTERFACE.                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_04614_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGIDLEINTERFACE_vidBoucleStruct(void);                  */
/*  extf argret void ENGIDLEINTERFACE_vidSelGainRegul(void);                  */
/*  extf argret void ENGIDLEINTERFACE_vidCalcCouples(void);                   */
/*  input uint8 ENGIDLEINTERFACE_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IdlSys_EveSync_GslIdlCtl                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IdlSys_EveSync_GslIdlCtl(void)
{
   if (ENGIDLEINTERFACE_u8Inhib != 0x5A)
   {
      ENGIDLEINTERFACE_vidBoucleStruct();
      ENGIDLEINTERFACE_vidSelGainRegul();
      ENGIDLEINTERFACE_vidCalcCouples();
   }
}
/*------------------------------- end of file --------------------------------*/