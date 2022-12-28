/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDETIDLE                                             */
/* !Description     : MISFDETIDLE component                                   */
/*                                                                            */
/* !Module          : MISFDETIDLE                                             */
/* !Description     : ALGORITHMES DE DETECTION DE MISFIRE EN IDLE             */
/*                                                                            */
/* !File            : MISFDETIDLE_SCH.C                                       */
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
/*   1 / Misf_EveRst_MisfDetIdle                                              */
/*   2 / Misf_EveMisf_MisfDetIdle                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5198626 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/MISFDETIDLE/MISFDETIDLE_SCH.C_v   $*/
/* $Revision::   1.2      $$Author::   achebino       $$Date::   13 Dec 2013 $*/
/* $Author::   achebino                               $$Date::   13 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MISFDETIDLE.h"
#include "MISFDETIDLE_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRst_MisfDetIdle                                    */
/* !Description :  Evènement de reset calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDETIDLE_vidInitOutput();                             */
/*  extf argret void MISFDETIDLE_vidInit();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveRst_MisfDetIdle                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRst_MisfDetIdle(void)
{
   MISFDETIDLE_vidInitOutput();
   MISFDETIDLE_vidInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfDetIdle                                   */
/* !Description :  Evènement reset calculateur                                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDETIDLE_vidMisfDetIdleDet();                         */
/*  input uint8 MISFDETIDLE_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_MisfDetIdle                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfDetIdle(void)
{
   if (MISFDETIDLE_u8Inhib != 0x5A)
   {
      MISFDETIDLE_vidMisfDetIdleDet();
   }
}
/*------------------------------- end of file --------------------------------*/