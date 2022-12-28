/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXMNG                                             */
/* !Description     : VLVACTEXMNG Component                                   */
/*                                                                            */
/* !Module          : VLVACTEXMNG                                             */
/* !Description     : MANAGER DE LA FONCTION VVT ECHAPPEMENT                  */
/*                                                                            */
/* !File            : VLVACTEXMNG_FCT1.C                                      */
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
/*   1 / VLVACTEXMNG_vidInitOutput                                            */
/*   2 / VLVACTEXMNG_vidInitStEnaCdn                                          */
/*   3 / VLVACTEXMNG_vidTimer1                                                */
/*   4 / VLVACTEXMNG_vidLrnStEnaCdn                                           */
/*   5 / VLVACTEXMNG_vidServoStEnaCdn                                         */
/*   6 / VLVACTEXMNG_vidClnStEnaCdn                                           */
/*   7 / VLVACTEXMNG_vidStMng                                                 */
/*   8 / VLVACTEXMNG_vidMngStCmd                                              */
/*   9 / VLVACTEXMNG_vidTimer2                                                */
/*   10 / VLVACTEXMNG_vidEngStopAuth                                          */
/*                                                                            */
/* !Reference   : V02 NT 08 07819 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#068177                                         */
/* !OtherRefs   : VEMS V02 ECU#068136                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXMNG/VLVACTEXMNG$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Feb 2014 $*/
/* $Author::   etsasson                               $$Date::   17 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXMNG.h"
#include "VLVACTEXMNG_L.h"
#include "VLVACTEXMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidInitOutput                                  */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 VlvAct_ExMngStCmd;                                          */
/*  output boolean VlvAct_bExLrnEna;                                          */
/*  output boolean VlvAct_bExServoEna;                                        */
/*  output boolean VlvAct_bExClnEna;                                          */
/*  output boolean VlvAct_bExEngStopAuth;                                     */
/*  output boolean VlvAct_bExCmdAuth;                                         */
/*  output boolean VlvAct_bExMngLrnStEna;                                     */
/*  output boolean VlvAct_bExMngServoStEna;                                   */
/*  output boolean VLVACTEXMNG_bTimeout1;                                     */
/*  output boolean VLVACTEXMNG_bTimeout2;                                     */
/*  output boolean VLVACTEXMNG_bTimeout3;                                     */
/*  output boolean VLVACTEXMNG_bTimeout4;                                     */
/*  output boolean VLVACTEXMNG_bTimeout5;                                     */
/*  output boolean VLVACTEXMNG_bOilPresPrev;                                  */
/*  output boolean VLVACTEXMNG_bVehicleStatePrev;                             */
/*  output uint8 VLVACTEXMNG_u8VehActStatPrev;                                */
/*  output boolean VLVACTEXMNG_bTimer1Input;                                  */
/*  output boolean VLVACTEXMNG_bTimer2Input;                                  */
/*  output uint8 VLVACTEXMNG_u8Tempo1;                                        */
/*  output uint8 VLVACTEXMNG_u8Tempo2;                                        */
/*  output uint8 VLVACTEXMNG_u8Tempo3;                                        */
/*  output uint8 VLVACTEXMNG_u8Tempo4;                                        */
/*  output uint16 VLVACTEXMNG_u16Tempo5;                                      */
/*  output boolean VlvAct_bExMngInitStEna;                                    */
/*  output boolean VLVACTEXMNG_bExLrnHyst01;                                  */
/*  output boolean VLVACTEXMNG_bExLrnHyst02;                                  */
/*  output boolean VLVACTEXMNG_bExLrnHyst03;                                  */
/*  output boolean VLVACTEXMNG_bExLrnHyst04;                                  */
/*  output boolean VLVACTEXMNG_bExLrnHyst05;                                  */
/*  output boolean VLVACTEXMNG_bExLrnHyst06;                                  */
/*  output boolean VLVACTEXMNG_bExLrnHyst07;                                  */
/*  output boolean VLVACTEXMNG_bExLrnHyst08;                                  */
/*  output boolean VLVACTEXMNG_bExServoHyst01;                                */
/*  output boolean VLVACTEXMNG_bExServoHyst02;                                */
/*  output boolean VLVACTEXMNG_bExServoHyst03;                                */
/*  output uint8 VlvAct_tiExUnlck;                                            */
/*  output uint8 VlvAct_noExUnlckStr;                                         */
/*  output boolean VLVACTEXMNG_bTOilExUnlckThd;                               */
/*  output boolean VLVACTEXMNG_bNEngExUnlckThd;                               */
/*  output boolean VLVACTEXMNG_bAgExAcvUnlckPosnThd;                          */
/*  output boolean VLVACTEXMNG_bAgExAcvSpFuncIntThd;                          */
/*  output st46 VlvAct_ExUnlckStrSt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidInitOutput(void)
{
   VEMS_vidSET(VlvAct_ExMngStCmd, 0);
   VEMS_vidSET(VlvAct_bExLrnEna, 0);
   VEMS_vidSET(VlvAct_bExServoEna, 0);
   VEMS_vidSET(VlvAct_bExClnEna, 0);
   VEMS_vidSET(VlvAct_bExEngStopAuth, 0);
   VEMS_vidSET(VlvAct_bExCmdAuth, 0);
   VEMS_vidSET(VlvAct_bExMngLrnStEna, 0);
   VEMS_vidSET(VlvAct_bExMngServoStEna , 0);

   VLVACTEXMNG_bTimeout1 = 0;
   VLVACTEXMNG_bTimeout2 = 0;
   VLVACTEXMNG_bTimeout3 = 0;
   VLVACTEXMNG_bTimeout4 = 0;
   VLVACTEXMNG_bTimeout5 = 0;
   VLVACTEXMNG_bOilPresPrev = 0;
   VLVACTEXMNG_bVehicleStatePrev = 0;
   VLVACTEXMNG_u8VehActStatPrev = 0;

   VLVACTEXMNG_bTimer1Input = 0;
   VLVACTEXMNG_bTimer2Input = 0;
   VLVACTEXMNG_u8Tempo1 = 0;
   VLVACTEXMNG_u8Tempo2 = 0;
   VLVACTEXMNG_u8Tempo3 = 0;
   VLVACTEXMNG_u8Tempo4 = 0;
   VLVACTEXMNG_u16Tempo5 = 0;

   VlvAct_bExMngInitStEna = 0;

   VLVACTEXMNG_bExLrnHyst01 = 0;
   VLVACTEXMNG_bExLrnHyst02 = 0;
   VLVACTEXMNG_bExLrnHyst03 = 0;
   VLVACTEXMNG_bExLrnHyst04 = 0;
   VLVACTEXMNG_bExLrnHyst05 = 0;
   VLVACTEXMNG_bExLrnHyst06 = 0;
   VLVACTEXMNG_bExLrnHyst07 = 0;
   VLVACTEXMNG_bExLrnHyst08 = 0;

   VLVACTEXMNG_bExServoHyst01 = 0;
   VLVACTEXMNG_bExServoHyst02 = 0;
   VLVACTEXMNG_bExServoHyst03 = 0;
   VlvAct_tiExUnlck = 0;
   VlvAct_noExUnlckStr  = 0;

   VLVACTEXMNG_bTOilExUnlckThd = 0;
   VLVACTEXMNG_bNEngExUnlckThd = 0;
   VLVACTEXMNG_bAgExAcvUnlckPosnThd = 0;
   VLVACTEXMNG_bAgExAcvSpFuncIntThd = 0;

   VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_IDLE;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidInitStEnaCdn                                */
/* !Description :  Quelque soit l’état de l’automate de gestion de la fonction*/
/*                 VVT échappement, le décaleur doit pouvoir revenir à sa     */
/*                 position de repos dés que les conditions de fonctionnement */
/*                 nominal ne sont plus réunies, afin de protéger l’actionneur*/
/*                 de décalage.                                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_002.02                                     */
/*                 VEMS_R_08_07819_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input st23 Vehicle_active_state;                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  input sint16 VlvAct_tOilExInitThdHi_C;                                    */
/*  input sint16 VlvAct_tOilExInitThdHiHys_C;                                 */
/*  input boolean VlvAct_bExMngInitStEna;                                     */
/*  input uint8 VlvAct_tCoExCmdAuthDly_T[5];                                  */
/*  input uint16 VlvAct_tiExCmdAuthDly_M[5];                                  */
/*  input uint8 VLVACTEXMNG_u8VehActStatPrev;                                 */
/*  input uint16 VLVACTEXMNG_u16Tempo5;                                       */
/*  input boolean VLVACTEXMNG_bTimeout5;                                      */
/*  output boolean VlvAct_bExMngInitStEna;                                    */
/*  output uint16 VLVACTEXMNG_u16Tempo5;                                      */
/*  output boolean VLVACTEXMNG_bTimeout5;                                     */
/*  output uint8 VLVACTEXMNG_u8VehActStatPrev;                                */
/*  output boolean VlvAct_bExCmdAuth;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidInitStEnaCdn(void)
{
   boolean bLocalVlvAct_bExOfsFrstLrn;
   uint8   u8LocalVehicle_active_state;
   uint8   u8SiteInterpolation;
   uint16  u16LocalCalcPara;
   uint16  u16LocalInCmdAuthDly;
   sint16  s16LocalEng_tOilEstim;
   sint16  s16LocalExt_tCoMes;
   sint32  s32LocalCalc;
   sint32  s32LocaltOilExInitThdLow;
   sint32  s32LocalVlvActtOilExInitThdHi;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);

   s32LocaltOilExInitThdLow = (sint32)(4 * ( VlvAct_tOilExInitThdHi_C
                                           - VlvAct_tOilExInitThdHiHys_C));

   s32LocalVlvActtOilExInitThdHi = (sint32)(4 * VlvAct_tOilExInitThdHi_C);

   if (VlvAct_bExMngInitStEna == 0)
   {
      if (s16LocalEng_tOilEstim > s32LocalVlvActtOilExInitThdHi)
      {
         VlvAct_bExMngInitStEna = 1;
      }
      else
      {
         VlvAct_bExMngInitStEna = 0;
      }
   }
   else
   {
      if (s16LocalEng_tOilEstim <= s32LocaltOilExInitThdLow)
      {
         VlvAct_bExMngInitStEna = 0;
      }
      else
      {
         VlvAct_bExMngInitStEna = 1;
      }
   }
   s32LocalCalc = (sint32)s16LocalExt_tCoMes + 40;
   u8SiteInterpolation = (uint8)MATHSRV_udtCLAMP(s32LocalCalc, 0, 255);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(VlvAct_tCoExCmdAuthDly_T,
                                                  u8SiteInterpolation,
                                                  5);
   u16LocalInCmdAuthDly = MATHSRV_u16Interp1d(VlvAct_tiExCmdAuthDly_M,
                                              u16LocalCalcPara);

   if (  (u8LocalVehicle_active_state == VS_CRANKING)
      && (VLVACTEXMNG_u8VehActStatPrev == VS_STALL))
   {
      VLVACTEXMNG_u16Tempo5 = (uint16)MATHSRV_udtMIN(u16LocalInCmdAuthDly,
                                                     25600);
      if (VLVACTEXMNG_u16Tempo5 == 0)
      {
         VLVACTEXMNG_bTimeout5 = 1;
      }
      else
      {
         VLVACTEXMNG_bTimeout5 = 0;
      }
   }
   else
   {
      if (VLVACTEXMNG_u16Tempo5 > 0)
      {
         VLVACTEXMNG_u16Tempo5 = (uint16)(VLVACTEXMNG_u16Tempo5 - 1);
         if (VLVACTEXMNG_u16Tempo5 == 0)
         {
            VLVACTEXMNG_bTimeout5 = 1;
         }
         else
         {
            VLVACTEXMNG_bTimeout5 = 0;
         }
      }
   }
   VLVACTEXMNG_u8VehActStatPrev = u8LocalVehicle_active_state;

   if (  (bLocalVlvAct_bExOfsFrstLrn != 0)
      && (VLVACTEXMNG_bTimeout5 != 0))
   {
      VEMS_vidSET(VlvAct_bExCmdAuth, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExCmdAuth, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidTimer1                                      */
/* !Description :  Calcul des sorties des Timers 1 et 2                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bOilPres;                                               */
/*  input boolean VLVACTEXMNG_bOilPresPrev;                                   */
/*  input uint8 VlvAct_tiExLrnOilPresDly_C;                                   */
/*  input uint8 VLVACTEXMNG_u8Tempo1;                                         */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean VLVACTEXMNG_bVehicleStatePrev;                              */
/*  input uint8 VlvAct_tiExLrnEngRunDly_C;                                    */
/*  input uint8 VLVACTEXMNG_u8Tempo2;                                         */
/*  output uint8 VLVACTEXMNG_u8Tempo1;                                        */
/*  output boolean VLVACTEXMNG_bTimeout1;                                     */
/*  output uint8 VLVACTEXMNG_u8Tempo2;                                        */
/*  output boolean VLVACTEXMNG_bTimeout2;                                     */
/*  output boolean VLVACTEXMNG_bOilPresPrev;                                  */
/*  output boolean VLVACTEXMNG_bVehicleStatePrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidTimer1(void)
{
   boolean bLocalExt_bOilPres;
   boolean bLocalVehicle_active_state;
   uint8   u8LocalVehicle_active_state;


   VEMS_vidGET(Ext_bOilPres, bLocalExt_bOilPres);
   if (  (VLVACTEXMNG_bOilPresPrev == 0)
      && (bLocalExt_bOilPres != 0))
   {
      VLVACTEXMNG_u8Tempo1 = VlvAct_tiExLrnOilPresDly_C;
      if (VLVACTEXMNG_u8Tempo1 == 0)
      {
         VLVACTEXMNG_bTimeout1 = 1;
      }
      else
      {
         VLVACTEXMNG_bTimeout1 = 0;
      }
   }
   else
   {
      if (VLVACTEXMNG_u8Tempo1 > 0)
      {
         VLVACTEXMNG_u8Tempo1 = (uint8)(VLVACTEXMNG_u8Tempo1 - 1);
         if (VLVACTEXMNG_u8Tempo1 == 0)
         {
            VLVACTEXMNG_bTimeout1 = 1;
         }
         else
         {
            VLVACTEXMNG_bTimeout1 = 0;
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
   if (  (VLVACTEXMNG_bVehicleStatePrev == 0)
      && (bLocalVehicle_active_state != 0))
   {
      VLVACTEXMNG_u8Tempo2 = VlvAct_tiExLrnEngRunDly_C;
      if (VLVACTEXMNG_u8Tempo2 == 0)
      {
         VLVACTEXMNG_bTimeout2 = 1;
      }
      else
      {
         VLVACTEXMNG_bTimeout2 = 0;
      }
   }
   else
   {
      if (VLVACTEXMNG_u8Tempo2 > 0)
      {
         VLVACTEXMNG_u8Tempo2 = (uint8)(VLVACTEXMNG_u8Tempo2 - 1);
         if (VLVACTEXMNG_u8Tempo2 == 0)
         {
            VLVACTEXMNG_bTimeout2 = 1;
         }
         else
         {
            VLVACTEXMNG_bTimeout2 = 0;
         }
      }
   }
   VLVACTEXMNG_bOilPresPrev = bLocalExt_bOilPres;
   VLVACTEXMNG_bVehicleStatePrev = bLocalVehicle_active_state;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidLrnStEnaCdn                                 */
/* !Description :  L’apprentissage de la butée basse de l’actionneur de       */
/*                 décalage AAC échappement n’est autorisé que lorsque toutes */
/*                 les conditions adéquates de fonctionnement moteur sont     */
/*                 réunies                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXMNG_vidTimer1();                                 */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 VlvAct_tCoExLrnThdLo_C;                                      */
/*  input sint16 VlvAct_tCoExLrnThdLoHys_C;                                   */
/*  input boolean VLVACTEXMNG_bExLrnHyst01;                                   */
/*  input sint16 VlvAct_tCoExLrnThdHi_C;                                      */
/*  input sint16 VlvAct_tCoExLrnThdHiHys_C;                                   */
/*  input boolean VLVACTEXMNG_bExLrnHyst02;                                   */
/*  input sint16 VlvAct_tOilExLrnThdLo_C;                                     */
/*  input sint16 VlvAct_tOilExLrnThdLoHys_C;                                  */
/*  input boolean VLVACTEXMNG_bExLrnHyst03;                                   */
/*  input sint16 VlvAct_tOilExLrnThdHi_C;                                     */
/*  input sint16 VlvAct_tOilExLrnThdHiHys_C;                                  */
/*  input boolean VLVACTEXMNG_bExLrnHyst04;                                   */
/*  input uint8 VlvAct_nEngExLrnThdLo_C;                                      */
/*  input uint8 VlvAct_nEngExLrnThdLoHys_C;                                   */
/*  input boolean VLVACTEXMNG_bExLrnHyst05;                                   */
/*  input uint8 VlvAct_nEngExLrnThdHi_C;                                      */
/*  input uint8 VlvAct_nEngExLrnThdHiHys_C;                                   */
/*  input boolean VLVACTEXMNG_bExLrnHyst06;                                   */
/*  input uint8 VlvAct_uBattExLrnThdLo_C;                                     */
/*  input uint8 VlvAct_uBattExLrnThdLoHys_C;                                  */
/*  input boolean VLVACTEXMNG_bExLrnHyst07;                                   */
/*  input uint8 VlvAct_uBattExLrnThdHi_C;                                     */
/*  input uint8 VlvAct_uBattExLrnThdHiHys_C;                                  */
/*  input boolean VLVACTEXMNG_bExLrnHyst08;                                   */
/*  input boolean VLVACTEXMNG_bTimeout1;                                      */
/*  input boolean VLVACTEXMNG_bTimeout2;                                      */
/*  output boolean VlvAct_bExMngLrnStEna;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidLrnStEnaCdn(void)
{
   boolean bLocalExhVlvActInLrn;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalInput;
   uint16  u16LocaltCoExLrnThd;
   uint16  u16LocaltCoExLrnThdSom;
   uint16  u16LocaltCoExLrnThdSou;
   uint16  u16LocalSom;
   sint16  s16LocalEng_tOilEstim;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocaltCoExLrnThdSou;
   sint16  s16LocalSou;
   sint16  s16LocalExt_uBattMes;
   sint32  s32LocaltCoExLrnThdSom;
   sint32  s32LocaltCoExLrnThdSou;
   sint32  s32LocalExt_tCoMes;
   sint32  s32LocalVlvActtCoExLrnThdLo;
   sint32  s32LocalVlvActtCoExLrnThdHi;
   sint32  s32LocalVlvActtOilExLrnThdLo;
   sint32  s32LocalVlvActtOilExLrnThdHi;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u16LocalInput = (uint16)MATHSRV_udtCLAMP(s32LocalExt_tCoMes,
                                            0,
                                            254);
   s32LocaltCoExLrnThdSou = (sint32)( ( VlvAct_tCoExLrnThdLo_C
                                      - VlvAct_tCoExLrnThdLoHys_C)
                                    + 40);
   u16LocaltCoExLrnThdSou = (uint16)MATHSRV_udtCLAMP(s32LocaltCoExLrnThdSou,
                                                     0,
                                                     255);
   s32LocalVlvActtCoExLrnThdLo = (sint32)(VlvAct_tCoExLrnThdLo_C + 40);
   u16LocaltCoExLrnThd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtCoExLrnThdLo,
                                                  0,
                                                  255);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoExLrnThdSou,
                                u16LocaltCoExLrnThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExLrnHyst01);

   s32LocalVlvActtCoExLrnThdHi = (sint32)(VlvAct_tCoExLrnThdHi_C + 40);
   u16LocaltCoExLrnThd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtCoExLrnThdHi,
                                                  0,
                                                  255);
   s32LocaltCoExLrnThdSom =(sint32)( VlvAct_tCoExLrnThdHi_C
                                   + VlvAct_tCoExLrnThdHiHys_C
                                   + 40);
   u16LocaltCoExLrnThdSom = (uint16)MATHSRV_udtCLAMP(s32LocaltCoExLrnThdSom,
                                                     0,
                                                     255);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoExLrnThd,
                                u16LocaltCoExLrnThdSom,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExLrnHyst02);

   u16LocalInput = (uint16)MATHSRV_udtCLAMP((s16LocalEng_tOilEstim + 200),
                                            0,
                                            1000);
   s32LocaltCoExLrnThdSou = (sint32)( ( ( VlvAct_tOilExLrnThdLo_C
                                        - VlvAct_tOilExLrnThdLoHys_C) * 4)
                                    + 200);
   u16LocaltCoExLrnThdSou = (uint16)MATHSRV_udtCLAMP(s32LocaltCoExLrnThdSou,
                                                     0,
                                                     1020);
   s32LocalVlvActtOilExLrnThdLo = (sint32)( (VlvAct_tOilExLrnThdLo_C * 4)
                                          + 200);
   u16LocaltCoExLrnThd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtOilExLrnThdLo,
                                                  0,
                                                  1020);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoExLrnThdSou,
                                u16LocaltCoExLrnThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExLrnHyst03);

   s32LocalVlvActtOilExLrnThdHi = (sint32)( (VlvAct_tOilExLrnThdHi_C * 4)
                                          + 200);
   u16LocaltCoExLrnThd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtOilExLrnThdHi ,
                                                  0,
                                                  1020);
   s32LocaltCoExLrnThdSom = (sint32)( (( VlvAct_tOilExLrnThdHi_C
                                       + VlvAct_tOilExLrnThdHiHys_C) * 4)
                                    +  200);
   u16LocaltCoExLrnThdSom = (uint16)MATHSRV_udtCLAMP(s32LocaltCoExLrnThdSom,
                                                     0,
                                                     1020);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoExLrnThd,
                                u16LocaltCoExLrnThdSom,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExLrnHyst04);

   u16LocalInput = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 7500);
   s16LocalSou = (sint16)( ( VlvAct_nEngExLrnThdLo_C
                           - VlvAct_nEngExLrnThdLoHys_C)
                         * 32);
   u16LocaltCoExLrnThdSou = (uint16)MATHSRV_udtMAX(s16LocalSou, 0);
   u16LocaltCoExLrnThd = (uint16)(32 * VlvAct_nEngExLrnThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoExLrnThdSou,
                                u16LocaltCoExLrnThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExLrnHyst05);

   u16LocalSom = (uint16)( ( VlvAct_nEngExLrnThdHi_C
                           + VlvAct_nEngExLrnThdHiHys_C)
                         * 32);
   u16LocaltCoExLrnThdSom =(uint16)MATHSRV_udtMIN(u16LocalSom, 8160);
   u16LocaltCoExLrnThd = (uint16)(32 * VlvAct_nEngExLrnThdHi_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoExLrnThd,
                                u16LocaltCoExLrnThdSom,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExLrnHyst06);

   u16LocalInput = (uint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
   s16LocaltCoExLrnThdSou = (sint16)( ( VlvAct_uBattExLrnThdLo_C
                                      - VlvAct_uBattExLrnThdLoHys_C)
                                    * 8);
   u16LocaltCoExLrnThdSou = (uint16)MATHSRV_udtMAX(s16LocaltCoExLrnThdSou, 0);
   u16LocaltCoExLrnThd = (uint16)(8 * VlvAct_uBattExLrnThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoExLrnThdSou,
                                u16LocaltCoExLrnThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExLrnHyst07);

   u16LocaltCoExLrnThdSom =(uint16)( ( VlvAct_uBattExLrnThdHi_C
                                     + VlvAct_uBattExLrnThdHiHys_C)
                                   * 8);
   u16LocaltCoExLrnThd = (uint16)(8 * VlvAct_uBattExLrnThdHi_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltCoExLrnThd,
                                u16LocaltCoExLrnThdSom,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExLrnHyst08);

   VLVACTEXMNG_vidTimer1();
   bLocalExhVlvActInLrn = GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXLRN);
   if (  (  (VLVACTEXMNG_bExLrnHyst01 != 0)
         && (VLVACTEXMNG_bExLrnHyst02 != 0))
      && (  (VLVACTEXMNG_bExLrnHyst03 != 0)
         && (VLVACTEXMNG_bExLrnHyst04 != 0))
      && (  (VLVACTEXMNG_bExLrnHyst05 != 0)
         && (VLVACTEXMNG_bExLrnHyst06 != 0))
      && (  (VLVACTEXMNG_bExLrnHyst07 != 0)
         && (VLVACTEXMNG_bExLrnHyst08 != 0))
      && (bLocalExhVlvActInLrn == 0)
      && (  (VLVACTEXMNG_bTimeout1 != 0)
         || (VLVACTEXMNG_bTimeout2 != 0)))
   {
      VEMS_vidSET(VlvAct_bExMngLrnStEna, 1);

   }
   else
   {
      VEMS_vidSET(VlvAct_bExMngLrnStEna, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidServoStEnaCdn                               */
/* !Description :  Le pilotage en boucle fermé de l’actionneur de décalage AAC*/
/*                 échappement n’est autorisé que lorsque toutes les          */
/*                 conditions adéquates de fonctionnement moteur sont réunies */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 VlvAct_tOilExServoThdLo_C;                                   */
/*  input sint16 VlvAct_tOilExServoThdLoHys_C;                                */
/*  input boolean VLVACTEXMNG_bExServoHyst01;                                 */
/*  input uint8 VlvAct_uBattExServoThdLo_C;                                   */
/*  input uint8 VlvAct_uBattExServoThdLoHys_C;                                */
/*  input boolean VLVACTEXMNG_bExServoHyst02;                                 */
/*  input uint8 VlvAct_nEngExServoThdLo_C;                                    */
/*  input uint8 VlvAct_nEngExServoThdLoHys_C;                                 */
/*  input boolean VLVACTEXMNG_bExServoHyst03;                                 */
/*  output boolean VlvAct_bExMngServoStEna;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidServoStEnaCdn(void)
{
   uint16 u16LocalExt_nEng;
   uint16 u16LocalInput;
   uint16 u16LocaltOilExServoThd;
   uint16 u16LocaltOilExServoThdSou;
   sint16 s16LocalEng_tOilEstim;
   sint16 s16LocaltOilExServoThdSou;
   sint16 s16LocalExt_uBattMes;
   sint32 s32LocaltOilExServoThdSou;
   sint32 s32LocalEng_tOilEstim;
   sint32 s32LocalVlvActtOilExServoThdLo;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   s32LocalEng_tOilEstim = (sint32)(s16LocalEng_tOilEstim + 200);
   u16LocalInput = (uint16)MATHSRV_udtCLAMP(s32LocalEng_tOilEstim,
                                            0,
                                            1000);
   s32LocaltOilExServoThdSou = (sint32)(  ( ( VlvAct_tOilExServoThdLo_C
                                            - VlvAct_tOilExServoThdLoHys_C)
                                          * 4)
                                       + 200);
   u16LocaltOilExServoThdSou =
      (uint16)MATHSRV_udtCLAMP(s32LocaltOilExServoThdSou,
                               0,
                               1020);
   s32LocalVlvActtOilExServoThdLo = (sint32)( (VlvAct_tOilExServoThdLo_C * 4)
                                            + 200);
   u16LocaltOilExServoThd =
      (uint16)MATHSRV_udtCLAMP(s32LocalVlvActtOilExServoThdLo,
                               0,
                               1020);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltOilExServoThdSou,
                                u16LocaltOilExServoThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExServoHyst01);
   u16LocalInput = (uint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
   s16LocaltOilExServoThdSou = (sint16)( ( VlvAct_uBattExServoThdLo_C
                                         - VlvAct_uBattExServoThdLoHys_C)
                                       * 8);
   u16LocaltOilExServoThdSou = (uint16)MATHSRV_udtMAX(s16LocaltOilExServoThdSou,
                                                      0);
   u16LocaltOilExServoThd = (uint16)(8 * VlvAct_uBattExServoThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltOilExServoThdSou,
                                u16LocaltOilExServoThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExServoHyst02);
   u16LocalInput = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng,7500);
   s16LocaltOilExServoThdSou = (sint16)( ( VlvAct_nEngExServoThdLo_C
                                         - VlvAct_nEngExServoThdLoHys_C)
                                       * 32);
   u16LocaltOilExServoThdSou = (uint16)MATHSRV_udtMAX(s16LocaltOilExServoThdSou,
                                                      0);
   u16LocaltOilExServoThd = (uint16)(32 * VlvAct_nEngExServoThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalInput,
                                u16LocaltOilExServoThdSou,
                                u16LocaltOilExServoThd,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bExServoHyst03);

   if (  (VLVACTEXMNG_bExServoHyst01 != 0)
      && (VLVACTEXMNG_bExServoHyst02 != 0)
      && (VLVACTEXMNG_bExServoHyst03 != 0))
   {
      VEMS_vidSET(VlvAct_bExMngServoStEna , 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExMngServoStEna , 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidClnStEnaCdn                                 */
/* !Description :  La stratégie de nettoyage de l’électrovanne de commande de */
/*                 l’actionneur de décalage AAC échappement n’est activée que */
/*                 lorsqu’une requête de nettoyage a été émise par la         */
/*                 stratégie dédiée; cette stratégie peut également être      */
/*                 activée manuellement.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bExMngClnStReq;                                      */
/*  input boolean VlvAct_bExMngClnBenchEna_C;                                 */
/*  output boolean VlvAct_bExMngClnStEna;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidClnStEnaCdn(void)
{
   boolean bLocalVlvAct_bExMngClnStReq;


   VEMS_vidGET(VlvAct_bExMngClnStReq, bLocalVlvAct_bExMngClnStReq);
   if (  (bLocalVlvAct_bExMngClnStReq != 0)
      || (VlvAct_bExMngClnBenchEna_C != 0))
   {
      VlvAct_bExMngClnStEna = 1;
   }
   else
   {
      VlvAct_bExMngClnStEna = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidStMng                                       */
/* !Description :  Gestion de la fonction VVT échappement                     */
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
/*  input boolean Vcpe_cam_offsets_are_learned;                               */
/*  input boolean CoPTSt_bMainEngStopReq;                                     */
/*  input boolean VlvAct_bExCmdAuth;                                          */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  input boolean VlvAct_bExMngLrnStEna;                                      */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input boolean VlvAct_bExMngServoStEna;                                    */
/*  input boolean VlvAct_bExFrstClnDone;                                      */
/*  input boolean VlvAct_bExLrnFrstOfsAuth;                                   */
/*  input boolean VlvAct_bExOfsFrstLrnWouDft;                                 */
/*  input st76 VlvAct_ExMngSt;                                                */
/*  input boolean VlvAct_bExMngInitStEna;                                     */
/*  input boolean VlvAct_bExMngClnStEna;                                      */
/*  input boolean VlvAct_bExMngUnlckStEna;                                    */
/*  input boolean VlvAct_bExUnlckStrEndIdc;                                   */
/*  output st76 VlvAct_ExMngSt;                                               */
/*  output boolean VlvAct_bExClnEna;                                          */
/*  output boolean VlvAct_bExLrnEna;                                          */
/*  output boolean VlvAct_bExServoEna;                                        */
/*  output boolean VlvAct_bExUnlckEna;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidStMng(void)
{
   boolean bLocalAcvLockPosnExVlv;
   boolean bLocalMoteur_synchronise;
   boolean bLocalClef_de_contact;
   boolean bLocalExt_bOilPres;
   boolean bLocalVcpeLearned;
   boolean bLocalCoPTSt_bMainEngStopReq;
   boolean bLocalVlvAct_bExCmdAuth;
   boolean bLocalVlvAct_bExOfsFrstLrn;
   boolean bLocalVlvAct_bExMngLrnStEna;
   boolean bLocalSrv_bActrTstExVVTEna;
   boolean bLocalVlvAct_bExMngServoStEna;
   boolean bLocalVlvAct_bExFrstClnDone;
   boolean bLocalVlvAct_bExLrnFrstOfsAuth;
   boolean bLocalVlvAct_bExOfsFrstLrnWouDft;


   bLocalAcvLockPosnExVlv = GDGAR_bGetFRM(FRM_FRM_ACVLOCKPOSNEXVLV);
   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Ext_bOilPres, bLocalExt_bOilPres);
   VEMS_vidGET(Vcpe_cam_offsets_are_learned, bLocalVcpeLearned);
   VEMS_vidGET(CoPTSt_bMainEngStopReq, bLocalCoPTSt_bMainEngStopReq);
   VEMS_vidGET(VlvAct_bExCmdAuth, bLocalVlvAct_bExCmdAuth);
   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);
   VEMS_vidGET(VlvAct_bExMngLrnStEna, bLocalVlvAct_bExMngLrnStEna);
   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);
   VEMS_vidGET(VlvAct_bExMngServoStEna, bLocalVlvAct_bExMngServoStEna);
   VEMS_vidGET(VlvAct_bExFrstClnDone, bLocalVlvAct_bExFrstClnDone);
   VEMS_vidGET(VlvAct_bExLrnFrstOfsAuth, bLocalVlvAct_bExLrnFrstOfsAuth);
   VEMS_vidGET(VlvAct_bExOfsFrstLrnWouDft, bLocalVlvAct_bExOfsFrstLrnWouDft);


   switch (VlvAct_ExMngSt)
   {
      /*Warning QAC: The QAC indentation check of a switch-cases bloc is not
      those used by VEMS presenting rules.*/
      case VLVACTEXMNG_INIT:
         if (bLocalAcvLockPosnExVlv != 0)
         {
            VlvAct_ExMngSt = VLVACTEXMNG_DFT;
         }
         else
         {
            if (  (bLocalMoteur_synchronise != 0)
               && (bLocalClef_de_contact != 0)
               && (bLocalExt_bOilPres != 0)
               && (bLocalCoPTSt_bMainEngStopReq == 0)
               && (VlvAct_bExMngInitStEna == 0)
               && (  (bLocalVlvAct_bExCmdAuth != 0)
                  || (bLocalVlvAct_bExOfsFrstLrn == 0)))
            {
               if (  (VlvAct_bExMngClnStEna != 0)
                  && (bLocalVlvAct_bExOfsFrstLrnWouDft == 0))
               {
                  VlvAct_ExMngSt = VLVACTEXMNG_CLEAN;
                  VEMS_vidSET(VlvAct_bExClnEna, 1);
               }
               else
               {
                  if (  (bLocalVlvAct_bExMngLrnStEna != 0)
                     && (  (  (bLocalVcpeLearned == 0)
                           && (bLocalVlvAct_bExOfsFrstLrn != 0))
                        || (bLocalVlvAct_bExLrnFrstOfsAuth != 0)))
                  {
                     VlvAct_ExMngSt = VLVACTEXMNG_LRN;
                     VEMS_vidSET(VlvAct_bExLrnEna, 1);
                  }
                  else
                  {
                     if (  (bLocalVcpeLearned != 0)
                        && (bLocalVlvAct_bExMngServoStEna != 0)
                        && (bLocalVlvAct_bExOfsFrstLrn != 0))
                     {
                        VlvAct_ExMngSt = VLVACTEXMNG_SERVO;
                        VEMS_vidSET(VlvAct_bExServoEna, 1);
                     }
                  }
               }
            }
         }
         break;

      case VLVACTEXMNG_LRN:
         if (bLocalAcvLockPosnExVlv != 0)
         {
            VlvAct_ExMngSt = VLVACTEXMNG_DFT;
            VEMS_vidSET(VlvAct_bExLrnEna, 0);
         }
         else
         {
            if (  (bLocalMoteur_synchronise == 0)
               || (bLocalClef_de_contact == 0)
               || (bLocalExt_bOilPres == 0)
               || (VlvAct_bExMngInitStEna != 0)
               || (bLocalCoPTSt_bMainEngStopReq != 0)
               || (bLocalVlvAct_bExMngLrnStEna == 0))
            {
               VEMS_vidSET(VlvAct_bExLrnEna, 0);
               VlvAct_ExMngSt = VLVACTEXMNG_INIT;
            }
            else
            {
               if (  (bLocalVcpeLearned != 0)
                  && (bLocalVlvAct_bExMngServoStEna != 0)
                  && (bLocalVlvAct_bExOfsFrstLrn != 0))
               {
                  VEMS_vidSET(VlvAct_bExLrnEna, 0);
                  VlvAct_ExMngSt = VLVACTEXMNG_SERVO;
                  VEMS_vidSET(VlvAct_bExServoEna, 1);
               }
            }
         }
         break;

      case VLVACTEXMNG_SERVO:
         if (bLocalAcvLockPosnExVlv != 0)
         {
            VlvAct_ExMngSt = VLVACTEXMNG_DFT;
            VEMS_vidSET(VlvAct_bExServoEna, 0);
         }
         else
         {
            if (  (bLocalMoteur_synchronise == 0)
               || (bLocalClef_de_contact == 0)
               || (bLocalExt_bOilPres == 0)
               || (VlvAct_bExMngInitStEna != 0)
               || (bLocalCoPTSt_bMainEngStopReq != 0)
               || (bLocalVlvAct_bExMngServoStEna == 0))
            {
               VEMS_vidSET(VlvAct_bExServoEna, 0);
               VlvAct_ExMngSt = VLVACTEXMNG_INIT;
            }
            else
            {
               if (  (VlvAct_bExMngClnStEna != 0)
                  && (bLocalSrv_bActrTstExVVTEna == 0))
               {
                  VEMS_vidSET(VlvAct_bExServoEna, 0);
                  VlvAct_ExMngSt = VLVACTEXMNG_CLEAN;
                  VEMS_vidSET(VlvAct_bExClnEna, 1);
               }
               else
               {
                  if (  (bLocalVcpeLearned == 0)
                     && (bLocalVlvAct_bExMngLrnStEna != 0))
                  {
                     VEMS_vidSET(VlvAct_bExServoEna, 0);
                     VlvAct_ExMngSt = VLVACTEXMNG_LRN;
                     VEMS_vidSET(VlvAct_bExLrnEna, 1);
                  }
                  else
                  {
                     if (VlvAct_bExMngUnlckStEna != 0)
                     {
                        VEMS_vidSET(VlvAct_bExServoEna, 0);
                        VlvAct_ExMngSt = VLVACTEXMNG_UNLOCK;
                        VlvAct_bExUnlckEna = 1;
                     }
                  }
               }
            }
         }
         break;

      case VLVACTEXMNG_CLEAN:
         if (bLocalAcvLockPosnExVlv != 0)
         {
            VlvAct_ExMngSt = VLVACTEXMNG_DFT;
            VEMS_vidSET(VlvAct_bExClnEna, 0);
         }
         else
         {
            if (  (bLocalMoteur_synchronise == 0)
               || (bLocalClef_de_contact == 0)
               || (bLocalExt_bOilPres == 0)
               || (VlvAct_bExMngInitStEna != 0)
               || (bLocalCoPTSt_bMainEngStopReq != 0))
            {
               VEMS_vidSET(VlvAct_bExClnEna, 0);
               VlvAct_ExMngSt = VLVACTEXMNG_INIT;
            }
            else
            {
               if (  (VlvAct_bExMngClnStEna == 0)
                  && (bLocalVlvAct_bExOfsFrstLrnWouDft == 0)
                  && (bLocalVlvAct_bExFrstClnDone != 0))
               {
                  if (  (bLocalVlvAct_bExMngLrnStEna != 0)
                     && (  (  (bLocalVcpeLearned == 0)
                           && (bLocalVlvAct_bExOfsFrstLrn != 0))
                        || (bLocalVlvAct_bExLrnFrstOfsAuth != 0)))
                  {
                     VEMS_vidSET(VlvAct_bExClnEna, 0);
                     VlvAct_ExMngSt = VLVACTEXMNG_LRN;
                     VEMS_vidSET(VlvAct_bExLrnEna, 1);
                  }
                  else
                  {
                     if (  (bLocalVcpeLearned != 0)
                        && (bLocalVlvAct_bExMngServoStEna != 0)
                        && (bLocalVlvAct_bExOfsFrstLrn != 0))
                     {
                        VEMS_vidSET(VlvAct_bExClnEna, 0);
                        VlvAct_ExMngSt = VLVACTEXMNG_SERVO;
                        VEMS_vidSET(VlvAct_bExServoEna, 1);
                     }
                  }
               }
               else
               {
                  if (  (VlvAct_bExMngClnStEna == 0)
                     && (bLocalVlvAct_bExOfsFrstLrn != 0))
                  {
                     VEMS_vidSET(VlvAct_bExClnEna, 0);
                     VlvAct_ExMngSt = VLVACTEXMNG_SERVO;
                     VEMS_vidSET(VlvAct_bExServoEna, 1);
                  }
               }
            }
         }
         break;

      case VLVACTEXMNG_DFT:
         if (bLocalAcvLockPosnExVlv == 0)
         {
            VlvAct_ExMngSt = VLVACTEXMNG_INIT;
         }
         break;

      case VLVACTEXMNG_UNLOCK:
         if (bLocalAcvLockPosnExVlv != 0)
         {
            VlvAct_bExUnlckEna = 0;
            VlvAct_ExMngSt = VLVACTEXMNG_DFT;
         }
         else
         {
            if (  (bLocalMoteur_synchronise == 0)
               || (bLocalClef_de_contact == 0)
               || (bLocalExt_bOilPres == 0)
               || (VlvAct_bExMngInitStEna != 0)
               || (bLocalCoPTSt_bMainEngStopReq != 0))
            {
               VlvAct_bExUnlckEna = 0;
               VlvAct_ExMngSt = VLVACTEXMNG_INIT;
            }
            else
            {
               if (  (  (VlvAct_bExMngUnlckStEna == 0)
                     || (VlvAct_bExUnlckStrEndIdc != 0))
                  && (bLocalVcpeLearned != 0)
                  && (bLocalVlvAct_bExMngServoStEna != 0)
                  && (bLocalVlvAct_bExOfsFrstLrn != 0))
               {
                  VlvAct_bExUnlckEna = 0;
                  VlvAct_ExMngSt = VLVACTEXMNG_SERVO;
                  VEMS_vidSET(VlvAct_bExServoEna, 1);
               }
            }
         }
         break;
      default:
         SWFAIL_vidSoftwareErrorHook();
         VlvAct_ExMngSt = VLVACTEXMNG_INIT;
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidMngStCmd                                    */
/* !Description :  La commande envoyée au driver de pilotage RCO de           */
/*                 l’électrovanne de commande VVT échappement est nulle       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTEXMNG_vidEngStopAuth();                            */
/*  input uint16 Consigne_rco_vvt_echap;                                      */
/*  input boolean VlvAct_bExServoEna;                                         */
/*  input uint16 VlvAct_ExClnStCmd;                                           */
/*  input boolean VlvAct_bExClnEna;                                           */
/*  input boolean VlvAct_bExUnlckEna;                                         */
/*  input uint16 VlvAct_ExUnlckCmd;                                           */
/*  input uint16 VlvAct_ExUnlckCmdMin_C;                                      */
/*  input boolean VlvAct_bExLrnEna;                                           */
/*  input boolean VlvAct_bExMngInitStEna;                                     */
/*  input uint16 VlvAct_ExTOilMaxValCmd_C;                                    */
/*  input uint16 VlvAct_ExLihValCmd_C;                                        */
/*  output uint16 VlvAct_ExMngStCmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidMngStCmd(void)
{
   boolean bLocalVlvAct_bExClnEna;
   boolean bLocalVlvAct_bExServoEna;
   boolean bLocalVlvAct_bExLrnEna;
   uint16  u16LocalVlvActExMngStCmd;
   uint16  u16LocalVlvAct_ExMngStCmd;
   uint16  u16LocalConsigne_rco_vvt_echap;
   uint16  u16LocalVlvAct_ExClnStCmd;


   VEMS_vidGET(Consigne_rco_vvt_echap, u16LocalConsigne_rco_vvt_echap);
   VEMS_vidGET(VlvAct_bExServoEna, bLocalVlvAct_bExServoEna);
   if (bLocalVlvAct_bExServoEna != 0)
   {
      u16LocalVlvActExMngStCmd = u16LocalConsigne_rco_vvt_echap;
   }
   else
   {
      VEMS_vidGET(VlvAct_ExClnStCmd, u16LocalVlvAct_ExClnStCmd);
      VEMS_vidGET(VlvAct_bExClnEna, bLocalVlvAct_bExClnEna);
      if (bLocalVlvAct_bExClnEna != 0)
      {
         u16LocalVlvActExMngStCmd = u16LocalVlvAct_ExClnStCmd;
      }
      else
      {
         if (VlvAct_bExUnlckEna != 0)
         {
            u16LocalVlvActExMngStCmd =
               (uint16)MATHSRV_udtMAX(VlvAct_ExUnlckCmd,
                                      VlvAct_ExUnlckCmdMin_C);
         }
         else
         {
            VEMS_vidGET(VlvAct_bExLrnEna, bLocalVlvAct_bExLrnEna);
            if (bLocalVlvAct_bExLrnEna != 0)
            {
               u16LocalVlvActExMngStCmd = 0;
            }
            else
            {
               if (VlvAct_bExMngInitStEna != 0)
               {
                  u16LocalVlvActExMngStCmd = VlvAct_ExTOilMaxValCmd_C;
               }
               else
               {
                  u16LocalVlvActExMngStCmd = VlvAct_ExLihValCmd_C;
               }
            }
         }
      }
   }
   u16LocalVlvAct_ExMngStCmd = (uint16)MATHSRV_udtMIN(u16LocalVlvActExMngStCmd,
                                                      1023);
   VEMS_vidSET(VlvAct_ExMngStCmd, u16LocalVlvAct_ExMngStCmd);
   VLVACTEXMNG_vidEngStopAuth();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidTimer2                                      */
/* !Description :  Calcul des sorties des Timers 3 et 4                       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_ExMngStCmd;                                           */
/*  input boolean CoPTSt_bMainEngStopReq;                                     */
/*  input boolean VLVACTEXMNG_bTimer1Input;                                   */
/*  input uint8 VlvAct_ExEngStopCmdThd_C;                                     */
/*  input uint8 VlvAct_tiExEngStopDftAuthDly_C;                               */
/*  input uint8 VLVACTEXMNG_u8Tempo3;                                         */
/*  input uint16 Vxx_rel_ex_vvt_mes;                                          */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 VlvAct_uBattExEngStopAuthDly_T[5];                           */
/*  input uint16 VlvAct_tOilExEngStopAuthDly_T[5];                            */
/*  input uint8 VlvAct_tiExEngStopAuthDly_M[5][5];                            */
/*  input boolean VLVACTEXMNG_bTimer2Input;                                   */
/*  input uint8 VlvAct_ExEngStopPosnMax_C;                                    */
/*  input uint8 VLVACTEXMNG_u8Tempo4;                                         */
/*  output boolean VLVACTEXMNG_bTimer1Input;                                  */
/*  output uint8 VLVACTEXMNG_u8Tempo3;                                        */
/*  output boolean VLVACTEXMNG_bTimeout3;                                     */
/*  output boolean VLVACTEXMNG_bTimer2Input;                                  */
/*  output uint8 VLVACTEXMNG_u8Tempo4;                                        */
/*  output boolean VLVACTEXMNG_bTimeout4;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidTimer2(void)
{
   boolean bLocalTimer1InputPrev;
   boolean bLocalTimer2InputPrev;
   boolean bLocalCoPTSt_bMainEngStopReq;
   uint8   u8LocalInterp2d;
   uint16  u16LocalVlvAct_ExMngStCmd;
   uint16  u16LocalVlvAct_ExEngStopCmdThd_C;
   uint16  u16LocalVxx_rel_ex_vvt_mes;
   uint16  u16Ext_uBattMes;
   uint16  u16LocalEng_tOilEstim;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   sint16  s16Ext_uBattMes;
   sint16  s16LocalEng_tOilEstim;
   sint32  s32LocalEng_tOilEstim;


   VEMS_vidGET(VlvAct_ExMngStCmd, u16LocalVlvAct_ExMngStCmd);
   VEMS_vidGET(CoPTSt_bMainEngStopReq, bLocalCoPTSt_bMainEngStopReq);
   bLocalTimer1InputPrev = VLVACTEXMNG_bTimer1Input;
   u16LocalVlvAct_ExEngStopCmdThd_C = (uint16)(4*VlvAct_ExEngStopCmdThd_C);
   if (  (u16LocalVlvAct_ExMngStCmd < u16LocalVlvAct_ExEngStopCmdThd_C)
      && (bLocalCoPTSt_bMainEngStopReq != 0))
   {
      VLVACTEXMNG_bTimer1Input = 1;
   }
   else
   {
      VLVACTEXMNG_bTimer1Input = 0;
   }

   if (  (VLVACTEXMNG_bTimer1Input != 0)
      && (bLocalTimer1InputPrev == 0))
   {
      VLVACTEXMNG_u8Tempo3 = VlvAct_tiExEngStopDftAuthDly_C;
      if (VLVACTEXMNG_u8Tempo3 == 0)
      {
         VLVACTEXMNG_bTimeout3 = 1;
      }
      else
      {
         VLVACTEXMNG_bTimeout3 = 0;
      }
   }
   else
   {
      if (VLVACTEXMNG_u8Tempo3 > 0)
      {
         VLVACTEXMNG_u8Tempo3 = (uint8)(VLVACTEXMNG_u8Tempo3 - 1);
         if (VLVACTEXMNG_u8Tempo3 == 0)
         {
            VLVACTEXMNG_bTimeout3 = 1;
         }
         else
         {
            VLVACTEXMNG_bTimeout3 = 0;
         }
      }
   }

   VEMS_vidGET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);
   VEMS_vidGET(Ext_uBattMes, s16Ext_uBattMes);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);

   u16Ext_uBattMes = (uint16)MATHSRV_udtMAX(s16Ext_uBattMes, 0);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(VlvAct_uBattExEngStopAuthDly_T,
                                                   u16Ext_uBattMes,
                                                   5);
   s32LocalEng_tOilEstim = s16LocalEng_tOilEstim + 200;
   u16LocalEng_tOilEstim = (uint16)MATHSRV_udtMAX(s32LocalEng_tOilEstim, 0);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(VlvAct_tOilExEngStopAuthDly_T,
                                                   u16LocalEng_tOilEstim,
                                                   5);
   u8LocalInterp2d =
         MATHSRV_u8Interp2d(&VlvAct_tiExEngStopAuthDly_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             5);

   bLocalTimer2InputPrev = VLVACTEXMNG_bTimer2Input;

   if (  (u16LocalVxx_rel_ex_vvt_mes < VlvAct_ExEngStopPosnMax_C)
      && (VLVACTEXMNG_bTimer1Input != 0))
   {
      VLVACTEXMNG_bTimer2Input = 1;
   }
   else
   {
      VLVACTEXMNG_bTimer2Input = 0;
   }

   if (  (VLVACTEXMNG_bTimer2Input != 0)
      && (bLocalTimer2InputPrev == 0))
   {
      VLVACTEXMNG_u8Tempo4 = u8LocalInterp2d;
      if (VLVACTEXMNG_u8Tempo4 == 0)
      {
         VLVACTEXMNG_bTimeout4 = 1;
      }
      else
      {
         VLVACTEXMNG_bTimeout4 = 0;
      }
   }
   else
   {
      if (VLVACTEXMNG_u8Tempo4 > 0)
      {
         VLVACTEXMNG_u8Tempo4 = (uint8)(VLVACTEXMNG_u8Tempo4 - 1);
         if (VLVACTEXMNG_u8Tempo4 == 0)
         {
            VLVACTEXMNG_bTimeout4 = 1;
         }
         else
         {
            VLVACTEXMNG_bTimeout4 = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidEngStopAuth                                 */
/* !Description :  La LdC VVT échappement doit informer à tout moment les     */
/*                 autres fonctions du contrôle moteur si la position du      */
/*                 déphaseur VVT admission permet l’arrêt du moteur           */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMNG_vidTimer2();                                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VLVACTEXMNG_bTimer1Input;                                   */
/*  input boolean VLVACTEXMNG_bTimeout3;                                      */
/*  input boolean VLVACTEXMNG_bTimer2Input;                                   */
/*  input boolean VLVACTEXMNG_bTimeout4;                                      */
/*  output boolean VlvAct_bExEngStopAuth;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidEngStopAuth(void)
{
   boolean bLocalVlvAct_bExEngStopAuth;


   VLVACTEXMNG_vidTimer2();
   if (  (  (VLVACTEXMNG_bTimer1Input != 0)
         && (VLVACTEXMNG_bTimeout3 != 0))
      || (  (VLVACTEXMNG_bTimer2Input != 0)
         && (VLVACTEXMNG_bTimeout4 != 0)))
   {
      bLocalVlvAct_bExEngStopAuth = 1;
   }
   else
   {
      bLocalVlvAct_bExEngStopAuth = 0;
   }
   VEMS_vidSET(VlvAct_bExEngStopAuth, bLocalVlvAct_bExEngStopAuth);
}
/*------------------------------- end of file --------------------------------*/