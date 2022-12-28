/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COES                                                    */
/* !Description     : COES component.                                         */
/*                                                                            */
/* !Module          : COES                                                    */
/* !Description     : Gestionnaire séquence d’arrêt STT                       */
/*                                                                            */
/* !File            : COES_SCH.C                                              */
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
/*   1 / COES_vidEntryInit                                                    */
/*   2 / CoEs_SdlFast_STTEs                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5660023 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_2877 / 1.6                                      */
/* !OtherRefs   : VEMS V02 ECU#067169                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COES/COES_SCH.C_v     $*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   22 Nov 2013 $*/
/* $Author::   mbenfrad                               $$Date::   22 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "COES.h"
#include "COES_L.h"
#include "COES_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidEntryInit                                          */
/* !Description :  Evenement Reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COES_vidInitOutput();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : COES_vidEntryInit                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidEntryInit(void)
{
   COES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoEs_SdlFast_STTEs                                         */
/* !Description :  Scheduler rapide de la fonction de gestion de l'arrêt STT. */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COES_vidInterdirInterrupSeqArret();                      */
/*  extf argret void COES_vidObserverVanosPositionRef();                      */
/*  extf argret void COES_vidObserverVanneCanisFermee();                      */
/*  extf argret void COES_vidFiltrerRegimeDentADent();                        */
/*  extf argret void COES_vidSequencerPhaseArretSTT();                        */
/*  extf argret void COES_vidSelectionnerCommandArret();                      */
/*  input uint8 COES_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoEs_SdlFast_STTEs                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoEs_SdlFast_STTEs(void)
{
   if (COES_u8Inhib != 0x5A)
   {
      COES_vidInterdirInterrupSeqArret();
      COES_vidObserverVanosPositionRef();
      COES_vidObserverVanneCanisFermee();
      COES_vidFiltrerRegimeDentADent();
      COES_vidSequencerPhaseArretSTT();
      COES_vidSelectionnerCommandArret();
   }
}
/*------------------------------- end of file --------------------------------*/