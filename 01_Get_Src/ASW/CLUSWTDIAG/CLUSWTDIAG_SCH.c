/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLUSWTDIAG                                              */
/* !Description     : CLUSWTDIAG Component                                    */
/*                                                                            */
/* !Module          : CLUSWTDIAG                                              */
/* !Description     : Diagnostic switch embrayage                             */
/*                                                                            */
/* !File            : CLUSWTDIAG_SCH.C                                        */
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
/*   1 / Clu_EveRst_CluSwtDiag                                                */
/*   2 / Clu_EveKOn_CluSwtDiag                                                */
/*   3 / Clu_EveCrTR_CluSwtDiag                                               */
/*   4 / Clu_SdlMid_CluSwtDiag                                                */
/*   5 / Clu_SdlSlow_CluSwtDiag                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 04680 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#045677                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CLUSWTDIAG/CLUSWTDIAG_SCH.C_v     $*/
/* $Revision::   1.4      $$Author::   ACHEBINO       $$Date::   12 Jul 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   12 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "CLUSWTDIAG.H"
#include "CLUSWTDIAG_L.H"
#include "CLUSWTDIAG_IM.H"
#include "GDGAR.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_EveRst_CluSwtDiag                                      */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUSWTDIAG_vidInit();                                    */
/*  extf argret void CLUSWTDIAG_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_EveRst_CluSwtDiag(void)
{
   CLUSWTDIAG_vidInit();
   CLUSWTDIAG_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_EveKOn_CluSwtDiag                                      */
/* !Description :  Evénement associé au passge de clef OFF à clef ON          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUSWTDIAG_vidEventFlagOn();                             */
/*  extf argret void CLUSWTDIAG_vidDiagCohMonitoring();                       */
/*  extf argret void CLUSWTDIAG_vidInitDiagStuck();                           */
/*  input uint8 CLUSWTDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_EveKOn_CluSwtDiag(void)
{
   if (CLUSWTDIAG_u8Inhib != 0x5A)
   {
      CLUSWTDIAG_vidEventFlagOn();
      CLUSWTDIAG_vidDiagCohMonitoring();
      CLUSWTDIAG_vidInitDiagStuck();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_EveCrTR_CluSwtDiag                                     */
/* !Description :  Evènement Crank To Run                                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUSWTDIAG_vidEventFlagOn();                             */
/*  extf argret void CLUSWTDIAG_vidDiagCohMonitoring();                       */
/*  input uint8 CLUSWTDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_EveCrTR_CluSwtDiag(void)
{
   if (CLUSWTDIAG_u8Inhib != 0x5A)
   {
      CLUSWTDIAG_vidEventFlagOn();
      CLUSWTDIAG_vidDiagCohMonitoring();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_SdlMid_CluSwtDiag                                      */
/* !Description :  Moniteur moyen du diagnostic switch embrayage              */
/* !Number      :  SCH.4                                                      */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUSWTDIAG_vidDiagCoh();                                 */
/*  extf argret void CLUSWTDIAG_vidDiagCohMonitoring();                       */
/*  extf argret void CLUSWTDIAG_vidCounter();                                 */
/*  extf argret void CLUSWTDIAG_vidDiagStuck();                               */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 CLUSWTDIAG_u8Inhib;                                           */
/*  input boolean Clu_bDgoCoh_CluSt;                                          */
/*  input boolean Clu_bMonRunCoh_CluSt;                                       */
/*  input boolean Clu_bDgoStuck_CluSt;                                        */
/*  input boolean Clu_bMonRunStuck_CluSt;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_SdlMid_CluSwtDiag(void)
{
   if (CLUSWTDIAG_u8Inhib != 0x5A)
   {
      CLUSWTDIAG_vidDiagCoh();
      CLUSWTDIAG_vidDiagCohMonitoring();
      CLUSWTDIAG_vidCounter();
      CLUSWTDIAG_vidDiagStuck();
      GDGAR_vidGdu(GD_DFT_COH_CLUST,
                   Clu_bDgoCoh_CluSt,
                   Clu_bMonRunCoh_CluSt,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_STUCK_CLUST,
                   Clu_bDgoStuck_CluSt,
                   Clu_bMonRunStuck_CluSt,
                   DIAG_DISPO);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_SdlSlow_CluSwtDiag                                     */
/* !Description :  Moniteur lent du diagnostic switch embrayage               */
/* !Number      :  SCH.5                                                      */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUSWTDIAG_vidTempo();                                   */
/*  input uint8 CLUSWTDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_SdlSlow_CluSwtDiag(void)
{
   if (CLUSWTDIAG_u8Inhib != 0x5A)
   {
      CLUSWTDIAG_vidTempo();
   }
}