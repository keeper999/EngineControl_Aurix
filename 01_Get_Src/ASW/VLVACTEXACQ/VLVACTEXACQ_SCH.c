/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXACQ                                             */
/* !Description     : VLVACTEXACQ Component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXACQ                                             */
/* !Description     : Acquisition du Décalage et Calcul de la Vitesse de      */
/*                    Décalage de la VVT d’échappement                        */
/*                                                                            */
/* !File            : VLVACTEXACQ_SCH.C                                       */
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
/*   1 / VLVACTEXACQ_vidEntryInit                                             */
/*   2 / VlvAct_EveExCmToo_ExAcq                                              */
/*   3 / VlvAct_EveCkSnOn_ExAcq                                               */
/*   4 / VlvAct_EveTDC_ExAcq                                                  */
/*   5 / VlvAct_EveKOn_ExAcq                                                  */
/*   6 / VlvAct_EveExCam_ExAcq                                                */
/*   7 / VlvAct_SdlFast_ExAcq                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6588648 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTEX/VLVACTEXACQ/VLVACT$*/
/* $Revision::   1.21     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VLVACTEXACQ.h"
#include "VLVACTEXACQ_L.h"
#include "VLVACTEXACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidEntryInit                                   */
/* !Description :  Foction d'accroche moniteur pour le Reset du calculateur   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXACQ_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_ExAcq                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidEntryInit(void)
{
   VLVACTEXACQ_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveExCmToo_ExAcq                                    */
/* !Description :  Fonction d'accroche à l'evenement VlvAct_EveExCmToo_ExAcq  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05907_001.02                                     */
/*                 VEMS_R_08_05907_002.01                                     */
/*                 VEMS_R_08_05907_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACQ_vidCamTargetState();                         */
/*  extf argret void VLVACTEXACQ_vidCurrentShift();                           */
/*  extf argret void VLVACTEXACQ_vidCurrentVelocity();                        */
/*  extf argret void GDGAR_vidGdu(argin uint8 indexDefaut,argin boolean       */
/* bDgo,argin boolean bMonRun,argin boolean bDiagStWait);                     */
/*  input boolean Ctrl_bCmExAcq;                                              */
/*  input uint8 VLVACTEXACQ_u8Inhib;                                          */
/*  input boolean VlvAct_bDgoORngShiftVlvActEx;                               */
/*  input boolean VlvAct_bMonRunORngShiftVlvActEx;                            */
/*  input boolean VlvAct_bDgoORngSpdVlvActEx;                                 */
/*  input boolean VlvAct_bMonRunORngSpdVlvActEx;                              */
/*  input boolean VlvAct_bDgoMissToothVlvActEx;                               */
/*  input boolean VlvAct_bMonRunMissToothVlvActEx;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveExCmToo_ExAcq                                        */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveExCmToo_ExAcq(void)
{
   boolean bLocalCtrl_bCmExAcq;


   VEMS_vidGET(Ctrl_bCmExAcq, bLocalCtrl_bCmExAcq);

   if (VLVACTEXACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmExAcq != 0)
      {
         VLVACTEXACQ_vidCamTargetState();
         VLVACTEXACQ_vidCurrentShift();
         VLVACTEXACQ_vidCurrentVelocity();
         GDGAR_vidGdu(GD_DFT_ORNGSHIFTVLVACTEX,
                      VlvAct_bDgoORngShiftVlvActEx,
                      VlvAct_bMonRunORngShiftVlvActEx,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNGSPDVLVACTEX,
                      VlvAct_bDgoORngSpdVlvActEx,
                      VlvAct_bMonRunORngSpdVlvActEx,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_MISSTOOTHVLVACTEX,
                      VlvAct_bDgoMissToothVlvActEx,
                      VlvAct_bMonRunMissToothVlvActEx,
                      DIAG_DISPO);
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveCkSnOn_ExAcq                                     */
/* !Description :  Fonction d'accroche à l'evenement VlvAct_EveCkSnOn_ExAcq   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05907_001.02                                     */
/*                 VEMS_R_08_05907_002.01                                     */
/*                 VEMS_R_08_05907_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACQ_vidInit();                                   */
/*  extf argret void VLVACTEXACQ_vidExhaustResynchro();                       */
/*  input boolean Ctrl_bCmExAcq;                                              */
/*  input uint8 VLVACTEXACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveCkSnOn_ExAcq                                         */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveCkSnOn_ExAcq(void)
{
   boolean bLocalCtrl_bCmExAcq;


   VEMS_vidGET(Ctrl_bCmExAcq, bLocalCtrl_bCmExAcq);

   if (VLVACTEXACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmExAcq != 0)
      {
         VLVACTEXACQ_vidInit();
         VLVACTEXACQ_vidExhaustResynchro();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveTDC_ExAcq                                        */
/* !Description :  Fonction d'accroche à l'evenement VlvAct_EveTDC_ExAcq      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05907_001.02                                     */
/*                 VEMS_R_08_05907_002.01                                     */
/*                 VEMS_R_08_05907_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACQ_vidExhaustPmhDiag();                         */
/*  extf argret void GDGAR_vidGdu(argin uint8 indexDefaut,argin boolean       */
/* bDgo,argin boolean bMonRun,argin boolean bDiagStWait);                     */
/*  input boolean Ctrl_bCmExAcq;                                              */
/*  input uint8 VLVACTEXACQ_u8Inhib;                                          */
/*  input boolean VlvAct_bDgoTDCDiagVlvActEx;                                 */
/*  input boolean VlvAct_bMonRunTDCDiagVlvActEx;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveTDC_ExAcq                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveTDC_ExAcq(void)
{
   boolean bLocalCtrl_bCmExAcq;


   VEMS_vidGET(Ctrl_bCmExAcq, bLocalCtrl_bCmExAcq);

   if (VLVACTEXACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmExAcq != 0)
      {
         VLVACTEXACQ_vidExhaustPmhDiag ();
         GDGAR_vidGdu(GD_DFT_TDCDIAGVLVACTEX,
                      VlvAct_bDgoTDCDiagVlvActEx,
                      VlvAct_bMonRunTDCDiagVlvActEx,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveKOn_ExAcq                                        */
/* !Description :  Fonction d'accroche à l'evenement VlvAct_EveKOn_ExAcq      */
/* !Number      :  SCH.5                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05907_001.02                                     */
/*                 VEMS_R_08_05907_002.01                                     */
/*                 VEMS_R_08_05907_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACQ_vidInitPannes();                             */
/*  input boolean Ctrl_bCmExAcq;                                              */
/*  input uint8 VLVACTEXACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveKOn_ExAcq                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveKOn_ExAcq(void)
{
   boolean bLocalCtrl_bCmExAcq;


   VEMS_vidGET(Ctrl_bCmExAcq, bLocalCtrl_bCmExAcq);

   if (VLVACTEXACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmExAcq != 0)
      {
         VLVACTEXACQ_vidInitPannes();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveExCam_ExAcq                                      */
/* !Description :  Evénement "ExCam" pour l'arbre à cames échappement.        */
/* !Number      :  SCH.6                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05907_001.02                                     */
/*                 VEMS_R_08_05907_002.01                                     */
/*                 VEMS_R_08_05907_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACQ_vidIntCamshaftEdge();                        */
/*  input boolean Ctrl_bCmExAcq;                                              */
/*  input uint8 VLVACTEXACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveExCam_ExAcq                                          */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveExCam_ExAcq(void)
{
   boolean bLocalCtrl_bCmExAcq;


   VEMS_vidGET(Ctrl_bCmExAcq, bLocalCtrl_bCmExAcq);

   if (VLVACTEXACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmExAcq != 0)
      {
         VLVACTEXACQ_vidIntCamshaftEdge();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExAcq                                       */
/* !Description :  Moniteur rapide.                                           */
/* !Number      :  SCH.7                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05907_001.02                                     */
/*                 VEMS_R_08_05907_002.01                                     */
/*                 VEMS_R_08_05907_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACQ_vidORngShiftbMonRun();                       */
/*  extf argret void VLVACTEXACQ_vidMissToothbMonRun();                       */
/*  extf argret void VLVACTEXACQ_vidORngSpdVlvbMonRun();                      */
/*  extf argret void VLVACTEXACQ_vidTDCDiagbMonRun();                         */
/*  extf argret void VLVACTEXACQ_vidExCamEngineSpd();                         */
/*  input boolean Ctrl_bCmExAcq;                                              */
/*  input uint8 VLVACTEXACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExAcq                                           */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExAcq(void)
{
   boolean bLocalCtrl_bCmExAcq;


   VEMS_vidGET(Ctrl_bCmExAcq, bLocalCtrl_bCmExAcq);
   if (VLVACTEXACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bCmExAcq != 0)
      {
         VLVACTEXACQ_vidORngShiftbMonRun();
         VLVACTEXACQ_vidMissToothbMonRun();
         VLVACTEXACQ_vidORngSpdVlvbMonRun();
         VLVACTEXACQ_vidTDCDiagbMonRun();
         VLVACTEXACQ_vidExCamEngineSpd();
      }
   }
}
/*------------------------------- end of file --------------------------------*/