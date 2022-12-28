/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXCLN                                             */
/* !Description     : VLVACTEXCLN component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXCLN                                             */
/* !Description     : NETTOYAGE DE L’ELECTROVANNE DE LA VVT ECHAPPEMENT       */
/*                                                                            */
/* !File            : VLVACTEXCLN_FCT3.C                                      */
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
/*   1 / VLVACTEXCLN_vidhealClnMngTimeRst                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 08235 / 12                                        */
/* !OtherRefs   : VEMS V02 ECU#055441                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTEX/VLVACTEXCLN/VLVACT$*/
/* $Revision::   1.2      $$Author::   achebino       $$Date::   05 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   05 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VLVACTEXCLN.h"
#include "VLVACTEXCLN_L.h"
#include "VLVACTEXCLN_IM.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidhealClnMngTimeRst                           */
/* !Description :  Réinitialisation de la durée de surveillance de l'erreur   */
/*                 pour la VVT échappement en mode curatif                    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_08_08235_001.01                                     */
/*                 VEMS_R_08_08235_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 VlvAct_tiExHealClnMonErrDly_C;                               */
/*  output uint16 VlvAct_tiExHealClnMonErrDly;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidhealClnMngTimeRst(void)
{
   VlvAct_tiExHealClnMonErrDly = VlvAct_tiExHealClnMonErrDly_C;
}
/*---------------------------- end of file -----------------------------------*/