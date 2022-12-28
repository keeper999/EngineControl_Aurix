/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHSPDACQ                                               */
/* !Description     : VEHSPDACQ Component                                     */
/*                                                                            */
/* !Module          : VEHSPDACQ                                               */
/* !Description     : ACQUISITION DE LA VITESSE VEHICULE FILAIRE              */
/*                                                                            */
/* !File            : VEHSPDACQ_FCT3.C                                        */
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
/*   1 / VEHSPDACQ_vidStopDetection                                           */
/*   2 / VEHSPDACQ_vidTransmission                                            */
/*   3 / VEHSPDACQ_vidDynFil                                                  */
/*   4 / VEHSPDACQ_vidMeanComputation                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5455394 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VEHSPD/VEHSPDACQ/VEHSPDACQ_FCT3.$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   19 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEHSPDACQ.h"
#include "VEHSPDACQ_L.h"
#include "VEHSPDACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidStopDetection                                 */
/* !Description :  Ce bloc permet d’effectuer la détection d’un arrêt du      */
/*                 véhicule.                                                  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidInit();                                     */
/*  input boolean VehSpd_bCntrChg;                                            */
/*  input uint16 VehSpd_ctPls;                                                */
/*  input uint16 VEHSPDACQ_u16CtPlsPrev;                                      */
/*  input uint8 VehSpd_tiDlyVehStopCmpl_C;                                    */
/*  input uint8 Compteur_arret_vehicule;                                      */
/*  input boolean Vehicle_stopped;                                            */
/*  input boolean VEHSPDACQ_bTimeOut;                                         */
/*  input uint16 Vitesse_vehicule_fil_preciseAcq;                             */
/*  input uint16 Ext_spdVehRawAcq;                                            */
/*  input uint8 Acceleration_filaireAcq;                                      */
/*  output boolean VehSpd_bCntrChg;                                           */
/*  output uint8 Compteur_arret_vehicule;                                     */
/*  output boolean VEHSPDACQ_bTimeOut;                                        */
/*  output boolean Vehicle_stopped;                                           */
/*  output uint16 Vitesse_vehicule_consolide;                                 */
/*  output uint16 Ext_spdVehTreat;                                            */
/*  output uint8 Acceleration_filaire_consolide;                              */
/*  output uint16 VEHSPDACQ_u16CtPlsPrev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidStopDetection(void)
{
   boolean bLocalVehicleStoppedPrev;
   boolean bLocalCntrChgPrev;


   bLocalCntrChgPrev = VehSpd_bCntrChg;
   if (VehSpd_ctPls != VEHSPDACQ_u16CtPlsPrev)
   {
      VehSpd_bCntrChg = 1;
   }
   else
   {
      VehSpd_bCntrChg = 0;
   }
   if (  (VehSpd_bCntrChg == 0)
      && (bLocalCntrChgPrev != 0))
   {
      Compteur_arret_vehicule =
         (uint8)MATHSRV_udtMIN(VehSpd_tiDlyVehStopCmpl_C, 200);
      if (Compteur_arret_vehicule == 0)
      {
         VEHSPDACQ_bTimeOut = 1;
      }
      else
      {
         VEHSPDACQ_bTimeOut = 0;
      }
   }
   else
   {
      if (Compteur_arret_vehicule > 0)
      {
         Compteur_arret_vehicule = (uint8)(Compteur_arret_vehicule - 1);
         if (Compteur_arret_vehicule == 0)
         {
            VEHSPDACQ_bTimeOut = 1;
         }
         else
         {
            VEHSPDACQ_bTimeOut = 0;
         }
      }
   }

   bLocalVehicleStoppedPrev = Vehicle_stopped;
   if (  (VehSpd_bCntrChg == 0)
      && (VEHSPDACQ_bTimeOut != 0))
   {
      Vehicle_stopped = 1;
      Vitesse_vehicule_consolide = 0;
      Ext_spdVehTreat = 0;
      Acceleration_filaire_consolide = 175;
      if (bLocalVehicleStoppedPrev == 0)
      {
         /*CALL_VehStop*/
         VEHSPDACQ_vidInit();
      }
   }
   else
   {
      Vehicle_stopped = 0;
      Vitesse_vehicule_consolide = Vitesse_vehicule_fil_preciseAcq;
      Ext_spdVehTreat = Ext_spdVehRawAcq;
      Acceleration_filaire_consolide = Acceleration_filaireAcq;
   }
   VEHSPDACQ_u16CtPlsPrev = VehSpd_ctPls;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidTransmission                                  */
/* !Description :  Ici, on effectue la transmission du signal à la fréquence  */
/*                 VehSpd_SdlFast_SpdAcq_1.                                   */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06646_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vitesse_vehicule_consolide;                                  */
/*  input uint8 Acceleration_filaire_consolide;                               */
/*  input uint16 Ext_spdVehTreat;                                             */
/*  input uint16 VehSpd_spdMinSat_C;                                          */
/*  input boolean VehSpd_bDeadzone_C;                                         */
/*  input uint16 VehSpd_spdMinForClamp_C;                                     */
/*  output uint16 Vitesse_vehicule_fil_precise;                               */
/*  output uint16 Vitesse_vehicule_consolide;                                 */
/*  output uint8 Acceleration_filaire;                                        */
/*  output uint8 Acceleration_filaire_consolide;                              */
/*  output uint16 Ext_spdVehRaw;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidTransmission(void)
{
   uint16 u16LocalExt_spdVehRaw;


   VEMS_vidSET(Vitesse_vehicule_fil_precise, Vitesse_vehicule_consolide);
   VEMS_vidSET(Acceleration_filaire, Acceleration_filaire_consolide);

   if (Ext_spdVehTreat >= VehSpd_spdMinSat_C)
   {
      u16LocalExt_spdVehRaw = Ext_spdVehTreat;
   }
   else
   {
      if (VehSpd_bDeadzone_C != 0)
      {
         u16LocalExt_spdVehRaw = 0;
      }
      else
      {
         if (Ext_spdVehTreat < VehSpd_spdMinForClamp_C)
         {
            u16LocalExt_spdVehRaw = 0;
         }
         else
         {
            u16LocalExt_spdVehRaw = VehSpd_spdMinSat_C;
         }
      }
   }

   VEMS_vidSET(Ext_spdVehRaw, u16LocalExt_spdVehRaw);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidDynFil                                        */
/* !Description :  Ce bloc réalise une moyenne glissante sur les              */
/*                 VehSpd_NbPlsCalcMean_C derniers signaux.                   */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidMeanComputation();                          */
/*  input uint8 BufVEHSPDACQ_index;                                           */
/*  input uint16 Ext_VehSpdPlsTiIntl;                                         */
/*  output uint16 BufVEHSPDACQ[8];                                            */
/*  output uint8 BufVEHSPDACQ_index;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidDynFil(void)
{
   uint8  u8LocalBufIndex;


   /*02_MeanComputation*/
   VEHSPDACQ_vidMeanComputation();
   /* To avoid overflow of index */
   u8LocalBufIndex = (uint8)(BufVEHSPDACQ_index % VehSpd_noPlsCalcMean_SC);
   BufVEHSPDACQ[u8LocalBufIndex] = Ext_VehSpdPlsTiIntl;
   u8LocalBufIndex = (uint8)(u8LocalBufIndex + 1);
   BufVEHSPDACQ_index = (uint8)(u8LocalBufIndex % VehSpd_noPlsCalcMean_SC);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidMeanComputation                               */
/* !Description :  Ce bloc réalise une moyenne glissante sur les              */
/*                 VehSpd_NbPlsCalcMean_SC derniers signaux.                  */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 BufVEHSPDACQ_index;                                           */
/*  input uint16 Ext_VehSpdPlsTiIntl;                                         */
/*  input uint16 BufVEHSPDACQ[8];                                             */
/*  input uint32 Cumul_PlsTiIntr;                                             */
/*  input uint16 VehSpd_dstIntlPls_C;                                         */
/*  input uint8 Ext_VehSpdBuf;                                                */
/*  output uint32 Cumul_PlsTiIntr;                                            */
/*  output uint16 Ext_MeanSpdVehRaw;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidMeanComputation(void)
{
   uint8  u8LocalBufIndex;
   uint32 u32LocalMeanSpd;
   uint32 u32LocalPlsTi;
   sint32 s32LocalDiff;


   /* To avoid overflow of index */
   u8LocalBufIndex = (uint8)(BufVEHSPDACQ_index % VehSpd_noPlsCalcMean_SC);

   s32LocalDiff = (sint32)( Ext_VehSpdPlsTiIntl
                          - BufVEHSPDACQ[u8LocalBufIndex]);
   u32LocalPlsTi = MATHSRV_u32Add_u32_s32(Cumul_PlsTiIntr, s32LocalDiff);
   Cumul_PlsTiIntr = MATHSRV_udtMIN(u32LocalPlsTi, 655350);

   u32LocalMeanSpd = (uint32)(VehSpd_dstIntlPls_C * 9216);
   u32LocalMeanSpd = MATHSRV_u32Mul_u32_u32_div_u32(u32LocalMeanSpd,
                                                    (uint32)Ext_VehSpdBuf,
                                                    Cumul_PlsTiIntr);
   Ext_MeanSpdVehRaw = (uint16)MATHSRV_udtMIN(u32LocalMeanSpd, 65535);
}
/*--------------------------------end of file---------------------------------*/