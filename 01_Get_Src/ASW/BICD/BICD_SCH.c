/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BICD                                                    */
/* !Description     : BICD Component.                                         */
/*                                                                            */
/* !Module          : BICD                                                    */
/* !Description     : Information Etat BICD                                   */
/*                                                                            */
/* !File            : BICD_SCH.C                                              */
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
/*   1 / EngSt_EveRst_DftStaCmd                                               */
/*   2 / EngSt_SdlFast_DftStaCmd                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6529336 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BICD/BICD_SCH.C_v                 $*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   22 May 2014 $*/
/* $Author::   wbouach                                $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BICD.h"
#include "BICD_L.h"
#include "BICD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_DftStaCmd                                     */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BICD_vidDftStaCmdInit();                                 */
/*  extf argret void BICD_vidInitOutput();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  EngSt_EveRst_DftStaCmd                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_DftStaCmd(void)
{
   BICD_vidDftStaCmdInit();
   BICD_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_DftStaCmd                                    */
/* !Description :  Monitoring rapide                                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BICD_vidFastFunCall();                                   */
/*  input uint8 BICD_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_DftStaCmd                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_DftStaCmd(void)
{
   if (BICD_u8Inhib != 0x5A)
   {
      BICD_vidFastFunCall();
   }
}
/*------------------------------- end of file --------------------------------*/