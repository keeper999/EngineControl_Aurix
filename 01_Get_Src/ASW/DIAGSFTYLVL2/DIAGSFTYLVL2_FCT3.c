/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGSFTYLVL2                                            */
/* !Description     : DIAGSFTYLVL2 Component.                                 */
/*                                                                            */
/* !Module          : DIAGSFTYLVL2                                            */
/* !Description     : SAFETY TMS: Diagnostics des capteurs/Trames CAN pour le */
/*                    safety niveau 2.                                        */
/*                                                                            */
/* !File            : DIAGSFTYLVL2_FCT3.C                                     */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DIAGSFTYLVL2_vidAccPSecu                                             */
/*   2 / DIAGSFTYLVL2_vidBrkDiagSftyLvl2                                      */
/*   3 / DIAGSFTYLVL2_vidBrkDiag                                              */
/*   4 / DIAGSFTYLVL2_vidBrkSecu                                              */
/*   5 / DIAGSFTYLVL2_vidVehSpdDiagSftyLvl2                                   */
/*   6 / DIAGSFTYLVL2_vidVehSpdDiag                                           */
/*   7 / DIAGSFTYLVL2_vidVehSpdSecu                                           */
/*   8 / DIAGSFTYLVL2_vidThrDiagSftyLvl2                                      */
/*   9 / DIAGSFTYLVL2_vidThrDiag                                              */
/*   10 / DIAGSFTYLVL2_vidThrSecu                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5147426 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "DIAGSFTYLVL2.h"
#include "DIAGSFTYLVL2_L.h"
#include "DIAGSFTYLVL2_IM.h"
#include "LIBSFTYLVL2.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidAccPSecu                                   */
/* !Description :  Cette fonction  décrit la sécurisation des diagnostiques   */
/*                 pour le Safety niveau 2 la pédale d'accélération           */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftCoh_AccP;                                       */
/*  input uint8 SftyMgt_nUpTranThd_AccPCoh_C;                                 */
/*  input uint8 SftyMgt_nDownTranThd_AccPCoh_C;                               */
/*  input uint8 SftyMgt_nInitCptConf_AccPCoh_C;                               */
/*  input uint8 SftyMgt_nDecCpt_AccPCoh_C;                                    */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_AccP;                                  */
/*  input boolean DIAGSFTYLVL2_bFilSig_AccP;                                  */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_AccP;                                */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_AccP;                                 */
/*  output boolean SftyMgt_bDftSftyCoh_AccP;                                  */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_AccP;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidAccPSecu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftCoh_AccP,
                                SftyMgt_nUpTranThd_AccPCoh_C,
                                SftyMgt_nDownTranThd_AccPCoh_C,
                                SftyMgt_nInitCptConf_AccPCoh_C,
                                SftyMgt_nDecCpt_AccPCoh_C,
                                &DIAGSFTYLVL2_u8CntFilt_AccP,
                                &DIAGSFTYLVL2_bFilSig_AccP,
                                &DIAGSFTYLVL2_u8CountNiv2_AccP,
                                &DIAGSFTYLVL2_bDgoNiv2_AccP);

   VEMS_vidSET(SftyMgt_bDftSftyCoh_AccP, DIAGSFTYLVL2_bDgoNiv2_AccP);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidBrkDiagSftyLvl2                            */
/* !Description :  Cette fonction effectue les diagnostiques du niveau 2 pour */
/*                 la pédale frein, qui se font en 2 étapes :   diagnostique  */
/*                 et sécurisation des défauts                                */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidBrkDiag();                               */
/*  extf argret void DIAGSFTYLVL2_vidBrkSecu();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidBrkDiagSftyLvl2(void)
{
   DIAGSFTYLVL2_vidBrkDiag();
   DIAGSFTYLVL2_vidBrkSecu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidBrkDiag                                    */
/* !Description :  Cette fonction décrit le diagnostique pour le Safety niveau*/
/*                 2 pour la pédale de frein.                                 */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Bps_brake_pedal_can_input;                                  */
/*  input boolean SftyMgt_bBrkPedPrss;                                        */
/*  input uint8 Acceleration_vehicule;                                        */
/*  input uint8 SftyMgt_ThdDecelBrk_C;                                        */
/*  input uint8 SftyMgt_ThdAccelBrk_C;                                        */
/*  input boolean SftyMgt_bAuthDiagCoh_BrkPed;                                */
/*  input boolean DIAGSFTYLVL2_bTimerInputPrev;                               */
/*  input uint16 SftyMgt_tiBrkPedPressInit_C;                                 */
/*  input uint8 DIAGSFTYLVL2_u8CountTimer;                                    */
/*  input boolean DIAGSFTYLVL2_bTimeOut;                                      */
/*  output boolean SftyMgt_bAuthDiagCoh_BrkPed;                               */
/*  output uint8 DIAGSFTYLVL2_u8CountTimer;                                   */
/*  output boolean DIAGSFTYLVL2_bTimeOut;                                     */
/*  output boolean SftyMgt_bDftInvCoh_BrkPed;                                 */
/*  output boolean DIAGSFTYLVL2_bTimerInputPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidBrkDiag(void)
{
   boolean bLocalBrakePedal;
   boolean bLocalBrkPedPrss;
   boolean bLocalTimerInput;
   uint8   u8LocalAcc_vehicule;
   uint16  u16LocalCountTmr;


   VEMS_vidGET(Bps_brake_pedal_can_input, bLocalBrakePedal);
   VEMS_vidGET(SftyMgt_bBrkPedPrss, bLocalBrkPedPrss);
   VEMS_vidGET(Acceleration_vehicule, u8LocalAcc_vehicule);

   if (  (SftyMgt_ThdDecelBrk_C > u8LocalAcc_vehicule)
      || (u8LocalAcc_vehicule > SftyMgt_ThdAccelBrk_C))
   {
      SftyMgt_bAuthDiagCoh_BrkPed = 1;
   }
   else
   {
      SftyMgt_bAuthDiagCoh_BrkPed = 0;
   }

   if (SftyMgt_bAuthDiagCoh_BrkPed == 0)
   {
      bLocalTimerInput = 0;
   }
   else
   {
      if (bLocalBrakePedal != bLocalBrkPedPrss)
      {
         bLocalTimerInput = 1;
      }
      else
      {
         bLocalTimerInput = 0;
      }
   }

   if (  (bLocalTimerInput != 0)
      && (DIAGSFTYLVL2_bTimerInputPrev == 0))
   {
      u16LocalCountTmr = (uint16)(SftyMgt_tiBrkPedPressInit_C / 4);
      DIAGSFTYLVL2_u8CountTimer = (uint8)MATHSRV_udtMIN(u16LocalCountTmr, 255);
      if (DIAGSFTYLVL2_u8CountTimer == 0)
      {
         DIAGSFTYLVL2_bTimeOut = 1;
      }
      else
      {
         DIAGSFTYLVL2_bTimeOut = 0;
      }
   }
   else
   {
      if (DIAGSFTYLVL2_u8CountTimer > 0)
      {
         DIAGSFTYLVL2_u8CountTimer = (uint8)(DIAGSFTYLVL2_u8CountTimer - 1);
         if (DIAGSFTYLVL2_u8CountTimer == 0)
         {
            DIAGSFTYLVL2_bTimeOut = 1;
         }
         else
         {
            DIAGSFTYLVL2_bTimeOut = 0;
         }
      }
   }

   if ((DIAGSFTYLVL2_bTimeOut != 0) && (bLocalTimerInput != 0))
   {
      SftyMgt_bDftInvCoh_BrkPed = 1;
   }
   else
   {
      SftyMgt_bDftInvCoh_BrkPed = 0;
   }

   DIAGSFTYLVL2_bTimerInputPrev = bLocalTimerInput;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidBrkSecu                                    */
/* !Description :  Cette fonction décrit la sécurisation des diagnostiques    */
/*                 pour le Safety niveau 2 la pédale de frien                 */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftInvCoh_BrkPed;                                  */
/*  input uint8 SftyMgt_nUpThd_BrkPedInvCoh_C;                                */
/*  input uint8 SftyMgt_nDownThd_BrkPedInvCoh_C;                              */
/*  input uint8 SftyMgt_nInitCpt_BrkPedInvCoh_C;                              */
/*  input uint8 SftyMgt_nDecCpt_BrkPedInvCoh_C;                               */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_BrkPed;                                */
/*  input boolean DIAGSFTYLVL2_bFilSig_BrkPed;                                */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_BrkPed;                              */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_BrkPed;                               */
/*  output boolean SftyMgt_bDftSftyInvCoh_BrkPed;                             */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_BrkPed;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidBrkSecu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftInvCoh_BrkPed,
                                SftyMgt_nUpThd_BrkPedInvCoh_C,
                                SftyMgt_nDownThd_BrkPedInvCoh_C,
                                SftyMgt_nInitCpt_BrkPedInvCoh_C,
                                SftyMgt_nDecCpt_BrkPedInvCoh_C,
                                &DIAGSFTYLVL2_u8CntFilt_BrkPed,
                                &DIAGSFTYLVL2_bFilSig_BrkPed,
                                &DIAGSFTYLVL2_u8CountNiv2_BrkPed,
                                &DIAGSFTYLVL2_bDgoNiv2_BrkPed);

   VEMS_vidSET(SftyMgt_bDftSftyInvCoh_BrkPed, DIAGSFTYLVL2_bDgoNiv2_BrkPed);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidVehSpdDiagSftyLvl2                         */
/* !Description :  Cette fonction effectue les diagnostiques du niveau 2 pour */
/*                 la vitesse véhicule, qui se font en 2 étapes :             */
/*                 diagnostique et sécurisation des défauts                   */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidVehSpdDiag();                            */
/*  extf argret void DIAGSFTYLVL2_vidVehSpdSecu();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidVehSpdDiagSftyLvl2(void)
{
   DIAGSFTYLVL2_vidVehSpdDiag();
   DIAGSFTYLVL2_vidVehSpdSecu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidVehSpdDiag                                 */
/* !Description :  Cette fonction décrit les diagnostiques et la sécurisation */
/*                 de la vitesse à partir quatre roues pour le Safety niveau 2*/
/*                 pour la vitesse véhicule.                                  */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DIAGSFTYLVL2_vidReinitCounter();                         */
/*  extf argret void DIAGSFTYLVL2_vidCalculcounter();                         */
/*  input uint16 ISCAN_u16N16F30DP263;                                        */
/*  input uint16 ISCAN_u16N16F30DP264;                                        */
/*  input uint16 ISCAN_u16N16F30DP265;                                        */
/*  input uint16 ISCAN_u16N16F30DP266;                                        */
/*  input uint16 Ext_spdVehSecu;                                              */
/*  input uint16 SftyMgt_facFilSpdVehLvl2_C;                                  */
/*  input uint16 DIAGSFTYLVL2_u16N16F30DP263;                                 */
/*  input uint16 DIAGSFTYLVL2_u16N16F30DP264;                                 */
/*  input uint16 DIAGSFTYLVL2_u16N16F30DP265;                                 */
/*  input uint16 DIAGSFTYLVL2_u16N16F30DP266;                                 */
/*  input uint32 DIAGSFTYLVL2_u32N16F30DP263Mem;                              */
/*  input uint32 DIAGSFTYLVL2_u32N16F30DP264Mem;                              */
/*  input uint32 DIAGSFTYLVL2_u32N16F30DP265Mem;                              */
/*  input uint32 DIAGSFTYLVL2_u32N16F30DP266Mem;                              */
/*  input uint16 SftyMgt_spdVehMinValLvl2;                                    */
/*  input uint16 SftyMgt_spdVehMax_inhLvl2_C;                                 */
/*  input uint16 SftyMgt_spdGrdMax_C;                                         */
/*  input uint16 SftyMgt_spdVehMinISCANLvl2_C;                                */
/*  input uint16 SftyMgt_spdVehMaxISCANLvl2_C;                                */
/*  input boolean SftyMgt_bDftCoh_SpdVeh;                                     */
/*  input boolean DIAGSFTYLVL2_bPosHys;                                       */
/*  input boolean DIAGSFTYLVL2_bPosHys1;                                      */
/*  input boolean DIAGSFTYLVL2_bPosHys2;                                      */
/*  input boolean DIAGSFTYLVL2_bPosHys3;                                      */
/*  input boolean SftyMgt_bEndtiCohSpdVehLvl2;                                */
/*  input boolean SftyMgt_bDftCoh_SpdVehLvl2;                                 */
/*  output uint16 DIAGSFTYLVL2_u16N16F30DP263;                                */
/*  output uint32 DIAGSFTYLVL2_u32N16F30DP263Mem;                             */
/*  output uint16 DIAGSFTYLVL2_u16N16F30DP264;                                */
/*  output uint32 DIAGSFTYLVL2_u32N16F30DP264Mem;                             */
/*  output uint16 DIAGSFTYLVL2_u16N16F30DP265;                                */
/*  output uint32 DIAGSFTYLVL2_u32N16F30DP265Mem;                             */
/*  output uint16 DIAGSFTYLVL2_u16N16F30DP266;                                */
/*  output uint32 DIAGSFTYLVL2_u32N16F30DP266Mem;                             */
/*  output uint16 SftyMgt_spdVehMinValLvl2;                                   */
/*  output uint16 SftyMgt_spdVehSecu;                                         */
/*  output boolean SftyMgt_bDftCoh_SpdVehLvl2;                                */
/*  output boolean DIAGSFTYLVL2_bPosHys;                                      */
/*  output boolean DIAGSFTYLVL2_bPosHys1;                                     */
/*  output boolean DIAGSFTYLVL2_bPosHys2;                                     */
/*  output boolean DIAGSFTYLVL2_bPosHys3;                                     */
/*  output boolean SftyMgt_bDftCoh_SpdVeh_Prev;                               */
/*  output boolean SftyMgt_bDftCoh_SpdVeh;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidVehSpdDiag(void)
{
   boolean bLocalResult263;
   boolean bLocalResult264;
   boolean bLocalResult265;
   boolean bLocalResult266;
   uint8   u8LocalResult;
   uint16  u16LocalISCANP263;
   uint16  u16LocalISCANP264;
   uint16  u16LocalISCANP265;
   uint16  u16LocalISCANP266;
   uint16  u16LocalExtSpdVehSecu;
   uint16  u16LocalClcGain;
   uint16  u16LocalSftyMgt_spdVehSecu;
   uint16  u16LocalN16F30DP263;
   uint16  u16LocalN16F30DP264;
   uint16  u16LocalN16F30DP265;
   uint16  u16LocalMin1;
   uint16  u16LocalMin2;
   uint16  u16LocalSwitch1;
   uint16  u16LocalSwitch2;
   uint16  u16LocalSwitch3;
   uint16  u16LocalSwitch4;
   uint16  u16LocalN16F30DP266;
   uint16  u16LocalISCAN_u16N16F30DP263;
   uint16  u16LocalISCAN_u16N16F30DP264;
   uint16  u16LocalISCAN_u16N16F30DP265;
   uint16  u16LocalISCAN_u16N16F30DP266;
   uint32  u32LocalVeh;
   uint32  u32LocalClc;
   sint32  s32LocalVeh;


   VEMS_vidGET(ISCAN_u16N16F30DP263, u16LocalISCANP263);
   VEMS_vidGET(ISCAN_u16N16F30DP264, u16LocalISCANP264);
   VEMS_vidGET(ISCAN_u16N16F30DP265, u16LocalISCANP265);
   VEMS_vidGET(ISCAN_u16N16F30DP266, u16LocalISCANP266);
   VEMS_vidGET(Ext_spdVehSecu, u16LocalExtSpdVehSecu);
   VEMS_vidGET(ISCAN_u16N16F30DP263, u16LocalISCAN_u16N16F30DP263);
   VEMS_vidGET(ISCAN_u16N16F30DP264, u16LocalISCAN_u16N16F30DP264);
   VEMS_vidGET(ISCAN_u16N16F30DP265, u16LocalISCAN_u16N16F30DP265);
   VEMS_vidGET(ISCAN_u16N16F30DP266, u16LocalISCAN_u16N16F30DP266);

   if (SftyMgt_facFilSpdVehLvl2_C >= 32768)
   {
      DIAGSFTYLVL2_u16N16F30DP263 =
         (uint16)MATHSRV_udtMIN(u16LocalISCANP263, 65533);
      DIAGSFTYLVL2_u32N16F30DP263Mem =
         (uint32)DIAGSFTYLVL2_u16N16F30DP263 * 65536;

      DIAGSFTYLVL2_u16N16F30DP264 =
         (uint16)MATHSRV_udtMIN(u16LocalISCANP264, 65533);
      DIAGSFTYLVL2_u32N16F30DP264Mem =
         (uint32)DIAGSFTYLVL2_u16N16F30DP264 * 65536;

      DIAGSFTYLVL2_u16N16F30DP265 =
         (uint16)MATHSRV_udtMIN(u16LocalISCANP265, 65533);
      DIAGSFTYLVL2_u32N16F30DP265Mem =
         (uint32)DIAGSFTYLVL2_u16N16F30DP265 * 65536;

      DIAGSFTYLVL2_u16N16F30DP266 =
         (uint16)MATHSRV_udtMIN(u16LocalISCANP266, 65533);
      DIAGSFTYLVL2_u32N16F30DP266Mem =
         (uint32)DIAGSFTYLVL2_u16N16F30DP266 * 65536;
   }
   else
   {
      u16LocalClcGain = (uint16)(SftyMgt_facFilSpdVehLvl2_C * 2);
      u16LocalN16F30DP263 =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalClcGain,
                                         &DIAGSFTYLVL2_u32N16F30DP263Mem,
                                         u16LocalISCANP263);
      DIAGSFTYLVL2_u16N16F30DP263 =
         (uint16)MATHSRV_udtMIN(u16LocalN16F30DP263, 65533);

      u16LocalN16F30DP264 =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalClcGain,
                                         &DIAGSFTYLVL2_u32N16F30DP264Mem,
                                         u16LocalISCANP264);
      DIAGSFTYLVL2_u16N16F30DP264 =
         (uint16)MATHSRV_udtMIN(u16LocalN16F30DP264, 65533);

      u16LocalN16F30DP265 =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalClcGain,
                                        &DIAGSFTYLVL2_u32N16F30DP265Mem,
                                        u16LocalISCANP265);
      DIAGSFTYLVL2_u16N16F30DP265 =
         (uint16)MATHSRV_udtMIN(u16LocalN16F30DP265, 65533);

      u16LocalN16F30DP266 =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalClcGain,
                                        &DIAGSFTYLVL2_u32N16F30DP266Mem,
                                        u16LocalISCANP266);
      DIAGSFTYLVL2_u16N16F30DP266 =
         (uint16)MATHSRV_udtMIN(u16LocalN16F30DP266, 65533);
   }
   u16LocalMin1 = (uint16)MATHSRV_udtMIN(DIAGSFTYLVL2_u16N16F30DP263,
                                         DIAGSFTYLVL2_u16N16F30DP264);
   u16LocalMin2 = (uint16)MATHSRV_udtMIN(DIAGSFTYLVL2_u16N16F30DP265,
                                         DIAGSFTYLVL2_u16N16F30DP266);
   SftyMgt_spdVehMinValLvl2 =
      (uint16)MATHSRV_udtMIN(u16LocalMin1, u16LocalMin2);

   if (DIAGSFTYLVL2_u16N16F30DP263 == SftyMgt_spdVehMinValLvl2)
   {
      bLocalResult263 = 1;
      u16LocalSwitch1 = SftyMgt_spdVehMax_inhLvl2_C;
   }
   else
   {
      bLocalResult263 = 0;
      u16LocalSwitch1 = DIAGSFTYLVL2_u16N16F30DP263;
   }
   if (DIAGSFTYLVL2_u16N16F30DP264 == SftyMgt_spdVehMinValLvl2)
   {
      bLocalResult264 = 1;
      u16LocalSwitch2 = SftyMgt_spdVehMax_inhLvl2_C;
   }
   else
   {
      bLocalResult264 = 0;
      u16LocalSwitch2 = DIAGSFTYLVL2_u16N16F30DP264;
   }
   if (DIAGSFTYLVL2_u16N16F30DP265 == SftyMgt_spdVehMinValLvl2)
   {
      bLocalResult265 = 1;
      u16LocalSwitch3 = SftyMgt_spdVehMax_inhLvl2_C;
   }
   else
   {
      bLocalResult265 = 0;
      u16LocalSwitch3 = DIAGSFTYLVL2_u16N16F30DP265;
   }
   if (DIAGSFTYLVL2_u16N16F30DP266 == SftyMgt_spdVehMinValLvl2)
   {
      bLocalResult266 = 1;
      u16LocalSwitch4 = SftyMgt_spdVehMax_inhLvl2_C;
   }
   else
   {
      bLocalResult266 = 0;
      u16LocalSwitch4 = DIAGSFTYLVL2_u16N16F30DP266;
   }
   u16LocalMin1 = (uint16)MATHSRV_udtMIN(u16LocalSwitch1, u16LocalSwitch2);
   u16LocalMin2 = (uint16)MATHSRV_udtMIN(u16LocalSwitch3, u16LocalSwitch4);

   u8LocalResult = (uint8) ( bLocalResult263
                           + bLocalResult264
                           + bLocalResult265
                           + bLocalResult266);
   if (u8LocalResult > 1)
   {
      u16LocalSftyMgt_spdVehSecu = SftyMgt_spdVehMinValLvl2;
   }
   else
   {
      u16LocalSftyMgt_spdVehSecu =
         (uint16)MATHSRV_udtMIN(u16LocalMin1, u16LocalMin2);
   }
   u32LocalClc = (uint32)(u16LocalSftyMgt_spdVehSecu * 32) / 25;
   u16LocalSftyMgt_spdVehSecu = (uint16)MATHSRV_udtMIN(u32LocalClc, 64000);
   VEMS_vidSET(SftyMgt_spdVehSecu, u16LocalSftyMgt_spdVehSecu);

   s32LocalVeh = (sint32)(u16LocalSftyMgt_spdVehSecu - u16LocalExtSpdVehSecu);
   u32LocalVeh = (uint32)MATHSRV_udtABS(s32LocalVeh);

   if (u32LocalVeh > SftyMgt_spdGrdMax_C)
   {
      SftyMgt_bDftCoh_SpdVehLvl2 = 1;
   }
   else
   {
      SftyMgt_bDftCoh_SpdVehLvl2 = 0;
   }

   /*** Begin Bloc PosHys ***/
   if (u16LocalISCAN_u16N16F30DP263 <= SftyMgt_spdVehMinISCANLvl2_C)
   {
      DIAGSFTYLVL2_bPosHys = 0;
   }
   else
   {
      if (u16LocalISCAN_u16N16F30DP263 >= SftyMgt_spdVehMaxISCANLvl2_C)
      {
         DIAGSFTYLVL2_bPosHys = 1;
      }
   }
   /*** End Bloc PosHys ***/

   /*** Begin Bloc PosHys1 ***/
   if (u16LocalISCAN_u16N16F30DP264 <= SftyMgt_spdVehMinISCANLvl2_C)
   {
      DIAGSFTYLVL2_bPosHys1 = 0;
   }
   else
   {
      if (u16LocalISCAN_u16N16F30DP264 >= SftyMgt_spdVehMaxISCANLvl2_C)
      {
         DIAGSFTYLVL2_bPosHys1 = 1;
      }
   }
   /*** End Bloc PosHys1 ***/

   /*** Begin Bloc PosHys2 ***/
   if (u16LocalISCAN_u16N16F30DP265 <= SftyMgt_spdVehMinISCANLvl2_C)
   {
      DIAGSFTYLVL2_bPosHys2 = 0;
   }
   else
   {
      if (u16LocalISCAN_u16N16F30DP265 >= SftyMgt_spdVehMaxISCANLvl2_C)
      {
         DIAGSFTYLVL2_bPosHys2 = 1;
      }
   }
   /*** End Bloc PosHys2 ***/

   /*** Begin Bloc PosHys3 ***/
   if (u16LocalISCAN_u16N16F30DP266 <= SftyMgt_spdVehMinISCANLvl2_C)
   {
      DIAGSFTYLVL2_bPosHys3 = 0;
   }
   else
   {
      if (u16LocalISCAN_u16N16F30DP266 >= SftyMgt_spdVehMaxISCANLvl2_C)
      {
         DIAGSFTYLVL2_bPosHys3 = 1;
      }
   }
   /*** End Bloc PosHys3 ***/
   SftyMgt_bDftCoh_SpdVeh_Prev = SftyMgt_bDftCoh_SpdVeh;
   if (  (DIAGSFTYLVL2_bPosHys != 0)
      || (DIAGSFTYLVL2_bPosHys1 != 0)
      || (DIAGSFTYLVL2_bPosHys2 != 0)
      || (DIAGSFTYLVL2_bPosHys3 != 0))
   {
      DIAGSFTYLVL2_vidReinitCounter();
   }
   else
   {
      DIAGSFTYLVL2_vidCalculcounter();
      if (SftyMgt_bEndtiCohSpdVehLvl2 != 0)
      {
         SftyMgt_bDftCoh_SpdVeh = SftyMgt_bDftCoh_SpdVehLvl2;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidVehSpdSecu                                 */
/* !Description :  Cette fonction décrit la sécurisation des diagnostiques    */
/*                 pour le Safety niveau 2 la vitesse véhicule                */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftCoh_SpdVeh;                                     */
/*  input uint8 SftyMgt_nUpTranThd_VehSpdCoh_C;                               */
/*  input uint8 SftyMgt_nDownTranThd_VehSpdCoh_C;                             */
/*  input uint8 SftyMgt_nInitCptConf_VehSpdCoh_C;                             */
/*  input uint8 SftyMgt_nDecCpt_VehSpdCoh_C;                                  */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_VehSpd;                                */
/*  input boolean DIAGSFTYLVL2_bFilSig_VehSpd;                                */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_VehSpd;                              */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_VehSpd;                               */
/*  output boolean SftyMgt_bDftSftyCoh_VehSpd;                                */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_VehSpd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidVehSpdSecu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftCoh_SpdVeh,
                                SftyMgt_nUpTranThd_VehSpdCoh_C,
                                SftyMgt_nDownTranThd_VehSpdCoh_C,
                                SftyMgt_nInitCptConf_VehSpdCoh_C,
                                SftyMgt_nDecCpt_VehSpdCoh_C,
                                &DIAGSFTYLVL2_u8CntFilt_VehSpd,
                                &DIAGSFTYLVL2_bFilSig_VehSpd,
                                &DIAGSFTYLVL2_u8CountNiv2_VehSpd,
                                &DIAGSFTYLVL2_bDgoNiv2_VehSpd);

   VEMS_vidSET(SftyMgt_bDftSftyCoh_VehSpd, DIAGSFTYLVL2_bDgoNiv2_VehSpd);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidThrDiagSftyLvl2                            */
/* !Description :  Cette fonction effectue les diagnostiques du niveau 2 pour */
/*                 la papillon, qui se font en 2 étapes :   diagnostique et   */
/*                 sécurisation des défauts                                   */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGSFTYLVL2_vidThrDiag();                               */
/*  extf argret void DIAGSFTYLVL2_vidThrSecu();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidThrDiagSftyLvl2(void)
{
   DIAGSFTYLVL2_vidThrDiag();
   DIAGSFTYLVL2_vidThrSecu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidThrDiag                                    */
/* !Description :  Cette fonction décrit les diagnostiques pour le Safety     */
/*                 niveau 2 pour la papillon                                  */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_uThrSen1;                                            */
/*  input uint16 SftyMgt_uThrRef;                                             */
/*  input uint16 SftyMgt_uThrSen2;                                            */
/*  input uint16 SftyMgt_uThrCohMax_C;                                        */
/*  output boolean SftyMgt_bDftCoh_Thr;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidThrDiag(void)
{
   uint16 u16LocalSftyMgt_uThrSen1;
   uint16 u16LocalSftyMgt_uThrRef;
   uint16 u16LocalSftyMgt_uThrSen2;
   uint32 u32LocalCalc;
   sint32 s32LocalCalc;


   VEMS_vidGET(SftyMgt_uThrSen1, u16LocalSftyMgt_uThrSen1);
   VEMS_vidGET(SftyMgt_uThrRef, u16LocalSftyMgt_uThrRef);
   VEMS_vidGET(SftyMgt_uThrSen2, u16LocalSftyMgt_uThrSen2);

   s32LocalCalc = (sint32)( ( (512 * ( u16LocalSftyMgt_uThrSen1
                                     + u16LocalSftyMgt_uThrSen2))
                            - (125 * u16LocalSftyMgt_uThrRef))
                          / 512);
   u32LocalCalc = (uint32)MATHSRV_udtABS(s32LocalCalc);

   if (u32LocalCalc >= SftyMgt_uThrCohMax_C)
   {
      SftyMgt_bDftCoh_Thr = 1;
   }
   else
   {
      SftyMgt_bDftCoh_Thr = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGSFTYLVL2_vidThrSecu                                    */
/* !Description :  Cette fonction décrit la sécurisation des diagnostiques    */
/*                 pour le Safety niveau 2 la papillon                        */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDftCoh_Thr;                                        */
/*  input uint8 SftyMgt_nUpTranThd_ThrCoh_C;                                  */
/*  input uint8 SftyMgt_nDownThd_ThrCoh_C;                                    */
/*  input uint8 SftyMgt_nInitCpt_ThrCoh_C;                                    */
/*  input uint8 SftyMgt_nDecCpt_ThrCoh_C;                                     */
/*  input uint8 DIAGSFTYLVL2_u8CntFilt_Thr;                                   */
/*  input boolean DIAGSFTYLVL2_bFilSig_Thr;                                   */
/*  input uint8 DIAGSFTYLVL2_u8CountNiv2_Thr;                                 */
/*  input boolean DIAGSFTYLVL2_bDgoNiv2_Thr;                                  */
/*  output boolean SftyMgt_bDftSftyCoh_Thr;                                   */
/*  output boolean DIAGSFTYLVL2_bDgoNiv2_Thr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGSFTYLVL2_vidThrSecu(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(SftyMgt_bDftCoh_Thr,
                                SftyMgt_nUpTranThd_ThrCoh_C,
                                SftyMgt_nDownThd_ThrCoh_C,
                                SftyMgt_nInitCpt_ThrCoh_C,
                                SftyMgt_nDecCpt_ThrCoh_C,
                                &DIAGSFTYLVL2_u8CntFilt_Thr,
                                &DIAGSFTYLVL2_bFilSig_Thr,
                                &DIAGSFTYLVL2_u8CountNiv2_Thr,
                                &DIAGSFTYLVL2_bDgoNiv2_Thr);

   VEMS_vidSET(SftyMgt_bDftSftyCoh_Thr, DIAGSFTYLVL2_bDgoNiv2_Thr);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/