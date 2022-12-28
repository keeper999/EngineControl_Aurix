/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCMD                                                  */
/* !Description     : INJCMD Component                                        */
/*                                                                            */
/* !Module          : INJCMD                                                  */
/* !Description     : INTERFACE COMMANDE INJECTEURS ESSENCE                   */
/*                                                                            */
/* !File            : INJCMD_FCT3.C                                           */
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
/*   1 / INJCMD_vidInitEnable                                                 */
/*   2 / INJCMD_vidInitialisationMode                                         */
/*   3 / INJCMD_vidDisableDriver                                              */
/*   4 / INJCMD_vidInhibitAllCylinder                                         */
/*   5 / INJCMD_vidInitDiag                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_6886136 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJCMD/INJCMD_FCT3.C_v    $*/
/* $Revision::   1.15     $$Author::   mbenfrad       $$Date::   17 Sep 2014 $*/
/* $Author::   mbenfrad                               $$Date::   17 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "INJCMD.h"
#include "INJCMD_L.h"
#include "INJCMD_IM.h"
#include "VEMS.h"
#include "INJCMD_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidInitEnable                                       */
/* !Description :  L’injection sera autorisée si la synchronisation «         */
/*                 imprécise » est validée si le vilebrequin tourne en sens   */
/*                 avant                                                      */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_10_01613_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJHAL_vidEnable(argin uint8 u8InstanceId);              */
/*  extf argret void INJHAL_vidInhibit(uint8 u8InstanceId,                    */
/* INJHAL_tbfInhibitMask bfInhibitMask);                                      */
/*  input boolean Ext_bDirRotCk;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidInitEnable(void)
{
   boolean bLocalExt_bDirRotCk;

   VEMS_vidGET(Ext_bDirRotCk, bLocalExt_bDirRotCk);
   if (bLocalExt_bDirRotCk != 0)
   {
      INJHAL_vidEnable(INS_INJ_GDI);
      INJHAL_vidInhibit(INS_INJ_GDI, INJHAL_bfENABLE_ALL_INJ);
   }
}
/*QAC Warning(2:4700): Complexity Accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidInitialisationMode                               */
/* !Description :  Initialise le mode d’injection (1, 2, 3 ou 4 pulses) , sur */
/*                 l’événement Stall to Crank,                                */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJHAL_vidWriteMode(uint8 u8InstanceId, uint8 u8Channel, */
/*  uint8 u8InjectionMode);                                                   */
/*  input uint8 InjSys_ModeInjection_C;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidInitialisationMode(void)
{
   INJHAL_vidWriteMode(INS_INJ_GDI, INJ_HAL_ALL_CYLINDER,
                       InjSys_ModeInjection_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidDisableDriver                                    */
/* !Description :  Cela permettra sa réactivation au redépart suivant,        */
/*                 l’autorisation étant faite sur le passage des états        */
/*                 véhicule de VS_STALL à VS_CRANKING.                        */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJHAL_vidDisable(argin uint8 u8InstanceId);             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidDisableDriver(void)
{
   INJHAL_vidDisable(INS_INJ_GDI);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidInhibitAllCylinder                               */
/* !Description :  Ce bloc gère la demande de désactivation des injections    */
/*                 séquentielles.                                             */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJHAL_vidInhibit(uint8 u8InstanceId,                    */
/*  INJHAL_tbfInhibitMask bfInhibitMask);                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidInhibitAllCylinder(void)
{
   INJHAL_vidInhibit(INS_INJ_GDI, INJHAL_bfINHIB_ALL_INJ);
}
/*QAC Warning(2:4700): Complexity Accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidInitDiag                                         */
/* !Description :  Toutes les sorties API DGOHAL BSW sont initialisées à 0.   */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dft_oc_Inj1Cmd;                                            */
/*  output boolean Dft_scg_Inj1Cmd;                                           */
/*  output boolean Dft_scw_Inj1Cmd;                                           */
/*  output boolean Dft_ovld_Inj1Cmd;                                          */
/*  output boolean Dena_oc_Inj1Cmd;                                           */
/*  output boolean Dena_scg_Inj1Cmd;                                          */
/*  output boolean Dena_scw_Inj1Cmd;                                          */
/*  output boolean Dena_ovld_Inj1Cmd;                                         */
/*  output boolean Dft_oc_Inj3Cmd;                                            */
/*  output boolean Dft_scg_Inj3Cmd;                                           */
/*  output boolean Dft_scw_Inj3Cmd;                                           */
/*  output boolean Dft_ovld_Inj3Cmd;                                          */
/*  output boolean Dena_oc_Inj3Cmd;                                           */
/*  output boolean Dena_scg_Inj3Cmd;                                          */
/*  output boolean Dena_scw_Inj3Cmd;                                          */
/*  output boolean Dena_ovld_Inj3Cmd;                                         */
/*  output boolean Dft_oc_Inj2Cmd;                                            */
/*  output boolean Dft_scg_Inj2Cmd;                                           */
/*  output boolean Dft_scw_Inj2Cmd;                                           */
/*  output boolean Dft_ovld_Inj2Cmd;                                          */
/*  output boolean Dena_oc_Inj2Cmd;                                           */
/*  output boolean Dena_scg_Inj2Cmd;                                          */
/*  output boolean Dena_scw_Inj2Cmd;                                          */
/*  output boolean Dena_ovld_Inj2Cmd;                                         */
/*  output boolean Dft_oc_Inj4Cmd;                                            */
/*  output boolean Dft_scg_Inj4Cmd;                                           */
/*  output boolean Dft_scw_Inj4Cmd;                                           */
/*  output boolean Dft_ovld_Inj4Cmd;                                          */
/*  output boolean Dena_oc_Inj4Cmd;                                           */
/*  output boolean Dena_scg_Inj4Cmd;                                          */
/*  output boolean Dena_scw_Inj4Cmd;                                          */
/*  output boolean Dena_ovld_Inj4Cmd;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidInitDiag(void)
{
   VEMS_vidSET(Dft_oc_Inj1Cmd, 0);
   VEMS_vidSET(Dft_scg_Inj1Cmd, 0);
   VEMS_vidSET(Dft_scw_Inj1Cmd, 0);
   VEMS_vidSET(Dft_ovld_Inj1Cmd, 0);
   VEMS_vidSET(Dena_oc_Inj1Cmd, 0);
   VEMS_vidSET(Dena_scg_Inj1Cmd, 0);
   VEMS_vidSET(Dena_scw_Inj1Cmd, 0);
   VEMS_vidSET(Dena_ovld_Inj1Cmd, 0);
   VEMS_vidSET(Dft_oc_Inj3Cmd, 0);
   VEMS_vidSET(Dft_scg_Inj3Cmd, 0);
   VEMS_vidSET(Dft_scw_Inj3Cmd, 0);
   VEMS_vidSET(Dft_ovld_Inj3Cmd, 0);
   VEMS_vidSET(Dena_oc_Inj3Cmd, 0);
   VEMS_vidSET(Dena_scg_Inj3Cmd, 0);
   VEMS_vidSET(Dena_scw_Inj3Cmd, 0);
   VEMS_vidSET(Dena_ovld_Inj3Cmd, 0);
   VEMS_vidSET(Dft_oc_Inj2Cmd, 0);
   VEMS_vidSET(Dft_scg_Inj2Cmd, 0);
   VEMS_vidSET(Dft_scw_Inj2Cmd, 0);
   VEMS_vidSET(Dft_ovld_Inj2Cmd, 0);
   VEMS_vidSET(Dena_oc_Inj2Cmd, 0);
   VEMS_vidSET(Dena_scg_Inj2Cmd, 0);
   VEMS_vidSET(Dena_scw_Inj2Cmd, 0);
   VEMS_vidSET(Dena_ovld_Inj2Cmd, 0);
   VEMS_vidSET(Dft_oc_Inj4Cmd, 0);
   VEMS_vidSET(Dft_scg_Inj4Cmd, 0);
   VEMS_vidSET(Dft_scw_Inj4Cmd, 0);
   VEMS_vidSET(Dft_ovld_Inj4Cmd, 0);
   VEMS_vidSET(Dena_oc_Inj4Cmd, 0);
   VEMS_vidSET(Dena_scg_Inj4Cmd, 0);
   VEMS_vidSET(Dena_scw_Inj4Cmd, 0);
   VEMS_vidSET(Dena_ovld_Inj4Cmd, 0);
}

/*------------------------------- end of file --------------------------------*/
