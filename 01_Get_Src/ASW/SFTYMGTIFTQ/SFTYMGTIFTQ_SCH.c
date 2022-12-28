/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYMGTIFTQ                                             */
/* !Description     : SFTYMGTIFTQ component.                                  */
/*                                                                            */
/* !Module          : SFTYMGTIFTQ                                             */
/* !Description     : SAFETY TMS: interface avec LDA/LDB de la structure      */
/*                    d'accueil                                               */
/*                                                                            */
/* !File            : SFTYMGTIFTQ_SCH.C                                       */
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
/*   1 / SftyMgt_EveRst_ifTqMon                                               */
/*   2 / SftyMgt_EveTDC_ifTqMon                                               */
/*   3 / SftyMgt_EveChkLih_ifTqMon                                            */
/*   4 / SftyMgt_SdlFast_ifTqMon                                              */
/*   5 / SftyMgt_SdlMid_ifTqMon                                               */
/*   6 / SftyMgt_EveRxn329_ifTqMon                                            */
/*   7 / SftyMgt_EveRxn349_ifTqMon                                            */
/*   8 / SftyMgt_EveRxn34D_ifTqMon                                            */
/*   9 / SftyMgt_EveRxn38D_ifTqMon                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5147394 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SFTYMGTIFTQ/SFTYMGTIFTQ_SCH1.C_v  $*/
/* $Revision::   1.4      $$Author::   hmelloul       $$Date::   21 Mar 2011 $*/
/* $Author::   hmelloul                               $$Date::   21 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "SFTYMGTIFTQ.h"
#include "SFTYMGTIFTQ_L.h"
#include "GDGAR.h"
#include "SFTYMGTIFTQ_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRst_ifTqMon                                     */
/* !Description :  Evènement reset de la fonction ifTqMon                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidInitOutput();                             */
/*  extf argret void SFTYMGTIFTQ_vidInitOutput1();                            */
/*  extf argret void SFTYMGTIFTQ_vidInpIgTqRelzd();                           */
/*  extf argret void SFTYMGTIFTQ_vidNoProdTqMon();                            */
/*  extf argret void SFTYMGTIFTQ_vidInhSftylvl2Afts();                        */
/*  extf argret void SFTYMGTIFTQ_vidEeprom();                                 */
/*  extf argret void SFTYMGTIFTQ_vidSensInpCkSftyLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidInpChkLvl2();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRst_ifTqMon                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRst_ifTqMon(void)
{
   SFTYMGTIFTQ_vidInitOutput();
   SFTYMGTIFTQ_vidInitOutput1();
   SFTYMGTIFTQ_vidInpIgTqRelzd();
   SFTYMGTIFTQ_vidNoProdTqMon();
   SFTYMGTIFTQ_vidInhSftylvl2Afts();
   SFTYMGTIFTQ_vidEeprom();
   SFTYMGTIFTQ_vidSensInpCkSftyLvl2();
   SFTYMGTIFTQ_vidInpChkLvl2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveTDC_ifTqMon                                     */
/* !Description :  Evènement TDC                                              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidInpIgTqRelzd();                           */
/*  input uint8 SFTYMGTIFTQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveTDC_ifTqMon                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveTDC_ifTqMon(void)
{
   if (SFTYMGTIFTQ_u8Inhib != 0x5A)
   {
      SFTYMGTIFTQ_vidInpIgTqRelzd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveChkLih_ifTqMon                                  */
/* !Description :  Evènement d'autorisation des tests fonctionnels            */
/*                 d'inhibition                                               */
/* !Number      :  SCH.3                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidDftAutChkIni();                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 SFTYMGTIFTQ_u8Inhib;                                          */
/*  input boolean SftyMgt_bDgoInhChkInitSfty;                                 */
/*  input boolean SftyMgt_bMonRunInhChkInitSfty;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveChkLih_ifTqMon                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveChkLih_ifTqMon(void)
{
   if (SFTYMGTIFTQ_u8Inhib != 0x5A)
   {
      SFTYMGTIFTQ_vidDftAutChkIni();
      GDGAR_vidGdu(GD_DFT_INHCHKINITSFTY,
                   SftyMgt_bDgoInhChkInitSfty,
                   SftyMgt_bMonRunInhChkInitSfty,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlFast_ifTqMon                                    */
/* !Description :  Evènement SdlFast.                                         */
/* !Number      :  SCH.4                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidSndDftLvl3();                             */
/*  extf argret void SFTYMGTIFTQ_vidInpInjTqRelzd();                          */
/*  input uint8 SFTYMGTIFTQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlFast_ifTqMon                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlFast_ifTqMon(void)
{
   if (SFTYMGTIFTQ_u8Inhib != 0x5A)
   {
      SFTYMGTIFTQ_vidSndDftLvl3();
      SFTYMGTIFTQ_vidInpInjTqRelzd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_ifTqMon                                     */
/* !Description :  Evènement SdlMid.                                          */
/* !Number      :  SCH.5                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_010.01                                     */
/*                 VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SFTYMGTIFTQ_vidDiagInpLvl2An();                          */
/*  extf argret void SFTYMGTIFTQ_vidDiagInpLvl2An_1();                        */
/*  extf argret void SFTYMGTIFTQ_vidDiagSensAcquiLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidFstftLvl3();                              */
/*  extf argret void SFTYMGTIFTQ_vidRam_uncleared();                          */
/*  extf argret void SFTYMGTIFTQ_vidRst();                                    */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void SFTYMGTIFTQ_vidInhSftylvl2Afts();                        */
/*  extf argret void SFTYMGTIFTQ_vidSensInpCkSftyLvl2();                      */
/*  extf argret void SFTYMGTIFTQ_vidInpChkLvl2();                             */
/*  input boolean SftyMgt_bDgoIrvSTT;                                         */
/*  input boolean SftyMgt_bMonRunIrvSTT;                                      */
/*  input boolean SftyMgt_bDgoRvLih;                                          */
/*  input boolean SftyMgt_bMonRunRvLih;                                       */
/*  input boolean SftyMgt_bDgoIrvVSCtl;                                       */
/*  input boolean SftyMgt_bMonRunIrvVSCtl;                                    */
/*  input boolean SftyMgt_bDgoIrvEM;                                          */
/*  input boolean SftyMgt_bMonRunIrvEM;                                       */
/*  input boolean SftyMgt_bDgoIrvECU;                                         */
/*  input boolean SftyMgt_bMonRunIrvECU;                                      */
/*  input boolean SftyMgt_bDgoDrvTra;                                         */
/*  input boolean SftyMgt_bMonRunDrvTra;                                      */
/*  input boolean SftyMgt_bDgoInhEngStopSTT;                                  */
/*  input boolean SftyMgt_bMonRunInhEngStopSTT;                               */
/*  input uint8 SFTYMGTIFTQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_ifTqMon                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_ifTqMon(void)
{
   boolean bLocalSftyMgt_bDgoIrvSTT;
   boolean bLocalSftyMgt_bMonRunIrvSTT;
   boolean bLocalSftyMgt_bDgoRvLih;
   boolean bLocalSftyMgt_bMonRunRvLih;
   boolean bLocalSftyMgt_bDgoIrvVSCtl;
   boolean bLocalSftyMgt_bMonRunIrvVSCtl;
   boolean bLocalSftyMgt_bDgoIrvEM;
   boolean bLocalSftyMgt_bMonRunIrvEM;
   boolean bLocalSftyMgt_bDgoIrvECU;
   boolean bLocalSftyMgt_bMonRunIrvECU;
   boolean bLocalSftyMgt_bDgoDrvTra;
   boolean bLocalSftyMgt_bMonRunDrvTra;
   boolean bLocalSftyMgt_bDgoInhEngStopSTT;
   boolean bLocalSftyMgt_bMonRunEngStopSTT;


   VEMS_vidGET(SftyMgt_bDgoIrvSTT, bLocalSftyMgt_bDgoIrvSTT);
   VEMS_vidGET(SftyMgt_bMonRunIrvSTT, bLocalSftyMgt_bMonRunIrvSTT);
   VEMS_vidGET(SftyMgt_bDgoRvLih, bLocalSftyMgt_bDgoRvLih);
   VEMS_vidGET(SftyMgt_bMonRunRvLih, bLocalSftyMgt_bMonRunRvLih);
   VEMS_vidGET(SftyMgt_bDgoIrvVSCtl, bLocalSftyMgt_bDgoIrvVSCtl);
   VEMS_vidGET(SftyMgt_bMonRunIrvVSCtl, bLocalSftyMgt_bMonRunIrvVSCtl);
   VEMS_vidGET(SftyMgt_bDgoIrvEM, bLocalSftyMgt_bDgoIrvEM);
   VEMS_vidGET(SftyMgt_bMonRunIrvEM, bLocalSftyMgt_bMonRunIrvEM);
   VEMS_vidGET(SftyMgt_bDgoIrvECU, bLocalSftyMgt_bDgoIrvECU);
   VEMS_vidGET(SftyMgt_bMonRunIrvECU, bLocalSftyMgt_bMonRunIrvECU);
   VEMS_vidGET(SftyMgt_bDgoDrvTra, bLocalSftyMgt_bDgoDrvTra);
   VEMS_vidGET(SftyMgt_bMonRunDrvTra, bLocalSftyMgt_bMonRunDrvTra);
   VEMS_vidGET(SftyMgt_bDgoInhEngStopSTT, bLocalSftyMgt_bDgoInhEngStopSTT);
   VEMS_vidGET(SftyMgt_bMonRunInhEngStopSTT, bLocalSftyMgt_bMonRunEngStopSTT);

   if (SFTYMGTIFTQ_u8Inhib != 0x5A)
   {
      SFTYMGTIFTQ_vidDiagInpLvl2An();
      SFTYMGTIFTQ_vidDiagInpLvl2An_1();
      SFTYMGTIFTQ_vidDiagSensAcquiLvl2();
      SFTYMGTIFTQ_vidFstftLvl3();
      SFTYMGTIFTQ_vidRam_uncleared();
      SFTYMGTIFTQ_vidRst();

      GDGAR_vidGdu(GD_DFT_DRVTRA,
                   bLocalSftyMgt_bDgoDrvTra,
                   bLocalSftyMgt_bMonRunDrvTra,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_INHENGSTOPSTT,
                   bLocalSftyMgt_bDgoInhEngStopSTT,
                   bLocalSftyMgt_bMonRunEngStopSTT,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_IRVSTT,
                   bLocalSftyMgt_bDgoIrvSTT,
                   bLocalSftyMgt_bMonRunIrvSTT,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_RVLIH,
                   bLocalSftyMgt_bDgoRvLih,
                   bLocalSftyMgt_bMonRunRvLih,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_IRVVSCTL,
                   bLocalSftyMgt_bDgoIrvVSCtl,
                   bLocalSftyMgt_bMonRunIrvVSCtl,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_IRVEM,
                   bLocalSftyMgt_bDgoIrvEM,
                   bLocalSftyMgt_bMonRunIrvEM,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_IRVECU,
                   bLocalSftyMgt_bDgoIrvECU,
                   bLocalSftyMgt_bMonRunIrvECU,
                   DIAG_DISPO);
      SFTYMGTIFTQ_vidInhSftylvl2Afts();
      SFTYMGTIFTQ_vidSensInpCkSftyLvl2();
      SFTYMGTIFTQ_vidInpChkLvl2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRxn329_ifTqMon                                  */
/* !Description :  Evénement de réception de la trame 329h                    */
/* !Number      :  SCH.6                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidF329RxLvl2();                             */
/*  extf argret void SFTYMGTIFTQ_vidF329SftyLevel2();                         */
/*  input uint8 SFTYMGTIFTQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRxn329_ifTqMon                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRxn329_ifTqMon(void)
{
   if (SFTYMGTIFTQ_u8Inhib != 0x5A)
   {
      SFTYMGTIFTQ_vidF329RxLvl2();
      SFTYMGTIFTQ_vidF329SftyLevel2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRxn349_ifTqMon                                  */
/* !Description :  Evenement de reception de la trame 349                     */
/* !Number      :  SCH.7                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidF349RxLvl2();                             */
/*  extf argret void SFTYMGTIFTQ_vidF349SftyLevel2();                         */
/*  input uint8 SFTYMGTIFTQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRxn349_ifTqMon                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRxn349_ifTqMon(void)
{
   if (SFTYMGTIFTQ_u8Inhib != 0x5A)
   {
      SFTYMGTIFTQ_vidF349RxLvl2();
      SFTYMGTIFTQ_vidF349SftyLevel2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRxn34D_ifTqMon                                  */
/* !Description :  Evénement d'interface (réception de trame 34Dh).           */
/* !Number      :  SCH.8                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidF34DSftyLevel2();                         */
/*  input uint8 SFTYMGTIFTQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRxn34D_ifTqMon                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRxn34D_ifTqMon(void)
{
   if (SFTYMGTIFTQ_u8Inhib != 0x5A)
   {
      SFTYMGTIFTQ_vidF34DSftyLevel2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_EveRxn38D_ifTqMon                                  */
/* !Description :  Evénement de réception de la trame 38Dh                    */
/* !Number      :  SCH.9                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_11_05663_013.02                                     */
/*                 VEMS_R_11_05663_014.01                                     */
/*                 VEMS_R_11_05663_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMGTIFTQ_vidF38DRxLvl2();                             */
/*  extf argret void SFTYMGTIFTQ_vidF38DSftyLevel2();                         */
/*  input uint8 SFTYMGTIFTQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_EveRxn38D_ifTqMon                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_EveRxn38D_ifTqMon(void)
{
   if (SFTYMGTIFTQ_u8Inhib != 0x5A)
   {
      SFTYMGTIFTQ_vidF38DRxLvl2();
      SFTYMGTIFTQ_vidF38DSftyLevel2();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/