/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KEYPUSHINFO                                             */
/* !Description     : KEYPUSHINFO component.                                  */
/*                                                                            */
/* !Module          : KEYPUSHINFO                                             */
/* !Description     : BASIC SOFTWARE PROCESSING REQUIREMENTS FOR KEY PUSH     */
/*                    INFORMATION.                                            */
/*                                                                            */
/* !File            : KEYPUSHINFO_SCH.C                                       */
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
/*   1 / STT_EveRst_KeyPushInfo                                               */
/*   2 / STT_SdlFast_KeyPushInfo                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6543971 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/KEYPUSHINFO/KEYPUSHINFO_SCH.C_v   $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "KEYPUSHINFO.h"
#include "KEYPUSHINFO_L.h"
#include "KEYPUSHINFO_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_EveRst_KeyPushInfo                                     */
/* !Description :  Evènement reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KEYPUSHINFO_vidInitOutput();                             */
/*  extf argret void KEYPUSHINFO_vidInit();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_EveRst_KeyPushInfo                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_EveRst_KeyPushInfo(void)
{
   KEYPUSHINFO_vidInitOutput();
   KEYPUSHINFO_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_SdlFast_KeyPushInfo                                    */
/* !Description :  Moniteur rapide.                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KEYPUSHINFO_vidEventSelc();                              */
/*  input uint8 KEYPUSHINFO_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_SdlFast_KeyPushInfo                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_SdlFast_KeyPushInfo(void)
{
   if (KEYPUSHINFO_u8Inhib != 0x5A)
   {
      KEYPUSHINFO_vidEventSelc();
   }
}

/*------------------------------- end of file --------------------------------*/