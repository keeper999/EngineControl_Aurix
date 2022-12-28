/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPMNGMODSECU                                          */
/* !Description     : ACCPMNGMODSECU Component.                               */
/*                                                                            */
/* !Module          : ACCPMNGMODSECU                                          */
/* !Description     : Security modes management for the gas pedal             */
/*                                                                            */
/* !File            : ACCPMNGMODSECU_FCT1.C                                   */
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
/*   1 / ACCPMNGMODSECU_vidInit                                               */
/*   2 / ACCPMNGMODSECU_vidInitOutput                                         */
/*   3 / ACCPMNGMODSECU_vidComputeAccPMng                                     */
/*   4 / ACCPMNGMODSECU_vidPedalPosInCalc                                     */
/*   5 / ACCPMNGMODSECU_vidMngPosSecu                                         */
/*   6 / ACCPMNGMODSECU_vidPedalPosfilter                                     */
/*   7 / ACCPMNGMODSECU_vidStuckPedalPos                                      */
/*   8 / ACCPMNGMODSECU_vidStateTransit                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_7317422 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#069330                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/REF/modules/ACCPMNGMODSECU/ACCPMNGMODSECU_F$*/
/* $Revision::   1.0      $$Author::   achebino       $$Date::   03 Oct 2014 $*/
/* $Author::   achebino                               $$Date::   03 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACCPMNGMODSECU.h"
#include "ACCPMNGMODSECU_L.h"
#include "ACCPMNGMODSECU_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPMNGMODSECU_vidInit                                     */
/* !Description :  All the secured pedal positions are set to 0 at the ECU    */
/*                 reset.The secured pedal state is considered as nominal     */
/*                 mode.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 AccP_rAccP;                                                 */
/*  output uint16 AccP_rAccPFctMon;                                           */
/*  output uint16 Ssm_precise_pedal_position;                                 */
/*  output st99 AccP_stAccPSec;                                               */
/*  output st100 AccP_stAccPVld;                                              */
/*  output sint32 AccP_rGrdAccP;                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPMNGMODSECU_vidInit(void)
{
   /*F01_Init*/
   VEMS_vidSET(AccP_rAccP, 0);
   VEMS_vidSET(AccP_rAccPFctMon, 0);
   VEMS_vidSET(Ssm_precise_pedal_position, 0);
   VEMS_vidSET(AccP_stAccPSec, AccP_stNomMode_SC);
   VEMS_vidSET(AccP_stAccPVld, AccP_stVldNomMode_SC);
   VEMS_vidSET(AccP_rGrdAccP, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPMNGMODSECU_vidInitOutput                               */
/* !Description :  Initialisation des variables de sorties.                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AccP_rAccPSens1;                                             */
/*  input uint16 AccP_rAccPSens2;                                             */
/*  input uint16 AccP_rAccPSens1Prev;                                         */
/*  input uint16 AccP_rAccPSens2Prev;                                         */
/*  output uint16 ACCPMNGMODSECU_u16AccPRawFilter;                            */
/*  output uint16 AccP_rAccPPrev;                                             */
/*  output uint16 AccP_rAccPSens1Prev;                                        */
/*  output uint16 AccP_rAccPSens2Prev;                                        */
/*  output uint16 AccP_rAccPRaw;                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPMNGMODSECU_vidInitOutput(void)
{
   uint16 u16LocalAccP_rAccPSens1;
   uint16 u16LocalAccP_rAccPSens2;
   uint16 u16LocalMin;


   ACCPMNGMODSECU_u16AccPRawFilter = 0;
   AccP_rAccPPrev = 0;

   VEMS_vidGET(AccP_rAccPSens1, u16LocalAccP_rAccPSens1);
   VEMS_vidGET(AccP_rAccPSens2, u16LocalAccP_rAccPSens2);
   AccP_rAccPSens1Prev =
      (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccPSens1, 1024);
   AccP_rAccPSens2Prev =
      (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccPSens2, 1024);

   u16LocalMin = (uint16)MATHSRV_udtMIN(AccP_rAccPSens1Prev,
                                        AccP_rAccPSens2Prev);
   AccP_rAccPRaw = (uint16)(((u16LocalMin * 25) + 1) / 2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPMNGMODSECU_vidComputeAccPMng                           */
/* !Description :  This function determines the calculation of the position of*/
/*                 the accelerator pedal with the request of the driver.      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPMNGMODSECU_vidPedalPosInCalc();                      */
/*  extf argret void ACCPMNGMODSECU_vidMngPosSecu();                          */
/*  extf argret void ACCPMNGMODSECU_vidPedalPosfilter();                      */
/*  extf argret void ACCPMNGMODSECU_vidStuckPedalPos();                       */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AccP_rAccPSens1;                                             */
/*  input uint16 AccP_rAccPSens2;                                             */
/*  output uint16 AccP_rAccPSens1Prev;                                        */
/*  output uint16 AccP_rAccPSens2Prev;                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPMNGMODSECU_vidComputeAccPMng(void)
{
   /*F02_Compute_AccPMng*/
   uint16 u16LocalAccP_rAccPSens1;
   uint16 u16LocalAccP_rAccPSens2;


   ACCPMNGMODSECU_vidPedalPosInCalc();
   ACCPMNGMODSECU_vidMngPosSecu();
   ACCPMNGMODSECU_vidPedalPosfilter();
   ACCPMNGMODSECU_vidStuckPedalPos();

   VEMS_vidGET(AccP_rAccPSens1, u16LocalAccP_rAccPSens1);
   VEMS_vidGET(AccP_rAccPSens2, u16LocalAccP_rAccPSens2);

   AccP_rAccPSens1Prev =
      (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccPSens1, 1024);
   AccP_rAccPSens2Prev =
      (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccPSens2, 1024);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPMNGMODSECU_vidPedalPosInCalc                           */
/* !Description :  Some intermediary variables are calculated:                */
/*                 AccP_bPsenPctlEl, AccP_bPsenNoDftEl, AccP_bPsenOneDftEl    */
/*                 ,AccP_bPsenNoBoothDftEl, AccP_bCohPctl, AccP_bCohPSenPctl. */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean AccP_bCohPctl;                                              */
/*  input boolean AccP_bPsenPctlEl;                                           */
/*  output boolean AccP_bPsenPctlEl;                                          */
/*  output boolean AccP_bPsenNoDftEl;                                         */
/*  output boolean AccP_bPsenOneDftEl;                                        */
/*  output boolean AccP_bPsenNoBoothDftEl;                                    */
/*  output boolean AccP_bCohPctl;                                             */
/*  output boolean AccP_bCohPSenPctl;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPMNGMODSECU_vidPedalPosInCalc(void)
{
   /*F01_Pedal_position_input_calc*/
   boolean            bLocalAccPSen1;
   boolean            bLocalAccPSen2;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped1;
   GDFRM_tenuGDUState LocalstDgoScg_Ped1;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped2;
   GDFRM_tenuGDUState LocalstDgoScg_Ped2;
   GDFRM_tenuGDUState LocalstDgoCoh_Ped;


   LocalstDgoScpOc_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED1);
   LocalstDgoScg_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED1);
   LocalstDgoScpOc_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED2);
   LocalstDgoScg_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED2);

   if (  (LocalstDgoScpOc_Ped1 == GDU_ETAT_PCTL_ABSENT)
      || (LocalstDgoScpOc_Ped1 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScg_Ped1 == GDU_ETAT_PCTL_ABSENT)
      || (LocalstDgoScg_Ped1 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScpOc_Ped2 == GDU_ETAT_PCTL_ABSENT)
      || (LocalstDgoScpOc_Ped2 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScg_Ped2 == GDU_ETAT_PCTL_ABSENT)
      || (LocalstDgoScg_Ped2 == GDU_ETAT_PCTL_PRESENT))
   {
      AccP_bPsenPctlEl = 1;
   }
   else
   {
      AccP_bPsenPctlEl = 0;
   }

   if (  (LocalstDgoScpOc_Ped1 == GDU_ETAT_ABSENT)
      && (LocalstDgoScg_Ped1 == GDU_ETAT_ABSENT)
      && (LocalstDgoScpOc_Ped2 == GDU_ETAT_ABSENT)
      && (LocalstDgoScg_Ped2 == GDU_ETAT_ABSENT))
   {
      AccP_bPsenNoDftEl = 1;
   }
   else
   {
      AccP_bPsenNoDftEl = 0;
   }

   bLocalAccPSen1 = GDGAR_bGetFRM(FRM_FRM_ACCPSEN1);
   bLocalAccPSen2 = GDGAR_bGetFRM(FRM_FRM_ACCPSEN2);

   /***OU bit-à-bit exclusif: Retourne 1 si l'un des
    deux bits de même poids est à 1 (mais pas les deux)***/
   AccP_bPsenOneDftEl = (boolean)(bLocalAccPSen1 ^ bLocalAccPSen2);

   if (  (bLocalAccPSen1 == 0)
      || (bLocalAccPSen2 == 0))
   {
      AccP_bPsenNoBoothDftEl = 1;
   }
   else
   {
      AccP_bPsenNoBoothDftEl = 0;
   }

   LocalstDgoCoh_Ped = GDGAR_tenuGetStDgo(GD_DFT_COH_PED);
   if (  (LocalstDgoCoh_Ped == GDU_ETAT_PCTL_ABSENT)
      || (LocalstDgoCoh_Ped == GDU_ETAT_PCTL_PRESENT))
   {
      AccP_bCohPctl = 1;
   }
   else
   {
      AccP_bCohPctl = 0;
   }
   AccP_bCohPSenPctl = (boolean)(AccP_bCohPctl ^ AccP_bPsenPctlEl);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPMNGMODSECU_vidMngPosSecu                               */
/* !Description :  For the secured gas pedal position, there are 8 modes. The */
/*                 transitions between all these modes depend on the failures */
/*                 on the gas pedal (coherency failure, stuck failure,        */
/*                 electrical failures).                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPMNGMODSECU_vidStateTransit();                        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st99 AccP_stAccPSec;                                                */
/*  input uint16 AccP_rAccPSens1Prev;                                         */
/*  input uint16 AccP_rAccPSens2Prev;                                         */
/*  output st99 AccP_stAccPSec;                                               */
/*  output st100 AccP_stAccPVld;                                              */
/*  output uint16 AccP_rAccPRaw;                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPMNGMODSECU_vidMngPosSecu(void)
{
   /*F02_MngPosSecu*/
   uint8   u8LocalAccP_stAccPSec;
   uint16  u16LocalMin;
   uint32  u32LocalCalAccPRaw;


   VEMS_vidGET(AccP_stAccPSec, u8LocalAccP_stAccPSec);
   switch (u8LocalAccP_stAccPSec)
   {
      case AccP_stNomMode_SC:
      case AccP_stNomDegMode_SC:
      case AccP_stStuckMode_SC:
      case AccP_stSubstMode_SC:
      case AccP_stDegSen1Mode_SC:
      case AccP_stDegSen2Mode_SC:
      case AccP_stDegPctlMode_SC:
      case AccP_stDegMode_SC:
      /*Warning QAC: The QAC indentation check of a switch-cases bloc is not
      those used by VEMS presenting rules.*/
         ACCPMNGMODSECU_vidStateTransit();
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(AccP_stAccPSec, AccP_stNomMode_SC);
         VEMS_vidSET(AccP_stAccPVld, AccP_stVldNomMode_SC);
         u16LocalMin =
            (uint16)MATHSRV_udtMIN(AccP_rAccPSens1Prev, AccP_rAccPSens2Prev);
         u32LocalCalAccPRaw =  (((u16LocalMin * 25) + 1) / 2);
         AccP_rAccPRaw = (uint16)MATHSRV_udtMIN(u32LocalCalAccPRaw, 12800);
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPMNGMODSECU_vidPedalPosfilter                           */
/* !Description :  In order to ensure the continuity of the gas pedal         */
/*                 position, a slew rate is applied.  AccP_rGrdAccP represents*/
/*                 the gradient of the pedal position.                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ACCPMNGMODSECU_u16AccPRawFilter;                             */
/*  input uint16 AccP_rAccPRaw;                                               */
/*  input uint16 AccP_rAccPRampFault_C;                                       */
/*  input st100 AccP_stAccPVld;                                               */
/*  input boolean Ext_bBrkPedPrss;                                            */
/*  input uint16 AccP_rAccPPrev;                                              */
/*  input boolean AccP_bPsenNoDftEl;                                          */
/*  input uint16 AccP_rAccPSens1Prev;                                         */
/*  input uint16 AccP_rAccPSens2Prev;                                         */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint16 AccP_rAccPMaxInc_C;                                          */
/*  input uint16 AccP_rAccPMaxDec_C;                                          */
/*  output uint16 ACCPMNGMODSECU_u16AccPRawFilter;                            */
/*  output uint16 AccP_rAccP;                                                 */
/*  output sint32 AccP_rGrdAccP;                                              */
/*  output uint16 AccP_rAccPPrev;                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPMNGMODSECU_vidPedalPosfilter(void)
{
   /*F03_Pedal_position_filtering*/
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped1;
   GDFRM_tenuGDUState LocalstDgoScg_Ped1;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped2;
   GDFRM_tenuGDUState LocalstDgoScg_Ped2;
   uint8              u8LocalDemisomme;
   uint8              u8LocalAccP_stAccPVld;
   uint8              u8LocalExt_bBrkPedPrss;
   uint16             u16LocalSlewFilterDec;
   uint16             u16LocalRateLimOut;
   uint16             u16LocalRateLimIn;
   uint16             u16LocalMinimum;
   uint16             u16LocalSlewFilterInc;
   uint16             u16LocalAccP_rAccP;
   uint32             u32LocalMinimum;
   uint32             u32LocalSlewFilterInc;
   uint32             u32LocalSlewFilterDec;
   sint32             s32LocalResult;


   LocalstDgoScpOc_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED1);
   LocalstDgoScg_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED1);
   LocalstDgoScpOc_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED2);
   LocalstDgoScg_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED2);

   /*** Begin Bloc Slew_rate1Slew_rate1 ***/
   u16LocalRateLimOut =
      MATHSRV_u16SlewFilter(ACCPMNGMODSECU_u16AccPRawFilter,
                            AccP_rAccPRaw,
                            AccP_rAccPRampFault_C,
                            AccP_rAccPRampFault_C);
   ACCPMNGMODSECU_u16AccPRawFilter =
      (uint16)MATHSRV_udtMIN(u16LocalRateLimOut, 12800);
   /*** End Bloc Slew_rate1 ***/

   VEMS_vidGET(AccP_stAccPVld, u8LocalAccP_stAccPVld);
   VEMS_vidGET(Ext_bBrkPedPrss, u8LocalExt_bBrkPedPrss);

   if (u8LocalAccP_stAccPVld == AccP_stVldDegMode_SC)
   {
      if (u8LocalExt_bBrkPedPrss != 0)
      {
         s32LocalResult = AccP_rAccPPrev - AccP_rAccPRampFault_C;
         u16LocalRateLimIn = (uint16)MATHSRV_udtMAX(s32LocalResult, 0);
      }
      else
      {
         u16LocalRateLimIn = ACCPMNGMODSECU_u16AccPRawFilter;
      }
   }
   else
   {
      if (  (u8LocalAccP_stAccPVld != AccP_stVldStuckMode_SC)
         && (u8LocalAccP_stAccPVld != AccP_stVldSubstMode_SC))
      {
         u16LocalRateLimIn = AccP_rAccPRaw;
      }
      else
      {
         if (AccP_bPsenNoDftEl != 0)
         {
            u16LocalMinimum = (uint16)MATHSRV_udtMIN(AccP_rAccPSens1Prev,
                                                     AccP_rAccPSens2Prev);
            u32LocalMinimum = ((u16LocalMinimum * 25) + 1) / 2;
            u16LocalRateLimIn =
               (uint16)MATHSRV_udtMIN(u32LocalMinimum, AccP_rAccPRaw);
         }
         else
         {
            if (  (LocalstDgoScpOc_Ped1 == GDU_ETAT_ABSENT)
               && (LocalstDgoScg_Ped1 == GDU_ETAT_ABSENT))
            {
               u32LocalMinimum = ((AccP_rAccPSens1Prev * 25) + 1) / 2;
               u16LocalRateLimIn =
                  (uint16)MATHSRV_udtMIN(u32LocalMinimum, AccP_rAccPRaw);
            }
            else
            {
               if (  (LocalstDgoScpOc_Ped2 == GDU_ETAT_ABSENT)
                  && (LocalstDgoScg_Ped2 == GDU_ETAT_ABSENT))
               {
                  u32LocalMinimum = ((AccP_rAccPSens2Prev * 25) + 1) / 2;
                  u16LocalRateLimIn =
                     (uint16)MATHSRV_udtMIN(u32LocalMinimum, AccP_rAccPRaw);
               }
               else
               {
                  u16LocalRateLimIn = AccP_rAccPRaw;
               }
            }
         }
      }
   }

   /*** Begin Bloc Slew_rate ***/
   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   u32LocalSlewFilterInc = (((uint32)((AccP_rAccPMaxInc_C * 64) + 2)) / 5);
   u16LocalSlewFilterInc = (uint16)MATHSRV_udtMIN(u32LocalSlewFilterInc, 65535);

   u32LocalSlewFilterDec = (((uint32)((AccP_rAccPMaxDec_C * 64) + 2)) / 5);
   u16LocalSlewFilterDec = (uint16)MATHSRV_udtMIN(u32LocalSlewFilterDec, 65535);

   u16LocalRateLimOut = MATHSRV_u16SlewFilter(u16LocalAccP_rAccP,
                                              u16LocalRateLimIn,
                                              u16LocalSlewFilterInc,
                                              u16LocalSlewFilterDec);
   u16LocalAccP_rAccP = (uint16)MATHSRV_udtMIN(u16LocalRateLimOut, 12800);
   VEMS_vidSET(AccP_rAccP, u16LocalAccP_rAccP);
   /*** End Bloc Slew_rate ***/

   s32LocalResult = u16LocalRateLimOut - AccP_rAccPPrev;
   u8LocalDemisomme = (uint8)(2 * AccP_SampleTiFast_SC);
   if (s32LocalResult > 0)
   {
      s32LocalResult =
         ((s32LocalResult * 3125) + u8LocalDemisomme) / (2 * u8LocalDemisomme);
   }
   else
   {
      s32LocalResult =
         ((s32LocalResult * 3125) - u8LocalDemisomme) / (2 * u8LocalDemisomme);
   }
   s32LocalResult = MATHSRV_udtCLAMP(s32LocalResult, -1000000, 1000000);
   VEMS_vidSET(AccP_rGrdAccP, s32LocalResult);

   AccP_rAccPPrev = u16LocalAccP_rAccP;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPMNGMODSECU_vidStuckPedalPos                            */
/* !Description :  Depending  on  the  failures  on  the  gas  pedal  the     */
/*                 pedal  position  used  for  the  stuck  pedal  diagnosis   */
/*                 (AccP_rAccPFctMon) can take several values.                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AccP_rAccPFctMon;                                            */
/*  input boolean AccP_bAccPCohDegMod_C;                                      */
/*  input uint16 AccP_rAccPSens1Prev;                                         */
/*  input uint16 AccP_rAccPSens2Prev;                                         */
/*  input uint16 AccP_rAccPFctMonPrev;                                        */
/*  input boolean AccP_bCohPctl;                                              */
/*  output uint16 AccP_rAccPFctMonPrev;                                       */
/*  output uint16 AccP_rAccPFctMon;                                           */
/*  output uint16 Ssm_precise_pedal_position;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPMNGMODSECU_vidStuckPedalPos(void)
{
   /*F04_Stuck_Pedal_position*/
   boolean            bLocalCohAccPSen;
   boolean            bLocalAccPSen1;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped1;
   GDFRM_tenuGDUState LocalstDgoScg_Ped1;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped2;
   GDFRM_tenuGDUState LocalstDgoScg_Ped2;
   uint16             u16LocalAccP_rAcc;
   uint16             u16LocalSsm_precise_pedal;
   uint32             u32Localswitcher;
   uint32             u32LocalAccP_rAcc;


   VEMS_vidGET(AccP_rAccPFctMon, u16LocalAccP_rAcc);
   AccP_rAccPFctMonPrev = (uint16)MATHSRV_udtMIN(u16LocalAccP_rAcc, 10000);

   bLocalCohAccPSen = GDGAR_bGetFRM(FRM_FRM_COHACCPSEN);
   bLocalAccPSen1 = GDGAR_bGetFRM(FRM_FRM_ACCPSEN1);
   LocalstDgoScpOc_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED1);
   LocalstDgoScg_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED1);
   LocalstDgoScpOc_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED2);
   LocalstDgoScg_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED2);

   /*** la résolution à la sortie du switcher est 100/1024 % ***/
   if (  (bLocalCohAccPSen != 0)
      && (AccP_bAccPCohDegMod_C != 0))
   {
      u32Localswitcher =
         (uint32)MATHSRV_udtMIN(AccP_rAccPSens1Prev, AccP_rAccPSens2Prev);
   }
   else
   {
      if (  ( (bLocalCohAccPSen != 0)
            && (AccP_bAccPCohDegMod_C == 0))
         || ( (  (LocalstDgoScpOc_Ped1 != GDU_ETAT_ABSENT)
              || (LocalstDgoScg_Ped1 != GDU_ETAT_ABSENT))
            && (  (LocalstDgoScpOc_Ped2 != GDU_ETAT_ABSENT)
               || (LocalstDgoScg_Ped2 != GDU_ETAT_ABSENT))))
      {
         u32Localswitcher = ((AccP_rAccPFctMonPrev * 64) + 312) / 625;
      }
      else
      {
         if (AccP_bCohPctl != 0)
         {
            u32Localswitcher = ((AccP_rAccPFctMonPrev * 64) + 312) / 625;
         }
         else
         {
            if (  (LocalstDgoScpOc_Ped1 == GDU_ETAT_ABSENT)
               && (LocalstDgoScg_Ped1 == GDU_ETAT_ABSENT))
            {
               u32Localswitcher = AccP_rAccPSens1Prev;
            }
            else
            {
               if (  (LocalstDgoScpOc_Ped1 == GDU_ETAT_PCTL_ABSENT)
                  || (LocalstDgoScpOc_Ped1 == GDU_ETAT_PCTL_PRESENT)
                  || (LocalstDgoScg_Ped1 == GDU_ETAT_PCTL_PRESENT)
                  || (LocalstDgoScg_Ped1 == GDU_ETAT_PCTL_ABSENT))
               {
                  u32Localswitcher = ((AccP_rAccPFctMonPrev * 64) + 312) / 625;
               }
               else
               {
                  if (bLocalAccPSen1 != 0)
                  {
                     if (  (LocalstDgoScpOc_Ped2 == GDU_ETAT_ABSENT)
                        && (LocalstDgoScg_Ped2 == GDU_ETAT_ABSENT))
                     {
                        u32Localswitcher = AccP_rAccPSens2Prev;
                     }
                     else
                     {
                        if (  (LocalstDgoScpOc_Ped2 == GDU_ETAT_PCTL_ABSENT)
                           || (LocalstDgoScpOc_Ped2 == GDU_ETAT_PCTL_PRESENT)
                           || (LocalstDgoScg_Ped2 == GDU_ETAT_PCTL_ABSENT)
                           || (LocalstDgoScg_Ped2 == GDU_ETAT_PCTL_PRESENT))
                        {
                           /*Warning QAC: Nesting of control structures
                           (statements) exceeds 15 */
                           u32Localswitcher =
                              ((AccP_rAccPFctMonPrev * 64) + 312) / 625;
                        }
                        else
                        {
                           /*Warning QAC: Nesting of control structures
                           (statements) exceeds 15 */
                           u32Localswitcher = 0;
                        }
                     }
                  }
                  else
                  {
                     u32Localswitcher = 0;
                  }
               }
            }
         }
      }
   }
   u32LocalAccP_rAcc = (u32Localswitcher * 625) / 64;
   u16LocalAccP_rAcc = (uint16)MATHSRV_udtMIN(u32LocalAccP_rAcc, 10000);
   VEMS_vidSET(AccP_rAccPFctMon, u16LocalAccP_rAcc);

   u16LocalSsm_precise_pedal = (uint16)MATHSRV_udtMIN(u32Localswitcher, 1024);
   VEMS_vidSET(Ssm_precise_pedal_position, u16LocalSsm_precise_pedal);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPMNGMODSECU_vidStateTransit                             */
/* !Description :  Inclut le traitement relatif au transitions entre ces modes*/
/* !Number      :  FCT1.8                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean AccP_bAccPCohDegMod_C;                                      */
/*  input boolean AccP_bPsenOneDftEl;                                         */
/*  input boolean AccP_bPsenPctlEl;                                           */
/*  input uint16 AccP_rAccPPrev;                                              */
/*  input boolean AccP_bPsenNoBoothDftEl;                                     */
/*  input uint16 AccP_rAccPRampFault_C;                                       */
/*  input uint16 AccP_rAccPSens2Prev;                                         */
/*  input boolean AccP_bCohPSenPctl;                                          */
/*  input uint16 AccP_rAccPSens1Prev;                                         */
/*  input boolean AccP_bPsenNoDftEl;                                          */
/*  output st99 AccP_stAccPSec;                                               */
/*  output st100 AccP_stAccPVld;                                              */
/*  output uint16 AccP_rAccPRaw;                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPMNGMODSECU_vidStateTransit(void)
{
   boolean            bLocalAccPSen1;
   boolean            bLocalAccPSen2;
   boolean            bLocalCohAccPSen;
   boolean            bLocalStuckAccP;
   GDFRM_tenuGDUState LocalstDgoCoh_Ped;
   GDFRM_tenuGDUState LocalstDgoStuck_Ped;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped2;
   GDFRM_tenuGDUState LocalstDgoScg_Ped2;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped1;
   GDFRM_tenuGDUState LocalstDgoScg_Ped1;
   uint16             u16LocalMin;
   uint32             u32LocalCalAccPRaw;
   sint32             s32LocalCalAccPRaw;


   LocalstDgoStuck_Ped = GDGAR_tenuGetStDgo(GD_DFT_STUCK_PED);
   LocalstDgoCoh_Ped = GDGAR_tenuGetStDgo(GD_DFT_COH_PED);
   LocalstDgoScpOc_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED1);
   LocalstDgoScpOc_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED2);
   LocalstDgoScg_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED1);
   LocalstDgoScg_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED2);

   bLocalStuckAccP = GDGAR_bGetFRM(FRM_FRM_STUCKACCP);
   bLocalCohAccPSen = GDGAR_bGetFRM(FRM_FRM_COHACCPSEN);
   bLocalAccPSen1 = GDGAR_bGetFRM(FRM_FRM_ACCPSEN1);
   bLocalAccPSen2 = GDGAR_bGetFRM(FRM_FRM_ACCPSEN2);

   if (  (  (LocalstDgoStuck_Ped == GDU_ETAT_ABSENT)
         && (bLocalCohAccPSen != 0)
         && (AccP_bAccPCohDegMod_C != 0)
         && (  (AccP_bPsenOneDftEl != 0)
            || (AccP_bPsenPctlEl != 0)))
      || (  (LocalstDgoCoh_Ped == GDU_ETAT_ABSENT)
         && (LocalstDgoStuck_Ped == GDU_ETAT_ABSENT)
         && (AccP_bPsenOneDftEl != 0)
         && (AccP_bPsenPctlEl != 0)))
   {/***Priorité 1***/
      VEMS_vidSET(AccP_stAccPSec, AccP_stDegMode_SC);
      VEMS_vidSET(AccP_stAccPVld, AccP_stVldDegMode_SC);
      AccP_rAccPRaw = (uint16)MATHSRV_udtMIN(AccP_rAccPPrev, 12800);
   }
   else
   {/***Priorité 2***/
      if (  (AccP_bPsenNoBoothDftEl != 0)
         && (bLocalStuckAccP != 0)
         && (  (  (bLocalCohAccPSen != 0)
               && (AccP_bAccPCohDegMod_C != 0))
            || (bLocalCohAccPSen == 0)))
      {
         VEMS_vidSET(AccP_stAccPSec, AccP_stStuckMode_SC);
         VEMS_vidSET(AccP_stAccPVld, AccP_stVldStuckMode_SC);
         s32LocalCalAccPRaw =
            (sint32)(AccP_rAccPPrev -  AccP_rAccPRampFault_C);
         AccP_rAccPRaw =
            (uint16)MATHSRV_udtCLAMP(s32LocalCalAccPRaw, 0, 12800);
      }
      else
      { /*** Priorité 3 ***/
         if (  (LocalstDgoCoh_Ped == GDU_ETAT_ABSENT)
            && (LocalstDgoStuck_Ped == GDU_ETAT_ABSENT)
            && (bLocalAccPSen1 != 0)
            && (LocalstDgoScpOc_Ped2 == GDU_ETAT_ABSENT)
            && (LocalstDgoScg_Ped2 == GDU_ETAT_ABSENT))
         {
            VEMS_vidSET(AccP_stAccPSec, AccP_stDegSen2Mode_SC);
            VEMS_vidSET(AccP_stAccPVld, AccP_stVldDegMode_SC);
            u32LocalCalAccPRaw =
               (uint32)(((AccP_rAccPSens2Prev * 25) + 1) / 2);
            AccP_rAccPRaw =
               (uint16)MATHSRV_udtMIN(u32LocalCalAccPRaw, 12800);
         }
         else
         {/***Priorité 4***/
            if (  (LocalstDgoStuck_Ped == GDU_ETAT_ABSENT)
               && (bLocalCohAccPSen == 0)
               && (bLocalAccPSen1 == 0)
               && (bLocalAccPSen2 == 0)
               && (AccP_bCohPSenPctl != 0))
            {
               VEMS_vidSET(AccP_stAccPSec, AccP_stDegPctlMode_SC);
               VEMS_vidSET(AccP_stAccPVld, AccP_stVldNomMode_SC);
               AccP_rAccPRaw =
                  (uint16)MATHSRV_udtMIN(AccP_rAccPPrev, 12800);
            }
            else
            { /*** Priorité 5 ***/
               if ( (  (LocalstDgoStuck_Ped == GDU_ETAT_ABSENT)
                    && (bLocalCohAccPSen != 0)
                    && (AccP_bAccPCohDegMod_C == 0)
                    && (AccP_bPsenNoBoothDftEl != 0))
                  || (  (  (AccP_bPsenNoBoothDftEl != 0)
                        && (bLocalStuckAccP != 0)
                        && (bLocalCohAccPSen != 0)
                        && (AccP_bAccPCohDegMod_C == 0))
                     || (  (bLocalAccPSen1 != 0)
                        && (bLocalAccPSen2 != 0))))
               {
                  VEMS_vidSET(AccP_stAccPSec, AccP_stSubstMode_SC);
                  VEMS_vidSET(AccP_stAccPVld, AccP_stVldSubstMode_SC);
                   s32LocalCalAccPRaw =
                     (sint32)(AccP_rAccPPrev -  AccP_rAccPRampFault_C);
                  AccP_rAccPRaw =
                     (uint16)MATHSRV_udtCLAMP(s32LocalCalAccPRaw, 0, 12800);
               }
               else
               { /*** Priorité 6***/
                  if (  (LocalstDgoCoh_Ped == GDU_ETAT_ABSENT)
                     && (LocalstDgoStuck_Ped == GDU_ETAT_ABSENT)
                     && (LocalstDgoScpOc_Ped1 == GDU_ETAT_ABSENT)
                     && (LocalstDgoScg_Ped1 == GDU_ETAT_ABSENT)
                     && (bLocalAccPSen2 != 0))
                  {
                     VEMS_vidSET(AccP_stAccPSec, AccP_stDegSen1Mode_SC);
                     VEMS_vidSET(AccP_stAccPVld, AccP_stVldDegMode_SC);
                     u32LocalCalAccPRaw =
                        (uint32)(((AccP_rAccPSens1Prev * 25) + 1) / 2);
                     AccP_rAccPRaw =
                        (uint16)MATHSRV_udtMIN(u32LocalCalAccPRaw, 12800);
                  }
                  else
                  {
                     if (  (LocalstDgoStuck_Ped == GDU_ETAT_ABSENT)
                        && (AccP_bPsenNoDftEl != 0))
                     {/***Priorité 7***/
                        if (  (bLocalCohAccPSen != 0)
                           && (AccP_bAccPCohDegMod_C != 0))
                        {
                        /*Warning QAC: Nesting of control structures
                        (statements) exceeds 15 */
                           VEMS_vidSET(AccP_stAccPSec, AccP_stNomDegMode_SC);
                           VEMS_vidSET(AccP_stAccPVld, AccP_stVldDegMode_SC);
                           u16LocalMin =
                              (uint16)MATHSRV_udtMIN(AccP_rAccPSens1Prev,
                                                   AccP_rAccPSens2Prev);
                           u32LocalCalAccPRaw =
                              (uint32)(((u16LocalMin * 25) + 1) / 2);
                           AccP_rAccPRaw =
                              (uint16)MATHSRV_udtMIN(u32LocalCalAccPRaw, 12800);
                        }
                        else
                        {/*** Priorité 8***/
                           /*Warning QAC: Nesting of control structures
                           (statements) exceeds 15 */
                           if (LocalstDgoCoh_Ped == GDU_ETAT_ABSENT)
                           {
                              VEMS_vidSET(AccP_stAccPSec, AccP_stNomMode_SC);
                              VEMS_vidSET(AccP_stAccPVld, AccP_stVldNomMode_SC);
                              u16LocalMin =
                                 (uint16)MATHSRV_udtMIN(AccP_rAccPSens1Prev,
                                                          AccP_rAccPSens2Prev);
                              u32LocalCalAccPRaw =
                                 (uint32)(((u16LocalMin * 25) + 1) / 2);
                              AccP_rAccPRaw =
                                 (uint16)MATHSRV_udtMIN(u32LocalCalAccPRaw,
                                                        12800);
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
}

/*-------------------------------End Of File----------------------------------*/