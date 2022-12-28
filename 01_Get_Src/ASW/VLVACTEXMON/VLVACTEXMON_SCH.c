/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXMON                                             */
/* !Description     : VLVACTEXMON component                                   */
/*                                                                            */
/* !Module          : VLVACTEXMON                                             */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA VVT ÉCHAPPEMENT            */
/*                                                                            */
/* !File            : VLVACTEXMON_SCH.C                                       */
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
/*   1 / VLVACTEXMON_vidEntryInit                                             */
/*   2 / VlvAct_Sdlfast_ExMon                                                 */
/*                                                                            */
/* !Reference   : V02 NT 09 06481 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#055118                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXMON/VLVACTEXMON$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   05 Jul 2011 $*/
/* $Author::   HHAMLAOU                               $$Date::   05 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTEXMON.h"
#include "VLVACTEXMON_L.h"
#include "VLVACTEXMON_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMON_vidEntryInit                                   */
/* !Description :  Fonction d'accroche Reset                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VLVACTEXMON_vidEntryInit                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMON_vidEntryInit(void)
{
   VLVACTEXMON_vidInitialization();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_Sdlfast_ExMon                                       */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06481_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMON_vidOffsetSetPtComp();                        */
/*  extf argret void VLVACTEXMON_vidColdDiagComp();                           */
/*  extf argret void VLVACTEXMON_vidHotDiagComp();                            */
/*  extf argret void VLVACTEXMON_vidHotStkDiagComp();                         */
/*  extf argret void VLVACTEXMON_vidPosStatErrorDiag();                       */
/*  extf argret void VLVACTEXMON_vidNegStatErrorDiag();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VLVACTEXMON_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*  input boolean VlvAct_bDgoDftCVlvActEx;                                    */
/*  input boolean VlvAct_bMonRunExColdFctDg;                                  */
/*  input boolean VlvAct_bDgoSlowC1VlvActEx;                                  */
/*  input boolean VlvAct_bDgoSlowC2VlvActEx;                                  */
/*  input boolean VlvAct_bDgoORngCVlvActEx;                                   */
/*  input boolean VlvAct_bDgoCmdCVlvActEx;                                    */
/*  input boolean VlvAct_bDgoDftHVlvActEx;                                    */
/*  input boolean VlvAct_bMonRunExHotFctDg;                                   */
/*  input boolean VlvAct_bDgoSlowH1VlvActEx;                                  */
/*  input boolean VlvAct_bDgoSlowH2VlvActEx;                                  */
/*  input boolean VlvAct_bDgoORngHVlvActEx;                                   */
/*  input boolean VlvAct_bDgoCmdHVlvActEx;                                    */
/*  input boolean VlvAct_bDgoStuckH1VlvActEx;                                 */
/*  input boolean VlvAct_bMonRunExHotStuckFctDg;                              */
/*  input boolean VlvAct_bDgoStuckH2VlvActEx;                                 */
/*  input boolean VlvAct_bDgoStuckH3VlvActEx;                                 */
/*  input boolean VlvAct_bDgoStuckHVlvActEx;                                  */
/*  input boolean VlvAct_bDgoDifPos1VlvActEx;                                 */
/*  input boolean VlvAct_bMonRunDifPos1VlvActEx;                              */
/*  input boolean VlvAct_bDgoDifNeg2VlvActEx;                                 */
/*  input boolean VlvAct_bMonRunDifPos2VlvActEx;                              */
/*  input boolean VlvAct_bDgoDifNeg1VlvActEx;                                 */
/*  input boolean VlvAct_bMonRunDifNeg1VlvActEx;                              */
/*  input boolean VlvAct_bMonRunDifNeg2VlvActEx;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_Sdlfast_ExMon                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_Sdlfast_ExMon(void)
{
   if (VLVACTEXMON_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXMON_vidOffsetSetPtComp();
         VLVACTEXMON_vidColdDiagComp();
         VLVACTEXMON_vidHotDiagComp();
         VLVACTEXMON_vidHotStkDiagComp();
         VLVACTEXMON_vidPosStatErrorDiag();
         VLVACTEXMON_vidNegStatErrorDiag();
         GDGAR_vidGdu(GD_DFT_DFTCVLVACTEX,
                      VlvAct_bDgoDftCVlvActEx,
                      VlvAct_bMonRunExColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SLOWC1VLVACTEX,
                      VlvAct_bDgoSlowC1VlvActEx,
                      VlvAct_bMonRunExColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SLOWC2VLVACTEX,
                      VlvAct_bDgoSlowC2VlvActEx,
                      VlvAct_bMonRunExColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNGCVLVACTEX,
                      VlvAct_bDgoORngCVlvActEx,
                      VlvAct_bMonRunExColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_CMDCVLVACTEX,
                      VlvAct_bDgoCmdCVlvActEx,
                      VlvAct_bMonRunExColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DFTHVLVACTEX,
                      VlvAct_bDgoDftHVlvActEx,
                      VlvAct_bMonRunExHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SLOWH1VLVACTEX,
                      VlvAct_bDgoSlowH1VlvActEx,
                      VlvAct_bMonRunExHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SLOWH2VLVACTEX,
                      VlvAct_bDgoSlowH2VlvActEx,
                      VlvAct_bMonRunExHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNGHVLVACTEX,
                      VlvAct_bDgoORngHVlvActEx,
                      VlvAct_bMonRunExHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_CMDHVLVACTEX,
                      VlvAct_bDgoCmdHVlvActEx,
                      VlvAct_bMonRunExHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_STUCKH1VLVACTEX,
                      VlvAct_bDgoStuckH1VlvActEx,
                      VlvAct_bMonRunExHotStuckFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_STUCKH2VLVACTEX,
                      VlvAct_bDgoStuckH2VlvActEx,
                      VlvAct_bMonRunExHotStuckFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_STUCKH3VLVACTEX,
                      VlvAct_bDgoStuckH3VlvActEx,
                      VlvAct_bMonRunExHotStuckFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_STUCKHVLVACTEX,
                      VlvAct_bDgoStuckHVlvActEx,
                      VlvAct_bMonRunExHotStuckFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DIFPOS1VLVACTEX,
                      VlvAct_bDgoDifPos1VlvActEx,
                      VlvAct_bMonRunDifPos1VlvActEx,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DIFPOS2VLVACTEX,
                      VlvAct_bDgoDifNeg2VlvActEx,
                      VlvAct_bMonRunDifPos2VlvActEx,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DIFNEG1VLVACTEX,
                      VlvAct_bDgoDifNeg1VlvActEx,
                      VlvAct_bMonRunDifNeg1VlvActEx,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DIFNEG2VLVACTEX,
                      VlvAct_bDgoDifNeg2VlvActEx,
                      VlvAct_bMonRunDifNeg2VlvActEx,
                      DIAG_DISPO);
      }
   }
}
/*--------------------------------- end of file ------------------------------*/