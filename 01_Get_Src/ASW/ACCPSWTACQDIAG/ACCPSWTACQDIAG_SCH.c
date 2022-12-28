/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPSWTACQDIAG                                          */
/* !Description     : ACCPSWTACQDIAG Component                                */
/*                                                                            */
/* !Module          : ACCPSWTACQDIAG                                          */
/* !Description     : IMPLEMENTATION DU TRAITEMENT DU CONTACTEUR ELECTRIQUE   */
/*                    LVV                                                     */
/*                                                                            */
/* !File            : ACCPSWTACQDIAG_SCH.C                                    */
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
/*   1 / AccP_EveRst_SwtAcqDiag                                               */
/*   2 / AccP_SdlFast_SwtAcqDiag                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6606841 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#050819                                         */
/* !OtherRefs   : VEMS V02 ECU#068754                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCP/ACCPSWTACQDIAG/ACCPSWTACQDIAG$*/
/* $Revision::   1.9      $$Author::   wbouach        $$Date::   27 May 2014 $*/
/* $Author::   wbouach                                $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "ACCPSWTACQDIAG.H"
#include "ACCPSWTACQDIAG_L.H"
#include "ACCPSWTACQDIAG_IM.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRst_SwtAcqDiag                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPSWTACQDIAG_vidInitOutput();                          */
/*  extf argret void ACCPSWTACQDIAG_vidInitPointDur();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_EveRst_SwtAcqDiag                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRst_SwtAcqDiag(void)
{
   ACCPSWTACQDIAG_vidInitOutput();
   ACCPSWTACQDIAG_vidInitPointDur();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_SwtAcqDiag                                    */
/* !Description :  Moniteur rapide pour la fonction pédale                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPSWTACQDIAG_vidPtDurSensDetec();                      */
/*  extf argret void ACCPSWTACQDIAG_vidLvvSwtAcqCond();                       */
/*  extf argret void ACCPSWTACQDIAG_vidLvvSwtDiagCond();                      */
/*  extf argret void ACCPSWTACQDIAG_vidMonitorMngCond();                      */
/*  extf argret void ACCPSWTACQDIAG_vidEndPointCohAff();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 ACCPSWTACQDIAG_u8Inhib;                                       */
/*  input boolean AccP_bHdPtSen;                                              */
/*  input boolean AccP_bDgoScpAccPSwt;                                        */
/*  input boolean AccP_bMonRunScpAccPSwt;                                     */
/*  input boolean AccP_bDgoStuckAccPSwt;                                      */
/*  input boolean AccP_bMonRunStuckAccPSwt;                                   */
/*  input boolean AccP_bDgoScgAccPSwt;                                        */
/*  input boolean AccP_bMonRunScgAccPSwt;                                     */
/*  input boolean AccP_bDgoCohAccPSwt;                                        */
/*  input boolean AccP_bMonRunCohAccPSwt;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_SdlFast_SwtAcqDiag                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_SwtAcqDiag(void)
{
   boolean bLocalAccP_bHdPtSen;


   if (ACCPSWTACQDIAG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(AccP_bHdPtSen, bLocalAccP_bHdPtSen);
      if (bLocalAccP_bHdPtSen != 0)
      {
         ACCPSWTACQDIAG_vidPtDurSensDetec();
      }
      else
      {
         ACCPSWTACQDIAG_vidLvvSwtAcqCond();
         ACCPSWTACQDIAG_vidLvvSwtDiagCond();
         ACCPSWTACQDIAG_vidMonitorMngCond();
         ACCPSWTACQDIAG_vidEndPointCohAff();

         GDGAR_vidGdu(GD_DFT_SCPACCPSWT,
                      AccP_bDgoScpAccPSwt,
                      AccP_bMonRunScpAccPSwt,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_STUCKACCPSWT,
                      AccP_bDgoStuckAccPSwt,
                      AccP_bMonRunStuckAccPSwt,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_SCGACCPSWT,
                      AccP_bDgoScgAccPSwt,
                      AccP_bMonRunScgAccPSwt,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_COHACCPSWT,
                      AccP_bDgoCohAccPSwt,
                      AccP_bMonRunCohAccPSwt,
                      DIAG_DISPO);
      }
   }
}

/*------------------------------- end of file --------------------------------*/