/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FAR_FARSPMGRONOFF                                       */
/* !Description     : FAR_FARSPMGRONOFF component                             */
/*                                                                            */
/* !Module          : FAR_FARSPMGRONOFF                                       */
/* !Description     : CALCUL DE L’OBJECTIF GLOBAL                             */
/*                                                                            */
/* !File            : FAR_FARSPMGRONOFF_FCT1.C                                */
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
/*   1 / FAR_FARSPMGRONOFF_vidInitOutput                                      */
/*   2 / FAR_FARSPMGRONOFF_vidObjRiGlobal                                     */
/*   3 / FAR_FARSPMGRONOFF_vidCalcObjRich                                     */
/*   4 / FAR_FARSPMGRONOFF_vidObjRchGlBrt                                     */
/*   5 / FAR_FARSPMGRONOFF_vidCaObjREnReg                                     */
/*   6 / FAR_FARSPMGRONOFF_ChoixTypInj                                        */
/*                                                                            */
/* !Reference   : V02 NT 08 05510 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FAR/FAR_FARSPMGRONOFF/FAR_FARSPM$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   vgarnier                               $$Date::   11 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.H"
#include "MATHSRV.h"
#include "FAR_FARSPMGRONOFF.h"
#include "FAR_FARSPMGRONOFF_L.h"
#include "FAR_FARSPMGRONOFF_IM.h"
#include "GDGAR.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FAR_FARSPMGRONOFF_vidInitOutput                            */
/* !Description :  Fonction f'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 Obj_rich_depart;                                            */
/*  output uint16 Obj_rich_en_regulation_richesse;                            */
/*  output uint32 Objectif_richesse_global;                                   */
/*  output uint16 Obj_rich_en_regul_rich_Brute;                               */
/*  output uint32 Objectif_richesse_global_brute;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FAR_FARSPMGRONOFF_vidInitOutput(void)
{
   VEMS_vidSET(Obj_rich_depart, 0);
   VEMS_vidSET(Obj_rich_en_regulation_richesse, 0);
   VEMS_vidSET(Objectif_richesse_global, 0);
   Obj_rich_en_regul_rich_Brute = 0;
   Objectif_richesse_global_brute = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FAR_FARSPMGRONOFF_vidObjRiGlobal                           */
/* !Description :  Fonction qui gére les appels des autres.                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FAR_FARSPMGRONOFF_vidCalcObjRich();                      */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Manu_inh_fuel_air_ratio;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FAR_FARSPMGRONOFF_vidObjRiGlobal(void)
{
   uint8 u8LocalVehicleActiveState;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicleActiveState);
   if (  (Manu_inh_fuel_air_ratio == 0)
      && (u8LocalVehicleActiveState == VS_RUNNING))
   {
      FAR_FARSPMGRONOFF_vidCalcObjRich();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FAR_FARSPMGRONOFF_vidCalcObjRich                           */
/* !Description :  fonction qui détermine :Objectif de richesse en régulation */
/*                 de richesse , Objectif de richesse global.                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_08_05510_001.02                                     */
/*                 VEMS_R_08_05510_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void FAR_FARSPMGRONOFF_vidObjRchGlBrt();                      */
/*  extf argret void FAR_FARSPMGRONOFF_vidCaObjREnReg();                      */
/*  extf argret void FAR_FARSPMGRONOFF_ChoixTypInj();                         */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  input boolean Fco_for_regul_lambda_on;                                    */
/*  output boolean Objectif_richesse_global_Ena;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FAR_FARSPMGRONOFF_vidCalcObjRich(void)
{
   boolean bLocalInhFarSpMgr;
   uint8   u8LocalCoupureDecelProgrInj;


   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupureDecelProgrInj);
   bLocalInhFarSpMgr = GDGAR_bGetFRM(FRM_FRM_INHFARSPMGR);

   if (  (Fco_for_regul_lambda_on != 0)
      && (  ( (u8LocalCoupureDecelProgrInj & 0x01 ) == 0x01)
         || ( (u8LocalCoupureDecelProgrInj & 0x02 ) == 0x02)
         || ( (u8LocalCoupureDecelProgrInj & 0x04 ) == 0x04)
         || ( (u8LocalCoupureDecelProgrInj & 0x08 ) == 0x08))
      && (bLocalInhFarSpMgr != 0))
   {
      Objectif_richesse_global_Ena = 0;
   }
   else
   {
      Objectif_richesse_global_Ena = 1;
      FAR_FARSPMGRONOFF_vidObjRchGlBrt();
      FAR_FARSPMGRONOFF_vidCaObjREnReg();
   }

   FAR_FARSPMGRONOFF_ChoixTypInj();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FAR_FARSPMGRONOFF_vidObjRchGlBrt                           */
/* !Description :  L’enrichissement au réattelage est positif. Il est  donc   */
/*                 impératif de cartographier  Afr_target_reinst_aps_corr_map,*/
/*                 Afr_target_reinst_init_corr_map et                         */
/*                 Afr_target_reinst_init_a_s_map en positif,  pour pouvoir   */
/*                 enrichir.                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_08_05510_002.02                                     */
/*                 VEMS_R_08_05510_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Obj_rich_coef_base_total;                                    */
/*  input uint16 Obj_rich_mise_en_action;                                     */
/*  input uint32 Obj_rich_apres_depart;                                       */
/*  input uint16 Hsfr_target;                                                 */
/*  input uint32 OxC_rlamOxCHeatPhaReq;                                       */
/*  input uint16 Obj_rich_charge_partielle;                                   */
/*  input uint16 Obj_rich_pleine_charge;                                      */
/*  input uint16 Obj_rich_temperature_air;                                    */
/*  input uint16 Objectif_richesse_anti_k;                                    */
/*  input uint32 Obj_rich_depart;                                             */
/*  input uint16 Eng_rlamRstrtSTT;                                            */
/*  input uint16 FARSp_rMixtSpAntiStall;                                      */
/*  input boolean Manu_inh_rich_stt;                                          */
/*  input sint16 Afr_target_reinst_aps_corr;                                  */
/*  input sint16 Afr_target_reinst_corr;                                      */
/*  input sint16 Eng_FacCorIntrSttHiEngSpd;                                   */
/*  output uint32 Obj_rich_depart;                                            */
/*  output uint32 Objectif_richesse_global_brute;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FAR_FARSPMGRONOFF_vidObjRchGlBrt(void)
{
   uint16 u16LocalData;
   uint16 u16LocalHsfrTarget;
   uint16 u16LocalObjRichChargePartielle;
   uint16 u16LocalObjRichCoefBaseTotal;
   uint16 u16LocalObjRichMiseEnAction;
   uint16 u16LocalObjRichPleineCharge;
   uint16 u16LocalObjRichTemperatureAir;
   uint16 u16LocalObjectifRichesseAntiK;
   uint16 u16LocalEng_rlamRstrtSTT;
   uint16 u16LocalFARSp_rMixtSpAntiStall;
   sint16 s16LocalEngFacCorIntrSttHiEngSpd;
   sint16 s16LocalAfrTargetReinstApsCorr;
   sint16 s16LocalAfrTargetReinstCorr;
   uint32 u32LocalData;
   uint32 u32LocalTempObj;
   uint32 u32LocalObjRichDepart;
   uint32 u32LocalObjRichDepartToSET;
   uint32 u32LocalObjRichApresDepart;
   uint32 u32LocalOxCRlamOxCHeatPhaReq;
   uint32 u32LocalObjRichDepartToGET;
   uint32 u32LocalAntiSTALL;
   sint32 s32LocalTempObj;


   VEMS_vidGET(Obj_rich_coef_base_total, u16LocalObjRichCoefBaseTotal);
   VEMS_vidGET(Obj_rich_mise_en_action, u16LocalObjRichMiseEnAction);
   u32LocalData =
      (uint32)( (u16LocalObjRichMiseEnAction * u16LocalObjRichCoefBaseTotal)
              / 16384);
   VEMS_vidGET(Obj_rich_apres_depart, u32LocalObjRichApresDepart);
   u32LocalTempObj = MATHSRV_udtMAX(u32LocalObjRichApresDepart,u32LocalData);
   VEMS_vidGET(Hsfr_target, u16LocalHsfrTarget);
   u32LocalData = (uint32)(u16LocalHsfrTarget  + 131072);
   if (u32LocalTempObj >(UINT32_MAX / u32LocalData))
   {
      if (u32LocalTempObj < 131072)
      {
         u16LocalData = (uint16)(u32LocalTempObj / 2);
         u32LocalTempObj = u32LocalTempObj + ((uint32)(u16LocalData
                                              * u16LocalHsfrTarget) / 65536);
      }
   }
   else
   {
      u32LocalTempObj = ((u32LocalTempObj * u32LocalData) / 131072);
   }
   VEMS_vidGET(OxC_rlamOxCHeatPhaReq, u32LocalOxCRlamOxCHeatPhaReq);
   u32LocalObjRichDepart =
      MATHSRV_udtMAX(u32LocalTempObj, u32LocalOxCRlamOxCHeatPhaReq);
   u32LocalObjRichDepartToSET = MATHSRV_udtMIN(u32LocalObjRichDepart,131071);
   VEMS_vidSET(Obj_rich_depart, u32LocalObjRichDepartToSET);

   VEMS_vidGET(Obj_rich_charge_partielle, u16LocalObjRichChargePartielle);
   VEMS_vidGET(Obj_rich_pleine_charge, u16LocalObjRichPleineCharge);
   VEMS_vidGET(Obj_rich_temperature_air, u16LocalObjRichTemperatureAir);
   VEMS_vidGET(Objectif_richesse_anti_k, u16LocalObjectifRichesseAntiK);
   VEMS_vidGET(Obj_rich_depart, u32LocalObjRichDepartToGET);
   VEMS_vidGET(Eng_rlamRstrtSTT, u16LocalEng_rlamRstrtSTT);
   VEMS_vidGET(FARSp_rMixtSpAntiStall, u16LocalFARSp_rMixtSpAntiStall);

   u32LocalTempObj =
      MATHSRV_udtMAX(u32LocalObjRichDepartToGET,u16LocalObjRichPleineCharge);
   u32LocalTempObj =
      MATHSRV_udtMAX(u32LocalTempObj,u16LocalObjRichChargePartielle);
   u32LocalTempObj =
      MATHSRV_udtMAX(u32LocalTempObj,u16LocalObjRichTemperatureAir);
   u32LocalTempObj =
      MATHSRV_udtMAX(u32LocalTempObj,u16LocalObjectifRichesseAntiK );
   if (Manu_inh_rich_stt == 0)
   {
      u32LocalTempObj =
         MATHSRV_udtMAX(u32LocalTempObj,u16LocalEng_rlamRstrtSTT);
   }
   else
   {
      u32LocalTempObj = MATHSRV_udtMAX(u32LocalTempObj, 8916);
   }
   u32LocalAntiSTALL = (uint32)((u16LocalFARSp_rMixtSpAntiStall * 320)/147);
   u32LocalTempObj = MATHSRV_udtMAX(u32LocalTempObj, u32LocalAntiSTALL);

   VEMS_vidGET(Afr_target_reinst_aps_corr, s16LocalAfrTargetReinstApsCorr);
   VEMS_vidGET(Afr_target_reinst_corr, s16LocalAfrTargetReinstCorr);
   VEMS_vidGET(Eng_FacCorIntrSttHiEngSpd, s16LocalEngFacCorIntrSttHiEngSpd);
   s32LocalTempObj = (sint32)(2*(s16LocalAfrTargetReinstCorr
         + s16LocalAfrTargetReinstApsCorr + s16LocalEngFacCorIntrSttHiEngSpd));
   if (s32LocalTempObj >= 0)
   {
      s32LocalTempObj =(sint32)(u32LocalTempObj + (uint32)s32LocalTempObj);
   }
   else
   {
      s32LocalTempObj =(sint32)(u32LocalTempObj - (uint32)(-s32LocalTempObj));
   }

   /* !Deviation: Violation of QAC_3356 rule.   */
   /*  Reason : s32LocalTempObj's value can be => "<0" or ">131071" */
   Objectif_richesse_global_brute =
      (uint32)MATHSRV_udtCLAMP(s32LocalTempObj,0,131071);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FAR_FARSPMGRONOFF_vidCaObjREnReg                           */
/* !Description :  Fonctio qui calcule Obj_rich_en_regulation_richesse.       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Obj_rich_coef_base_total;                                    */
/*  input uint16 Obj_rich_mise_en_action;                                     */
/*  input uint16 Hsfr_target;                                                 */
/*  input uint16 Obj_rich_min_limit;                                          */
/*  output uint16 Obj_rich_en_regul_rich_Brute;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FAR_FARSPMGRONOFF_vidCaObjREnReg(void)
{
   uint16 u16LocalData;
   uint16 u16LocalObjRichCoefBaseTotal;
   uint16 u16LocalObjRichMinLimit;
   uint16 u16LocalObjRichMiseEnAction;
   uint16 u16LocalHsfrTarget;
   uint32 u32LocalData;
   uint32 u32LocalTempObj;

   VEMS_vidGET(Obj_rich_coef_base_total, u16LocalObjRichCoefBaseTotal);
   VEMS_vidGET(Obj_rich_mise_en_action, u16LocalObjRichMiseEnAction);
   VEMS_vidGET(Hsfr_target, u16LocalHsfrTarget);

   u32LocalData = (uint32)( ( u16LocalObjRichMiseEnAction
                            * u16LocalObjRichCoefBaseTotal)
                          / 16384);
   VEMS_vidGET(Obj_rich_min_limit, u16LocalObjRichMinLimit);
   u32LocalTempObj = MATHSRV_udtMAX(u16LocalObjRichMinLimit,u32LocalData);
   u32LocalData = (uint32)(u16LocalHsfrTarget  + 131072);
   if (u32LocalTempObj > (UINT32_MAX / u32LocalData))
   {
      if (u32LocalTempObj < 65535)
      {
         u16LocalData = (uint16)( (u32LocalTempObj * u16LocalHsfrTarget)
                                / 131072);
         u32LocalTempObj = u32LocalTempObj +u16LocalData;
      }
   }
   else
   {
      u32LocalTempObj = (((u32LocalTempObj * u32LocalData) ) / 131072);
   }
   Obj_rich_en_regul_rich_Brute =
      (uint16)MATHSRV_udtMIN(u32LocalTempObj, 65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FAR_FARSPMGRONOFF_ChoixTypInj                              */
/* !Description :   Dans le cas de moteur avec système d’injection directe de */
/*                 carburant, la consigne de richesse de combustion (à        */
/*                 réaliser dans les cylindres comme l’objectif de richesse   */
/*                 pleine charge) est différentiée de la consigne de richesse.*/
/* !Number      :  FCT1.6                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ctrl_bSelFarSpMdlCf;                                        */
/*  input uint16 FARSp_rMixtCylSp;                                            */
/*  input boolean Objectif_richesse_global_Ena;                               */
/*  input uint32 Objectif_richesse_global_brute;                              */
/*  input uint8 Objectif_richesse_defaut;                                     */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint32 Richesse_maximale_CMG;                                       */
/*  input st67 Ext_stTypInjSysCf;                                             */
/*  input uint16 EngM_mfAirCor;                                               */
/*  input uint16 EngM_mfAirScvCor;                                            */
/*  input uint32 Objectif_richesse_global;                                    */
/*  input uint16 Far_facScvCmbEgMixt;                                         */
/*  input uint16 Obj_rich_en_regul_rich_Brute;                                */
/*  output uint32 Objectif_richesse_global;                                   */
/*  output uint16 Far_facScvCmbEgMixt;                                        */
/*  output uint16 Obj_rich_en_regulation_richesse;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FAR_FARSPMGRONOFF_ChoixTypInj(void)
{
   boolean bLocalCtrl_bSelFarSpMdlCf;
   uint8   u8LocalExt_stTypInjSysCf;
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalFARSp_rMixtCylSp;
   uint16  u16LocalEngM_mfAirCor;
   uint16  u16LocalEngM_mfAirScvCor;
   uint16  u16LocalObjRichEnRegRichesse;
   uint32  u32LocalRichesse_maximale_CMG;
   uint32  u32LocalObjectifRichesseGlobal;
   uint32  u32LocalEngM_mfAir;
   uint32  u32LocalObjRichEnRegRichesse;


   VEMS_vidGET(Ctrl_bSelFarSpMdlCf, bLocalCtrl_bSelFarSpMdlCf);
   VEMS_vidGET(FARSp_rMixtCylSp, u16LocalFARSp_rMixtCylSp);

   if(bLocalCtrl_bSelFarSpMdlCf != 0)
   {
      u32LocalObjectifRichesseGlobal = (u16LocalFARSp_rMixtCylSp * 320) / 147;
   }
   else
   {
      if (Objectif_richesse_global_Ena != 0)
      {
         u32LocalObjectifRichesseGlobal = Objectif_richesse_global_brute;
      }
      else
      {
         u32LocalObjectifRichesseGlobal =
            (uint32)(Objectif_richesse_defaut * 256);
      }

      VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
      if(u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         VEMS_vidGET(Richesse_maximale_CMG, u32LocalRichesse_maximale_CMG);
         u32LocalObjectifRichesseGlobal =
            MATHSRV_udtMIN(u32LocalObjectifRichesseGlobal,
                           u32LocalRichesse_maximale_CMG);
      }
   }
   u32LocalObjectifRichesseGlobal =
      MATHSRV_udtMIN(u32LocalObjectifRichesseGlobal, 131071);
   VEMS_vidSET(Objectif_richesse_global, u32LocalObjectifRichesseGlobal);

   VEMS_vidGET(Ext_stTypInjSysCf, u8LocalExt_stTypInjSysCf);
   VEMS_vidGET(EngM_mfAirCor, u16LocalEngM_mfAirCor);
   VEMS_vidGET(EngM_mfAirScvCor, u16LocalEngM_mfAirScvCor);

   u32LocalEngM_mfAir = u16LocalEngM_mfAirCor + u16LocalEngM_mfAirScvCor ;
   if( u32LocalEngM_mfAir != 0 )
   {
      Far_facScvCmbEgMixt = (uint16)( (u16LocalEngM_mfAirCor * 4096)
                                    / u32LocalEngM_mfAir);
   }
   else
   {
      Far_facScvCmbEgMixt = 4096;
   }

   if( u8LocalExt_stTypInjSysCf == Ext_stTypGslGdi_SC )
   {
      VEMS_vidGET(Objectif_richesse_global, u32LocalObjectifRichesseGlobal);
      u32LocalObjRichEnRegRichesse = ( ( Far_facScvCmbEgMixt
                                       * u32LocalObjectifRichesseGlobal)
                                     / 4096);
   }
   else
   {
      if(bLocalCtrl_bSelFarSpMdlCf != 0)
      {
         u32LocalObjRichEnRegRichesse = (u16LocalFARSp_rMixtCylSp * 320) / 147;
      }
      else
      {
         u32LocalObjRichEnRegRichesse = (uint32) Obj_rich_en_regul_rich_Brute;
      }
   }
   u16LocalObjRichEnRegRichesse =
      (uint16)MATHSRV_udtMIN(u32LocalObjRichEnRegRichesse , 65535);
   VEMS_vidSET(Obj_rich_en_regulation_richesse, u16LocalObjRichEnRegRichesse);
}

/*------------------------------end of file----------------------------------*/