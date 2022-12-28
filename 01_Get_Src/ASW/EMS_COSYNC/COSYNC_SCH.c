/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COSYNC                                                  */
/* !Description     : COSYNC component.                                       */
/*                                                                            */
/* !Module          : COSYNC                                                  */
/* !Description     : Superviseur de la fonction de synchronisation           */
/*                                                                            */
/* !File            : COSYNC_SCH.c                                            */
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
/*   1 / COSYNC_vidEntryInit                                                  */
/*   2 / COSYNC_vidEntry_10ms                                                 */
/*                                                                            */
/* !Reference   : V02 NT 10 02290 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2284 / 02                                       */
/* !OtherRefs   : VEMS V02 ECU#048141                                         */
/* !OtherRefs   : VEMS V02 ECU#048312                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COSYNC/COSYNC_SCH.c_v $*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   Jun 28 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 28 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "COSYNC.h"
#include "COSYNC_L.h"
#include "COSYNC_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidEntryInit                                        */
/* !Description :  Fonction de Reset Calculateur.                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_001.01                                     */
/*                 VEMS_R_10_02290_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COSYNC_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : COSYNC_vidEntryInit                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidEntryInit(void)
{
   COSYNC_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COSYNC_vidEntry_10ms                                       */
/* !Description :  Moniteur 10ms d'appel de la fonction.                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_02290_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COSYNC_vidSuperviseurFctSynchro();                       */
/*  input uint8 CoSync_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : COSYNC_vidEntry_10ms                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COSYNC_vidEntry_10ms(void)
{
   if (CoSync_u8Inhib != 0x5A)
   {
      COSYNC_vidSuperviseurFctSynchro();
   }
}
/*-------------------------------- end of file -------------------------------*/