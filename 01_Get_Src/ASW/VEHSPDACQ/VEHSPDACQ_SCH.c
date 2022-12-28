/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHSPDACQ                                               */
/* !Description     : VEHSPDACQ Component                                     */
/*                                                                            */
/* !Module          : VEHSPDACQ                                               */
/* !Description     : ACQUISITION DE LA VITESSE VEHICULE FILAIRE              */
/*                                                                            */
/* !File            : VEHSPDACQ_SCH.C                                         */
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
/*   1 / VehSpd_EveRst_AcqVehSpdSen                                           */
/*   2 / VehSpd_EveVSTop_AcqVehSpdSen                                         */
/*   3 / VehSpd_SdlFast_AcqVehSpdSen                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5455394 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VEHSPD/VEHSPDACQ/VEHSPDACQ_SCH.C$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   19 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VEHSPDACQ.h"
#include "VEHSPDACQ_L.h"
#include "VEHSPDACQ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_EveRst_AcqVehSpdSen                                 */
/* !Description :  Reset                                                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidInitOutput();                               */
/*  extf argret void VEHSPDACQ_vidInit();                                     */
/*  extf argret void VEHSPDACQ_vidInitDistance();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_EveRst_AcqVehSpdSen                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_EveRst_AcqVehSpdSen(void)
{
   VEHSPDACQ_vidInitOutput();
   VEHSPDACQ_vidInit();
   VEHSPDACQ_vidInitDistance();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_EveVSTop_AcqVehSpdSen                               */
/* !Description :  Evènement Top notifiant de la détection par le LDB (bloc   */
/*                 SPDHAL) d'une nouvelle impulsion du capteur vitesse        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidAcvEveVSTopCall();                          */
/*  input uint8 VEHSPDACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_EveVSTop_AcqVehSpdSen                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_EveVSTop_AcqVehSpdSen(void)
{
   if (VEHSPDACQ_u8Inhib != 0x5A)
   {
      VEHSPDACQ_vidAcvEveVSTopCall();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_SdlFast_AcqVehSpdSen                                */
/* !Description :  Moniteur rapide de la fonction acquisition vitesse véhicule*/
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidAcvSdlFastCall();                           */
/*  input uint8 VEHSPDACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_SdlFast_AcqVehSpdSen                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_SdlFast_AcqVehSpdSen(void)
{
   if (VEHSPDACQ_u8Inhib != 0x5A)
   {
      VEHSPDACQ_vidAcvSdlFastCall();
   }
}
/*--------------------------------end of file--------------------------------*/
