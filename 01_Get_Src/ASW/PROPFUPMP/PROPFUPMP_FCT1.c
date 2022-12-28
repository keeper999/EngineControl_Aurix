/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROPFUPMP                                               */
/* !Description     : PROPFUPMP component.                                    */
/*                                                                            */
/* !Module          : PROPFUPMP                                               */
/* !Description     : PROPORTIONAL FUEL PUMP COMMAND AND DIAGNOSIS            */
/*                                                                            */
/* !File            : PROPFUPMP_FCT1.C                                        */
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
/*   1 / PROPFUPMP_vidInit                                                    */
/*   2 / PROPFUPMP_vidInitOutput                                              */
/*   3 / PROPFUPMP_vidCmdPropFuPmp                                            */
/*   4 / PROPFUPMP_vidPropFuPmp_DiagHw                                        */
/*   5 / PROPFUPMP_vidDiagPropFuPmp                                           */
/*   6 / PROPFUPMP_vidPropFuPmpDiag_Acq                                       */
/*   7 / PROPFUPMP_vidPropfuPmpDiag_Conv                                      */
/*   8 / PROPFUPMP_vidPropFuPmpDiag_Diag                                      */
/*   9 / PROPFUPMP_vidDiag_rSt                                                */
/*   10 / PROPFUPMP_vidPropFuPmp_Sel                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6562300 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/PROPFUPMP/PROPFUPMP_FCT1.C_v      $*/
/* $Revision::   1.0      $$Author::   hmelloul       $$Date::   02 Jun 2014 $*/
/* $Author::   hmelloul                               $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "PROPFUPMP.h"
#include "PROPFUPMP_L.h"
#include "PROPFUPMP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidInit                                          */
/* !Description :  The following outputs Ext_rFlowFuTnkPmp and                */
/*                 Ext_stDftFuTnkPmp are initialized at event reset. The      */
/*                 command frequency of proportional fuel pump is sent to BSW */
/*                 only at reset event of ECU.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 FuPmp_rFlowFuTnkPmpIni_C;                                    */
/*  output uint16 Ext_rFlowFuTnkPmp;                                          */
/*  output uint16 Commande_pompe_ess_pwm;                                     */
/*  output uint8 Ext_stDftFuTnkPmp;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidInit(void)
{
   uint16 u16LocalFuPmp_rFlowFuTnkPmpIni_C;


   u16LocalFuPmp_rFlowFuTnkPmpIni_C =
      (uint16)MATHSRV_udtMIN(FuPmp_rFlowFuTnkPmpIni_C, 32768);
   VEMS_vidSET(Ext_rFlowFuTnkPmp, u16LocalFuPmp_rFlowFuTnkPmpIni_C);
   VEMS_vidSET(Commande_pompe_ess_pwm, u16LocalFuPmp_rFlowFuTnkPmpIni_C);
   VEMS_vidSET(Ext_stDftFuTnkPmp, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidInitOutput                                    */
/* !Description :  initialisation des sorties.                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean PROPFUPMP_bPwrRly_rCtl_Prev;                               */
/*  output boolean PROPFUPMP_bTimeout;                                        */
/*  output uint8 PROPFUPMP_u8TimerCpt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidInitOutput(void)
{
   PROPFUPMP_bPwrRly_rCtl_Prev = 0;
   PROPFUPMP_bTimeout = 0;
   PROPFUPMP_u8TimerCpt = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidCmdPropFuPmp                                  */
/* !Description :  The PWM signal request is linearized then sent to the BSW. */
/*                 If the actuator test is in progress, then it’s the actuator*/
/*                 test set point value which is sent to the BSW.             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_006.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 FTPCtl_rFlowFuTnkPmp;                                        */
/*  input uint16 FuPmp_rSpPosnActrTst;                                        */
/*  input boolean FuPmp_bActrTstInProgs;                                      */
/*  input uint16 Ext_FlowFuTnkPmp_A[3];                                       */
/*  input uint16 FuPmp_rFlowFuTnkPmp;                                         */
/*  input uint16 Ext_FlowFuTnkPmp_T[3];                                       */
/*  output uint16 FuPmp_rFlowFuTnkPmp;                                        */
/*  output uint16 Ext_rFlowFuTnkPmp;                                          */
/*  output uint16 Commande_pompe_ess_pwm;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidCmdPropFuPmp(void)
{
   boolean bLocalFuPmp_bActrTstInProgs;
   uint16  u16LocalFuPmp_rSpPosnActrTst;
   uint16  u16LocalFTPCtl_rFlowFuTnkPmp;
   uint16  u16LocalExt_rFlowFuTnkPmp;
   uint16  u16LocalFuPmp_rFlowFuTnkPmp;
   uint16  u16LocalCalcPara;


   VEMS_vidGET(FTPCtl_rFlowFuTnkPmp, u16LocalFTPCtl_rFlowFuTnkPmp);
   VEMS_vidGET(FuPmp_rSpPosnActrTst, u16LocalFuPmp_rSpPosnActrTst);
   VEMS_vidGET(FuPmp_bActrTstInProgs, bLocalFuPmp_bActrTstInProgs);


   if (bLocalFuPmp_bActrTstInProgs != 0)
   {
      u16LocalFuPmp_rFlowFuTnkPmp = u16LocalFuPmp_rSpPosnActrTst;
   }
   else
   {
      u16LocalFuPmp_rFlowFuTnkPmp = u16LocalFTPCtl_rFlowFuTnkPmp;
   }

   FuPmp_rFlowFuTnkPmp = (uint16)MATHSRV_udtMIN(u16LocalFuPmp_rFlowFuTnkPmp,
                                                1000);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Ext_FlowFuTnkPmp_A,
                                                   FuPmp_rFlowFuTnkPmp,
                                                   3);

   u16LocalExt_rFlowFuTnkPmp = MATHSRV_u16Interp1d(Ext_FlowFuTnkPmp_T,
                                                   u16LocalCalcPara);

   u16LocalExt_rFlowFuTnkPmp = (uint16)MATHSRV_udtMIN(u16LocalExt_rFlowFuTnkPmp,
                                                      32768);

   VEMS_vidSET(Ext_rFlowFuTnkPmp, u16LocalExt_rFlowFuTnkPmp);
   VEMS_vidSET(Commande_pompe_ess_pwm, u16LocalExt_rFlowFuTnkPmp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidPropFuPmp_DiagHw                              */
/* !Description :  The driver electrical diagnosis results are directly sent  */
/*                 by the BSW. The authorization flow for the electrical      */
/*                 diagnosis are set to 1, if there is no diagnosis inhibition*/
/*                 requested and if the power command relay is closed.        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean PwrRly_rCtl;                                                */
/*  input boolean Dft_oc_pompe_ess_pwm;                                       */
/*  input boolean Dena_oc_pompe_ess_pwm;                                      */
/*  input boolean Dft_scg_pompe_ess_pwm;                                      */
/*  input boolean Dena_scg_pompe_ess_pwm;                                     */
/*  input boolean Dft_scp_pompe_ess_pwm;                                      */
/*  input boolean Dena_scp_pompe_ess_pwm;                                     */
/*  output boolean FuPmp_bDgoOc_PropFuPmp;                                    */
/*  output boolean FuPmp_bDgoScg_PropFuPmp;                                   */
/*  output boolean FuPmp_bDgoScp_PropFuPmp;                                   */
/*  output boolean FuPmp_bMonRunOc_PropFuPmp;                                 */
/*  output boolean FuPmp_bMonRunScg_PropFuPmp;                                */
/*  output boolean FuPmp_bMonRunScp_PropFuPmp;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidPropFuPmp_DiagHw(void)
{
   boolean bLocalInhDiag_PropFuPmp;
   boolean bLocalPwrRly_rCtl;
   boolean bLocalDft_oc_pompe_ess_pwm;
   boolean bLocalDena_oc_pompe_ess_pwm;
   boolean bLocalDft_scg_pompe_ess_pwm;
   boolean bLocalDena_scg_pompe_ess_pwm;
   boolean bLocalDft_scp_pompe_ess_pwm;
   boolean bLocalDena_scp_pompe_ess_pwm;


   bLocalInhDiag_PropFuPmp = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PROPFUPMP);
   VEMS_vidGET(PwrRly_rCtl, bLocalPwrRly_rCtl);
   VEMS_vidGET(Dft_oc_pompe_ess_pwm, bLocalDft_oc_pompe_ess_pwm);
   VEMS_vidGET(Dena_oc_pompe_ess_pwm, bLocalDena_oc_pompe_ess_pwm);
   VEMS_vidGET(Dft_scg_pompe_ess_pwm, bLocalDft_scg_pompe_ess_pwm);
   VEMS_vidGET(Dena_scg_pompe_ess_pwm, bLocalDena_scg_pompe_ess_pwm);
   VEMS_vidGET(Dft_scp_pompe_ess_pwm, bLocalDft_scp_pompe_ess_pwm);
   VEMS_vidGET(Dena_scp_pompe_ess_pwm, bLocalDena_scp_pompe_ess_pwm);
   FuPmp_bDgoOc_PropFuPmp = bLocalDft_oc_pompe_ess_pwm;
   FuPmp_bDgoScg_PropFuPmp = bLocalDft_scg_pompe_ess_pwm;
   FuPmp_bDgoScp_PropFuPmp = bLocalDft_scp_pompe_ess_pwm;
   if ((bLocalInhDiag_PropFuPmp == 0) && (bLocalPwrRly_rCtl != 0))
   {
      if (bLocalDena_oc_pompe_ess_pwm != 0)
      {
         FuPmp_bMonRunOc_PropFuPmp = 1;
      }
      else
      {
         FuPmp_bMonRunOc_PropFuPmp = 0;
      }
      if (bLocalDena_scg_pompe_ess_pwm != 0)
      {
         FuPmp_bMonRunScg_PropFuPmp = 1;
      }
      else
      {
         FuPmp_bMonRunScg_PropFuPmp = 0;
      }
      if (bLocalDena_scp_pompe_ess_pwm != 0)
      {
         FuPmp_bMonRunScp_PropFuPmp = 1;
      }
      else
      {
         FuPmp_bMonRunScp_PropFuPmp = 0;
      }
   }
   else
   {
      FuPmp_bMonRunOc_PropFuPmp = 0;
      FuPmp_bMonRunScg_PropFuPmp = 0;
      FuPmp_bMonRunScp_PropFuPmp = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidDiagPropFuPmp                                 */
/* !Description :  According to the PWM and the frequency of the diagnosis    */
/*                 signal of proportional fuel pump sent by the BSW, we       */
/*                 determine the pump status.                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROPFUPMP_vidPropFuPmpDiag_Acq();                        */
/*  extf argret void PROPFUPMP_vidPropfuPmpDiag_Conv();                       */
/*  extf argret void PROPFUPMP_vidPropFuPmpDiag_Diag();                       */
/*  extf argret void PROPFUPMP_vidPropFuPmp_Sel();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidDiagPropFuPmp(void)
{
   PROPFUPMP_vidPropFuPmpDiag_Acq();
   PROPFUPMP_vidPropfuPmpDiag_Conv();
   PROPFUPMP_vidPropFuPmpDiag_Diag();
   PROPFUPMP_vidPropFuPmp_Sel();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidPropFuPmpDiag_Acq                             */
/* !Description :  The BSW send the value of PWM and the frequency of the     */
/*                 diagnosis signal of the proportional fuel pump.            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acqui_diag_pompe_ess_pwd_rco;                                */
/*  input uint32 Acqui_diag_pompe_ess_pwd_per;                                */
/*  output uint32 Ext_tiPerStFlowFuTnkPmp;                                    */
/*  output uint16 Ext_rStFlowFuTnkPmp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidPropFuPmpDiag_Acq(void)
{
   uint16 u16LocalAcqui_diag_rco;
   uint32 u32LocalAcqui_diag_per;
   uint32 u32LocalExt_tiPerStFlowFuTnkPmp;
   uint32 u32LocalExt_rStFlowFuTnkPmp;


   VEMS_vidGET(Acqui_diag_pompe_ess_pwd_rco, u16LocalAcqui_diag_rco);
   VEMS_vidGET(Acqui_diag_pompe_ess_pwd_per, u32LocalAcqui_diag_per);

   u32LocalExt_tiPerStFlowFuTnkPmp = u32LocalAcqui_diag_per / 100;
   Ext_tiPerStFlowFuTnkPmp =
      MATHSRV_udtMIN(u32LocalExt_tiPerStFlowFuTnkPmp, 100000);
   u32LocalExt_rStFlowFuTnkPmp =
      (uint32)(((u16LocalAcqui_diag_rco * 125) + 2048) / 4096);
   Ext_rStFlowFuTnkPmp =
      (uint16)MATHSRV_udtMIN(u32LocalExt_rStFlowFuTnkPmp, 1000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidPropfuPmpDiag_Conv                            */
/* !Description :  The proportional fuel pump status is built from the PWM    */
/*                 sent by the MJP module using the following cartography.    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_rStFlowFuTnkPmp;                                         */
/*  output uint8 Ext_stFlowFuTnkPmp_Conv;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidPropfuPmpDiag_Conv(void)
{
   boolean bLocalMark;


   bLocalMark = 0;

   if (  (Ext_rStFlowFuTnkPmp <= 20)
      || (  (Ext_rStFlowFuTnkPmp >= 980)
         && (Ext_rStFlowFuTnkPmp <= 1000)))
   {
      Ext_stFlowFuTnkPmp_Conv = 8;
   }
   else
   {
      if (  (Ext_rStFlowFuTnkPmp >= 70)
         && (Ext_rStFlowFuTnkPmp <= 150))
      {
         Ext_stFlowFuTnkPmp_Conv = 0;
      }
      else
      {
         if (  (Ext_rStFlowFuTnkPmp >= 180)
            && (Ext_rStFlowFuTnkPmp <= 260))
         {
            Ext_stFlowFuTnkPmp_Conv = 1;
         }
         else
         {
            if (  (Ext_rStFlowFuTnkPmp >= 290)
               && (Ext_rStFlowFuTnkPmp <= 370))
            {
               Ext_stFlowFuTnkPmp_Conv = 2;
            }
            else
            {
               if (  (Ext_rStFlowFuTnkPmp >= 400)
                  && (Ext_rStFlowFuTnkPmp <= 480))
               {
                  Ext_stFlowFuTnkPmp_Conv = 3;
               }
               else
               {
                  if (  (Ext_rStFlowFuTnkPmp >= 510)
                     && (Ext_rStFlowFuTnkPmp <= 590))
                  {
                     Ext_stFlowFuTnkPmp_Conv = 4;
                  }
                  else
                  {
                     bLocalMark = 1;
                  }
               }
            }
         }
      }
   }
   if (bLocalMark != 0)
   {
      if (  (Ext_rStFlowFuTnkPmp >= 620)
         && (Ext_rStFlowFuTnkPmp <= 700))
      {
         Ext_stFlowFuTnkPmp_Conv = 5;
      }
      else
      {
         if (  (Ext_rStFlowFuTnkPmp >= 730)
            && (Ext_rStFlowFuTnkPmp <= 810))
         {
            Ext_stFlowFuTnkPmp_Conv = 6;
         }
         else
         {
            if (  (Ext_rStFlowFuTnkPmp >= 840)
               && (Ext_rStFlowFuTnkPmp <= 920))
            {
               Ext_stFlowFuTnkPmp_Conv = 7;
            }
            else
            {
               Ext_stFlowFuTnkPmp_Conv = 9;
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidPropFuPmpDiag_Diag                            */
/* !Description :  The diagnosis are authorized if there is no inhibition     */
/*                 requested and if the power command relay is closed since a */
/*                 calibrated time.                                           */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PROPFUPMP_vidDiag_rSt();                                 */
/*  input boolean PwrRly_rCtl;                                                */
/*  input boolean PROPFUPMP_bPwrRly_rCtl_Prev;                                */
/*  input uint8 FuPmp_tiInhDiag_C;                                            */
/*  input uint8 PROPFUPMP_u8TimerCpt;                                         */
/*  input boolean PROPFUPMP_bTimeout;                                         */
/*  output uint8 PROPFUPMP_u8TimerCpt;                                        */
/*  output boolean PROPFUPMP_bTimeout;                                        */
/*  output boolean PROPFUPMP_bPwrRly_rCtl_Prev;                               */
/*  output boolean FuPmp_bMonRunMap_PropFuPmp;                                */
/*  output boolean FuPmp_bMonRunGravScp_PropFuPmp;                            */
/*  output boolean FuPmp_bMonRunFrq_PropFuPmp;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidPropFuPmpDiag_Diag(void)
{
   boolean bLocalInhDiag_PropFuPmp;
   boolean bLocalPwrRly_rCtl;


   bLocalInhDiag_PropFuPmp = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PROPFUPMP);
   VEMS_vidGET(PwrRly_rCtl, bLocalPwrRly_rCtl);


   if (  (PROPFUPMP_bPwrRly_rCtl_Prev == 0)
      && (bLocalPwrRly_rCtl != 0))
   {
      PROPFUPMP_u8TimerCpt = (uint8)MATHSRV_udtMIN(FuPmp_tiInhDiag_C, 100);
      if (PROPFUPMP_u8TimerCpt == 0)
      {
         PROPFUPMP_bTimeout = 1;
      }
      else
      {
         PROPFUPMP_bTimeout = 0;
      }
   }
   else
   {
      if (PROPFUPMP_u8TimerCpt > 0)
      {
         PROPFUPMP_u8TimerCpt = (uint8)(PROPFUPMP_u8TimerCpt - 1);
         if (PROPFUPMP_u8TimerCpt == 0)
         {
            PROPFUPMP_bTimeout = 1;
         }
         else
         {
            PROPFUPMP_bTimeout = 0;
         }
      }
   }

   PROPFUPMP_bPwrRly_rCtl_Prev = bLocalPwrRly_rCtl;

   if (	(bLocalInhDiag_PropFuPmp == 0)
      && (bLocalPwrRly_rCtl != 0)
      && (PROPFUPMP_bTimeout != 0))
   {
      PROPFUPMP_vidDiag_rSt();
      FuPmp_bMonRunMap_PropFuPmp = 1;
      FuPmp_bMonRunGravScp_PropFuPmp = 1;
      FuPmp_bMonRunFrq_PropFuPmp = 1;
   }
   else
   {
      FuPmp_bMonRunMap_PropFuPmp = 0;
      FuPmp_bMonRunGravScp_PropFuPmp = 0;
      FuPmp_bMonRunFrq_PropFuPmp = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidDiag_rSt                                      */
/* !Description :  The diagnosis results depend on the status of the PWM and  */
/*                 on the frequency of diagnosis signal.                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_004.03                                     */
/*                 VEMS_E_11_03107_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Ext_stFlowFuTnkPmp_Conv;                                      */
/*  input uint32 Ext_tiPerStFlowFuTnkPmp;                                     */
/*  input uint8 Ext_frqStFlowFuTnkPmp;                                        */
/*  output boolean FuPmp_bDgoGravScp_PropFuPmp;                               */
/*  output boolean FuPmp_bDgoMap_PropFuPmp;                                   */
/*  output uint8 Ext_frqStFlowFuTnkPmp;                                       */
/*  output boolean FuPmp_bDgoFrq_PropFuPmp;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidDiag_rSt(void)
{
   uint32 u32LocalCalc;


   if (Ext_stFlowFuTnkPmp_Conv == 7)
   {
      FuPmp_bDgoGravScp_PropFuPmp = 1;
   }
   else
   {
      FuPmp_bDgoGravScp_PropFuPmp = 0;
   }

   if (Ext_stFlowFuTnkPmp_Conv == 9)
   {
      FuPmp_bDgoMap_PropFuPmp = 1;
   }
   else
   {
      FuPmp_bDgoMap_PropFuPmp = 0;
   }

   if (Ext_tiPerStFlowFuTnkPmp != 0)
   {
      u32LocalCalc = (1000000 / Ext_tiPerStFlowFuTnkPmp);
      Ext_frqStFlowFuTnkPmp = (uint8)MATHSRV_udtMIN(u32LocalCalc, 200);
   }
   else
   {
      Ext_frqStFlowFuTnkPmp = 0;
   }

   if (	(Ext_frqStFlowFuTnkPmp < 70)
      || (Ext_frqStFlowFuTnkPmp > 130))
   {
      FuPmp_bDgoFrq_PropFuPmp = 1;
   }
   else
   {
      FuPmp_bDgoFrq_PropFuPmp = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidPropFuPmp_Sel                                 */
/* !Description :  If a failure is detected on the diagnosis signal, the pump */
/*                 status is frozen to its last valid value. If a failure is  */
/*                 confirmed, the status is set to a recovery value.          */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_03107_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean FuPmp_bDgoFrq_PropFuPmp;                                    */
/*  input boolean FuPmp_bDgoMap_PropFuPmp;                                    */
/*  input boolean FuPmp_bDgoGravScp_PropFuPmp;                                */
/*  input uint8 Ext_stFlowFuTnkPmp_Conv;                                      */
/*  input uint8 Ext_stDftFuTnkPmp;                                            */
/*  input uint8 Ext_stDftFuPmpRcv_C;                                          */
/*  input uint8 Ext_stDftFuTnkPmpMem;                                         */
/*  output uint8 Ext_stDftFuTnkPmpMem;                                        */
/*  output uint8 Ext_stDftFuTnkPmp;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidPropFuPmp_Sel(void)
{
   boolean bLocalAcvDftMod_PropFuPmp;
   boolean bLocalInhDiag_PropFuPmp;
   uint8   u8LocalExt_stDftFuTnkPmp;


   bLocalAcvDftMod_PropFuPmp = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_PROPFUPMP);
   bLocalInhDiag_PropFuPmp = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PROPFUPMP);

   if (  (FuPmp_bDgoFrq_PropFuPmp == 0)
      && (FuPmp_bDgoMap_PropFuPmp == 0)
      && (FuPmp_bDgoGravScp_PropFuPmp == 0)
      && (bLocalInhDiag_PropFuPmp == 0))
   {
      Ext_stDftFuTnkPmpMem = (uint8)MATHSRV_udtMIN(Ext_stFlowFuTnkPmp_Conv, 9);
   }
   else
   {
      VEMS_vidGET(Ext_stDftFuTnkPmp, u8LocalExt_stDftFuTnkPmp);
      Ext_stDftFuTnkPmpMem = (uint8)MATHSRV_udtMIN(u8LocalExt_stDftFuTnkPmp, 9);
   }
   if (bLocalAcvDftMod_PropFuPmp != 0)
   {
      u8LocalExt_stDftFuTnkPmp = Ext_stDftFuPmpRcv_C;
   }
   else
   {
      u8LocalExt_stDftFuTnkPmp = Ext_stDftFuTnkPmpMem;
   }
   u8LocalExt_stDftFuTnkPmp = (uint8)MATHSRV_udtMIN(u8LocalExt_stDftFuTnkPmp,8);
   VEMS_vidSET(Ext_stDftFuTnkPmp, u8LocalExt_stDftFuTnkPmp);
}

/*-------------------------------- end of file -------------------------------*/