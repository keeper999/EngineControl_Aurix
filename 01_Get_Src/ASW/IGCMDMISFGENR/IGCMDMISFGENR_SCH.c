/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCMDMISFGENR                                           */
/* !Description     : IGCMDMISFGENR component.                                */
/*                                                                            */
/* !Module          : IGCMDMISFGENR                                           */
/* !Description     : Générateur De Ratés D'allumage.                         */
/*                                                                            */
/* !File            : IGCMDMISFGENR_SCH.C                                     */
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
/*   1 / IgCmd_EveRst_MisfGenr                                                */
/*   2 / IgCmd_EveRTSt_MisfGenr                                               */
/*   3 / IgCmd_EveStTR_MisfGenr                                               */
/*   4 / IgCmd_SdlSlow_MisfGenr                                               */
/*   5 / IgCmd_EveBDC_MisfGenr                                                */
/*                                                                            */
/* !Reference   : V02 NT 09 06148 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/MISF/IGCMDMISFGENR/IGCMDMISFGENR$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   24 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   24 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IGCMDMISFGENR.h"
#include "IGCMDMISFGENR_L.h"
#include "IGCMDMISFGENR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveRst_MisfGenr                                      */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCMDMISFGENR_vidInitOutput();                           */
/*  extf argret void IGCMDMISFGENR_vidInit();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveRst_MisfGenr                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveRst_MisfGenr(void)
{
   IGCMDMISFGENR_vidInitOutput();
   IGCMDMISFGENR_vidInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveRTSt_MisfGenr                                     */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCMDMISFGENR_vidInit();                                 */
/*  input uint8 IGCMDMISFGENR_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveRTSt_MisfGenr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveRTSt_MisfGenr(void)
{
   if (IGCMDMISFGENR_u8Inhib != 0x5A)
   {
      IGCMDMISFGENR_vidInit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveStTR_MisfGenr                                     */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCMDMISFGENR_vidInit();                                 */
/*  input uint8 IGCMDMISFGENR_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveStTR_MisfGenr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveStTR_MisfGenr(void)
{
   if (IGCMDMISFGENR_u8Inhib != 0x5A)
   {
      IGCMDMISFGENR_vidInit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_SdlSlow_MisfGenr                                     */
/* !Description :  Moniteur lent de la fonction MisfGenr.                     */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCMDMISFGENR_vidMisfireRatio();                         */
/*  input uint8 IGCMDMISFGENR_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_SdlSlow_MisfGenr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_SdlSlow_MisfGenr(void)
{
   if (IGCMDMISFGENR_u8Inhib != 0x5A)
   {
      IGCMDMISFGENR_vidMisfireRatio();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveBDC_MisfGenr                                      */
/* !Description :  Interruption PMB                                           */
/* !Number      :  SCH.5                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCMDMISFGENR_vidManageMisfCoils();                      */
/*  extf argret void IGCMDMISFGENR_vidCylSelection();                         */
/*  input uint8 IGCMDMISFGENR_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveBDC_MisfGenr                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveBDC_MisfGenr(void)
{
   if (IGCMDMISFGENR_u8Inhib != 0x5A)
   {
      IGCMDMISFGENR_vidManageMisfCoils();
      IGCMDMISFGENR_vidCylSelection();
   }
}
/********************************** end of file *******************************/