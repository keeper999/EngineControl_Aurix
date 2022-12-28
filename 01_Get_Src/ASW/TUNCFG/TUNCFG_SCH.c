/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TUNCFG                                                  */
/* !Description     : TUNCFG component.                                       */
/*                                                                            */
/* !Module          : TUNCFG                                                  */
/* !Description     : GESTION DES DIVERSITES                                  */
/*                                                                            */
/* !File            : TUNCFG_SCH.C                                            */
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
/*   1 / Cf_EveRst_TunCfg                                                     */
/*   2 / Cf_EveTele_TunCfg                                                    */
/*   3 / Cf_SdlSlow_TunCfg                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5304544 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TUNCFG/TUNCFG_SCH.C_v           $*/
/* $Revision::   1.16     $$Author::   pbakabad       $$Date::   Jun 28 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 28 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "TUNCFG.h"
#include "TUNCFG_L.h"
#include "TUNCFG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_TunCfg                                           */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_024.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TUNCFG_vidTunCfg();                                      */
/*  extf argret void TUNCFG_vidTunCfg1();                                     */
/*  extf argret void TUNCFG_vidProdCfg();                                     */
/*  extf argret void TUNCFG_vidSelCfg();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Cf_EveRst_TunCfg                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_TunCfg(void)
{
   TUNCFG_vidTunCfg();
   TUNCFG_vidTunCfg1();
   TUNCFG_vidProdCfg();
   TUNCFG_vidSelCfg();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveTele_TunCfg                                          */
/* !Description :  Evénement télécodage                                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_024.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TUNCFG_vidProdCfg();                                     */
/*  input uint8 TUNCFG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Cf_EveTele_TunCfg                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveTele_TunCfg(void)
{
   if (TUNCFG_u8Inhib != 0x5A)
   {
      TUNCFG_vidProdCfg();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlSlow_TunCfg                                          */
/* !Description :  Moniteur lent pour la fonction configuration moteur        */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_024.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TUNCFG_vidTunCfg();                                      */
/*  extf argret void TUNCFG_vidTunCfg1();                                     */
/*  extf argret void TUNCFG_vidSelCfg();                                      */
/*  input uint8 TUNCFG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Cf_SdlSlow_TunCfg                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlSlow_TunCfg(void)
{
   if (TUNCFG_u8Inhib != 0x5A)
   {
      TUNCFG_vidTunCfg();
      TUNCFG_vidTunCfg1();
      TUNCFG_vidSelCfg();
   }
}
/*----------------------------- end of file ----------------------------------*/