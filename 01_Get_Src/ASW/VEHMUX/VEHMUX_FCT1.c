/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHMUX                                                  */
/* !Description     : VEHMUX Component                                        */
/*                                                                            */
/* !Module          : VEHMUX                                                  */
/* !Description     : ACQUISITION VITESSE VEHICULE VIA CAN                    */
/*                                                                            */
/* !File            : VEHMUX_FCT1.C                                           */
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
/*   1 / VEHMUX_vidVehSpdMuxInit                                              */
/*   2 / VEHMUX_vidAcquisition38D                                             */
/*   3 / VEHMUX_vidAcquisSpeedAccelMux                                        */
/*   4 / VEHMUX_vidCalcDist7F2                                                */
/*   5 / VEHMUX_vidAcquisFrame7F2                                             */
/*   6 / VEHMUX_vidCalcDist552                                                */
/*   7 / VEHMUX_vidAcquisFrame552                                             */
/*   8 / VEHMUX_vidTravaledDistanceCalc                                       */
/*                                                                            */
/* !Reference   : V02 NT 08 05607 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/VEHMUX/VEHMUX_FCT1.C_v            $*/
/* $Revision::   1.7      $$Author::   ACHEBINO       $$Date::   18 Jun 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   18 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEHMUX.h"
#include "VEHMUX_L.h"
#include "VEHMUX_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMUX_vidVehSpdMuxInit                                    */
/* !Description :  Outputs initialisation                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Esp_frame_nb_per_sec_count;                                  */
/*  output uint16 Distance_covered_computed;                                  */
/*  output uint16 Vitesse_vehicule_rx_via_can;                                */
/*  output uint8 Acceleration_veh_rx_via_can;                                 */
/*  output boolean Km_vehicle_first_7F2_received;                             */
/*  output boolean Km_vehicle_first_552_received;                             */
/*  output uint16 Distance_parcourue_mux;                                     */
/*  output uint32 Km_vehicle_mux_prev;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMUX_vidVehSpdMuxInit(void)
{
   /*0_VehSpdMux_Init*/
   Esp_frame_nb_per_sec_count = 0;
   VEMS_vidSET(Distance_covered_computed, 0);
   VEMS_vidSET(Vitesse_vehicule_rx_via_can, 0);
   VEMS_vidSET(Acceleration_veh_rx_via_can, 0xAF);
   VEMS_vidSET(Km_vehicle_first_7F2_received, 0);
   VEMS_vidSET(Km_vehicle_first_552_received, 0);
   VEMS_vidSET(Distance_parcourue_mux, 0);
   Km_vehicle_mux_prev = 0;
}

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMUX_vidAcquisition38D                                   */
/* !Description :  Acquisition of speed and the acceleration of the vehicle   */
/*                 when presence of ABS mux and ESP.                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_07_08035_077.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHMUX_vidAcquisSpeedAccelMux();                         */
/*  input boolean Abs_mux;                                                    */
/*  input boolean Esp_present;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMUX_vidAcquisition38D(void)
{
   /*2_Acquis_trame_38D*/
   boolean bLocalEsp_present;
   boolean bLocalAbs_mux;


   VEMS_vidGET(Abs_mux, bLocalAbs_mux);
   VEMS_vidGET(Esp_present, bLocalEsp_present);

   if (  (bLocalAbs_mux != 0)
      || (bLocalEsp_present != 0))
   {
      VEHMUX_vidAcquisSpeedAccelMux();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMUX_vidAcquisSpeedAccelMux                              */
/* !Description :  Acquisition of speed and the acceleration of the vehicle.  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Acceleration_vehicule_mux;                                    */
/*  input uint16 Vitesse_vehicule_mux;                                        */
/*  input uint16 Distance_covered_computed;                                   */
/*  input uint8 Esp_frame_nb_per_sec_count;                                   */
/*  output uint8 Acceleration_veh_rx_via_can;                                 */
/*  output uint16 Vitesse_vehicule_rx_via_can;                                */
/*  output uint16 Distance_covered_computed;                                  */
/*  output uint8 Esp_frame_nb_per_sec_count;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMUX_vidAcquisSpeedAccelMux(void)
{
   /*Acquis_vitesse_accel_mux */
   uint8  u8LocalAcceleration_vehicule_mux;
   uint16 u16LocalVitesse_vehicule_mux;
   uint16 u16LocalVitesseVehRxViaCan;
   uint16 u16LocalDistance_covered_comput;


   VEMS_vidGET(Acceleration_vehicule_mux, u8LocalAcceleration_vehicule_mux);
   VEMS_vidSET(Acceleration_veh_rx_via_can, u8LocalAcceleration_vehicule_mux);

   VEMS_vidGET(Vitesse_vehicule_mux, u16LocalVitesse_vehicule_mux);
   u16LocalVitesseVehRxViaCan =
      (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_mux, 65534);
   VEMS_vidSET(Vitesse_vehicule_rx_via_can, u16LocalVitesseVehRxViaCan);

   VEMS_vidGET(Distance_covered_computed, u16LocalDistance_covered_comput);
   if (Esp_frame_nb_per_sec_count == 25)
   {
      u16LocalDistance_covered_comput =
         (uint16)( u16LocalDistance_covered_comput
                 + (u16LocalVitesse_vehicule_mux / 36));
      VEMS_vidSET(Distance_covered_computed, u16LocalDistance_covered_comput);
      Esp_frame_nb_per_sec_count = 1;
   }
   else
   {
      Esp_frame_nb_per_sec_count = (uint8)(Esp_frame_nb_per_sec_count + 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMUX_vidCalcDist7F2                                      */
/* !Description :  The system compute the Distance_parcourue_mux via          */
/*                 Km_vehicle_mux received from the frame 7F2                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHMUX_vidAcquisFrame7F2();                              */
/*  input boolean Ext_bArchiCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMUX_vidCalcDist7F2(void)
{
   /*4_Calcul_dst_parcourue_via_trame_7F2*/
   boolean bLocalExt_bArchiCf;

   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   if (bLocalExt_bArchiCf == 0)
   {
      VEHMUX_vidAcquisFrame7F2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMUX_vidAcquisFrame7F2                                   */
/* !Description :  Acquisation of the frame 7F2.                              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VEHMUX_vidTravaledDistanceCalc();                        */
/*  input boolean Km_vehicle_first_7F2_received;                              */
/*  input uint32 Km_vehicle_mux;                                              */
/*  input uint8 ISCAN_u8N8F7F2V003;                                           */
/*  output boolean Km_vehicle_first_7F2_received;                             */
/*  output uint32 Km_vehicle_mux_prev;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMUX_vidAcquisFrame7F2(void)
{
   /*Acquis_trame_7F2*/
   boolean bLocalKm_veh_first_7F2_received;
   boolean bLocalInhClcnDstCovered;
   uint32  u32LocalKm_vehicle_mux;
   uint8   u8LocalISCAN_u8N8F7F2V003;


   VEMS_vidGET(Km_vehicle_first_7F2_received, bLocalKm_veh_first_7F2_received);
   VEMS_vidGET(Km_vehicle_mux, u32LocalKm_vehicle_mux);
   VEMS_vidGET(ISCAN_u8N8F7F2V003, u8LocalISCAN_u8N8F7F2V003);
   if (  (bLocalKm_veh_first_7F2_received == 0)
      && (u8LocalISCAN_u8N8F7F2V003 == 143))
   {
      VEMS_vidSET(Km_vehicle_first_7F2_received, 1);
      Km_vehicle_mux_prev = u32LocalKm_vehicle_mux;
   }
   bLocalInhClcnDstCovered = GDGAR_bGetFRM(FRM_FRM_INHCLCNDSTCOVERED);
   if (bLocalInhClcnDstCovered == 0)
   {
      VEHMUX_vidTravaledDistanceCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMUX_vidCalcDist552                                      */
/* !Description :  The system compute the Distance_parcourue_mux via          */
/*                 Km_vehicle_mux received from the frame 552                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHMUX_vidAcquisFrame552();                              */
/*  input boolean Ext_bArchiCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMUX_vidCalcDist552(void)
{
   /*5_Calcul_dst_parcourue_via_trame_552*/
   boolean bLocalExt_bArchiCf;

   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   if (bLocalExt_bArchiCf != 0)
   {
      VEHMUX_vidAcquisFrame552();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMUX_vidAcquisFrame552                                   */
/* !Description :  Acquisation of the frame 552.                              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VEHMUX_vidTravaledDistanceCalc();                        */
/*  input boolean Km_vehicle_first_552_received;                              */
/*  input uint32 Km_vehicle_mux;                                              */
/*  output boolean Km_vehicle_first_552_received;                             */
/*  output uint32 Km_vehicle_mux_prev;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMUX_vidAcquisFrame552(void)
{
   /*Aquis_trame_552*/
   boolean bLocalKm_veh_first_552_received;
   boolean bLocalInhClcnDstCovered;
   uint32  u32LocalKm_vehicle_mux;


   VEMS_vidGET(Km_vehicle_first_552_received, bLocalKm_veh_first_552_received);
   VEMS_vidGET(Km_vehicle_mux, u32LocalKm_vehicle_mux);

   if (bLocalKm_veh_first_552_received == 0 )
   {
      VEMS_vidSET(Km_vehicle_first_552_received, 1);
      Km_vehicle_mux_prev = u32LocalKm_vehicle_mux;
   }
   bLocalInhClcnDstCovered = GDGAR_bGetFRM(FRM_FRM_INHCLCNDSTCOVERED);
   if (bLocalInhClcnDstCovered == 0 )
   {
      VEHMUX_vidTravaledDistanceCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMUX_vidTravaledDistanceCalc                             */
/* !Description :  The production of Distance_parcourue_mux through           */
/*                 Km_vehicle_mux.                                            */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Distance_parcourue_mux;                                      */
/*  input uint32 Km_vehicle_mux;                                              */
/*  input uint32 Km_vehicle_mux_prev;                                         */
/*  output uint16 Distance_parcourue_mux;                                     */
/*  output uint32 Km_vehicle_mux_prev;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMUX_vidTravaledDistanceCalc(void)
{
   /*Distance_parcourue_via_552 or Distance_parcourue_via_7F2*/
   uint16 u16LocalDistance_parcourue_mux;
   uint16 u16LocalKm_vehicle_mux_delta;
   uint32 u32LocalKm_vehicle_mux;


   VEMS_vidGET(Distance_parcourue_mux, u16LocalDistance_parcourue_mux);
   VEMS_vidGET(Km_vehicle_mux, u32LocalKm_vehicle_mux);

   if (u32LocalKm_vehicle_mux > Km_vehicle_mux_prev)
   {
      u16LocalKm_vehicle_mux_delta = (uint16)( ( (uint16)u32LocalKm_vehicle_mux
                                               - (uint16)Km_vehicle_mux_prev)
                                             * 10000);
   }
   else
   {
      u16LocalKm_vehicle_mux_delta = 0;
   }
   u16LocalDistance_parcourue_mux =
      (uint16)(u16LocalDistance_parcourue_mux + u16LocalKm_vehicle_mux_delta);
   VEMS_vidSET(Distance_parcourue_mux, u16LocalDistance_parcourue_mux);
   Km_vehicle_mux_prev = MATHSRV_udtMIN(u32LocalKm_vehicle_mux, 16777214);
}

/*-------------------------------end of file----------------------------------*/
