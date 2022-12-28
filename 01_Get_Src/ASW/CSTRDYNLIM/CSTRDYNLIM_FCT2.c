/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRDYNLIM                                              */
/* !Description     : CSTRDYNLIM component.                                   */
/*                                                                            */
/* !Module          : CSTRDYNLIM                                              */
/* !Description     : BORNAGE DYNAMIQUE DE DEBIT PURGE                        */
/*                                                                            */
/* !File            : CSTRDYNLIM_FCT2.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CSTRDYNLIM_vidPrgDecRat                                              */
/*   2 / CSTRDYNLIM_vidPurgeGblCta                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5205503 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CSTR/CSTRDYNLIM/CSTRDYNLIM_FCT2.$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   22 May 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   22 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_Types.h"
#include "STD_limits.h"
#include "MATHSRV.h"
#include "CSTRDYNLIM.h"
#include "CSTRDYNLIM_L.h"
#include "CSTRDYNLIM_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidPrgDecRat                                    */
/* !Description :  calcul de la variable Cpc_max_purge_ratio                  */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoEs_bAcvClsCanPurgSTTEs;                                   */
/*  input uint16 Cpc_fuel_vapour_conc_err;                                    */
/*  input uint16 Cpc_current_purge_ratio;                                     */
/*  input boolean CSTRDYNLIM_bGsmPurgeClosingEntry;                           */
/*  input boolean Cpc_bAcvClsCanPurgSTTRamp_C;                                */
/*  input uint16 Cpc_purge_rate_gain_stt;                                     */
/*  input uint8 Cpc_max_purge_ratio_max_step_stt;                             */
/*  input uint16 Cpc_purge_rate_gain;                                         */
/*  input uint8 Cpc_max_purge_ratio_max_step;                                 */
/*  input uint16 Cpc_max_purge_ratio;                                         */
/*  output uint16 Cpc_max_purge_ratio;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidPrgDecRat(void)
{
   boolean bLocalCoEs_bAcvClsCanPurgSTTEs;
   uint16  u16LocalCpc_fuel_vapour_conc_err;
   uint16  u16LocalCpc_current_purge_ratio;
   uint32  u32LocalCpc_purge_rate_gain;
   uint32  u32LocalCpc_max_purge_ratio;
   uint32  u32LocalCpc_max_purge_rat;
   uint32  u32LocalDivi;
   uint32  u32LocalFirstPram;
   uint32  u32LocalSecondPram;
   sint32  s32LocalDiff;


   VEMS_vidGET(CoEs_bAcvClsCanPurgSTTEs, bLocalCoEs_bAcvClsCanPurgSTTEs);
   VEMS_vidGET(Cpc_fuel_vapour_conc_err, u16LocalCpc_fuel_vapour_conc_err);
   VEMS_vidGET(Cpc_current_purge_ratio, u16LocalCpc_current_purge_ratio);
   if (CSTRDYNLIM_bGsmPurgeClosingEntry != 0)
   {
      Cpc_max_purge_ratio = u16LocalCpc_current_purge_ratio;
   }
   else
   {
      if (  (bLocalCoEs_bAcvClsCanPurgSTTEs != 0)
         && (Cpc_bAcvClsCanPurgSTTRamp_C != 0))
      {
         if (u16LocalCpc_fuel_vapour_conc_err != 0)
         {
            u32LocalFirstPram = (uint32)(Cpc_purge_rate_gain_stt * 65536);
            u32LocalSecondPram =
               (uint32)(u16LocalCpc_fuel_vapour_conc_err * 25);
            u32LocalDivi = (u32LocalFirstPram / u32LocalSecondPram);
         }
         else
         {
            u32LocalDivi =
               (uint32)(Cpc_max_purge_ratio_max_step_stt * 1024);
         }
      }
      else
      {
         u32LocalCpc_purge_rate_gain = (uint32)(Cpc_purge_rate_gain * 49152);
         if (u16LocalCpc_fuel_vapour_conc_err != 0)
         {
            u32LocalCpc_max_purge_ratio = ((( u32LocalCpc_purge_rate_gain
                                             + 3125)
                                           / 6250));
            if (u32LocalCpc_max_purge_ratio >= 491528)
            {
            /*Msg(3:3356)/Msg(3:3359)/Msg(3:3201):Pas d'impact: cette condition
            est couverte dans le rtrt*/
               u32LocalCpc_max_purge_rat = UINT32_MAX;
            }
            else
            {
               u32LocalCpc_max_purge_rat = ( u32LocalCpc_max_purge_ratio
                                           * 8738);
            }

            u32LocalDivi = ( u32LocalCpc_max_purge_rat
                           / u16LocalCpc_fuel_vapour_conc_err);
         }
         else
         {
            u32LocalDivi = (uint32)(Cpc_max_purge_ratio_max_step * 256);
         }
      }
      s32LocalDiff = MATHSRV_s32Sub_u32_u32((uint32)Cpc_max_purge_ratio,
                                                    u32LocalDivi);
      Cpc_max_purge_ratio = (uint16)MATHSRV_udtMAX(s32LocalDiff, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRDYNLIM_vidPurgeGblCta                                  */
/* !Description :  Ce processus utilise les contraintes spécifiques pour      */
/*                 générer la contrainte globale en débit qui est ensuite     */
/*                 convertie en taux de purge.                                */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 InM_mfAirThrEstim;                                           */
/*  input boolean OxC_bMonReqORngIntr;                                        */
/*  input boolean OxC_bMonEndORngIntr;                                        */
/*  input uint16 Cpc_fuel_constraint_max_mfr;                                 */
/*  input uint16 Cpc_fpw_constraint_max_mfr;                                  */
/*  input uint16 Cpc_air_constraint_max_mfr;                                  */
/*  input uint16 Cpc_lambda_constraint_max_mfr;                               */
/*  input uint16 Cpc_cat_diag_max_purge_ratio;                                */
/*  output uint16 Cpc_constraints_max_purge_ratio;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRDYNLIM_vidPurgeGblCta(void)
{
   boolean bLocalOxC_bMonReqORngIntr;
   boolean bLocalOxC_bMonEndORngIntr;
   uint16  u16LocalMin;
   uint16  u16LocalInM_mfAirThrEstim;
   uint16  u16LocalCpcConstraintsMaxPurgeRa;
   uint32  u32LocalDiv;


   VEMS_vidGET(InM_mfAirThrEstim, u16LocalInM_mfAirThrEstim);
   VEMS_vidGET(OxC_bMonReqORngIntr, bLocalOxC_bMonReqORngIntr);
   VEMS_vidGET(OxC_bMonEndORngIntr, bLocalOxC_bMonEndORngIntr);
   u16LocalMin = (uint16)MATHSRV_udtMIN(Cpc_fuel_constraint_max_mfr,
                                         Cpc_fpw_constraint_max_mfr);
   u16LocalMin = (uint16)MATHSRV_udtMIN(u16LocalMin,
                                        Cpc_air_constraint_max_mfr);
   u16LocalMin = (uint16)MATHSRV_udtMIN(u16LocalMin,
                                        Cpc_lambda_constraint_max_mfr);

   if (u16LocalMin != 0)
   {
      if (u16LocalInM_mfAirThrEstim != 0)
      {
         u32LocalDiv =
            ((uint32)(u16LocalMin * 16384) / u16LocalInM_mfAirThrEstim);
      }
      else
      {
         u32LocalDiv = CPC_LIM_MAX_PURGE_RATIO_MAX_VAL;
      }

      if (  (bLocalOxC_bMonReqORngIntr != 0)
         && (bLocalOxC_bMonEndORngIntr == 0))
      {
         u16LocalCpcConstraintsMaxPurgeRa =
            (uint16)MATHSRV_udtMIN(Cpc_cat_diag_max_purge_ratio, u32LocalDiv);
      }
      else
      {
         u16LocalCpcConstraintsMaxPurgeRa =
            (uint16)MATHSRV_udtMIN(u32LocalDiv, 65535);
      }
   }
   else
   {
      u16LocalCpcConstraintsMaxPurgeRa = 0;
   }
   VEMS_vidSET(Cpc_constraints_max_purge_ratio,
               u16LocalCpcConstraintsMaxPurgeRa);
}
/*------------------------------- end of file --------------------------------*/