/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TRBWAPMP                                                */
/* !Description     : TRBWAPMP component.                                     */
/*                                                                            */
/* !Module          : TRBWAPMP                                                */
/* !Description     : WATER PUMP COMMAND AND DIAGNOSIS                        */
/*                                                                            */
/* !File            : TRBWAPMP_SCH.C                                          */
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
/*   1 / CoT_EveRst_TrbWaPmp                                                  */
/*   2 / CoT_SdlSlow_TrbWaPmp                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6851428 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TRBWAPMP/TRBWAPMP_SCH.C_v       $*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   20 Oct 2014 $*/
/* $Author::   mbenfrad                               $$Date::   20 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"STD_TYPES.h"
#include"TRBWAPMP.h"
#include"TRBWAPMP_L.h"
#include"TRBWAPMP_IM.h"
#include"VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EveRst_TrbWaPmp                                        */
/* !Description :  Evénement Reset de l'ECU.                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HIND GHORBEL                                               */
/* !Trace_To    :  VEMS_R_11_02775_001.02                                     */
/*                 VEMS_R_11_02775_002.01                                     */
/*                 VEMS_R_11_02775_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TRBWAPMP_vidInit();                                      */
/*  extf argret void TRBWAPMP_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EveRst_TrbWaPmp                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EveRst_TrbWaPmp(void)
{
   TRBWAPMP_vidInit();
   TRBWAPMP_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_SdlSlow_TrbWaPmp                                       */
/* !Description :  Evénement de reception de la trame.                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HIND GHORBEL                                               */
/* !Trace_To    :  VEMS_R_11_02775_001.02                                     */
/*                 VEMS_R_11_02775_002.01                                     */
/*                 VEMS_R_11_02775_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TRBWAPMP_vidTreatment();                                 */
/*  extf argret void TRBWAPMP_vidDiagnosis();                                 */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 TRBWAPMP_u8Inhib;                                             */
/*  input boolean Ctrl_bAcv_TrbCoWaPmp;                                       */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean TrbCoSysHw_bDgoScp_TrbWaPmp;                                */
/*  input boolean TrbCoSysHw_bMonRunScp_TrbWaPmp;                             */
/*  input boolean TrbCoSysHw_bDgoScg_TrbWaPmp;                                */
/*  input boolean TrbCoSysHw_bMonRunScg_TrbWaPmp;                             */
/*  input boolean TrbCoSysHw_bDgoOc_TrbWaPmp;                                 */
/*  input boolean TrbCoSysHw_bMonRunOc_TrbWaPmp;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_SdlSlow_TrbWaPmp                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_SdlSlow_TrbWaPmp(void)
{
   boolean bLocalCtrl_bAcv_TrbCoWaPmp;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalECU_bWkuMain;


   if (TRBWAPMP_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_TrbCoWaPmp, bLocalCtrl_bAcv_TrbCoWaPmp);
      VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      if (  (bLocalCtrl_bAcv_TrbCoWaPmp != 0)
         && (  (bLocalUCE_bPwrlAcv !=0)
            || (bLocalECU_bWkuMain !=0)))
      {
         TRBWAPMP_vidTreatment();
         TRBWAPMP_vidDiagnosis();
         GDGAR_vidGdu(GD_DFT_SCP_TRBWAPMP,
                      TrbCoSysHw_bDgoScp_TrbWaPmp,
                      TrbCoSysHw_bMonRunScp_TrbWaPmp,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCG_TRBWAPMP,
                      TrbCoSysHw_bDgoScg_TrbWaPmp,
                      TrbCoSysHw_bMonRunScg_TrbWaPmp,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_OC_TRBWAPMP,
                      TrbCoSysHw_bDgoOc_TrbWaPmp,
                      TrbCoSysHw_bMonRunOc_TrbWaPmp,
                      DIAG_DISPO);
      }
   }
}
/*-------------------------------- end of file -------------------------------*/