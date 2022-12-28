/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHSPDDIAG                                              */
/* !Description     : VEHSPDDIAG component                                    */
/*                                                                            */
/* !Module          : VEHSPDDIAG                                              */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA VITESSE VEHICULE           */
/*                                                                            */
/* !File            : VEHSPDDIAG_SCH.C                                        */
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
/*   1 / VehSpd_EveRst_MonVehSpd                                              */
/*   2 / VehSpd_SdlMid_MonVehSpd                                              */
/*   3 / VehSpd_SdlSfty_MonVehSpd                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 01664 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VEHSPDDIAG/VEHSPDDIAG_SCH.C_v   $*/
/* $Revision::   1.0      $$Author::   PBAKABAD       $$Date::   04 Oct 2011 $*/
/* $Author::   PBAKABAD                               $$Date::   04 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VEHSPDDIAG.h"
#include "VEHSPDDIAG_L.h"
#include "VEHSPDDIAG_IM.h"
#include "LIBSFTYLVL2.h"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_EveRst_MonVehSpd                                    */
/* !Description :  Evènement reset de l'ECU.                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  GHADDAB                                                    */
/* !Trace_To    :  VEMS_R_09_ 01664_001.01                                    */
/*                 VEMS_R_09_ 01664_003.01                                    */
/*                 VEMS_R_09_ 01664_002.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDDIAG_vidInit();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_EveRst_MonVehSpd                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_EveRst_MonVehSpd(void)
{
   VEHSPDDIAG_vidInit();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_SdlMid_MonVehSpd                                    */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  GHADDAB                                                    */
/* !Trace_To    :  VEMS_R_09_ 01664_001.01                                    */
/*                 VEMS_R_09_ 01664_002.01                                    */
/*                 VEMS_R_09_ 01664_003.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDDIAG_vidConsistency_Test();                        */
/*  extf argret void VEHSPDDIAG_vidMaxValueTested();                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VEHSPDDIAG_u8Inhib;                                           */
/*  input boolean VehSpd_bDgoCoh_spdVeh;                                      */
/*  input boolean VehSpd_bMonRunCoh_spdVeh;                                   */
/*  input boolean VehSpd_bDgoORng_spdVeh;                                     */
/*  input boolean VehSpd_bMonRunORng_spdVeh;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_SdlMid_MonVehSpd                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_SdlMid_MonVehSpd(void)
{
   if (VEHSPDDIAG_u8Inhib != 0x5A)
   {
      VEHSPDDIAG_vidConsistency_Test();
      VEHSPDDIAG_vidMaxValueTested();
      GDGAR_vidGdu(GD_DFT_COH_SPDVEH,
                   VehSpd_bDgoCoh_spdVeh,
                   VehSpd_bMonRunCoh_spdVeh,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_SPDVEH,
                   VehSpd_bDgoORng_spdVeh,
                   VehSpd_bMonRunORng_spdVeh,
                   DIAG_DISPO);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_SdlSfty_MonVehSpd                                   */
/* !Description :  Evènement de calcul des fonctions safety de niveau 2.      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  GHADDAB                                                    */
/* !Trace_To    :  VEMS_R_09_ 01664_001.01                                    */
/*                 VEMS_R_09_ 01664_002.01                                    */
/*                 VEMS_R_09_ 01664_003.01                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHSPDDIAG_vidSafetyLev2();                              */
/*  input boolean Ext_bAcv_VehSpdSftyLvl2;                                    */
/*  input uint8 VEHSPDDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_SdlSfty_MonVehSpd                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_SdlSfty_MonVehSpd(void)
{
   boolean bLocalExt_bAcv_VehSpdSftyLvl2;


   VEMS_vidGET(Ext_bAcv_VehSpdSftyLvl2, bLocalExt_bAcv_VehSpdSftyLvl2);

   if (VEHSPDDIAG_u8Inhib != 0x5A)
   {
      if (bLocalExt_bAcv_VehSpdSftyLvl2!= 0)
      {
         VEHSPDDIAG_vidSafetyLev2();
      }
   }
}
/*--------------------------- end of file ----------------------------------*/
