/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CONFIGLIN                                               */
/* !Description     : CONFIGLIN component                                     */
/*                                                                            */
/* !Module          : CONFIGLIN                                               */
/* !Description     : LIN CONFIGURATION                                       */
/*                                                                            */
/* !File            : CONFIGLIN_SCH.C                                         */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CONFIGLIN_vidMngEveRst                                               */
/*   3 / CONFIGLIN_vidMngSch_10MS                                             */
/*   5 / CONFIGLIN_vidMngSch_100MS                                            */
/*                                                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                          $*/
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CONFIGLIN/CONFIGLIN_SCH.c_v       $*/
/* $Revision::   1.2                                                         $*/
/* $Author::   fgravez                                $$Date::   15 Sep 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CONFIGLIN.h"
#include "CONFIGLIN_L.h"
#include "CONFIGLIN_im.h"

#define CONFIGLIN_START_SEC_CODE
#include "Memmap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : API which call the functions which must be executed on this */
/*                event.                                                      */
/* !Number      : SCH.1                                                       */
/* !Reference   : V02 NT 09 04644 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void CONFIGLIN_vidInit();                                    */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidMngEveRst                                         */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidMngEveRst(void)
{
   CONFIGLIN_vidInit();
}

/******************************************************************************/
/*                                                                            */
/* !Description : API which call the functions which must be executed on this */
/*                event.                                                      */
/* !Number      : SCH.2                                                       */
/* !Reference   : V02 NT 09 04644 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void CONFIGLIN_vidReInitCondCheck();                         */
/*   extf argret void CONFIGLIN_vidLinScheduler();                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidMngSch_10MS                                       */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidMngSch_10MS(void)
{
   if (CONFIGLIN_u8Inhib != 0x5A)
   {
      CONFIGLIN_vidReInitCondCheck();
      CONFIGLIN_vidLinScheduler();
   }
}

/******************************************************************************/
/*                                                                            */
/* !Description : API which call the functions which must be executed on this */
/*                event.                                                      */
/* !Number      : SCH.3                                                       */
/* !Reference   : V02 NT 09 04644 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void CONFIGLIN_vidDiagLinBlocked();                          */
/*   extf argret void CONFIGLIN_vidDiagAltAbsent();                           */
/*   extf argret void CONFIGLIN_vidDiagFrame                                  */
/*                   (uint8 u8NodeIndex, uint16 u16DefaultIndex);             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidMngSch_100MS                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidMngSch_100MS(void)
{
   if (CONFIGLIN_u8Inhib != 0x5A)
   {
      CONFIGLIN_vidDiagLinBlocked();
      CONFIGLIN_vidDiagAltAbsent();
      CONFIGLIN_vidDiagFrame(ETAT_ALT1_LIN, GD_DFT_ETAT_ALT1);
   }
}

/******************************************************************************/
/*                                                                            */
/* !Description : API which call the functions which must be executed on this */
/*                event.                                                      */
/* !Number      : SCH.4                                                       */
/* !Reference   : V02 NT 09 04644 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void CONFIGLIN_vidDiagFrame                                  */
/*                   (uint8 u8NodeIndex, uint16 u16DefaultIndex);             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : CONFIGLIN_vidMngSch_1S                                         */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :                                                             */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CONFIGLIN_vidMngSch_1S(void)
{
   if (CONFIGLIN_u8Inhib != 0x5A)
   {
      CONFIGLIN_vidDiagFrame(ETAT_ALT2_LIN, GD_DFT_ETAT_ALT2);
   }
}

#define CONFIGLIN_STOP_SEC_CODE
#include "Memmap.h"
/*QAC Warning Msg(2:0838): Due to the multiple inclusion of MemMap.h file  */
/*-------------------------------- end of file -------------------------------*/
/*QAC Warning Msg(2:0862): Due to Inclusion of MemMap.h                    */
