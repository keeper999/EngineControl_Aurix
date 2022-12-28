/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CRSCTLBSITREAT                                          */
/* !Description     : CRSCTLBSITREAT Component                                */
/*                                                                            */
/* !Module          : CRSCTLBSITREAT                                          */
/* !Description     : TRAITEMENT DES INFORMATIONS BSI POUR LES BESOINS DE LA  */
/*                    XVV                                                     */
/*                                                                            */
/* !File            : CRSCTLBSITREAT_SCH.C                                    */
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
/*   1 / CrsCtl_EveRst_CrsCtlBsiTreat                                         */
/*   2 / CrsCtl_EveRxn50E_CrsCtlBsiTreat                                      */
/*   3 / CrsCtl_SdlSlow_CrsCtlBsiTreat                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5206188 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CRSCTL/CRSCTLBSITREAT/CRSCTLBSIT$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   19 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CRSCTLBSITREAT.h"
#include "CRSCTLBSITREAT_L.h"
#include "CRSCTLBSITREAT_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrsCtl_EveRst_CrsCtlBsiTreat                               */
/* !Description :  Evènement reset de l'ECU                                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_E_11_06467_001.01                                     */
/*                 VEMS_E_11_06467_002.01                                     */
/*                 VEMS_E_11_06467_003.01                                     */
/*                 VEMS_R_11_06467_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLBSITREAT_vidInit();                                */
/*  extf argret void CRSCTLBSITREAT_vidNVRAMmanagemnt();                      */
/*  extf argret void CRSCTLBSITREAT_vidDiag_2();                              */
/*  extf argret void CRSCTLBSITREAT_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrsCtl_EveRst_CrsCtlBsiTreat                                   */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrsCtl_EveRst_CrsCtlBsiTreat(void)
{
   CRSCTLBSITREAT_vidInit();
   CRSCTLBSITREAT_vidNVRAMmanagemnt();
   CRSCTLBSITREAT_vidDiag_2();
   CRSCTLBSITREAT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrsCtl_EveRxn50E_CrsCtlBsiTreat                            */
/* !Description :  Evènement de réception de la trame 50E                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_E_11_06467_001.01                                     */
/*                 VEMS_E_11_06467_002.01                                     */
/*                 VEMS_E_11_06467_003.01                                     */
/*                 VEMS_R_11_06467_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLBSITREAT_vidDiag_1();                              */
/*  extf argret void CRSCTLBSITREAT_vidNVRAMmanagemnt();                      */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 CRSCTLBSITREAT_u8Inhib;                                       */
/*  input boolean VSCtl_bDgoElInfBsiDft;                                      */
/*  input boolean VSCtl_bMonRunElDft;                                         */
/*  input boolean VSCtl_bDgoElCptTraBsiDft;                                   */
/*  input boolean VSCtl_bDgoElChkConsDft;                                     */
/*  input boolean VSCtl_bDgoElConsDefDftVSLim;                                */
/*  input boolean VSCtl_bDgoElConsVarDftVSLim;                                */
/*  input boolean VSCtl_bDgoElConsDefDftVSReg;                                */
/*  input boolean VSCtl_bDgoElConsVarDftVSReg;                                */
/*  input boolean VSCtl_bDgoElConsInitDftVSReg;                               */
/*  input boolean VSCtl_bDgoElDftCrsCtl;                                      */
/*  input boolean VSCtl_bDgoZeroFrameCntDft;                                  */
/*  input boolean VSCtl_bDgoEvenFrameCntDft;                                  */
/*  input boolean VSCtl_bDgoElFrameCntIncDft;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrsCtl_EveRxn50E_CrsCtlBsiTreat                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrsCtl_EveRxn50E_CrsCtlBsiTreat(void)
{
   if (CRSCTLBSITREAT_u8Inhib != 0x5A)
   {
      CRSCTLBSITREAT_vidDiag_1();
      CRSCTLBSITREAT_vidNVRAMmanagemnt();

      GDGAR_vidGdu(GD_DFT_ELINFBSIDFT,
                   VSCtl_bDgoElInfBsiDft,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELCPTTRABSIDFT,
                   VSCtl_bDgoElCptTraBsiDft,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELCHKCONSDFT,
                   VSCtl_bDgoElChkConsDft,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELCONSDEFDFTVSLIM,
                   VSCtl_bDgoElConsDefDftVSLim,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELCONSVARDFTVSLIM,
                   VSCtl_bDgoElConsVarDftVSLim,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELCONSDEFDFTVSREG,
                   VSCtl_bDgoElConsDefDftVSReg,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELCONSVARDFTVSREG,
                   VSCtl_bDgoElConsVarDftVSReg,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELCONSINITDFTVSREG,
                   VSCtl_bDgoElConsInitDftVSReg,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELDFTCRSCTL,
                   VSCtl_bDgoElDftCrsCtl,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ZEROFRAMECNTDFT,
                   VSCtl_bDgoZeroFrameCntDft,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_EVENFRAMECNTDFT,
                   VSCtl_bDgoEvenFrameCntDft,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELFRAMECNTINCDFT,
                   VSCtl_bDgoElFrameCntIncDft,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrsCtl_SdlSlow_CrsCtlBsiTreat                              */
/* !Description :  Moniteur lent pour la fonction xVV                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_E_11_06467_001.01                                     */
/*                 VEMS_E_11_06467_002.01                                     */
/*                 VEMS_E_11_06467_003.01                                     */
/*                 VEMS_R_11_06467_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLBSITREAT_vidDiag_2();                              */
/*  extf argret void CRSCTLBSITREAT_vidInfoTreat();                           */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 CRSCTLBSITREAT_u8Inhib;                                       */
/*  input boolean VSCtl_bDgoElConsCohVSMaxp;                                  */
/*  input boolean VSCtl_bMonRunElDft;                                         */
/*  input boolean VSCtl_bDgoElConsDefDftVSMaxp;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrsCtl_SdlSlow_CrsCtlBsiTreat                                  */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrsCtl_SdlSlow_CrsCtlBsiTreat(void)
{
   if (CRSCTLBSITREAT_u8Inhib != 0x5A)
   {
      CRSCTLBSITREAT_vidDiag_2();
      CRSCTLBSITREAT_vidInfoTreat();

      GDGAR_vidGdu(GD_DFT_ELCONSCOHVSMAXP,
                   VSCtl_bDgoElConsCohVSMaxp,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_ELCONSDEFDFTVSMAXP,
                   VSCtl_bDgoElConsDefDftVSMaxp,
                   VSCtl_bMonRunElDft,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/