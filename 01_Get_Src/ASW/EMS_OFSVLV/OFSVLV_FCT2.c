/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OFSVLV                                                  */
/* !Description     : OFSVLV Component                                        */
/*                                                                            */
/* !Module          : OFSVLV                                                  */
/* !Description     : Limitation balayage et coordination des consignes VVT   */
/*                                                                            */
/* !File            : OFSVLV_FCT2.C                                           */
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
/*   1 / OFSVLV_vidLimitation_du_balayage                                     */
/*   2 / OFSVLV_vidCalcConsigLimit                                            */
/*   3 / OFSVLV_vidTranfDebitBalyCroismnt                                     */
/*   4 / OFSVLV_vidDevectorisation                                            */
/*   5 / OFSVLV_vidVerification_balayage                                      */
/*   6 / OFSVLV_vidBalayage_maximum                                           */
/*   7 / OFSVLV_vidBalayage_maximumCalc                                       */
/*   8 / OFSVLV_vidBalayageMaxParDft                                          */
/*   9 / OFSVLV_vidPilotageCroisemntMax                                       */
/*                                                                            */
/* !Reference   : V02 NT 11 02164 / 02                                        */
/* !OtherRefs   : 01460_10_03509_2/1.1                                        */
/* !OtherRefs   : VEMS V02 ECU#053816                                         */
/* !OtherRefs   : VEMS V02 ECU#054358                                         */
/* !OtherRefs   : VEMS V02 ECU#061723                                         */
/* !OtherRefs   : VEMS V02 ECU#067972                                         */
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
#include "MATHSRV.h"
#include "OFSVLV.h"
#include "LIB_CALIB.h"
/* inclure LIB_CALIB. Inverser les axes de AirEfc_facMassFlowCor_M (13*18)
dans LIB_CALIB.h et HEADER.c75 */
#include "OFSVLV_L.h"
#include "OFSVLV_IM.h"
#include "STD_LIMITS.h"
#include "SWFAIL.h"
#include "VEMS.h"
#include "rtw_shared_utils.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidLimitation_du_balayage                           */
/* !Description :  Elle permet la limitation du balayage par les VVT          */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidCalcConsigLimit();                             */
/*  extf argret void OFSVLV_vidLimitation_consignes();                        */
/*  input boolean VlvSys_bPresTrb_C;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidLimitation_du_balayage(void)
{
   /* F03_Limitation_du_balayage */
   if (VlvSys_bPresTrb_C != 0)
   {
      OFSVLV_vidCalcConsigLimit();
   }
   OFSVLV_vidLimitation_consignes();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidCalcConsigLimit                                  */
/* !Description :  Elle permet de calculer une consigne VVT admission minimum */
/*                 et une consigne VVT échappement maximum à partir d'un débit*/
/*                 d'air balayé maximum.                                      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidTranfDebitBalyCroismnt();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OFSVLV_vidPilotageCroisemntMax();                        */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*  input uint16 VlvSys_rAirLdAltiCor;                                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvSys_rAirLd8_A[8];                                         */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint16 VlvSys_facCmdLimScv_M[8][8];                                 */
/*  output boolean VlvSys_bPresInServo;                                       */
/*  output boolean VlvSys_bPresExServo;                                       */
/*  output uint16 VlvSys_facCmdLimScv;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidCalcConsigLimit(void)
{
   /*F01_Calculs_consignes_limites  */
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalVlvSysrAirLdAltiCorParaX;
   uint16 u16LocalExtnEngParaY;
   uint16 u16LocalfacCmdLimScv;

   OFSVLV_vidTranfDebitBalyCroismnt();

   /* Affectation lors F02_Pilotage_croisement_maximum */
   VlvSys_bPresInServo = VlvSys_bPresInServo_C;
   VlvSys_bPresExServo = VlvSys_bPresExServo_C;
   VEMS_vidGET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalVlvSysrAirLdAltiCorParaX =
      MATHSRV_u16CalcParaIncAryU16(VlvSys_rAirLd8_A,
                                   u16LocalVlvSys_rAirLdAltiCor,
                                   8);
   u16LocalExtnEngParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                       u16LocalExt_nEng,
                                                       8);
   u16LocalfacCmdLimScv =
      MATHSRV_u16Interp2d(&VlvSys_facCmdLimScv_M[0][0],
                          u16LocalVlvSysrAirLdAltiCorParaX,
                          u16LocalExtnEngParaY,
                          8);
   VlvSys_facCmdLimScv = (uint16)MATHSRV_udtMIN(u16LocalfacCmdLimScv, 1000);
   OFSVLV_vidPilotageCroisemntMax();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidTranfDebitBalyCroismnt                           */
/* !Description :  Elle permet de calculer un croisement de soupape maximum à */
/*                 partir du débit d'air balayé maximum issu de la protection */
/*                 composant.                                                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_013.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidDevectorisation();                             */
/*  extf argret void OFSVLV_vidVerification_balayage();                       */
/*  extf argret void OFSVLV_vidBalayageMaxParDft();                           */
/*  extf argret void OFSVLV_vidBalayage_maximum();                            */
/*  input boolean VlvSys_bAcvBedModLimScv;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidTranfDebitBalyCroismnt(void)
{
   /* F01_Transformation_debit_balaye_croisement */
   OFSVLV_vidDevectorisation();
   OFSVLV_vidVerification_balayage();
   if (VlvSys_bAcvBedModLimScv != 0)
   {
      OFSVLV_vidBalayageMaxParDft();
   }
   else
   {
      OFSVLV_vidBalayage_maximum();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidDevectorisation                                  */
/* !Description :  Elle permet de sélectionner, pour chacune des grandeurs en */
/*                 entrée, la composante du vecteur correspondant au numéro de*/
/*                 cylindre en phase d’admission.                             */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 Eng_noInCyl;                                                  */
/*  input uint16 ExM_prm_pExMnfEstimOvlpCyl[6];                               */
/*  input uint16 InM_prm_pDsThrPredOvlpCyl[6];                                */
/*  output uint16 ExM_pExMnfEstimRef;                                         */
/*  output uint16 InM_pDsThrPred_facVlvOvlpRef;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidDevectorisation(void)
{
   /*F01_Devectorisation*/
   uint8  u8LocalIndex;
   uint8  u8LocalEng_noInCyl;
   uint16 u16localPrmExMnfEstimOvlpCyl;
   uint16 u16localPrmDsThrPredOvlpCyl;


   VEMS_vidGET(Eng_noInCyl, u8LocalEng_noInCyl);
   u8LocalEng_noInCyl =
      (uint8)MATHSRV_udtCLAMP(u8LocalEng_noInCyl, 1, 6);
   u8LocalIndex = (uint8)(u8LocalEng_noInCyl - 1);
   VEMS_vidGET1DArrayElement(ExM_prm_pExMnfEstimOvlpCyl,
                             u8LocalIndex,
                             u16localPrmExMnfEstimOvlpCyl);
   VEMS_vidGET1DArrayElement(InM_prm_pDsThrPredOvlpCyl,
                             u8LocalIndex,
                             u16localPrmDsThrPredOvlpCyl);
   ExM_pExMnfEstimRef = u16localPrmExMnfEstimOvlpCyl;
   InM_pDsThrPred_facVlvOvlpRef = u16localPrmDsThrPredOvlpCyl;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidVerification_balayage                            */
/* !Description :  Elle permet de vérifier que le moteur se trouve bien dans  */
/*                 des conditions favorables au balayage afin de garantir le  */
/*                 calcul en aval.                                            */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean VlvSys_bAcvBedModLimScv_C;                                  */
/*  input uint16 InM_pDsThrPred_facVlvOvlpRef;                                */
/*  input uint16 VlvSys_rThdLimScv_C;                                         */
/*  input uint16 ExM_pExMnfEstimRef;                                          */
/*  output boolean VlvSys_bAcvBedModLimScv;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidVerification_balayage(void)
{
   /*F02_verification_balayage */
   uint32 u32LocalMul;
   uint32 u32LocalMul2;


   if (VlvSys_bAcvBedModLimScv_C != 0)
   {
      VlvSys_bAcvBedModLimScv = 1;
   }
   else
   {
      if (InM_pDsThrPred_facVlvOvlpRef == 0)
      {
         VlvSys_bAcvBedModLimScv = 1;
      }
      else
      {
         u32LocalMul =
            (uint32)(InM_pDsThrPred_facVlvOvlpRef * VlvSys_rThdLimScv_C);
         u32LocalMul2 = (uint32)(ExM_pExMnfEstimRef * 65535);
         if (u32LocalMul2 > u32LocalMul)
         {
            VlvSys_bAcvBedModLimScv = 1;
         }
         else
         {
            VlvSys_bAcvBedModLimScv = 0;
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidBalayage_maximum                                 */
/* !Description :  Elle permet de déterminer le croisement maximum des VVT    */
/*                 respectant le débit d’air balayé maximum                   */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OFSVLV_vidBalayage_maximumCalc();                        */
/*  input uint32 EngM_facMassAirScvReq;                                       */
/*  input uint32 EngM_facMassAirScvCor;                                       */
/*  input uint16 TPM_mfAirScvLimMaxCor;                                       */
/*  input uint16 InThM_tAirUsInVlvEstim;                                      */
/*  input sint8 VlvSys_agCkOpInVlvSatCorReq;                                  */
/*  input sint8 VlvSys_agCkClsExVlvSatCorReq;                                 */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean VlvSys_bMassAirScvSel_C;                                    */
/*  input boolean VlvSys_bAcvTPMBedMod_C;                                     */
/*  input uint16 VlvSys_mfAirScvLimMaxBedMod_C;                               */
/*  input uint16 InM_pDsThrPred_facVlvOvlpRef;                                */
/*  input uint16 ExM_pExMnfEstimRef;                                          */
/*  input uint16 VlvSys_facChrExp_MP;                                         */
/*  input uint16 AirEfc_facChrExp_T[11];                                      */
/*  input uint32 OFSVLV_u32AirEfcPresEngX;                                    */
/*  input uint32 AirEfc_rPresEngX_A[11];                                      */
/*  input uint16 AirEfc_tAirUsInVlv_A[16];                                    */
/*  input uint16 AirEfc_facTInSqrt_T[16];                                     */
/*  input sint16 VlvSys_agCkPosnVlvOvlpOfs_C;                                 */
/*  input uint16 VlvSys_facMassFlowCor_MP;                                    */
/*  input ???? AirEfc_facMassFlowCor_M;                                       */
/*  input uint16 AirEfc_nEngY_A[18];                                          */
/*  input sint16 OFSVLV_s16AirCkPosnVlvOvlpX;                                 */
/*  input sint16 AirEfc_agCkPosnVlvOvlpX_A[13];                               */
/*  input uint16 AirEfc_nEng2Y_A[8];                                          */
/*  input uint16 VlvSys_mfAirScvRed_A[16];                                    */
/*  input uint16 VlvSys_mfAirScvRed_MP;                                       */
/*  input uint8 VlvSys_agCkVlvOvlpMax_M[8][16];                               */
/*  input sint16 VlvSys_agCkVlvOvlpOfs_C;                                     */
/*  output uint16 VlvSys_mfAirScvTotLimMax_MP;                                */
/*  output uint32 OFSVLV_u32AirEfcPresEngX;                                   */
/*  output uint16 VlvSys_facTInSqrt_MP;                                       */
/*  output sint16 OFSVLV_s16AirCkPosnVlvOvlpX;                                */
/*  output uint8 VlvSys_agCkVlvOvlpMax;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidBalayage_maximum(void)
{
   /*F03_balayage_maximum */
   uint8  u8LocalCkVlvOvlpMax;
   sint8  s8LocalCkOpInVlvSatCorReq;
   sint8  s8LocalCkClsExVlvSatCorReq;
   uint16 u16LocalAirScvLimMaxCor;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalAirScvRedParaY;
   uint16 u16LocalExtnEngPara2X;
   uint16 u16LocalAirUsInVlvParaX;
   uint16 u16LocalInThMAirUsInVlvEstim;
   sint16 s16Localsum1;
   sint16 s16LocalagCkVlvOvlpMax;
   uint32 u32LocalFacMassAirScvReq;
   uint32 u32LocalFacMassAirScvCor;
   uint32 u32LocalSwitch1;
   uint32 u32LocalDiv1;
   uint32 u32LocalSwitch2;
   uint32 u32LocalAirScvTotLimMax_MP;
   sint32 s32Localsum1;
   sint32 s32Localop1;


   VEMS_vidGET(EngM_facMassAirScvReq, u32LocalFacMassAirScvReq);
   VEMS_vidGET(EngM_facMassAirScvCor, u32LocalFacMassAirScvCor);
   VEMS_vidGET(TPM_mfAirScvLimMaxCor, u16LocalAirScvLimMaxCor);
   VEMS_vidGET(InThM_tAirUsInVlvEstim, u16LocalInThMAirUsInVlvEstim);
   VEMS_vidGET(VlvSys_agCkOpInVlvSatCorReq, s8LocalCkOpInVlvSatCorReq);
   VEMS_vidGET(VlvSys_agCkClsExVlvSatCorReq, s8LocalCkClsExVlvSatCorReq);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   /* Production of VlvSys_mfAirScvTotLimMax_MP */
   if (VlvSys_bMassAirScvSel_C != 0)
   {
      u32LocalSwitch1 = u32LocalFacMassAirScvReq;
   }
   else
   {
      u32LocalSwitch1 = u32LocalFacMassAirScvCor;
   }

   if (VlvSys_bAcvTPMBedMod_C != 0)
   {
      u32LocalSwitch2 = (uint32)(VlvSys_mfAirScvLimMaxBedMod_C * 65536);
   }
   else
   {
      u32LocalSwitch2 = (uint32)(u16LocalAirScvLimMaxCor * 65535);
   }

   if (u32LocalSwitch1 != 0)
   {
      u32LocalAirScvTotLimMax_MP = u32LocalSwitch2 / u32LocalSwitch1;
   }
   else
   {
      u32LocalAirScvTotLimMax_MP = 65535;
   }
   VlvSys_mfAirScvTotLimMax_MP =
      (uint16)MATHSRV_udtMIN(u32LocalAirScvTotLimMax_MP, 65535);

   /* Production of VlvSys_facChrExp_MP */
   if (InM_pDsThrPred_facVlvOvlpRef != 0)
   {
      u32LocalDiv1 = (uint32)(ExM_pExMnfEstimRef * 65536);
      u32LocalDiv1 = u32LocalDiv1 / (uint32)InM_pDsThrPred_facVlvOvlpRef;
   }
   else
   {
      u32LocalDiv1 = 65536;
   }

   OFSVLV_u32AirEfcPresEngX = (uint32)MATHSRV_udtMIN(u32LocalDiv1, 65536);

   LookUp_U16_U32( &(VlvSys_facChrExp_MP), (&(AirEfc_facChrExp_T[0])),
                  OFSVLV_u32AirEfcPresEngX, (&(AirEfc_rPresEngX_A[0])), 10U);

   /* Production of VlvSys_facTInSqrt_MP */
   u16LocalAirUsInVlvParaX =
      MATHSRV_u16CalcParaIncAryU16(AirEfc_tAirUsInVlv_A,
                                   u16LocalInThMAirUsInVlvEstim,
                                   16);
   VlvSys_facTInSqrt_MP = MATHSRV_u16Interp1d(AirEfc_facTInSqrt_T,
                                              u16LocalAirUsInVlvParaX);

   /*production of VlvSys_facMassFlowCor_MP */
   s32Localsum1 =(sint32)(1500 * ( s8LocalCkOpInVlvSatCorReq
                                 + s8LocalCkClsExVlvSatCorReq));
   s32Localsum1 = ( s32Localsum1
                  + (sint32)(4 * VlvSys_agCkPosnVlvOvlpOfs_C));
   if (s32Localsum1 < (sint32)0)
   {
      s16Localsum1 = (sint16)((s32Localsum1 - 187) / 375);
   }
   else
   {
      s16Localsum1 = (sint16)((s32Localsum1 + 187) / 375);
   }

   OFSVLV_s16AirCkPosnVlvOvlpX =
      (sint16)MATHSRV_udtCLAMP(s16Localsum1, -1024, 1024);

   /* la table AirEfc_facMassFlowCor_M est de dimension 13*18 */

   Look2D_U16_U16_S16( &(VlvSys_facMassFlowCor_MP),
                      (&(AirEfc_facMassFlowCor_M[0][0])),
                      u16LocalExt_nEng,
                      (&(AirEfc_nEngY_A[0])),
                      17U,
                      OFSVLV_s16AirCkPosnVlvOvlpX,
                      (&(AirEfc_agCkPosnVlvOvlpX_A[0])), 12U);

   /*Production of VlvSys_mfAirScvRed_MP*/
   OFSVLV_vidBalayage_maximumCalc();

   /*Production of VlvSys_agCkVlvOvlpMax*/
   u16LocalExtnEngPara2X = MATHSRV_u16CalcParaIncAryU16(AirEfc_nEng2Y_A,
                                                        u16LocalExt_nEng,
                                                        8);
   u16LocalAirScvRedParaY = MATHSRV_u16CalcParaIncAryU16(VlvSys_mfAirScvRed_A,
                                                         VlvSys_mfAirScvRed_MP,
                                                         16);
   u8LocalCkVlvOvlpMax =
      MATHSRV_u8Interp2d(&VlvSys_agCkVlvOvlpMax_M[0][0],
                         u16LocalExtnEngPara2X,
                         u16LocalAirScvRedParaY,
                         16);
   s32Localop1 = VlvSys_agCkVlvOvlpOfs_C + (750 * u8LocalCkVlvOvlpMax);

   if (s32Localop1 < (sint32)0)
   {
      s16LocalagCkVlvOvlpMax = (sint16)((s32Localop1 - 375) / 750);
   }
   else
   {
      s16LocalagCkVlvOvlpMax = (sint16)((s32Localop1 + 375) / 750);
   }

   VlvSys_agCkVlvOvlpMax = (uint8) MATHSRV_udtCLAMP(s16LocalagCkVlvOvlpMax,
                                                    0,
                                                    255);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidBalayage_maximumCalc                             */
/* !Description :  Production de la variable VlvSys_mfAirScvRed_MP.           */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 VlvSys_mfAirScvTotLimMax_MP;                                 */
/*  input uint16 AirEfc_pRef_C;                                               */
/*  input uint16 VlvSys_facChrExp_MP;                                         */
/*  input uint16 VlvSys_facTInSqrt_MP;                                        */
/*  input uint16 InM_pDsThrPred_facVlvOvlpRef;                                */
/*  input uint16 VlvSys_facMassFlowCor_MP;                                    */
/*  output uint16 VlvSys_mfAirScvRed_MP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidBalayage_maximumCalc(void)
{
   uint32 u32LocalMul4;
   uint32 u32Local_Mul_1;
   uint32 u32Local_Div_1;
   uint32 u32Local_Mod_1;
   uint32 u32Local_Var_1;
   uint32 u32Local_Var_10;
   uint32 u32Local_Mul_2;
   uint32 u32Local_Mod_2;
   uint32 u32Local_Var_2;
   uint32 u32Local_Mod_3;
   uint32 u32Local_Mod_30;
   uint32 u32Local_Var_3;
   uint32 u32Local_Var_5;
   uint32 u32Localmax;


   /*Production of VlvSys_mfAirScvRed_MP:
   num = VlvSys_mfAirScvTotLimMax_MP * AirEfc_pRef_C * 65536 *65536 * 163840
   den = VlvSys_facChrExp_MP * VlvSys_facTInSqrt_MP *
      InM_pDsThrPred_facVlvOvlpRef * (3 * VlvSys_facMassFlowCor_MP + 229376)
   VlvSys_mfAirScvRed_MP = num / den                                          */

   if (  (VlvSys_mfAirScvTotLimMax_MP == 0)
      || (AirEfc_pRef_C == 0))
   {
      VlvSys_mfAirScvRed_MP = 0;
   }
   else
   {
      if (  (VlvSys_facChrExp_MP != 0)
         && (VlvSys_facTInSqrt_MP != 0)
         && (InM_pDsThrPred_facVlvOvlpRef != 0))
      {
         u32LocalMul4 = (uint32)( ((3 * VlvSys_facMassFlowCor_MP) + 229380)
                                / 8);
         u32Local_Mul_1 = VlvSys_facChrExp_MP * VlvSys_facTInSqrt_MP;
         u32Localmax = UINT32_MAX / (uint32)InM_pDsThrPred_facVlvOvlpRef;
         if (u32Local_Mul_1 < u32Localmax)
         {
            u32Local_Mul_1 = u32Local_Mul_1 * InM_pDsThrPred_facVlvOvlpRef;
            u32Local_Var_1 = (u32Local_Mul_1 + 32768) / 65536;
         }
         else
         {
            u32Local_Div_1 = u32Local_Mul_1 / 65536;
            u32Local_Mod_1 = ( ( (  (u32Local_Mul_1 % 65536)
                                 * InM_pDsThrPred_facVlvOvlpRef)
                               + 32768)
                             / 65536);
            u32Local_Var_1 =
               (u32Local_Div_1 * InM_pDsThrPred_facVlvOvlpRef) + u32Local_Mod_1;
         }
         if (u32Local_Var_1 == 0)
         {
            VlvSys_mfAirScvRed_MP = 65535;
         }
         else
         {
            u32Local_Mul_2 = 1342177280 / u32LocalMul4;

            u32Local_Mod_2 = ((1342177280 % u32LocalMul4) * AirEfc_pRef_C)
                           / u32LocalMul4;
            u32Local_Var_2 = (u32Local_Mul_2 * AirEfc_pRef_C) + u32Local_Mod_2;
            u32Localmax = UINT32_MAX / (uint32)VlvSys_mfAirScvTotLimMax_MP;

            if (u32Local_Var_2 < u32Localmax)
            {
               u32Local_Var_3 = ( (u32Local_Var_2 * VlvSys_mfAirScvTotLimMax_MP)
                                / u32Local_Var_1);
               /* QAC Msg(2:0584): the divisor is always non-zero*/
            }
            else
            {
               u32Local_Var_3 = u32Local_Var_2 / u32Local_Var_1;
               /* QAC Msg(2:0584): the divisor is always non-zero*/
               if (u32Local_Var_3 < 65535)
               {
                  u32Local_Mod_3 = u32Local_Var_2 % u32Local_Var_1;
                  /* QAC Msg(2:0584): the divisor is always non-zero*/
                  u32Local_Var_5 = ( u32Local_Var_1
                                   / (uint32)VlvSys_mfAirScvTotLimMax_MP);

                  if (u32Local_Mod_3 < u32Local_Var_5)
                  {
                     u32Local_Mod_3 = 0;
                  }
                  else
                  {
                     if (u32Local_Mod_3 < u32Localmax)
                     {
                        u32Local_Mod_3 = ( ( u32Local_Mod_3
                                           * VlvSys_mfAirScvTotLimMax_MP)
                                         / u32Local_Var_1);
                        /* QAC Msg(2:0584): the divisor is always non-zero*/
                     }
                     else
                     {
                        u32Local_Var_10 = ( u32Local_Var_1
                                          / ( (VlvSys_mfAirScvTotLimMax_MP + 8)
                                            / 16));
                        /* QAC Msg(2:0584): the divisor is always non-zero*/
                        u32Local_Mod_30 = u32Local_Mod_3 % u32Local_Var_10;
                        u32Local_Mod_3 = u32Local_Mod_3 / u32Local_Var_10;
                        u32Local_Mod_30 =
                           MATHSRV_udtMIN(u32Local_Mod_30, 268435455);
                        u32Local_Mod_30 = ( (u32Local_Mod_30 * 16)
                                          / u32Local_Var_10);
                        u32Local_Mod_3 =
                           (u32Local_Mod_3 * 16 ) + u32Local_Mod_30;
                     }
                  }
                  u32Local_Var_3 = ( ( u32Local_Var_3
                                     * VlvSys_mfAirScvTotLimMax_MP)
                                   + u32Local_Mod_3);
               }
            }
            VlvSys_mfAirScvRed_MP =
               (uint16)MATHSRV_udtMIN(u32Local_Var_3, 65535);
         }
      }
      else
      {
         VlvSys_mfAirScvRed_MP = 65535;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidBalayageMaxParDft                                */
/* !Description :  Elle permet d’attribuer à la valeur de croisement de VVT   */
/*                 maximum une valeur constante calibrable dans le cas où les */
/*                 conditions moteurs sont défavorables au calcul nominal ou  */
/*                 encore lorsque le mode banc est activé.                    */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvSys_agCkVlvOvlpMax_C;                                      */
/*  output uint8 VlvSys_agCkVlvOvlpMax;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidBalayageMaxParDft(void)
{
   /*F04_balayage_maximum_par_defaut */
   VlvSys_agCkVlvOvlpMax = VlvSys_agCkVlvOvlpMax_C;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidPilotageCroisemntMax                             */
/* !Description :  Elle  calcule la consigne VVT admission minimum et la      */
/*                 consigne VVT  échappement maximum en fonction des          */
/*                 différentes conditions moteurs.                            */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void OFSVLV_vidPilotageCroimntMaxInit();                      */
/*  input sint8 VlvSys_agCkClsExVlvSatCorReq;                                 */
/*  input sint8 VlvSys_agCkOpInVlvSatCorReq;                                  */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0Min;                                */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0Max;                                 */
/*  input uint8 VlvSys_agCkVlvOvlpMax;                                        */
/*  input uint16 VlvSys_facCmdLimScv;                                         */
/*  input st124 OFSVLV_u8PilotageCroismntMax;                                 */
/*  input boolean VlvSys_bPresInServo;                                        */
/*  input boolean VlvSys_bPresExServo;                                        */
/*  output st124 OFSVLV_u8PilotageCroismntMax;                                */
/*  output uint8 VlvSys_agCkOpInVlvMin;                                       */
/*  output uint8 VlvSys_agCkClsExVlvMax;                                      */
/*  output boolean VlvSys_bDetInServoDftPos;                                  */
/*  output boolean VlvSys_bDetExServoDftPos;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidPilotageCroisemntMax(void)
{
   /*F02_Pilotage_croisement_maximum*/
   boolean bLocalDuringAdm;
   boolean bLocalDuringPasVvt;
   boolean bLocalDuringAdmEch;
   boolean bLocalDuringEch;
   sint8   s8LocalInVlvSatCorReq;
   sint8   s8LocalExVlvSatCorReq;
   sint16  s16LocalMulop1;
   sint16  s16LocalMulop3;
   sint16  s16LocalMulop4;
   sint16  s16LocalCkClsExVlvMax;
   uint32  u32LocalRefMin;
   uint32  u32LocalRefMax;
   sint32  s32LocalMulop2;
   sint32  s32LocaReqRef0Max;
   sint32  s32LocaReqRef0Min;
   sint32  s32LocaReqRef0Max2;
   sint32  s32LocaReqRef0Min2;
   sint32  s32LocalMulop4;


   VEMS_vidGET(VlvSys_agCkClsExVlvSatCorReq, s8LocalExVlvSatCorReq);
   VEMS_vidGET(VlvSys_agCkOpInVlvSatCorReq, s8LocalInVlvSatCorReq);

   /* Operation 1 */
   s16LocalMulop4 = (sint16)( ( VlvSys_agCkClsExVlvReqRef0Min
                              - VlvSys_agCkOpInVlvReqRef0Max)
                            + 128);
   u32LocalRefMin = (uint32)(VlvSys_agCkClsExVlvReqRef0Min * 1000);
   u32LocalRefMax = (uint32)(VlvSys_agCkOpInVlvReqRef0Max * 1000);

   /* Operation 2 */
   s16LocalMulop1 = (sint16)( ( s8LocalExVlvSatCorReq
                              - VlvSys_agCkVlvOvlpMax)
                            + 256);
   s32LocalMulop2 = (sint32)( (1000 - VlvSys_facCmdLimScv)
                            * (s8LocalInVlvSatCorReq + 128));
   s32LocaReqRef0Max = (s16LocalMulop1 * VlvSys_facCmdLimScv) + s32LocalMulop2;
   s32LocaReqRef0Min =  ( s32LocaReqRef0Max
                        + (sint32)((VlvSys_agCkVlvOvlpMax - 128) * 1000));

   /* Operation 3 */
   s16LocalMulop3 = (sint16)( ( VlvSys_agCkClsExVlvReqRef0Min
                              - VlvSys_agCkVlvOvlpMax)
                            + 128);
   s32LocalMulop4 = (sint32)( ( 1000 - VlvSys_facCmdLimScv)
                            * VlvSys_agCkOpInVlvReqRef0Max);
   s32LocaReqRef0Max2 = (s16LocalMulop3 * VlvSys_facCmdLimScv) + s32LocalMulop4;

   s32LocaReqRef0Min2 = ( s32LocaReqRef0Max2
                        + (sint32)((VlvSys_agCkVlvOvlpMax - 128) * 1000));

   switch (OFSVLV_u8PilotageCroismntMax)
   {
      case VVT_ADM_EN_BUTEE:
         /* VVT_Adm_en_butee */
         bLocalDuringAdm = 1;
         if (  (VlvSys_bPresInServo != 0)
            && (VlvSys_bPresExServo != 0))
         {
            if (  (s32LocaReqRef0Min > (sint32)u32LocalRefMin)
               && (s32LocaReqRef0Max < (sint32)u32LocalRefMax))
            {
               OFSVLV_u8PilotageCroismntMax = PAS_DE_VVT_EN_BUTEE;
               bLocalDuringAdm = 0;
            }
            else
            {
               if (  (s32LocaReqRef0Min2 <= (sint32)u32LocalRefMin)
                  && (s32LocaReqRef0Max2 >= (sint32)u32LocalRefMax))
               {
                  OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
                  bLocalDuringAdm = 0;
               }
            }
         }
         else
         {
            if (  (VlvSys_bPresExServo != 0)
               && (s16LocalMulop4 >= (sint16)VlvSys_agCkVlvOvlpMax ))
            {
               OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
               bLocalDuringAdm = 0;
            }
         }

         /*During*/
         if (bLocalDuringAdm != 0)
         {
            VlvSys_agCkOpInVlvMin = VlvSys_agCkOpInVlvReqRef0Max;
            s16LocalCkClsExVlvMax = (sint16)( ( VlvSys_agCkOpInVlvReqRef0Max
                                              + VlvSys_agCkVlvOvlpMax)
                                            - 128);
            VlvSys_agCkClsExVlvMax =
               (uint8)MATHSRV_udtCLAMP(s16LocalCkClsExVlvMax,0 ,255);
            VEMS_vidSET(VlvSys_bDetInServoDftPos, 1);
            VEMS_vidSET(VlvSys_bDetExServoDftPos, 0);
         }
         break;

      case PAS_DE_VVT_EN_BUTEE:
         /*PAS_DE_VVT_EN_BUTEE */
         bLocalDuringPasVvt = 1;
         if (  (VlvSys_bPresInServo != 0)
            && (VlvSys_bPresExServo !=0 ))
         {
            if (s32LocaReqRef0Min <= (sint32)u32LocalRefMin)
            {
               if (s32LocaReqRef0Max >= (sint32)u32LocalRefMax)
               {
                  OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
               }
               else
               {
                  OFSVLV_u8PilotageCroismntMax = VVT_ECH_EN_BUTEE;
               }
               bLocalDuringPasVvt = 0;
            }
            else
            {
               if (s32LocaReqRef0Max >= (sint32)u32LocalRefMax)
               {
                  OFSVLV_u8PilotageCroismntMax = VVT_ADM_EN_BUTEE;
                  bLocalDuringPasVvt = 0;
               }
            }
         }

         /*During*/
         if (bLocalDuringPasVvt != 0)
         {
            if (s32LocaReqRef0Max >= 0)
            {
               s32LocaReqRef0Max = (s32LocaReqRef0Max + 500) / 1000;
            }
            else
            {
               s32LocaReqRef0Max = (s32LocaReqRef0Max - 500) / 1000;
            }
            if (s32LocaReqRef0Min >= 0)
            {
               s32LocaReqRef0Min = (s32LocaReqRef0Min + 500)/1000;
            }
            else
            {
               s32LocaReqRef0Min = (s32LocaReqRef0Min - 500) /1000;
            }
            VlvSys_agCkOpInVlvMin =
               (uint8)MATHSRV_udtCLAMP(s32LocaReqRef0Max,0 ,255);
            VlvSys_agCkClsExVlvMax =
               (uint8)MATHSRV_udtCLAMP(s32LocaReqRef0Min,0 ,255);
            VEMS_vidSET(VlvSys_bDetInServoDftPos, 0);
            VEMS_vidSET(VlvSys_bDetExServoDftPos, 0);
         }
         break;

      case VVT_ADM_ET_ECH_EN_BUTEE:
         /*vvt_adm_et_ech_en_butee*/
         bLocalDuringAdmEch = 1;
         if (VlvSys_bPresInServo == 0)
         {
            if (  (VlvSys_bPresExServo != 0)
               && (s16LocalMulop4 < (sint16)VlvSys_agCkVlvOvlpMax))
            {
               OFSVLV_u8PilotageCroismntMax = VVT_ADM_EN_BUTEE;
               bLocalDuringAdmEch = 0;
            }
         }
         else
         {
            if (VlvSys_bPresExServo != 0)
            {
               if (s16LocalMulop4 < (sint16)VlvSys_agCkVlvOvlpMax)
               {
                  if (s32LocaReqRef0Max >= (sint32)u32LocalRefMax)
                  {
                     OFSVLV_u8PilotageCroismntMax = VVT_ADM_EN_BUTEE;
                  }
                  else
                  {
                     if (s32LocaReqRef0Min > (sint32)u32LocalRefMin)
                     {
                        OFSVLV_u8PilotageCroismntMax = PAS_DE_VVT_EN_BUTEE;
                     }
                     else
                     {
                        OFSVLV_u8PilotageCroismntMax = VVT_ECH_EN_BUTEE;
                     }
                  }
                  bLocalDuringAdmEch = 0;
               }
            }
            else
            {
               if (s16LocalMulop4 < (sint16)VlvSys_agCkVlvOvlpMax)
               {
                  OFSVLV_u8PilotageCroismntMax = VVT_ECH_EN_BUTEE;
                  bLocalDuringAdmEch = 0;
               }
            }
         }

         /*During*/
         if (bLocalDuringAdmEch != 0)
         {
            VlvSys_agCkOpInVlvMin = VlvSys_agCkOpInVlvReqRef0Max;
            VlvSys_agCkClsExVlvMax = VlvSys_agCkClsExVlvReqRef0Min;
            VEMS_vidSET(VlvSys_bDetInServoDftPos, 1);
            VEMS_vidSET(VlvSys_bDetExServoDftPos, 1);
         }
         break;

      case VVT_ECH_EN_BUTEE:
         /*vvt_ech_en_butee*/
         bLocalDuringEch = 1;
         if (  (VlvSys_bPresInServo != 0)
            && (VlvSys_bPresExServo != 0))
         {
            if (  (s32LocaReqRef0Min > (sint32)u32LocalRefMin)
               && (s32LocaReqRef0Max < (sint32)u32LocalRefMax))
            {
               OFSVLV_u8PilotageCroismntMax = PAS_DE_VVT_EN_BUTEE;
               bLocalDuringEch = 0;
            }
            else
            {
               if (  (s32LocaReqRef0Min2 <= (sint32)u32LocalRefMin)
                  && (s32LocaReqRef0Max2 >= (sint32)u32LocalRefMax))
               {
                  OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
                  bLocalDuringEch = 0;
               }
            }
         }
         else
         {
            if (  (VlvSys_bPresExServo == 0)
               && (s16LocalMulop4 >= (sint16)VlvSys_agCkVlvOvlpMax))
            {
               OFSVLV_u8PilotageCroismntMax = VVT_ADM_ET_ECH_EN_BUTEE;
               bLocalDuringEch = 0;
            }
         }

         /*During*/
         if (bLocalDuringEch != 0)
         {
            VlvSys_agCkOpInVlvMin =
               (uint8)MATHSRV_udtCLAMP(s16LocalMulop3, 0, 255);
            VlvSys_agCkClsExVlvMax = VlvSys_agCkClsExVlvReqRef0Min;
            VEMS_vidSET(VlvSys_bDetInServoDftPos, 0);
            VEMS_vidSET(VlvSys_bDetExServoDftPos, 1);
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         OFSVLV_vidPilotageCroimntMaxInit();
         break;
   }
}

/*------------------------------- end of file --------------------------------*/