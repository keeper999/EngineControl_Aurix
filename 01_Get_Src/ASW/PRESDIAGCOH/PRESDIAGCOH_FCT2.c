/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PRESDIAGCOH                                             */
/* !Description     : PRESDIAGCOH Component                                   */
/*                                                                            */
/* !Module          : PRESDIAGCOH                                             */
/* !Description     : PRESSURE SENSORS COHERENCY DIAGNOSIS                    */
/*                                                                            */
/* !File            : PRESDIAGCOH_FCT2.C                                      */
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
/*   1 / PRESDIAGCOH_vidUpstrmThrPSDrift                                      */
/*                                                                            */
/* !Reference   : V02 NT 12 01298 / 04                                        */
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
#include "PRESDIAGCOH.h"
#include "PRESDIAGCOH_L.h"
#include "PRESDIAGCOH_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidUpstrmThrPSDrift                            */
/* !Description :  Calcule de la dérive négative et positive  du capteur de   */
/*                 pression d'étranglement amont.                             */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 DgSen_pDelta_pOil_pUsThrFil;                                 */
/*  input sint16 DgSen_pDelta_pAirExt_pUsThrFil;                              */
/*  input boolean DgSen_bUsThrPrssSup;                                        */
/*  input uint16 DgSen_pDifMaxUsThrOilThd_C;                                  */
/*  input uint16 DgSen_pDifMaxUsThrAirExtThd_C;                               */
/*  input uint16 Oil_tiDlyDriftPos_pUsThrFilThd_C;                            */
/*  input uint16 PRESDIAGCOH_u16UpstrmTimerCount;                             */
/*  input boolean PRESDIAGCOH_bUpstrmTimerOut;                                */
/*  input boolean DgSen_bUsThrPrssSdwn;                                       */
/*  input uint16 DgSen_pDifMaxAirExtUsThrThd_C;                               */
/*  input uint16 DgSen_pDifMaxOilUsThrThd_C;                                  */
/*  input uint16 Oil_tiDlyDriftNeg_pUsThrFilThd_C;                            */
/*  input uint16 PRESDIAGCOH_u16UpstrmTimer1Count;                            */
/*  input boolean PRESDIAGCOH_bUpstrmTimer1Out;                               */
/*  output boolean DgSen_bUsThrPrssSup;                                       */
/*  output uint16 PRESDIAGCOH_u16UpstrmTimerCount;                            */
/*  output boolean PRESDIAGCOH_bUpstrmTimerOut;                               */
/*  output boolean DgSen_bDgoUsThrPrssSup;                                    */
/*  output boolean DgSen_bUsThrPrssSdwn;                                      */
/*  output uint16 PRESDIAGCOH_u16UpstrmTimer1Count;                           */
/*  output boolean PRESDIAGCOH_bUpstrmTimer1Out;                              */
/*  output boolean DgSen_bDgoUsThrPrssSdwn;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidUpstrmThrPSDrift(void)
{
   boolean bLocalTimerInitPrev;
   boolean bLocalTimer1InitPrev;
   sint32  s32LocalDeltaOilUsThrFil;
   sint32  s32LocalDeltaAirExtUsThrFil;


   /* Production of DgSen_bDgoUsThrPrssSup */
   s32LocalDeltaOilUsThrFil = (sint32)((- 1) * DgSen_pDelta_pOil_pUsThrFil);
   s32LocalDeltaAirExtUsThrFil =
         (sint32)((- 1) * DgSen_pDelta_pAirExt_pUsThrFil);
   bLocalTimerInitPrev = DgSen_bUsThrPrssSup;
   if (  (s32LocalDeltaOilUsThrFil > DgSen_pDifMaxUsThrOilThd_C)
      && (s32LocalDeltaAirExtUsThrFil > DgSen_pDifMaxUsThrAirExtThd_C))
   {
      DgSen_bUsThrPrssSup = 1;
   }
   else
   {
      DgSen_bUsThrPrssSup = 0;
   }

   if (  (bLocalTimerInitPrev == 0)
      && (DgSen_bUsThrPrssSup != 0))
   {
      PRESDIAGCOH_u16UpstrmTimerCount = Oil_tiDlyDriftPos_pUsThrFilThd_C;
      if (PRESDIAGCOH_u16UpstrmTimerCount == 0)
      {
         PRESDIAGCOH_bUpstrmTimerOut = 1;
      }
      else
      {
         PRESDIAGCOH_bUpstrmTimerOut = 0;
      }
   }
   else
   {
      if (PRESDIAGCOH_u16UpstrmTimerCount > 0)
      {
         PRESDIAGCOH_u16UpstrmTimerCount =
            (uint16)(PRESDIAGCOH_u16UpstrmTimerCount - 1);
         if (PRESDIAGCOH_u16UpstrmTimerCount == 0)
         {
            PRESDIAGCOH_bUpstrmTimerOut = 1;
         }
         else
         {
            PRESDIAGCOH_bUpstrmTimerOut = 0;
         }
      }
   }

   if (  (PRESDIAGCOH_bUpstrmTimerOut != 0)
      && (DgSen_bUsThrPrssSup != 0))
   {
      DgSen_bDgoUsThrPrssSup = 1;
   }
   else
   {
      DgSen_bDgoUsThrPrssSup = 0;
   }

   /* Production of DgSen_bDgoUsThrPrssSdwn */
   bLocalTimer1InitPrev = DgSen_bUsThrPrssSdwn;
   if (  (DgSen_pDelta_pAirExt_pUsThrFil > DgSen_pDifMaxAirExtUsThrThd_C)
      && (DgSen_pDelta_pOil_pUsThrFil > DgSen_pDifMaxOilUsThrThd_C))
   {
      DgSen_bUsThrPrssSdwn = 1;
   }
   else
   {
      DgSen_bUsThrPrssSdwn = 0;
   }

   if (  (bLocalTimer1InitPrev == 0)
      && (DgSen_bUsThrPrssSdwn != 0))
   {
      PRESDIAGCOH_u16UpstrmTimer1Count = Oil_tiDlyDriftNeg_pUsThrFilThd_C;
      if (PRESDIAGCOH_u16UpstrmTimer1Count == 0)
      {
         PRESDIAGCOH_bUpstrmTimer1Out = 1;
      }
      else
      {
         PRESDIAGCOH_bUpstrmTimer1Out = 0;
      }
   }
   else
   {
      if (PRESDIAGCOH_u16UpstrmTimer1Count > 0)
      {
         PRESDIAGCOH_u16UpstrmTimer1Count =
            (uint16)(PRESDIAGCOH_u16UpstrmTimer1Count - 1);
         if (PRESDIAGCOH_u16UpstrmTimer1Count == 0)
         {
            PRESDIAGCOH_bUpstrmTimer1Out = 1;
         }
         else
         {
            PRESDIAGCOH_bUpstrmTimer1Out = 0;
         }
      }
   }

   if (  (PRESDIAGCOH_bUpstrmTimer1Out != 0)
      && (DgSen_bUsThrPrssSdwn != 0))
   {
      DgSen_bDgoUsThrPrssSdwn = 1;
   }
   else
   {
      DgSen_bDgoUsThrPrssSdwn = 0;
   }
}
/*------------------------------- end of file --------------------------------*/