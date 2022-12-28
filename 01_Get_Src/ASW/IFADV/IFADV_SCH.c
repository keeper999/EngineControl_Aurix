/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFADV                                                   */
/* !Description     : IFADV component                                         */
/*                                                                            */
/* !Module          : IFADV                                                   */
/* !Description     : INTERFACE DE LA CHAINE D’AVANCE                         */
/*                                                                            */
/* !File            : IFADV_SCH.C                                             */
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
/*   1 / Can_EveRst_FHCanF34DIf                                               */
/*   2 / Can_EveRxn34D_FHCanF34DIf                                            */
/*   3 / Can_SdlFast_FHCanF34DIf                                              */
/*   4 / RE_AdvMinT_005_MSEIf                                                 */
/*   5 / RE_AdvMinT_006_DREIf                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 07695 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CAA/IFADV/IFADV_SCH.c_v         $*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   04 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   04 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "IFADV.h"
#include "IFADV_L.h"
#include "IFADV_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF34DIf                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFADV_vidIgSys2();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF34DIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF34DIf(void)
{
   IFADV_vidIgSys2();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn34D_FHCanF34DIf                                  */
/* !Description :  Evénement d'interface (réception de trame 34Dh).           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFADV_vidIgSys2();                                       */
/*  input uint8 IFADV_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn34D_FHCanF34DIf                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn34D_FHCanF34DIf(void)
{
   if (IFADV_u8Inhib != 0x5A)
   {
      IFADV_vidIgSys2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_SdlFast_FHCanF34DIf                                    */
/* !Description :  Moniteur rapide de la fonction FHCANF34D                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFADV_vidIgSys2();                                       */
/*  input uint8 IFADV_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_SdlFast_FHCanF34DIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_SdlFast_FHCanF34DIf(void)
{
   if (IFADV_u8Inhib != 0x5A)
   {
      IFADV_vidIgSys2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_AdvMinT_005_MSEIf                                       */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.4                                                      */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFADV_vidIgSys1();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_AdvMinT_005_MSEIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_AdvMinT_005_MSEIf(void)
{
   IFADV_vidIgSys1();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_AdvMinT_006_DREIf                                       */
/* !Description :  Event TDC                                                  */
/* !Number      :  SCH.5                                                      */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFADV_vidIgSys1();                                       */
/*  input uint8 IFADV_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_AdvMinT_006_DREIf                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_AdvMinT_006_DREIf(void)
{
   if (IFADV_u8Inhib != 0x5A)
   {
      IFADV_vidIgSys1();
   }
}
/*------------------------------- end of file --------------------------------*/