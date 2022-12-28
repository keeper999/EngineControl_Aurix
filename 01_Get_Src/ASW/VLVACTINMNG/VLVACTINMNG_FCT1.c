/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINMNG                                             */
/* !Description     : VLVACTINMNG component.                                  */
/*                                                                            */
/* !Module          : VLVACTINMNG                                             */
/* !Description     : MANAGER DE LA FONCTION VVT ADMISSION .                  */
/*                                                                            */
/* !File            : VLVACTINMNG_FCT1.C                                      */
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
/*   1 / VLVACTINMNG_vidInitOutput                                            */
/*   2 / VLVACTINMNG_vidInitStEnaCdn                                          */
/*   3 / VLVACTINMNG_vidTimer1                                                */
/*   4 / VLVACTINMNG_vidLrnStEnaCdn                                           */
/*   5 / VLVACTINMNG_vidServoStEnaCdn                                         */
/*   6 / VLVACTINMNG_vidClnStEnaCdn                                           */
/*   7 / VLVACTINMNG_vidStMng                                                 */
/*   8 / VLVACTINMNG_vidMngStCmd                                              */
/*   9 / VLVACTINMNG_vidTimer2                                                */
/*   10 / VLVACTINMNG_vidEngStopAuth                                          */
/*                                                                            */
/* !Reference   : V02 NT 08 07174 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#068180                                         */
/* !OtherRefs   : VEMS V02 ECU#068137                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINMNG/VLVACTINMNG$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Feb 2014 $*/
/* $Author::   etsasson                               $$Date::   17 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINMNG.h"
#include "VLVACTINMNG_L.h"
#include "VLVACTINMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidInitOutput                                  */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 VlvAct_InMngStCmd;                                          */
/*  output boolean VlvAct_bInLrnEna;                                          */
/*  output boolean VlvAct_bInServoEna;                                        */
/*  output boolean VlvAct_bInClnEna;                                          */
/*  output boolean VlvAct_bInEngStopAuth;                                     */
/*  output boolean VlvAct_bInCmdAuth;                                         */
/*  output boolean VlvAct_bInMngLrnStEna;                                     */
/*  output boolean VlvAct_bInMngServoStEna;                                   */
/*  output boolean VLVACTINMNG_bTimeout1;                                     */
/*  output boolean VLVACTINMNG_bTimeout2;                                     */
/*  output boolean VLVACTINMNG_bTimeout3;                                     */
/*  output boolean VLVACTINMNG_bTimeout4;                                     */
/*  output boolean VLVACTINMNG_bTimeout5;                                     */
/*  output boolean VLVACTINMNG_bOilPresPrev;                                  */
/*  output boolean VLVACTINMNG_bVehicleStatePrev;                             */
/*  output uint8 VLVACTINMNG_u8VehActStatPrev;                                */
/*  output boolean VLVACTINMNG_bTimer1Input;                                  */
/*  output boolean VLVACTINMNG_bTimer2Input;                                  */
/*  output uint8 VLVACTINMNG_u8Tempo1;                                        */
/*  output uint8 VLVACTINMNG_u8Tempo2;                                        */
/*  output uint8 VLVACTINMNG_u8Tempo3;                                        */
/*  output uint8 VLVACTINMNG_u8Tempo4;                                        */
/*  output uint16 VLVACTINMNG_u16Tempo5;                                      */
/*  output boolean VlvAct_bInMngInitStEna;                                    */
/*  output boolean VLVACTINMNG_bInLrnHyst01;                                  */
/*  output boolean VLVACTINMNG_bInLrnHyst02;                                  */
/*  output boolean VLVACTINMNG_bInLrnHyst03;                                  */
/*  output boolean VLVACTINMNG_bInLrnHyst04;                                  */
/*  output boolean VLVACTINMNG_bInLrnHyst05;                                  */
/*  output boolean VLVACTINMNG_bInLrnHyst06;                                  */
/*  output boolean VLVACTINMNG_bInLrnHyst07;                                  */
/*  output boolean VLVACTINMNG_bInLrnHyst08;                                  */
/*  output boolean VLVACTINMNG_bInServoHyst01;                                */
/*  output boolean VLVACTINMNG_bInServoHyst02;                                */
/*  output boolean VLVACTINMNG_bInServoHyst03;                                */
/*  output boolean VLVACTINMNG_bTOilInUnlckThd;                               */
/*  output boolean VLVACTINMNG_bNEngInUnlckThd;                               */
/*  output boolean VLVACTINMNG_bAgInAcvUnlckPosnThd;                          */
/*  output boolean VLVACTINMNG_bagInAcvSpFuncIntThd;                          */
/*  output uint8 VlvAct_tiInUnlck;                                            */
/*  output uint8 VlvAct_noInUnlckStr;                                         */
/*  output st43 VlvAct_InUnlckStrSt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidInitOutput(void)
{
   VEMS_vidSET(VlvAct_InMngStCmd, 0);
   VEMS_vidSET(VlvAct_bInLrnEna, 0);
   VEMS_vidSET(VlvAct_bInServoEna, 0);
   VEMS_vidSET(VlvAct_bInClnEna, 0);
   VEMS_vidSET(VlvAct_bInEngStopAuth, 0);
   VEMS_vidSET(VlvAct_bInCmdAuth, 0);
   VEMS_vidSET(VlvAct_bInMngLrnStEna, 0);
   VEMS_vidSET(VlvAct_bInMngServoStEna, 0);

   VLVACTINMNG_bTimeout1 = 0;
   VLVACTINMNG_bTimeout2 = 0;
   VLVACTINMNG_bTimeout3 = 0;
   VLVACTINMNG_bTimeout4 = 0;
   VLVACTINMNG_bTimeout5 = 0;
   VLVACTINMNG_bOilPresPrev = 0;
   VLVACTINMNG_bVehicleStatePrev = 0;
   VLVACTINMNG_u8VehActStatPrev = 0;

   VLVACTINMNG_bTimer1Input = 0;
   VLVACTINMNG_bTimer2Input = 0;
   VLVACTINMNG_u8Tempo1 = 0;
   VLVACTINMNG_u8Tempo2 = 0;
   VLVACTINMNG_u8Tempo3 = 0;
   VLVACTINMNG_u8Tempo4 = 0;
   VLVACTINMNG_u16Tempo5 = 0;

   VlvAct_bInMngInitStEna = 0;

   VLVACTINMNG_bInLrnHyst01 = 0;
   VLVACTINMNG_bInLrnHyst02 = 0;
   VLVACTINMNG_bInLrnHyst03 = 0;
   VLVACTINMNG_bInLrnHyst04 = 0;
   VLVACTINMNG_bInLrnHyst05 = 0;
   VLVACTINMNG_bInLrnHyst06 = 0;
   VLVACTINMNG_bInLrnHyst07 = 0;
   VLVACTINMNG_bInLrnHyst08 = 0;

   VLVACTINMNG_bInServoHyst01 = 0;
   VLVACTINMNG_bInServoHyst02 = 0;
   VLVACTINMNG_bInServoHyst03 = 0;

   VLVACTINMNG_bTOilInUnlckThd = 0;
   VLVACTINMNG_bNEngInUnlckThd = 0;
   VLVACTINMNG_bAgInAcvUnlckPosnThd = 0;
   VLVACTINMNG_bagInAcvSpFuncIntThd = 0;

   VlvAct_tiInUnlck = 0;
   VlvAct_noInUnlckStr = 0;
   VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_IDLE;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidInitStEnaCdn                                */
/* !Description :  Quelque soit l’état de l’automate de gestion de la fonction*/
/*                 VVT admission, le décaleur doit pouvoir revenir à sa       */
/*                 position de repos dés que les conditions de fonctionnement */
/*                 nominal ne sont plus réunies, afin de protéger l’actionneur*/
/*                 de décalage.                                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_009.01                                     */
/*                 VEMS_R_08_07174_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input st23 Vehicle_active_state;                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  input sint16 VlvAct_tOilInInitThdHi_C;                                    */
/*  input sint16 VlvAct_tOilInInitThdHiHys_C;                                 */
/*  input boolean VlvAct_bInMngInitStEna;                                     */
/*  input uint8 VlvAct_tCoInCmdAuthDly_T[5];                                  */
/*  input uint16 VlvAct_tiInCmdAuthDly_M[5];                                  */
/*  input uint8 VLVACTINMNG_u8VehActStatPrev;                                 */
/*  input uint16 VLVACTINMNG_u16Tempo5;                                       */
/*  input boolean VLVACTINMNG_bTimeout5;                                      */
/*  output boolean VlvAct_bInMngInitStEna;                                    */
/*  output uint16 VLVACTINMNG_u16Tempo5;                                      */
/*  output boolean VLVACTINMNG_bTimeout5;                                     */
/*  output uint8 VLVACTINMNG_u8VehActStatPrev;                                */
/*  output boolean VlvAct_bInCmdAuth;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidInitStEnaCdn(void)
{
   boolean bLocalVlvActInOfsFrstLrn;
   uint8   u8LocalVehicle_active_state;
   uint8   u8SiteInterpolation;
   uint16  u16LocalCalcPara;
   uint16  u16LocalInCmdAuthDly;
   sint16  s16LocalEng_tOilEstim;
   sint16  s16LocalExt_tCoMes;
   sint32  s32LocalCalc;
   sint32  s32LocaltOilInInitThdLow;
   sint32  s32LocalVlvActtOilInInitThdHi;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvActInOfsFrstLrn);

   s32LocaltOilInInitThdLow = (sint32)( 4 * ( VlvAct_tOilInInitThdHi_C
                                            - VlvAct_tOilInInitThdHiHys_C));
   s32LocalVlvActtOilInInitThdHi = (sint32)(4 * VlvAct_tOilInInitThdHi_C);

   if (VlvAct_bInMngInitStEna == 0)
   {
      if (s16LocalEng_tOilEstim > s32LocalVlvActtOilInInitThdHi)
      {
         VlvAct_bInMngInitStEna = 1;
      }
      else
      {
         VlvAct_bInMngInitStEna = 0;
      }
   }
   else
   {
      if (s16LocalEng_tOilEstim <= s32LocaltOilInInitThdLow)
      {
         VlvAct_bInMngInitStEna = 0;
      }
      else
      {
         VlvAct_bInMngInitStEna = 1;
      }
   }

   s32LocalCalc = (sint32)(s16LocalExt_tCoMes + 40);
   u8SiteInterpolation = (uint8)MATHSRV_udtCLAMP(s32LocalCalc, 0, 255);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(VlvAct_tCoInCmdAuthDly_T,
                                                  u8SiteInterpolation,
                                                  5);
   u16LocalInCmdAuthDly = MATHSRV_u16Interp1d(VlvAct_tiInCmdAuthDly_M,
                                              u16LocalCalcPara);

   if (  (u8LocalVehicle_active_state == VS_CRANKING)
      && (VLVACTINMNG_u8VehActStatPrev == VS_STALL))
   {
      VLVACTINMNG_u16Tempo5 = (uint16)MATHSRV_udtMIN(u16LocalInCmdAuthDly,
                                                     25600);
      if (VLVACTINMNG_u16Tempo5 == 0)
      {
         VLVACTINMNG_bTimeout5 = 1;
      }
      else
      {
         VLVACTINMNG_bTimeout5 = 0;
      }
   }
   else
   {
      if (VLVACTINMNG_u16Tempo5 > 0)
      {
         VLVACTINMNG_u16Tempo5 = (uint16)(VLVACTINMNG_u16Tempo5 - 1);
         if (VLVACTINMNG_u16Tempo5 == 0)
         {
            VLVACTINMNG_bTimeout5 = 1;
         }
         else
         {
            VLVACTINMNG_bTimeout5 = 0;
         }
      }
   }
   VLVACTINMNG_u8VehActStatPrev = u8LocalVehicle_active_state;

   if (  (bLocalVlvActInOfsFrstLrn != 0)
      && (VLVACTINMNG_bTimeout5 != 0))
   {
      VEMS_vidSET(VlvAct_bInCmdAuth, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInCmdAuth, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidTimer1                                      */
/* !Description :  Calcul des sorties des Timers 1 et 2                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bOilPres;                                               */
/*  input boolean VLVACTINMNG_bOilPresPrev;                                   */
/*  input uint8 VlvAct_tiInLrnOilPresDly_C;                                   */
/*  input uint8 VLVACTINMNG_u8Tempo1;                                         */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean VLVACTINMNG_bVehicleStatePrev;                              */
/*  input uint8 VlvAct_tiInLrnEngRunDly_C;                                    */
/*  input uint8 VLVACTINMNG_u8Tempo2;                                         */
/*  output uint8 VLVACTINMNG_u8Tempo1;                                        */
/*  output boolean VLVACTINMNG_bTimeout1;                                     */
/*  output uint8 VLVACTINMNG_u8Tempo2;                                        */
/*  output boolean VLVACTINMNG_bTimeout2;                                     */
/*  output boolean VLVACTINMNG_bOilPresPrev;                                  */
/*  output boolean VLVACTINMNG_bVehicleStatePrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidTimer1(void)
{
   boolean bLocalExt_bOilPres;
   boolean bLocalVehicle_active_state;
   uint8   u8LocalVehicle_active_state;


   VEMS_vidGET(Ext_bOilPres, bLocalExt_bOilPres);
   if (  (VLVACTINMNG_bOilPresPrev == 0)
      && (bLocalExt_bOilPres != 0))
   {
      VLVACTINMNG_u8Tempo1 = VlvAct_tiInLrnOilPresDly_C;
      if (VLVACTINMNG_u8Tempo1 == 0)
      {
         VLVACTINMNG_bTimeout1 = 1;
      }
      else
      {
         VLVACTINMNG_bTimeout1 = 0;
      }
   }
   else
   {
      if (VLVACTINMNG_u8Tempo1 > 0)
      {
         VLVACTINMNG_u8Tempo1 = (uint8)(VLVACTINMNG_u8Tempo1 - 1);
         if (VLVACTINMNG_u8Tempo1 == 0)
         {
            VLVACTINMNG_bTimeout1 = 1;
         }
         else
         {
            VLVACTINMNG_bTimeout1 = 0;
         }
      }
   }

   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if (u8LocalVehicle_active_state == VS_RUNNING)
   {
      bLocalVehicle_active_state = 1;
   }
   else
   {
      bLocalVehicle_active_state = 0;
   }
   if (  (VLVACTINMNG_bVehicleStatePrev == 0)
      && (bLocalVehicle_active_state != 0))
   {
      VLVACTINMNG_u8Tempo2 = VlvAct_tiInLrnEngRunDly_C;
      if (VLVACTINMNG_u8Tempo2 == 0)
      {
         VLVACTINMNG_bTimeout2 = 1;
      }
      else
      {
         VLVACTINMNG_bTimeout2 = 0;
      }
   }
   else
   {
      if (VLVACTINMNG_u8Tempo2 > 0)
      {
         VLVACTINMNG_u8Tempo2 = (uint8)(VLVACTINMNG_u8Tempo2 - 1);
         if (VLVACTINMNG_u8Tempo2 == 0)
         {
            VLVACTINMNG_bTimeout2 = 1;
         }
         else
         {
            VLVACTINMNG_bTimeout2 = 0;
         }
      }
   }
   VLVACTINMNG_bOilPresPrev = bLocalExt_bOilPres;
   VLVACTINMNG_bVehicleStatePrev = bLocalVehicle_active_state;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidLrnStEnaCdn                                 */
/* !Description :  L’apprentissage de la butée basse de l’actionneur de       */
/*                 décalage AAC admission n’est autorisé que lorsque toutes   */
/*                 les conditions adéquates de fonctionnement moteur sont     */
/*                 réunies                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINMNG_vidTimer1();                                 */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 VlvAct_tCoInLrnThdLo_C;                                      */
/*  input sint16 VlvAct_tCoInLrnThdLoHys_C;                                   */
/*  input boolean VLVACTINMNG_bInLrnHyst01;                                   */
/*  input sint16 VlvAct_tCoInLrnThdHi_C;                                      */
/*  input sint16 VlvAct_tCoInLrnThdHiHys_C;                                   */
/*  input boolean VLVACTINMNG_bInLrnHyst02;                                   */
/*  input sint16 VlvAct_tOilInLrnThdLo_C;                                     */
/*  input sint16 VlvAct_tOilInLrnThdLoHys_C;                                  */
/*  input boolean VLVACTINMNG_bInLrnHyst03;                                   */
/*  input sint16 VlvAct_tOilInLrnThdHi_C;                                     */
/*  input sint16 VlvAct_tOilInLrnThdHiHys_C;                                  */
/*  input boolean VLVACTINMNG_bInLrnHyst04;                                   */
/*  input uint8 VlvAct_nEngInLrnThdLo_C;                                      */
/*  input uint8 VlvAct_nEngInLrnThdLoHys_C;                                   */
/*  input boolean VLVACTINMNG_bInLrnHyst05;                                   */
/*  input uint8 VlvAct_nEngInLrnThdHi_C;                                      */
/*  input uint8 VlvAct_nEngInLrnThdHiHys_C;                                   */
/*  input boolean VLVACTINMNG_bInLrnHyst06;                                   */
/*  input uint8 VlvAct_uBattInLrnThdLo_C;                                     */
/*  input uint8 VlvAct_uBattInLrnThdLoHys_C;                                  */
/*  input boolean VLVACTINMNG_bInLrnHyst07;                                   */
/*  input uint8 VlvAct_uBattInLrnThdHi_C;                                     */
/*  input uint8 VlvAct_uBattInLrnThdHiHys_C;                                  */
/*  input boolean VLVACTINMNG_bInLrnHyst08;                                   */
/*  input boolean VLVACTINMNG_bTimeout1;                                      */
/*  input boolean VLVACTINMNG_bTimeout2;                                      */
/*  output boolean VlvAct_bInMngLrnStEna;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidLrnStEnaCdn(void)
{
   boolean bLocalInhVlvActInLrn;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalInput;
   uint16  u16LocaltCoInLrnThd;
   uint16  u16LocaltCoInLrnThdSom;
   uint16  u16LocaltCoInLrnThdSou;
   uint16  u16LocalSom;
   sint16  s16LocalEng_tOilEstim;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocaltCoInLrnThdSou;
   sint16  s16LocalSou;
   sint16  s16LocalExt_uBattMes;
   sint32  s32LocaltCoInLrnThdSom;
   sint32  s32LocaltCoInLrnThdSou;
   sint32  s32LocalExt_tCoMes;
   sint32  s32LocalVlvActtCoInLrnThdLo;
   sint32  s32LocalVlvActtCoInLrnThdHi;
   sint32  s32LocalVlvActtOilInLrnThdLo;
   sint32  s32LocalVlvActtOilInLrnThdHi;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u16LocalInput = (uint16)MATHSRV_udtCLAMP(s32LocalExt_tCoMes,
                                            0,
                                            254);
   s32LocaltCoInLrnThdSou = (sint32)( ( VlvAct_tCoInLrnThdLo_C
                                      - VlvAct_tCoInLrnThdLoHys_C)
                                    + 40);
   u16LocaltCoInLrnThdSou = (uint16)MATHSRV_udtCLAMP(s32LocaltCoInLrnThdSou,
                                                     0,
                                                     255);
   s32LocalVlvActtCoInLrnThdLo = (sint32)(VlvAct_tCoInLrnThdLo_C + 40);
   u16LocaltCoInLrnThd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtCoInLrnThdLo,
                                                  0,
                                                  255);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoInLrnThdSou,
                                u16LocaltCoInLrnThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInLrnHyst01);

   s32LocalVlvActtCoInLrnThdHi = (sint32)(VlvAct_tCoInLrnThdHi_C + 40);
   u16LocaltCoInLrnThd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtCoInLrnThdHi,
                                                  0,
                                                  255);
   s32LocaltCoInLrnThdSom =(sint32)( VlvAct_tCoInLrnThdHi_C
                                   + VlvAct_tCoInLrnThdHiHys_C
                                   + 40);
   u16LocaltCoInLrnThdSom = (uint16)MATHSRV_udtCLAMP(s32LocaltCoInLrnThdSom,
                                                     0,
                                                     255);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoInLrnThd,
                                u16LocaltCoInLrnThdSom,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInLrnHyst02);

   u16LocalInput = (uint16)MATHSRV_udtCLAMP((s16LocalEng_tOilEstim + 200),
                                            0,
                                            1000);
   s32LocaltCoInLrnThdSou = (sint32)( ( ( VlvAct_tOilInLrnThdLo_C
                                        - VlvAct_tOilInLrnThdLoHys_C) * 4)
                                    + 200);
   u16LocaltCoInLrnThdSou = (uint16)MATHSRV_udtCLAMP(s32LocaltCoInLrnThdSou,
                                                     0,
                                                     1020);
   s32LocalVlvActtOilInLrnThdLo = (sint32)( ( VlvAct_tOilInLrnThdLo_C * 4)
                                          + 200);
   u16LocaltCoInLrnThd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtOilInLrnThdLo ,
                                                  0,
                                                  1020);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoInLrnThdSou,
                                u16LocaltCoInLrnThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInLrnHyst03);

   s32LocalVlvActtOilInLrnThdHi = (sint32)( (VlvAct_tOilInLrnThdHi_C * 4)
                                          + 200);
   u16LocaltCoInLrnThd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtOilInLrnThdHi,
                                                  0,
                                                  1020);
   s32LocaltCoInLrnThdSom = (sint32)( ( ( VlvAct_tOilInLrnThdHi_C
                                      + VlvAct_tOilInLrnThdHiHys_C) * 4)
                                    +  200);
   u16LocaltCoInLrnThdSom = (uint16)MATHSRV_udtCLAMP(s32LocaltCoInLrnThdSom,
                                                     0,
                                                     1020);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoInLrnThd,
                                u16LocaltCoInLrnThdSom,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInLrnHyst04);

   u16LocalInput = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 7500);
   s16LocalSou = (sint16)( ( VlvAct_nEngInLrnThdLo_C
                           - VlvAct_nEngInLrnThdLoHys_C)
                         * 32);
   u16LocaltCoInLrnThdSou = (uint16)MATHSRV_udtMAX(s16LocalSou, 0);
   u16LocaltCoInLrnThd = (uint16)(32 * VlvAct_nEngInLrnThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoInLrnThdSou,
                                u16LocaltCoInLrnThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInLrnHyst05);

   u16LocalSom = (uint16)( ( VlvAct_nEngInLrnThdHi_C
                           + VlvAct_nEngInLrnThdHiHys_C)
                         * 32);
   u16LocaltCoInLrnThdSom = (uint16)MATHSRV_udtMIN(u16LocalSom, 8160);
   u16LocaltCoInLrnThd = (uint16)(32 * VlvAct_nEngInLrnThdHi_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoInLrnThd,
                                u16LocaltCoInLrnThdSom,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInLrnHyst06);

   u16LocalInput = (uint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
   s16LocaltCoInLrnThdSou = (sint16)( ( VlvAct_uBattInLrnThdLo_C
                                      - VlvAct_uBattInLrnThdLoHys_C)
                                    * 8);
   u16LocaltCoInLrnThdSou = (uint16)MATHSRV_udtMAX(s16LocaltCoInLrnThdSou, 0);
   u16LocaltCoInLrnThd = (uint16)(8 * VlvAct_uBattInLrnThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoInLrnThdSou,
                                u16LocaltCoInLrnThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInLrnHyst07);

   u16LocaltCoInLrnThdSom =(uint16)( ( VlvAct_uBattInLrnThdHi_C
                                     + VlvAct_uBattInLrnThdHiHys_C)
                                   * 8);
   u16LocaltCoInLrnThd = (uint16)(8 * VlvAct_uBattInLrnThdHi_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoInLrnThd,
                                u16LocaltCoInLrnThdSom,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInLrnHyst08);

   VLVACTINMNG_vidTimer1();
   bLocalInhVlvActInLrn = GDGAR_bGetFRM(FRM_FRM_INHVLVACTINLRN);
   if (  (  (VLVACTINMNG_bInLrnHyst01 != 0)
         && (VLVACTINMNG_bInLrnHyst02 != 0))
      && (  (VLVACTINMNG_bInLrnHyst03 != 0)
         && (VLVACTINMNG_bInLrnHyst04 != 0))
      && (  (VLVACTINMNG_bInLrnHyst05 != 0)
         && (VLVACTINMNG_bInLrnHyst06 != 0))
      && (  (VLVACTINMNG_bInLrnHyst07 != 0)
         && (VLVACTINMNG_bInLrnHyst08 != 0))
      && (bLocalInhVlvActInLrn == 0)
      && (  (VLVACTINMNG_bTimeout1 != 0)
         || (VLVACTINMNG_bTimeout2 != 0)))
   {
      VEMS_vidSET(VlvAct_bInMngLrnStEna, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInMngLrnStEna, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidServoStEnaCdn                               */
/* !Description :  Le pilotage en boucle fermé de l’actionneur de décalage AAC*/
/*                 admission n’est autorisé que lorsque toutes les conditions */
/*                 adéquates de fonctionnement moteur sont réunies            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 VlvAct_tOilInServoThdLo_C;                                   */
/*  input sint16 VlvAct_tOilInServoThdLoHys_C;                                */
/*  input boolean VLVACTINMNG_bInServoHyst01;                                 */
/*  input uint8 VlvAct_uBattInServoThdLo_C;                                   */
/*  input uint8 VlvAct_uBattInServoThdLoHys_C;                                */
/*  input boolean VLVACTINMNG_bInServoHyst02;                                 */
/*  input uint8 VlvAct_nEngInServoThdLo_C;                                    */
/*  input uint8 VlvAct_nEngInServoThdLoHys_C;                                 */
/*  input boolean VLVACTINMNG_bInServoHyst03;                                 */
/*  output boolean VlvAct_bInMngServoStEna;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidServoStEnaCdn(void)
{
   uint16 u16LocalExt_nEng;
   uint16 u16LocalInput;
   uint16 u16LocaltOilInServoThd;
   uint16 u16LocaltOilInServoThdSou;
   sint16 s16LocalEng_tOilEstim;
   sint16 s16LocaltOilInServoThdSou;
   sint16 s16LocalExt_uBattMes;
   sint32 s32LocaltOilInServoThdSou;
   sint32 s32LocalEng_tOilEstim;
   sint32 s32LocalVlvActtOilInServoThdLo;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   s32LocalEng_tOilEstim = (sint32)(s16LocalEng_tOilEstim + 200);
   u16LocalInput = (uint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim,
                                            0,
                                            1000);
   s32LocaltOilInServoThdSou = (sint32)(  ( ( VlvAct_tOilInServoThdLo_C
                                            - VlvAct_tOilInServoThdLoHys_C)
                                          * 4)
                                       + 200);
   u16LocaltOilInServoThdSou =
      (uint16)MATHSRV_udtCLAMP(s32LocaltOilInServoThdSou,
                               0,
                               1020);
   s32LocalVlvActtOilInServoThdLo = (sint32)( (VlvAct_tOilInServoThdLo_C * 4)
                                            +  200);
   u16LocaltOilInServoThd =
      (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtOilInServoThdLo,
                               0,
                               1020);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltOilInServoThdSou,
                                u16LocaltOilInServoThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInServoHyst01);
   u16LocalInput = (uint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
   s16LocaltOilInServoThdSou = (sint16)( ( VlvAct_uBattInServoThdLo_C
                                         - VlvAct_uBattInServoThdLoHys_C)
                                       * 8);
   u16LocaltOilInServoThdSou = (uint16)MATHSRV_udtMAX(s16LocaltOilInServoThdSou,
                                                      0);
   u16LocaltOilInServoThd =(uint16)(8 * VlvAct_uBattInServoThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltOilInServoThdSou,
                                u16LocaltOilInServoThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInServoHyst02);
   u16LocalInput = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng,7500);
   s16LocaltOilInServoThdSou = (sint16)( ( VlvAct_nEngInServoThdLo_C
                                         - VlvAct_nEngInServoThdLoHys_C)
                                       * 32);
   u16LocaltOilInServoThdSou = (uint16)MATHSRV_udtMAX(s16LocaltOilInServoThdSou,
                                                      0);
   u16LocaltOilInServoThd = (uint16)(32 * VlvAct_nEngInServoThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltOilInServoThdSou,
                                u16LocaltOilInServoThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bInServoHyst03);

   if (  (VLVACTINMNG_bInServoHyst01 != 0)
      && (VLVACTINMNG_bInServoHyst02 != 0)
      && (VLVACTINMNG_bInServoHyst03 != 0))
   {
      VEMS_vidSET(VlvAct_bInMngServoStEna, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInMngServoStEna, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidClnStEnaCdn                                 */
/* !Description :  La stratégie de nettoyage de l’électrovanne de commande de */
/*                 l’actionneur de décalage AAC admission n’est activée que   */
/*                 lorsqu’une requête de nettoyage a été émise par la         */
/*                 stratégie dédiée; cette stratégie peut également être      */
/*                 activée manuellement.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bInMngClnStReq;                                      */
/*  input boolean VlvAct_bInMngClnBenchEna_C;                                 */
/*  output boolean VlvAct_bInMngClnStEna;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidClnStEnaCdn(void)
{
   boolean bLocalVlvAct_bInMngClnStReq;


   VEMS_vidGET(VlvAct_bInMngClnStReq, bLocalVlvAct_bInMngClnStReq);
   if (  (bLocalVlvAct_bInMngClnStReq != 0)
      || (VlvAct_bInMngClnBenchEna_C != 0))
   {
      VlvAct_bInMngClnStEna = 1;
   }
   else
   {
      VlvAct_bInMngClnStEna = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidStMng                                       */
/* !Description :  Gestion de la fonction VVT admission                       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Ext_bOilPres;                                               */
/*  input boolean Vcpi_cam_offsets_are_learned;                               */
/*  input boolean CoPTSt_bMainEngStopReq;                                     */
/*  input boolean VlvAct_bInCmdAuth;                                          */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  input boolean VlvAct_bInMngLrnStEna;                                      */
/*  input boolean Srv_bActrTstInVVTEna;                                       */
/*  input boolean VlvAct_bInMngServoStEna;                                    */
/*  input boolean VlvAct_bInFrstClnDone;                                      */
/*  input boolean VlvAct_bInLrnFrstOfsAuth;                                   */
/*  input boolean VlvAct_bInOfsFrstLrnWouDft;                                 */
/*  input st74 VlvAct_InMngSt;                                                */
/*  input boolean VlvAct_bInMngInitStEna;                                     */
/*  input boolean VlvAct_bInMngClnStEna;                                      */
/*  input boolean VlvAct_bInMngUnlckStEna;                                    */
/*  input boolean VlvAct_bInInUnlckStrEndIdc;                                 */
/*  output st74 VlvAct_InMngSt;                                               */
/*  output boolean VlvAct_bInClnEna;                                          */
/*  output boolean VlvAct_bInLrnEna;                                          */
/*  output boolean VlvAct_bInServoEna;                                        */
/*  output boolean VlvAct_bInUnlckEna;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidStMng(void)
{
   boolean bLocalAcvLockPosnInVlv;
   boolean bLocalMoteur_synchronise;
   boolean bLocalClef_de_contact;
   boolean bLocalExt_bOilPres;
   boolean bLocalVcpiLearned;
   boolean bLocalCoPTSt_bMainEngStopReq;
   boolean bLocalVlvAct_bInCmdAuth;
   boolean bLocalVlvAct_bInOfsFrstLrn;
   boolean bLocalVlvAct_bInMngLrnStEna;
   boolean bLocalSrv_bActrTstInVVTEna;
   boolean bLocalVlvAct_bInMngServoStEna;
   boolean bLocalVlvAct_bInFrstClnDone;
   boolean bLocalVlvAct_bInLrnFrstOfsAuth;
   boolean bLocalVlvAct_bInOfsFrstLrnWouDft;


   bLocalAcvLockPosnInVlv = GDGAR_bGetFRM(FRM_FRM_ACVLOCKPOSNINVLV);
   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Ext_bOilPres, bLocalExt_bOilPres);
   VEMS_vidGET(Vcpi_cam_offsets_are_learned, bLocalVcpiLearned);
   VEMS_vidGET(CoPTSt_bMainEngStopReq, bLocalCoPTSt_bMainEngStopReq);
   VEMS_vidGET(VlvAct_bInCmdAuth, bLocalVlvAct_bInCmdAuth);
   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);
   VEMS_vidGET(VlvAct_bInMngLrnStEna, bLocalVlvAct_bInMngLrnStEna);
   VEMS_vidGET(Srv_bActrTstInVVTEna, bLocalSrv_bActrTstInVVTEna);
   VEMS_vidGET(VlvAct_bInMngServoStEna, bLocalVlvAct_bInMngServoStEna);
   VEMS_vidGET(VlvAct_bInFrstClnDone, bLocalVlvAct_bInFrstClnDone);
   VEMS_vidGET(VlvAct_bInLrnFrstOfsAuth, bLocalVlvAct_bInLrnFrstOfsAuth);
   VEMS_vidGET(VlvAct_bInOfsFrstLrnWouDft, bLocalVlvAct_bInOfsFrstLrnWouDft);

   switch (VlvAct_InMngSt)
   {
      /*Warning QAC: The QAC indentation check of a switch-cases bloc is not
      those used by VEMS presenting rules.*/
      case VLVACT_INIT:
         if (bLocalAcvLockPosnInVlv != 0)
         {
            VlvAct_InMngSt = VLVACT_DFT;
         }
         else
         {
            if (  (bLocalMoteur_synchronise != 0)
               && (bLocalClef_de_contact != 0)
               && (bLocalExt_bOilPres != 0)
               && (bLocalCoPTSt_bMainEngStopReq == 0)
               && (VlvAct_bInMngInitStEna == 0)
               && (  (bLocalVlvAct_bInCmdAuth != 0)
                  || (bLocalVlvAct_bInOfsFrstLrn == 0)))
            {
               if (  (VlvAct_bInMngClnStEna != 0)
                  && (bLocalVlvAct_bInOfsFrstLrnWouDft == 0))
               {
                  VlvAct_InMngSt = VLVACT_CLEAN;
                  VEMS_vidSET(VlvAct_bInClnEna, 1);
               }
               else
               {
                  if (  (bLocalVlvAct_bInMngLrnStEna != 0)
                     && (  (  (bLocalVcpiLearned == 0)
                           && (bLocalVlvAct_bInOfsFrstLrn != 0))
                        || (bLocalVlvAct_bInLrnFrstOfsAuth != 0)))
                  {
                     VlvAct_InMngSt = VLVACT_LRN;
                     VEMS_vidSET(VlvAct_bInLrnEna, 1);
                  }
                  else
                  {
                     if (  (bLocalVcpiLearned != 0)
                        && (bLocalVlvAct_bInMngServoStEna != 0)
                        && (bLocalVlvAct_bInOfsFrstLrn != 0))
                     {
                        VlvAct_InMngSt = VLVACT_SERVO;
                        VEMS_vidSET(VlvAct_bInServoEna, 1);
                     }
                  }
               }
            }
         }
         break;

      case VLVACT_LRN:
         if (bLocalAcvLockPosnInVlv != 0)
         {
            VlvAct_InMngSt = VLVACT_DFT;
            VEMS_vidSET(VlvAct_bInLrnEna, 0);
         }
         else
         {
            if (  (bLocalMoteur_synchronise == 0)
               || (bLocalClef_de_contact == 0)
               || (bLocalExt_bOilPres == 0)
               || (VlvAct_bInMngInitStEna != 0)
               || (bLocalCoPTSt_bMainEngStopReq != 0)
               || (bLocalVlvAct_bInMngLrnStEna == 0))
            {
               VEMS_vidSET(VlvAct_bInLrnEna, 0);
               VlvAct_InMngSt = VLVACT_INIT;
            }
            else
            {
               if (  (bLocalVcpiLearned != 0)
                  && (bLocalVlvAct_bInMngServoStEna != 0)
                  && (bLocalVlvAct_bInOfsFrstLrn != 0))
               {
                  VEMS_vidSET(VlvAct_bInLrnEna, 0);
                  VlvAct_InMngSt = VLVACT_SERVO;
                  VEMS_vidSET(VlvAct_bInServoEna, 1);
               }
            }
         }
         break;

      case VLVACT_SERVO:
         if (bLocalAcvLockPosnInVlv != 0)
         {
            VlvAct_InMngSt = VLVACT_DFT;
            VEMS_vidSET(VlvAct_bInServoEna, 0);
         }
         else
         {
            if (  (bLocalMoteur_synchronise == 0)
               || (bLocalClef_de_contact == 0)
               || (bLocalExt_bOilPres == 0)
               || (VlvAct_bInMngInitStEna != 0)
               || (bLocalCoPTSt_bMainEngStopReq != 0)
               || (bLocalVlvAct_bInMngServoStEna == 0))
            {
               VEMS_vidSET(VlvAct_bInServoEna, 0);
               VlvAct_InMngSt = VLVACT_INIT;
            }
            else
            {
               if (  (VlvAct_bInMngClnStEna != 0)
                  && (bLocalSrv_bActrTstInVVTEna == 0))
               {
                  VEMS_vidSET(VlvAct_bInServoEna, 0);
                  VlvAct_InMngSt = VLVACT_CLEAN;
                  VEMS_vidSET(VlvAct_bInClnEna, 1);
               }
               else
               {
                  if (  (bLocalVcpiLearned == 0)
                     && (bLocalVlvAct_bInMngLrnStEna != 0))
                  {
                     VEMS_vidSET(VlvAct_bInServoEna, 0);
                     VlvAct_InMngSt = VLVACT_LRN;
                     VEMS_vidSET(VlvAct_bInLrnEna, 1);
                  }
                  else
                  {
                     if (VlvAct_bInMngUnlckStEna != 0)
                     {
                        VEMS_vidSET(VlvAct_bInServoEna, 0);
                        VlvAct_InMngSt = VLVACT_UNLOCK;
                        VlvAct_bInUnlckEna = 1;
                     }
                  }
               }
            }
         }
         break;

      case VLVACT_CLEAN:
         if (bLocalAcvLockPosnInVlv != 0)
         {
            VlvAct_InMngSt = VLVACT_DFT;
            VEMS_vidSET(VlvAct_bInClnEna, 0);
         }
         else
         {
            if (  (bLocalMoteur_synchronise == 0)
               || (bLocalClef_de_contact == 0)
               || (bLocalExt_bOilPres == 0)
               || (VlvAct_bInMngInitStEna != 0)
               || (bLocalCoPTSt_bMainEngStopReq != 0))
            {
               VEMS_vidSET(VlvAct_bInClnEna, 0);
               VlvAct_InMngSt = VLVACT_INIT;
            }
            else
            {
               if (  (VlvAct_bInMngClnStEna == 0)
                  && (bLocalVlvAct_bInOfsFrstLrnWouDft == 0)
                  && (bLocalVlvAct_bInFrstClnDone != 0))
               {
                  if (  (bLocalVlvAct_bInMngLrnStEna != 0)
                     && (  (  (bLocalVcpiLearned == 0)
                           && (bLocalVlvAct_bInOfsFrstLrn != 0))
                        || (bLocalVlvAct_bInLrnFrstOfsAuth != 0)))
                  {
                     VEMS_vidSET(VlvAct_bInClnEna, 0);
                     VlvAct_InMngSt = VLVACT_LRN;
                     VEMS_vidSET(VlvAct_bInLrnEna, 1);
                  }
                  else
                  {
                     if (  (bLocalVcpiLearned != 0)
                        && (bLocalVlvAct_bInMngServoStEna != 0)
                        && (bLocalVlvAct_bInOfsFrstLrn != 0))
                     {
                        VEMS_vidSET(VlvAct_bInClnEna, 0);
                        VlvAct_InMngSt = VLVACT_SERVO;
                        VEMS_vidSET(VlvAct_bInServoEna, 1);
                     }
                  }
               }
               else
               {
                  if (  (VlvAct_bInMngClnStEna == 0)
                     && (bLocalVlvAct_bInOfsFrstLrn != 0))
                  {
                     VEMS_vidSET(VlvAct_bInClnEna, 0);
                     VlvAct_InMngSt = VLVACT_SERVO;
                     VEMS_vidSET(VlvAct_bInServoEna, 1);
                  }
               }
            }
         }
         break;

      case VLVACT_DFT:
         if (bLocalAcvLockPosnInVlv == 0)
         {
            VlvAct_InMngSt = VLVACT_INIT;
         }
         break;

      case VLVACT_UNLOCK:
         if (bLocalAcvLockPosnInVlv != 0)
         {
            VlvAct_bInUnlckEna = 0;
            VlvAct_InMngSt = VLVACT_DFT;
         }
         else
         {
            if (  (bLocalMoteur_synchronise == 0)
               || (bLocalClef_de_contact == 0)
               || (bLocalExt_bOilPres == 0)
               || (VlvAct_bInMngInitStEna != 0)
               || (bLocalCoPTSt_bMainEngStopReq != 0))
            {
               VlvAct_bInUnlckEna = 0;
               VlvAct_InMngSt = VLVACT_INIT;
            }
            else
            {
               if (  (  (VlvAct_bInMngUnlckStEna == 0)
                     || (VlvAct_bInInUnlckStrEndIdc != 0))
                  && (bLocalVcpiLearned != 0)
                  && (bLocalVlvAct_bInMngServoStEna != 0)
                  && (bLocalVlvAct_bInOfsFrstLrn != 0))
               {
                  VlvAct_bInUnlckEna = 0;
                  VlvAct_InMngSt = VLVACT_SERVO;
                  VEMS_vidSET(VlvAct_bInServoEna, 1);
               }
            }
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VlvAct_InMngSt = VLVACT_INIT;
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidMngStCmd                                    */
/* !Description :  La commande envoyée au driver de pilotage RCO de           */
/*                 l’électrovanne de commande VVT admission est nulle         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTINMNG_vidEngStopAuth();                            */
/*  input uint16 Consigne_rco_vvt_adm;                                        */
/*  input boolean VlvAct_bInServoEna;                                         */
/*  input uint16 VlvAct_InClnStCmd;                                           */
/*  input boolean VlvAct_bInClnEna;                                           */
/*  input boolean VlvAct_bInUnlckEna;                                         */
/*  input uint16 VlvAct_InUnlckCmd;                                           */
/*  input uint16 VlvAct_InUnlckCmdMin_C;                                      */
/*  input boolean VlvAct_bInLrnEna;                                           */
/*  input boolean VlvAct_bInMngInitStEna;                                     */
/*  input uint8 VlvAct_InTOilMaxValCmd_C;                                     */
/*  input uint8 VlvAct_InLihValCmd_C;                                         */
/*  output uint16 VlvAct_InMngStCmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidMngStCmd(void)
{
   boolean bLocalVlvAct_bInClnEna;
   boolean bLocalVlvAct_bInServoEna;
   boolean bLocalVlvAct_bInLrnEna;
   uint16  u16LocalVlvActInMngStCmd;
   uint16  u16LocalVlvAct_InMngStCmd;
   uint16  u16LocalConsigne_rco_vvt_adm;
   uint16  u16LocalVlvAct_InClnStCmd;


   VEMS_vidGET(Consigne_rco_vvt_adm, u16LocalConsigne_rco_vvt_adm);
   VEMS_vidGET(VlvAct_bInServoEna, bLocalVlvAct_bInServoEna);
   if (bLocalVlvAct_bInServoEna != 0)
   {
      u16LocalVlvActInMngStCmd = u16LocalConsigne_rco_vvt_adm;
   }
   else
   {
      VEMS_vidGET(VlvAct_InClnStCmd, u16LocalVlvAct_InClnStCmd);
      VEMS_vidGET(VlvAct_bInClnEna, bLocalVlvAct_bInClnEna);
      if (bLocalVlvAct_bInClnEna != 0)
      {
         u16LocalVlvActInMngStCmd = u16LocalVlvAct_InClnStCmd;
      }
      else
      {
         if (VlvAct_bInUnlckEna != 0)
         {
            u16LocalVlvActInMngStCmd =
               (uint16)MATHSRV_udtMAX(VlvAct_InUnlckCmd,
                                      VlvAct_InUnlckCmdMin_C);
         }
         else
         {
            VEMS_vidGET(VlvAct_bInLrnEna, bLocalVlvAct_bInLrnEna);
            if (bLocalVlvAct_bInLrnEna != 0)
            {
               u16LocalVlvActInMngStCmd = 0;
            }
            else
            {
               if (VlvAct_bInMngInitStEna != 0)
               {
                  u16LocalVlvActInMngStCmd =
                        (uint16)(4 * VlvAct_InTOilMaxValCmd_C);
               }
               else
               {
                  u16LocalVlvActInMngStCmd =
                        (uint16)(4 * VlvAct_InLihValCmd_C);
               }
            }
         }
      }
   }
   u16LocalVlvAct_InMngStCmd = (uint16)MATHSRV_udtMIN(u16LocalVlvActInMngStCmd,
                                                      1023);
   VEMS_vidSET(VlvAct_InMngStCmd, u16LocalVlvAct_InMngStCmd);
   VLVACTINMNG_vidEngStopAuth();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidTimer2                                      */
/* !Description :  Calcul des sorties Timers 3 et 4                           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_InMngStCmd;                                           */
/*  input boolean CoPTSt_bMainEngStopReq;                                     */
/*  input boolean VLVACTINMNG_bTimer1Input;                                   */
/*  input uint8 VlvAct_InEngStopCmdThd_C;                                     */
/*  input uint8 VlvAct_tiInEngStopDftAuthDly_C;                               */
/*  input uint8 VLVACTINMNG_u8Tempo3;                                         */
/*  input uint16 Vxx_rel_in_vvt_mes;                                          */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 VlvAct_uBattInEngStopAuthDly_T[5];                           */
/*  input uint16 VlvAct_tOilInEngStopAuthDly_T[5];                            */
/*  input uint8 VlvAct_tiInEngStopAuthDly_M[5][5];                            */
/*  input boolean VLVACTINMNG_bTimer2Input;                                   */
/*  input uint8 VlvAct_InEngStopPosnMax_C;                                    */
/*  input uint8 VLVACTINMNG_u8Tempo4;                                         */
/*  output boolean VLVACTINMNG_bTimer1Input;                                  */
/*  output uint8 VLVACTINMNG_u8Tempo3;                                        */
/*  output boolean VLVACTINMNG_bTimeout3;                                     */
/*  output boolean VLVACTINMNG_bTimer2Input;                                  */
/*  output uint8 VLVACTINMNG_u8Tempo4;                                        */
/*  output boolean VLVACTINMNG_bTimeout4;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidTimer2(void)
{
   boolean bLocalTimer1InputPrev;
   boolean bLocalTimer2InputPrev;
   boolean bLocalCoPTSt_bMainEngStopReq;
   uint8   u8LocalInterp2d;
   uint16  u16LocalVlvAct_InMngStCmd;
   uint16  u16LocalVlvAct_InEngStopCmdThd_C;
   uint16  u16LocalVxx_rel_in_vvt_mes;
   uint16  u16Ext_uBattMes;
   uint16  u16LocalEng_tOilEstim;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   sint16  s16Ext_uBattMes;
   sint16  s16LocalEng_tOilEstim;
   sint32  s32LocalEng_tOilEstim;


   VEMS_vidGET(VlvAct_InMngStCmd, u16LocalVlvAct_InMngStCmd);
   VEMS_vidGET(CoPTSt_bMainEngStopReq, bLocalCoPTSt_bMainEngStopReq);
   bLocalTimer1InputPrev = VLVACTINMNG_bTimer1Input;
   u16LocalVlvAct_InEngStopCmdThd_C = (uint16)(4*VlvAct_InEngStopCmdThd_C);
   if (  (u16LocalVlvAct_InMngStCmd < u16LocalVlvAct_InEngStopCmdThd_C)
      && (bLocalCoPTSt_bMainEngStopReq != 0))
   {
      VLVACTINMNG_bTimer1Input = 1;
   }
   else
   {
      VLVACTINMNG_bTimer1Input = 0;
   }
   if (  (VLVACTINMNG_bTimer1Input != 0)
      && (bLocalTimer1InputPrev == 0))
   {
      VLVACTINMNG_u8Tempo3 = VlvAct_tiInEngStopDftAuthDly_C;
      if (VLVACTINMNG_u8Tempo3 == 0)
      {
         VLVACTINMNG_bTimeout3 = 1;
      }
      else
      {
         VLVACTINMNG_bTimeout3 = 0;
      }
   }
   else
   {
      if (VLVACTINMNG_u8Tempo3 > 0)
      {
         VLVACTINMNG_u8Tempo3 = (uint8)(VLVACTINMNG_u8Tempo3 - 1);
         if (VLVACTINMNG_u8Tempo3 == 0)
         {
            VLVACTINMNG_bTimeout3 = 1;
         }
         else
         {
            VLVACTINMNG_bTimeout3 = 0;
         }
      }
   }

   VEMS_vidGET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);
   VEMS_vidGET(Ext_uBattMes, s16Ext_uBattMes);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);

   u16Ext_uBattMes = (uint16)MATHSRV_udtMAX(s16Ext_uBattMes, 0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(VlvAct_uBattInEngStopAuthDly_T,
                                                   u16Ext_uBattMes,
                                                   5);
   s32LocalEng_tOilEstim = s16LocalEng_tOilEstim + 200;
   u16LocalEng_tOilEstim = (uint16)MATHSRV_udtMAX(s32LocalEng_tOilEstim, 0);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(VlvAct_tOilInEngStopAuthDly_T,
                                                   u16LocalEng_tOilEstim,
                                                   5);
   u8LocalInterp2d =
         MATHSRV_u8Interp2d(&VlvAct_tiInEngStopAuthDly_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             5);

   bLocalTimer2InputPrev = VLVACTINMNG_bTimer2Input;

   if (  (u16LocalVxx_rel_in_vvt_mes < VlvAct_InEngStopPosnMax_C)
      && (VLVACTINMNG_bTimer1Input != 0))
   {
      VLVACTINMNG_bTimer2Input = 1;
   }
   else
   {
      VLVACTINMNG_bTimer2Input = 0;
   }

   if (  (VLVACTINMNG_bTimer2Input != 0)
      && (bLocalTimer2InputPrev == 0))
   {
      VLVACTINMNG_u8Tempo4 = u8LocalInterp2d;
      if (VLVACTINMNG_u8Tempo4 == 0)
      {
         VLVACTINMNG_bTimeout4 = 1;
      }
      else
      {
         VLVACTINMNG_bTimeout4 = 0;
      }
   }
   else
   {
      if (VLVACTINMNG_u8Tempo4 > 0)
      {
         VLVACTINMNG_u8Tempo4 = (uint8)(VLVACTINMNG_u8Tempo4 - 1);
         if (VLVACTINMNG_u8Tempo4 == 0)
         {
            VLVACTINMNG_bTimeout4 = 1;
         }
         else
         {
            VLVACTINMNG_bTimeout4 = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidEngStopAuth                                 */
/* !Description :  La LdC VVT admission doit informer à tout moment les autres*/
/*                 fonctions du contrôle moteur si la position du déphaseur   */
/*                 VVT admission permet l’arrêt du moteur                     */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMNG_vidTimer2();                                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VLVACTINMNG_bTimer1Input;                                   */
/*  input boolean VLVACTINMNG_bTimeout3;                                      */
/*  input boolean VLVACTINMNG_bTimer2Input;                                   */
/*  input boolean VLVACTINMNG_bTimeout4;                                      */
/*  output boolean VlvAct_bInEngStopAuth;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidEngStopAuth(void)
{
   boolean bLocalVlvAct_bInEngStopAuth;


   VLVACTINMNG_vidTimer2();
   if (  (  (VLVACTINMNG_bTimer1Input != 0)
         && (VLVACTINMNG_bTimeout3 != 0))
      || (  (VLVACTINMNG_bTimer2Input != 0)
         && (VLVACTINMNG_bTimeout4 != 0)))
   {
      bLocalVlvAct_bInEngStopAuth = 1;
   }
   else
   {
      bLocalVlvAct_bInEngStopAuth = 0;
   }
   VEMS_vidSET(VlvAct_bInEngStopAuth, bLocalVlvAct_bInEngStopAuth);
}
/*------------------------------- end of file --------------------------------*/