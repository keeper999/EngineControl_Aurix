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
/* !File            : MISFDIAGSTABCDN_FCT3.C                                  */
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
/*   1 / MISFDIAGSTABCDN_vidLoadSetStab                                       */
/*   2 / MISFDIAGSTABCDN_vidLoadWaitStab                                      */
/*   3 / MISFDIAGSTABCDN_vidGearSetStab                                       */
/*   4 / MISFDIAGSTABCDN_vidGearWaitStab                                      */
/*   5 / MISFDIAGSTABCDN_vidTorqSetStab                                       */
/*   6 / MISFDIAGSTABCDN_vidTorqWaitStab                                      */
/*   7 / MISFDIAGSTABCDN_vidMisfIgAdvClcn                                     */
/*   8 / MISFDIAGSTABCDN_vidMisfdvStabChk                                     */
/*   9 / MISFDIAGSTABCDN_vidIgnAdvNotStab                                     */
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
/* !Function    :  MISFDIAGSTABCDN_vidLoadSetStab                             */
/* !Description :  Lorsqu’on  est  stable, déclarer  la  stabilité.           */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Indicated_torque_mf_not_stable;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidLoadSetStab(void)
{
   Indicated_torque_mf_not_stable = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidLoadWaitStab                            */
/* !Description :  Lorsqu’on  est  stable,  on  attend  un  délai  avant  de  */
/*                 déclarer  la  stabilité                                    */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Mf_indicated_tor_stability_count;                             */
/*  output uint8 Mf_indicated_tor_stability_count;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidLoadWaitStab(void)
{
   if (Mf_indicated_tor_stability_count > 0)
   {
      Mf_indicated_tor_stability_count =
         (uint8)(Mf_indicated_tor_stability_count - 1);
   }
   else
   {
      Mf_indicated_tor_stability_count = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidGearSetStab                             */
/* !Description :  Lorsqu’on  est  stable, déclarer  la  stabilité.           */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Gear_engaged_mf_not_stable;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidGearSetStab(void)
{
   VEMS_vidSET(Gear_engaged_mf_not_stable, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidGearWaitStab                            */
/* !Description :  Lorsqu’on  est  stable,  on  attend  un  délai  avant  de  */
/*                 déclarer  la  stabilité                                    */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Mf_gear_engaged_stability_count;                              */
/*  output uint8 Mf_gear_engaged_stability_count;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidGearWaitStab(void)
{
   if (Mf_gear_engaged_stability_count > 0)
   {
      Mf_gear_engaged_stability_count =
         (uint8)(Mf_gear_engaged_stability_count - 1);
   }
   else
   {
      Mf_gear_engaged_stability_count = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidTorqSetStab                             */
/* !Description :  Lorsqu’on  est  stable, déclarer  la  stabilité.           */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Torque_deduction_mf_not_stable;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidTorqSetStab(void)
{
   Torque_deduction_mf_not_stable = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidTorqWaitStab                            */
/* !Description :  Lorsqu’on  est  stable,  on  attend  un  délai  avant  de  */
/*                 déclarer  la  stabilité                                    */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Mf_torq_deduction_stab_count;                                 */
/*  output uint8 Mf_torq_deduction_stab_count;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidTorqWaitStab(void)
{
   if (Mf_torq_deduction_stab_count > 0)
   {
      Mf_torq_deduction_stab_count = (uint8)(Mf_torq_deduction_stab_count - 1);
   }
   else
   {
      Mf_torq_deduction_stab_count = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidMisfIgAdvClcn                           */
/* !Description :  Calcul du saut d’avance à l’allumage à chaque événement    */
/*                 Misf_EveMisf_MisfDiagStabCdn                               */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IgSys_agIgSp;                                                 */
/*  input uint8 MISFDIAGSTABCDN_u8IgSyaIgSpPrev;                              */
/*  output uint8 Misf_agIgSpJmp;                                              */
/*  output uint8 MISFDIAGSTABCDN_u8IgSyaIgSpPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidMisfIgAdvClcn(void)
{
   uint8  u8LocalIgSysagIgSp;
   sint16 s16LocalMisfagIgSpJmp;


   VEMS_vidGET(IgSys_agIgSp, u8LocalIgSysagIgSp);
   s16LocalMisfagIgSpJmp =
      (sint16)(u8LocalIgSysagIgSp - MISFDIAGSTABCDN_u8IgSyaIgSpPrev);
   Misf_agIgSpJmp = (uint8)MATHSRV_udtABS(s16LocalMisfagIgSpJmp);
   MISFDIAGSTABCDN_u8IgSyaIgSpPrev = u8LocalIgSysagIgSp;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidMisfdvStabChk                           */
/* !Description :  Le saut d’avance est comparé à un seuil calibrable         */
/*                 Misf_agIgAdvStabLim_C pour la détection de la stabilité ou */
/*                 non du système                                             */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidIgnAdvNotStab();                      */
/*  extf argret void MISFDIAGSTABCDN_vidIgnAdvStable();                       */
/*  input boolean Misf_bEngStabCdn;                                           */
/*  input uint8 Misf_agIgSpJmp;                                               */
/*  input uint8 Misf_agIgAdvStabLim_C;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidMisfdvStabChk(void)
{
   if (Misf_bEngStabCdn != 0)
   {
      if (Misf_agIgSpJmp >= Misf_agIgAdvStabLim_C)
      {
         MISFDIAGSTABCDN_vidIgnAdvNotStab();
      }
      else
      {
         MISFDIAGSTABCDN_vidIgnAdvStable();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidIgnAdvNotStab                           */
/* !Description :  Le système est déclaré non stabe et un compteur            */
/*                 (Misf_ctIgAdvStab) est initialisé avec une valeur          */
/*                 permettant d’attendre avant de confirmer que le système est*/
/*                 redevenu stable                                            */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Misf_ctIgAdvStabLim_C;                                       */
/*  output boolean Mf_stability_conditions;                                   */
/*  output uint16 Misf_ctIgAdvStab;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidIgnAdvNotStab(void)
{
   VEMS_vidSET(Mf_stability_conditions, 0);
   Misf_ctIgAdvStab = Misf_ctIgAdvStabLim_C;
}

/*------------------------------- end of file --------------------------------*/