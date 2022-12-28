/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GOBD                                                    */
/* !Description     : GOBD Component                                          */
/*                                                                            */
/* !Module          : GOBD                                                    */
/* !Description     : Gestionnaire OBD                                        */
/*                                                                            */
/* !File            : GOBD_FCT2.C                                             */
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
/*   1 / GOBD_vidAutomate                                                     */
/*   2 / GOBD_bMngAutomateTrans                                               */
/*   3 / GOBD_vidAutomateRstDft                                               */
/*   4 / GOBD_vidAutomateUnval                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5075502 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GOBD/GOBD_FCT2.c_v           $*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   11 Feb 2014 $*/
/* $Author::   mbenfrad                               $$Date::   11 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GOBD.h"
#include "GOBD_L.h"
#include "GOBD_im.h"
#include "GD_A.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidAutomate                                           */
/* !Description :  Function which launchs all steps which are necessary to    */
/*                 update the GDU Manager state.                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GOBD_bMngAutomateTrans(argin uint16 u16IdxDft);      */
/*  extf argret void GOBD_vidExitEveStObd(argin uint16 u16IdxDft);            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidAutomate
(
   uint16 u16IdxDft
)
{
   boolean bLocalEvo;                  /* indicate that the state has changed */

   /* Call function which manage the GDY state transitions */
   bLocalEvo = GOBD_bMngAutomateTrans (u16IdxDft);

   /* If the state has not changed, we execute the action which must be done
   during the state. Else we execute the actions that must be done when we exit
   the state PREC and actions for entry in a state */
   if (FALSE == bLocalEvo)
   {
      /*call traite_during_automate_x(Etat_automate_x);*/
   }
   else
   {
      GOBD_vidExitEveStObd(u16IdxDft);
   }
}/* mettre a jour GOBD_Macro.h si cette fonction evolue*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_bMngAutomateTrans                                     */
/* !Description :  This function manage the transition of GDU manager state.  */
/*                 It returns true if the state has changed.                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidTransOK(argin uint16 u16IdxDft);                 */
/*  extf argret void GOBD_vidTransPending1(argin uint16 u16IdxDft);           */
/*  extf argret void GOBD_vidTransPending2(argin uint16 u16IdxDft);           */
/*  extf argret void GOBD_vidTransEnregistre(argin uint16 u16IdxDft);         */
/*  extf argret void GOBD_vidTransHistoOn(argin uint16 u16IdxDft);            */
/*  extf argret void GOBD_vidTransHistoOff(argin uint16 u16IdxDft);           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input GDFRM_tenuGOBDState GOBD_enustDgo[9];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean GOBD_bMngAutomateTrans
(
   uint16 u16IdxDft
)
{
   GDFRM_tenuGOBDState  enuLocalStDgo;     /* Automate state                  */
   boolean              bLocalRet;         /* Return value                    */

   enuLocalStDgo = GOBD_enustDgo[u16IdxDft];
   bLocalRet = FALSE;

   switch (GOBD_enustDgo[u16IdxDft])
   {
   case GOBD_ETAT_OK:
      GOBD_vidTransOK(u16IdxDft);
      break;
   case GOBD_ETAT_PENDING1:
      GOBD_vidTransPending1(u16IdxDft);
      break;
   case GOBD_ETAT_PENDING2:
      GOBD_vidTransPending2(u16IdxDft);
      break;
   case GOBD_ETAT_ENREGISTRE:
      GOBD_vidTransEnregistre(u16IdxDft);
      break;
   case GOBD_ETAT_HISTORIQUE_ON:
      GOBD_vidTransHistoOn (u16IdxDft);
      break;
   case GOBD_ETAT_HISTORIQUE_OFF:
      GOBD_vidTransHistoOff (u16IdxDft);
      break;

   default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

   /* check that the GDU manager state has changed to return true. Return true
    is equivalent to generate a event which call all the API link to it */
   if(enuLocalStDgo != GOBD_enustDgo[u16IdxDft])
   {
      bLocalRet = TRUE;
   }
   return bLocalRet;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidAutomateRstDft                                     */
/* !Description :  Manage the state change on the event EveRstDft et          */
/*                 RstDftCal.                                                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidAutomateRstDft
(
   uint16 u16IdxDft
)
{
   GOBD_enustDgo[u16IdxDft] =  GOBD_ETAT_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidAutomateUnval                                      */
/* !Description :  Manage the transitions from the event DftUnval.            */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GOBD_vidExitEveStObd(argin uint16 u16IdxDft);            */
/*  input uint8 GD_au8IdxClasObd[9];                                          */
/*  input GDFRM_tenuGOBDState GOBD_enustDgo[9];                               */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidAutomateUnval
(
   uint16 u16IdxDft
)
{
   uint8  u8LocalIdxClasObd;  /* index for OBD class              */

   u8LocalIdxClasObd = GD_au8IdxClasObd[u16IdxDft];

   if((GOBD_enustDgo[u16IdxDft] == GOBD_ETAT_ENREGISTRE)
      &&(GD_astrClasObd[u8LocalIdxClasObd].u8NoHealDC == 0))
   {
      GOBD_enustDgo[u16IdxDft] =  GOBD_ETAT_HISTORIQUE_OFF;
      GOBD_vidExitEveStObd(u16IdxDft);
   }
}
/*------------------------------- end of file --------------------------------*/