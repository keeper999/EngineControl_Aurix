/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGSTOUTPIDC                                            */
/* !Description     : ENGSTOUTPIDC Component                                  */
/*                                                                            */
/* !Module          : ENGSTOUTPIDC                                            */
/* !Description     : SORTIE FILAIRE MOTEUR TOURNANT                          */
/*                                                                            */
/* !File            : ENGSTOUTPIDC_SCH.C                                      */
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
/*   1 / EngSt_EveRst_EngStOutIdc                                             */
/*   2 / EngSt_SdlFast_EngStOutIdc                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6528229 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ENGSTOUTPIDC/ENGSTOUTPIDC_SCH.C_v $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   22 May 2014 $*/
/* $Author::   wbouach                                $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ENGSTOUTPIDC.h"
#include "ENGSTOUTPIDC_L.h"
#include "ENGSTOUTPIDC_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_EngStOutIdc                                   */
/* !Description :  Fonction d'accroche à l'événement reset du calculateur     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_12_01048_001.01                                     */
/*                 VEMS_E_12_01048_002.01                                     */
/*                 VEMS_E_12_01048_003.01                                     */
/*                 VEMS_E_12_01048_004.01                                     */
/*                 VEMS_E_12_01048_005.01                                     */
/*                 VEMS_E_12_01048_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTOUTPIDC_vidInit();                                  */
/*  extf argret void ENGSTOUTPIDC_vidDiagOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_EngStOutIdc                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_EngStOutIdc(void)
{
   ENGSTOUTPIDC_vidInit();
   ENGSTOUTPIDC_vidDiagOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_EngStOutIdc                                  */
/* !Description :  Fonction d'accroche à l'événement EngSt_SdlFast_EngStOutIdc*/
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_12_01048_001.01                                     */
/*                 VEMS_E_12_01048_002.01                                     */
/*                 VEMS_E_12_01048_003.01                                     */
/*                 VEMS_E_12_01048_004.01                                     */
/*                 VEMS_E_12_01048_005.01                                     */
/*                 VEMS_E_12_01048_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGSTOUTPIDC_vidEngineRunningInfo();                     */
/*  extf argret void ENGSTOUTPIDC_vidDiagOutput();                            */
/*  extf argret void ENGSTOUTPIDC_vidElectricDiag();                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Ctrl_bEngRun;                                               */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input uint8 ENGSTOUTPIDC_u8Inhib;                                         */
/*  input boolean Ext_bDgoScp_EngStOutIdc;                                    */
/*  input boolean Ext_bMonRunScp_EngStOutIdc;                                 */
/*  input boolean Ext_bDgoScg_EngStOutIdc;                                    */
/*  input boolean Ext_bMonRunScg_EngStOutIdc;                                 */
/*  input boolean Ext_bDgoOc_EngStOutIdc;                                     */
/*  input boolean Ext_bMonRunOc_EngStOutIdc;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_EngStOutIdc                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_EngStOutIdc(void)
{
   boolean bLocalCtrl_bEngRun;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalECU_bImmoUnlockWkuSt;


   VEMS_vidGET(Ctrl_bEngRun, bLocalCtrl_bEngRun);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);

   if (ENGSTOUTPIDC_u8Inhib != 0x5A)
   {
      if (  (bLocalCtrl_bEngRun != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalUCE_bPwrlAcv != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0)))
      {
         ENGSTOUTPIDC_vidEngineRunningInfo();
         ENGSTOUTPIDC_vidDiagOutput();
         ENGSTOUTPIDC_vidElectricDiag();
         GDGAR_vidGdu(GD_DFT_SCP_ENGSTOUTIDC,
                      Ext_bDgoScp_EngStOutIdc,
                      Ext_bMonRunScp_EngStOutIdc,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCG_ENGSTOUTIDC,
                      Ext_bDgoScg_EngStOutIdc,
                      Ext_bMonRunScg_EngStOutIdc,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_OC_ENGSTOUTIDC,
                      Ext_bDgoOc_EngStOutIdc,
                      Ext_bMonRunOc_EngStOutIdc,
                      DIAG_DISPO);
      }
   }
}
/*------------------------------- end of file --------------------------------*/