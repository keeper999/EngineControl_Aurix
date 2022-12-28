/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INAIRFLOWDIAG                                           */
/* !Description     : INAIRFLOWDIAG Component.                                */
/*                                                                            */
/* !Module          : INAIRFLOWDIAG                                           */
/* !Description     : Diagnostic fonctionnel du debit d’air d’admission.      */
/*                                                                            */
/* !File            : INAIRFLOWDIAG_SCH.C                                     */
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
/*   1 / AirSys_EveRst_InAirflowDiag                                          */
/*   2 / AirSys_SdlMid_InAirflowDiag                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5198333 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INAIRFLOWDIAG/INAIRFLOWDIAG_SCH.$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   15 May 2013 $*/
/* $Author::   etsasson                               $$Date::   15 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "INAIRFLOWDIAG.h"
#include "INAIRFLOWDIAG_L.h"
#include "INAIRFLOWDIAG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirSys_EveRst_InAirflowDiag                                */
/* !Description :  Evènement de reset de la fonction AirSys                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_E_11_03601_001.01                                     */
/*                 VEMS_E_11_03601_002.01                                     */
/*                 VEMS_E_11_03601_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INAIRFLOWDIAG_vidInit();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirSys_EveRst_InAirflowDiag                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirSys_EveRst_InAirflowDiag(void)
{
   INAIRFLOWDIAG_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirSys_SdlMid_InAirflowDiag                                */
/* !Description :  Moniteur moyen de la fonction diagnostic de la boucle d'air*/
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_E_11_03601_001.01                                     */
/*                 VEMS_E_11_03601_002.01                                     */
/*                 VEMS_E_11_03601_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INAIRFLOWDIAG_vidLowAirflow();                           */
/*  extf argret void INAIRFLOWDIAG_vidLeak();                                 */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 INAIRFLOWDIAG_u8Inhib;                                        */
/*  input boolean AirSys_bDgoBoost1_pDsThr;                                   */
/*  input boolean AirSys_bMonRunBoost1_pDsThr;                                */
/*  input boolean AirSys_bDgoBoost2_pDsThr;                                   */
/*  input boolean AirSys_bMonRunBoost2_pDsThr;                                */
/*  input boolean AirSys_bDgoBoost3_pDsThr;                                   */
/*  input boolean AirSys_bMonRunBoost3_pDsThr;                                */
/*  input boolean AirSys_bDgoBoost4_pDsThr;                                   */
/*  input boolean AirSys_bMonRunBoost4_pDsThr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirSys_SdlMid_InAirflowDiag                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirSys_SdlMid_InAirflowDiag(void)
{
   if (INAIRFLOWDIAG_u8Inhib != 0x5A)
   {
      INAIRFLOWDIAG_vidLowAirflow();
      INAIRFLOWDIAG_vidLeak();
      GDGAR_vidGdu(GD_DFT_BOOST1_PDSTHR,
                   AirSys_bDgoBoost1_pDsThr,
                   AirSys_bMonRunBoost1_pDsThr,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_BOOST2_PDSTHR,
                   AirSys_bDgoBoost2_pDsThr,
                   AirSys_bMonRunBoost2_pDsThr,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_BOOST3_PDSTHR,
                   AirSys_bDgoBoost3_pDsThr,
                   AirSys_bMonRunBoost3_pDsThr,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_BOOST4_PDSTHR,
                   AirSys_bDgoBoost4_pDsThr,
                   AirSys_bMonRunBoost4_pDsThr,
                   DIAG_DISPO);
   }
}
/*-------------------------------- end of file -------------------------------*/