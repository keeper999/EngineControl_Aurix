/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRPOSMES                                               */
/* !Description     : THRPOSMES component.                                    */
/*                                                                            */
/* !Module          : THRPOSMES                                               */
/* !Description     : Mesure de la position Papillon.                         */
/*                                                                            */
/* !File            : THRPOSMES_SCH.c                                         */
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
/*   1 / Thr_EveRst_PosnMes                                                   */
/*   2 / Thr_EveClcnServo_PosnMes                                             */
/*   3 / Thr_EveTDC_PosnMes                                                   */
/*   4 / Thr_SdlSfty_ThrPosnMes                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6658623 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#068658                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRPOSMES/THRPOSMES_SCH.c_v   $*/
/* $Revision::   1.7                                                         $*/
/* $Author::   wbouach                                $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRPOSMES.h"
#include "THRPOSMES_L.h"
#include "THRPOSMES_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_PosnMes                                         */
/* !Description :  Fonction d'accroche à l'événement reset du calculateur     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04913_001.01                                     */
/*                 VEMS_R_08_04913_011.01                                     */
/*                 VEMS_R_08_04913_012.01                                     */
/*                 VEMS_R_08_04913_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRPOSMES_vidInitOutput();                               */
/*  extf argret void THRPOSMES_vidAcqPosition1();                             */
/*  extf argret void THRPOSMES_vidAcqPosition2();                             */
/*  extf argret void THRPOSMES_vidTpsPosTolerance();                          */
/*  extf argret void THRPOSMES_vidDiagElecCohPosSnsr();                       */
/*  extf argret void THRPOSMES_vidDiagElec();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_PosnMes                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_PosnMes(void)
{
   THRPOSMES_vidInitOutput();
   THRPOSMES_vidAcqPosition1();
   THRPOSMES_vidAcqPosition2();
   THRPOSMES_vidTpsPosTolerance();
   THRPOSMES_vidDiagElecCohPosSnsr();
   THRPOSMES_vidDiagElec();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_PosnMes                                   */
/* !Description :  Fonction d'accroche à l'évenement de calcul de             */
/*                 l'asservissement papillon motorisé (front montant du signal*/
/*                 PWM de commande).                                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04913_001.01                                     */
/*                 VEMS_R_08_04913_011.01                                     */
/*                 VEMS_R_08_04913_012.01                                     */
/*                 VEMS_R_08_04913_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRPOSMES_vidVoltageFilter();                            */
/*  extf argret void THRPOSMES_vidAcqPosition1();                             */
/*  extf argret void THRPOSMES_vidAcqPosition2();                             */
/*  extf argret void THRPOSMES_vidDiagElecCohPosSnsr();                       */
/*  extf argret void THRPOSMES_vidDiagElec();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 THRPOSMES_u8Inhib;                                            */
/*  input boolean Thr_bDgoCohPosnSnsr;                                        */
/*  input boolean Thr_bMonRunCohPosnSnsr;                                     */
/*  input boolean Thr_bMonWaitCohPosnSnsr;                                    */
/*  input boolean Thr_bDgoScpPosnSnsr1;                                       */
/*  input boolean Thr_bMonRunScpPosnSnsr1;                                    */
/*  input boolean Thr_bMonWaitScpPosnSnsr1;                                   */
/*  input boolean Thr_bDgoScgPosnSnsr1;                                       */
/*  input boolean Thr_bMonRunScgPosnSnsr1;                                    */
/*  input boolean Thr_bMonWaitScgPosnSnsr1;                                   */
/*  input boolean Thr_bDgoScgPosnSnsr2;                                       */
/*  input boolean Thr_bMonRunScgPosnSnsr2;                                    */
/*  input boolean Thr_bMonWaitScgPosnSnsr2;                                   */
/*  input boolean Thr_bDgoScpPosnSnsr2;                                       */
/*  input boolean Thr_bMonRunScpPosnSnsr2;                                    */
/*  input boolean Thr_bMonWaitScpPosnSnsr2;                                   */
/*  input boolean Ext_bDgoDftSenr_Thr;                                        */
/*  input boolean Ext_bMonRunDftSenr_Thr;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_PosnMes                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_PosnMes(void)
{
   if (THRPOSMES_u8Inhib != 0x5A)
   {
      THRPOSMES_vidVoltageFilter();
      THRPOSMES_vidAcqPosition1();
      THRPOSMES_vidAcqPosition2();
      THRPOSMES_vidDiagElecCohPosSnsr();
      THRPOSMES_vidDiagElec();
      GDGAR_vidGdu(GD_DFT_COHPOSNSNSR,
                   Thr_bDgoCohPosnSnsr,
                   Thr_bMonRunCohPosnSnsr,
                   Thr_bMonWaitCohPosnSnsr);
      GDGAR_vidGdu(GD_DFT_SCPPOSNSNSR1,
                   Thr_bDgoScpPosnSnsr1,
                   Thr_bMonRunScpPosnSnsr1,
                   Thr_bMonWaitScpPosnSnsr1);
      GDGAR_vidGdu(GD_DFT_SCGPOSNSNSR1,
                   Thr_bDgoScgPosnSnsr1,
                   Thr_bMonRunScgPosnSnsr1,
                   Thr_bMonWaitScgPosnSnsr1);
      GDGAR_vidGdu(GD_DFT_SCGPOSNSNSR2,
                   Thr_bDgoScgPosnSnsr2,
                   Thr_bMonRunScgPosnSnsr2,
                   Thr_bMonWaitScgPosnSnsr2);
      GDGAR_vidGdu(GD_DFT_SCPPOSNSNSR2,
                   Thr_bDgoScpPosnSnsr2,
                   Thr_bMonRunScpPosnSnsr2,
                   Thr_bMonWaitScpPosnSnsr2);
      GDGAR_vidGdu(GD_DFT_DFTSENR_THR,
                   Ext_bDgoDftSenr_Thr,
                   Ext_bMonRunDftSenr_Thr,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveTDC_PosnMes                                         */
/* !Description :  Fonction d'accroche à l'interruption PMH (TDC)             */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04913_001.01                                     */
/*                 VEMS_R_08_04913_011.01                                     */
/*                 VEMS_R_08_04913_012.01                                     */
/*                 VEMS_R_08_04913_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRPOSMES_vidTpsPosTolerance();                          */
/*  input uint8 THRPOSMES_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveTDC_PosnMes                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveTDC_PosnMes(void)
{
   if (THRPOSMES_u8Inhib != 0x5A)
   {
      THRPOSMES_vidTpsPosTolerance();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlSfty_ThrPosnMes                                     */
/* !Description :  Evènement de calcul des fonctions safety de niveau 2       */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04913_001.01                                     */
/*                 VEMS_R_08_04913_011.01                                     */
/*                 VEMS_R_08_04913_012.01                                     */
/*                 VEMS_R_08_04913_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRPOSMES_vidCohPosnSnsrSafetyL2();                      */
/*  extf argret void THRPOSMES_vidSafetyLevel2();                             */
/*  input uint8 THRPOSMES_u8Inhib;                                            */
/*  input boolean Ext_bAcv_ThrSftyLvl2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlSfty_ThrPosnMes                                         */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlSfty_ThrPosnMes(void)
{
   boolean bLocalExt_bAcv_ThrSftyLvl2;


   if (THRPOSMES_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bAcv_ThrSftyLvl2, bLocalExt_bAcv_ThrSftyLvl2);
      if (bLocalExt_bAcv_ThrSftyLvl2 != 0)
      {
         THRPOSMES_vidCohPosnSnsrSafetyL2();
         THRPOSMES_vidSafetyLevel2();
      }
   }
}

/*------------------------------- end of file --------------------------------*/