/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DMPVLVCMD                                               */
/* !Description     : DMPVLVCMD Component.                                    */
/*                                                                            */
/* !Module          : DMPVLVCMD                                               */
/* !Description     : DUMP-VALVE COMMAND AND DIAGNOSIS .                      */
/*                                                                            */
/* !File            : DMPVLVCMD_FCT1.C                                        */
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
/*   1 / DmpVlvCmd_vidInitEveRst                                              */
/*   2 / DmpVlvCmd_vidDmpVlvCmdAplication                                     */
/*   3 / DmpVlvCmd_vidDiagnostic                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6851423 / 01                                        */
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
#include "DMPVLVCMD.h"
#include "DMPVLVCMD_L.h"
#include "DMPVLVCMD_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvCmd_vidInitEveRst                                    */
/* !Description :  Initialisation des variables au reset                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean DmpVlvAct_bDgoLo_DmpVlvCmd;                                */
/*  output boolean DmpVlvAct_bMonRunLo_DmpVlvCmd;                             */
/*  output boolean DmpVlvAct_bDgoHi_DmpVlvCmd;                                */
/*  output boolean DmpVlvAct_bMonRunHi_DmpVlvCmd;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvCmd_vidInitEveRst(void)
{
   DmpVlvAct_bDgoLo_DmpVlvCmd = 0;
   DmpVlvAct_bMonRunLo_DmpVlvCmd = 0;
   DmpVlvAct_bDgoHi_DmpVlvCmd = 0;
   DmpVlvAct_bMonRunHi_DmpVlvCmd = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvCmd_vidDmpVlvCmdAplication                           */
/* !Description :  The Dump-Valve PWM frequency calibration is transmitted to */
/*                 the basic layer. Frequency is updated before PWM command   */
/*                 signal as the PWM command is dependent upon frequency.     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 DmpVlv_rDmpVlvCmdAppld;                                      */
/*  input uint16 DmpVlv_CmdDrvMin_C;                                          */
/*  input uint16 DmpVlv_CmdDrvMax_C;                                          */
/*  input uint16 PnmDmpVlvCmdFreq_C;                                          */
/*  output uint16 Commande_DmpVlv_pwm_rco;                                    */
/*  output uint16 Commande_DmpVlv_pwm_freq;                                   */
/*  output uint16 PnmDmpVlvCmdFreq_C;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvCmd_vidDmpVlvCmdAplication(void)
{
   uint16 u16LocalDmpVlv_rDmpVlvCmdAppld;


   VEMS_vidGET(DmpVlv_rDmpVlvCmdAppld, u16LocalDmpVlv_rDmpVlvCmdAppld);

   u16LocalDmpVlv_rDmpVlvCmdAppld =
      (uint16)MATHSRV_udtCLAMP(u16LocalDmpVlv_rDmpVlvCmdAppld,
                               DmpVlv_CmdDrvMin_C,
                               DmpVlv_CmdDrvMax_C);

   u16LocalDmpVlv_rDmpVlvCmdAppld =
      (uint16)MATHSRV_udtMIN(u16LocalDmpVlv_rDmpVlvCmdAppld, 32768);

   VEMS_vidSET(Commande_DmpVlv_pwm_rco, u16LocalDmpVlv_rDmpVlvCmdAppld);
   VEMS_vidSET(Commande_DmpVlv_pwm_freq, PnmDmpVlvCmdFreq_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvCmd_vidDiagnostic                                    */
/* !Description :  Dump Valve Diagnosis                                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_DmpVlvCmd;                                           */
/*  input boolean Dft_scg_DmpVlvCmd;                                          */
/*  input boolean Dft_scp_DmpVlvCmd;                                          */
/*  input boolean Dena_oc_DmpVlvCmd;                                          */
/*  input boolean Dena_scg_DmpVlvCmd;                                         */
/*  input boolean Dena_scp_DmpVlvCmd;                                         */
/*  output boolean DmpVlvAct_bDgoHi_DmpVlvCmd;                                */
/*  output boolean DmpVlvAct_bDgoLo_DmpVlvCmd;                                */
/*  output boolean DmpVlvAct_bMonRunLo_DmpVlvCmd;                             */
/*  output boolean DmpVlvAct_bMonRunHi_DmpVlvCmd;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvCmd_vidDiagnostic(void)
{
   boolean bLocalInhInDmpVlvCmd;
   boolean bLocalDft_oc_DmpVlvCmd;
   boolean bLocalDft_scg_DmpVlvCmd;
   boolean bLocalDft_scp_DmpVlvCmd;
   boolean bLocalDena_oc_DmpVlvCmd;
   boolean bLocalDena_scg_DmpVlvCmd;
   boolean bLocalDena_scp_DmpVlvCmd;


   bLocalInhInDmpVlvCmd = GDGAR_bGetFRM(FRM_FRM_INHDIAGDMPVLVCMD);
   VEMS_vidGET(Dft_oc_DmpVlvCmd, bLocalDft_oc_DmpVlvCmd);
   VEMS_vidGET(Dft_scg_DmpVlvCmd, bLocalDft_scg_DmpVlvCmd);
   VEMS_vidGET(Dft_scp_DmpVlvCmd, bLocalDft_scp_DmpVlvCmd);
   VEMS_vidGET(Dena_oc_DmpVlvCmd, bLocalDena_oc_DmpVlvCmd);
   VEMS_vidGET(Dena_scg_DmpVlvCmd, bLocalDena_scg_DmpVlvCmd);
   VEMS_vidGET(Dena_scp_DmpVlvCmd, bLocalDena_scp_DmpVlvCmd);

   DmpVlvAct_bDgoHi_DmpVlvCmd = bLocalDft_scp_DmpVlvCmd;

   if (  (bLocalDft_oc_DmpVlvCmd != 0)
      || (bLocalDft_scg_DmpVlvCmd != 0))
   {
      DmpVlvAct_bDgoLo_DmpVlvCmd = 1;
   }
   else
   {
      DmpVlvAct_bDgoLo_DmpVlvCmd = 0;
   }

   if (  (bLocalInhInDmpVlvCmd == 0)
      && (  (bLocalDena_oc_DmpVlvCmd != 0)
         || (bLocalDena_scg_DmpVlvCmd != 0)))
   {
      DmpVlvAct_bMonRunLo_DmpVlvCmd = 1;
   }
   else
   {
      DmpVlvAct_bMonRunLo_DmpVlvCmd = 0;
   }

   if (  (bLocalDena_scp_DmpVlvCmd != 0)
      && (bLocalInhInDmpVlvCmd == 0))
   {
      DmpVlvAct_bMonRunHi_DmpVlvCmd = 1;
   }
   else
   {
      DmpVlvAct_bMonRunHi_DmpVlvCmd = 0;
   }
}
/*------------------------------- end of file --------------------------------*/