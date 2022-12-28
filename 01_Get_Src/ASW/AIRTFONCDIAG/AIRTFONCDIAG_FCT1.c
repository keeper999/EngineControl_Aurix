/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTFONCDIAG                                            */
/* !Description     : AIRTFONCDIAG component.                                 */
/*                                                                            */
/* !Module          : AIRTFONCDIAG                                            */
/* !Description     : Diagnostic fonctionnel de la température d’admission    */
/*                    d’air.                                                  */
/*                                                                            */
/* !File            : AIRTFONCDIAG_FCT1.C                                     */
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
/*   1 / AIRTFONCDIAG_vidInitOutput                                           */
/*   2 / AIRTFONCDIAG_vidBeforeStartCoh                                       */
/*   3 / AIRTFONCDIAG_vidCohActivDtct                                         */
/*   4 / AIRTFONCDIAG_vidOutRngDtct                                           */
/*   5 / AIRTFONCDIAG_vidOutRngActivDtct                                      */
/*   6 / AIRTFONCDIAG_vidPosOfsDtct                                           */
/*   7 / AIRTFONCDIAG_vidPosOfsActivDtct                                      */
/*   8 / AIRTFONCDIAG_vidNegOfsDtct                                           */
/*   9 / AIRTFONCDIAG_vidNegOfsActivDtct                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5070969 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/AIRTFONCDIAG/AIRTFONCDIAG_FCT1.C_v$*/
/* $Revision::   1.2      $$Author::   CROCHE         $$Date::   27 Jun 2011 $*/
/* $Author::   CROCHE                                 $$Date::   27 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "AIRTFONCDIAG.h"
#include "AIRTFONCDIAG_L.h"
#include "AIRTFONCDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidInitOutput                                 */
/* !Description :  Fonction d'initialisation des variables internes de la     */
/*                 spec.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 AirT_tiTPosOfs;                                             */
/*  output uint16 AirT_tiIdlCtlTNegOfs;                                       */
/*  output uint16 AirT_tiEngrunTNegOfs;                                       */
/*  output boolean AirT_bDgoStallCoh_tAirMes;                                 */
/*  output boolean AirT_bDgoORng_tAirMes;                                     */
/*  output boolean AirT_bDgoPosOfs_tAirMes;                                   */
/*  output boolean AirT_bDgoNegOfs_tAirMes;                                   */
/*  output boolean AirT_bTmfAirCorPosOfs;                                     */
/*  output uint16 AirT_timfAirCorPosOfs;                                      */
/*  output boolean AIRTFONCDIAG_bTimerInit_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidInitOutput(void)
{
   AirT_tiTPosOfs = 0;
   AirT_tiIdlCtlTNegOfs = 0;
   AirT_tiEngrunTNegOfs = 0;
   AirT_bDgoStallCoh_tAirMes = 0;
   AirT_bDgoORng_tAirMes = 0;
   AirT_bDgoPosOfs_tAirMes = 0;
   AirT_bDgoNegOfs_tAirMes = 0;
   AirT_bTmfAirCorPosOfs = 0;
   AirT_timfAirCorPosOfs = 0;
   AIRTFONCDIAG_bTimerInit_prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidBeforeStartCoh                             */
/* !Description :  Le test de cohérence avec la température d’eau avant       */
/*                 démarrage est activé seulement si : 1) Le moteur est arrêté*/
/*                 depuis suffisamment longtemps (via l’information reçu du   */
/*                 calculateur EMF), 2) Le diagnostic n’est pas inhibé par le */
/*                 GAR.                                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_09_04089_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AIRTFONCDIAG_vidCohActivDtct();                          */
/*  input uint32 Time_since_stall;                                            */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint32 Ext_ctVehPwrl;                                               */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint32 Ext_ctVehPwrl2004;                                           */
/*  input uint32 AirT_tiDlyTDsThrStallCoh_C;                                  */
/*  input uint16 AirT_tiDlymaxTDsThrStallCoh_C;                               */
/*  output boolean AirT_bMonRunStallCoh_tAirMes;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidBeforeStartCoh(void)
{
   boolean bLocalInhMonAirT;
   boolean bLocalDelay1;
   boolean bLocalDelay2;
   boolean bLocalExtArchiCf;
   uint8   u8LocalVehicleActiveState;
   uint32  u32LocalTimeSinceStall;
   uint32  u32LocalAirTDly;
   uint32  u32LocalAirTDlymax;
   uint32  u32LocalExtCtVehPwrl;
   uint32  u32LocalExtCtVehPwrl2004;

   bLocalInhMonAirT = GDGAR_bGetFRM(FRM_FRM_INHMONAIRT);

   VEMS_vidGET(Time_since_stall, u32LocalTimeSinceStall);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicleActiveState);
   VEMS_vidGET(Ext_ctVehPwrl, u32LocalExtCtVehPwrl);
   VEMS_vidGET(Ext_bArchiCf, bLocalExtArchiCf);
   VEMS_vidGET(Ext_ctVehPwrl2004, u32LocalExtCtVehPwrl2004);

   u32LocalAirTDly = (  ( AirT_tiDlyTDsThrStallCoh_C
                        * AirT_SampleTiMid_SC)
                     / EngSt_SampleTiSlow_SC);
   u32LocalAirTDlymax = (  (AirT_tiDlymaxTDsThrStallCoh_C * 16000)
                        / EngSt_SampleTiSlow_SC);
   if (  (u32LocalTimeSinceStall > u32LocalAirTDly)
      && (u32LocalTimeSinceStall < u32LocalAirTDlymax))
   {
      bLocalDelay1 = 1;
   }
   else
   {
      bLocalDelay1 = 0;
   }

   if (  (  (bLocalExtArchiCf != 0)
         && (u32LocalExtCtVehPwrl != 0))
      || (  (bLocalExtArchiCf == 0)
         && (u32LocalExtCtVehPwrl2004 != 0)))
   {
      bLocalDelay2 = 1;
   }
   else
   {
      bLocalDelay2 = 0;
   }

   if (  (u8LocalVehicleActiveState == VS_STALL)
      && (bLocalDelay1 != 0)
      && (bLocalInhMonAirT == 0)
      && (bLocalDelay2 != 0))
   {
      AirT_bMonRunStallCoh_tAirMes = 1;
      AIRTFONCDIAG_vidCohActivDtct();
   }
   else
   {
      AirT_bMonRunStallCoh_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidCohActivDtct                               */
/* !Description :  La détection du défaut revient à constater un écart entre  */
/*                 la température d’air et la température d’eau suffisamment  */
/*                 important.                                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 AirT_tDsThrStallCoh_C;                                        */
/*  output boolean AirT_bDgoStallCoh_tAirMes;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidCohActivDtct(void)
{
   uint8  u8LocalTemperature_air;
   uint8  u8LocalTemperature_eau;
   uint16 u16LocalTemperature;
   uint16 u16LocalComp;
   sint16 s16LocalTemperature;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);

   s16LocalTemperature = (sint16)( ( u8LocalTemperature_air
                                   - u8LocalTemperature_eau)
                                 * 5);
   u16LocalTemperature = (uint16)MATHSRV_udtABS(s16LocalTemperature);
   u16LocalComp = (uint16)(AirT_tDsThrStallCoh_C * 8);
   if (u16LocalTemperature > u16LocalComp)
   {
      AirT_bDgoStallCoh_tAirMes = 1;
   }
   else
   {
      AirT_bDgoStallCoh_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidOutRngDtct                                 */
/* !Description :  Le test de la valeur hors zone de la température           */
/*                 d’admission d’air est activé seulement si le diagnostic    */
/*                 n’est pas inhibé par le GAR.                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_09_04089_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void AIRTFONCDIAG_vidOutRngActivDtct();                       */
/*  output boolean AirT_bMonRunORng_tAirMes;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidOutRngDtct(void)
{
   boolean bLocalInhMonAirT;


   bLocalInhMonAirT = GDGAR_bGetFRM(FRM_FRM_INHMONAIRT);

   if (bLocalInhMonAirT == 0)
   {
      AirT_bMonRunORng_tAirMes = 1;
      AIRTFONCDIAG_vidOutRngActivDtct();
   }
   else
   {
      AirT_bMonRunORng_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidOutRngActivDtct                            */
/* !Description :  La détection du défaut revient à tester avec 2 seuils      */
/*                 calibrables (seuil Mini et seuil Maxi) si la valeur mesurée*/
/*                 se trouve hors de la zone de fonctionnement normale.       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Temperature_air;                                              */
/*  input sint16 AirT_tDsThrThdORngMax_C;                                     */
/*  input sint16 AirT_tDsThrThdORngMin_C;                                     */
/*  output boolean AirT_bDgoORng_tAirMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidOutRngActivDtct(void)
{
   uint8  u8LocalTemperature_air;
   sint16 s16LocalAirTemperature;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);

   s16LocalAirTemperature = (sint16)((u8LocalTemperature_air * 5) - 320);

   if (  ( (sint32)s16LocalAirTemperature
         > (sint32)(AirT_tDsThrThdORngMax_C * 8))
      || ( (sint32)s16LocalAirTemperature
         < (sint32)(AirT_tDsThrThdORngMin_C * 8)))
   {
      AirT_bDgoORng_tAirMes = 1;
   }
   else
   {
      AirT_bDgoORng_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidPosOfsDtct                                 */
/* !Description :  Le test de l’offset positif de la température d’admission  */
/*                 d’air est activé seulement si : La vitesse véhicule est    */
/*                 suffisamment élevée depuis un certain délai, le débit d’air*/
/*                 massique d’air pompé par le moteur est suffisant, le       */
/*                 diagnostic n’est pas inhibé.                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_09_04089_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AIRTFONCDIAG_vidPosOfsActivDtct();                       */
/*  input uint16 EngM_mfAirCor;                                               */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 AirT_spdVehThdMinTPosOfs_C;                                   */
/*  input uint16 AirT_tiTPosOfs;                                              */
/*  input uint16 AirT_tiDlyTPosOfs_C;                                         */
/*  input uint16 AirT_mfAirThdMinTPosOfs_C;                                   */
/*  input boolean AIRTFONCDIAG_bTimerInit_prev;                               */
/*  input uint16 AirT_tiDlymfAirCorPosOfs_C;                                  */
/*  input uint16 AirT_timfAirCorPosOfs;                                       */
/*  input boolean AirT_bTmfAirCorPosOfs;                                      */
/*  output uint16 AirT_tiTPosOfs;                                             */
/*  output uint16 AirT_timfAirCorPosOfs;                                      */
/*  output boolean AirT_bTmfAirCorPosOfs;                                     */
/*  output boolean AIRTFONCDIAG_bTimerInit_prev;                              */
/*  output boolean AirT_bMonRunPosOfs_tAirMes;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidPosOfsDtct(void)
{
   boolean bLocalInhMonAirT;
   boolean bLocalTimerInit;
   uint8   u8LocalVitesse_vehicule;
   uint16  u16LocalEngM_mfAirCor;
   uint16  u16LocalAirT_tiTPosOfs;
   uint16  u16LocalTimer;


   bLocalInhMonAirT = GDGAR_bGetFRM(FRM_FRM_INHMONAIRT);

   VEMS_vidGET(EngM_mfAirCor, u16LocalEngM_mfAirCor);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);

   if (u8LocalVitesse_vehicule > AirT_spdVehThdMinTPosOfs_C)
   {
      if (AirT_tiTPosOfs > 0)
      {
         u16LocalAirT_tiTPosOfs = (uint16)(AirT_tiTPosOfs - 1);
         AirT_tiTPosOfs = (uint16)MATHSRV_udtMIN(u16LocalAirT_tiTPosOfs, 2550);
      }
   }
   else
   {
      AirT_tiTPosOfs = (uint16)MATHSRV_udtMIN(AirT_tiDlyTPosOfs_C, 2550);
   }

   if (u16LocalEngM_mfAirCor > AirT_mfAirThdMinTPosOfs_C)
   {
      bLocalTimerInit = 1;
   }
   else
   {
      bLocalTimerInit = 0;
   }
   /*Timer*/
   if (  (AIRTFONCDIAG_bTimerInit_prev == 0)
      && (bLocalTimerInit != 0))
   {
      AirT_timfAirCorPosOfs =
         (uint16)MATHSRV_udtMIN(AirT_tiDlymfAirCorPosOfs_C, 2550);
      if (AirT_timfAirCorPosOfs == 0)
      {
         AirT_bTmfAirCorPosOfs = 1;
      }
      else
      {
         AirT_bTmfAirCorPosOfs = 0;
      }
   }
   else
   {
      if (AirT_timfAirCorPosOfs > 0)
      {
         u16LocalTimer = (uint16)(AirT_timfAirCorPosOfs - 1);
         AirT_timfAirCorPosOfs =
            (uint16)MATHSRV_udtMIN(u16LocalTimer, 2550);
         if (AirT_timfAirCorPosOfs == 0)
         {
            AirT_bTmfAirCorPosOfs = 1;
         }
         else
         {
            AirT_bTmfAirCorPosOfs = 0;
         }
      }
   }
   AIRTFONCDIAG_bTimerInit_prev = bLocalTimerInit;

   if (  (AirT_tiTPosOfs == 0)
      && (AirT_bTmfAirCorPosOfs != 0)
      && (bLocalInhMonAirT == 0)
      && (bLocalTimerInit != 0))
   {
      AirT_bMonRunPosOfs_tAirMes = 1;
      AIRTFONCDIAG_vidPosOfsActivDtct();
   }
   else
   {
      AirT_bMonRunPosOfs_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidPosOfsActivDtct                            */
/* !Description :  La détection du défaut revient à tester si la valeur       */
/*                 mesurée dépasse le seuil maximum (calibrable) que peut     */
/*                 normalement atteindre l’air dans les conditions            */
/*                 d’activation du diagnostic.                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Temperature_air;                                              */
/*  input sint16 AirT_tDsThrThdMaxPosOfs_C;                                   */
/*  output boolean AirT_bDgoPosOfs_tAirMes;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidPosOfsActivDtct(void)
{
   uint8  u8LocalTemperature_air;
   sint16 s16LocalAirTemperature;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);

   s16LocalAirTemperature = (sint16)((u8LocalTemperature_air * 5) - 320);
   if ((sint32)s16LocalAirTemperature > (sint32)(AirT_tDsThrThdMaxPosOfs_C * 8))
   {
      AirT_bDgoPosOfs_tAirMes = 1;
   }
   else
   {
      AirT_bDgoPosOfs_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidNegOfsDtct                                 */
/* !Description :  Fonction qui décrit les conditions d'activation du test de */
/*                 l’offset négatif de la température d’admission d’air (     */
/*                 moteur démarré, vitesse véhicule faible, température d’eau */
/*                 élevée, moteur au ralenti, Le diagnostic n’est pas inhibé  */
/*                 par le GAR.)                                               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_09_04089_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AIRTFONCDIAG_vidNegOfsActivDtct();                       */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint16 AirT_tiIdlCtlTNegOfs;                                        */
/*  input uint16 AirT_tiDlyIdlCtlTNegOfs_C;                                   */
/*  input uint16 AirT_tiEngrunTNegOfs;                                        */
/*  input uint16 AirT_tiDlyEngrunTNegOfs_C;                                   */
/*  input uint8 AirT_spdVehThdMaxTNegOfs_C;                                   */
/*  input sint16 AirT_tCoThdMaxTNegOfs_C;                                     */
/*  output uint16 AirT_tiIdlCtlTNegOfs;                                       */
/*  output uint16 AirT_tiEngrunTNegOfs;                                       */
/*  output boolean AirT_bMonRunNegOfs_tAirMes;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidNegOfsDtct(void)
{
   boolean bLocalInhMonAirT;
   boolean bLocalIdlSys_bAcvIdlCtl;
   uint8   u8LocalVitesse_vehicule;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalAirT_tiIdlCtlTNegOfs;
   uint16  u16LocalAirT_tiEngrunTNegOfs;


   bLocalInhMonAirT = GDGAR_bGetFRM(FRM_FRM_INHMONAIRT);

   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);

   if (bLocalIdlSys_bAcvIdlCtl != 0)
   {
      if (AirT_tiIdlCtlTNegOfs > 0)
      {
         u16LocalAirT_tiIdlCtlTNegOfs = (uint16)(AirT_tiIdlCtlTNegOfs - 1);
         AirT_tiIdlCtlTNegOfs =
            (uint16)MATHSRV_udtMIN(u16LocalAirT_tiIdlCtlTNegOfs, 6555);
      }
   }
   else
   {
      AirT_tiIdlCtlTNegOfs = (uint16)MATHSRV_udtMIN(AirT_tiDlyIdlCtlTNegOfs_C,
                                                    6555);
   }

   if (u8LocalVehicle_active_state == VS_RUNNING)
   {
      if (AirT_tiEngrunTNegOfs > 0)
      {
         u16LocalAirT_tiEngrunTNegOfs = (uint16)(AirT_tiEngrunTNegOfs - 1);
         AirT_tiEngrunTNegOfs =
            (uint16)MATHSRV_udtMIN(u16LocalAirT_tiEngrunTNegOfs, 6555);
      }
   }
   else
   {
      AirT_tiEngrunTNegOfs = (uint16)MATHSRV_udtMIN(AirT_tiDlyEngrunTNegOfs_C,
                                                    6555);
   }

   if (  (AirT_tiIdlCtlTNegOfs == 0)
      && (u8LocalVitesse_vehicule < AirT_spdVehThdMaxTNegOfs_C)
      && (u8LocalTemperature_eau > (AirT_tCoThdMaxTNegOfs_C + 64))
      && (AirT_tiEngrunTNegOfs == 0)
      && (bLocalInhMonAirT == 0))
   {
      AirT_bMonRunNegOfs_tAirMes = 1;
      AIRTFONCDIAG_vidNegOfsActivDtct();
   }
   else
   {
      AirT_bMonRunNegOfs_tAirMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidNegOfsActivDtct                            */
/* !Description :  La détection du défaut revient à tester si la valeur       */
/*                 mesurée est en dessous du seuil minimum (calibrable) que   */
/*                 doit normalement atteindre l’air dans les conditions       */
/*                 d’activation du diagnostic.                                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Temperature_air;                                              */
/*  input sint16 Ext_tAirExtMes;                                              */
/*  input uint8 AirT_tAirExtMes_A[8];                                         */
/*  input uint8 AirT_tDsThr_pAirExtMes_T[8];                                  */
/*  output boolean AirT_bDgoNegOfs_tAirMes;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidNegOfsActivDtct(void)
{
   uint8   u8LocalTemperature_air;
   uint8   u8LocalExt_tAirExtMes;
   uint8   u8LocalInterp;
   uint16  u16LocalCalcPara;
   sint16  s16LocalExt_tAirExtMes;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
   VEMS_vidGET(Ext_tAirExtMes, s16LocalExt_tAirExtMes);

   s16LocalExt_tAirExtMes =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_tAirExtMes, -50, 200);
   u8LocalExt_tAirExtMes = (uint8)(s16LocalExt_tAirExtMes + 50);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(AirT_tAirExtMes_A,
                                                  u8LocalExt_tAirExtMes,
                                                  8);
   u8LocalInterp =
      MATHSRV_u8Interp1d(AirT_tDsThr_pAirExtMes_T, u16LocalCalcPara);

   if (u8LocalTemperature_air < u8LocalInterp)
   {
      AirT_bDgoNegOfs_tAirMes = 1;
   }
   else
   {
      AirT_bDgoNegOfs_tAirMes = 0;
   }
}
/*-------------------------------- end of file -------------------------------*/