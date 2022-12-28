/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FCTDIAGTRBPRES                                          */
/* !Description     : FCTDIAGTRBPRES Component                                */
/*                                                                            */
/* !Module          : FCTDIAGTRBPRES                                          */
/* !Description     :  Diagnostic fonctionnel de la pression de               */
/*                    suralimentation                                         */
/*                                                                            */
/* !File            : FCTDIAGTRBPRES_SCH.C                                    */
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
/*   1 / AirPres_EveRst_FctDiagTrbPres                                        */
/*   2 / AirPres_SdlMid_FctDiagTrbPres                                        */
/*   3 / AirPres_Eve14TDC_DiagTrbPres                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5198884 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065845                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/AIRPRES/FCTDIAGTRBPRES/FCTDIAGTR$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   16 May 2013 $*/
/* $Author::   etsasson                               $$Date::   16 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "FCTDIAGTRBPRES.h"
#include "FCTDIAGTRBPRES_L.h"
#include "FCTDIAGTRBPRES_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_FctDiagTrbPres                              */
/* !Description :  Evènement de reset de la fonction AirPres.                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_001.01                                     */
/*                 VEMS_E_11_03491_002.01                                     */
/*                 VEMS_E_11_03491_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGTRBPRES_vidInitOutput();                          */
/*  extf argret void FCTDIAGTRBPRES_vidDiagTrbPrsinit();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_FctDiagTrbPres                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_FctDiagTrbPres(void)
{
   FCTDIAGTRBPRES_vidInitOutput();
   FCTDIAGTRBPRES_vidDiagTrbPrsinit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_FctDiagTrbPres                              */
/* !Description :  Moniteur moyen pour la fonction AirPres.                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_001.01                                     */
/*                 VEMS_E_11_03491_002.01                                     */
/*                 VEMS_E_11_03491_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGTRBPRES_vidDiagTrbPres();                         */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 FCTDIAGTRBPRES_u8Inhib;                                       */
/*  input boolean AirPres_bDgoPosDif1_pUsThr;                                 */
/*  input boolean AirPres_bMonRunPosDif1_pUsThr;                              */
/*  input boolean AirPres_bDgoPosDif2_pUsThr;                                 */
/*  input boolean AirPres_bMonRunPosDif2_pUsThr;                              */
/*  input boolean AirPres_bDgoNegDif1_pUsThr;                                 */
/*  input boolean AirPres_bMonRunNegDif1_pUsThr;                              */
/*  input boolean AirPres_bDgoNegDif2_pUsThr;                                 */
/*  input boolean AirPres_bMonRunNegDif2_pUsThr;                              */
/*  input boolean AirPres_bDgoPlaus_pUsThrIdl;                                */
/*  input boolean AirPres_bMonRunPlaus_pUsThrIdl;                             */
/*  input boolean AirPres_bDgoPlaus_pUsThrBoost;                              */
/*  input boolean AirPres_bMonRunPlaus_pUsThrBoost;                           */
/*  input boolean AirPres_bDgoNegDif_pUsThrSen;                               */
/*  input boolean AirPres_bMonRunNegDif_pUsThrSen;                            */
/*  input boolean AirPres_bDgoPosDif_pUsThrSen;                               */
/*  input boolean AirPres_bMonRunPosDif_pUsThrSen;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_FctDiagTrbPres                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_FctDiagTrbPres(void)
{
   if (FCTDIAGTRBPRES_u8Inhib != 0x5A)
   {
      FCTDIAGTRBPRES_vidDiagTrbPres();
      GDGAR_vidGdu(GD_DFT_POSDIF1_PUSTHR,
                   AirPres_bDgoPosDif1_pUsThr,
                   AirPres_bMonRunPosDif1_pUsThr,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_POSDIF2_PUSTHR,
                   AirPres_bDgoPosDif2_pUsThr,
                   AirPres_bMonRunPosDif2_pUsThr,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_NEGDIF1_PUSTHR,
                   AirPres_bDgoNegDif1_pUsThr,
                   AirPres_bMonRunNegDif1_pUsThr,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_NEGDIF2_PUSTHR,
                   AirPres_bDgoNegDif2_pUsThr,
                   AirPres_bMonRunNegDif2_pUsThr,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_PLAUS_PUSTHRIDL,
                   AirPres_bDgoPlaus_pUsThrIdl,
                   AirPres_bMonRunPlaus_pUsThrIdl,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_PLAUS_PUSTHRBOOST,
                   AirPres_bDgoPlaus_pUsThrBoost,
                   AirPres_bMonRunPlaus_pUsThrBoost,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_NEGDIF_PUSTHRSEN,
                   AirPres_bDgoNegDif_pUsThrSen,
                   AirPres_bMonRunNegDif_pUsThrSen,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_POSDIF_PUSTHRSEN,
                   AirPres_bDgoPosDif_pUsThrSen,
                   AirPres_bMonRunPosDif_pUsThrSen,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_Eve14TDC_DiagTrbPres                               */
/* !Description :  Evenement sur 1/4 de PMH                                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_001.01                                     */
/*                 VEMS_E_11_03491_002.01                                     */
/*                 VEMS_E_11_03491_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FCTDIAGTRBPRES_vidDiagCntTrbPres();                      */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 FCTDIAGTRBPRES_u8Inhib;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input boolean Ctrl_bAcv_pUsThr;                                           */
/*  input boolean AirPres_bDgoMaxAbs_pUsThr;                                  */
/*  input boolean AirPres_bMonRunMaxAbs_pUsThr;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_Eve14TDC_DiagTrbPres                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_Eve14TDC_DiagTrbPres(void)
{
   boolean bLocalECU_bWkuMain;
   boolean bLocalECU_bImmoUnlockWkuSt;
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalCtrl_bAcv_pUsThr;


   if (FCTDIAGTRBPRES_u8Inhib != 0x5A)
   {
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
      VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
      VEMS_vidGET(Ctrl_bAcv_pUsThr, bLocalCtrl_bAcv_pUsThr);

      if (  (  (bLocalECU_bWkuMain != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0))
         && (bLocalCoPTSt_bEngRun != 0)
         && (bLocalCtrl_bAcv_pUsThr != 0))
      {
         FCTDIAGTRBPRES_vidDiagCntTrbPres();
         GDGAR_vidGdu(GD_DFT_MAXABS_PUSTHR,
                      AirPres_bDgoMaxAbs_pUsThr,
                      AirPres_bMonRunMaxAbs_pUsThr,
                      DIAG_DISPO);
      }
   }
}
/*------------------------------- end of file --------------------------------*/