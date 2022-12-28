/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COFANCMDDIAG                                            */
/* !Description     : COFANCMDDIAG component.                                 */
/*                                                                            */
/* !Module          : COFANCMDDIAG                                            */
/* !Description     : COMMANDE ET DIAGNOSTICS DES GMV.                        */
/*                                                                            */
/* !File            : COFANCMDDIAG_FCT4.C                                     */
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
/*   1 / COFANCMDDIAG_vidCofanB2VNullTran                                     */
/*   2 / COFANCMDDIAG_vidCofanB2WaitTran                                      */
/*   3 / COFANCMDDIAG_vidCofanB2_PVTran                                       */
/*   4 / COFANCMDDIAG_vidCofanB2_GVTran                                       */
/*   5 / COFANCMDDIAG_vidCofanB2_DEFAUT                                       */
/*   6 / COFANCMDDIAG_vidCofanc_Ro_T                                          */
/*   7 / COFANCMDDIAG_vidCofanc_Rfao_T                                        */
/*   8 / COFANCMDDIAG_vidCofanc_Gmvp_T                                        */
/*   9 / COFANCMDDIAG_vidCofanc_Rfgmvp_T                                      */
/*   10 / COFANCMDDIAG_vidCofanc_Rf_T                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6722439 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/COFANCMDDIAG/COFANCMDDIAG_FCT4.C_v$*/
/* $Revision::   1.15     $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "COFANCMDDIAG_IM.H"
#include "COFANCMDDIAG_L.H"
#include "COFANCMDDIAG.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanB2VNullTran                           */
/* !Description :  fonction de transition de l'état COFANB2_VNULLE            */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_rFanB2LoSpdHiThd_C;                                     */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output boolean CoFan_bAcvCoFan1Cmd;                                       */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output boolean FanCtl_bReqIncVoltMin;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanB2VNullTran(void)
{
   boolean bLocalAcvErrSpdFanAppldB2;
   boolean bLocalAcvLoSpdFanAppldB2;
   boolean bLocalAcvHiSpdFanAppldB2;
   boolean bLocalAcvNoSpdFanAppldB2;


   bLocalAcvErrSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDB2);
   bLocalAcvLoSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVLOSPDFANAPPLDB2);
   bLocalAcvHiSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDB2);
   bLocalAcvNoSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDB2);
   if (bLocalAcvLoSpdFanAppldB2 != 0)
   {
      VEMS_vidSET(Cf_speed_for_air, 25);
      CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
   }
   else
   {
      if (bLocalAcvErrSpdFanAppldB2 != 0)
      {
         VEMS_vidSET(Cf_speed_for_air, 63);
         CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
      }
      else
      {
         if (bLocalAcvHiSpdFanAppldB2 != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 50);
            CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
         }
         else
         {
            if(bLocalAcvNoSpdFanAppldB2 != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 0);
               CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
            }
            else
            {
               if (CoFan_rSpdFanPred >= CoFan_rFanB2LoSpdHiThd_C)
               {
                  CoFan_stAcvCoFanCmd = COFANB2_ATTENTE;
                  CoFan_bAcvCoFan1Cmd = 0;
                  CoFan_bAcvCoFan2Cmd = 0;
                  VEMS_vidSET(Cf_speed_for_air, 0);
                  VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
               }
            }
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanB2WaitTran                            */
/* !Description :  Fonction de transition de l'état COFANB2_ATTENTE           */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqRes_bCdnFanRes;                                           */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_rFanB2LoSpdHiThd_C;                                     */
/*  input uint16 CoFan_tiDlyTranActrProt;                                     */
/*  input uint16 CoFan_tiHldDlyLoSpd_C;                                       */
/*  input uint8 CoFan_rFanB2LoSpdLoThd_C;                                     */
/*  input uint8 CoFan_tiTqDly_C;                                              */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output boolean CoFan_bAcvCoFan1Cmd;                                       */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output boolean FanCtl_bReqIncVoltMin;                                     */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanB2WaitTran(void)
{
   boolean bLocalAcvErrSpdFanAppldB2;
   boolean bLocalAcvLoSpdFanAppldB2;
   boolean bLocalAcvHiSpdFanAppldB2;
   boolean bLocalAcvNoSpdFanAppldB2;
   boolean bLocalTqRes_bCdnFanRes;
   sint32  s32LocalTranActrProt;


   bLocalAcvErrSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDB2);
   bLocalAcvLoSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVLOSPDFANAPPLDB2);
   bLocalAcvHiSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDB2);
   bLocalAcvNoSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDB2);
   if (bLocalAcvLoSpdFanAppldB2 != 0)
   {
      VEMS_vidSET(Cf_speed_for_air, 25);
      CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
   }
   else
   {
      if (bLocalAcvErrSpdFanAppldB2 != 0)
      {
         VEMS_vidSET(Cf_speed_for_air, 63);
         CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;

      }
      else
      {
         if (bLocalAcvHiSpdFanAppldB2 != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 50);
            CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
         }
         else
         {
            if (bLocalAcvNoSpdFanAppldB2 != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 0);
               CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
            }
            else
            {
               VEMS_vidGET(TqRes_bCdnFanRes , bLocalTqRes_bCdnFanRes );
               if (  (CoFan_rSpdFanPred >= CoFan_rFanB2LoSpdHiThd_C)
                  && (CoFan_tiDlyTranActrProt <= 1)
                  && (bLocalTqRes_bCdnFanRes == 1))
               {
                  CoFan_stAcvCoFanCmd = COFANB2_PV;
                  CoFan_bAcvCoFan1Cmd = 0;
                  CoFan_bAcvCoFan2Cmd = 1;
                  VEMS_vidSET(Cf_speed_for_air, 25);
                  VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
                  CoFan_tiDlyTranActrProt =
                     (uint16)MATHSRV_udtMIN(CoFan_tiHldDlyLoSpd_C, 1000);
               }
               else
               {
                  if (CoFan_rSpdFanPred < CoFan_rFanB2LoSpdLoThd_C)
                  {
                     CoFan_stAcvCoFanCmd = COFANB2_VNULLE;
                     CoFan_bAcvCoFan1Cmd = 0;
                     CoFan_bAcvCoFan2Cmd = 0;
                     VEMS_vidSET(Cf_speed_for_air, 0);
                     VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
                     CoFan_tiDlyTranActrProt = (uint16)CoFan_tiTqDly_C;
                  }
                  else
                  {
                     s32LocalTranActrProt = (sint32)( CoFan_tiDlyTranActrProt
                                                    - 1);
                     CoFan_tiDlyTranActrProt =
                        (uint16)MATHSRV_udtCLAMP(s32LocalTranActrProt, 0, 1000);
                  }
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanB2_PVTran                             */
/* !Description :  Fonction de la transition de l'état COFANB2_PV             */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 CoFan_tiDlyTranActrProt;                                     */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_rFanB2HiSpdHiThd_C;                                     */
/*  input uint16 CoFan_tiHldDlyHiSpd_C;                                       */
/*  input uint8 CoFan_rFanB2LoSpdLoThd_C;                                     */
/*  input uint8 CoFan_tiTqDly_C;                                              */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output boolean CoFan_bAcvCoFan1Cmd;                                       */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output boolean FanCtl_bReqIncVoltMin;                                     */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanB2_PVTran(void)
{
   boolean bLocalAcvNoSpdFanAppldB2;
   boolean bLocalAcvErrSpdFanAppldB2;
   sint32  s32LocalTranActrProt;


   bLocalAcvErrSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDB2);
   bLocalAcvNoSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDB2);
   if (bLocalAcvErrSpdFanAppldB2 != 0)
   {
      VEMS_vidSET(Cf_speed_for_air, 63);
      CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
   }
   else
   {
      if (bLocalAcvNoSpdFanAppldB2 != 0)
      {
         VEMS_vidSET(Cf_speed_for_air, 0);
         CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
      }
      else
      {
         if (CoFan_tiDlyTranActrProt <= 1)
         {
            if (CoFan_rSpdFanPred >= CoFan_rFanB2HiSpdHiThd_C)
            {
               CoFan_stAcvCoFanCmd = COFANB2_GV;
               CoFan_bAcvCoFan1Cmd = 1;
               CoFan_bAcvCoFan2Cmd = 1;
               VEMS_vidSET(Cf_speed_for_air, 50);
               VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
               CoFan_tiDlyTranActrProt =
                  (uint16)MATHSRV_udtMIN(CoFan_tiHldDlyHiSpd_C, 1000);
            }
            else
            {
               if (CoFan_rSpdFanPred < CoFan_rFanB2LoSpdLoThd_C)
               {
                  CoFan_stAcvCoFanCmd = COFANB2_VNULLE;
                  CoFan_bAcvCoFan1Cmd = 0;
                  CoFan_bAcvCoFan2Cmd = 0;
                  VEMS_vidSET(Cf_speed_for_air, 0);
                  VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
                  CoFan_tiDlyTranActrProt = (uint16)CoFan_tiTqDly_C;
               }
            }
         }
         else
         {
            s32LocalTranActrProt = (sint32)(CoFan_tiDlyTranActrProt - 1);
            CoFan_tiDlyTranActrProt =
               (uint16)MATHSRV_udtMIN(s32LocalTranActrProt, 1000);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanB2_GVTran                             */
/* !Description :  Fonction de transition de l'état COFANB2_GV                */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean FanCtl_bReqIncVoltMin;                                      */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_rFanB2HiSpdLoThd_C;                                     */
/*  input uint16 CoFan_tiDlyTranActrProt;                                     */
/*  input uint16 CoFan_tiHldDlyLoSpd_C;                                       */
/*  input boolean CoFan_bFanB2HiSpd2;                                         */
/*  input uint16 CoFan_tiHldDlyHiSpd_C;                                       */
/*  input uint8 Cf_speed_for_air;                                             */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output boolean CoFan_bAcvCoFan1Cmd;                                       */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output boolean FanCtl_bReqIncVoltMin;                                     */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*  output uint8 Cf_speed_for_air;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanB2_GVTran(void)
{
   boolean bLocalAcvLoSpdFanAppldB2;
   boolean bLocalAcvHiSpdFanAppldB2;
   boolean bLocalAcvNoSpdFanAppldCohB2;
   boolean bLocalFANCtl;
   uint8   u8LocalCfSpeedAir;
   sint32  s32LocalTranActrProt;


   bLocalAcvLoSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVLOSPDFANAPPLDB2);
   bLocalAcvHiSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDB2);
   bLocalAcvNoSpdFanAppldCohB2 = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDCOHB2);
   if (bLocalAcvHiSpdFanAppldB2 != 0)
   {
      u8LocalCfSpeedAir = 50;
      CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
   }
   else
   {
      if (bLocalAcvLoSpdFanAppldB2 != 0)
      {
         u8LocalCfSpeedAir = 25;
         CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
      }
      else
      {
         if(bLocalAcvNoSpdFanAppldCohB2 != 0)
         {
            u8LocalCfSpeedAir = 0;
            CoFan_stAcvCoFanCmd = COFANB2_DEFAUT;
         }
         else
         {
            VEMS_vidGET(FanCtl_bReqIncVoltMin, bLocalFANCtl);
            if (bLocalFANCtl == 0)
            {
               if (  ( CoFan_rSpdFanPred < CoFan_rFanB2HiSpdLoThd_C)
                  && (CoFan_tiDlyTranActrProt <= 1))
               {
                  CoFan_stAcvCoFanCmd = COFANB2_PV;
                  CoFan_bAcvCoFan1Cmd = 0;
                  CoFan_bAcvCoFan2Cmd = 1;
                  u8LocalCfSpeedAir = 25;
                  VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
                  CoFan_tiDlyTranActrProt =
                     (uint16)MATHSRV_udtMIN(CoFan_tiHldDlyLoSpd_C, 1000);
               }
               else
               {
                  if (CoFan_bFanB2HiSpd2 != 0)
                  {
                     VEMS_vidSET(FanCtl_bReqIncVoltMin, 1);
                     CoFan_bAcvCoFan1Cmd = 1;
                     CoFan_bAcvCoFan2Cmd = 1;
                     u8LocalCfSpeedAir = 55;
                     CoFan_tiDlyTranActrProt =
                        (uint16)MATHSRV_udtMIN(CoFan_tiHldDlyHiSpd_C, 1000);
                     CoFan_stAcvCoFanCmd = COFANB2_GV;
                  }
                  else
                  {
                     VEMS_vidGET(Cf_speed_for_air, u8LocalCfSpeedAir);
                     s32LocalTranActrProt =
                        (sint32)(CoFan_tiDlyTranActrProt - 1);
                     CoFan_tiDlyTranActrProt =
                        (uint16)MATHSRV_udtCLAMP(s32LocalTranActrProt, 0, 1000);
                  }
               }
            }
            else
            {
               if (  (CoFan_bFanB2HiSpd2 == 0)
                  && (CoFan_tiDlyTranActrProt <= 1))
               {
                  VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
                  CoFan_bAcvCoFan1Cmd = 1;
                  CoFan_bAcvCoFan2Cmd = 1;
                  u8LocalCfSpeedAir = 50;
                  CoFan_tiDlyTranActrProt =
                     (uint16)MATHSRV_udtMIN(CoFan_tiHldDlyHiSpd_C, 1000);
                  CoFan_stAcvCoFanCmd = COFANB2_GV;
               }
               else
               {
                  VEMS_vidGET(Cf_speed_for_air, u8LocalCfSpeedAir);
                  s32LocalTranActrProt = (sint32)( CoFan_tiDlyTranActrProt - 1);
                  CoFan_tiDlyTranActrProt =
                     (uint16)MATHSRV_udtCLAMP(s32LocalTranActrProt, 0, 1000);
               }
            }
         }
      }
   }
   u8LocalCfSpeedAir = (uint8)MATHSRV_udtMIN(u8LocalCfSpeedAir, 63);
   VEMS_vidSET(Cf_speed_for_air, u8LocalCfSpeedAir);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanB2_DEFAUT                             */
/* !Description :  Focntion de transition de l'étape COFANB2_DEFAULT          */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_tiTqDly_C;                                              */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output boolean CoFan_bAcvCoFan1Cmd;                                       */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output boolean FanCtl_bReqIncVoltMin;                                     */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanB2_DEFAUT(void)
{
   boolean bLocalAcvErrSpdFanAppldB2;
   boolean bLocalAcvLoSpdFanAppldB2;
   boolean bLocalAcvHiSpdFanAppldB2;
   boolean bLocalAcvNoSpdFanAppldB2;
   boolean bLocalAcvNoSpdFanAppldCohB2;


   bLocalAcvErrSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDB2);
   bLocalAcvLoSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVLOSPDFANAPPLDB2);
   bLocalAcvHiSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDB2);
   bLocalAcvNoSpdFanAppldB2 = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDB2);
   bLocalAcvNoSpdFanAppldCohB2 = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDCOHB2);
   if (  (bLocalAcvErrSpdFanAppldB2 == 0)
      && (bLocalAcvLoSpdFanAppldB2 == 0)
      && (bLocalAcvHiSpdFanAppldB2 == 0)
      && (bLocalAcvNoSpdFanAppldB2 == 0)
      && (bLocalAcvNoSpdFanAppldCohB2 == 0))
   {
      CoFan_stAcvCoFanCmd = COFANB2_VNULLE;
      CoFan_bAcvCoFan1Cmd = 0;
      CoFan_bAcvCoFan2Cmd = 0;
      VEMS_vidSET(Cf_speed_for_air, 0);
      VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
      CoFan_tiDlyTranActrProt = (uint16)CoFan_tiTqDly_C;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanc_Ro_T                                */
/* !Description :  Fonction de transition de l'état COFANC_RO                 */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_ctCritScFanC;                                           */
/*  input uint8 CoFan_noThdCntCritScFanC_C;                                   */
/*  input uint16 CoFan_ctDftStFanC;                                           */
/*  input uint8 CoFan_rSpdFanCReqFil;                                         */
/*  input uint8 CoFan_rSpdFanCThd_C;                                          */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input uint8 CoFan_tiOnDly_C;                                              */
/*  input uint8 CoFan_tiTqDly_C;                                              */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanc_Ro_T(void)
{
   boolean bLocalAcvHiSpdFanAppldC;
   boolean bLocalAcvNoSpdFanAppldC;
   boolean bLocalAcvCritScFanAppldC;
   boolean bLocalAcvErrSpdFanAppldC;
   uint32  u32Local;

   bLocalAcvErrSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDC);
   bLocalAcvHiSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDC);
   bLocalAcvNoSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDC);
   bLocalAcvCritScFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVCRITSCFANAPPLDC);
   if (CoFan_ctCritScFanC >= CoFan_noThdCntCritScFanC_C)
   {
      VEMS_vidSET(Cf_speed_for_air, 0);
      CoFan_bAcvCoFan2Cmd = 0;
      CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
   }
   else
   {
      if (  (bLocalAcvErrSpdFanAppldC != 0)
         || (CoFan_ctDftStFanC > 0))
      {
         VEMS_vidSET(Cf_speed_for_air, 63);
         CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
      }
      else
      {
         if (bLocalAcvCritScFanAppldC != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_bAcvCoFan2Cmd = 0;
            CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
         }
         else
         {
            if (bLocalAcvNoSpdFanAppldC != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 0);
               CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
            }
            else
            {
               if (bLocalAcvHiSpdFanAppldC != 0)
               {
                  VEMS_vidSET(Cf_speed_for_air, 50);
                  CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
               }
               else
               {
                  if (CoFan_rSpdFanCReqFil >= CoFan_rSpdFanCThd_C)
                  {
                     CoFan_stAcvCoFanCmd = COFANC_RFAO;
                     u32Local = (uint32)((CoFan_LoStFan1_C * 8192) / 25);
                     CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                  32768);
                     CoFan_bAcvCoFan2Cmd = 1;
                     VEMS_vidSET(Cf_speed_for_air, 0);
                     CoFan_tiDlyTranActrProt =
                        (uint16)MATHSRV_udtMAX(CoFan_tiOnDly_C,
                                               CoFan_tiTqDly_C);
                  }
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanc_Rfao_T                              */
/* !Description :  Fonction de transition de l'état COFANC_RFAO               */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_ctCritScFanC;                                           */
/*  input uint8 CoFan_noThdCntCritScFanC_C;                                   */
/*  input uint16 CoFan_ctDftStFanC;                                           */
/*  input uint16 CoFan_tiDlyTranActrProt;                                     */
/*  input uint8 CoFan_rSpdFanCReqFil;                                         */
/*  input uint8 CoFan_rSpdFanCThd_C;                                          */
/*  input uint8 CoFan_rRCOFanC;                                               */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input uint16 CoFan_tiOffDly_C;                                            */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanc_Rfao_T(void)
{
   boolean bLocalAcvHiSpdFanAppldC;
   boolean bLocalAcvNoSpdFanAppldC;
   boolean bLocalAcvErrSpdFanAppldC;
   boolean bLocalAcvCritScFanAppldC;
   uint8   u8LocalCfSpeedAir;
   sint32  s32LocalTranActrProt;
   uint32  u32Local;


   bLocalAcvErrSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDC);
   bLocalAcvHiSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDC);
   bLocalAcvNoSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDC);
   bLocalAcvCritScFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVCRITSCFANAPPLDC);
   if (CoFan_ctCritScFanC >= CoFan_noThdCntCritScFanC_C)
   {
      VEMS_vidSET(Cf_speed_for_air, 0);
      CoFan_bAcvCoFan2Cmd = 0;
      CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
   }
   else
   {
      if (  (bLocalAcvErrSpdFanAppldC != 0)
         || (CoFan_ctDftStFanC > 0))
      {
         VEMS_vidSET(Cf_speed_for_air, 63);
         CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
      }
      else
      {
         if (bLocalAcvCritScFanAppldC != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_bAcvCoFan2Cmd = 0;
            CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
         }
         else
         {
            if (bLocalAcvNoSpdFanAppldC != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 0);
               CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
            }
            else
            {
               if (bLocalAcvHiSpdFanAppldC != 0)
               {
                  VEMS_vidSET(Cf_speed_for_air, 50);
                  CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
               }
               else
               {
                  if (CoFan_tiDlyTranActrProt <= 1)
                  {
                     if (CoFan_rSpdFanCReqFil >= CoFan_rSpdFanCThd_C)
                     {
                        CoFan_stAcvCoFanCmd = COFANC_GMVP;
                        u32Local = (uint32)((CoFan_rRCOFanC * 8192) / 25);
                        CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                     32768);
                        CoFan_bAcvCoFan2Cmd = 1;
                        u8LocalCfSpeedAir = (uint8)( (CoFan_rSpdFanPred + 1)
                                                   / 2);
                        u8LocalCfSpeedAir =
                           (uint8)MATHSRV_udtMIN(u8LocalCfSpeedAir, 63);
                        VEMS_vidSET(Cf_speed_for_air, u8LocalCfSpeedAir);
                     }
                     else
                     {
                        CoFan_stAcvCoFanCmd = COFANC_RFGMVP;
                        u32Local = (uint32)((CoFan_LoStFan1_C * 8192) / 25);
                        CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                     32768);
                        CoFan_bAcvCoFan2Cmd = 1;
                        VEMS_vidSET(Cf_speed_for_air, 0);
                        CoFan_tiDlyTranActrProt =
                           (uint16)MATHSRV_udtMIN(CoFan_tiOffDly_C, 1000);
                     }
                  }
                  else
                  {
                     s32LocalTranActrProt = (sint32)( CoFan_tiDlyTranActrProt
                                                    - 1);
                     CoFan_tiDlyTranActrProt =
                        (uint16)MATHSRV_udtMIN(s32LocalTranActrProt, 1000);
                  }
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanc_Gmvp_T                              */
/* !Description :  Fonction de transition de l'état COFANC_GMVP               */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_ctCritScFanC;                                           */
/*  input uint8 CoFan_noThdCntCritScFanC_C;                                   */
/*  input uint16 CoFan_ctDftStFanC;                                           */
/*  input uint8 CoFan_rSpdFanCReqFil;                                         */
/*  input uint8 CoFan_rSpdFanCThd_C;                                          */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input uint16 CoFan_tiOffDly_C;                                            */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_rRCOFanC;                                               */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanc_Gmvp_T(void)
{
   boolean bLocalAcvHiSpdFanAppldC;
   boolean bLocalAcvNoSpdFanAppldC;
   boolean bLocalAcvErrSpdFanAppldC;
   boolean bLocalAcvCritScFanAppldC;
   uint8   u8LocalCfSpeedAir;
   uint32  u32Local;


   bLocalAcvErrSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDC);
   bLocalAcvHiSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDC);
   bLocalAcvNoSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDC);
   bLocalAcvCritScFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVCRITSCFANAPPLDC);

   if (CoFan_ctCritScFanC >= CoFan_noThdCntCritScFanC_C)
   {
      VEMS_vidSET(Cf_speed_for_air, 0);
      CoFan_bAcvCoFan2Cmd = 0;
      CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
   }
   else
   {
      if (  (bLocalAcvErrSpdFanAppldC != 0)
         || (CoFan_ctDftStFanC > 0))
      {
         VEMS_vidSET(Cf_speed_for_air, 63);
         CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
      }
      else
      {
         if (bLocalAcvCritScFanAppldC != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_bAcvCoFan2Cmd = 0;
            CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
         }
         else
         {
            if (bLocalAcvNoSpdFanAppldC != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 0);
               CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
            }
            else
            {
               if (bLocalAcvHiSpdFanAppldC != 0)
               {
                  VEMS_vidSET(Cf_speed_for_air, 50);
                  CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
               }
               else
               {
                  if (CoFan_rSpdFanCReqFil < CoFan_rSpdFanCThd_C)
                  {
                     CoFan_stAcvCoFanCmd = COFANC_RFGMVP;
                     u32Local = (uint32)((CoFan_LoStFan1_C * 8192) / 25);
                     CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                  32768);
                     CoFan_bAcvCoFan2Cmd = 1;
                     VEMS_vidSET(Cf_speed_for_air, 0);
                     CoFan_tiDlyTranActrProt =
                        (uint16)MATHSRV_udtMIN(CoFan_tiOffDly_C, 1000);
                  }
                  else
                  {
                     u8LocalCfSpeedAir = (uint8)((CoFan_rSpdFanPred + 1) / 2);
                     u8LocalCfSpeedAir =
                        (uint8)MATHSRV_udtMIN(u8LocalCfSpeedAir, 63);
                     VEMS_vidSET(Cf_speed_for_air, u8LocalCfSpeedAir);
                     u32Local = (uint32)((CoFan_rRCOFanC * 8192) / 25);
                     CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                  32768);
                  }
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanc_Rfgmvp_T                            */
/* !Description :  Fonction de transition de l'état COFANC_RFGMVP             */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_ctCritScFanC;                                           */
/*  input uint8 CoFan_noThdCntCritScFanC_C;                                   */
/*  input uint16 CoFan_ctDftStFanC;                                           */
/*  input uint8 CoFan_rSpdFanCReqFil;                                         */
/*  input uint8 CoFan_rSpdFanCThd_C;                                          */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input uint8 CoFan_tiTqDly_C;                                              */
/*  input uint8 CoFan_rSpdFanCOpRlyThd_C;                                     */
/*  input uint16 CoFan_tiDlyTranActrProt;                                     */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanc_Rfgmvp_T(void)
{
   boolean bLocalAcvHiSpdFanAppldC;
   sint32  s32LocalTranActrProt;
   boolean bLocalAcvNoSpdFanAppldC;
   boolean bLocalAcvErrSpdFanAppldC;
   boolean bLocalAcvCritScFanAppldC;
   uint32  u32Local;


   bLocalAcvErrSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDC);
   bLocalAcvHiSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDC);
   bLocalAcvNoSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDC);
   bLocalAcvCritScFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVCRITSCFANAPPLDC);

   if (CoFan_ctCritScFanC >= CoFan_noThdCntCritScFanC_C)
   {
      VEMS_vidSET(Cf_speed_for_air, 0);
      CoFan_bAcvCoFan2Cmd = 0;
      CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
   }
   else
   {
      if (  (bLocalAcvErrSpdFanAppldC != 0)
         || (CoFan_ctDftStFanC > 0))
      {
         VEMS_vidSET(Cf_speed_for_air, 63);
         CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
      }
      else
      {
         if (bLocalAcvCritScFanAppldC != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_bAcvCoFan2Cmd = 0;
            CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
         }
         else
         {
            if (bLocalAcvNoSpdFanAppldC != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 0);
               CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
            }
            else
            {
               if (bLocalAcvHiSpdFanAppldC != 0)
               {
                  VEMS_vidSET(Cf_speed_for_air, 50);
                  CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
               }
               else
               {
                  if (CoFan_rSpdFanCReqFil >= CoFan_rSpdFanCThd_C)
                  {
                     CoFan_stAcvCoFanCmd = COFANC_RF;
                     u32Local = (uint32)((CoFan_LoStFan1_C * 8192) / 25);
                     CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                  32768);
                     CoFan_bAcvCoFan2Cmd = 1;
                     VEMS_vidSET(Cf_speed_for_air, 0);
                     CoFan_tiDlyTranActrProt = CoFan_tiTqDly_C;
                  }
                  else
                  {
                     if (  (CoFan_rSpdFanCReqFil < CoFan_rSpdFanCOpRlyThd_C)
                        && (CoFan_tiDlyTranActrProt <= 1))
                     {
                        CoFan_stAcvCoFanCmd = COFANC_RO;
                        u32Local = (uint32)((CoFan_LoStFan1_C * 8192) / 25);
                        CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                     32768);
                        CoFan_bAcvCoFan2Cmd = 0;
                        VEMS_vidSET(Cf_speed_for_air, 0);
                     }
                     else
                     {
                        s32LocalTranActrProt = (sint32)(CoFan_tiDlyTranActrProt
                                                       - 1);
                        CoFan_tiDlyTranActrProt =
                           (uint16)MATHSRV_udtCLAMP(s32LocalTranActrProt,
                                                    0,
                                                    1000);
                     }
                  }
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanc_Rf_T                                */
/* !Description :  Fonction de transition de l'état COFANC_RF                 */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoFan_ctCritScFanC;                                           */
/*  input uint8 CoFan_noThdCntCritScFanC_C;                                   */
/*  input uint16 CoFan_ctDftStFanC;                                           */
/*  input uint8 CoFan_rSpdFanCReqFil;                                         */
/*  input uint8 CoFan_rSpdFanCThd_C;                                          */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input uint16 CoFan_tiOffDly_C;                                            */
/*  input uint16 CoFan_tiDlyTranActrProt;                                     */
/*  input uint8 CoFan_rRCOFanC;                                               */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanc_Rf_T(void)
{
   uint8   u8LocalCfSpeedAir;
   sint32  s32LocalTranActrProt;
   boolean bLocalAcvHiSpdFanAppldC;
   boolean bLocalAcvNoSpdFanAppldC;
   boolean bLocalAcvErrSpdFanAppldC;
   boolean bLocalAcvCritScFanAppldC;
   uint32  u32Local;


   bLocalAcvErrSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDC);
   bLocalAcvHiSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDC);
   bLocalAcvNoSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDC);
   bLocalAcvCritScFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVCRITSCFANAPPLDC);

   if (CoFan_ctCritScFanC >= CoFan_noThdCntCritScFanC_C)
   {
      VEMS_vidSET(Cf_speed_for_air, 0);
      CoFan_bAcvCoFan2Cmd = 0;
      CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
   }
   else
   {
      if (  (bLocalAcvErrSpdFanAppldC != 0)
         || (CoFan_ctDftStFanC > 0))
      {
         VEMS_vidSET(Cf_speed_for_air, 63);
         CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
      }
      else
      {
         if (bLocalAcvCritScFanAppldC != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_bAcvCoFan2Cmd = 0;
            CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
         }
         else
         {
            if (bLocalAcvNoSpdFanAppldC != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 0);
               CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
            }
            else
            {
               if (bLocalAcvHiSpdFanAppldC != 0)
               {
                  VEMS_vidSET(Cf_speed_for_air, 50);
                  CoFan_stAcvCoFanCmd = COFANC_DEFAUT;
               }
               else
               {
                  if (CoFan_rSpdFanCReqFil < CoFan_rSpdFanCThd_C)
                  {
                     CoFan_stAcvCoFanCmd = COFANC_RFGMVP;
                     u32Local = (uint32)((CoFan_LoStFan1_C * 8192) / 25);
                     CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                  32768);
                     CoFan_bAcvCoFan2Cmd = 1;
                     VEMS_vidSET(Cf_speed_for_air, 0);
                     CoFan_tiDlyTranActrProt =
                        (uint16)MATHSRV_udtMIN(CoFan_tiOffDly_C, 1000);
                  }
                  else
                  {
                     if (CoFan_tiDlyTranActrProt <= 1)
                     {
                        CoFan_stAcvCoFanCmd = COFANC_GMVP;
                        u32Local = (uint32)((CoFan_rRCOFanC * 8192) / 25);
                        CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local,
                                                                     32768);
                        CoFan_bAcvCoFan2Cmd = 1;
                        u8LocalCfSpeedAir = (uint8)( (CoFan_rSpdFanPred + 1)
                                                   / 2);
                        u8LocalCfSpeedAir =
                           (uint8)MATHSRV_udtMIN(u8LocalCfSpeedAir, 63);
                        VEMS_vidSET(Cf_speed_for_air, u8LocalCfSpeedAir);
                     }
                     else
                     {
                        s32LocalTranActrProt = (sint32)(CoFan_tiDlyTranActrProt
                                                       - 1);
                        CoFan_tiDlyTranActrProt =
                           (uint16)MATHSRV_udtMIN(s32LocalTranActrProt, 1000);
                     }
                  }
               }
            }
         }
      }
   }
}
/*----------------------------------end of file-------------------------------*/