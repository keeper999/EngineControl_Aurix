/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINCLN                                             */
/* !Description     : VLVACTINCLN component.                                  */
/*                                                                            */
/* !Module          : VLVACTINCLN                                             */
/* !Description     : NETTOYAGE DE L’ELECTROVANNE DE LA VVT ADMISSION         */
/*                                                                            */
/* !File            : VLVACTINCLN_FCT3.C                                      */
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
/*   1 / VLVACTINCLN_vidhealClnMngTimeRst                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 08234 / 13                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTIN/VLVACTINCLN/VLVACT$*/
/* $Revision::   1.2      $$Author::   achebino       $$Date::   15 Oct 2012 $*/
/* $Author::   achebino                               $$Date::   15 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VLVACTINCLN.h"
#include "VLVACTINCLN_L.h"
#include "VLVACTINCLN_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidhealClnMngTimeRst                           */
/* !Description :  Réinitialisation de la durée de surveillance de l'erreur   */
/*                 pour la VVT échappement en mode curatif                    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 VlvAct_tiInHealClnMonErrDly_C;                               */
/*  output uint16 VlvAct_tiInHealClnMonErrDly;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidhealClnMngTimeRst(void)
{
   VlvAct_tiInHealClnMonErrDly = VlvAct_tiInHealClnMonErrDly_C;
}
/*---------------------------- end of file -----------------------------------*/