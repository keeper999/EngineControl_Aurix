/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINCLN                                             */
/* !Description     : VLVACTINCLN component.                                  */
/*                                                                            */
/* !Module          : VLVACTINCLN                                             */
/* !Description     : NETTOYAGE DE L’ELECTROVANNE DE LA VVT ADMISSION         */
/*                                                                            */
/* !File            : VLVACTINCLN_FCT1.C                                      */
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
/*   1 / VLVACTINCLN_vidInitOutput                                            */
/*   2 / VLVACTINCLN_vidClnIndTiCnt                                           */
/*   3 / VLVACTINCLN_vidClnIndTmCntRct                                        */
/*   4 / VLVACTINCLN_vidClnIndTmCntPct                                        */
/*   5 / VLVACTINCLN_vidClnInCnteFrstcln                                      */
/*   6 / VLVACTINCLN_vidErrCountRst                                           */
/*   7 / VLVACTINCLN_vidRctClnUdt                                             */
/*   8 / VLVACTINCLN_vidCmdcmp                                                */
/*   9 / VLVACTINCLN_vidCmdCalc                                               */
/*   10 / VLVACTINCLN_vidFrstCleaCond                                         */
/*                                                                            */
/* !Reference   : V02 NT 08 08234 / 13                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINCLN/VLVACTINCLN$*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   18 Mar 2013 $*/
/* $Author::   mbenfrad                               $$Date::   18 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINCLN.h"
#include "VLVACTINCLN_L.h"
#include "VLVACTINCLN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidInitOutput                                  */
/* !Description :  initialisation                                             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 VlvAct_InClnStCmd;                                          */
/*  output boolean VlvAct_bInMngClnStReq;                                     */
/*  output boolean VlvAct_bInFrstClnDone;                                     */
/*  output boolean VLVACTINCLN_bVlAcvInHealCln_Prev;                          */
/*  output boolean VLVACTINCLN_bFrtErrCntRst_Prev;                            */
/*  output boolean VLVACTINCLN_bTriggerPrev;                                  */
/*  output boolean VLVACTINCLN_bInitTimer1_Prev;                              */
/*  output boolean VLVACTINCLN_bInitTimer2_Prev;                              */
/*  output boolean VLVACTINCLN_bVlvActClnBeEnaPrev;                           */
/*  output boolean VLVACTINCLN_bLocalComparePrev;                             */
/*  output boolean VLVACTINCLN_bLocalCalcPrev;                                */
/*  output uint16 VLVACTINCLN_u16TimerCount1;                                 */
/*  output uint16 VLVACTINCLN_u16TimerCount;                                  */
/*  output uint32 VLVACTINCLN_u32TimerCount2;                                 */
/*  output boolean VLVACTINCLN_bTimeout;                                      */
/*  output boolean VLVACTINCLN_bTimeout1;                                     */
/*  output boolean VLVACTINCLN_bTimeout2;                                     */
/*  output uint8 VlvAct_ctInFrstClnCyc;                                       */
/*  output uint8 VlvAct_tiInFrstClnIdc;                                       */
/*  output uint8 VlvAct_CtInHealClnErr;                                       */
/*  output boolean VlvAct_bInHealClnEnd;                                      */
/*  output boolean VlvAct_bInManClnEnaIdc;                                    */
/*  output boolean VlvAct_bInNormClnEnd;                                      */
/*  output uint8 VlvAct_tiInHealClnIdc;                                       */
/*  output uint8 VlvAct_tiInNormClnIdc;                                       */
/*  output uint8 VlvAct_ctInHealClnDone;                                      */
/*  output uint8 VlvAct_ctInNormClnDone;                                      */
/*  output boolean VLVACTINCLN_bManCleanVarUpPrev;                            */
/*  output boolean VLVACTINCLN_bRctClnVarUdtPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidInitOutput(void)
{
   VEMS_vidSET(VlvAct_InClnStCmd, 0);
   VEMS_vidSET(VlvAct_bInMngClnStReq, 0);
   VEMS_vidSET(VlvAct_bInFrstClnDone, 0);
   VLVACTINCLN_bVlAcvInHealCln_Prev = 0;
   VLVACTINCLN_bFrtErrCntRst_Prev = 0;
   VLVACTINCLN_bTriggerPrev = 0;
   VLVACTINCLN_bInitTimer1_Prev = 0;
   VLVACTINCLN_bInitTimer2_Prev = 0;
   VLVACTINCLN_bVlvActClnBeEnaPrev = 0;
   VLVACTINCLN_bLocalComparePrev = 0;
   VLVACTINCLN_bLocalCalcPrev = 0;
   VLVACTINCLN_u16TimerCount1 = 0;
   VLVACTINCLN_u16TimerCount = 0;
   VLVACTINCLN_u32TimerCount2 = 0;
   VLVACTINCLN_bTimeout = 0;
   VLVACTINCLN_bTimeout1 = 0;
   VLVACTINCLN_bTimeout2 = 0;
   VlvAct_ctInFrstClnCyc = 0;
   VlvAct_tiInFrstClnIdc = 0;
   VlvAct_CtInHealClnErr = 0;
   VlvAct_bInHealClnEnd = 0;
   VlvAct_bInManClnEnaIdc = 0;
   VlvAct_bInNormClnEnd = 0;
   VlvAct_tiInHealClnIdc = 0;
   VlvAct_tiInNormClnIdc = 0;
   VlvAct_ctInHealClnDone = 0;
   VlvAct_ctInNormClnDone = 0;
   VLVACTINCLN_bManCleanVarUpPrev = 0;
   VLVACTINCLN_bRctClnVarUdtPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidClnIndTiCnt                                 */
/* !Description :  index du compteur pour le mode curatif et le mode          */
/*                 préventif.                                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCLN_vidClnIndTmCntRct();                         */
/*  extf argret void VLVACTINCLN_vidClnIndTmCntPct();                         */
/*  extf argret void VLVACTINCLN_vidClnInCnteFrstcln();                       */
/*  input boolean VlvAct_bInHealClnStMonGlblReq;                              */
/*  input boolean VlvAct_bInNormClnStReq;                                     */
/*  input boolean VlvAct_bInFrstClnStReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidClnIndTiCnt(void)
{
   if (VlvAct_bInHealClnStMonGlblReq != 0)
   {
      VLVACTINCLN_vidClnIndTmCntRct();
   }
   if (VlvAct_bInNormClnStReq != 0)
   {
      VLVACTINCLN_vidClnIndTmCntPct();
   }
   if (VlvAct_bInFrstClnStReq != 0)
   {
      VLVACTINCLN_vidClnInCnteFrstcln();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidClnIndTmCntRct                              */
/* !Description :  Ce bloc incrémente l’index de temps utilisé dans la        */
/*                 cartographie générant la commande de nettoyage en mode     */
/*                 curatif.                                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_tiInHealClnIdc;                                        */
/*  output uint8 VlvAct_tiInHealClnIdc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidClnIndTmCntRct(void)
{
   if (VlvAct_tiInHealClnIdc < 20)
   {
      VlvAct_tiInHealClnIdc = (uint8)(VlvAct_tiInHealClnIdc + 1);
   }
   else
   {
      VlvAct_tiInHealClnIdc = 20;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidClnIndTmCntPct                              */
/* !Description :  Ce bloc incrémente l’index de temps utilisé dans la        */
/*                 cartographie générant la commande de nettoyage en mode     */
/*                 préventif.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_tiInNormClnIdc;                                        */
/*  output uint8 VlvAct_tiInNormClnIdc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidClnIndTmCntPct(void)
{
   if (VlvAct_tiInNormClnIdc < 20)
   {
      VlvAct_tiInNormClnIdc = (uint8)(VlvAct_tiInNormClnIdc + 1);
   }
   else
   {
      VlvAct_tiInNormClnIdc = 20;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidClnInCnteFrstcln                            */
/* !Description :  Ce bloc incrémente l’index de temps utilisé dans la        */
/*                 cartographie générant la commande de nettoyage en mode     */
/*                 préventif.                                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_tiInFrstClnIdc;                                        */
/*  output uint8 VlvAct_tiInFrstClnIdc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidClnInCnteFrstcln(void)
{
   if (VlvAct_tiInFrstClnIdc < 20)
   {
      VlvAct_tiInFrstClnIdc = (uint8)(VlvAct_tiInFrstClnIdc + 1);
   }
   else
   {
      VlvAct_tiInFrstClnIdc = 20;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidErrCountRst                                 */
/* !Description :  remise à zero de la variable VlvAct_CtInHealClnErr         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 VlvAct_CtInHealClnErr;                                       */
/*  output uint8 VlvAct_ctInNormClnDone;                                      */
/*  output uint8 VlvAct_ctInHealClnDone;                                      */
/*  output boolean VlvAct_bInNormClnEnd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidErrCountRst(void)
{
   VlvAct_CtInHealClnErr = 0;
   VlvAct_ctInNormClnDone = 0;
   VlvAct_ctInHealClnDone = 0;
   VlvAct_bInNormClnEnd = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidRctClnUdt                                   */
/* !Description :  Mise à jour des variables liées aux nettoyages curatifs    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCLN_vidRctClnVarUdt();                           */
/*  input uint8 VlvAct_tiInHealClnIdc;                                        */
/*  input uint8 VlvAct_tiInClnEndThd_C;                                       */
/*  input boolean VLVACTINCLN_bRctClnVarUdtPrev;                              */
/*  output boolean VLVACTINCLN_bRctClnVarUdtPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidRctClnUdt(void)
{
   boolean bLocalRctClnVarUdt;


   if (VlvAct_tiInHealClnIdc >= VlvAct_tiInClnEndThd_C)
   {
      bLocalRctClnVarUdt = 1;
   }
   else
   {
      bLocalRctClnVarUdt = 0;
   }
   if (  (VLVACTINCLN_bRctClnVarUdtPrev == 0)
      && (bLocalRctClnVarUdt != 0))
   {
      VLVACTINCLN_vidRctClnVarUdt();
   }
   VLVACTINCLN_bRctClnVarUdtPrev = bLocalRctClnVarUdt;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidCmdcmp                                      */
/* !Description :  Le calcul du consigne RCO de commande se fait à travers le */
/*                 booléen d'activation du nettoyage de l'EV VVT admission(   */
/*                 VlvAct_bInClnEna).                                         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINCLN_vidCmdCalc();                                */
/*  input boolean VlvAct_bInClnEna;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidCmdcmp(void)
{
   boolean bLocalVlvAct_bInClnEna;


   VEMS_vidGET(VlvAct_bInClnEna, bLocalVlvAct_bInClnEna);
   if (bLocalVlvAct_bInClnEna != 0)
   {
      VLVACTINCLN_vidCmdCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidCmdCalc                                     */
/* !Description :  Le nettoyage (mode préventif, mode curatif, sortie usine)  */
/*                 se fait suivant un profil de commande défini par les       */
/*                 cartographies VlvAct_InNormClnCmd_M, VlvAct_InHealClnCmd_M */
/*                 et VlvAct_InFrstClnCmd_M.                                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_08_08234_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Vcpi_cam_position_error;                                     */
/*  input boolean VlvAct_bInNormClnStReq;                                     */
/*  input uint8 VlvAct_tiInNormClnIdc;                                        */
/*  input boolean VlvAct_bInFrstClnStReq;                                     */
/*  input uint8 VlvAct_tiInFrstClnIdc;                                        */
/*  input uint8 VlvAct_tiInHealClnIdc;                                        */
/*  input uint8 VlvAct_tiInFrstClnIdc_T[21];                                  */
/*  input uint8 VlvAct_tiInClnIdc;                                            */
/*  input uint8 VlvAct_InFrstClnCmd_M[21];                                    */
/*  input boolean VlvAct_bInHealClnStMonGlblReq;                              */
/*  input uint8 VlvAct_tiInHealClnIdc_T[21];                                  */
/*  input uint8 VlvAct_InHealClnCmd_M[21];                                    */
/*  input uint8 VlvAct_tiInNormClnIdc_T[21];                                  */
/*  input uint8 VlvAct_InNormClnCmd_M[21];                                    */
/*  input uint16 VlvAct_InClnCmdMin_C;                                        */
/*  input boolean VlvAct_bInSelTypCmdProfTyp_C;                               */
/*  input uint16 Vcpi_integral_value;                                         */
/*  input uint16 VlvAct_InClnCmdMax_C;                                        */
/*  output uint8 VlvAct_tiInClnIdc;                                           */
/*  output uint16 VlvAct_InClnStCmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidCmdCalc(void)
{
   uint8  u8LocalData;
   uint16 u16LocalPara;
   uint16 u16LocalVlvAct_InClnStCmd;
   uint16 u16LocalOutPutSwitch;
   uint16 u16LocalVcpi_integral_value;
   sint16 s16LocalVcpi_cam_position_error;
   sint32 s32LocalVlvAct;


   VEMS_vidGET(Vcpi_cam_position_error, s16LocalVcpi_cam_position_error);

   if (VlvAct_bInNormClnStReq != 0)
   {
      VlvAct_tiInClnIdc = (uint8)MATHSRV_udtMIN(VlvAct_tiInNormClnIdc, 20);
   }
   else
   {
      if (VlvAct_bInFrstClnStReq != 0)
      {
         VlvAct_tiInClnIdc = (uint8)MATHSRV_udtMIN(VlvAct_tiInFrstClnIdc, 20);
      }
      else
      {
         VlvAct_tiInClnIdc = (uint8)MATHSRV_udtMIN(VlvAct_tiInHealClnIdc, 20);
      }
   }

   if (VlvAct_bInFrstClnStReq != 0)
   {
      u16LocalPara = MATHSRV_u16CalcParaIncAryU8(VlvAct_tiInFrstClnIdc_T,
                                                 VlvAct_tiInClnIdc,
                                                 21);
      u16LocalPara = (uint16)(u16LocalPara & 0xFF00);
      u8LocalData = MATHSRV_u8Interp1d(VlvAct_InFrstClnCmd_M, u16LocalPara);
   }
   else
   {
      if (VlvAct_bInHealClnStMonGlblReq != 0)
      {
         u16LocalPara = MATHSRV_u16CalcParaIncAryU8(VlvAct_tiInHealClnIdc_T,
                                                    VlvAct_tiInClnIdc,
                                                    21);
         u16LocalPara = (uint16)(u16LocalPara & 0xFF00);
         u8LocalData = MATHSRV_u8Interp1d(VlvAct_InHealClnCmd_M, u16LocalPara);
      }
      else
      {
         u16LocalPara = MATHSRV_u16CalcParaIncAryU8(VlvAct_tiInNormClnIdc_T,
                                                    VlvAct_tiInClnIdc,
                                                    21);
         u16LocalPara = (uint16)(u16LocalPara & 0xFF00);
         u8LocalData = MATHSRV_u8Interp1d(VlvAct_InNormClnCmd_M, u16LocalPara);
      }
   }

   switch(u8LocalData)
   {
      case 0:
         u16LocalOutPutSwitch = VlvAct_InClnCmdMin_C;
         break;
      case 1:
         if (VlvAct_bInSelTypCmdProfTyp_C != 0)
         {
            VEMS_vidGET(Vcpi_integral_value, u16LocalVcpi_integral_value);
            u16LocalOutPutSwitch =
               (uint16)((u16LocalVcpi_integral_value + 32) / 64);
         }
         else
         {
            u16LocalOutPutSwitch = 512;
         }
         break;
      case 2:
         u16LocalOutPutSwitch = VlvAct_InClnCmdMax_C;
         break;
      default:
         u16LocalOutPutSwitch = VlvAct_InClnCmdMin_C;
         break;
   }
   if (  (s16LocalVcpi_cam_position_error >= 0)
      || (VlvAct_bInSelTypCmdProfTyp_C != 0))
   {
      u16LocalVlvAct_InClnStCmd =
         (uint16)MATHSRV_udtMIN(u16LocalOutPutSwitch, 1023);
   }
   else
   {
      s32LocalVlvAct = (sint32)(1024 - u16LocalOutPutSwitch);
      u16LocalVlvAct_InClnStCmd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvAct,
                                                           0,
                                                           1023);
   }
   VEMS_vidSET(VlvAct_InClnStCmd, u16LocalVlvAct_InClnStCmd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidFrstCleaCond                                */
/* !Description :  Le mode de nettoyage sortie usine « nettoyage moteur neuf »*/
/*                 doit permettre l’élimination des copeaux d’usinage présents*/
/*                 dans le circuit d’huile qui n’auraient pas pu être         */
/*                 supprimés lors du nettoyage réalisé après le montage du    */
/*                 moteur à l’usine moteur.                                   */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_08_08234_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTINCLN_vidFrstCleanVarUpdte();                      */
/*  input boolean Vta_intake_allow_learning;                                  */
/*  input boolean VlvAct_bInFrstClnAuth;                                      */
/*  input boolean VlvAct_bInOfsFrstLrnWouDft;                                 */
/*  input uint8 VlvAct_tiInFrstClnIdc;                                        */
/*  input uint8 VlvAct_tiInClnEndThd_C;                                       */
/*  input uint8 VlvAct_ctInFrstClnCyc;                                        */
/*  input uint8 VlvAct_ctInFrstClnCycThd_C;                                   */
/*  input boolean VLVACTINCLN_bLocalCalcPrev;                                 */
/*  input boolean VLVACTINCLN_bLocalComparePrev;                              */
/*  output boolean VlvAct_bInFrstClnDone;                                     */
/*  output boolean VlvAct_bInFrstClnStReq;                                    */
/*  output boolean VLVACTINCLN_bLocalComparePrev;                             */
/*  output boolean VLVACTINCLN_bLocalCalcPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidFrstCleaCond(void)
{
   boolean bLocalVtaintakeallowlearning;
   boolean bLocalVlvActbInFrstClnAuth;
   boolean bLocalVlvAct_bInOfsFrstLrnWouDft;
   boolean bLocalCalc;
   boolean bLocalCompare1;


   VEMS_vidGET(Vta_intake_allow_learning, bLocalVtaintakeallowlearning);
   VEMS_vidGET(VlvAct_bInFrstClnAuth, bLocalVlvActbInFrstClnAuth);
   VEMS_vidGET(VlvAct_bInOfsFrstLrnWouDft, bLocalVlvAct_bInOfsFrstLrnWouDft);
   if (VlvAct_tiInFrstClnIdc >= VlvAct_tiInClnEndThd_C)
   {
      bLocalCompare1 = 1;
   }
   else
   {
      bLocalCompare1 = 0;
   }

   if (  (bLocalVtaintakeallowlearning == 0)
      && (bLocalVlvActbInFrstClnAuth != 0)
      && (bLocalVlvAct_bInOfsFrstLrnWouDft == 0)
      && (VlvAct_ctInFrstClnCyc < VlvAct_ctInFrstClnCycThd_C))
   {
      bLocalCalc = 1;
   }
   else
   {
      bLocalCalc = 0;
   }
   if (  (VLVACTINCLN_bLocalCalcPrev !=0)
      && (bLocalCalc == 0))
   {
      VEMS_vidSET(VlvAct_bInFrstClnDone, 1);
   }
   if (  (bLocalCalc != 0)
      && (bLocalCompare1 == 0))
   {
      VlvAct_bInFrstClnStReq = 1;
   }
   else
   {
      VlvAct_bInFrstClnStReq = 0;
   }
   if (  (VLVACTINCLN_bLocalComparePrev == 0)
      && (bLocalCompare1 != 0))
   {
      VLVACTINCLN_vidFrstCleanVarUpdte();
   }
   VLVACTINCLN_bLocalComparePrev = bLocalCompare1;
   VLVACTINCLN_bLocalCalcPrev = bLocalCalc;
}
/*---------------------------- end of file -----------------------------------*/