/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHSPDACQ                                               */
/* !Description     : VEHSPDACQ Component                                     */
/*                                                                            */
/* !Module          : VEHSPDACQ                                               */
/* !Description     : ACQUISITION DE LA VITESSE VEHICULE FILAIRE              */
/*                                                                            */
/* !File            : VEHSPDACQ_FCT2.C                                        */
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
/*   1 / VEHSPDACQ_vidSPDHALEna                                               */
/*   2 / VEHSPDACQ_vidSPDHALDis                                               */
/*   3 / VEHSPDACQ_vidSPDHALAcq                                               */
/*   4 / VEHSPDACQ_vidDateOvfMng                                              */
/*   5 / VEHSPDACQ_vidVehSpdComputation                                       */
/*   6 / VEHSPDACQ_vidVehSpdBuf                                               */
/*   7 / VEHSPDACQ_vidSpdComputation                                          */
/*   8 / VEHSPDACQ_vidAccelComputation                                        */
/*   9 / VEHSPDACQ_vidAccelMoyenCompt                                         */
/*   10 / VEHSPDACQ_vidCoveredDistance                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5455394 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VEHSPD/VEHSPDACQ/VEHSPDACQ_FCT2.$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   19 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "VEHSPDACQ.h"
#include "VEHSPDACQ_L.h"
#include "VEHSPDACQ_IM.h"
#include "SPDHAL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidSPDHALEna                                     */
/* !Description :  Activation du driver du capteur vitesse filaire.           */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPDHAL_vidEnable();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidSPDHALEna(void)
{
   SPDHAL_vidEnable();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidSPDHALDis                                     */
/* !Description :  Désactivation du driver du capteur vitesse filaire.        */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPDHAL_vidDisable();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidSPDHALDis(void)
{
   SPDHAL_vidDisable();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidSPDHALAcq                                     */
/* !Description :  Compteur et date correspondent à la dernière impulsion     */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPDHAL_vidGetPulseInformation(argout uint16              */
/*  *pu16PulseCounter, argout uint32 *pu32LastPulseDate);                     */
/*  input uint32 VehSpd_PlsDate;                                              */
/*  output uint32 VehSpd_PrevPlsDate;                                         */
/*  output uint32 VehSpd_PlsDate;                                             */
/*  output uint16 VehSpd_ctPls;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidSPDHALAcq(void)
{
   uint16 u16LocalPulseCounter;
   uint32 u32LocalLastPulseDate;


   VehSpd_PrevPlsDate = MATHSRV_udtMIN(VehSpd_PlsDate, SPDHAL_u32TIMER_PERIOD);
   SPDHAL_vidGetPulseInformation(&u16LocalPulseCounter,
                                 &u32LocalLastPulseDate);

   VehSpd_PlsDate = u32LocalLastPulseDate % SPDHAL_u32TIMER_PERIOD;
   VehSpd_ctPls = u16LocalPulseCounter;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidDateOvfMng                                    */
/* !Description :  Ce bloc permet le calcul de l’intervalle de temps entre    */
/*                 deux impulsions dans le cas où un Overflow serait survenu. */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 VehSpd_PrevPlsDate;                                          */
/*  input uint32 VehSpd_PlsDate;                                              */
/*  output uint16 Ext_VehSpdOvfPlsTiIntl;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidDateOvfMng(void)
{
   uint32 u32LocalPlsDate;
   uint32 u32LocalPrevPlsDate;


   /* To avoid pulse date overflow */
   u32LocalPrevPlsDate = VehSpd_PrevPlsDate % SPDHAL_u32TIMER_PERIOD;
   u32LocalPlsDate = SPDHAL_u32TIMER_PERIOD - u32LocalPrevPlsDate;
   u32LocalPlsDate = u32LocalPlsDate + VehSpd_PlsDate;
   u32LocalPlsDate = u32LocalPlsDate / 100;

   Ext_VehSpdOvfPlsTiIntl = (uint16)MATHSRV_udtMIN(u32LocalPlsDate, 65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidVehSpdComputation                             */
/* !Description :  Le premier bloc gère le traitement du Buffer et le second  */
/*                 le calcul de la vitesse.  Plus bas, on calcule la distance */
/*                 parcourue par le véhicule.                                 */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_09_06646_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidVehSpdBuf();                                */
/*  extf argret void VEHSPDACQ_vidSpdComputation();                           */
/*  extf argret void VEHSPDACQ_vidAccelComputation();                         */
/*  extf argret void VEHSPDACQ_vidAccelMoyenCompt();                          */
/*  extf argret void VEHSPDACQ_vidCoveredDistance();                          */
/*  input uint16 Ext_VehSpdPlsTiIntl;                                         */
/*  output boolean VehSpd_bInfoAvl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidVehSpdComputation(void)
{
   if (Ext_VehSpdPlsTiIntl != 0)
   {
      VehSpd_bInfoAvl = 1;

      /*01_VehSpdBuf*/
      VEHSPDACQ_vidVehSpdBuf();

      /*02_SpdComputation*/
      VEHSPDACQ_vidSpdComputation();

      /*03_AccelComputation*/
      VEHSPDACQ_vidAccelComputation();
      /*04_AccelMoyenCompt*/
      VEHSPDACQ_vidAccelMoyenCompt();
      /*05_Distance_parcourue*/
      VEHSPDACQ_vidCoveredDistance();
   }
   else
   {
      VehSpd_bInfoAvl = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidVehSpdBuf                                     */
/* !Description :  Ce bloc effectue la gestion du Buffer.                     */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Ext_VehSpdBuf;                                                */
/*  output uint8 Ext_VehSpdBuf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidVehSpdBuf(void)
{

   if (Ext_VehSpdBuf < VehSpd_noPlsCalcMean_SC)
   {
      Ext_VehSpdBuf = (uint8)(Ext_VehSpdBuf + 1);
   }
   else
   {
      Ext_VehSpdBuf = VehSpd_noPlsCalcMean_SC;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidSpdComputation                                */
/* !Description :  Ici, on réalise le calcul de la vitesse en réalisant un    */
/*                 filtrage dynamique. Lorsque le Buffer est réinitialisé, par*/
/*                 exemple après un reset, le calcul de la vitesse ne peut se */
/*                 faire que lorsqu’on a reçu au moins deux impulsions ;      */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidDynFil();                                   */
/*  input uint16 Ext_MeanSpdVehRaw;                                           */
/*  input uint16 VehSpd_facFilterGain_C;                                      */
/*  input uint32 VEHSPDACQ_u32FirstOrderFilterMem;                            */
/*  output uint16 Vitesse_vehicule_fil_preciseAcq;                            */
/*  output uint16 Ext_spdVehRawAcq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidSpdComputation(void)
{
   VEHSPDACQ_vidDynFil();

   Vitesse_vehicule_fil_preciseAcq = Ext_MeanSpdVehRaw;
   Ext_spdVehRawAcq =
      MATHSRV_u16FirstOrderFilterGu16(VehSpd_facFilterGain_C,
                                      &VEHSPDACQ_u32FirstOrderFilterMem,
                                      Ext_MeanSpdVehRaw);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidAccelComputation                              */
/* !Description :  Le calcul de l’accélération est obtenu en faisant le       */
/*                 rapport entre la différence de vitesse entre deux          */
/*                 impulsions et le temps écoulé entre ces deux impulsions.   */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_spdVehRawAcq;                                            */
/*  input uint16 Ext_spdVehRawAcqPrev;                                        */
/*  input uint16 Ext_VehSpdPlsTiIntl;                                         */
/*  output uint8 Acceleration_filaireRaw;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidAccelComputation(void)
{
   sint32  s32LocalSpdVar;
   sint32  s32LocalAccel;
   uint32  u32LocalAccel;
   uint32  u32LocalPlsTiIntl;
   uint32  u32LocalModAc;


   s32LocalSpdVar = (sint32)(Ext_spdVehRawAcq - Ext_spdVehRawAcqPrev);
   u32LocalPlsTiIntl = Ext_VehSpdPlsTiIntl * 288;

   if (u32LocalPlsTiIntl != 0)
   {
      if (s32LocalSpdVar < 0)
      {
         u32LocalAccel = (uint32)(-s32LocalSpdVar);
         if ((uint32)(-s32LocalSpdVar) <= (UINT32_MAX / (uint32)390625))
         {
            u32LocalAccel = u32LocalAccel * 390625;
            u32LocalAccel = ( ( u32LocalAccel
                              + ( u32LocalPlsTiIntl
                                / 2))
                            / u32LocalPlsTiIntl);
            s32LocalAccel = MATHSRV_s32Add_u32_s32(u32LocalAccel, -175);
            s32LocalAccel = -s32LocalAccel;
         }
         else
         {
            u32LocalModAc = u32LocalAccel % u32LocalPlsTiIntl;
            u32LocalAccel = u32LocalAccel / u32LocalPlsTiIntl;
            u32LocalAccel = u32LocalAccel * 390625;
            if (u32LocalModAc <= (UINT32_MAX / (uint32)390625))
            {
               u32LocalModAc = u32LocalModAc * 390625;
               u32LocalModAc = u32LocalModAc / u32LocalPlsTiIntl;
            }
            else
            {
               u32LocalModAc = ( u32LocalModAc
                               + ( u32LocalPlsTiIntl
                                 / 2));

               u32LocalModAc = u32LocalModAc * 5;
               u32LocalModAc = u32LocalModAc / u32LocalPlsTiIntl;
               u32LocalModAc = u32LocalModAc * 78125;
            }
            u32LocalAccel = u32LocalAccel + u32LocalModAc;
            s32LocalAccel = MATHSRV_s32Add_u32_s32(u32LocalAccel, -175);
            s32LocalAccel = -s32LocalAccel;
         }
      }
      else
      {
         u32LocalAccel = (uint32)(s32LocalSpdVar);
         if ((uint32)(s32LocalSpdVar) <= (UINT32_MAX / (uint32)390625))
         {
            u32LocalAccel = u32LocalAccel * 390625;
            u32LocalAccel = ( ( u32LocalAccel
                              + ( u32LocalPlsTiIntl
                                / 2))
                            / u32LocalPlsTiIntl);
            s32LocalAccel = MATHSRV_s32Add_u32_s32(u32LocalAccel, 175);
         }
         else
         {
            u32LocalModAc = u32LocalAccel % u32LocalPlsTiIntl;
            u32LocalAccel = u32LocalAccel / u32LocalPlsTiIntl;
            u32LocalAccel = u32LocalAccel * 390625;
            if (u32LocalModAc <= (UINT32_MAX / (uint32)390625))
            {
               u32LocalModAc = u32LocalModAc * 390625;
               u32LocalModAc = u32LocalModAc / u32LocalPlsTiIntl;
            }
            else
            {
               u32LocalModAc = ( u32LocalModAc
                               + ( u32LocalPlsTiIntl
                                 / 2));

               u32LocalModAc = u32LocalModAc * 5;
               u32LocalModAc = u32LocalModAc / u32LocalPlsTiIntl;
               u32LocalModAc = u32LocalModAc * 78125;
            }
            u32LocalAccel = u32LocalAccel + u32LocalModAc;
            s32LocalAccel = MATHSRV_s32Add_u32_s32(u32LocalAccel, 175);
         }
      }
   }
   else
   {
      if (s32LocalSpdVar != 0)
      {
         if (s32LocalSpdVar < 0)
         {
            s32LocalAccel = 0;
         }
         else
         {
            s32LocalAccel = 255;
         }
      }
      else
      {
         s32LocalAccel = 175;
      }
   }
   Acceleration_filaireRaw = (uint8)MATHSRV_udtCLAMP(s32LocalAccel, 0, 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidAccelMoyenCompt                               */
/* !Description :  elle permet le calcul de l’accélération en faisant le      */
/*                 rapport entre la différence de vitesse entre deux          */
/*                 impulsions et le temps écoulé entre ces deux impulsions    */
/*                 puis la  moyenne des huit dernières valeurs obtenues       */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 AccMoyen_index;                                               */
/*  input uint8 VehSpd_AccMoyIndex_C;                                         */
/*  input uint8 AccMoyen_index;                                               */
/*  input uint8 Ext_AccBuf;                                                   */
/*  input boolean VehSpd_bInfoAvl;                                            */
/*  input boolean VEHSPDACQ_bFilterAnRebond;                                  */
/*  input uint16 Acc_AntiRebond_Down_C;                                       */
/*  input uint16 VEHSPDACQ_u16CounterAntiRebond;                              */
/*  input uint8 Acceleration_filaireRaw;                                      */
/*  input uint8 VEHSPDACQ_au8AccelfilaireRaw[8];                              */
/*  input uint16 VehSpd_facAccelFilGain_C;                                    */
/*  input uint32 VEHSPDACQ_u32AccelFiltredMem;                                */
/*  input uint8 VEHSPDACQ_u8InputFilter;                                      */
/*  output uint8 AccMoyen_index;                                              */
/*  output uint8 Ext_AccBuf;                                                  */
/*  output uint16 VEHSPDACQ_u16CounterAntiRebond;                             */
/*  output boolean VEHSPDACQ_bFilterAnRebond;                                 */
/*  output uint8 VEHSPDACQ_au8AccelfilaireRaw[8];                             */
/*  output uint8 VEHSPDACQ_u8InputFilter;                                     */
/*  output uint8 Acceleration_filaireAcq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidAccelMoyenCompt(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalAccMoyen_index;
   uint16 u16LocalAccelfilaireRaw;
   uint16 u16LocalThd;
   uint16 u16LocalExt_AccBuf;
   uint16 u16LocalAccMoyen_index;


   u16LocalAccelfilaireRaw = 0;

   if (VehSpd_AccMoyIndex_C == 0)
   {
      u16LocalAccMoyen_index = 8;
   }
   else
   {
      u16LocalAccMoyen_index = (uint16)(AccMoyen_index + 1);
      u16LocalAccMoyen_index = (uint16)(u16LocalAccMoyen_index
                                       % VehSpd_AccMoyIndex_C);
   }
   AccMoyen_index = (uint8)MATHSRV_udtMIN(u16LocalAccMoyen_index, 8);
   u8LocalAccMoyen_index = (uint8)MATHSRV_udtMIN(u16LocalAccMoyen_index, 7);

   u16LocalExt_AccBuf = (uint16)(Ext_AccBuf + 1);
   u16LocalExt_AccBuf = (uint16)MATHSRV_udtMIN(u16LocalExt_AccBuf,
                                               VehSpd_AccMoyIndex_C);
   Ext_AccBuf = (uint8) MATHSRV_udtMIN(u16LocalExt_AccBuf,
                                       8);

   if (VehSpd_bInfoAvl != VEHSPDACQ_bFilterAnRebond)
   {
      if (VehSpd_bInfoAvl == 0)
      {
         u16LocalThd = Acc_AntiRebond_Down_C;
      }
      else
      {
         u16LocalThd = 0;
      }

      if (VEHSPDACQ_u16CounterAntiRebond < 65535)
      {
         VEHSPDACQ_u16CounterAntiRebond =
            (uint16)(VEHSPDACQ_u16CounterAntiRebond + 1);
      }

      if (VEHSPDACQ_u16CounterAntiRebond >= u16LocalThd)
      {
         VEHSPDACQ_bFilterAnRebond = VehSpd_bInfoAvl;
         VEHSPDACQ_u16CounterAntiRebond = 0;
      }
   }
   else
   {
      VEHSPDACQ_u16CounterAntiRebond = 0;
   }

   if (VEHSPDACQ_bFilterAnRebond != 0)
   {
      VEHSPDACQ_au8AccelfilaireRaw[u8LocalAccMoyen_index] =
         Acceleration_filaireRaw;
   }
   else
   {
      VEHSPDACQ_au8AccelfilaireRaw[u8LocalAccMoyen_index] = 175;
   }

   for(u8LocalIndex = 0; u8LocalIndex < Ext_AccBuf; u8LocalIndex++)
   {
      u16LocalAccelfilaireRaw =
         (uint16)( u16LocalAccelfilaireRaw
                 + VEHSPDACQ_au8AccelfilaireRaw[u8LocalIndex]);
   }

   if (Ext_AccBuf != 0)
   {
      VEHSPDACQ_u8InputFilter = (uint8)( u16LocalAccelfilaireRaw
                                       / Ext_AccBuf) ;
   }
   else
   {
      VEHSPDACQ_u8InputFilter = 175;
   }

   Acceleration_filaireAcq =
         (uint8)MATHSRV_u16FirstOrderFilterGu16(VehSpd_facAccelFilGain_C,
                                                &VEHSPDACQ_u32AccelFiltredMem,
                                               (uint16)VEHSPDACQ_u8InputFilter);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidCoveredDistance                               */
/* !Description :  Le calcul de la distance parcourue est fait en additionnant*/
/*                 à la valeur précédente la distance parcourue depuis la     */
/*                 dernière impulsion vue.                                    */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Distance_fil_precise;                                        */
/*  input uint16 VehSpd_dstIntlPls_C;                                         */
/*  input uint16 Ext_spdVehRawAcq;                                            */
/*  output uint32 Distance_fil_precise;                                       */
/*  output uint16 Distance_parcourue_fil;                                     */
/*  output uint16 Ext_spdVehRawAcqPrev;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidCoveredDistance(void)
{
   uint16 u16LocalDistance_parcourue_fil;
   uint32 u32LocalDistWireCm;


   u32LocalDistWireCm = (Distance_fil_precise + (uint32)VehSpd_dstIntlPls_C);
   u32LocalDistWireCm = (u32LocalDistWireCm % Dist_fil_sat_SC);

   Distance_fil_precise = u32LocalDistWireCm;

   u16LocalDistance_parcourue_fil = (uint16)(u32LocalDistWireCm / 1000);
   VEMS_vidSET(Distance_parcourue_fil, u16LocalDistance_parcourue_fil);
   Ext_spdVehRawAcqPrev = Ext_spdVehRawAcq;
}
/*--------------------------------end of file---------------------------------*/