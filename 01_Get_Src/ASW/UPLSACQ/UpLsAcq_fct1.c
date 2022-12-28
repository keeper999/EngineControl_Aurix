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
/* !File            : UPLSACQ_fct1.C                                          */
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
/*   1 / UPLSACQ_vidInitOutput                                                */
/*   2 / UPLSACQ_vidSenO2UsInitialization                                     */
/*   3 / UPLSACQ_vidSenO2UsAcquiTreatment                                     */
/*   4 / UPLSACQ_vidInitDeadZoneCount                                         */
/*   5 / UPLSACQ_vidSenO2UsDefaultMngt                                        */
/*   6 / UPLSACQ_vidRunKeyOff                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6562315 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/UPLSACQ/UPLSACQ_FCT1.c_v          $*/
/* $Revision::   1.7      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "UPLSACQ.H"
#include "UPLSACQ_L.H"
#include "UPLSACQ_IM.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidInitOutput                                      */
/* !Description :  Initialisation des variables produites dans ce module      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Compteur_transition_sonde_amont;                             */
/*  output boolean Sonde_riche_amont;                                         */
/*  output uint16 Tension_sonde_amont;                                        */
/*  output uint16 Tension_sonde_amont_brute;                                  */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev1;                             */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev2;                             */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev3;                             */
/*  output boolean UPLSACQ_bFiltSondeEnablePrev;                              */
/*  output uint32 UPLSACQ_u32FiltredVoltageMem;                               */
/*  output uint16 UPLSACQ_u16SenO2UsFiltred;                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidInitOutput(void)
{
   /* Initialisation des variables de sortie */
   VEMS_vidSET(Compteur_transition_sonde_amont, 0);
   VEMS_vidSET(Sonde_riche_amont, 0);
   VEMS_vidSET(Tension_sonde_amont, 0);
   VEMS_vidSET(Tension_sonde_amont_brute, 0);

   /* Initialisation des variables internes */
   UPLSACQ_u16SenO2UsVoltagePrev1 = 0;
   UPLSACQ_u16SenO2UsVoltagePrev2 = 0;
   UPLSACQ_u16SenO2UsVoltagePrev3 = 0;
   UPLSACQ_bFiltSondeEnablePrev = 0;

   /* Initialisation des variables du filtre */
   UPLSACQ_u32FiltredVoltageMem = 0;
   UPLSACQ_u16SenO2UsFiltred = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsInitialization                           */
/* !Description :  Initialisation des variables internes et des sortie du     */
/*                 module                                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Inhibe_extrema_sonde_count;                                 */
/*  output boolean Tension_so2_am_first_computed;                             */
/*  output uint16 Tension_sonde_am_max_dc;                                    */
/*  output uint16 Tension_sonde_am_min_dc;                                    */
/*  output uint16 Tension_sonde_amont_filtree;                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsInitialization(void)
{
   VEMS_vidSET(Inhibe_extrema_sonde_count, 0);
   Tension_so2_am_first_computed = 0;
   Tension_sonde_am_max_dc = 0;
   Tension_sonde_am_min_dc = 1023;
   VEMS_vidSET(Tension_sonde_amont_filtree, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsAcquiTreatment                           */
/* !Description :  Run Sonde à oxigène amont                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf argret void UPLSACQ_vidSenO2UsManagement();                          */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Ext_bDgoScp_uUpLs;                                          */
/*  input boolean Ext_bDgoScg_uUpLs;                                          */
/*  input boolean Ext_bDgoOc_uUpLs;                                           */
/*  output boolean Ext_bMonRunScp_uUpLs;                                      */
/*  output boolean Panne_so2_am_presente;                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsAcquiTreatment(void)
{
   boolean bLocalInhUpLsAcqDiagEl;
   boolean bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   bLocalInhUpLsAcqDiagEl = GDGAR_bGetFRM(FRM_FRM_INHUPLSACQDIAGEL);
   if (  (bLocalInhUpLsAcqDiagEl == 0)
      && (bLocalClef_de_contact != 0))
   {
      Ext_bMonRunScp_uUpLs = 1;
   }
   else
   {
      Ext_bMonRunScp_uUpLs = 0;
   }
   if (  (Ext_bDgoScp_uUpLs != 0)
      || (Ext_bDgoScg_uUpLs != 0)
      || (Ext_bDgoOc_uUpLs != 0))
   {
      Panne_so2_am_presente = 1;
   }
   else
   {
      Panne_so2_am_presente = 0;
   }
   if (bLocalClef_de_contact != 0)
   {
      UPLSACQ_vidSenO2UsManagement();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidInitDeadZoneCount                               */
/* !Description :  Initialisation de Compteur d'occurrences pendant lesquelles*/
/*                 la tension sonde est dans la bande morte de détection CO   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsen_active_dead_zone_delay;                                */
/*  output uint16 Ldsen_sensor_dead_zone_count;                               */
/*  output uint16 Ldsen_active_dead_zone_count;                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidInitDeadZoneCount(void)
{
   Ldsen_sensor_dead_zone_count = 0;
   Ldsen_active_dead_zone_count = Ldsen_active_dead_zone_delay;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsDefaultMngt                              */
/* !Description :  Management du defaut de sonde amont                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_006.01                                     */
/*                 VEMS_R_08_04819_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf argret void UPLSACQ_vidSenO2UsDefault();                             */
/*  input uint8 Temperature_eau;                                              */
/*  input st23 Vehicle_active_state;                                          */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Ldsen_active_dead_zone_temp;                                  */
/*  input uint16 Ldsen_active_dead_zone_count;                                */
/*  input boolean Ext_bDgoOc_uUpLs;                                           */
/*  input boolean Ext_bDgoScg_uUpLs;                                          */
/*  input boolean Ext_bDgoScp_uUpLs;                                          */
/*  output boolean Ext_bMonWaitOc_uUpLs;                                      */
/*  output boolean Ext_bMonRunOc_uUpLs;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsDefaultMngt(void)
{
   boolean bLocalInhSenO2UsFuRatTran;
   boolean bLocalInhUpLsAcqDiagEl;
   boolean bLocalData;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalEngine_running_state;


   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   Ext_bMonWaitOc_uUpLs = 0;
   bLocalInhSenO2UsFuRatTran = GDGAR_bGetFRM(FRM_FRM_INHSENO2USFURATTRAN);
   bLocalInhUpLsAcqDiagEl = GDGAR_bGetFRM(FRM_FRM_INHUPLSACQDIAGEL);

   if (  (u8LocalTemperature_eau > Ldsen_active_dead_zone_temp)
      && (u8LocalEngine_running_state != ERUN_FULL_LOAD)
      && (Ldsen_active_dead_zone_count == 0)
      && (u8LocalVehicle_active_state == VS_RUNNING))
   {
      bLocalData = 1;
   }
   else
   {
      bLocalData = 0;
   }

   if (  (bLocalData != 0)
      && (Ext_bDgoOc_uUpLs == 0)
      && (Ext_bDgoScg_uUpLs == 0)
      && (Ext_bDgoScp_uUpLs == 0)
      && (bLocalInhSenO2UsFuRatTran == 0)
      && (bLocalInhUpLsAcqDiagEl == 0))
   {
      Ext_bMonRunOc_uUpLs = 1;
      UPLSACQ_vidSenO2UsDefault();
   }
   else
   {
      Ext_bMonRunOc_uUpLs = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidRunKeyOff                                       */
/* !Description :  Run clef off                                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void UPLSACQ_vidSenO2StateKeyOff();                           */
/*  input boolean Clef_de_contact;                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidRunKeyOff(void)
{
   boolean bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   if (bLocalClef_de_contact == 0)
   {
      UPLSACQ_vidSenO2StateKeyOff();
   }
}

/*------------------------------- end of file --------------------------------*/