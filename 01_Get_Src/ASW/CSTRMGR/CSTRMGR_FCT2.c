/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRMGR                                                 */
/* !Description     : CSTRMGR Component                                       */
/*                                                                            */
/* !Module          : CSTRMGR                                                 */
/* !Description     : Calcul de la consigne d_ouverture de la purge.          */
/*                                                                            */
/* !File            : CSTRMGR_FCT2.C                                          */
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
/*   1 / CSTRMGR_vidPurgeControlState                                         */
/*   2 / CSTRMGR_vidPurgeClosedTrans                                          */
/*   3 / CSTRMGR_vidPurgeMinTrans                                             */
/*   4 / CSTRMGR_vidFullLoadTrans                                             */
/*   5 / CSTRMGR_vidNormalBoundingTrans                                       */
/*   6 / CSTRMGR_vidPurgeHoldingTrans                                         */
/*   7 / CSTRMGR_vidLambdaPurgeClosTrans                                      */
/*   8 / CSTRMGR_vidGsmPurgeClosingTrans                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 01858 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTR/CSTRMGR/CSTRMGR_FCT2.C_v     $*/
/* $Revision::   1.4      $$Author::   achebino       $$Date::   19 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   19 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "CSTRMGR.H"
#include "CSTRMGR_L.H"
#include "CSTRMGR_IM.H"
#include "GDGAR.H"
#include "VEMS.H"
#include "SWFAIL.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidPurgeControlState                               */
/* !Description :  Fonction de l'automate de gestion de la purge              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CSTRMGR_vidPurgeClosedTrans();                           */
/*  extf argret void CSTRMGR_vidPurgeMinTrans();                              */
/*  extf argret void CSTRMGR_vidFullLoadTrans();                              */
/*  extf argret void CSTRMGR_vidNormalBoundingTrans();                        */
/*  extf argret void CSTRMGR_vidPurgeHoldingTrans();                          */
/*  extf argret void CSTRMGR_vidLambdaPurgeClosTrans();                       */
/*  extf argret void CSTRMGR_vidGsmPurgeClosingTrans();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st66 Cpc_purge_control_state;                                       */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidPurgeControlState(void)
{
   uint8 u8LocalCpc_purge_control_state;


   VEMS_vidGET(Cpc_purge_control_state, u8LocalCpc_purge_control_state);
   switch(u8LocalCpc_purge_control_state)
   {
      case CPC_PURGE_CLOSED:
         CSTRMGR_vidPurgeClosedTrans();
      break;

      case CPC_PURGE_MIN:
         CSTRMGR_vidPurgeMinTrans();
      break;

      case CPC_FULL_LOAD:
         CSTRMGR_vidFullLoadTrans();
      break;

      case CPC_NORMAL_BOUNDING:
         CSTRMGR_vidNormalBoundingTrans();
      break;

      case CPC_PURGE_HOLDING:
         CSTRMGR_vidPurgeHoldingTrans();
      break;

      case CPC_LAMBDA_PURGE_CLOSING:
         CSTRMGR_vidLambdaPurgeClosTrans();
      break;

      case CPC_GSM_PURGE_CLOSING:
         CSTRMGR_vidGsmPurgeClosingTrans();
      break;

      default:
         VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_CLOSED);
         Rco_demande_purge_nom = 0;
         Demande_purge_dormant_nom = 1;
         VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
         SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidPurgeClosedTrans                                */
/* !Description :  Fonction de transition de l'etat PURGE_CLOSED              */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Gsm_closed_cpc_request;                                     */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  input uint8 Temperature_eau;                                              */
/*  input sint16 Cpc_water_temp_thresh;                                       */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean CSTRMGR_open_loop_min_purge_req;                            */
/*  input uint8 Cpc_min_purge_rco;                                            */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Cpc_full_load_purge_rco;                                      */
/*  input boolean Conditions_for_feedback;                                    */
/*  input boolean Dv_detection_pied_leve_final;                               */
/*  input boolean Manage_isc_closed_loop;                                     */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidPurgeClosedTrans(void)
{
   boolean bLocalInhCstr;
   boolean bLocalGsm_closed_cpc_request;
   boolean bLocalOxC_bMonRunORngIntr;
   boolean bLocalConditions_for_feedback;
   boolean bLocalDv_det_pied_leve_final;
   boolean bLocalManage_isc_closed_loop;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalEngine_running_state;


   bLocalInhCstr = GDGAR_bGetFRM(FRM_FRM_INHCSTR);
   VEMS_vidGET(Gsm_closed_cpc_request, bLocalGsm_closed_cpc_request);
   VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);

   if (  (bLocalInhCstr == 0)
      && (bLocalGsm_closed_cpc_request == 0)
      && (bLocalOxC_bMonRunORngIntr == 0))
   {
      VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);

      if (u8LocalTemperature_eau > (Cpc_water_temp_thresh + 64))
      {
         VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);

         if (CSTRMGR_open_loop_min_purge_req != 0)
         {
            if (u8LocalVehicle_active_state == VS_RUNNING)
            {
               Demande_purge_dormant_nom = 0;
               VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_MIN);
               Rco_demande_purge_nom = Cpc_min_purge_rco;
               VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
            }
         }
         else
         {
            VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);

            if (u8LocalEngine_running_state == ERUN_FULL_LOAD)
            {
               Demande_purge_dormant_nom = 0;
               VEMS_vidSET(Cpc_purge_control_state, CPC_FULL_LOAD);
               Rco_demande_purge_nom = Cpc_full_load_purge_rco;
               VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
            }
            else
            {
               VEMS_vidGET(Conditions_for_feedback,
                           bLocalConditions_for_feedback);
               VEMS_vidGET(Dv_detection_pied_leve_final,
                           bLocalDv_det_pied_leve_final);
               VEMS_vidGET(Manage_isc_closed_loop,
                           bLocalManage_isc_closed_loop);

               if (  (u8LocalVehicle_active_state == VS_RUNNING)
                  && (bLocalConditions_for_feedback != 0)
                  && (  (bLocalDv_det_pied_leve_final == 0)
                     || (bLocalManage_isc_closed_loop != 0)))
               {
                  Demande_purge_dormant_nom = 0;
                  VEMS_vidSET(Cpc_purge_control_state, CPC_NORMAL_BOUNDING);
                  VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidPurgeMinTrans                                   */
/* !Description :  Fonction de transition de l'etat PURGE_MIN                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Gsm_closed_cpc_request;                                     */
/*  input boolean Gsm_cpc_slow_closing_choice;                                */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean CSTRMGR_open_loop_min_purge_req;                            */
/*  input sint16 Cpc_water_temp_thresh;                                       */
/*  input st07 Engine_running_state;                                          */
/*  input boolean Conditions_for_feedback;                                    */
/*  input boolean Dv_detection_pied_leve_final;                               */
/*  input boolean Manage_isc_closed_loop;                                     */
/*  input uint8 Cpc_full_load_purge_rco;                                      */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidPurgeMinTrans(void)
{
   boolean bLocalInhCstr;
   boolean bLocalGsm_closed_cpc_request;
   boolean bLocalGsm_cpc_slow_clos_choice;
   boolean bLocalConditions_for_feedback;
   boolean bLocalDv_det_pied_leve_final;
   boolean bLocalManage_isc_closed_loop;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalEngine_running_state;


   bLocalInhCstr = GDGAR_bGetFRM(FRM_FRM_INHCSTR);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Gsm_closed_cpc_request, bLocalGsm_closed_cpc_request);
   VEMS_vidGET(Gsm_cpc_slow_closing_choice, bLocalGsm_cpc_slow_clos_choice);

   if (  (u8LocalVehicle_active_state != VS_RUNNING)
      || (bLocalInhCstr != 0)
      || (  (bLocalGsm_closed_cpc_request != 0)
         && (bLocalGsm_cpc_slow_clos_choice == 0)))
   {
      VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_CLOSED);
      Demande_purge_dormant_nom = 1;
      Rco_demande_purge_nom = 0;
      VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
   }
   else
   {
      VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);

      if (  (CSTRMGR_open_loop_min_purge_req == 0)
         && (u8LocalTemperature_eau > (Cpc_water_temp_thresh + 64))
         && (bLocalGsm_closed_cpc_request == 0))
      {
         VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);

         if (u8LocalEngine_running_state != ERUN_FULL_LOAD)
         {
            VEMS_vidGET(Conditions_for_feedback, bLocalConditions_for_feedback);
            VEMS_vidGET(Dv_detection_pied_leve_final,
                        bLocalDv_det_pied_leve_final);
            VEMS_vidGET(Manage_isc_closed_loop, bLocalManage_isc_closed_loop);

            if (  (bLocalConditions_for_feedback != 0)
               && (  (bLocalDv_det_pied_leve_final == 0)
                  || (bLocalManage_isc_closed_loop != 0)))
            {
               VEMS_vidSET(Cpc_purge_control_state, CPC_NORMAL_BOUNDING);
               VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
            }
         }
         else
         {
            VEMS_vidSET(Cpc_purge_control_state, CPC_FULL_LOAD);
            Rco_demande_purge_nom = Cpc_full_load_purge_rco;
            VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidFullLoadTrans                                   */
/* !Description :  Fonction de transition de l'etat FULL_LOAD                 */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st07 Engine_running_state;                                          */
/*  input boolean Gsm_closed_cpc_request;                                     */
/*  input boolean Gsm_cpc_slow_closing_choice;                                */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidFullLoadTrans(void)
{
   boolean bLocalInhCstr;
   boolean bLocalGsm_closed_cpc_request;
   boolean bLocalGsm_cpc_slow_clos_choice;
   uint8   u8LocalEngine_running_state;


   bLocalInhCstr = GDGAR_bGetFRM(FRM_FRM_INHCSTR);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Gsm_closed_cpc_request, bLocalGsm_closed_cpc_request);
   VEMS_vidGET(Gsm_cpc_slow_closing_choice, bLocalGsm_cpc_slow_clos_choice);

   if (  (u8LocalEngine_running_state != ERUN_FULL_LOAD)
      || (bLocalInhCstr != 0)
      || (  (bLocalGsm_closed_cpc_request != 0)
         && (bLocalGsm_cpc_slow_clos_choice == 0)))
   {
      VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_CLOSED);
      Demande_purge_dormant_nom = 1;
      Rco_demande_purge_nom = 0;
      VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
   }
   else
   {
      if (bLocalGsm_closed_cpc_request != 0)
      {
         VEMS_vidSET(Cpc_purge_control_state, CPC_GSM_PURGE_CLOSING);
         VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidNormalBoundingTrans                             */
/* !Description :  Fonction de transition de l'etat NORMAL_BOUNDING           */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Gsm_closed_cpc_request;                                     */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Gsm_cpc_slow_closing_choice;                                */
/*  input boolean Conditions_for_feedback;                                    */
/*  input boolean CSTRMGR_open_loop_min_purge_req;                            */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  input uint8 Cpc_min_purge_rco;                                            */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 Cpc_full_load_purge_rco;                                      */
/*  input sint16 Lambda_feedback;                                             */
/*  input uint8 Cpc_purge_inh_low_lambda_thresh;                              */
/*  input uint16 Cpc_constraints_max_purge_ratio;                             */
/*  input uint16 Cpc_current_purge_ratio;                                     */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*  output uint16 Cpc_control_purge_ratio;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidNormalBoundingTrans(void)
{
   boolean bLocalInhCstr;
   boolean bLocalGsm_closed_cpc_request;
   boolean bLocalGsm_cpc_slow_clos_choice;
   boolean bLocalConditions_for_feedback;
   boolean bLocalOxC_bMonRunORngIntr;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalEngine_running_state;
   sint16  s16LocalLambda_feedback;
   uint16  u16LocalCpc_cons_max_purge_ratio;
   uint16  u16LocalCpc_current_purge_ratio;

   bLocalInhCstr = GDGAR_bGetFRM(FRM_FRM_INHCSTR);
   VEMS_vidGET(Gsm_closed_cpc_request, bLocalGsm_closed_cpc_request);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Gsm_cpc_slow_closing_choice, bLocalGsm_cpc_slow_clos_choice);
   VEMS_vidGET(Conditions_for_feedback, bLocalConditions_for_feedback);

   if (  (CSTRMGR_open_loop_min_purge_req == 0)
      && (  (u8LocalVehicle_active_state != VS_RUNNING)
         || (bLocalInhCstr != 0)
         || (  (bLocalGsm_closed_cpc_request != 0)
            && (bLocalGsm_cpc_slow_clos_choice == 0))
         || (bLocalConditions_for_feedback == 0)))
   {
      VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_CLOSED);
      Demande_purge_dormant_nom = 1;
      Rco_demande_purge_nom = 0;
      VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
   }
   else
   {
      if (bLocalGsm_closed_cpc_request == 0)
      {
         VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);

         if (  (bLocalInhCstr == 0)
            && (bLocalOxC_bMonRunORngIntr == 0)
            && (CSTRMGR_open_loop_min_purge_req != 0))
         {
            VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_MIN);
            Rco_demande_purge_nom = Cpc_min_purge_rco;
            VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
         }
         else
         {
            VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);

            if (u8LocalEngine_running_state == ERUN_FULL_LOAD)
            {
               if (  (u8LocalVehicle_active_state == VS_RUNNING)
                  && (CSTRMGR_open_loop_min_purge_req == 0)
                  && (bLocalInhCstr == 0))
               {
                  VEMS_vidSET(Cpc_purge_control_state, CPC_FULL_LOAD);
                  Rco_demande_purge_nom = Cpc_full_load_purge_rco;
                  VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
               }
            }
            else
            {
               VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);

               if (  (  MATHSRV_udtABS(s16LocalLambda_feedback)
                     >= (Cpc_purge_inh_low_lambda_thresh * 256))
                  || (bLocalOxC_bMonRunORngIntr != 0))
               {
                  VEMS_vidGET(Cpc_constraints_max_purge_ratio,
                              u16LocalCpc_cons_max_purge_ratio);
                  VEMS_vidGET(Cpc_current_purge_ratio,
                              u16LocalCpc_current_purge_ratio);

                  Cpc_control_purge_ratio =
                     (uint16)MATHSRV_udtMIN(u16LocalCpc_cons_max_purge_ratio,
                                           u16LocalCpc_current_purge_ratio);
                  VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_HOLDING);
                  VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
               }
            }
         }
      }
      else
      {
         if (bLocalGsm_cpc_slow_clos_choice != 0)
         {
            VEMS_vidSET(Cpc_purge_control_state, CPC_GSM_PURGE_CLOSING);
            VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidPurgeHoldingTrans                               */
/* !Description :  Fonction de transition de l'etat PURGE_HOLDING             */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Gsm_closed_cpc_request;                                     */
/*  input boolean Gsm_cpc_slow_closing_choice;                                */
/*  input boolean Conditions_for_feedback;                                    */
/*  input boolean CSTRMGR_open_loop_min_purge_req;                            */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  input uint8 Cpc_min_purge_rco;                                            */
/*  input sint16 Lambda_feedback;                                             */
/*  input uint16 Cpc_current_purge_ratio;                                     */
/*  input uint8 Cpc_purge_inh_high_lambda_thresh;                             */
/*  input uint8 Cpc_purge_inh_low_lambda_thresh;                              */
/*  input uint8 Cpc_diff_purge_ratio_thresh;                                  */
/*  input uint16 Cpc_constraints_max_purge_ratio;                             */
/*  input boolean CoEs_bAcvClsCanPurgSTTEs;                                   */
/*  input boolean Cpc_bAcvClsCanPurgSTTLbdaCdn_C;                             */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*  output uint16 Cpc_control_purge_ratio;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidPurgeHoldingTrans(void)
{
   boolean bLocalInhCstr;
   boolean bLocalGsm_closed_cpc_request;
   boolean bLocalGsm_cpc_slow_clos_choice;
   boolean bLocalConditions_for_feedback;
   boolean bLocalOxC_bMonRunORngIntr;
   boolean bLocalCoEs_bAcvClsCanPurgSTT;
   uint8   u8LocalVehicle_active_state;
   sint16  s16LocalLambda_feedback;
   uint16  u16Localratio;
   uint16  u16LocalthreshLo;
   uint16  u16LocalthreshHi;
   uint16  u16LocalCpc_current_purge_ratio;
   uint16  u16LocalCpc_cons_max_purge_ratio;
   uint32  u32Localratio;


   bLocalInhCstr = GDGAR_bGetFRM(FRM_FRM_INHCSTR);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Gsm_closed_cpc_request, bLocalGsm_closed_cpc_request);
   VEMS_vidGET(Gsm_cpc_slow_closing_choice, bLocalGsm_cpc_slow_clos_choice);
   VEMS_vidGET(Conditions_for_feedback, bLocalConditions_for_feedback);

   if (  (CSTRMGR_open_loop_min_purge_req == 0)
      && (  (u8LocalVehicle_active_state != VS_RUNNING)
         || (bLocalInhCstr != 0)
         || (  (bLocalGsm_closed_cpc_request != 0)
            && (bLocalGsm_cpc_slow_clos_choice == 0))
         || (bLocalConditions_for_feedback == 0)))
   {
      VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_CLOSED);
      Demande_purge_dormant_nom = 1;
      Rco_demande_purge_nom = 0;
      VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
   }
   else
   {
      VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);
      if (bLocalOxC_bMonRunORngIntr == 0)
      {
         if (  (CSTRMGR_open_loop_min_purge_req != 0)
            && (bLocalInhCstr == 0)
            && (bLocalGsm_closed_cpc_request == 0))
         {
            VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_MIN);
            Rco_demande_purge_nom = Cpc_min_purge_rco;
            VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
         }
         else
         {
            VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
            VEMS_vidGET(Cpc_current_purge_ratio,
                        u16LocalCpc_current_purge_ratio);
            u16LocalthreshHi =
                     (uint16)(Cpc_purge_inh_high_lambda_thresh * 256);

            if ( MATHSRV_udtABS(s16LocalLambda_feedback) <= u16LocalthreshHi)
            {
               if (  (bLocalGsm_closed_cpc_request != 0)
                  && (bLocalGsm_cpc_slow_clos_choice != 0))
               {
                  VEMS_vidSET(Cpc_purge_control_state, CPC_GSM_PURGE_CLOSING);
                  VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
               }
               else
               {
                  u16LocalthreshLo =
                     (uint16)(Cpc_purge_inh_low_lambda_thresh * 256);
                  u16Localratio = (uint16)(Cpc_diff_purge_ratio_thresh * 128);
                  VEMS_vidGET(Cpc_constraints_max_purge_ratio,
                              u16LocalCpc_cons_max_purge_ratio);
                  u32Localratio =
                     (uint32)(u16LocalCpc_cons_max_purge_ratio + u16Localratio);

                  if (  (bLocalGsm_closed_cpc_request == 0)
                     && (  ( MATHSRV_udtABS(s16LocalLambda_feedback)
                             < u16LocalthreshLo)
                        || (u16LocalCpc_current_purge_ratio > u32Localratio)))
                  {
                     VEMS_vidSET(Cpc_purge_control_state, CPC_NORMAL_BOUNDING);
                     VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
                  }
               }
            }
            else
            {
               VEMS_vidGET(CoEs_bAcvClsCanPurgSTTEs,
                           bLocalCoEs_bAcvClsCanPurgSTT);
               if (  (Cpc_bAcvClsCanPurgSTTLbdaCdn_C == 0)
                  || (bLocalCoEs_bAcvClsCanPurgSTT == 0))
               {
                  VEMS_vidSET(Cpc_purge_control_state,
                              CPC_LAMBDA_PURGE_CLOSING);
                  Cpc_control_purge_ratio = u16LocalCpc_current_purge_ratio;
                  VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidLambdaPurgeClosTrans                            */
/* !Description :  Fonction de transition de l'etat LAMBDA_PURGE_CLOSING      */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Gsm_closed_cpc_request;                                     */
/*  input boolean Gsm_cpc_slow_closing_choice;                                */
/*  input boolean Conditions_for_feedback;                                    */
/*  input boolean CSTRMGR_open_loop_min_purge_req;                            */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  input uint8 Cpc_min_purge_rco;                                            */
/*  input sint16 Lambda_feedback;                                             */
/*  input uint8 Cpc_purge_inh_low_lambda_thresh;                              */
/*  input uint8 Cpc_decreasing_ratio;                                         */
/*  input uint16 Cpc_control_purge_ratio;                                     */
/*  input uint16 Cpc_purge_ratio_step_min;                                    */
/*  input uint16 Cpc_purge_ratio_step;                                        */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*  output uint16 Cpc_purge_ratio_step;                                       */
/*  output uint16 Cpc_control_purge_ratio;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidLambdaPurgeClosTrans(void)
{
   boolean bLocalInhCstr;
   boolean bLocalOxC_bMonRunORngIntr;
   boolean bLocalGsm_closed_cpc_request;
   boolean bLocalGsm_cpc_slow_clos_choice;
   boolean bLocalConditions_for_feedback;
   uint8   u8LocalVehicle_active_state;
   sint16  s16LocalLambda_feedback;
   uint16  u16Localthresh;
   uint16  u16Localratio;
   sint32  s32LocalDiff;


   bLocalInhCstr = GDGAR_bGetFRM(FRM_FRM_INHCSTR);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Gsm_closed_cpc_request, bLocalGsm_closed_cpc_request);
   VEMS_vidGET(Gsm_cpc_slow_closing_choice, bLocalGsm_cpc_slow_clos_choice);
   VEMS_vidGET(Conditions_for_feedback, bLocalConditions_for_feedback);

   if (  (CSTRMGR_open_loop_min_purge_req == 0)
      && (  (u8LocalVehicle_active_state != VS_RUNNING)
         || (bLocalInhCstr != 0)
         || (  (bLocalGsm_closed_cpc_request != 0)
            && (bLocalGsm_cpc_slow_clos_choice == 0))
         || (bLocalConditions_for_feedback == 0)))
   {
      VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_CLOSED);
      Demande_purge_dormant_nom = 1;
      Rco_demande_purge_nom = 0;
      VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
   }
   else
   {
      VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);

      if (  (CSTRMGR_open_loop_min_purge_req != 0)
         && (bLocalInhCstr == 0)
         && (bLocalGsm_closed_cpc_request == 0)
         && (bLocalOxC_bMonRunORngIntr == 0))
      {
         VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_MIN);
         Rco_demande_purge_nom = Cpc_min_purge_rco;
         VEMS_vidSET(OxC_bMonIntrPurgeCdn , 0);
      }
      else
      {
         VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
         u16Localthresh = (uint16)(Cpc_purge_inh_low_lambda_thresh * 256);

         if (MATHSRV_udtABS(s16LocalLambda_feedback) < u16Localthresh)
         {
            VEMS_vidSET(Cpc_purge_control_state, CPC_NORMAL_BOUNDING);
            VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
         }
         else
         {
            u16Localratio =
            (uint16)((Cpc_decreasing_ratio * Cpc_control_purge_ratio) / 256);
            Cpc_purge_ratio_step =
               (uint16)MATHSRV_udtMAX(u16Localratio, Cpc_purge_ratio_step_min);
            s32LocalDiff = (sint32)( Cpc_control_purge_ratio
                                   - Cpc_purge_ratio_step);
            Cpc_control_purge_ratio = (uint16)MATHSRV_udtMAX(s32LocalDiff, 0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRMGR_vidGsmPurgeClosingTrans                            */
/* !Description :  Fonction de transition de l'etat GSM_PURGE_CLOSING         */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Mariem BOUATTOUR                                           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Gsm_closed_cpc_request;                                     */
/*  input boolean Gsm_cpc_slow_closing_choice;                                */
/*  input boolean Conditions_for_feedback;                                    */
/*  input boolean CSTRMGR_open_loop_min_purge_req;                            */
/*  input boolean OxC_bMonRunORngIntr;                                        */
/*  input uint8 Cpc_min_purge_rco;                                            */
/*  input sint16 Lambda_feedback;                                             */
/*  input uint8 Cpc_purge_inh_high_lambda_thresh;                             */
/*  input boolean CoEs_bAcvClsCanPurgSTTEs;                                   */
/*  input boolean Cpc_bAcvClsCanPurgSTTLbdaCdn_C;                             */
/*  input uint16 Cpc_current_purge_ratio;                                     */
/*  output st66 Cpc_purge_control_state;                                      */
/*  output boolean Demande_purge_dormant_nom;                                 */
/*  output uint8 Rco_demande_purge_nom;                                       */
/*  output boolean OxC_bMonIntrPurgeCdn;                                      */
/*  output uint16 Cpc_control_purge_ratio;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRMGR_vidGsmPurgeClosingTrans(void)
{
   boolean bLocalInhCstr;
   boolean bLocalGsm_closed_cpc_request;
   boolean bLocalOxC_bMonRunORngIntr;
   boolean bLocalGsm_cpc_slow_clos_choice;
   boolean bLocalConditions_for_feedback;
   boolean bLocalCoEs_bAcvClsCanPurgSTT;
   uint8   u8LocalVehicle_active_state;
   sint16  s16LocalLambda_feedback;
   uint16  u16Localthresh;
   uint16  u16LocalCpc_current_purge_ratio;


   bLocalInhCstr = GDGAR_bGetFRM(FRM_FRM_INHCSTR);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Gsm_closed_cpc_request, bLocalGsm_closed_cpc_request);
   VEMS_vidGET(Gsm_cpc_slow_closing_choice, bLocalGsm_cpc_slow_clos_choice);
   VEMS_vidGET(Conditions_for_feedback, bLocalConditions_for_feedback);

   if (  (CSTRMGR_open_loop_min_purge_req == 0)
      && (  (u8LocalVehicle_active_state != VS_RUNNING)
         || (bLocalInhCstr != 0)
         || (  (bLocalGsm_closed_cpc_request != 0)
            && (bLocalGsm_cpc_slow_clos_choice == 0))
         || (bLocalConditions_for_feedback == 0)))
   {
      VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_CLOSED);
      Demande_purge_dormant_nom = 1;
      Rco_demande_purge_nom = 0;
      VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
   }
   else
   {
      VEMS_vidGET(OxC_bMonRunORngIntr, bLocalOxC_bMonRunORngIntr);

      if (  (CSTRMGR_open_loop_min_purge_req != 0)
         && (bLocalInhCstr == 0)
         && (bLocalGsm_closed_cpc_request == 0)
         && (bLocalOxC_bMonRunORngIntr == 0))
      {
         VEMS_vidSET(Cpc_purge_control_state, CPC_PURGE_MIN);
         Rco_demande_purge_nom = Cpc_min_purge_rco;
         VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
      }
      else
      {
         VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
         u16Localthresh = (uint16)(Cpc_purge_inh_high_lambda_thresh * 256);

         if (MATHSRV_udtABS(s16LocalLambda_feedback) <= u16Localthresh)
         {
            if (bLocalGsm_closed_cpc_request == 0)
            {
               VEMS_vidSET(Cpc_purge_control_state, CPC_NORMAL_BOUNDING);
               VEMS_vidSET(OxC_bMonIntrPurgeCdn, 1);
            }
         }
         else
         {
            VEMS_vidGET(CoEs_bAcvClsCanPurgSTTEs, bLocalCoEs_bAcvClsCanPurgSTT);
            if (  (Cpc_bAcvClsCanPurgSTTLbdaCdn_C == 0)
               || (bLocalCoEs_bAcvClsCanPurgSTT == 0))
            {
               VEMS_vidGET(Cpc_current_purge_ratio,
                           u16LocalCpc_current_purge_ratio);
               Cpc_control_purge_ratio = u16LocalCpc_current_purge_ratio;
               VEMS_vidSET(Cpc_purge_control_state, CPC_LAMBDA_PURGE_CLOSING);
               VEMS_vidSET(OxC_bMonIntrPurgeCdn, 0);
            }
         }
      }
   }
}
/*------------------------------- end of file --------------------------------*/