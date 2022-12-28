/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDU                                                     */
/* !Description     : GDU Component.                                          */
/*                                                                            */
/* !Module          : GDU                                                     */
/* !Description     : SINGLE FAILURE MANAGER                                  */
/*                                                                            */
/* !File            : GDU_FCT3.c                                              */
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
/*   1 / GDU_vidAutomate                                                      */
/*   2 / GDU_bMngAutomateTrans                                                */
/*   3 / GDU_vidMngAutomateEntry                                              */
/*   4 / GDU_vidMngAutomateExit                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5444560 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDU/GDU_FCT3.c_v             $*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   27 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GDU.h"
#include "GDU_L.h"
#include "GDU_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidAutomate                                            */
/* !Description :  Function which launchs all steps which are necessary to    */
/*                 update the GDU Manager state.                              */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDU_bMngAutomateTrans(argin uint16 u16IdxDft);       */
/*  extf argret void GDU_vidMngAutomateExit(argin uint16 u16IdxDft, argin     */
/* GDFRM_tenuGDUState enuStDgo);                                              */
/*  extf argret void GDU_vidMngAutomateEntry(argin uint16 u16IdxDft);         */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidAutomate
(
   uint16 u16IdxDft
)
{
   GDFRM_tenuGDUState enuLocalStDgo;   /* State of GDU manager */
   boolean            bLocalEvo;       /* indicate that the state has changed */

   enuLocalStDgo = GD_astrDftEep[u16IdxDft].enuStDgo;

   /* Call function which manage the GDY state transitions */
   bLocalEvo = GDU_bMngAutomateTrans (u16IdxDft);

   /* If the state has not changed, we execute the action which must be done
   during the state. Else we execute the actions that must be done when we exit
   the state PREC and actions for entry in a state */
   if (FALSE == bLocalEvo)
   {
      /*call traite_during_automate_x(Etat_automate_x);*/
   }
   else
   {
      GDU_vidMngAutomateExit (u16IdxDft, enuLocalStDgo);
      GDU_vidMngAutomateEntry (u16IdxDft);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_bMngAutomateTrans                                      */
/* !Description :  This function manage the transition of GDU manager state.  */
/*                 It returns true if the state has changed.                  */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidTransAbs(argin uint16 u16IdxDft);                 */
/*  extf argret void GDU_vidTransPctlPrst(argin uint16 u16IdxDft);            */
/*  extf argret void GDU_vidTransPctlAbs(argin uint16 u16IdxDft);             */
/*  extf argret void GDU_vidTransPrst(argin uint16 u16IdxDft);                */
/*  extf argret void GDU_vidTransDeval(argin uint16 u16IdxDft);               */
/*  extf argret void GDU_vidTransFugit(argin uint16 u16IdxDft);               */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean GDU_bMngAutomateTrans
(
   uint16 u16IdxDft
)
{  /* local parameter  */
   boolean             bLocalRet;         /* Indicate if state change or not  */
   GDFRM_tenuGDUState  enuLocalStDgo;     /* Automate state */

   /* Initialization */
   enuLocalStDgo = GD_astrDftEep[u16IdxDft].enuStDgo;
   bLocalRet = FALSE;

      switch (enuLocalStDgo)
      {
      case GDU_ETAT_ABSENT:
         GDU_vidTransAbs(u16IdxDft);
         break;

      case GDU_ETAT_PCTL_PRESENT:
         GDU_vidTransPctlPrst(u16IdxDft);
         break;

      case GDU_ETAT_PCTL_ABSENT:
         GDU_vidTransPctlAbs (u16IdxDft);
         break;

      case GDU_ETAT_PRESENT:
         GDU_vidTransPrst (u16IdxDft);
         break;

      case GDU_ETAT_DEVALIDATION:
         GDU_vidTransDeval(u16IdxDft);
         break;

      case GDU_ETAT_FUGITIF:
         GDU_vidTransFugit(u16IdxDft);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
      }
   /* check that the GDU manager state has changed to return true. Return true
    is equivalent to generate a event which call all the API link to it */
   if(enuLocalStDgo != GD_astrDftEep[u16IdxDft].enuStDgo)
   {
      bLocalRet = TRUE;
   }
   return bLocalRet;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngAutomateEntry                                    */
/* !Description :  Manage the action which must be done when the manager enter*/
/*                 in a different state.                                      */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidMngEntryStAbsent(argin uint16 u16IdxDft);         */
/*  extf argret void GDU_vidMngEntryStPresent(argin uint16 u16IdxDft);        */
/*  extf argret void GDU_vidMngEntryStFugitif(argin uint16 u16IdxDft);        */
/*  extf argret void GDU_vidMngEntryStPctlPresent(argin uint16 u16IdxDft);    */
/*  extf argret void GDU_vidMngEntryStPctlAbsent(argin uint16 u16IdxDft);     */
/*  extf argret void GDU_vidMngEntryStDeval(argin uint16 u16DftIdx);          */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngAutomateEntry
(
   uint16 u16IdxDft
)
{
   switch (GD_astrDftEep[u16IdxDft].enuStDgo)
   {
   case GDU_ETAT_ABSENT:
      GDU_vidMngEntryStAbsent(u16IdxDft);
      break;
   case GDU_ETAT_PRESENT:
      GDU_vidMngEntryStPresent(u16IdxDft);
      break;
   case GDU_ETAT_FUGITIF:
      GDU_vidMngEntryStFugitif(u16IdxDft);
      break;
   case GDU_ETAT_PCTL_PRESENT:
      GDU_vidMngEntryStPctlPresent(u16IdxDft);
      break;

   case GDU_ETAT_PCTL_ABSENT:
      GDU_vidMngEntryStPctlAbsent(u16IdxDft);
      break;
   case GDU_ETAT_DEVALIDATION:
      GDU_vidMngEntryStDeval(u16IdxDft);
      break;

   default:
   /* Ce cas n'est jamais atteint car protégé par le cas
      default de GDU_bMngAutomateTrans */
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidMngAutomateExit                                     */
/* !Description :  Manage the action which must be done when the manager leave*/
/*                 in a different state.                                      */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidMngExitStAbsent(argin uint16 u16IdxDft);          */
/*  extf argret void GDU_vidMngExitStPctlAbsent(argin uint16 u16IdxDft);      */
/*  extf argret void GDU_vidMngExitStPctlPresent(argin uint16 u16IdxDft);     */
/*  extf argret void GDU_vidMngExitStPresent(argin uint16 u16IdxDft);         */
/*  extf argret void GDU_vidMngExitStDeval(argin uint16 u16IdxDft);           */
/*  extf argret void GDU_vidMngExitStFugitif(argin uint16 u16IdxDft);         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidMngAutomateExit
(
   uint16 u16IdxDft,
   GDFRM_tenuGDUState enuStDgo
)
{
   switch (enuStDgo)
   {
   case GDU_ETAT_ABSENT:
      GDU_vidMngExitStAbsent(u16IdxDft);
      break;
   case GDU_ETAT_PCTL_ABSENT:
      GDU_vidMngExitStPctlAbsent(u16IdxDft);
      break;
   case GDU_ETAT_PCTL_PRESENT:
      GDU_vidMngExitStPctlPresent(u16IdxDft);
      break;
   case GDU_ETAT_PRESENT:
      GDU_vidMngExitStPresent(u16IdxDft);
      break;
   case GDU_ETAT_DEVALIDATION:
      GDU_vidMngExitStDeval(u16IdxDft);
      break;
   case GDU_ETAT_FUGITIF:
      GDU_vidMngExitStFugitif(u16IdxDft);
      break;
   /*default:
    Ce cas n'est jamais atteint car protégé par le cas
      default de GDU_bMngAutomateTrans
      break;*/
   }
}
/*------------------------------- end of file --------------------------------*/