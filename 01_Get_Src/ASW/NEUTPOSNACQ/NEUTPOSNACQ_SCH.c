/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : NEUTPOSNACQ                                             */
/* !Description     : NEUTPOSNACQ component.                                  */
/*                                                                            */
/* !Module          : NEUTPOSNACQ                                             */
/* !Description     : ACQUISITION DE LA POSITION POINT MORT                   */
/*                                                                            */
/* !File            : NEUTPOSNACQ_SCH.C                                       */
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
/*   1 / Gear_EveRst_NeutPosnAcq                                              */
/*   2 / Gear_SdlFast_NeutPosnAcq                                             */
/*   3 / NeutPosnAcq_SdlSfty_SftyLvl2                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6533527 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/NEUTPOSNACQ/NEUTPOSNACQ_SCH.C_v   $*/
/* $Revision::   1.6      $$Author::   achebino       $$Date::   27 May 2014 $*/
/* $Author::   achebino                               $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "NEUTPOSNACQ.h"
#include "NEUTPOSNACQ_L.h"
#include "NEUTPOSNACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Gear_EveRst_NeutPosnAcq                                    */
/* !Description :  Evénement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_ 03229_001.01                                    */
/*                 VEMS_R_09_ 03229_002.01                                    */
/*                 VEMS_R_09_ 03229_003.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NEUTPOSNACQ_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Gear_EveRst_NeutPosnAcq                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Gear_EveRst_NeutPosnAcq(void)
{
   NEUTPOSNACQ_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Gear_SdlFast_NeutPosnAcq                                   */
/* !Description :  Moniteur rapide de la fonction Gear                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_ 03229_001.01                                    */
/*                 VEMS_R_09_ 03229_002.01                                    */
/*                 VEMS_R_09_ 03229_003.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NEUTPOSNACQ_vidOS();                                     */
/*  input uint8 NEUTPOSNACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Gear_SdlFast_NeutPosnAcq                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Gear_SdlFast_NeutPosnAcq(void)
{
   if (NEUTPOSNACQ_u8Inhib != 0x5A)
   {
      NEUTPOSNACQ_vidOS();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NeutPosnAcq_SdlSfty_SftyLvl2                               */
/* !Description :  Evènement de calcul des fonctions safety de niveau 2.      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_ 03229_001.01                                    */
/*                 VEMS_R_09_ 03229_002.01                                    */
/*                 VEMS_R_09_ 03229_003.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void NEUTPOSNACQ_vidSafetyLevel2();                           */
/*  input uint8 NEUTPOSNACQ_u8Inhib;                                          */
/*  input boolean Ext_bAcv_NeutPosnAcqSftyLvl2;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : NeutPosnAcq_SdlSfty_SftyLvl2                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NeutPosnAcq_SdlSfty_SftyLvl2(void)
{
   boolean bLocalExt_bAcvNeutPsnAcqSftLv2;


   if (NEUTPOSNACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bAcv_NeutPosnAcqSftyLvl2, bLocalExt_bAcvNeutPsnAcqSftLv2);
      if (bLocalExt_bAcvNeutPsnAcqSftLv2 != 0)
      {
         NEUTPOSNACQ_vidSafetyLevel2();
      }
   }
}

/*---------------------------- end of file -----------------------------------*/