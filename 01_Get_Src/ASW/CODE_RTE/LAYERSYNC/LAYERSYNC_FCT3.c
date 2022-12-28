/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : LAYERSYNC                                               */
/* !Description     : LAYERSYNC component.                                    */
/*                                                                            */
/* !Module          : LAYERSYNC                                               */
/* !Description     : LAYER DE LA FONCTION SYNCHRO                            */
/*                                                                            */
/* !File            : LAYERSYNC_FCT3.c                                        */
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
/*   1 / LAYERSYNC_vidEnaBwdRot                                               */
/*   2 / LAYERSYNC_vidIniTDCCnt                                               */
/*   3 / LAYERSYNC_vidEngStopPosnAfter                                        */
/*   4 / LAYERSYNC_vidReadToothInfo                                           */
/*   5 / LAYERSYNC_vidCtEdgeCmInStrt                                          */
/*   6 / LAYERSYNC_vidCtEdgeCmExStrt                                          */
/*   7 / LAYERSYNC_vidChangeOfMind                                            */
/*   8 / LAYERSYNC_vidCtEdgeCmInRstrt                                         */
/*   9 / LAYERSYNC_vidCtEdgeCmExRstrt                                         */
/*   10 / LAYERSYNC_vidEngStopPosn                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6944973 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/LAYERSYNC/LAYERSYNC_FCT3.c_v      $*/
/* $Revision::   1.1      $$Author::   achebino       $$Date::   21 Aug 2014 $*/
/* $Author::   achebino                               $$Date::   21 Aug 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "LAYERSYNC.h"
#include "LAYERSYNC_L.h"
#include "LAYERSYNC_IM.h"
#include "CRKHAL.h"
#include "LAYERSYNC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidEnaBwdRot                                     */
/* !Description :  API qui autorise la rotation du moteur en sens inverse.    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtEnableBwdRotation()Std_ReturnType;             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidEnaBwdRot(void)
 {
   Std_ReturnType udtLocalStatus;
   /*QAC Warning(3:3203): CRKHAL_udtEnableBwdRotation returns Std value*/


   udtLocalStatus = CRKHAL_udtEnableBwdRotation();
   /*QAC Warning(3:3199): CRKHAL_udtEnableBwdRotation returns Std value*/
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidIniTDCCnt                                     */
/* !Description :  Fonction qui permet la lecture de la position angulaire du */
/*                 moteur lors de la synchronisation moteur.                  */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtGetToothInfo(argin uint8 u8MaxTableSize, argio */
/*  uint32 *pau32ToothInfoTable)Std_ReturnType;                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_noMaxTableSize_C;                                        */
/*  output uint16 Acq_pos_ang_lors_synchro;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidIniTDCCnt(void)
{
   Std_ReturnType udtLocalStatus;
   uint16         u16LocalAcqPosAngLorsSynchro;
   uint32         au32ToothInfoTable[LAYERSYNC_u8MAX_TAB_SIZE];


   udtLocalStatus = CRKHAL_udtGetToothInfo(Sync_noMaxTableSize_C,
                                           &au32ToothInfoTable[0]);
   if (udtLocalStatus != E_OK)
   {
      u16LocalAcqPosAngLorsSynchro = 0;
   }
   else
   {
      u16LocalAcqPosAngLorsSynchro =
         (uint16)MATHSRV_udtMIN(au32ToothInfoTable[3], 46079);
   }
   VEMS_vidSET(Acq_pos_ang_lors_synchro, u16LocalAcqPosAngLorsSynchro);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidEngStopPosnAfter                              */
/* !Description :  Lors de la détection de la singularité du signal           */
/*                 vilebrequin on effectue la lecture de l’API donnant la     */
/*                 position d’arrêt du moteur calculée à posteriori.          */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtGetEngStopPosition(argin uint8                 */
/*  u8EngStopPositionType, argio uint16 *pu16EngStopPosition)Std_ReturnType;  */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acq_angle_arret_moteur_redem;                                */
/*  output uint16 Acq_angle_arret_moteur_redem;                               */
/*  output boolean SyncAcq_bCalcOk;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidEngStopPosnAfter(void)
{
   Std_ReturnType udtLocalStatus;
   uint16         u16LocalEngStopPosition;
   uint16         u16LocalAcqAngleArretMoteurRedem;


   udtLocalStatus = CRKHAL_udtGetEngStopPosition(CRKHAL_u8STOP_POSITION_AFTER,
                                                 &u16LocalEngStopPosition);
   if (udtLocalStatus == E_OK)
   {
      u16LocalAcqAngleArretMoteurRedem = u16LocalEngStopPosition;
   }
   else
   {
      VEMS_vidGET(Acq_angle_arret_moteur_redem,
                  u16LocalAcqAngleArretMoteurRedem);
   }
   u16LocalAcqAngleArretMoteurRedem =
         (uint16)MATHSRV_udtMIN(u16LocalAcqAngleArretMoteurRedem, 46079);
   VEMS_vidSET(Acq_angle_arret_moteur_redem, u16LocalAcqAngleArretMoteurRedem);

   SyncAcq_bCalcOk = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidReadToothInfo                                 */
/* !Description :  Fonction de lecture des variables de synchronisation       */
/*                 provenant du LdB.                                          */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtGetToothInfo(argin uint8 u8MaxTableSize, argio */
/*  uint32 *pau32ToothInfoTable)Std_ReturnType;                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void CRKHAL_udtReadStatus(argin uint8 u8Channel, argio boolean*/
/* *pbStatus)Std_ReturnType;                                                  */
/*  input uint8 Sync_noMaxTableSize_C;                                        */
/*  output uint8 Acq_tooth_compteur;                                          */
/*  output uint32 Acq_dernier_tps_inter_dent_vileb;                           */
/*  output uint32 Acq_av_dernie_tps_int_dent_vileb;                           */
/*  output uint16 Acq_angle_moteur;                                           */
/*  output boolean Acq_sens_rotation_moteur;                                  */
/*  output boolean Acq_position_anglaire_moteur;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidReadToothInfo(void)
{
   Std_ReturnType udtLocalStatus;
   boolean        bLocalStatus;
   boolean        bLocalAcqpositionanglairemoteur;
   boolean        bLocalAcqSensRotationMoteur;
   uint8          u8LocalAcqToothCompteur;
   uint16         u16LocalAcqAngleMoteur;
   uint32         au32ToothInfoTable[LAYERSYNC_u8MAX_TAB_SIZE];
   uint32         u32LocalAcqDernierTpsInterDent;
   uint32         u32LocalAcqavDernieTpsIntDentVil;


   udtLocalStatus = CRKHAL_udtGetToothInfo(Sync_noMaxTableSize_C,
                                           &au32ToothInfoTable[0]);
   if (udtLocalStatus != E_OK)
   {
      u8LocalAcqToothCompteur = COUNTER_EDGECK_MAX;
      u32LocalAcqDernierTpsInterDent = TIME_CGT_MAX;
      u32LocalAcqavDernieTpsIntDentVil = TIME_CGTLST_MAX;
      u16LocalAcqAngleMoteur = ENGINE_POSITION_MAX;
      bLocalAcqSensRotationMoteur = ENGINE_ROTATION_DIR;
   }
   else
   {
      u8LocalAcqToothCompteur =
         (uint8)MATHSRV_udtMIN(au32ToothInfoTable[0], 255);
      u32LocalAcqDernierTpsInterDent = au32ToothInfoTable[1];
      u32LocalAcqavDernieTpsIntDentVil = au32ToothInfoTable[2];
      u16LocalAcqAngleMoteur =
         (uint16)MATHSRV_udtMIN(au32ToothInfoTable[3], 46079);
      if (au32ToothInfoTable[4] != 0)
      {
         bLocalAcqSensRotationMoteur = 1;
      }
      else
      {
         bLocalAcqSensRotationMoteur = 0;
      }
   }

   VEMS_vidSET(Acq_tooth_compteur, u8LocalAcqToothCompteur);
   VEMS_vidSET(Acq_dernier_tps_inter_dent_vileb,
               u32LocalAcqDernierTpsInterDent);
   VEMS_vidSET(Acq_av_dernie_tps_int_dent_vileb,
               u32LocalAcqavDernieTpsIntDentVil);
   VEMS_vidSET(Acq_angle_moteur, u16LocalAcqAngleMoteur);

   if (bLocalAcqSensRotationMoteur == CRKHAL_bFWD_ROTATION)
   {
      VEMS_vidSET(Acq_sens_rotation_moteur, 1);
   }
   else
   {
      VEMS_vidSET(Acq_sens_rotation_moteur, 0);
   }

   udtLocalStatus = CRKHAL_udtReadStatus(CRKHAL_u8ENG_POSITION_KNOWN,
                                         &bLocalStatus);
   if (udtLocalStatus == E_OK)
   {
      bLocalAcqpositionanglairemoteur = bLocalStatus;
   }
   else
   {
      bLocalAcqpositionanglairemoteur = 0;
   }
   VEMS_vidSET(Acq_position_anglaire_moteur, bLocalAcqpositionanglairemoteur);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidCtEdgeCmInStrt                                */
/* !Description :  Fonction qui permet la lecture de la position angulaire du */
/*                 front AAC admission.                                       */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtGetToothInfo(argin uint8 u8MaxTableSize, argio */
/*  uint32 *pau32ToothInfoTable)Std_ReturnType;                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_noMaxTableSize_C;                                        */
/*  output uint16 Acq_pos_ang_moteur_front_aac_adm;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidCtEdgeCmInStrt(void)
{
   Std_ReturnType udtLocalStatus;
   uint16         u16LocalAcqPosAngMotFrontAacAdm;
   uint32         au32ToothInfoTable[LAYERSYNC_u8MAX_TAB_SIZE];


   udtLocalStatus = CRKHAL_udtGetToothInfo(Sync_noMaxTableSize_C,
                                           &au32ToothInfoTable[0]);
   if (udtLocalStatus != E_OK)
   {
      u16LocalAcqPosAngMotFrontAacAdm = 0;
   }
   else
   {
      u16LocalAcqPosAngMotFrontAacAdm =
         (uint16)MATHSRV_udtMIN(au32ToothInfoTable[3], 46079);
   }

   VEMS_vidSET(Acq_pos_ang_moteur_front_aac_adm,
               u16LocalAcqPosAngMotFrontAacAdm);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidCtEdgeCmExStrt                                */
/* !Description :  Fonction qui permet la lecture de la position angulaire du */
/*                 front AAC échappement                                      */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtGetToothInfo(argin uint8 u8MaxTableSize, argio */
/*  uint32 *pau32ToothInfoTable)Std_ReturnType;                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_noMaxTableSize_C;                                        */
/*  output uint16 Acq_pos_ang_moteur_front_aac_ech;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidCtEdgeCmExStrt(void)
{
   Std_ReturnType udtLocalStatus;
   uint16         u16LocalAcqPosAngMotFrontAacEch;
   uint32         au32ToothInfoTable[LAYERSYNC_u8MAX_TAB_SIZE];


   udtLocalStatus = CRKHAL_udtGetToothInfo(Sync_noMaxTableSize_C,
                                           &au32ToothInfoTable[0]);
   if (udtLocalStatus != E_OK)
   {
      u16LocalAcqPosAngMotFrontAacEch = 0;
   }
   else
   {
      u16LocalAcqPosAngMotFrontAacEch =
         (uint16)MATHSRV_udtMIN(au32ToothInfoTable[3], 46079);
   }
   VEMS_vidSET(Acq_pos_ang_moteur_front_aac_ech,
               u16LocalAcqPosAngMotFrontAacEch);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidChangeOfMind                                  */
/* !Description :  Fonction qui permet la lecture de ll'état de a position    */
/*                 angulaire du moteur sur l’évènement N_Inv_Off.             */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtReadStatus(argin uint8 u8Channel, argio boolean*/
/*  *pbStatus)Std_ReturnType;                                                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acq_statut_pos_angulaire_moteur;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidChangeOfMind(void)
{
   Std_ReturnType udtLocalStatus;
   boolean        bLocalStatus;
   boolean        bLocalReadStatus;
   boolean        bLocalAcqStatutPosAngulaireMot;


   udtLocalStatus = CRKHAL_udtReadStatus(CRKHAL_u8ENG_POSITION_KNOWN,
                                         &bLocalStatus);
   if (udtLocalStatus == E_OK)
   {
      bLocalReadStatus = bLocalStatus;
   }
   else
   {
      bLocalReadStatus = 0;
   }

   if (bLocalReadStatus == 0)
   {
      bLocalAcqStatutPosAngulaireMot = 1;
   }
   else
   {
      bLocalAcqStatutPosAngulaireMot = 0;
   }
   VEMS_vidSET(Acq_statut_pos_angulaire_moteur, bLocalAcqStatutPosAngulaireMot);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidCtEdgeCmInRstrt                               */
/* !Description :  Fonction qui permet la lecture de la position angulaire du */
/*                 front AAC admission.                                       */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtGetToothInfo(argin uint8 u8MaxTableSize, argio */
/*  uint32 *pau32ToothInfoTable)Std_ReturnType;                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_noMaxTableSize_C;                                        */
/*  output uint16 Acq_pos_ang_red_mot_frt_aac_adm;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidCtEdgeCmInRstrt(void)
{
   Std_ReturnType udtLocalStatus;
   uint16         u16LocalAcqPosAngRedMotFrtAacAdm;
   uint32         au32ToothInfoTable[LAYERSYNC_u8MAX_TAB_SIZE];


   udtLocalStatus = CRKHAL_udtGetToothInfo(Sync_noMaxTableSize_C,
                                           &au32ToothInfoTable[0]);
   if (udtLocalStatus != E_OK)
   {
      u16LocalAcqPosAngRedMotFrtAacAdm = 0;
   }
   else
   {
      u16LocalAcqPosAngRedMotFrtAacAdm =
         (uint16)MATHSRV_udtMIN(au32ToothInfoTable[3], 46079);
   }
   VEMS_vidSET(Acq_pos_ang_red_mot_frt_aac_adm,
               u16LocalAcqPosAngRedMotFrtAacAdm);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidCtEdgeCmExRstrt                               */
/* !Description :  Fonction qui permet la lecture de la position angulaire du */
/*                 front AAC échappement                                      */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtGetToothInfo(argin uint8 u8MaxTableSize, argio */
/*  uint32 *pau32ToothInfoTable)Std_ReturnType;                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_noMaxTableSize_C;                                        */
/*  output uint16 Acq_pos_ang_red_mot_frnt_aac_ech;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidCtEdgeCmExRstrt(void)
{
   Std_ReturnType udtLocalStatus;
   uint16         u16LocalAcqPosAngRedMotFrntAcEch;
   uint32         au32ToothInfoTable[LAYERSYNC_u8MAX_TAB_SIZE];


   udtLocalStatus = CRKHAL_udtGetToothInfo(Sync_noMaxTableSize_C,
                                           &au32ToothInfoTable[0]);
   if (udtLocalStatus != E_OK)
   {
      u16LocalAcqPosAngRedMotFrntAcEch = 0;
   }
   else
   {
      u16LocalAcqPosAngRedMotFrntAcEch =
         (uint16)MATHSRV_udtMIN(au32ToothInfoTable[3], 46079);
   }
   VEMS_vidSET(Acq_pos_ang_red_mot_frnt_aac_ech,
               u16LocalAcqPosAngRedMotFrntAcEch);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidEngStopPosn                                   */
/* !Description :  Fonction qui permet d'effectuer la lecture de l’API donnant*/
/*                 la position  d’arrêt moteur calculée.                      */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRKHAL_udtGetEngStopPosition(argin uint8                 */
/*  u8EngStopPositionType, argio uint16 *pu16EngStopPosition)Std_ReturnType;  */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acq_angle_arret_moteur;                                      */
/*  output uint16 Acq_angle_arret_moteur;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidEngStopPosn(void)
{
   Std_ReturnType udtLocalStatus;
   uint16         u16LocalEngStopPosition;
   uint16         u16LocalAcqAngleArretMoteur;


   udtLocalStatus = CRKHAL_udtGetEngStopPosition(CRKHAL_u8STOP_POSITION,
                                                 &u16LocalEngStopPosition);
   if (udtLocalStatus == E_OK)
   {
      u16LocalAcqAngleArretMoteur = u16LocalEngStopPosition;
   }
   else
   {
      VEMS_vidGET(Acq_angle_arret_moteur, u16LocalAcqAngleArretMoteur);
   }

   u16LocalAcqAngleArretMoteur =
      (uint16)MATHSRV_udtMIN(u16LocalAcqAngleArretMoteur, 46079);
   VEMS_vidSET(Acq_angle_arret_moteur, u16LocalAcqAngleArretMoteur);
}
/*------------------------------- end of file --------------------------------*/