/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLMGR                                                  */
/* !Description     : IDLMGR component                                        */
/*                                                                            */
/* !Module          : IDLMGR                                                  */
/* !Description     : GESTION DU RALENTI                                      */
/*                                                                            */
/* !File            : IDLMGR_FCT2.C                                           */
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
/*   1 / IDLMGR_vidCalc_inertie_veh                                           */
/*   2 / IDLMGR_vidCalc_transition_gains                                      */
/*   3 / IDLMGR_vidCalc_gains_filt_regime                                     */
/*   4 / IDLMGR_vidCalc_gains_filtre_grad                                     */
/*   5 / IDLMGR_vidEstimer_regime                                             */
/*   6 / IDLMGR_vidCalculer_reg_grad_spec                                     */
/*   7 / IDLMGR_vidCalculer_ralenti                                           */
/*   8 / IDLMGR_vidCalculer_coef_ralenti                                      */
/*   9 / IDLMGR_vidManager_le_ralenti                                         */
/*   10 / IDLMGR_vidCalculer_consigne_dyn                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5010777 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0003 / 2.9                                      */
/* !OtherRefs   : VEMS V02 ECU#063158                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLMGR/IDLMGR_FCT$*/
/* $Revision::   1.18     $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_LIMITS.h"
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IDLMGR.h"
#include "IDLMGR_L.h"
#include "IDLMGR_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_inertie_veh                                 */
/* !Description :  Dans cette fonction, on calcule l’inertie du véhicule à    */
/*                 partir des informations de régime moteur, vitesse véhicule,*/
/*                 masse véhicule et inertie du moteur à vide.                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_011.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean IdlSys_bRstNEstim;                                          */
/*  input uint16 IDLMGR_u16MeasuredIdlSysSpdVeh;                              */
/*  input uint16 IDLMGR_u16MeasuredEngSpdFilt;                                */
/*  input uint16 IdlSys_rGearRaw_MP;                                          */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_tiFilVehSpd_C;                                        */
/*  input uint32 IDLMGR_u32FiltredIdlSpdVehMem;                               */
/*  input uint16 IdlSys_tiFilEngSpd_C;                                        */
/*  input uint32 IDLMGR_u32FiltredEngSpdMem;                                  */
/*  input uint16 IdlSys_tiFilRatGear_C;                                       */
/*  input uint32 IDLMGR_u32FiltredSysRGearMem;                                */
/*  input uint16 IdlSys_rGear_MP;                                             */
/*  input uint8 IdlSys_mVeh_C;                                                */
/*  input uint8 IdlSys_jEng_C;                                                */
/*  output uint16 IDLMGR_u16MeasuredIdlSysSpdVeh;                             */
/*  output uint32 IDLMGR_u32FiltredIdlSpdVehMem;                              */
/*  output uint16 IDLMGR_u16MeasuredEngSpdFilt;                               */
/*  output uint32 IDLMGR_u32FiltredEngSpdMem;                                 */
/*  output uint16 IdlSys_rGearRaw_MP;                                         */
/*  output uint16 IdlSys_rGear_MP;                                            */
/*  output uint32 IDLMGR_u32FiltredSysRGearMem;                               */
/*  output uint16 IdlSys_jVehFil;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_inertie_veh(void)
{
   uint8  u8LocalExt_tiTDC;
   uint16 u16LocalExt_nEngClc0;
   uint16 u16LocalVeh_spdVeh;
   uint16 u16LocalIdlSysRGear;
   uint16 u16LocalMeasuredValue;
   uint32 u32LocalFilterGain;
   uint32 u32LocalCalcjVehSpcFil;
   uint32 u32LocalIdlSysrGearRaw;
   uint32 u32LocalCalc;


   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   if (IdlSys_bRstNEstim != 0)
   {
      IDLMGR_u16MeasuredIdlSysSpdVeh =
         (uint16)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 64000);
      IDLMGR_u32FiltredIdlSpdVehMem = IDLMGR_u16MeasuredIdlSysSpdVeh
                                    * (uint32)65536;
      IDLMGR_u16MeasuredEngSpdFilt =
         (uint16)MATHSRV_udtMIN(u16LocalExt_nEngClc0, 32000);
      IDLMGR_u32FiltredEngSpdMem = (uint32)( IDLMGR_u16MeasuredEngSpdFilt
                                           * 65536);
      if (IDLMGR_u16MeasuredEngSpdFilt != 0)
      {
         u32LocalIdlSysrGearRaw = (uint32)( ( IDLMGR_u16MeasuredIdlSysSpdVeh
                                            * 256)
                                          / IDLMGR_u16MeasuredEngSpdFilt);
         IdlSys_rGearRaw_MP =
            (uint16)MATHSRV_udtMIN(u32LocalIdlSysrGearRaw, 820);
      }
      else
      {
         IdlSys_rGearRaw_MP = 820;
      }
      IdlSys_rGear_MP = IdlSys_rGearRaw_MP;
      IDLMGR_u32FiltredSysRGearMem = (uint32)(IdlSys_rGearRaw_MP * 65536);
   }
   else
   {
      VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
      u32LocalFilterGain =
         (uint32)((128 * u8LocalExt_tiTDC) + (IdlSys_tiFilVehSpd_C * 125));
      if (  (u32LocalFilterGain == 0)
         || (IdlSys_tiFilVehSpd_C == 0))
      {
         u16LocalMeasuredValue = u16LocalVeh_spdVeh;
         IDLMGR_u32FiltredIdlSpdVehMem = (uint32)(u16LocalVeh_spdVeh * 65536);
      }
      else
      {
         u32LocalFilterGain = (uint32)( 8388608
                                      * u8LocalExt_tiTDC)
                            / u32LocalFilterGain;
         u16LocalMeasuredValue =
            MATHSRV_u16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                            &IDLMGR_u32FiltredIdlSpdVehMem,
                                            u16LocalVeh_spdVeh);
      }
      IDLMGR_u16MeasuredIdlSysSpdVeh =
         (uint16)MATHSRV_udtMIN(u16LocalMeasuredValue, 64000);

      u32LocalFilterGain =
         (uint32)((128 * u8LocalExt_tiTDC) + (IdlSys_tiFilEngSpd_C * 125));
      if (  (u32LocalFilterGain == 0)
         || (IdlSys_tiFilEngSpd_C == 0))
      {
         u16LocalMeasuredValue = u16LocalExt_nEngClc0;
         IDLMGR_u32FiltredEngSpdMem = (uint32)(u16LocalExt_nEngClc0 * 65536);
      }
      else
      {
         u32LocalFilterGain = (uint32)( 8388608
                                      * u8LocalExt_tiTDC)
                            / u32LocalFilterGain;
         u16LocalMeasuredValue =
            MATHSRV_u16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                            &IDLMGR_u32FiltredEngSpdMem,
                                            u16LocalExt_nEngClc0);
      }
      IDLMGR_u16MeasuredEngSpdFilt =
         (uint16)MATHSRV_udtMIN(u16LocalMeasuredValue, 32000);
      if (IDLMGR_u16MeasuredEngSpdFilt != 0)
      {
         u32LocalIdlSysrGearRaw = (uint32)( ( IDLMGR_u16MeasuredIdlSysSpdVeh
                                            * 256)
                                          / IDLMGR_u16MeasuredEngSpdFilt);
         IdlSys_rGearRaw_MP =
            (uint16)MATHSRV_udtMIN(u32LocalIdlSysrGearRaw, 820);
      }
      else
      {
         IdlSys_rGearRaw_MP = 820;
      }
      u32LocalFilterGain =
         (uint32)((128 * u8LocalExt_tiTDC) + (IdlSys_tiFilRatGear_C * 125));
      if (  (u32LocalFilterGain == 0)
         || (IdlSys_tiFilRatGear_C == 0))
      {
         u16LocalIdlSysRGear = IdlSys_rGearRaw_MP;
         IDLMGR_u32FiltredSysRGearMem = (uint32)(IdlSys_rGearRaw_MP * 65536);
      }
      else
      {
         u32LocalFilterGain = (uint32)( 8388608
                                      * u8LocalExt_tiTDC)
                            / u32LocalFilterGain;
         u16LocalIdlSysRGear =
            MATHSRV_u16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                            &IDLMGR_u32FiltredSysRGearMem,
                                            IdlSys_rGearRaw_MP);
      }
      IdlSys_rGear_MP = (uint16)MATHSRV_udtMIN(u16LocalIdlSysRGear, 820);
   }

   /* IdlSys_jVehFil = (IdlSys_rGear¨2 * IdlSys_mVeh_C * 1759 ) / 6553600
                     + IdlSys_jEng_C                                   */

   u32LocalCalcjVehSpcFil = (uint32)( ( IdlSys_rGear_MP
                                      * IdlSys_rGear_MP)
                                    * IdlSys_mVeh_C);

   if (u32LocalCalcjVehSpcFil > (uint32)(23841095))
   {
      u32LocalCalcjVehSpcFil  = 6399;
   }
   else
   {
      if (u32LocalCalcjVehSpcFil <= 2441709)
      {
         u32LocalCalcjVehSpcFil = u32LocalCalcjVehSpcFil * 1759;
         u32LocalCalc = (uint32)IdlSys_jEng_C * 6553600;
         if (u32LocalCalcjVehSpcFil <= (UINT32_MAX - u32LocalCalc))
         {
            u32LocalCalcjVehSpcFil = (u32LocalCalcjVehSpcFil + u32LocalCalc);
            u32LocalCalcjVehSpcFil = u32LocalCalcjVehSpcFil / 6553600;
         }
         else
         {
            u32LocalCalcjVehSpcFil =
               (u32LocalCalcjVehSpcFil / 6553600) + IdlSys_jEng_C;
         }
      }
      else
      {
         u32LocalCalcjVehSpcFil = (u32LocalCalcjVehSpcFil / 10) * 1759;
         u32LocalCalc = (uint32)IdlSys_jEng_C * 655360;
         if (u32LocalCalcjVehSpcFil <= (UINT32_MAX - u32LocalCalc))
         {
            u32LocalCalcjVehSpcFil = (u32LocalCalcjVehSpcFil + u32LocalCalc);
            u32LocalCalcjVehSpcFil = u32LocalCalcjVehSpcFil / 655360;
         }
         else
         {
            u32LocalCalcjVehSpcFil =
               (u32LocalCalcjVehSpcFil / 655360) + IdlSys_jEng_C;
         }
      }
   }
   IdlSys_jVehFil = (uint16)MATHSRV_udtMIN(u32LocalCalcjVehSpcFil, 6399);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_transition_gains                            */
/* !Description :  Dans cette fonction, on gère un état qui viendra piloter   */
/*                 les gains de l'estimateur en fonction de la situation de   */
/*                 vie : Moteur à vide, Moteur entrainé sans appui frein et   */
/*                 Moteur entrainé avec appui frein.                          */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 IdlSys_idxFilGain;                                            */
/*  input uint8 IdlSys_noGear;                                                */
/*  input boolean IdlSys_bAcvBrk;                                             */
/*  output uint8 IDLMGR_u8IdlSysIdxFilGainPrev;                               */
/*  output uint8 IdlSys_idxFilGain;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_transition_gains(void)
{
   boolean bLocalIdlSys_bAcvBrk;
   uint8   u8LocalIdlSys_noGear;


   IDLMGR_u8IdlSysIdxFilGainPrev = (uint8)MATHSRV_udtMIN(IdlSys_idxFilGain, 2);
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   switch (IdlSys_idxFilGain)
   {
      case 0:
         if (u8LocalIdlSys_noGear != 0)
         /* !QAC : Msg(2:2215) Indentation is correct. */
         {
            VEMS_vidGET(IdlSys_bAcvBrk, bLocalIdlSys_bAcvBrk);
            if (bLocalIdlSys_bAcvBrk == 0)
            {
               IdlSys_idxFilGain = 1;
            }
            else
            {
               IdlSys_idxFilGain = 2;
            }
         }
         break;

      case 1:
         if (u8LocalIdlSys_noGear == 0)
         {
            IdlSys_idxFilGain = 0;
         }
         else
         {
            VEMS_vidGET(IdlSys_bAcvBrk, bLocalIdlSys_bAcvBrk);
            if (bLocalIdlSys_bAcvBrk != 0)
            {
               IdlSys_idxFilGain = 2;
            }
         }
         break;

      case 2:
         if (u8LocalIdlSys_noGear == 0)
         {
            IdlSys_idxFilGain = 0;
         }
         else
         {
            VEMS_vidGET(IdlSys_bAcvBrk, bLocalIdlSys_bAcvBrk);
            if (bLocalIdlSys_bAcvBrk == 0)
            {
               IdlSys_idxFilGain = 1;
            }
         }
         break;

      default :
         IdlSys_idxFilGain = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_gains_filt_regime                           */
/* !Description :  Dans cette fonction on calcule les gains de l’estimateur de*/
/*                 régime moteur, et gérer la transition entre ceux-ci.       */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_tiTranFilNEng_C;                                      */
/*  input uint16 IdlSys_tiTranFilGrd;                                         */
/*  input uint8 IdlSys_idxFilGain;                                            */
/*  input uint8 IDLMGR_u8IdlSysIdxFilGainPrev;                                */
/*  input uint16 IDLMGR_u16MltpSwRmpTranStep;                                 */
/*  input uint8 IDLMGR_u8OldIdxFilGainPrev;                                   */
/*  input uint16 IdlSys_facAntNEng1_C;                                        */
/*  input uint16 IdlSys_tiFilNEng1_C;                                         */
/*  input uint16 IdlSys_facIntNEng1_C;                                        */
/*  input uint16 IdlSys_facAntNEng2_C;                                        */
/*  input uint16 IdlSys_tiFilNEng2_C;                                         */
/*  input uint16 IdlSys_facIntNEng2_C;                                        */
/*  input uint16 IdlSys_facAntNEng3_C;                                        */
/*  input uint16 IdlSys_tiFilNEng3_C;                                         */
/*  input uint16 IdlSys_facIntNEng3_C;                                        */
/*  output uint16 IdlSys_tiTranFilGrd;                                        */
/*  output uint8 IDLMGR_u8OldIdxFilGainPrev;                                  */
/*  output uint16 IDLMGR_u16MltpSwRmpTranStep;                                */
/*  output uint16 IdlSys_facAntNEng;                                          */
/*  output uint16 IdlSys_tiFilNEng;                                           */
/*  output uint16 IdlSys_facIntNEng;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_gains_filt_regime(void)
{
   uint8  u8LocalExt_tiTDC;
   uint8  u8LocalIdxFilGain;
   uint8  u8LocalIdxFilGainPrev;
   uint16 u16LocalMltpSwRmpTranIn11;
   uint16 u16LocalMltpSwRmpTranIn12;
   uint16 u16LocalMltpSwRmpTranIn13;
   uint16 u16LocalMltpSwRmpTranIn21;
   uint16 u16LocalMltpSwRmpTranIn22;
   uint16 u16LocalMltpSwRmpTranIn23;
   uint32 u32LocalTedivTr;
   uint32 u32LocalKAntNEng;
   uint32 u32LocaltiFilNeng;
   uint32 u32LocalfacIntNEng;
   sint32 s32LocalStep;


   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);

   if (IdlSys_tiTranFilNEng_C != 0)
   {
      IdlSys_tiTranFilGrd = (uint16)MATHSRV_udtMIN(IdlSys_tiTranFilNEng_C,
                                                   2048);
      u32LocalTedivTr =
         (uint32)((u8LocalExt_tiTDC * 1024) / IdlSys_tiTranFilGrd);
   }
   else
   {
      u32LocalTedivTr = 1000;
   }

   u8LocalIdxFilGain = (uint8)MATHSRV_udtMIN(IdlSys_idxFilGain, 2);
   u8LocalIdxFilGainPrev = (uint8)MATHSRV_udtMIN(IDLMGR_u8IdlSysIdxFilGainPrev,
                                                 2);
   if (u8LocalIdxFilGain != u8LocalIdxFilGainPrev)
   {
      IDLMGR_u8OldIdxFilGainPrev = u8LocalIdxFilGainPrev;
      s32LocalStep = (sint32)(1000 - u32LocalTedivTr);
   }
   else
   {
      s32LocalStep = (sint32)(IDLMGR_u16MltpSwRmpTranStep - u32LocalTedivTr);
   }
   /* !QAC : Msg(3:3356) The result of this logical operation can be 'true'. */
   IDLMGR_u16MltpSwRmpTranStep =
      (uint16)MATHSRV_udtCLAMP(s32LocalStep, 0, 1000);
   if (IDLMGR_u8OldIdxFilGainPrev == 0)
   {
      u16LocalMltpSwRmpTranIn11 = IdlSys_facAntNEng1_C;
      u16LocalMltpSwRmpTranIn12 = IdlSys_tiFilNEng1_C;
      u16LocalMltpSwRmpTranIn13 = IdlSys_facIntNEng1_C;
   }
   else
   {
      if (IDLMGR_u8OldIdxFilGainPrev == 1)
      {
         u16LocalMltpSwRmpTranIn11 = IdlSys_facAntNEng2_C;
         u16LocalMltpSwRmpTranIn12 = IdlSys_tiFilNEng2_C;
         u16LocalMltpSwRmpTranIn13 = IdlSys_facIntNEng2_C;
      }
      else
      {
         u16LocalMltpSwRmpTranIn11 =  IdlSys_facAntNEng3_C;
         u16LocalMltpSwRmpTranIn12 =  IdlSys_tiFilNEng3_C;
         u16LocalMltpSwRmpTranIn13 =  IdlSys_facIntNEng3_C;
      }
   }

   if (u8LocalIdxFilGain == 0)
   {
      u16LocalMltpSwRmpTranIn21 = IdlSys_facAntNEng1_C;
      u16LocalMltpSwRmpTranIn22 = IdlSys_tiFilNEng1_C;
      u16LocalMltpSwRmpTranIn23 = IdlSys_facIntNEng1_C;
   }
   else
   {
      if (u8LocalIdxFilGain == 1)
      {
         u16LocalMltpSwRmpTranIn21 = IdlSys_facAntNEng2_C;
         u16LocalMltpSwRmpTranIn22 = IdlSys_tiFilNEng2_C;
         u16LocalMltpSwRmpTranIn23 = IdlSys_facIntNEng2_C;
      }
      else
      {
         u16LocalMltpSwRmpTranIn21 = IdlSys_facAntNEng3_C;
         u16LocalMltpSwRmpTranIn22 = IdlSys_tiFilNEng3_C;
         u16LocalMltpSwRmpTranIn23 = IdlSys_facIntNEng3_C;
      }
   }
   u32LocalKAntNEng = (uint32)( ( ( IDLMGR_u16MltpSwRmpTranStep
                                   * u16LocalMltpSwRmpTranIn11)
                                + ( ( 1000
                                    - IDLMGR_u16MltpSwRmpTranStep)
                                  * u16LocalMltpSwRmpTranIn21))
                              / 250);
   u32LocaltiFilNeng = (uint32)( ( ( IDLMGR_u16MltpSwRmpTranStep
                                   * u16LocalMltpSwRmpTranIn12)
                                 + ( ( 1000
                                     - IDLMGR_u16MltpSwRmpTranStep)
                                   * u16LocalMltpSwRmpTranIn22))
                               / 1000);
   u32LocalfacIntNEng = (uint32)( ( ( IDLMGR_u16MltpSwRmpTranStep
                                    * u16LocalMltpSwRmpTranIn13)
                                  + ( ( 1000
                                      - IDLMGR_u16MltpSwRmpTranStep)
                                    * u16LocalMltpSwRmpTranIn23))
                                / 250);

   IdlSys_facAntNEng = (uint16)MATHSRV_udtMIN(u32LocalKAntNEng, 4096);
   IdlSys_tiFilNEng = (uint16)MATHSRV_udtMIN(u32LocaltiFilNeng, 2048);
   IdlSys_facIntNEng = (uint16)MATHSRV_udtMIN(u32LocalfacIntNEng, 4096);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_gains_filtre_grad                           */
/* !Description :  Dans cette fonction on calcule les gains de l’estimateur de*/
/*                 gradient de régime moteur, et gérer la transition entre    */
/*                 ceux-ci.                                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_tiTranFilNGrd_C;                                      */
/*  input uint16 IdlSys_tiTranFilNGrd;                                        */
/*  input uint8 IdlSys_idxFilGain;                                            */
/*  input uint8 IDLMGR_u8IdlSysIdxFilGainPrev;                                */
/*  input uint16 IDLMGR_u16MltpSwRmpTrFilGrdStep;                             */
/*  input uint8 IDLMGR_u8OldIdxFilGainPrev;                                   */
/*  input uint16 IdlSys_facAntNGrd1_C;                                        */
/*  input uint16 IdlSys_tiFilNGrd1_C;                                         */
/*  input uint16 IdlSys_facIntNGrd1_C;                                        */
/*  input uint16 IdlSys_facAntNGrd2_C;                                        */
/*  input uint16 IdlSys_tiFilNGrd2_C;                                         */
/*  input uint16 IdlSys_facIntNGrd2_C;                                        */
/*  input uint16 IdlSys_facAntNGrd3_C;                                        */
/*  input uint16 IdlSys_tiFilNGrd3_C;                                         */
/*  input uint16 IdlSys_facIntNGrd3_C;                                        */
/*  output uint16 IdlSys_tiTranFilNGrd;                                       */
/*  output uint8 IDLMGR_u8OldIdxFilGainPrev;                                  */
/*  output uint16 IDLMGR_u16MltpSwRmpTrFilGrdStep;                            */
/*  output uint16 IdlSys_facAntNGrd;                                          */
/*  output uint16 IdlSys_tiFilNGrd;                                           */
/*  output uint16 IdlSys_facIntNGrd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_gains_filtre_grad(void)
{
   uint8  u8LocalExt_tiTDC;
   uint8  u8LocalIdxFilGain;
   uint8  u8LocalIdxFilGainPrev;
   uint16 u16LocalMltpSwRmpTranIn11;
   uint16 u16LocalMltpSwRmpTranIn12;
   uint16 u16LocalMltpSwRmpTranIn13;
   uint16 u16LocalMltpSwRmpTranIn21;
   uint16 u16LocalMltpSwRmpTranIn22;
   uint16 u16LocalMltpSwRmpTranIn23;
   uint32 u32LocalTedivTr;
   uint32 u32LocalKAntFilGrd;
   uint32 u32LocaltiFilGrd;
   uint32 u32LocalKItFilGrd;
   sint32 s32LocalStep;


   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   if (IdlSys_tiTranFilNGrd_C != 0)
   {
      IdlSys_tiTranFilNGrd = (uint16)MATHSRV_udtMIN(IdlSys_tiTranFilNGrd_C,
                                                   2048);
      u32LocalTedivTr =
         (uint32)((u8LocalExt_tiTDC * 1024) / IdlSys_tiTranFilNGrd);
   }
   else
   {
      u32LocalTedivTr = 1000;
   }

   u8LocalIdxFilGain = (uint8)MATHSRV_udtMIN(IdlSys_idxFilGain, 2);
   u8LocalIdxFilGainPrev = (uint8)MATHSRV_udtMIN(IDLMGR_u8IdlSysIdxFilGainPrev,
                                                 2);
   if (u8LocalIdxFilGain != u8LocalIdxFilGainPrev)
   {
      IDLMGR_u8OldIdxFilGainPrev = u8LocalIdxFilGainPrev;
      s32LocalStep = (sint32)(1000 - u32LocalTedivTr);
   }
   else
   {
      s32LocalStep = (sint32)( IDLMGR_u16MltpSwRmpTrFilGrdStep
                             - u32LocalTedivTr);
   }
   /* !QAC : Msg(3:3356) The result of this logical operation can be 'true'. */
   IDLMGR_u16MltpSwRmpTrFilGrdStep = (uint16)MATHSRV_udtCLAMP(s32LocalStep,
                                                              0,
                                                              1000);
   if (IDLMGR_u8OldIdxFilGainPrev == 0)
   {
      u16LocalMltpSwRmpTranIn11 = IdlSys_facAntNGrd1_C;
      u16LocalMltpSwRmpTranIn12 = IdlSys_tiFilNGrd1_C;
      u16LocalMltpSwRmpTranIn13 = IdlSys_facIntNGrd1_C;
   }
   else
   {
      if (IDLMGR_u8OldIdxFilGainPrev == 1)
      {
         u16LocalMltpSwRmpTranIn11 = IdlSys_facAntNGrd2_C;
         u16LocalMltpSwRmpTranIn12 = IdlSys_tiFilNGrd2_C;
         u16LocalMltpSwRmpTranIn13 = IdlSys_facIntNGrd2_C;
      }
      else
      {
         u16LocalMltpSwRmpTranIn11 = IdlSys_facAntNGrd3_C;
         u16LocalMltpSwRmpTranIn12 = IdlSys_tiFilNGrd3_C;
         u16LocalMltpSwRmpTranIn13 = IdlSys_facIntNGrd3_C;
      }
   }
   if (u8LocalIdxFilGain == 0)
   {
      u16LocalMltpSwRmpTranIn21 = IdlSys_facAntNGrd1_C;
      u16LocalMltpSwRmpTranIn22 = IdlSys_tiFilNGrd1_C;
      u16LocalMltpSwRmpTranIn23 = IdlSys_facIntNGrd1_C;
   }
   else
   {
      if (u8LocalIdxFilGain == 1)
      {
         u16LocalMltpSwRmpTranIn21 = IdlSys_facAntNGrd2_C;
         u16LocalMltpSwRmpTranIn22 = IdlSys_tiFilNGrd2_C;
         u16LocalMltpSwRmpTranIn23 = IdlSys_facIntNGrd2_C;
      }
      else
      {
         u16LocalMltpSwRmpTranIn21 = IdlSys_facAntNGrd3_C;
         u16LocalMltpSwRmpTranIn22 = IdlSys_tiFilNGrd3_C;
         u16LocalMltpSwRmpTranIn23 = IdlSys_facIntNGrd3_C;
      }
   }
   u32LocalKAntFilGrd = (uint32)( ( ( IDLMGR_u16MltpSwRmpTrFilGrdStep
                                    * u16LocalMltpSwRmpTranIn11)
                                  + ( ( 1000
                                      - IDLMGR_u16MltpSwRmpTrFilGrdStep)
                                    * u16LocalMltpSwRmpTranIn21))
                                / 250);
   u32LocaltiFilGrd = (uint32)( ( ( IDLMGR_u16MltpSwRmpTrFilGrdStep
                                  * u16LocalMltpSwRmpTranIn12)
                                + ( ( 1000
                                    - IDLMGR_u16MltpSwRmpTrFilGrdStep)
                                  * u16LocalMltpSwRmpTranIn22))
                              / 1000);
   u32LocalKItFilGrd = (uint32)( ( ( IDLMGR_u16MltpSwRmpTrFilGrdStep
                                   * u16LocalMltpSwRmpTranIn13)
                                 + ( ( 1000
                                     - IDLMGR_u16MltpSwRmpTrFilGrdStep)
                                   * u16LocalMltpSwRmpTranIn23))
                               / 250);
   IdlSys_facAntNGrd = (uint16)MATHSRV_udtMIN(u32LocalKAntFilGrd, 4096);
   IdlSys_tiFilNGrd = (uint16)MATHSRV_udtMIN(u32LocaltiFilGrd, 2048);
   IdlSys_facIntNGrd = (uint16)MATHSRV_udtMIN(u32LocalKItFilGrd, 4096);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidEstimer_regime                                   */
/* !Description :  Ce bloc calcule le régime moteur estimé à partir du régime */
/*                 moteur que l’on filtre par un passe-bas de 1er  ordre,     */
/*                 auquel on ajoute une composante issue du couple moteur     */
/*                 réalisé.                                                   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_nEngEstim[2];                                         */
/*  input uint16 IdlSys_facInt[2];                                            */
/*  input sint32 IDLMGR_s32nEngAddPrev[2];                                    */
/*  input boolean IdlSys_bRstNEstim;                                          */
/*  input uint16 IdlSys_tiFil[2];                                             */
/*  input sint16 IdlSys_nGrdPred;                                             */
/*  input uint16 IdlSys_facAnt[2];                                            */
/*  output uint16 IdlSys_nEngEstim[2];                                        */
/*  output sint32 IDLMGR_s32nEngAddPrev[2];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidEstimer_regime(void)
{
   uint8  u8LocalExt_tiTDC;
   uint8  u8LocalIndex;
   sint8  s8LocalaEngPredSign;
   sint8  s8LocalnEngAddPrevSign;
   uint16 u16LocalExt_nEngClc0;
   uint16 u16LocalEngEstim2;
   uint32 u32LocalMult1;
   uint32 u32LocalDiv1;
   uint32 u32LocalMul2;
   uint32 u32LocalDiv;
   uint32 u32LocalAdd;
   uint32 u32LocalAdd1;
   uint32 u32LocalAdd2;
   uint32 u32Localsum;
   uint32 u32LocalAddPrev;
   sint32 s32LocalAdd;
   sint32 s32LocalAddPrev;


   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   /*scaling calc prev value */

   for (u8LocalIndex = 0; u8LocalIndex < 2; u8LocalIndex++)
   {
      /* Calc of IDLMGR_s32nEngAddPrev */
      s32LocalAddPrev = (sint32)( u16LocalExt_nEngClc0
                                - IdlSys_nEngEstim[u8LocalIndex]);
      if (s32LocalAddPrev >= 0)
      {
         if (IdlSys_facInt[u8LocalIndex] == 0)
         {
            s32LocalAddPrev = IDLMGR_s32nEngAddPrev[u8LocalIndex];
         }
         else
         {
            u32LocalAddPrev = (uint32)( ( ( s32LocalAddPrev
                                          * IdlSys_facInt[u8LocalIndex])
                                        + 2)
                                      / 4);
            if (  u32LocalAddPrev
               >= (uint32)(SINT32_MAX - IDLMGR_s32nEngAddPrev[u8LocalIndex]))
            {
               s32LocalAddPrev = SINT32_MAX;
            }
            else
            {
               s32LocalAddPrev = IDLMGR_s32nEngAddPrev[u8LocalIndex]
                               + (sint32)u32LocalAddPrev;
            }
         }
      }
      else
      {
         u32LocalAddPrev = ( (uint32)( (uint16)( s32LocalAddPrev
                                               * (-1))
                                     * IdlSys_facInt[u8LocalIndex])
                           / 4);
         if (IDLMGR_s32nEngAddPrev[u8LocalIndex] >= 0)
         {
            s32LocalAddPrev = IDLMGR_s32nEngAddPrev[u8LocalIndex]
                            - (sint32)u32LocalAddPrev;
         }
         else
         {
            if (  u32LocalAddPrev
               >= (uint32)( IDLMGR_s32nEngAddPrev[u8LocalIndex]
                          + SINT32_MAX
                          +  1))
            {
               s32LocalAddPrev = SINT32_MIN;
            }
            else
            {
               s32LocalAddPrev = IDLMGR_s32nEngAddPrev[u8LocalIndex]
                               - (sint32)u32LocalAddPrev;
            }
         }
      }
      if (IdlSys_bRstNEstim != 0)
      {
         IdlSys_nEngEstim[u8LocalIndex] =
            (uint16)MATHSRV_udtMIN(u16LocalExt_nEngClc0, 32000);
      }
      else
      {
       /*
                  125*IdlSys_nEngEstim*IdlSys_tiFil + 128*Ext_tiTDC*Ext_nEngClc0
IdlSys_nEngEstim = -----------------------------------------------------------
                                 128*Ext_tiTDC + 125*IdlSys_tiFil

        Ext_tiTDC
      + --------- *(IDLMGR_s32nEngAddPrev + IdlSys_nGrdPred *IdlSys_facAnt)
        1024*1000
         */
         u32LocalDiv = (uint32)( ( u8LocalExt_tiTDC
                                 * 128)
                               + ( IdlSys_tiFil[u8LocalIndex]
                                 * 125));
         if (u32LocalDiv == 0)
         {
            u16LocalEngEstim2 = 0;
         }
         else
         {
            /* Calc of Add 1 */
            u32LocalMult1 = (uint32)( IdlSys_nEngEstim[u8LocalIndex]
                                    * IdlSys_tiFil[u8LocalIndex]);
            u32LocalMul2 = (uint32)( u8LocalExt_tiTDC
                                   * u16LocalExt_nEngClc0
                                   * 128);
            if (u32LocalMult1 <= (UINT32_MAX / (uint32)125))
            {
               u32LocalMult1 = u32LocalMult1 * 125;
               u32Localsum = UINT32_MAX - u32LocalMul2;
               if (u32LocalMult1 >= u32Localsum)
               {
                  u32LocalAdd1 = ( u32LocalMult1
                                 / u32LocalDiv);
                  u32LocalAdd1 = u32LocalAdd1
                               + ( u32LocalMul2
                                 / u32LocalDiv);
               }
               else
               {
                  /* !QAC : Msg(2:0584) u32LocalDiv != 0*/
                  u32LocalAdd1 = ( u32LocalMult1
                                 + u32LocalMul2)
                               / u32LocalDiv;
               }
            }
            else
            {
               u32LocalDiv1 = u32LocalDiv / 128;
               u32LocalMult1 = (125 * (u32LocalMult1 / 128));
               /* !QAC : Msg(2:0584) u32LocalDiv != 0*/
               u32LocalMul2 = u32LocalMul2 / 128;
               u32LocalAdd1 = ( u32LocalMult1
                              + u32LocalMul2)
                            / u32LocalDiv1;          /*calc 1 terme */
            }
            if (u8LocalExt_tiTDC != 0)
            {
               if (IdlSys_nGrdPred >= 0)
               {
                  s8LocalaEngPredSign = 1;
               }
               else
               {
                  s8LocalaEngPredSign = -1;
               }
               if (IDLMGR_s32nEngAddPrev[u8LocalIndex] >= 0)
               {
                  s8LocalnEngAddPrevSign = 1;
               }
               else
               {
                  s8LocalnEngAddPrevSign = -1;
               }
               u32LocalMult1 = (uint32)( ( IdlSys_nGrdPred
                                         * s8LocalaEngPredSign)
                                       * IdlSys_facAnt[u8LocalIndex]);

               u32LocalMul2 = (uint32)( s8LocalnEngAddPrevSign
                                      * IDLMGR_s32nEngAddPrev[u8LocalIndex]);
               if (s8LocalnEngAddPrevSign == s8LocalaEngPredSign)
               {
                  u32LocalAdd = u32LocalMult1 + u32LocalMul2;
                  s32LocalAdd = s8LocalnEngAddPrevSign;
               }
               else
               {
                  s32LocalAdd = ( (sint32)u32LocalMult1
                                * s8LocalaEngPredSign)
                              + IDLMGR_s32nEngAddPrev[u8LocalIndex];
                  u32LocalAdd = (uint32)MATHSRV_udtABS(s32LocalAdd);
               }
               if (u32LocalAdd <= (UINT32_MAX / (uint32)u8LocalExt_tiTDC))
               {
                  u32LocalAdd2 = (u32LocalAdd * u8LocalExt_tiTDC) / 1024000;
               }
               else
               {
                  u32LocalAdd2 = ( ( u32LocalAdd
                                  / 256)
                                * u8LocalExt_tiTDC)
                              / 4000;
               }
               if (s32LocalAdd < 0)
               {
                  if (u32LocalAdd2 >= u32LocalAdd1)
                  {
                     u16LocalEngEstim2 = 0;
                  }
                  else
                  {
                     if (u32LocalAdd1 >= (u32LocalAdd2 + 32000))
                     {
                        u16LocalEngEstim2 = 32000;
                     }
                     else
                     {
                        u16LocalEngEstim2 = (uint16)( u32LocalAdd1
                                                    - u32LocalAdd2);
                     }
                  }
               }
               else
               {
                  if (  (u32LocalAdd1 >= 32000)
                     || (u32LocalAdd2 >= 32000))
                  {
                     u16LocalEngEstim2 = 32000;
                  }
                  else
                  {
                     u16LocalEngEstim2 = (uint16)( u32LocalAdd1
                                                 + u32LocalAdd2);
                  }
               }
            }
            else
            {
               u16LocalEngEstim2 = IdlSys_nEngEstim[u8LocalIndex];
            }
         }
         /* Calc of IdlSys_nEngEstim */
         IdlSys_nEngEstim[u8LocalIndex] =
            (uint16)MATHSRV_udtMIN(u16LocalEngEstim2, 32000);
      }
      IDLMGR_s32nEngAddPrev[u8LocalIndex] = s32LocalAddPrev;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_reg_grad_spec                           */
/* !Description :  Cette fonction calcule le e régime moteur filtré à utiliser*/
/*                 dans la fonction du ralenti et le gradient de régime moteur*/
/*                 filtré à utiliser dans la fonction du ralenti.             */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_016.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean IdlSys_bCfNEngFil_C;                                        */
/*  input uint16 IdlSys_nEngEstim1;                                           */
/*  input uint16 IdlSys_nEngFil1;                                             */
/*  input boolean IdlSys_bCfNGrdFil_C;                                        */
/*  input uint16 IdlSys_nEngEstim2;                                           */
/*  input uint16 IdlSys_nEngFil2;                                             */
/*  input uint16 IDLMGR_u16SwitchPrev;                                        */
/*  input sint16 IdlSys_nGrdEng;                                              */
/*  input sint16 IdlSys_nGrdRaw_MP;                                           */
/*  input uint16 IdlSys_tiFilNGrd_A[8];                                       */
/*  input uint16 IDLMGR_u16FilAEngInPrev;                                     */
/*  input uint16 IdlSys_tiFilNGrd_T[8];                                       */
/*  input boolean IdlSys_bEnaIdl;                                             */
/*  input uint16 IdlSys_tiFilNGrd_MP;                                         */
/*  input sint32 IDLMGR_s32FiltredIdlSysaEngMem;                              */
/*  output uint16 IdlSys_nEng;                                                */
/*  output sint16 IdlSys_nGrdRaw_MP;                                          */
/*  output uint16 IdlSys_tiFilNGrd_MP;                                        */
/*  output sint32 IDLMGR_s32FiltredIdlSysaEngMem;                             */
/*  output sint16 IdlSys_nGrdEng;                                             */
/*  output uint16 IDLMGR_u16FilAEngInPrev;                                    */
/*  output uint16 IDLMGR_u16SwitchPrev;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_reg_grad_spec(void)
{
   boolean bLocalIdlSys_bEnaIdl;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalCalcPara;
   uint16  u16LocalCalcInterp;
   uint16  u16LocalSwitch;
   uint16  u16LocalInputMap;
   uint16  u16LocalIdlSysAEng;
   sint16  s16LocalIdlSysAEng;
   sint16  s16LocalIdlSysAEngFill;
   uint32  u32LocalFilterGain;
   sint32  s32LocalIdlSys_nGrdRaw_MP;
   sint32  s32LocalInputMap;


   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);

   if (IdlSys_bCfNEngFil_C != 0)
   {
      u16LocalIdlSysAEng = IdlSys_nEngEstim1;
   }
   else
   {
      u16LocalIdlSysAEng = IdlSys_nEngFil1;
   }
   IdlSys_nEng = (uint16)MATHSRV_udtMIN(u16LocalIdlSysAEng, 32000);
   if (IdlSys_bCfNGrdFil_C != 0)
   {
      u16LocalSwitch = IdlSys_nEngEstim2;
   }
   else
   {
      u16LocalSwitch = IdlSys_nEngFil2;
   }
   s32LocalIdlSys_nGrdRaw_MP = (u16LocalSwitch - IDLMGR_u16SwitchPrev) * 1000;
   if (u8LocalExt_tiTDC != 0)
   {
      s32LocalIdlSys_nGrdRaw_MP = s32LocalIdlSys_nGrdRaw_MP / u8LocalExt_tiTDC;
      IdlSys_nGrdRaw_MP = (sint16)MATHSRV_udtCLAMP(s32LocalIdlSys_nGrdRaw_MP,
                                                   -32000,
                                                   32000);
   }
   else
   {
      IdlSys_nGrdRaw_MP = (sint16)MATHSRV_udtCLAMP(s32LocalIdlSys_nGrdRaw_MP,
                                                   -32000,
                                                   32000);
   }
   s32LocalInputMap = (sint32)( ( ( IdlSys_nGrdRaw_MP
                           - ( 4 * IdlSys_nGrdEng))
                           + 32000)
                         / 4);
   u16LocalInputMap = (uint16)MATHSRV_udtMAX(s32LocalInputMap, 0);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(IdlSys_tiFilNGrd_A,
                                                   IDLMGR_u16FilAEngInPrev,
                                                   8);
   u16LocalCalcInterp = MATHSRV_u16Interp1d(IdlSys_tiFilNGrd_T ,
                                            u16LocalCalcPara);

   IdlSys_tiFilNGrd_MP = (uint16)MATHSRV_udtMIN(u16LocalCalcInterp, 2048);
   VEMS_vidGET(IdlSys_bEnaIdl, bLocalIdlSys_bEnaIdl);
   if (bLocalIdlSys_bEnaIdl != 0)
   {
   u32LocalFilterGain =
         (uint32)((128 * u8LocalExt_tiTDC) + (IdlSys_tiFilNGrd_MP * 125));
      if (  (u32LocalFilterGain == 0)
         || (IdlSys_tiFilNGrd_MP == 0))
      {
         s16LocalIdlSysAEng = (sint16)(IdlSys_nGrdRaw_MP / 4);
         IDLMGR_s32FiltredIdlSysaEngMem = (sint32)(s16LocalIdlSysAEng * 65536);
      }
      else
      {
         u32LocalFilterGain = (uint32)( 8388608
                                      * u8LocalExt_tiTDC)
                            / u32LocalFilterGain;
         s16LocalIdlSysAEngFill = (sint16)(IdlSys_nGrdRaw_MP / 4);
         s16LocalIdlSysAEng =
            MATHSRV_s16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                            &IDLMGR_s32FiltredIdlSysaEngMem,
                                            s16LocalIdlSysAEngFill);
      }
   }
   else
   {
      s16LocalIdlSysAEng = (sint16)(IdlSys_nGrdRaw_MP / 4);
      IDLMGR_s32FiltredIdlSysaEngMem = (sint32)(s16LocalIdlSysAEng * 65536);
   }
   IdlSys_nGrdEng = (sint16)MATHSRV_udtCLAMP(s16LocalIdlSysAEng, -8000, 8000);
   IDLMGR_u16FilAEngInPrev = u16LocalInputMap;
   IDLMGR_u16SwitchPrev = u16LocalSwitch;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_ralenti                                 */
/* !Description :  cette fonction calcule le ralenti lorsque les calculs sont */
/*                 activés.                                                   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_017.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLMGR_vidCalculer_coef_ralenti();                       */
/*  extf argret void IDLMGR_vidManager_le_ralenti();                          */
/*  extf argret void IDLMGR_vidCalculer_consigne_dyn();                       */
/*  extf argret void IDLMGR_vidCalc_auto_coupure_inj();                       */
/*  extf argret void IDLMGR_vidCalc_couple_isop();                            */
/*  extf argret void IDLMGR_vidCalc_couple_init_reg();                        */
/*  extf argret void IDLMGR_vidPiloter_avances_mini();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_ralenti(void)
{
        IDLMGR_vidCalculer_coef_ralenti();
        IDLMGR_vidManager_le_ralenti();
        IDLMGR_vidCalculer_consigne_dyn();
        IDLMGR_vidCalc_auto_coupure_inj();
        IDLMGR_vidCalc_couple_isop();
        IDLMGR_vidCalc_couple_init_reg();
        IDLMGR_vidPiloter_avances_mini();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_coef_ralenti                            */
/* !Description :  Le profil d’entrée au ralenti est déterminé à partir de    */
/*                 l’erreur de régime entre la consigne statique de ralenti et*/
/*                 le régime moteur filtré. On différencie les cas appui frein*/
/*                 et hors appui frein.                                       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_018.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 IdlSys_nEng;                                                 */
/*  input uint16 IdlSys_nErrIdlDyn_A[8];                                      */
/*  input uint16 IDLMGR_u16ErrIdlDyn_A;                                       */
/*  input uint16 IdlSys_facIdlDynBrk_M[4][8];                                 */
/*  input uint16 IdlSys_facIdlDynNorm_M[4][8];                                */
/*  input boolean IdlSys_bAcvBrk;                                             */
/*  input boolean IdlSys_bIniIdl;                                             */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_facTranMaxIdlDyn_C;                                   */
/*  input sint16 IdlSys_facTranMinIdlDyn_C;                                   */
/*  input uint16 IdlSys_rTranIdlDyn_MP;                                       */
/*  input uint16 IdlSys_facIdlDynBrk_MP;                                      */
/*  input uint16 IdlSys_facIdlDynNorm_MP;                                     */
/*  input sint16 IdlSys_tEng;                                                 */
/*  input uint8 IdlSys_tEng_A[8];                                             */
/*  input uint16 IdlSys_facCorIdlDyn_T[8];                                    */
/*  input uint16 IdlSys_facCorIdlDyn_MP;                                      */
/*  input uint16 IdlSys_facIdlDynRaw_MP;                                      */
/*  input sint16 IdlSys_nErrIdlDyn_MP;                                        */
/*  input uint16 IdlSys_facIdlDyn;                                            */
/*  output uint16 IDLMGR_u16ErrIdlDyn_A;                                      */
/*  output uint16 IdlSys_facIdlDynBrk_MP;                                     */
/*  output uint16 IdlSys_facIdlDynNorm_MP;                                    */
/*  output uint16 IdlSys_rTranIdlDyn_MP;                                      */
/*  output uint16 IdlSys_facIdlDynRaw_MP;                                     */
/*  output uint16 IdlSys_facCorIdlDyn_MP;                                     */
/*  output uint16 IdlSys_facIdlDyn;                                           */
/*  output sint16 IdlSys_nErrIdlDyn_MP;                                       */
/*  output sint16 IdlSys_nGrdTarIdl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_coef_ralenti(void)
{
   boolean bLocalIdlSys_bAcvBrk;
   uint8   u8LocalIdlSys_noGear;
   uint8   u8LocalExt_tiTDC;
   uint8   u8LocalIdlSysTEng;
   uint16  u16LocalCalcPara1;
   uint16  u16LocalRatioIdlSys;
   uint16  u16LocalCalcInc;
   uint16  u16LocalCalcDec;
   uint16  u16LocalInterp1;
   uint16  u16LocalIdlSysTranIdlDyn;
   uint16  u16LocalIdlSys_noGear;
   uint16  u16LocalInterp2;
   uint16  u16LocalInterpDynBrk;
   uint16  u16LocalInterpDynNorm;
   uint16  u16LocalTqSys_nTarIdl;
   sint16  s16LocalInputMAp;
   sint16  s16LocalIdlSys_nErrIdlDyn_MP;
   sint16  s16LocalIdlSysTEng;
   uint32  u32LocalIdlSys_facIdlDyn;
   uint32  u32LocalIdlSys_rTranIdlDyn1;
   uint32  u32LocalIdlSys_rTranIdlDyn2;
   uint32  u32LocalCalcInc;
   sint32  s32LocalIdlSys_nGrdTarIdl;
   sint32  s32LocalCalcDec;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   s16LocalInputMAp =
      (sint16)(((u16LocalTqSys_nTarIdl - IdlSys_nEng) + 32000) / 4);

   IDLMGR_u16ErrIdlDyn_A = (uint16)MATHSRV_udtMAX(s16LocalInputMAp, 0);
   u16LocalIdlSys_noGear = (uint16)(u8LocalIdlSys_noGear * 256);

   u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlDyn_A,
                                                    IDLMGR_u16ErrIdlDyn_A,
                                                    8);
   u16LocalInterp1 = MATHSRV_u16Interp2d(&IdlSys_facIdlDynBrk_M[0][0],
                                         u16LocalIdlSys_noGear,
                                         u16LocalCalcPara1,
                                         8);
   u16LocalInterp2 = MATHSRV_u16Interp2d(&IdlSys_facIdlDynNorm_M[0][0],
                                         u16LocalIdlSys_noGear,
                                         u16LocalCalcPara1,
                                         8);
   u16LocalInterpDynBrk = (uint16)MATHSRV_udtMIN(u16LocalInterp1, 1280);
   u16LocalInterpDynNorm = (uint16)MATHSRV_udtMIN(u16LocalInterp2, 1280);
   IdlSys_facIdlDynBrk_MP = (uint16)(8 * u16LocalInterpDynBrk);
   IdlSys_facIdlDynNorm_MP = (uint16)(8 * u16LocalInterpDynNorm);

   VEMS_vidGET(IdlSys_bAcvBrk, bLocalIdlSys_bAcvBrk);
   if (bLocalIdlSys_bAcvBrk != 0)
   {
      u16LocalRatioIdlSys = 1024;
   }
   else
   {
      u16LocalRatioIdlSys = 0;
   }
   if (IdlSys_bIniIdl != 0)
   {
      u16LocalIdlSysTranIdlDyn = u16LocalRatioIdlSys;
   }
   else
   {
      VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
      u32LocalCalcInc = (uint32)( (u8LocalExt_tiTDC * IdlSys_facTranMaxIdlDyn_C)
                                / 125);
      s32LocalCalcDec =
                     (sint32)( ( (u8LocalExt_tiTDC * IdlSys_facTranMinIdlDyn_C)
                               * (-1))
                             / 125);
      u16LocalCalcInc = (uint16)MATHSRV_udtMIN(u32LocalCalcInc, 65535);
      u16LocalCalcDec = (uint16)MATHSRV_udtCLAMP(s32LocalCalcDec, 0, 65535);
      u16LocalIdlSysTranIdlDyn = MATHSRV_u16SlewFilter(IdlSys_rTranIdlDyn_MP,
                                                       u16LocalRatioIdlSys,
                                                       u16LocalCalcInc,
                                                       u16LocalCalcDec);
   }
   IdlSys_rTranIdlDyn_MP =
      (uint16)MATHSRV_udtMIN(u16LocalIdlSysTranIdlDyn, 1024);
   u32LocalIdlSys_rTranIdlDyn1 = (uint32)( IdlSys_rTranIdlDyn_MP
                                         * IdlSys_facIdlDynBrk_MP);
   u32LocalIdlSys_rTranIdlDyn2 = (uint32)( (1024 - IdlSys_rTranIdlDyn_MP)
                                         * IdlSys_facIdlDynNorm_MP);
   IdlSys_facIdlDynRaw_MP = (uint16)( ( u32LocalIdlSys_rTranIdlDyn1
                                      + u32LocalIdlSys_rTranIdlDyn2
                                      + 512)
                                    / 1024);
   s16LocalIdlSysTEng = (sint16)((sint32)(IdlSys_tEng + 200) / 4);
   u8LocalIdlSysTEng = (uint8)MATHSRV_udtCLAMP(s16LocalIdlSysTEng, 0, 255);
   u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU8(IdlSys_tEng_A,
                                                   u8LocalIdlSysTEng,
                                                   8);
   u16LocalInterp2 = MATHSRV_u16Interp1d(IdlSys_facCorIdlDyn_T,
                                         u16LocalCalcPara1);
   IdlSys_facCorIdlDyn_MP = (uint16)MATHSRV_udtMIN(u16LocalInterp2, 1280);
   s16LocalIdlSys_nErrIdlDyn_MP =
      (sint16)((u16LocalTqSys_nTarIdl - IdlSys_nEng) / 4);

   u32LocalIdlSys_facIdlDyn = (uint32)( ( ( IdlSys_facCorIdlDyn_MP
                                          * IdlSys_facIdlDynRaw_MP)
                                        + 64 ) / 128);
   IdlSys_facIdlDyn =
      (uint16)MATHSRV_udtMIN(u32LocalIdlSys_facIdlDyn, 10240);
   IdlSys_nErrIdlDyn_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalIdlSys_nErrIdlDyn_MP, -8000, 8000);

   s32LocalIdlSys_nGrdTarIdl =
      (sint32)((IdlSys_nErrIdlDyn_MP * IdlSys_facIdlDyn) / 1024);

   IdlSys_nGrdTarIdl =
      (sint16)MATHSRV_udtCLAMP(s32LocalIdlSys_nGrdTarIdl, -8000, 8000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidManager_le_ralenti                               */
/* !Description :  La fonction de supervision du régulateur se décompose en 8 */
/*                 blocs de détection des conditions du ralenti et 1 bloc de  */
/*                 décision.                                                  */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_019.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLMGR_vidDeterminer_etat_moteur();                      */
/*  extf argret void IDLMGR_vidDeterminer_inj_dyn();                          */
/*  extf argret void IDLMGR_vidDet_regime_critique();                         */
/*  extf argret void IDLMGR_vidDet_ralenti_effectif();                        */
/*  extf argret void IDLMGR_vidDet_chang_etat_rampage();                      */
/*  extf argret void IDLMGR_vidReinit_en_surregime();                         */
/*  extf argret void IDLMGR_vidChange_rapport_boite();                        */
/*  extf argret void IDLMGR_vidDet_changement_mode();                         */
/*  extf argret void IDLMGR_vidDeterminer_demarrage();                        */
/*  extf argret void IDLMGR_vidSuperv_regu_de_ralenti();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidManager_le_ralenti(void)
{
   IDLMGR_vidDeterminer_etat_moteur();
   IDLMGR_vidDeterminer_inj_dyn();
   IDLMGR_vidDet_regime_critique();
   IDLMGR_vidDet_ralenti_effectif();
   IDLMGR_vidDet_chang_etat_rampage();
   IDLMGR_vidReinit_en_surregime();
   IDLMGR_vidChange_rapport_boite();
   IDLMGR_vidDet_changement_mode();
   IDLMGR_vidDeterminer_demarrage();
   IDLMGR_vidSuperv_regu_de_ralenti();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_consigne_dyn                            */
/* !Description :  Lors de l’initialisation de la consigne dynamique par      */
/*                 IdlSys_bIniIdlCtl, la consigne dynamique est rendue égale  */
/*                 au maximum entre la consigne statique de ralenti et le     */
/*                 régime moteur.                                             */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_031.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 IDLMGR_u16InTarIdlPrev;                                      */
/*  input uint16 IdlSys_facIdlDyn;                                            */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean IdlSys_bIniIdlCtl;                                          */
/*  input sint16 IdlSys_nOfsIdlDyn_MP;                                        */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input boolean TqSys_bSpcCmbSel;                                           */
/*  input uint16 IDLMGR_IdlSys_nTarIdlDynPrev;                                */
/*  input boolean IdlSys_bInhNSpcTarIdlDyn_C;                                 */
/*  input boolean IdlSys_bSpcTarIdlDyn_MP;                                    */
/*  input uint16 IdlSys_nSpcTarIdlDyn;                                        */
/*  output sint16 IdlSys_nOfsIdlDyn_MP;                                       */
/*  output uint16 IDLMGR_u16InTarIdlPrev;                                     */
/*  output boolean IdlSys_bSpcTarIdlDyn_MP;                                   */
/*  output uint16 IdlSys_nTarIdlDyn;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_consigne_dyn(void)
{
   boolean bLocalIdlSys_bAcvIdlCtl;
   boolean bLocalIdlSys_bIniIdlCtl;
   boolean bLocalTqSys_bSpcCmbSel;
   sint8   s8LocalSign;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalExt_nEngClc0;
   uint16  u16LocalIdlSys_nTarIdlDyn;
   uint16  u16LocalTqSys_nTarIdl;
   uint16  u16LocalnTarIdlDynRaw;
   uint16  u16LocalIdlSys_nSpcTarIdlDyn;
   uint32  u32LocalTarIdl;
   uint32  u32Localnum;
   uint32  u32Localdiv;
   sint32  s32LocalSum;
   sint32  s32LocalTarIdl;


   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   u32LocalTarIdl = (uint32)MATHSRV_udtABS( u16LocalTqSys_nTarIdl
                                          - IDLMGR_u16InTarIdlPrev);
   u32Localdiv = IdlSys_facIdlDyn * u8LocalExt_tiTDC;

   if (u32Localdiv != 0)
   {
      u32Localnum = 4096000000UL / u32Localdiv;
      if (u32LocalTarIdl >= u32Localnum)
      {
         u32LocalTarIdl = 4000;
      }
      else
      {
         u32LocalTarIdl = ((u32LocalTarIdl * u32Localdiv) + 512000) / 1024000;
      }
   }
   else
   {
      u32LocalTarIdl = 0;
   }
   if (u16LocalTqSys_nTarIdl > IDLMGR_u16InTarIdlPrev)
   {
      IdlSys_nOfsIdlDyn_MP = (sint16)u32LocalTarIdl;
   }
   else
   {
      s32LocalTarIdl = ((sint32)u32LocalTarIdl * (-1));
      IdlSys_nOfsIdlDyn_MP = (sint16)s32LocalTarIdl;
   }

   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
   if (bLocalIdlSys_bAcvIdlCtl == 0)
   {
      u16LocalnTarIdlDynRaw = u16LocalTqSys_nTarIdl;
   }
   else
   {
      VEMS_vidGET(IdlSys_bIniIdlCtl, bLocalIdlSys_bIniIdlCtl);
      if (bLocalIdlSys_bIniIdlCtl == 0)
      {
         if (u16LocalTqSys_nTarIdl > IDLMGR_u16InTarIdlPrev)
         {
            s8LocalSign = 1;
         }
         else
         {
            if (u16LocalTqSys_nTarIdl < IDLMGR_u16InTarIdlPrev)
            {
               s8LocalSign = -1;
            }
            else
            {
               s8LocalSign = 0;
            }
         }
         s32LocalSum = (sint32)( IDLMGR_u16InTarIdlPrev
                               + IdlSys_nOfsIdlDyn_MP
                               + s8LocalSign);
         u16LocalnTarIdlDynRaw = (uint16)MATHSRV_udtCLAMP(s32LocalSum,
                                                          0,
                                                          65535);
         u16LocalnTarIdlDynRaw = (uint16)MATHSRV_udtMAX(u16LocalnTarIdlDynRaw,
                                                        u16LocalTqSys_nTarIdl);
      }
      else
      {
         VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
         u16LocalnTarIdlDynRaw = (uint16)MATHSRV_udtMAX(u16LocalTqSys_nTarIdl,
                                                        u16LocalExt_nEngClc0);
      }
   }

   IDLMGR_u16InTarIdlPrev = (uint16)MATHSRV_udtMIN(u16LocalnTarIdlDynRaw,
                                                     32000);

   VEMS_vidGET(TqSys_bSpcCmbSel, bLocalTqSys_bSpcCmbSel);
   if (  (  (u16LocalTqSys_nTarIdl == IDLMGR_IdlSys_nTarIdlDynPrev)
         && (bLocalTqSys_bSpcCmbSel == 0))
      || (IdlSys_bInhNSpcTarIdlDyn_C != 0))
   {
      IdlSys_bSpcTarIdlDyn_MP = 0;
   }
   else
   {
      if (  (  (u16LocalTqSys_nTarIdl == IDLMGR_IdlSys_nTarIdlDynPrev)
            || (bLocalIdlSys_bAcvIdlCtl == 0))
         && (bLocalTqSys_bSpcCmbSel != 0))
      {
         IdlSys_bSpcTarIdlDyn_MP = 1;
      }
   }

   if (IdlSys_bSpcTarIdlDyn_MP == 0)
   {
      u16LocalIdlSys_nTarIdlDyn = u16LocalnTarIdlDynRaw;
   }
   else
   {
      VEMS_vidGET(IdlSys_nSpcTarIdlDyn, u16LocalIdlSys_nSpcTarIdlDyn);
      u16LocalIdlSys_nTarIdlDyn = u16LocalIdlSys_nSpcTarIdlDyn;
   }

   u16LocalIdlSys_nTarIdlDyn =
      (uint16)MATHSRV_udtMIN(u16LocalIdlSys_nTarIdlDyn, 32000);
   VEMS_vidSET(IdlSys_nTarIdlDyn, u16LocalIdlSys_nTarIdlDyn);
}
/*------------------------------- end of file --------------------------------*/