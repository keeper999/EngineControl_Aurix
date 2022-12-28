/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DmpVlvOplCmd                                            */
/* !Description     : DmpVlvOplCmd component.                                 */
/*                                                                            */
/* !Module          : DmpVlvOplCmd                                            */
/* !Description     : DUMP VALVE OPEN LOOP COMMAND SETPOINT                   */
/*                                                                            */
/* !File            : DmpVlvOplCmd_fct1.c                                     */
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
/*   1 / DmpVlvOplCmd_vidInitOutput                                           */
/*   2 / DmpVlvOplCmd_vidCalcCmdBModeBenchMod                                 */
/*   3 / DmpVlvOplCmd_vidDmpVlvOplCmdBenchMod                                 */
/*                                                                            */
/* !Reference   : V02 NT 10 01292 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/DMPVLVOPLCMD/DmpVlvOplCmd_fct1.c$*/
/* $Revision::   1.3      $$Author::   lthibaud       $$Date::   23 Feb 2011 $*/
/* $Author::   lthibaud                               $$Date::   23 Feb 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
  temp.mde producing this kind of error                                      */
#include "DmpVlvOplCmd.h"
#include "DmpVlvOplCmd_L.h"
#include "DmpVlvOplCmd_IM.h"
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvOplCmd_vidInitOutput                                 */
/* !Description :  The Dump valve open loop command setpoint is initialised by*/
/*                 a calibration at reset.                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 DmpVlvAct_rDmpVlvOplCmdSpIni_C;                              */
/*  input boolean DmpVlvAct_bDmpVlvOplCmdEna_C;                               */
/*  output uint16 DmpVlvAct_rDmpVlvOplCmdSp;                                  */
/*  output boolean DmpVlvAct_bDmpVlvOplCmdEna;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvOplCmd_vidInitOutput(void)
{
   uint16  u16Local_DmpVlvAct_rDmpVlvOplCmdSp;
   boolean ubLocal_DmpVlvAct_bDmpVlvOplCmdEna;

   u16Local_DmpVlvAct_rDmpVlvOplCmdSp =
      (uint16)MATHSRV_udtMIN(DmpVlvAct_rDmpVlvOplCmdSpIni_C, 32768);
   VEMS_vidSET(DmpVlvAct_rDmpVlvOplCmdSp, u16Local_DmpVlvAct_rDmpVlvOplCmdSp);

   ubLocal_DmpVlvAct_bDmpVlvOplCmdEna =
      (boolean)MATHSRV_udtMIN(DmpVlvAct_bDmpVlvOplCmdEna_C, 1);
   VEMS_vidSET(DmpVlvAct_bDmpVlvOplCmdEna, ubLocal_DmpVlvAct_bDmpVlvOplCmdEna);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvOplCmd_vidCalcCmdBModeBenchMod                       */
/* !Description :  The computation of the Dump valve open loop command bench  */
/*                 mode setpoint can be inhibited by an enable.               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DmpVlvOplCmd_vidDmpVlvOplCmdBenchMod();                  */
/*  input boolean DmpVlvAct_bDmpVlvOplCmdEna_C;                               */
/*  output boolean DmpVlvAct_bDmpVlvOplCmdEna;                                */
/*  output boolean DmpVlvAct_bDmpVlvOplCmdEna_C;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvOplCmd_vidCalcCmdBModeBenchMod(void)
{
   VEMS_vidSET(DmpVlvAct_bDmpVlvOplCmdEna, DmpVlvAct_bDmpVlvOplCmdEna_C);
   if(DmpVlvAct_bDmpVlvOplCmdEna_C != 0)
   {
      DmpVlvOplCmd_vidDmpVlvOplCmdBenchMod();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvOplCmd_vidDmpVlvOplCmdBenchMod                       */
/* !Description :  The method to command setpoint in bench mode is based on   */
/*                 the error observed (Pa) and engine speed.                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 DmpVlvAct_rDmpVlvOplCmdSp;                                   */
/*  input uint16 DmpVlvAct_rDmpVlvOplCmdSp_Prev;                              */
/*  input boolean DmpVlvAct_bOplCmdMapSel_C;                                  */
/*  input uint16 AirPres_pSpgPresSp;                                          */
/*  input uint16 Acq_spg_pres_measured;                                       */
/*  input uint16 Regime_moteur;                                               */
/*  input sint16 DmpVlvAct_ErrSpgPress;                                       */
/*  input uint16 DmpVlvAct_rOplCmd_pErrSpg_A[16];                             */
/*  input uint16 DmpVlvAct_rOplCmd_nEng_A[16];                                */
/*  input uint16 DmpVlvAct_rOplCmd_pErrSpg_nEng_M[16][16];                    */
/*  input uint16 DmpVlvAct_rOplCmdSp_C;                                       */
/*  input uint16 DmpVlvAct_max_pres_slew_C;                                   */
/*  input uint16 DmpVlvAct_min_pres_slew_C;                                   */
/*  output uint16 DmpVlvAct_rDmpVlvOplCmdSp_Prev;                             */
/*  output sint16 DmpVlvAct_ErrSpgPress;                                      */
/*  output uint16 DmpVlvAct_rDmpVlvOplCmdSp;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvOplCmd_vidDmpVlvOplCmdBenchMod(void)
{
   uint16 u16Local_SlewRate_Input;
   uint16 u16Local_DmpVlvAct_rDmpVlvOplCmdSp;
   uint16 u16Local_DmpVlvAct_ErrSpgPress;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16Local_Regime_moteur;
   uint16 u16Local_AirPres_pSpgPresSp;
   uint16 u16Local_Acq_spg_pres_measured;

   VEMS_vidGET(DmpVlvAct_rDmpVlvOplCmdSp, DmpVlvAct_rDmpVlvOplCmdSp_Prev);

   if (DmpVlvAct_bOplCmdMapSel_C != 0)
   {
      VEMS_vidGET(AirPres_pSpgPresSp, u16Local_AirPres_pSpgPresSp);
      VEMS_vidGET(Acq_spg_pres_measured, u16Local_Acq_spg_pres_measured);
      VEMS_vidGET(Regime_moteur, u16Local_Regime_moteur);

      /*The division below is a resolution calculation for Z=X-Y*/
      DmpVlvAct_ErrSpgPress = (sint16)((u16Local_AirPres_pSpgPresSp -
                                       u16Local_Acq_spg_pres_measured)/2);
      /* DmpVlvAct_ErrSpgPress is converted to unsigned by adding 32767 */
      u16Local_DmpVlvAct_ErrSpgPress =
         (uint16)(DmpVlvAct_ErrSpgPress + 32767);

      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(DmpVlvAct_rOplCmd_pErrSpg_A,
                                      u16Local_DmpVlvAct_ErrSpgPress,
                                      16);

      u16LocalParaY =
         MATHSRV_u16CalcParaIncAryU16(DmpVlvAct_rOplCmd_nEng_A,
                                      u16Local_Regime_moteur,
                                      16);

      u16Local_SlewRate_Input =
         MATHSRV_u16Interp2d (&DmpVlvAct_rOplCmd_pErrSpg_nEng_M[0][0],
                              u16LocalParaX,
                              u16LocalParaY,
                              16);
   }
   else
   {
      u16Local_SlewRate_Input = DmpVlvAct_rOplCmdSp_C;
   }

   u16Local_DmpVlvAct_rDmpVlvOplCmdSp =
      MATHSRV_u16SlewFilter(DmpVlvAct_rDmpVlvOplCmdSp_Prev,
                            u16Local_SlewRate_Input,
                            DmpVlvAct_max_pres_slew_C,
                            DmpVlvAct_min_pres_slew_C);

   u16Local_DmpVlvAct_rDmpVlvOplCmdSp =
      (uint16)MATHSRV_udtMIN(u16Local_DmpVlvAct_rDmpVlvOplCmdSp, 32768);

   VEMS_vidSET(DmpVlvAct_rDmpVlvOplCmdSp, u16Local_DmpVlvAct_rDmpVlvOplCmdSp);
}
