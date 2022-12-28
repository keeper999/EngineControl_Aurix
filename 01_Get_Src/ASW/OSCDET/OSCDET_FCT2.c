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
/* !File            : OSCDET_FCT2.C                                           */
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
/*   1 / OSCDET_vidOscCheckStabDecision                                       */
/*                                                                            */
/* !Reference   : V02 NT 12 00679 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/OSCDET/OSCDET_FCT2.C_v            $*/
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
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OSCDET_vidOscCheckStabDecision                             */
/* !Description :  Ce bloc définit le mode de detection de la stabilité.      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 EngSt_nOscDetMod_C;                                           */
/*  input boolean EngSt_bOscDetAirLdCor;                                      */
/*  input boolean EngSt_bOscDetIdlSpd;                                        */
/*  input boolean EngSt_bOscDetByp_C;                                         */
/*  output boolean EngSt_bOscDetStab;                                         */
/*  output boolean EngSt_bOscDetAirLdCor;                                     */
/*  output boolean EngSt_bOscDetIdlSpd;                                       */
/*  output boolean EngSt_bOscDetByp_C;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OSCDET_vidOscCheckStabDecision(void)
{
   switch (EngSt_nOscDetMod_C)
   {
      case 0:
         if ((EngSt_bOscDetAirLdCor != 0) && (EngSt_bOscDetIdlSpd != 0))
         {
            VEMS_vidSET(EngSt_bOscDetStab, 1);
         }
         else
         {
            VEMS_vidSET(EngSt_bOscDetStab, 0);
         }
         break;

      case 1:
         if ((EngSt_bOscDetAirLdCor != 0) || (EngSt_bOscDetIdlSpd != 0))
         {
            VEMS_vidSET(EngSt_bOscDetStab, 1);
         }
         else
         {
            VEMS_vidSET(EngSt_bOscDetStab, 0);
         }
         break;

      case 2:
         VEMS_vidSET(EngSt_bOscDetStab, EngSt_bOscDetAirLdCor);
         break;

      case 3:
         VEMS_vidSET(EngSt_bOscDetStab, EngSt_bOscDetIdlSpd);
         break;

      case 4:
         VEMS_vidSET(EngSt_bOscDetStab, EngSt_bOscDetByp_C);
         break;

      default:
         VEMS_vidSET(EngSt_bOscDetStab, EngSt_bOscDetByp_C);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/************************************* end of file ****************************/