/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQCLUPED                                               */
/* !Description     : ACQCLUPED Component                                     */
/*                                                                            */
/* !Module          : ACQCLUPED                                               */
/* !Description     : ACQUISITION DE LA PEDALE D'EMBRAYAGE                    */
/*                                                                            */
/* !File            : ACQCLUPED_SCH.c                                         */
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
/*   1 / Clu_EveRst_CluPed                                                    */
/*   2 / Clu_SdlFast_AcqnCluPed                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6509293 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACQCLUPED/ACQCLUPED_SCH.c_v       $*/
/* $Revision::   1.8                                                         $*/
/* $Author::   achebino                               $$Date::   23 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACQCLUPED.h"
#include "ACQCLUPED_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_EveRst_CluPed                                          */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_04680_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCLUPED_vidResetCpsCluPedInput();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Clu_EveRst_CluPed                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_EveRst_CluPed(void)
{
   ACQCLUPED_vidResetCpsCluPedInput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_SdlFast_AcqnCluPed                                     */
/* !Description :  Moniteur d'acquisition de l'embrayage                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_04680_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCLUPED_vidClutchReadInput();                          */
/*  input uint8 ACQCLUPED_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Clu_SdlFast_AcqnCluPed                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_SdlFast_AcqnCluPed(void)
{
   if (ACQCLUPED_u8Inhib != 0x5A)
   {
      ACQCLUPED_vidClutchReadInput();
   }
}
/*------------------------------- end of file --------------------------------*/