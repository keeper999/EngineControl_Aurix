/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQDRIVMON                                               */
/* !Description     : TQDRIVMON Component.                                    */
/*                                                                            */
/* !Module          : TQDRIVMON                                               */
/* !Description     : Valider couple conducteur.                              */
/*                                                                            */
/* !File            : TQDRIVMON_FCT1.C                                        */
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
/*   1 / TQDRIVMON_vidInitOutput                                              */
/*   2 / TQDRIVMON_vidEnveloppeCoupleMaxi                                     */
/*   3 / TQDRIVMON_vidGenererrDrivTakeOff                                     */
/*   4 / TQDRIVMON_vidCalcCoupleSorIVC1                                       */
/*   5 / TQDRIVMON_vidValCoupleNivAppli                                       */
/*   6 / TQDRIVMON_vidValAntiCourseMorte                                      */
/*   7 / TQDRIVMON_vidValAideDecollage                                        */
/*                                                                            */
/* !Reference   : V02 NT 10 01230 / 04                                        */
/* !OtherRefs   : CSCT_CGMT09_1790 / 2.3                                      */
/* !OtherRefs   : VEMS V02 ECU#047137                                         */
/* !OtherRefs   : VEMS V02 ECU#057585                                         */
/* !OtherRefs   : VEMS V02 ECU#060258                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQDRIVMON/TQDRIVMON_FC$*/
/* $Revision::   1.15     $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQDRIVMON.h"
#include "TQDRIVMON_L.h"
#include "TQDRIVMON_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQDRIVMON_vidInitOutput                                    */
/* !Description :  Initialisation des parametres                              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDgoTqDem;                                         */
/*  output sint16 SftyMgt_tqCkEfc;                                            */
/*  output boolean SftyMgt_bDgoDZone;                                         */
/*  output boolean SftyMgt_bDgoTakeOff;                                       */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter;                            */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter2;                           */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter1;                           */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter3;                           */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter4;                           */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter5;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQDRIVMON_vidInitOutput(void)
{
   /* output initialization */
   VEMS_vidSET(SftyMgt_bDgoTqDem, 0);
   VEMS_vidSET(SftyMgt_tqCkEfc, 0);
   VEMS_vidSET(SftyMgt_bDgoDZone, 0);
   VEMS_vidSET(SftyMgt_bDgoTakeOff, 0);
   /* internal data initialization */
   TQDRIVMON_u16TurnOnDelayCounter = 0;
   TQDRIVMON_u16TurnOnDelayCounter2 = 0;
   TQDRIVMON_u16TurnOnDelayCounter1 = 0;
   TQDRIVMON_u16TurnOnDelayCounter3 = 0;
   TQDRIVMON_u16TurnOnDelayCounter4 = 0;
   TQDRIVMON_u16TurnOnDelayCounter5 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQDRIVMON_vidEnveloppeCoupleMaxi                           */
/* !Description :  Le couple maxi sortant de cette fonction est l’enveloppe de*/
/*                 couple maximum absolue  admissible d’après la synthèse des */
/*                 cartographies pédales de la partie applicative.            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01230_002.02                                     */
/*                 VEMS_R_10_01230_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 SftyMgt_tqEfcNRegTakeOffNorm;                                */
/*  input sint16 SftyMgt_tqEfcNRegTakeOffEco;                                 */
/*  input uint16 SftyMgt_rAccPSptModTqDem;                                    */
/*  input uint16 SftyMgt_nCkFil;                                              */
/*  input boolean SftyMgt_bAcvNRegTakeOffTqDem;                               */
/*  input uint16 SftyMgt_rDrivTakeOffTqDem;                                   */
/*  input uint16 SftyMgt_tqCkEfc_rAccPX_A[16];                                */
/*  input uint32 SftyMgt_tqCkEfc_nEngY_A[16];                                 */
/*  input uint16 TQDRIVMON_aSftyMgt_tqCkEfc_nEngY[16];                        */
/*  input uint16 SftyMgt_tqCkEfcMaxAbs_M[16][16];                             */
/*  input uint16 SftyMgt_tqCkEfcTakeOff_M[16][16];                            */
/*  output uint16 TQDRIVMON_aSftyMgt_tqCkEfc_nEngY[16];                       */
/*  output sint16 SftyMgt_tqCkMaxAbs;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQDRIVMON_vidEnveloppeCoupleMaxi(void)
{
   boolean bLocalSftyMgt_bAcvNRegTkOffTqDem;
   uint8   u8LocalIndex;
   uint16  u16LocalSftyMgt_rAccPSptModTqDem;
   uint16  u16LocalSftyMgt_nCkFil;
   uint16  u16LocalInterpOutput;
   uint16  u16LocalCalcParaX;
   uint16  u16LocalCalcParaY;
   uint16  u16LocalSftyMgtrDrivTakeOffTqDem;
   sint16  s16LocalSftyMgt_tqEfcNRegTkOfEco;
   sint16  s16LocalSftyMgt_tqEfcNRegTkOfNrm;
   sint16  s16LocaltqCkTakeOffReg;
   uint32  u32LocaltqCkEfc_nEngY;
   sint32  s32LocalInterpOutput;
   sint32  s32LocalCkMaxAbs;


   VEMS_vidGET(SftyMgt_tqEfcNRegTakeOffNorm, s16LocalSftyMgt_tqEfcNRegTkOfNrm);
   VEMS_vidGET(SftyMgt_tqEfcNRegTakeOffEco, s16LocalSftyMgt_tqEfcNRegTkOfEco);
   VEMS_vidGET(SftyMgt_rAccPSptModTqDem, u16LocalSftyMgt_rAccPSptModTqDem);
   VEMS_vidGET(SftyMgt_nCkFil, u16LocalSftyMgt_nCkFil);
   VEMS_vidGET(SftyMgt_bAcvNRegTakeOffTqDem, bLocalSftyMgt_bAcvNRegTkOffTqDem);
   VEMS_vidGET(SftyMgt_rDrivTakeOffTqDem, u16LocalSftyMgtrDrivTakeOffTqDem);


   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(SftyMgt_tqCkEfc_rAccPX_A,
                                   u16LocalSftyMgt_rAccPSptModTqDem,
                                   16);

   for (u8LocalIndex = 0; u8LocalIndex < 16; u8LocalIndex++)
   {
      u32LocaltqCkEfc_nEngY = SftyMgt_tqCkEfc_nEngY_A[u8LocalIndex] / 25;
      TQDRIVMON_aSftyMgt_tqCkEfc_nEngY[u8LocalIndex] =
         (uint16)MATHSRV_udtMIN(u32LocaltqCkEfc_nEngY, 65535);
   }
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(TQDRIVMON_aSftyMgt_tqCkEfc_nEngY,
                                   u16LocalSftyMgt_nCkFil,
                                   16);

   if (u16LocalSftyMgtrDrivTakeOffTqDem == 1000)
   {
      u16LocalInterpOutput = MATHSRV_u16Interp2d(&SftyMgt_tqCkEfcMaxAbs_M[0][0],
                                                 u16LocalCalcParaX,
                                                 u16LocalCalcParaY,
                                                 16);
   }
   else
   {
      u16LocalInterpOutput =
         MATHSRV_u16Interp2d(&SftyMgt_tqCkEfcTakeOff_M[0][0],
                             u16LocalCalcParaX,
                             u16LocalCalcParaY,
                             16);
   }
   s32LocalInterpOutput = (sint32)(u16LocalInterpOutput - 32000);

   if (bLocalSftyMgt_bAcvNRegTkOffTqDem != 0)
   {
      s16LocaltqCkTakeOffReg =
         (sint16)MATHSRV_udtMAX(s16LocalSftyMgt_tqEfcNRegTkOfNrm,
                                s16LocalSftyMgt_tqEfcNRegTkOfEco);
      s32LocalCkMaxAbs = MATHSRV_udtMAX(s32LocalInterpOutput,
                                        s16LocaltqCkTakeOffReg);
      SftyMgt_tqCkMaxAbs = (sint16)MATHSRV_udtMIN(s32LocalCkMaxAbs, 32000);
   }
   else
   {
      SftyMgt_tqCkMaxAbs = (sint16)MATHSRV_udtMIN(s32LocalInterpOutput, 32000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQDRIVMON_vidGenererrDrivTakeOff                           */
/* !Description :  Génération du signal SftyMgt_rDrivTakeOff et bDrivTakeOff  */
/*                 (équivalent à TqDem_rDrivTakeOff et bDrivTakeOff au niveau */
/*                 applicatif)                                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01230_002.02                                     */
/*                 VEMS_R_10_01230_006.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint16 SftyMgt_rDrivTakeOffTqDem;                                   */
/*  input uint8 SftyMgt_noEgdGearCordCoPt;                                    */
/*  input boolean SftyMgt_bAcvNRegTakeOffTqDem;                               */
/*  input boolean SftyMgt_bTakeOffSpdCoPt_C;                                  */
/*  input boolean SftyMgt_bInhRvTqDemTakeOffFRM;                              */
/*  input uint16 SftyMgt_spdVehDft_C;                                         */
/*  input uint16 SftyMgt_spdVehMaxTakeOff_C;                                  */
/*  input uint16 SftyMgt_spdVeh;                                              */
/*  input boolean SftyMgt_bTakeOffCoPt;                                       */
/*  input uint16 SftyMgt_tiDlyTakeOff_C;                                      */
/*  input uint16 TQDRIVMON_u16TurnOnDelayCounter1;                            */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter1;                           */
/*  output boolean SftyMgt_bDgo_rDrivTakeOff;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQDRIVMON_vidGenererrDrivTakeOff(void)
{
   boolean bLocalInhRvTqDemTakeOffFRM;
   boolean bLocalSftyMgt_bTakeOffCoPt;
   boolean bLocalSftyMgt_bAcvNRegTkOffTqDem;
   boolean bLocalTurnOnDelay;
   boolean bLocalTurnOnDelay1;
   boolean bLocalTurnOnDelay2;
   boolean bLocalTurnOnOutDelay;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalSftyMgt_noEgdGearCordCoPt;
   uint16  u16LocalSftyMgtrDrivTakeOffTqDem;
   uint16  u16LocalSftyMgt_spdVeh;
   uint16  u16LocalCount;
   uint16  u16LocalMinTurnOnDelaySimple;


   bLocalTurnOnDelay = 0;
   bLocalTurnOnDelay1 = 0;
   bLocalTurnOnDelay2 = 0;
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(SftyMgt_rDrivTakeOffTqDem, u16LocalSftyMgtrDrivTakeOffTqDem);
   VEMS_vidGET(SftyMgt_noEgdGearCordCoPt, u8LocalSftyMgt_noEgdGearCordCoPt);
   VEMS_vidGET(SftyMgt_bAcvNRegTakeOffTqDem, bLocalSftyMgt_bAcvNRegTkOffTqDem);
   if (  (u8LocalExt_stGBxCf == 0)
      || (SftyMgt_bTakeOffSpdCoPt_C != 0))
   {
      VEMS_vidGET(SftyMgt_bInhRvTqDemTakeOffFRM, bLocalInhRvTqDemTakeOffFRM);
      if (bLocalInhRvTqDemTakeOffFRM != 0)
      {
         if (SftyMgt_spdVehDft_C > SftyMgt_spdVehMaxTakeOff_C)
         {
            bLocalTurnOnDelay1 = 1;
         }
      }
      else
      {
         VEMS_vidGET(SftyMgt_spdVeh, u16LocalSftyMgt_spdVeh);
         if (u16LocalSftyMgt_spdVeh > SftyMgt_spdVehMaxTakeOff_C)
         {
            bLocalTurnOnDelay1 = 1;
         }
      }
      if (  (u8LocalSftyMgt_noEgdGearCordCoPt > 0)
         || (bLocalSftyMgt_bAcvNRegTkOffTqDem == 0))
      {
         bLocalTurnOnDelay2 = 1;
      }
      if (  (bLocalTurnOnDelay1 != 0)
         && (bLocalTurnOnDelay2 != 0))
      {
         bLocalTurnOnDelay = 1;
      }
      else
      {
         bLocalTurnOnDelay = 0;
      }
   }
   else
   {
      VEMS_vidGET(SftyMgt_bTakeOffCoPt, bLocalSftyMgt_bTakeOffCoPt);
      if (  (bLocalSftyMgt_bTakeOffCoPt == 0)
         && (  (u8LocalSftyMgt_noEgdGearCordCoPt > 0)
            || (bLocalSftyMgt_bAcvNRegTkOffTqDem == 0)))
      {
         bLocalTurnOnDelay = 1;
      }
   }
   /* Turn_On_Delay_Simple1 */
   u16LocalCount = (uint16)((uint32)(SftyMgt_tiDlyTakeOff_C + 6) / 4);
   u16LocalMinTurnOnDelaySimple =
      (uint16)MATHSRV_udtMIN(TQDRIVMON_u16TurnOnDelayCounter1,
                             u16LocalCount);

   if (bLocalTurnOnDelay == 0)
   {
      TQDRIVMON_u16TurnOnDelayCounter1 = 0;
   }
   else
   {
      TQDRIVMON_u16TurnOnDelayCounter1 =
         (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }

   if (TQDRIVMON_u16TurnOnDelayCounter1 >= u16LocalCount)
   {
      bLocalTurnOnOutDelay = 1;
   }
   else
   {
      bLocalTurnOnOutDelay = 0;
   }

   if (  (bLocalTurnOnOutDelay != 0)
      && (u16LocalSftyMgtrDrivTakeOffTqDem < 1000))
   {
      SftyMgt_bDgo_rDrivTakeOff = 1;
   }
   else
   {
      SftyMgt_bDgo_rDrivTakeOff = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQDRIVMON_vidCalcCoupleSorIVC1                             */
/* !Description :  Ce bloc a la même fonctionnalité que l’IVC1 dans la partie */
/*                 applicative. Elle permet de prendre en compte les          */
/*                 adaptations en pied levé ainsi que le couple d’anti-course */
/*                 morte.                                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01230_016.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 SftyMgt_tqSumLossCmp;                                        */
/*  input uint16 SftyMgt_rAccP;                                               */
/*  input uint16 SftyMgt_nCkFil;                                              */
/*  input uint16 SftyMgt_nTarIdlUnChkBuf;                                     */
/*  input uint16 SftyMgt_facNEngIdl_A[9];                                     */
/*  input uint16 TQDRIVMON_u16facNEngIdl;                                     */
/*  input uint8 SftyMgt_facNEngIdl_T[9];                                      */
/*  input uint16 SftyMgt_rAccPOfs_C;                                          */
/*  input uint8 SftyMgt_facNIdl_MP;                                           */
/*  input sint16 SftyMgt_tqCkMaxAbs;                                          */
/*  input sint16 SftyMgt_tqCkLossOfs_C;                                       */
/*  input uint8 SftyMgt_facAdpAccPOff_MP;                                     */
/*  input boolean SftyMgt_bModSptTqDem;                                       */
/*  output uint16 TQDRIVMON_u16facNEngIdl;                                    */
/*  output uint8 SftyMgt_facNIdl_MP;                                          */
/*  output uint8 SftyMgt_facAdpAccPOff_MP;                                    */
/*  output sint16 SftyMgt_tqCkEfcWoutAntiDBTol;                               */
/*  output boolean SftyMgt_bModSptDft;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQDRIVMON_vidCalcCoupleSorIVC1(void)
{
   boolean bLocalSftyMgt_bModSptTqDem;
   uint8   u8LocalInterpOutput;
   uint16  u16LocalSftyMgt_nTarIdlUnChkBuf;
   uint16  u16LocalSftyMgt_rAccP;
   uint16  u16LocalSftyMgt_nCkFil;
   uint16  u16LocalCalcPara;
   sint16  s16LocalSftyMgt_tqSumLossCmp;
   sint16  s16LocalSftyMgt_facNIdlMP;
   sint32  s32LocalCalc1;
   sint32  s32LocalInterp;


   VEMS_vidGET(SftyMgt_tqSumLossCmp, s16LocalSftyMgt_tqSumLossCmp);
   VEMS_vidGET(SftyMgt_rAccP, u16LocalSftyMgt_rAccP);
   VEMS_vidGET(SftyMgt_nCkFil, u16LocalSftyMgt_nCkFil);
   VEMS_vidGET(SftyMgt_nTarIdlUnChkBuf, u16LocalSftyMgt_nTarIdlUnChkBuf);

   s32LocalInterp = (sint32)( ( u16LocalSftyMgt_nCkFil
                              - u16LocalSftyMgt_nTarIdlUnChkBuf)
                            + 4000);
   TQDRIVMON_u16facNEngIdl = (uint16)MATHSRV_udtCLAMP(s32LocalInterp, 0, 65535);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_facNEngIdl_A,
                                                   TQDRIVMON_u16facNEngIdl,
                                                   9);

   u8LocalInterpOutput = MATHSRV_u8Interp1d(SftyMgt_facNEngIdl_T,
                                            u16LocalCalcPara);
   s16LocalSftyMgt_facNIdlMP = (sint16)(u8LocalInterpOutput - 100);
   SftyMgt_facNIdl_MP = (uint8)MATHSRV_udtCLAMP(s16LocalSftyMgt_facNIdlMP,
                                                0,
                                                100);
   if (u16LocalSftyMgt_rAccP <= SftyMgt_rAccPOfs_C)
   {
      SftyMgt_facAdpAccPOff_MP = SftyMgt_facNIdl_MP;
      s32LocalCalc1 = ( ( SftyMgt_tqCkMaxAbs
                        + s16LocalSftyMgt_tqSumLossCmp)
                      - SftyMgt_tqCkLossOfs_C);
      s32LocalCalc1 = (s32LocalCalc1 * SftyMgt_facAdpAccPOff_MP);
      s32LocalCalc1 = ((SftyMgt_tqCkMaxAbs * 100) - s32LocalCalc1) / 100;
      SftyMgt_tqCkEfcWoutAntiDBTol = (sint16)MATHSRV_udtCLAMP(s32LocalCalc1,
                                                              -32000,
                                                              32000);
      VEMS_vidGET(SftyMgt_bModSptTqDem, bLocalSftyMgt_bModSptTqDem);
      if (bLocalSftyMgt_bModSptTqDem != 0)
      {
         SftyMgt_bModSptDft = 1;
      }
      else
      {
         SftyMgt_bModSptDft = 0;
      }
   }
   else
   {
      SftyMgt_bModSptDft = 0;
      SftyMgt_facAdpAccPOff_MP = 0;
      SftyMgt_tqCkEfcWoutAntiDBTol =
         (sint16)MATHSRV_udtCLAMP(SftyMgt_tqCkMaxAbs, -32000, 32000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQDRIVMON_vidValCoupleNivAppli                             */
/* !Description :  Cette sous-fonction compare les couples de l’IVC de l’ACS à*/
/*                 leurs enveloppes équivalentes calculées dans F01. Un défaut*/
/*                 est levé si un au moins des couples de la partie           */
/*                 applicative dépasse le critère d’accélération intempestive.*/
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01230_017.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bInhRvTqDemTakeOffFRM;                              */
/*  input sint16 SftyMgt_tqEfcDifLrnOutDZone;                                 */
/*  input uint16 SftyMgt_tiDlyTakeOffDftFRM_C;                                */
/*  input uint8 SftyMgt_tiDlyTakeOffDft_C;                                    */
/*  input uint16 TQDRIVMON_u16TurnOnDelayCounter2;                            */
/*  input boolean SftyMgt_bDgo_rDrivTakeOff;                                  */
/*  input sint16 SftyMgt_tqCkEfcWoutAntiDBTqDem;                              */
/*  input sint16 SftyMgt_tqCkEfcWoutAntiDBTol;                                */
/*  input sint16 SftyMgt_tqErrThdSftyTqDem_C;                                 */
/*  input uint8 SftyMgt_tiDlyTqDemDft_C;                                      */
/*  input uint16 TQDRIVMON_u16TurnOnDelayCounter;                             */
/*  input uint16 SftyMgt_tiDlyModSptDft_C;                                    */
/*  input uint16 TQDRIVMON_u16TurnOnDelayCounter3;                            */
/*  input boolean SftyMgt_bModSptDft;                                         */
/*  input boolean SftyMgt_bDgo_rDrivTakeOff_MP;                               */
/*  input boolean SftyMgt_bDgoTqDemMax_MP;                                    */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter2;                           */
/*  output boolean SftyMgt_bDgo_rDrivTakeOff_MP;                              */
/*  output boolean SftyMgt_bDgoTqDemMaxRaw_MP;                                */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter;                            */
/*  output boolean SftyMgt_bDgoTqDemMax_MP;                                   */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter3;                           */
/*  output boolean SftyMgt_bDgoTqDem;                                         */
/*  output sint16 SftyMgt_tqCkEfc;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQDRIVMON_vidValCoupleNivAppli(void)
{
   boolean bLocalInhRvTqDemTakeOffFRM;
   boolean bLocalTurnOnDelayOut;
   sint16  s16LocalSftyMgt_tqCkEfcWtDBTqDem;
   sint16  s16LocalSftyMgt_tqEfcDLrnOtDZone;
   sint16  s16LocalSum;
   uint16  u16LocalDlyTakeOff;
   uint16  u16LocalDlyTakeOff1;
   uint16  u16LocalSumTurnOnDelaySimple;
   uint16  u16LocalMinTurnOnDelaySimple;
   uint16  u16LocalMinTurnOnDelaySimple1;
   uint16  u16LocalMinTurnOnDelaySimple2;
   sint32  s32LocalSum;


   VEMS_vidGET(SftyMgt_bInhRvTqDemTakeOffFRM, bLocalInhRvTqDemTakeOffFRM);
   VEMS_vidGET(SftyMgt_tqEfcDifLrnOutDZone, s16LocalSftyMgt_tqEfcDLrnOtDZone);

   if (bLocalInhRvTqDemTakeOffFRM != 0)
   {
      u16LocalDlyTakeOff =
         (uint16)((uint32)(SftyMgt_tiDlyTakeOffDftFRM_C + 6) / 4);
   }
   else
   {
      u16LocalDlyTakeOff = (uint16)(SftyMgt_tiDlyTakeOffDft_C + 1);
   }
   /* Turn_On_Delay_Simple */
   u16LocalMinTurnOnDelaySimple =
      (uint16)MATHSRV_udtMIN(TQDRIVMON_u16TurnOnDelayCounter2,
                             u16LocalDlyTakeOff);

   if (SftyMgt_bDgo_rDrivTakeOff == 0)
   {
      TQDRIVMON_u16TurnOnDelayCounter2 = 0;
   }
   else
   {
      TQDRIVMON_u16TurnOnDelayCounter2 =
         (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }

   if (TQDRIVMON_u16TurnOnDelayCounter2 >= u16LocalDlyTakeOff)
   {
      SftyMgt_bDgo_rDrivTakeOff_MP = 1;
   }
   else
   {
      SftyMgt_bDgo_rDrivTakeOff_MP = 0;
   }
   /* Turn_On_Delay_Simple1 */
   VEMS_vidGET(SftyMgt_tqCkEfcWoutAntiDBTqDem,
               s16LocalSftyMgt_tqCkEfcWtDBTqDem);
   s32LocalSum = (sint32)( SftyMgt_tqCkEfcWoutAntiDBTol
                         + SftyMgt_tqErrThdSftyTqDem_C);
   u16LocalSumTurnOnDelaySimple = (uint16)(SftyMgt_tiDlyTqDemDft_C + 1);
   u16LocalMinTurnOnDelaySimple1 =
      (uint16)MATHSRV_udtMIN(TQDRIVMON_u16TurnOnDelayCounter,
                             u16LocalSumTurnOnDelaySimple);
   if (s16LocalSftyMgt_tqCkEfcWtDBTqDem > s32LocalSum)
   {
      SftyMgt_bDgoTqDemMaxRaw_MP = 1;
      TQDRIVMON_u16TurnOnDelayCounter =
         (uint16)(u16LocalMinTurnOnDelaySimple1 + 1);
   }
   else
   {
      SftyMgt_bDgoTqDemMaxRaw_MP = 0;
      TQDRIVMON_u16TurnOnDelayCounter = 0;
   }

   if (TQDRIVMON_u16TurnOnDelayCounter >= u16LocalSumTurnOnDelaySimple)
   {
      SftyMgt_bDgoTqDemMax_MP = 1;
   }
   else
   {
      SftyMgt_bDgoTqDemMax_MP = 0;
   }
   /* Turn_On_Delay_Simple2 */
   u16LocalDlyTakeOff1 = (uint16)((uint32)(SftyMgt_tiDlyModSptDft_C + 6) / 4);
   u16LocalMinTurnOnDelaySimple2 =
      (uint16)MATHSRV_udtMIN(TQDRIVMON_u16TurnOnDelayCounter3,
                             u16LocalDlyTakeOff1);

   if (SftyMgt_bModSptDft == 0)
   {
      TQDRIVMON_u16TurnOnDelayCounter3 = 0;
   }
   else
   {
      TQDRIVMON_u16TurnOnDelayCounter3 =
         (uint16)(u16LocalMinTurnOnDelaySimple2 + 1);
   }

   if (TQDRIVMON_u16TurnOnDelayCounter3 >= u16LocalDlyTakeOff1)
   {
      bLocalTurnOnDelayOut = 1;
   }
   else
   {
      bLocalTurnOnDelayOut = 0;
   }

   if (  (SftyMgt_bDgo_rDrivTakeOff_MP != 0)
      || (SftyMgt_bDgoTqDemMax_MP != 0)
      || (bLocalTurnOnDelayOut != 0))
   {
      VEMS_vidSET(SftyMgt_bDgoTqDem, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoTqDem, 0);
   }
   s32LocalSum = s16LocalSftyMgt_tqCkEfcWtDBTqDem
               + s16LocalSftyMgt_tqEfcDLrnOtDZone;
   s16LocalSum = (sint16)MATHSRV_udtCLAMP(s32LocalSum, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkEfc, s16LocalSum);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQDRIVMON_vidValAntiCourseMorte                            */
/* !Description :  Cette fonction sécurise le calcul de l’offset d’anti course*/
/*                 morte. On vérifie la nullité de l’offset lors d’un levé de */
/*                 pied.  Dans les autres cas de vie, une éventuelle erreur de*/
/*                 calcul de l’offset est contrôlable au pied.                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01230_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_rAccP;                                               */
/*  input boolean SftyMgt_bDeac0TqVSCtl;                                      */
/*  input boolean SftyMgt_bInhAntiDBFRM;                                      */
/*  input sint16 SftyMgt_tqEfcDifLrnOutDZone;                                 */
/*  input uint16 SftyMgt_rAccPThdDZone_C;                                     */
/*  input boolean SftyMgt_bAccPDZone_MP;                                      */
/*  input boolean SftyMgt_bDeacDZone_C;                                       */
/*  input sint16 SftyMgt_tqDeacDZone_C;                                       */
/*  input uint16 SftyMgt_tiDZoneErr_C;                                        */
/*  input uint16 TQDRIVMON_u16TurnOnDelayCounter4;                            */
/*  output boolean SftyMgt_bAccPDZone_MP;                                     */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter4;                           */
/*  output boolean SftyMgt_bDgoDZone;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQDRIVMON_vidValAntiCourseMorte(void)
{
   boolean bLocalSftyMgt_bDeac0TqVSCtl;
   boolean bLocalSftyMgt_bInhAntiDBFRM;
   boolean bLocalAnd;
   boolean bLocalOr;
   boolean bLocalTurnOnDelay;
   uint16  u16LocalSftyMgt_rAccP;
   uint16  u16LocalDlyTakeOff;
   uint16  u16LocalMinTurnOnDelaySimple;
   sint16  s16LocalSftyMgt_tqEfcDifLrnOutDZ;


   VEMS_vidGET(SftyMgt_rAccP, u16LocalSftyMgt_rAccP);
   VEMS_vidGET(SftyMgt_bDeac0TqVSCtl, bLocalSftyMgt_bDeac0TqVSCtl);
   VEMS_vidGET(SftyMgt_bInhAntiDBFRM, bLocalSftyMgt_bInhAntiDBFRM);
   VEMS_vidGET(SftyMgt_tqEfcDifLrnOutDZone, s16LocalSftyMgt_tqEfcDifLrnOutDZ);
   if (u16LocalSftyMgt_rAccP <= SftyMgt_rAccPThdDZone_C)
   {
      SftyMgt_bAccPDZone_MP = 1;
   }
   else
   {
      SftyMgt_bAccPDZone_MP = 0;
   }
   if (  (SftyMgt_bAccPDZone_MP != 0)
      && (bLocalSftyMgt_bDeac0TqVSCtl == 0))
   {
      bLocalAnd = 1;
   }
   else
   {
      bLocalAnd = 0;
   }
   if (  (bLocalAnd != 0)
      || (bLocalSftyMgt_bInhAntiDBFRM != 0)
      || (SftyMgt_bDeacDZone_C != 0))
   {
      bLocalOr = 1;
   }
   else
   {
      bLocalOr = 0;
   }
   if (  (bLocalOr != 0)
      && (s16LocalSftyMgt_tqEfcDifLrnOutDZ > SftyMgt_tqDeacDZone_C))
   {
      bLocalTurnOnDelay = 1;
   }
   else
   {
      bLocalTurnOnDelay = 0;
   }
   /* Turn_On_Delay_Simple */
   u16LocalDlyTakeOff = (uint16)((uint32)(SftyMgt_tiDZoneErr_C + 6) / 4);
   u16LocalMinTurnOnDelaySimple =
      (uint16)MATHSRV_udtMIN(TQDRIVMON_u16TurnOnDelayCounter4,
                             u16LocalDlyTakeOff);
   if (bLocalTurnOnDelay == 0)
   {
      TQDRIVMON_u16TurnOnDelayCounter4 = 0;
   }
   else
   {
      TQDRIVMON_u16TurnOnDelayCounter4 =
         (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }

   if (TQDRIVMON_u16TurnOnDelayCounter4 >= u16LocalDlyTakeOff)
   {
      VEMS_vidSET(SftyMgt_bDgoDZone, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoDZone, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQDRIVMON_vidValAideDecollage                              */
/* !Description :  Cette fonction valide qu’en pied levé, le couple de        */
/*                 décollage calculé est inférieur ou égal à moins les pertes */
/*                 globales du moteur majoré d’un offset                      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01230_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_rAccP;                                               */
/*  input boolean SftyMgt_bInhNRegTakeOffFRM;                                 */
/*  input sint16 SftyMgt_tqSumLossCmp;                                        */
/*  input sint16 SftyMgt_tqEfcNRegTakeOffNorm;                                */
/*  input uint16 SftyMgt_rAccPThdAcvTakeOff_C;                                */
/*  input boolean SftyMgt_bDeacTakeOffNReg_C;                                 */
/*  input sint16 SftyMgt_tqTakeOffThd_C;                                      */
/*  input boolean SftyMgt_bTakeOffInh_MP;                                     */
/*  input boolean SftyMgt_bTqAccPOff_MP;                                      */
/*  input uint16 SftyMgt_tiDlyTakeOffErr_C;                                   */
/*  input uint16 TQDRIVMON_u16TurnOnDelayCounter5;                            */
/*  input boolean SftyMgt_bDgoTakeOffRaw_MP;                                  */
/*  output boolean SftyMgt_bTakeOffInh_MP;                                    */
/*  output boolean SftyMgt_bTqAccPOff_MP;                                     */
/*  output boolean SftyMgt_bDgoTakeOffRaw_MP;                                 */
/*  output uint16 TQDRIVMON_u16TurnOnDelayCounter5;                           */
/*  output boolean SftyMgt_bDgoTakeOff;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQDRIVMON_vidValAideDecollage(void)
{
   boolean bLocalSftyMgt_bInhNRegTakeOffFRM;
   uint16  u16LocalSftyMgt_rAccP;
   uint16  u16LocalDlyTakeOff;
   uint16  u16LocalMinTurnOnDelaySimple;
   sint16  s16LocalSftyMgt_tqSumLossCmp;
   sint16  s16LocalSftyMgt_tqEfcNRegTkOffNm;
   sint32  s32LocalDiff;


   VEMS_vidGET(SftyMgt_rAccP, u16LocalSftyMgt_rAccP);
   VEMS_vidGET(SftyMgt_bInhNRegTakeOffFRM, bLocalSftyMgt_bInhNRegTakeOffFRM);
   VEMS_vidGET(SftyMgt_tqSumLossCmp, s16LocalSftyMgt_tqSumLossCmp);
   VEMS_vidGET(SftyMgt_tqEfcNRegTakeOffNorm, s16LocalSftyMgt_tqEfcNRegTkOffNm);
   if (  (u16LocalSftyMgt_rAccP < SftyMgt_rAccPThdAcvTakeOff_C)
      || (bLocalSftyMgt_bInhNRegTakeOffFRM != 0)
      || (SftyMgt_bDeacTakeOffNReg_C != 0))
   {
      SftyMgt_bTakeOffInh_MP = 1;
   }
   else
   {
      SftyMgt_bTakeOffInh_MP = 0;
   }
   s32LocalDiff = SftyMgt_tqTakeOffThd_C - s16LocalSftyMgt_tqSumLossCmp;
   if (s16LocalSftyMgt_tqEfcNRegTkOffNm > s32LocalDiff)
   {
      SftyMgt_bTqAccPOff_MP = 1;
   }
   else
   {
      SftyMgt_bTqAccPOff_MP = 0;
   }
   if (  (SftyMgt_bTakeOffInh_MP != 0)
      && (SftyMgt_bTqAccPOff_MP != 0))
   {
      SftyMgt_bDgoTakeOffRaw_MP = 1;
   }
   else
   {
      SftyMgt_bDgoTakeOffRaw_MP = 0;
   }
   /* Turn_On_Delay_Simple */
   u16LocalDlyTakeOff = (uint16)((uint32)(SftyMgt_tiDlyTakeOffErr_C + 6) / 4);
   u16LocalMinTurnOnDelaySimple =
      (uint16)MATHSRV_udtMIN(TQDRIVMON_u16TurnOnDelayCounter5,
                             u16LocalDlyTakeOff);
   if (SftyMgt_bDgoTakeOffRaw_MP == 0)
   {
      TQDRIVMON_u16TurnOnDelayCounter5 = 0;
   }
   else
   {
      TQDRIVMON_u16TurnOnDelayCounter5 =
         (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }

   if (TQDRIVMON_u16TurnOnDelayCounter5 >= u16LocalDlyTakeOff)
   {
      VEMS_vidSET(SftyMgt_bDgoTakeOff, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoTakeOff, 0);
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*----------------------------- end of file ----------------------------------*/