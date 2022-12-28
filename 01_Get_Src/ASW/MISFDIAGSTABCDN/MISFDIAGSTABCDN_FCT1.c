/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDIAGSTABCDN                                         */
/* !Description     : MISFDIAGSTABCDN component.                              */
/*                                                                            */
/* !Module          : MISFDIAGSTABCDN                                         */
/* !Description     : Conditions de stabilité pour diagnostic misfire         */
/*                                                                            */
/* !File            : MISFDIAGSTABCDN_FCT1.c                                  */
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
/*   1 / MISFDIAGSTABCDN_vidInitOutput                                        */
/*   2 / MISFDIAGSTABCDN_vidInitEngineCnd                                     */
/*   3 / MISFDIAGSTABCDN_vidDiagStabCdn                                       */
/*   4 / MISFDIAGSTABCDN_vidVculeNotRning                                     */
/*   5 / MISFDIAGSTABCDN_vidChkLoadStab                                       */
/*   6 / MISFDIAGSTABCDN_vidChkgearstab                                       */
/*   7 / MISFDIAGSTABCDN_vidChktrqstab                                        */
/*   8 / MISFDIAGSTABCDN_vidEngineCndts                                       */
/*   9 / MISFDIAGSTABCDN_vidEngCdtNotStab                                     */
/*   10 / MISFDIAGSTABCDN_vidEngineCdtStab                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5577717 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066973                                         */
/* !OtherRefs   : VEMS V02 ECU#068484                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDIAGSTABCDN/MISFDIAGSTABC$*/
/* $Revision::   1.6      $$Author::   wbouach        $$Date::   15 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   15 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEMS.h"
#include "MISFDIAGSTABCDN.h"
#include "MISFDIAGSTABCDN_L.h"
#include "MISFDIAGSTABCDN_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidInitOutput                              */
/* !Description :  initialisation des variables internes.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean MISFDIAGSTABCDN_bTrqDedct_Prev;                            */
/*  output boolean MISFDIAGSTABCDN_bGearEnStab_Prev;                          */
/*  output boolean MISFDIAGSTABCDN_bTorStab_Prev;                             */
/*  output boolean MISFDIAGSTABCDN_bMisfEngCdnPrev;                           */
/*  output uint8 MISFDIAGSTABCDN_u8IgSyaIgSpPrev;                             */
/*  output boolean MISFDIAGSTABCDN_bAcvCdNrmRawPrev;                          */
/*  output boolean MISFDIAGSTABCDN_bAcvCdIdlRawPrev;                          */
/*  output uint8 Misf_ctNeutStabTq;                                           */
/*  output uint8 Misf_ctStabTq;                                               */
/*  output boolean MISFDIAGSTABCDN_bfirstiteration;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidInitOutput(void)
{
   MISFDIAGSTABCDN_bTrqDedct_Prev = 0;
   MISFDIAGSTABCDN_bGearEnStab_Prev = 0;
   MISFDIAGSTABCDN_bTorStab_Prev = 0;
   MISFDIAGSTABCDN_bMisfEngCdnPrev = 0;
   MISFDIAGSTABCDN_u8IgSyaIgSpPrev = 0;
   MISFDIAGSTABCDN_bAcvCdNrmRawPrev = 0;
   MISFDIAGSTABCDN_bAcvCdIdlRawPrev = 0;
   Misf_ctNeutStabTq = 0;
   Misf_ctStabTq = 0;
   MISFDIAGSTABCDN_bfirstiteration = 0;
   MISFDIAGSTABCDN_bfirstiteration1 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidInitEngineCnd                           */
/* !Description :  A chaque reset du calculateur, on réinitialise les         */
/*                 variables internes et  les sorties.                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Mf_engine_stable_delay_c;                                     */
/*  input uint8 Mf_indicated_tor_stability_delay;                             */
/*  input uint8 Mf_gear_engaged_stability_delay;                              */
/*  input uint8 Mf_torq_deduction_stab_delay;                                 */
/*  output uint8 Mf_engine_stable_t_d_c;                                      */
/*  output uint8 Mf_indicated_tor_stability_count;                            */
/*  output uint8 Mf_gear_engaged_stability_count;                             */
/*  output uint8 Mf_torq_deduction_stab_count;                                */
/*  output boolean Indicated_torque_mf_not_stable;                            */
/*  output boolean Torque_deduction_mf_not_stable;                            */
/*  output uint16 Misf_ctIgAdvStab;                                           */
/*  output boolean Misf_bEngStabCdn;                                          */
/*  output boolean Mf_stability_conditions;                                   */
/*  output boolean Gear_engaged_mf_not_stable;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidInitEngineCnd(void)
{
   Mf_engine_stable_t_d_c = Mf_engine_stable_delay_c;
   Mf_indicated_tor_stability_count = Mf_indicated_tor_stability_delay;
   Mf_gear_engaged_stability_count = Mf_gear_engaged_stability_delay;
   Mf_torq_deduction_stab_count = Mf_torq_deduction_stab_delay;
   Indicated_torque_mf_not_stable = 1;
   Torque_deduction_mf_not_stable = 1;
   Misf_ctIgAdvStab = 0;
   Misf_bEngStabCdn = 0;
   VEMS_vidSET(Mf_stability_conditions, 0);
   VEMS_vidSET(Gear_engaged_mf_not_stable, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidDiagStabCdn                             */
/* !Description :  La condition de couple prend en compte, par l’intermédiaire*/
/*                 de la variable TqCmp_tqSumLossCmp , les couples prélevés   */
/*                 par  l’alternateur, le GMV, la climatisation, et la        */
/*                 direction assistée.                                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDIAGSTABCDN_vidVculeNotRning();                      */
/*  extf argret void MISFDIAGSTABCDN_vidEngineCndts();                        */
/*  extf argret void MISFDIAGSTABCDN_vidChkLoadStab();                        */
/*  extf argret void MISFDIAGSTABCDN_vidChkgearstab();                        */
/*  extf argret void MISFDIAGSTABCDN_vidChktrqstab();                         */
/*  extf argret void MISFDIAGSTABCDN_vidEngineCdtStab();                      */
/*  extf argret void MISFDIAGSTABCDN_vidEngCdtNotStab();                      */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Clef_de_contact;                                            */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input boolean Mf_engine_conditions;                                       */
/*  input boolean Vehicle_not_running;                                        */
/*  output sint16 Torque_deduction;                                           */
/*  output boolean Vehicle_not_running;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidDiagStabCdn(void)
{
   boolean bLocalClef_de_contact;
   uint8   u8LocalVehicle_active_state;
   sint16  s16LocalTqCmp_tqSumLossCmp;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);
   Torque_deduction =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqCmp_tqSumLossCmp, -32000, 32000);

   if (u8LocalVehicle_active_state != VS_RUNNING)
   {
      Vehicle_not_running = 1;
      MISFDIAGSTABCDN_vidVculeNotRning();
      MISFDIAGSTABCDN_vidEngineCndts();
   }
   else
   {
      Vehicle_not_running = 0;
      MISFDIAGSTABCDN_vidChkLoadStab();
      MISFDIAGSTABCDN_vidChkgearstab();
      MISFDIAGSTABCDN_vidChktrqstab();
      MISFDIAGSTABCDN_vidEngineCndts();
      if (  (Mf_engine_conditions != 0)
         && (bLocalClef_de_contact != 0))
      {
         MISFDIAGSTABCDN_vidEngineCdtStab();
      }
   }
   if (  (bLocalClef_de_contact == 0)
      || (Vehicle_not_running != 0)
      || (Mf_engine_conditions == 0))
   {
      MISFDIAGSTABCDN_vidEngCdtNotStab();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidVculeNotRning                           */
/* !Description :  Lorsque les conditions qui permettent de juger la stabilité*/
/*                 du moteur ne sont pas remplies, on recopie les  variables  */
/*                 EngLim_tqIdcEngCur, Gear_engaged, et Torque_deduction dans */
/*                 des plages mémoires qui  permettront ensuite de suivre leur*/
/*                 évolution.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Gear_engaged;                                                 */
/*  input sint16 Indicated_torque_mf_min;                                     */
/*  input sint16 Indicated_torque_mf_max;                                     */
/*  input sint16 Torque_deduction;                                            */
/*  input sint16 Torque_deduction_mf_min;                                     */
/*  input sint16 Torque_deduction_mf_max;                                     */
/*  output uint8 Gear_engaged_mf_last;                                        */
/*  output sint16 Indicated_torque_mf_min;                                    */
/*  output sint16 Indicated_torque_mf_max;                                    */
/*  output sint16 Torque_deduction_mf_min;                                    */
/*  output sint16 Torque_deduction_mf_max;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidVculeNotRning(void)
{
   uint8   u8LocalGear_engaged;
   sint16  s16LocalEngLim_tqIdcEngCur;
   sint16  s16LocalIndicated_torque_mf_min;
   sint16  s16LocalIndicated_torque_mf_max;
   sint16  s16LocalTorque_deduction_mf_min;
   sint16  s16LocalTorque_deduction_mf_max;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);

   Gear_engaged_mf_last = u8LocalGear_engaged;
   s16LocalIndicated_torque_mf_min =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqIdcEngCur,
                             Indicated_torque_mf_min);
   Indicated_torque_mf_min =
      (sint16)MATHSRV_udtCLAMP(s16LocalIndicated_torque_mf_min,-32000,32000);

   s16LocalIndicated_torque_mf_max =
      (sint16)MATHSRV_udtMAX(s16LocalEngLim_tqIdcEngCur,
                             Indicated_torque_mf_max);
   Indicated_torque_mf_max =
      (sint16)MATHSRV_udtCLAMP(s16LocalIndicated_torque_mf_max,-32000,32000);

   s16LocalTorque_deduction_mf_min = (sint16)MATHSRV_udtMIN(Torque_deduction,
                                                    Torque_deduction_mf_min);
   Torque_deduction_mf_min =
      (sint16)MATHSRV_udtCLAMP(s16LocalTorque_deduction_mf_min,-32000,32000);


   s16LocalTorque_deduction_mf_max = (sint16)MATHSRV_udtMAX(Torque_deduction,
                                                    Torque_deduction_mf_max);
   Torque_deduction_mf_max =
      (sint16)MATHSRV_udtCLAMP(s16LocalTorque_deduction_mf_max,-32000,32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidChkLoadStab                             */
/* !Description :  Condition de stabilité en CMI sur la détection au ralenti, */
/*                 une nouvelle stratégie de détection de stabilité en couple */
/*                 a été développée. Misf_bAcvTqStab_C = 1 : la nouvelle      */
/*                 stratégie est active, Misf_bAcvTqStab_C = 0 : l’ancienne   */
/*                 stratégie est active.                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidChkLdStabFilt();                      */
/*  extf argret void MISFDIAGSTABCDN_vidChkLdStab();                          */
/*  input boolean Misf_bAcvTqStab_C;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidChkLoadStab(void)
{

   if (Misf_bAcvTqStab_C != 0)
   {
      MISFDIAGSTABCDN_vidChkLdStabFilt();
   }
   else
   {
      MISFDIAGSTABCDN_vidChkLdStab();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidChkgearstab                             */
/* !Description :  Le critère de stablité est basé sur le changement éventuel */
/*                 d’un rapport. Si on constate un changement de  rapport, on */
/*                 déclare l’instabilité, sinon on déclare la stabilité après */
/*                 un délai.                                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDIAGSTABCDN_vidGearNotStable();                      */
/*  extf argret void MISFDIAGSTABCDN_vidGearStable();                         */
/*  input uint8 Gear_engaged;                                                 */
/*  input uint8 Gear_engaged_mf_last;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidChkgearstab(void)
{
   uint8  u8LocalGear_engaged;


   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);

   if (u8LocalGear_engaged != Gear_engaged_mf_last)
   {
      MISFDIAGSTABCDN_vidGearNotStable();
   }
   else
   {
      MISFDIAGSTABCDN_vidGearStable();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidChktrqstab                              */
/* !Description :  Le critère de stablité est basé sur la variation crête à   */
/*                 crête du couple depuis la dernière initialisation          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidTorqNotStable();                      */
/*  extf argret void MISFDIAGSTABCDN_vidTorqStable();                         */
/*  input sint16 Torque_deduction_mf_max;                                     */
/*  input sint16 Torque_deduction_mf_min;                                     */
/*  input sint16 Mf_torq_deduction_stab_limit;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidChktrqstab(void)
{
   sint32  s32LocalCalc1;


   s32LocalCalc1 = (sint32)(Torque_deduction_mf_max - Torque_deduction_mf_min);
   if (s32LocalCalc1 > Mf_torq_deduction_stab_limit)
   {
      MISFDIAGSTABCDN_vidTorqNotStable();
   }
   else
   {
      MISFDIAGSTABCDN_vidTorqStable();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidEngineCndts                             */
/* !Description :  Les conditions de stabilité.                               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st07 Engine_running_state;                                          */
/*  input boolean Dv_detection_pied_leve_final;                               */
/*  input boolean Gear_engaged_mf_not_stable;                                 */
/*  input boolean Auto_injection;                                             */
/*  input boolean Indicated_torque_mf_not_stable;                             */
/*  input boolean Torque_deduction_mf_not_stable;                             */
/*  output boolean Mf_engine_conditions;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidEngineCndts(void)
{
   boolean bLocalDvDetectPiedLevFinal;
   boolean bLocalGearEngagedMfNotStable;
   boolean bLocalAuto_injection;
   uint8   u8LocalEngineRunningState;


   VEMS_vidGET(Engine_running_state, u8LocalEngineRunningState);
   VEMS_vidGET(Dv_detection_pied_leve_final, bLocalDvDetectPiedLevFinal);
   VEMS_vidGET(Gear_engaged_mf_not_stable, bLocalGearEngagedMfNotStable);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);


   if (  (u8LocalEngineRunningState == ERUN_ENGINE_OVERRUN_FCO)
      || (u8LocalEngineRunningState == ERUN_ENGINE_OVERSPEED_FCO)
      || (Indicated_torque_mf_not_stable != 0)
      || (bLocalGearEngagedMfNotStable != 0)
      || (Torque_deduction_mf_not_stable != 0)
      || (  (u8LocalEngineRunningState != ERUN_ON_IDLE)
         && (bLocalDvDetectPiedLevFinal != 0))
      || (bLocalAuto_injection == 0))
   {
      Mf_engine_conditions = 0;
   }
   else
   {
      Mf_engine_conditions = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidEngCdtNotStab                           */
/* !Description :  Dans ce bloc on déclare l’instabilité dès que l’une des    */
/*                 conditions de stabilité n’est plus vérifiée.               */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Mf_engine_stable_delay_c;                                     */
/*  output boolean Misf_bEngStabCdn;                                          */
/*  output uint8 Mf_engine_stable_t_d_c;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidEngCdtNotStab(void)
{
   Misf_bEngStabCdn = 0;
   Mf_engine_stable_t_d_c = Mf_engine_stable_delay_c;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidEngineCdtStab                           */
/* !Description :  Ici on déclare la stabilité si les conditions élémentaires */
/*                 sont vérifiées et si le délai s’est écoulé.                */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidTimerOut();                           */
/*  extf argret void MISFDIAGSTABCDN_vidTimer();                              */
/*  input uint8 Mf_engine_stable_t_d_c;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidEngineCdtStab(void)
{
   if (Mf_engine_stable_t_d_c == 0)
   {
      MISFDIAGSTABCDN_vidTimerOut();
   }
   else
   {
      MISFDIAGSTABCDN_vidTimer();
   }
}
/*------------------------------- end of file --------------------------------*/