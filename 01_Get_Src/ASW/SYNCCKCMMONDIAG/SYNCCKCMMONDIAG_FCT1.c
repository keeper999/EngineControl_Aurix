/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKCMMONDIAG                                         */
/* !Description     : SYNCCKCMMONDIAG component.                              */
/*                                                                            */
/* !Module          : SYNCCKCMMONDIAG                                         */
/* !Description     : SURVEILLANCE DES SIGNAUX ARBRE A CAMES ET VILEBREQUIN   */
/*                                                                            */
/* !File            : SYNCCKCMMONDIAG_FCT1.C                                  */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / SYNCCKCMMONDIAG_vidInitOutput                                        */
/*   2 / SYNCCKCMMONDIAG_vidIniEnaDgoNoSg                                     */
/*   3 / SYNCCKCMMONDIAG_vidClEnaDgoNoSg                                      */
/*   4 / SYNCCKCMMONDIAG_vidGenrCkDiagEve                                     */
/*   5 / SYNCCKCMMONDIAG_vidGenrCmDiagEve                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 04208 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKCMMONDIAG/SYNCCKCMMONDI$*/
/* $Revision::   1.6      $$Author::   wbouach        $$Date::   20 Jan 2012 $*/
/* $Author::   wbouach                                $$Date::   20 Jan 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SYNCCKCMMONDIAG.h"
#include "SYNCCKCMMONDIAG_L.h"
#include "SYNCCKCMMONDIAG_IM.h"
#include "VEMS.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidInitOutput                              */
/* !Description :  Initialisation des variables au reset de l’ECU             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean SYNCCKCMMONDIAG_bCrkInCamSynPrev;                          */
/*  output boolean SYNCCKCMMONDIAG_bCrkInCamTimeout;                          */
/*  output uint8 SYNCCKCMMONDIAG_u8CrkInTimerCnt;                             */
/*  output boolean SYNCCKCMMONDIAG_bCrkExCamSynPrev;                          */
/*  output boolean SYNCCKCMMONDIAG_bCrkExCamTimeout;                          */
/*  output uint8 SYNCCKCMMONDIAG_u8CrkExTimerCnt;                             */
/*  output boolean SYNCCKCMMONDIAG_bAcqCrkEngInPrev;                          */
/*  output uint8 SYNCCKCMMONDIAG_u8InCmTimerCnt;                              */
/*  output boolean Sync_bMinTimeElpdInCam;                                    */
/*  output boolean SYNCCKCMMONDIAG_bAcqCrkEngExPrev;                          */
/*  output uint8 SYNCCKCMMONDIAG_u8ExCmTimerCnt;                              */
/*  output boolean Sync_bMinTimeElpdExCam;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidInitOutput(void)
{
/*Timer 1*/
   SYNCCKCMMONDIAG_bCrkInCamSynPrev = 1;
   SYNCCKCMMONDIAG_bCrkInCamTimeout = 0;
   SYNCCKCMMONDIAG_u8CrkInTimerCnt = 0;
/*Timer 2*/
   SYNCCKCMMONDIAG_bCrkExCamSynPrev = 1;
   SYNCCKCMMONDIAG_bCrkExCamTimeout = 0;
   SYNCCKCMMONDIAG_u8CrkExTimerCnt = 0;
/*Timer 3*/
   SYNCCKCMMONDIAG_bAcqCrkEngInPrev = 0;
   SYNCCKCMMONDIAG_u8InCmTimerCnt = 0;
   Sync_bMinTimeElpdInCam = 0;
/*Timer 4*/
   SYNCCKCMMONDIAG_bAcqCrkEngExPrev = 0;
   SYNCCKCMMONDIAG_u8ExCmTimerCnt = 0;
   Sync_bMinTimeElpdExCam = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidIniEnaDgoNoSg                           */
/* !Description :  Au réveil calculateur et au KEY ON, on autorise les        */
/*                 diagnostics d’absence du signal vilebrequin et des signaux */
/*                 arbre à cames                                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Sync_bRotDetEng;                                            */
/*  output boolean Sync_bEnaDiagNoSigCk;                                      */
/*  output boolean Sync_bEnaDiagNoSigInCam;                                   */
/*  output boolean Sync_bEnaDiagNoSigExCam;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidIniEnaDgoNoSg(void)
{
   boolean bLocalSync_bRotDetEng;


   VEMS_vidGET(Sync_bRotDetEng, bLocalSync_bRotDetEng);

   if (bLocalSync_bRotDetEng != 0)
   {
      Sync_bEnaDiagNoSigCk = 0;
      Sync_bEnaDiagNoSigInCam = 0;
      Sync_bEnaDiagNoSigExCam = 0;
   }
   else
   {
      Sync_bEnaDiagNoSigCk = 1;
      Sync_bEnaDiagNoSigInCam = 1;
      Sync_bEnaDiagNoSigExCam = 1;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidClEnaDgoNoSg                            */
/* !Description :  Dès que le signal à diagnostiquer est synchronisé alors le */
/*                 test de perte de signal est activé. Dès que la             */
/*                 synchronisation du signal à diagnostiquer et la            */
/*                 synchronisation du signal de référence sont perdues alors  */
/*                 on active le test d’absence du signal.                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Acq_crk_sync_status_upvb0;                                  */
/*  input boolean Acq_crk_sync_upvb0;                                         */
/*  input boolean Acq_excam_sync_upvb0;                                       */
/*  input boolean Acq_excam_sync_status_upvb0;                                */
/*  input boolean Acq_incam_sync_upvb0;                                       */
/*  input boolean Acq_incam_sync_status_upvb0;                                */
/*  input boolean SYNCCKCMMONDIAG_bCrkInCamSynPrev;                           */
/*  input uint8 Sync_CfmTimeStallEng;                                         */
/*  input uint8 SYNCCKCMMONDIAG_u8CrkInTimerCnt;                              */
/*  input boolean SYNCCKCMMONDIAG_bCrkExCamSynPrev;                           */
/*  input uint8 SYNCCKCMMONDIAG_u8CrkExTimerCnt;                              */
/*  input boolean SYNCCKCMMONDIAG_bCrkInCamTimeout;                           */
/*  input boolean SYNCCKCMMONDIAG_bCrkExCamTimeout;                           */
/*  output uint8 SYNCCKCMMONDIAG_u8CrkInTimerCnt;                             */
/*  output boolean SYNCCKCMMONDIAG_bCrkInCamTimeout;                          */
/*  output uint8 SYNCCKCMMONDIAG_u8CrkExTimerCnt;                             */
/*  output boolean SYNCCKCMMONDIAG_bCrkExCamTimeout;                          */
/*  output boolean SYNCCKCMMONDIAG_bCrkInCamSynPrev;                          */
/*  output boolean SYNCCKCMMONDIAG_bCrkExCamSynPrev;                          */
/*  output boolean Sync_bEnaDiagNoSigCk;                                      */
/*  output boolean Sync_bEnaDiagNoSigInCam;                                   */
/*  output boolean Sync_bEnaDiagNoSigExCam;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidClEnaDgoNoSg(void)
{
   boolean bLocalcrk_syn_ok;
   boolean bLocalex_cam_syn_ok;
   boolean bLocalin_cam_syn_ok;
   boolean bLocalAcq_crk_sync_status_upvb0;
   boolean bLocalAcq_crk_sync_upvb0;
   boolean bLocalAcq_excam_sync_upvb0;
   boolean bLocalAcq_excam_sync_st_upvb0;
   boolean bLocalAcq_incam_sync_upvb0;
   boolean bLocalAcq_incam_sync_st_upvb0;
   boolean bLocalCrkInCamSynOk;
   boolean bLocalCrkExCamSynOk;
   uint8   u8LocalTimerCnt;


   VEMS_vidGET(Acq_crk_sync_status_upvb0, bLocalAcq_crk_sync_status_upvb0);
   VEMS_vidGET(Acq_crk_sync_upvb0, bLocalAcq_crk_sync_upvb0);
   VEMS_vidGET(Acq_excam_sync_upvb0, bLocalAcq_excam_sync_upvb0);
   VEMS_vidGET(Acq_excam_sync_status_upvb0, bLocalAcq_excam_sync_st_upvb0);
   VEMS_vidGET(Acq_incam_sync_upvb0, bLocalAcq_incam_sync_upvb0);
   VEMS_vidGET(Acq_incam_sync_status_upvb0, bLocalAcq_incam_sync_st_upvb0);

   if (  (bLocalAcq_incam_sync_upvb0 != 0)
      && (bLocalAcq_incam_sync_st_upvb0 != 0))
   {
      bLocalin_cam_syn_ok = 1;
   }
   else
   {
      bLocalin_cam_syn_ok = 0;
   }

   if (  (bLocalAcq_crk_sync_upvb0 != 0)
      && (bLocalAcq_crk_sync_status_upvb0 != 0))
   {
      bLocalcrk_syn_ok = 1;
   }
   else
   {
      bLocalcrk_syn_ok = 0;
   }

   if (  (bLocalAcq_excam_sync_upvb0 != 0)
      && (bLocalAcq_excam_sync_st_upvb0 != 0))
   {
      bLocalex_cam_syn_ok = 1;
   }
   else
   {
      bLocalex_cam_syn_ok = 0;
   }

   if (  (bLocalcrk_syn_ok == 0)
      && (bLocalin_cam_syn_ok == 0))
   {
      bLocalCrkInCamSynOk = 1;
   }
   else
   {
      bLocalCrkInCamSynOk = 0;
   }

   if (  (bLocalcrk_syn_ok == 0)
      && (bLocalex_cam_syn_ok == 0))
   {
      bLocalCrkExCamSynOk = 1;
   }
   else
   {
      bLocalCrkExCamSynOk = 0;
   }

   if (  (SYNCCKCMMONDIAG_bCrkInCamSynPrev == 0)
      && (bLocalCrkInCamSynOk != 0))
   {
      SYNCCKCMMONDIAG_u8CrkInTimerCnt =
         (uint8)MATHSRV_udtMIN(Sync_CfmTimeStallEng, 250);
      if (SYNCCKCMMONDIAG_u8CrkInTimerCnt == 0)
      {
         SYNCCKCMMONDIAG_bCrkInCamTimeout = 1;
      }
      else
      {
         SYNCCKCMMONDIAG_bCrkInCamTimeout = 0;
      }
   }
   else
   {
      if (SYNCCKCMMONDIAG_u8CrkInTimerCnt > 0)
      {
         u8LocalTimerCnt = (uint8)(SYNCCKCMMONDIAG_u8CrkInTimerCnt - 1);
         SYNCCKCMMONDIAG_u8CrkInTimerCnt =
            (uint8)MATHSRV_udtMIN(u8LocalTimerCnt, 250);
         if (SYNCCKCMMONDIAG_u8CrkInTimerCnt == 0)
         {
            SYNCCKCMMONDIAG_bCrkInCamTimeout = 1;
         }
         else
         {
            SYNCCKCMMONDIAG_bCrkInCamTimeout = 0;
         }
      }
   }


   if (  (SYNCCKCMMONDIAG_bCrkExCamSynPrev == 0)
      && (bLocalCrkExCamSynOk != 0))
   {
      SYNCCKCMMONDIAG_u8CrkExTimerCnt =
         (uint8)MATHSRV_udtMIN(Sync_CfmTimeStallEng, 250);
      if (SYNCCKCMMONDIAG_u8CrkExTimerCnt == 0)
      {
         SYNCCKCMMONDIAG_bCrkExCamTimeout = 1;
      }
      else
      {
         SYNCCKCMMONDIAG_bCrkExCamTimeout = 0;
      }
   }
   else
   {
      if (SYNCCKCMMONDIAG_u8CrkExTimerCnt > 0)
      {
         u8LocalTimerCnt = (uint8)(SYNCCKCMMONDIAG_u8CrkExTimerCnt - 1);
         SYNCCKCMMONDIAG_u8CrkExTimerCnt =
            (uint8)MATHSRV_udtMIN(u8LocalTimerCnt, 250);
         if (SYNCCKCMMONDIAG_u8CrkExTimerCnt == 0)
         {
            SYNCCKCMMONDIAG_bCrkExCamTimeout = 1;
         }
         else
         {
            SYNCCKCMMONDIAG_bCrkExCamTimeout = 0;
         }
      }
   }

   SYNCCKCMMONDIAG_bCrkInCamSynPrev = bLocalCrkInCamSynOk;
   SYNCCKCMMONDIAG_bCrkExCamSynPrev = bLocalCrkExCamSynOk;

   if (bLocalcrk_syn_ok != 0)
   {
      Sync_bEnaDiagNoSigCk = 0;
   }
   else
   {
      if (  (SYNCCKCMMONDIAG_bCrkInCamTimeout != 0)
         && (bLocalCrkInCamSynOk != 0))
      {
         Sync_bEnaDiagNoSigCk = 1;
      }
   }

   if (bLocalin_cam_syn_ok != 0)
   {
      Sync_bEnaDiagNoSigInCam = 0;
   }
   else
   {
      if (  (SYNCCKCMMONDIAG_bCrkInCamTimeout != 0)
         && (bLocalCrkInCamSynOk != 0))
      {
         Sync_bEnaDiagNoSigInCam = 1;
      }
   }

   if (bLocalex_cam_syn_ok != 0)
   {
      Sync_bEnaDiagNoSigExCam = 0;
   }
   else
   {
      if (  (SYNCCKCMMONDIAG_bCrkExCamTimeout != 0)
         && (bLocalCrkExCamSynOk != 0))
      {
         Sync_bEnaDiagNoSigExCam = 1;
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidGenrCkDiagEve                           */
/* !Description :  Ce module a pour vocation d’émettre les évènements qui     */
/*                 déclenchent les calculs de la perte et de l’absence du     */
/*                 signal vilebrequin.                                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void SYNCCKCMMONDIAG_vidGenrNoSigCk();                        */
/*  extf argret void SYNCCKCMMONDIAG_vidGenrSigLossCk();                      */
/*  input boolean Sync_bEnaDiagNoSigCk;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidGenrCkDiagEve(void)
{
   boolean bLocalAcvNoSigCkTest;


   bLocalAcvNoSigCkTest = GDGAR_bGetFRM(FRM_FRM_ACVNOSIGCKTEST);

   if (  (Sync_bEnaDiagNoSigCk != 0)
      || (bLocalAcvNoSigCkTest != 0))
   {
      SYNCCKCMMONDIAG_vidGenrNoSigCk();
   }
   else
   {
      SYNCCKCMMONDIAG_vidGenrSigLossCk();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMMONDIAG_vidGenrCmDiagEve                           */
/* !Description :  Ce module a pour vocation d’émettre  les évènements qui    */
/*                 déclenchent  les calculs de  la perte et de  l’absence des */
/*                 signaux vilebrequin et arbres à cames (admission et        */
/*                 échappement)                                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCCKCMMONDIAG_vidGenrNoSigInCm();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidGenrLossInCm();                       */
/*  extf argret void SYNCCKCMMONDIAG_vidGenrNoSigExCm();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidGenrLossExCm();                       */
/*  input boolean Ext_bPresExCmSen;                                           */
/*  input boolean Ext_bPresInCmSen;                                           */
/*  input boolean Sync_bEnaDiagNoSigInCam;                                    */
/*  input boolean Sync_bEnaDiagNoSigExCam;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMMONDIAG_vidGenrCmDiagEve(void)
{
   boolean bLocalExt_bPresExCmSen;
   boolean bLocalExt_bPresInCmSen;
   boolean bLocalAcvNoSigInCmTest;
   boolean bLocalAcvNoSigExCmTest;


   bLocalAcvNoSigInCmTest = GDGAR_bGetFRM(FRM_FRM_ACVNOSIGINCMTEST);
   bLocalAcvNoSigExCmTest = GDGAR_bGetFRM(FRM_FRM_ACVNOSIGEXCMTEST);
   VEMS_vidGET(Ext_bPresExCmSen, bLocalExt_bPresExCmSen);
   VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);

   if (bLocalExt_bPresInCmSen != 0)
   {
      if (  (Sync_bEnaDiagNoSigInCam != 0)
         || (bLocalAcvNoSigInCmTest != 0))
      {
         SYNCCKCMMONDIAG_vidGenrNoSigInCm();
      }
      else
      {
         SYNCCKCMMONDIAG_vidGenrLossInCm();
      }
   }
   else
   {
      if (bLocalAcvNoSigInCmTest != 0)
      {
         SYNCCKCMMONDIAG_vidGenrNoSigInCm();
      }
   }

   if (bLocalExt_bPresExCmSen != 0)
   {
      if (  (Sync_bEnaDiagNoSigExCam != 0)
         || (bLocalAcvNoSigExCmTest != 0))
      {
         SYNCCKCMMONDIAG_vidGenrNoSigExCm();
      }
      else
      {
         SYNCCKCMMONDIAG_vidGenrLossExCm();
      }
   }
   else
   {
      if (bLocalAcvNoSigExCmTest != 0)
      {
         SYNCCKCMMONDIAG_vidGenrNoSigExCm();
      }
   }
}
/*------------------------------- end of file --------------------------------*/