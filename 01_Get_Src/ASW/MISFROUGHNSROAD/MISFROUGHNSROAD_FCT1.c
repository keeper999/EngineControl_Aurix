/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFROUGHNSROAD                                         */
/* !Description     : MISFROUGHNSROAD component.                              */
/*                                                                            */
/* !Module          : MISFROUGHNSROAD                                         */
/* !Description     : DETECTION DE LA MAUVAISE ROUTE                          */
/*                                                                            */
/* !File            : MISFROUGHNSROAD_FCT1.C                                  */
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
/*   1 / MISFROUGHNSROAD_vidInitOutput                                        */
/*   2 / MISFROUGHNSROAD_vidRoughRoad                                         */
/*   3 / MISFROUGHNSROAD_vidRghRoadDetect                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 02692 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFROUGHNSROAD/MISFROUGHNSRO$*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   15 Jan 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include"STD_TYPES.h"
#include"MATHSRV.h"
#include"MISFROUGHNSROAD.h"
#include"MISFROUGHNSROAD_L.h"
#include"MISFROUGHNSROAD_IM.h"
#include"GDGAR.h"
#include"VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFROUGHNSROAD_vidInitOutput                              */
/* !Description :  Cette fonction initialise la variable de sortie du module  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_rough_road_uavb0;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : A.LABBENE                                                   */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFROUGHNSROAD_vidInitOutput(void)
{
   VEMS_vidSET(Mf_rough_road_uavb0, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFROUGHNSROAD_vidRoughRoad                               */
/* !Description :  Cette fonction implémente la stratégie de détection de la  */
/*                 mauvaise route dans le cadre de la stratégie générique de  */
/*                 détection de misfire.                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFROUGHNSROAD_vidRghRoadDetect();                      */
/*  input boolean Mf_algo_cond_ok_uavb0;                                      */
/*  input boolean Mf_pfilt_comb_ena_uacb0;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : A.LABBENE                                                   */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFROUGHNSROAD_vidRoughRoad(void)
{
   boolean bLocalMf_algo_cond_ok_uavb0;


   VEMS_vidGET(Mf_algo_cond_ok_uavb0, bLocalMf_algo_cond_ok_uavb0);
   if ((bLocalMf_algo_cond_ok_uavb0 != 0) && (Mf_pfilt_comb_ena_uacb0 != 0))
   {
      MISFROUGHNSROAD_vidRghRoadDetect();
   }
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFROUGHNSROAD_vidRghRoadDetect                           */
/* !Description :  Ce module compare la somme des indices de confiance        */
/*                 pondérés avec 2 seuils : Mf_misfire_detected_thresh_uacn0  */
/*                 et un un 2ème seuil plus grand. Dès que des pics se        */
/*                 trouvent entre les 2 seuils, un booléen indique qu'il y a  */
/*                 risque de mauvaise route.                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_02692_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u16CalcParaIncAryU8(????);                                   */
/*  extf MATHSRV_u8Interp2d(????);                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Mf_det_single_output_uavn0;                                   */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint8 Mf_rough_road_det_map_uacn2[7][16];                           */
/*  input uint8 Mf_misfire_detected_thresh_uacn0;                             */
/*  input uint8 Mf_n_min_rough_road_det_uacn0;                                */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint8 Mf_low_veh_speed_thresh_uacn0;                                */
/*  output boolean Mf_rough_road_uavb0;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : A.LABBENE                                                   */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFROUGHNSROAD_vidRghRoadDetect(void)
{
   boolean bLocalAcvRoughnsRoadMod;
   boolean bLocalANDBlock1Output;
   boolean bLocalANDBlock2Output;
   uint8   u8LocalMfDetSingleOutputUavn0;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalVitesse_vehicule;
   uint8   u8LocalInterp;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalEngLim_tqIdcEngCur;
   sint16  s16LocalEngLim_tqIdcEngCur;


   VEMS_vidGET(Mf_det_single_output_uavn0, u8LocalMfDetSingleOutputUavn0);

   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   s16LocalEngLim_tqIdcEngCur =
      (sint16)MATHSRV_udtMAX(s16LocalEngLim_tqIdcEngCur, -32000);
   u16LocalEngLim_tqIdcEngCur = (uint16)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                                u16LocalEngLim_tqIdcEngCur,
                                                7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               16);
   u8LocalInterp = MATHSRV_u8Interp2d(&Mf_rough_road_det_map_uacn2[0][0],
                                      u16LocalParaX,
                                      u16LocalParaY,
                                      16);

   if (  (u8LocalMfDetSingleOutputUavn0 <= Mf_misfire_detected_thresh_uacn0)
      && (u8LocalMfDetSingleOutputUavn0 > u8LocalInterp)
      && (u8LocalRegime_moteur_32 > Mf_n_min_rough_road_det_uacn0))
   {
      bLocalANDBlock1Output = 1;
   }
   else
   {
      bLocalANDBlock1Output = 0;
   }

   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);

   if (  (u8LocalVitesse_vehicule > Mf_low_veh_speed_thresh_uacn0)
      && (u8LocalCoPt_noEgdGearCord != 0))
   {
      bLocalANDBlock2Output = 1;
   }
   else
   {
      bLocalANDBlock2Output = 0;
   }

   bLocalAcvRoughnsRoadMod = GDGAR_bGetFRM(FRM_FRM_ACVROUGHNSROADMOD);

   if (  (bLocalANDBlock1Output !=0)
      && (  (bLocalANDBlock2Output !=0)
         || (bLocalAcvRoughnsRoadMod != 0)))
   {
      VEMS_vidSET(Mf_rough_road_uavb0, 1);
   }
   else
   {
      VEMS_vidSET(Mf_rough_road_uavb0, 0);
   }
}