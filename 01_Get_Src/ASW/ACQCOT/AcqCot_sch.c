/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQCOT                                                  */
/* !Description     : ACQCOT Component                                        */
/*                                                                            */
/* !Module          : ACQCOT                                                  */
/* !Description     : ACQUISITION DE LA TEMPERATURE D’EAU                     */
/*                                                                            */
/* !File            : ACQCOT_SCH.C                                            */
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
/*   1 / CoT_EveRst_AcqCoT                                                    */
/*   2 / CoT_SdlMid_AcqCoT                                                    */
/*   3 / CoT_EveCrTR_AcqCoT                                                   */
/*   4 / CoT_EveStTR_AcqCoT                                                   */
/*   5 / CoT_SdlSlow_AcqCoT                                                   */
/*   6 / CoT_EvePwrl_AcqCoT                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_6529851 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACQCOT/ACQCOT_SCH.c_v             $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACQCOT.h"
#include "ACQCOT_L.h"
#include "ACQCOT_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EveRst_AcqCoT                                          */
/* !Description :  Evènement reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCOT_vidInitTemperature();                             */
/*  extf argret void ACQCOT_vidWaterTempAcquisition();                        */
/*  extf argret void ACQCOT_vidInitialization();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EveRst_AcqCoT                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EveRst_AcqCoT(void)
{
   ACQCOT_vidInitTemperature();
   ACQCOT_vidWaterTempAcquisition();
   ACQCOT_vidInitialization();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_SdlMid_AcqCoT                                          */
/* !Description :  Moniteur moyen pour la fonction acquisition température    */
/*                 d'eau.                                                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCOT_vidWaterTempAcquisition();                        */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean  bDgo, boolean    */
/* bMonRun,   boolean  bDiagStWait);                                          */
/*  extf argret void ACQCOT_vidWaterTempTreatment();                          */
/*  input uint8 ACQCOT_u8Inhib;                                               */
/*  input boolean Ext_bDgoScp_tCoMes;                                         */
/*  input boolean Ext_bMonRunScp_tCoMes;                                      */
/*  input boolean Ext_bDgoOc_tCoMes;                                          */
/*  input boolean Ext_bMonRunOc_tCoMes;                                       */
/*  input boolean Ext_bDgoScg_tCoMes;                                         */
/*  input boolean Ext_bMonRunScg_tCoMes;                                      */
/*  input boolean Ext_bDgoGrd_tCoMes;                                         */
/*  input boolean Ext_bMonRunGrd_tCoMes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_SdlMid_AcqCoT                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_SdlMid_AcqCoT(void)
{
   if (ACQCOT_u8Inhib != 0x5A)
   {
      ACQCOT_vidWaterTempAcquisition();
      GDGAR_vidGdu(GD_DFT_SCP_TCOMES,
                   Ext_bDgoScp_tCoMes,
                   Ext_bMonRunScp_tCoMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_TCOMES,
                   Ext_bDgoOc_tCoMes,
                   Ext_bMonRunOc_tCoMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_TCOMES,
                   Ext_bDgoScg_tCoMes,
                   Ext_bMonRunScg_tCoMes,
                   DIAG_DISPO);
      ACQCOT_vidWaterTempTreatment();
      GDGAR_vidGdu(GD_DFT_GRD_TCOMES,
                   Ext_bDgoGrd_tCoMes,
                   Ext_bMonRunGrd_tCoMes,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EveCrTR_AcqCoT                                         */
/* !Description :  Evènement cranking vers running.                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCOT_vidCrTRunWaterTemp();                             */
/*  input uint8 ACQCOT_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EveCrTR_AcqCoT                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EveCrTR_AcqCoT(void)
{
   if (ACQCOT_u8Inhib != 0x5A)
   {
      ACQCOT_vidCrTRunWaterTemp();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EveStTR_AcqCoT                                         */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCOT_vidStallWaterTemp();                              */
/*  input uint8 ACQCOT_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EveStTR_AcqCoT                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EveStTR_AcqCoT(void)
{
   if (ACQCOT_u8Inhib != 0x5A)
   {
      ACQCOT_vidStallWaterTemp();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_SdlSlow_AcqCoT                                         */
/* !Description :  Moniteur lent                                              */
/* !Number      :  SCH.5                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCOT_vidRunWaterTemp();                                */
/*  input uint8 ACQCOT_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_SdlSlow_AcqCoT                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_SdlSlow_AcqCoT(void)
{
   if (ACQCOT_u8Inhib != 0x5A)
   {
      ACQCOT_vidRunWaterTemp();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EvePwrl_AcqCoT                                         */
/* !Description :  Evènement Powerlatch pour la fonction CoT                  */
/* !Number      :  SCH.6                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03873_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCOT_vidStoragetCoPwrl();                              */
/*  input uint8 ACQCOT_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EvePwrl_AcqCoT                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EvePwrl_AcqCoT(void)
{
   if (ACQCOT_u8Inhib != 0x5A)
   {
      ACQCOT_vidStoragetCoPwrl();
   }
}
/*------------------------------- end of file --------------------------------*/