/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQLNCHRES                                               */
/* !Description     : TQLNCHRES Component.                                    */
/*                                                                            */
/* !Module          : TQLNCHRES                                               */
/* !Description     : Réserve de couple décollage                             */
/*                                                                            */
/* !File            : TQLNCHRES_FCT1.C                                        */
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
/*   1 / TQLNCHRES_vidInitOutput                                              */
/*   2 / TQLNCHRES_vidReserveCplDecollage                                     */
/*   3 / TQLNCHRES_vidReserve_decollage                                       */
/*   4 / TQLNCHRES_vidCondition_decollage                                     */
/*   5 / TQLNCHRES_vidCondition_vitesse                                       */
/*   6 / TQLNCHRES_vidCalcul_reserve                                          */
/*   7 / TQLNCHRES_vidCluPedLnchCdn                                           */
/*   8 / TQLNCHRES_vidSpdVehLnchCdn                                           */
/*   9 / TQLNCHRES_vidAccPedLnchCdn                                           */
/*   10 / TQLNCHRES_vidEngRunLnchCdn                                          */
/*                                                                            */
/* !Reference   : V02 NT 10 04984 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0175 / 2                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQLNCHRES/TQLNCHR$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "GDGAR.h"
#include "TQLNCHRES.h"
#include "TQLNCHRES_L.h"
#include "TQLNCHRES_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidInitOutput                                    */
/* !Description :  Cette fonction permet l'initialisation des variables de    */
/*                 sortie.                                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 TqRes_tqLnchRes;                                            */
/*  output boolean TQLNCHRES_bCdnExtrCluPPrev;                                */
/*  output boolean TQLNCHRES_bCdnCluLnchResInPrev;                            */
/*  output boolean TQLNCHRES_bCdnSpdLnchResInPrev;                            */
/*  output boolean TQLNCHRES_bCdnNEngLnchResInPrev;                           */
/*  output boolean TQLNCHRES_bRateLimiterSwitchPrev;                          */
/*  output boolean TqRes_bCdnNEngLnchRes_MP;                                  */
/*  output uint16 TQLNCHRES_u16tiCluTempo;                                    */
/*  output uint16 TQLNCHRES_u16tiSpdVehTempo;                                 */
/*  output uint16 TQLNCHRES_u16tiLoCkSpdTempo;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidInitOutput(void)
{
   VEMS_vidSET(TqRes_tqLnchRes, 0);

   TQLNCHRES_bCdnExtrCluPPrev = 0;
   TQLNCHRES_bCdnCluLnchResInPrev = 0;
   TQLNCHRES_bCdnSpdLnchResInPrev = 0;
   TQLNCHRES_bCdnNEngLnchResInPrev = 0;
   TQLNCHRES_bRateLimiterSwitchPrev = 0;

   TqRes_bCdnNEngLnchRes_MP = 0;

   TQLNCHRES_u16tiCluTempo = 0;
   TQLNCHRES_u16tiSpdVehTempo = 0;
   TQLNCHRES_u16tiLoCkSpdTempo = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidReserveCplDecollage                           */
/* !Description :  Cette fonction autorise l'application de la fonction       */
/*                 "Réserve de Couple Décollage" sous la condition Ext_stGBxCf*/
/*                 = 0.                                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04984_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQLNCHRES_vidReserve_decollage();                        */
/*  input uint8 Ext_stGBxCf;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidReserveCplDecollage(void)
{
   uint8 u8LocalExt_stGBxCf;

   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (u8LocalExt_stGBxCf == 0)
   {
      TQLNCHRES_vidReserve_decollage();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidReserve_decollage                             */
/* !Description :  La  réserve  de  couple  spécifique  au  décollage  dépend */
/*                 de  la  température  d’eau  et  du  régime,  cette réserve */
/*                 est activée suivant un des quatre critères  : switch       */
/*                 embrayage, vitesse véhicule, pied  levé et moteur en sous  */
/*                 régime                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04984_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLNCHRES_vidCondition_decollage();                      */
/*  extf argret void TQLNCHRES_vidCondition_vitesse();                        */
/*  extf argret void TQLNCHRES_vidCalcul_reserve();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidReserve_decollage(void)
{
   TQLNCHRES_vidCondition_decollage();
   TQLNCHRES_vidCondition_vitesse();
   TQLNCHRES_vidCalcul_reserve();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidCondition_decollage                           */
/* !Description :  Cette fonction évalue les différentes conditions           */
/*                 d'activation de la condition de décollage.                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04984_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLNCHRES_vidCluPedLnchCdn();                            */
/*  extf argret void TQLNCHRES_vidSpdVehLnchCdn();                            */
/*  extf argret void TQLNCHRES_vidAccPedLnchCdn();                            */
/*  extf argret void TQLNCHRES_vidEngRunLnchCdn();                            */
/*  input boolean TqRes_bCdnCluLnchRes_MP;                                    */
/*  input boolean TqRes_bCdnSpdLnchRes_MP;                                    */
/*  input boolean TqRes_bCdnAccLnchRes_MP;                                    */
/*  input boolean TqRes_bCdnNEngLnchRes_MP;                                   */
/*  output boolean TqRes_bCdnLnchRes;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidCondition_decollage(void)
{
   TQLNCHRES_vidCluPedLnchCdn();
   TQLNCHRES_vidSpdVehLnchCdn();
   TQLNCHRES_vidAccPedLnchCdn();
   TQLNCHRES_vidEngRunLnchCdn();

   if (  (TqRes_bCdnCluLnchRes_MP != 0)
      || (TqRes_bCdnSpdLnchRes_MP != 0)
      || (TqRes_bCdnAccLnchRes_MP != 0)
      || (TqRes_bCdnNEngLnchRes_MP !=0))
   {
      TqRes_bCdnLnchRes = 1 ;
   }
   else
   {
      TqRes_bCdnLnchRes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidCondition_vitesse                             */
/* !Description :  La condition de la vitesse s’active si la vitesse est      */
/*                 inférieure à un seuil minimum calibrable. Elle se désactive*/
/*                 après une temporisation calibrable si la vitesse devient   */
/*                 supérieure à un seuil maximum calibrable aussi.            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04984_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 TqRes_spdThrLoLnchRes_C;                                      */
/*  input uint8 TqRes_spdThrHiLnchRes_C;                                      */
/*  input boolean TQLNCHRES_bCdnSpdLnchResInPrev;                             */
/*  input uint16 TQLNCHRES_u16tiSpdVehTempo;                                  */
/*  input uint8 TqRes_tiCdnSpdLnchRes_C;                                      */
/*  output boolean TQLNCHRES_bCdnSpdLnchResInPrev;                            */
/*  output uint16 TQLNCHRES_u16tiSpdVehTempo;                                 */
/*  output boolean TqRes_bCdnSpdLnchRes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidCondition_vitesse(void)
{
   boolean bLocalDft_spdVeh;
   boolean bLocalCdnSpdLnchResIn;
   boolean bLocalCdnSpdLnchResOut;
   uint16  u16LocalVeh_SpdVeh;
   uint16  u16LocalTqRes_spdThrLoLnchRes;
   uint16  u16LocalTqRes_spdThrHiLnchRes;
   uint16  u16LocalTiSpdVehTempo;


   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_SpdVeh);
   bLocalDft_spdVeh = GDGAR_bGetFRM(FRM_FRM_DFT_SPDVEH);

   u16LocalTqRes_spdThrLoLnchRes = (uint16)(TqRes_spdThrLoLnchRes_C * 32);
   u16LocalTqRes_spdThrHiLnchRes = (uint16)(TqRes_spdThrHiLnchRes_C * 32);

   /* Computing Turn-Off Delay's input */
   if (u16LocalVeh_SpdVeh <= u16LocalTqRes_spdThrLoLnchRes)
   {
      bLocalCdnSpdLnchResIn = 1;
   }
   else
   {
      if (u16LocalVeh_SpdVeh >= u16LocalTqRes_spdThrHiLnchRes)
      {
         bLocalCdnSpdLnchResIn = 0;
      }
      else
      {
         bLocalCdnSpdLnchResIn = TQLNCHRES_bCdnSpdLnchResInPrev;
      }
   }

   /* Computing Turn-Off Delay's internal counter and output */
   if (bLocalCdnSpdLnchResIn != 0)
   {
      bLocalCdnSpdLnchResOut = 1;
      TQLNCHRES_bCdnSpdLnchResInPrev = 1;
      TQLNCHRES_u16tiSpdVehTempo =
         (uint16)MATHSRV_udtMIN(TQLNCHRES_u16tiSpdVehTempo, 1500);
   }
   else
   {
      if (TQLNCHRES_bCdnSpdLnchResInPrev != 0)
      {
         u16LocalTiSpdVehTempo =(uint16)((TqRes_tiCdnSpdLnchRes_C * 25) / 4);
         TQLNCHRES_u16tiSpdVehTempo =
            (uint16)MATHSRV_udtMIN(u16LocalTiSpdVehTempo, 1500);
         TQLNCHRES_bCdnSpdLnchResInPrev = 0;
      }
      else
      {
         if (TQLNCHRES_u16tiSpdVehTempo > 0)
         {
            u16LocalTiSpdVehTempo = (uint16)(TQLNCHRES_u16tiSpdVehTempo - 1);
            TQLNCHRES_u16tiSpdVehTempo =
               (uint16)MATHSRV_udtMIN(u16LocalTiSpdVehTempo, 1500);
         }
      }

      if (TQLNCHRES_u16tiSpdVehTempo == 0)
      {
         bLocalCdnSpdLnchResOut = 0;
      }
      else
      {
         bLocalCdnSpdLnchResOut = 1;
      }
   }

   /* Computing function's output */
   if (  (bLocalDft_spdVeh != 0)
      || (bLocalCdnSpdLnchResOut != 0))
   {
      TqRes_bCdnSpdLnchRes = 1;
   }
   else
   {
      TqRes_bCdnSpdLnchRes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidCalcul_reserve                                */
/* !Description :  La  variable  réserve  de  couple  décollage  varie  entre */
/*                 la  valeur  0  et  une  valeur  maximum  déduite  d’une    */
/*                 cartographie calibrable dont les entrées sont le régime    */
/*                 moteur et la température de l’eau.                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04984_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 TqDem_tqCkEfc;                                               */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint8 TqRes_tCo_A[8];                                               */
/*  input uint16 TqRes_tqCkEfc_A[8];                                          */
/*  input uint16 TqRes_tqLnchRes_M[8][8];                                     */
/*  input boolean TqRes_bCdnLnchRes;                                          */
/*  input boolean TqRes_bCdnSpdLnchRes;                                       */
/*  input boolean TQLNCHRES_bRateLimiterSwitchPrev;                           */
/*  input uint16 TqRes_tqLnchResMax_MP;                                       */
/*  input uint16 TqRes_tqIncMaxLnchRes_C;                                     */
/*  input sint16 TqRes_tqDecMaxLnchRes_C;                                     */
/*  input uint16 TqRes_tqLnchRes;                                             */
/*  output uint16 TqRes_tqLnchResMax_MP;                                      */
/*  output boolean TQLNCHRES_bRateLimiterSwitchPrev;                          */
/*  output uint16 TqRes_tqLnchRes;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidCalcul_reserve(void)
{
   boolean bLocalRateLimiterSwitch;
   boolean bLocalRateLimiterEna;
   uint8   u8LocalExt_tCoMes;
   uint16  u16LocalTqDem_tqCkEfc;
   uint16  u16LocalTqRes_tqIdlRes;
   uint16  u16LocalTqRes_tqLnchResIn;
   uint16  u16LocalTqRes_tqLnchResOut;
   uint16  u16LocalTqRes_tqLnchResInc;
   uint16  u16LocalTqRes_tqLnchResDec;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalInterp;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalTqDem_tqCkEfc;
   sint16  s16LocalTqRes_tqLnchResDec;
   sint32  s32LocalExt_tCoMes;
   sint32  s32LocalTqDem_tqCkEfc;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(TqDem_tqCkEfc, s16LocalTqDem_tqCkEfc);
   VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);

   /* Computing input of X-Breakpoint table */
   s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes, 0, 254);

   /* Computing input of Y-Breakpoint table */
   s32LocalTqDem_tqCkEfc = (sint32)(s16LocalTqDem_tqCkEfc + 1600);
   u16LocalTqDem_tqCkEfc = (uint16)MATHSRV_udtCLAMP(s32LocalTqDem_tqCkEfc,
                                                    0,
                                                    3200);

   /* Computing interpolation result */
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(TqRes_tCo_A,
                                               u8LocalExt_tCoMes,
                                               8);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(TqRes_tqCkEfc_A,
                                                u16LocalTqDem_tqCkEfc,
                                                8);
   u16LocalInterp = MATHSRV_u16Interp2d(&TqRes_tqLnchRes_M[0][0],
                                        u16LocalParaX,
                                        u16LocalParaY,
                                        8);
   TqRes_tqLnchResMax_MP = (uint16)MATHSRV_udtMIN(u16LocalInterp, 1600);

   /* Computing Rate Limiter's activation */
   if (  (TqRes_bCdnLnchRes != 0)
      && (TqRes_bCdnSpdLnchRes != 0))
   {
      bLocalRateLimiterSwitch = 1;
   }
   else
   {
      bLocalRateLimiterSwitch = 0;
   }

   if (  (bLocalRateLimiterSwitch != 0)
      && (TQLNCHRES_bRateLimiterSwitchPrev == 0))
   {
      bLocalRateLimiterEna = 0;
   }
   else
   {
      bLocalRateLimiterEna = 1;
   }
   TQLNCHRES_bRateLimiterSwitchPrev = bLocalRateLimiterSwitch;

   /* Computing Rate Limiter's output */
   if (bLocalRateLimiterEna == 0)
   {
      u16LocalTqRes_tqLnchResOut = u16LocalTqRes_tqIdlRes;
   }
   else
   {
      /* Selecting Rate Limiter's input */
      if (bLocalRateLimiterSwitch == 0)
      {
         u16LocalTqRes_tqLnchResIn = 0;
      }
      else
      {
         u16LocalTqRes_tqLnchResIn = TqRes_tqLnchResMax_MP;
      }

      /* Computing Rate Limiter's thresholds */
      u16LocalTqRes_tqLnchResInc =
         (uint16)(TqRes_tqIncMaxLnchRes_C / 25);
      s16LocalTqRes_tqLnchResDec =
         (sint16)((TqRes_tqDecMaxLnchRes_C * (-1)) / 25);
      u16LocalTqRes_tqLnchResDec =
         (uint16)MATHSRV_udtMAX(s16LocalTqRes_tqLnchResDec, 0);

      VEMS_vidGET(TqRes_tqLnchRes, u16LocalTqRes_tqLnchResOut);

      u16LocalTqRes_tqLnchResOut =
         MATHSRV_u16SlewFilter(u16LocalTqRes_tqLnchResOut,
                               u16LocalTqRes_tqLnchResIn,
                               u16LocalTqRes_tqLnchResInc,
                               u16LocalTqRes_tqLnchResDec);
   }

   u16LocalTqRes_tqLnchResOut =
      (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqLnchResOut, 1600);
   VEMS_vidSET(TqRes_tqLnchRes, u16LocalTqRes_tqLnchResOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidCluPedLnchCdn                                 */
/* !Description :  Production de TqRes_bCdnCluLnchRes_MP.                     */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input uint8 Ext_rCluP;                                                    */
/*  input uint8 TqRes_rCluThrLnchRes_C;                                       */
/*  input boolean TqRes_bCfCluLnchRes_C;                                      */
/*  input boolean TQLNCHRES_bCdnExtrCluPPrev;                                 */
/*  input uint16 TQLNCHRES_u16tiCluTempo;                                     */
/*  input boolean TQLNCHRES_bCdnCluLnchResInPrev;                             */
/*  input uint8 TqRes_tiCdnCluLnchRes_C;                                      */
/*  input boolean TqRes_bAcvCdnCluLnchRes_C;                                  */
/*  output boolean TQLNCHRES_bCdnExtrCluPPrev;                                */
/*  output boolean TQLNCHRES_bCdnCluLnchResInPrev;                            */
/*  output uint16 TQLNCHRES_u16tiCluTempo;                                    */
/*  output boolean TqRes_bCdnCluLnchRes_MP;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidCluPedLnchCdn(void)
{
   boolean bLocalExt_bCluPedPrss;
   boolean bLocalCdnExt_rCluP;
   boolean bLocalCdnCluLnchResIn;
   boolean bLocalCdnCluLnchResOut;
   uint8   u8LocalExt_rCluP;
   uint16  u16LocalTiCluTempo;


   VEMS_vidGET(Ext_bCluPedPrss, bLocalExt_bCluPedPrss);
   VEMS_vidGET(Ext_rCluP, u8LocalExt_rCluP);

   /* Evaluating condition on "Ext_rCluP" */
   if (u8LocalExt_rCluP < TqRes_rCluThrLnchRes_C)
   {
      bLocalCdnExt_rCluP = 1;
   }
   else
   {
      bLocalCdnExt_rCluP = 0;
   }

   /* Computing Turn-Off Delay's input */
   if (TqRes_bCfCluLnchRes_C == 0)
   {
      if (bLocalExt_bCluPedPrss != 0)
      {
         bLocalCdnCluLnchResIn = 1;
      }
      else
      {
         bLocalCdnCluLnchResIn = 0;
      }
   }
   else
   {
      if (bLocalCdnExt_rCluP != 0)
      {
         if (TQLNCHRES_bCdnExtrCluPPrev == 0)
         {
            bLocalCdnCluLnchResIn = 1;
         }
         else
         {
            bLocalCdnCluLnchResIn = 0;
         }
      }
      else
      {
         bLocalCdnCluLnchResIn = 0;
      }
   }

   TQLNCHRES_bCdnExtrCluPPrev = bLocalCdnExt_rCluP;

   /* Computing Turn-Off Delay's internal counter and output */
   if (bLocalCdnCluLnchResIn != 0)
   {
      bLocalCdnCluLnchResOut = 1;
      TQLNCHRES_bCdnCluLnchResInPrev = 1;
      TQLNCHRES_u16tiCluTempo = (uint16)MATHSRV_udtMIN(TQLNCHRES_u16tiCluTempo,
                                                       1500);
   }
   else
   {
      if (TQLNCHRES_bCdnCluLnchResInPrev != 0)
      {
         u16LocalTiCluTempo = (uint16)((TqRes_tiCdnCluLnchRes_C * 25) / 4);
         TQLNCHRES_u16tiCluTempo = (uint16)MATHSRV_udtMIN(u16LocalTiCluTempo,
                                                          1500);
         TQLNCHRES_bCdnCluLnchResInPrev = 0;
      }
      else
      {
         if (TQLNCHRES_u16tiCluTempo > 0)
         {
            u16LocalTiCluTempo = (uint16)(TQLNCHRES_u16tiCluTempo - 1);
            TQLNCHRES_u16tiCluTempo = (uint16)MATHSRV_udtMIN(u16LocalTiCluTempo,
                                                             1500);
         }
      }

      if (TQLNCHRES_u16tiCluTempo == 0)
      {
         bLocalCdnCluLnchResOut = 0;
      }
      else
      {
         bLocalCdnCluLnchResOut = 1;
      }
   }

   if (  (TqRes_bAcvCdnCluLnchRes_C != 0)
      && (bLocalCdnCluLnchResOut != 0))
   {
      TqRes_bCdnCluLnchRes_MP = 1;
   }
   else
   {
      TqRes_bCdnCluLnchRes_MP = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidSpdVehLnchCdn                                 */
/* !Description :  Production de TqRes_bCdnSpdLnchRes_MP.                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean TqRes_bAcvCdnSpdLnchRes_C;                                  */
/*  output boolean TqRes_bCdnSpdLnchRes_MP;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidSpdVehLnchCdn(void)
{
   boolean bLocalDft_spdVeh;
   uint16  u16LocalVeh_spdVeh;


   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   bLocalDft_spdVeh = GDGAR_bGetFRM(FRM_FRM_DFT_SPDVEH);

   if (  (TqRes_bAcvCdnSpdLnchRes_C != 0)
      && (u16LocalVeh_spdVeh > 0)
      && (bLocalDft_spdVeh == 0))
   {
      TqRes_bCdnSpdLnchRes_MP = 1;
   }
   else
   {
      TqRes_bCdnSpdLnchRes_MP = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidAccPedLnchCdn                                 */
/* !Description :  Production de TqRes_bCdnAccLnchRes_MP.                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint8 TqRes_rAccThrLnchRes_C;                                       */
/*  input boolean TqRes_bAcvCdnAccLnchRes_C;                                  */
/*  output boolean TqRes_bCdnAccLnchRes_MP;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidAccPedLnchCdn(void)
{
   boolean bLocalDft_spdVeh;
   uint16  u16LocalAccP_rAccP;
   uint16  u16LocalTqRes_rAccPThr;


   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   bLocalDft_spdVeh = GDGAR_bGetFRM(FRM_FRM_DFT_SPDVEH);

   u16LocalTqRes_rAccPThr = (uint16)(TqRes_rAccThrLnchRes_C * 64);

   if (  (TqRes_bAcvCdnAccLnchRes_C != 0)
      && (u16LocalAccP_rAccP >= u16LocalTqRes_rAccPThr)
      && (bLocalDft_spdVeh == 0))
   {
      TqRes_bCdnAccLnchRes_MP = 1;
   }
   else
   {
      TqRes_bCdnAccLnchRes_MP = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLNCHRES_vidEngRunLnchCdn                                 */
/* !Description :  Production de TqRes_bCdnNEngLnchRes_MP.                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 TqRes_nEngOfsLnchRes_C;                                      */
/*  input uint16 TQLNCHRES_u16tiLoCkSpdTempo;                                 */
/*  input boolean TQLNCHRES_bCdnNEngLnchResInPrev;                            */
/*  input uint8 TqRes_tiCdnNEngLnchRes_C;                                     */
/*  output boolean TqRes_bCdnNEngLnchRes_MP;                                  */
/*  output boolean TQLNCHRES_bCdnNEngLnchResInPrev;                           */
/*  output uint16 TQLNCHRES_u16tiLoCkSpdTempo;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLNCHRES_vidEngRunLnchCdn(void)
{
   boolean bLocalTqSys_bEngNOnIdl;
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalCdnNEngLnchResIn;
   uint16  u16LocalTiLoCkSpdTempo;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalTqSys_nTarIdl;
   sint32  s32LocalTardLoSpd;


   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);
   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);

   s32LocalTardLoSpd = (sint32)( u16LocalTqSys_nTarIdl
                               - (4 * TqRes_nEngOfsLnchRes_C));

   /* Computing Turn-Off Delay's input */
   if (  (bLocalTqSys_bEngNOnIdl != 0)
      && (bLocalCoPTSt_bEngRun != 0)
      && ((sint32)u16LocalEng_nCkFil < s32LocalTardLoSpd))
   {
      bLocalCdnNEngLnchResIn = 1;
   }
   else
   {
      bLocalCdnNEngLnchResIn = 0;
   }

   /* Computing Turn-Off Delay's internal counter and output */
   if (bLocalCdnNEngLnchResIn != 0)
   {
      TqRes_bCdnNEngLnchRes_MP = 1;
      TQLNCHRES_bCdnNEngLnchResInPrev = 1;
      TQLNCHRES_u16tiLoCkSpdTempo =
         (uint16)MATHSRV_udtMIN(TQLNCHRES_u16tiLoCkSpdTempo, 1500);
   }
   else
   {
      if (TQLNCHRES_bCdnNEngLnchResInPrev != 0)
      {
         u16LocalTiLoCkSpdTempo = (uint16)((TqRes_tiCdnNEngLnchRes_C * 25) / 4);
         TQLNCHRES_u16tiLoCkSpdTempo =
            (uint16)MATHSRV_udtMIN(u16LocalTiLoCkSpdTempo, 1500);
         TQLNCHRES_bCdnNEngLnchResInPrev = 0;
      }
      else
      {
         if (TQLNCHRES_u16tiLoCkSpdTempo > 0)
         {
            u16LocalTiLoCkSpdTempo = (uint16)(TQLNCHRES_u16tiLoCkSpdTempo - 1);
            TQLNCHRES_u16tiLoCkSpdTempo =
               (uint16)MATHSRV_udtMIN(u16LocalTiLoCkSpdTempo, 1500);
         }
      }

      if (TQLNCHRES_u16tiLoCkSpdTempo == 0)
      {
         TqRes_bCdnNEngLnchRes_MP = 0;
      }
      else
      {
         TqRes_bCdnNEngLnchRes_MP = 1;
      }
   }
}

/*------------------------------ end of file ---------------------------------*/