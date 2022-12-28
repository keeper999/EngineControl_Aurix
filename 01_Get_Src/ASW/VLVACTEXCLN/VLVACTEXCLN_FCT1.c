/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXCLN                                             */
/* !Description     : VLVACTEXCLN component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXCLN                                             */
/* !Description     : NETTOYAGE DE L’ELECTROVANNE DE LA VVT ECHAPPEMENT       */
/*                                                                            */
/* !File            : VLVACTEXCLN_FCT1.C                                      */
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
/*   1 / VLVACTEXCLN_vidInitOutput                                            */
/*   2 / VLVACTEXCLN_vidClnIndTiCnt                                           */
/*   3 / VLVACTEXCLN_vidClnIndTmCntRct                                        */
/*   4 / VLVACTEXCLN_vidClnIndTmCntPct                                        */
/*   5 / VLVACTEXCLN_vidClnInCnteFrstcln                                      */
/*   6 / VLVACTEXCLN_vidErrCountRst                                           */
/*   7 / VLVACTEXCLN_vidRctClnUdt                                             */
/*   8 / VLVACTEXCLN_vidCmdcmp                                                */
/*   9 / VLVACTEXCLN_vidCmdCalc                                               */
/*   10 / VLVACTEXCLN_vidFrstCleaCond                                         */
/*                                                                            */
/* !Reference   : V02 NT 08 08235 / 12                                        */
/* !OtherRefs   : VEMS V02 ECU#055441                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXCLN/VLVACTEXCLN$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   12 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXCLN.h"
#include "VLVACTEXCLN_L.h"
#include "VLVACTEXCLN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidInitOutput                                  */
/* !Description :  initialisation                                             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 VlvAct_ExClnStCmd;                                          */
/*  output boolean VlvAct_bExMngClnStReq;                                     */
/*  output boolean VlvAct_bExFrstClnDone;                                     */
/*  output boolean VLVACTEXCLN_bVlAcvExHealCln_Prev;                          */
/*  output boolean VLVACTEXCLN_bFrtErrCntRst_Prev;                            */
/*  output boolean VLVACTEXCLN_bTriggerPrev;                                  */
/*  output boolean VLVACTEXCLN_bInitTimer1_Prev;                              */
/*  output boolean VLVACTEXCLN_bInitTimer2_Prev;                              */
/*  output boolean VLVACTEXCLN_bManCleanVarUpPrev;                            */
/*  output boolean VLVACTEXCLN_bVlvActClnBeEnaPrev;                           */
/*  output boolean VLVACTEXCLN_bLocalComparePrev;                             */
/*  output boolean VLVACTEXCLN_bLocalCalcPrev;                                */
/*  output uint16 VLVACTEXCLN_u16TimerCount1;                                 */
/*  output uint16 VLVACTEXCLN_u16TimerCount;                                  */
/*  output uint32 VLVACTEXCLN_u32TimerCount2;                                 */
/*  output boolean VLVACTEXCLN_bTimeout;                                      */
/*  output boolean VLVACTEXCLN_bTimeout1;                                     */
/*  output boolean VLVACTEXCLN_bTimeout2;                                     */
/*  output uint8 VlvAct_ctExFrstClnCyc;                                       */
/*  output uint8 VlvAct_tiExFrstClnIdc;                                       */
/*  output uint8 VlvAct_CtExHealClnErr;                                       */
/*  output boolean VlvAct_bExHealClnEnd;                                      */
/*  output boolean VlvAct_bExManClnEnaIdc;                                    */
/*  output boolean VlvAct_bExNormClnEnd;                                      */
/*  output uint8 VlvAct_tiExHealClnIdc;                                       */
/*  output uint8 VlvAct_tiExNormClnIdc;                                       */
/*  output uint8 VlvAct_ctExHealClnDone;                                      */
/*  output uint8 VlvAct_ctExNormClnDone;                                      */
/*  output boolean VLVACTEXCLN_bRctClnVarUdtPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidInitOutput(void)
{
   VEMS_vidSET(VlvAct_ExClnStCmd, 0);
   VEMS_vidSET(VlvAct_bExMngClnStReq, 0);
   VEMS_vidSET(VlvAct_bExFrstClnDone, 0);
   VLVACTEXCLN_bVlAcvExHealCln_Prev = 0;
   VLVACTEXCLN_bFrtErrCntRst_Prev = 0;
   VLVACTEXCLN_bTriggerPrev = 0;
   VLVACTEXCLN_bInitTimer1_Prev = 0;
   VLVACTEXCLN_bInitTimer2_Prev = 0;
   VLVACTEXCLN_bManCleanVarUpPrev =0;
   VLVACTEXCLN_bVlvActClnBeEnaPrev = 0;
   VLVACTEXCLN_bLocalComparePrev = 0;
   VLVACTEXCLN_bLocalCalcPrev = 0;
   VLVACTEXCLN_u16TimerCount1 = 0;
   VLVACTEXCLN_u16TimerCount = 0;
   VLVACTEXCLN_u32TimerCount2 = 0;
   VLVACTEXCLN_bTimeout = 0;
   VLVACTEXCLN_bTimeout1 = 0;
   VLVACTEXCLN_bTimeout2 =0;
   VlvAct_ctExFrstClnCyc = 0;
   VlvAct_tiExFrstClnIdc = 0;
   VlvAct_CtExHealClnErr = 0;
   VlvAct_bExHealClnEnd = 0;
   VlvAct_bExManClnEnaIdc = 0;
   VlvAct_bExNormClnEnd = 0;
   VlvAct_tiExHealClnIdc = 0;
   VlvAct_tiExNormClnIdc = 0;
   VlvAct_ctExHealClnDone = 0;
   VlvAct_ctExNormClnDone = 0;
   VLVACTEXCLN_bRctClnVarUdtPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidClnIndTiCnt                                 */
/* !Description :  Index du compteur pour le mode curatif et le mode          */
/*                 préventif.                                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCLN_vidClnIndTmCntRct();                         */
/*  extf argret void VLVACTEXCLN_vidClnIndTmCntPct();                         */
/*  extf argret void VLVACTEXCLN_vidClnInCnteFrstcln();                       */
/*  input boolean VlvAct_bExHealClnStMonGlblReq;                              */
/*  input boolean VlvAct_bExNormClnStReq;                                     */
/*  input boolean VlvAct_bExFrstClnStReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidClnIndTiCnt(void)
{
   if (VlvAct_bExHealClnStMonGlblReq != 0)
   {
      VLVACTEXCLN_vidClnIndTmCntRct();
   }
   if (VlvAct_bExNormClnStReq != 0)
   {
      VLVACTEXCLN_vidClnIndTmCntPct();
   }
   if (VlvAct_bExFrstClnStReq != 0)
   {
      VLVACTEXCLN_vidClnInCnteFrstcln();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidClnIndTmCntRct                              */
/* !Description :  Ce bloc incrémente l’index de temps utilisé dans la        */
/*                 cartographie générant la commande de nettoyage en mode     */
/*                 curatif.                                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_tiExHealClnIdc;                                        */
/*  output uint8 VlvAct_tiExHealClnIdc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidClnIndTmCntRct(void)
{
   if ( VlvAct_tiExHealClnIdc < 20 )
   {
      VlvAct_tiExHealClnIdc = (uint8)(VlvAct_tiExHealClnIdc + 1);
   }
   else
   {
      VlvAct_tiExHealClnIdc = 20;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidClnIndTmCntPct                              */
/* !Description :  Ce bloc incrémente l’index de temps utilisé dans la        */
/*                 cartographie générant la commande de nettoyage en mode     */
/*                 préventif.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_tiExNormClnIdc;                                        */
/*  output uint8 VlvAct_tiExNormClnIdc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidClnIndTmCntPct(void)
{
   if (VlvAct_tiExNormClnIdc < 20)
   {
      VlvAct_tiExNormClnIdc = (uint8)(VlvAct_tiExNormClnIdc + 1);
   }
   else
   {
      VlvAct_tiExNormClnIdc = 20;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidClnInCnteFrstcln                            */
/* !Description :  Ce bloc incrémente l’index de temps utilisé dans la        */
/*                 cartographie générant la commande de nettoyage en mode     */
/*                 préventif.                                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_tiExFrstClnIdc;                                        */
/*  output uint8 VlvAct_tiExFrstClnIdc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidClnInCnteFrstcln(void)
{
   if (VlvAct_tiExFrstClnIdc < 20)
   {
      VlvAct_tiExFrstClnIdc = (uint8)(VlvAct_tiExFrstClnIdc + 1);
   }
   else
   {
      VlvAct_tiExFrstClnIdc = 20;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidErrCountRst                                 */
/* !Description :  remise à zero de la variable VlvAct_CtInHealClnErr         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 VlvAct_CtExHealClnErr;                                       */
/*  output uint8 VlvAct_ctExNormClnDone;                                      */
/*  output uint8 VlvAct_ctExHealClnDone;                                      */
/*  output boolean VlvAct_bExNormClnEnd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidErrCountRst(void)
{
   VlvAct_CtExHealClnErr = 0;
   VlvAct_ctExNormClnDone = 0;
   VlvAct_ctExHealClnDone = 0;
   VlvAct_bExNormClnEnd = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidRctClnUdt                                   */
/* !Description :  Mise à jour des variables liées aux nettoyages curatifs    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCLN_vidRctClnVarUdt();                           */
/*  input uint8 VlvAct_tiExHealClnIdc;                                        */
/*  input uint8 VlvAct_tiExClnEndThd_C;                                       */
/*  input boolean VLVACTEXCLN_bRctClnVarUdtPrev;                              */
/*  output boolean VLVACTEXCLN_bRctClnVarUdtPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidRctClnUdt(void)
{
   /*2_Reactive_cleaning_update */
   boolean bLocalRctClnVarUdt;


   if (VlvAct_tiExHealClnIdc >= VlvAct_tiExClnEndThd_C)
   {
      bLocalRctClnVarUdt = 1;
   }
   else
   {
      bLocalRctClnVarUdt = 0;
   }
   if (  (VLVACTEXCLN_bRctClnVarUdtPrev == 0)
      && (bLocalRctClnVarUdt != 0))
   {
      VLVACTEXCLN_vidRctClnVarUdt();
   }
   VLVACTEXCLN_bRctClnVarUdtPrev = bLocalRctClnVarUdt;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidCmdcmp                                      */
/* !Description :  Activation du nettoyage de l'électrovanne VVT échappement  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXCLN_vidCmdCalc();                                */
/*  input boolean VlvAct_bExClnEna;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidCmdcmp(void)
{
   boolean bLocalVlvAct_bExClnEna;


   VEMS_vidGET(VlvAct_bExClnEna, bLocalVlvAct_bExClnEna);

   if (bLocalVlvAct_bExClnEna != 0)
   {
      VLVACTEXCLN_vidCmdCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidCmdCalc                                     */
/* !Description :  Le nettoyage (mode préventif, mode curatif, sortie usine)  */
/*                 se fait suivant un profil de commande définit par les      */
/*                 cartographies VlvAct_ExNormClnCmd_M, VlvAct_ExHealClnCmd_M */
/*                 et VlvAct_ExFrstClnCmd_M.                                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_08_08235_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Vcpe_cam_position_error;                                     */
/*  input boolean VlvAct_bExNormClnStReq;                                     */
/*  input uint8 VlvAct_tiExNormClnIdc;                                        */
/*  input boolean VlvAct_bExFrstClnStReq;                                     */
/*  input uint8 VlvAct_tiExFrstClnIdc;                                        */
/*  input uint8 VlvAct_tiExHealClnIdc;                                        */
/*  input uint8 VlvAct_tiExFrstClnIdc_T[21];                                  */
/*  input uint8 VlvAct_tiExClnIdc;                                            */
/*  input uint8 VlvAct_ExFrstClnCmd_M[21];                                    */
/*  input boolean VlvAct_bExHealClnStMonGlblReq;                              */
/*  input uint8 VlvAct_tiExHealClnIdc_T[21];                                  */
/*  input uint8 VlvAct_ExHealClnCmd_M[21];                                    */
/*  input uint8 VlvAct_tiExNormClnIdc_T[21];                                  */
/*  input uint8 VlvAct_ExNormClnCmd_M[21];                                    */
/*  input uint16 VlvAct_ExClnCmdMin_C;                                        */
/*  input boolean VlvAct_bExSelTypCmdProfTyp_C;                               */
/*  input uint16 Vcpe_integral_value;                                         */
/*  input uint16 VlvAct_ExClnCmdMax_C;                                        */
/*  output uint8 VlvAct_tiExClnIdc;                                           */
/*  output uint16 VlvAct_ExClnStCmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidCmdCalc(void)
{
   uint8  u8LocalData;
   uint16 u16LocalPara;
   uint16 u16LocalVlvAct_ExClnStCmd;
   uint16 u16LocalOutPutSwitch;
   uint16 u16LocalVcpe_integral_value;
   sint16 s16LocalVcpe_cam_position_error;
   sint32 s32LocalVlvAct;


   VEMS_vidGET(Vcpe_cam_position_error, s16LocalVcpe_cam_position_error);

   if (VlvAct_bExNormClnStReq != 0)
   {
      VlvAct_tiExClnIdc = (uint8)MATHSRV_udtMIN(VlvAct_tiExNormClnIdc, 20);
   }
   else
   {
      if (VlvAct_bExFrstClnStReq != 0)
      {
         VlvAct_tiExClnIdc = (uint8)MATHSRV_udtMIN(VlvAct_tiExFrstClnIdc, 20);
      }
      else
      {
         VlvAct_tiExClnIdc = (uint8)MATHSRV_udtMIN(VlvAct_tiExHealClnIdc, 20);
      }
   }

   if (VlvAct_bExFrstClnStReq != 0)
   {
      u16LocalPara = MATHSRV_u16CalcParaIncAryU8(VlvAct_tiExFrstClnIdc_T,
                                                 VlvAct_tiExClnIdc,
                                                 21);
      u16LocalPara = (uint16)(u16LocalPara & 0xFF00);
      u8LocalData = MATHSRV_u8Interp1d(VlvAct_ExFrstClnCmd_M, u16LocalPara);
   }
   else
   {
      if (VlvAct_bExHealClnStMonGlblReq != 0)
      {
         u16LocalPara = MATHSRV_u16CalcParaIncAryU8(VlvAct_tiExHealClnIdc_T,
                                                    VlvAct_tiExClnIdc,
                                                    21);
         u16LocalPara = (uint16)(u16LocalPara & 0xFF00);
         u8LocalData = MATHSRV_u8Interp1d(VlvAct_ExHealClnCmd_M, u16LocalPara);
      }
      else
      {
         u16LocalPara = MATHSRV_u16CalcParaIncAryU8(VlvAct_tiExNormClnIdc_T,
                                                    VlvAct_tiExClnIdc,
                                                    21);
         u16LocalPara = (uint16)(u16LocalPara & 0xFF00);
         u8LocalData = MATHSRV_u8Interp1d(VlvAct_ExNormClnCmd_M, u16LocalPara);
      }
   }

   switch(u8LocalData)
   {
      case 0:
         u16LocalOutPutSwitch = VlvAct_ExClnCmdMin_C;
         break;

      case 1:
         if (VlvAct_bExSelTypCmdProfTyp_C != 0)
         {
            VEMS_vidGET(Vcpe_integral_value, u16LocalVcpe_integral_value);
            u16LocalOutPutSwitch =
               (uint16)((u16LocalVcpe_integral_value + 32) / 64);
         }
         else
         {
            u16LocalOutPutSwitch = 512;
         }
         break;

      case 2:
         u16LocalOutPutSwitch = VlvAct_ExClnCmdMax_C;
         break;

      default:
         u16LocalOutPutSwitch = VlvAct_ExClnCmdMin_C;
         break;
   }
   if (  (s16LocalVcpe_cam_position_error >= 0)
      || (VlvAct_bExSelTypCmdProfTyp_C != 0))
   {
      u16LocalVlvAct_ExClnStCmd =
         (uint16)MATHSRV_udtMIN(u16LocalOutPutSwitch, 1023);
   }
   else
   {
      s32LocalVlvAct = (sint32)(1024 - u16LocalOutPutSwitch);
      u16LocalVlvAct_ExClnStCmd = (uint16)MATHSRV_udtCLAMP(s32LocalVlvAct,
                                                           0,
                                                           1023);
   }
   VEMS_vidSET(VlvAct_ExClnStCmd, u16LocalVlvAct_ExClnStCmd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidFrstCleaCond                                */
/* !Description :  Le mode de nettoyage sortie usine « nettoyage moteur neuf »*/
/*                 doit permettre l’élimination des copeaux d’usinage présents*/
/*                 dans le circuit d’huile qui n’auraient pas pu être         */
/*                 supprimés lors du nettoyage réalisé après le montage du    */
/*                 moteur à l’usine moteur.                                   */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_08_08235_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTEXCLN_vidFrstCleanVarUpdte();                      */
/*  input boolean Vta_exhaust_allow_learning;                                 */
/*  input boolean VlvAct_bExFrstClnAuth;                                      */
/*  input boolean VlvAct_bExOfsFrstLrnWouDft;                                 */
/*  input uint8 VlvAct_tiExFrstClnIdc;                                        */
/*  input uint8 VlvAct_tiExClnEndThd_C;                                       */
/*  input uint8 VlvAct_ctExFrstClnCyc;                                        */
/*  input uint8 VlvAct_ctExFrstClnCycThd_C;                                   */
/*  input boolean VLVACTEXCLN_bLocalCalcPrev;                                 */
/*  input boolean VLVACTEXCLN_bLocalComparePrev;                              */
/*  output boolean VlvAct_bExFrstClnDone;                                     */
/*  output boolean VlvAct_bExFrstClnStReq;                                    */
/*  output boolean VLVACTEXCLN_bLocalComparePrev;                             */
/*  output boolean VLVACTEXCLN_bLocalCalcPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidFrstCleaCond(void)
{
   boolean bLocalVta_exhaust_allow_learning;
   boolean bLocalVlvActbExFrstClnAuth;
   boolean bLocalVlvAct_bExOfsFrstLrnWouDft;
   boolean bLocalCalc;
   boolean bLocalCompare1;


   VEMS_vidGET(Vta_exhaust_allow_learning, bLocalVta_exhaust_allow_learning);
   VEMS_vidGET(VlvAct_bExFrstClnAuth, bLocalVlvActbExFrstClnAuth);
   VEMS_vidGET(VlvAct_bExOfsFrstLrnWouDft, bLocalVlvAct_bExOfsFrstLrnWouDft);
   if (VlvAct_tiExFrstClnIdc >= VlvAct_tiExClnEndThd_C)
   {
      bLocalCompare1 = 1;
   }
   else
   {
      bLocalCompare1 = 0;
   }

   if (  (bLocalVta_exhaust_allow_learning == 0)
      && (bLocalVlvActbExFrstClnAuth != 0)
      && (bLocalVlvAct_bExOfsFrstLrnWouDft == 0)
      && (VlvAct_ctExFrstClnCyc < VlvAct_ctExFrstClnCycThd_C))
   {
      bLocalCalc = 1;
   }
   else
   {
      bLocalCalc = 0;
   }
   if (  (VLVACTEXCLN_bLocalCalcPrev !=0)
      && (bLocalCalc == 0))
   {
      VEMS_vidSET(VlvAct_bExFrstClnDone, 1);
   }
   if (  (bLocalCalc != 0)
      && (bLocalCompare1 == 0))
   {
      VlvAct_bExFrstClnStReq = 1;
   }
   else
   {
      VlvAct_bExFrstClnStReq = 0;
   }
   if (  (VLVACTEXCLN_bLocalComparePrev == 0)
      && (bLocalCompare1 != 0))
   {
      VLVACTEXCLN_vidFrstCleanVarUpdte();
   }
   VLVACTEXCLN_bLocalComparePrev = bLocalCompare1;
   VLVACTEXCLN_bLocalCalcPrev = bLocalCalc;
}
/*---------------------------- end of file -----------------------------------*/