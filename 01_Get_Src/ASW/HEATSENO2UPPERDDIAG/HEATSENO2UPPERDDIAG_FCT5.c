/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2UPPERDDIAG                                     */
/* !Description     : HEATSENO2UPPERDDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2UPPERDDIAG                                     */
/* !Description     : DIAGNOSTIC DE LA SONDE A OXYGENE AMONT                  */
/*                                                                            */
/* !File            : HEATSENO2UPPERDDIAG_FCT5.C                              */
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
/*   1 / HEATSENO2UPPERDDIAG_vidCrPrdRich                                     */
/*   2 / HEATSENO2UPPERDDIAG_vidCorRich                                       */
/*   3 / HEATSENO2UPPERDDIAG_vidCorLean                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5012863 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2US/HEATSENO2UPPERDDIA$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   17 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2UPPERDDIAG.h"
#include "HEATSENO2UPPERDDIAG_L.h"
#include "HEATSENO2UPPERDDIAG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCrPrdRich                           */
/* !Description :  Cette fonction fait le bilan des pannes  présentes         */
/*                 concernant la période riche                                */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint16 Dnstr_modifier_time_scale;                                   */
/*  input uint16 Dnstr_modifier_temp;                                         */
/*  output uint16 Dnstr_modifier_temp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCrPrdRich(void)
{
   boolean bLocalLambda_slow_mode;
   uint16  u16LocalDnstrmodifiertime_scale;
   uint32  u32LocalAddResult;


   VEMS_vidGET(Lambda_slow_mode , bLocalLambda_slow_mode );
   VEMS_vidGET(Dnstr_modifier_time_scale , u16LocalDnstrmodifiertime_scale);

   if (bLocalLambda_slow_mode != 0)
   {
      u32LocalAddResult = (uint32)( u16LocalDnstrmodifiertime_scale
                                  + Dnstr_modifier_temp);
      Dnstr_modifier_temp = (uint16)MATHSRV_udtMIN(u32LocalAddResult, 65535);
   }
   else
   {
      Dnstr_modifier_temp = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCorRich                             */
/* !Description :  Cette fonction fait le bilan des pannes  présentes         */
/*                 concernant la période riche                                */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint16 Dnstr_modifier_time_scale;                                   */
/*  input boolean Manu_inh_correction_perdiag;                                */
/*  input uint16 Oxy_ups_tempo_rich;                                          */
/*  input uint16 Dnstr_modifier_temp;                                         */
/*  output uint16 Oxy_ups_period_rich;                                        */
/*  output uint16 Oxy_ups_tempo_rich;                                         */
/*  output uint16 Dnstr_modifier_temp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCorRich(void)
{
   boolean bLocalLambda_slow_mode;
   uint16  u16LocalDnstrmodifiertime_scale;
   sint32  s32Localsubstractresult;


   VEMS_vidGET(Lambda_slow_mode , bLocalLambda_slow_mode );
   VEMS_vidGET(Dnstr_modifier_time_scale , u16LocalDnstrmodifiertime_scale);

   if (Manu_inh_correction_perdiag != 0)
   {
      Oxy_ups_period_rich = (uint16)MATHSRV_udtMIN(Oxy_ups_tempo_rich, 26214);
   }
   else
   {
      s32Localsubstractresult = (sint32)( Oxy_ups_tempo_rich
                                        - Dnstr_modifier_temp);
      Oxy_ups_period_rich = (uint16)MATHSRV_udtCLAMP(s32Localsubstractresult,
                                                     0,
                                                     26214);
   }
   Oxy_ups_tempo_rich = 0;

   if (bLocalLambda_slow_mode != 0)
   {
      Dnstr_modifier_temp = u16LocalDnstrmodifiertime_scale;
   }
   else
   {
      Dnstr_modifier_temp = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCorLean                             */
/* !Description :  Cette fonction fait le bilan des pannes  présentes         */
/*                 concernant la période pauvre                               */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint16 Dnstr_modifier_time_scale;                                   */
/*  input uint16 Dnstr_modifier_temp;                                         */
/*  output uint16 Dnstr_modifier_temp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCorLean(void)
{
   boolean bLocalLambda_slow_mode;
   uint16  u16LocalDnstrmodifiertime_scale;
   uint32  u32LocalAddResult;


   VEMS_vidGET(Lambda_slow_mode , bLocalLambda_slow_mode );
   VEMS_vidGET(Dnstr_modifier_time_scale , u16LocalDnstrmodifiertime_scale);

   if (bLocalLambda_slow_mode != 0)
   {
      u32LocalAddResult = (uint32)( u16LocalDnstrmodifiertime_scale
                                  + Dnstr_modifier_temp);
      Dnstr_modifier_temp = (uint16)MATHSRV_udtMIN(u32LocalAddResult, 65535);
   }
   else
   {
      Dnstr_modifier_temp = 0;
   }
}

/*------------------------------- end of file --------------------------------*/