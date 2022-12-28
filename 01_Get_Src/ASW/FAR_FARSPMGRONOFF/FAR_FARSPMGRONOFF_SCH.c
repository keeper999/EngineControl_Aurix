/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FAR_FARSPMGRONOFF                                       */
/* !Description     : FAR_FARSPMGRONOFF component                             */
/*                                                                            */
/* !Module          : FAR_FARSPMGRONOFF                                       */
/* !Description     : CALCUL DE L’OBJECTIF GLOBAL                             */
/*                                                                            */
/* !File            : FAR_FARSPMGRONOFF_SCH.C                                 */
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
/*   1 / FAR_FARSPMGRONOFF_vidEntryInit                                       */
/*   2 / Far_SdlFast_FarSpMgr                                                 */
/*   3 / Far_EveCrTR_FarSpMgr                                                 */
/*   4 / Far_EveNTFL_FarSpMgr                                                 */
/*   5 / Far_EveTOSR_FarSpMgr                                                 */
/*                                                                            */
/* !Reference   : V02 NT 08 05510 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FAR/FAR_FARSPMGRONOFF/FAR_FARSPM$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   vgarnier                               $$Date::   11 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "FAR_FARSPMGRONOFF.h"
#include "FAR_FARSPMGRONOFF_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FAR_FARSPMGRONOFF_vidEntryInit                             */
/* !Description :  Fonction d'accroche au moniteur Reset.                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FAR_FARSPMGRONOFF_vidInitOutput();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FAR_FARSPMGRONOFF_vidInitOutput                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FAR_FARSPMGRONOFF_vidEntryInit(void)
{
   FAR_FARSPMGRONOFF_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Far_SdlFast_FarSpMgr                                       */
/* !Description :  Moniteur rapide de la fonction objectif de richesse pour le*/
/*                 groupe injection.                                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FAR_FARSPMGRONOFF_vidObjRiGlobal();                      */
/*  input uint8 FAR_FARSPMGRONOFF_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Far_SdlFast_FarSpMgr                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Far_SdlFast_FarSpMgr(void)
{
   if (FAR_FARSPMGRONOFF_u8Inhib != 0x5A)
   {
      FAR_FARSPMGRONOFF_vidObjRiGlobal();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Far_EveCrTR_FarSpMgr                                       */
/* !Description :  Evénement CRANKING vers RUNNING.                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FAR_FARSPMGRONOFF_vidObjRiGlobal();                      */
/*  input uint8 FAR_FARSPMGRONOFF_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Far_EveCrTR_FarSpMgr                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Far_EveCrTR_FarSpMgr(void)
{
   if (FAR_FARSPMGRONOFF_u8Inhib != 0x5A)
   {
      FAR_FARSPMGRONOFF_vidObjRiGlobal();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Far_EveNTFL_FarSpMgr                                       */
/* !Description :  Transition ERUN_NORMAL_RUNNING vers ERUN_FULL_LOAD.        */
/* !Number      :  SCH.4                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FAR_FARSPMGRONOFF_vidObjRiGlobal();                      */
/*  input uint8 FAR_FARSPMGRONOFF_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Far_EveNTFL_FarSpMgr                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Far_EveNTFL_FarSpMgr(void)
{
   if (FAR_FARSPMGRONOFF_u8Inhib != 0x5A)
   {
      FAR_FARSPMGRONOFF_vidObjRiGlobal();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Far_EveTOSR_FarSpMgr                                       */
/* !Description :  Entrée en ERUN_ENGINE_OVERRUN_FCO ou                       */
/*                 ERUN_ENGINE_OVERSPEED_FCO.                                 */
/* !Number      :  SCH.5                                                      */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FAR_FARSPMGRONOFF_vidObjRiGlobal();                      */
/*  input uint8 FAR_FARSPMGRONOFF_u8Inhib;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Far_EveTOSR_FarSpMgr                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Far_EveTOSR_FarSpMgr(void)
{
   if (FAR_FARSPMGRONOFF_u8Inhib != 0x5A)
   {
      FAR_FARSPMGRONOFF_vidObjRiGlobal();
   }
}
/*------------------------------end of file-----------------------------------*/