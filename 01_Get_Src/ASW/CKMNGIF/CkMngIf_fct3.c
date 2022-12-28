/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CKMNGIF                                                 */
/* !Description     : CKMNGIF component.                                      */
/*                                                                            */
/* !Module          : CKMNGIF                                                 */
/* !Description     : Interface Gestion Roue Dentée Vilebrequin.              */
/*                                                                            */
/* !File            : CKMNGIF_FCT3.C                                          */
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
/*   1 / CKMNGIF_vidDiagEngFail                                               */
/*   2 / CKMNGIF_vidPhaseCylEch                                               */
/*   3 / CKMNGIF_vidToothCylEch                                               */
/*   4 / CKMNGIF_vidNoExCyl                                                   */
/*   5 / CKMNGIF_vidBdcTreatment                                              */
/*   6 / CKMNGIF_vidCalcBdcEngSpd                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6884590 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#069167                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/CKMNGIF/CkMngIf_fct3.c_v     $*/
/* $Revision::   1.18     $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   31 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CKMNGIF.h"
#include "CKMNGIF_L.h"
#include "CKMNGIF_IM.h"
#include "GDGAR.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidDiagEngFail                                     */
/* !Description :  Fonction de diagnostic de deux pannes sur le régime moteur */
/*                 : Panne Régime trop haut et Panne  Accélération  trop      */
/*                 forte                                                      */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Gear_engaged;                                                 */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean Moteur_tournant;                                            */
/*  input uint16 Regime_moteur_max_thresh;                                    */
/*  input sint8 Engine_speed_derivate;                                        */
/*  input uint8 Engine_spd_der_filter_gain;                                   */
/*  input uint32 CKMNGIF_u32FiltredEngSpdMem;                                 */
/*  input uint8 Regime_accel_max_thresh_map[6];                               */
/*  input sint8 Engine_speed_derivate_filt;                                   */
/*  input uint8 Regime_moteur_accel_max_thresh;                               */
/*  output boolean Ext_bMonRunHi_aEng;                                        */
/*  output boolean Ext_bMonRunHi_nEng;                                        */
/*  output boolean Ext_bDgoHi_nEng;                                           */
/*  output sint8 Engine_speed_derivate_filt;                                  */
/*  output uint8 Regime_moteur_accel_max_thresh;                              */
/*  output boolean Ext_bDgoHi_aEng;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidDiagEngFail(void)
{
   boolean bLocalMoteur_tournant;
   uint8   u8LocalGear_engaged;
   uint16  u16LocalFilterIn;
   uint16  u16LocalFilterOut;
   uint16  u16Local_Regime_moteur;
   sint8   s8LocalEngine_speed_derivate;


   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   VEMS_vidGET(Regime_moteur, u16Local_Regime_moteur);
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);

   if (bLocalMoteur_tournant != 0)
   {
      Ext_bMonRunHi_aEng = 1;
      Ext_bMonRunHi_nEng = 1;

      if (u16Local_Regime_moteur > Regime_moteur_max_thresh)
      {
         Ext_bDgoHi_nEng = 1;
      }
      else
      {
         Ext_bDgoHi_nEng = 0;
      }
      VEMS_vidGET(Engine_speed_derivate, s8LocalEngine_speed_derivate);
      u16LocalFilterIn  = (uint16)((s8LocalEngine_speed_derivate + 128) * 256);
      u16LocalFilterOut =
         MATHSRV_u16FirstOrderFilterGu8(Engine_spd_der_filter_gain,
                                        &CKMNGIF_u32FiltredEngSpdMem,
                                        u16LocalFilterIn);
      Engine_speed_derivate_filt = (sint8)((u16LocalFilterOut / 256) - 128);
      Regime_moteur_accel_max_thresh =
         Regime_accel_max_thresh_map[u8LocalGear_engaged];
      if (Engine_speed_derivate_filt > Regime_moteur_accel_max_thresh)
      {
         Ext_bDgoHi_aEng = 1;
      }
      else
      {
         Ext_bDgoHi_aEng = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidPhaseCylEch                                     */
/* !Description :  Fonction permettant  d'obtenir la position angulaire du    */
/*                 vilebrequin                                                */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CKMNGIF_vidToothCylEch();                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Moteur_synchronise;                                         */
/*  input uint16 Periode_moteur;                                              */
/*  output uint16 Periode_moteur_hold;                                        */
/*  output uint16 Ext_tiHldPerEng;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidPhaseCylEch(void)
{
   boolean bLocalMoteur_synchronise;
   uint16  u16LocalPeriode_moteur;


   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(Periode_moteur, u16LocalPeriode_moteur);

   if (bLocalMoteur_synchronise != 0)
   {
      CKMNGIF_vidToothCylEch();
   }
   VEMS_vidSET(Periode_moteur_hold, u16LocalPeriode_moteur);
   VEMS_vidSET(Ext_tiHldPerEng, u16LocalPeriode_moteur);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidToothCylEch                                     */
/* !Description :  Une fois le moteur synchronisé, le LdA fait un appel au LdB*/
/*                 via l’API CRKHAL pour obtenir la position angulaire du     */
/*                 vilebrequin dont la référence (0 °Vil) est pour  rappel à  */
/*                 l’événement PMH du cylindre 1                              */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void CKMNGIF_vidNoExCyl();                                    */
/*  input uint16 Acqui_angle_crankshaft;                                      */
/*  input boolean Cipd_bAgDifPha;                                             */
/*  input boolean Cipd_inh_dephia;                                            */
/*  output uint16 Sync_agCkPosnRef1;                                          */
/*  output uint16 Ext_agCkPosnCurRef2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidToothCylEch(void)
{
   boolean bLocalCipd_bAgDifPha;
   uint16  u16LocalAcquianglecrankshaft;
   uint16  u16LocalCrkHALRead1;
   uint16  u16LocalCrkHALRead2;


   VEMS_vidGET(Acqui_angle_crankshaft, u16LocalAcquianglecrankshaft);

   u16LocalCrkHALRead2 =
      (uint16)(((u16LocalAcquianglecrankshaft + 11520) / 6) % 7680);

   VEMS_vidGET(Cipd_bAgDifPha, bLocalCipd_bAgDifPha);
   if (  ( bLocalCipd_bAgDifPha != 0)
      && ( Cipd_inh_dephia == 0))
   {
      u16LocalCrkHALRead2 = (uint16)((u16LocalCrkHALRead2 + 3840) % 7680);
      u16LocalCrkHALRead1 =
         (uint16)((u16LocalAcquianglecrankshaft + 23040) % 46080);
   }
   else
   {
      u16LocalCrkHALRead1 =
         (uint16)MATHSRV_udtMIN(u16LocalAcquianglecrankshaft, 46079);
   }

   VEMS_vidSET(Sync_agCkPosnRef1 , u16LocalCrkHALRead1);
   VEMS_vidSET(Ext_agCkPosnCurRef2, u16LocalCrkHALRead2);
   CKMNGIF_vidNoExCyl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidNoExCyl                                         */
/* !Description :  Ce bloc permet de produire, à récurrence temporelle et     */
/*                 moteur synchronisé, les informations « numéro du cylindre  */
/*                 en phase d’échappement » et « numéro du prochain cylindre  */
/*                 en phase d’échappement ».                                  */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Offset_reperes_ang;                                          */
/*  input uint16 Periode_angulaire;                                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 Sync_agCkPosnRef1;                                           */
/*  input uint8 Table_cyl_phys_ordre_allumage[6];                             */
/*  output uint8 Eng_noExCyl;                                                 */
/*  output uint8 Eng_noExNxtCyl;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidNoExCyl(void)
{
   uint8  u8LocalCounter;
   uint8  u8LocalEngnoExCyl;
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalEngNoExNxtCyl;
   uint16 u16LocalSync_agCkPosnRef1;
   uint16 u16LocalOffset_reperes_ang;
   uint16 u16LocalPeriode_angulaire;
   sint32 s32LocalCKMNGIF;
   sint32 s32LocalComp;
   sint32 s32LocalAng;
   sint32 s32LocalCalc;


   VEMS_vidGET(Offset_reperes_ang, u16LocalOffset_reperes_ang);
   VEMS_vidGET(Periode_angulaire, u16LocalPeriode_angulaire);
   s32LocalAng = (sint32)(u16LocalOffset_reperes_ang - 360);
   s32LocalCKMNGIF = 64 * s32LocalAng;
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   VEMS_vidGET(Sync_agCkPosnRef1, u16LocalSync_agCkPosnRef1);
   if (u16LocalSync_agCkPosnRef1 < s32LocalCKMNGIF)
   {
      if (u8LocalExt_noCylEng == 3)
      {
         u8LocalCounter = 2;
      }
      else
      {
         u8LocalCounter = 3;
      }
   }
   else
   {
      s32LocalCalc = s32LocalAng + u16LocalPeriode_angulaire;
      s32LocalComp = (64 * s32LocalCalc);

      if (u16LocalSync_agCkPosnRef1 < s32LocalComp)
      {
         u8LocalCounter = 0;
      }
      else
      {
         s32LocalComp = s32LocalCalc + u16LocalPeriode_angulaire;
         s32LocalComp = (64 * s32LocalComp);

         if (u16LocalSync_agCkPosnRef1 < s32LocalComp)
         {
            u8LocalCounter = 1;
         }
         else
         {
            u8LocalCounter = 2;
         }
      }
   }

   u8LocalEngnoExCyl = Table_cyl_phys_ordre_allumage[u8LocalCounter];
   u8LocalEngnoExCyl = (uint8)MATHSRV_udtMIN(u8LocalEngnoExCyl, 5);
   u8LocalEngnoExCyl = (uint8)(u8LocalEngnoExCyl + 1);
   VEMS_vidSET(Eng_noExCyl, u8LocalEngnoExCyl);

   if (u8LocalExt_noCylEng != 0)
   {
      u8LocalCounter = (uint8)((u8LocalCounter + 1) % u8LocalExt_noCylEng);
   }

   u8LocalEngNoExNxtCyl = Table_cyl_phys_ordre_allumage[u8LocalCounter];
   u8LocalEngNoExNxtCyl = (uint8)MATHSRV_udtMIN(u8LocalEngNoExNxtCyl, 5);
   u8LocalEngNoExNxtCyl = (uint8)(u8LocalEngNoExNxtCyl + 1);
   VEMS_vidSET(Eng_noExNxtCyl, u8LocalEngNoExNxtCyl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidBdcTreatment                                    */
/* !Description :  Fonction qui déclenche le  calcul du régime moteur au PMB .*/
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CKMNGIF_vidCalcBdcEngSpd();                              */
/*  input boolean Sync_bAcvBDCEngSpdClcn_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidBdcTreatment(void)
{
   if (Sync_bAcvBDCEngSpdClcn_C !=0)
   {
      CKMNGIF_vidCalcBdcEngSpd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidCalcBdcEngSpd                                   */
/* !Description :  Fonction de calcul du régime moteur au PMB                 */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint32 Acqui_periode_moteur;                                        */
/*  input uint16 Periode_moteur_calc;                                         */
/*  input uint16 CKMNGIF_u16EngSpdClcn;                                       */
/*  output uint16 Periode_moteur_calc;                                        */
/*  output uint16 CKMNGIF_u16EngSpdClcn;                                      */
/*  output uint16 Regime_moteur;                                              */
/*  output uint16 Ext_nEngBDC;                                                */
/*  output uint16 Ext_nEngFineResl;                                           */
/*  output uint16 Ext_nEng;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidCalcBdcEngSpd(void)
{
   uint8          u8LocalExt_noCylEng;
   uint16         u16LocalExt_nEng;
   uint16         u16LocalExt_nEngFineResl;
   uint32         u32LocalPeriod;
   uint32         u32LocalDenom;
   uint32         u32LocalResult;


   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   VEMS_vidGET(Acqui_periode_moteur, u32LocalPeriod);

   if (u32LocalPeriod <= 8388416)
   {
      Periode_moteur_calc = (uint16)((u32LocalPeriod + 64) / 128);
   }
   else
   {
      Periode_moteur_calc = 65535;
   }

   if (  (Periode_moteur_calc != 0)
      && (u8LocalExt_noCylEng != 0))
   {
      u32LocalDenom = (uint32)(Periode_moteur_calc * u8LocalExt_noCylEng);

      u32LocalResult = 37500000uL / u32LocalDenom;
      CKMNGIF_u16EngSpdClcn = (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
      u16LocalExt_nEng = (uint16)(CKMNGIF_u16EngSpdClcn / 8);
      u16LocalExt_nEngFineResl = (uint16)(CKMNGIF_u16EngSpdClcn / 2);
      VEMS_vidSET(Regime_moteur, u16LocalExt_nEng);
      u16LocalExt_nEng = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 8000);
      u16LocalExt_nEngFineResl =
         (uint16)MATHSRV_udtMIN(u16LocalExt_nEngFineResl, 32000);
      VEMS_vidSET(Ext_nEngBDC, u16LocalExt_nEng);
      VEMS_vidSET(Ext_nEngFineResl, u16LocalExt_nEngFineResl);
      u16LocalExt_nEng = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 7500);
      VEMS_vidSET(Ext_nEng, u16LocalExt_nEng);
   }
   else
   {
      CKMNGIF_u16EngSpdClcn = 0;
      VEMS_vidSET(Regime_moteur, 0);
      VEMS_vidSET(Ext_nEngFineResl, 0);
      VEMS_vidSET(Ext_nEngBDC, 0);
      VEMS_vidSET(Ext_nEng, 0);
   }
}

/*------------------------------- end of file --------------------------------*/