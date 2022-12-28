/******************************************************************************/
/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INITPROTECT                                             */
/* !Description     : INITPROTECT                                             */
/*                                                                            */
/* !Module          : INITPROTECT                                             */
/* !Description     : Génération des variables non produites                  */
/*                                                                            */
/* !File            : INITPROTECT_FCT1.C                                      */
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
/*   1 / INITPROTECT_vidInitProtectEnable                                     */
/*   2 / INITPROTECT_vidInitProtectDisable                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/INITPROTECT/INITPROTECT_fct$*/
/* $Revision::   1.0      $$Author::   fsanchez2      $$Date::   04 Mar 2014 $*/
/* $Author::   fsanchez2                              $$Date::   04 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "INITPROTECT.h"
#include "INITPROTECT_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Active la protection contre les activateTask à l'init       */
/* !Number      : FCT1.1                                                      */
/* !Reference   : NONE                                                        */
/*                                                                            */
/******************************************************************************/
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : V.VOYER                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INITPROTECT_vidInitProtectEnable(void)
{
   INITPROTECT_bInitInProgress = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Desactive la protection contre les activateTask à l'init    */
/* !Number      : FCT1.2                                                      */
/* !Reference   : NONE                                                        */
/*                                                                            */
/******************************************************************************/
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : V.VOYER                                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INITPROTECT_vidInitProtectDisable(void)
{
   INITPROTECT_bInitInProgress = 0;
}
/*------------------------------- end of file --------------------------------*/