/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHST                                                   */
/* !Description     : VEHST component.                                        */
/*                                                                            */
/* !Module          : VEHST                                                   */
/* !Description     : ETAT VEHICULE                                           */
/*                                                                            */
/* !File            : VEHST_SCH.C                                             */
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
/*   1 / EngSt_EveRst_VehSt                                                   */
/*   2 / EngSt_SdlFast_VehSt                                                  */
/*   3 / EngSt_SdlMid_VehSt                                                   */
/*   4 / EngSt_EveKOn_VehSt                                                   */
/*   5 / EngSt_EveStTR_VehSt                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5404370 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VEHST/VEHST_SCH.C_v               $*/
/* $Revision::   1.6      $$Author::   hmelloul       $$Date::   16 Jul 2013 $*/
/* $Author::   hmelloul                               $$Date::   16 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "VEHST.H"
#include "VEHST_l.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_VehSt                                         */
/* !Description :  Fonction d'accroche à l'événement Event_reset              */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHST_vidInitStart();                                    */
/*  extf argret void VEHST_vidVehStateControl();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_VehSt                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_VehSt(void)
{
   VEHST_vidInitStart();
   VEHST_vidVehStateControl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_VehSt                                        */
/* !Description :  Focntion d'accroche au moniteur EngSt_SdlFast_VehSt        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHST_vidCompThr();                                      */
/*  extf argret void VEHST_vidVehStateControl();                              */
/*  input uint8 VEHST_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_VehSt                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_VehSt(void)
{
   if (VEHST_u8Inhib != 0x5A)
   {
      VEHST_vidCompThr();
      VEHST_vidVehStateControl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlMid_VehSt                                         */
/* !Description :  Focntion d'accroche au moniteur EngSt_SdlMid_VehSt         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHST_vidStartCondition();                               */
/*  input uint8 VEHST_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlMid_VehSt                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlMid_VehSt(void)
{
   if (VEHST_u8Inhib != 0x5A)
   {
      VEHST_vidStartCondition();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveKOn_VehSt                                         */
/* !Description :  Evenement Key On                                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHST_vidVehStateControl();                              */
/*  input uint8 VEHST_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveKOn_VehSt                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveKOn_VehSt(void)
{
   if (VEHST_u8Inhib != 0x5A)
   {
      VEHST_vidVehStateControl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveStTR_VehSt                                        */
/* !Description :  Evènement Stall-2-Rot                                      */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHST_vidVehStateControl();                              */
/*  input uint8 VEHST_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveStTR_VehSt                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveStTR_VehSt(void)
{
   if (VEHST_u8Inhib != 0x5A)
   {
      VEHST_vidVehStateControl();
   }
}
/*------------------------------- end of file --------------------------------*/