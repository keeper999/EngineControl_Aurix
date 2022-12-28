/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CRSCTLBSITREAT                                          */
/* !Description     : CRSCTLBSITREAT Component                                */
/*                                                                            */
/* !Module          : CRSCTLBSITREAT                                          */
/* !Description     : TRAITEMENT DES INFORMATIONS BSI POUR LES BESOINS DE LA  */
/*                    XVV                                                     */
/*                                                                            */
/* !File            : CRSCTLBSITREAT_FCT1.C                                   */
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
/*   1 / CRSCTLBSITREAT_vidInit                                               */
/*   2 / CRSCTLBSITREAT_vidInitOutput                                         */
/*   3 / CRSCTLBSITREAT_vidDiag_1                                             */
/*   4 / CRSCTLBSITREAT_vidDiagEna                                            */
/*   5 / CRSCTLBSITREAT_vidBsiFraCnt                                          */
/*   6 / CRSCTLBSITREAT_vidCptTrBsiNtZero                                     */
/*   7 / CRSCTLBSITREAT_vidCptTraBsiInc                                       */
/*   8 / CRSCTLBSITREAT_vidBsiFraFil                                          */
/*   9 / CRSCTLBSITREAT_vidInfoBsiCoh                                         */
/*   10 / CRSCTLBSITREAT_vidLimSpdSpCoh                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5206188 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CRSCTL/CRSCTLBSITREAT/CRSCTLBSIT$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   19 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CRSCTLBSITREAT.h"
#include "CRSCTLBSITREAT_I.h"
#include "CRSCTLBSITREAT_L.h"
#include "CRSCTLBSITREAT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidInit                                     */
/* !Description :  Fonction d'initialisation des variables produites.         */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 EcuSt_stTypRst;                                               */
/*  input uint8 XVV_Cc_rvv_drv_vh_spd_sp_mux_mem;                             */
/*  output uint8 Ext_ctBSIFrameMem;                                           */
/*  output uint8 Ext_spdVehReqVSLimMem;                                       */
/*  output uint8 Ext_spdVehReqVSRegMem;                                       */
/*  output uint8 Ext_spdVehVSLimReq;                                          */
/*  output uint8 Ext_spdVehVSRegReq;                                          */
/*  output uint8 Ext_stAcvRegVSCtlReq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidInit(void)
{
   uint8 u8LocalEcuSt_stTypRst;


   Ext_ctBSIFrameMem = 255;
   Ext_spdVehReqVSLimMem = 255;
   VEMS_vidGET(EcuSt_stTypRst, u8LocalEcuSt_stTypRst);
   if (u8LocalEcuSt_stTypRst == RSTSRV_udtSOFTWARE_RESET)
   {
      Ext_spdVehReqVSRegMem = XVV_Cc_rvv_drv_vh_spd_sp_mux_mem;
   }
   else
   {
      Ext_spdVehReqVSRegMem = 255;
   }
   VEMS_vidSET(Ext_spdVehVSLimReq, 255);
   VEMS_vidSET(Ext_spdVehVSRegReq, 255);
   VEMS_vidSET(Ext_stAcvRegVSCtlReq, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidInitOutput                               */
/* !Description :  Fonction d'initialisation.                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 VSCtl_ctZeroFramePrev;                                       */
/*  output uint8 VSCtl_ctEvenFramePrev;                                       */
/*  output boolean VSCtl_bMonRunElDft;                                        */
/*  output boolean VSCtl_bDftBsiFraCntInc;                                    */
/*  output boolean VSCtl_bDgoElChkConsDft;                                    */
/*  output boolean VSCtl_bDgoElConsDefDftVSLim;                               */
/*  output boolean VSCtl_bDgoElConsDefDftVSReg;                               */
/*  output boolean VSCtl_bDgoElConsInitDftVSReg;                              */
/*  output boolean VSCtl_bDgoElConsVarDftVSLim;                               */
/*  output boolean VSCtl_bDgoElConsVarDftVSReg;                               */
/*  output boolean VSCtl_bDgoElCptTraBsiDft;                                  */
/*  output boolean VSCtl_bDgoElFrameCntIncDft;                                */
/*  output boolean VSCtl_bDgoElInfBsiDft;                                     */
/*  output boolean VSCtl_bDgoEvenFrameCntDft;                                 */
/*  output boolean VSCtl_bDgoZeroFrameCntDft;                                 */
/*  output boolean VSCtl_bDgoElDftCrsCtl;                                     */
/*  output uint8 VSCtl_ctEvenFrame;                                           */
/*  output uint8 Ext_stVSCtlReq_2;                                            */
/*  output uint8 Ext_spdVehVSCtlReq_2;                                        */
/*  output boolean Ext_bVSRegDVSRegReq_2;                                     */
/*  output boolean Ext_bVSLimReq_2;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidInitOutput(void)
{
   VSCtl_ctZeroFramePrev = 0;
   VSCtl_ctEvenFramePrev = 0;
   VSCtl_bMonRunElDft = 0;
   VSCtl_bDftBsiFraCntInc = 0;
   VSCtl_bDgoElChkConsDft = 0;
   VSCtl_bDgoElConsDefDftVSLim= 0;
   VSCtl_bDgoElConsDefDftVSReg = 0;
   VSCtl_bDgoElConsInitDftVSReg = 0;
   VSCtl_bDgoElConsVarDftVSLim = 0;
   VSCtl_bDgoElConsVarDftVSReg = 0;
   VSCtl_bDgoElCptTraBsiDft = 0;
   VSCtl_bDgoElFrameCntIncDft = 0;
   VSCtl_bDgoElInfBsiDft = 0;
   VSCtl_bDgoEvenFrameCntDft = 0;
   VSCtl_bDgoZeroFrameCntDft = 0;
   VSCtl_bDgoElDftCrsCtl = 0;
   VSCtl_ctEvenFrame = 0;
   Ext_stVSCtlReq_2 = 0;
   Ext_spdVehVSCtlReq_2 = 0;
   Ext_bVSRegDVSRegReq_2 = 0;
   Ext_bVSLimReq_2 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidDiag_1                                   */
/* !Description :  Fonction qui réalise les diagnostics des cohérences des    */
/*                 informations BSI à chaque réception de la trame 50Eh et si */
/*                 la LVV ou RVV est détectée présente.                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CRSCTLBSITREAT_vidDiagEna();                             */
/*  input boolean Ext_bVSRegCf;                                               */
/*  input boolean Ext_bVSLimCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidDiag_1(void)
{
   boolean bLocalExt_bVSRegCf;
   boolean bLocalExt_bVSLimCf;


   VEMS_vidGET(Ext_bVSRegCf, bLocalExt_bVSRegCf);
   VEMS_vidGET(Ext_bVSLimCf, bLocalExt_bVSLimCf);
   if (  (bLocalExt_bVSRegCf != 0)
      || (bLocalExt_bVSLimCf != 0))
   {
      CRSCTLBSITREAT_vidDiagEna();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidDiagEna                                  */
/* !Description :  Focntion qui décrit 5 stratégies de diagnostics de         */
/*                 cohérence.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CRSCTLBSITREAT_vidBsiFraCnt();                           */
/*  extf argret void CRSCTLBSITREAT_vidBsiFraFil();                           */
/*  extf argret void CRSCTLBSITREAT_vidInfoBsiCoh();                          */
/*  extf argret void CRSCTLBSITREAT_vidLimSpdSpCoh();                         */
/*  extf argret void CRSCTLBSITREAT_vidRegSpdSpCoh();                         */
/*  extf argret void CRSCTLBSITREAT_vidCksCoh();                              */
/*  input boolean Ext_bKeyOff;                                                */
/*  input boolean Diag_on;                                                    */
/*  input boolean VSCtl_bDftBsiFraCntInc;                                     */
/*  input uint8 Ext_ctBSIFrame;                                               */
/*  input boolean VSCtl_bMonRunElDft;                                         */
/*  input boolean VSCtl_bDgoElInfBsiDft;                                      */
/*  input boolean VSCtl_bDgoElCptTraBsiDft;                                   */
/*  input boolean VSCtl_bDgoElConsDefDftVSLim;                                */
/*  input boolean VSCtl_bDgoElConsVarDftVSLim;                                */
/*  input boolean VSCtl_bDgoElConsDefDftVSReg;                                */
/*  input boolean VSCtl_bDgoElConsVarDftVSReg;                                */
/*  input boolean VSCtl_bDgoElConsInitDftVSReg;                               */
/*  input boolean VSCtl_bDgoElChkConsDft;                                     */
/*  output boolean VSCtl_bMonRunElDft;                                        */
/*  output boolean VSCtl_bDgoElFrameCntIncDft;                                */
/*  output boolean VSCtl_bDgoElDftCrsCtl;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidDiagEna(void)
{
   boolean bLocalExt_bKeyOff;
   boolean bLocalDiag_on;
   uint8   u8LocalExt_ctBSIFrame;
   uint8   u8LocalMod;


   VEMS_vidGET(Ext_bKeyOff, bLocalExt_bKeyOff);
   VEMS_vidGET(Diag_on, bLocalDiag_on);
   if (  (bLocalExt_bKeyOff == 0)
      && (bLocalDiag_on != 0))
   {
      VSCtl_bMonRunElDft = 1;
   }
   else
   {
      VSCtl_bMonRunElDft = 0;
   }
   CRSCTLBSITREAT_vidBsiFraCnt();
   VSCtl_bDgoElFrameCntIncDft = VSCtl_bDftBsiFraCntInc;
   VEMS_vidGET(Ext_ctBSIFrame, u8LocalExt_ctBSIFrame);
   u8LocalMod = (uint8)(u8LocalExt_ctBSIFrame % 2);
   if (  (u8LocalExt_ctBSIFrame == 0)
      || (u8LocalMod == 1))
   {
      CRSCTLBSITREAT_vidBsiFraFil();
   }

   if (VSCtl_bMonRunElDft != 0)
   {
      CRSCTLBSITREAT_vidInfoBsiCoh();
   }

   if (VSCtl_bDgoElInfBsiDft == 0)
   {
      CRSCTLBSITREAT_vidLimSpdSpCoh();
      CRSCTLBSITREAT_vidRegSpdSpCoh();
   }
   if (VSCtl_bMonRunElDft != 0)
   {
      CRSCTLBSITREAT_vidCksCoh();
   }
   if (  (VSCtl_bDgoElCptTraBsiDft != 0)
      || (VSCtl_bDgoElInfBsiDft != 0)
      || (VSCtl_bDgoElConsDefDftVSLim != 0)
      || (VSCtl_bDgoElConsVarDftVSLim != 0)
      || (VSCtl_bDgoElConsDefDftVSReg != 0)
      || (VSCtl_bDgoElConsVarDftVSReg != 0)
      || (VSCtl_bDgoElConsInitDftVSReg != 0)
      || (VSCtl_bDgoElChkConsDft != 0))
   {
      VSCtl_bDgoElDftCrsCtl = 1;
   }
   else
   {
      VSCtl_bDgoElDftCrsCtl = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidBsiFraCnt                                */
/* !Description :  Focntion de diagnontis de cohérence du compteur de trame   */
/*                 BSI                                                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CRSCTLBSITREAT_vidCptTrBsiNtZero();                      */
/*  input boolean VSCtl_bMonRunElDft;                                         */
/*  input uint8 Ext_ctBSIFrame;                                               */
/*  input uint8 VSCtl_ctZeroFrameThd_C;                                       */
/*  input uint8 VSCtl_ctIncZeroFrame_C;                                       */
/*  input uint8 VSCtl_ctZeroFramePrev;                                        */
/*  input uint8 VSCtl_ctEvenFrame;                                            */
/*  input uint8 VSCtl_ctEvenFrameThd_C;                                       */
/*  input uint8 VSCtl_ctZeroFrame;                                            */
/*  input boolean VSCtl_bDgoZeroFrameCntDft;                                  */
/*  input boolean VSCtl_bDftBsiFraCntInc;                                     */
/*  input boolean VSCtl_bDgoEvenFrameCntDft;                                  */
/*  output uint8 VSCtl_ctZeroFrame;                                           */
/*  output boolean VSCtl_bDgoZeroFrameCntDft;                                 */
/*  output boolean VSCtl_bDftBsiFraCntInc;                                    */
/*  output boolean VSCtl_bDgoEvenFrameCntDft;                                 */
/*  output uint8 VSCtl_ctEvenFrame;                                           */
/*  output uint8 Ext_ctBSIFrameMem;                                           */
/*  output uint8 VSCtl_ctZeroFramePrev;                                       */
/*  output uint8 VSCtl_ctEvenFramePrev;                                       */
/*  output boolean VSCtl_bDgoElCptTraBsiDft;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidBsiFraCnt(void)
{
   uint8  u8LocalExt_ctBSIFrame;
   uint16 u16LocalSom1;
   uint16 u16LocalSom2;
   uint16 u16LocalMin;


   if (VSCtl_bMonRunElDft == 0)
   {
      VSCtl_ctZeroFrame = 0;
      VSCtl_bDgoZeroFrameCntDft = 0;
      VSCtl_bDftBsiFraCntInc = 0;
      VSCtl_bDgoEvenFrameCntDft = 0;
      VSCtl_ctEvenFrame = 0;
      Ext_ctBSIFrameMem = 255;
   }
   else
   {
      VEMS_vidGET(Ext_ctBSIFrame, u8LocalExt_ctBSIFrame);
      if (u8LocalExt_ctBSIFrame == 0)
      {
         u16LocalSom1 = (uint16)(VSCtl_ctZeroFrameThd_C + 1);
         u16LocalSom2 =
            (uint16)(VSCtl_ctIncZeroFrame_C + VSCtl_ctZeroFramePrev);
         u16LocalMin = (uint16)MATHSRV_udtMIN(u16LocalSom1, u16LocalSom2);
         VSCtl_ctZeroFrame = (uint8)MATHSRV_udtMIN(u16LocalMin, 255);
         if (u16LocalMin > (uint16)VSCtl_ctZeroFrameThd_C)
         {
            VSCtl_bDgoZeroFrameCntDft = 1;
         }
         else
         {
            VSCtl_bDgoZeroFrameCntDft = 0;
         }
         if (VSCtl_ctEvenFrame > VSCtl_ctEvenFrameThd_C)
         {
            VSCtl_bDgoEvenFrameCntDft = 1;
         }
         else
         {
            VSCtl_bDgoEvenFrameCntDft = 0;
         }
         Ext_ctBSIFrameMem = 0;
      }
      else
      {
         CRSCTLBSITREAT_vidCptTrBsiNtZero();
         if (VSCtl_ctZeroFrame > VSCtl_ctZeroFrameThd_C)
         {
            VSCtl_bDgoZeroFrameCntDft = 1;
         }
         else
         {
            VSCtl_bDgoZeroFrameCntDft =0;
         }
         if (VSCtl_ctEvenFrame > VSCtl_ctEvenFrameThd_C)
         {
            VSCtl_bDgoEvenFrameCntDft = 1;
         }
         else
         {
            VSCtl_bDgoEvenFrameCntDft = 0;
         }
         Ext_ctBSIFrameMem = u8LocalExt_ctBSIFrame;
      }
   }
   VSCtl_ctZeroFramePrev = VSCtl_ctZeroFrame;
   VSCtl_ctEvenFramePrev = VSCtl_ctEvenFrame;
   if (  (VSCtl_bDgoZeroFrameCntDft != 0)
      || (VSCtl_bDftBsiFraCntInc != 0)
      || (VSCtl_bDgoEvenFrameCntDft != 0))
   {
      VSCtl_bDgoElCptTraBsiDft = 1;
   }
   else
   {
      VSCtl_bDgoElCptTraBsiDft = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidCptTrBsiNtZero                           */
/* !Description :  Cette fonction réalise les diagnostics du compteur de trame*/
/*                 BSI dans le cas où les valeurs  reçues sont différentes de */
/*                 zéro.                                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CRSCTLBSITREAT_vidCptTraBsiInc();                        */
/*  input uint8 Ext_ctBSIFrame;                                               */
/*  input uint8 VSCtl_ctZeroFramePrev;                                        */
/*  input uint8 VSCtl_ctDecZeroFrame_C;                                       */
/*  input uint8 VSCtl_ctEvenFramePrev;                                        */
/*  input uint8 VSCtl_ctDecEvenFrame_C;                                       */
/*  input uint8 VSCtl_ctEvenFrameThd_C;                                       */
/*  input uint8 VSCtl_ctIncEvenFrame_C;                                       */
/*  input uint8 Ext_ctBSIFrameMem;                                            */
/*  output uint8 VSCtl_ctZeroFrame;                                           */
/*  output uint8 VSCtl_ctEvenFrame;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidCptTrBsiNtZero(void)
{
   uint8  u8LocalExt_ctBSIFrame;
   uint8  u8LocalMod;
   uint16 u16LocalSom1;
   uint16 u16LocalSom2;
   uint16 u16LocalMin;
   sint16 s16LocalDiff;


   VEMS_vidGET(Ext_ctBSIFrame, u8LocalExt_ctBSIFrame);
   u8LocalMod = (uint8)(u8LocalExt_ctBSIFrame % 2);
   if (u8LocalMod == 1)
   {
      s16LocalDiff = (sint16)(VSCtl_ctZeroFramePrev - VSCtl_ctDecZeroFrame_C);
      VSCtl_ctZeroFrame = (uint8)MATHSRV_udtMAX(s16LocalDiff, 0);

      s16LocalDiff = (sint16)(VSCtl_ctEvenFramePrev - VSCtl_ctDecEvenFrame_C);
      VSCtl_ctEvenFrame = (uint8)MATHSRV_udtMAX(s16LocalDiff, 0);
   }
   else
   {
      VSCtl_ctZeroFrame = VSCtl_ctZeroFramePrev;

      u16LocalSom1 = (uint16)(VSCtl_ctEvenFrameThd_C + 1);
      u16LocalSom2 =
         (uint16)(VSCtl_ctEvenFramePrev + VSCtl_ctIncEvenFrame_C);
      u16LocalMin = (uint16)MATHSRV_udtMIN(u16LocalSom1, u16LocalSom2);
      VSCtl_ctEvenFrame = (uint8)MATHSRV_udtMIN(u16LocalMin, 255);
   }
   if (Ext_ctBSIFrameMem != 255)
   {
      CRSCTLBSITREAT_vidCptTraBsiInc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidCptTraBsiInc                             */
/* !Description :  Cette fonction réalise le diagnostic sur la valeur de      */
/*                 l’incrément du compteur de trame BSI                       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_ctBSIFrame;                                               */
/*  input uint8 Ext_ctBSIFrameMem;                                            */
/*  input uint8 VSCtl_ctIncMinFrame_C;                                        */
/*  input uint8 VSCtl_ctIncMaxFrame_C;                                        */
/*  output boolean VSCtl_bDftBsiFraCntInc;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidCptTraBsiInc(void)
{
   uint8  u8LocalExt_ctBSIFrame;
   sint16 s16LocalDiff;


   VEMS_vidGET(Ext_ctBSIFrame, u8LocalExt_ctBSIFrame);
   s16LocalDiff = (sint16)(u8LocalExt_ctBSIFrame - Ext_ctBSIFrameMem);
   if (s16LocalDiff < 0)
   {
      s16LocalDiff = (sint16)(s16LocalDiff + 16);
   }
   if (  (s16LocalDiff < VSCtl_ctIncMinFrame_C)
      || (s16LocalDiff > VSCtl_ctIncMaxFrame_C))
   {
      VSCtl_bDftBsiFraCntInc = 1;
   }
   else
   {
      VSCtl_bDftBsiFraCntInc = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidBsiFraFil                                */
/* !Description :  Cette fonction permet de filtrer les informations BSI en   */
/*                 fonction des valeurs reçues du compteur de trame BSI avant */
/*                 qu’elles soient traitées pour les besoins de la fonction   */
/*                 XVV                                                        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bVSLimReq;                                              */
/*  input boolean Ext_bVSRegDVSRegReq;                                        */
/*  input uint8 Ext_spdVehVSCtlReq;                                           */
/*  input uint8 Ext_stVSCtlReq;                                               */
/*  input boolean Cc_limitation_speed_on_mux;                                 */
/*  input boolean Cc_regulation_speed_on_mux;                                 */
/*  input boolean Cc_acc_regulation_type_mux;                                 */
/*  output boolean Ext_bVSLimReq_2;                                           */
/*  output boolean Ext_bVSRegDVSRegReq_2;                                     */
/*  output uint8 Ext_spdVehVSCtlReq_2;                                        */
/*  output uint8 Ext_stVSCtlReq_2;                                            */
/*  output boolean Cc_limitation_speed_on;                                    */
/*  output boolean Cc_regulation_speed_on;                                    */
/*  output boolean Cc_acc_regulation_type;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidBsiFraFil(void)
{
   boolean bLocalExt_bVSLimReq;
   boolean bLocalExt_bVSRegDVSRegReq;
   boolean bLocalCc_limitation_speed_on_mux;
   boolean bLocalCc_regulation_speed_on_mux;
   boolean bLocalCc_acc_regulation_type_mux;
   uint8   u8LocalExt_spdVehVSCtlReq;
   uint8   u8LocalExt_stVSCtlReq;


   VEMS_vidGET(Ext_bVSLimReq, bLocalExt_bVSLimReq);
   VEMS_vidGET(Ext_bVSRegDVSRegReq, bLocalExt_bVSRegDVSRegReq);
   VEMS_vidGET(Ext_spdVehVSCtlReq, u8LocalExt_spdVehVSCtlReq);
   VEMS_vidGET(Ext_stVSCtlReq, u8LocalExt_stVSCtlReq);
   VEMS_vidGET(Cc_limitation_speed_on_mux, bLocalCc_limitation_speed_on_mux);
   VEMS_vidGET(Cc_regulation_speed_on_mux, bLocalCc_regulation_speed_on_mux);
   VEMS_vidGET(Cc_acc_regulation_type_mux, bLocalCc_acc_regulation_type_mux);

   Ext_bVSLimReq_2 = bLocalExt_bVSLimReq;
   Ext_bVSRegDVSRegReq_2 = bLocalExt_bVSRegDVSRegReq;
   Ext_spdVehVSCtlReq_2 = u8LocalExt_spdVehVSCtlReq;
   Ext_stVSCtlReq_2 = (uint8)MATHSRV_udtMIN(u8LocalExt_stVSCtlReq, 3);
   Cc_limitation_speed_on = bLocalCc_limitation_speed_on_mux;
   Cc_regulation_speed_on = bLocalCc_regulation_speed_on_mux;
   Cc_acc_regulation_type = bLocalCc_acc_regulation_type_mux;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidInfoBsiCoh                               */
/* !Description :  Cette fonction s’assure de la cohérence des informations   */
/*                 envoyées par la BSI.                                       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Cc_acc_regulation_type_mux;                                 */
/*  input boolean Cc_regulation_speed_on_mux;                                 */
/*  input boolean Cc_limitation_speed_on_mux;                                 */
/*  input boolean Ext_bVSRegDVSRegReq;                                        */
/*  input uint8 Ext_spdVehVSCtlReq;                                           */
/*  input boolean Ext_bVSLimReq;                                              */
/*  input uint8 Ext_ctBSIFrame;                                               */
/*  input boolean CrsCtl_LVV_activated;                                       */
/*  input boolean CrsCtl_RVV_activated;                                       */
/*  input boolean CrsCtl_LVV_selected;                                        */
/*  input boolean CrsCtl_RVV_selected;                                        */
/*  input boolean CrsCtl_ACC_activated;                                       */
/*  input boolean CrsCtl_ACC_selected;                                        */
/*  input boolean CrsCtl_Off;                                                 */
/*  output boolean CrsCtl_LVV_selected;                                       */
/*  output boolean CrsCtl_RVV_selected;                                       */
/*  output boolean CrsCtl_ACC_selected;                                       */
/*  output boolean CrsCtl_LVV_activated;                                      */
/*  output boolean CrsCtl_RVV_activated;                                      */
/*  output boolean CrsCtl_ACC_activated;                                      */
/*  output boolean CrsCtl_Off;                                                */
/*  output boolean VSCtl_bDgoElInfBsiDft;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidInfoBsiCoh(void)
{
   boolean bLocalExt_bVSLimReq;
   boolean bLocalCc_limitation_speed_on_mux;
   boolean bLocalExt_bVSRegDVSRegReq;
   boolean bLocalCc_regulation_speed_on_mux;
   boolean bLocalCc_acc_regulation_type_mux;
   uint8   u8LocalExt_ctBSIFrame;
   uint8   u8LocalExt_spdVehVSCtlReq;

   VEMS_vidGET(Cc_acc_regulation_type_mux, bLocalCc_acc_regulation_type_mux);
   VEMS_vidGET(Cc_regulation_speed_on_mux, bLocalCc_regulation_speed_on_mux);
   VEMS_vidGET(Cc_limitation_speed_on_mux, bLocalCc_limitation_speed_on_mux);
   VEMS_vidGET(Ext_bVSRegDVSRegReq, bLocalExt_bVSRegDVSRegReq);
   VEMS_vidGET(Ext_spdVehVSCtlReq, u8LocalExt_spdVehVSCtlReq);
   VEMS_vidGET(Ext_bVSLimReq, bLocalExt_bVSLimReq);

   VEMS_vidGET(Ext_ctBSIFrame, u8LocalExt_ctBSIFrame);
   if (u8LocalExt_ctBSIFrame == 0)
   {
      CrsCtl_LVV_selected = 0;
      CrsCtl_RVV_selected = 0;
      CrsCtl_ACC_selected = 0;
      CrsCtl_LVV_activated = 0;
      CrsCtl_RVV_activated = 0;
      CrsCtl_ACC_activated = 0;
   }
   else
   {
      if (bLocalExt_bVSLimReq != 0)
      {
         CrsCtl_LVV_selected = 0;
         CrsCtl_RVV_selected = 0;
         CrsCtl_ACC_selected = 0;
         CrsCtl_RVV_activated = 0;
         CrsCtl_ACC_activated = 0;
         /*CrsCtl_LVV_activated*/
         if (  (bLocalCc_limitation_speed_on_mux != 0)
            && (bLocalExt_bVSRegDVSRegReq == 0)
            && (u8LocalExt_spdVehVSCtlReq != 255))
         {
            CrsCtl_LVV_activated = 1;
         }
         else
         {
            CrsCtl_LVV_activated = 0;
         }
      }
      else
      {
         if (  (bLocalExt_bVSRegDVSRegReq == 0)
            && (u8LocalExt_spdVehVSCtlReq == 255))
         {
         /*CrsCtl_LVV_selected*/
            if (bLocalCc_limitation_speed_on_mux != 0)
            {
               CrsCtl_LVV_selected = 1;
            }
            else
            {
               CrsCtl_LVV_selected = 0;
            }
         /*CrsCtl_RVV_selected**/
            if (bLocalCc_regulation_speed_on_mux !=0)
            {
               CrsCtl_RVV_selected = 1;
            }
            else
            {
               CrsCtl_RVV_selected = 0;
            }
         /*CrsCtl_ACC_selected*/
            if (bLocalCc_acc_regulation_type_mux != 0)
            {
               CrsCtl_ACC_selected = 1;
            }
            else
            {
               CrsCtl_ACC_selected = 0;
            }
         }
         else
         {
            CrsCtl_LVV_selected = 0;
            CrsCtl_RVV_selected = 0;
            CrsCtl_ACC_selected = 0;
         }

         if (  (bLocalExt_bVSRegDVSRegReq != 0)
            && (u8LocalExt_spdVehVSCtlReq != 255))
         {
         /*CrsCtl_RVV_activated*/
            if (bLocalCc_regulation_speed_on_mux !=0)
            {
               CrsCtl_RVV_activated = 1;
            }
            else
            {
               CrsCtl_RVV_activated = 0;
            }
         /*CrsCtl_ACC_activated*/
            if (bLocalCc_acc_regulation_type_mux != 0)
            {
               CrsCtl_ACC_activated = 1;
            }
            else
            {
               CrsCtl_ACC_activated = 0;
            }
         }
         else
         {
            CrsCtl_RVV_activated = 0;
            CrsCtl_ACC_activated = 0;
         }
         /*CrsCtl_LVV_activated*/
         CrsCtl_LVV_activated = 0;
      }
   }
   /*CrsCtl_Off*/
   if (  (bLocalCc_limitation_speed_on_mux == 0)
      && (bLocalCc_regulation_speed_on_mux == 0)
      && (bLocalCc_acc_regulation_type_mux == 0)
      && (bLocalExt_bVSLimReq == 0)
      && (bLocalExt_bVSRegDVSRegReq == 0)
      && (u8LocalExt_spdVehVSCtlReq == 255))
   {
      CrsCtl_Off = 1;
   }
   else
   {
      CrsCtl_Off = 0;
   }
   /*VSCtl_bDgoElInfBsiDft*/
   if (  (CrsCtl_LVV_activated == 0)
      && (CrsCtl_RVV_activated == 0)
      && (CrsCtl_LVV_selected == 0)
      && (CrsCtl_RVV_selected == 0)
      && (CrsCtl_ACC_activated == 0)
      && (CrsCtl_ACC_selected == 0)
      && (CrsCtl_Off == 0))
   {
      VSCtl_bDgoElInfBsiDft = 1;
   }
   else
   {
      VSCtl_bDgoElInfBsiDft = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidLimSpdSpCoh                              */
/* !Description :  Cette fonction teste la cohérence de la consigne de vitesse*/
/*                 envoyée par la BSI dans le cas où la LVV est active et à   */
/*                 condition que l’ensemble des informations envoyées soient  */
/*                 cohérentes entre-elles                                     */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bVSLimReq;                                              */
/*  input uint8 Ext_spdVehVSCtlReq;                                           */
/*  input boolean Ext_bKeyOff;                                                */
/*  input boolean VSCtl_bMonRunElDft;                                         */
/*  input uint8 VSCtl_spdVSLimReqMinThd_C;                                    */
/*  input uint8 VSCtl_spdVSLimReqMaxThd_C;                                    */
/*  input uint8 Ext_spdVehReqVSLimMem;                                        */
/*  input uint8 VSCtl_spdVSLimReqDeltaMin1_C;                                 */
/*  input uint8 VSCtl_spdVSLimReqDeltaMax1_C;                                 */
/*  input boolean Ext_bVSLimReqMem;                                           */
/*  input boolean VSCtl_bDgoElConsDefDftVSLim;                                */
/*  input boolean VSCtl_bDgoElConsVarDftVSLim;                                */
/*  output boolean VSCtl_bDgoElConsDefDftVSLim;                               */
/*  output boolean VSCtl_bDgoElConsVarDftVSLim;                               */
/*  output boolean Ext_bVSLimReqMem;                                          */
/*  output uint8 Ext_spdVehReqVSLimMem;                                       */
/*  output boolean VSCtl_bSpdVehReqVSLimDft;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidLimSpdSpCoh(void)
{
   boolean bLocalExt_bVSLimReq;
   boolean bLocalExt_bKeyOff;
   uint8   u8LocalExt_spdVehVSCtlReq;
   uint16  u16LocalSom;
   sint16  s16LocalDiff;

   VEMS_vidGET(Ext_bVSLimReq, bLocalExt_bVSLimReq);
   VEMS_vidGET(Ext_spdVehVSCtlReq, u8LocalExt_spdVehVSCtlReq);
   VEMS_vidGET(Ext_bKeyOff, bLocalExt_bKeyOff);

   if (VSCtl_bMonRunElDft != 0)
   {
      if (bLocalExt_bVSLimReq != 0)
      {
         if (  (u8LocalExt_spdVehVSCtlReq < VSCtl_spdVSLimReqMinThd_C)
            || (u8LocalExt_spdVehVSCtlReq > VSCtl_spdVSLimReqMaxThd_C))
         {
            VSCtl_bDgoElConsDefDftVSLim = 1;
         }
         else
         {
            VSCtl_bDgoElConsDefDftVSLim = 0;
         }
         s16LocalDiff =
            (sint16)(Ext_spdVehReqVSLimMem - VSCtl_spdVSLimReqDeltaMin1_C);
         u16LocalSom =
            (uint16)(Ext_spdVehReqVSLimMem + VSCtl_spdVSLimReqDeltaMax1_C);
         if (  (Ext_bVSLimReqMem != 0)
            && (  ((sint16)u8LocalExt_spdVehVSCtlReq < s16LocalDiff)
               || ((uint16)u8LocalExt_spdVehVSCtlReq > u16LocalSom)))
         {
            VSCtl_bDgoElConsVarDftVSLim = 1;
         }
         else
         {
            VSCtl_bDgoElConsVarDftVSLim = 0;
         }
      }
      else
      {
         VSCtl_bDgoElConsDefDftVSLim = 0;
         VSCtl_bDgoElConsVarDftVSLim = 0;
      }
   }
   else
   {
      VSCtl_bDgoElConsDefDftVSLim = 0;
      VSCtl_bDgoElConsVarDftVSLim = 0;
   }

   if (bLocalExt_bKeyOff != 0)
   {
      Ext_bVSLimReqMem = 0;
      Ext_spdVehReqVSLimMem = 255;
   }
   else
   {
      Ext_bVSLimReqMem = bLocalExt_bVSLimReq;
      Ext_spdVehReqVSLimMem = u8LocalExt_spdVehVSCtlReq;
   }
   if (  (VSCtl_bDgoElConsDefDftVSLim != 0)
      || (VSCtl_bDgoElConsVarDftVSLim != 0))
   {
      VSCtl_bSpdVehReqVSLimDft = 1;
   }
   else
   {
      VSCtl_bSpdVehReqVSLimDft = 0;
   }
}
/*------------------------------- end of file --------------------------------*/