/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OFSVLV                                                  */
/* !Description     : OFSVLV Component                                        */
/*                                                                            */
/* !Module          : OFSVLV                                                  */
/* !Description     : Limitation balayage et coordination des consignes VVT   */
/*                                                                            */
/* !File            : OFSVLV_FCT1.C                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / OFSVLV_vidInitOutput                                                 */
/*   2 / OFSVLV_vidPilotageCroimntMaxInit                                     */
/*   3 / OFSVLV_vidInit                                                       */
/*   4 / OFSVLV_vidVlvArb                                                     */
/*   5 / OFSVLV_vidDefinition_butee                                           */
/*   6 / OFSVLV_vidSaturations                                                */
/*   7 / OFSVLV_vidSatAdmission                                               */
/*   8 / OFSVLV_vidSatNot_Admission                                           */
/*   9 / OFSVLV_vidSatEchappement                                             */
/*   10 / OFSVLV_vidSatNot_Echappement                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 02164 / 02                                        */
/* !OtherRefs   : 01460_10_03509_2/1.1                                        */
/* !OtherRefs   : VEMS V02 ECU#053816                                         */
/* !OtherRefs   : VEMS V02 ECU#054358                                         */
/* !OtherRefs   : VEMS V02 ECU#061723                                         */
/* !OtherRefs   : VEMS V02 ECU#067972                                         */
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
#include "OFSVLV.h"
#include "OFSVLV_L.h"
#include "OFSVLV_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidInitOutput                                       */
/* !Description :  Initialisation des outputs                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OFSVLV_vidPilotageCroimntMaxInit();                      */
/*  input sint8 VlvSys_agCkClsExVlvReq;                                       */
/*  input sint8 VlvSys_agCkOpInVlvReq;                                        */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 VlvSys_agCkClsExVlvEstimIni;                                  */
/*  input uint8 VlvSys_agCkOpInVlvEstimIni;                                   */
/*  input sint16 OFSVLV_s16OutFilterIn;                                       */
/*  input sint16 OFSVLV_s16OutFilterEx;                                       */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint16 VlvSys_facCmdLimScv_M[8][8];                                 */
/*  output sint16 VlvSys_agCkOpInVlvSatCorReq_MP;                             */
/*  output sint16 VlvSys_agCkOpExVlvSatCorReq_MP;                             */
/*  output uint16 VlvSys_rTranAcvVlvSys;                                      */
/*  output sint16 OFSVLV_s16OutFilterEx;                                      */
/*  output sint16 OFSVLV_s16OutFilterIn;                                      */
/*  output sint32 OFSVLV_s32Filtre1Mem;                                       */
/*  output sint32 OFSVLV_s32Filtre2Mem;                                       */
/*  output boolean VlvSys_bPresInServo;                                       */
/*  output boolean VlvSys_bPresExServo;                                       */
/*  output uint16 VlvSys_facCmdLimScv;                                        */
/*  output uint8 VlvSys_agCkOpInVlvReqRef0Max;                                */
/*  output uint8 VlvSys_agCkClsExVlvReqRef0Min;                               */
/*  output uint8 VlvSys_agCkVlvOvlpMax;                                       */
/*  output uint8 VlvSys_agCkOpInVlvMin;                                       */
/*  output uint8 VlvSys_agCkClsExVlvMax;                                      */
/*  output uint8 VlvSys_agCkOpInVlvBedModCorReq;                              */
/*  output uint8 VlvSys_agCkClsExVlvBedModCorReq;                             */
/*  output uint8 VlvSys_agCkOpInVlvLocLopCorReq;                              */
/*  output uint8 VlvSys_agCkClsExVlvLocLopCorReq;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidInitOutput(void)
{
   sint8  s8LocalVlvSys_agCkClsExVlvReq;
   sint8  s8LocalVlvSys_agCkOpInVlvReq;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalVlvSysrAirLdAltiCorParaX;
   uint16 u16LocalExtnEngParaY;
   uint16 u16LocalfacCmdLimScv;


   VEMS_vidGET(VlvSys_agCkClsExVlvReq, s8LocalVlvSys_agCkClsExVlvReq);
   VEMS_vidGET(VlvSys_agCkOpInVlvReq, s8LocalVlvSys_agCkOpInVlvReq);
   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   /*RateLimiter*/
   VlvSys_agCkOpInVlvSatCorReq_MP =
      (sint16)(s8LocalVlvSys_agCkOpInVlvReq * 150);
   VlvSys_agCkOpExVlvSatCorReq_MP =
      (sint16)(s8LocalVlvSys_agCkClsExVlvReq * 150);

    /*F01_Transition_activation */
   VlvSys_rTranAcvVlvSys = 0;

   /*Filter*/
   OFSVLV_s16OutFilterEx = (sint16)((8 * VlvSys_agCkClsExVlvEstimIni) - 1024);
   OFSVLV_s16OutFilterIn = (sint16)((8 * VlvSys_agCkOpInVlvEstimIni) - 1024);
   OFSVLV_s32Filtre1Mem = OFSVLV_s16OutFilterIn * 65536;
   OFSVLV_s32Filtre2Mem = OFSVLV_s16OutFilterEx * 65536;

   /*F02_Pilotage_croisement_maximum */
   VlvSys_bPresInServo = VlvSys_bPresInServo_C;
   VlvSys_bPresExServo = VlvSys_bPresExServo_C;
   u16LocalVlvSysrAirLdAltiCorParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd8_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   8);
   u16LocalExtnEngParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                       u16LocalExt_nEng,
                                                       8);
   u16LocalfacCmdLimScv =
      MATHSRV_u16Interp2d(&VlvSys_facCmdLimScv_M[0][0],
                          u16LocalVlvSysrAirLdAltiCorParaX,
                          u16LocalExtnEngParaY,
                          8);
   VlvSys_facCmdLimScv = (uint16)MATHSRV_udtMIN(u16LocalfacCmdLimScv, 1000);
   VlvSys_agCkOpInVlvReqRef0Max = 128;
   VlvSys_agCkClsExVlvReqRef0Min = 128;
   VlvSys_agCkVlvOvlpMax = 128;
   OFSVLV_vidPilotageCroimntMaxInit();

   /*F03_Limitation_du_balayage */
   VlvSys_agCkOpInVlvMin = 128;
   VlvSys_agCkClsExVlvMax = 128;

   /* F04_mode_banc*/
   VlvSys_agCkOpInVlvBedModCorReq = 128;
   VlvSys_agCkClsExVlvBedModCorReq = 128;

   /*F06_Pilotage_VVT_en_butee */
   VlvSys_agCkOpInVlvLocLopCorReq = 128;
   VlvSys_agCkClsExVlvLocLopCorReq = 128;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidPilotageCroimntMaxInit                           */
/* !Description :  Elle permet l' initialisation de l'automate.               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint8 VlvSys_agCkClsExVlvSatCorReq;                                 */
/*  input sint8 VlvSys_agCkOpInVlvSatCorReq;                                  */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0Min;                                */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0Max;                                 */
/*  input uint8 VlvSys_agCkVlvOvlpMax;                                        */
/*  input uint16 VlvSys_facCmdLimScv;                                         */
/*  input boolean VlvSys_bPresInServo;                                        */
/*  input boolean VlvSys_bPresExServo;                                        */
/*  output st124 OFSVLV_u8PilotageCroismntMax;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidPilotageCroimntMaxInit(void)
{
   /*F02_Pilotage_croisement_maximum:INIT*/
   sint8  s8LocalInVlvSatCorReq;
   sint8  s8LocalExVlvSatCorReq;
   sint16 s16LocalMulop1;
   sint16 s16LocalMulop4;
   uint32 u32LocalRefMin;
   uint32 u32LocalRefMax;
   sint32 s32LocalMulop2;
   sint32 s32LocaReqRef0Max;
   sint32 s32LocaReqRef0Min;


   VEMS_vidGET(VlvSys_agCkClsExVlvSatCorReq, s8LocalExVlvSatCorReq);
   VEMS_vidGET(VlvSys_agCkOpInVlvSatCorReq, s8LocalInVlvSatCorReq);
   /* Operation 2 */
   s16LocalMulop4 = (sint16)( ( VlvSys_agCkClsExVlvReqRef0Min
                              - VlvSys_agCkOpInVlvReqRef0Max)
                            + 128);
   u32LocalRefMin = (uint32)(VlvSys_agCkClsExVlvReqRef0Min * 1000);
   u32LocalRefMax = (uint32)(VlvSys_agCkOpInVlvReqRef0Max * 1000);
   /* Operation 2 */

   s16LocalMulop1 = (sint16)( ( s8LocalExVlvSatCorReq
                              - VlvSys_agCkVlvOvlpMax)
                            + 256);
   s32LocalMulop2 = (sint32)( (1000 - VlvSys_facCmdLimScv)
                            * (s8LocalInVlvSatCorReq + 128));
   s32LocaReqRef0Max = ( (s16LocalMulop1 * VlvSys_facCmdLimScv)
                       + s32LocalMulop2);
   s32LocaReqRef0Min = ( s32LocaReqRef0Max
                       + (sint32)( (VlvSys_agCkVlvOvlpMax - 128)
                                 * 1000));
   if (VlvSys_bPresInServo == 0)
   {
      if (VlvSys_bPresExServo != 0)
      {
         if (s16LocalMulop4 < (sint16)VlvSys_agCkVlvOvlpMax)
         {
            OFSVLV_u8PilotageCroismntMax = VVT_ADM_EN_BUTEE;
         }
         else
         {
            OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
         }
      }
      else
      {
         OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
      }
   }
   else
   {
      if (VlvSys_bPresExServo != 0)
      {
         if (s32LocaReqRef0Min > (sint32)u32LocalRefMin)
         {
            if (s32LocaReqRef0Max >= (sint32)u32LocalRefMax)
            {
               OFSVLV_u8PilotageCroismntMax = VVT_ADM_EN_BUTEE;
            }
            else
            {
               /*Condition (s16LocalMulop4 >= VlvSys_agCkVlvOvlpMax) False */
               OFSVLV_u8PilotageCroismntMax = PAS_DE_VVT_EN_BUTEE;
            }
         }
         else
         {
            if (s16LocalMulop4 >= (sint16)VlvSys_agCkVlvOvlpMax)
            {
               OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
            }
            else
            {
               /* s32LocaReqRef0Max < u32LocalRefMax*/
               OFSVLV_u8PilotageCroismntMax = VVT_ECH_EN_BUTEE;
            }
         }
      }
      else
      {
         if (s16LocalMulop4 >= (sint16)VlvSys_agCkVlvOvlpMax)
         {
            OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
         }
         else
         {
            OFSVLV_u8PilotageCroismntMax = VVT_ECH_EN_BUTEE;
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidInit                                             */
/* !Description :  Initialisation des consignes VVT à leurs butées de repos   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 VlvSys_agCkClsExVlvReqRef0Min_C;                              */
/*  input sint8 VlvSys_agCkOpInVlvReqRef0Max_C;                               */
/*  output boolean VlvSys_bDetExServoDftPos;                                  */
/*  output boolean VlvSys_bDetInServoDftPos;                                  */
/*  output sint8 VlvSys_agCkClsExVlvSatCorReq;                                */
/*  output sint8 VlvSys_agCkClsExVlvReqRef0Min_C;                             */
/*  output uint8 VlvSys_agCkClsExVlvAcvCorReq;                                */
/*  output uint8 VlvSys_agCkClsExVlvReqRef0;                                  */
/*  output sint8 VlvSys_agCkOpInVlvSatCorReq;                                 */
/*  output sint8 VlvSys_agCkOpInVlvReqRef0Max_C;                              */
/*  output uint8 VlvSys_agCkOpInVlvAcvCorReq;                                 */
/*  output uint8 VlvSys_agCkOpInVlvReqRef0;                                   */
/*  output uint8 VlvSys_agCkClsExVlvEstimIni;                                 */
/*  output uint8 VlvSys_agCkOpInVlvEstimIni;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidInit(void)
{
   uint8 u8LocalCkClsExVlvReqRef0Min;
   uint8 u8LocalOpInVlvReqRef0Max;


   VEMS_vidSET(VlvSys_bDetExServoDftPos, 1);
   VEMS_vidSET(VlvSys_bDetInServoDftPos, 1);
   u8LocalCkClsExVlvReqRef0Min = (uint8)(VlvSys_agCkClsExVlvReqRef0Min_C + 128);
   u8LocalOpInVlvReqRef0Max = (uint8)(VlvSys_agCkOpInVlvReqRef0Max_C + 128);
   VEMS_vidSET(VlvSys_agCkClsExVlvSatCorReq, VlvSys_agCkClsExVlvReqRef0Min_C);
   VEMS_vidSET(VlvSys_agCkClsExVlvAcvCorReq, u8LocalCkClsExVlvReqRef0Min);
   VEMS_vidSET(VlvSys_agCkClsExVlvReqRef0, u8LocalCkClsExVlvReqRef0Min);
   VEMS_vidSET(VlvSys_agCkOpInVlvSatCorReq, VlvSys_agCkOpInVlvReqRef0Max_C);
   VEMS_vidSET(VlvSys_agCkOpInVlvAcvCorReq, u8LocalOpInVlvReqRef0Max);
   VEMS_vidSET(VlvSys_agCkOpInVlvReqRef0, u8LocalOpInVlvReqRef0Max);
   VlvSys_agCkClsExVlvEstimIni = u8LocalCkClsExVlvReqRef0Min;
   VlvSys_agCkOpInVlvEstimIni = u8LocalOpInVlvReqRef0Max;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidVlvArb                                           */
/* !Description :  Elle permet d'appliquer, aux consignes VVT admission et    */
/*                 échappement, des consignes spécifiques en fonctions de     */
/*                 plusieurs conditions d'arbitrage.                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidDefinition_butee();                            */
/*  extf argret void OFSVLV_vidSaturations();                                 */
/*  extf argret void OFSVLV_vidLimitation_du_balayage();                      */
/*  extf argret void OFSVLV_vidMode_banc();                                   */
/*  extf argret void OFSVLV_vidActivation();                                  */
/*  extf argret void OFSVLV_vidPilotage_VVT_en_butee();                       */
/*  extf argret void OFSVLV_vidPanne();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidVlvArb(void)
{
   OFSVLV_vidDefinition_butee();
   OFSVLV_vidSaturations();
   OFSVLV_vidLimitation_du_balayage();
   OFSVLV_vidMode_banc();
   OFSVLV_vidActivation();
   OFSVLV_vidPilotage_VVT_en_butee();
   OFSVLV_vidPanne();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidDefinition_butee                                 */
/* !Description :  Elle permet de déterminer les butées minimum et maximum des*/
/*                 actionneurs VVT admission et échappement                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvSys_bAcvDftPosLocLop_C;                                  */
/*  input sint8 VlvAct_agCkOpInVlvReqRef0Min;                                 */
/*  input sint8 VlvAct_agCkOpInVlvReqRef0Max;                                 */
/*  input sint8 VlvAct_agCkClsExVlvReqRef0Min;                                */
/*  input sint8 VlvAct_agCkClsExVlvReqRef0Max;                                */
/*  input sint8 VlvSys_agCkOpInVlvReqRef0Min_C;                               */
/*  input sint8 VlvSys_agCkOpInVlvReqRef0Max_C;                               */
/*  input sint8 VlvSys_agCkClsExVlvReqRef0Min_C;                              */
/*  input sint8 VlvSys_agCkClsExVlvReqRef0Max_C;                              */
/*  output sint8 VlvSys_agCkOpInVlvReqRef0Min;                                */
/*  output uint8 VlvSys_agCkOpInVlvReqRef0Max;                                */
/*  output uint8 VlvSys_agCkClsExVlvReqRef0Min;                               */
/*  output sint8 VlvSys_agCkClsExVlvReqRef0Max;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidDefinition_butee(void)
{
   sint8 s8LocalAgCkOpInVlvReqRef0Min;
   sint8 s8LocalAgCkOpInVlvReqRef0Max;
   sint8 s8LocalAgCkClsExVlvReqRef0Min;
   sint8 S8LocalAgCkClsExVlvReqRef0Max;


   if (VlvSys_bAcvDftPosLocLop_C != 0)
   {
      VEMS_vidGET(VlvAct_agCkOpInVlvReqRef0Min, s8LocalAgCkOpInVlvReqRef0Min);
      VlvSys_agCkOpInVlvReqRef0Min = s8LocalAgCkOpInVlvReqRef0Min;
      VEMS_vidGET(VlvAct_agCkOpInVlvReqRef0Max, s8LocalAgCkOpInVlvReqRef0Max);
      VlvSys_agCkOpInVlvReqRef0Max =
         (uint8)(s8LocalAgCkOpInVlvReqRef0Max + 128);
      VEMS_vidGET(VlvAct_agCkClsExVlvReqRef0Min, s8LocalAgCkClsExVlvReqRef0Min);
      VlvSys_agCkClsExVlvReqRef0Min =
         (uint8)(s8LocalAgCkClsExVlvReqRef0Min + 128);
      VEMS_vidGET(VlvAct_agCkClsExVlvReqRef0Max, S8LocalAgCkClsExVlvReqRef0Max);
      VlvSys_agCkClsExVlvReqRef0Max = S8LocalAgCkClsExVlvReqRef0Max;
   }
   else
   {
      VlvSys_agCkOpInVlvReqRef0Min = VlvSys_agCkOpInVlvReqRef0Min_C;
      VlvSys_agCkOpInVlvReqRef0Max =
         (uint8)(VlvSys_agCkOpInVlvReqRef0Max_C + 128);
      VlvSys_agCkClsExVlvReqRef0Min =
         (uint8)(VlvSys_agCkClsExVlvReqRef0Min_C + 128);
      VlvSys_agCkClsExVlvReqRef0Max = VlvSys_agCkClsExVlvReqRef0Max_C;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidSaturations                                      */
/* !Description :  Elle a pour but de limiter les gradients de consigne VVT et*/
/*                 de saturer les consignes VVT.                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidSatAdmission();                                */
/*  extf argret void OFSVLV_vidSatNot_Admission();                            */
/*  extf argret void OFSVLV_vidSatEchappement();                              */
/*  extf argret void OFSVLV_vidSatNot_Echappement();                          */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidSaturations(void)
{
   if (VlvSys_bPresInServo_C != 0)
   {
      OFSVLV_vidSatAdmission();
   }
   else
   {
      OFSVLV_vidSatNot_Admission();
   }
   if (VlvSys_bPresExServo_C != 0)
   {
      OFSVLV_vidSatEchappement();
   }
   else
   {
      OFSVLV_vidSatNot_Echappement();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidSatAdmission                                     */
/* !Description :  Elle permet de limiter les gradients ascendants et         */
/*                 descendants de la consigne VVT admission par des facteurs  */
/*                 fonction du régime et de la charge                         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint8 VlvSys_agCkOpInVlvReq;                                        */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint16 VlvSys_agCkGrdIncOpInVlv_M[16][16];                          */
/*  input uint16 VlvSys_agCkGrdDecOpInVlv_M[16][16];                          */
/*  input boolean VlvSys_bAcvOpInVlvRateLim_C;                                */
/*  input sint16 VlvSys_agCkOpInVlvSatCorReq_MP;                              */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0Max;                                 */
/*  input sint8 VlvSys_agCkOpInVlvReqRef0Min;                                 */
/*  output sint16 VlvSys_agCkOpInVlvSatCorReq_MP;                             */
/*  output sint8 VlvSys_agCkOpInVlvSatCorReq;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidSatAdmission(void)
{
   /* F01_Admission */
   sint8  s8LocalVlvSys_agCkOpInVlvReq;
   sint8  s8LocalCkOpInVlvSatCorReq;
   sint8  s8LocalMax;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalVlvSysrAirLdAltiCorParaX;
   uint16 u16LocalExtnEngParaY;
   uint16 u16LocalAgCkOpInVlvReqInc;
   uint16 u16LocalAgCkOpInVlvReqDec;
   sint16 s16LocalAgCkOpInVlvReqDec;
   sint16 s16LocalVlvSys_agCkOpInVlvReq;
   sint16 s16LocalagCkOpInVlvSatCorReq_MP;
   sint16 s16LocalMin;
   sint16 s16LocalMax;
   sint16 s16LocalCkOpInVlvSatCorReq;
   sint32 s32LocalAgCkOpInVlvReqInc;
   sint32 s32LocalAgCkOpInVlvReqDec;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(VlvSys_agCkOpInVlvReq, s8LocalVlvSys_agCkOpInVlvReq);

   u16LocalVlvSysrAirLdAltiCorParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);

   u16LocalExtnEngParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                       u16LocalExt_nEng,
                                                       16);

   u16LocalAgCkOpInVlvReqInc =
      MATHSRV_u16Interp2d(&VlvSys_agCkGrdIncOpInVlv_M[0][0],
                          u16LocalVlvSysrAirLdAltiCorParaX,
                          u16LocalExtnEngParaY,
                          16);
   u16LocalAgCkOpInVlvReqDec =
      MATHSRV_u16Interp2d(&VlvSys_agCkGrdDecOpInVlv_M[0][0],
                          u16LocalVlvSysrAirLdAltiCorParaX,
                          u16LocalExtnEngParaY,
                          16);
   /* VlvSys_agCkGrdDecOpInVlv_M: Unit =°Ck/s                                 */
   /* VlvSys_agCkGrdIncOpInVlv_M: Unit =°Ck/s                                 */
   /* VlvSys_tiSampleFast_SC = 10ms --> Division by 100                       */
   s32LocalAgCkOpInVlvReqInc =
         (sint32) ( ( ( u16LocalAgCkOpInVlvReqInc
                       - 20000)
                     * VlvSys_tiSampleFast_SC) / 10);

   s32LocalAgCkOpInVlvReqDec =
         (sint32) ( ( ( u16LocalAgCkOpInVlvReqDec
                       - 20000)
                     * VlvSys_tiSampleFast_SC) / 10);

   u16LocalAgCkOpInVlvReqInc =
      (uint16)MATHSRV_udtMAX(s32LocalAgCkOpInVlvReqInc, 0);
   s16LocalAgCkOpInVlvReqDec =
      (sint16)MATHSRV_udtMIN(s32LocalAgCkOpInVlvReqDec, 0);

   s16LocalVlvSys_agCkOpInVlvReq = (sint16)(s8LocalVlvSys_agCkOpInVlvReq * 150);

   if (VlvSys_bAcvOpInVlvRateLim_C != 0)
   {
      s16LocalagCkOpInVlvSatCorReq_MP =
         MATHSRV_s16SlewFilter(VlvSys_agCkOpInVlvSatCorReq_MP,
                               s16LocalVlvSys_agCkOpInVlvReq,
                               u16LocalAgCkOpInVlvReqInc,
                               (uint16)(-s16LocalAgCkOpInVlvReqDec));
   }
   else
   {
      s16LocalagCkOpInVlvSatCorReq_MP = s16LocalVlvSys_agCkOpInVlvReq;
   }
   VlvSys_agCkOpInVlvSatCorReq_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalagCkOpInVlvSatCorReq_MP, -19200, 19199);

   s8LocalMax = (sint8)(VlvSys_agCkOpInVlvReqRef0Max - 128);
   s16LocalMin = (sint16)(VlvSys_agCkOpInVlvReqRef0Min * 150);
   s16LocalMax = (sint16)(s8LocalMax * 150);
   s16LocalCkOpInVlvSatCorReq =
      (sint16)MATHSRV_udtCLAMP(VlvSys_agCkOpInVlvSatCorReq_MP,
                              s16LocalMin,
                              s16LocalMax);
   s8LocalCkOpInVlvSatCorReq = (sint8)(s16LocalCkOpInVlvSatCorReq / 150);
   VEMS_vidSET(VlvSys_agCkOpInVlvSatCorReq, s8LocalCkOpInVlvSatCorReq);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidSatNot_Admission                                 */
/* !Description :  Dans le cas où, le moteur n’est pas équipé d’un VVT        */
/*                 admission, la consigne est égale à la butée                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0Max;                                 */
/*  output sint8 VlvSys_agCkOpInVlvSatCorReq;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidSatNot_Admission(void)
{
   sint8 s8LocalCalc;


   s8LocalCalc = (sint8)(VlvSys_agCkOpInVlvReqRef0Max - 128);
   VEMS_vidSET(VlvSys_agCkOpInVlvSatCorReq, s8LocalCalc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidSatEchappement                                   */
/* !Description :  On limite les gradients ascendants et descendants de la    */
/*                 consigne VVT échappement par des facteurs fonction du      */
/*                 régime et de la charge                                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint8 VlvSys_agCkClsExVlvReq;                                       */
/*  input uint16 VlvSys_rAirLd16_A[16];                                       */
/*  input uint16 VlvSys_nEng16_A[16];                                         */
/*  input uint16 VlvSys_agCkGrdIncClsExVlv_M[16][16];                         */
/*  input uint16 VlvSys_agCkGrdDecClsExVlv_M[16][16];                         */
/*  input boolean VlvSys_bAcvClsExVlvRateLim_C;                               */
/*  input sint16 VlvSys_agCkOpExVlvSatCorReq_MP;                              */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0Min;                                */
/*  input sint8 VlvSys_agCkClsExVlvReqRef0Max;                                */
/*  output sint16 VlvSys_agCkOpExVlvSatCorReq_MP;                             */
/*  output sint8 VlvSys_agCkClsExVlvSatCorReq;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidSatEchappement(void)
{
/*  F03_Echappement */
   sint8  s8LocalVlvSys_agCkClsExVlvReq;
   sint8  s8LocalExVlvSatCorReq;
   sint8  s8LocalMin;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalVlvSysrAirLdAltiCorParaX;
   uint16 u16LocalExtnEngParaY;
   uint16 u16LocalAgCkOpExVlvReqInc;
   uint16 u16LocalAgCkOpExVlvReqDec;
   sint16 s16LocalAgCkOpExVlvReqDec;
   sint16 s16LocalVlvSys_agCkClsExVlvReq;
   sint16 s16LocalagCkOpExVlvSatCorReq_MP;
   sint16 s16LocalExVlvSatCorReq;
   sint16 s16LocalMin;
   sint16 s16LocalMax;
   sint32 s32LocalAgCkOpExVlvReqInc;
   sint32 s32LocalAgCkOpExVlvReqDec;


   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(VlvSys_agCkClsExVlvReq, s8LocalVlvSys_agCkClsExVlvReq);

   u16LocalVlvSysrAirLdAltiCorParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd16_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   16);

   u16LocalExtnEngParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng16_A,
                                                       u16LocalExt_nEng,
                                                       16);
   u16LocalAgCkOpExVlvReqInc =
      MATHSRV_u16Interp2d(&VlvSys_agCkGrdIncClsExVlv_M[0][0],
                          u16LocalVlvSysrAirLdAltiCorParaX,
                          u16LocalExtnEngParaY,
                          16);
   u16LocalAgCkOpExVlvReqDec =
      MATHSRV_u16Interp2d(&VlvSys_agCkGrdDecClsExVlv_M[0][0],
                          u16LocalVlvSysrAirLdAltiCorParaX,
                          u16LocalExtnEngParaY,
                          16);
   /* VlvSys_agCkGrdIncClsExVlv_M: Unit =°Ck/s                                */
   /* VlvSys_agCkGrdDecClsExVlv_M: Unit =°Ck/s                                */
   /* VlvSys_tiSampleFast_SC = 10ms --> Division by 100                       */

   s32LocalAgCkOpExVlvReqInc =
      (sint32)( ( ( u16LocalAgCkOpExVlvReqInc
                  - 20000)
                * VlvSys_tiSampleFast_SC) / 10);
   s32LocalAgCkOpExVlvReqDec =
      (sint32)( ( ( u16LocalAgCkOpExVlvReqDec
                    - 20000)
                  * VlvSys_tiSampleFast_SC) / 10);

   u16LocalAgCkOpExVlvReqInc =
      (uint16)MATHSRV_udtMAX(s32LocalAgCkOpExVlvReqInc, 0);
   s16LocalAgCkOpExVlvReqDec =
      (sint16)MATHSRV_udtMIN(s32LocalAgCkOpExVlvReqDec, 0);
   s16LocalVlvSys_agCkClsExVlvReq =
      (sint16)(s8LocalVlvSys_agCkClsExVlvReq * 150);

   if (VlvSys_bAcvClsExVlvRateLim_C != 0)
   {
      s16LocalagCkOpExVlvSatCorReq_MP =
         MATHSRV_s16SlewFilter(VlvSys_agCkOpExVlvSatCorReq_MP,
                               s16LocalVlvSys_agCkClsExVlvReq,
                               u16LocalAgCkOpExVlvReqInc,
                               (uint16)(-s16LocalAgCkOpExVlvReqDec));
   }
   else
   {
      s16LocalagCkOpExVlvSatCorReq_MP = s16LocalVlvSys_agCkClsExVlvReq;
   }
   VlvSys_agCkOpExVlvSatCorReq_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalagCkOpExVlvSatCorReq_MP, -19200, 19199);

   s8LocalMin = (sint8)(VlvSys_agCkClsExVlvReqRef0Min - 128);
   s16LocalMin = (sint16)(s8LocalMin * 150);
   s16LocalMax = (sint16)(VlvSys_agCkClsExVlvReqRef0Max * 150);
   s16LocalExVlvSatCorReq =
      (sint16)MATHSRV_udtCLAMP(VlvSys_agCkOpExVlvSatCorReq_MP,
                              s16LocalMin,
                              s16LocalMax);
   s8LocalExVlvSatCorReq = (sint8)(s16LocalExVlvSatCorReq / 150);
   VEMS_vidSET(VlvSys_agCkClsExVlvSatCorReq, s8LocalExVlvSatCorReq);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidSatNot_Echappement                               */
/* !Description :  Dans le cas où, le moteur n’est pas équipé d’un VVT        */
/*                 échappement, la consigne est égale à la butée.             */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0Min;                                */
/*  output sint8 VlvSys_agCkClsExVlvSatCorReq;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidSatNot_Echappement(void)
{
   sint8 s8LocalExVlvSatCorReq;


   s8LocalExVlvSatCorReq = (sint8)(VlvSys_agCkClsExVlvReqRef0Min - 128);
   VEMS_vidSET(VlvSys_agCkClsExVlvSatCorReq, s8LocalExVlvSatCorReq);
}

/*------------------------------- end of file --------------------------------*/