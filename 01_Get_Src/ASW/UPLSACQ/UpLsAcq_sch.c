/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : UPLSACQ                                                 */
/* !Description     : UPLSACQ component.                                      */
/*                                                                            */
/* !Module          : UPLSACQ                                                 */
/* !Description     : ACQUISITION DE LA SONDE A OXYGENE AMONT                 */
/*                                                                            */
/* !File            : UPLSACQ_sch.C                                           */
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
/*   1 / SenO2Us_EveRst_UpLsAcq                                               */
/*   2 / SenO2Us_EveCrTR_UpLsAcq                                              */
/*   3 / SenO2Us_EveTDC_UpLsAcq                                               */
/*   4 / SenO2Us_SdlFast_UpLsAcq                                              */
/*   5 / SenO2Us_SdlMid_UpLsAcq                                               */
/*   6 / SenO2Us_SdlSlow_UpLsAcq                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6562315 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/UPLSACQ/UPLSACQ_SCH.c_v           $*/
/* $Revision::   1.7      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "UPLSACQ.H"
#include "UPLSACQ_L.H"
#include "UPLSACQ_IM.H"
#include "GDGAR.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_EveRst_UpLsAcq                                     */
/* !Description :  Fonction d'accroche moniteur à l'evenement                 */
/*                 SenO2Us_EveRst_UpLsAcq                                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_001.01                                     */
/*                 VEMS_R_08_04819_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void UPLSACQ_vidInitOutput();                                 */
/*  extf argret void UPLSACQ_vidSenO2UsInitialization();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_EveRst_UpLsAcq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_EveRst_UpLsAcq(void)
{
   UPLSACQ_vidInitOutput();
   UPLSACQ_vidSenO2UsInitialization();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_EveCrTR_UpLsAcq                                    */
/* !Description :  Fonction d'accroche moniteur à l'evenement                 */
/*                 SenO2Us_EveCrTR_UpLsAcq                                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_001.01                                     */
/*                 VEMS_R_08_04819_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void UPLSACQ_vidInitDeadZoneCount();                          */
/*  input uint8 UPLSACQ_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_EveCrTR_UpLsAcq                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_EveCrTR_UpLsAcq(void)
{
   if (UPLSACQ_u8Inhib != 0x5A)
   {
      UPLSACQ_vidInitDeadZoneCount();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_EveTDC_UpLsAcq                                     */
/* !Description :  Fonction d'accroche moniteur à l'evenement                 */
/*                 SenO2Us_EveTDC_UpLsAcq                                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_007.01                                     */
/*                 VEMS_R_08_04819_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void UPLSACQ_vidSenO2UsFiltSyncEngine();                      */
/*  input uint8 UPLSACQ_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_EveTDC_UpLsAcq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_EveTDC_UpLsAcq(void)
{
   if (UPLSACQ_u8Inhib != 0x5A)
   {
      UPLSACQ_vidSenO2UsFiltSyncEngine();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_SdlFast_UpLsAcq                                    */
/* !Description :  Fonction d'accroche moniteur à l'evenement                 */
/*                 SenO2Us_SdlFast_UpLsAcq                                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_001.01                                     */
/*                 VEMS_R_08_04819_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void UPLSACQ_vidSenO2UsAcquiTreatment();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  extf argret void UPLSACQ_vidSenO2UsFiltStallEng();                        */
/*  extf argret void UPLSACQ_vidRunKeyOff();                                  */
/*  input uint8 UPLSACQ_u8Inhib;                                              */
/*  input boolean Ext_bDgoScp_uUpLs;                                          */
/*  input boolean Ext_bMonRunScp_uUpLs;                                       */
/*  input boolean Ext_bMonWaitScp_uUpLs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_SdlFast_UpLsAcq                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_SdlFast_UpLsAcq(void)
{
   if (UPLSACQ_u8Inhib != 0x5A)
   {
      UPLSACQ_vidSenO2UsAcquiTreatment();
      GDGAR_vidGdu(GD_DFT_SCP_UUPLS,
                 Ext_bDgoScp_uUpLs,
                 Ext_bMonRunScp_uUpLs,
                 Ext_bMonWaitScp_uUpLs);
      UPLSACQ_vidSenO2UsFiltStallEng();
      UPLSACQ_vidRunKeyOff();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_SdlMid_UpLsAcq                                     */
/* !Description :  Fonction d'accroche moniteur à l'evenement                 */
/*                 SenO2Us_SdlMid_UpLsAcq                                     */
/* !Number      :  SCH.5                                                      */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_007.01                                     */
/*                 VEMS_R_08_04819_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void UPLSACQ_vidSenO2UsDefaultMngt();                         */
/*  extf argret void UPLSACQ_vidSenO2UsDiagGroundMngt();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input uint8 UPLSACQ_u8Inhib;                                              */
/*  input boolean Ext_bDgoOc_uUpLs;                                           */
/*  input boolean Ext_bMonRunOc_uUpLs;                                        */
/*  input boolean Ext_bMonWaitOc_uUpLs;                                       */
/*  input boolean Ext_bDgoScg_uUpLs;                                          */
/*  input boolean Ext_bMonRunScg_uUpLs;                                       */
/*  input boolean Ext_bMonWaitScg_uUpLs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_SdlMid_UpLsAcq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_SdlMid_UpLsAcq(void)
{
   if (UPLSACQ_u8Inhib != 0x5A)
   {
      UPLSACQ_vidSenO2UsDefaultMngt ();
      UPLSACQ_vidSenO2UsDiagGroundMngt();
      GDGAR_vidGdu(GD_DFT_OC_UUPLS,
                 Ext_bDgoOc_uUpLs,
                 Ext_bMonRunOc_uUpLs,
                 Ext_bMonWaitOc_uUpLs);
      GDGAR_vidGdu(GD_DFT_SCG_UUPLS,
                 Ext_bDgoScg_uUpLs,
                 Ext_bMonRunScg_uUpLs,
                 Ext_bMonWaitScg_uUpLs);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_SdlSlow_UpLsAcq                                    */
/* !Description :  Fonction d'accroche moniteur à l'evenement                 */
/*                 SenO2Us_SdlSlow_UpLsAcq                                    */
/* !Number      :  SCH.6                                                      */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_001.01                                     */
/*                 VEMS_R_08_04819_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void UPLSACQ_vidSO2UsDefaultCountDec();                       */
/*  input uint8 UPLSACQ_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_SdlSlow_UpLsAcq                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_SdlSlow_UpLsAcq(void)
{
   if (UPLSACQ_u8Inhib != 0x5A)
   {
      UPLSACQ_vidSO2UsDefaultCountDec();
   }
}

/*------------------------------- END OF FILE --------------------------------*/