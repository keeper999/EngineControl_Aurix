/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FUCNS                                                   */
/* !Description     : FUCNS component.                                        */
/*                                                                            */
/* !Module          : FUCNS                                                   */
/* !Description     : CONSOMMATION CARBURANT                                  */
/*                                                                            */
/* !File            : FUCNS_FCT1.C                                            */
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
/*   1 / FUCNS_vidInitOutput                                                  */
/*   2 / FUCNS_vidInit                                                        */
/*   3 / FUCNS_vidCalcTotalMassInj                                            */
/*   4 / FUCNS_vidDirectInjCount                                              */
/*   5 / FUCNS_vidCalcRealConso                                               */
/*   6 / FUCNS_vidCalcUsedFuelPerHour                                         */
/*   7 / FUCNS_vidCalcFuelUsedBetweenFram                                     */
/*   8 / FUCNS_vidCalcFuelUsedNotCounted                                      */
/*   9 / FUCNS_vidCalcUsedFuel                                                */
/*   10 / FUCNS_vidCalcInstantUsedFuel                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5139613 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066800                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FUCNS/FUCNS_FCT1.C_v         $*/
/* $Revision::   1.6      $$Author::   HHAMLAOU       $$Date::   02 Sep 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   02 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FUCNS.H"
#include "FUCNS_L.H"
#include "FUCNS_IM.H"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidInitOutput                                        */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 FuCns_volFuCnsTot;                                           */
/*  output uint16 Consommation_carburant_horaire;                             */
/*  output uint8 Consommation_carburant_inst;                                 */
/*  output boolean FuCns_bFuCnsTyp;                                           */
/*  output uint16 Fuel_used_between_frame;                                    */
/*  output uint16 InjCtl_mfFuReq;                                             */
/*  output uint8 Conso_Inst_InjDir;                                           */
/*  output uint32 FUCNS_u32InstantUsedFuelMem;                                */
/*  output uint32 FUCNS_u32InstantUsedFuelMem1;                               */
/*  output uint8 Conso_Inst_InjInd;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidInitOutput(void)
{
   VEMS_vidSET(FuCns_volFuCnsTot, 0);
   VEMS_vidSET(Consommation_carburant_horaire, 0);
   VEMS_vidSET(Consommation_carburant_inst, 0);
   VEMS_vidSET(FuCns_bFuCnsTyp, 0);
   VEMS_vidSET(Fuel_used_between_frame, 0);
   VEMS_vidSET(InjCtl_mfFuReq, 0);
   Conso_Inst_InjDir = 0;
   FUCNS_u32InstantUsedFuelMem = 0;
   FUCNS_u32InstantUsedFuelMem1 = 0;
   Conso_Inst_InjInd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidInit                                              */
/* !Description :  Bloc d'initialisation des variables appelé lors du reset   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint32 FuCns_mFuInjTot;                                            */
/*  output uint16 Fuel_used_not_counted;                                      */
/*  output uint16 FuCns_mFuWoutPurgeOxC;                                      */
/*  output uint16 Fuel_used_not_counted_InjDir;                               */
/*  output uint8 Conso_carburant_can_InjInd;                                  */
/*  output uint8 Conso_carburant_can_InjDir;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidInit(void)
{
   VEMS_vidSET(FuCns_mFuInjTot, 0);
   VEMS_vidSET(Fuel_used_not_counted, 0);
   VEMS_vidSET(FuCns_mFuWoutPurgeOxC, 0);
   Fuel_used_not_counted_InjDir = 0;
   Conso_carburant_can_InjInd = 0;
   Conso_carburant_can_InjDir = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcTotalMassInj                                  */
/* !Description :  Lors de chaque occurrence de l’évènement injection, on     */
/*                 incrémente le compteur de la masse totale injectée estimée */
/*                 pour le calcul de la consommation carburant totale.        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  L.DHIB                                                     */
/* !Trace_To    :  VEMS_E_11_00116_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void FUCNS_vidDirectInjCount();                               */
/*  input uint16 InjrSys_mFuInjEstim;                                         */
/*  input uint32 FuCns_mFuInjTot;                                             */
/*  input uint8 Ext_stTypInjSysCf;                                            */
/*  output uint32 FuCns_mFuInjTot;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcTotalMassInj(void)
{
   uint8  u8LocalExt_stTypInjSysCf;
   uint16 u16LocalInjrSys_mFuInjEstim;
   uint32 u32Localcompare;
   uint32 u32LocalFuCns_mFuInjTot;


   VEMS_vidGET(InjrSys_mFuInjEstim, u16LocalInjrSys_mFuInjEstim);
   VEMS_vidGET(FuCns_mFuInjTot, u32LocalFuCns_mFuInjTot);
   VEMS_vidGET(Ext_stTypInjSysCf, u8LocalExt_stTypInjSysCf);
   u32Localcompare = UINT32_MAX - (uint32)u16LocalInjrSys_mFuInjEstim;
   if (u32LocalFuCns_mFuInjTot < u32Localcompare)
   {
      u32LocalFuCns_mFuInjTot = u16LocalInjrSys_mFuInjEstim
                              + u32LocalFuCns_mFuInjTot;
   }
   else
   {
      u32LocalFuCns_mFuInjTot = UINT32_MAX;
   }
   VEMS_vidSET(FuCns_mFuInjTot, u32LocalFuCns_mFuInjTot);

   if (u8LocalExt_stTypInjSysCf == 1)
   {
      FUCNS_vidDirectInjCount();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidDirectInjCount                                    */
/* !Description :  Ce compteur servira à calculer la consommation instantanée */
/*                 en injection directe sans prendre en compte la             */
/*                 surconsommation due à la purge du catalyseur.              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  L.DHIB                                                     */
/* !Trace_To    :  VEMS_E_11_00116_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean Dnstr_purge_cata_rich;                                      */
/*  input boolean Dnstr_purge_cata_low;                                       */
/*  input uint16 InjrSys_mFuInjEstim;                                         */
/*  input uint16 FuCns_mFuWoutPurgeOxC;                                       */
/*  input uint16 Ext_pDsThrMesSI;                                             */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_pDsThrMesSI_A[16];                                       */
/*  input uint16 Ext_nEng_A[16];                                              */
/*  input uint16 FuCns_mFuReqWoutPurgeOxC_M[16][16];                          */
/*  input uint32 Objectif_richesse_global;                                    */
/*  output uint16 FuCns_mFuWoutPurgeOxC;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidDirectInjCount(void)
{
   boolean bLocalDnstr_purge_cata_rich;
   boolean bLocalDnstr_purge_cata_low;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalInjrSys_mFuInjEstim;
   uint16  u16LocalFuCns_mFuWoutPurgeOxC;
   uint16  u16LocalExt_pDsThrMesSI;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalExtpDsThrMesSI;
   uint16  u16LocalExtNEng;
   uint16  u16LocalInterp2D;
   uint32  u32LocalObjectif_richesse_global;
   uint32  u32LocalFuCnsMFuWoutPurgeOxC;
   uint32  u32LocalObjRichGlbInterp;
   uint32  u32LocalRest;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Dnstr_purge_cata_rich, bLocalDnstr_purge_cata_rich);
   VEMS_vidGET(Dnstr_purge_cata_low, bLocalDnstr_purge_cata_low);
   VEMS_vidGET(InjrSys_mFuInjEstim, u16LocalInjrSys_mFuInjEstim);
   VEMS_vidGET(FuCns_mFuWoutPurgeOxC, u16LocalFuCns_mFuWoutPurgeOxC);
   if (  (  (u8LocalCoPTSt_stEng != Stop)
         && (u8LocalCoPTSt_stEng != Driven_Restart))
      && (bLocalDnstr_purge_cata_rich == 0)
      && (bLocalDnstr_purge_cata_low == 0))
   {
      u32LocalFuCnsMFuWoutPurgeOxC = u16LocalInjrSys_mFuInjEstim
                                   + u16LocalFuCns_mFuWoutPurgeOxC;
      u16LocalFuCns_mFuWoutPurgeOxC =
         (uint16)MATHSRV_udtMIN(u32LocalFuCnsMFuWoutPurgeOxC, 65535);
   }
   else
   {
      VEMS_vidGET(Ext_pDsThrMesSI, u16LocalExt_pDsThrMesSI);
      VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
      u16LocalExtpDsThrMesSI =
         MATHSRV_u16CalcParaIncAryU16(Ext_pDsThrMesSI_A,
                                      u16LocalExt_pDsThrMesSI,
                                      16);
      u16LocalExtNEng = MATHSRV_u16CalcParaIncAryU16(Ext_nEng_A,
                                                     u16LocalExt_nEng,
                                                     16);
      u16LocalInterp2D =
         MATHSRV_u16Interp2d(&FuCns_mFuReqWoutPurgeOxC_M[0][0],
                             u16LocalExtpDsThrMesSI,
                             u16LocalExtNEng,
                             16);
      if (u16LocalInterp2D != 0)
      {
         if (  (u8LocalCoPTSt_stEng != Stop)
            && (u8LocalCoPTSt_stEng != Driven_Restart))
         {
            VEMS_vidGET(Objectif_richesse_global,
                        u32LocalObjectif_richesse_global);
            if (u32LocalObjectif_richesse_global > (UINT32_MAX / 147UL))
            {
               u32LocalObjRichGlbInterp = u32LocalObjectif_richesse_global
                                        / 65536;
               u32LocalRest = (u32LocalObjectif_richesse_global % 65536) * 147;
               u32LocalRest = u32LocalRest / 65536;
               u32LocalObjRichGlbInterp = u32LocalObjRichGlbInterp * 147;
               u32LocalObjRichGlbInterp = (( u32LocalObjRichGlbInterp
                                           + u32LocalRest) + 10) / 20;
               if (u32LocalObjRichGlbInterp >= 65535UL)
               {
                  u16LocalFuCns_mFuWoutPurgeOxC = 65535;
               }
               else
               {
                  u32LocalObjRichGlbInterp = u32LocalObjRichGlbInterp
                                           * u16LocalInterp2D;
                  u32LocalFuCnsMFuWoutPurgeOxC =
                     u32LocalObjRichGlbInterp + u16LocalFuCns_mFuWoutPurgeOxC;
                  u16LocalFuCns_mFuWoutPurgeOxC =
                     (uint16)MATHSRV_udtMIN(u32LocalFuCnsMFuWoutPurgeOxC,
                                            65535);
               }
            }
            else
            {
               if (u32LocalObjectif_richesse_global <= 1141290)
               {
                  u32LocalRest = u32LocalObjectif_richesse_global * 147;
                  u32LocalObjRichGlbInterp = u32LocalRest / 2560;
                  u32LocalRest = u32LocalRest % 2560;
                  u32LocalRest = ( u32LocalRest
                                 * u16LocalInterp2D)
                               / 2560;
                  u32LocalObjRichGlbInterp = ( u32LocalObjRichGlbInterp
                                             * u16LocalInterp2D)
                                           + u32LocalRest;
                  u32LocalObjRichGlbInterp = ( u32LocalObjRichGlbInterp
                                             + 256)
                                           / 512;
                  u32LocalFuCnsMFuWoutPurgeOxC = u32LocalObjRichGlbInterp
                                               + u16LocalFuCns_mFuWoutPurgeOxC;
                  u16LocalFuCns_mFuWoutPurgeOxC =
                     (uint16)MATHSRV_udtMIN(u32LocalFuCnsMFuWoutPurgeOxC,
                                            65535);
               }
               else
               {
                  u16LocalFuCns_mFuWoutPurgeOxC = 65535;
               }
            }
         }
         else
         {
            u32LocalFuCnsMFuWoutPurgeOxC = u16LocalInterp2D
                                         + u16LocalFuCns_mFuWoutPurgeOxC;
            u16LocalFuCns_mFuWoutPurgeOxC =
               (uint16)MATHSRV_udtMIN(u32LocalFuCnsMFuWoutPurgeOxC, 65535);
         }
      }
   }
   VEMS_vidSET(FuCns_mFuWoutPurgeOxC, u16LocalFuCns_mFuWoutPurgeOxC);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcRealConso                                     */
/* !Description :  Ce bloc calcule la consommation horaire de carburant, la   */
/*                 consommation de carburant depuis l'initialisation du       */
/*                 calculateur, la consommation totale de carburant ainsi que */
/*                 la consommation instantanée.                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FUCNS_vidCalcUsedFuelPerHour();                          */
/*  extf argret void FUCNS_vidCalcFuelUsedBetweenFram();                      */
/*  extf argret void FUCNS_vidCalcFuelUsedNotCounted();                       */
/*  extf argret void FUCNS_vidCalcUsedFuel();                                 */
/*  extf argret void FUCNS_vidCalcInstantUsedFuel();                          */
/*  extf argret void FUCNS_vidUpdatingTotalInjTime();                         */
/*  input boolean Moteur_tournant;                                            */
/*  input uint32 FuCns_mFuInjTot;                                             */
/*  output uint32 FuCns_mFuInjTotTemp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcRealConso(void)
{
   boolean bLocalMoteur_tournant;
   uint32  u32LocalFuCns_mFuInjTot;


   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   if (bLocalMoteur_tournant != 0)
   {
      VEMS_vidGET(FuCns_mFuInjTot, u32LocalFuCns_mFuInjTot);
      FuCns_mFuInjTotTemp = u32LocalFuCns_mFuInjTot;
   }
   else
   {
      FuCns_mFuInjTotTemp = 0;
   }
   FUCNS_vidCalcUsedFuelPerHour();
   FUCNS_vidCalcFuelUsedBetweenFram();
   FUCNS_vidCalcFuelUsedNotCounted();
   FUCNS_vidCalcUsedFuel();
   FUCNS_vidCalcInstantUsedFuel();
   FUCNS_vidUpdatingTotalInjTime();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcUsedFuelPerHour                               */
/* !Description :  Bloc de calcul de la consommation horaire de carburant     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint16 Fuel_used_not_counted;                                       */
/*  input uint32 FuCns_mFuInjTotTemp;                                         */
/*  input uint8 Rho_carburant;                                                */
/*  input uint16 Conso_carburant_entre_trame;                                 */
/*  input uint8 Conso_carburant_filtre_gain;                                  */
/*  input uint32 FUCNS_u32UsedFuelPerHourMem;                                 */
/*  output uint16 Conso_carburant_entre_trame;                                */
/*  output uint16 Consommation_carburant_horaire;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcUsedFuelPerHour(void)
{
   uint16 u16LocalCpc_fuel_mass_flow_rate;
   uint16 u16LocalFuel_used_not_counted;
   uint16 u16LocalConsomCarburantHoraire;
   uint16 u16FilterInput;
   uint16 u16LocalRhoCarburant;
   sint32 s32LocalDelta;
   uint32 u32FilterInput;
   uint32 u32LocalAbs;
   uint32 u32LocalSum1;
   uint32 u32LocalSum2;
   uint32 u32LocalResult;
   uint32 u32LocalProd;
   uint32 u32LocaldeltaRest;
   uint32 u32LocalRhoRest;


   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   VEMS_vidGET(Fuel_used_not_counted, u16LocalFuel_used_not_counted);

   if (FuCns_mFuInjTotTemp > u16LocalFuel_used_not_counted)
   {
      u32LocalAbs = FuCns_mFuInjTotTemp - u16LocalFuel_used_not_counted;
   }
   else
   {
      s32LocalDelta = (sint32)(FuCns_mFuInjTotTemp
                              - u16LocalFuel_used_not_counted);
      u32LocalAbs = (uint32)MATHSRV_udtABS(s32LocalDelta);
   }
   u32LocaldeltaRest = (u32LocalAbs % 4096) * 3125;
   u32LocalSum1 = ((u32LocalAbs / 4096) * 3125)
                  + (u32LocaldeltaRest / 4096);
   u16LocalRhoCarburant = (uint16)(Rho_carburant + 1792);
   if (u32LocalSum1 > (UINT32_MAX /(uint32)5))
   {
      u32LocalSum1 = (u32LocalSum1 + (u16LocalRhoCarburant / 2))
                     / u16LocalRhoCarburant;
      u32LocalSum1 = u32LocalSum1 * 5;
   }
   else
   {
      u32LocalSum1 = (u32LocalSum1 * 5)/ u16LocalRhoCarburant;
   }
   u32LocalProd = (uint32)(u16LocalCpc_fuel_mass_flow_rate * 40000);
   u32LocalRhoRest = u32LocalProd % u16LocalRhoCarburant;
   u32LocalSum2 = ((u32LocalProd / u16LocalRhoCarburant) * 5)
                  + ((u32LocalRhoRest * 5)/u16LocalRhoCarburant);
   u32LocalSum2 = u32LocalSum2 / 4096;
   if (FuCns_mFuInjTotTemp < u16LocalFuel_used_not_counted)
   {
      if (u32LocalSum1 >= u32LocalSum2)
      {
         u32LocalResult = 0;
      }
      else
      {
         u32LocalResult = u32LocalSum2 - u32LocalSum1;
    /*QAC Msg(3:3382):  error couldn't happen:u32LocalSum2 > u32LocalSum1 */
      }
   }
   else
   {
      u32LocalResult = u32LocalSum2 + u32LocalSum1;
   }
   Conso_carburant_entre_trame = (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
   u32FilterInput = (uint32)( ( ( Conso_carburant_entre_trame
                                * 4608)
                              + 12)
                            / 25);
   u16FilterInput = (uint16)MATHSRV_udtMIN(u32FilterInput, 65535);
   u16LocalConsomCarburantHoraire =
      MATHSRV_u16FirstOrderFilterGu8(Conso_carburant_filtre_gain,
                                     &FUCNS_u32UsedFuelPerHourMem,
                                     u16FilterInput);
   VEMS_vidSET(Consommation_carburant_horaire, u16LocalConsomCarburantHoraire);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcFuelUsedBetweenFram                           */
/* !Description :  Bloc de calcul de la quantité arrondie d'essence consommée */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint32 FuCns_mFuInjTotTemp;                                         */
/*  input uint8 Rho_carburant;                                                */
/*  output uint16 Fuel_used_between_frame;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcFuelUsedBetweenFram(void)
{
   uint8  u8LocalRest;
   uint16 u16LocalCpc_fuel_mass_flow_rate;
   uint16 u16LocalDenom;
   uint16 u16LocalTemp;
   uint16 u16LocalCpcfuelflow_rate;
   uint32 u32LocalTemp;
   uint32 u32LocalFuCnsTemp;


   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   u8LocalRest = (uint8)((FuCns_mFuInjTotTemp % 128) / 128);
   u32LocalFuCnsTemp = FuCns_mFuInjTotTemp / 128;
   u32LocalFuCnsTemp = u32LocalFuCnsTemp + u8LocalRest;
   u16LocalCpcfuelflow_rate =
               (uint16)((u16LocalCpc_fuel_mass_flow_rate + 5) / 10);
   u32LocalTemp = ((u32LocalFuCnsTemp + u16LocalCpcfuelflow_rate) * 125);
   u16LocalDenom = (uint16)(Rho_carburant + 1792);
   u32LocalTemp = u32LocalTemp / u16LocalDenom;
   u32LocalTemp = (u32LocalTemp * 125) / 512;
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u32LocalTemp, 65535);
   VEMS_vidSET(Fuel_used_between_frame, u16LocalTemp);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcFuelUsedNotCounted                            */
/* !Description :  Bloc de calcul du temps d'ouverture injecteur non pris en  */
/*                 compte dans la quantité d'essence consommée entre 2 trames */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Fuel_used_between_frame;                                     */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint8 Rho_carburant;                                                */
/*  input uint32 FuCns_mFuInjTotTemp;                                         */
/*  output uint16 Fuel_used_not_counted;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcFuelUsedNotCounted(void)
{
   uint16 u16LocalFuel_used_between_frame;
   uint16 u16LocalFuel_used_not_counted;
   uint16 u16LocalRhoCarburant;
   uint16 u16LocalCpc_fuel_mass_flow_rate;
   uint32 u32LocalCpc_fuel_mass_flow_rate;
   uint32 u32Local_flow_rate;
   uint32 u32LocalResult;
   uint32 u32LocalTemp;
   uint32 u32LocalMod;
   uint32 u32Localcompare;


   VEMS_vidGET(Fuel_used_between_frame, u16LocalFuel_used_between_frame);
   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   u32LocalTemp = (uint32)(u16LocalFuel_used_between_frame * 65536);
   u16LocalRhoCarburant = (uint16)(Rho_carburant + 1792);
   if (u32LocalTemp > (UINT32_MAX / (uint32)u16LocalRhoCarburant))
   {
      u32LocalMod = u32LocalTemp % 15625;
      u32LocalMod = ((u32LocalMod * u16LocalRhoCarburant) + 7812) / 15625;
      u32LocalTemp = u32LocalTemp / 15625;
      u32LocalTemp = (u32LocalTemp * u16LocalRhoCarburant) + u32LocalMod;
   }
   else
   {
      u32LocalTemp = u32LocalTemp * u16LocalRhoCarburant;
      u32LocalTemp = (u32LocalTemp + 7812) / 15625UL;
   }
   u32LocalCpc_fuel_mass_flow_rate =
      ( (uint32)( (u16LocalCpc_fuel_mass_flow_rate * 64)
                + 3)
      / 5);
   u32Localcompare = UINT32_MAX - u32LocalCpc_fuel_mass_flow_rate;
   if (FuCns_mFuInjTotTemp < u32Localcompare)
   {
      u32Local_flow_rate =
         FuCns_mFuInjTotTemp + u32LocalCpc_fuel_mass_flow_rate;
   }
   else
   {
      u32Local_flow_rate = UINT32_MAX;
   }

   if (u32LocalTemp >= u32Local_flow_rate)
   {
      u16LocalFuel_used_not_counted = 0;
   }
   else
   {
      u32LocalResult = (u32Local_flow_rate - u32LocalTemp);
      u16LocalFuel_used_not_counted =
         (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
   }
   VEMS_vidSET(Fuel_used_not_counted, u16LocalFuel_used_not_counted);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcUsedFuel                                      */
/* !Description :  Bloc de calcul de la consommation de carburant depuis      */
/*                 l'initialisation du calculateur et de la consommation      */
/*                 totale de carburant                                        */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  L.DHIB                                                     */
/* !Trace_To    :  VEMS_E_11_00116_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Fuel_used_between_frame;                                     */
/*  input uint32 Consommation_carburant_totale;                               */
/*  input uint8 Conso_carburant_can_InjInd;                                   */
/*  input boolean FuCns_bRstFuCnsTot_C;                                       */
/*  output uint8 Conso_carburant_can_InjInd;                                  */
/*  output uint32 Consommation_carburant_totale;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcUsedFuel(void)
{
   uint16 u16LocalFuel_used_between_frame;
   uint32 u32LocalConsoCarburantCanInjInd;
   uint32 u32LocalConsomCarburantTotal;
   uint32 u32LocalTemp;


   VEMS_vidGET(Fuel_used_between_frame, u16LocalFuel_used_between_frame);
   VEMS_vidGET(Consommation_carburant_totale, u32LocalConsomCarburantTotal);
   u32LocalConsoCarburantCanInjInd = (uint32)( Conso_carburant_can_InjInd
                                             + u16LocalFuel_used_between_frame);
   if (u32LocalConsoCarburantCanInjInd >= 255)
   {
      Conso_carburant_can_InjInd = 0;
   }
   else
   {
      Conso_carburant_can_InjInd = (uint8)u32LocalConsoCarburantCanInjInd;
   }
   if (FuCns_bRstFuCnsTot_C != 0)
   {
      VEMS_vidSET(Consommation_carburant_totale, 0);
   }
   else
   {
      u32LocalTemp = (UINT32_MAX - (uint32)u16LocalFuel_used_between_frame);
      if (u32LocalConsomCarburantTotal < u32LocalTemp)
      {
         u32LocalConsomCarburantTotal = ( u32LocalConsomCarburantTotal
                                        + u16LocalFuel_used_between_frame);
      }
      else
      {
         u32LocalConsomCarburantTotal = 4294967295UL;
      }
      VEMS_vidSET(Consommation_carburant_totale, u32LocalConsomCarburantTotal);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcInstantUsedFuel                               */
/* !Description :  Bloc de calcul la consommation instantanée de carburant    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  L.DHIB                                                     */
/* !Trace_To    :  VEMS_E_11_00116_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint16 Conso_carburant_entre_trame;                                 */
/*  input uint8 Conso_carburant_inst_filtre_gain;                             */
/*  input uint32 FUCNS_u32InstantUsedFuelMem1;                                */
/*  output uint8 Conso_Inst_InjInd;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcInstantUsedFuel(void)
{
   uint8  u8LocalVitesse_vehicule;
   uint16 u16FilterInput;
   uint32 u32FilterInputTemp;

   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   if (u8LocalVitesse_vehicule != 0)
   {
      u32FilterInputTemp = (uint32)( (Conso_carburant_entre_trame * 150)
                                   / u8LocalVitesse_vehicule);
      u16FilterInput = (uint16)MATHSRV_udtMIN(u32FilterInputTemp, 255);
   }
   else
   {
      u16FilterInput = 0;
   }
   Conso_Inst_InjInd =
      (uint8)MATHSRV_u16FirstOrderFilterGu8(Conso_carburant_inst_filtre_gain,
                                            &FUCNS_u32InstantUsedFuelMem1,
                                            u16FilterInput);
}

/*-------------------------- end of file -------------------------------------*/