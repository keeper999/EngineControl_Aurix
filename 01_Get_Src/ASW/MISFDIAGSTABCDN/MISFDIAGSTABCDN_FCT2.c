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
/* !File            : MISFDIAGSTABCDN_FCT2.C                                  */
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
/*   1 / MISFDIAGSTABCDN_vidLoadNotStable                                     */
/*   2 / MISFDIAGSTABCDN_vidLoadStable                                        */
/*   3 / MISFDIAGSTABCDN_vidGearNotStable                                     */
/*   4 / MISFDIAGSTABCDN_vidGearStable                                        */
/*   5 / MISFDIAGSTABCDN_vidTorqNotStable                                     */
/*   6 / MISFDIAGSTABCDN_vidTorqStable                                        */
/*   7 / MISFDIAGSTABCDN_vidTimer                                             */
/*   8 / MISFDIAGSTABCDN_vidTimerOut                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5577717 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066973                                         */
/* !OtherRefs   : VEMS V02 ECU#068484                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDIAGSTABCDN/MISFDIAGSTABC$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   15 Jun 2012 $*/
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
/* !Function    :  MISFDIAGSTABCDN_vidLoadNotStable                           */
/* !Description :  L’initialisation de la variation est effectuée dès que l’on*/
/*                 constate l’instabilité.                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Mf_indicated_tor_stability_delay;                             */
/*  output sint16 Indicated_torque_mf_min;                                    */
/*  output sint16 Indicated_torque_mf_max;                                    */
/*  output uint8 Mf_indicated_tor_stability_count;                            */
/*  output boolean Indicated_torque_mf_not_stable;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidLoadNotStable(void)
{
   sint16  s16LocalEngLim_tqIdcEngCur;
   sint16  s16LocalMinMax;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   s16LocalMinMax = (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcEngCur,
                                             -32000,
                                             32000);
   Indicated_torque_mf_min = s16LocalMinMax;
   Indicated_torque_mf_max = s16LocalMinMax;

   Mf_indicated_tor_stability_count = Mf_indicated_tor_stability_delay;
   Indicated_torque_mf_not_stable = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidLoadStable                              */
/* !Description :  Lorsqu’on  est  stable,  on  attend  un  délai  avant  de  */
/*                 déclarer  la  stabilité  et  on  continue  de  réactualiser*/
/*                  la  variation de couple indiqué.                          */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDIAGSTABCDN_vidLoadSetStab();                        */
/*  extf argret void MISFDIAGSTABCDN_vidLoadWaitStab();                       */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Mf_indicated_tor_stability_count;                             */
/*  input boolean MISFDIAGSTABCDN_bTorStab_Prev;                              */
/*  input sint16 Indicated_torque_mf_min;                                     */
/*  input sint16 Indicated_torque_mf_max;                                     */
/*  output boolean MISFDIAGSTABCDN_bTorStab_Prev;                             */
/*  output sint16 Indicated_torque_mf_min;                                    */
/*  output sint16 Indicated_torque_mf_max;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidLoadStable(void)
{
   sint16  s16LocalEngLim_tqIdcEngCur;
   sint16  s16LocalIndicated_torque_mf_min;
   sint16  s16LocalIndicated_torque_mf_max;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);

   if (Mf_indicated_tor_stability_count == 0)
   {
      if (MISFDIAGSTABCDN_bTorStab_Prev == 0)
      {
         MISFDIAGSTABCDN_vidLoadSetStab();
      }
      else
      {
         MISFDIAGSTABCDN_vidLoadWaitStab();
      }
      MISFDIAGSTABCDN_bTorStab_Prev = 1;
   }
   else
   {
      MISFDIAGSTABCDN_vidLoadWaitStab();
      MISFDIAGSTABCDN_bTorStab_Prev = 0;
   }

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
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidGearNotStable                           */
/* !Description :  L’initialisation de la variation est effectuée dès que l’on*/
/*                 constate l’instabilité.                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Gear_engaged;                                                 */
/*  input uint8 Mf_gear_engaged_stability_delay;                              */
/*  output uint8 Mf_gear_engaged_stability_count;                             */
/*  output boolean Gear_engaged_mf_not_stable;                                */
/*  output uint8 Gear_engaged_mf_last;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidGearNotStable(void)
{
   uint8 u8LocalGear_engaged;


   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   Mf_gear_engaged_stability_count = Mf_gear_engaged_stability_delay;
   VEMS_vidSET(Gear_engaged_mf_not_stable, 1);
   Gear_engaged_mf_last = u8LocalGear_engaged;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidGearStable                              */
/* !Description :  Lorsqu’on  est  stable,  on  attend  un  délai  avant  de  */
/*                 déclarer  la  stabilité  et  on  continue  de  réactualiser*/
/*                  la  variation de couple indiqué.                          */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidGearSetStab();                        */
/*  extf argret void MISFDIAGSTABCDN_vidGearWaitStab();                       */
/*  input uint8 Mf_gear_engaged_stability_count;                              */
/*  input boolean MISFDIAGSTABCDN_bGearEnStab_Prev;                           */
/*  output boolean MISFDIAGSTABCDN_bGearEnStab_Prev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidGearStable(void)
{
   if (Mf_gear_engaged_stability_count == 0)
   {
      if (MISFDIAGSTABCDN_bGearEnStab_Prev == 0)
      {
         MISFDIAGSTABCDN_vidGearSetStab();
      }
      else
      {
         MISFDIAGSTABCDN_vidGearWaitStab();
      }
      MISFDIAGSTABCDN_bGearEnStab_Prev = 1;
   }
   else
   {
      MISFDIAGSTABCDN_vidGearWaitStab();
      MISFDIAGSTABCDN_bGearEnStab_Prev = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidTorqNotStable                           */
/* !Description :  L’initialisation de la variation est effectuée dès que l’on*/
/*                 constate l’instabilité.                                    */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 Torque_deduction;                                            */
/*  input uint8 Mf_torq_deduction_stab_delay;                                 */
/*  output sint16 Torque_deduction_mf_min;                                    */
/*  output sint16 Torque_deduction_mf_max;                                    */
/*  output uint8 Mf_torq_deduction_stab_count;                                */
/*  output boolean Torque_deduction_mf_not_stable;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidTorqNotStable(void)
{
   Torque_deduction_mf_min = (sint16)MATHSRV_udtCLAMP( Torque_deduction,
                                                       -32000,
                                                       32000);
   Torque_deduction_mf_max = (sint16)MATHSRV_udtCLAMP( Torque_deduction,
                                                       -32000,
                                                        32000);
   Mf_torq_deduction_stab_count = Mf_torq_deduction_stab_delay;
   Torque_deduction_mf_not_stable = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidTorqStable                              */
/* !Description :  Lorsqu’on  est  stable,  on  attend  un  délai  avant  de  */
/*                 déclarer  la  stabilité  et  on  continue  de  réactualiser*/
/*                  la  variation de couple indiqué.                          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidTorqSetStab();                        */
/*  extf argret void MISFDIAGSTABCDN_vidTorqWaitStab();                       */
/*  input uint8 Mf_torq_deduction_stab_count;                                 */
/*  input boolean MISFDIAGSTABCDN_bTrqDedct_Prev;                             */
/*  input sint16 Torque_deduction;                                            */
/*  input sint16 Torque_deduction_mf_min;                                     */
/*  input sint16 Torque_deduction_mf_max;                                     */
/*  output boolean MISFDIAGSTABCDN_bTrqDedct_Prev;                            */
/*  output sint16 Torque_deduction_mf_min;                                    */
/*  output sint16 Torque_deduction_mf_max;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidTorqStable(void)
{
   sint16   s16LocalTorque_deduction_mf_min;
   sint16   s16LocalTorque_deduction_mf_max;


   if (Mf_torq_deduction_stab_count == 0)
   {
      if (MISFDIAGSTABCDN_bTrqDedct_Prev == 0)
      {
         MISFDIAGSTABCDN_vidTorqSetStab();
      }
      else
      {
         MISFDIAGSTABCDN_vidTorqWaitStab();
      }
      MISFDIAGSTABCDN_bTrqDedct_Prev = 1;
   }
   else
   {
      MISFDIAGSTABCDN_vidTorqWaitStab();
      MISFDIAGSTABCDN_bTrqDedct_Prev = 0;
   }

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
/* !Function    :  MISFDIAGSTABCDN_vidTimer                                   */
/* !Description :  la variation du couple  indiqué doit rester  inférieure à  */
/*                 un seuil pendant un certain  délai.                        */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Mf_engine_stable_t_d_c;                                       */
/*  output boolean Misf_bEngStabCdn;                                          */
/*  output uint8 Mf_engine_stable_t_d_c;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidTimer(void)
{
   Misf_bEngStabCdn = 0;
   if (Mf_engine_stable_t_d_c > 0)
   {
      Mf_engine_stable_t_d_c = (uint8)(Mf_engine_stable_t_d_c - 1);
   }
   else
   {
      Mf_engine_stable_t_d_c = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidTimerOut                                */
/* !Description :  Indicateur de validité des conditions de stabilités        */
/*                 spécifiques à la détection de misfires                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Misf_bEngStabCdn;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidTimerOut(void)
{
   Misf_bEngStabCdn = 1;
}
/*------------------------------- end of file --------------------------------*/