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
/* !File            : FUCNS_FCT2.C                                            */
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
/*   1 / FUCNS_vidUpdatingTotalInjTime                                        */
/*   2 / FUCNS_vidCalcPseudoConso                                             */
/*   3 / FUCNS_vidCalFuelUseBwnFrmeInjDir                                     */
/*   4 / FUCNS_vidCalcFuelUseNotCntInjDir                                     */
/*   5 / FUCNS_vidCalcFuelConsBwnFrInjDir                                     */
/*   6 / FUCNS_vidCalcFuelConsoInjDir                                         */
/*   7 / FUCNS_vidCalcInstantConsoInjDir                                      */
/*   8 / FUCNS_vidActTotalInjFuelInjDir                                       */
/*   9 / FUCNS_vidFinalInstructionCalc                                        */
/*   10 / FUCNS_vidSendFrame                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5139613 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066800                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FUCNS/FUCNS_FCT2.C_v         $*/
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
/* !Function    :  FUCNS_vidUpdatingTotalInjTime                              */
/* !Description :  Total_injection_time est ré-initialisée à la valeur de     */
/*                 Fuel_used_not_counted pour la trame suivante               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Fuel_used_not_counted;                                       */
/*  output uint32 FuCns_mFuInjTot;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidUpdatingTotalInjTime(void)
{
   uint16 u16LocalFuel_used_not_counted;


   VEMS_vidGET(Fuel_used_not_counted, u16LocalFuel_used_not_counted);
   VEMS_vidSET(FuCns_mFuInjTot, u16LocalFuel_used_not_counted);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcPseudoConso                                   */
/* !Description :  Clacule de la pseudo consommation.                         */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FUCNS_vidCalFuelUseBwnFrmeInjDir();                      */
/*  extf argret void FUCNS_vidCalcFuelUseNotCntInjDir();                      */
/*  extf argret void FUCNS_vidCalcFuelConsBwnFrInjDir();                      */
/*  extf argret void FUCNS_vidCalcFuelConsoInjDir();                          */
/*  extf argret void FUCNS_vidCalcInstantConsoInjDir();                       */
/*  extf argret void FUCNS_vidActTotalInjFuelInjDir();                        */
/*  input uint8 Ext_stTypInjSysCf;                                            */
/*  input boolean Moteur_tournant;                                            */
/*  input uint16 FuCns_mFuWoutPurgeOxC;                                       */
/*  output uint16 FuCns_mFuWoutPurgeOxCTemp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcPseudoConso(void)
{
   boolean bLocalMoteur_tournant;
   uint8   u8LocalExt_stTypInjSysCf;
   uint16  u16LocalFuCns_mFuWoutPurgeOxC;


   VEMS_vidGET(Ext_stTypInjSysCf, u8LocalExt_stTypInjSysCf);
   if (u8LocalExt_stTypInjSysCf == 1)
   {
      VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
      if (bLocalMoteur_tournant !=0)
      {
         VEMS_vidGET(FuCns_mFuWoutPurgeOxC, u16LocalFuCns_mFuWoutPurgeOxC);
         FuCns_mFuWoutPurgeOxCTemp = u16LocalFuCns_mFuWoutPurgeOxC;
      }
      else
      {
         FuCns_mFuWoutPurgeOxCTemp = 0;
      }
      FUCNS_vidCalFuelUseBwnFrmeInjDir();
      FUCNS_vidCalcFuelUseNotCntInjDir();
      FUCNS_vidCalcFuelConsBwnFrInjDir();
      FUCNS_vidCalcFuelConsoInjDir();
      FUCNS_vidCalcInstantConsoInjDir();
      FUCNS_vidActTotalInjFuelInjDir();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalFuelUseBwnFrmeInjDir                           */
/* !Description :  Le coefficient "1/10 " appliqué à Cpc_fuel_mass_flow_rate  */
/*                 permet de passer de [kg/s] à [kg/100ms]. Le coefficient    */
/*                 "1e-9" appliqué à Rho_carburant permet de passer de [g/L] à*/
/*                 [kg/mm3].                                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint16 FuCns_mFuWoutPurgeOxCTemp;                                   */
/*  input uint8 Rho_carburant;                                                */
/*  output uint16 Fuel_used_between_frame_InjDir;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalFuelUseBwnFrmeInjDir(void)
{
   uint16 u16LocalCpc_fuel_mass_flow_rate;
   uint16 u16LocalDenom;
   uint32 u32LocalTemp;


   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   u32LocalTemp = ( (FuCns_mFuWoutPurgeOxCTemp * 5)
                  + (u16LocalCpc_fuel_mass_flow_rate * 64));
   u32LocalTemp = ((u32LocalTemp * 625) + 2 ) / 4;
   u32LocalTemp = u32LocalTemp * 5;
   u16LocalDenom = (uint16)(Rho_carburant + 1792);
   u32LocalTemp = u32LocalTemp / u16LocalDenom;
   Fuel_used_between_frame_InjDir = (uint16)((u32LocalTemp + 8192) / 16384);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcFuelUseNotCntInjDir                           */
/* !Description :  Le coefficient "1e-9" appliqué à Rho_carburant permet de   */
/*                 passer de [g/L] à [kg/mm3].                                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint16 Fuel_used_between_frame_InjDir;                              */
/*  input uint8 Rho_carburant;                                                */
/*  input uint16 FuCns_mFuWoutPurgeOxCTemp;                                   */
/*  output uint16 Fuel_used_not_counted_InjDir;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcFuelUseNotCntInjDir(void)
{
   uint16 u16LocalRhoCarburant;
   uint16 u16LocalCpc_fuel_mass_flow_rate;
   uint32 u32LocalResult;
   uint32 u32Local_flow_rate;
   uint32 u32LocalTemp;
   uint32 u32LocalMod;

   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);
   u32LocalTemp = (uint32)(Fuel_used_between_frame_InjDir * 65536);
   u16LocalRhoCarburant = (uint16)(Rho_carburant + 1792);
   if (u32LocalTemp > (UINT32_MAX / (uint32)u16LocalRhoCarburant))
   {
      u32LocalMod = u32LocalTemp % 15625;
      u32LocalMod = ((u32LocalMod * u16LocalRhoCarburant) + 7812) / 15625;
      u32LocalTemp = u32LocalTemp  / 15625UL;
      u32LocalTemp = (u32LocalTemp * u16LocalRhoCarburant) + u32LocalMod;
   }
   else
   {
      u32LocalTemp = u32LocalTemp * u16LocalRhoCarburant;
      u32LocalTemp = (u32LocalTemp + 7812) / 15625UL;
   }
   u32Local_flow_rate = ( (u16LocalCpc_fuel_mass_flow_rate * 64)
                        + (FuCns_mFuWoutPurgeOxCTemp * 5))
                      / 5;
   if (u32LocalTemp >= u32Local_flow_rate)
   {
      Fuel_used_not_counted_InjDir = 0;
   }
   else
   {
      u32LocalResult = (u32Local_flow_rate - u32LocalTemp);
      Fuel_used_not_counted_InjDir =
         (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcFuelConsBwnFrInjDir                           */
/* !Description :  Le coefficient "1/10 " appliqué à Cpc_fuel_mass_flow_rate  */
/*                 permet de passer de [kg/s] à [kg/100ms]. Le coefficient    */
/*                 "1e-9" appliqué à Rho_carburant permet de passer de [g/L] à*/
/*                 [kg/ mm3].                                                 */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Cpc_fuel_mass_flow_rate;                                     */
/*  input uint16 FuCns_mFuWoutPurgeOxCTemp;                                   */
/*  input uint16 Fuel_used_not_counted_InjDir;                                */
/*  input uint8 Rho_carburant;                                                */
/*  output uint16 Conso_carb_entre_trame_InjDir;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcFuelConsBwnFrInjDir(void)
{
   uint16 u16LocalDen;
   uint16 u16LocalCpc_fuel_mass_flow_rate;
   sint32 s32LocalCalc;
   sint32 s32LocalRest;
   sint32 s32LocalRate;


   VEMS_vidGET(Cpc_fuel_mass_flow_rate, u16LocalCpc_fuel_mass_flow_rate);

   s32LocalCalc = (sint32)( ( FuCns_mFuWoutPurgeOxCTemp
                            - Fuel_used_not_counted_InjDir)
                          * 5);
   s32LocalRate = u16LocalCpc_fuel_mass_flow_rate * 64;
   s32LocalCalc = (s32LocalCalc + s32LocalRate) * 125;
   s32LocalRest = (s32LocalCalc % 4096) * 25;
   if (s32LocalCalc >= 0)
   {
      s32LocalRest = (s32LocalRest + 2048) / 4096;
      s32LocalCalc = (s32LocalCalc + 2048) / 4096;
   }
   else
   {
      s32LocalRest = (s32LocalRest - 2048) / 4096;
      s32LocalCalc = (s32LocalCalc - 2048) / 4096;
   }
   s32LocalCalc = (s32LocalCalc * 25) + s32LocalRest;

   u16LocalDen = (uint16)(Rho_carburant + 1792);
   s32LocalCalc = s32LocalCalc / (sint32)u16LocalDen;
   Conso_carb_entre_trame_InjDir = (uint16)MATHSRV_udtMAX(s32LocalCalc, 0);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcFuelConsoInjDir                               */
/* !Description :  Lorsque Conso_carburant_can_InjDir atteint sa valeur       */
/*                 maximale, celle-ci est réinitialisée à 0.                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Conso_carburant_can_InjDir;                                   */
/*  input uint16 Fuel_used_between_frame_InjDir;                              */
/*  output uint8 Conso_carburant_can_InjDir;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcFuelConsoInjDir(void)
{
   uint32 u32LocalCalc;


   u32LocalCalc = (uint32)( Conso_carburant_can_InjDir
                          + Fuel_used_between_frame_InjDir);
   if (u32LocalCalc >= 255)
   {
      Conso_carburant_can_InjDir = 0;
   }
   else
   {
      Conso_carburant_can_InjDir = (uint8)u32LocalCalc;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidCalcInstantConsoInjDir                            */
/* !Description :  Le coefficient "3.6" appliqué à Vitesse_vehicule permet de */
/*                 passer de [km/h] à [100km/100ms] et                        */
/*                 Conso_carburant_entre_trame_InjDir de passer de [mm3] en   */
/*                 [L].Nous obtenons ainsi, après filtrage, une consommation  */
/*                 instantanée Conso_inst_InjDir en L/100km.                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint16 Conso_carb_entre_trame_InjDir;                               */
/*  input uint8 Conso_carburant_inst_filtre_gain;                             */
/*  input uint32 FUCNS_u32InstantUsedFuelMem;                                 */
/*  output uint8 Conso_Inst_InjDir;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidCalcInstantConsoInjDir(void)
{
   uint8  u8LocalVitesse_vehicule;
   uint16 u16FilterInput;
   uint32 u32FilterInputTemp;

   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   if (u8LocalVitesse_vehicule != 0)
   {
      u32FilterInputTemp = (uint32)( (Conso_carb_entre_trame_InjDir * 150)
                                   / u8LocalVitesse_vehicule);
      u16FilterInput = (uint16)MATHSRV_udtMIN(u32FilterInputTemp, 255);
   }
   else
   {
      u16FilterInput = 0;
   }
   Conso_Inst_InjDir =
      (uint8)MATHSRV_u16FirstOrderFilterGu8(Conso_carburant_inst_filtre_gain,
                                            &FUCNS_u32InstantUsedFuelMem,
                                            u16FilterInput);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidActTotalInjFuelInjDir                             */
/* !Description :  Actualisation totale du carburant.                         */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Fuel_used_not_counted_InjDir;                                */
/*  output uint16 FuCns_mFuWoutPurgeOxC;                                      */
/*  output uint16 Fuel_used_not_counted_InjDir;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidActTotalInjFuelInjDir(void)
{
   VEMS_vidSET(FuCns_mFuWoutPurgeOxC, Fuel_used_not_counted_InjDir);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidFinalInstructionCalc                              */
/* !Description :  Ce bloc calcule la consigne réelle finale de débit         */
/*                 d’essence qui a été appliquée.                             */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  L.DHIB                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 InjrSys_mFuInjEstim;                                         */
/*  output uint16 InjCtl_mfFuReq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidFinalInstructionCalc(void)
{
   uint16 u16LocalInjrSys_mFuInjEstim;
   uint32 u32LocalInjrSysmFuInjEstim;


   VEMS_vidGET(InjrSys_mFuInjEstim, u16LocalInjrSys_mFuInjEstim);
   u32LocalInjrSysmFuInjEstim = u16LocalInjrSys_mFuInjEstim
                              * (uint32)15625;
   u16LocalInjrSys_mFuInjEstim = (uint16)( (u32LocalInjrSysmFuInjEstim + 65536)
                                         / 131072);
   u16LocalInjrSys_mFuInjEstim =
      (uint16)MATHSRV_udtMIN(u16LocalInjrSys_mFuInjEstim, 1600);
   VEMS_vidSET(InjCtl_mfFuReq, u16LocalInjrSys_mFuInjEstim);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FUCNS_vidSendFrame                                         */
/* !Description :  On sélectionne ici les informations à transmettre sur le   */
/*                 CAN en fonction de l’architecture d’injection.             */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  L.DHIB                                                     */
/* !Trace_To    :  VEMS_E_11_00116_022.01                                     */
/*                 VEMS_E_11_00116_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stTypInjSysCf;                                            */
/*  input boolean FuCns_bFuCnsTyp;                                            */
/*  input boolean FuCns_bAcvFuCnsTyp_C;                                       */
/*  input uint8 Conso_Inst_InjDir;                                            */
/*  input uint8 Conso_carburant_can_InjInd;                                   */
/*  input uint8 Conso_carburant_can_InjDir;                                   */
/*  input uint8 Conso_Inst_InjInd;                                            */
/*  output uint8 Consommation_carburant_inst;                                 */
/*  output uint8 Conso_Inst_InjDir;                                           */
/*  output uint8 FuCns_volFuCnsTot;                                           */
/*  output uint8 Conso_carburant_can_InjInd;                                  */
/*  output boolean FuCns_bFuCnsTyp;                                           */
/*  output uint8 Conso_carburant_can_InjDir;                                  */
/*  output uint8 Conso_Inst_InjInd;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FUCNS_vidSendFrame(void)
{
   boolean bLocalFuCns_bFuCnsTyp;
   uint8   u8LocalExt_stTypInjSysCf;


   VEMS_vidGET(Ext_stTypInjSysCf, u8LocalExt_stTypInjSysCf);
   VEMS_vidGET(FuCns_bFuCnsTyp, bLocalFuCns_bFuCnsTyp);
   if (  (u8LocalExt_stTypInjSysCf == 1)
      && (FuCns_bAcvFuCnsTyp_C != 0))
   {
      VEMS_vidSET(Consommation_carburant_inst, Conso_Inst_InjDir);
      if (bLocalFuCns_bFuCnsTyp != 0)
      {
         VEMS_vidSET(FuCns_volFuCnsTot, Conso_carburant_can_InjInd);
         VEMS_vidSET(FuCns_bFuCnsTyp, 0);
      }
      else
      {
         VEMS_vidSET(FuCns_volFuCnsTot, Conso_carburant_can_InjDir);
         VEMS_vidSET(FuCns_bFuCnsTyp, 1);
      }
   }
   else
   {
      VEMS_vidSET(Consommation_carburant_inst, Conso_Inst_InjInd);
      VEMS_vidSET(FuCns_volFuCnsTot, Conso_carburant_can_InjInd);
      VEMS_vidSET(FuCns_bFuCnsTyp, 0);
   }
}
/*-------------------------- end of file -------------------------------------*/