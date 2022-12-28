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
/* !File            : LAYERSYNC_FCT4.c                                        */
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
/*   1 / LAYERSYNC_vidCkOff                                                   */
/*   2 / LAYERSYNC_vidInit                                                    */
/*   3 / LAYERSYNC_vidIniExAcqPos                                             */
/*   4 / LAYERSYNC_vidIniInAcqPos                                             */
/*   5 / LAYERSYNC_vidAcqExPos                                                */
/*   6 / LAYERSYNC_vidAcqInPos                                                */
/*   7 / LAYERSYNC_vidInitOutput                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6944973 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/LAYERSYNC/LAYERSYNC_FCT4.c_v      $*/
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
#include "CAMHAL.h"
#include "LAYERSYNC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidCkOff                                         */
/* !Description :  Lors de la perte de la synchronisation par le LDB,  ou lors*/
/*                 d’un arrêt moteur, sur l’événement Crank Off, on           */
/*                 réinitialise SyncAcq_bCalcOk.                              */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean SyncAcq_bCalcOk;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidCkOff(void)
{
   SyncAcq_bCalcOk = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidInit                                          */
/* !Description :  Fonction qui permet l'initialisation des outputs           */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void LAYERSYNC_vidIniInAcqPos();                              */
/*  extf argret void LAYERSYNC_vidIniExAcqPos();                              */
/*  input boolean Ext_bPresInCmSen;                                           */
/*  input boolean Ext_bPresExCmSen;                                           */
/*  output uint16 Acquisition_angle_vilb_aac_adm;                             */
/*  output boolean Acquisition_etat_aac_adm;                                  */
/*  output uint32 Acquisition_temps_dents_aac_adm;                            */
/*  output uint16 Acquisition_angle_vilb_aac_ech;                             */
/*  output boolean Acquisition_etat_aac_ech;                                  */
/*  output uint32 Acquisition_temps_dents_aac_ech;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidInit(void)
{
   boolean bLocalExt_bPresInCmSen;
   boolean bLocalExt_bPresExCmSen;


   VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);
   VEMS_vidGET(Ext_bPresExCmSen, bLocalExt_bPresExCmSen);

   VEMS_vidSET(Acquisition_angle_vilb_aac_adm, 0);
   VEMS_vidSET(Acquisition_etat_aac_adm, 0);
   VEMS_vidSET(Acquisition_temps_dents_aac_adm, 4294967250uL);
   VEMS_vidSET(Acquisition_angle_vilb_aac_ech, 0);
   VEMS_vidSET(Acquisition_etat_aac_ech, 0);
   VEMS_vidSET(Acquisition_temps_dents_aac_ech, 4294967250uL);

   if (bLocalExt_bPresInCmSen != 0)
   {
      LAYERSYNC_vidIniInAcqPos();
   }

   if (bLocalExt_bPresExCmSen != 0)
   {
      LAYERSYNC_vidIniExAcqPos();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidIniExAcqPos                                   */
/* !Description :  Fonction pour le reset du calculateur                      */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  CAMHAL_udtEnableDetection(argin               */
/*  CAMHAL_tudtChannel udtChannelName);                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidIniExAcqPos(void)
{
   (void)CAMHAL_udtEnableDetection(CAMHAL_udtCH_EXHAUST_CAMSHAFT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidIniInAcqPos                                   */
/* !Description :  Fonction pour la  reset du calculateur                     */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  CAMHAL_udtEnableDetection(argin               */
/*  CAMHAL_tudtChannel udtChannelName);                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidIniInAcqPos(void)
{
   (void)CAMHAL_udtEnableDetection(CAMHAL_udtCH_INTAKE_CAMSHAFT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidAcqExPos                                      */
/* !Description :  Fonction qui permet l'acquisition de l'angle du vilbrequin,*/
/*                 la période entre les dents ainsi que l'état du front AAC   */
/*                 échappement                                                */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  CAMHAL_udtReadEventPosition(argin             */
/*  CAMHAL_tudtChannel udtChannelName, argout uint16 *pu16Position);          */
/*  extf argret Std_ReturnType  CAMHAL_udtReadToothPeriod(argin               */
/* CAMHAL_tudtChannel udtChannelName, argout uint32 *pu32Period);             */
/*  extf argret Std_ReturnType  CAMHAL_udtReadSignalLevel(argin               */
/* CAMHAL_tudtChannel udtChannelName, argout boolean *bLocalLevel);           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_angle_vilb_aac_ech;                             */
/*  output uint32 Acquisition_temps_dents_aac_ech;                            */
/*  output boolean Acquisition_etat_aac_ech;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidAcqExPos(void)
{
   boolean bLocalLevel;
   uint16  u16LocalAcqAngleVilbAacEch;
   uint32  u32LocalAcqTempsDentsAacEch;


   (void)CAMHAL_udtReadEventPosition(CAMHAL_udtCH_EXHAUST_CAMSHAFT,
                                     &u16LocalAcqAngleVilbAacEch);
   (void)CAMHAL_udtReadToothPeriod(CAMHAL_udtCH_EXHAUST_CAMSHAFT,
                                   &u32LocalAcqTempsDentsAacEch);
   (void)CAMHAL_udtReadSignalLevel(CAMHAL_udtCH_EXHAUST_CAMSHAFT, &bLocalLevel);

   u16LocalAcqAngleVilbAacEch =
      (uint16)MATHSRV_udtMIN(u16LocalAcqAngleVilbAacEch, 46079);
   VEMS_vidSET(Acquisition_angle_vilb_aac_ech,
               u16LocalAcqAngleVilbAacEch);
   VEMS_vidSET(Acquisition_temps_dents_aac_ech,
               u32LocalAcqTempsDentsAacEch);
   VEMS_vidSET(Acquisition_etat_aac_ech, bLocalLevel);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidAcqInPos                                      */
/* !Description :  Fonction qui permet l'acquisition de l'angle du vilbrequin,*/
/*                 la période entre les dents ainsi que l'état du front AAC   */
/*                 admission                                                  */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  CAMHAL_udtReadEventPosition(argin             */
/*  CAMHAL_tudtChannel udtChannelName, argout uint16 *pu16Position);          */
/*  extf argret Std_ReturnType  CAMHAL_udtReadToothPeriod(argin               */
/* CAMHAL_tudtChannel udtChannelName, argout uint32 *pu32Period);             */
/*  extf argret Std_ReturnType  CAMHAL_udtReadSignalLevel(argin               */
/* CAMHAL_tudtChannel udtChannelName, argout boolean *bLocalLevel);           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_angle_vilb_aac_adm;                             */
/*  output uint32 Acquisition_temps_dents_aac_adm;                            */
/*  output boolean Acquisition_etat_aac_adm;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidAcqInPos(void)
{
   boolean bLocalLevel;
   uint16  u16LocalAcqAngleVilbAacAdm;
   uint32  u32LocalAcqTempsDentsAacAdm;


   (void)CAMHAL_udtReadEventPosition(CAMHAL_udtCH_INTAKE_CAMSHAFT,
                                     &u16LocalAcqAngleVilbAacAdm);
   (void)CAMHAL_udtReadToothPeriod(CAMHAL_udtCH_INTAKE_CAMSHAFT,
                                   &u32LocalAcqTempsDentsAacAdm);
   (void)CAMHAL_udtReadSignalLevel(CAMHAL_udtCH_INTAKE_CAMSHAFT, &bLocalLevel);

   u16LocalAcqAngleVilbAacAdm =
      (uint16)MATHSRV_udtMIN(u16LocalAcqAngleVilbAacAdm, 46079);
   VEMS_vidSET(Acquisition_angle_vilb_aac_adm,
               u16LocalAcqAngleVilbAacAdm);
   VEMS_vidSET(Acquisition_temps_dents_aac_adm,
               u32LocalAcqTempsDentsAacAdm);
   VEMS_vidSET(Acquisition_etat_aac_adm, bLocalLevel);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidInitOutput                                    */
/* !Description :  Fonction qui permet l'initialisation des sorties           */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acq_angle_arret_moteur;                                     */
/*  output uint16 Acq_angle_arret_moteur_redem;                               */
/*  output uint16 Acq_angle_moteur;                                           */
/*  output uint32 Acq_av_dernie_tps_int_dent_vileb;                           */
/*  output uint32 Acq_dernier_tps_inter_dent_vileb;                           */
/*  output uint16 Acq_pos_ang_lors_synchro;                                   */
/*  output uint16 Acq_pos_ang_moteur_front_aac_adm;                           */
/*  output uint16 Acq_pos_ang_moteur_front_aac_ech;                           */
/*  output uint16 Acq_pos_ang_red_mot_frnt_aac_ech;                           */
/*  output uint16 Acq_pos_ang_red_mot_frt_aac_adm;                            */
/*  output boolean Acq_position_anglaire_moteur;                              */
/*  output boolean Acq_sens_rotation_moteur;                                  */
/*  output boolean Acq_statut_pos_angulaire_moteur;                           */
/*  output uint8 Acq_tooth_compteur;                                          */
/*  output uint16 Acqui_angle_crankshaft;                                     */
/*  output uint8 Acqui_compteur_de_pmh;                                       */
/*  output uint32 Acqui_duree_dent;                                           */
/*  output uint32 Acqui_periode_moteur;                                       */
/*  output boolean Dena_chr_excamdiag;                                        */
/*  output boolean Dena_chr_incamdiag;                                        */
/*  output boolean Dft_chr_excamdiag;                                         */
/*  output boolean Dft_chr_incamdiag;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidInitOutput(void)
{
   VEMS_vidSET(Acq_angle_arret_moteur, 0);
   VEMS_vidSET(Acq_angle_arret_moteur_redem, 0);
   VEMS_vidSET(Acq_angle_moteur, 0);
   VEMS_vidSET(Acq_av_dernie_tps_int_dent_vileb, 0);
   VEMS_vidSET(Acq_dernier_tps_inter_dent_vileb, 0);
   VEMS_vidSET(Acq_pos_ang_lors_synchro, 0);
   VEMS_vidSET(Acq_pos_ang_moteur_front_aac_adm, 0);
   VEMS_vidSET(Acq_pos_ang_moteur_front_aac_ech, 0);
   VEMS_vidSET(Acq_pos_ang_red_mot_frnt_aac_ech, 0);
   VEMS_vidSET(Acq_pos_ang_red_mot_frt_aac_adm, 0);
   VEMS_vidSET(Acq_position_anglaire_moteur, 0);
   VEMS_vidSET(Acq_sens_rotation_moteur, 0);
   VEMS_vidSET(Acq_statut_pos_angulaire_moteur, 0);
   VEMS_vidSET(Acq_tooth_compteur, 0);
   VEMS_vidSET(Acqui_angle_crankshaft, 0);
   VEMS_vidSET(Acqui_compteur_de_pmh, 0);
   VEMS_vidSET(Acqui_duree_dent, 0);
   VEMS_vidSET(Acqui_periode_moteur, 0);
   VEMS_vidSET(Dena_chr_excamdiag, 0);
   VEMS_vidSET(Dena_chr_incamdiag, 0);
   VEMS_vidSET(Dft_chr_excamdiag, 0);
   VEMS_vidSET(Dft_chr_incamdiag, 0);
}
/*------------------------------- end of file --------------------------------*/