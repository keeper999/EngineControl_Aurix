/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDEXTINT                                                */
/* !Description     : GDEXTINT Component                                      */
/*                                                                            */
/* !Module          : GDEXTINT                                                */
/* !Description     : GD EXTERNAL INTERFACE                                   */
/*                                                                            */
/* !File            : GDEXTINT_SCH.C                                          */
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
/*   1 / Dem_Init                                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5075312 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDEXTINT/GDEXTINT_SCH.C_v    $*/
/* $Revision::   1.17     $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GDExtInt.h"
#include "GDExtInt_L.h"
#include "GDExtInt_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dem_Init                                                   */
/* !Description :  Initializes or re-initializes the GD                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_10_02831_007.02                                     */
/*                 VEMS_E_10_02831_008.02                                     */
/*                 VEMS_E_10_02831_009.01                                     */
/*                 VEMS_R_10_02831_001.01                                     */
/*                 VEMS_R_10_02831_002.01                                     */
/*                 VEMS_R_10_02831_003.01                                     */
/*                 VEMS_R_10_02831_004.01                                     */
/*                 VEMS_R_10_02831_005.01                                     */
/*                 VEMS_R_10_02831_006.02                                     */
/*                 PTS_R_5075312_001.01                                       */
/*                 PTS_R_5075312_002.01                                       */
/*                 PTS_R_5075312_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDEXTINT_vidEveRst_GDExtInt();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Dem_Init                                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Dem_Init(void)
{
   GDEXTINT_vidEveRst_GDExtInt();
}
/*------------------------------- end of file --------------------------------*/