/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TWCMGT                                                  */
/* !Description     : TWCMGT component.                                       */
/*                                                                            */
/* !Module          : TWCMGT                                                  */
/* !Description     : Three Way Catalyst Heating Manager.                     */
/*                                                                            */
/* !File            : TWCMGT_FCT1.C                                           */
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
/*   1 / TWCMGT_VidInitOutput                                                 */
/*   2 / TWCMGT_VidInitThreeWayCatHeatMng                                     */
/*   3 / TWCMGT_VidThreeWayCatHeatMngVal                                      */
/*   4 / TWCMGT_VidMngHeatAuthorization                                       */
/*   5 / TWCMGT_VidAuthorizeActivCondCalc                                     */
/*   6 / TWCMGT_VidCheckActivationCond                                        */
/*   7 / TWCMGT_VidCheckTheOnceActivCond                                      */
/*   8 / TWCMGT_VidCheckTheEveryTimeActCd                                     */
/*   9 / TWCMGT_VidManageActivationCond                                       */
/*   10 / TWCMGT_VidCheckDeactivationCond                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 02024 / 01                                        */
/* !OtherRefs   : 01460_10_02228 / 1                                          */
/* !OtherRefs   : VEMS V02 ECU#054415                                         */
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
#include "TWCMGT.h"
#include "TWCMGT_L.h"
#include "TWCMGT_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidInitOutput                                       */
/* !Description :  fonction d'initialisation des variables produites          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TWCMGT_u16OutPassFilterK;                                    */
/*  input uint16 TWCMgt_tiPha1_NV;                                            */
/*  input uint16 TWCMgt_tiOutStg_MP;                                          */
/*  input boolean TWCMgt_bRstETBTiPha1_C;                                     */
/*  output boolean TWCMgt_bAcvNEngAcvCdn;                                     */
/*  output boolean TWCMGT_bBasculRS1;                                         */
/*  output boolean TWCMGT_bDeacHeatPhaPrev;                                   */
/*  output uint16 TWCMGT_u16OutPassFilterK;                                   */
/*  output uint32 TWCMGT_u32FilterKMem;                                       */
/*  output boolean TWCMgt_bLiOffClcAuth;                                      */
/*  output boolean TWCMGT_bInTWCLiOffTurnOnPrev;                              */
/*  output uint16 TWCMGT_u16TWCLiOffCount;                                    */
/*  output uint8 TWCMgt_stHeatPhaReqBas;                                      */
/*  output boolean TWCMGT_bTWCMinStrtCdnReqPrev;                              */
/*  output uint16 TWCMGT_u16AcvCdnAcvCount;                                   */
/*  output boolean TWCMGT_bInHeatPhaTurnOnPrev;                               */
/*  output uint16 TWCMGT_u16HeatPhaCount;                                     */
/*  output boolean TWCMGT_bInGearIdlTurnOnPrev;                               */
/*  output uint16 TWCMGT_u16GearIdlCount;                                     */
/*  output boolean TWCMGT_bInTWCHeatTurnOnPrev;                               */
/*  output uint16 TWCMGT_u16TWCHeatCount;                                     */
/*  output boolean TWCMGT_bOxCbEndMonORngItrsvPrev;                           */
/*  output boolean TWCMGT_bAcvHeatPhaPrev;                                    */
/*  output boolean TWCMGT_bLsMonbEndMonResHeatPrev;                           */
/*  output uint16 TWCMgt_tiOutStg_MP;                                         */
/*  output uint16 TWCMgt_tiHiTWCCurEstim_MP;                                  */
/*  output boolean TWCMGT_bIntiDlyPha3TurnOnPrev;                             */
/*  output uint16 TWCMGT_u16tiDlyPha3Count;                                   */
/*  output uint16 TWCMgt_tiLiOff;                                             */
/*  output boolean TWCMGT_bTWCHeatReqPrev2;                                   */
/*  output uint16 TWCMGT_u16tiLiOffOutMem;                                    */
/*  output uint8 TWCMgt_stTrbActPosnReqBas;                                   */
/*  output boolean TWCMgt_bAcvHeatPha;                                        */
/*  output uint16 TWCMgt_tiTWC;                                               */
/*  output boolean TWCMgt_bDeacHeatPha;                                       */
/*  output boolean TWCMgt_bTCoAr;                                             */
/*  output boolean TWCMgt_bTWCMinStrtCdnReq;                                  */
/*  output boolean TWCMgt_bAfterEngStrtReqCdn;                                */
/*  output boolean TWCMGT_bOutTurnOnDelay;                                    */
/*  output boolean TWCMGT_bMonMisfbClcMisfOBDPrev;                            */
/*  output boolean TWCMGT_bOuttiDlyPha3TurnOnDelay;                           */
/*  output boolean TWCMGT_bOutHeatPhaTurnOnDelay;                             */
/*  output boolean TWCMGT_bOutGearIdlTurnOnDelay;                             */
/*  output boolean TWCMGT_bOutTWCHeatTurnOnDelay;                             */
/*  output boolean TWCMGT_bOutTWCLiOffTurnOnDelay;                            */
/*  output boolean TWCMGT_bRstETBTiPha1Prev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidInitOutput(void)
{
   TWCMgt_bAcvNEngAcvCdn = 0;
   TWCMGT_bBasculRS1 = 0;
   TWCMGT_bDeacHeatPhaPrev = 0;
   TWCMGT_u16OutPassFilterK = 100;
   TWCMGT_u32FilterKMem = (uint32)(TWCMGT_u16OutPassFilterK * 256);
   TWCMgt_bLiOffClcAuth = 0;
   TWCMGT_bInTWCLiOffTurnOnPrev = 0;
   TWCMGT_u16TWCLiOffCount = 0;
   TWCMgt_stHeatPhaReqBas = 0;
   TWCMGT_bTWCMinStrtCdnReqPrev = 0;
   TWCMGT_u16AcvCdnAcvCount = 0;
   TWCMGT_bInHeatPhaTurnOnPrev = 0;
   TWCMGT_u16HeatPhaCount = 0;
   TWCMGT_bInGearIdlTurnOnPrev = 0;
   TWCMGT_u16GearIdlCount = 0;
   TWCMGT_bInTWCHeatTurnOnPrev = 0;
   TWCMGT_u16TWCHeatCount = 0;
   TWCMGT_bOxCbEndMonORngItrsvPrev = 0;
   TWCMGT_bAcvHeatPhaPrev = 0;
   TWCMGT_bLsMonbEndMonResHeatPrev = 0;
   TWCMgt_tiOutStg_MP = (uint16)MATHSRV_udtMIN(TWCMgt_tiPha1_NV, 50000);
   TWCMgt_tiHiTWCCurEstim_MP = TWCMgt_tiOutStg_MP;
   TWCMGT_bIntiDlyPha3TurnOnPrev = 0;
   TWCMGT_u16tiDlyPha3Count = 0;
   TWCMgt_tiLiOff = 0;
   TWCMGT_bTWCHeatReqPrev2 = 0;
   TWCMGT_u16tiLiOffOutMem = 0;
   TWCMgt_stTrbActPosnReqBas = 0;
   TWCMgt_bAcvHeatPha = 0;
   TWCMgt_tiTWC = 0;
   TWCMgt_bDeacHeatPha = 0;
   TWCMgt_bTCoAr = 0;
   TWCMgt_bTWCMinStrtCdnReq = 0;
   TWCMgt_bAfterEngStrtReqCdn = 0;
   TWCMGT_bOutTurnOnDelay = 0;
   TWCMGT_bMonMisfbClcMisfOBDPrev = 0;
   TWCMGT_bOuttiDlyPha3TurnOnDelay = 0;
   TWCMGT_bOutHeatPhaTurnOnDelay = 0;
   TWCMGT_bOutGearIdlTurnOnDelay = 0;
   TWCMGT_bOutTWCHeatTurnOnDelay = 0;
   TWCMGT_bOutTWCLiOffTurnOnDelay = 0;
   TWCMGT_bRstETBTiPha1Prev = TWCMgt_bRstETBTiPha1_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidInitThreeWayCatHeatMng                           */
/* !Description :  fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TWCMgt_bLiOffDone;                                          */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  input uint16 TWCMgt_tiHiTWCHiAr;                                          */
/*  output boolean TWCMgt_bLiOffDone;                                         */
/*  output uint8 TWCMgt_stHeatPhaReq;                                         */
/*  output uint8 TWCMgt_stTrbActPosnReq;                                      */
/*  output boolean OxC_bIntrHeat;                                             */
/*  output uint16 TWCMgt_tiHiTWCHiAr;                                         */
/*  output boolean TWCMgt_bTWCHeatReq;                                        */
/*  output boolean TWCMgt_bLiOffDonePrev;                                     */
/*  output boolean TWCMgt_bTWCHeatReqPrev;                                    */
/*  output uint16 TWCMgt_tiHiTWCHiArPrev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidInitThreeWayCatHeatMng(void)
{
   boolean bLocalTWCMgt_bLiOffDone;


   VEMS_vidSET(TWCMgt_bLiOffDone, 0);
   VEMS_vidSET(TWCMgt_stHeatPhaReq, 0);
   VEMS_vidSET(TWCMgt_stTrbActPosnReq, 0);
   VEMS_vidSET(OxC_bIntrHeat, 0);
   TWCMgt_tiHiTWCHiAr = 0;
   TWCMgt_bTWCHeatReq = 0;
   VEMS_vidGET(TWCMgt_bLiOffDone, bLocalTWCMgt_bLiOffDone);
   TWCMgt_bLiOffDonePrev = bLocalTWCMgt_bLiOffDone;
   TWCMgt_bTWCHeatReqPrev = TWCMgt_bTWCHeatReq;
   TWCMgt_tiHiTWCHiArPrev = TWCMgt_tiHiTWCHiAr;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidThreeWayCatHeatMngVal                            */
/* !Description :  The function is composed of 6                              */
/*                 blocks:F01_Manage_Heating_Authorization,                   */
/*                 F02_Manage_Progressive_Heating,                            */
/*                 F03_Authorize_Light_Off_Computation , F04_Manage_Light_Off */
/*                 , F05_Manage_Waste_Gate_Position and F06_Manage_output.    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TWCMGT_VidMngHeatAuthorization();                        */
/*  extf argret void TWCMGT_VidMng_Progressive_Heat();                        */
/*  extf argret void TWCMGT_VidAuthorizeLightOffCompt();                      */
/*  extf argret void TWCMGT_VidManage_Light_Off();                            */
/*  extf argret void TWCMGT_VidMngWaste_Gate_Position();                      */
/*  extf argret void TWCMGT_VidManage_Output();                               */
/*  input boolean OxC_bEndMonORngItrsv;                                       */
/*  input boolean LsMon_bEndMonResHeatLsUs;                                   */
/*  input boolean MonMisf_bClcMisfOBD;                                        */
/*  input boolean TWCMgt_bLiOffClcAuth;                                       */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  input boolean TWCMgt_bLiOffDone;                                          */
/*  input boolean TWCMgt_bRstETBTiPha1_C;                                     */
/*  output boolean TWCMgt_bTWCHeatReqPrev;                                    */
/*  output boolean TWCMgt_bLiOffDonePrev;                                     */
/*  output boolean TWCMGT_bOxCbEndMonORngItrsvPrev;                           */
/*  output boolean TWCMGT_bLsMonbEndMonResHeatPrev;                           */
/*  output boolean TWCMGT_bMonMisfbClcMisfOBDPrev;                            */
/*  output boolean TWCMGT_bRstETBTiPha1Prev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidThreeWayCatHeatMngVal(void)
{
   boolean bLocalOxC_bEndMonORngItrsv;
   boolean bLocalTWCMgt_bLiOffDone;
   boolean bLocalMonMisf_bClcMisfOBD;
   boolean bLocalLsMon_bEndMonResHeatLsUs;


   VEMS_vidGET(OxC_bEndMonORngItrsv, bLocalOxC_bEndMonORngItrsv);
   VEMS_vidGET(LsMon_bEndMonResHeatLsUs, bLocalLsMon_bEndMonResHeatLsUs);
   VEMS_vidGET(MonMisf_bClcMisfOBD, bLocalMonMisf_bClcMisfOBD);

   /*F01_Manage_Heating_Authorization*/
   TWCMGT_VidMngHeatAuthorization();
   /*F02_Manage_Progressive_Heating*/
   TWCMGT_VidMng_Progressive_Heat();
   /*F03_Authorize_Light_Off_Computation*/
   TWCMGT_VidAuthorizeLightOffCompt();
   if (TWCMgt_bLiOffClcAuth != 0)
   {
      /*F04_Manage_Light_Off*/
      TWCMGT_VidManage_Light_Off();
   }
   if (TWCMgt_bTWCHeatReq != 0)
   {
      /*F05_Manage_Waste_Gate_Position*/
      TWCMGT_VidMngWaste_Gate_Position();
   }
   /*F06_Manage_output*/
   TWCMGT_VidManage_Output();
   VEMS_vidGET(TWCMgt_bLiOffDone, bLocalTWCMgt_bLiOffDone);
   TWCMgt_bTWCHeatReqPrev = TWCMgt_bTWCHeatReq;
   TWCMgt_bLiOffDonePrev = bLocalTWCMgt_bLiOffDone;
   TWCMGT_bOxCbEndMonORngItrsvPrev = bLocalOxC_bEndMonORngItrsv;
   TWCMGT_bLsMonbEndMonResHeatPrev = bLocalLsMon_bEndMonResHeatLsUs;
   TWCMGT_bMonMisfbClcMisfOBDPrev = bLocalMonMisf_bClcMisfOBD;
   TWCMGT_bRstETBTiPha1Prev = TWCMgt_bRstETBTiPha1_C;

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidMngHeatAuthorization                             */
/* !Description :  This block manages the authorization of catalyst heating.  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TWCMGT_VidAuthorizeActivCondCalc();                      */
/*  extf argret void TWCMGT_VidCheckActivationCond();                         */
/*  extf argret void TWCMGT_VidCheckDeactivationCond();                       */
/*  extf argret void TWCMGT_VidMngActivAndDeactivCond();                      */
/*  input boolean TWCMgt_bAcvNEngAcvCdn;                                      */
/*  input boolean TWCMgt_bTWCHeatReqPrev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidMngHeatAuthorization(void)
{
   /* F01_Authorize_Activation_Conditions_Calculation */
   TWCMGT_VidAuthorizeActivCondCalc();
   if (TWCMgt_bAcvNEngAcvCdn != 0)
   {
      /*F02_Check_Activation_Conditions*/
      TWCMGT_VidCheckActivationCond();
   }

   if (TWCMgt_bTWCHeatReqPrev != 0)
   {
      /*F03_Check_Deactivation_Condition*/
      TWCMGT_VidCheckDeactivationCond();
   }
   /*F04_Manage_Activation_and_Deactivation_Conditions*/
   TWCMGT_VidMngActivAndDeactivCond();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidAuthorizeActivCondCalc                           */
/* !Description :  This block allows the activation of the calculus of the    */
/*                 block F02_Check_Activation_Conditions”. It checks that the */
/*                 engine is really started. This function is based on an     */
/*                 engine speed threshold                                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean TWCMgt_bAcvNEngAcvCdn;                                      */
/*  input boolean TWCMgt_bTWCHeatReqPrev;                                     */
/*  input boolean TWCMGT_bTWCHeatReqPrev2;                                    */
/*  input boolean TWCMGT_bBasculRS1;                                          */
/*  input uint16 TWCMgt_nEngTWCStrtThd_C;                                     */
/*  output boolean TWCMGT_bBasculRS1;                                         */
/*  output boolean TWCMgt_bAcvNEngAcvCdn;                                     */
/*  output boolean TWCMgt_bAcvNEngBegCdnAcv;                                  */
/*  output boolean TWCMGT_bTWCHeatReqPrev2;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidAuthorizeActivCondCalc(void)
{
   boolean  bLocalTWCMgt_bAcvNEngAcvCdn;
   uint16   u16LocalExt_nEng;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   bLocalTWCMgt_bAcvNEngAcvCdn = TWCMgt_bAcvNEngAcvCdn;
   if (  (TWCMgt_bTWCHeatReqPrev == 0)
      && (TWCMGT_bTWCHeatReqPrev2 != 0))
   {
      TWCMGT_bBasculRS1 = 1;
   }
   if (TWCMGT_bBasculRS1 != 0)
   {
      TWCMgt_bAcvNEngAcvCdn = 0;
   }
   else
   {
      if (u16LocalExt_nEng > TWCMgt_nEngTWCStrtThd_C)
      {
         TWCMgt_bAcvNEngAcvCdn = 1;
      }
   }
   if (  (bLocalTWCMgt_bAcvNEngAcvCdn == 0)
      && (TWCMgt_bAcvNEngAcvCdn != 0))
   {
      TWCMgt_bAcvNEngBegCdnAcv = 1 ;
   }
   else
   {
      TWCMgt_bAcvNEngBegCdnAcv = 0 ;
   }
   TWCMGT_bTWCHeatReqPrev2 = TWCMgt_bTWCHeatReqPrev;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidCheckActivationCond                              */
/* !Description :  This block manages the activation conditions which are     */
/*                 necessary to authorize a catalyst heating.                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TWCMGT_VidCheckTheOnceActivCond();                       */
/*  extf argret void TWCMGT_VidCheckTheEveryTimeActCd();                      */
/*  extf argret void TWCMGT_VidManageActivationCond();                        */
/*  input boolean TWCMgt_bAcvNEngBegCdnAcv;                                   */
/*  input boolean TWCMgt_bTWCMinStrtCdnReq;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidCheckActivationCond(void)
{
   if (TWCMgt_bAcvNEngBegCdnAcv != 0)
   {
      /*F01_Check_the_Once_Activation_Conditions*/
      TWCMGT_VidCheckTheOnceActivCond();
   }
   if (TWCMgt_bTWCMinStrtCdnReq != 0)
   {
      /*F02_Check_the_Everytime_Activation_Conditions*/
      TWCMGT_VidCheckTheEveryTimeActCd();
   }
   /*F03_Manage_Activation_Conditions*/
   TWCMGT_VidManageActivationCond();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidCheckTheOnceActivCond                            */
/* !Description :  This blocks checks the conditions which are required at    */
/*                 start of the engine to authorize a catalyst heating. It is */
/*                 calculated once at start when the flag                     */
/*                 TWCMgt_bAcvNEng_AcvCdnBeg” enables its operation.          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoStrtMes;                                              */
/*  input sint16 Ext_tDsThrMes;                                               */
/*  input sint16 Ext_tCoMesPwrl;                                              */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 ExM_tOxCEstim;                                               */
/*  input uint32 EOM_tiEngStopRst;                                            */
/*  input uint16 UsThrM_pAirExtEstim;                                         */
/*  input uint8 TWCMgt_tCoAcvHeatPha_A[12];                                   */
/*  input uint8 TWCMgt_stAcvHeatPha_T[12];                                    */
/*  input sint16 TWCMgt_tThdDifMaxTInTCo_C;                                   */
/*  input uint16 TWCMgt_tiThdMinEngStopRst_C;                                 */
/*  input uint16 TWCMgt_pThrMinAmbPres_C;                                     */
/*  input sint16 TWCMgt_tThdDifTCo_C;                                         */
/*  input sint16 TWCMgt_tTWCMaxHeatAcvT_C;                                    */
/*  output boolean TWCMgt_bTCoAr;                                             */
/*  output boolean TWCMgt_bTWCMinStrtCdnReq;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidCheckTheOnceActivCond(void)
{
   boolean bLocalInterpCompare;
   boolean bLocalThdDifCompare;
   uint8   u8LocalInterp1D;
   uint8   u8LocalExt_tCoStrtMes;
   uint16  u16LocalUsThrM_pAirExtEstim;
   uint16  u16LocalCalcPara;
   uint32  u32LocalEOM_tiEngStopRst;
   uint32  u32LocalDiffStrtMes;
   sint16  s16LocalExt_tCoStrtMes;
   sint16  s16LocaloutputInterp;
   sint16  s16LocalExt_tDsThrMes;
   sint16  s16LocalExt_tCoMesPwrl;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalExM_tOxCEstim;
   sint32  s32LocalDiffStrtMes;
   sint32  s32LocalDiffCoMes;


   VEMS_vidGET(Ext_tCoStrtMes, s16LocalExt_tCoStrtMes);
   VEMS_vidGET(Ext_tDsThrMes, s16LocalExt_tDsThrMes);
   VEMS_vidGET(Ext_tCoMesPwrl, s16LocalExt_tCoMesPwrl);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(ExM_tOxCEstim, s16LocalExM_tOxCEstim);
   VEMS_vidGET(EOM_tiEngStopRst, u32LocalEOM_tiEngStopRst);
   VEMS_vidGET(UsThrM_pAirExtEstim, u16LocalUsThrM_pAirExtEstim);

   s16LocalExt_tCoStrtMes =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoStrtMes, -40, 214);
   u8LocalExt_tCoStrtMes = (uint8)(s16LocalExt_tCoStrtMes + 40) ;
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(TWCMgt_tCoAcvHeatPha_A,
                                                  u8LocalExt_tCoStrtMes,
                                                  12);
   u8LocalInterp1D =
      MATHSRV_u8Interp1d(TWCMgt_stAcvHeatPha_T, u16LocalCalcPara);
   s16LocaloutputInterp = (sint16)(u8LocalInterp1D - 1);
   if (s16LocaloutputInterp > 0)
   {
      TWCMgt_bTCoAr = 1 ;
   }
   else
   {
      TWCMgt_bTCoAr = 0 ;
   }
   if(  (u8LocalInterp1D == 2)
     || (u8LocalInterp1D == 0))
   {
      bLocalInterpCompare = 1;
   }
   else
   {
      bLocalInterpCompare = 0;
   }

   if (TWCMgt_tThdDifMaxTInTCo_C < 0)
   {
      bLocalThdDifCompare = 0;
   }
   else
   {
      s32LocalDiffStrtMes =
         (sint32)(s16LocalExt_tCoStrtMes - s16LocalExt_tDsThrMes);
      u32LocalDiffStrtMes = (uint32)MATHSRV_udtABS(s32LocalDiffStrtMes);
      if (u32LocalDiffStrtMes <= (uint32)TWCMgt_tThdDifMaxTInTCo_C)
      {
         bLocalThdDifCompare = 1;
      }
      else
      {
         bLocalThdDifCompare = 0;
      }
   }
   s32LocalDiffCoMes = (sint32)(s16LocalExt_tCoMesPwrl - s16LocalExt_tCoMes);
   if (  (bLocalInterpCompare != 0)
      && (bLocalThdDifCompare != 0)
      && (u32LocalEOM_tiEngStopRst >= TWCMgt_tiThdMinEngStopRst_C)
      && (u16LocalUsThrM_pAirExtEstim >= TWCMgt_pThrMinAmbPres_C)
      && (s32LocalDiffCoMes > TWCMgt_tThdDifTCo_C)
      && (s16LocalExM_tOxCEstim < TWCMgt_tTWCMaxHeatAcvT_C))
   {
      TWCMgt_bTWCMinStrtCdnReq = 1;
   }
   else
   {
      TWCMgt_bTWCMinStrtCdnReq = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidCheckTheEveryTimeActCd                           */
/* !Description :  This block checks heating authorization conditions which   */
/*                 have to be check every time. It is calculated only when the*/
/*                 block “F01_Once_Checking_Activation_Conditions” authorizes */
/*                 it; that is to say only if all the start conditions are    */
/*                 satisfied.                                                 */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  input boolean VlvAct_bAcvExServo;                                         */
/*  input boolean TWCMgt_bInhAcvInServoCdn_C;                                 */
/*  input boolean TWCMgt_bInhAcvExServoCdn_C;                                 */
/*  output boolean TWCMgt_bAfterEngStrtReqCdn;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidCheckTheEveryTimeActCd(void)
{
   boolean bLocalVlvAct_bAcvInServo;
   boolean bLocalVlvAct_bAcvExServo;


   VEMS_vidGET(VlvAct_bAcvInServo, bLocalVlvAct_bAcvInServo);
   VEMS_vidGET(VlvAct_bAcvExServo, bLocalVlvAct_bAcvExServo);

   if (  (  (bLocalVlvAct_bAcvInServo != 0)
         || (TWCMgt_bInhAcvInServoCdn_C != 0))
      && (  (bLocalVlvAct_bAcvExServo != 0)
         || (TWCMgt_bInhAcvExServoCdn_C != 0)))
   {
      TWCMgt_bAfterEngStrtReqCdn = 1;
   }
   else
   {
      TWCMgt_bAfterEngStrtReqCdn = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidManageActivationCond                             */
/* !Description :  This block manages the required conditions to authorize a  */
/*                 catalyst heating and allow applying a delay before         */
/*                 activation.                                                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TWCMgt_bTCoAr;                                              */
/*  input uint16 TWCMgt_tiDlyAcvCdnAcvHiAr_C;                                 */
/*  input uint16 TWCMgt_tiDlyAcvCdnAcvLoAr_C;                                 */
/*  input boolean TWCMgt_bTWCMinStrtCdnReq;                                   */
/*  input boolean TWCMGT_bTWCMinStrtCdnReqPrev;                               */
/*  input uint16 TWCMGT_u16AcvCdnAcvCount;                                    */
/*  input uint16 TWCMgt_tiSdlFast_C;                                          */
/*  input boolean TWCMGT_bOutTurnOnDelay;                                     */
/*  input boolean TWCMgt_bAfterEngStrtReqCdn;                                 */
/*  output uint16 TWCMGT_u16AcvCdnAcvCount;                                   */
/*  output boolean TWCMGT_bOutTurnOnDelay;                                    */
/*  output boolean TWCMgt_bAcvHeatPha;                                        */
/*  output boolean TWCMGT_bTWCMinStrtCdnReqPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidManageActivationCond(void)
{
   uint16 u16LocalInputTurnOnDelay;


   if (TWCMgt_bTCoAr != 0)
   {
      u16LocalInputTurnOnDelay = TWCMgt_tiDlyAcvCdnAcvHiAr_C;
   }
   else
   {
      u16LocalInputTurnOnDelay = TWCMgt_tiDlyAcvCdnAcvLoAr_C;
   }

   if (TWCMgt_bTWCMinStrtCdnReq != 0)
   {
      if (TWCMGT_bTWCMinStrtCdnReqPrev == 0)
      {
         TWCMGT_u16AcvCdnAcvCount = u16LocalInputTurnOnDelay;
      }
      else
      {
         if (TWCMGT_u16AcvCdnAcvCount >= TWCMgt_tiSdlFast_C)
         {
            TWCMGT_u16AcvCdnAcvCount =
               (uint16)(TWCMGT_u16AcvCdnAcvCount - TWCMgt_tiSdlFast_C);
         }
         else
         {
            TWCMGT_u16AcvCdnAcvCount = 0;
         }
      }
      if (TWCMGT_u16AcvCdnAcvCount == 0)
      {
         TWCMGT_bOutTurnOnDelay = 1;
      }
      else
      {
         TWCMGT_bOutTurnOnDelay = 0;
      }
   }
   else
   {
      TWCMGT_bOutTurnOnDelay = 0;
   }

   if (  (TWCMGT_bOutTurnOnDelay != 0)
      && (TWCMgt_bAfterEngStrtReqCdn != 0))
   {
      TWCMgt_bAcvHeatPha = 1;
   }
   else
   {
      TWCMgt_bAcvHeatPha = 0;
   }
   TWCMGT_bTWCMinStrtCdnReqPrev = TWCMgt_bTWCMinStrtCdnReq;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidCheckDeactivationCond                            */
/* !Description :  This block manages the deactivation conditions of catalyst */
/*                 heating. When at least one of a deactivation condition is  */
/*                 true, TWCMgt_bDeacHeatPha” also becomes true. Therefore,   */
/*                 the catalyst heating is stopped.                           */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input sint16 TqDem_tqCkEfc;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint8 CoVSCtl_stAccP;                                               */
/*  input sint16 ExM_tOxCEstim;                                               */
/*  input boolean TWCMgt_bDeacHeatPha;                                        */
/*  input boolean TWCMGT_bDeacHeatPhaPrev;                                    */
/*  input boolean TWCMgt_bTWCHeatReqPrev;                                     */
/*  input uint16 TWCMgt_tiTWC;                                                */
/*  input uint16 TWCMgt_tiSdlFast_C;                                          */
/*  input boolean TWCMGT_bInHeatPhaTurnOnPrev;                                */
/*  input uint16 TWCMgt_tiDlyIdlHeatPhaThd_C;                                 */
/*  input uint16 TWCMGT_u16HeatPhaCount;                                      */
/*  input uint16 TWCMgt_nEngToDrvReq_A[12];                                   */
/*  input uint16 TWCMgt_tqNEngDrvReq_T[12];                                   */
/*  input uint8 TWCMgt_rAccePedDrvReq_C;                                      */
/*  input boolean TWCMGT_bOutHeatPhaTurnOnDelay;                              */
/*  input boolean TWCMGT_bInGearIdlTurnOnPrev;                                */
/*  input uint16 TWCMgt_tiDlyGearIdl_C;                                       */
/*  input uint16 TWCMGT_u16GearIdlCount;                                      */
/*  input boolean TWCMgt_bInhReGearHeatDeac_C;                                */
/*  input sint16 TWCMgt_tTWCHeatDeacThd_C;                                    */
/*  input boolean TWCMGT_bInTWCHeatTurnOnPrev;                                */
/*  input uint16 TWCMgt_tiDlyTWCHeatDeac_C;                                   */
/*  input uint16 TWCMGT_u16TWCHeatCount;                                      */
/*  input boolean TWCMgt_bTCoAr;                                              */
/*  input uint16 TWCMgt_tiHeatHiAr_A[12];                                     */
/*  input uint16 TWCMgt_tiHiTWCHiArPrev;                                      */
/*  input uint16 TWCMgt_tiTWCHeatDeac_T[12];                                  */
/*  input uint16 TWCMgt_tiMaxHeatThdLoAr_C;                                   */
/*  input boolean TWCMGT_bOutGearIdlTurnOnDelay;                              */
/*  input boolean TWCMGT_bOutTWCHeatTurnOnDelay;                              */
/*  output uint16 TWCMgt_tiTWC;                                               */
/*  output uint16 TWCMGT_u16HeatPhaCount;                                     */
/*  output boolean TWCMGT_bOutHeatPhaTurnOnDelay;                             */
/*  output boolean TWCMGT_bInHeatPhaTurnOnPrev;                               */
/*  output boolean OxC_bIntrHeat;                                             */
/*  output uint16 TWCMGT_u16GearIdlCount;                                     */
/*  output boolean TWCMGT_bOutGearIdlTurnOnDelay;                             */
/*  output boolean TWCMGT_bInGearIdlTurnOnPrev;                               */
/*  output uint16 TWCMGT_u16TWCHeatCount;                                     */
/*  output boolean TWCMGT_bOutTWCHeatTurnOnDelay;                             */
/*  output boolean TWCMGT_bInTWCHeatTurnOnPrev;                               */
/*  output boolean TWCMgt_bDeacHeatPha;                                       */
/*  output boolean TWCMGT_bDeacHeatPhaPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidCheckDeactivationCond(void)
{
   boolean   bLocalTqSys_bEngNOnIdl;
   boolean   bLocalHeatPhaInTurnOndelay;
   boolean   bLocalInTurnOndelayTWCHeat;
   boolean   bLocalFRMInhTWCHeat;
   boolean   bLocalOxC_bIntrHeat;
   boolean   bLocalInGearIdlTurnOn;
   boolean   bLocalGearHeaCord;
   boolean   bLocalDrvReq;
   boolean   bLocaltiTWC;
   boolean   bLocalTWCMgt_bDeacHeatPha;
   uint8     u8LocalCoPt_noEgdGearCord;
   uint8     u8LocalCoVSCtl_stAccP;
   uint16    u16LocalAccP_rAccP;
   uint16    u16LocalExt_nEng;
   uint16    u16LocalCalcPara;
   uint16    u16LocalInterp1D;
   uint16    u16LocalTWCMgttiTWC;
   uint16    u16LocalCalcParaHeatDeac;
   uint16    u16LocalAccPCompare;
   uint32    u32LocalTWCMgt_tiTWC;
   sint16    s16LocalExM_tOxCEstim;
   sint16    s16LocalTqDem_tqCkEfc;
   sint32    s32LocaltqNEngDrvReq;


   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);
   VEMS_vidGET(TqDem_tqCkEfc, s16LocalTqDem_tqCkEfc);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(CoVSCtl_stAccP, u8LocalCoVSCtl_stAccP);
   VEMS_vidGET(ExM_tOxCEstim, s16LocalExM_tOxCEstim);
   bLocalFRMInhTWCHeat = GDGAR_bGetFRM(FRM_FRM_INHTWCHEAT);

   /* producing TWCMgt_tiTWC */
   bLocalTWCMgt_bDeacHeatPha = TWCMgt_bDeacHeatPha;
   if (  (TWCMgt_bDeacHeatPha  != 0)
      && (TWCMGT_bDeacHeatPhaPrev == 0))
   {
      TWCMgt_tiTWC = 0;
   }
   else
   {
      if (TWCMgt_bTWCHeatReqPrev != 0)
      {
         u32LocalTWCMgt_tiTWC = (uint32)(TWCMgt_tiTWC + TWCMgt_tiSdlFast_C);
      }
      else
      {
         u32LocalTWCMgt_tiTWC = TWCMgt_tiTWC;
      }
      TWCMgt_tiTWC = (uint16)MATHSRV_udtMIN(u32LocalTWCMgt_tiTWC, 50000);
   }

   if (  (TWCMgt_tiTWC > 0)
      && (bLocalTqSys_bEngNOnIdl != 0))
   {
      bLocalHeatPhaInTurnOndelay = 1;
   }
   else
   {
      bLocalHeatPhaInTurnOndelay = 0;
   }

   if (bLocalHeatPhaInTurnOndelay != 0)
   {
      if (TWCMGT_bInHeatPhaTurnOnPrev == 0)
      {
         TWCMGT_u16HeatPhaCount = TWCMgt_tiDlyIdlHeatPhaThd_C;
      }
      else
      {
         if (TWCMGT_u16HeatPhaCount >= TWCMgt_tiSdlFast_C)
         {
            TWCMGT_u16HeatPhaCount =
               (uint16)(TWCMGT_u16HeatPhaCount - TWCMgt_tiSdlFast_C);
         }
         else
         {
            TWCMGT_u16HeatPhaCount = 0;
         }
      }
      if (TWCMGT_u16HeatPhaCount == 0)
      {
         TWCMGT_bOutHeatPhaTurnOnDelay = 1;
      }
      else
      {
         TWCMGT_bOutHeatPhaTurnOnDelay = 0;
      }
   }
   else
   {
      TWCMGT_bOutHeatPhaTurnOnDelay = 0;
   }
   TWCMGT_bInHeatPhaTurnOnPrev = bLocalHeatPhaInTurnOndelay;

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TWCMgt_nEngToDrvReq_A,
                                                   u16LocalExt_nEng,
                                                   12);
   u16LocalInterp1D =
      MATHSRV_u16Interp1d(TWCMgt_tqNEngDrvReq_T, u16LocalCalcPara);
   s32LocaltqNEngDrvReq = (sint32)(u16LocalInterp1D - 32000);
   u16LocalAccPCompare = (uint16)(TWCMgt_rAccePedDrvReq_C * 128);
   if (  (s16LocalTqDem_tqCkEfc > s32LocaltqNEngDrvReq)
      || (u16LocalAccP_rAccP > u16LocalAccPCompare))
   {
      bLocalDrvReq = 1;
   }
   else
   {
      bLocalDrvReq = 0;
   }

   /*producing OxC_bIntrHeat*/
   if (  (TWCMGT_bOutHeatPhaTurnOnDelay != 0)
      || (bLocalFRMInhTWCHeat != 0)
      || (bLocalDrvReq != 0))
   {
      bLocalOxC_bIntrHeat = 1;
   }
   else
   {
      bLocalOxC_bIntrHeat = 0;
   }
   VEMS_vidSET(OxC_bIntrHeat, bLocalOxC_bIntrHeat);

   if (  (u8LocalCoPt_noEgdGearCord != 0)
      && (u8LocalCoVSCtl_stAccP == 0))
   {
      bLocalInGearIdlTurnOn = 1;
   }
   else
   {
      bLocalInGearIdlTurnOn = 0;
   }
   if (bLocalInGearIdlTurnOn != 0)
   {
      if (TWCMGT_bInGearIdlTurnOnPrev == 0)
      {
         TWCMGT_u16GearIdlCount = TWCMgt_tiDlyGearIdl_C;
      }
      else
      {
         if (TWCMGT_u16GearIdlCount >= TWCMgt_tiSdlFast_C)
         {
            TWCMGT_u16GearIdlCount =
               (uint16)(TWCMGT_u16GearIdlCount - TWCMgt_tiSdlFast_C);
         }
         else
         {
            TWCMGT_u16GearIdlCount = 0;
         }
      }
      if (TWCMGT_u16GearIdlCount == 0)
      {
         TWCMGT_bOutGearIdlTurnOnDelay = 1;
      }
      else
      {
         TWCMGT_bOutGearIdlTurnOnDelay = 0;
      }
   }
   else
   {
      TWCMGT_bOutGearIdlTurnOnDelay = 0;
   }
   TWCMGT_bInGearIdlTurnOnPrev = bLocalInGearIdlTurnOn;

   if (  (u8LocalCoPt_noEgdGearCord == 7)
      && (TWCMgt_bInhReGearHeatDeac_C == 0))
   {
      bLocalGearHeaCord = 1;
   }
   else
   {
      bLocalGearHeaCord = 0;
   }

   if (s16LocalExM_tOxCEstim > TWCMgt_tTWCHeatDeacThd_C)
   {
      bLocalInTurnOndelayTWCHeat = 1;
   }
   else
   {
      bLocalInTurnOndelayTWCHeat = 0;
   }
   if (bLocalInTurnOndelayTWCHeat != 0)
   {
      if (TWCMGT_bInTWCHeatTurnOnPrev == 0)
      {
         TWCMGT_u16TWCHeatCount = TWCMgt_tiDlyTWCHeatDeac_C;
      }
      else
      {
         if (TWCMGT_u16TWCHeatCount >= TWCMgt_tiSdlFast_C)
         {
            TWCMGT_u16TWCHeatCount =
               (uint16)(TWCMGT_u16TWCHeatCount - TWCMgt_tiSdlFast_C);
         }
         else
         {
            TWCMGT_u16TWCHeatCount = 0;
         }
      }
      if (TWCMGT_u16TWCHeatCount == 0)
      {
         TWCMGT_bOutTWCHeatTurnOnDelay = 1;
      }
      else
      {
         TWCMGT_bOutTWCHeatTurnOnDelay = 0;
      }
   }
   else
   {
      TWCMGT_bOutTWCHeatTurnOnDelay = 0;
   }
   TWCMGT_bInTWCHeatTurnOnPrev = bLocalInTurnOndelayTWCHeat;

   if (TWCMgt_bTCoAr != 0)
   {
      u16LocalCalcParaHeatDeac =
         MATHSRV_u16CalcParaIncAryU16(TWCMgt_tiHeatHiAr_A,
                                      TWCMgt_tiHiTWCHiArPrev,
                                      12);
      u16LocalTWCMgttiTWC =
         MATHSRV_u16Interp1d(TWCMgt_tiTWCHeatDeac_T, u16LocalCalcParaHeatDeac);
   }
   else
   {
      u16LocalTWCMgttiTWC = TWCMgt_tiMaxHeatThdLoAr_C;
   }
   if (TWCMgt_tiTWC > u16LocalTWCMgttiTWC)
   {
      bLocaltiTWC = 1;
   }
   else
   {
      bLocaltiTWC = 0;
   }

   if (  (TWCMGT_bOutHeatPhaTurnOnDelay != 0)
      || (bLocalDrvReq != 0)
      || (TWCMGT_bOutGearIdlTurnOnDelay != 0)
      || (bLocalGearHeaCord != 0)
      || (TWCMGT_bOutTWCHeatTurnOnDelay != 0)
      || (bLocaltiTWC))
   {
      TWCMgt_bDeacHeatPha = 1;
   }
   else
   {
      TWCMgt_bDeacHeatPha = 0;
   }
   TWCMGT_bDeacHeatPhaPrev = bLocalTWCMgt_bDeacHeatPha;
}
/*------------------------------- end of file --------------------------------*/