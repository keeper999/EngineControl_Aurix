/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHMNG                                                  */
/* !Description     : VEHMNG component                                        */
/*                                                                            */
/* !Module          : VEHMNG                                                  */
/* !Description     : Gestion de la vitesse véhicule                          */
/*                                                                            */
/* !File            : VEHMNG_FCT1.C                                           */
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
/*   1 / VEHMNG_vidVehSdpMngInit                                              */
/*   2 / VEHMNG_vidVehSpdInformation                                          */
/*   3 / VEHMNG_vidVehSpdMngCanCmm                                            */
/*   4 / VEHMNG_vidCanTranSpeedManagement                                     */
/*   5 / VEHMNG_vidCmmTranSpeedManagement                                     */
/*   6 / VEHMNG_vidVehicleSpeedFiltered                                       */
/*   7 / VEHMNG_vidClcDistTraveledViaCAN                                      */
/*   8 / VEHMNG_vidDistTraveledViaCAN                                         */
/*   9 / VEHMNG_vidClcDistTraveledViaWire                                     */
/*   10 / VEHMNG_vidDistTraveledViaWire                                       */
/*                                                                            */
/* !Reference   : V02 NT 08 05610 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/VEHMNG/VEHMNG_FCT1.C_v            $*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   05 Oct 2012 $*/
/* $Author::   achebino                               $$Date::   05 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEHMNG.h"
#include "VEHMNG_L.h"
#include "VEHMNG_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidVehSdpMngInit                                    */
/* !Description :  Initialisation de la stratégie                             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Abs_mux;                                                    */
/*  input boolean Esp_present;                                                */
/*  input uint16 Eng_spdVeh_C;                                                */
/*  output uint8 Acceleration_vehicule;                                       */
/*  output uint8 Vitesse_vehicule;                                            */
/*  output uint16 Veh_spdVeh;                                                 */
/*  output boolean Vehicule_roulant;                                          */
/*  output uint16 Vitesse_vehicule_filtree;                                   */
/*  output uint16 Distance_parcourue_hectometre;                              */
/*  output uint32 Distance_parcourue_totale;                                  */
/*  output uint16 Distance_parcourue;                                         */
/*  output uint8 Ext_spdVeh;                                                  */
/*  output uint32 VEHMNG_u32VitesseVehFiltreeMem;                             */
/*  output boolean VEHMNG_bInhClcnDstCoveredPrev;                             */
/*  output uint16 Distance_parcourue_prev;                                    */
/*  output uint16 VEHMNG_u16DistanceParcourue;                                */
/*  output st55 Emetteur_vitesse_vehicule_state;                              */
/*  output uint16 Eng_spdVeh;                                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidVehSdpMngInit(void)
{
   boolean bLocalAbs_mux;
   boolean bLocalEsp_present;
   uint16  u16LocalEngSpdVeh;


   /* 01_VehSpdMng_Init */
   VEMS_vidSET(Acceleration_vehicule, 0xAF);
   VEMS_vidSET(Vitesse_vehicule, 0);
   VEMS_vidSET(Veh_spdVeh, 0);
   VEMS_vidSET(Vehicule_roulant, 0);
   VEMS_vidSET(Vitesse_vehicule_filtree, 0);
   VEMS_vidSET(Distance_parcourue_hectometre, 0);
   Distance_parcourue_totale = 0;
   VEMS_vidSET(Distance_parcourue, 0);
   VEMS_vidSET(Ext_spdVeh, 0);

   /*Internals initialization*/
   VEHMNG_u32VitesseVehFiltreeMem = 0;
   VEHMNG_bInhClcnDstCoveredPrev = 0;
   Distance_parcourue_prev = 0;
   VEHMNG_u16DistanceParcourue = 0;

   VEMS_vidGET(Abs_mux, bLocalAbs_mux);
   VEMS_vidGET(Esp_present, bLocalEsp_present);

   if (  (bLocalAbs_mux != 0)
      || (bLocalEsp_present != 0))
   {
      VEMS_vidSET(Emetteur_vitesse_vehicule_state, VITESSE_CAN_EMETTEUR);
      u16LocalEngSpdVeh = (uint16)MATHSRV_udtMIN(Eng_spdVeh_C, 64000);
      VEMS_vidSET(Eng_spdVeh, u16LocalEngSpdVeh);
   }
   else
   {
      VEMS_vidSET(Emetteur_vitesse_vehicule_state, VITESSE_CMM_EMETTEUR);
      VEMS_vidSET(Eng_spdVeh, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidVehSpdInformation                                */
/* !Description :  Pour le RCD la vitesse doit nominalement être lue sur la   */
/*                 trame 38D en cas d'absence de cette trame.                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05610_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Abs_mux;                                                    */
/*  input boolean Esp_present;                                                */
/*  input st55 Emetteur_vitesse_vehicule_state;                               */
/*  input uint16 Eng_spdVeh_C;                                                */
/*  output st55 Emetteur_vitesse_vehicule_state;                              */
/*  output uint16 Eng_spdVeh;                                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidVehSpdInformation(void)
{
   /* Information_vitesse_vehicule */
   boolean bLocalAbs_mux;
   boolean bLocalEsp_present;
   uint8   u8LocalEmetteur_vitesse_vehicule;
   uint16  u16LocalEngSpdVeh;


   VEMS_vidGET(Abs_mux, bLocalAbs_mux);
   VEMS_vidGET(Esp_present, bLocalEsp_present);
   VEMS_vidGET(Emetteur_vitesse_vehicule_state,
               u8LocalEmetteur_vitesse_vehicule);
   switch(u8LocalEmetteur_vitesse_vehicule)
   {
      case VITESSE_CAN_EMETTEUR:
         if (  (bLocalAbs_mux == 0 )
            && (bLocalEsp_present == 0))
         {
            VEMS_vidSET(Emetteur_vitesse_vehicule_state, VITESSE_CMM_EMETTEUR);
            VEMS_vidSET(Eng_spdVeh, 0);
         }
         break;

      case VITESSE_CMM_EMETTEUR:
         if (  (bLocalAbs_mux != 0)
            || (bLocalEsp_present != 0))
         {
            VEMS_vidSET(Emetteur_vitesse_vehicule_state, VITESSE_CAN_EMETTEUR);
            u16LocalEngSpdVeh = (uint16)MATHSRV_udtMIN(Eng_spdVeh_C, 64000);
            VEMS_vidSET(Eng_spdVeh, u16LocalEngSpdVeh);
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
      break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidVehSpdMngCanCmm                                  */
/* !Description :  La vitesse doit, pour le RCD, être nominalement lue sur la */
/*                 trame 38D.                                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05610_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHMNG_vidCanTranSpeedManagement();                      */
/*  extf argret void VEHMNG_vidCmmTranSpeedManagement();                      */
/*  input st55 Emetteur_vitesse_vehicule_state;                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidVehSpdMngCanCmm(void)
{
   /* 03_VehSpdMng_CAN_CMM */
   uint8 u8LocalEmetteur_vitesse_vehicule;


   VEMS_vidGET(Emetteur_vitesse_vehicule_state,
               u8LocalEmetteur_vitesse_vehicule);
   if (u8LocalEmetteur_vitesse_vehicule == VITESSE_CAN_EMETTEUR)
   {
      VEHMNG_vidCanTranSpeedManagement();
   }
   else
   {
      if (u8LocalEmetteur_vitesse_vehicule == VITESSE_CMM_EMETTEUR)
      {
         VEHMNG_vidCmmTranSpeedManagement();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidCanTranSpeedManagement                           */
/* !Description :  La vitesse doit, pour le RCD, être nominalement lue sur la */
/*                 trame 38D.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05610_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_spdVeh_C;                                                */
/*  input uint16 Vitesse_vehicule_rx_via_can;                                 */
/*  input uint8 Acceleration_veh_rx_via_can;                                  */
/*  output uint16 Eng_spdVeh;                                                 */
/*  output uint8 Vitesse_vehicule;                                            */
/*  output uint8 Ext_spdVeh;                                                  */
/*  output uint16 Veh_spdVeh;                                                 */
/*  output boolean Vehicule_roulant;                                          */
/*  output uint8 Acceleration_vehicule;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidCanTranSpeedManagement(void)
{
   /* 1_Gestion_vitesse_can_emetteur */
   uint8  u8LocalVitesse_vehicule;
   uint8  u8LocalAccelerationVehRxViaCan;
   uint16 u16LocalVehSpdVeh;
   uint16 u16LocalEngSpdVeh;
   uint16 u16LocalVitesseVehRxViaCan;
   uint16 u16LocalVitesseVehiculeRxViaCan;
   uint32 u32LocalVitesseVehRxViaCan;


   u16LocalEngSpdVeh = (uint16)MATHSRV_udtMIN(Eng_spdVeh_C, 64000);
   VEMS_vidSET(Eng_spdVeh, u16LocalEngSpdVeh);

   VEMS_vidGET(Vitesse_vehicule_rx_via_can, u16LocalVitesseVehiculeRxViaCan);
   u16LocalVitesseVehRxViaCan = (uint16)(u16LocalVitesseVehiculeRxViaCan / 100);
   u8LocalVitesse_vehicule = (uint8)MATHSRV_udtMIN(u16LocalVitesseVehRxViaCan,
                                                   255);
   VEMS_vidSET(Vitesse_vehicule, u8LocalVitesse_vehicule);

   VEMS_vidSET(Ext_spdVeh, u8LocalVitesse_vehicule);

   u32LocalVitesseVehRxViaCan = (uint32)( ( u16LocalVitesseVehiculeRxViaCan
                                          * 128)
                                        / 100);

   u16LocalVehSpdVeh = (uint16)MATHSRV_udtMIN(u32LocalVitesseVehRxViaCan,
                                              64000);
   VEMS_vidSET(Veh_spdVeh, u16LocalVehSpdVeh);

   if (u16LocalVitesseVehiculeRxViaCan == 0)
   {
      VEMS_vidSET(Vehicule_roulant, 0);
   }
   else
   {
      VEMS_vidSET(Vehicule_roulant, 1);
   }

   VEMS_vidGET(Acceleration_veh_rx_via_can, u8LocalAccelerationVehRxViaCan);
   VEMS_vidSET(Acceleration_vehicule, u8LocalAccelerationVehRxViaCan);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidCmmTranSpeedManagement                           */
/* !Description :  La vitesse véhicule est l’image de la vitesse filaire      */
/*                 calculée par le CMM.On ne peut s'y trouver que si le       */
/*                 véhicule est équipé d'un capteur filaire et que l'ABS/ESP  */
/*                 ne sont pas disponibles.                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_spdVehRaw;                                               */
/*  input uint8 Acceleration_filaire;                                         */
/*  output uint8 Vitesse_vehicule;                                            */
/*  output uint8 Ext_spdVeh;                                                  */
/*  output uint16 Veh_spdVeh;                                                 */
/*  output uint16 Eng_spdVeh;                                                 */
/*  output boolean Vehicule_roulant;                                          */
/*  output uint8 Acceleration_vehicule;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidCmmTranSpeedManagement(void)
{
   /* 2_Gestion_vitesse_cmm_emetteur */
   uint8  u8LocalExt_spdVeh;
   uint8  u8LocalAcceleration_filaire;
   uint16 u16LocalExt_spdVehRaw;
   uint16 u16LocalVeh_spdVeh;


   VEMS_vidGET(Ext_spdVehRaw, u16LocalExt_spdVehRaw);

   u8LocalExt_spdVeh = (uint8)(u16LocalExt_spdVehRaw / 256);
   VEMS_vidSET(Vitesse_vehicule, u8LocalExt_spdVeh);
   VEMS_vidSET(Ext_spdVeh, u8LocalExt_spdVeh);

   u16LocalVeh_spdVeh = (uint16)(u16LocalExt_spdVehRaw / 2);
   VEMS_vidSET(Veh_spdVeh, u16LocalVeh_spdVeh);
   VEMS_vidSET(Eng_spdVeh, u16LocalVeh_spdVeh);

   if (u16LocalExt_spdVehRaw == 0)
   {
      VEMS_vidSET(Vehicule_roulant, 0);
   }
   else
   {
      VEMS_vidSET(Vehicule_roulant, 1);
   }

   VEMS_vidGET(Acceleration_filaire, u8LocalAcceleration_filaire);
   VEMS_vidSET(Acceleration_vehicule, u8LocalAcceleration_filaire);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidVehicleSpeedFiltered                             */
/* !Description :  Filtrage de la vitesse vehicule                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MATHSRV_u16FirstOrderFilterGu8(argin uint8               */
/* u8FilterGain,argout uint32 * pu32AccuracyFilterValue,argin uint16          */
/* u16MeasuredValue, uint16);                                                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vitesse_vehicule_fil_precise;                                */
/*  input uint8 Vitesse_vehicule_gain;                                        */
/*  input uint32 VEHMNG_u32VitesseVehFiltreeMem;                              */
/*  output uint16 Vitesse_vehicule_filtree;                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidVehicleSpeedFiltered(void)
{
   /* 04_VehSpdMng_Filtree */
   uint16 u16LocalVehSpdWireAccurate;
   uint16 u16LocalVitesse_vehicule_filtree;


   VEMS_vidGET(Vitesse_vehicule_fil_precise, u16LocalVehSpdWireAccurate);
   u16LocalVitesse_vehicule_filtree =
      MATHSRV_u16FirstOrderFilterGu8(Vitesse_vehicule_gain,
                                     &VEHMNG_u32VitesseVehFiltreeMem,
                                     u16LocalVehSpdWireAccurate);
   VEMS_vidSET(Vitesse_vehicule_filtree, u16LocalVitesse_vehicule_filtree);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidClcDistTraveledViaCAN                            */
/* !Description :  Calcul de la distance Distance_parcourue.                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHMNG_vidDistTraveledViaCAN();                          */
/*  input st55 Emetteur_vitesse_vehicule_state;                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidClcDistTraveledViaCAN(void)
{
   /* 05_Calcul_Distance_Parcourue_via_CAN */
   uint8 u8LocalEmetteur_vitesse_vehicule;


   VEMS_vidGET(Emetteur_vitesse_vehicule_state,
               u8LocalEmetteur_vitesse_vehicule);
   if (u8LocalEmetteur_vitesse_vehicule == VITESSE_CAN_EMETTEUR)
   {
      VEHMNG_vidDistTraveledViaCAN();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidDistTraveledViaCAN                               */
/* !Description :  La distance_parcourue_prev est rafraîchie en permanence    */
/*                 tandis que lors des variations de FRM_bInhClcnDstCovered,  */
/*                 le flux Distance_parcourue est figé durant un pas de calcul*/
/*                 afin de garantir au pas suivant que les 2 variables sont   */
/*                 dans le même référentiel                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16Channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VEHMNG_u16DistanceParcourue;                                 */
/*  input boolean Km_vehicle_first_7F2_received;                              */
/*  input boolean Km_vehicle_first_552_received;                              */
/*  input uint16 Distance_parcourue_mux;                                      */
/*  input uint16 Distance_covered_computed;                                   */
/*  input boolean VEHMNG_bInhClcnDstCoveredPrev;                              */
/*  output uint16 Distance_parcourue_prev;                                    */
/*  output uint16 VEHMNG_u16DistanceParcourue;                                */
/*  output uint16 Distance_parcourue;                                         */
/*  output boolean VEHMNG_bInhClcnDstCoveredPrev;                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidDistTraveledViaCAN(void)
{
   /* Distance_Parcourue_via_CAN */
   boolean bLocalInhClcnDstCovered;
   boolean bLocalKmVehicleFirst7F2Received;
   boolean bLocalKmVehicleFirst552Received;
   uint16  u16LocalDistance_parcourue;


   Distance_parcourue_prev = VEHMNG_u16DistanceParcourue;
   bLocalInhClcnDstCovered = GDGAR_bGetFRM(FRM_FRM_INHCLCNDSTCOVERED);
   VEMS_vidGET(Km_vehicle_first_7F2_received, bLocalKmVehicleFirst7F2Received);
   VEMS_vidGET(Km_vehicle_first_552_received, bLocalKmVehicleFirst552Received);

   if (  (bLocalInhClcnDstCovered == 0)
      && (  (bLocalKmVehicleFirst7F2Received != 0)
         || (bLocalKmVehicleFirst552Received != 0)))
   {
      VEMS_vidGET(Distance_parcourue_mux, u16LocalDistance_parcourue);
   }
   else
   {
      VEMS_vidGET(Distance_covered_computed, u16LocalDistance_parcourue);
   }

   VEHMNG_u16DistanceParcourue = u16LocalDistance_parcourue;

   if (  (  (VEHMNG_bInhClcnDstCoveredPrev != 0)
         || (bLocalInhClcnDstCovered == 0))
      && (  (VEHMNG_bInhClcnDstCoveredPrev == 0)
         || (bLocalInhClcnDstCovered != 0)))
   {
      VEMS_vidSET(Distance_parcourue, u16LocalDistance_parcourue);
   }

   VEHMNG_bInhClcnDstCoveredPrev = bLocalInhClcnDstCovered;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidClcDistTraveledViaWire                           */
/* !Description :  Calcul de Distance_parcourue                               */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHMNG_vidDistTraveledViaWire();                         */
/*  input st55 Emetteur_vitesse_vehicule_state;                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidClcDistTraveledViaWire(void)
{
   /* 06_Calcul_Distance_Parcourue_via_fil */
   uint8 u8LocalEmetteur_vitesse_vehicule;


   VEMS_vidGET(Emetteur_vitesse_vehicule_state,
               u8LocalEmetteur_vitesse_vehicule);
   if (u8LocalEmetteur_vitesse_vehicule == VITESSE_CMM_EMETTEUR)
   {
      VEHMNG_vidDistTraveledViaWire();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidDistTraveledViaWire                              */
/* !Description :  Calcul de Distance_parcourue par le capteur filaire        */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Distance_parcourue_fil;                                      */
/*  output uint16 Distance_parcourue;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidDistTraveledViaWire(void)
{
   /* Distance_parcourue_via_filaire */
   uint16 u16LocalDistance_parcourue;


   VEMS_vidGET(Distance_parcourue_fil, u16LocalDistance_parcourue);
   VEMS_vidSET(Distance_parcourue, u16LocalDistance_parcourue);
}
/*---------------------------------end of file--------------------------------*/