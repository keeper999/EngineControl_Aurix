/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROPFUPMP                                               */
/* !Description     : PROPFUPMP component.                                    */
/*                                                                            */
/* !Module          : PROPFUPMP                                               */
/* !Description     : PROPORTIONAL FUEL PUMP COMMAND AND DIAGNOSIS            */
/*                                                                            */
/* !File            : PROPFUPMP_SCH.C                                         */
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
/*   1 / FuPmp_EveRst_PropFuPmp                                               */
/*   2 / FuPmp_SdlFast_PropFuPmp                                              */
/*   3 / FuPmp_SdlSlow_PropFuPmp                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6562300 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/PROPFUPMP/PROPFUPMP_SCH.C_v       $*/
/* $Revision::   1.0      $$Author::   hmelloul       $$Date::   02 Jun 2014 $*/
/* $Author::   hmelloul                               $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PROPFUPMP.h"
#include "PROPFUPMP_L.h"
#include "PROPFUPMP_IM.h"
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_EveRst_PropFuPmp                                     */
/* !Description :  ECU Event Reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_001.02                                     */
/*                 VEMS_E_11_03107_008.02                                     */
/*                 VEMS_E_11_03107_009.02                                     */
/*                 VEMS_E_11_03107_012.01                                     */
/*                 VEMS_E_11_03107_013.01                                     */
/*                 VEMS_E_11_03107_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROPFUPMP_vidInit();                                     */
/*  extf argret void PROPFUPMP_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_EveRst_PropFuPmp                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_EveRst_PropFuPmp(void)
{
   PROPFUPMP_vidInit();
   PROPFUPMP_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_SdlFast_PropFuPmp                                    */
/* !Description :  Fast scheduler.                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_001.02                                     */
/*                 VEMS_E_11_03107_008.02                                     */
/*                 VEMS_E_11_03107_009.02                                     */
/*                 VEMS_E_11_03107_012.01                                     */
/*                 VEMS_E_11_03107_013.01                                     */
/*                 VEMS_E_11_03107_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PROPFUPMP_vidCmdPropFuPmp();                             */
/*  extf argret void PROPFUPMP_vidPropFuPmp_DiagHw();                         */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  extf argret void PROPFUPMP_vidCmdPropFuPmpNull();                         */
/*  input boolean Ctrl_bAcv_FuTnkPmp;                                         */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input uint8 PROPFUPMP_u8Inhib;                                            */
/*  input boolean FuPmp_bDgoScg_PropFuPmp;                                    */
/*  input boolean FuPmp_bMonRunScg_PropFuPmp;                                 */
/*  input boolean FuPmp_bDgoScp_PropFuPmp;                                    */
/*  input boolean FuPmp_bMonRunScp_PropFuPmp;                                 */
/*  input boolean FuPmp_bDgoOc_PropFuPmp;                                     */
/*  input boolean FuPmp_bMonRunOc_PropFuPmp;                                  */
/*  output boolean Ctrl_bInhCmd_FuTnkPmp;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_SdlFast_PropFuPmp                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_SdlFast_PropFuPmp(void)
{
   boolean bLocalCtrl_bAcv_FuTnkPmp;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalECU_bImmoUnlockWkuSt;


   VEMS_vidGET(Ctrl_bAcv_FuTnkPmp, bLocalCtrl_bAcv_FuTnkPmp);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
   if (PROPFUPMP_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_FuTnkPmp != 0)
      {
         if (	(bLocalECU_bWkuMain != 0)
            || (bLocalUCE_bPwrlAcv != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0))
         {
            Ctrl_bInhCmd_FuTnkPmp = 0;
            PROPFUPMP_vidCmdPropFuPmp();
            PROPFUPMP_vidPropFuPmp_DiagHw();
            GDGAR_vidGdu(GD_DFT_SCG_PROPFUPMP,
                         FuPmp_bDgoScg_PropFuPmp,
                         FuPmp_bMonRunScg_PropFuPmp,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_SCP_PROPFUPMP,
                         FuPmp_bDgoScp_PropFuPmp,
                         FuPmp_bMonRunScp_PropFuPmp,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_OC_PROPFUPMP,
                         FuPmp_bDgoOc_PropFuPmp,
                         FuPmp_bMonRunOc_PropFuPmp,
                         DIAG_DISPO);
         }
         else
         {
            Ctrl_bInhCmd_FuTnkPmp = 1;
            PROPFUPMP_vidCmdPropFuPmpNull();
         }
      }
      else
      {
         Ctrl_bInhCmd_FuTnkPmp = 1;
         PROPFUPMP_vidCmdPropFuPmpNull();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_SdlSlow_PropFuPmp                                    */
/* !Description :  Moniteur lent de la fonction FuPmp.                        */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_001.02                                     */
/*                 VEMS_E_11_03107_008.02                                     */
/*                 VEMS_E_11_03107_009.02                                     */
/*                 VEMS_E_11_03107_012.01                                     */
/*                 VEMS_E_11_03107_013.01                                     */
/*                 VEMS_E_11_03107_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PROPFUPMP_vidDiagPropFuPmp();                            */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input boolean Ctrl_bAcv_FuTnkPmp;                                         */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input uint8 PROPFUPMP_u8Inhib;                                            */
/*  input boolean FuPmp_bDgoMap_PropFuPmp;                                    */
/*  input boolean FuPmp_bMonRunMap_PropFuPmp;                                 */
/*  input boolean FuPmp_bDgoGravScp_PropFuPmp;                                */
/*  input boolean FuPmp_bMonRunGravScp_PropFuPmp;                             */
/*  input boolean FuPmp_bDgoFrq_PropFuPmp;                                    */
/*  input boolean FuPmp_bMonRunFrq_PropFuPmp;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_SdlSlow_PropFuPmp                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_SdlSlow_PropFuPmp(void)
{
   boolean bLocalCtrl_bAcv_FuTnkPmp;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalECU_bImmoUnlockWkuSt;


   VEMS_vidGET(Ctrl_bAcv_FuTnkPmp, bLocalCtrl_bAcv_FuTnkPmp);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
   if (PROPFUPMP_u8Inhib != 0x5A)
   {
      if (	(bLocalCtrl_bAcv_FuTnkPmp != 0)
         && (	(bLocalECU_bWkuMain != 0)
            || (bLocalUCE_bPwrlAcv != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0)))
      {
         PROPFUPMP_vidDiagPropFuPmp();
         GDGAR_vidGdu(GD_DFT_MAP_PROPFUPMP,
                      FuPmp_bDgoMap_PropFuPmp,
                      FuPmp_bMonRunMap_PropFuPmp,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_GRAVSCP_PROPFUPMP,
                      FuPmp_bDgoGravScp_PropFuPmp,
                      FuPmp_bMonRunGravScp_PropFuPmp,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_FRQ_PROPFUPMP,
                      FuPmp_bDgoFrq_PropFuPmp,
                      FuPmp_bMonRunFrq_PropFuPmp,
                      DIAG_DISPO);
      }
   }
}

/*-------------------------------- end of file -------------------------------*/