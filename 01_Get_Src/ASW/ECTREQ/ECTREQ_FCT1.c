/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ECTREQ                                                  */
/* !Description     : ECTREQ Component                                        */
/*                                                                            */
/* !Module          : ECTREQ                                                  */
/* !Description     : Electronically Controlled Thermostat command and        */
/*                    diagnosis                                               */
/*                                                                            */
/* !File            : ECTREQ_FCT1.C                                           */
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
/*   1 / ECTREQ_vidInitOutput                                                 */
/*   2 / ECTREQ_vidInitialization                                             */
/*   3 / ECTREQ_vidTreatment                                                  */
/*   4 / ECTREQ_vidFiltBatt                                                   */
/*   5 / ECTREQ_vidCmdRCO_Cor                                                 */
/*   6 / ECTREQ_vidDrvCmd                                                     */
/*   7 / ECTREQ_vidDiagnosis                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6886129 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ECTREQ/ECTREQ_FCT1.C_v            $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ECTREQ.h"
#include "ECTREQ_L.h"
#include "ECTREQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECTREQ_vidInitOutput                                       */
/* !Description :  Fonction qui initialise les sorties des blocs dynamique et */
/*                 les sorties non initlialisée.                              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_uBattMes;                                                */
/*  output sint16 ECTREQ_s16Ext_uBattMesPrev;                                 */
/*  output uint16 Commande_ectdrv_pwm_rco;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECTREQ_vidInitOutput(void)
{
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   ECTREQ_s16Ext_uBattMesPrev =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
   VEMS_vidSET(Commande_ectdrv_pwm_rco, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECTREQ_vidInitialization                                   */
/* !Description :  In this block the initialization of the output command is  */
/*                 done and the PWM frequency is communicated to the  LDB.    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ECTReq_rSatMin_C;                                            */
/*  output uint16 PwrHw_rCtlECTReq_Drv;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECTREQ_vidInitialization(void)
{
   uint32  u32LocalPwrHw_rCtlECTReq_Drv;
   uint16  u16LocalPwrHw_rCtlECTReq_Drv;


   u32LocalPwrHw_rCtlECTReq_Drv = ECTReq_rSatMin_C * 10;
   u16LocalPwrHw_rCtlECTReq_Drv =
      (uint16) MATHSRV_udtMIN(u32LocalPwrHw_rCtlECTReq_Drv, 10000);
   VEMS_vidSET(PwrHw_rCtlECTReq_Drv, u16LocalPwrHw_rCtlECTReq_Drv);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECTREQ_vidTreatment                                        */
/* !Description :  In this block we make a treatment on the ECT command in    */
/*                 order to send to the hardware driver a corrected and       */
/*                 saturated value.                                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ECTREQ_vidFiltBatt();                                    */
/*  extf argret void ECTREQ_vidCmdRCO_Cor();                                  */
/*  extf argret void ECTREQ_vidDrvCmd();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECTREQ_vidTreatment(void)
{
   ECTREQ_vidFiltBatt();
   ECTREQ_vidCmdRCO_Cor();
   ECTREQ_vidDrvCmd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECTREQ_vidFiltBatt                                         */
/* !Description :  Here we make an average on the two last values of battery  */
/*                 voltage to use it for the correction.                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 ECTREQ_s16Ext_uBattMesPrev;                                  */
/*  output uint16 CoFan_uBattMes_Filtered;                                    */
/*  output sint16 ECTREQ_s16Ext_uBattMesPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECTREQ_vidFiltBatt(void)
{
   sint16  s16LocalExt_uBattMes;
   sint32  s32LocalSomme;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   s32LocalSomme = (sint32)(s16LocalExt_uBattMes + ECTREQ_s16Ext_uBattMesPrev);
   s32LocalSomme = s32LocalSomme / 2;
   CoFan_uBattMes_Filtered = (uint16)MATHSRV_udtCLAMP(s32LocalSomme, 0, 3200);
   ECTREQ_s16Ext_uBattMesPrev =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECTREQ_vidCmdRCO_Cor                                       */
/* !Description :  In this block the ECT command is first corrected with the  */
/*                 value of the filtered battery voltage and then saturated   */
/*                 between two values.                                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_06350_006.01                                     */
/*                 VEMS_E_11_06350_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 CoFan_uBattMes_Filtered;                                     */
/*  input uint8 ThMgt_rPwrECTReq;                                             */
/*  input uint8 ThMgt_rSpECTReqPosnActrTst;                                   */
/*  input boolean ThMgt_bECTActrTstInProgs;                                   */
/*  input uint8 Ext_uBattMes_Nom;                                             */
/*  input uint16 ECTReq_rSatMin_C;                                            */
/*  input uint16 ECTReq_rSatMax_C;                                            */
/*  input uint16 PwrHw_rCtlECTReq_Cor;                                        */
/*  output uint16 PwrHw_rCtlECTReq_Cor;                                       */
/*  output uint16 PwrHw_rCtlECTReq_Sat;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECTREQ_vidCmdRCO_Cor(void)
{
   boolean bLocalThMgt_bECTActrTstInProgs;
   uint8   u8LocalThMgt_rPwrECTReq;
   uint8   u8LocalThMgt_rSpECTReqPosActrTst;
   uint8   u8LocalSwitch;
   uint16  u16LocalPwrHw_rCtlECTReq_Sat;
   uint32  u32LocalRst;
   uint32  u32LocalECTReq_rSatMin_C;
   uint32  u32LocalECTReq_rSatMax_C;


   if (CoFan_uBattMes_Filtered != 0)
   {
      VEMS_vidGET(ThMgt_rPwrECTReq, u8LocalThMgt_rPwrECTReq);
      VEMS_vidGET( ThMgt_rSpECTReqPosnActrTst,
                   u8LocalThMgt_rSpECTReqPosActrTst);
      VEMS_vidGET(ThMgt_bECTActrTstInProgs, bLocalThMgt_bECTActrTstInProgs);

      if (bLocalThMgt_bECTActrTstInProgs != 0)
      {
         u8LocalSwitch = u8LocalThMgt_rSpECTReqPosActrTst;
      }
      else
      {
         u8LocalSwitch = u8LocalThMgt_rPwrECTReq;
      }

      u32LocalRst = (uint32)(  ( (Ext_uBattMes_Nom * u8LocalSwitch)
                               * 1000)
                            /  CoFan_uBattMes_Filtered);
      PwrHw_rCtlECTReq_Cor = (uint16)MATHSRV_udtMIN(u32LocalRst, 10000);
   }
   else
   {
      PwrHw_rCtlECTReq_Cor = 0;
   }

   u32LocalECTReq_rSatMin_C = (uint32)(ECTReq_rSatMin_C * 10);
   u32LocalECTReq_rSatMax_C = (uint32)(ECTReq_rSatMax_C * 10);
   u16LocalPwrHw_rCtlECTReq_Sat =
      (uint16)MATHSRV_udtCLAMP(PwrHw_rCtlECTReq_Cor,
                               u32LocalECTReq_rSatMin_C,
                               u32LocalECTReq_rSatMax_C);

   PwrHw_rCtlECTReq_Sat =
      (uint16)MATHSRV_udtMIN(u16LocalPwrHw_rCtlECTReq_Sat, 10000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECTREQ_vidDrvCmd                                           */
/* !Description :  Here we make a conversion of the corrected and saturated   */
/*                 ECT command and we send this final value to the  LDB.  The */
/*                 PWM request can be inverted using the calibration          */
/*                 ECTReq_bInvDuCy_C if it is required.                       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_06350_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ECTReq_rMaxDuCy_C;                                           */
/*  input uint16 ECTReq_rMinDuCy_C;                                           */
/*  input uint16 PwrHw_rCtlECTReq_Sat;                                        */
/*  input boolean ECTReq_bInvDuCy_C;                                          */
/*  input uint16 PwrHw_rCtlECTReq_Cnv;                                        */
/*  output uint16 PwrHw_rCtlECTReq_Cnv;                                       */
/*  output uint16 Commande_ectdrv_pwm_rco;                                    */
/*  output uint16 PwrHw_rCtlECTReq_Drv;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECTREQ_vidDrvCmd(void)
{
   uint16  u16LocalPwrHw_rCtlECTReq_Drv;
   uint16  u16LocaludtDutyCycle;
   uint16  u16LocalCtlECTReq_Cnv_DELTA;
   uint32  u32LocalCtlECTReq_Cnv_PROD;
   uint32  u32LocalCtlPmpReq_DrvMin;
   sint32  s32LocalPwrHw_rCtlECTReq_Drv;
   sint32  s32LocalPwrHw_rCtlECTReq_Cnv;


   if (ECTReq_rMaxDuCy_C > ECTReq_rMinDuCy_C)
   {
      u16LocalCtlECTReq_Cnv_DELTA = (uint16)( ECTReq_rMaxDuCy_C
                                            - ECTReq_rMinDuCy_C);

      u32LocalCtlECTReq_Cnv_PROD = (uint32)( PwrHw_rCtlECTReq_Sat
                                           * u16LocalCtlECTReq_Cnv_DELTA);

      u32LocalCtlPmpReq_DrvMin  = (uint32)(ECTReq_rMinDuCy_C * 10);

      s32LocalPwrHw_rCtlECTReq_Cnv  = (sint32)( u32LocalCtlPmpReq_DrvMin
                                              + (  ( u32LocalCtlECTReq_Cnv_PROD
                                                   + 500)
                                                / 1000));

      PwrHw_rCtlECTReq_Cnv =
         (uint16)MATHSRV_udtMIN(s32LocalPwrHw_rCtlECTReq_Cnv, 10000);
   }
   else
   {
      u16LocalCtlECTReq_Cnv_DELTA = (uint16)( ECTReq_rMinDuCy_C
                                            - ECTReq_rMaxDuCy_C);

      u32LocalCtlECTReq_Cnv_PROD = (uint32)( PwrHw_rCtlECTReq_Sat
                                           * u16LocalCtlECTReq_Cnv_DELTA);

      u32LocalCtlPmpReq_DrvMin  = (uint32)(ECTReq_rMinDuCy_C * 10);

      s32LocalPwrHw_rCtlECTReq_Cnv  = (sint32)( u32LocalCtlPmpReq_DrvMin
                                              - (  ( u32LocalCtlECTReq_Cnv_PROD
                                                   + 500)
                                                / 1000));
      PwrHw_rCtlECTReq_Cnv =
         (uint16)MATHSRV_udtCLAMP(s32LocalPwrHw_rCtlECTReq_Cnv, 0, 10000);
      /* QAC Warning : Msg(3:3356) : The different cases of this logical
         operation have been fully covered */
   }

   if (ECTReq_bInvDuCy_C != 0)
   {
      s32LocalPwrHw_rCtlECTReq_Drv = (sint32)(10000 - PwrHw_rCtlECTReq_Cnv);
      u16LocalPwrHw_rCtlECTReq_Drv = (uint16) s32LocalPwrHw_rCtlECTReq_Drv;
   }
   else
   {
      u16LocalPwrHw_rCtlECTReq_Drv = PwrHw_rCtlECTReq_Cnv;
   }

   u16LocaludtDutyCycle =
      (uint16)((uint32)(u16LocalPwrHw_rCtlECTReq_Drv * 2048) / 625);

   VEMS_vidSET(Commande_ectdrv_pwm_rco, u16LocaludtDutyCycle);
   VEMS_vidSET(PwrHw_rCtlECTReq_Drv, u16LocalPwrHw_rCtlECTReq_Drv);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECTREQ_vidDiagnosis                                        */
/* !Description :  In this block we make the electrical diagnosis of the ECT  */
/*                 command.                                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_06350_009.01                                     */
/*                 VEMS_E_11_06350_010.01                                     */
/*                 VEMS_E_11_06350_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Diag_elec_ectdrv;                                             */
/*  input boolean Dena_oc_ectcommand;                                         */
/*  input boolean Dena_scg_ectcommand;                                        */
/*  input boolean Dena_scw_ectcommand;                                        */
/*  input boolean Dft_scw_ectcommand;                                         */
/*  input boolean Dft_scg_ectcommand;                                         */
/*  input boolean Dft_oc_ectcommand;                                          */
/*  output boolean Dft_scw_ectcommand;                                        */
/*  output boolean Dft_scg_ectcommand;                                        */
/*  output boolean Dft_oc_ectcommand;                                         */
/*  output boolean Dena_oc_ectcommand;                                        */
/*  output boolean Dena_scg_ectcommand;                                       */
/*  output boolean Dena_scw_ectcommand;                                       */
/*  output boolean CoFan_bMonRunOc_ECTReq;                                    */
/*  output boolean CoFan_bMonRunScg_ECTReq;                                   */
/*  output boolean CoFan_bMonRunScp_ECTReq;                                   */
/*  output boolean CoFan_bDgoScp_ECTReq;                                      */
/*  output boolean CoFan_bDgoScg_ECTReq;                                      */
/*  output boolean CoFan_bDgoOc_ECTReq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECTREQ_vidDiagnosis(void)
{
   boolean bLocalInhDiag_rPwrECTReq;
   uint8   u8LocalDiag_elec_ectdrv;


   bLocalInhDiag_rPwrECTReq = GDGAR_bGetFRM(FRM_FRM_INHDIAG_RPWRECTREQ);
   VEMS_vidGET(Diag_elec_ectdrv, u8LocalDiag_elec_ectdrv);

   Dft_scw_ectcommand = (uint8)(u8LocalDiag_elec_ectdrv & 0x01);
   Dft_scg_ectcommand = (uint8)((u8LocalDiag_elec_ectdrv & 0x02) >> 1);
   Dft_oc_ectcommand = (uint8)((u8LocalDiag_elec_ectdrv & 0x04) >> 2);
   Dena_oc_ectcommand = (uint8)((u8LocalDiag_elec_ectdrv & 0x08) >> 3);
   Dena_scg_ectcommand = (uint8)((u8LocalDiag_elec_ectdrv & 0x10) >> 4);
   Dena_scw_ectcommand = (uint8)((u8LocalDiag_elec_ectdrv & 0x20) >> 5);

   if (bLocalInhDiag_rPwrECTReq == 0)
   {
      if (Dena_oc_ectcommand != 0)
      {
         CoFan_bMonRunOc_ECTReq = 1;
      }
      else
      {
         CoFan_bMonRunOc_ECTReq = 0;
      }

      if (Dena_scg_ectcommand != 0)
      {
         CoFan_bMonRunScg_ECTReq = 1;
      }
      else
      {
         CoFan_bMonRunScg_ECTReq = 0;
      }

      if (Dena_scw_ectcommand != 0)
      {
         CoFan_bMonRunScp_ECTReq = 1;
      }
      else
      {
         CoFan_bMonRunScp_ECTReq = 0;
      }
   }
   else
   {
      CoFan_bMonRunOc_ECTReq = 0;
      CoFan_bMonRunScp_ECTReq = 0;
      CoFan_bMonRunScg_ECTReq = 0;
   }
   CoFan_bDgoScp_ECTReq = Dft_scw_ectcommand;
   CoFan_bDgoScg_ECTReq = Dft_scg_ectcommand;
   CoFan_bDgoOc_ECTReq = Dft_oc_ectcommand;
}

/*-------------------------------- end of file -------------------------------*/