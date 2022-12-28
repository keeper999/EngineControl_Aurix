/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSECUMNG                                              */
/* !Description     : THRSECUMNG component.                                   */
/*                                                                            */
/* !Module          : THRSECUMNG                                              */
/* !Description     : GESTION DES MODES DE SECURITE DU PAPILLON MOTORISE      */
/*                                                                            */
/* !File            : THRSECUMNG_SCH.C                                        */
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
/*   1 / Thr_EveRst_SecuMng                                                   */
/*   2 / Thr_EveClcnServo_SecuMng                                             */
/*   3 / Thr_EveStoreLih_SecuMng                                              */
/*   4 / Thr_EveFRMUpd_SecuMng                                                */
/*                                                                            */
/* !Reference   : V02 NT 08 05135 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRSECUMNG/THRSECUMNG_sch.C_v $*/
/* $Revision::   1.4      $$Author::   acabresp       $$Date::   03 May 2010 $*/
/* $Author::   acabresp                               $$Date::   03 May 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "THRSECUMNG.h"
#include "THRSECUMNG_L.h"
#include "THRSECUMNG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_SecuMng                                         */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSECUMNG_vidSFControlPart();                           */
/*  extf argret void THRSECUMNG_vidSelectThrottlePos();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveRst_SecuMng                                             */
/* !Trigger  : Thr_EveRst_SecuMng                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_SecuMng(void)
{
   THRSECUMNG_vidSFControlPart();
   THRSECUMNG_vidSelectThrottlePos();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_SecuMng                                   */
/* !Description :  Evénement de calcul de l'asservissement papillon motorisé  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSECUMNG_vidSelectThrottlePos();                       */
/*  input uint8 THRSECUMNG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveClcnServo_SecuMng                                       */
/* !Trigger  : Thr_EveClcnServo_SecuMng                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_SecuMng(void)
{
   if (THRSECUMNG_u8Inhib != 0x5A)
   {
      THRSECUMNG_vidSelectThrottlePos();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveStoreLih_SecuMng                                    */
/* !Description :  Demande de mémorisation de la position de repos du papillon*/
/* !Number      :  SCH.3                                                      */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSECUMNG_vidSelectThrotThrusts();                      */
/*  extf argret void THRSECUMNG_vidSelectLimpHome();                          */
/*  input uint8 THRSECUMNG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveStoreLih_SecuMng                                        */
/* !Trigger  : Thr_EveStoreLih_SecuMng                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveStoreLih_SecuMng(void)
{
   if (THRSECUMNG_u8Inhib != 0x5A)
   {
      THRSECUMNG_vidSelectThrotThrusts();
      THRSECUMNG_vidSelectLimpHome();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveFRMUpd_SecuMng                                      */
/* !Description :  Evénement de mise à jour du GAR.                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSECUMNG_vidSFControlPart();                           */
/*  input uint8 THRSECUMNG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveFRMUpd_SecuMng                                          */
/* !Trigger  : Thr_EveFRMUpd_SecuMng                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveFRMUpd_SecuMng(void)
{
   if (THRSECUMNG_u8Inhib != 0x5A)
   {
      THRSECUMNG_vidSFControlPart();
   }
}

/*------------------------------- end of file --------------------------------*/