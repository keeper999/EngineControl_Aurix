/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTQSTRUCTMNGT                                         */
/* !Description     : AIRTQSTRUCTMNGT component                               */
/*                                                                            */
/* !Module          : AIRTQSTRUCTMNGT                                         */
/* !Description     : MANAGER DES ÉTATS DE LA STRUCTURE COUPLE                */
/*                                                                            */
/* !File            : AIRTQSTRUCTMNGT_FCT2.c                                  */
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
/*   1 / AIRTQSTRUCTMNGT_vidFcSurfStart                                       */
/*   2 / AIRTQSTRUCTMNGT_vidFcDeTranToCyc                                     */
/*   3 / AIRTQSTRUCTMNGT_vidFcTransToCycl                                     */
/*   4 / AIRTQSTRUCTMNGT_vidFcTranToDecyc                                     */
/*   5 / AIRTQSTRUCTMNGT_vidFcTransToStop                                     */
/*                                                                            */
/* !Reference   : PTS DOC 5015877 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/AIRTQSTRUCTMNGT/AIRTQSTRUC$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   24 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "AIRTQSTRUCTMNGT.h"
#include "AIRTQSTRUCTMNGT_L.h"
#include "AIRTQSTRUCTMNGT_IM.h"
#include "mathsrv.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidFcSurfStart                             */
/* !Description :  initialiser la valeur de Coef_de_transition_air au         */
/*                 demarrage                                                  */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoEs_bIntrSTTEsLoEngSpd;                                    */
/*  input uint8 Coef_de_transition_air;                                       */
/*  input boolean CrkMng_bIntrKeyLoEngSpd;                                    */
/*  input boolean CrkMng_bAcvKeyEngStopThrFil_C;                              */
/*  input uint8 Dtc_coef_air_STT_ReStrt_Lo;                                   */
/*  output uint8 Coef_de_transition_air;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidFcSurfStart(void)
{
   boolean bLocalCoEs_bIntrSTTEsLoEngSpd;
   uint8   u8LocalCoef_de_transition_air;
   uint16  u16LocalSum;


   VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd,bLocalCoEs_bIntrSTTEsLoEngSpd);
   VEMS_vidGET(Coef_de_transition_air,u8LocalCoef_de_transition_air);
   if (  (bLocalCoEs_bIntrSTTEsLoEngSpd != 0)
      || (  (CrkMng_bIntrKeyLoEngSpd != 0)
         && (CrkMng_bAcvKeyEngStopThrFil_C != 0)))
   {
      u16LocalSum =
         (uint16)(u8LocalCoef_de_transition_air + Dtc_coef_air_STT_ReStrt_Lo);
      u8LocalCoef_de_transition_air = (uint8)MATHSRV_udtMIN(u16LocalSum, 255);
      VEMS_vidSET(Coef_de_transition_air , u8LocalCoef_de_transition_air);
   }
   else
   {
      VEMS_vidSET(Coef_de_transition_air, 255);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidFcDeTranToCyc                           */
/* !Description :  calculer le coeficient Coef_de_transition_air dans l'état  */
/*                 de bouclage.                                               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input uint8 Coef_de_transition_air;                                       */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint8 Dtc_coef_de_trans_dec_STT_map[16];                            */
/*  input uint8 Dtc_coef_de_trans_dec_dem_map[16];                            */
/*  output uint8 Coef_de_transition_air;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidFcDeTranToCyc(void)
{
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalCoef_de_transition_air;
   uint8   u8LocalDtcCoefDeTransDec;
   uint16  u16LocalTempEau;
   sint16  s16LocalDiff;


   VEMS_vidGET(Temperature_eau,u8LocalTemperature_eau);
   VEMS_vidGET(CoPTSt_bRStrtSTT,bLocalCoPTSt_bRStrtSTT);
   VEMS_vidGET(Coef_de_transition_air,u8LocalCoef_de_transition_air);
   u16LocalTempEau = MATHSRV_u16CalcParaIncAryU8(Temperature_eau_bkpt_map,
                                                 u8LocalTemperature_eau,
                                                 16);
   if (bLocalCoPTSt_bRStrtSTT != 0)
   {
      u8LocalDtcCoefDeTransDec =
              MATHSRV_u8Interp1d(Dtc_coef_de_trans_dec_STT_map,u16LocalTempEau);
   }
   else
   {
      u8LocalDtcCoefDeTransDec =
              MATHSRV_u8Interp1d(Dtc_coef_de_trans_dec_dem_map,u16LocalTempEau);
   }

   s16LocalDiff =
     (sint16)(u8LocalCoef_de_transition_air - u8LocalDtcCoefDeTransDec);
   u8LocalCoef_de_transition_air = (uint8)MATHSRV_udtMAX(s16LocalDiff,0);
   VEMS_vidSET(Coef_de_transition_air,u8LocalCoef_de_transition_air);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidFcTransToCycl                           */
/* !Description :  On souhaite converger vers la structure couple, on calcule */
/*                 donc des coefficients qui permettent de filtrer les        */
/*                 consignes.                                                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoCha_bTqReq;                                               */
/*  input uint16 EngM_pInMnfMinReq;                                           */
/*  input uint16 InM_pDsThrCor;                                               */
/*  input uint8 Coef_de_transition_air;                                       */
/*  input boolean CoEs_bIntrSTTEsHiEngSpd;                                    */
/*  input boolean Manu_inh_esp_torq_reduction;                                */
/*  input boolean Manu_inh_dtc_filtrage_air;                                  */
/*  input uint16 Dtc_fafr_obj_man_p_min_offset;                               */
/*  input uint8 Dtc_coef_de_trans_air_dec;                                    */
/*  input uint8 Dtc_coef_trans_air_dec_p_min;                                 */
/*  input boolean CrkMng_bIntrKeyHiEngSpd;                                    */
/*  input boolean CrkMng_bAcvKeyEngStopThrFil_C;                              */
/*  input uint8 Dtc_coef_air_STT_ReStrt_Hi;                                   */
/*  output uint8 Coef_de_transition_air;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidFcTransToCycl(void)
{
   boolean bLocalCoCha_bTqReq;
   boolean bLocalCoEs_bIntrSTTEsHiEngSpd;
   uint8   u8LocalCoef_de_transition_air;
   uint8   u8LocalSwitch;
   uint16  u16LocalInM_pDsThrCor;
   uint16  u16LocalEngM_pInMnfMinReq;
   sint16  s16LocalDiff;
   uint32  u32LocalSum;


   VEMS_vidGET(CoCha_bTqReq,bLocalCoCha_bTqReq);
   VEMS_vidGET(EngM_pInMnfMinReq,u16LocalEngM_pInMnfMinReq);
   VEMS_vidGET(InM_pDsThrCor, u16LocalInM_pDsThrCor);
   VEMS_vidGET(Coef_de_transition_air,u8LocalCoef_de_transition_air);
   VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd,bLocalCoEs_bIntrSTTEsHiEngSpd);

   if (  (  (Manu_inh_esp_torq_reduction == 0)
         && (bLocalCoCha_bTqReq !=0))
      || (Manu_inh_dtc_filtrage_air != 0))
   {
      u8LocalSwitch = 0;
   }
   else
   {
      u32LocalSum =
         (uint32)(Dtc_fafr_obj_man_p_min_offset + u16LocalEngM_pInMnfMinReq);
      if (u16LocalInM_pDsThrCor >= u32LocalSum)
      {
         s16LocalDiff =
            (sint16)(u8LocalCoef_de_transition_air - Dtc_coef_de_trans_air_dec);
      }
      else
      {
         s16LocalDiff = (sint16)( u8LocalCoef_de_transition_air
                                - Dtc_coef_trans_air_dec_p_min);
      }
      u8LocalSwitch = (uint8)MATHSRV_udtMAX(s16LocalDiff, 0);
   }
   if (  (bLocalCoEs_bIntrSTTEsHiEngSpd != 0)
      || (  (CrkMng_bIntrKeyHiEngSpd != 0)
         && (CrkMng_bAcvKeyEngStopThrFil_C != 0)))
   {
      s16LocalDiff = (sint16)( u8LocalCoef_de_transition_air
                             - Dtc_coef_air_STT_ReStrt_Hi);
      u8LocalCoef_de_transition_air = (uint8)MATHSRV_udtMAX(s16LocalDiff, 0);
   }
   else
   {
      u8LocalCoef_de_transition_air = u8LocalSwitch;
   }
   VEMS_vidSET(Coef_de_transition_air, u8LocalCoef_de_transition_air);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidFcTranToDecyc                           */
/* !Description :  On calcule un coefficient de filtrage sur les consignes    */
/*                 d’air et d’avance débouclées. Le booléen                   */
/*                 Manu_inh_dtc_filtrage_air permet de l’inhiber.             */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Coef_de_transition_air;                                       */
/*  input boolean Manu_inh_dtc_filtrage_air;                                  */
/*  input uint8 Dtc_coef_de_trans_air_inc;                                    */
/*  output uint8 Coef_de_transition_air;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidFcTranToDecyc(void)
{
   uint8  u8LocalCoef_de_transition_air;
   uint16 u16LocalSum;


   VEMS_vidGET(Coef_de_transition_air,u8LocalCoef_de_transition_air);

   if (Manu_inh_dtc_filtrage_air != 0)
   {
      VEMS_vidSET(Coef_de_transition_air, 255);
   }
   else
   {
      u16LocalSum =
        (uint16)(u8LocalCoef_de_transition_air + Dtc_coef_de_trans_air_inc);
      u8LocalCoef_de_transition_air = (uint8)MATHSRV_udtMIN(u16LocalSum,255);
      VEMS_vidSET(Coef_de_transition_air , u8LocalCoef_de_transition_air);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQSTRUCTMNGT_vidFcTransToStop                           */
/* !Description :  Lors d’une séquence d’arrêt, le coefficient de transition  */
/*                 d’air prend une valeur calibrable spécifique à un arrêt    */
/*                 STT.                                                       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Coef_de_transition_air;                                       */
/*  input uint8 Dtc_coef_de_trans_air_arret_STT;                              */
/*  output uint8 Coef_de_transition_air;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQSTRUCTMNGT_vidFcTransToStop(void)
{
   uint8  u8LocalCoef_de_transition_air;
   uint16 u16LocalSum;


   VEMS_vidGET(Coef_de_transition_air,u8LocalCoef_de_transition_air);
   u16LocalSum = (uint16)
        (u8LocalCoef_de_transition_air + Dtc_coef_de_trans_air_arret_STT);
   u8LocalCoef_de_transition_air = (uint8)MATHSRV_udtMIN(u16LocalSum, 255);
   VEMS_vidSET(Coef_de_transition_air , u8LocalCoef_de_transition_air);
}
/*------------------------------- end of file --------------------------------*/