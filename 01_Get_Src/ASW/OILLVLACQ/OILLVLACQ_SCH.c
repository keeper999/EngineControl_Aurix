/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILLVLACQ                                               */
/* !Description     : OILLVLACQ Component                                     */
/*                                                                            */
/* !Module          : OILLVLACQ                                               */
/* !Description     : OIL LEVEL ACQUISITION                                   */
/*                                                                            */
/* !File            : OILLVLACQ_SCH.C                                         */
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
/*   1 / Oil_EveRst_OilLvlAcq                                                 */
/*   2 / Oil_SdlFast_OilLvlAcq                                                */
/*   3 / Oil_EveOilLvl_OilLvlAcq                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6872932 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OILLVLACQ/OILLVLACQ_SCH.C_v     $*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   01 Sep 2014 $*/
/* $Author::   mbenfrad                               $$Date::   01 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"STD_TYPES.h"
#include"OILLVLACQ.h"
#include"OILLVLACQ_L.h"
#include"OILLVLACQ_IM.h"
#include"VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveRst_OilLvlAcq                                       */
/* !Description :  Reset Event                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_11_02972_001.01                                     */
/*                 VEMS_E_11_02972_002.01                                     */
/*                 VEMS_E_11_02972_003.05                                     */
/*                 VEMS_R_11_02972_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILLVLACQ_vidInit();                                     */
/*  extf argret void OILLVLACQ_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Oil_EveRst_OilLvlAcq                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveRst_OilLvlAcq(void)
{
   OILLVLACQ_vidInit();
   OILLVLACQ_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlFast_OilLvlAcq                                      */
/* !Description :  Fast scheduler                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_11_02972_001.01                                     */
/*                 VEMS_E_11_02972_002.01                                     */
/*                 VEMS_E_11_02972_003.05                                     */
/*                 VEMS_R_11_02972_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILLVLACQ_vidAcquisition();                              */
/*  extf argret void OILLVLACQ_vidDiagnosis();                                */
/*  extf argret void OILLVLACQ_vidTreatment();                                */
/*  extf argret void OILLVLACQ_vidSelection();                                */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 OILLVLACQ_u8Inhib;                                            */
/*  input boolean Ctrl_bAcv_uEngOilLvl;                                       */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean Ext_bDgoScg_OilLvlAcq;                                      */
/*  input boolean Ext_bMonRunScg_OilLvlAcq;                                   */
/*  input boolean Ext_bDgoScp_OilLvlAcq;                                      */
/*  input boolean Ext_bMonRunScp_OilLvlAcq;                                   */
/*  input boolean Ext_bDgoGrd_OilLvlAcq;                                      */
/*  input boolean Ext_bMonRunGrd_OilLvlAcq;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Oil_SdlFast_OilLvlAcq                                          */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlFast_OilLvlAcq(void)
{
   boolean bLocalCtrl_bAcv_uEngOilLvl;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalDIAGCAN_bIntegElect;


   if (OILLVLACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_uEngOilLvl, bLocalCtrl_bAcv_uEngOilLvl);
      VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegElect);
      if (  (bLocalCtrl_bAcv_uEngOilLvl != 0)
         && (bLocalDIAGCAN_bIntegElect == 0))
      {
         OILLVLACQ_vidAcquisition();
         VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
         if (bLocalUCE_bPwrlAcv == 0)
         {
            OILLVLACQ_vidDiagnosis();
            OILLVLACQ_vidTreatment();
            OILLVLACQ_vidSelection();
            GDGAR_vidGdu(GD_DFT_SCG_OILLVLACQ,
                        Ext_bDgoScg_OilLvlAcq,
                        Ext_bMonRunScg_OilLvlAcq,
                        DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_SCP_OILLVLACQ,
                        Ext_bDgoScp_OilLvlAcq,
                        Ext_bMonRunScp_OilLvlAcq,
                        DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_GRD_OILLVLACQ,
                        Ext_bDgoGrd_OilLvlAcq,
                        Ext_bMonRunGrd_OilLvlAcq,
                        DIAG_DISPO);
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveOilLvl_OilLvlAcq                                    */
/* !Description :  Event created by LDB to call the API                       */
/*                 OILLVHAL_udtGetConversionResult                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_11_02972_001.01                                     */
/*                 VEMS_E_11_02972_002.01                                     */
/*                 VEMS_E_11_02972_003.05                                     */
/*                 VEMS_R_11_02972_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILLVLACQ_vidAcqBSW();                                   */
/*  input uint8 OILLVLACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Oil_EveOilLvl_OilLvlAcq                                        */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveOilLvl_OilLvlAcq(void)
{
   if (OILLVLACQ_u8Inhib != 0x5A)
   {
      OILLVLACQ_vidAcqBSW();
   }
}
/*-------------------------------- end of file -------------------------------*/