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
/* !File            : LAYERSYNC_FCT1.C                                        */
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
/*   1 / LAYERSYNC_vidInitAPI                                                 */
/*   2 / LAYERSYNC_vidAcquiDureeDent                                          */
/*   3 / LAYERSYNC_vidAcquiPeriodeMoteur                                      */
/*   4 / LAYERSYNC_vidTrouverPhaseMoteur                                      */
/*   5 / LAYERSYNC_vidPhaseCylEch                                             */
/*   6 / LAYERSYNC_vidDiagExCm                                                */
/*   7 / LAYERSYNC_vidIniExAcq                                                */
/*   8 / LAYERSYNC_vidIniExCmAcq                                              */
/*   9 / LAYERSYNC_vidExAcq                                                   */
/*   10 / LAYERSYNC_vidExCmSt                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6944973 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/LAYERSYNC/LAYERSYNC_FCT1.c_v      $*/
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
#include "TDCHAL.h"
#include "DGOHAL.h"
#include "CAMHAL.h"
#include "LAYERSYNC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidInitAPI                                       */
/* !Description :  L’autorisation de recherche de détection de front du signal*/
/*                 vilebrequin se fait uniquement après que les tests         */
/*                 fonctionnels aient été effectués.                          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  CRKHAL_udtEnableDetection();                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidInitAPI(void)
{
   (void)CRKHAL_udtEnableDetection();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidAcquiDureeDent                                */
/* !Description :  La durée dent est désormais également calculée sur la tâche*/
/*                 calé tournant (Event_tache_cale_tournant)                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  CRKHAL_udtReadLastToothDuration(argout uint32 */
/*  *pu32Duration);                                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 Acqui_duree_dent;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidAcquiDureeDent(void)
{
   Std_ReturnType  udtLocalStatus;
   /* !QAC : Msg(3:3203) this warning is due to the use of HAL_API */
   uint32          u32LocalAcquiDureeDent;


   udtLocalStatus = CRKHAL_udtReadLastToothDuration(&u32LocalAcquiDureeDent);
   /* !QAC : Msg(3:3199) this warning is due to the use of HAL_API */
   VEMS_vidSET(Acqui_duree_dent, u32LocalAcquiDureeDent);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidAcquiPeriodeMoteur                            */
/* !Description :  Fonction qui permet l'aquisition de la période du moteur   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  TDCHAL_udtGetPeriod(argout uint32             */
/*  *pu32Period);                                                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 Acqui_periode_moteur;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidAcquiPeriodeMoteur(void)
{
   Std_ReturnType  udtLocalStatus;
   /* !QAC : Msg(3:3203) this warning is due to the use of HAL_API */
   uint32          u32LocalAcquiPeriodeMoteur;


   udtLocalStatus = TDCHAL_udtGetPeriod(&u32LocalAcquiPeriodeMoteur);
   /* !QAC : Msg(3:3199) this warning is due to the use of HAL_API */
   VEMS_vidSET(Acqui_periode_moteur, u32LocalAcquiPeriodeMoteur);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidTrouverPhaseMoteur                            */
/* !Description :  Fonction qui permet l'acquisition de la valeur du compteur */
/*                 PMH                                                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  TDCHAL_udtGetCounter(argout uint8             */
/*  *pu8Counter);                                                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Acqui_compteur_de_pmh;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidTrouverPhaseMoteur(void)
{
   Std_ReturnType  udtLocalStatus;
   /* !QAC : Msg(3:3203) this warning is due to the use of HAL_API */
   uint8           u8LocalAcquiCompteurDePmh;


   udtLocalStatus = TDCHAL_udtGetCounter(&u8LocalAcquiCompteurDePmh);
   /* !QAC : Msg(3:3199) this warning is due to the use of HAL_API */
   u8LocalAcquiCompteurDePmh =
      (uint8)MATHSRV_udtMIN(u8LocalAcquiCompteurDePmh, 3);
   VEMS_vidSET(Acqui_compteur_de_pmh, u8LocalAcquiCompteurDePmh);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidPhaseCylEch                                   */
/* !Description :  Fonction qui permet l'acquisition de l'angle du crankshaft */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint16  CRKHAL_u16GetEngineAngle();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acqui_angle_crankshaft;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidPhaseCylEch(void)
{
   uint16 u16LocalAcquiAngleCrankshaft;


   u16LocalAcquiAngleCrankshaft = CRKHAL_u16GetEngineAngle();
   u16LocalAcquiAngleCrankshaft =
      (uint16)MATHSRV_udtMIN(u16LocalAcquiAngleCrankshaft, 46079);
   VEMS_vidSET(Acqui_angle_crankshaft, u16LocalAcquiAngleCrankshaft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidDiagExCm                                      */
/* !Description :  Fonction responsable du diagnostic.                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_chr_excamdiag;                                        */
/*  output boolean Dft_chr_excamdiag;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidDiagExCm(void)
{
   DGOHAL_tbfStatus u32LocalFault;


   u32LocalFault = DGOHAL_bfRead(DGOHAL_udtCAMSHAFTEX);

   if ( (u32LocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_CAMEX_PATTERN)) != 0)
   {
      VEMS_vidSET(Dena_chr_excamdiag, 1);
      if ( (u32LocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_CAMEX_PATTERN))
         != 0)
      {
         VEMS_vidSET(Dft_chr_excamdiag, 1);
      }
      else
      {
         VEMS_vidSET(Dft_chr_excamdiag, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_chr_excamdiag, 0);
      VEMS_vidSET(Dft_chr_excamdiag, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidIniExAcq                                      */
/* !Description :  Au réveil du calculateur, les booléens d’états et leur     */
/*                 indicateur de validité sont forcés à 0.                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidIniExCmAcq();                               */
/*  input boolean Ext_bPresExCmSen;                                           */
/*  output boolean Acq_excam_sync_upvb0;                                      */
/*  output boolean Acq_excam_sync_status_upvb0;                               */
/*  output boolean Acq_excam_tooth_det_upvb0;                                 */
/*  output boolean Acq_excam_tooth_det_vld_upvb0;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidIniExAcq(void)
{
   boolean   bLocalExt_bPresExCmSen;


   VEMS_vidSET(Acq_excam_sync_upvb0, 0);
   VEMS_vidSET(Acq_excam_sync_status_upvb0, 0);
   VEMS_vidSET(Acq_excam_tooth_det_upvb0, 0);
   VEMS_vidSET(Acq_excam_tooth_det_vld_upvb0, 0);

   VEMS_vidGET(Ext_bPresExCmSen, bLocalExt_bPresExCmSen);
   if (bLocalExt_bPresExCmSen != 0)
   {
      LAYERSYNC_vidIniExCmAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidIniExCmAcq                                    */
/* !Description :  Fonction d'initialisation de L'API CAMHAL                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CAMHAL_vidSetMode(argin CAMHAL_tudtChannel               */
/*  udtChannelName, argin CAMHAL_tenuMode enuMode);                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidIniExCmAcq(void)
 {
   CAMHAL_vidSetMode(CAMHAL_udtCH_EXHAUST_CAMSHAFT, CAMHAL_udtNORMAL_MODE);
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidExAcq                                         */
/* !Description :  Afin de délivrer des informations pertinentes et           */
/*                 d’économiser de la charge CPU, les booléens d’états et     */
/*                 leurflag de validité ne sont acquis que si le capteur arbre*/
/*                 à cames echappement est présent sur le moteur.             */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void LAYERSYNC_vidExCmSt();                                   */
/*  input boolean Ext_bPresExCmSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidExAcq(void)
 {
   boolean bLocalExt_bPresExCmSen;


   VEMS_vidGET(Ext_bPresExCmSen, bLocalExt_bPresExCmSen);
   if (bLocalExt_bPresExCmSen != 0)
   {
      LAYERSYNC_vidExCmSt();
   }
 }

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAYERSYNC_vidExCmSt                                        */
/* !Description :  Fonction de diagnostique du  signal arbre à cames          */
/*                 echappement.                                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  CAMHAL_udtReadStatus(argin CAMHAL_tudtChannel        */
/*  udtChannel, argin uint8 u8Channel, argout boolean *pbStatus);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acq_excam_sync_upvb0;                                      */
/*  output boolean Acq_excam_sync_status_upvb0;                               */
/*  output boolean Acq_excam_tooth_det_upvb0;                                 */
/*  output boolean Acq_excam_tooth_det_vld_upvb0;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAYERSYNC_vidExCmSt(void)
 {
   boolean bLocalCAMHALReadStatus;
   boolean bLocalAcqExcamSyncUpvb0;
   boolean bLocalAcqExcamSyncStatuUpvb0;
   boolean bLocalAcqExcamToothDetUpvb0;
   boolean bLocalAcqExcamToothVldUpvb0;


   bLocalCAMHALReadStatus = CAMHAL_udtReadStatus(CAMHAL_udtCH_EXHAUST_CAMSHAFT,
                                                 CAMHAL_u8SYNCHRONISED,
                                                 &bLocalAcqExcamSyncUpvb0);
   if (bLocalCAMHALReadStatus == E_OK)
   {
      bLocalAcqExcamSyncStatuUpvb0 = 1;
   }
   else
   {
      bLocalAcqExcamSyncStatuUpvb0 = 0;
   }

   bLocalCAMHALReadStatus = CAMHAL_udtReadStatus(CAMHAL_udtCH_EXHAUST_CAMSHAFT,
                                                 CAMHAL_u8DETECTED,
                                                 &bLocalAcqExcamToothDetUpvb0);
   if (bLocalCAMHALReadStatus == E_OK)
   {
      bLocalAcqExcamToothVldUpvb0 = 1;
   }
   else
   {
      bLocalAcqExcamToothVldUpvb0 = 0;
   }

   VEMS_vidSET(Acq_excam_sync_upvb0, bLocalAcqExcamSyncUpvb0);
   VEMS_vidSET(Acq_excam_sync_status_upvb0, bLocalAcqExcamSyncStatuUpvb0);
   VEMS_vidSET(Acq_excam_tooth_det_upvb0, bLocalAcqExcamToothDetUpvb0);
   VEMS_vidSET(Acq_excam_tooth_det_vld_upvb0, bLocalAcqExcamToothVldUpvb0);
 }
/*------------------------------- end of file --------------------------------*/