/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGREQH                                                 */
/* !Description     : ENGREQH component.                                      */
/*                                                                            */
/* !Module          : ENGREQH                                                 */
/* !Description     : ERH                                                     */
/*                                                                            */
/* !File            : ENGREQH_FCT2.C                                          */
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
/*   1 / ENGREQH_vidCondTemperAirAutoStop                                     */
/*   2 / ENGREQH_vidChoixTemperatureAir                                       */
/*   3 / ENGREQH_vidPartieFonctionTempAir                                     */
/*   4 / ENGREQH_vidPartieDisfoncTempAir                                      */
/*   5 / ENGREQH_vidCondTempCatalyAutStop                                     */
/*   6 / ENGREQH_vidCondSeuilBasTempCatal                                     */
/*   7 / ENGREQH_vidCondSeuilHautTempCata                                     */
/*   8 / ENGREQH_vidPartieDisfoncTempCata                                     */
/*   9 / ENGREQH_vidConTempCarTurbAutStop                                     */
/*   10 / ENGREQH_vidCondPresHuileAutoStop                                    */
/*                                                                            */
/* !Reference   : V02 NT 09 05960 / 08                                        */
/* !OtherRefs   : CSMT_CGMT08_2303 / 2.6                                      */
/* !OtherRefs   : VEMS V02 ECU#058179                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/ENGREQH/ENGREQH_FCT2.C$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ENGREQH.h"
#include "ENGREQH_L.h"
#include "ENGREQH_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondTemperAirAutoStop                           */
/* !Description :  Cette fonction autorise du STOP en fonction de règles liées*/
/*                 à la température d’air et de la température moteur. Cette  */
/*                 fonction est composée de 3 sous systèmes: sélection de la  */
/*                 température, partie fonctionnelle, partie dysfonc-         */
/*                 tionnelle.                                                 */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_011.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGREQH_vidChoixTemperatureAir();                        */
/*  extf argret void ENGREQH_vidPartieFonctionTempAir();                      */
/*  extf argret void ENGREQH_vidPartieDisfoncTempAir();                       */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input boolean EngReqH_bFctStopAuthTAir;                                   */
/*  input boolean EngReqH_bForcStopAuthTAir;                                  */
/*  output boolean EngReqH_bAuthStopSTTTAir;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondTemperAirAutoStop(void)
{
   boolean bLocalInhCdnStopTAirTCo;


   ENGREQH_vidChoixTemperatureAir();
   ENGREQH_vidPartieFonctionTempAir();
   ENGREQH_vidPartieDisfoncTempAir();
   bLocalInhCdnStopTAirTCo = GDGAR_bGetFRM(FRM_FRM_INHCDNSTOPTAIRTCO);
   if (bLocalInhCdnStopTAirTCo == 0)
   {
      EngReqH_bAuthStopSTTTAir = EngReqH_bFctStopAuthTAir;
   }
   else
   {
      EngReqH_bAuthStopSTTTAir = EngReqH_bForcStopAuthTAir;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidChoixTemperatureAir                             */
/* !Description :  Ce sous système fait partie de l’autorisation de stop en   */
/*                 fonction du couple température d’air / température d’eau.Il*/
/*                 permet de sélectionner au choix une température d’air.     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_012.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input sint8 Ext_tAir;                                                     */
/*  input sint16 Ext_tDsThrMes;                                               */
/*  input sint16 Ext_tAirUsCmprMes;                                           */
/*  input uint8 EngReqH_stForcTAirSel_C;                                      */
/*  input uint8 EngReqH_stTAirSel_C;                                          */
/*  input sint16 EngReqH_tAirVal_C;                                           */
/*  output sint16 EngReqH_tAirVal;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidChoixTemperatureAir(void)
{
   boolean bLocalSelTAirCdnStopTAirTCo;
   uint8   u8LocalSwitcher;
   sint8   s8LocalExt_tAir;
   sint16  s16LocalExt_tDsThrMes;
   sint16  s16LocalExt_tAirUsCmprMes;
   sint16  s16LocalEngReqH_tAirVal;


   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidGET(Ext_tDsThrMes, s16LocalExt_tDsThrMes);
   VEMS_vidGET(Ext_tAirUsCmprMes, s16LocalExt_tAirUsCmprMes);
   bLocalSelTAirCdnStopTAirTCo = GDGAR_bGetFRM(FRM_FRM_SELTAIRCDNSTOPTAIRTCO);

   if (bLocalSelTAirCdnStopTAirTCo != 0)
   {
      u8LocalSwitcher = EngReqH_stForcTAirSel_C;
   }
   else
   {
      u8LocalSwitcher = EngReqH_stTAirSel_C;
   }

   switch(u8LocalSwitcher)
   {
      case 0:
         s16LocalEngReqH_tAirVal = s8LocalExt_tAir;
         break;

      case 1:
         s16LocalEngReqH_tAirVal = s16LocalExt_tDsThrMes;
         break;

      case 2:
         s16LocalEngReqH_tAirVal = s16LocalExt_tAirUsCmprMes;
         break;

      case 3:
         s16LocalEngReqH_tAirVal = EngReqH_tAirVal_C;
         break;

      default:
         s16LocalEngReqH_tAirVal = EngReqH_tAirVal_C;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   EngReqH_tAirVal = (sint16)MATHSRV_udtCLAMP(s16LocalEngReqH_tAirVal,-50,200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidPartieFonctionTempAir                           */
/* !Description :  Ce sous système est la partie fonctionnelle de la fonction */
/*                 d’autorisation du stop sur des conditions liées au couple  */
/*                 température d’air / température d’eau.                     */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 EngReqH_tAirVal;                                             */
/*  input sint16 EngReqH_facTAirStopAuth_C;                                   */
/*  input sint16 EngReqH_tCoOfsStopAuth_C;                                    */
/*  input sint16 EngReqH_tAirMinStopAuth_C;                                   */
/*  input sint16 EngReqH_tCoMin_tAirStopAuth_C;                               */
/*  output boolean EngReqH_bFctStopAuthTAir;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidPartieFonctionTempAir(void)
{
   sint16 s16LocalExt_tCoMes;
   sint32 s32LocalMulti;
   sint32 s32LocalSum;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   s32LocalMulti = (sint32)((EngReqH_tAirVal * EngReqH_facTAirStopAuth_C)/10);
   s32LocalSum = (s32LocalMulti + EngReqH_tCoOfsStopAuth_C);

   if (  (EngReqH_tAirVal >= EngReqH_tAirMinStopAuth_C)
      || (s16LocalExt_tCoMes >= EngReqH_tCoMin_tAirStopAuth_C)
      || (s16LocalExt_tCoMes >= s32LocalSum))
   {
      EngReqH_bFctStopAuthTAir = 1;
   }
   else
   {
      EngReqH_bFctStopAuthTAir = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidPartieDisfoncTempAir                            */
/* !Description :  Ce sous système est la partie dysfonctionnelle             */
/*                 d’autorisation du STOP en fonction du couple température   */
/*                 d’air / température d’eau. Par calibration, elle offre     */
/*                 plusieurs possibilités de reconfiguration.                 */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_014.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 ENGREQH_u8CoPTStEngPrev;                                      */
/*  input boolean ENGREQH_bSwitchAuthTAirMem;                                 */
/*  input boolean EngReqH_bFctStopTAirMem_MP;                                 */
/*  input boolean EngReqH_bFctStopAuthTAir;                                   */
/*  input uint8 EngReqH_stTAirTCoDft_C;                                       */
/*  output boolean EngReqH_bFctStopTAirMem_MP;                                */
/*  output boolean ENGREQH_bSwitchAuthTAirMem;                                */
/*  output boolean EngReqH_bForcStopAuthTAir;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidPartieDisfoncTempAir(void)
{
   boolean bLocalInhCdnStopTAirTCo;
   uint8   u8LocalCoPTSt_stEng;


   bLocalInhCdnStopTAirTCo = GDGAR_bGetFRM(FRM_FRM_INHCDNSTOPTAIRTCO);
   VEMS_vidGET(CoPTSt_stEng,u8LocalCoPTSt_stEng);
   /*Production of EngReqH_bFctStopTAirMem_MP */
   if (  (u8LocalCoPTSt_stEng == 3)
      && (ENGREQH_u8CoPTStEngPrev != 3))
   {
      EngReqH_bFctStopTAirMem_MP = 0;
   }
   else
   {
      EngReqH_bFctStopTAirMem_MP = ENGREQH_bSwitchAuthTAirMem;
   }
   if (bLocalInhCdnStopTAirTCo != 0)
   {
      ENGREQH_bSwitchAuthTAirMem = EngReqH_bFctStopTAirMem_MP;
   }
   else
   {
      ENGREQH_bSwitchAuthTAirMem = EngReqH_bFctStopAuthTAir;
   }
   /*Production of EngReqH_bForcStopAuthTAir*/
   switch (EngReqH_stTAirTCoDft_C)
   {
      case 0:
         EngReqH_bForcStopAuthTAir = EngReqH_bFctStopAuthTAir;
         break;

      case 1:
         EngReqH_bForcStopAuthTAir = 1;
         break;

      case 2:
         EngReqH_bForcStopAuthTAir = ENGREQH_bSwitchAuthTAirMem;
         break;

      case 3:
         EngReqH_bForcStopAuthTAir = 0;
         break;

      default:
         EngReqH_bForcStopAuthTAir = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondTempCatalyAutStop                           */
/* !Description :  Cette fonction autorise le STOP fonction de la température */
/*                 du catalyseur. Elle comprend une partie instaurant une     */
/*                 limite basse, une autre une limite haute et une partie     */
/*                 dysfonctionnelle.                                          */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGREQH_vidCondSeuilBasTempCatal();                      */
/*  extf argret void ENGREQH_vidCondSeuilHautTempCata();                      */
/*  extf argret void ENGREQH_vidPartieDisfoncTempCata();                      */
/*  input boolean EngReqH_bForcCdnStopSTTTOxC;                                */
/*  input boolean EngReqH_bFctAuthStopSTTTOxCHi;                              */
/*  output boolean EngReqH_bAuthStopSTTTOxC;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondTempCatalyAutStop(void)
{
   ENGREQH_vidCondSeuilBasTempCatal();
   ENGREQH_vidCondSeuilHautTempCata();
   ENGREQH_vidPartieDisfoncTempCata();
   if ( (EngReqH_bForcCdnStopSTTTOxC !=0)
      &&(EngReqH_bFctAuthStopSTTTOxCHi != 0))
   {
      EngReqH_bAuthStopSTTTOxC = 1;
   }
   else
   {
      EngReqH_bAuthStopSTTTOxC = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondSeuilBasTempCatal                           */
/* !Description :  Ce sous système est la partie fonctionnelle d’autorisation */
/*                 du stop en fonction de la température du catalyseur.       */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_016.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean OxC_bIntrHeat;                                              */
/*  input sint16 ExM_tOxCEstim;                                               */
/*  input uint16 OxC_facDmgOxC;                                               */
/*  input sint16 CoPTSt_tCoMesStrt;                                           */
/*  input boolean EOM_bTWCHeatPha;                                            */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 EngReqH_facDmgOxCX_A[4];                                     */
/*  input uint8 EngReqH_tCoMesStrtY_A[6];                                     */
/*  input uint16 EngReqH_tOxCMinHeatStopAuth_M[4][6];                         */
/*  input uint16 EngReqH_tOxCMinStopAuth_M[4][6];                             */
/*  input boolean ENGREQH_bOutRSLatchSTTTOxCLo;                               */
/*  input uint16 EngReqH_tOxCMinHeatStopAuth_MP;                              */
/*  input uint16 EngReqH_tOxCMinStopAuth_MP;                                  */
/*  output uint16 EngReqH_tOxCMinHeatStopAuth_MP;                             */
/*  output uint16 EngReqH_tOxCMinStopAuth_MP;                                 */
/*  output boolean ENGREQH_bOutRSLatchSTTTOxCLo;                              */
/*  output boolean EngReqH_bFctAuthStopSTTTOxCLo;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondSeuilBasTempCatal(void)
{
   boolean bLocalOxC_bIntrHeat;
   boolean bLocalEOM_bTWCHeatPha;
   uint8   u8LocalSiteInterpolation;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalCalcParaX;
   uint16  u16LocalCalcParaY;
   uint16  u16LocalCalcInterp_1;
   uint16  u16LocalCalcInterp_2;
   uint16  u16LocalOxC_facDmgOxC;
   sint16  s16LocalDiff;
   sint16  s16LocalExM_tOxCEstim;
   sint16  s16LocalCoPTSt_tCoMesStrt;
   sint32  s32Localsum;
   sint32  s32LocalEngReqHTOxCMinHeatStop;
   sint32  s32LocalEngReqHTOxCMinStopAuth;


   VEMS_vidGET(OxC_bIntrHeat, bLocalOxC_bIntrHeat);
   VEMS_vidGET(ExM_tOxCEstim, s16LocalExM_tOxCEstim);
   VEMS_vidGET(OxC_facDmgOxC, u16LocalOxC_facDmgOxC);
   VEMS_vidGET(CoPTSt_tCoMesStrt, s16LocalCoPTSt_tCoMesStrt);
   VEMS_vidGET(EOM_bTWCHeatPha, bLocalEOM_bTWCHeatPha);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(EngReqH_facDmgOxCX_A,
                                                    u16LocalOxC_facDmgOxC,
                                                    4);
   s32Localsum = (sint32)(s16LocalCoPTSt_tCoMesStrt + 40 );
   u8LocalSiteInterpolation = (uint8)MATHSRV_udtCLAMP(s32Localsum,0,254);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(EngReqH_tCoMesStrtY_A,
                                                   u8LocalSiteInterpolation,
                                                   6);
   /*Production of EngReqH_tOxCMinHeatStopAuth_MP*/
   u16LocalCalcInterp_1 =
      MATHSRV_u16Interp2d(&EngReqH_tOxCMinHeatStopAuth_M [0][0],
                           u16LocalCalcParaX,
                           u16LocalCalcParaY,
                           6);
   s32LocalEngReqHTOxCMinHeatStop = (sint32)(u16LocalCalcInterp_1 - 5);
   EngReqH_tOxCMinHeatStopAuth_MP =
      (uint16)MATHSRV_udtCLAMP(s32LocalEngReqHTOxCMinHeatStop, 0, 1050);
   /*Production of EngReqH_tOxCMinStopAuth_MP*/
   u16LocalCalcInterp_2 =
      MATHSRV_u16Interp2d(&EngReqH_tOxCMinStopAuth_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          6);
   s32LocalEngReqHTOxCMinStopAuth = (sint32)(u16LocalCalcInterp_2 - 5);
   EngReqH_tOxCMinStopAuth_MP =
      (uint16)MATHSRV_udtCLAMP(s32LocalEngReqHTOxCMinStopAuth, 0, 1050);
   /* bascule RS (R Prioritaire): Q = !R . (S + Q) */
   if (u8LocalCoPTSt_stEng == 3)
   {
      ENGREQH_bOutRSLatchSTTTOxCLo = 0;
      EngReqH_bFctAuthStopSTTTOxCLo = 0;
   }
   else
   {
      if( bLocalEOM_bTWCHeatPha != 0)
      {
         ENGREQH_bOutRSLatchSTTTOxCLo = 1;
      }
      if(ENGREQH_bOutRSLatchSTTTOxCLo !=0)
      {
         if(bLocalOxC_bIntrHeat !=0)
         {
            EngReqH_bFctAuthStopSTTTOxCLo = 1;
         }
         else
         {
            s16LocalDiff = (sint16)(EngReqH_tOxCMinHeatStopAuth_MP - 50);
            if(s16LocalExM_tOxCEstim>= s16LocalDiff)
            {
               EngReqH_bFctAuthStopSTTTOxCLo = 1;
            }
         }
      }
      else
      {
         s16LocalDiff = (sint16)(EngReqH_tOxCMinStopAuth_MP - 50);
         if (s16LocalExM_tOxCEstim >= s16LocalDiff)
         {
            EngReqH_bFctAuthStopSTTTOxCLo = 1;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondSeuilHautTempCata                           */
/* !Description :  Cette fonction surveille la température catalyseur par     */
/*                 rapport à un seuil haut. La condition  peut être forcée à 1*/
/*                 par  calibration ou en cas de défaillance sur la           */
/*                 température catalyseur.                                    */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_017.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input uint16 OxC_facDmgOxC;                                               */
/*  input sint16 ExM_tOxCEstim;                                               */
/*  input uint16 EngReqH_facDmgOxCX_A[4];                                     */
/*  input uint16 EngReqH_tOxCHiLimSTTRstrtReq_T[4];                           */
/*  input sint16 EngReqH_tOxCHysLimRstrtReq_C;                                */
/*  input boolean EngReqH_bDeacRstrtTOxCMax_C;                                */
/*  input boolean TPM_bInhInjCutOff;                                          */
/*  input boolean ENGREQH_bHysteresisOutput;                                  */
/*  output boolean ENGREQH_bHysteresisOutput;                                 */
/*  output boolean EngReqH_bFctAuthStopSTTTOxCHi;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondSeuilHautTempCata(void)
{
   boolean bLocalInhCdnAuthStopTOxC;
   boolean bLocalTPM_bInhInjCutOff;
   uint16  u16LocalOxC_facDmgOxC;
   uint16  u16LocalCalcPara;
   uint16  u16Localinterp;
   sint16  s16LocalExM_tOxCEstim;
   sint32  s32LocalLow;
   sint32  s32LocalHigh;


   VEMS_vidGET(OxC_facDmgOxC,u16LocalOxC_facDmgOxC);
   VEMS_vidGET(ExM_tOxCEstim,s16LocalExM_tOxCEstim);
   bLocalInhCdnAuthStopTOxC = GDGAR_bGetFRM(FRM_FRM_INHCDNAUTHSTOPTOXC);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(EngReqH_facDmgOxCX_A,
                                                   u16LocalOxC_facDmgOxC,
                                                   4);
   u16Localinterp = MATHSRV_u16Interp1d(EngReqH_tOxCHiLimSTTRstrtReq_T,
                                        u16LocalCalcPara);
   s32LocalLow = (sint32)(u16Localinterp - EngReqH_tOxCHysLimRstrtReq_C - 55);
   /*NegHys*/
   s32LocalHigh = (sint32)(u16Localinterp - 55);
   if (s16LocalExM_tOxCEstim >= s32LocalHigh)
   {
      ENGREQH_bHysteresisOutput = 0;
   }
   else
   {
      if (s16LocalExM_tOxCEstim <= s32LocalLow)
      {
         ENGREQH_bHysteresisOutput = 1;
      }
   }

   if (  (bLocalInhCdnAuthStopTOxC != 0)
      || (EngReqH_bDeacRstrtTOxCMax_C != 0))
   {
      EngReqH_bFctAuthStopSTTTOxCHi = 1;
   }
   else
   {
      VEMS_vidGET(TPM_bInhInjCutOff, bLocalTPM_bInhInjCutOff);
      if (  (ENGREQH_bHysteresisOutput != 0)
         && (bLocalTPM_bInhInjCutOff == 0))
      {
         EngReqH_bFctAuthStopSTTTOxCHi = 1;
      }
      else
      {
         EngReqH_bFctAuthStopSTTTOxCHi = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidPartieDisfoncTempCata                           */
/* !Description :  partie_disfonctionnelle_seuil_bas_temperature_catalyseur . */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_018.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input uint32 EOM_tiEngRun;                                                */
/*  input uint32 EngReqH_tiDlyTOxC_C;                                         */
/*  input boolean EngReqH_bDeacCdnSTTTOxCMin_C;                               */
/*  input boolean EngReqH_bFctAuthStopSTTTOxCLo;                              */
/*  output boolean EngReqH_bForcCdnStopSTTTOxC;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidPartieDisfoncTempCata(void)
{
   boolean bLocalInhCdnAuthStopTOxC;
   uint32  u32LocalEOM_tiEngRun;


   VEMS_vidGET(EOM_tiEngRun,u32LocalEOM_tiEngRun);
   bLocalInhCdnAuthStopTOxC = GDGAR_bGetFRM(FRM_FRM_INHCDNAUTHSTOPTOXC);
   if (  (u32LocalEOM_tiEngRun >= EngReqH_tiDlyTOxC_C)
      || (bLocalInhCdnAuthStopTOxC != 0)
      || (EngReqH_bDeacCdnSTTTOxCMin_C != 0))
   {
      EngReqH_bForcCdnStopSTTTOxC = 1;
   }
   else
   {
      EngReqH_bForcCdnStopSTTTOxC = EngReqH_bFctAuthStopSTTTOxCLo;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidConTempCarTurbAutStop                           */
/* !Description :  Ce sous système calcule l’autorisation du stop en fonction */
/*                 de la température carter turbine. On autorise le stop si la*/
/*                 température du carter turbine est inférieure à un seuil    */
/*                 calibrable.                                                */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_042.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PhyMSI_tTrbCaseEstim;                                        */
/*  input sint16 EngReqH_tTrbMaxStopAuth_C;                                   */
/*  input uint8 EngReqH_tTrbHysMaxStopAuth_C;                                 */
/*  output boolean EngReqH_bAuthStopSTTTTrb;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidConTempCarTurbAutStop(void)
{
   uint16 u16LocalPhyMSI_tTrbCaseEstim;
   sint32 s32LocalDiff;
   sint32 s32LocalHigh;
   sint32 s32LocalLow;


   VEMS_vidGET(PhyMSI_tTrbCaseEstim, u16LocalPhyMSI_tTrbCaseEstim);

   /* Production of EngReqH_bAuthStopSTTTTrb */
   s32LocalDiff = (sint32)( EngReqH_tTrbMaxStopAuth_C
                          - EngReqH_tTrbHysMaxStopAuth_C);
   s32LocalHigh = (sint32)((EngReqH_tTrbMaxStopAuth_C + 273) * 32);
   s32LocalLow = (s32LocalDiff + 273) * 32;
   if (u16LocalPhyMSI_tTrbCaseEstim >= s32LocalHigh)
   {
      EngReqH_bAuthStopSTTTTrb = 0;
   }
   else
   {
      if (u16LocalPhyMSI_tTrbCaseEstim <= s32LocalLow)
      {
         EngReqH_bAuthStopSTTTTrb = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondPresHuileAutoStop                           */
/* !Description :  Cette fonction autorise le STOP au bout d’une temporisation*/
/*                 débutant après un seuil de pression d’huile franchi suite à*/
/*                 un démarrage/redémarrage.                                  */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_043.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pOilMes;                                                 */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 EngReqH_pOilMaxAuthSTT_C;                                    */
/*  input uint8 EngReqH_pOilHysMaxAuthSTT_C;                                  */
/*  input uint8 EngReqH_tiPOilStopAuthX_A[8];                                 */
/*  input uint8 EngReqH_tiPOilStopAuth_T[8];                                  */
/*  input boolean EngReqH_bpOilAuthSTT;                                       */
/*  input boolean ENGREQH_bpOilAuthSTTPrev;                                   */
/*  input uint8 ENGREQH_u8pOilAuthSTTCount;                                   */
/*  output boolean EngReqH_bpOilAuthSTT;                                      */
/*  output uint8 ENGREQH_u8pOilAuthSTTCount;                                  */
/*  output boolean EngReqH_bAuthStopSTTPOil;                                  */
/*  output boolean ENGREQH_bpOilAuthSTTPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondPresHuileAutoStop(void)
{
   uint8  u8LocalExt_tCoMes;
   uint8  u8LocalInterpDelay;
   uint16 u16LocalExt_pOilMes;
   uint16 u16LocalCalcPara;
   sint16 s16LocalExt_tCoMes;
   sint32 s32LocalExt_pOilMes;
   sint32 s32LocalDiff;
   sint32 s32LocalEngReqH_pOilMaxAuthSTT_C;
   sint32 s32LocalExt_tCoMes;


   VEMS_vidGET(Ext_pOilMes, u16LocalExt_pOilMes);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   /* Production of hysterisis Output EngReqH_bpOilAuthSTT*/
   s32LocalDiff = (sint32)( ( EngReqH_pOilMaxAuthSTT_C
                            - EngReqH_pOilHysMaxAuthSTT_C)
                           * 32);
   s32LocalExt_pOilMes = (sint32)(u16LocalExt_pOilMes * 25);
   s32LocalEngReqH_pOilMaxAuthSTT_C = (sint32)(EngReqH_pOilMaxAuthSTT_C * 32);
   if (s32LocalExt_pOilMes <= s32LocalDiff)
   {
      EngReqH_bpOilAuthSTT = 0;
   }
   else
   {
      if (s32LocalExt_pOilMes >= s32LocalEngReqH_pOilMaxAuthSTT_C)
      {
         EngReqH_bpOilAuthSTT = 1;
      }
   }

   /* Production of interp output */
   s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes, 0, 254);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(EngReqH_tiPOilStopAuthX_A,
                                                  u8LocalExt_tCoMes,
                                                  8);
   u8LocalInterpDelay =
      MATHSRV_u8Interp1d(EngReqH_tiPOilStopAuth_T, u16LocalCalcPara);

    /*Turn_On_Delay*/
   if (EngReqH_bpOilAuthSTT != 0)
   {
      if (ENGREQH_bpOilAuthSTTPrev == 0)
      {
         ENGREQH_u8pOilAuthSTTCount = u8LocalInterpDelay;
      }
      else
      {
         if (ENGREQH_u8pOilAuthSTTCount > 0)
         {
            ENGREQH_u8pOilAuthSTTCount =
               (uint8)(ENGREQH_u8pOilAuthSTTCount - 1);
         }
      }
      if (ENGREQH_u8pOilAuthSTTCount == 0)
      {
         EngReqH_bAuthStopSTTPOil = 1;
      }
      else
      {
         EngReqH_bAuthStopSTTPOil = 0;
      }
   }
   else
   {
      EngReqH_bAuthStopSTTPOil = 0;
   }
   ENGREQH_u8pOilAuthSTTCount =
      (uint8)MATHSRV_udtMIN(ENGREQH_u8pOilAuthSTTCount, 200);
   ENGREQH_bpOilAuthSTTPrev = EngReqH_bpOilAuthSTT;
}
/*-------------------------------- end of file -------------------------------*/