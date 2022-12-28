/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINMON                                             */
/* !Description     : VLVACTINMON component                                   */
/*                                                                            */
/* !Module          : VLVACTINMON                                             */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA VVT ADMISSION              */
/*                                                                            */
/* !File            : VLVACTINMON_SCH.C                                       */
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
/*   1 / VLVACTINMON_vidEntryInit                                             */
/*   2 / VlvAct_Sdlfast_InMon                                                 */
/*                                                                            */
/* !Reference   : V02 NT 09 06381 / 05                                        */
/* !OtherRefs   : VEMS V02 ECU#055138                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINMON/VLVACTINMON$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   04 Jul 2011 $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINMON.h"
#include "VLVACTINMON_L.h"
#include "VLVACTINMON_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMON_vidEntryInit                                   */
/* !Description :  Fonction d'accroche Reset                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VLVACTINMON_vidEntryInit                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMON_vidEntryInit(void)
{
   VLVACTINMON_vidInitialization();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_Sdlfast_InMon                                       */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06381_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMON_vidOffsetSetPtComp();                        */
/*  extf argret void VLVACTINMON_vidColdDiagComp();                           */
/*  extf argret void VLVACTINMON_vidHotDiagComp();                            */
/*  extf argret void VLVACTINMON_vidHotStkDiagComp();                         */
/*  extf argret void VLVACTINMON_vidPosStatErrorDiag();                       */
/*  extf argret void VLVACTINMON_vidNegStatErrorDiag();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VLVACTINMON_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*  input boolean VlvAct_bDgoDftCVlvActIn;                                    */
/*  input boolean VlvAct_bMonRunInColdFctDg;                                  */
/*  input boolean VlvAct_bDgoSlowC1VlvActIn;                                  */
/*  input boolean VlvAct_bDgoSlowC2VlvActIn;                                  */
/*  input boolean VlvAct_bDgoORngCVlvActIn;                                   */
/*  input boolean VlvAct_bDgoCmdCVlvActIn;                                    */
/*  input boolean VlvAct_bDgoDftHVlvActIn;                                    */
/*  input boolean VlvAct_bMonRunInHotFctDg;                                   */
/*  input boolean VlvAct_bDgoSlowH1VlvActIn;                                  */
/*  input boolean VlvAct_bDgoSlowH2VlvActIn;                                  */
/*  input boolean VlvAct_bDgoORngHVlvActIn;                                   */
/*  input boolean VlvAct_bDgoCmdHVlvActIn;                                    */
/*  input boolean VlvAct_bDgoStuckH1VlvActIn;                                 */
/*  input boolean VlvAct_bMonRunInHotStuckFctDg;                              */
/*  input boolean VlvAct_bDgoStuckH2VlvActIn;                                 */
/*  input boolean VlvAct_bDgoStuckH3VlvActIn;                                 */
/*  input boolean VlvAct_bDgoStuckHVlvActIn;                                  */
/*  input boolean VlvAct_bDgoDifPos1VlvActIn;                                 */
/*  input boolean VlvAct_bMonRunDifPos1VlvActIn;                              */
/*  input boolean VlvAct_bDgoDifNeg2VlvActIn;                                 */
/*  input boolean VlvAct_bMonRunDifPos2VlvActIn;                              */
/*  input boolean VlvAct_bDgoDifNeg1VlvActIn;                                 */
/*  input boolean VlvAct_bMonRunDifNeg1VlvActIn;                              */
/*  input boolean VlvAct_bMonRunDifNeg2VlvActIn;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_Sdlfast_InMon                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_Sdlfast_InMon(void)
{
   if (VLVACTINMON_u8Inhib != 0x5A)
   {
      if(VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINMON_vidOffsetSetPtComp();
         VLVACTINMON_vidColdDiagComp();
         VLVACTINMON_vidHotDiagComp();
         VLVACTINMON_vidHotStkDiagComp();
         VLVACTINMON_vidPosStatErrorDiag();
         VLVACTINMON_vidNegStatErrorDiag();
         GDGAR_vidGdu(GD_DFT_DFTCVLVACTIN,
                      VlvAct_bDgoDftCVlvActIn,
                      VlvAct_bMonRunInColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SLOWC1VLVACTIN,
                      VlvAct_bDgoSlowC1VlvActIn,
                      VlvAct_bMonRunInColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SLOWC2VLVACTIN,
                      VlvAct_bDgoSlowC2VlvActIn,
                      VlvAct_bMonRunInColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNGCVLVACTIN,
                      VlvAct_bDgoORngCVlvActIn,
                      VlvAct_bMonRunInColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_CMDCVLVACTIN,
                      VlvAct_bDgoCmdCVlvActIn,
                      VlvAct_bMonRunInColdFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DFTHVLVACTIN,
                      VlvAct_bDgoDftHVlvActIn,
                      VlvAct_bMonRunInHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SLOWH1VLVACTIN,
                      VlvAct_bDgoSlowH1VlvActIn,
                      VlvAct_bMonRunInHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SLOWH2VLVACTIN,
                      VlvAct_bDgoSlowH2VlvActIn,
                      VlvAct_bMonRunInHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNGHVLVACTIN,
                      VlvAct_bDgoORngHVlvActIn,
                      VlvAct_bMonRunInHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_CMDHVLVACTIN,
                      VlvAct_bDgoCmdHVlvActIn,
                      VlvAct_bMonRunInHotFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_STUCKH1VLVACTIN,
                      VlvAct_bDgoStuckH1VlvActIn,
                      VlvAct_bMonRunInHotStuckFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_STUCKH2VLVACTIN,
                      VlvAct_bDgoStuckH2VlvActIn,
                      VlvAct_bMonRunInHotStuckFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_STUCKH3VLVACTIN,
                      VlvAct_bDgoStuckH3VlvActIn,
                      VlvAct_bMonRunInHotStuckFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_STUCKHVLVACTIN,
                      VlvAct_bDgoStuckHVlvActIn,
                      VlvAct_bMonRunInHotStuckFctDg,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DIFPOS1VLVACTIN,
                      VlvAct_bDgoDifPos1VlvActIn,
                      VlvAct_bMonRunDifPos1VlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DIFPOS2VLVACTIN,
                      VlvAct_bDgoDifNeg2VlvActIn,
                      VlvAct_bMonRunDifPos2VlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DIFNEG1VLVACTIN,
                      VlvAct_bDgoDifNeg1VlvActIn,
                      VlvAct_bMonRunDifNeg1VlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_DIFNEG2VLVACTIN,
                      VlvAct_bDgoDifNeg2VlvActIn,
                      VlvAct_bMonRunDifNeg2VlvActIn,
                      DIAG_DISPO);
      }
   }
}
/*--------------------------------- end of file ------------------------------*/