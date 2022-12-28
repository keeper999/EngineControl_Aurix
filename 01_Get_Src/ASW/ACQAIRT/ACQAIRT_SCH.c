/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQAIRT                                                 */
/* !Description     : ACQAIRT component                                       */
/*                                                                            */
/* !Module          : ACQAIRT                                                 */
/* !Description     : MESURE DE LA TEMPERATURE D’AIR                          */
/*                                                                            */
/* !File            : ACQAIRT_SCH.C                                           */
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
/*   1 / AirT_EveRst_AcqAirT                                                  */
/*   2 / AirT_SdlMid_AcqAirT                                                  */
/*   3 / AirT_EveCrTR_AcqAirT                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6535285 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACQAIRT/ACQAIRT_SCH.c_v           $*/
/* $Revision::   1.11                                                        $*/
/* $Author::   achebino                               $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"STD_TYPES.h"
#include"ACQAIRT.h"
#include"ACQAIRT_L.h"
#include"ACQAIRT_IM.h"
#include"GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_EveRst_AcqAirT                                        */
/* !Description :  fonction d'accroche moniteur a l'evenement                 */
/*                 AirT_EveRst_AcqAirT.                                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_03872_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQAIRT_vidInitOutput();                                 */
/*  extf argret void ACQAIRT_vidAirTemperatureAcqui();                        */
/*  extf argret void ACQAIRT_vidResetAirIntakeTemp();                         */
/*  extf argret void ACQAIRT_vidThrMesTempAir();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_EveRst_AcqAirT                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_EveRst_AcqAirT(void)
{
   ACQAIRT_vidInitOutput();
   ACQAIRT_vidAirTemperatureAcqui();
   ACQAIRT_vidResetAirIntakeTemp();
   ACQAIRT_vidThrMesTempAir();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_SdlMid_AcqAirT                                        */
/* !Description :  Fonction d'accroche moniteur a l'evenement                 */
/*                 AirT_SdlMid_AcqAirT                                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_03872_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQAIRT_vidAirTemperatureAcqui();                        */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait) ;                                            */
/*  extf argret void ACQAIRT_vidFunctionalDiagnosis();                        */
/*  extf argret void ACQAIRT_vidAirTemperatureMeas();                         */
/*  input uint8 ACQAIRT_u8Inhib;                                              */
/*  input boolean Ext_bDgoScp_tAirMes;                                        */
/*  input boolean Ext_bMonRunScp_tAirMes;                                     */
/*  input boolean Ext_bDgoOc_tAirMes;                                         */
/*  input boolean Ext_bMonRunOc_tAirMes;                                      */
/*  input boolean Ext_bDgoScg_tAirMes;                                        */
/*  input boolean Ext_bMonRunScg_tAirMes;                                     */
/*  input boolean Ext_bDgoGrd_tAirMes;                                        */
/*  input boolean Ext_bMonRunGrd_tAirMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_SdlMid_AcqAirT                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_SdlMid_AcqAirT(void)
{
   if (ACQAIRT_u8Inhib != 0x5A)
   {
      ACQAIRT_vidAirTemperatureAcqui();
      GDGAR_vidGdu(GD_DFT_SCP_TAIRMES,
                   Ext_bDgoScp_tAirMes,
                   Ext_bMonRunScp_tAirMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_TAIRMES,
                   Ext_bDgoOc_tAirMes,
                   Ext_bMonRunOc_tAirMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_TAIRMES,
                   Ext_bDgoScg_tAirMes,
                   Ext_bMonRunScg_tAirMes,
                   DIAG_DISPO);
      ACQAIRT_vidFunctionalDiagnosis();
      GDGAR_vidGdu(GD_DFT_GRD_TAIRMES,
                   Ext_bDgoGrd_tAirMes,
                   Ext_bMonRunGrd_tAirMes,
                   DIAG_DISPO);
      ACQAIRT_vidAirTemperatureMeas();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_EveCrTR_AcqAirT                                       */
/* !Description :  Evénement CRANKING vers RUNNING                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_03872_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQAIRT_vidThrMesTempAir();                              */
/*  input uint8 ACQAIRT_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_EveCrTR_AcqAirT                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_EveCrTR_AcqAirT(void)
{
   if (ACQAIRT_u8Inhib != 0x5A)
   {
      ACQAIRT_vidThrMesTempAir();
   }
}
/*-------------------------------- end of file -------------------------------*/