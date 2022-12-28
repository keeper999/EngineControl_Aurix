/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_FCT6.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidDuree_Fctmt                                         */
/*   2 / IFAIRSYSIGSYS_vidTqSys                                               */
/*   3 / IFAIRSYSIGSYS_vidCstr                                                */
/*   4 / IFAIRSYSIGSYS_vidOutputInMnfReq                                      */
/*   5 / IFAIRSYSIGSYS_vidOutMainOxCEstim                                     */
/*   6 / IFAIRSYSIGSYS_vidOutput_tOilMes                                      */
/*   7 / IFAIRSYSIGSYS_vidDetInstMisf                                         */
/*   8 / IFAIRSYSIGSYS_vidECU1                                                */
/*   9 / IFAIRSYSIGSYS_vidCptrTempsEngSt                                      */
/*   10 / IFAIRSYSIGSYS_vidCptrTempsEcuSt                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/IFAIRSYSIGSYS/IFAIRSYSIGSYS_FCT6$*/
/* $Revision::   1.34     $$Author::   HHAMLAOU       $$Date::   07 Nov 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidDuree_Fctmt                               */
/* !Description :  Cette fonction calcule le temps de fonctionnement moteur   */
/*                 ainsi que le temps d'allumage ECU depuis le dernier RAZ    */
/*                 eeprom                                                     */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYSIGSYS_vidCptrTempsEngSt();                       */
/*  extf argret void IFAIRSYSIGSYS_vidCptrTempsEcuSt();                       */
/*  input boolean Moteur_tournant;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidDuree_Fctmt(void)
{
   boolean bLocalMoteur_tournant;


   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   if (bLocalMoteur_tournant != 0)
   {
      IFAIRSYSIGSYS_vidCptrTempsEngSt();
   }
   IFAIRSYSIGSYS_vidCptrTempsEcuSt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidTqSys                                     */
/* !Description :  Fonction li à l'événement synchro                          */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 TqSys_tqCkAOSCord;                                           */
/*  output sint16 TqSys_tqCkAntiOscCord;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidTqSys(void)
{
   /*F03_TqSys */
   sint16  s16LocalTqSys_tqCkAOSCord;
   sint16  s16LocalTqSys_tqCkAntiOscCord;


   VEMS_vidGET(TqSys_tqCkAOSCord, s16LocalTqSys_tqCkAOSCord);

   s16LocalTqSys_tqCkAntiOscCord =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqCkAOSCord, -32000, 32000);
   VEMS_vidSET(TqSys_tqCkAntiOscCord, s16LocalTqSys_tqCkAntiOscCord);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidCstr                                      */
/* !Description :  Evénement pour l'initialisation                            */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 InjSys_mFuReq;                                               */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 InjSys_prm_mCanPurg[2];                                      */
/*  output uint16 Required_fuel_flow_rate;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidCstr(void)
{
   /*F01_Cstr */
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalInjSys_prm_mCanPurg;
   uint16  u16LocalRequired_fuel_flow_rate;
   uint32  u32LocalSum;
   uint32  u32LocalRequired_fuel_flow_rate;
   uint32  u32LocalInjSys_mFuReq;


   VEMS_vidGET(InjSys_mFuReq, u32LocalInjSys_mFuReq);
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET1DArrayElement(InjSys_prm_mCanPurg,
                             0,
                             u16LocalInjSys_prm_mCanPurg);

   if (u8LocalExt_tiTDC != 0)
   {
      if (u32LocalInjSys_mFuReq >= 2139062)
      {
         u16LocalRequired_fuel_flow_rate = 65535;
      }
      else
      {
         u32LocalSum = u32LocalInjSys_mFuReq + u16LocalInjSys_prm_mCanPurg;
         u32LocalRequired_fuel_flow_rate = ( ( ( u32LocalSum
                                               * 125)
                                             / ( u8LocalExt_tiTDC
                                               * 16)));
         u16LocalRequired_fuel_flow_rate =
            (uint16)MATHSRV_udtMIN(u32LocalRequired_fuel_flow_rate, 65535);
      }
   }
   else
   {
      u16LocalRequired_fuel_flow_rate = 0;
   }
   VEMS_vidSET(Required_fuel_flow_rate, u16LocalRequired_fuel_flow_rate);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputInMnfReq                            */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 AirSys_pInMnfReq.                                          */
/* !Number      :  FCT6.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 AirSys_prm_pInMnfReq_If_C;                                    */
/*  input uint16 AirSys_prm_pInMnfReq[2];                                     */
/*  output uint16 AirSys_pInMnfReq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputInMnfReq(void)
{
   /*/F13_Output_pInMnfReq */
   uint8  u8LocalIdx;
   uint16 u16LocalAirSys_pInMnfReq;


   u8LocalIdx =
      (uint8)MATHSRV_udtCLAMP(AirSys_prm_pInMnfReq_If_C, 1, 2);
   u8LocalIdx = (uint8)(u8LocalIdx - 1);
   VEMS_vidGET1DArrayElement(AirSys_prm_pInMnfReq,
                             u8LocalIdx,
                             u16LocalAirSys_pInMnfReq);
   VEMS_vidSET(AirSys_pInMnfReq, u16LocalAirSys_pInMnfReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutMainOxCEstim                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 ExM_tExLsDsMainOxCEstim et ExM_tExLsUsMainOxCEstim.        */
/* !Number      :  FCT6.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 LsSys_idxSelTEgDsMainOxCEstim_C;                              */
/*  input uint16 ExM_prm_tEg[12];                                             */
/*  input uint8 LsSys_idxSelTEgUsMainOxCEstim_C;                              */
/*  output uint16 ExM_tExLsDsMainOxCEstim;                                    */
/*  output uint16 ExM_tExLsUsMainOxCEstim;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutMainOxCEstim(void)
{
   /*F12_Output_MainOxCEstim*/
   uint8  u8LocalIdx1;
   uint8  u8LocalIdx2;
   uint16 u16LocalExM_tExLsDsMainOxCEstim;
   uint16 u16LocalExM_tExLsUsMainOxCEstim;


   u8LocalIdx1 =
      (uint8)MATHSRV_udtCLAMP(LsSys_idxSelTEgDsMainOxCEstim_C, 1, 12);
   u8LocalIdx1 = (uint8)(u8LocalIdx1 - 1);
   VEMS_vidGET1DArrayElement(ExM_prm_tEg,
                             u8LocalIdx1,
                             u16LocalExM_tExLsDsMainOxCEstim);
   u16LocalExM_tExLsDsMainOxCEstim =
      (uint16)MATHSRV_udtMIN(u16LocalExM_tExLsDsMainOxCEstim, 41600);

   u8LocalIdx2 =
      (uint8)MATHSRV_udtCLAMP(LsSys_idxSelTEgUsMainOxCEstim_C, 1, 12);
   u8LocalIdx2 = (uint8)(u8LocalIdx2 - 1);
   VEMS_vidGET1DArrayElement(ExM_prm_tEg,
                             u8LocalIdx2,
                             u16LocalExM_tExLsUsMainOxCEstim);
   u16LocalExM_tExLsUsMainOxCEstim =
      (uint16)MATHSRV_udtMIN(u16LocalExM_tExLsUsMainOxCEstim, 41600);
   VEMS_vidSET(ExM_tExLsDsMainOxCEstim, u16LocalExM_tExLsDsMainOxCEstim);
   VEMS_vidSET(ExM_tExLsUsMainOxCEstim, u16LocalExM_tExLsUsMainOxCEstim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_tOilMes                            */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_tOilMes.                                               */
/* !Number      :  FCT6.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Eng_bTOilChk;                                               */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input sint16 Ext_tOilDft;                                                 */
/*  output sint16 Ext_tOilMes;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_tOilMes(void)
{
   /*F11_Output_tOilMes*/
   boolean bLocalEng_bTOilChk;
   sint16  s16LocalExt_tOilMes;
   sint16  s16LocalExt_tOilDft;
   sint32  s32LocalExt_tOilMes;
   sint32  s32LocalExt_tOilDft;

   VEMS_vidGET(Eng_bTOilChk, bLocalEng_bTOilChk);
   if (bLocalEng_bTOilChk != 0)
   {
      VEMS_vidGET(Eng_tOilEstim, s16LocalExt_tOilMes);
      s32LocalExt_tOilMes = (sint32)((s16LocalExt_tOilMes * 5) / 2);
      s16LocalExt_tOilMes =
         (sint16)MATHSRV_udtCLAMP(s32LocalExt_tOilMes, -500, 2000);
      VEMS_vidSET(Ext_tOilMes, s16LocalExt_tOilMes);
   }
   else
   {
      s32LocalExt_tOilDft = (sint32)((Ext_tOilDft * 5) / 2);
      s16LocalExt_tOilDft =
         (sint16)MATHSRV_udtCLAMP(s32LocalExt_tOilDft, -500, 2000);
      VEMS_vidSET(Ext_tOilMes, s16LocalExt_tOilDft);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidDetInstMisf                               */
/* !Description :  fonction appelée à  l'interruption logicielle de fin       */
/*                 d'acquisition de la fenêtre misfire.                       */
/* !Number      :  FCT6.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Mf_misfire_detected_uavb0;                                  */
/*  output boolean MonMisf_bDetInstMisf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidDetInstMisf(void)
{
   /*01_DetInstMisf */
   boolean bLocalMf_misfire_detected_uavb0;


   VEMS_vidGET(Mf_misfire_detected_uavb0, bLocalMf_misfire_detected_uavb0);
   VEMS_vidSET(MonMisf_bDetInstMisf, bLocalMf_misfire_detected_uavb0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidECU1                                      */
/* !Description :  Ce block contient les entrées de la chaîne d’air issues des*/
/*                 modules projets EBx-DT.                                    */
/* !Number      :  FCT6.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_sonde_amont;                                         */
/*  output uint8 Ext_uLsUsMes;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidECU1(void)
{
   /*f6_ECU1*/
   uint8  u8LocalExt_uLsUsMes;
   uint16 u16LocalTension_sonde_amont;


   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   u8LocalExt_uLsUsMes =
      (uint8)MATHSRV_udtMIN(u16LocalTension_sonde_amont, 205);
   VEMS_vidSET(Ext_uLsUsMes, u8LocalExt_uLsUsMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidCptrTempsEngSt                            */
/* !Description :  Cette fonction calcule le temps de fonctionnement moteur   */
/*                 ECU depuis le dernier RAZ eeprom                           */
/* !Number      :  FCT6.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 temps_fonctionnement_moteur;                                 */
/*  output uint16 temps_fonctionnement_moteur;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidCptrTempsEngSt(void)
{
   uint16 u16LocalTps_Fctm_Moteur;

   VEMS_vidGET(temps_fonctionnement_moteur, u16LocalTps_Fctm_Moteur);
   if (u16LocalTps_Fctm_Moteur < 65535)
   {
      u16LocalTps_Fctm_Moteur = (uint16)(u16LocalTps_Fctm_Moteur + 1);
      VEMS_vidSET(temps_fonctionnement_moteur, u16LocalTps_Fctm_Moteur);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidCptrTempsEcuSt                            */
/* !Description :  Cette fonction calcule le temps le temps d'allumage ECU    */
/*                 depuis le dernier RAZ eeprom                               */
/* !Number      :  FCT6.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 temps_allumage_ecu;                                          */
/*  output uint16 temps_allumage_ecu;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidCptrTempsEcuSt(void)
{
   uint16 u16Localtemps_allumage_ecu;

   VEMS_vidGET(temps_allumage_ecu, u16Localtemps_allumage_ecu);
   if (u16Localtemps_allumage_ecu < 65535)
   {
      u16Localtemps_allumage_ecu = (uint16)(u16Localtemps_allumage_ecu + 1);
      VEMS_vidSET(temps_allumage_ecu, u16Localtemps_allumage_ecu);
   }
}
/*-------------------------------- end of file -------------------------------*/