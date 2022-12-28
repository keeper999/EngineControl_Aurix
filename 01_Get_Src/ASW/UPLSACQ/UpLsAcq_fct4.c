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
/* !File            : UPLSACQ_fct4.C                                          */
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
/*   1 / UPLSACQ_vidSenO2UsCounterInhib                                       */
/*   2 / UPLSACQ_vidSenO2UsCountInhibInit                                     */
/*   3 / UPLSACQ_vidSenO2UsVoltageCalc                                        */
/*   4 / UPLSACQ_vidLeanToRichSensor                                          */
/*   5 / UPLSACQ_vidRichToLeanSensor                                          */
/*   6 / UPLSACQ_vidSenO2UsFreeze                                             */
/*   7 / UPLSACQ_vidExtremeSenO2VoltMngt                                      */
/*   8 / UPLSACQ_vidNoFaultSenO2VoltMngt                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6562315 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/UPLSACQ/UPLSACQ_FCT4.c_v          $*/
/* $Revision::   1.7      $$Author::   wbouach        $$Date::   14 May 2014 $*/
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
/* !Function    :  UPLSACQ_vidSenO2UsCounterInhib                             */
/* !Description :  Calcul des extrema des sondes                              */
/* !Number      :  FCT4.1                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Inhibe_extrema_sonde_count;                                  */
/*  output uint16 Inhibe_extrema_sonde_count;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsCounterInhib(void)
{
   uint16 u16LocalInhibe_extrema_sonde_cou;


   VEMS_vidGET(Inhibe_extrema_sonde_count, u16LocalInhibe_extrema_sonde_cou);
   if (u16LocalInhibe_extrema_sonde_cou > 52428)
   {
      VEMS_vidSET(Inhibe_extrema_sonde_count, 52428);
   }
   else
   {
      if (u16LocalInhibe_extrema_sonde_cou != 0)
      {
         u16LocalInhibe_extrema_sonde_cou =
         (uint16)(u16LocalInhibe_extrema_sonde_cou - 1);
         VEMS_vidSET(Inhibe_extrema_sonde_count,
                     u16LocalInhibe_extrema_sonde_cou);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsCountInhibInit                           */
/* !Description :  Initialsation du compteur d'inhibition du calcul des       */
/*                 extrema des sondes lors d'une coupure injection            */
/* !Number      :  FCT4.2                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Inhibe_extrema_sonde_delay;                                  */
/*  output uint16 Inhibe_extrema_sonde_count;                                 */
/*  output uint16 Inhibe_extrema_sonde_delay;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsCountInhibInit(void)
{
   if (Inhibe_extrema_sonde_delay <= 52428)
   {
      VEMS_vidSET(Inhibe_extrema_sonde_count, Inhibe_extrema_sonde_delay);
   }
   else
   {
      VEMS_vidSET(Inhibe_extrema_sonde_count, 52428);
   }

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsVoltageCalc                              */
/* !Description :  Calcul de la tension sonde amont                           */
/* !Number      :  FCT4.3                                                     */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_005.01                                     */
/*                 VEMS_R_08_04819_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void UPLSACQ_vidNoFaultSenO2VoltMngt();                       */
/*  extf argret void UPLSACQ_vidExtremeSenO2VoltMngt();                       */
/*  input uint16 Inhibe_extrema_sonde_count;                                  */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint16 Acq_tension_sonde_o2_am;                                     */
/*  input uint16 Tension_sonde_amont_brute;                                   */
/*  input uint16 Seuil_maxi_tension_sonde;                                    */
/*  input boolean Tension_so2_am_first_computed;                              */
/*  output boolean Ext_bMonWaitScp_uUpLs;                                     */
/*  output uint16 Tension_sonde_amont_brute;                                  */
/*  output boolean Ext_bDgoScp_uUpLs;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsVoltageCalc(void)
{
   boolean bLocalInhUpLsAcqDiagEl;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalTension_sonde_amont_brut;
   uint16  u16LocalInhibe_extrema_sonde_cou;
   uint16  u16LocalAcq_tension_sonde_o2_am;


   VEMS_vidGET(Inhibe_extrema_sonde_count, u16LocalInhibe_extrema_sonde_cou);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Acq_tension_sonde_o2_am, u16LocalAcq_tension_sonde_o2_am);

   Ext_bMonWaitScp_uUpLs = 0;
   bLocalInhUpLsAcqDiagEl = GDGAR_bGetFRM(FRM_FRM_INHUPLSACQDIAGEL);

   u16LocalTension_sonde_amont_brut =
      (uint16)(u16LocalAcq_tension_sonde_o2_am / 4);
   u16LocalTension_sonde_amont_brut =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont_brut, 1023);
   VEMS_vidSET(Tension_sonde_amont_brute, u16LocalTension_sonde_amont_brut);
   VEMS_vidGET(Tension_sonde_amont_brute, u16LocalTension_sonde_amont_brut);

   if (u16LocalTension_sonde_amont_brut >= Seuil_maxi_tension_sonde)
   {
      if (bLocalInhUpLsAcqDiagEl == 0)
      {
         Ext_bDgoScp_uUpLs = 1;
      }
      else
      {
         Ext_bDgoScp_uUpLs = 0;
      }
   }
   else
   {
      Ext_bDgoScp_uUpLs = 0;
      /* Manage_tension_sonde_sans_defaut */
      UPLSACQ_vidNoFaultSenO2VoltMngt();
      if (  (u16LocalInhibe_extrema_sonde_cou == 0)
         && (Tension_so2_am_first_computed != 0)
         && (u8LocalVehicle_active_state == VS_RUNNING))
      {
         /* Manage_tension_sonde_extrema */
         UPLSACQ_vidExtremeSenO2VoltMngt();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidLeanToRichSensor                                */
/* !Description :  Transition de la sonde amont de l'etat pauvre a l'etat     */
/*                 riche                                                      */
/* !Number      :  FCT4.4                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Compteur_transition_sonde_amont;                              */
/*  output boolean Sonde_riche_amont;                                         */
/*  output uint8 Compteur_transition_sonde_amont;                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidLeanToRichSensor(void)
{
   uint8 u8LocalCompteur_transition_son;


   VEMS_vidSET(Sonde_riche_amont, 1);
   VEMS_vidGET(Compteur_transition_sonde_amont, u8LocalCompteur_transition_son);
   if (u8LocalCompteur_transition_son < 255)
   {
      u8LocalCompteur_transition_son = (uint8)( u8LocalCompteur_transition_son
                                              + 1);
      VEMS_vidSET(Compteur_transition_sonde_amont,
                  u8LocalCompteur_transition_son);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidRichToLeanSensor                                */
/* !Description :  Transition de la sonde amont de l'etat riche a l'etat      */
/*                 pauvre                                                     */
/* !Number      :  FCT4.5                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Compteur_transition_sonde_amont;                              */
/*  output boolean Sonde_riche_amont;                                         */
/*  output uint8 Compteur_transition_sonde_amont;                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidRichToLeanSensor(void)
{
   uint8 u8LocalCompteur_transition_son;


   VEMS_vidSET(Sonde_riche_amont, 0);
   VEMS_vidGET(Compteur_transition_sonde_amont, u8LocalCompteur_transition_son);
   if (u8LocalCompteur_transition_son < 255)
   {
      u8LocalCompteur_transition_son = (uint8)( u8LocalCompteur_transition_son
                                               + 1);
      VEMS_vidSET(Compteur_transition_sonde_amont,
                  u8LocalCompteur_transition_son);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsFreeze                                   */
/* !Description :  Etat pauvre mesuré par la sonde                            */
/* !Number      :  FCT4.6                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sonde_riche_amont;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsFreeze(void)
{
   VEMS_vidSET(Sonde_riche_amont, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidExtremeSenO2VoltMngt                            */
/* !Description :  Management des tensions extremums de la sondes amont       */
/* !Number      :  FCT4.7                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input boolean DC_bSyncGlbDC;                                              */
/*  input uint16 Tension_sonde_am_max_dc;                                     */
/*  input uint16 Tension_sonde_am_min_dc;                                     */
/*  output uint16 Tension_sonde_am_max_dc;                                    */
/*  output uint16 Tension_sonde_am_min_dc;                                    */
/*  output uint16 Tension_sonde_am_max_cycle;                                 */
/*  output uint16 Tension_sonde_am_min_cycle;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidExtremeSenO2VoltMngt(void)
{
   uint16  u16LocalTension_sonde_amont;
   boolean bLocalDC_bSyncGlbDC;


   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   VEMS_vidGET(DC_bSyncGlbDC, bLocalDC_bSyncGlbDC);
   if (u16LocalTension_sonde_amont > Tension_sonde_am_max_dc)
   {
      Tension_sonde_am_max_dc =
         (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont, 1023);
   }
   else
   {
      Tension_sonde_am_max_dc =
         (uint16)MATHSRV_udtMIN(Tension_sonde_am_max_dc, 1023);
   }
   if (u16LocalTension_sonde_amont < Tension_sonde_am_min_dc)
   {
      Tension_sonde_am_min_dc =
         (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont, 1023);
   }
   else
   {
      Tension_sonde_am_min_dc =
         (uint16)MATHSRV_udtMIN(Tension_sonde_am_min_dc, 1023);
   }
   if (bLocalDC_bSyncGlbDC != 0)
   {
      VEMS_vidSET(Tension_sonde_am_max_cycle, Tension_sonde_am_max_dc);
      VEMS_vidSET(Tension_sonde_am_min_cycle, Tension_sonde_am_min_dc);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidNoFaultSenO2VoltMngt                            */
/* !Description :  Management de la tension sonde sans defaut                 */
/* !Number      :  FCT4.8                                                     */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_sonde_amont_filtree;                                 */
/*  input uint16 Up_oxy_test_bed_voltage_v;                                   */
/*  input boolean Up_oxy_cfg_test_bed_enable_c0;                              */
/*  output uint16 Tension_sonde_amont;                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidNoFaultSenO2VoltMngt(void)
{
   uint16 u16LocalTension_sonde_amont_filt;
   uint16 u16LocalUp_oxy_test_bed_voltage;
   uint16 u16LocalTension_sond_amont;


   VEMS_vidGET(Tension_sonde_amont_filtree, u16LocalTension_sonde_amont_filt);
   VEMS_vidGET(Up_oxy_test_bed_voltage_v, u16LocalUp_oxy_test_bed_voltage);

   if (Up_oxy_cfg_test_bed_enable_c0 != 0)
   {
      u16LocalTension_sond_amont =
         (uint16)MATHSRV_udtMIN(u16LocalUp_oxy_test_bed_voltage, 1023);
      VEMS_vidSET(Tension_sonde_amont, u16LocalTension_sond_amont);
   }
   else
   {
      if (u16LocalTension_sonde_amont_filt <= 1023)
      {
         VEMS_vidSET(Tension_sonde_amont, u16LocalTension_sonde_amont_filt);
      }
      else
      {
         VEMS_vidSET(Tension_sonde_amont, 1023);
      }
   }
}
/*------------------------------- end of file --------------------------------*/