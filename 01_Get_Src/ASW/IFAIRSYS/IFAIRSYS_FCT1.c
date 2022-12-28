/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYS                                                */
/* !Description     : IFAIRSYS Component                                      */
/*                                                                            */
/* !Module          : IFAIRSYS                                                */
/* !Description     : INTERFACE DE LA CHAINE D AIR                            */
/*                                                                            */
/* !File            : IFAIRSYS_FCT1.C                                         */
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
/*   1 / IFAIRSYS_vidInitOutput                                               */
/*   2 / IFAIRSYS_vidAccP                                                     */
/*   3 / IFAIRSYS_vidCrkMgt                                                   */
/*   4 / IFAIRSYS_vidThr                                                      */
/*   5 / IFAIRSYS_vidVehRun                                                   */
/*   6 / IFAIRSYS_vidInj                                                      */
/*   7 / IFAIRSYS_vidBoostPressure                                            */
/*   8 / IFAIRSYS_vidmfAirMid2                                                */
/*   9 / IFAIRSYS_vidInitFilter                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5199971 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/AIRSYS/IFAIRSYS/IFAIRSYS_FCT1.C_$*/
/* $Revision::   1.10     $$Author::   etsasson       $$Date::   15 May 2013 $*/
/* $Author::   etsasson                               $$Date::   15 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IFAIRSYS.h"
#include "IFAIRSYS_L.h"
#include "IFAIRSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidInitOutput                                     */
/* !Description :  Initialisation des sorties du module IFAIRSYS.             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean AccP_bAccPMin;                                             */
/*  output uint32 AirSys_arEfcThrReqWoutTqSys;                                */
/*  output uint16 AirSys_facTranAir;                                          */
/*  output uint16 ThrLrn_rOpSI;                                               */
/*  output boolean Veh_bRunVeh;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidInitOutput(void)
{
   VEMS_vidSET(AccP_bAccPMin, 0);
   VEMS_vidSET(AirSys_arEfcThrReqWoutTqSys, 0);
   VEMS_vidSET(AirSys_facTranAir, 0);
   VEMS_vidSET(ThrLrn_rOpSI, 0);
   VEMS_vidSET(Veh_bRunVeh, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidAccP                                           */
/* !Description :  Production de l'indicateur position pédale pied levé       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Dv_detection_pied_leve;                                     */
/*  output boolean AccP_bAccPMin;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidAccP(void)
{
   boolean bLocalDv_detection_pied_leve;
   boolean bLocalAccP_bAccPMin;


   VEMS_vidGET(Dv_detection_pied_leve, bLocalDv_detection_pied_leve);
   if (bLocalDv_detection_pied_leve != 0)
   {
      bLocalAccP_bAccPMin = 1;
   }
   else
   {
      bLocalAccP_bAccPMin = 0;
   }
   VEMS_vidSET(AccP_bAccPMin, bLocalAccP_bAccPMin);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidCrkMgt                                         */
/* !Description :  Ce bloc contient les entrées de la chaine d’air issus de la*/
/*                 chaine d’injection.                                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Dtc_surf_hors_struc_couple;                                  */
/*  input uint8 Coef_de_transition_air;                                       */
/*  output uint32 AirSys_arEfcThrReqWoutTqSys;                                */
/*  output uint16 AirSys_facTranAir;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidCrkMgt(void)
{
   uint8  u8LocalCoef_de_transition_air;
   uint16 u16LocalAirSys_facTranAir;
   uint32 u32LocalDtc_surf_horstruccouple;


   VEMS_vidGET(Dtc_surf_hors_struc_couple, u32LocalDtc_surf_horstruccouple);
   VEMS_vidSET(AirSys_arEfcThrReqWoutTqSys, u32LocalDtc_surf_horstruccouple);

   VEMS_vidGET(Coef_de_transition_air, u8LocalCoef_de_transition_air);
   u16LocalAirSys_facTranAir = u8LocalCoef_de_transition_air;
   VEMS_vidSET(AirSys_facTranAir, u16LocalAirSys_facTranAir);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidThr                                            */
/* !Description :  Ce bloc contient les entrées de la chaine d’air issus de la*/
/*                 chaine d’injection.                                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  output uint16 ThrLrn_rOpSI;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidThr(void)
{
   uint16 u16LocalThrLrn_rOpSI;
   uint16 u16LocalTpac_corr_throt_pos;

   VEMS_vidGET(Tpac_corrected_throttle_position, u16LocalTpac_corr_throt_pos);
   u16LocalThrLrn_rOpSI = (uint16)MATHSRV_udtMIN(u16LocalTpac_corr_throt_pos,
                                                 1024);
   VEMS_vidSET(ThrLrn_rOpSI, u16LocalThrLrn_rOpSI);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidVehRun                                         */
/* !Description :  Production de l'indicateur véhicule roulant.               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Vehicule_roulant;                                           */
/*  output boolean Veh_bRunVeh;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidVehRun(void)
{
   boolean bLocalVehicule_roulant;

   VEMS_vidGET(Vehicule_roulant, bLocalVehicule_roulant);
   VEMS_vidSET(Veh_bRunVeh, bLocalVehicule_roulant);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidInj                                            */
/* !Description :  Ce bloc contient les entrées de la chaine d’air issus de la*/
/*                 chaine d’injection.                                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input boolean InjSys_prm_bCylCutOff[6];                                   */
/*  output boolean InjSys_prm_bInjCutOffCyl[6];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidInj(void)
{
   boolean bLocalTInjSys_prm_bInjCutOffCyl[6];
   /* QAC_Warning: Msg(2:3204): due to the use of VEMS_vidGET1DArray macro */

   VEMS_vidGET1DArray(InjSys_prm_bCylCutOff,
                      6,
                      bLocalTInjSys_prm_bInjCutOffCyl);
   VEMS_vidSET1DArray(InjSys_prm_bInjCutOffCyl,
                      6,
                      bLocalTInjSys_prm_bInjCutOffCyl);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidBoostPressure                                  */
/* !Description :  Ce bloc contient les entrées de la chaine d’air issus de la*/
/*                 chaine d’injection.                                        */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acq_spg_pres_measured;                                       */
/*  output uint16 Ext_pUsThrMesSI;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidBoostPressure(void)
{
   uint16 u16LocalAcq_spg_pres_measured;


   VEMS_vidGET(Acq_spg_pres_measured, u16LocalAcq_spg_pres_measured);
   VEMS_vidSET(Ext_pUsThrMesSI, u16LocalAcq_spg_pres_measured);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidmfAirMid2                                      */
/* !Description :  Ce bloc initialise la temperature d'air avant papillon T2  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_air;                                              */
/*  output sint16 Ext_tUsThrMes;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidmfAirMid2(void)
{
   uint8  u8LocalTemperature_air;
   sint16 s16LocalExt_tUsThrMes;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
   s16LocalExt_tUsThrMes =
      (sint16)((((u8LocalTemperature_air * 5) + 4) / 8) - 40);
   VEMS_vidSET(Ext_tUsThrMes, s16LocalExt_tUsThrMes);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidInitFilter                                     */
/* !Description :  Fonction d'initialisation de la sortie du filter           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 Engine_speed_derivate;                                        */
/*  output sint8 Ext_nEngGrd;                                                 */
/*  output sint32 IFAIRSYS_s32OutputMem;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidInitFilter(void)
{
   sint8 s8LocalEngine_speed_derivate;


   VEMS_vidGET(Engine_speed_derivate, s8LocalEngine_speed_derivate);
   VEMS_vidSET(Ext_nEngGrd, s8LocalEngine_speed_derivate);
   IFAIRSYS_s32OutputMem =(sint32)(s8LocalEngine_speed_derivate * 256);
}
/*-------------------------------- end of file -------------------------------*/