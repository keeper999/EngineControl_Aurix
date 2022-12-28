/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFROUGHNSROADCAN                                      */
/* !Description     : MISFROUGHNSROADCAN component.                           */
/*                                                                            */
/* !Module          : MISFROUGHNSROADCAN                                      */
/* !Description     : DETECTION DE LA MAUVAISE ROUTE EN FONCTION DE LA VITESSE*/
/*                    DES ROUES                                               */
/*                                                                            */
/* !File            : MISFROUGHNSROADCAN_FCT1.C                               */
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
/*   1 / MISFROUGHNSROADCAN_vidInitOutput                                     */
/*   2 / MISFROUGHNSROADCAN_vidClcn                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 01896 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFROUGHNSROADCAN/MISFROUGHN$*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   29 Jun 2010 $*/
/* $Author::   wbouach                                $$Date::   29 Jun 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "MISFROUGHNSROADCAN.h"
#include "MISFROUGHNSROADCAN_L.h"
#include "MISFROUGHNSROADCAN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFROUGHNSROADCAN_vidInitOutput                           */
/* !Description :  Initialisations des sorties.                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  ALI.FARES                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Misf_bAcvRoughnsRoadMod;                                   */
/*  output uint16 MISFROUGHNSROADCAN_u16ArdSpPrev;                            */
/*  output uint16 MISFROUGHNSROADCAN_u16ArgSpPrev;                            */
/*  output uint16 MISFROUGHNSROADCAN_u16AvdSpPrev;                            */
/*  output uint16 MISFROUGHNSROADCAN_u16AvgSpPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFROUGHNSROADCAN_vidInitOutput(void)
{
   VEMS_vidSET(Misf_bAcvRoughnsRoadMod, 0);

   MISFROUGHNSROADCAN_u16ArdSpPrev = 0;
   MISFROUGHNSROADCAN_u16ArgSpPrev = 0;
   MISFROUGHNSROADCAN_u16AvdSpPrev = 0;
   MISFROUGHNSROADCAN_u16AvgSpPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFROUGHNSROADCAN_vidClcn                                 */
/* !Description :  Cette stratégie active le mode mauvaise route à partir de  */
/*                 la vitesse des roues transmises via l’ISCAN.               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  ALI.FARES                                                  */
/* !Trace_To    :  VEMS_R_09_01896_001.01                                     */
/*                 VEMS_R_09_01896_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Tra_noGearMan;                                                */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 Tra_noGearMan_bkpt_map[7];                                    */
/*  input uint8 Vitesse_vehicule_bkpt_map[16];                                */
/*  input uint16 Misf_aRoughnRoadDetThd_M[7][16];                             */
/*  input boolean Cps_clutch_pedal_input;                                     */
/*  input uint16 Vitesse_vehicule_ard_mux;                                    */
/*  input uint16 Vitesse_vehicule_arg_mux;                                    */
/*  input uint16 Vitesse_vehicule_avd_mux;                                    */
/*  input uint16 Vitesse_vehicule_avg_mux;                                    */
/*  input uint16 MISFROUGHNSROADCAN_u16ArdSpPrev;                             */
/*  input uint16 MISFROUGHNSROADCAN_u16ArgSpPrev;                             */
/*  input uint16 MISFROUGHNSROADCAN_u16AvdSpPrev;                             */
/*  input uint16 MISFROUGHNSROADCAN_u16AvgSpPrev;                             */
/*  input uint16 Acceleration_vehicule_ard_mux;                               */
/*  input uint16 Acceleration_vehicule_arg_mux;                               */
/*  input uint16 Acceleration_vehicule_avd_mux;                               */
/*  input uint16 Acceleration_vehicule_avg_mux;                               */
/*  input uint16 Misf_aRoughnRoadDetThd;                                      */
/*  output uint16 Misf_aRoughnRoadDetThd;                                     */
/*  output boolean Misf_bDgoLostMisfRoughnsRoad;                              */
/*  output boolean Misf_bMonRunLostMisfRoughnsRoad;                           */
/*  output uint16 Acceleration_vehicule_ard_mux;                              */
/*  output uint16 Acceleration_vehicule_arg_mux;                              */
/*  output uint16 Acceleration_vehicule_avd_mux;                              */
/*  output uint16 Acceleration_vehicule_avg_mux;                              */
/*  output boolean Misf_bAcvRoughnsRoadMod;                                   */
/*  output uint16 MISFROUGHNSROADCAN_u16ArdSpPrev;                            */
/*  output uint16 MISFROUGHNSROADCAN_u16ArgSpPrev;                            */
/*  output uint16 MISFROUGHNSROADCAN_u16AvdSpPrev;                            */
/*  output uint16 MISFROUGHNSROADCAN_u16AvgSpPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFROUGHNSROADCAN_vidClcn(void)
{
   boolean bLocalInhMisfRoughnsRoadAccCan;
   boolean bLocalCps_clutch_pedal_input;
   boolean bLocalMisf_bAcvRoughnsRoadMod;
   boolean bLocalInhMisfRoughnsRoadAccDiag;
   uint8   u8LocalTra_noGearMan;
   uint8   u8LocalVitesse_vehicule;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalInterp2D;
   uint16  u16LocalVitesse_vehicule_ard_mux;
   uint16  u16LocalVitesse_vehicule_arg_mux;
   uint16  u16LocalVitesse_vehicule_avd_mux;
   uint16  u16LocalVitesse_vehicule_avg_mux;
   uint16  u16LocalAccel_vehicule_ard_mux;
   uint16  u16LocalAccel_vehicule_arg_mux;
   uint16  u16LocalAccel_vehicule_avd_mux;
   uint16  u16LocalAccel_vehicule_avg_mux;
   uint16  u16LocalAccel_vehicule_max1;
   uint16  u16LocalAccel_vehicule_max;
   sint32  s32LocalAccel_vehicule_ard_mux;
   sint32  s32LocalAccel_vehicule_arg_mux;
   sint32  s32LocalAccel_vehicule_avd_mux;
   sint32  s32LocalAccel_vehicule_avg_mux;


   VEMS_vidGET(Tra_noGearMan, u8LocalTra_noGearMan);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Tra_noGearMan_bkpt_map,
                                               u8LocalTra_noGearMan,
                                               7);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Vitesse_vehicule_bkpt_map,
                                               u8LocalVitesse_vehicule,
                                               16);
   u16LocalInterp2D = MATHSRV_u16Interp2d(&Misf_aRoughnRoadDetThd_M[0][0],
                                          u16LocalParaX,
                                          u16LocalParaY,
                                          16);
   Misf_aRoughnRoadDetThd = (uint16)MATHSRV_udtMIN(u16LocalInterp2D,65520);

   bLocalInhMisfRoughnsRoadAccDiag =
      GDGAR_bGetFRM(FRM_FRM_INHMISFROUGHNSROADACCDIAG);
   Misf_bDgoLostMisfRoughnsRoad = bLocalInhMisfRoughnsRoadAccDiag ;
   Misf_bMonRunLostMisfRoughnsRoad = 1;

   bLocalInhMisfRoughnsRoadAccCan =
      GDGAR_bGetFRM(FRM_FRM_INHMISFROUGHNSROADACCCAN);
   VEMS_vidGET(Cps_clutch_pedal_input, bLocalCps_clutch_pedal_input);
   VEMS_vidGET(Vitesse_vehicule_ard_mux, u16LocalVitesse_vehicule_ard_mux);
   VEMS_vidGET(Vitesse_vehicule_arg_mux, u16LocalVitesse_vehicule_arg_mux);
   VEMS_vidGET(Vitesse_vehicule_avd_mux, u16LocalVitesse_vehicule_avd_mux);
   VEMS_vidGET(Vitesse_vehicule_avg_mux, u16LocalVitesse_vehicule_avg_mux);

   if(bLocalCps_clutch_pedal_input !=0)
   {
      bLocalMisf_bAcvRoughnsRoadMod = 0;
   }
   else
   {
      if(bLocalInhMisfRoughnsRoadAccCan != 0)
      {
         bLocalMisf_bAcvRoughnsRoadMod = 0;
      }
      else
      {
         s32LocalAccel_vehicule_ard_mux = (sint32)(
            (u16LocalVitesse_vehicule_ard_mux - MISFROUGHNSROADCAN_u16ArdSpPrev)
            * 20) / (sint32)Misf_SampleTiFast_SC;
         s32LocalAccel_vehicule_arg_mux = (sint32)(
            (u16LocalVitesse_vehicule_arg_mux - MISFROUGHNSROADCAN_u16ArgSpPrev)
            * 20) / (sint32)Misf_SampleTiFast_SC;
         s32LocalAccel_vehicule_avd_mux = (sint32)(
            (u16LocalVitesse_vehicule_avd_mux - MISFROUGHNSROADCAN_u16AvdSpPrev)
            * 20) / (sint32)Misf_SampleTiFast_SC;
         s32LocalAccel_vehicule_avg_mux = (sint32)(
            (u16LocalVitesse_vehicule_avg_mux - MISFROUGHNSROADCAN_u16AvgSpPrev)
            * 20) / (sint32)Misf_SampleTiFast_SC;

         u16LocalAccel_vehicule_ard_mux =
            (uint16)MATHSRV_udtABS(s32LocalAccel_vehicule_ard_mux);
         u16LocalAccel_vehicule_arg_mux =
            (uint16)MATHSRV_udtABS(s32LocalAccel_vehicule_arg_mux);
         u16LocalAccel_vehicule_avd_mux =
            (uint16)MATHSRV_udtABS(s32LocalAccel_vehicule_avd_mux);
         u16LocalAccel_vehicule_avg_mux =
            (uint16)MATHSRV_udtABS(s32LocalAccel_vehicule_avg_mux);

         Acceleration_vehicule_ard_mux =
            (uint16)MATHSRV_udtMIN(u16LocalAccel_vehicule_ard_mux, 65520);
         Acceleration_vehicule_arg_mux =
            (uint16)MATHSRV_udtMIN(u16LocalAccel_vehicule_arg_mux, 65520);
         Acceleration_vehicule_avd_mux =
            (uint16)MATHSRV_udtMIN(u16LocalAccel_vehicule_avd_mux, 65520);
         Acceleration_vehicule_avg_mux =
            (uint16)MATHSRV_udtMIN(u16LocalAccel_vehicule_avg_mux, 65520);

         u16LocalAccel_vehicule_max =
            (uint16)MATHSRV_udtMAX(Acceleration_vehicule_ard_mux,
                                   Acceleration_vehicule_arg_mux);
         u16LocalAccel_vehicule_max1 =
            (uint16)MATHSRV_udtMAX(Acceleration_vehicule_avd_mux,
                                   Acceleration_vehicule_avg_mux);
         u16LocalAccel_vehicule_max =
            (uint16)MATHSRV_udtMAX(u16LocalAccel_vehicule_max,
                                   u16LocalAccel_vehicule_max1);

         if(u16LocalAccel_vehicule_max >= Misf_aRoughnRoadDetThd)
         {
            bLocalMisf_bAcvRoughnsRoadMod = 1;
         }
         else
         {
            bLocalMisf_bAcvRoughnsRoadMod = 0;
         }
      }
   }
   VEMS_vidSET(Misf_bAcvRoughnsRoadMod, bLocalMisf_bAcvRoughnsRoadMod);
   MISFROUGHNSROADCAN_u16ArdSpPrev =
            (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_ard_mux,65533);
   MISFROUGHNSROADCAN_u16ArgSpPrev =
            (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_arg_mux,65533);
   MISFROUGHNSROADCAN_u16AvdSpPrev =
            (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_avd_mux,65533);
   MISFROUGHNSROADCAN_u16AvgSpPrev =
            (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_avg_mux,65533);
}

/*------------------------------- end of file --------------------------------*/