/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINACQ                                             */
/* !Description     : VLVACTINACQ component.                                  */
/*                                                                            */
/* !Module          : VLVACTINACQ                                             */
/* !Description     : ACQUISITION DU DECALAGE ET CALCUL DE LA VITESSE DE      */
/*                    DECALAGE DE LA VVT D'ADMISSION                          */
/*                                                                            */
/* !File            : VLVACTINACQ_SCH.C                                       */
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
/*   1 / VLVACTINACQ_vidEntryInit                                             */
/*   2 / VlvAct_EveInCmToo_InAcq                                              */
/*   3 / VlvAct_EveCkSnOn_InAcq                                               */
/*   4 / VlvAct_EveTDC_InAcq                                                  */
/*   5 / VlvAct_EveKOn_InAcq                                                  */
/*   6 / VlvAct_EveInCam_InAcq                                                */
/*   7 / VlvAct_SdlFast_InAcq                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6588653 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTIN/VLVACTINACQ/VLVACT$*/
/* $Revision::   1.21     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VLVACTINACQ.h"
#include "VLVACTINACQ_L.h"
#include "VLVACTINACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidEntryInit                                   */
/* !Description :  Fonction d'accroche moniteur pour le Reset du calculateur  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACQ_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_InAcq                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidEntryInit(void)
{
   VLVACTINACQ_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveInCmToo_InAcq                                    */
/* !Description :  Fonction d'accroche à l'evenement VlvAct_EveInCmToo_InAcq  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_08_05855_004.01                                     */
/*                 VEMS_E_08_05855_005.01                                     */
/*                 VEMS_E_08_05855_006.01                                     */
/*                 VEMS_R_08_05855_001.02                                     */
/*                 VEMS_R_08_05855_002.01                                     */
/*                 VEMS_R_08_05855_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACQ_vidCamTargetState();                         */
/*  extf argret void VLVACTINACQ_vidCurrentShift();                           */
/*  extf argret void VLVACTINACQ_vidCurrentVelocity();                        */
/*  extf argret void GDGAR_vidGdu(argin uint8 indexDefaut,argin boolean       */
/* bDgo,argin boolean bMonRun,argin boolean bDiagStWait);                     */
/*  input boolean Ctrl_bCmInAcq;                                              */
/*  input uint8 VLVACTINACQ_u8Inhib;                                          */
/*  input boolean VlvAct_bDgoORngShiftVlvActIn;                               */
/*  input boolean VlvAct_bMonRunORngShiftVlvActIn;                            */
/*  input boolean VlvAct_bDgoORngSpdVlvActIn;                                 */
/*  input boolean VlvAct_bMonRunORngSpdVlvActIn;                              */
/*  input boolean VlvAct_bDgoMissToothVlvActIn;                               */
/*  input boolean VlvAct_bMonRunMissToothVlvActIn;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveInCmToo_InAcq                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveInCmToo_InAcq(void)
{
   boolean bLocalCtrl_bCmInAcq;


   VEMS_vidGET(Ctrl_bCmInAcq, bLocalCtrl_bCmInAcq);

   if (VLVACTINACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmInAcq != 0)
      {
         VLVACTINACQ_vidCamTargetState();
         VLVACTINACQ_vidCurrentShift();
         VLVACTINACQ_vidCurrentVelocity();
         GDGAR_vidGdu(GD_DFT_ORNGSHIFTVLVACTIN,
                      VlvAct_bDgoORngShiftVlvActIn,
                      VlvAct_bMonRunORngShiftVlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNGSPDVLVACTIN,
                      VlvAct_bDgoORngSpdVlvActIn,
                      VlvAct_bMonRunORngSpdVlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_MISSTOOTHVLVACTIN,
                      VlvAct_bDgoMissToothVlvActIn,
                      VlvAct_bMonRunMissToothVlvActIn,
                      DIAG_DISPO);
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveCkSnOn_InAcq                                     */
/* !Description :  Fonction d'accroche à l'evenement VlvAct_EveCkSnOn_InAcq   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_08_05855_004.01                                     */
/*                 VEMS_E_08_05855_005.01                                     */
/*                 VEMS_E_08_05855_006.01                                     */
/*                 VEMS_R_08_05855_001.02                                     */
/*                 VEMS_R_08_05855_002.01                                     */
/*                 VEMS_R_08_05855_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACQ_vidInit();                                   */
/*  extf argret void VLVACTINACQ_vidIntakeResynchro();                        */
/*  input boolean Ctrl_bCmInAcq;                                              */
/*  input uint8 VLVACTINACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveCkSnOn_InAcq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveCkSnOn_InAcq(void)
{
   boolean bLocalCtrl_bCmInAcq;


   VEMS_vidGET(Ctrl_bCmInAcq, bLocalCtrl_bCmInAcq);

   if (VLVACTINACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmInAcq != 0)
      {
         VLVACTINACQ_vidInit();
         VLVACTINACQ_vidIntakeResynchro();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveTDC_InAcq                                        */
/* !Description :  Fonction d'accroche à l'evenement VlvAct_EveTDC_InAcq      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_08_05855_004.01                                     */
/*                 VEMS_E_08_05855_005.01                                     */
/*                 VEMS_E_08_05855_006.01                                     */
/*                 VEMS_R_08_05855_001.02                                     */
/*                 VEMS_R_08_05855_002.01                                     */
/*                 VEMS_R_08_05855_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACQ_vidIntakePmhDiag();                          */
/*  extf argret void GDGAR_vidGdu(argin uint8 indexDefaut,argin boolean       */
/* bDgo,argin boolean bMonRun,argin boolean bDiagStWait);                     */
/*  input boolean Ctrl_bCmInAcq;                                              */
/*  input uint8 VLVACTINACQ_u8Inhib;                                          */
/*  input boolean VlvAct_bDgoTDCDiagVlvActIn;                                 */
/*  input boolean VlvAct_bMonRunTDCDiagVlvActIn;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveTDC_InAcq                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveTDC_InAcq(void)
{
   boolean bLocalCtrl_bCmInAcq;


   VEMS_vidGET(Ctrl_bCmInAcq, bLocalCtrl_bCmInAcq);
   if (VLVACTINACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmInAcq != 0)
      {
         VLVACTINACQ_vidIntakePmhDiag ();
         GDGAR_vidGdu(GD_DFT_TDCDIAGVLVACTIN,
                     VlvAct_bDgoTDCDiagVlvActIn,
                     VlvAct_bMonRunTDCDiagVlvActIn,
                     DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveKOn_InAcq                                        */
/* !Description :  Fonction d'accroche à l'evenement VlvAct_EveKOn_InAcq      */
/* !Number      :  SCH.5                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_08_05855_004.01                                     */
/*                 VEMS_E_08_05855_005.01                                     */
/*                 VEMS_E_08_05855_006.01                                     */
/*                 VEMS_R_08_05855_001.02                                     */
/*                 VEMS_R_08_05855_002.01                                     */
/*                 VEMS_R_08_05855_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACQ_vidInitPannes();                             */
/*  input boolean Ctrl_bCmInAcq;                                              */
/*  input uint8 VLVACTINACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveKOn_InAcq                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveKOn_InAcq(void)
{
   boolean bLocalCtrl_bCmInAcq;


   VEMS_vidGET(Ctrl_bCmInAcq, bLocalCtrl_bCmInAcq);

   if (VLVACTINACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmInAcq != 0)
      {
         VLVACTINACQ_vidInitPannes();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveInCam_InAcq                                      */
/* !Description :  Evénement "InCam" pour l'arbre à cames admission.          */
/* !Number      :  SCH.6                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_08_05855_004.01                                     */
/*                 VEMS_E_08_05855_005.01                                     */
/*                 VEMS_E_08_05855_006.01                                     */
/*                 VEMS_R_08_05855_001.02                                     */
/*                 VEMS_R_08_05855_002.01                                     */
/*                 VEMS_R_08_05855_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACQ_vidIntCamshaftEdge();                        */
/*  input boolean Ctrl_bCmInAcq;                                              */
/*  input uint8 VLVACTINACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveInCam_InAcq                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveInCam_InAcq(void)
{
   boolean bLocalCtrl_bCmInAcq;


   VEMS_vidGET(Ctrl_bCmInAcq, bLocalCtrl_bCmInAcq);

   if (VLVACTINACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmInAcq != 0)
      {
         VLVACTINACQ_vidIntCamshaftEdge();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InAcq                                       */
/* !Description :  Moniteur rapide pour la fonction VLVACTINACQ.              */
/* !Number      :  SCH.7                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_08_05855_004.01                                     */
/*                 VEMS_E_08_05855_005.01                                     */
/*                 VEMS_E_08_05855_006.01                                     */
/*                 VEMS_R_08_05855_001.02                                     */
/*                 VEMS_R_08_05855_002.01                                     */
/*                 VEMS_R_08_05855_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACQ_vidORngShiftbMonRun();                       */
/*  extf argret void VLVACTINACQ_vidMissToothbMonRun();                       */
/*  extf argret void VLVACTINACQ_vidORngSpdVlvbMonRun();                      */
/*  extf argret void VLVACTINACQ_vidTDCDiagbMonRun();                         */
/*  extf argret void VLVACTINACQ_vidCamEngineSpeed();                         */
/*  input boolean Ctrl_bCmInAcq;                                              */
/*  input uint8 VLVACTINACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InAcq                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InAcq(void)
{
   boolean bLocalCtrl_bCmInAcq;


   VEMS_vidGET(Ctrl_bCmInAcq, bLocalCtrl_bCmInAcq);

   if (VLVACTINACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmInAcq != 0)
      {
         VLVACTINACQ_vidORngShiftbMonRun();
         VLVACTINACQ_vidMissToothbMonRun();
         VLVACTINACQ_vidORngSpdVlvbMonRun();
         VLVACTINACQ_vidTDCDiagbMonRun();
         VLVACTINACQ_vidCamEngineSpeed();
      }
   }
}
/*------------------------------- end of file --------------------------------*/