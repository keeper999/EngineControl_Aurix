/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : UPLSACQ                                                 */
/* !Description     : UPLSACQ component.                                      */
/*                                                                            */
/* !Module          : UPLSACQ                                                 */
/* !Description     : ACQUISITION DE LA SONDE A OXYGENE AMONT                 */
/*                                                                            */
/* !File            : UPLSACQ_fct3.C                                          */
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
/*   1 / UPLSACQ_vidSenO2UsManagement                                         */
/*   2 / UPLSACQ_vidSenO2UsDefault                                            */
/*   3 / UPLSACQ_vidSenO2StateKeyOff                                          */
/*   4 / UPLSACQ_vidFilteringSyncEngine                                       */
/*   5 / UPLSACQ_vidFilteringStallEngine                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6562315 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/UPLSACQ/UPLSACQ_FCT3.c_v          $*/
/* $Revision::   1.9      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "UPLSACQ.H"
#include "UPLSACQ_L.H"
#include "UPLSACQ_IM.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsManagement                               */
/* !Description :  management de la tension sonde amont                       */
/* !Number      :  FCT3.1                                                     */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_003.01                                     */
/*                 VEMS_R_08_04819_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void UPLSACQ_vidSenO2UsCounterInhib();                        */
/*  extf argret void UPLSACQ_vidSenO2UsCountInhibInit();                      */
/*  extf argret void UPLSACQ_vidSenO2UsVoltageCalc();                         */
/*  extf argret void UPLSACQ_vidSenO2UsFreeze();                              */
/*  extf argret void UPLSACQ_vidLeanToRichSensor();                           */
/*  extf argret void UPLSACQ_vidRichToLeanSensor();                           */
/*  input boolean Auto_injection;                                             */
/*  input boolean Sonde_riche_amont;                                          */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input boolean Panne_so2_am_presente;                                      */
/*  input uint16 Seuil_sonde_amont_riche;                                     */
/*  input uint16 Seuil_sonde_amont_pauvre;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsManagement(void)
{
   boolean bLocalInhSenO2UsFuRatTran;
   boolean bLocalAuto_injection;
   boolean bLocalSonde_riche_amont;
   uint16  u16LocalTension_sonde_amont;


   bLocalInhSenO2UsFuRatTran = GDGAR_bGetFRM(FRM_FRM_INHSENO2USFURATTRAN);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Sonde_riche_amont, bLocalSonde_riche_amont);
   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   if (bLocalAuto_injection != 0)
   {
      /* 2_2_0_inhibe_extrema_sonde_count */
      UPLSACQ_vidSenO2UsCounterInhib();
   }
   else
   {
      /* 2_2_0_init_inhibe_extrema_sonde_count */
      UPLSACQ_vidSenO2UsCountInhibInit();
   }

   /* 2_2_1_calcul_tension_sonde_amont */
   UPLSACQ_vidSenO2UsVoltageCalc();

   if (bLocalInhSenO2UsFuRatTran != 0)
   {
      /* 2_2_4_freeze_sonde_amont  */
      UPLSACQ_vidSenO2UsFreeze();
   }
   else
   {
      if (Panne_so2_am_presente == 0)
      {
         if (bLocalSonde_riche_amont == 0)
         {
            if (u16LocalTension_sonde_amont >= Seuil_sonde_amont_riche)
            {
               /* 2_2_2_sonde_lean_to_rich */
               UPLSACQ_vidLeanToRichSensor();
            }
         }
         else
         {
            if (  (u16LocalTension_sonde_amont < Seuil_sonde_amont_riche)
               && (u16LocalTension_sonde_amont < Seuil_sonde_amont_pauvre))
            {
               /* 2_2_3_sonde_rich_to_lean */
               UPLSACQ_vidRichToLeanSensor();
            }
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsDefault                                  */
/* !Description :  Défaut circuit ouvert                                      */
/* !Number      :  FCT3.2                                                     */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_006.01                                     */
/*                 VEMS_R_08_04819_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Lshd_voltage_upstr_sens_filtered;                            */
/*  input uint16 Ldsen_sensor_dead_zone_lo_thresh;                            */
/*  input uint16 Ldsen_sensor_dead_zone_hi_thresh;                            */
/*  input uint16 Ldsen_sensor_dead_zone_count;                                */
/*  input uint8 Ldsen_sensor_dead_zone_inc_step;                              */
/*  input uint8 Ldsen_sensor_dead_zone_dec_step;                              */
/*  input uint16 Ldsen_sensor_dead_zone_thresh;                               */
/*  output uint16 Ldsen_sensor_dead_zone_count;                               */
/*  output boolean Ext_bDgoOc_uUpLs;                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsDefault(void)
{
   uint16 u16LocalLshd_voltage_upstr_se;
   sint32 s32LocalCounter;

   VEMS_vidGET(Lshd_voltage_upstr_sens_filtered, u16LocalLshd_voltage_upstr_se);


   if (  (u16LocalLshd_voltage_upstr_se > Ldsen_sensor_dead_zone_lo_thresh)
      && ( u16LocalLshd_voltage_upstr_se
         < Ldsen_sensor_dead_zone_hi_thresh))
   {
      s32LocalCounter = ( Ldsen_sensor_dead_zone_count
                        + Ldsen_sensor_dead_zone_inc_step);

   }
   else
   {
      s32LocalCounter = ( Ldsen_sensor_dead_zone_count
                        - Ldsen_sensor_dead_zone_dec_step);
   }
   Ldsen_sensor_dead_zone_count = (uint16)MATHSRV_udtCLAMP(s32LocalCounter,
                                                           0,
                                                           65535);
   if (Ldsen_sensor_dead_zone_count >= Ldsen_sensor_dead_zone_thresh)
   {
      Ext_bDgoOc_uUpLs = 1;
   }
   else
   {
      Ext_bDgoOc_uUpLs = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2StateKeyOff                                */
/* !Description :  Etat de la sonde en cle off                                */
/* !Number      :  FCT3.3                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sonde_riche_amont;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2StateKeyOff(void)
{
   VEMS_vidSET(Sonde_riche_amont, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidFilteringSyncEngine                             */
/* !Description :  filtrage de la Tension sonde amont brute                   */
/* !Number      :  FCT3.4                                                     */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 Tension_sonde_amont_brute;                                   */
/*  input uint16 UPLSACQ_u16SenO2UsVoltagePrev1;                              */
/*  input uint16 UPLSACQ_u16SenO2UsVoltagePrev2;                              */
/*  input uint16 UPLSACQ_u16SenO2UsVoltagePrev3;                              */
/*  output boolean Tension_so2_am_first_computed;                             */
/*  output uint16 Tension_sonde_amont_filtree;                                */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev3;                             */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev2;                             */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev1;                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidFilteringSyncEngine(void)
{
   uint8  u8LocalExt_noCylEng;
   uint16 u16LocalFiltredSensor;
   uint16 u16LocalTension_sonde_amont_brut;
   uint32 u32LocalFiltredSensor;


   Tension_so2_am_first_computed = 1;
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   VEMS_vidGET(Tension_sonde_amont_brute, u16LocalTension_sonde_amont_brut);

   switch (u8LocalExt_noCylEng)
   {
      case 0:
         u32LocalFiltredSensor = 1023;
         break;
      case 1:
         u32LocalFiltredSensor = u16LocalTension_sonde_amont_brut;
         break;
      case 2:
         u32LocalFiltredSensor = ( u16LocalTension_sonde_amont_brut
                                 + UPLSACQ_u16SenO2UsVoltagePrev1);
         u32LocalFiltredSensor = ((u32LocalFiltredSensor + 1) / 2);
         break;
      case 3:
         u32LocalFiltredSensor = ( u16LocalTension_sonde_amont_brut
                                 + UPLSACQ_u16SenO2UsVoltagePrev1
                                 + UPLSACQ_u16SenO2UsVoltagePrev2);
         u32LocalFiltredSensor = (u32LocalFiltredSensor / 3);
         break;
      case 4:
         u32LocalFiltredSensor = ( u16LocalTension_sonde_amont_brut
                                 + UPLSACQ_u16SenO2UsVoltagePrev1
                                 + UPLSACQ_u16SenO2UsVoltagePrev2
                                 + UPLSACQ_u16SenO2UsVoltagePrev3);
         u32LocalFiltredSensor = ((u32LocalFiltredSensor + 2) / 4);
         break;
      default:
         SWFAIL_vidSoftwareErrorHook();
         u32LocalFiltredSensor = 0;
         break;
   }

   u16LocalFiltredSensor = (uint16)MATHSRV_udtMIN(u32LocalFiltredSensor, 1023);
   VEMS_vidSET(Tension_sonde_amont_filtree, u16LocalFiltredSensor);

   UPLSACQ_u16SenO2UsVoltagePrev3 =
      (uint16)MATHSRV_udtMIN(UPLSACQ_u16SenO2UsVoltagePrev2, 1023);

   UPLSACQ_u16SenO2UsVoltagePrev2 =
      (uint16)MATHSRV_udtMIN(UPLSACQ_u16SenO2UsVoltagePrev1, 1023);

   UPLSACQ_u16SenO2UsVoltagePrev1 =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont_brut, 1023);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidFilteringStallEngine                            */
/* !Description :  filtrage de la sonde en moteur cale                        */
/* !Number      :  FCT3.5                                                     */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_sonde_amont_brute;                                   */
/*  output boolean Tension_so2_am_first_computed;                             */
/*  output uint16 Tension_sonde_amont_filtree;                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidFilteringStallEngine(void)
{
   uint16 u16LocalTension_sonde_amont_brut;


   Tension_so2_am_first_computed = 1;
   VEMS_vidGET(Tension_sonde_amont_brute, u16LocalTension_sonde_amont_brut);
   if (u16LocalTension_sonde_amont_brut <= 1023)
   {
      VEMS_vidSET(Tension_sonde_amont_filtree,
                  u16LocalTension_sonde_amont_brut);
   }
   else
   {
      VEMS_vidSET(Tension_sonde_amont_filtree, 1023);
   }

}

/*------------------------------- end of file --------------------------------*/