/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_FCT8.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidOutput_bTqReq                                       */
/*   2 / IFAIRSYSIGSYS_vidOutput_tOilChk                                      */
/*   3 / IFAIRSYSIGSYS_vidOutNotAvlBatMes                                     */
/*   4 / IFAIRSYSIGSYS_vidOutput_iBattMes                                     */
/*   5 / IFAIRSYSIGSYS_vidOutbElecltgr                                        */
/*   6 / IFAIRSYSIGSYS_vidOutBrakePedInp                                      */
/*   7 / IFAIRSYSIGSYS_vidOutputCrash                                         */
/*   8 / IFAIRSYSIGSYS_vidOutSlaveWkuReq                                      */
/*   9 / IFAIRSYSIGSYS_vidrapEngaMeca349                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
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
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_bTqReq                             */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 CoCha_bTqReq.                                              */
/* !Number      :  FCT8.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bASRReg;                                                */
/*  input boolean Ext_bESPReg;                                                */
/*  output boolean CoCha_bTqReq;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_bTqReq(void)
{
   /*F10_Output_bTqReq */
   boolean bLocalExt_bASRReg;
   boolean bLocalExt_bESPReg;


   VEMS_vidGET(Ext_bASRReg, bLocalExt_bASRReg);
   VEMS_vidGET(Ext_bESPReg, bLocalExt_bESPReg);

   if (  (bLocalExt_bASRReg != 0)
      || (bLocalExt_bESPReg != 0))
   {
      VEMS_vidSET(CoCha_bTqReq, 1);
   }
   else
   {
      VEMS_vidSET(CoCha_bTqReq, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_tOilChk                            */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Eng_bTOilChk.                                              */
/* !Number      :  FCT8.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Eng_bTOilChk;                                               */
/*  output boolean Ext_bTOilChk;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_tOilChk(void)
{
   /*F11_Output_tOilChk */
   boolean bLocalEng_bTOilChk;


   VEMS_vidGET(Eng_bTOilChk, bLocalEng_bTOilChk);
   VEMS_vidSET(Ext_bTOilChk, bLocalEng_bTOilChk);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutNotAvlBatMes                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_bNotAvl_iBattMes.                                      */
/* !Number      :  FCT8.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bNotAvl_noIncCurBattMes;                                */
/*  output boolean Ext_bNotAvl_iBattMes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutNotAvlBatMes(void)
{
   /*F01_Output_bNotAvl_iBattMes */
   boolean bLocalExt_bNotAvlIncCurBattMes;


   VEMS_vidGET(Ext_bNotAvl_noIncCurBattMes, bLocalExt_bNotAvlIncCurBattMes);
   VEMS_vidSET(Ext_bNotAvl_iBattMes, bLocalExt_bNotAvlIncCurBattMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_iBattMes                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_iBattMes.                                              */
/* !Number      :  FCT8.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint32 CAN_noIncCurBattMes;                                         */
/*  output sint32 Ext_iBattMes;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_iBattMes(void)
{
   /*F02_Output_iBattMes */
   sint32 s32LocalCAN_noIncCurBattMes;


   VEMS_vidGET(CAN_noIncCurBattMes, s32LocalCAN_noIncCurBattMes);
   s32LocalCAN_noIncCurBattMes = MATHSRV_udtCLAMP(s32LocalCAN_noIncCurBattMes,
                                                 -1536000,
                                                 1536000);
   VEMS_vidSET(Ext_iBattMes, s32LocalCAN_noIncCurBattMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutbElecltgr                              */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_bElecItgrReq.                                          */
/* !Number      :  FCT8.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  output boolean Ext_bElecItgrReq;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutbElecltgr(void)
{
   /* F20_Output_bElecltgr */
   boolean  bLocalDIAGCAN_bIntegElec;


   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegElec);
   VEMS_vidSET(Ext_bElecItgrReq, bLocalDIAGCAN_bIntegElec);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutBrakePedInp                            */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Bps_brake_pedal_input.                                     */
/* !Number      :  FCT8.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bBrkPedPrss;                                            */
/*  output boolean Bps_brake_pedal_input;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutBrakePedInp(void)
{
   /*F05_Output_brake_pedal_input */
   boolean bLocalExt_bBrkPedPrss;


   VEMS_vidGET(Ext_bBrkPedPrss, bLocalExt_bBrkPedPrss);
   VEMS_vidSET(Bps_brake_pedal_input, bLocalExt_bBrkPedPrss);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputCrash                               */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Crash_fps_mux.                                             */
/* !Number      :  FCT8.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bVehCollWarn;                                           */
/*  output boolean Crash_fps_mux;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputCrash(void)
{
   /* F21_Output_Crash */
   boolean  bLocalExt_bVehCollWarn;


   VEMS_vidGET(Ext_bVehCollWarn, bLocalExt_bVehCollWarn);
   VEMS_vidSET(Crash_fps_mux, bLocalExt_bVehCollWarn);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutSlaveWkuReq                            */
/* !Description :  Fonction appelé à la réception d'une trame CAN432.         */
/* !Number      :  FCT8.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bImmoUnlockWkuReq;                                      */
/*  input boolean Ext_bPrepIgEngWkuReq;                                       */
/*  input boolean Ext_bOilWkuReq;                                             */
/*  input boolean Ext_bStopEngCoWkuReq;                                       */
/*  input boolean ECU_bUcapWkuSt;                                             */
/*  input boolean Ext_bAcvSta;                                                */
/*  input uint8 CoReqVeh_stWkuMain;                                           */
/*  output uint8 Ext_bfSlavePtlWkuReq;                                        */
/*  output boolean Rcd_anticipation_adc_mux;                                  */
/*  output boolean Rcd_mes_huile_moteur_mux;                                  */
/*  output boolean Rcd_post_ventil_mot_mux;                                   */
/*  output boolean StaCtl_bAcvStaReq;                                         */
/*  output boolean Rcd_reveil_principal;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutSlaveWkuReq(void)
{
   /*F07_Output_bfSlavePtlWkuReq */
   boolean bLocalExt_bImmoUnlockWkuReq;
   boolean bLocalExt_bPrepIgEngWkuReq;
   boolean bLocalExt_bOilWkuReq;
   boolean bLocalExt_bStopEngCoWkuReq;
   boolean bLocalECU_bUcapWkuSt;
   boolean bLocalExt_bAcvSta;
   uint8   u8LocalExt_bfSlavePtlWkuReq;
   uint8   u8LocalCoReqVeh_stWkuMain;


   VEMS_vidGET(Ext_bImmoUnlockWkuReq, bLocalExt_bImmoUnlockWkuReq);
   VEMS_vidGET(Ext_bPrepIgEngWkuReq, bLocalExt_bPrepIgEngWkuReq);
   VEMS_vidGET(Ext_bOilWkuReq, bLocalExt_bOilWkuReq);
   VEMS_vidGET(Ext_bStopEngCoWkuReq, bLocalExt_bStopEngCoWkuReq);
   VEMS_vidGET(ECU_bUcapWkuSt, bLocalECU_bUcapWkuSt);


   u8LocalExt_bfSlavePtlWkuReq = 0x00;
   u8LocalExt_bfSlavePtlWkuReq =
      (uint8)(u8LocalExt_bfSlavePtlWkuReq | bLocalExt_bImmoUnlockWkuReq);
   u8LocalExt_bfSlavePtlWkuReq =
      (uint8)(u8LocalExt_bfSlavePtlWkuReq | (bLocalExt_bPrepIgEngWkuReq << 1));
   u8LocalExt_bfSlavePtlWkuReq =
      (uint8)(u8LocalExt_bfSlavePtlWkuReq | (bLocalExt_bOilWkuReq << 2));
   u8LocalExt_bfSlavePtlWkuReq =
      (uint8)(u8LocalExt_bfSlavePtlWkuReq | (bLocalExt_bStopEngCoWkuReq << 3));
   u8LocalExt_bfSlavePtlWkuReq =
      (uint8)(u8LocalExt_bfSlavePtlWkuReq | (bLocalECU_bUcapWkuSt << 4));
   VEMS_vidSET(Ext_bfSlavePtlWkuReq, u8LocalExt_bfSlavePtlWkuReq);

   VEMS_vidSET(Rcd_anticipation_adc_mux, bLocalExt_bImmoUnlockWkuReq);
   VEMS_vidSET(Rcd_mes_huile_moteur_mux, bLocalExt_bOilWkuReq);
   VEMS_vidSET(Rcd_post_ventil_mot_mux, bLocalExt_bStopEngCoWkuReq);

   VEMS_vidGET(Ext_bAcvSta, bLocalExt_bAcvSta);
   VEMS_vidSET(StaCtl_bAcvStaReq, bLocalExt_bAcvSta);

   VEMS_vidGET(CoReqVeh_stWkuMain, u8LocalCoReqVeh_stWkuMain);
   if (u8LocalCoReqVeh_stWkuMain == 2)
   {
      VEMS_vidSET(Rcd_reveil_principal, 1);
   }
   else
   {
      VEMS_vidSET(Rcd_reveil_principal, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidrapEngaMeca349                            */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Bv_rapport_enga_meca_rx349.                                */
/* !Number      :  FCT8.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 CoPt_noTarGear;                                               */
/*  input boolean CoPt_bSIP;                                                  */
/*  output uint8 GSI_noTarGear;                                               */
/*  output uint8 CoPt_stPhaGearShift;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidrapEngaMeca349(void)
{
   /*F09_Output_rapport_enga_meca_rx349 */
   boolean  bLocalCoPt_bSIP;
   uint8    u8LocalCoPt_noTarGear;
   sint8    s8LocalCoPt_noTarGear;


   VEMS_vidGET(CoPt_noTarGear, s8LocalCoPt_noTarGear);
   u8LocalCoPt_noTarGear =
      (uint8)MATHSRV_udtCLAMP(s8LocalCoPt_noTarGear, 0, 6);
   VEMS_vidSET(GSI_noTarGear, u8LocalCoPt_noTarGear);

   VEMS_vidGET(CoPt_bSIP, bLocalCoPt_bSIP);
   if (bLocalCoPt_bSIP != 0)
   {
      VEMS_vidSET(CoPt_stPhaGearShift, 1);
   }
   else
   {
      VEMS_vidSET(CoPt_stPhaGearShift, 0);
   }
}

/*-------------------------------- end of file -------------------------------*/