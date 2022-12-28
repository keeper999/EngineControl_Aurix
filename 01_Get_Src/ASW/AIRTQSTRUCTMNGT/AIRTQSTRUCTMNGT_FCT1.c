/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTQSTRUCTMNGT                                         */
/* !Description     : AIRTQSTRUCTMNGT component                               */
/*                                                                            */
/* !Module          : AIRTQSTRUCTMNGT                                         */
/* !Description     : MANAGER DES ÉTATS DE LA STRUCTURE COUPLE                */
/*                                                                            */
/* !File            : AIRTQSTRUCTMNGT_FCT1.c                                  */
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
/*   1 / AIRTQSTRUCTMNGT_vidInitOutput                                        */
/*   2 / AIRTQSTRUCTMNGT_vidCalcSecCrOffs                                     */
/*   3 / AIRTQSTRUCTMNGT_vidInitSecCrOffs                                     */
/*   4 / AIRTQSTRUCTMNGT_vidDtcSecOffDel                                      */
/*   5 / AIRTQSTRUCTMNGT_vidManager                                           */
/*   6 / AIRTQSTRUCTMNGT_vidCalObjPres                                        */
/*   7 / AIRTQSTRUCTMNGT_vidStructInit                                        */
/*   8 / AIRTQSTRUCTMNGT_StructState                                          */
/*                                                                            */
/* !Reference   : PTS DOC 5015877 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/AIRTQSTRUCTMNGT/AIRTQSTRUC$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   24 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   24 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "AIRTQSTRUCTMNGT.h"
#include "AIRTQSTRUCTMNGT_L.h"
#include "AIRTQSTRUCTMNGT_IM.h"
#include "mathsrv.h"
#include "SWFAIL.H"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidInitOutput                              */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void AIRTQSTRUCTMNGT_vidCalcSecCrOffs();                      */
/*  extf argret void AIRTQSTRUCTMNGT_StructState();                           */
/*  output st12 Dtc_etat_structure;                                           */
/*  output boolean Dtc_structure_debouclee;                                   */
/*  output uint8 Coef_de_transition_air;                                      */
/*  output boolean CrkMng_bIntrKeyHiEngSpd;                                   */
/*  output boolean CrkMng_bIntrKeyLoEngSpd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidInitOutput(void)
{
   VEMS_vidSET(Dtc_etat_structure, DTC_INIT_DEM_SURFACE);
   AIRTQSTRUCTMNGT_vidCalcSecCrOffs();
   Dtc_structure_debouclee = 1;
   VEMS_vidSET(Coef_de_transition_air, 0);
   CrkMng_bIntrKeyHiEngSpd = 0;
   CrkMng_bIntrKeyLoEngSpd = 0;
   AIRTQSTRUCTMNGT_StructState();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidCalcSecCrOffs                           */
/* !Description :  cette fonction fait appel à                                */
/*                 AIRTQSTRUCTMGT_vidInitSecCrOffset et                       */
/*                 AIRTQSTRUCTMGT_vidCompDtcSecOffDel                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AIRTQSTRUCTMNGT_vidInitSecCrOffs();                      */
/*  extf argret void AIRTQSTRUCTMNGT_vidDtcSecOffDel();                       */
/*  input st12 Dtc_etat_structure;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidCalcSecCrOffs(void)
{
   uint8 u8LocalDtc_etat_structure;


   VEMS_vidGET(Dtc_etat_structure,u8LocalDtc_etat_structure);
   if (u8LocalDtc_etat_structure == DTC_INIT_DEM_SURFACE)
   {
      AIRTQSTRUCTMNGT_vidInitSecCrOffs();
   }
   if (u8LocalDtc_etat_structure == DTC_SECOND_CRANK_SURFACE)
   {
      AIRTQSTRUCTMNGT_vidDtcSecOffDel();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidInitSecCrOffs                           */
/* !Description :  cette fonction permet de calculer                          */
/*                 Dtc_second_crank_offset_delay à partir de la valeur de     */
/*                 Temperature_eau.                                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint8 Dtc_STT_crank_delay_map[16];                                  */
/*  input uint8 Dtc_second_crank_delay_map[16];                               */
/*  output uint8 Dtc_second_crank_offset_delay;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidInitSecCrOffs(void)
{
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalDtcDel;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalDtc_sec_crank_off_delay;
   uint16  u16LocalTempEau;


   VEMS_vidGET(CoPTSt_bRStrtSTT,bLocalCoPTSt_bRStrtSTT);
   VEMS_vidGET(Temperature_eau,u8LocalTemperature_eau);
   u16LocalTempEau = MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                                 u8LocalTemperature_eau,
                                                 16);
   if (bLocalCoPTSt_bRStrtSTT != 0)
   {
      u8LocalDtcDel = MATHSRV_u8Interp1d(Dtc_STT_crank_delay_map,
                                         u16LocalTempEau);
   }
   else
   {
      u8LocalDtcDel = MATHSRV_u8Interp1d(Dtc_second_crank_delay_map,
                                         u16LocalTempEau);

   }
   u8LocalDtc_sec_crank_off_delay = (uint8)MATHSRV_udtMIN(u8LocalDtcDel,250);
   VEMS_vidSET(Dtc_second_crank_offset_delay,u8LocalDtc_sec_crank_off_delay);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidDtcSecOffDel                            */
/* !Description :  décrementer la valeur de Dtc_second_crank_offset_delay.    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Dtc_second_crank_offset_delay;                                */
/*  output uint8 Dtc_second_crank_offset_delay;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidDtcSecOffDel(void)
{
   uint8  u8LocalDtc_sec_crank_off_delay;
   sint16 s16LocalDiff;


   VEMS_vidGET(Dtc_second_crank_offset_delay, u8LocalDtc_sec_crank_off_delay);
   s16LocalDiff = (sint16)(u8LocalDtc_sec_crank_off_delay - 1);
   u8LocalDtc_sec_crank_off_delay = (uint8)MATHSRV_udtCLAMP(s16LocalDiff,0,250);
   VEMS_vidSET(Dtc_second_crank_offset_delay,u8LocalDtc_sec_crank_off_delay);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidManager                                 */
/* !Description :  2 sections effectives sont calculées suivant que l’on soit */
/*                 en ou hors structure couple.. Le passage filtré de l’une   */
/*                 vers l’autre et géré par un stateflow (Manager) à l’aide de*/
/*                 coefficients sur l’air et sur l’avance.                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQSTRUCTMNGT_vidCalObjPres();                         */
/*  extf argret void AIRTQSTRUCTMNGT_StructState();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidManager(void)
{
   AIRTQSTRUCTMNGT_vidCalObjPres();
   AIRTQSTRUCTMNGT_StructState();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidCalObjPres                              */
/* !Description :  Ce module calcule l’objectif de ratio de la pression       */
/*                 collecteur ainsi q’un seuil à partir duquel on déboucle.   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 UsThrM_pAirExtEstim;                                         */
/*  input uint16 UsThrM_pLossAirFil;                                          */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint8 Dtc_seuil_ratio_pres_trans_map[16];                           */
/*  input uint16 AirSys_pInMnfReq;                                            */
/*  output uint8 Dtc_seuil_ratio_pres_trans;                                  */
/*  output uint8 Dtc_obj_pres_ratio;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidCalObjPres(void)
{
   uint16 u16LocalRedMOt;
   uint16 u16LocalRedMOtP;
   uint16 u16LocalAirSys_pInMnfReq;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalUsThrM_pAirExtEstim;
   uint16 u16LocalUsThrM_pLossAirFil;
   sint32 s32LocalObjRat;


   VEMS_vidGET(Regime_moteur,u16LocalRegime_moteur);
   VEMS_vidGET(UsThrM_pAirExtEstim,u16LocalUsThrM_pAirExtEstim);
   VEMS_vidGET(UsThrM_pLossAirFil,u16LocalUsThrM_pLossAirFil);
   u16LocalRedMOt = (uint16)MATHSRV_udtMIN((u16LocalRegime_moteur * 8),65535);
   u16LocalRedMOtP = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                  u16LocalRedMOt,
                                                  16);
   Dtc_seuil_ratio_pres_trans =
      MATHSRV_u8Interp1d(Dtc_seuil_ratio_pres_trans_map,u16LocalRedMOtP);
   s32LocalObjRat = (u16LocalUsThrM_pAirExtEstim - u16LocalUsThrM_pLossAirFil);
   if (s32LocalObjRat == 0)
   {
      Dtc_obj_pres_ratio = 255;
   }
   else
   {
      VEMS_vidGET(AirSys_pInMnfReq,u16LocalAirSys_pInMnfReq);
      s32LocalObjRat = ((u16LocalAirSys_pInMnfReq * 256) / s32LocalObjRat);
      Dtc_obj_pres_ratio = (uint8)MATHSRV_udtCLAMP(s32LocalObjRat, 0, 255);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidStructInit                              */
/* !Description :  initialisation de l'état de la structure                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void AIRTQSTRUCTMNGT_vidFcSurfStart();                        */
/*  output st12 Dtc_etat_structure;                                           */
/*  output boolean Dtc_structure_debouclee;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidStructInit(void)
{
   VEMS_vidSET(Dtc_etat_structure,DTC_INIT_DEM_SURFACE);
   Dtc_structure_debouclee = 1;
   AIRTQSTRUCTMNGT_vidFcSurfStart();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_StructState                                */
/* !Description :  Le stateflow gère l’ensemble des passages entre le mode    */
/*                 bouclé et débouclé.                                        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_08_04993_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void AIRTQSTRUCTMNGT_vidFcSurfStart();                        */
/*  extf argret void AIRTQSTRUCTMNGT_vidStructInit();                         */
/*  extf argret void AIRTQSTRUCTMNGT_vidFcTransToStop();                      */
/*  extf argret void AIRTQSTRUCTMNGT_vidFcDeTranToCyc();                      */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void AIRTQSTRUCTMNGT_vidFcTranToDecyc();                      */
/*  extf argret void AIRTQSTRUCTMNGT_vidFcTransToCycl();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean CoPt_bSIP;                                                  */
/*  input boolean CoCha_bTqReq;                                               */
/*  input boolean Moteur_tournant;                                            */
/*  input uint16 Dtc_first_crank_offset;                                      */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 Coef_de_transition_air;                                       */
/*  input st12 Dtc_etat_structure;                                            */
/*  input uint8 Dtc_second_crank_offset_delay;                                */
/*  input boolean CoEs_bAcvThrSysSTTEs;                                       */
/*  input boolean Clef_de_contact;                                            */
/*  input uint16 Dtc_seuil_regime_de_trans_dem;                               */
/*  input boolean CrkMng_bAcvThrClsEngStop_C;                                 */
/*  input uint8 Dtc_obj_pres_ratio;                                           */
/*  input uint8 Dtc_seuil_ratio_pres_trans;                                   */
/*  input uint8 Dtc_seuil_deboucle_vitesse_min;                               */
/*  input uint8 Dtc_pres_ratio_hysteresis;                                    */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input uint16 CrkMng_nEngSpdHiThd_C;                                       */
/*  input uint16 CrkMng_nEngSpdLoThd_C;                                       */
/*  input boolean CoEs_bIntrSTTEsLoEngSpd;                                    */
/*  input boolean CoEs_bIntrSTTEsHiEngSpd;                                    */
/*  input boolean Dtc_structure_debouclee;                                    */
/*  output st12 Dtc_etat_structure;                                           */
/*  output boolean Dtc_structure_debouclee;                                   */
/*  output boolean CrkMng_bIntrKeyHiEngSpd;                                   */
/*  output boolean CrkMng_bIntrKeyLoEngSpd;                                   */
/*  output boolean IgSys_bAcvStructAir;                                       */
/*  output boolean IgSys_bAcvStructAdv;                                       */
/*  output boolean TqSys_bTqSysAcv;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_StructState(void)
{
   boolean bLocalAcvAirThrArSpByp;
   boolean bLocalCoPt_bSIP;
   boolean bLocalCoCha_bTqReq;
   boolean bLocalMoteur_tournant;
   boolean bLocalCoEs_bAcvThrSysSTTEs;
   boolean bLocalCoEs_bIntrSTTEsLoEngSpd;
   boolean bLocalClef_de_contact;
   boolean bLocalCoEsbIntrSTTEsHiEngSpd;
   boolean bLocalCoPTStbRStrtSTT;
   uint8   u8LocalVitesse_vehicule;
   uint8   u8LocalDtc_etat_structure;
   uint8   u8LocalCoef_de_transition_air;
   uint8   u8LocalDtc_sec_crank_off_delay;
   uint16  u16LocalDtc_first_crank_offset;
   uint16  u16LocalRegime_moteur;
   sint16  s16LocalDiff;


   VEMS_vidGET(CoPt_bSIP, bLocalCoPt_bSIP);
   VEMS_vidGET(CoCha_bTqReq, bLocalCoCha_bTqReq);
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Dtc_first_crank_offset, u16LocalDtc_first_crank_offset);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   VEMS_vidGET(Coef_de_transition_air, u8LocalCoef_de_transition_air);
   VEMS_vidGET(Dtc_etat_structure, u8LocalDtc_etat_structure);
   VEMS_vidGET(Dtc_second_crank_offset_delay, u8LocalDtc_sec_crank_off_delay);
   VEMS_vidGET(CoEs_bAcvThrSysSTTEs, bLocalCoEs_bAcvThrSysSTTEs);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   switch (u8LocalDtc_etat_structure)
   {
      case DTC_INIT_DEM_SURFACE :
         if (  (Dtc_seuil_regime_de_trans_dem <= (u16LocalRegime_moteur * 8))
            && (bLocalMoteur_tournant != 0))
         {
            VEMS_vidSET(Dtc_etat_structure, DTC_FIRST_CRANK_SURFACE);
         }
         else
         {
            Dtc_structure_debouclee = 1;
         }
         AIRTQSTRUCTMNGT_vidFcSurfStart();
         break;

      case DTC_FIRST_CRANK_SURFACE :
         if (bLocalMoteur_tournant == 0)
         {
            CrkMng_bIntrKeyHiEngSpd = 0;
            CrkMng_bIntrKeyLoEngSpd = 0;
            AIRTQSTRUCTMNGT_vidStructInit();
         }
         else
         {
            if (  (bLocalCoEs_bAcvThrSysSTTEs != 0)
               || (  (bLocalClef_de_contact == 0)
                  && (CrkMng_bAcvThrClsEngStop_C != 0)))
            {
               VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ARRET);
               AIRTQSTRUCTMNGT_vidFcTransToStop();
               CrkMng_bIntrKeyHiEngSpd = 0;
               CrkMng_bIntrKeyLoEngSpd = 0;
            }
            else
            {
               if (u16LocalDtc_first_crank_offset == 0)
               {
                  VEMS_vidSET(Dtc_etat_structure, DTC_SECOND_CRANK_SURFACE);
               }
               else
               {
                  Dtc_structure_debouclee = 1;
               }
               AIRTQSTRUCTMNGT_vidFcSurfStart();
            }
         }
         break;

      case DTC_SECOND_CRANK_SURFACE :
         if (bLocalMoteur_tournant == 0)
         {
            CrkMng_bIntrKeyHiEngSpd = 0;
            CrkMng_bIntrKeyLoEngSpd = 0;
            AIRTQSTRUCTMNGT_vidStructInit();
         }
         else
         {
            if (  (bLocalCoEs_bAcvThrSysSTTEs != 0)
               || (  (bLocalClef_de_contact == 0)
                  && (CrkMng_bAcvThrClsEngStop_C != 0)))
            {
               VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ARRET);
               AIRTQSTRUCTMNGT_vidFcTransToStop();
               CrkMng_bIntrKeyHiEngSpd = 0;
               CrkMng_bIntrKeyLoEngSpd = 0;
            }
            else
            {
               if (u8LocalDtc_sec_crank_off_delay == 0)
               {
                  VEMS_vidSET(Dtc_etat_structure,DTC_TRANS_DEM_SURFACE);
                  AIRTQSTRUCTMNGT_vidFcDeTranToCyc();
               }
               else
               {
                  Dtc_structure_debouclee = 1;
                  AIRTQSTRUCTMNGT_vidFcSurfStart();
               }
            }
         }
         break;

      case DTC_TRANS_DEM_SURFACE :
         if (bLocalMoteur_tournant == 0)
         {
            CrkMng_bIntrKeyHiEngSpd = 0;
            CrkMng_bIntrKeyLoEngSpd = 0;
            AIRTQSTRUCTMNGT_vidStructInit();
         }
         else
         {
            if (  (bLocalCoEs_bAcvThrSysSTTEs != 0)
               || (  (bLocalClef_de_contact == 0)
                  && (CrkMng_bAcvThrClsEngStop_C != 0)))
            {
               VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ARRET);
               AIRTQSTRUCTMNGT_vidFcTransToStop();
               CrkMng_bIntrKeyHiEngSpd = 0;
               CrkMng_bIntrKeyLoEngSpd = 0;
            }
            else
            {
               bLocalAcvAirThrArSpByp = GDGAR_bGetFRM(FRM_FRM_ACVAIRTHRARSPBYP);
               if (bLocalAcvAirThrArSpByp != 0)
               {
                  VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ET_DEBOUCLEE);
                  AIRTQSTRUCTMNGT_vidFcTranToDecyc();
               }
               else
               {
                  if (u8LocalCoef_de_transition_air == 0)
                  {
                     VEMS_vidSET(Dtc_etat_structure,
                                 DTC_VERS_ET_STRUCTURE_COUPLE);
                     AIRTQSTRUCTMNGT_vidFcTransToCycl();
                  }
                  else
                  {
                     Dtc_structure_debouclee = 0;
                     AIRTQSTRUCTMNGT_vidFcDeTranToCyc();
                  }
               }
            }
         }
         break;

      case DTC_VERS_ET_STRUCTURE_COUPLE :
         if (bLocalMoteur_tournant == 0)
         {
            CrkMng_bIntrKeyHiEngSpd = 0;
            CrkMng_bIntrKeyLoEngSpd = 0;
            AIRTQSTRUCTMNGT_vidStructInit();
         }
         else
         {
            if (  (bLocalCoEs_bAcvThrSysSTTEs != 0)
               || (  (bLocalClef_de_contact == 0)
                  && (CrkMng_bAcvThrClsEngStop_C != 0)))
            {
               VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ARRET);
               AIRTQSTRUCTMNGT_vidFcTransToStop();
               CrkMng_bIntrKeyHiEngSpd = 0;
               CrkMng_bIntrKeyLoEngSpd = 0;
            }
            else
            {
               bLocalAcvAirThrArSpByp = GDGAR_bGetFRM(FRM_FRM_ACVAIRTHRARSPBYP);
               if (  (  (Dtc_obj_pres_ratio > Dtc_seuil_ratio_pres_trans)
                     && (  u8LocalVitesse_vehicule
                        >= Dtc_seuil_deboucle_vitesse_min)
                     && (bLocalCoCha_bTqReq == 0)
                     && (bLocalCoPt_bSIP == 0))
                  || (bLocalAcvAirThrArSpByp != 0))
               {
                  VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ET_DEBOUCLEE);
                  AIRTQSTRUCTMNGT_vidFcTranToDecyc();
               }
               else
               {
                  Dtc_structure_debouclee = 0;
                  AIRTQSTRUCTMNGT_vidFcTransToCycl();
               }
            }
         }
         break;

      case DTC_VERS_ET_DEBOUCLEE :
         if (bLocalMoteur_tournant == 0)
         {
            CrkMng_bIntrKeyHiEngSpd = 0;
            CrkMng_bIntrKeyLoEngSpd = 0;
            AIRTQSTRUCTMNGT_vidStructInit();
         }
         else
         {
            if (  (bLocalCoEs_bAcvThrSysSTTEs != 0)
               || (  (bLocalClef_de_contact == 0)
                  && (CrkMng_bAcvThrClsEngStop_C != 0)))
            {
               VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ARRET);
               AIRTQSTRUCTMNGT_vidFcTransToStop();
               CrkMng_bIntrKeyHiEngSpd = 0;
               CrkMng_bIntrKeyLoEngSpd = 0;
            }
            else
            {
               bLocalAcvAirThrArSpByp = GDGAR_bGetFRM(FRM_FRM_ACVAIRTHRARSPBYP);
               s16LocalDiff =(sint16)
                       (Dtc_seuil_ratio_pres_trans - Dtc_pres_ratio_hysteresis);
               if (  ( (Dtc_obj_pres_ratio < s16LocalDiff)
                     ||(bLocalCoCha_bTqReq != 0)
                     ||(bLocalCoPt_bSIP != 0))
                  && (bLocalAcvAirThrArSpByp == 0))
               {
                  VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ET_STRUCTURE_COUPLE);
                  AIRTQSTRUCTMNGT_vidFcTransToCycl();
               }
               else
               {
                  Dtc_structure_debouclee = 1;
                  AIRTQSTRUCTMNGT_vidFcTranToDecyc();
               }
            }
         }
         break;

      case DTC_VERS_ARRET:
         if (bLocalMoteur_tournant == 0)
         {
            CrkMng_bIntrKeyHiEngSpd = 0;
            CrkMng_bIntrKeyLoEngSpd = 0;
            AIRTQSTRUCTMNGT_vidStructInit();
         }
         else
         {
            VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTStbRStrtSTT);
            if (  (bLocalClef_de_contact != 0)
               && (CrkMng_bAcvThrClsEngStop_C != 0)
               && (bLocalCoEs_bAcvThrSysSTTEs == 0)
               && (bLocalCoPTStbRStrtSTT == 0))
            {
               if (u16LocalRegime_moteur >= CrkMng_nEngSpdHiThd_C)
               {
                  CrkMng_bIntrKeyHiEngSpd = 1;
                  VEMS_vidSET(Dtc_etat_structure, DTC_VERS_ET_STRUCTURE_COUPLE);
                  AIRTQSTRUCTMNGT_vidFcTransToCycl();
               }
               else
               {
                  if (u16LocalRegime_moteur < CrkMng_nEngSpdLoThd_C)
                  {
                     CrkMng_bIntrKeyLoEngSpd = 1;
                     AIRTQSTRUCTMNGT_vidStructInit();
                  }
               }
            }
            else
            {
               VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd,
                           bLocalCoEs_bIntrSTTEsLoEngSpd);
               if (  (bLocalCoEs_bAcvThrSysSTTEs == 0)
                  && (bLocalCoEs_bIntrSTTEsLoEngSpd != 0))
               {
                  AIRTQSTRUCTMNGT_vidStructInit();
               }
               else
               {
                  VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd,
                              bLocalCoEsbIntrSTTEsHiEngSpd);
                  if (  (bLocalCoEs_bAcvThrSysSTTEs == 0)
                     && (bLocalCoEsbIntrSTTEsHiEngSpd != 0))
                  {
                     VEMS_vidSET(Dtc_etat_structure,
                                 DTC_VERS_ET_STRUCTURE_COUPLE);
                     AIRTQSTRUCTMNGT_vidFcTransToCycl();
                  }
                  else
                  {
                     Dtc_structure_debouclee = 1;
                     AIRTQSTRUCTMNGT_vidFcTransToStop();
                  }
               }
            }
         }
         break;
      default:
         VEMS_vidSET(Dtc_etat_structure,DTC_INIT_DEM_SURFACE);
         Dtc_structure_debouclee = 1;
         AIRTQSTRUCTMNGT_vidFcSurfStart();
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   if (Dtc_structure_debouclee != 0)
   {
      VEMS_vidSET(IgSys_bAcvStructAir, 0);
      VEMS_vidSET(IgSys_bAcvStructAdv, 0);
      VEMS_vidSET(TqSys_bTqSysAcv, 0);
   }
   else
   {
      VEMS_vidSET(IgSys_bAcvStructAir, 1);
      VEMS_vidSET(IgSys_bAcvStructAdv, 1);
      VEMS_vidSET(TqSys_bTqSysAcv, 1);
   }
}
/*------------------------------- end of file --------------------------------*/