/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSECUMNG                                              */
/* !Description     : THRSECUMNG component.                                   */
/*                                                                            */
/* !Module          : THRSECUMNG                                              */
/* !Description     : GESTION DES MODES DE SECURITE DU PAPILLON MOTORISE      */
/*                                                                            */
/* !File            : THRSECUMNG_FCT1.C                                       */
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
/*   1 / THRSECUMNG_vidSFControlPart                                          */
/*   2 / THRSECUMNG_vidSelectThrottlePos                                      */
/*   3 / THRSECUMNG_vidSelectThrotThrusts                                     */
/*   4 / THRSECUMNG_vidSelectLimpHome                                         */
/*                                                                            */
/* !Reference   : V02 NT 08 05135 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRSECUMNG.h"
#include "THRSECUMNG_L.h"
#include "THRSECUMNG_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSECUMNG_vidSFControlPart                                */
/* !Description :  L'automate de gestion des voies d'acquisition de la        */
/*                 position papillon motorisé comporte 4 états: Normal (pas de*/
/*                 pannes), Single_1/Single_2 (Détection d'une panne          */
/*                 électrique mémorisée sur l’un des 2 capteurs), Failure     */
/*                 (mesure invalide/panne cohérence).                         */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  GDOURA                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRSECUMNG_vidSelectThrotThrusts();                      */
/*  extf argret void THRSECUMNG_vidSelectLimpHome();                          */
/*  input st21 Ssm_throttle_pos_sensing_status;                               */
/*   input bool SSM_THROTTLE_POS_FAILURE;                                     */
/*   input bool SSM_THROTTLE_POS_SINGLE_1;                                    */
/*   input bool SSM_THROTTLE_POS_SINGLE_2;                                    */
/*   input bool SSM_THROTTLE_POS_NORMAL;                                      */
/*   output st21 Ssm_throttle_pos_sensing_status;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSECUMNG_vidSFControlPart(void)
{
   boolean bLocalInhSecuMngThrPosnSen;
   boolean bLocalInhSecuMngThrPosnSen1;
   boolean bLocalInhSecuMngThrPosnSen2;
   uint8   u8LocalSsmThrPosSensingStatus;
   uint8   u8LocalStatus;

   VEMS_vidGET(Ssm_throttle_pos_sensing_status, u8LocalSsmThrPosSensingStatus);

   bLocalInhSecuMngThrPosnSen =
      GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN);
   bLocalInhSecuMngThrPosnSen1 =
      GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN1);
   bLocalInhSecuMngThrPosnSen2 =
      GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN2);

   if (  (bLocalInhSecuMngThrPosnSen != 0)
      || (  (bLocalInhSecuMngThrPosnSen1 != 0)
         && (bLocalInhSecuMngThrPosnSen2 != 0)))
   {
      u8LocalStatus = SSM_THROTTLE_POS_FAILURE;
   }
   else
   {
      if ( (bLocalInhSecuMngThrPosnSen1 == 0)
           && (bLocalInhSecuMngThrPosnSen2 != 0))
      {
         if  (u8LocalSsmThrPosSensingStatus != SSM_THROTTLE_POS_FAILURE)
         {
            u8LocalStatus = SSM_THROTTLE_POS_SINGLE_1;
         }
         else
         {
            u8LocalStatus = SSM_THROTTLE_POS_FAILURE;
         }
      }
      else
      {
         if (bLocalInhSecuMngThrPosnSen1 != 0)
         {
            if  (u8LocalSsmThrPosSensingStatus != SSM_THROTTLE_POS_FAILURE)
            {
               u8LocalStatus = SSM_THROTTLE_POS_SINGLE_2;
            }
            else
            {
               u8LocalStatus = SSM_THROTTLE_POS_FAILURE;
            }
         }
         else
         {
            u8LocalStatus = SSM_THROTTLE_POS_NORMAL;
         }
      }
   }

   VEMS_vidSET(Ssm_throttle_pos_sensing_status, u8LocalStatus);
   if (u8LocalSsmThrPosSensingStatus != u8LocalStatus)
   {
      THRSECUMNG_vidSelectThrotThrusts();
      THRSECUMNG_vidSelectLimpHome();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSECUMNG_vidSelectThrottlePos                            */
/* !Description :  La position fournie au reste de l'applicatif peut etre     */
/*                 celle issue du capteur n°1 lorsque l'automate est dans     */
/*                 l'état "NORMAL" ou "SINGLE_1", celle du capteur n°2 lorsque*/
/*                 l'automate est dans l'état "SINGLE_2" ou par défaut        */
/*                 calibrable à  l'état "FAILURE".                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  GDOURA                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st21 Ssm_throttle_pos_sensing_status;                               */
/*  input boolean Tpac_pos_filt_med_inh;                                      */
/*  input uint16 Tps_1_raw_filt_position;                                     */
/*  input uint16 Tpac_1_filt_filt_position;                                   */
/*  input uint16 Tps_2_raw_filt_position;                                     */
/*  input uint16 Tpac_2_filt_filt_position;                                   */
/*  input uint16 Ssm_default_throttle_position;                               */
/*  output uint16 Ssm_raw_filt_throttle_position;                             */
/*  output uint8 Position_papillon;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSECUMNG_vidSelectThrottlePos(void)
{
   uint16 u16LocalSsmRawFiltThrottlePos;
   uint16 u16LocalThrottlePosition;
   uint16 u16LocalTpac_1_filt_filtPosition;
   uint16 u16LocalTps_1_raw_filt_position;
   uint16 u16LocalTps_2_raw_filt_position;
   uint16 u16LocalTpac_2_filt_filtPosition;
   uint8  u8LocalSsmThrPosSensingStatus;
   uint8  u8LocalPosition_papillon;


   VEMS_vidGET(Ssm_throttle_pos_sensing_status, u8LocalSsmThrPosSensingStatus);
   if (  (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_NORMAL)
      || (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_SINGLE_1))
   {
      if (Tpac_pos_filt_med_inh != 0)
      {
         VEMS_vidGET(Tps_1_raw_filt_position, u16LocalTps_1_raw_filt_position);
         u16LocalSsmRawFiltThrottlePos = u16LocalTps_1_raw_filt_position;
      }
      else
      {
         VEMS_vidGET(Tpac_1_filt_filt_position,
                     u16LocalTpac_1_filt_filtPosition);
         u16LocalSsmRawFiltThrottlePos = u16LocalTpac_1_filt_filtPosition;
      }
   }
   else
   {
      if (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_SINGLE_2)
      {
         if (Tpac_pos_filt_med_inh != 0)
         {
            VEMS_vidGET(Tps_2_raw_filt_position,
                        u16LocalTps_2_raw_filt_position);
            u16LocalSsmRawFiltThrottlePos = u16LocalTps_2_raw_filt_position;
         }
         else
         {
            VEMS_vidGET(Tpac_2_filt_filt_position,
                        u16LocalTpac_2_filt_filtPosition);
            u16LocalSsmRawFiltThrottlePos = u16LocalTpac_2_filt_filtPosition;
         }
      }
      else
      {
         u16LocalSsmRawFiltThrottlePos = Ssm_default_throttle_position;
      }
   }

   u16LocalSsmRawFiltThrottlePos =
            (uint16)MATHSRV_udtMIN(u16LocalSsmRawFiltThrottlePos, 1024);
   VEMS_vidSET(Ssm_raw_filt_throttle_position, u16LocalSsmRawFiltThrottlePos);

   u16LocalThrottlePosition = (uint16)((u16LocalSsmRawFiltThrottlePos + 2) / 4);
   u8LocalPosition_papillon = (uint8)MATHSRV_udtMIN(u16LocalThrottlePosition,
                                                    255);
   VEMS_vidSET(Position_papillon, u8LocalPosition_papillon);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSECUMNG_vidSelectThrotThrusts                           */
/* !Description :  Les butées fournies au reste de l'applicatif peuvent etre  */
/*                 ceux mesurées sur le capteur n°1 lorsque l'automate est    */
/*                 dans l'état "NORMAL" ou "SINGLE_1"ou ceux du capteur n°2   */
/*                 lorsque l'automate est dans l'état "SINGLE_2". Les butées  */
/*                 sont rafraîchies au Reset.                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  GDOURA                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st21 Ssm_throttle_pos_sensing_status;                               */
/*  input uint16 Tpac_1_clo_throttle_filt_pos;                                */
/*  input uint16 Tpac_1_open_throttle_pos;                                    */
/*  input uint16 Tpac_2_clo_throttle_filt_pos;                                */
/*  input uint16 Tpac_2_open_throttle_pos;                                    */
/*  input uint16 Ssm_default_closed_throttle_pos;                             */
/*  input uint16 Ssm_default_open_throttle_pos;                               */
/*  output uint16 Ssm_closed_throttle_pos;                                    */
/*  output uint16 Ssm_open_throttle_pos;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSECUMNG_vidSelectThrotThrusts(void)
{
   uint16 u16LocalSsmClosedThrottlePos;
   uint16 u16LocalSsmOpenThrottlePos;
   uint16 u16LocalTpac1CloThrottleFiltPos;
   uint16 u16LocalTpac_1_open_throttle_pos;
   uint16 u16LocalTpac_2_clo_thr_filt_pos;
   uint16 u16LocalTpac_2_open_throttle_pos;
   uint8  u8LocalSsmThrPosSensingStatus;


   VEMS_vidGET(Ssm_throttle_pos_sensing_status, u8LocalSsmThrPosSensingStatus);
   if (  (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_NORMAL)
      || (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_SINGLE_1))
   {
      VEMS_vidGET(Tpac_1_clo_throttle_filt_pos,
                  u16LocalTpac1CloThrottleFiltPos);
      VEMS_vidGET(Tpac_1_open_throttle_pos,
                  u16LocalTpac_1_open_throttle_pos);
      u16LocalSsmClosedThrottlePos = u16LocalTpac1CloThrottleFiltPos;
      u16LocalSsmOpenThrottlePos = u16LocalTpac_1_open_throttle_pos;
   }
   else
   {
      if (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_SINGLE_2)
      {
         VEMS_vidGET(Tpac_2_clo_throttle_filt_pos,
                     u16LocalTpac_2_clo_thr_filt_pos);
         VEMS_vidGET(Tpac_2_open_throttle_pos,
                     u16LocalTpac_2_open_throttle_pos);
         u16LocalSsmClosedThrottlePos = u16LocalTpac_2_clo_thr_filt_pos;
         u16LocalSsmOpenThrottlePos = u16LocalTpac_2_open_throttle_pos;
      }
      else
      {
         u16LocalSsmClosedThrottlePos = Ssm_default_closed_throttle_pos;
         u16LocalSsmOpenThrottlePos = Ssm_default_open_throttle_pos;
      }
   }

   u16LocalSsmClosedThrottlePos =
      (uint16)MATHSRV_udtMIN(u16LocalSsmClosedThrottlePos, 1024);
   VEMS_vidSET(Ssm_closed_throttle_pos, u16LocalSsmClosedThrottlePos);

   u16LocalSsmOpenThrottlePos =
      (uint16)MATHSRV_udtMIN(u16LocalSsmOpenThrottlePos, 1024);
   VEMS_vidSET(Ssm_open_throttle_pos, u16LocalSsmOpenThrottlePos);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSECUMNG_vidSelectLimpHome                               */
/* !Description :  La position  limp home fournie au reste de l'applicatif    */
/*                 peut etre celle mesurées sur le capteur n°1 lorsque        */
/*                 l'automate est dans l'état "NORMAL" ou "SINGLE_1"ou celle  */
/*                 du capteur n°2 à l'état "SINGLE_2" ou par défaut calibrable*/
/*                 à l'état "FAILURE".                                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  GDOURA                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st21 Ssm_throttle_pos_sensing_status;                               */
/*  input uint16 Tpac_1_limp_home_pos;                                        */
/*  input uint16 Tpac_2_limp_home_pos;                                        */
/*  input uint16 Ssm_default_limp_home_pos;                                   */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  output uint16 Ssm_limp_home_throttle_pos;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSECUMNG_vidSelectLimpHome(void)
{
   uint16 u16LocalSsmLimpHome;
   uint16 u16LocalTpac_1_limp_home_pos;
   uint16 u16LocalTpac_2_limp_home_pos;
   uint16 u16LocalSsmLimpHomeThrottlePos;
   uint16 u16LocalSsm_closed_throttle_pos;
   uint8  u8LocalSsmThrPosSensingStatus;
   sint32 s32LocalSsmLimpH;


   VEMS_vidGET(Ssm_throttle_pos_sensing_status, u8LocalSsmThrPosSensingStatus);
   if (  (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_NORMAL)
      || (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_SINGLE_1))
   {
      VEMS_vidGET(Tpac_1_limp_home_pos, u16LocalTpac_1_limp_home_pos);
      u16LocalSsmLimpHome = u16LocalTpac_1_limp_home_pos;
   }
   else
   {
      if (u8LocalSsmThrPosSensingStatus == SSM_THROTTLE_POS_SINGLE_2)
      {
         VEMS_vidGET(Tpac_2_limp_home_pos, u16LocalTpac_2_limp_home_pos);
         u16LocalSsmLimpHome = u16LocalTpac_2_limp_home_pos;
      }
      else
      {
         u16LocalSsmLimpHome = Ssm_default_limp_home_pos;
      }
   }

   VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_closed_throttle_pos);
   s32LocalSsmLimpH = (sint32)( u16LocalSsmLimpHome
                              - u16LocalSsm_closed_throttle_pos);

   u16LocalSsmLimpHomeThrottlePos = (uint16)MATHSRV_udtCLAMP(s32LocalSsmLimpH,
                                                             0,
                                                             1024);
   VEMS_vidSET(Ssm_limp_home_throttle_pos, u16LocalSsmLimpHomeThrottlePos);
}

/*------------------------------- end of file --------------------------------*/