/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FISARFUDET                                              */
/* !Description     : FISARFUDET component.                                   */
/*                                                                            */
/* !Module          : FISARFUDET                                              */
/* !Description     : DETECTION DE REMPLISSAGE CARBURANT POUR LA FONCTION     */
/*                    FISA.                                                   */
/*                                                                            */
/* !File            : FISARFUDET_FCT1.C                                       */
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
/*   1 / FISARFUDET_vidInit                                                   */
/*   2 / FISARFUDET_vidArretMoteur                                            */
/*   3 / FISARFUDET_vidClefOn                                                 */
/*   4 / FISARFUDET_vidCalculDelta                                            */
/*   5 / FISARFUDET_vidCalculValeursReset                                     */
/*   6 / FISARFUDET_vidCndCalcCoefLissage                                     */
/*   7 / FISARFUDET_vidCalcCoefLissage                                        */
/*   8 / FISARFUDET_vidCalcConsoDepRempl                                      */
/*   9 / FISARFUDET_vidConsomDepuisPlein                                      */
/*   10 / FISARFUDET_vidResetCoefEffectue                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 07467 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#060865                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/FISARFUDET/FISARFUDET_FCT1.C_v    $*/
/* $Revision::   1.6      $$Author::   bbris          $$Date::   16 Apr 2012 $*/
/* $Author::   bbris                                  $$Date::   16 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FISARFUDET.h"
#include "FISARFUDET_L.h"
#include "FISARFUDET_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidInit                                         */
/* !Description :  Fonction d'initialisation des variables EEPROM             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 FISA_facRst_nvm;                                              */
/*  input boolean RFuDet_bRstAdp_nvm;                                         */
/*  output uint8 FISA_facRst;                                                 */
/*  output boolean RFuDet_bRstAdp;                                            */
/*  output boolean RFuDet_bRstAdp_nvm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidInit(void)
{
   uint8   u8LocalFISA_facRst;


   u8LocalFISA_facRst = (uint8)MATHSRV_udtMIN(FISA_facRst_nvm, 128);
   VEMS_vidSET(FISA_facRst, u8LocalFISA_facRst);
   VEMS_vidSET(RFuDet_bRstAdp, RFuDet_bRstAdp_nvm);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidArretMoteur                                  */
/* !Description :  cette fonction permet de retourner le volume carburant à la*/
/*                 coupure moteur                                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Flev_fuel_level;                                              */
/*  output uint8 Ext_volFuOld;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidArretMoteur(void)
{
   uint8 u8LocalFlevFuelLevel;


   VEMS_vidGET(Flev_fuel_level, u8LocalFlevFuelLevel);
   Ext_volFuOld = u8LocalFlevFuelLevel;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidClefOn                                       */
/* !Description :  cette fonction permet de determiner le Volume carburant au */
/*                 key on                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_08_07467_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FISARFUDET_vidCalculDelta();                             */
/*  input uint8 Flev_fuel_level;                                              */
/*  input boolean Ext_bRFuDet;                                                */
/*  output uint8 Ext_volFuNew;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidClefOn(void)
{
   uint8 u8LocalFlevFuelLevel;


   VEMS_vidGET(Flev_fuel_level, u8LocalFlevFuelLevel);
   Ext_volFuNew = u8LocalFlevFuelLevel;
   if (Ext_bRFuDet == 0)
   {
      FISARFUDET_vidCalculDelta();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidCalculDelta                                  */
/* !Description :  cette fonction permet de détecter le remplissage du        */
/*                 réservoir                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Ext_volFuNew;                                                 */
/*  input uint8 Ext_volFuOld;                                                 */
/*  input boolean Ext_bRFuDet;                                                */
/*  input uint8 RFuDet_volFuDelta;                                            */
/*  input uint8 VolFuDelta_C;                                                 */
/*  output uint8 RFuDet_volFuDelta;                                           */
/*  output boolean FISARFUDET_bExtbRFuDetPrev;                                */
/*  output boolean Ext_bRFuDet;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidCalculDelta(void)
{
   RFuDet_volFuDelta = (uint8)MATHSRV_udtMAX(Ext_volFuNew - Ext_volFuOld, 0);
   FISARFUDET_bExtbRFuDetPrev = Ext_bRFuDet;
   if (RFuDet_volFuDelta >= VolFuDelta_C)
   {
      Ext_bRFuDet = 1;
   }
   else
   {
      Ext_bRFuDet = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidCalculValeursReset                           */
/* !Description :  cette fonction permet la demande de reset après détection  */
/*                 de plein                                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FISARFUDET_vidCalcConsoDepRempl();                       */
/*  extf argret void FISARFUDET_vidResetCoefEffectue();                       */
/*  input boolean FISA_bRstAdpDone;                                           */
/*  input boolean FISARFUDET_bFISARstAdpDonePrev;                             */
/*  input boolean Ext_bRFuDet;                                                */
/*  output boolean FISARFUDET_bExtbRFuDetPrev;                                */
/*  output boolean FISARFUDET_bFISARstAdpDonePrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidCalculValeursReset(void)
{
   boolean bLocalFISAbRstAdpDone;


   VEMS_vidGET(FISA_bRstAdpDone, bLocalFISAbRstAdpDone);
   FISARFUDET_vidCalcConsoDepRempl();
   if (  (bLocalFISAbRstAdpDone != 0)
      && (FISARFUDET_bFISARstAdpDonePrev == 0))
   {
      FISARFUDET_vidResetCoefEffectue();
   }
   FISARFUDET_bExtbRFuDetPrev = Ext_bRFuDet;
   FISARFUDET_bFISARstAdpDonePrev = bLocalFISAbRstAdpDone;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidCndCalcCoefLissage                           */
/* !Description :  cette fonction permet l'activation du bloc                 */
/*                 1_Calcul_coefficient_lissage                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_08_07467_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FISARFUDET_vidCalcCoefLissage();                         */
/*  input boolean Ext_bRFuDet;                                                */
/*  input boolean FISARFUDET_bExtbRFuDetPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidCndCalcCoefLissage(void)
{
   if (  (Ext_bRFuDet != 0)
      && (FISARFUDET_bExtbRFuDetPrev == 0))
   {
      FISARFUDET_vidCalcCoefLissage();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidCalcCoefLissage                              */
/* !Description :  remise à jour à chaque détection de remplissage carburant  */
/*                 de la valeur  de reset du coefficient de qualité carburant */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 FISA_facOld;                                                  */
/*  input uint8 FISA_facNew_C;                                                */
/*  input uint8 Ext_volFuOld;                                                 */
/*  input uint8 Ext_volFuNew;                                                 */
/*  output uint8 FISA_facRst;                                                 */
/*  output uint8 FISA_facRst_nvm;                                             */
/*  output uint16 Ext_volFuCns;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidCalcCoefLissage(void)
{
   uint8  u8LocalFISAfacOld;
   uint8  u8LocalFISAfacRst;
   uint16 u16LocalFISAfacRst;
   sint32 s32LocalNumerator;


   VEMS_vidGET(FISA_facOld, u8LocalFISAfacOld);
   s32LocalNumerator = ( Ext_volFuOld * (u8LocalFISAfacOld - FISA_facNew_C))
                       + (Ext_volFuNew * FISA_facNew_C);

   if (s32LocalNumerator < 0)
   {
      u8LocalFISAfacRst = 0;
   }
   else
   {
      if (Ext_volFuNew != 0)
      {
         u16LocalFISAfacRst = (uint16)(s32LocalNumerator / Ext_volFuNew);
         u8LocalFISAfacRst = (uint8)MATHSRV_udtMIN(u16LocalFISAfacRst, 128);
      }
      else
      {
         u8LocalFISAfacRst = 128;
      }
   }
   VEMS_vidSET(FISA_facRst, u8LocalFISAfacRst);
   FISA_facRst_nvm = u8LocalFISAfacRst;
   Ext_volFuCns = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidCalcConsoDepRempl                            */
/* !Description :  Cette fonction  permet l’évaluation du volume d'essence    */
/*                 consommée sans prendre en compte la purge canister à 80    */
/*                 mm3 près .                                                 */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_08_07467_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FISARFUDET_vidConsomDepuisPlein();                       */
/*  input uint16 Temps_injection_entre_pmh;                                   */
/*  input uint16 Injector_constant;                                           */
/*  input uint8 Rho_carburant;                                                */
/*  input boolean Ext_bRFuDet;                                                */
/*  output uint16 Fuel_used_between_tdc;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidCalcConsoDepRempl(void)
{
   uint16 u16LocalInjectorconstant;
   uint16 u16LocalTempsInjEntrePmh;
   uint32 u32Local2;
   uint32 u32Local3;


   VEMS_vidGET(Temps_injection_entre_pmh, u16LocalTempsInjEntrePmh);
   VEMS_vidGET(Injector_constant, u16LocalInjectorconstant);
   if ( u16LocalTempsInjEntrePmh < 8191 )
   {
      u32Local2 = (uint32)( u16LocalInjectorconstant + 1 ) * (uint32)
                          ( Rho_carburant + 1792 );
      u32Local2 = (uint32)( u16LocalTempsInjEntrePmh * 524288 )
                          / u32Local2;
   }
   else
   {
      u32Local2 = (uint32)(u16LocalTempsInjEntrePmh * 65536);
      u32Local3 = (uint32)( Rho_carburant + 1792 );
      u32Local2 =  u32Local2 / u32Local3;
      u32Local2 = ( u32Local2 * 8 ) / ( u16LocalInjectorconstant + 1 );
   }
   Fuel_used_between_tdc = (uint16)MATHSRV_udtMIN(u32Local2, 65535);
   if (Ext_bRFuDet != 0)
   {
      FISARFUDET_vidConsomDepuisPlein();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidConsomDepuisPlein                            */
/* !Description :  cette fonction permet de calculer la quantité de carburant */
/*                 consommée depuis le remplissage du réservoir ainsi elle    */
/*                 demande la reset après détection de plein                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_volFuCns;                                                */
/*  input uint16 Fuel_used_between_tdc;                                       */
/*  input uint16 Ext_volCircFu_C;                                             */
/*  output uint16 Ext_volFuCns;                                               */
/*  output boolean RFuDet_bRstAdp;                                            */
/*  output boolean RFuDet_bRstAdp_nvm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidConsomDepuisPlein(void)
{
   boolean bLocalRFuDetbRstAdp;
   uint32  u32LocalExt_volCircFu;
   uint32  u32Local;


   u32Local = (uint32)(Ext_volFuCns + Fuel_used_between_tdc);
   Ext_volFuCns = (uint16)MATHSRV_udtMIN(u32Local,  65535);
   u32LocalExt_volCircFu = (uint32)(10 * Ext_volCircFu_C);
   if (Ext_volFuCns >= u32LocalExt_volCircFu)
   {
      bLocalRFuDetbRstAdp = 1;
   }
   else
   {
      bLocalRFuDetbRstAdp = 0;
   }
   VEMS_vidSET(RFuDet_bRstAdp, bLocalRFuDetbRstAdp);
   RFuDet_bRstAdp_nvm = bLocalRFuDetbRstAdp;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FISARFUDET_vidResetCoefEffectue                            */
/* !Description :  cette fonction permet de mettre à zero les informations de */
/*                 remplissage et de demande de reset après detection du plein*/
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bRFuDet;                                               */
/*  output boolean RFuDet_bRstAdp;                                            */
/*  output boolean RFuDet_bRstAdp_nvm;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISARFUDET_vidResetCoefEffectue(void)
{
   Ext_bRFuDet = 0;
   VEMS_vidSET(RFuDet_bRstAdp, 0);
   RFuDet_bRstAdp_nvm = 0;
}
/*------------------------------ end of file ---------------------------------*/