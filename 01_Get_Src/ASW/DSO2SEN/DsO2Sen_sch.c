/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DSO2SEN                                                 */
/* !Description     : DSO2SEN Component                                       */
/*                                                                            */
/* !Module          : DSO2SEN                                                 */
/* !Description     : ACQUISITION DE LA SONDE A OXYGENE AVAL                  */
/*                                                                            */
/* !File            : DSO2SEN_SCH.C                                           */
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
/*   1 / SenO2Ds_EveRst_DsLsAcq                                               */
/*   2 / SenO2Ds_SdlLow_DsLsAcq                                               */
/*   3 / SenO2Ds_SdlMid_DsLsAcq                                               */
/*   4 / SenO2Ds_SdlFast_DsLsAcq                                              */
/*   5 / SenO2Ds_EveCrTR_DsLsAcq                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6563982 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/DSO2SEN/DSO2SEN_SCH.C_v           $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DSO2SEN.h"
#include "DSO2SEN_L.h"
#include "DSO2SEN_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_EveRst_DsLsAcq                                     */
/* !Description :  Reset CMM                                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DSO2SEN_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_EveRst_DsLsAcq                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_EveRst_DsLsAcq(void)
{
   DSO2SEN_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_SdlLow_DsLsAcq                                     */
/* !Description :  Moniteur lent pour la fonction sonde aval                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DSO2SEN_vidDiagOCSO2();                                  */
/*  extf argret void DSO2SEN_vidDiagSCGSO2();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input uint8 DSO2SEN_u8Inhib;                                              */
/*  input boolean Ext_bDgoOc_uDsLs;                                           */
/*  input boolean Ext_bMonRunOc_uDsLs;                                        */
/*  input boolean Ext_bMonWaitOc_DsO2Sen;                                     */
/*  input boolean Ext_bDgoScg_uDsLs;                                          */
/*  input boolean Ext_bMonRunScg_uDsLs;                                       */
/*  input boolean Ext_bMonWaitScg_uDsLs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_SdlLow_DsLsAcq                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_SdlLow_DsLsAcq(void)
{
   if (DSO2SEN_u8Inhib != 0x5A)
   {
      DSO2SEN_vidDiagOCSO2();
      DSO2SEN_vidDiagSCGSO2();

      GDGAR_vidGdu(GD_DFT_OC_UDSLS,
                   Ext_bDgoOc_uDsLs,
                   Ext_bMonRunOc_uDsLs,
                   Ext_bMonWaitOc_DsO2Sen);

      GDGAR_vidGdu(GD_DFT_SCG_UDSLS,
                   Ext_bDgoScg_uDsLs,
                   Ext_bMonRunScg_uDsLs,
                   Ext_bMonWaitScg_uDsLs);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_SdlMid_DsLsAcq                                     */
/* !Description :  Moniteur moyen pour la fonction papillon                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DSO2SEN_vidDiagCCSO2();                                  */
/*  extf argret void DSO2SEN_vidRunClefOff();                                 */
/*  extf argret void DSO2SEN_vidMngVoltSO2Extrema();                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input uint8 DSO2SEN_u8Inhib;                                              */
/*  input boolean Ext_bDgoScp_uDsLs;                                          */
/*  input boolean Ext_bMonRunScp_uDsLs;                                       */
/*  input boolean Ext_bMonWaitScp_uDsLs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_SdlMid_DsLsAcq                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_SdlMid_DsLsAcq(void)
{
   if (DSO2SEN_u8Inhib != 0x5A)
   {
      DSO2SEN_vidDiagCCSO2();
      DSO2SEN_vidRunClefOff();
      DSO2SEN_vidMngVoltSO2Extrema();
      GDGAR_vidGdu(GD_DFT_SCP_UDSLS,
                   Ext_bDgoScp_uDsLs,
                   Ext_bMonRunScp_uDsLs,
                   Ext_bMonWaitScp_uDsLs);

   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_SdlFast_DsLsAcq                                    */
/* !Description :  Moniteur rapide pour la fonction sonde aval                */
/* !Number      :  SCH.4                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DSO2SEN_vidAnalogMeasurement();                          */
/*  extf argret void DSO2SEN_vidMngDownStreamSO2();                           */
/*  input uint8 DSO2SEN_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_SdlFast_DsLsAcq                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_SdlFast_DsLsAcq(void)
{
   if (DSO2SEN_u8Inhib != 0x5A)
   {
      DSO2SEN_vidAnalogMeasurement();
      DSO2SEN_vidMngDownStreamSO2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_EveCrTR_DsLsAcq                                    */
/* !Description :  Evénement CRANKING vers RUNNING                            */
/* !Number      :  SCH.5                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DSO2SEN_vidInitDeadZoneCount();                          */
/*  input uint8 DSO2SEN_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_EveCrTR_DsLsAcq                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_EveCrTR_DsLsAcq(void)
{
   if (DSO2SEN_u8Inhib != 0x5A)
   {
      DSO2SEN_vidInitDeadZoneCount();
   }
}
/*-------------------------------- end of file -------------------------------*/