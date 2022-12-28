/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OBDSRV06                                                */
/* !Description     : OBDSRV06 Component                                      */
/*                                                                            */
/* !Module          : OBDSRV06                                                */
/* !Description     : Definition des Trames EOBD pour le Mode06               */
/*                                                                            */
/* !File            : OBDSRV06_FCT1.c                                         */
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
/*   1 / OBDSRV06_pwrl                                                        */
/*   2 / OBDSRV06_EveRstDft                                                   */
/*   3 / OBDSRV06_EveRst                                                      */
/*   4 / OBDSRV06_SdlMid                                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 04787 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#061812                                         */
/* !OtherRefs   : VEMS V02 ECU#062507                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/OBDSRV06/OBDSRV06_FCT1.c$*/
/* $Revision::   1.8      $$Author::   pbakabad       $$Date::   Jul 05 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 05 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "OBDSRV06_im.h"
#include "OBDSRV06.h"
#include "OBDSRV06_L.h"
#include "MATHSRV.h"
#include "VEMS.h"
#include "GD_api.h"
#include "GDFRMDEF.h"
#include "RTE.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDSRV06_pwrl                                              */
/* !Description :  Evènement appelé pour l'écriture au powerlatch             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GD_bBitRead(argin uint8 u8Variable, argin uint8      */
/*  u8BitToTreat);                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Manu_inh_obdmid_01;                                         */
/*  input uint8 Mode_6_s1_81_data_d;                                          */
/*  input boolean Ext_bCondDiag_UsPlausFld;                                   */
/*  input uint16 SenO2Us_FldPlausFacMes_Obd6Mod;                              */
/*  input uint8 Mode_6_s1_A1_data_a;                                          */
/*  input boolean Ext_bCondDiag_UsPlausFco;                                   */
/*  input uint16 SenO2Us_FcoPlausFacMes_Obd6Mod;                              */
/*  input uint8 Mode_6_s1_01_data_a;                                          */
/*  input uint16 Tension_sonde_am_min_cycle;                                  */
/*  input boolean Ext_bCondDiag_uUpLs;                                        */
/*  input uint16 Tension_sonde_am_max_cycle;                                  */
/*  input uint8 Mode_6_s1_01_data_b;                                          */
/*  input boolean Ext_bCondDiag_OxySensPerd;                                  */
/*  input uint16 SenO2Us_PerDiag_FacMes_Obd6Mod;                              */
/*  input boolean Manu_inh_obdmid_02;                                         */
/*  input uint8 Mode_6_s2_A1_data_d;                                          */
/*  input boolean Ext_bCondDiag_DsPlausFld;                                   */
/*  input uint16 SenO2Ds_FldPlausFacMes_Obd6Mod;                              */
/*  input uint8 Mode_6_s2_C1_data_a;                                          */
/*  input boolean Ext_bCondDiag_DsPlausFco;                                   */
/*  input uint16 SenO2Ds_FcoPlausFacMes_Obd6Mod;                              */
/*  input uint8 Mode_6_s2_01_data_a;                                          */
/*  input uint16 Tension_sonde_av_min_cycle;                                  */
/*  input boolean Ext_bCondDiag_uDsLs;                                        */
/*  input uint16 Tension_sonde_av_max_cycle;                                  */
/*  input boolean Ext_bCondDiag_SigGrdDiag;                                   */
/*  input uint16 SenO2Ds_SigGrdFacMes_Obd6Mod;                                */
/*  input uint16 CatMon_facMes_Obd6Mod;                                       */
/*  input boolean Manu_inh_obdmid_21;                                         */
/*  input boolean Ext_bCondDiag_Cat;                                          */
/*  input uint16 HeatSenO2_UsFacMes_Obd6Mod;                                  */
/*  input boolean Manu_inh_obdmid_41;                                         */
/*  input boolean Ext_bCondDiag_UsHeat;                                       */
/*  input uint16 HeatSenO2_DsFacMes_Obd6Mod;                                  */
/*  input boolean Manu_inh_obdmid_42;                                         */
/*  input boolean Ext_bCondDiag_DsHeat;                                       */
/*  input boolean Manu_inh_obdmid_A2;                                         */
/*  input uint16 MonMisf_ctOccurMfDCCyl1;                                     */
/*  input boolean Mode_6_obdmid_A2_tid_0B;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl1;                                */
/*  input boolean Mode_6_obdmid_A2_tid_0C;                                    */
/*  input boolean Manu_inh_obdmid_A3;                                         */
/*  input uint16 MonMisf_ctOccurMfDCCyl2;                                     */
/*  input boolean Mode_6_obdmid_A3_tid_0B;                                    */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl2;                                */
/*  input boolean Mode_6_obdmid_A3_tid_0C;                                    */
/*  input boolean Manu_inh_obdmid_A4;                                         */
/*  input uint16 MonMisf_ctOccurMfDCCyl3;                                     */
/*  input boolean Mode_6_obdmid_A4_tid_0B;                                    */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl3;                                */
/*  input boolean Mode_6_obdmid_A4_tid_0C;                                    */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input boolean Manu_inh_obdmid_A5;                                         */
/*  input uint16 MonMisf_ctOccurMfDCCyl4;                                     */
/*  input boolean Mode_6_obdmid_A5_tid_0B;                                    */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl4;                                */
/*  input boolean Mode_6_obdmid_A5_tid_0C;                                    */
/*  output uint16 SenO2Us_FldPlausMes_Obd6Mod_eep;                            */
/*  output uint16 SenO2Us_FcoPlausMes_Obd6Mod_eep;                            */
/*  output uint16 Tension_sonde_am_min_cycle_eep;                             */
/*  output uint16 Tension_sonde_am_max_cycle_eep;                             */
/*  output uint16 Oxy_sens_period_var_eep;                                    */
/*  output uint16 SenO2Ds_FldPlausMes_Obd6Mod_eep;                            */
/*  output uint16 SenO2Ds_FcoPlausMes_Obd6Mod_eep;                            */
/*  output uint16 Tension_sonde_av_min_cycle_eep;                             */
/*  output uint16 Tension_sonde_av_max_cycle_eep;                             */
/*  output uint16 SenO2Ds_SigGrdFacMes_Obd6Mod_eep;                           */
/*  output uint16 CatMon_facMes_Obd6Mod_eep;                                  */
/*  output uint16 HeatSenO2_UsFacMes_Obd6Mod_eep;                             */
/*  output uint16 HeatSenO2_DsFacMes_Obd6Mod_eep;                             */
/*  output uint16 MonMisf_ctOccurMfDCCyl1_eep;                                */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl1_eep;                           */
/*  output uint16 MonMisf_ctOccurMfDCCyl2_eep;                                */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl2_eep;                           */
/*  output uint16 MonMisf_ctOccurMfDCCyl3_eep;                                */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl3_eep;                           */
/*  output uint16 MonMisf_ctOccurMfDCCyl4_eep;                                */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl4_eep;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OBDSRV06_pwrl(void)
{
   uint16   u16Local;
   boolean  bLocalRdy;

   /* Sonde amont */
   if(Manu_inh_obdmid_01 == 0)
   {
      bLocalRdy = GD_bBitRead(Mode_6_s1_81_data_d,0);
      if((bLocalRdy == 1) && (Ext_bCondDiag_UsPlausFld ==1))
      {
         VEMS_vidGET(SenO2Us_FldPlausFacMes_Obd6Mod, u16Local);
         u16Local = (uint16)MATHSRV_udtMIN(0x03FF, u16Local);
         SenO2Us_FldPlausMes_Obd6Mod_eep = u16Local;
      }

      bLocalRdy = GD_bBitRead(Mode_6_s1_A1_data_a,7);
      if((bLocalRdy == 1) && (Ext_bCondDiag_UsPlausFco == 1))
      {
         VEMS_vidGET(SenO2Us_FcoPlausFacMes_Obd6Mod, u16Local);
         u16Local = (uint16)MATHSRV_udtMIN(0x03FF, u16Local);
         SenO2Us_FcoPlausMes_Obd6Mod_eep = u16Local;
      }

      bLocalRdy = GD_bBitRead(Mode_6_s1_01_data_a,1);
      VEMS_vidGET(Tension_sonde_am_min_cycle, u16Local);
      if((  (u16Local != 0)
            && (u16Local != 0x03FF)
         )
         && ((bLocalRdy == 1) && (Ext_bCondDiag_uUpLs == 1)))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0x03FE, u16Local);
         Tension_sonde_am_min_cycle_eep = u16Local;
      }

      bLocalRdy = GD_bBitRead(Mode_6_s1_01_data_a,0);
      VEMS_vidGET(Tension_sonde_am_max_cycle, u16Local);
      if((  (u16Local != 0)
            && (u16Local != 0x03FF)
         )
         && ((bLocalRdy == 1) && (Ext_bCondDiag_uUpLs == 1)))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0x03FE, u16Local);
         Tension_sonde_am_max_cycle_eep = u16Local;
      }

      bLocalRdy = GD_bBitRead(Mode_6_s1_01_data_b,6);
      if((bLocalRdy == 1) && (Ext_bCondDiag_OxySensPerd == 1))
      {
         VEMS_vidGET(SenO2Us_PerDiag_FacMes_Obd6Mod, u16Local);
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFE, u16Local);
         Oxy_sens_period_var_eep = u16Local;
      }
   }

   /* Sonde aval */
   if(Manu_inh_obdmid_02 == 0)
   {
      bLocalRdy = GD_bBitRead(Mode_6_s2_A1_data_d,0);
      if((bLocalRdy == 1) && (Ext_bCondDiag_DsPlausFld == 1))
      {
         VEMS_vidGET(SenO2Ds_FldPlausFacMes_Obd6Mod, u16Local);
         u16Local = (uint16)MATHSRV_udtMIN(0x03FF, u16Local);
         SenO2Ds_FldPlausMes_Obd6Mod_eep = u16Local;
      }

      bLocalRdy = GD_bBitRead(Mode_6_s2_C1_data_a,7);
      if((bLocalRdy == 1) && (Ext_bCondDiag_DsPlausFco == 1))
      {
         VEMS_vidGET(SenO2Ds_FcoPlausFacMes_Obd6Mod, u16Local);
         u16Local =
            (uint16)MATHSRV_udtMIN(0x3FF,u16Local);
         SenO2Ds_FcoPlausMes_Obd6Mod_eep = u16Local;
      }

      bLocalRdy = GD_bBitRead(Mode_6_s2_01_data_a, 1);
      VEMS_vidGET(Tension_sonde_av_min_cycle, u16Local);
      if (  ((u16Local != 0x00) && (u16Local != 0x03FF))
            && ((bLocalRdy == 1 ) && (Ext_bCondDiag_uDsLs == 1)))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0x03FE, u16Local);
         Tension_sonde_av_min_cycle_eep = u16Local;
      }

      bLocalRdy = GD_bBitRead(Mode_6_s2_01_data_a,0);
      VEMS_vidGET(Tension_sonde_av_max_cycle,u16Local);
      if (  ((u16Local != 0x00) && (u16Local != 0x03FF))
            && ((bLocalRdy == 1 ) && (Ext_bCondDiag_uDsLs == 1)))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0x03FE, u16Local);
         Tension_sonde_av_max_cycle_eep = u16Local;
      }

      bLocalRdy = GD_bBitRead(Mode_6_s2_C1_data_a,6);
      if((bLocalRdy == 1) && (Ext_bCondDiag_SigGrdDiag == 1))
      {
         VEMS_vidGET(SenO2Ds_SigGrdFacMes_Obd6Mod, u16Local);
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFE, u16Local);
         SenO2Ds_SigGrdFacMes_Obd6Mod_eep = u16Local;
      }
   }

   /* Catalyseur */
   VEMS_vidGET(CatMon_facMes_Obd6Mod, u16Local);
   if((Manu_inh_obdmid_21 == 0) && (Ext_bCondDiag_Cat == 1))
   {
      u16Local = (uint16)MATHSRV_udtMIN(0xFFFE, u16Local);
      CatMon_facMes_Obd6Mod_eep = u16Local;
   }

   /* Chauffage sonde amont */
   VEMS_vidGET(HeatSenO2_UsFacMes_Obd6Mod, u16Local);
   if((Manu_inh_obdmid_41 == 0) && (Ext_bCondDiag_UsHeat == 1))
   {
      u16Local = (uint16)MATHSRV_udtMIN(0xFFFE, u16Local);
      HeatSenO2_UsFacMes_Obd6Mod_eep = u16Local;
   }

   /* Chauffage sonde aval */
   VEMS_vidGET(HeatSenO2_DsFacMes_Obd6Mod, u16Local);
   if((Manu_inh_obdmid_42 == 0) && (Ext_bCondDiag_DsHeat == 1))
   {
      u16Local = (uint16)MATHSRV_udtMIN(0xFFFE, u16Local);
      HeatSenO2_DsFacMes_Obd6Mod_eep = u16Local;
   }

   /* Misfire */
   if(Manu_inh_obdmid_A2 == 0)
   {

      VEMS_vidGET(MonMisf_ctOccurMfDCCyl1, u16Local);
      if((Mode_6_obdmid_A2_tid_0B == 1) && (Ext_bCondDiag_Misf == 1))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFF, u16Local);
         VEMS_vidSET(MonMisf_ctOccurMfDCCyl1_eep, u16Local);
      }

      VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl1, u16Local);
      if((Mode_6_obdmid_A2_tid_0C == 1) && (Ext_bCondDiag_Misf == 1))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFF, u16Local);
         VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl1_eep, u16Local);
      }
   }

   if(Manu_inh_obdmid_A3 == 0)
   {
      VEMS_vidGET(MonMisf_ctOccurMfDCCyl2, u16Local);
      if((Mode_6_obdmid_A3_tid_0B == 1) && (Ext_bCondDiag_Misf == 1))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFF, u16Local);
         VEMS_vidSET(MonMisf_ctOccurMfDCCyl2_eep, u16Local);
      }

      VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl2, u16Local);
      if((Mode_6_obdmid_A3_tid_0C == 1) && (Ext_bCondDiag_Misf == 1))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFF, u16Local);
         VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl2_eep, u16Local);
      }
   }

   if(Manu_inh_obdmid_A4 == 0)
   {
      VEMS_vidGET(MonMisf_ctOccurMfDCCyl3,u16Local);
      if((Mode_6_obdmid_A4_tid_0B == 1) && (Ext_bCondDiag_Misf == 1))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFF, u16Local);
         VEMS_vidSET(MonMisf_ctOccurMfDCCyl3_eep, u16Local);
      }

      VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl3, u16Local);
      if((Mode_6_obdmid_A4_tid_0C == 1) && (Ext_bCondDiag_Misf == 1))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFF, u16Local);
         VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl3_eep, u16Local);
      }
   }

   VEMS_vidGET(Ext_noCylEng,u16Local);
   if((Manu_inh_obdmid_A5 == 0) && (u16Local == 4))
   {
      VEMS_vidGET(MonMisf_ctOccurMfDCCyl4,u16Local);
      if((Mode_6_obdmid_A5_tid_0B == 1) && (Ext_bCondDiag_Misf == 1))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFF, u16Local);
         VEMS_vidSET(MonMisf_ctOccurMfDCCyl4_eep, u16Local);
      }

      VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl4, u16Local);
      if((Mode_6_obdmid_A5_tid_0C == 1) && (Ext_bCondDiag_Misf == 1))
      {
         u16Local = (uint16)MATHSRV_udtMIN(0xFFFF, u16Local);
         VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl4_eep, u16Local);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDSRV06_EveRstDft                                         */
/* !Description :  Fonction appelée lors de la demande d'effacement Manuel des*/
/*                 défauts                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  output uint16 CatMon_facMes_Obd6Mod_eep;                                  */
/*  output uint16 HeatSenO2_DsFacMes_Obd6Mod_eep;                             */
/*  output uint16 HeatSenO2_UsFacMes_Obd6Mod_eep;                             */
/*  output uint16 Oxy_sens_period_var_eep;                                    */
/*  output uint16 SenO2Ds_FcoPlausMes_Obd6Mod_eep;                            */
/*  output uint16 SenO2Ds_FldPlausMes_Obd6Mod_eep;                            */
/*  output uint16 SenO2Us_FcoPlausMes_Obd6Mod_eep;                            */
/*  output uint16 SenO2Us_FldPlausMes_Obd6Mod_eep;                            */
/*  output uint16 SenO2Ds_SigGrdFacMes_Obd6Mod_eep;                           */
/*  output uint16 Tension_sonde_am_max_cycle_eep;                             */
/*  output uint16 Tension_sonde_am_min_cycle_eep;                             */
/*  output uint16 Tension_sonde_av_max_cycle_eep;                             */
/*  output uint16 Tension_sonde_av_min_cycle_eep;                             */
/*  output uint16 MonMisf_ctOccurMfDCCyl1_eep;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl2_eep;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl3_eep;                                */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl1_eep;                           */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl2_eep;                           */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl3_eep;                           */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl4_eep;                           */
/*  output uint16 MonMisf_ctOccurMfDCCyl4_eep;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OBDSRV06_EveRstDft(void)
{
   uint16 u16Local;

   /* Initialisation des variables lors d’une requête d’effacement
   des défauts au Mode 04 ou via les services constructeurs (CLRDTC) */
   CatMon_facMes_Obd6Mod_eep = 0xFFFF;
   HeatSenO2_DsFacMes_Obd6Mod_eep = 0xFFFF;
   HeatSenO2_UsFacMes_Obd6Mod_eep = 0xFFFF;
   Oxy_sens_period_var_eep = 0xFFFE;
   SenO2Ds_FcoPlausMes_Obd6Mod_eep = 0x0400;
   SenO2Ds_FldPlausMes_Obd6Mod_eep = 0x0400;
   SenO2Us_FcoPlausMes_Obd6Mod_eep = 0x0400;
   SenO2Us_FldPlausMes_Obd6Mod_eep = 0x0400;
   SenO2Ds_SigGrdFacMes_Obd6Mod_eep = 0xFFFF;
   Tension_sonde_am_max_cycle_eep = 0x0000;
   Tension_sonde_am_min_cycle_eep = 0x03FF;
   Tension_sonde_av_max_cycle_eep = 0x0000;
   Tension_sonde_av_min_cycle_eep = 0x03FF;
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl1_eep,0x0000);
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl2_eep,0x0000);
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl3_eep,0x0000);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl1_eep,0x0000);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl2_eep,0x0000);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl3_eep,0x0000);

   VEMS_vidGET(Ext_noCylEng,u16Local);

   if(u16Local == 4)
   {
      VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl4_eep,0x0000);
      VEMS_vidSET(MonMisf_ctOccurMfDCCyl4_eep,0x0000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDSRV06_EveRst                                            */
/* !Description :  Fonction appelée par l'Evénement reset de la fonction      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 GD_stEventStatus[635];                                        */
/*  output boolean Ext_bCondDiag_uUpLs;                                       */
/*  output boolean Ext_bCondDiag_OxySensPerd;                                 */
/*  output boolean Ext_bCondDiag_UsPlausFld;                                  */
/*  output boolean Ext_bCondDiag_UsPlausFco;                                  */
/*  output uint8 GD_stEventStatus_prev[635];                                  */
/*  output boolean Ext_bCondDiag_uDsLs;                                       */
/*  output boolean Ext_bCondDiag_DsPlausFld;                                  */
/*  output boolean Ext_bCondDiag_DsPlausFco;                                  */
/*  output boolean Ext_bCondDiag_SigGrdDiag;                                  */
/*  output boolean Ext_bCondDiag_Cat;                                         */
/*  output boolean Ext_bCondDiag_UsHeat;                                      */
/*  output boolean Ext_bCondDiag_DsHeat;                                      */
/*  output boolean Ext_bCondDiag_Misf;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OBDSRV06_EveRst(void)
{

   uint8 u8Local;

   /* Initialisation Sonde amont */
   Ext_bCondDiag_uUpLs = 0;
   Ext_bCondDiag_OxySensPerd = 0;
   Ext_bCondDiag_UsPlausFld = 0;
   Ext_bCondDiag_UsPlausFco = 0;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_SCG_UUPLS,u8Local);
   GD_stEventStatus_prev[GD_DFT_SCG_UUPLS] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_SCP_UUPLS,u8Local);
   GD_stEventStatus_prev[GD_DFT_SCP_UUPLS] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_OC_UUPLS,u8Local);
   GD_stEventStatus_prev[GD_DFT_OC_UUPLS] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_OXYSENSPERD,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_OXYSENSPERD] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_USPLAUSFLD,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_USPLAUSFLD] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_USPLAUSFCO,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_USPLAUSFCO] = u8Local;

   /* Initialisation sonde aval */
   Ext_bCondDiag_uDsLs = 0;
   Ext_bCondDiag_DsPlausFld = 0;
   Ext_bCondDiag_DsPlausFco = 0;
   Ext_bCondDiag_SigGrdDiag = 0;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_SCG_UDSLS,u8Local);
   GD_stEventStatus_prev[GD_DFT_SCG_UDSLS] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_SCP_UDSLS,u8Local);
   GD_stEventStatus_prev[GD_DFT_SCP_UDSLS] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_OC_UDSLS,u8Local);
   GD_stEventStatus_prev[GD_DFT_OC_UDSLS] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_DSPLAUSFLD,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_DSPLAUSFLD] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_DSPLAUSFCO,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_DSPLAUSFCO] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_SIGGRDDIAG,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_SIGGRDDIAG] = u8Local;

   /* Initialisation Catalyseur */
   Ext_bCondDiag_Cat = 0;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_CAT,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_CAT] = u8Local;

   /* Initialisation Chauffage sonde */
   Ext_bCondDiag_UsHeat = 0;
   Ext_bCondDiag_DsHeat = 0;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_USHEAT,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_USHEAT] = u8Local;

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_DSHEAT,u8Local);
   GD_stEventStatus_prev[GD_DFT_ORNG_DSHEAT] = u8Local;

   /* Initialisation Chauffage sonde */
   Ext_bCondDiag_Misf = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDSRV06_SdlMid                                            */
/* !Description :  fonction appelée par le Cheduler moyen de la fonction      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 GD_stEventStatus[635];                                        */
/*  input uint8 GD_stEventStatus_prev[635];                                   */
/*  input boolean Mf_emiss_horizon_uavb0;                                     */
/*  input boolean Mf_cat_dam_horizon_uavb0;                                   */
/*  input uint16 SenO2Ds_SigGrdFacMes_Obd6Mod;                                */
/*  input uint16 SenO2Ds_SigGrdFacMes_Obd6Mod_eep;                            */
/*  output boolean Ext_bCondDiag_uUpLs;                                       */
/*  output boolean Ext_bCondDiag_OxySensPerd;                                 */
/*  output boolean Ext_bCondDiag_UsPlausFld;                                  */
/*  output boolean Ext_bCondDiag_UsPlausFco;                                  */
/*  output boolean Ext_bCondDiag_uDsLs;                                       */
/*  output boolean Ext_bCondDiag_SigGrdDiag;                                  */
/*  output boolean Ext_bCondDiag_DsPlausFld;                                  */
/*  output boolean Ext_bCondDiag_DsPlausFco;                                  */
/*  output boolean Ext_bCondDiag_Cat;                                         */
/*  output boolean Ext_bCondDiag_DsHeat;                                      */
/*  output boolean Ext_bCondDiag_Misf;                                        */
/*  output uint16 SenO2Ds_SigGrd_Obd6Mod;                                     */
/*  output uint16 SenO2Ds_SigGrd_Obd6Mod_eep;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OBDSRV06_SdlMid(void)
{

   uint8    u8Local_1;
   uint8    u8Local_2;
   uint8    u8Local_3;
   uint16   u16Local;


   /* Sonde amont */
   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_SCG_UUPLS,u8Local_1);
   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_SCP_UUPLS,u8Local_2);
   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_OC_UUPLS,u8Local_3);
   if(   (  (GD_stEventStatus_prev[GD_DFT_SCG_UUPLS] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_SCG_UUPLS]))
      || (  (GD_stEventStatus_prev[GD_DFT_SCP_UUPLS] == GD_INIT)
         && (u8Local_2 != GD_stEventStatus_prev[GD_DFT_SCP_UUPLS]))
      || (  (GD_stEventStatus_prev[GD_DFT_OC_UUPLS] == GD_INIT)
         && (u8Local_3 != GD_stEventStatus_prev[GD_DFT_OC_UUPLS]))
   )
   {
      Ext_bCondDiag_uUpLs = 1;
   }

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_OXYSENSPERD,
            u8Local_1);

   if(   (  (GD_stEventStatus_prev[GD_DFT_ORNG_OXYSENSPERD] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_ORNG_OXYSENSPERD]))
   )
   {
      Ext_bCondDiag_OxySensPerd = 1;
   }

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_USPLAUSFLD,u8Local_1);
   if(   (  (GD_stEventStatus_prev[GD_DFT_ORNG_USPLAUSFLD] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_ORNG_USPLAUSFLD]))
   )
   {
      Ext_bCondDiag_UsPlausFld = 1;
   }

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_USPLAUSFCO,u8Local_1);
   if(   (  (GD_stEventStatus_prev[GD_DFT_ORNG_USPLAUSFCO] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_ORNG_USPLAUSFCO]))
   )
   {
      Ext_bCondDiag_UsPlausFco = 1;
   }

   /* Initialisation Sonde aval */
   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_SCG_UDSLS,u8Local_1);
   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_SCP_UDSLS,u8Local_2);
   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_OC_UDSLS,u8Local_3);
   if(   (  (GD_stEventStatus_prev[GD_DFT_SCG_UDSLS] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_SCG_UDSLS]))
      || (  (GD_stEventStatus_prev[GD_DFT_SCP_UDSLS] == GD_INIT)
         && (u8Local_2 != GD_stEventStatus_prev[GD_DFT_SCP_UDSLS]))
      || (  (GD_stEventStatus_prev[GD_DFT_OC_UDSLS] == GD_INIT)
         && (u8Local_3 != GD_stEventStatus_prev[GD_DFT_OC_UDSLS]))
   )
   {
      Ext_bCondDiag_uDsLs = 1;
   }

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_SIGGRDDIAG,u8Local_1);
   if(   (  (GD_stEventStatus_prev[GD_DFT_ORNG_SIGGRDDIAG] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_ORNG_SIGGRDDIAG]))
   )
   {
      Ext_bCondDiag_SigGrdDiag = 1;
   }

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_DSPLAUSFLD,u8Local_1);
   if(   (  (GD_stEventStatus_prev[GD_DFT_ORNG_DSPLAUSFLD] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_ORNG_DSPLAUSFLD]))
   )
   {
      Ext_bCondDiag_DsPlausFld = 1;
   }

   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_DSPLAUSFCO,u8Local_1);
   if(   (  (GD_stEventStatus_prev[GD_DFT_ORNG_DSPLAUSFCO] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_ORNG_DSPLAUSFCO]))
   )
   {
      Ext_bCondDiag_DsPlausFco = 1;
   }

   /* Initialisation Catalyseur */
   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_CAT,u8Local_1);
   if(   (  (GD_stEventStatus_prev[GD_DFT_ORNG_CAT] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_ORNG_CAT]))
   )
   {
      Ext_bCondDiag_Cat = 1;
   }

   /* Initialisation Chauffage sonde */
   VEMS_vidGET1DArrayElement(GD_stEventStatus,GD_DFT_ORNG_USHEAT,u8Local_1);
   if(   (  (GD_stEventStatus_prev[GD_DFT_ORNG_USHEAT] == GD_INIT)
         && (u8Local_1 != GD_stEventStatus_prev[GD_DFT_ORNG_USHEAT]))
   )
   {
      Ext_bCondDiag_DsHeat = 1;
   }

   /* Initialisation Misfire */
   VEMS_vidGET(Mf_emiss_horizon_uavb0,u8Local_1);
   VEMS_vidGET(Mf_cat_dam_horizon_uavb0,u8Local_2);
   if((u8Local_1 == 1) || (u8Local_2 == 1))
   {
      Ext_bCondDiag_Misf = 1;
   }

   /* Scalling de la valeur remontée pour le diagnostic dérivée sonde aval */
   VEMS_vidGET(SenO2Ds_SigGrdFacMes_Obd6Mod,u16Local);
   SenO2Ds_SigGrd_Obd6Mod = (uint16)(((u16Local * 3125) + 2048) / 4096);
   SenO2Ds_SigGrd_Obd6Mod_eep =
        (uint16)(((SenO2Ds_SigGrdFacMes_Obd6Mod_eep * 3125) + 2048) / 4096);
}

/*-------------------------------- end of file -------------------------------*/