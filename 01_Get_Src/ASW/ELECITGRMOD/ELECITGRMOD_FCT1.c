/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ELECITGRMOD                                             */
/* !Description     : ELECITGRMOD component                                   */
/*                                                                            */
/* !Module          : ELECITGRMOD                                             */
/* !Description     : IMPLÉMENTATION DU MODE INTEGRATION ELECTRONIQUE         */
/*                                                                            */
/* !File            : ELECITGRMOD_FCT1.C                                      */
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
/*   1 / ELECITGRMOD_vidIntElecInit                                           */
/*   2 / ELECITGRMOD_vidIntElecCondCheck                                      */
/*   3 / ELECITGRMOD_vidIntegElectronic                                       */
/*   4 / ELECITGRMOD_vidEntryIntElec                                          */
/*   5 / ELECITGRMOD_vidExitIntElec                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6873723 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ELECITGRMOD/ELECITGRMOD_FCT1.c_v  $*/
/* $Revision::   1.0          $$Author::   hmelloul    $$Date::   19 Aug 2014$*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
/*QAC Warning Msg(2:0838): Due to the multiple inclusion */
#include "ELECITGRMOD_im.h"
#include "ELECITGRMOD_L.h"
#include "ELECITGRMOD_I.h"
/*QAC Warning Msg(2:0838): Due to the multiple inclusion */
#include "ELECITGRMOD.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ELECITGRMOD_vidIntElecInit                                 */
/* !Description :  This function checks if conditions to be in Inegration     */
/*                 Electronic mode are correct at the init                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_6873723_002.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret Std_ReturnType  Dem_DisableDTCRecordUpdate();                 */
/*  extf argret Std_ReturnType  Dem_EnableDTCRecordUpdate();                  */
/*  input uint8 Rcd_reveil_principal_count_on;                                */
/*  input boolean EcuSt_bRstSw;                                               */
/*  input uint16 DIAGCAN_u16Etat_IntElec_nrazram;                             */
/*  output uint8 DIAGCAN_u8IntElecAftrRstWaitCnt;                             */
/*  output uint8 Ext_tiHldIntModeExitMainWku;                                 */
/*  output uint8 DIAGCAN_tiF092Out_InteElec;                                  */
/*  output uint8 DIAGCAN_tiF092Out_ClearDTC;                                  */
/*  output boolean DIAGCAN_bTxMute;                                           */
/*  output boolean DIAGCAN_bInhibition_defauts;                               */
/*  output boolean DIAGCAN_bIntegratioElectronique;                           */
/*  output uint8 DIAGCAN_u8Nb_trame_InteElec_rec;                             */
/*  output uint8 DIAGCAN_u8Nb_trame_ClearDTC_rec;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ELECITGRMOD_vidIntElecInit(void)
{
   boolean           bLocalEcustRstSw;
   Std_ReturnType    u8LocalReturnType;
   /*QAC Warning : Msg(3/3203) --> variable produced but never used
   --> no impact*/

   if (Rcd_reveil_principal_count_on < 255)
   {
      DIAGCAN_u8IntElecAftrRstWaitCnt =
         (uint8)(Rcd_reveil_principal_count_on + 1);
   }
   Ext_tiHldIntModeExitMainWku = 0;
   DIAGCAN_tiF092Out_InteElec = 0;
   DIAGCAN_tiF092Out_ClearDTC = 0;

   VEMS_vidGET(EcuSt_bRstSw, bLocalEcustRstSw);

   if ((bLocalEcustRstSw == TRUE) &&
       (DIAGCAN_u16Etat_IntElec_nrazram == 0xAA55))
   {
      VEMS_vidSET(DIAGCAN_bTxMute, TRUE);
      DIAGCAN_bInhibition_defauts = TRUE;
      VEMS_vidSET(DIAGCAN_bIntegratioElectronique, 1);
      u8LocalReturnType = Dem_DisableDTCRecordUpdate();
/*QAC Warning: Msg(3:3199) The value of 'u8LocalReturnType' is never used
                                      following this assignment. --> No Impact*/
   }
   else
   {
      VEMS_vidSET(DIAGCAN_bTxMute, FALSE);
      DIAGCAN_bInhibition_defauts = FALSE;
      VEMS_vidSET(DIAGCAN_bIntegratioElectronique, 0);
      u8LocalReturnType = Dem_EnableDTCRecordUpdate();
/*QAC Warning: Msg(3:3199) The value of 'u8LocalReturnType' is never used
                                      following this assignment. --> No Impact*/
   }

   DIAGCAN_u8Nb_trame_InteElec_rec = 0;
   DIAGCAN_u8Nb_trame_ClearDTC_rec = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ELECITGRMOD_vidIntElecCondCheck                            */
/* !Description :  This function checks if conditions are corrects            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_6873723_006.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ELECITGRMOD_vidExitIntElec();                            */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Diag_on;                                                    */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Rcd_signal;                                                 */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input uint8 DIAGCAN_u8IntElecAftrRstWaitCnt;                              */
/*  input uint8 DIAGCAN_tiF092Out_ClearDTC;                                   */
/*  input uint8 DIAGCAN_tiF092Out_InteElec;                                   */
/*  input uint8 Ext_tiHldIntModeExitMainWku;                                  */
/*  input uint8 Ext_tiHldIntModeExitMainWku_C;                                */
/*  output uint8 DIAGCAN_u8IntElecAftrRstWaitCnt;                             */
/*  output uint8 DIAGCAN_tiF092Out_ClearDTC;                                  */
/*  output uint8 DIAGCAN_tiF092Out_InteElec;                                  */
/*  output uint8 Ext_tiHldIntModeExitMainWku;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ELECITGRMOD_vidIntElecCondCheck(void)
{
   boolean  bLocalMoteurTournant;
   boolean  bLocalDiagOn;
   boolean  bLocalECU_bWkuMain;
   boolean  bLocalIntegratioElectronique;
   boolean  bLocalRcdSignal;
   uint8    u8LocalVitessevehicule;
   sint16   s16LocalVar;

   VEMS_vidGET(Moteur_tournant, bLocalMoteurTournant);
   VEMS_vidGET(Diag_on, bLocalDiagOn);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(Rcd_signal, bLocalRcdSignal);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitessevehicule);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);

   s16LocalVar = (sint16)(DIAGCAN_u8IntElecAftrRstWaitCnt - 1);
   DIAGCAN_u8IntElecAftrRstWaitCnt = (uint8)MATHSRV_udtMAX(s16LocalVar, 0);

   s16LocalVar = (sint16)(DIAGCAN_tiF092Out_ClearDTC - 1);
   DIAGCAN_tiF092Out_ClearDTC = (uint8)MATHSRV_udtMAX(s16LocalVar, 0);

   s16LocalVar = (sint16)(DIAGCAN_tiF092Out_InteElec - 1);
   DIAGCAN_tiF092Out_InteElec = (uint8)MATHSRV_udtMAX(s16LocalVar, 0);

   if (bLocalECU_bWkuMain == 0)
   {
      s16LocalVar = (sint16)(Ext_tiHldIntModeExitMainWku - 1);
      Ext_tiHldIntModeExitMainWku =
         (uint8)MATHSRV_udtMAX(s16LocalVar, 0);
   }
   else
   {
      Ext_tiHldIntModeExitMainWku = Ext_tiHldIntModeExitMainWku_C;
   }

   if (  ( bLocalIntegratioElectronique == TRUE)
      && (  ( bLocalMoteurTournant == TRUE)
         || ( u8LocalVitessevehicule != 0)
         || ( bLocalDiagOn == TRUE)
         || (  ( bLocalECU_bWkuMain == FALSE)
            && ( DIAGCAN_u8IntElecAftrRstWaitCnt == 0)
            && ( Ext_tiHldIntModeExitMainWku == 0))
         || ( bLocalRcdSignal == FALSE)))
   {
      ELECITGRMOD_vidExitIntElec();

   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ELECITGRMOD_vidIntegElectronic                             */
/* !Description :  This function checks data received by the frame 0x092      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_6873723_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ELECITGRMOD_vidEntryIntElec();                           */
/*  extf argret void ELECITGRMOD_vidExitIntElec();                            */
/*  extf argret Dem_ReturnClearDTCType  Dem_ClearDTC(argin uint32 u32DTC,     */
/* argin Dem_DTCKindType u8DTCKind, argin Dem_DTCOriginType u8DTCOrigin);     */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Diag_on;                                                    */
/*  input boolean Rcd_signal;                                                 */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Ext_bDelDftReq;                                             */
/*  input boolean Ext_bElIntgDiagMod;                                         */
/*  input boolean Ext_bElIntgDiag;                                            */
/*  input uint8 DIAGCAN_tiF092Out_InteElec;                                   */
/*  input uint8 DIAGCAN_tiF092Out_InteElec_C;                                 */
/*  input uint8 DIAGCAN_u8Nb_trame_InteElec_rec;                              */
/*  input uint8 DIAGCAN_u8Command_InteElec_prev;                              */
/*  input uint8 DIAGCAN_tiF092Out_ClearDTC;                                   */
/*  input uint8 DIAGCAN_tiF092Out_ClearDTC_C;                                 */
/*  input uint8 DIAGCAN_u8Nb_trame_ClearDTC_rec;                              */
/*  input uint8 Ext_tiHldIntModeExitMainWku;                                  */
/*  output uint8 DIAGCAN_u8Nb_trame_InteElec_rec;                             */
/*  output uint8 DIAGCAN_tiF092Out_InteElec;                                  */
/*  output uint8 DIAGCAN_u8Command_InteElec_prev;                             */
/*  output uint8 DIAGCAN_u8Nb_trame_ClearDTC_rec;                             */
/*  output uint8 DIAGCAN_tiF092Out_ClearDTC;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ELECITGRMOD_vidIntegElectronic(void)
{
   boolean  bLocalMoteurTournant;
   boolean  bLocalDiagOn;
   boolean  bLocalExt_bDelDftReq;
   boolean  bLocalExt_bElIntgDiagMod;
   boolean  bLocalExt_bElIntgDiag;
   boolean  bLocalRcdSignal;
   boolean  bLocalECU_bWkuMain;
   uint8    u8LocalVitesseVehicle;
   uint8    u8LocalCanData092;


   VEMS_vidGET(Moteur_tournant, bLocalMoteurTournant);
   VEMS_vidGET(Diag_on, bLocalDiagOn);
   VEMS_vidGET(Rcd_signal, bLocalRcdSignal);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesseVehicle);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(Ext_bDelDftReq, bLocalExt_bDelDftReq);
   VEMS_vidGET(Ext_bElIntgDiagMod, bLocalExt_bElIntgDiagMod);
   VEMS_vidGET(Ext_bElIntgDiag, bLocalExt_bElIntgDiag);
   u8LocalCanData092   = (uint8)(  bLocalExt_bElIntgDiagMod
                                + (bLocalExt_bElIntgDiag << 1));
   /* On teste les conditions sécuritaires */
   if (  (bLocalMoteurTournant == FALSE)
      && (u8LocalVitesseVehicle == 0)
      && (bLocalECU_bWkuMain == TRUE)
      && (bLocalRcdSignal == TRUE)
      && (bLocalDiagOn == FALSE))
   {
      /* On vérifie si le timer d’une seconde ne s’est pas écoulé */
      if (DIAGCAN_tiF092Out_InteElec == 0)
      {
         /* S’il est écoulé, on reprend le décomptage des demandes d’IE à partir
         /du début et on relance le timer */
         DIAGCAN_u8Nb_trame_InteElec_rec = 1;
         DIAGCAN_tiF092Out_InteElec = DIAGCAN_tiF092Out_InteElec_C;
      }
      else
      {
         /* Sinon, on continue de compter les demandes */
         if (DIAGCAN_u8Nb_trame_InteElec_rec < 255)
         {
            DIAGCAN_u8Nb_trame_InteElec_rec =
               (uint8)(DIAGCAN_u8Nb_trame_InteElec_rec + 1);
         }
      }

      if (DIAGCAN_u8Nb_trame_InteElec_rec == 1)
      {
         /* A la première demande reçue on la garde en mémoire pour pouvoir
         la comparer avec la suivante */
         DIAGCAN_u8Command_InteElec_prev = u8LocalCanData092;
      }
      else
      {
         if (DIAGCAN_u8Command_InteElec_prev != u8LocalCanData092)
         {
            /* Si la demande d’IE a changé, alors on reprend le décomptage
            du début et on relance le timer */
            DIAGCAN_u8Command_InteElec_prev = u8LocalCanData092;
            DIAGCAN_u8Nb_trame_InteElec_rec = 1;
            DIAGCAN_tiF092Out_InteElec = DIAGCAN_tiF092Out_InteElec_C;
         }
         else if (DIAGCAN_u8Nb_trame_InteElec_rec == 3)
         {
            /* A la troisième demande identique reçue, on l’applique */
            if (  (bLocalExt_bElIntgDiag == 1)
               && (bLocalExt_bElIntgDiagMod == 1))
            {
               ELECITGRMOD_vidEntryIntElec();
            }
            else if (  (bLocalExt_bElIntgDiag == 0)
                    && (bLocalExt_bElIntgDiagMod == 0))
            {
               ELECITGRMOD_vidExitIntElec();
            }
            else
            {
               /* Do Nothing */
            }
            /* On force le timer à 0 pour pouvoir réinitialiser le décomptage
            à la prochaine réception de trame */
            DIAGCAN_tiF092Out_InteElec = 0;
         }
         else
         {
               /* Do Nothing */
         }
      }
      if (bLocalExt_bDelDftReq == 1)
      {
         /* Lors d’une demande de ClearDTC, si le timer est  écoulé
         on recommence le décomptage et on réinitialise le timer */
         if (DIAGCAN_tiF092Out_ClearDTC == 0)
         {
            DIAGCAN_u8Nb_trame_ClearDTC_rec = 1;
            DIAGCAN_tiF092Out_ClearDTC = DIAGCAN_tiF092Out_ClearDTC_C;
         }
         else
         {
            if (DIAGCAN_u8Nb_trame_ClearDTC_rec < 255)
            {
               DIAGCAN_u8Nb_trame_ClearDTC_rec =
                  (uint8)(DIAGCAN_u8Nb_trame_ClearDTC_rec + 1);
            }
         }
         /* A partir de la troisième demande reçue dans le temps imparti,
         on effectue le ClearDTC */
         if (DIAGCAN_u8Nb_trame_ClearDTC_rec >= 3)
         {
            /*QAC Warning : Msg(2:3200) 'Dem_ClearDTC' returns a value which
              is not being used --> No Impact*/
            Dem_ClearDTC(0xFFFFFF,
                         DEM_DTC_KIND_ALL_DTCS,
                         DEM_DTC_ORIGIN_PRIMARY_MEMORY);
         }
      }
      else
      {
         /* Si on ne demande pas de reset, On force le timer à 0 pour pouvoir
         réinitialiser le décomptage à la prochaine réception de trame. */
         DIAGCAN_tiF092Out_ClearDTC = 0;
      }
   }
   else
   {
      if ( ( bLocalECU_bWkuMain == 1)
         ||( Ext_tiHldIntModeExitMainWku == 0))
      {
         ELECITGRMOD_vidExitIntElec();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ELECITGRMOD_vidEntryIntElec                                */
/* !Description :  This function launch the Integration Electronic mode       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_6873723_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret Std_ReturnType  Dem_DisableDTCRecordUpdate();                 */
/*  output uint16 DIAGCAN_u16Etat_IntElec_nrazram;                            */
/*  output boolean DIAGCAN_bTxMute;                                           */
/*  output boolean DIAGCAN_bInhibition_defauts;                               */
/*  output boolean DIAGCAN_bIntegratioElectronique;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ELECITGRMOD_vidEntryIntElec(void)
{
   Std_ReturnType    u8LocalReturnType;
   /*QAC Warning : Msg(3/3203) --> variable produced but never used
   --> no impact*/


   DIAGCAN_u16Etat_IntElec_nrazram = 0xAA55;
   VEMS_vidSET(DIAGCAN_bTxMute, TRUE);
   DIAGCAN_bInhibition_defauts = TRUE;
   VEMS_vidSET(DIAGCAN_bIntegratioElectronique, 1);

   u8LocalReturnType = Dem_DisableDTCRecordUpdate();
/*QAC Warning: Msg(3:3199) The value of 'u8LocalReturnType' is never used
                                      following this assignment. --> No Impact*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ELECITGRMOD_vidExitIntElec                                 */
/* !Description :  This function quits the Integration Electronic mode        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  PTS_R_6873723_005.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret Std_ReturnType  Dem_EnableDTCRecordUpdate();                  */
/*  output uint16 DIAGCAN_u16Etat_IntElec_nrazram;                            */
/*  output boolean DIAGCAN_bTxMute;                                           */
/*  output boolean DIAGCAN_bInhibition_defauts;                               */
/*  output boolean DIAGCAN_bIntegratioElectronique;                           */
/*  output uint8 DIAGCAN_u8Nb_trame_InteElec_rec;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ELECITGRMOD_vidExitIntElec(void)
{
   Std_ReturnType    u8LocalReturnType;
   /*QAC Warning : Msg(3/3203) --> variable produced but never used
   --> no impact*/


   DIAGCAN_u16Etat_IntElec_nrazram = 0;
   VEMS_vidSET(DIAGCAN_bTxMute, FALSE);
   DIAGCAN_bInhibition_defauts = FALSE;
   VEMS_vidSET(DIAGCAN_bIntegratioElectronique, 0);
   DIAGCAN_u8Nb_trame_InteElec_rec = 0;

   u8LocalReturnType = Dem_EnableDTCRecordUpdate();
/*QAC Warning: Msg(3:3199) The value of 'u8LocalReturnType' is never used
                                      following this assignment. --> No Impact*/
}

/*------------------------------- end of file --------------------------------*/
