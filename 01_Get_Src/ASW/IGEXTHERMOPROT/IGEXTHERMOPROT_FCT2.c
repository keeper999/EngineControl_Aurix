/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGEXTHERMOPROT                                          */
/* !Description     : IGEXTHERMOPROT component.                               */
/*                                                                            */
/* !Module          : IGEXTHERMOPROT                                          */
/* !Description     : PROTECTION THERMIQUE DE LA LIGNE D’ECHAPPEMENT.         */
/*                                                                            */
/* !File            : IGEXTHERMOPROT_FCT2.C                                   */
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
/*   1 / IGEXTHERMOPROT_vidCalOnIntOrProt                                     */
/*   2 / IGEXTHERMOPROT_vidCalOnCutOrCutP                                     */
/*   3 / IGEXTHERMOPROT_vidAdvCalc                                            */
/*   4 / IGEXTHERMOPROT_vidPrevAdvCalc                                        */
/*   5 / IGEXTHERMOPROT_vidCurAdvCalc                                         */
/*   6 / IGEXTHERMOPROT_vidBVAdvCalc                                          */
/*   7 / IGEXTHERMOPROT_vidASRAdvCalc                                         */
/*   8 / IGEXTHERMOPROT_vidThermProtCalc                                      */
/*   9 / IGEXTHERMOPROT_vidInhAdvMinTimer                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 06151 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                 */
/* $Revision::   1.7      $$Author::   wbouach        $$Date::                */
/* $Author::   wbouach                                $$Date::                */
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "IGEXTHERMOPROT.h"
#include "IGEXTHERMOPROT_l.h"
#include "IGEXTHERMOPROT_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidCalOnIntOrProt                           */
/* !Description :  Fonction de calcul du during de la transition INTEGRATION  */
/*                 et PROTECTION                                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 EngM_mfAirCor_temp;                                          */
/*  input uint16 IgSys_rMinThermoIgEfc_ThP;                                   */
/*  input uint16 IgSys_rDynIgSpEfc_ThP;                                       */
/*  input uint8 IgSys_SampleTiMid_PhysVal;                                    */
/*  input uint16 IgSys_mAirInt_thermoProt;                                    */
/*  output uint16 IgSys_mAirInt_thermoProt;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidCalOnIntOrProt(void)
{
   uint16 u16LocalCalcThermoProt;
   uint32 u32LocalSOM;
   uint32 u32LocalCalc;
   sint32 s32LocalCalc;
   sint32 s32LocalCalc1;
   sint32 s32LocalSOM;


   if (EngM_mfAirCor_temp != 0)
   {
      s32LocalSOM = (sint32)( ( IgSys_rMinThermoIgEfc_ThP
                           - IgSys_rDynIgSpEfc_ThP)
                         * IgSys_SampleTiMid_PhysVal);
      if (s32LocalSOM > 0)
      {
         if ( (uint32)s32LocalSOM > ( UINT32_MAX / (uint32)EngM_mfAirCor_temp))
         {
            s32LocalCalc1 = (sint32)(IgSys_mAirInt_thermoProt * 16000);
            s32LocalSOM = (sint32)( ( ( IgSys_rMinThermoIgEfc_ThP
                                      - IgSys_rDynIgSpEfc_ThP)
                                    * IgSys_SampleTiMid_PhysVal)
                                  / 64);
            if ( (uint32)s32LocalSOM < ( UINT32_MAX /
                                       (uint32)EngM_mfAirCor_temp))
            {
               u32LocalSOM = (uint32)( s32LocalSOM * EngM_mfAirCor_temp);
               u32LocalCalc = ( ( ((uint32)s32LocalCalc1 + u32LocalSOM)
                                + 8000)
                              / 16000);
               u16LocalCalcThermoProt =
                  (uint16)MATHSRV_udtMIN(u32LocalCalc, 65535);
            }
            else
            {
               u16LocalCalcThermoProt = 65535;
            }
         }
         else
         {
            u32LocalSOM = ((uint32)(s32LocalSOM * EngM_mfAirCor_temp)
                          / 1024000);
            u32LocalCalc = (u32LocalSOM + IgSys_mAirInt_thermoProt);
            u16LocalCalcThermoProt =
               (uint16)MATHSRV_udtMIN(u32LocalCalc, 65535);
         }
      }
      else
      {
         if (s32LocalSOM < ( SINT32_MIN / (sint32)EngM_mfAirCor_temp))
         {
            s32LocalCalc1 = (sint32)(IgSys_mAirInt_thermoProt * 16000);
            s32LocalSOM = (sint32)( ( ( IgSys_rMinThermoIgEfc_ThP
                                      - IgSys_rDynIgSpEfc_ThP)
                                    * IgSys_SampleTiMid_PhysVal)
                                  / 64);
            if (s32LocalSOM > ( SINT32_MIN / (sint32)EngM_mfAirCor_temp))
            {
               s32LocalSOM = ( s32LocalSOM * EngM_mfAirCor_temp);
               s32LocalCalc = ( ((s32LocalCalc1 + s32LocalSOM) + 8000) / 16000);
               u16LocalCalcThermoProt = (uint16)MATHSRV_udtMAX(s32LocalCalc, 0);
            }
            else
            {
               u16LocalCalcThermoProt = 0;
            }
         }
         else
         {
            s32LocalCalc = ((s32LocalSOM * EngM_mfAirCor_temp) / 1024000);
            s32LocalSOM = (s32LocalCalc + IgSys_mAirInt_thermoProt);
            u16LocalCalcThermoProt = (uint16)MATHSRV_udtMAX(s32LocalSOM, 0);
         }
      }
      IgSys_mAirInt_thermoProt = u16LocalCalcThermoProt;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidCalOnCutOrCutP                           */
/* !Description :  Focntion de calcul du during des transitions COUPURE et    */
/*                 COUPURE_PROT                                               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 IgSys_mAirInt_thermoProt;                                    */
/*  input uint16 IgSys_rDecPuc_mAir_C;                                        */
/*  input uint8 IgSys_SampleTiMid_PhysVal;                                    */
/*  input uint16 EngM_mfAirCor_temp;                                          */
/*  output uint16 IgSys_mAirInt_thermoProt;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidCalOnCutOrCutP(void)
{
   uint16 u16LocalCalcThermoProt;
   uint32 u32LocalCalc1;
   uint32 u32LocalCalc2;
   uint32 u32LocalSOM;
   sint32 s32LocalCalc;


   u32LocalCalc1 = (uint32)(IgSys_mAirInt_thermoProt * 16000);
   u32LocalSOM = (uint32)( ( ( IgSys_rDecPuc_mAir_C
                              * IgSys_SampleTiMid_PhysVal)
                           + 32)
                         / 64);

   if (u32LocalSOM == 0)
   {
      u16LocalCalcThermoProt = IgSys_mAirInt_thermoProt;
   }
   else
   {
      if ( (uint32)EngM_mfAirCor_temp  < ( UINT32_MAX / u32LocalSOM))
      {
         u32LocalCalc2 = (EngM_mfAirCor_temp * u32LocalSOM);
         if (u32LocalCalc1 <  u32LocalCalc2)
         {
            u16LocalCalcThermoProt = 0;
         }
         else
         {
            s32LocalCalc = ( ( (sint32)(u32LocalCalc1 - u32LocalCalc2)
                                       + 8000)
                           / 16000);
            u16LocalCalcThermoProt = (uint16)s32LocalCalc;
         }
      }
      else
      {
         u16LocalCalcThermoProt = 0;
      }
   }
   IgSys_mAirInt_thermoProt = u16LocalCalcThermoProt;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidAdvCalc                                  */
/* !Description :  Fonction permettant le débornage des avances mini en cas de*/
/*                 protection composants pour assurer les suivis de couple    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGEXTHERMOPROT_vidPrevAdvCalc();                         */
/*  extf argret void IGEXTHERMOPROT_vidCurAdvCalc();                          */
/*  extf argret void IGEXTHERMOPROT_vidBVAdvCalc();                           */
/*  extf argret void IGEXTHERMOPROT_vidASRAdvCalc();                          */
/*  extf argret void IGEXTHERMOPROT_vidInhAdvMinTimer();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Eng_bExThermoProtNotInh;                                    */
/*  input boolean IGEXTHERMOPROT_bCond1;                                      */
/*  input boolean IGEXTHERMOPROT_bTimerOut1;                                  */
/*  input boolean Inhibition_appli_avance_min_spc[4];                         */
/*  input boolean IGEXTHERMOPROT_bCond2;                                      */
/*  input boolean IGEXTHERMOPROT_bTimerOut2;                                  */
/*  input boolean IGEXTHERMOPROT_bCond3;                                      */
/*  input boolean IGEXTHERMOPROT_bTimerOut3;                                  */
/*  input boolean IGEXTHERMOPROT_bCond4;                                      */
/*  input boolean IGEXTHERMOPROT_bTimerOut4;                                  */
/*  output boolean Eng_bExThermoProt;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidAdvCalc(void)
{
   boolean bLocalExThermoProt;
   boolean bLocalEngThPrNotInh;
   boolean bLocalCondition1;
   boolean bLocalCondition2;
   boolean bLocalCondition3;
   boolean bLocalCondition4;


   VEMS_vidGET(Eng_bExThermoProtNotInh, bLocalEngThPrNotInh);

   IGEXTHERMOPROT_vidPrevAdvCalc();
   IGEXTHERMOPROT_vidCurAdvCalc();
   IGEXTHERMOPROT_vidBVAdvCalc();
   IGEXTHERMOPROT_vidASRAdvCalc();
   IGEXTHERMOPROT_vidInhAdvMinTimer();

   if (  (  (IGEXTHERMOPROT_bCond1 != 0)
         && (IGEXTHERMOPROT_bTimerOut1 == 0))
      && (Inhibition_appli_avance_min_spc[0] != 0))
   {
      bLocalCondition1 = 1;
   }
   else
   {
      bLocalCondition1 = 0;
   }
   if (  (  (IGEXTHERMOPROT_bCond2 != 0)
         && (IGEXTHERMOPROT_bTimerOut2 == 0))
      && (Inhibition_appli_avance_min_spc[1] != 0))
   {
      bLocalCondition2 = 1;
   }
   else
   {
      bLocalCondition2 = 0;
   }
   if (  (  (IGEXTHERMOPROT_bCond3 != 0)
         && (IGEXTHERMOPROT_bTimerOut3 == 0))
      && (Inhibition_appli_avance_min_spc[2] != 0))
   {
      bLocalCondition3 = 1;
   }
   else
   {
      bLocalCondition3 = 0;
   }
   if (  (  (IGEXTHERMOPROT_bCond4 != 0)
         && (IGEXTHERMOPROT_bTimerOut4 == 0))
      && (Inhibition_appli_avance_min_spc[3] != 0))
   {
      bLocalCondition4 = 1;
   }
   else
   {
      bLocalCondition4 = 0;
   }
   if (  (bLocalCondition1 != 0)
      || (bLocalCondition2 != 0)
      || (bLocalCondition3 != 0)
      || (bLocalCondition4 != 0))
   {
      bLocalExThermoProt = 0;
   }
   else
   {
      bLocalExThermoProt = bLocalEngThPrNotInh;
   }
   VEMS_vidSET(Eng_bExThermoProt,bLocalExThermoProt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidPrevAdvCalc                              */
/* !Description :  Première fonction permettant le débornage des avances mini */
/*                 en cas de protection composants pour assurer les suivis de */
/*                 couple                                                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Eng_bExThermoProtNotInh;                                    */
/*  input boolean TqSys_bAcvCll;                                              */
/*  input uint8 IgSys_agIgTarWiCllTar;                                        */
/*  input uint8 IgSys_agIgLimMinKnk;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IgSys_nEng_IgThermoProt_A[8];                                */
/*  input uint16 EngM_rAirLdCor_3_A[8];                                       */
/*  input uint16 Tempo_appli_agr_prev_avance_mini[8][8];                      */
/*  input boolean Activation_agr_prev_avance_mini;                            */
/*  input boolean Inhibition_appli_avance_min_spc[4];                         */
/*  input uint16 IGEXTHERMOPROT_u16TmrDelay1;                                 */
/*  input boolean IGEXTHERMOPROT_bInitTmrPrev1;                               */
/*  input boolean IGEXTHERMOPROT_bCond1;                                      */
/*  input boolean IGEXTHERMOPROT_bInitTmrPrev2;                               */
/*  output boolean IGEXTHERMOPROT_bCond1;                                     */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay1;                                */
/*  output boolean IGEXTHERMOPROT_bTimerOut1;                                 */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev2;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev1;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidPrevAdvCalc(void)
{
   boolean bLocalEngThPrNotInh;
   boolean bLocalTqSys_bAcvCll;
   boolean bLocalInitTimer1;
   uint8   u8LocalagIgTrWiCllTar;
   uint8   u8LocalagIgLimMinKnk;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalOutMap1;
   sint32  s32LocalDelay1;


   VEMS_vidGET(Eng_bExThermoProtNotInh, bLocalEngThPrNotInh);
   VEMS_vidGET(TqSys_bAcvCll, bLocalTqSys_bAcvCll);
   VEMS_vidGET(IgSys_agIgTarWiCllTar, u8LocalagIgTrWiCllTar);
   VEMS_vidGET(IgSys_agIgLimMinKnk, u8LocalagIgLimMinKnk);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_IgThermoProt_A,
                                                u16LocalExt_nEng,
                                                8);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(EngM_rAirLdCor_3_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);
   u16LocalOutMap1 =
      MATHSRV_u16Interp2d(&Tempo_appli_agr_prev_avance_mini[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          8);

   if (  (bLocalEngThPrNotInh != 0)
      && (  (bLocalTqSys_bAcvCll != 0)
         && (Activation_agr_prev_avance_mini != 0))
      && (Inhibition_appli_avance_min_spc[0] != 0)
      && (u8LocalagIgTrWiCllTar < u8LocalagIgLimMinKnk))
   {
      IGEXTHERMOPROT_bCond1 = 1;
   }
   else
   {
      IGEXTHERMOPROT_bCond1 = 0;
   }

   if (  (  (IGEXTHERMOPROT_u16TmrDelay1 > 0)
         && (IGEXTHERMOPROT_bInitTmrPrev1 != 0))
      || (IGEXTHERMOPROT_bCond1 != 0))
   {
      bLocalInitTimer1 = 1;
   }
   else
   {
      bLocalInitTimer1 = 0;
   }

   if (  (IGEXTHERMOPROT_bInitTmrPrev1 != 0)
      && (IGEXTHERMOPROT_bInitTmrPrev2 == 0))
   {
      IGEXTHERMOPROT_u16TmrDelay1 = u16LocalOutMap1;
      if (IGEXTHERMOPROT_u16TmrDelay1 == 0)
      {
         IGEXTHERMOPROT_bTimerOut1 = 1;
      }
      else
      {
         IGEXTHERMOPROT_bTimerOut1 = 0;
      }
   }
   else
   {
      if (IGEXTHERMOPROT_u16TmrDelay1 > 0)
      {
         s32LocalDelay1 = IGEXTHERMOPROT_u16TmrDelay1 - u8LocalExt_tiTDC;
         IGEXTHERMOPROT_u16TmrDelay1 = (uint16)MATHSRV_udtMAX(s32LocalDelay1,
                                                              0);
         if (IGEXTHERMOPROT_u16TmrDelay1 == 0)
         {
            IGEXTHERMOPROT_bTimerOut1 = 1;
         }
         else
         {
            IGEXTHERMOPROT_bTimerOut1 = 0;
         }
      }
   }

   IGEXTHERMOPROT_bInitTmrPrev2 = IGEXTHERMOPROT_bInitTmrPrev1;
   IGEXTHERMOPROT_bInitTmrPrev1 = bLocalInitTimer1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidCurAdvCalc                               */
/* !Description :  Deuxième fonction permettant le débornage des avances mini */
/*                 en cas de protection composants pour assurer les suivis de */
/*                 couple                                                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Eng_bExThermoProtNotInh;                                    */
/*  input uint8 IgSys_agIgTarWiCllTar;                                        */
/*  input uint8 IgSys_agIgLimMinKnk;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean TqSys_bAOSAcv;                                              */
/*  input uint16 IgSys_nEng_IgThermoProt_A[8];                                */
/*  input uint16 EngM_rAirLdCor_3_A[8];                                       */
/*  input uint16 Tempo_appli_agr_cur_avance_mini[8][8];                       */
/*  input boolean Activation_agr_cur_avance_mini;                             */
/*  input boolean Inhibition_appli_avance_min_spc[4];                         */
/*  input uint16 IGEXTHERMOPROT_u16TmrDelay3;                                 */
/*  input boolean IGEXTHERMOPROT_bInitTmrPrev3;                               */
/*  input boolean IGEXTHERMOPROT_bCond2;                                      */
/*  input boolean IGEXTHERMOPROT_bInitTmrPrev4;                               */
/*  output boolean IGEXTHERMOPROT_bCond2;                                     */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay3;                                */
/*  output boolean IGEXTHERMOPROT_bTimerOut2;                                 */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev4;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev3;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidCurAdvCalc(void)
{
   boolean bLocalEngThPrNotInh;
   boolean bLocalTqSys_bAOSAcv;
   boolean bLocalInitTimer3;
   uint8   u8LocalagIgTrWiCllTar;
   uint8   u8LocalagIgLimMinKnk;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalOutMap3;
   sint32  s32LocalDelay3;


   VEMS_vidGET(Eng_bExThermoProtNotInh, bLocalEngThPrNotInh);
   VEMS_vidGET(IgSys_agIgTarWiCllTar, u8LocalagIgTrWiCllTar);
   VEMS_vidGET(IgSys_agIgLimMinKnk, u8LocalagIgLimMinKnk);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET(TqSys_bAOSAcv, bLocalTqSys_bAOSAcv);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_IgThermoProt_A,
                                                u16LocalExt_nEng,
                                                8);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(EngM_rAirLdCor_3_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);
   u16LocalOutMap3 = MATHSRV_u16Interp2d(&Tempo_appli_agr_cur_avance_mini[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         8);

   if (  (bLocalEngThPrNotInh != 0)
      && (  (bLocalTqSys_bAOSAcv != 0)
         && (Activation_agr_cur_avance_mini != 0))
      && (Inhibition_appli_avance_min_spc[1] != 0)
      && (u8LocalagIgTrWiCllTar < u8LocalagIgLimMinKnk))
   {
      IGEXTHERMOPROT_bCond2 = 1;
   }
   else
   {
      IGEXTHERMOPROT_bCond2 = 0;
   }

   if (  (  (IGEXTHERMOPROT_u16TmrDelay3 > 0)
         && (IGEXTHERMOPROT_bInitTmrPrev3 != 0))
      || (IGEXTHERMOPROT_bCond2 != 0))
   {
      bLocalInitTimer3 = 1;
   }
   else
   {
      bLocalInitTimer3 = 0;
   }

   if (  (IGEXTHERMOPROT_bInitTmrPrev3 != 0)
      && (IGEXTHERMOPROT_bInitTmrPrev4 == 0))
   {
      IGEXTHERMOPROT_u16TmrDelay3 = u16LocalOutMap3;
      if (IGEXTHERMOPROT_u16TmrDelay3 == 0)
      {
         IGEXTHERMOPROT_bTimerOut2 = 1;
      }
      else
      {
         IGEXTHERMOPROT_bTimerOut2 = 0;
      }
   }
   else
   {
      if (IGEXTHERMOPROT_u16TmrDelay3 > 0)
      {
         s32LocalDelay3 = IGEXTHERMOPROT_u16TmrDelay3 - u8LocalExt_tiTDC;
         IGEXTHERMOPROT_u16TmrDelay3 = (uint16)MATHSRV_udtMAX(s32LocalDelay3,
                                                              0);
         if (IGEXTHERMOPROT_u16TmrDelay3 == 0)
         {
            IGEXTHERMOPROT_bTimerOut2 = 1;
         }
         else
         {
            IGEXTHERMOPROT_bTimerOut2 = 0;
         }
      }
   }

   IGEXTHERMOPROT_bInitTmrPrev4 = IGEXTHERMOPROT_bInitTmrPrev3;
   IGEXTHERMOPROT_bInitTmrPrev3 = bLocalInitTimer3;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidBVAdvCalc                                */
/* !Description :  Troisième fonction permettant le débornage des avances mini*/
/*                 en cas de protection composants pour assurer les suivis de */
/*                 couple                                                     */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Eng_bExThermoProtNotInh;                                    */
/*  input uint8 IgSys_agIgTarWiCllTar;                                        */
/*  input uint8 IgSys_agIgLimMinKnk;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean CoPt_bSIP;                                                  */
/*  input uint16 IgSys_nEng_IgThermoProt_A[8];                                */
/*  input uint16 EngM_rAirLdCor_3_A[8];                                       */
/*  input uint16 Tempo_appli_BV_avance_mini[8][8];                            */
/*  input boolean Activation_BV_avance_mini;                                  */
/*  input boolean Inhibition_appli_avance_min_spc[4];                         */
/*  input uint16 IGEXTHERMOPROT_u16TmrDelay5;                                 */
/*  input boolean IGEXTHERMOPROT_bInitTmrPrev5;                               */
/*  input boolean IGEXTHERMOPROT_bCond3;                                      */
/*  input boolean IGEXTHERMOPROT_bInitTmrPrev6;                               */
/*  output boolean IGEXTHERMOPROT_bCond3;                                     */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay5;                                */
/*  output boolean IGEXTHERMOPROT_bTimerOut3;                                 */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev6;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev5;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidBVAdvCalc(void)
{
   boolean bLocalEngThPrNotInh;
   boolean bLocalCoPt_bSIP;
   boolean bLocalInitTimer5;
   uint8   u8LocalagIgTrWiCllTar;
   uint8   u8LocalagIgLimMinKnk;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalOutMap5;
   sint32  s32LocalDelay5;


   VEMS_vidGET(Eng_bExThermoProtNotInh, bLocalEngThPrNotInh);
   VEMS_vidGET(IgSys_agIgTarWiCllTar, u8LocalagIgTrWiCllTar);
   VEMS_vidGET(IgSys_agIgLimMinKnk, u8LocalagIgLimMinKnk);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET(CoPt_bSIP, bLocalCoPt_bSIP);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_IgThermoProt_A,
                                                u16LocalExt_nEng,
                                                8);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(EngM_rAirLdCor_3_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);
   u16LocalOutMap5 = MATHSRV_u16Interp2d(&Tempo_appli_BV_avance_mini[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         8);

   if (  (bLocalEngThPrNotInh != 0)
      && (  (bLocalCoPt_bSIP != 0)
         && (Activation_BV_avance_mini != 0))
      && (Inhibition_appli_avance_min_spc[2] != 0)
      && (u8LocalagIgTrWiCllTar < u8LocalagIgLimMinKnk))
   {
      IGEXTHERMOPROT_bCond3 = 1;
   }
   else
   {
      IGEXTHERMOPROT_bCond3 = 0;
   }

   if (  (  (IGEXTHERMOPROT_u16TmrDelay5 > 0)
         && (IGEXTHERMOPROT_bInitTmrPrev5 != 0))
      || (IGEXTHERMOPROT_bCond3 != 0))
   {
      bLocalInitTimer5 = 1;
   }
   else
   {
      bLocalInitTimer5 = 0;
   }

   if (  (IGEXTHERMOPROT_bInitTmrPrev5 != 0)
      && (IGEXTHERMOPROT_bInitTmrPrev6 == 0))
   {
      IGEXTHERMOPROT_u16TmrDelay5 = u16LocalOutMap5;
      if (IGEXTHERMOPROT_u16TmrDelay5 == 0)
      {
         IGEXTHERMOPROT_bTimerOut3 = 1;
      }
      else
      {
         IGEXTHERMOPROT_bTimerOut3 = 0;
      }
   }
   else
   {
      if (IGEXTHERMOPROT_u16TmrDelay5 > 0)
      {
         s32LocalDelay5 = IGEXTHERMOPROT_u16TmrDelay5 - u8LocalExt_tiTDC;
         IGEXTHERMOPROT_u16TmrDelay5 = (uint16)MATHSRV_udtMAX(s32LocalDelay5,
                                                              0);
         if (IGEXTHERMOPROT_u16TmrDelay5 == 0)
         {
            IGEXTHERMOPROT_bTimerOut3 = 1;
         }
         else
         {
            IGEXTHERMOPROT_bTimerOut3 = 0;
         }
      }
   }

   IGEXTHERMOPROT_bInitTmrPrev6 = IGEXTHERMOPROT_bInitTmrPrev5;
   IGEXTHERMOPROT_bInitTmrPrev5 = bLocalInitTimer5;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidASRAdvCalc                               */
/* !Description :  Quatrième fonction permettant le débornage des avances mini*/
/*                 en cas de protection composants pour assurer les suivis de */
/*                 couple                                                     */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Eng_bExThermoProtNotInh;                                    */
/*  input uint8 IgSys_agIgTarWiCllTar;                                        */
/*  input uint8 IgSys_agIgLimMinKnk;                                          */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean CoCha_bASRSecuReq;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 IgSys_nEng_IgThermoProt_A[8];                                */
/*  input uint16 EngM_rAirLdCor_3_A[8];                                       */
/*  input uint16 Tempo_appli_ESP_ASR_avance_mini[8][8];                       */
/*  input boolean Activation_ESP_ASR_avance_mini;                             */
/*  input boolean Inhibition_appli_avance_min_spc[4];                         */
/*  input uint16 IGEXTHERMOPROT_u16TmrDelay7;                                 */
/*  input boolean IGEXTHERMOPROT_bInitTmrPrev7;                               */
/*  input boolean IGEXTHERMOPROT_bCond4;                                      */
/*  input boolean IGEXTHERMOPROT_bInitTmrPrev8;                               */
/*  output boolean IGEXTHERMOPROT_bCond4;                                     */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay7;                                */
/*  output boolean IGEXTHERMOPROT_bTimerOut4;                                 */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev8;                              */
/*  output boolean IGEXTHERMOPROT_bInitTmrPrev7;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidASRAdvCalc(void)
{
   boolean bLocalEngThPrNotInh;
   boolean bLocalCoCha_bASRSecuReq;
   boolean bLocalInitTimer7;
   uint8   u8LocalagIgTrWiCllTar;
   uint8   u8LocalagIgLimMinKnk;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalOutMap7;
   sint32  s32LocalDelay7;


   VEMS_vidGET(Eng_bExThermoProtNotInh, bLocalEngThPrNotInh);
   VEMS_vidGET(IgSys_agIgTarWiCllTar, u8LocalagIgTrWiCllTar);
   VEMS_vidGET(IgSys_agIgLimMinKnk, u8LocalagIgLimMinKnk);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET(CoCha_bASRSecuReq, bLocalCoCha_bASRSecuReq);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_IgThermoProt_A,
                                                u16LocalExt_nEng,
                                                8);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(EngM_rAirLdCor_3_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);
   u16LocalOutMap7 = MATHSRV_u16Interp2d(&Tempo_appli_ESP_ASR_avance_mini[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         8);

   if (  (bLocalEngThPrNotInh != 0)
      && (  (bLocalCoCha_bASRSecuReq != 0)
         && (Activation_ESP_ASR_avance_mini != 0))
      && (Inhibition_appli_avance_min_spc[3] != 0)
      && (u8LocalagIgTrWiCllTar < u8LocalagIgLimMinKnk))
   {
      IGEXTHERMOPROT_bCond4 = 1;
   }
   else
   {
      IGEXTHERMOPROT_bCond4 = 0;
   }

   if (  (  (IGEXTHERMOPROT_u16TmrDelay7 > 0)
         && (IGEXTHERMOPROT_bInitTmrPrev7 != 0))
      || (IGEXTHERMOPROT_bCond4 != 0))
   {
      bLocalInitTimer7 = 1;
   }
   else
   {
      bLocalInitTimer7 = 0;
   }

   if (  (IGEXTHERMOPROT_bInitTmrPrev7 != 0)
      && (IGEXTHERMOPROT_bInitTmrPrev8 == 0))
   {
      IGEXTHERMOPROT_u16TmrDelay7 = u16LocalOutMap7;
      if (IGEXTHERMOPROT_u16TmrDelay7 == 0)
      {
         IGEXTHERMOPROT_bTimerOut4 = 1;
      }
      else
      {
         IGEXTHERMOPROT_bTimerOut4 = 0;
      }
   }
   else
   {
      if (IGEXTHERMOPROT_u16TmrDelay7 > 0)
      {
         s32LocalDelay7 = IGEXTHERMOPROT_u16TmrDelay7 - u8LocalExt_tiTDC;
         IGEXTHERMOPROT_u16TmrDelay7 = (uint16)MATHSRV_udtMAX(s32LocalDelay7,
                                                              0);
         if (IGEXTHERMOPROT_u16TmrDelay7 == 0)
         {
            IGEXTHERMOPROT_bTimerOut4 = 1;
         }
         else
         {
            IGEXTHERMOPROT_bTimerOut4 = 0;
         }
      }
   }

   IGEXTHERMOPROT_bInitTmrPrev8 = IGEXTHERMOPROT_bInitTmrPrev7;
   IGEXTHERMOPROT_bInitTmrPrev7 = bLocalInitTimer7;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidThermProtCalc                            */
/* !Description :  Fonction permettant le calcul des variables nécessaires    */
/*                 pour le fonctionnement de l'automate                       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Temperature_eau;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 EngM_mfAirCor;                                               */
/*  input uint8 Temperature_eau_2_bkpt_map[6];                                */
/*  input uint8 IgSys_rAirMax_ThermoProt_T[6];                                */
/*  input uint16 IgSys_nEng_IgThermoProt2_A[16];                              */
/*  input uint16 EngM_rAirLdCor_4_A[16];                                      */
/*  input uint16 IgSys_mAirMax_ThermoProt_M[16][16];                          */
/*  input uint16 IgSys_rAirCor_M[16][16];                                     */
/*  input boolean IgSys_bAirMin_ThermoProtOfs_C;                              */
/*  input uint16 IgSys_mAirMax_ThermoProt;                                    */
/*  input uint16 IgSys_mAirMin_ThermoProtOfs_C;                               */
/*  input uint16 IgSys_mAirMin_ThermoProt_C;                                  */
/*  output uint16 IgSys_mAirMax_ThermoProt;                                   */
/*  output uint16 IgSys_mAirMin_ThermoProt;                                   */
/*  output uint16 EngM_mfAirCor_temp;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidThermProtCalc(void)
{
   uint8  u8LocalTemperatureEau;
   uint8  u8LocalinterpMaxThermoProt;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalTempEauPara;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalOutMap1;
   uint16 u16LocalOutMap2;
   uint16 u16LocalAirCor;
   uint32 u32LocalVarInt;
   uint32 u32LocalmAirMinThermoProt;


   VEMS_vidGET(Temperature_eau, u8LocalTemperatureEau);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(EngM_mfAirCor, u16LocalAirCor);

   u16LocalTempEauPara =
      MATHSRV_u16CalcParaIncAryU8(Temperature_eau_2_bkpt_map,
                                  u8LocalTemperatureEau,
                                  6);
   u8LocalinterpMaxThermoProt =
      MATHSRV_u8Interp1d(&IgSys_rAirMax_ThermoProt_T[0],
                          u16LocalTempEauPara);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_IgThermoProt2_A,
                                                u16LocalExt_nEng,
                                                16);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(EngM_rAirLdCor_4_A,
                                                u16LocalEngM_rAirLdCor,
                                                16);
   u16LocalOutMap1 = MATHSRV_u16Interp2d(&IgSys_mAirMax_ThermoProt_M[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         16);
   u16LocalOutMap2 = MATHSRV_u16Interp2d(&IgSys_rAirCor_M[0][0],
                                        u16LocalParaX,
                                        u16LocalParaY,
                                        16);

   IgSys_mAirMax_ThermoProt = (uint16)((uint32)(((u8LocalinterpMaxThermoProt *
                                                u16LocalOutMap1)+ 256) / 512));

   if (IgSys_bAirMin_ThermoProtOfs_C != 0)
   {
      u32LocalmAirMinThermoProt = (uint32)((IgSys_mAirMax_ThermoProt
                                    + IgSys_mAirMin_ThermoProtOfs_C));
      IgSys_mAirMin_ThermoProt =
         (uint16)MATHSRV_udtMIN(u32LocalmAirMinThermoProt, 65535);
   }
   else
   {
      IgSys_mAirMin_ThermoProt = IgSys_mAirMin_ThermoProt_C;
   }

   if (u16LocalOutMap2 <= 1000)
   {
      EngM_mfAirCor_temp = 0;
   }
   else
   {
      u32LocalVarInt = ((u16LocalOutMap2 - 1000) * u16LocalAirCor) / 100;
      EngM_mfAirCor_temp = (uint16)MATHSRV_udtMIN(u32LocalVarInt, 65535);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGEXTHERMOPROT_vidInhAdvMinTimer                           */
/* !Description :  Une fois le temps d'un des quatre premiers Timers écoulé,  */
/*                 les quatre second Timers sont lancés en même temps pour    */
/*                 décompter un temps d’inhibition du débornage des avances   */
/*                 calibrables                                                */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 IgSys_nEng_IgThermoProt_A[8];                                */
/*  input uint16 EngM_rAirLdCor_3_A[8];                                       */
/*  input uint16 Tempo_inh_agr_prev_avance_mini[8][8];                        */
/*  input uint16 Tempo_inh_agr_cur_avance_mini[8][8];                         */
/*  input uint16 Tempo_inh_BV_avance_mini[8][8];                              */
/*  input uint16 Tempo_inh_ESP_ASR_avance_mini[8][8];                         */
/*  input boolean IGEXTHERMOPROT_bTimerOut1;                                  */
/*  input boolean IGEXTHERMOPROT_bTimerOut2;                                  */
/*  input boolean IGEXTHERMOPROT_bTimerOut3;                                  */
/*  input boolean IGEXTHERMOPROT_bTimerOut4;                                  */
/*  input boolean IGEXTHERMOPROT_bTimer1InitPrev;                             */
/*  input boolean IGEXTHERMOPROT_bTimer1Init;                                 */
/*  input uint16 IGEXTHERMOPROT_u16TmrDelay2;                                 */
/*  input uint16 IGEXTHERMOPROT_u16TmrDelay4;                                 */
/*  input uint16 IGEXTHERMOPROT_u16TmrDelay6;                                 */
/*  input uint16 IGEXTHERMOPROT_u16TmrDelay8;                                 */
/*  output boolean IGEXTHERMOPROT_bTimer1Init;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay2;                                */
/*  output boolean Inhibition_appli_avance_min_spc[4];                        */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay4;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay6;                                */
/*  output uint16 IGEXTHERMOPROT_u16TmrDelay8;                                */
/*  output boolean IGEXTHERMOPROT_bTimer1InitPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGEXTHERMOPROT_vidInhAdvMinTimer(void)
{
   uint8  u8LocalExt_tiTDC;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalOutMap2;
   uint16 u16LocalOutMap4;
   uint16 u16LocalOutMap6;
   uint16 u16LocalOutMap8;
   sint32 s32LocalDelay2;
   sint32 s32LocalDelay4;
   sint32 s32LocalDelay6;
   sint32 s32LocalDelay8;

   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_IgThermoProt_A,
                                                u16LocalExt_nEng,
                                                8);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(EngM_rAirLdCor_3_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);

   u16LocalOutMap2 = MATHSRV_u16Interp2d(&Tempo_inh_agr_prev_avance_mini[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         8);

   u16LocalOutMap4 = MATHSRV_u16Interp2d(&Tempo_inh_agr_cur_avance_mini[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         8);

   u16LocalOutMap6 = MATHSRV_u16Interp2d(&Tempo_inh_BV_avance_mini[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         8);

   u16LocalOutMap8 = MATHSRV_u16Interp2d(&Tempo_inh_ESP_ASR_avance_mini[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         8);

   if (  (IGEXTHERMOPROT_bTimerOut1 == 0)
      || (IGEXTHERMOPROT_bTimerOut2 == 0)
      || (IGEXTHERMOPROT_bTimerOut3 == 0)
      || (IGEXTHERMOPROT_bTimerOut4 == 0) )
   {
      IGEXTHERMOPROT_bTimer1Init = 1;
   }
   else
   {
      IGEXTHERMOPROT_bTimer1Init = 0;
   }

   if (  (IGEXTHERMOPROT_bTimer1InitPrev != 0)
      && (IGEXTHERMOPROT_bTimer1Init == 0))
   {
      IGEXTHERMOPROT_u16TmrDelay2 = u16LocalOutMap2;
      if (IGEXTHERMOPROT_u16TmrDelay2 == 0)
      {
         Inhibition_appli_avance_min_spc[0] = 1;
      }
      else
      {
         Inhibition_appli_avance_min_spc[0] = 0;
      }
   }
   else
   {
      if (IGEXTHERMOPROT_u16TmrDelay2 > 0)
      {
         s32LocalDelay2 = IGEXTHERMOPROT_u16TmrDelay2 - u8LocalExt_tiTDC;
         IGEXTHERMOPROT_u16TmrDelay2 = (uint16)MATHSRV_udtMAX(s32LocalDelay2,
                                                              0);
         if (IGEXTHERMOPROT_u16TmrDelay2 == 0)
         {
            Inhibition_appli_avance_min_spc[0] = 1;
         }
         else
         {
            Inhibition_appli_avance_min_spc[0] = 0;
         }
      }
   }

   if (  (IGEXTHERMOPROT_bTimer1InitPrev != 0)
      && (IGEXTHERMOPROT_bTimer1Init == 0))
   {
      IGEXTHERMOPROT_u16TmrDelay4 = u16LocalOutMap4;
      if (IGEXTHERMOPROT_u16TmrDelay4 == 0)
      {
         Inhibition_appli_avance_min_spc[1] = 1;
      }
      else
      {
         Inhibition_appli_avance_min_spc[1] = 0;
      }
   }
   else
   {
      if (IGEXTHERMOPROT_u16TmrDelay4 > 0)
      {
         s32LocalDelay4 = IGEXTHERMOPROT_u16TmrDelay4 - u8LocalExt_tiTDC;
         IGEXTHERMOPROT_u16TmrDelay4 = (uint16)MATHSRV_udtMAX(s32LocalDelay4,
                                                              0);
         if (IGEXTHERMOPROT_u16TmrDelay4 == 0)
         {
            Inhibition_appli_avance_min_spc[1] = 1;
         }
         else
         {
            Inhibition_appli_avance_min_spc[1] = 0;
         }
      }
   }

   if (  (IGEXTHERMOPROT_bTimer1InitPrev != 0)
      && (IGEXTHERMOPROT_bTimer1Init == 0))
   {
      IGEXTHERMOPROT_u16TmrDelay6 = u16LocalOutMap6;
      if (IGEXTHERMOPROT_u16TmrDelay6 == 0)
      {
         Inhibition_appli_avance_min_spc[2] = 1;
      }
      else
      {
         Inhibition_appli_avance_min_spc[2] = 0;
      }
   }
   else
   {
      if (IGEXTHERMOPROT_u16TmrDelay6 > 0)
      {
         s32LocalDelay6 = IGEXTHERMOPROT_u16TmrDelay6 - u8LocalExt_tiTDC;
         IGEXTHERMOPROT_u16TmrDelay6 = (uint16)MATHSRV_udtMAX(s32LocalDelay6,
                                                              0);
         if (IGEXTHERMOPROT_u16TmrDelay6 == 0)
         {
            Inhibition_appli_avance_min_spc[2] = 1;
         }
         else
         {
            Inhibition_appli_avance_min_spc[2] = 0;
         }
      }
   }

   if (  (IGEXTHERMOPROT_bTimer1InitPrev != 0)
      && (IGEXTHERMOPROT_bTimer1Init == 0))
   {
      IGEXTHERMOPROT_u16TmrDelay8 = u16LocalOutMap8;
      if (IGEXTHERMOPROT_u16TmrDelay8 == 0)
      {
         Inhibition_appli_avance_min_spc[3] = 1;
      }
      else
      {
         Inhibition_appli_avance_min_spc[3] = 0;
      }
   }
   else
   {
      if (IGEXTHERMOPROT_u16TmrDelay8 > 0)
      {
         s32LocalDelay8 = IGEXTHERMOPROT_u16TmrDelay8 - u8LocalExt_tiTDC;
         IGEXTHERMOPROT_u16TmrDelay8 = (uint16)MATHSRV_udtMAX(s32LocalDelay8,
                                                              0);
         if (IGEXTHERMOPROT_u16TmrDelay8 == 0)
         {
            Inhibition_appli_avance_min_spc[3] = 1;
         }
         else
         {
            Inhibition_appli_avance_min_spc[3] = 0;
         }
      }
   }

   IGEXTHERMOPROT_bTimer1InitPrev = IGEXTHERMOPROT_bTimer1Init;
}
/*------------------------------- end of file --------------------------------*/