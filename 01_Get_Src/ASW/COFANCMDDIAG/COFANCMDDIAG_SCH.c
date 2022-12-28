/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COFANCMDDIAG                                            */
/* !Description     : COFANCMDDIAG component.                                 */
/*                                                                            */
/* !Module          : COFANCMDDIAG                                            */
/* !Description     : COMMANDE ET DIAGNOSTICS DES GMV.                        */
/*                                                                            */
/* !File            : COFANCMDDIAG_SCH.C                                      */
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
/*   1 / CoFan_EveRst_CmdDiagCoFan                                            */
/*   2 / CoFan_EveRstDft_CmdDiagCoFan                                         */
/*   3 / CoFan_SdlMid_CmdDiagCoFan                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6722439 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/COFANCMDDIAG/COFANCMDDIAG_SCH.C_v $*/
/* $Revision::   1.14     $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "COFANCMDDIAG_IM.h"
#include "COFANCMDDIAG_L.h"
#include "COFANCMDDIAG.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_EveRst_CmdDiagCoFan                                  */
/* !Description :  Fonction d'accroche au moniteur CoFan_EveRst_CmdDiagCoFan  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COFANCMDDIAG_vidInitOutput();                            */
/*  extf argret void COFANCMDDIAG_vidInit();                                  */
/*  extf argret void COFANCMDDIAG_vidRstCoFanCtlMng();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_EveRst_CmdDiagCoFan                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_EveRst_CmdDiagCoFan(void)
{
   COFANCMDDIAG_vidInitOutput();
   COFANCMDDIAG_vidInit();
   COFANCMDDIAG_vidRstCoFanCtlMng();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_EveRstDft_CmdDiagCoFan                               */
/* !Description :  Fonction d'accroche au moniteur                            */
/*                 CoFan_EveRstDft_CmdDiagCoFan                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COFANCMDDIAG_vidRstDft();                                */
/*  input uint8 COFANCMDDIAG_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_EveRstDft_CmdDiagCoFan                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_EveRstDft_CmdDiagCoFan(void)
{
   if (COFANCMDDIAG_u8Inhib != 0x5A)
   {
      COFANCMDDIAG_vidRstDft();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlMid_CmdDiagCoFan                                  */
/* !Description :  Fonction d'accroche au moniteur CoFan_SdlMid_CmdDiagCoFan  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COFANCMDDIAG_vidCoFanSpdMng();                           */
/*  extf argret void COFANCMDDIAG_vidCoFanCtlMng();                           */
/*  extf argret void COFANCMDDIAG_vidCoFanCmd();                              */
/*  extf argret void COFANCMDDIAG_vidDiagCoFan();                             */
/*  extf argret void GDGAR_vidGdu(argin uint16 indexDefaut, argin boolean     */
/* bDgo, argin boolean bMonRun, argin boolean Ns_bMonWait);                   */
/*  input uint8 COFANCMDDIAG_u8Inhib;                                         */
/*  input boolean CoFan_bDgoOc_DrvrFan1;                                      */
/*  input boolean CoFan_bMonRunOc_DrvrFan1;                                   */
/*  input boolean CoFan_bDgoLo_DrvrFan1;                                      */
/*  input boolean CoFan_bMonRunLo_DrvrFan1;                                   */
/*  input boolean CoFan_bDgoHi_DrvrFan1;                                      */
/*  input boolean CoFan_bMonRunHi_DrvrFan1;                                   */
/*  input boolean CoFan_bDgoOc_DrvrFan2;                                      */
/*  input boolean CoFan_bMonRunOc_DrvrFan2;                                   */
/*  input boolean CoFan_bDgoLo_DrvrFan2;                                      */
/*  input boolean CoFan_bMonRunLo_DrvrFan2;                                   */
/*  input boolean CoFan_bDgoHi_DrvrFan2;                                      */
/*  input boolean CoFan_bMonRunHi_DrvrFan2;                                   */
/*  input boolean CoFan_bDgoCoh_StFanB1;                                      */
/*  input boolean CoFan_bMonRunCoh_StFanB1;                                   */
/*  input boolean CoFan_bDgoCoh_StFanB2LoSpd;                                 */
/*  input boolean CoFan_bMonRunCoh_StFanB2LoSpd;                              */
/*  input boolean CoFan_bDgoCoh_StFanB2HiSpd;                                 */
/*  input boolean CoFan_bMonRunCoh_StFanB2HiSpd;                              */
/*  input boolean CoFan_bDgoCoh_StFanB2NoSpd;                                 */
/*  input boolean CoFan_bMonRunCoh_StFanB2NoSpd;                              */
/*  input boolean CoFan_bDgoClsdRly_StFanC;                                   */
/*  input boolean CoFan_bMonRunClsdRly_StFanC;                                */
/*  input boolean CoFan_bDgoEl_StFanC;                                        */
/*  input boolean CoFan_bMonRunEl_StFanC;                                     */
/*  input boolean CoFan_bDgoUnVld_StFanC;                                     */
/*  input boolean CoFan_bMonRunUnVld_StFanC;                                  */
/*  input boolean CoFan_bDgoCritSc_StFanC;                                    */
/*  input boolean CoFan_bMonRunCritSc_StFanC;                                 */
/*  input boolean CoFan_bDgoECI_StFanC;                                       */
/*  input boolean CoFan_bMonRunECI_StFanC;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlMid_CmdDiagCoFan                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlMid_CmdDiagCoFan(void)
{
   if (COFANCMDDIAG_u8Inhib != 0x5A)
   {
      COFANCMDDIAG_vidCoFanSpdMng();
      COFANCMDDIAG_vidCoFanCtlMng();
      COFANCMDDIAG_vidCoFanCmd();
      COFANCMDDIAG_vidDiagCoFan();
      GDGAR_vidGdu(GD_DFT_OC_DRVRFAN1,
                   CoFan_bDgoOc_DrvrFan1,
                   CoFan_bMonRunOc_DrvrFan1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_LO_DRVRFAN1,
                   CoFan_bDgoLo_DrvrFan1,
                   CoFan_bMonRunLo_DrvrFan1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_HI_DRVRFAN1,
                   CoFan_bDgoHi_DrvrFan1,
                   CoFan_bMonRunHi_DrvrFan1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_DRVRFAN2,
                   CoFan_bDgoOc_DrvrFan2,
                   CoFan_bMonRunOc_DrvrFan2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_LO_DRVRFAN2,
                   CoFan_bDgoLo_DrvrFan2,
                   CoFan_bMonRunLo_DrvrFan2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_HI_DRVRFAN2,
                   CoFan_bDgoHi_DrvrFan2,
                   CoFan_bMonRunHi_DrvrFan2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COH_STFANB1,
                   CoFan_bDgoCoh_StFanB1,
                   CoFan_bMonRunCoh_StFanB1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COH_STFANB2LOSPD,
                   CoFan_bDgoCoh_StFanB2LoSpd,
                   CoFan_bMonRunCoh_StFanB2LoSpd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COH_STFANB2HISPD,
                   CoFan_bDgoCoh_StFanB2HiSpd,
                   CoFan_bMonRunCoh_StFanB2HiSpd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COH_STFANB2NOSPD,
                   CoFan_bDgoCoh_StFanB2NoSpd,
                   CoFan_bMonRunCoh_StFanB2NoSpd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_CLSDRLY_STFANC,
                   CoFan_bDgoClsdRly_StFanC,
                   CoFan_bMonRunClsdRly_StFanC,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_EL_STFANC,
                   CoFan_bDgoEl_StFanC,
                   CoFan_bMonRunEl_StFanC,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_UNVLD_STFANC,
                   CoFan_bDgoUnVld_StFanC,
                   CoFan_bMonRunUnVld_StFanC,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_CRITSC_STFANC,
                   CoFan_bDgoCritSc_StFanC,
                   CoFan_bMonRunCritSc_StFanC,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ECI_STFANC,
                   CoFan_bDgoECI_StFanC,
                   CoFan_bMonRunECI_StFanC,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/