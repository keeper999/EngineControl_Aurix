/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : REQADJVLTCTL                                            */
/* !Description     : REQADJVLTCTL Component                                  */
/*                                                                            */
/* !Module          : REQADJVLTCTL                                            */
/* !Description     : GESTION CHAUFFAGE SONDE AVAL                            */
/*                                                                            */
/* !File            : REQADJVLTCTL_FCT1.C                                     */
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
/*   1 / REQADJVLTCTL_vidInitReqAdjVltCtl                                     */
/*   2 / REQADJVLTCTL_vidTraitReqAdjVltCt                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 03742 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HEATSENO2/REQADJVLTCTL/REQADJVLT$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   25 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   25 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "REQADJVLTCTL.h"
#include "REQADJVLTCTL_L.h"
#include "REQADJVLTCTL_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REQADJVLTCTL_vidInitReqAdjVltCtl                           */
/* !Description :  Initialisation des variables au reset                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsSys_bAdj_uBattNom;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void REQADJVLTCTL_vidInitReqAdjVltCtl(void)
{
   VEMS_vidSET(LsSys_bAdj_uBattNom, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REQADJVLTCTL_vidTraitReqAdjVltCt                           */
/* !Description :  Cette fonction permet la demande d’ajustement de la tension*/
/*                 de batterie pour les besoins en chauffage des sondes O2 par*/
/*                 l'envoi de Requête de boost VoltCtl pour  ces sondes O2.   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_03742_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st70 LsSys_stLsDsMainOxCHeat;                                       */
/*  input uint8 LsSys_LsDsMainOxCHeatModeReq_T[8];                            */
/*  input boolean LsSys_bLsDsMainOxCHeatModeReq_M[8];                         */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input uint8 LsSys_LsUsMainOxCHeatModeReq_T[8];                            */
/*  input boolean LsSys_bLsUsMainOxCHeatModeReq_M[8];                         */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrMan;                                 */
/*  input uint16 LsSys_uBatt2LsDsMainOxCRef_C;                                */
/*  input uint16 LsSys_uBatt2LsDsMainOxCThd_C;                                */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrMan;                                 */
/*  input uint16 LsSys_uBatt2LsUsMainOxCRef_C;                                */
/*  input uint16 LsSys_uBatt2LsUsMainOxCThd_C;                                */
/*  input boolean LsSys_bLsUsMainOxCHeatFloEna;                               */
/*  input boolean LsSys_bEnaLsDs_AdjuBattNom_C;                               */
/*  input boolean LsSys_bComp_uBatt2LsDsMainOxC;                              */
/*  input boolean LsSys_bAcv_stLsDsMainOxC;                                   */
/*  input boolean LsSys_bEnaLsUs_AdjuBattNom_C;                               */
/*  input boolean LsSys_bComp_uBatt2LsUsMainOxC;                              */
/*  input boolean LsSys_bAcv_stLsUsMainOxC;                                   */
/*  output boolean LsSys_bAcv_stLsDsMainOxC;                                  */
/*  output boolean LsSys_bAcv_stLsUsMainOxC;                                  */
/*  output boolean LsSys_bComp_uBatt2LsDsMainOxC;                             */
/*  output boolean LsSys_bComp_uBatt2LsUsMainOxC;                             */
/*  output boolean LsSys_bAdj_uBattNom;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void REQADJVLTCTL_vidTraitReqAdjVltCt(void)
{
   boolean bLocalLsSys_bLsUsMainOxHeatFlEna;
   boolean bLocalLsSys_bAdj_uBattNom;
   uint8   u8LocalLsSys_stLsDsMainOxCHeat;
   uint8   u8LocalLsSys_stLsUsMainOxCHeat;
   uint8   u8LocalLsSys_rLsDsMainOxHtPwrMan;
   uint8   u8LocalLsSys_rLsUsMainOxHtPwrMan;
   uint16  u16LocalCalcPara;
   uint32  u32LocalResult1;
   uint32  u32LocalResult2;
   uint32  u32LocalLsSysubatt;


   VEMS_vidGET(LsSys_stLsDsMainOxCHeat, u8LocalLsSys_stLsDsMainOxCHeat);
   u8LocalLsSys_stLsDsMainOxCHeat =
      (uint8)MATHSRV_udtMIN(u8LocalLsSys_stLsDsMainOxCHeat, 7);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU8(LsSys_LsDsMainOxCHeatModeReq_T,
                                  u8LocalLsSys_stLsDsMainOxCHeat,
                                  8);
   u16LocalCalcPara = (uint16)(u16LocalCalcPara / 256);
   LsSys_bAcv_stLsDsMainOxC = LsSys_bLsDsMainOxCHeatModeReq_M[u16LocalCalcPara];

   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
   u8LocalLsSys_stLsUsMainOxCHeat =
      (uint8)MATHSRV_udtMIN(u8LocalLsSys_stLsUsMainOxCHeat, 7);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU8(LsSys_LsUsMainOxCHeatModeReq_T,
                                  u8LocalLsSys_stLsUsMainOxCHeat,
                                  8);
   u16LocalCalcPara = (uint16)(u16LocalCalcPara / 256);
   LsSys_bAcv_stLsUsMainOxC = LsSys_bLsUsMainOxCHeatModeReq_M[u16LocalCalcPara];

   VEMS_vidGET(LsSys_rLsDsMainOxCHeatPwrMan, u8LocalLsSys_rLsDsMainOxHtPwrMan);
   u32LocalResult1 = (u8LocalLsSys_rLsDsMainOxHtPwrMan *
      LsSys_uBatt2LsDsMainOxCRef_C);
   u32LocalLsSysubatt = LsSys_uBatt2LsDsMainOxCThd_C * 200;
   if (u32LocalResult1 > u32LocalLsSysubatt)
   {
      LsSys_bComp_uBatt2LsDsMainOxC = 1;
   }
   else
   {
      LsSys_bComp_uBatt2LsDsMainOxC = 0;
   }
   VEMS_vidGET(LsSys_rLsUsMainOxCHeatPwrMan, u8LocalLsSys_rLsUsMainOxHtPwrMan);
   u32LocalResult2 = (u8LocalLsSys_rLsUsMainOxHtPwrMan *
      LsSys_uBatt2LsUsMainOxCRef_C);
   u32LocalLsSysubatt = LsSys_uBatt2LsUsMainOxCThd_C * 200;
   if (u32LocalResult2 > u32LocalLsSysubatt)
   {
      LsSys_bComp_uBatt2LsUsMainOxC = 1;
   }
   else
   {
      LsSys_bComp_uBatt2LsUsMainOxC = 0;
   }
   VEMS_vidGET(LsSys_bLsUsMainOxCHeatFloEna, bLocalLsSys_bLsUsMainOxHeatFlEna);
   if (  (  (LsSys_bEnaLsDs_AdjuBattNom_C != 0)
         && (  (LsSys_bComp_uBatt2LsDsMainOxC != 0)
            || (LsSys_bAcv_stLsDsMainOxC != 0)))
      || (  (LsSys_bEnaLsUs_AdjuBattNom_C != 0)
         && (  (LsSys_bComp_uBatt2LsUsMainOxC != 0)
            || (bLocalLsSys_bLsUsMainOxHeatFlEna != 0)
            || (LsSys_bAcv_stLsUsMainOxC != 0))))
   {
      bLocalLsSys_bAdj_uBattNom = 1;
   }
   else
   {
      bLocalLsSys_bAdj_uBattNom = 0;
   }
   VEMS_vidSET(LsSys_bAdj_uBattNom, bLocalLsSys_bAdj_uBattNom);
}
/*------------------------------- end of file --------------------------------*/