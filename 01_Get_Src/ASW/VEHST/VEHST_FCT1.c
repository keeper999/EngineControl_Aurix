/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHST                                                   */
/* !Description     : VEHST component.                                        */
/*                                                                            */
/* !Module          : VEHST                                                   */
/* !Description     : ETAT VEHICULE                                           */
/*                                                                            */
/* !File            : VEHST_FCT1.C                                            */
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
/*   1 / VEHST_vidCompThr                                                     */
/*   2 / VEHST_vidVehStateControl                                             */
/*   3 / VEHST_vidManageEngineStalled                                         */
/*   4 / VEHST_vidManageEngineCranking                                        */
/*   5 / VEHST_vidManageEngineRunning                                         */
/*   6 / VEHST_vidInitStart                                                   */
/*   7 / VEHST_vidStartCondition                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5404370 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VEHST/VEHST_FCT1.C_v              $*/
/* $Revision::   1.8      $$Author::   hmelloul       $$Date::   16 Jul 2013 $*/
/* $Author::   hmelloul                               $$Date::   16 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "VEHST.H"
#include "VEHST_l.H"
#include "VEHST_IM.H"
#include "SWFAIL.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHST_vidCompThr                                           */
/* !Description :  Les seuils Crank_to_run_engine_rpm_low et                  */
/*                 Crank_to_run_engine_rpm_high sont calculés sur la          */
/*                 transition Moteur_tournant, aussi en interpolant les       */
/*                 variables : coefficient de qualité carburant et température*/
/*                 eau sur une cartographie 2D.                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 FISA_facAdp;                                                  */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint8 FISA_Enrich_facAdpY_A[5];                                     */
/*  input uint8 Crank_to_run_engine_rpm_low_map[16][5];                       */
/*  input uint8 Crank_to_run_engine_rpm_high_map[16][5];                      */
/*  output uint8 Crank_to_run_engine_rpm_low;                                 */
/*  output uint8 Crank_to_run_engine_rpm_high;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHST_vidCompThr(void)
{
   uint8  u8LocalFISAfacAdp;
   uint8  u8LocalTemperatureeau;
   uint8  u8LocalVehicleactivestate;
   uint16 u16LocalVEHSTPara1;
   uint16 u16LocalVEHSTPara2;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicleactivestate);
   VEMS_vidGET(FISA_facAdp, u8LocalFISAfacAdp);
   VEMS_vidGET(Temperature_eau, u8LocalTemperatureeau);
   u16LocalVEHSTPara1 = MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                                    u8LocalTemperatureeau,
                                                    16);
   u16LocalVEHSTPara2 = MATHSRV_u16CalcParaIncAryU8(FISA_Enrich_facAdpY_A,
                                                    u8LocalFISAfacAdp,
                                                    5);

   if (u8LocalVehicleactivestate == VS_RUNNING)
   {
      Crank_to_run_engine_rpm_low =
         MATHSRV_u8Interp2d(&Crank_to_run_engine_rpm_low_map[0][0],
                            u16LocalVEHSTPara1,
                            u16LocalVEHSTPara2,
                            5);
   }
   else
   {
      if (u8LocalVehicleactivestate == VS_CRANKING)
      {
         Crank_to_run_engine_rpm_high =
            MATHSRV_u8Interp2d(&Crank_to_run_engine_rpm_high_map[0][0],
                               u16LocalVEHSTPara1,
                               u16LocalVEHSTPara2,
                               5);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHST_vidVehStateControl                                   */
/* !Description :  Fonction de commande de l'état véhicule                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHST_vidManageEngineRunning();                          */
/*  extf argret void VEHST_vidManageEngineStalled();                          */
/*  extf argret void VEHST_vidManageEngineCranking();                         */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Eng_stEru;                                                    */
/*  output st23 Vehicle_active_state;                                         */
/*  output boolean Ext_bAcvInjSys;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHST_vidVehStateControl(void)
{
   uint8  u8LocalVehicleactivestate;
   uint8  u8LocalEngStEru;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicleactivestate);

   switch (u8LocalVehicleactivestate)
   {
   case VS_RUNNING:
      VEHST_vidManageEngineRunning();
      break;

   case VS_STALL:
      VEHST_vidManageEngineStalled();
      break;

   case VS_CRANKING:
      VEHST_vidManageEngineCranking();
      break;

   default:
      SWFAIL_vidSoftwareErrorHook();
      VEMS_vidSET(Vehicle_active_state,VS_STALL);
      break;
   }

   VEMS_vidGET(Eng_stEru, u8LocalEngStEru);
   if (u8LocalEngStEru == Ext_stRun_SC)
   {
      VEMS_vidSET(Ext_bAcvInjSys, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcvInjSys, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHST_vidManageEngineStalled                               */
/* !Description :  Fonction qui permet le traitement de l'état STALL.         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EngSt_EveStTCr_VehSt();                                  */
/*  input boolean Moteur_tournant;                                            */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Compteur_de_pmh;                                             */
/*  output st23 Vehicle_active_state;                                         */
/*  output uint16 Initial_vs_crank_tdc_count;                                 */
/*  output uint8 Eng_stEru;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHST_vidManageEngineStalled(void)
{
   boolean bLocalMoteurtournant;
   uint8   u8LocalPowerconditionsstate;
   uint8   u8LocalVehicleactivestate;
   uint16  u16LocalCompteurdepmh;


   VEMS_vidGET(Moteur_tournant, bLocalMoteurtournant);
   VEMS_vidGET(Power_conditions_state, u8LocalPowerconditionsstate);
   VEMS_vidGET(Compteur_de_pmh, u16LocalCompteurdepmh);

   if ((u8LocalPowerconditionsstate == POWER_ON)
      && (bLocalMoteurtournant != 0))
   {
      u8LocalVehicleactivestate = VS_CRANKING;
      VEMS_vidSET(Vehicle_active_state, u8LocalVehicleactivestate);
      Initial_vs_crank_tdc_count = u16LocalCompteurdepmh;
      VEMS_vidSET(Eng_stEru, Ext_stCrk_SC);
      /* EngSt_EveStTCr_VehSt*/
      EngSt_EveStTCr_VehSt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHST_vidManageEngineCranking                              */
/* !Description :  Fonction qui permet le traitement de l'état CRANKING       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void EngSt_EveCrTSt_VehSt();                                  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EngSt_EveCrTR_VehSt();                                   */
/*  input boolean Moteur_tournant;                                            */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Compteur_de_pmh;                                             */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Crank_to_run_engine_rpm_high;                                 */
/*  input uint16 Initial_vs_crank_tdc_count;                                  */
/*  input uint8 Crank_exit_delay;                                             */
/*  output uint8 Eng_stEru;                                                   */
/*  output st23 Vehicle_active_state;                                         */
/*  output uint16 Initial_vs_crank_tdc_count;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHST_vidManageEngineCranking(void)
{
   boolean bLocalMoteurtournant;
   uint8   u8LocalPowerconditionsstate;
   uint8   u8LocalVehicleactivestate;
   uint16  u16LocalCompteurdepmh;
   uint16  u16LocalRegimemoteur;


   VEMS_vidGET(Moteur_tournant, bLocalMoteurtournant);
   VEMS_vidGET(Power_conditions_state, u8LocalPowerconditionsstate);
   VEMS_vidGET(Compteur_de_pmh, u16LocalCompteurdepmh);
   VEMS_vidGET(Regime_moteur, u16LocalRegimemoteur);


   if (  (u8LocalPowerconditionsstate == WAITING_FOR_POWER_LATCH_DELAY)
      || (bLocalMoteurtournant == 0)  )
   {
      /*EngSt_EveCrTSt_VehSt*/
      EngSt_EveCrTSt_VehSt();
      u8LocalVehicleactivestate = VS_STALL;
      VEMS_vidSET(Eng_stEru, Ext_stStall_SC);
      VEMS_vidSET(Vehicle_active_state, u8LocalVehicleactivestate);
   }
   else
   {
      if (u16LocalRegimemoteur >= (4 * Crank_to_run_engine_rpm_high))
      {
         if ( (u8LocalPowerconditionsstate == POWER_ON)
            &&((u16LocalCompteurdepmh - Initial_vs_crank_tdc_count)
               >= Crank_exit_delay))
         {
            u8LocalVehicleactivestate = VS_RUNNING;
            /*EngSt_EveCrTR_VehSt*/
            EngSt_EveCrTR_VehSt();
            VEMS_vidSET(Vehicle_active_state, u8LocalVehicleactivestate);
            VEMS_vidSET(Eng_stEru, Ext_stRun_SC);
         }
      }
      else
      {
         Initial_vs_crank_tdc_count = u16LocalCompteurdepmh;
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHST_vidManageEngineRunning                               */
/* !Description :  Fonction qui permet le traitement de l'état RUNNING        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void EngSt_EveRTCr_VehSt();                                   */
/*  input boolean Moteur_tournant;                                            */
/*  input st08 Power_conditions_state;                                        */
/*  input uint16 Compteur_de_pmh;                                             */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Crank_to_run_engine_rpm_low;                                  */
/*  input boolean Manu_inh_run_to_crank;                                      */
/*  output st23 Vehicle_active_state;                                         */
/*  output uint8 Eng_stEru;                                                   */
/*  output uint16 Initial_vs_crank_tdc_count;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHST_vidManageEngineRunning(void)
{
   boolean bLocalMoteurtournant;
   uint8   u8LocalPowerconditionsstate;
   uint8   u8LocalVehicleactivestate;
   uint16  u16LocalCompteurdepmh;
   uint16  u16LocalRegimemoteur;


   VEMS_vidGET(Moteur_tournant, bLocalMoteurtournant);
   VEMS_vidGET(Power_conditions_state, u8LocalPowerconditionsstate);
   VEMS_vidGET(Compteur_de_pmh, u16LocalCompteurdepmh);
   VEMS_vidGET(Regime_moteur, u16LocalRegimemoteur);

   if (  (u8LocalPowerconditionsstate == WAITING_FOR_POWER_LATCH_DELAY)
      || (bLocalMoteurtournant == 0))
   {
      u8LocalVehicleactivestate = VS_STALL;
      VEMS_vidSET(Vehicle_active_state, u8LocalVehicleactivestate);
      VEMS_vidSET(Eng_stEru, Ext_stStall_SC);
   }
   else
   {
      if (u16LocalRegimemoteur < (4 * Crank_to_run_engine_rpm_low))
      {
         u8LocalVehicleactivestate = VS_CRANKING;
         Initial_vs_crank_tdc_count = u16LocalCompteurdepmh;
         VEMS_vidSET(Vehicle_active_state, u8LocalVehicleactivestate);
         VEMS_vidSET(Eng_stEru, Ext_stCrk_SC);
         if (Manu_inh_run_to_crank == 0)
         {
            /*EngSt_EveRTCr_VehSt*/
            EngSt_EveRTCr_VehSt();
         }
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHST_vidInitStart                                         */
/* !Description :  Initialisation des variables produites.                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st23 Vehicle_active_state;                                         */
/*  output uint8 Eng_stEru;                                                   */
/*  output boolean EngSt_CrkIp;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHST_vidInitStart(void)
{
   VEMS_vidSET(Vehicle_active_state, VS_STALL);
   VEMS_vidSET(Eng_stEru, Ext_stStall_SC);
   VEMS_vidSET(EngSt_CrkIp, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHST_vidStartCondition                                    */
/* !Description :  Ce bloc permet de déterminer si un démarrage est en cours  */
/*                 et sert principalement à la fonction de délestage gérée par*/
/*                 le BSI.                                                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Moteur_tournant;                                            */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Demarrage_en_cours_delay;                                     */
/*  input uint8 Demarrage_en_cours_counter;                                   */
/*  output uint8 Demarrage_en_cours_counter;                                  */
/*  output boolean EngSt_CrkIp;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHST_vidStartCondition(void)
{
   boolean bLocalMoteurtournant;
   boolean bLocalEngStCrkIp;
   uint8   u8LocalVehicleactivestate;
   sint16  s16LocalCounter;


   VEMS_vidGET(Moteur_tournant, bLocalMoteurtournant);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicleactivestate);

   if (u8LocalVehicleactivestate != VS_RUNNING)
   {
      Demarrage_en_cours_counter = Demarrage_en_cours_delay;
   }
   else
   {
      s16LocalCounter = (sint16)(Demarrage_en_cours_counter - 1);
      Demarrage_en_cours_counter = (uint8)(MATHSRV_udtMAX(s16LocalCounter,0));
   }

   if (bLocalMoteurtournant == 0)
   {
      bLocalEngStCrkIp = 0;
   }
   else
   {
      if (u8LocalVehicleactivestate != VS_RUNNING)
      {
         bLocalEngStCrkIp = 1;
      }
      else
      {
         if (Demarrage_en_cours_counter == 0)
         {
            bLocalEngStCrkIp = 0;
         }
         else
         {
            bLocalEngStCrkIp = 1;
         }
      }
   }
   VEMS_vidSET(EngSt_CrkIp, bLocalEngStCrkIp);
}

/*------------------------------- end of file --------------------------------*/