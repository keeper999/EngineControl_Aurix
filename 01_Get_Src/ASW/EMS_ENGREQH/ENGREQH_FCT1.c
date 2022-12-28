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
/* !File            : ENGREQH_FCT1.C                                          */
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
/*   1 / ENGREQH_vidInitOutput                                                */
/*   2 / ENGREQH_vidCondTempEauAutoriStop                                     */
/*   3 / ENGREQH_vidPartieFonctionTempEau                                     */
/*   4 / ENGREQH_vidPartieDisfoncTempEau                                      */
/*   5 / ENGREQH_vidCondTempHuileAutoStop                                     */
/*   6 / ENGREQH_vidPartieFonctTempHuile                                      */
/*   7 / ENGREQH_vidPartieDisfonTempHuile                                     */
/*   8 / ENGREQH_vidTempoDemarrageAutStop                                     */
/*   9 / ENGREQH_vidCondSondLambdaAutStop                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 05960 / 08                                        */
/* !OtherRefs   : CSMT_CGMT08_2303 / 2.6                                      */
/* !OtherRefs   : VEMS V02 ECU#058179                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/ENGREQH/ENGREQH_FCT1.C$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
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
/* !Function    :  ENGREQH_vidInitOutput                                      */
/* !Description :  Initialisation des variables de sortie.                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 Ext_nEngToothClc;                                            */
/*  output boolean EngReqH_bEngRStrtAutnAvl;                                  */
/*  output boolean EngReqH_bEngRunReq;                                        */
/*  output boolean EngReqH_bAuthStopSTTLsOk;                                  */
/*  output boolean EngReqH_bAuthStopSTTStrtDly;                               */
/*  output boolean EngReqH_bAuthStopSTTTAir;                                  */
/*  output boolean EngReqH_bAuthStopSTTTCo;                                   */
/*  output boolean EngReqH_bAuthStopSTTTCoMem_MP;                             */
/*  output boolean EngReqH_bAuthStopSTTTOil;                                  */
/*  output boolean EngReqH_bAuthStopSTTTOxC;                                  */
/*  output boolean EngReqH_bCdnAuthStopSTT;                                   */
/*  output boolean EngReqH_bCdnTCoMax_MP;                                     */
/*  output boolean EngReqH_bCdnTCoMin_MP;                                     */
/*  output boolean EngReqH_bCdnTOilMax_MP;                                    */
/*  output boolean EngReqH_bCdnTOilMin_MP;                                    */
/*  output boolean EngReqH_bCntTDCRstrtAutnAvl;                               */
/*  output boolean EngReqH_bEngRstrtAutnAvlTmp_MP;                            */
/*  output boolean EngReqH_bFctAuthStopSTTTCo;                                */
/*  output boolean EngReqH_bFctAuthStopSTTTOil;                               */
/*  output boolean EngReqH_bFctAuthStopSTTTOxCHi;                             */
/*  output boolean EngReqH_bFctAuthStopSTTTOxCLo;                             */
/*  output boolean EngReqH_bFctStopAuthTAir;                                  */
/*  output boolean EngReqH_bFctStopTAirMem_MP;                                */
/*  output boolean EngReqH_bForcCdnStopSTTTCo;                                */
/*  output boolean EngReqH_bForcCdnStopSTTTOil;                               */
/*  output boolean EngReqH_bForcCdnStopSTTTOxC;                               */
/*  output boolean EngReqH_bForcStopAuthTAir;                                 */
/*  output boolean EngReqH_bGlblStopSTTLsOk_MP;                               */
/*  output boolean EngReqH_bGlblStopSTTStrtDly_MP;                            */
/*  output boolean EngReqH_bGlblStopSTTTAir_MP;                               */
/*  output boolean EngReqH_bGlblStopSTTTCo_MP;                                */
/*  output boolean EngReqH_bGlblStopSTTTOil_MP;                               */
/*  output boolean EngReqH_bGlblStopSTTTOxC_MP;                               */
/*  output boolean EngReqH_bNEngRstrtAutnAvl;                                 */
/*  output boolean EngReqH_bSTTRstrtReqCdnTFu;                                */
/*  output boolean EngReqH_bSTTRstrtReqCdnTFu_MP;                             */
/*  output boolean EngReqH_bSTTRstrtReqCdnThMgt;                              */
/*  output boolean EngReqH_bSyntNotSTTRstrtReq;                               */
/*  output boolean EngReqH_bSyntSTTRstrtReq;                                  */
/*  output uint16 EngReqH_ctTDCPndRaw_MP;                                     */
/*  output uint8 EngReqH_ctTDCPnd_MP;                                         */
/*  output uint16 EngReqH_facCorCntTDC_MP;                                    */
/*  output boolean ENGREQH_bHysteresisOutput;                                 */
/*  output sint16 EngReqH_tAirVal;                                            */
/*  output uint16 EngReqH_tOxCMinHeatStopAuth_MP;                             */
/*  output uint16 EngReqH_tOxCMinStopAuth_MP;                                 */
/*  output uint16 EngReqH_tiInhEngStopAFA_MP;                                 */
/*  output uint16 EngReqH_tiInhEngStopAuthSTT_MP;                             */
/*  output uint16 EngReqH_tiInhEngStopCanPurg_MP;                             */
/*  output uint16 EngReqH_tiInhEngStopDft_MP;                                 */
/*  output uint16 EngReqH_tiInhEngStopRStrtReq_MP;                            */
/*  output uint16 EngReqH_tiInhEngStopTqAdp_MP;                               */
/*  output uint16 EngReqH_tiInhEngStop_MP;                                    */
/*  output uint8 ENGREQH_u8CoPTStEngPrev;                                     */
/*  output boolean ENGREQH_bSwitcherStopSTTTCo;                               */
/*  output boolean ENGREQH_bSwitcherStopSTTTOil;                              */
/*  output boolean ENGREQH_bOutRSLatchSTTStrtDly;                             */
/*  output boolean ENGREQH_bOutRSLatchSTTStrtPrev;                            */
/*  output uint16 ENGREQH_u16StopSTTStrtDlyCount;                             */
/*  output boolean ENGREQH_bAndLogicalConditionPrev;                          */
/*  output uint16 ENGREQH_u16AuthStopSTTLsOkCount;                            */
/*  output boolean ENGREQH_bSwitchAuthTAirMem;                                */
/*  output boolean ENGREQH_bOutRSLatchSTTTOxCLo;                              */
/*  output uint32 ENGREQH_u32FilTrbEstimMem;                                  */
/*  output boolean ENGREQH_bOutRSLatchDmgTrb;                                 */
/*  output boolean ENGREQH_bEnaCounterPrev;                                   */
/*  output boolean ENGREQH_bRSTCounterPrev;                                   */
/*  output boolean ENGREQH_bRSTEngNOnIdlPev;                                  */
/*  output uint16 ENGREQH_u16CounterTrbProt;                                  */
/*  output boolean ENGREQH_bOutRSLatchTrbProt;                                */
/*  output uint8 ENGREQH_u8STTRstrtReqCount;                                  */
/*  output boolean ENGREQH_bOutTurnOnDelay;                                   */
/*  output boolean ENGREQH_bDeacCanPurgMPPrev;                                */
/*  output uint16 ENGREQH_u16DeacCanPurgMPCount;                              */
/*  output boolean ENGREQH_bLogicalAndInhLrnAFAPrev;                          */
/*  output uint16 ENGREQH_u16InhLrnAFACount;                                  */
/*  output boolean ENGREQH_bInhLrnAFAOut;                                     */
/*  output sint16 ENGREQH_s16nEngRstrtAutn;                                   */
/*  output boolean ENGREQH_bLogicalORPrev;                                    */
/*  output uint16 EngReqH_pAirExtMem_MP;                                      */
/*  output boolean EngReqH_bpOilAuthSTT;                                      */
/*  output boolean ENGREQH_bpOilAuthSTTPrev;                                  */
/*  output boolean EngReqH_bAuthStopSTTTTrb;                                  */
/*  output boolean ENGREQH_bpAirExtMemPrev;                                   */
/*  output boolean ENGREQH_bpAirExtMemPrev_2;                                 */
/*  output boolean ENGREQH_bpAirExtUnfav;                                     */
/*  output boolean ENGREQH_bpAirDeltaUnfav;                                   */
/*  output uint8 ENGREQH_u8pOilAuthSTTCount;                                  */
/*  output uint16 ENGREQH_u16nEngFilter;                                      */
/*  output uint32 ENGREQH_u32nEngFiltMem;                                     */
/*  output uint8 EngReqH_stEngStopAuth;                                       */
/*  output boolean EngReqH_bDetPresAirUnfav;                                  */
/*  output boolean EngReqH_bAuthStopSTTPOil;                                  */
/*  output uint16 EngReqH_tiInhEngStopInjSys_MP;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidInitOutput(void)
{
   uint16 u16LocalExt_pAirExtMes;
   uint16 u16LocalExt_nEngToothClc;


   VEMS_vidSET(EngReqH_bEngRStrtAutnAvl,0);
   VEMS_vidSET(EngReqH_bEngRunReq,0);
   EngReqH_bAuthStopSTTLsOk = 0;
   EngReqH_bAuthStopSTTStrtDly = 0;
   EngReqH_bAuthStopSTTTAir = 0;
   EngReqH_bAuthStopSTTTCo = 0;
   EngReqH_bAuthStopSTTTCoMem_MP = 0;
   EngReqH_bAuthStopSTTTOil = 0;
   EngReqH_bAuthStopSTTTOxC = 0;
   EngReqH_bCdnAuthStopSTT  = 0;
   EngReqH_bCdnTCoMax_MP  = 0;
   EngReqH_bCdnTCoMin_MP = 0;
   EngReqH_bCdnTOilMax_MP = 0;
   EngReqH_bCdnTOilMin_MP = 0;
   EngReqH_bCntTDCRstrtAutnAvl = 0;
   EngReqH_bEngRstrtAutnAvlTmp_MP = 1;
   EngReqH_bFctAuthStopSTTTCo = 0;
   EngReqH_bFctAuthStopSTTTOil = 0;
   EngReqH_bFctAuthStopSTTTOxCHi = 0;
   EngReqH_bFctAuthStopSTTTOxCLo = 0;
   EngReqH_bFctStopAuthTAir = 0;
   EngReqH_bFctStopTAirMem_MP = 0;
   EngReqH_bForcCdnStopSTTTCo = 0;
   EngReqH_bForcCdnStopSTTTOil = 0;
   EngReqH_bForcCdnStopSTTTOxC = 0;
   EngReqH_bForcStopAuthTAir  = 0;
   EngReqH_bGlblStopSTTLsOk_MP = 0;
   EngReqH_bGlblStopSTTStrtDly_MP = 0;
   EngReqH_bGlblStopSTTTAir_MP = 0;
   EngReqH_bGlblStopSTTTCo_MP = 0;
   EngReqH_bGlblStopSTTTOil_MP = 0;
   EngReqH_bGlblStopSTTTOxC_MP = 0;
   EngReqH_bNEngRstrtAutnAvl = 0;
   EngReqH_bSTTRstrtReqCdnTFu = 0;
   EngReqH_bSTTRstrtReqCdnTFu_MP = 0;
   EngReqH_bSTTRstrtReqCdnThMgt = 0;
   EngReqH_bSyntNotSTTRstrtReq = 0;
   EngReqH_bSyntSTTRstrtReq = 0;
   EngReqH_ctTDCPndRaw_MP = 0;
   EngReqH_ctTDCPnd_MP = 0;
   EngReqH_facCorCntTDC_MP = 0;
   ENGREQH_bHysteresisOutput = 0;
   EngReqH_tAirVal = 0;
   EngReqH_tOxCMinHeatStopAuth_MP = 50;
   EngReqH_tOxCMinStopAuth_MP = 50;
   EngReqH_tiInhEngStopAFA_MP = 1;
   EngReqH_tiInhEngStopAuthSTT_MP = 1;
   EngReqH_tiInhEngStopCanPurg_MP = 1;
   EngReqH_tiInhEngStopDft_MP = 1;
   EngReqH_tiInhEngStopRStrtReq_MP = 1;
   EngReqH_tiInhEngStopTqAdp_MP = 1;
   EngReqH_tiInhEngStop_MP = 1;
   ENGREQH_u8CoPTStEngPrev = 1;
   /*F01_01_02_partie_disfonctionnelle */
   ENGREQH_bSwitcherStopSTTTCo = 0;
   /*F01_02_02_partie_dysfonctionnelle*/
   ENGREQH_bSwitcherStopSTTTOil = 0;
   /*F01_03_Temporisation_apres_demarrage_avant_autorisation_stop */
   ENGREQH_bOutRSLatchSTTStrtDly = 0;
   ENGREQH_bOutRSLatchSTTStrtPrev = 0;
   ENGREQH_u16StopSTTStrtDlyCount = 0;
   /*F01_04_Condition_sondes_lambda_pretes_pour_autorisation_stop*/
   ENGREQH_bAndLogicalConditionPrev = 0;
   ENGREQH_u16AuthStopSTTLsOkCount = 0;
   /*F01_05_03_partie_disfonctionnelle */
   ENGREQH_bSwitchAuthTAirMem = 0;
   /*F01_06_01_Condition_de_seuil_bas_temperature_catalyseur */
   ENGREQH_bOutRSLatchSTTTOxCLo = 0;
   /*F01_07_01_01_Calcul_regime_turbine */
   ENGREQH_u32FilTrbEstimMem = 0;
   /*F01_07_01_03_Gestion_compteur_usure_turbo */
   ENGREQH_bOutRSLatchDmgTrb = 0;
   ENGREQH_bEnaCounterPrev = 0;
   ENGREQH_bRSTCounterPrev = 0;
   /* F01_07_02_Calcul_delai_autorisation_STOP_fonction_turbo */
   ENGREQH_bRSTEngNOnIdlPev = 0;
   ENGREQH_u16CounterTrbProt = 0;
   ENGREQH_bOutRSLatchTrbProt = 0;
   /*F02_03_Observation_du_temps_minimum_de_stop */
   ENGREQH_u8STTRstrtReqCount = 0;
   ENGREQH_bOutTurnOnDelay = 0;
   /*F05_02_Temps_max_interdiction_purge_canister */
   ENGREQH_bDeacCanPurgMPPrev = 0;
   ENGREQH_u16DeacCanPurgMPCount = 0;
   /*F05_03_Temps_max_interdiction_apprentissage_richesse*/
   ENGREQH_bLogicalAndInhLrnAFAPrev = 0;
   ENGREQH_u16InhLrnAFACount = 0;
   ENGREQH_bInhLrnAFAOut = 0;
   /*F06_01_Condition_regime_moteur */
   ENGREQH_s16nEngRstrtAutn = 0;
   /*F06_03_Condition_redemarrage_autonome*/
   ENGREQH_bLogicalORPrev = 0;
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   EngReqH_pAirExtMem_MP = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pAirExtMes,
                                                    500,
                                                    1500);
   EngReqH_bpOilAuthSTT = 0;
   ENGREQH_bpOilAuthSTTPrev = 0;
   EngReqH_bAuthStopSTTTTrb = 0;
   ENGREQH_bpAirExtMemPrev = 0;
   ENGREQH_bpAirExtMemPrev_2 = 0;
   ENGREQH_bpAirExtUnfav = 0;
   ENGREQH_bpAirDeltaUnfav = 0;
   ENGREQH_u8pOilAuthSTTCount = 0;
   VEMS_vidGET(Ext_nEngToothClc, u16LocalExt_nEngToothClc);
   ENGREQH_u16nEngFilter = (uint16)MATHSRV_udtMIN(u16LocalExt_nEngToothClc,
                                                  2000);
   ENGREQH_u32nEngFiltMem = u16LocalExt_nEngToothClc * 256;
   VEMS_vidSET(EngReqH_stEngStopAuth, 1);
   VEMS_vidSET(EngReqH_bDetPresAirUnfav, 0);
   EngReqH_bAuthStopSTTPOil = 0;
   EngReqH_tiInhEngStopInjSys_MP = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondTempEauAutoriStop                           */
/* !Description :  Cette fonction autorise le STOP à partir de l’observation  */
/*                 de la température eau moteur. Elle comprend une partie     */
/*                 fonctionnelle et une dysfonctionnelle.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGREQH_vidPartieFonctionTempEau();                      */
/*  extf argret void ENGREQH_vidPartieDisfoncTempEau();                       */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input boolean EngReqH_bFctAuthStopSTTTCo;                                 */
/*  input boolean EngReqH_bForcCdnStopSTTTCo;                                 */
/*  output boolean EngReqH_bAuthStopSTTTCo;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondTempEauAutoriStop(void)
{
   boolean bLocalInhCdnStopTCo;


   ENGREQH_vidPartieFonctionTempEau();
   ENGREQH_vidPartieDisfoncTempEau();
   bLocalInhCdnStopTCo = GDGAR_bGetFRM(FRM_FRM_INHCDNSTOPTCO);
   if (bLocalInhCdnStopTCo == 0)
   {
      EngReqH_bAuthStopSTTTCo = EngReqH_bFctAuthStopSTTTCo;
   }
   else
   {
      EngReqH_bAuthStopSTTTCo = EngReqH_bForcCdnStopSTTTCo;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidPartieFonctionTempEau                           */
/* !Description :  Ce sous système est la partie fonctionnelle d’autorisation */
/*                 du stop en fonction de la température d’eau moteur. On     */
/*                 autorise le stop si la température moteur est comprise     */
/*                 entre 2 seuils calibrables.                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 CoPTSt_tCoMesStrt;                                           */
/*  input sint16 EngReqH_tCoMaxStopAuth_C;                                    */
/*  input sint16 EngReqH_tCoHysMaxStopAuth_C;                                 */
/*  input uint8 EngReqH_tCoStopAuthX_A[12];                                   */
/*  input uint8 EngReqH_tCoMinStopAuth_T[12];                                 */
/*  input sint16 EngReqH_tCoHysMinStopAuth_C;                                 */
/*  input boolean EngReqH_bCdnTCoMax_MP;                                      */
/*  input boolean EngReqH_bCdnTCoMin_MP;                                      */
/*  output boolean EngReqH_bCdnTCoMax_MP;                                     */
/*  output boolean EngReqH_bCdnTCoMin_MP;                                     */
/*  output boolean EngReqH_bFctAuthStopSTTTCo;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidPartieFonctionTempEau(void)
{
   uint8  u8LocalSiteInterpolation;
   uint8  u8LocalCalcInterp;
   uint16 u16LocalCalcPara;
   sint16 s16LocalExt_tCoMes;
   sint16 s16LocalCoPTSt_tCoMesStrt;
   sint16 s16LocalDiff;
   sint32 s32LocalDiff;
   sint32 s32Localsum;


   VEMS_vidGET(Ext_tCoMes,s16LocalExt_tCoMes);
   VEMS_vidGET(CoPTSt_tCoMesStrt,s16LocalCoPTSt_tCoMesStrt);
   /*NegHys*/
   if(s16LocalExt_tCoMes >= EngReqH_tCoMaxStopAuth_C)
   {
      EngReqH_bCdnTCoMax_MP = 0;
   }
   else
   {
      s32LocalDiff =
         (sint32)(EngReqH_tCoMaxStopAuth_C - EngReqH_tCoHysMaxStopAuth_C);
      if (s16LocalExt_tCoMes <= s32LocalDiff)
      {
         EngReqH_bCdnTCoMax_MP = 1;
      }
   }
   s32Localsum = (sint32)(s16LocalCoPTSt_tCoMesStrt + 40 );
   u8LocalSiteInterpolation = (uint8)MATHSRV_udtCLAMP(s32Localsum, 0, 254);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(EngReqH_tCoStopAuthX_A,
                                                  u8LocalSiteInterpolation,
                                                  12);
   u8LocalCalcInterp =
      MATHSRV_u8Interp1d(EngReqH_tCoMinStopAuth_T,u16LocalCalcPara);
   s32LocalDiff =
      (sint32)(u8LocalCalcInterp - EngReqH_tCoHysMinStopAuth_C - 40);
   /*PosHys*/
   if ((sint32)s16LocalExt_tCoMes <= s32LocalDiff)
   {
      EngReqH_bCdnTCoMin_MP = 0;
   }
   else
   {
      s16LocalDiff = (sint16)(u8LocalCalcInterp - 40);
      if (s16LocalExt_tCoMes >= s16LocalDiff)
      {
         EngReqH_bCdnTCoMin_MP = 1;
      }
   }
   if (  (EngReqH_bCdnTCoMax_MP != 0)
      && (EngReqH_bCdnTCoMin_MP != 0))
   {
      EngReqH_bFctAuthStopSTTTCo = 1;
   }
   else
   {
      EngReqH_bFctAuthStopSTTTCo = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidPartieDisfoncTempEau                            */
/* !Description :  Ce sous système est la partie dysfonctionnelle             */
/*                 d’autorisation de STOP en fonction de la température d’eau */
/*                 moteur. Elle est activée sur un booléen de reconfiguration */
/*                 en cas de défaillance sur la température d’eau.            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 ENGREQH_u8CoPTStEngPrev;                                      */
/*  input boolean ENGREQH_bSwitcherStopSTTTCo;                                */
/*  input boolean EngReqH_bAuthStopSTTTCoMem_MP;                              */
/*  input boolean EngReqH_bFctAuthStopSTTTCo;                                 */
/*  input uint8 EngReqH_stTCoDftVal_C;                                        */
/*  output boolean EngReqH_bAuthStopSTTTCoMem_MP;                             */
/*  output boolean ENGREQH_bSwitcherStopSTTTCo;                               */
/*  output boolean EngReqH_bForcCdnStopSTTTCo;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidPartieDisfoncTempEau(void)
{
   boolean bLocalInhCdnStopTCo;
   uint8   u8LocalCoPTSt_stEng;


   bLocalInhCdnStopTCo = GDGAR_bGetFRM(FRM_FRM_INHCDNSTOPTCO);
   VEMS_vidGET(CoPTSt_stEng,u8LocalCoPTSt_stEng);
   if ( (u8LocalCoPTSt_stEng == 3)
      &&(ENGREQH_u8CoPTStEngPrev != 3))
   {
      EngReqH_bAuthStopSTTTCoMem_MP = 0;
   }
   else
   {
      EngReqH_bAuthStopSTTTCoMem_MP = ENGREQH_bSwitcherStopSTTTCo;
   }
   if (bLocalInhCdnStopTCo != 0)
   {
      ENGREQH_bSwitcherStopSTTTCo = EngReqH_bAuthStopSTTTCoMem_MP;
   }
   else
   {
      ENGREQH_bSwitcherStopSTTTCo = EngReqH_bFctAuthStopSTTTCo;
   }
   switch (EngReqH_stTCoDftVal_C)
   {
      case 0:
         EngReqH_bForcCdnStopSTTTCo = EngReqH_bFctAuthStopSTTTCo;
         break;

      case 1:
         EngReqH_bForcCdnStopSTTTCo = 1;
         break;

      case 2:
         EngReqH_bForcCdnStopSTTTCo = ENGREQH_bSwitcherStopSTTTCo;
         break;

      case 3:
         EngReqH_bForcCdnStopSTTTCo = 0;
         break;

      default:
         EngReqH_bForcCdnStopSTTTCo = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondTempHuileAutoStop                           */
/* !Description :  Cette fonction autorise le STOP en fonction de la          */
/*                 température d’huile. Elle comprend une partie fonctionnelle*/
/*                 et une dysfonctionnelle.                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGREQH_vidPartieFonctTempHuile();                       */
/*  extf argret void ENGREQH_vidPartieDisfonTempHuile();                      */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input boolean EngReqH_bFctAuthStopSTTTOil;                                */
/*  input boolean EngReqH_bForcCdnStopSTTTOil;                                */
/*  output boolean EngReqH_bAuthStopSTTTOil;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondTempHuileAutoStop(void)
{
   boolean  bLocalInhCdnStopTOil;


   ENGREQH_vidPartieFonctTempHuile();
   ENGREQH_vidPartieDisfonTempHuile();
   bLocalInhCdnStopTOil = GDGAR_bGetFRM(FRM_FRM_INHCDNSTOPTOIL);
   if (bLocalInhCdnStopTOil == 0)
   {
      EngReqH_bAuthStopSTTTOil = EngReqH_bFctAuthStopSTTTOil;
   }
   else
   {
      EngReqH_bAuthStopSTTTOil = EngReqH_bForcCdnStopSTTTOil;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidPartieFonctTempHuile                            */
/* !Description :  Ce sous système est la partie fonctionnelle de la fonction */
/*                 d’autorisation du stop en fonction de la température       */
/*                 d’huile. Dans ce sous système, on autorise le stop si la   */
/*                 température d’huile est comprise entre 2 seuils            */
/*                 calibrables.                                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input sint16 EngReqH_tOilMaxStopAuth_C;                                   */
/*  input sint16 EngReqH_tOilHysMaxStopAuth_C;                                */
/*  input sint16 EngReqH_tOilMinStopAuth_C;                                   */
/*  input sint16 EngReqH_tOilHysMinStopAuth_C;                                */
/*  input boolean EngReqH_bCdnTOilMax_MP;                                     */
/*  input boolean EngReqH_bCdnTOilMin_MP;                                     */
/*  output boolean EngReqH_bCdnTOilMax_MP;                                    */
/*  output boolean EngReqH_bCdnTOilMin_MP;                                    */
/*  output boolean EngReqH_bFctAuthStopSTTTOil;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidPartieFonctTempHuile(void)
{
   sint16 s16LocalExt_tOilMes;
   sint32 s32LocalDiff;
   sint32 s32LocalEngReqH_tOilMaxStopAuth;
   sint32 s32LocalEngReqH_tOilMinStopAuth;


   /*NegHys*/
   VEMS_vidGET(Ext_tOilMes,s16LocalExt_tOilMes);
   s32LocalEngReqH_tOilMaxStopAuth = (sint32)(EngReqH_tOilMaxStopAuth_C * 10);
   if (s16LocalExt_tOilMes >= s32LocalEngReqH_tOilMaxStopAuth)
   {
      EngReqH_bCdnTOilMax_MP = 0;
   }
   else
   {
      s32LocalDiff =
         (sint32)(EngReqH_tOilMaxStopAuth_C - EngReqH_tOilHysMaxStopAuth_C);
      s32LocalDiff = s32LocalDiff * 10;
      if (s16LocalExt_tOilMes <= s32LocalDiff )
      {
         EngReqH_bCdnTOilMax_MP = 1;
      }
   }
   /*PosHys*/
   s32LocalDiff =
      (sint32)(EngReqH_tOilMinStopAuth_C - EngReqH_tOilHysMinStopAuth_C);
   s32LocalDiff = s32LocalDiff * 10;
   if (s16LocalExt_tOilMes <= s32LocalDiff)
   {
      EngReqH_bCdnTOilMin_MP = 0;
   }
   else
   {
      s32LocalEngReqH_tOilMinStopAuth =
         (sint32)(EngReqH_tOilMinStopAuth_C * 10);
      if(s16LocalExt_tOilMes >= s32LocalEngReqH_tOilMinStopAuth)
      {
         EngReqH_bCdnTOilMin_MP = 1;
      }
   }

   if (  (EngReqH_bCdnTOilMax_MP != 0)
      && (EngReqH_bCdnTOilMin_MP != 0))
   {
      EngReqH_bFctAuthStopSTTTOil = 1;
   }
   else
   {
      EngReqH_bFctAuthStopSTTTOil = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidPartieDisfonTempHuile                           */
/* !Description :  Ce sous système est la partie dysfonctionnelle             */
/*                 d’autorisation de STOP en fonction de la température       */
/*                 d’huile mo- teur. Elle est activée sur un booléen de       */
/*                 reconfiguration en cas de défaillance sur la température   */
/*                 d’huile.                                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean EngReqH_bFctAuthStopSTTTOil;                                */
/*  input uint8 ENGREQH_u8CoPTStEngPrev;                                      */
/*  input uint8 EngReqH_stTOilDftVal_C;                                       */
/*  input boolean ENGREQH_bSwitcherStopSTTTOil;                               */
/*  output boolean ENGREQH_bSwitcherStopSTTTOil;                              */
/*  output boolean EngReqH_bForcCdnStopSTTTOil;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidPartieDisfonTempHuile(void)
{
   boolean bLocalInhCdnStopTOil;
   uint8   u8LocalCoPTSt_stEng;


   bLocalInhCdnStopTOil = GDGAR_bGetFRM(FRM_FRM_INHCDNSTOPTOIL);
   VEMS_vidGET(CoPTSt_stEng,u8LocalCoPTSt_stEng);
   if (bLocalInhCdnStopTOil == 0)
   {
      ENGREQH_bSwitcherStopSTTTOil = EngReqH_bFctAuthStopSTTTOil;
   }
   else
   {
      if (  (u8LocalCoPTSt_stEng == 3)
         && (ENGREQH_u8CoPTStEngPrev != 3))
      {
         ENGREQH_bSwitcherStopSTTTOil = 0;
      }
   }
   switch (EngReqH_stTOilDftVal_C)
   {
      case 0:
         EngReqH_bForcCdnStopSTTTOil = EngReqH_bFctAuthStopSTTTOil;
         break;

      case 1:
         EngReqH_bForcCdnStopSTTTOil = 1;
         break;

      case 2:
         EngReqH_bForcCdnStopSTTTOil = ENGREQH_bSwitcherStopSTTTOil;
         break;

      case 3:
         EngReqH_bForcCdnStopSTTTOil = 0;
         break;

      default:
         EngReqH_bForcCdnStopSTTTOil = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidTempoDemarrageAutStop                           */
/* !Description :  Cette fonction autorise le STOP au bout d’une temporisation*/
/*                 débutant avec l’entrée en phase engine_running suite  à un */
/*                 démarrage/redémarrage.                                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input sint16 CoPTSt_tCoMesStrt;                                           */
/*  input uint8 EngReqH_tCoStopAuthX_A[12];                                   */
/*  input uint16 EngReqH_tiDlyStrtSTTAuth_T[12];                              */
/*  input boolean ENGREQH_bOutRSLatchSTTStrtDly;                              */
/*  input boolean ENGREQH_bOutRSLatchSTTStrtPrev;                             */
/*  input uint16 ENGREQH_u16StopSTTStrtDlyCount;                              */
/*  output boolean ENGREQH_bOutRSLatchSTTStrtDly;                             */
/*  output uint16 ENGREQH_u16StopSTTStrtDlyCount;                             */
/*  output boolean EngReqH_bAuthStopSTTStrtDly;                               */
/*  output boolean ENGREQH_bOutRSLatchSTTStrtPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidTempoDemarrageAutStop(void)
{
   uint8  u8LocalCoPTSt_stEng;
   uint8  u8LocalSiteInterpolation;
   uint16 u16LocalTdly;
   uint16 u16LocalCalcPara;
   sint16 s16LocalCoPTSt_tCoMesStrt;
   sint32 s32Localsum;


   VEMS_vidGET(CoPTSt_stEng,u8LocalCoPTSt_stEng);
   VEMS_vidGET(CoPTSt_tCoMesStrt, s16LocalCoPTSt_tCoMesStrt);
   /* bascule RS (R Prioritaire): Q = !R . (S + Q) */
   if (u8LocalCoPTSt_stEng == 1)
   {
      ENGREQH_bOutRSLatchSTTStrtDly = 0;
   }
   else
   {
      if (u8LocalCoPTSt_stEng == 5)
      {
         ENGREQH_bOutRSLatchSTTStrtDly = 1;
      }
   }
   s32Localsum = (sint32)(s16LocalCoPTSt_tCoMesStrt + 40);
   u8LocalSiteInterpolation = (uint8)MATHSRV_udtCLAMP(s32Localsum, 0, 254);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(EngReqH_tCoStopAuthX_A,
                                                  u8LocalSiteInterpolation,
                                                  12);
   u16LocalTdly =
      MATHSRV_u16Interp1d(EngReqH_tiDlyStrtSTTAuth_T, u16LocalCalcPara);

   /*Turn_On_Delay*/
   if (ENGREQH_bOutRSLatchSTTStrtDly != 0)
   {
      if (ENGREQH_bOutRSLatchSTTStrtPrev == 0)
      {
         ENGREQH_u16StopSTTStrtDlyCount =
            (uint16)MATHSRV_udtMIN(u16LocalTdly, 400);
      }
      else
      {
         if (ENGREQH_u16StopSTTStrtDlyCount > 0)
         {
            ENGREQH_u16StopSTTStrtDlyCount =
               (uint16)(ENGREQH_u16StopSTTStrtDlyCount - 1);
         }
      }
      if (ENGREQH_u16StopSTTStrtDlyCount == 0)
      {
         EngReqH_bAuthStopSTTStrtDly = 1;
      }
      else
      {
         EngReqH_bAuthStopSTTStrtDly = 0;
      }
   }
   else
   {
      EngReqH_bAuthStopSTTStrtDly = 0;
   }
   ENGREQH_bOutRSLatchSTTStrtPrev = ENGREQH_bOutRSLatchSTTStrtDly;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondSondLambdaAutStop                           */
/* !Description :  Cette fonction autorise le STOP si les sondes à oxygène    */
/*                 amont et aval du catalyseur sont prêtes depuis une         */
/*                 temporisation calibrable.On peut désactiver, par           */
/*                 calibration, la condition sur chacune des sondes.          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input boolean LsSys_bLsUsMainOxCHeatOk;                                   */
/*  input boolean LsSys_bLsDsMainOxCHeatOk;                                   */
/*  input boolean EngReqH_bDeacUsLs_C;                                        */
/*  input boolean EngReqH_bDeacDsLs_C;                                        */
/*  input boolean ENGREQH_bAndLogicalConditionPrev;                           */
/*  input uint16 EngReqH_tiDlyStopAuthLsOk_C;                                 */
/*  input uint16 ENGREQH_u16AuthStopSTTLsOkCount;                             */
/*  output uint16 ENGREQH_u16AuthStopSTTLsOkCount;                            */
/*  output boolean EngReqH_bAuthStopSTTLsOk;                                  */
/*  output boolean ENGREQH_bAndLogicalConditionPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondSondLambdaAutStop(void)
{
   boolean bLocalswitcher1;
   boolean bLocalswitcher2;
   boolean bLocalResult;
   boolean bLocalInhCdnStopLsUsOxC;
   boolean bLocalInhCdnStopLsDsOxC;
   boolean bLocalLsSys_bLsUsMainOxCHeatOk;
   boolean bLocalLsSys_bLsDsMainOxCHeatOk;


   VEMS_vidGET(LsSys_bLsUsMainOxCHeatOk, bLocalLsSys_bLsUsMainOxCHeatOk);
   VEMS_vidGET(LsSys_bLsDsMainOxCHeatOk, bLocalLsSys_bLsDsMainOxCHeatOk);
   bLocalInhCdnStopLsUsOxC = GDGAR_bGetFRM(FRM_FRM_INHCDNSTOPLSUSOXC);
   bLocalInhCdnStopLsDsOxC = GDGAR_bGetFRM(FRM_FRM_INHCDNSTOPLSDSOXC);
   if (  (EngReqH_bDeacUsLs_C != 0)
      || (bLocalInhCdnStopLsUsOxC != 0))
   {
      bLocalswitcher1 = 1;
   }
   else
   {
      bLocalswitcher1 = bLocalLsSys_bLsUsMainOxCHeatOk;
   }

   if (  (EngReqH_bDeacDsLs_C != 0)
      || (bLocalInhCdnStopLsDsOxC != 0))
   {
      bLocalswitcher2 = 1;
   }
   else
   {
      bLocalswitcher2 = bLocalLsSys_bLsDsMainOxCHeatOk;
   }

   if (  (bLocalswitcher1 != 0)
      && (bLocalswitcher2 != 0))
   {
      bLocalResult = 1;
   }
   else
   {
      bLocalResult = 0;
   }

    /*Turn_On_Delay*/
   if (bLocalResult != 0)
   {
      if (ENGREQH_bAndLogicalConditionPrev == 0)
      {
         ENGREQH_u16AuthStopSTTLsOkCount =
            (uint16)MATHSRV_udtMIN(EngReqH_tiDlyStopAuthLsOk_C, 400);
      }
      else
      {
         if (ENGREQH_u16AuthStopSTTLsOkCount > 0)
         {
            ENGREQH_u16AuthStopSTTLsOkCount =
               (uint16)(ENGREQH_u16AuthStopSTTLsOkCount - 1);
         }
      }
      if (ENGREQH_u16AuthStopSTTLsOkCount == 0)
      {
         EngReqH_bAuthStopSTTLsOk = 1;
      }
      else
      {
         EngReqH_bAuthStopSTTLsOk = 0;
      }
   }
   else
   {
      EngReqH_bAuthStopSTTLsOk = 0;
   }
   ENGREQH_bAndLogicalConditionPrev = bLocalResult;
}
/*-------------------------------- end of file -------------------------------*/