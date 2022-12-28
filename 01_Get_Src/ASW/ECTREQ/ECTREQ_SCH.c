/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ECTREQ                                                  */
/* !Description     : ECTREQ Component                                        */
/*                                                                            */
/* !Module          : ECTREQ                                                  */
/* !Description     : Electronically Controlled Thermostat command and        */
/*                    diagnosis                                               */
/*                                                                            */
/* !File            : ECTREQ_SCH.C                                            */
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
/*   1 / CoFan_EveRst_ECTReq                                                  */
/*   2 / CoFan_SdlSlow_ECTReq                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6886129 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ECTREQ/ECTREQ_SCH.C_v             $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ECTREQ.h"
#include "ECTREQ_L.h"
#include "ECTREQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_EveRst_ECTReq                                        */
/* !Description :  Evénement Reset de l'ECU.                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_06350_001.01                                     */
/*                 VEMS_E_11_06350_002.01                                     */
/*                 VEMS_E_11_06350_003.01                                     */
/*                 VEMS_E_11_06350_004.01                                     */
/*                 VEMS_E_11_06350_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ECTREQ_vidInitOutput();                                  */
/*  extf argret void ECTREQ_vidInitialization();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_EveRst_ECTReq                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_EveRst_ECTReq(void)
{
   ECTREQ_vidInitOutput();
   ECTREQ_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlSlow_ECTReq                                       */
/* !Description :  Control flow for the ECT                                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_06350_001.01                                     */
/*                 VEMS_E_11_06350_002.01                                     */
/*                 VEMS_E_11_06350_003.01                                     */
/*                 VEMS_E_11_06350_004.01                                     */
/*                 VEMS_E_11_06350_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ECTREQ_vidTreatment();                                   */
/*  extf argret void ECTREQ_vidDiagnosis();                                   */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 ECTREQ_u8Inhib;                                               */
/*  input boolean Ctrl_bAcv_ECTReq;                                           */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean CoFan_bDgoScp_ECTReq;                                       */
/*  input boolean CoFan_bMonRunScp_ECTReq;                                    */
/*  input boolean CoFan_bDgoScg_ECTReq;                                       */
/*  input boolean CoFan_bMonRunScg_ECTReq;                                    */
/*  input boolean CoFan_bDgoOc_ECTReq;                                        */
/*  input boolean CoFan_bMonRunOc_ECTReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlSlow_ECTReq                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlSlow_ECTReq(void)
{
   boolean   bLocalCtrl_bAcv_ECTReq;
   boolean   bLocalECU_bWkuMain;


   if (ECTREQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_ECTReq, bLocalCtrl_bAcv_ECTReq);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

      if (  (bLocalCtrl_bAcv_ECTReq != 0)
         && (bLocalECU_bWkuMain != 0))
      {
         ECTREQ_vidTreatment();
         ECTREQ_vidDiagnosis();
         GDGAR_vidGdu(GD_DFT_SCP_ECTREQ,
                      CoFan_bDgoScp_ECTReq,
                      CoFan_bMonRunScp_ECTReq,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_SCG_ECTREQ,
                      CoFan_bDgoScg_ECTReq,
                      CoFan_bMonRunScg_ECTReq,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_OC_ECTREQ,
                      CoFan_bDgoOc_ECTReq,
                      CoFan_bMonRunOc_ECTReq,
                      DIAG_DISPO);
      }
   }
}
/*-------------------------------- end of file -------------------------------*/