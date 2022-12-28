/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INMNFPRESDIAG                                           */
/* !Description     : INMNFPRESDIAG Component.                                */
/*                                                                            */
/* !Module          : INMNFPRESDIAG                                           */
/* !Description     : Diagnostic fonctionnel de la pression collecteur.       */
/*                                                                            */
/* !File            : INMNFPRESDIAG_SCH.C                                     */
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
/*   1 / AirPres_EveRst_InMnfPresDiag                                         */
/*   2 / AirPres_SdlMid_InMnfPresDiag                                         */
/*   3 / AirPres_EveCrTSt_InMnfPresDiag                                       */
/*   4 / AirPres_SdlFast_InMnfPresDiag                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6539920 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INMNFPRESDIAG/INMNFPRESDIAG_SCH.C_$*/
/* $Revision::   1.10     $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INMNFPRESDIAG.h"
#include "INMNFPRESDIAG_L.h"
#include "INMNFPRESDIAG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_InMnfPresDiag                               */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_001.01                                     */
/*                 VEMS_E_11_03503_002.01                                     */
/*                 VEMS_E_11_03503_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INMNFPRESDIAG_vidMnfPresDiagInit();                      */
/*  extf argret void INMNFPRESDIAG_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_InMnfPresDiag                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_InMnfPresDiag(void)
{
   /*F01_InMnfPresDiag_Ini*/
   INMNFPRESDIAG_vidMnfPresDiagInit();
   INMNFPRESDIAG_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_InMnfPresDiag                               */
/* !Description :  Moniteur moyen de la fonction diagnostic de la boucle d'air*/
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_001.01                                     */
/*                 VEMS_E_11_03503_002.01                                     */
/*                 VEMS_E_11_03503_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INMNFPRESDIAG_vidCanPurgVerif();                         */
/*  extf argret void INMNFPRESDIAG_vidMngActivStart();                        */
/*  extf argret void INMNFPRESDIAG_vidMfPrDiagBfStart();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void INMNFPRESDIAG_vidMfPrDiagDrStart();                      */
/*  extf argret void INMNFPRESDIAG_vidMnfPresDiagAuth();                      */
/*  extf argret void INMNFPRESDIAG_vidMnfPresDiagLim();                       */
/*  extf argret void INMNFPRESDIAG_vidDiagAuthFulLoad();                      */
/*  input uint8 INMNFPRESDIAG_u8Inhib;                                        */
/*  input boolean AirPres_bDgoStallCoh_pDsThr;                                */
/*  input boolean AirPres_bMonRunStallCoh_pDsThr;                             */
/*  input boolean AirPres_bDgoCrkCoh_pDsThr;                                  */
/*  input boolean AirPres_bMonRunCrkCoh_pDsThr;                               */
/*  input boolean AirPres_bMonWaitCrkCoh_pDsThr;                              */
/*  input boolean AirPres_bDgoStabCoh_pDsThr;                                 */
/*  input boolean AirPres_bMonRunStabCoh_pDsThr;                              */
/*  input boolean AirPres_bDgoThrCoh_pDsThr;                                  */
/*  input boolean AirPres_bMonRunThrCoh_pDsThr;                               */
/*  input boolean AirPres_bDgoORng_pDsThr;                                    */
/*  input boolean AirPres_bMonRunORng_pDsThr;                                 */
/*  input boolean AirPres_bDgoFldCoh_pDsThr;                                  */
/*  input boolean AirPres_bMonRunFldCoh_pDsThr;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_InMnfPresDiag                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_InMnfPresDiag(void)
{
   if (INMNFPRESDIAG_u8Inhib != 0x5A)
   {
      /*F02_InMnfPresDiag_CanPurg*/
      INMNFPRESDIAG_vidCanPurgVerif();

      /*F00_InMnfPresDiag_GestionActivation_demarrage*/
      INMNFPRESDIAG_vidMngActivStart();

      /*F03_InMnfPresDiag_AvantDemarrage*/
      INMNFPRESDIAG_vidMfPrDiagBfStart();
      GDGAR_vidGdu(GD_DFT_STALLCOH_PDSTHR,
                   AirPres_bDgoStallCoh_pDsThr,
                   AirPres_bMonRunStallCoh_pDsThr,
                   DIAG_DISPO);

      /*F04_InMnfPresDiag_AuDemarrage*/
      INMNFPRESDIAG_vidMfPrDiagDrStart();
      GDGAR_vidGdu(GD_DFT_CRKCOH_PDSTHR,
                   AirPres_bDgoCrkCoh_pDsThr,
                   AirPres_bMonRunCrkCoh_pDsThr,
                   AirPres_bMonWaitCrkCoh_pDsThr);

      /*F05_InMnfPresDiag_EnStabilise*/
      INMNFPRESDIAG_vidMnfPresDiagAuth();
      GDGAR_vidGdu(GD_DFT_STABCOH_PDSTHR,
                   AirPres_bDgoStabCoh_pDsThr,
                   AirPres_bMonRunStabCoh_pDsThr,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_THRCOH_PDSTHR,
                   AirPres_bDgoThrCoh_pDsThr,
                   AirPres_bMonRunThrCoh_pDsThr,
                   DIAG_DISPO);

      /*F06_InMnfPresDiag_PresLim*/
      INMNFPRESDIAG_vidMnfPresDiagLim();
      GDGAR_vidGdu(GD_DFT_ORNG_PDSTHR,
                   AirPres_bDgoORng_pDsThr,
                   AirPres_bMonRunORng_pDsThr,
                   DIAG_DISPO);

      /*F07_InMnfPresDiag_PleineCharge*/
      INMNFPRESDIAG_vidDiagAuthFulLoad();
      GDGAR_vidGdu(GD_DFT_FLDCOH_PDSTHR,
                   AirPres_bDgoFldCoh_pDsThr,
                   AirPres_bMonRunFldCoh_pDsThr,
                   DIAG_DISPO);

   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveCrTSt_InMnfPresDiag                             */
/* !Description :  Evènement d'arrêt moteur                                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_001.01                                     */
/*                 VEMS_E_11_03503_002.01                                     */
/*                 VEMS_E_11_03503_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INMNFPRESDIAG_vidPrsDiagStallIni();                      */
/*  input uint8 INMNFPRESDIAG_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveCrTSt_InMnfPresDiag                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveCrTSt_InMnfPresDiag(void)
{
   if (INMNFPRESDIAG_u8Inhib != 0x5A)
   {
      /*F09_InMnfPresDiag_Stall_Ini*/
      INMNFPRESDIAG_vidPrsDiagStallIni();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_InMnfPresDiag                              */
/* !Description :  Moniteur rapide                                            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_001.01                                     */
/*                 VEMS_E_11_03503_002.01                                     */
/*                 VEMS_E_11_03503_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INMNFPRESDIAG_vidMnfPresDiagGrd();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 INMNFPRESDIAG_u8Inhib;                                        */
/*  input boolean AirPres_bDgoGrd_pDsThr;                                     */
/*  input boolean AirPres_bMonRunGrd_pDsThr;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_InMnfPresDiag                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_InMnfPresDiag(void)
{
   if (INMNFPRESDIAG_u8Inhib != 0x5A)
   {
      /*F08_InMnfPresDiag_GrdPres*/
      INMNFPRESDIAG_vidMnfPresDiagGrd();
      GDGAR_vidGdu(GD_DFT_GRD_PDSTHR,
                   AirPres_bDgoGrd_pDsThr,
                   AirPres_bMonRunGrd_pDsThr,
                   DIAG_DISPO);
   }
}
/************************************* end of file ****************************/