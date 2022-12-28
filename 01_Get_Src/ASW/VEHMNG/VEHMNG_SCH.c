/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHMNG                                                  */
/* !Description     : VEHMNG component                                        */
/*                                                                            */
/* !Module          : VEHMNG                                                  */
/* !Description     : Gestion de la vitesse véhicule                          */
/*                                                                            */
/* !File            : VEHMNG_SCH.C                                            */
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
/*   1 / VehSpd_EveRst_VehMng                                                 */
/*   2 / VehSpd_SdlFast_VehMng                                                */
/*   3 / VehSpd_SdlMid_VehMng                                                 */
/*                                                                            */
/* !Reference   : V02 NT 08 05610 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/VEHMNG/VEHMNG_SCH.C_v             $*/
/* $Revision::   1.14     $$Author::   achebino       $$Date::   05 Oct 2012 $*/
/* $Author::   achebino                               $$Date::   05 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "VEHMNG.H"
#include "VEHMNG_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_EveRst_VehMng                                       */
/* !Description :  Evénement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05610_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHMNG_vidVehSdpMngInit();                               */
/*  extf argret void VEHMNG_vidVehSpdInformation();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_EveRst_VehMng                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_EveRst_VehMng(void)
{
   VEHMNG_vidVehSdpMngInit();
   VEHMNG_vidVehSpdInformation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_SdlFast_VehMng                                      */
/* !Description :  Moniteur rapide de la fonction VehSpd.                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05610_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHMNG_vidVehSpdMngCanCmm();                             */
/*  extf argret void VEHMNG_vidClcDistTraveledViaCAN();                       */
/*  extf argret void VEHMNG_vidClcDistTraveledViaWire();                      */
/*  extf argret void VEHMNG_vidVehDstClcMng();                                */
/*  input uint8 VEHMNG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_SdlFast_VehMng                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_SdlFast_VehMng(void)
{
   if (VEHMNG_u8Inhib != 0x5A)
   {
      VEHMNG_vidVehSpdMngCanCmm();
      VEHMNG_vidClcDistTraveledViaCAN();
      VEHMNG_vidClcDistTraveledViaWire();
      VEHMNG_vidVehDstClcMng();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_SdlMid_VehMng                                       */
/* !Description :  Moniteur moyen de la fonction VehSpd.                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05610_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHMNG_vidVehicleSpeedFiltered();                        */
/*  input uint8 VEHMNG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_SdlMid_VehMng                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_SdlMid_VehMng(void)
{
   if (VEHMNG_u8Inhib != 0x5A)
   {
      VEHMNG_vidVehicleSpeedFiltered();
   }
}
/*---------------------------------end of file--------------------------------*/