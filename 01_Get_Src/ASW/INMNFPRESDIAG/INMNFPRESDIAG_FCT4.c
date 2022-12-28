/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INMNFPRESDIAG                                           */
/* !Description     : INMNFPRESDIAG Component.                                */
/*                                                                            */
/* !Module          : INMNFPRESDIAG                                           */
/* !Description     : Diagnostic fonctionnel de la pression collecteur.       */
/*                                                                            */
/* !File            : INMNFPRESDIAG_FCT4.C                                    */
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
/*   1 / INMNFPRESDIAG_vidThrCohAuth                                          */
/*   2 / INMNFPRESDIAG_vidThrCohDiag                                          */
/*   3 / INMNFPRESDIAG_vidMngActivStart                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6539920 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INMNFPRESDIAG/INMNFPRESDIAG_FCT4.C$*/
/* $Revision::   1.0      $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "INMNFPRESDIAG.h"
#include "INMNFPRESDIAG_L.h"
#include "INMNFPRESDIAG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidThrCohAuth                                */
/* !Description :  On définit ici les conditions d’activation du diagnostic de*/
/*                 cohérence de pression d’admission avec la position         */
/*                 d’ouverture papillon.                                      */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input uint16 Ext_pUsThrMesSI;                                             */
/*  input uint16 AirPres_pDsThrOpMem;                                         */
/*  input uint8 AirPres_rPresThrSat;                                          */
/*  input uint8 AirPres_rPresThrMaxThd_C;                                     */
/*  input uint8 AirPres_rOpThdMax_C;                                          */
/*  input uint16 AirPres_nOpThdMin_nEng_C;                                    */
/*  input uint16 AirPres_nOpThdMax_nEng_C;                                    */
/*  input boolean AirPres_bCanPurgOk;                                         */
/*  input boolean AirPres_bAcvDftThrCoh_C;                                    */
/*  output uint16 AirPres_pDsThrOpMem;                                        */
/*  output uint8 AirPres_rPresThrSat;                                         */
/*  output boolean AirPres_bMonRunStabCoh_pDsThr;                             */
/*  output boolean AirPres_bMonRunThrCoh_pDsThr;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidThrCohAuth(void)
{
   boolean   bLocalInhInMnfPresDiag;
   boolean   bLocalComp;
   uint8     u8LocalCorrected_throttle_pos;
   uint8     u8LocalAirPres_rPresThr;
   uint16    u16LocalOpThdMax;
   uint16    u16LocalRegime_moteur;
   uint16    u16LocalExt_pUsThrMesSI;
   uint16    u16LocalExt_pDsThrMes;
   sint16    s16LocalExt_pDsThrMes;
   uint32    u32LocalAirPres_pDsThrOpMem;

   bLocalInhInMnfPresDiag = GDGAR_bGetFRM(FRM_FRM_INHINMNFPRESDIAG);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrected_throttle_pos);
   VEMS_vidGET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
   VEMS_vidGET(Ext_pUsThrMesSI, u16LocalExt_pUsThrMesSI);

   u16LocalExt_pDsThrMes = (uint16)MATHSRV_udtMAX(s16LocalExt_pDsThrMes, 0);

   u32LocalAirPres_pDsThrOpMem = (uint32)(u16LocalExt_pDsThrMes * 25) / 2;

   AirPres_pDsThrOpMem = (uint16)MATHSRV_udtMIN(u32LocalAirPres_pDsThrOpMem,
                                                65535);
   if (u16LocalExt_pUsThrMesSI == 0)
   {
      u8LocalAirPres_rPresThr = 99;
   }
   else
   {
      if (u16LocalExt_pUsThrMesSI > AirPres_pDsThrOpMem)
      {
         u8LocalAirPres_rPresThr =
            (uint8)((uint32)( ( ( AirPres_pDsThrOpMem * 200)
                              + u16LocalExt_pUsThrMesSI)
                            / (2 * u16LocalExt_pUsThrMesSI)));
      }
      else
      {
         u8LocalAirPres_rPresThr = 99;
      }
   }
   AirPres_rPresThrSat = (uint8)MATHSRV_udtMIN(u8LocalAirPres_rPresThr, 99);
   if (AirPres_rPresThrSat < AirPres_rPresThrMaxThd_C)
   {
      bLocalComp = 1;
   }
   else
   {
      bLocalComp = 0;
   }
   u16LocalOpThdMax = (uint16)((AirPres_rOpThdMax_C * 64) / 25);
   if (  (bLocalInhInMnfPresDiag == 0)
      && (u16LocalRegime_moteur > AirPres_nOpThdMin_nEng_C)
      && (u16LocalRegime_moteur < AirPres_nOpThdMax_nEng_C)
      && (u8LocalCorrected_throttle_pos < u16LocalOpThdMax)
      && (bLocalComp != 0)
      && (AirPres_bCanPurgOk != 0))
   {
      if (AirPres_bAcvDftThrCoh_C != 0)
      {
         AirPres_bMonRunStabCoh_pDsThr = 0;
         AirPres_bMonRunThrCoh_pDsThr = 1;
      }
      else
      {
         AirPres_bMonRunStabCoh_pDsThr = 1;
         AirPres_bMonRunThrCoh_pDsThr = 0;
      }
   }
   else
   {
      AirPres_bMonRunStabCoh_pDsThr = 0;
      AirPres_bMonRunThrCoh_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidThrCohDiag                                */
/* !Description :  On effectue ici la comparaison entre la position papillon  */
/*                 mesurée et une position théorique recalculée à partir du   */
/*                 rapport de pression amont et aval papillon.                */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pUsThrMesSI;                                             */
/*  input uint16 EngM_mfAirCor;                                               */
/*  input uint8 UsThrM_tSqrtInAir;                                            */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint8 AirPres_rPresThrSat;                                          */
/*  input uint8 AirPres_rPresThrBSVThd_C;                                     */
/*  input uint8 AirPres_rThrPres_rBSV_A[13];                                  */
/*  input uint16 AirPres_rBSV_T[13];                                          */
/*  input uint16 AirPres_rBSVCon_C;                                           */
/*  input uint16 AirPres_rBSVClc;                                             */
/*  input uint16 AirPres_arThr_rOpThr_A[16];                                  */
/*  input uint16 AirPres_sThrClc;                                             */
/*  input uint8 AirPres_rOpThr_T[16];                                         */
/*  input uint8 AirPres_rOpDif;                                               */
/*  input uint8 AirPres_rOpThdDifMax_C;                                       */
/*  output uint16 AirPres_rBSVClc;                                            */
/*  output uint16 AirPres_sThrClc;                                            */
/*  output uint8 AirPres_rOpMem;                                              */
/*  output uint8 AirPres_rOpDif;                                              */
/*  output boolean AirPres_bDgoThrCoh_pDsThr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidThrCohDiag(void)
{
   uint8  u8LocalUsThrM_tSqrtInAir;
   uint8  u8LocalCorrected_throttle_pos;
   uint8  u8LocalAirPres_rOpThr;
   uint8  u8LocalRest1;
   uint16 u16LocalExt_pUsThrMesSI;
   uint16 u16LocalEngM_mfAirCor;
   uint16 u16LocalAirPres_rBSVClc;
   uint16 u16LocalCalcPara1;
   uint16 u16LocalCalcPara2;
   sint16 s16Localminus;
   uint32 u32LocalMulDiv;
   uint32 u32LocalMul;
   uint32 u32LocalDiv1;
   uint32 u32LocalResult;
   uint32 u32LocalRest2;


   VEMS_vidGET(Ext_pUsThrMesSI, u16LocalExt_pUsThrMesSI);
   VEMS_vidGET(EngM_mfAirCor, u16LocalEngM_mfAirCor);
   VEMS_vidGET(UsThrM_tSqrtInAir, u8LocalUsThrM_tSqrtInAir);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrected_throttle_pos);

   if (AirPres_rPresThrSat > AirPres_rPresThrBSVThd_C)
   {
      u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU8(AirPres_rThrPres_rBSV_A,
                                                      AirPres_rPresThrSat,
                                                      13);
      u16LocalAirPres_rBSVClc = MATHSRV_u16Interp1d(AirPres_rBSV_T,
                                                    u16LocalCalcPara1);
   }
   else
   {
      u16LocalAirPres_rBSVClc = AirPres_rBSVCon_C ;
   }
   AirPres_rBSVClc = (uint16)MATHSRV_udtMIN(u16LocalAirPres_rBSVClc, 10000);

   if (u16LocalExt_pUsThrMesSI == 0)
   {
      AirPres_sThrClc = 65535;
   }
   else
   {
      u32LocalMul = (uint32)(u16LocalEngM_mfAirCor * AirPres_rBSVClc);
      if (u8LocalUsThrM_tSqrtInAir != 0)
      {
         u32LocalMulDiv = UINT32_MAX / (uint32)u8LocalUsThrM_tSqrtInAir;
         if (u32LocalMul <= u32LocalMulDiv)
         {
            u32LocalResult = ( (u32LocalMul * u8LocalUsThrM_tSqrtInAir)
                             / (25 * u16LocalExt_pUsThrMesSI));
            AirPres_sThrClc = (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
         }
         else
         {
            u32LocalDiv1 = (u32LocalMul / 25);
            if (u32LocalDiv1 <= u32LocalMulDiv)
            {
               u8LocalRest1 = (uint8)(u32LocalMul % 25);
               u32LocalRest2 =
                  (uint32)( (u8LocalRest1 * u8LocalUsThrM_tSqrtInAir)
                          / 25);
               u32LocalResult = ( ( (u32LocalDiv1 * u8LocalUsThrM_tSqrtInAir)
                                  + u32LocalRest2)
                                / u16LocalExt_pUsThrMesSI);
               AirPres_sThrClc = (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
            }
            else
            {
               AirPres_sThrClc = 65535;
            }
         }
      }
      else
      {
         AirPres_sThrClc = 0;
      }
   }

   u16LocalCalcPara2 = MATHSRV_u16CalcParaIncAryU16(AirPres_arThr_rOpThr_A,
                                                    AirPres_sThrClc,
                                                    16);
   u8LocalAirPres_rOpThr = MATHSRV_u8Interp1d(AirPres_rOpThr_T,
                                              u16LocalCalcPara2);

   AirPres_rOpMem = u8LocalCorrected_throttle_pos;

   s16Localminus = (sint16)( (sint16)u8LocalAirPres_rOpThr
                           - (sint16)u8LocalCorrected_throttle_pos);

   AirPres_rOpDif = (uint8)MATHSRV_udtABS(s16Localminus);

   if (AirPres_rOpDif >= AirPres_rOpThdDifMax_C)
   {
      AirPres_bDgoThrCoh_pDsThr = 1;
   }
   else
   {
      AirPres_bDgoThrCoh_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidMngActivStart                             */
/* !Description :  A l’initialisation, toutes les variables sont mises à zéro.*/
/*                   Les pressions admission et atmo sont mises à jour dès le */
/*                 premier réveil principal (AirPres_bAuthUpdPres=1)          */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input boolean ECU_bWkuMain;                                               */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean AirPres_bDetFirstSt;                                        */
/*  input boolean INMNFPRESDIAG_bDetFirstStPrev;                              */
/*  input boolean AirPres_bDiagAftStall;                                      */
/*  input boolean INMNFPRESDIAG_bWkuMainPrev;                                 */
/*  output boolean AirPres_bDetFirstStTCk;                                    */
/*  output boolean AirPres_bDiagAftStall;                                     */
/*  output boolean INMNFPRESDIAG_bWkuMainPrev;                                */
/*  output boolean AirPres_bAuthUpdPres;                                      */
/*  output boolean AirPres_bDetFirstRun;                                      */
/*  output boolean INMNFPRESDIAG_bDetFirstStPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidMngActivStart(void)
{
   /*F00_InMnfPresDiag_GestionActivation_demarrage*/
   boolean bLocalInhInMnfPresDiag;
   boolean bLocalECUbWkuMain;
   uint8   u8LocalVehicle_active_state;


   VEMS_vidGET(ECU_bWkuMain, bLocalECUbWkuMain);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   bLocalInhInMnfPresDiag = GDGAR_bGetFRM(FRM_FRM_INHINMNFPRESDIAG);

   /*Production of AirPres_bDetFirstStTCk and AirPres_bDiagAftStall*/
   if (  (bLocalInhInMnfPresDiag == 0)
      && (AirPres_bDetFirstSt == 0)
      && (INMNFPRESDIAG_bDetFirstStPrev != 0))
   {
      AirPres_bDetFirstStTCk = 1;
      AirPres_bDiagAftStall = 1;
   }
   else
   {
      AirPres_bDetFirstStTCk = 0;
   }

   /*Production of AirPres_bAuthUpdPres and AirPres_bDetFirstRun*/
   if (bLocalECUbWkuMain != 0)
   {
      INMNFPRESDIAG_bWkuMainPrev = 1;
   }

   if (AirPres_bDiagAftStall == 0)
   {
      if (  (INMNFPRESDIAG_bWkuMainPrev != 0)
         && (bLocalInhInMnfPresDiag == 0))
      {
         AirPres_bAuthUpdPres = 1;
      }
      else
      {
         AirPres_bAuthUpdPres = 0;
      }
   }
   else
   {
      AirPres_bAuthUpdPres = 0;
      if (u8LocalVehicle_active_state == VS_RUNNING)
      {
         AirPres_bDetFirstRun = 1;
      }
   }

   INMNFPRESDIAG_bDetFirstStPrev = AirPres_bDetFirstSt;
}
/************************************* end of file ****************************/