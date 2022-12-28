/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OSCDET                                                  */
/* !Description     : OSCDET Component                                        */
/*                                                                            */
/* !Module          : OSCDET                                                  */
/* !Description     : VERIFICATION DES CONDITIONS DE STABILITE DU POINT DE    */
/*                    FONCTIONNEMENT DU MOTEUR AU RALENTI                     */
/*                                                                            */
/* !File            : OSCDET_SCH.C                                            */
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
/*   1 / EngSt_EveRst_OscDet                                                  */
/*   2 / EngSt_SdlFast_OscDet                                                 */
/*                                                                            */
/* !Reference   : V02 NT 12 00679 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/OSCDET/OSCDET_SCH.C_v             $*/
/* $Revision::   1.1      $$Author::   achebino       $$Date::   06 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   06 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "OSCDET.h"
#include "OSCDET_l.h"
#include "OSCDET_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_OscDet                                        */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OSCDET_vidOscCheckStabilityInit();                       */
/*  extf argret void OSCDET_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_OscDet                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_OscDet(void)
{
   OSCDET_vidOscCheckStabilityInit();
   OSCDET_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_OscDet                                       */
/* !Description :  Moniteur rapide de la fonction démarreur                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OSCDET_vidOscCheckFctCallInit();                         */
/*  extf argret void OSCDET_vidOscChekStabilityPeriod();                      */
/*  extf argret void OSCDET_vidOscChekStabAirLd();                            */
/*  extf argret void OSCDET_vidOscCheckStabIdlSpd();                          */
/*  extf argret void OSCDET_vidOscCheckStabDecision();                        */
/*  input uint8 OSCDET_u8Inhib;                                               */
/*  input boolean EngSt_bAcvOscDetStab;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_OscDet                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_OscDet(void)
{
   if (OSCDET_u8Inhib != 0x5A)
   {
      OSCDET_vidOscCheckFctCallInit();

      if (EngSt_bAcvOscDetStab != 0)
      {
         OSCDET_vidOscChekStabilityPeriod();
         OSCDET_vidOscChekStabAirLd();
         OSCDET_vidOscCheckStabIdlSpd();
         OSCDET_vidOscCheckStabDecision();
      }
   }
}
/************************************* end of file ****************************/