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
/* !File            : COFANCMDDIAG_FCT2.C                                     */
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
/*   1 / COFANCMDDIAG_vidCoFanCtlMng                                          */
/*   2 / COFANCMDDIAG_vidCoFanCtlMngB1                                        */
/*   3 / COFANCMDDIAG_vidCoFanCtlMngB2                                        */
/*   4 / COFANCMDDIAG_vidCoFanCtlMngC                                         */
/*   5 / COFANCMDDIAG_vidCofanc_Init_T                                        */
/*   6 / COFANCMDDIAG_vidCofanc_Default_T                                     */
/*   7 / COFANCMDDIAG_vidCoFanCmd                                             */
/*   8 / COFANCMDDIAG_vidCoFanCmdB1                                           */
/*   9 / COFANCMDDIAG_vidCoFanCmdB2                                           */
/*   10 / COFANCMDDIAG_vidCoFanCmdC                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6722439 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/COFANCMDDIAG/COFANCMDDIAG_FCT2.C_v$*/
/* $Revision::   1.19     $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
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
#include "SWFAIL.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanCtlMng                                */
/* !Description :  Cette fonction définie les états des commandes CMD_GMV1 et */
/*                 CMD_GMV2 en fonction de la vitesse GMV et de la vitesse de */
/*                 consigne filtrée (C).                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COFANCMDDIAG_vidCoFanCtlMngB1();                         */
/*  extf argret void COFANCMDDIAG_vidCoFanCtlMngB2();                         */
/*  extf argret void COFANCMDDIAG_vidCoFanCtlMngC();                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanCtlMng(void)
{
   uint8   u8LocalCfCoolFan;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfCoolFan);
   switch (u8LocalCfCoolFan)
   {
      case EQUIPMENT_B1:
         COFANCMDDIAG_vidCoFanCtlMngB1();
         break;

      case EQUIPMENT_B2:
         COFANCMDDIAG_vidCoFanCtlMngB2();
         break;

      case EQUIPMENT_C:
         COFANCMDDIAG_vidCoFanCtlMngC();
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanCtlMngB1                              */
/* !Description :  Cette fonction définie les états des commandes CMD_GMV1 en */
/*                 fonction de la vitesse GMVprédite (B1).                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st59 CoFan_stAcvCoFanCmd;                                           */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_rFanB1HiThd_C;                                          */
/*  input boolean TqRes_bCdnFanRes;                                           */
/*  input uint16 CoFan_tiDlyTranActrProt;                                     */
/*  input uint16 CoFan_tiHldDly_C;                                            */
/*  input uint8 CoFan_rFanB1LoThd_C;                                          */
/*  input uint8 CoFan_tiTqDly_C;                                              */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output boolean CoFan_bAcvCoFan1Cmd;                                       */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanCtlMngB1(void)
{
   boolean bLocalAcvHiSpdFanAppldB1;
   boolean bLocalAcvNoSpdFanAppldB1;
   boolean bLocalTqRes_bCdnFanRes;
   sint32  s32LocalTranActrProt;


   bLocalAcvHiSpdFanAppldB1 = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDB1);
   bLocalAcvNoSpdFanAppldB1 = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDB1);
   switch(CoFan_stAcvCoFanCmd)
   {
      case COFANB1_VNULLE:
         if (bLocalAcvNoSpdFanAppldB1 != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_stAcvCoFanCmd = COFANB1_DEFAUT;
         }
         else
         {
            if (bLocalAcvHiSpdFanAppldB1 != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 50);
               CoFan_stAcvCoFanCmd = COFANB1_DEFAUT;
            }
            else
            {
               if (CoFan_rSpdFanPred >= CoFan_rFanB1HiThd_C)
               {
                  CoFan_stAcvCoFanCmd = COFANB1_ATTENTE;
                  CoFan_bAcvCoFan1Cmd = 0;
                  VEMS_vidSET(Cf_speed_for_air, 0);
               }
            }
         }
         break;

      case COFANB1_ATTENTE:
         VEMS_vidGET(TqRes_bCdnFanRes , bLocalTqRes_bCdnFanRes );
         if (bLocalAcvNoSpdFanAppldB1 != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_stAcvCoFanCmd = COFANB1_DEFAUT;
         }
         else
         {
            if (bLocalAcvHiSpdFanAppldB1 != 0)
            {
               VEMS_vidSET(Cf_speed_for_air, 50);
               CoFan_stAcvCoFanCmd = COFANB1_DEFAUT;
            }
            else
            {
               if (  (CoFan_rSpdFanPred > CoFan_rFanB1HiThd_C)
                  && (CoFan_tiDlyTranActrProt <= 1)
                  && (bLocalTqRes_bCdnFanRes == 1))
               {
                  CoFan_stAcvCoFanCmd = COFANB1_GV;
                  CoFan_bAcvCoFan1Cmd = 1;
                  VEMS_vidSET(Cf_speed_for_air, 50);
                  CoFan_tiDlyTranActrProt =
                     (uint16)MATHSRV_udtMIN(CoFan_tiHldDly_C, 1000);
               }
               else
               {
                  if (CoFan_rSpdFanPred < CoFan_rFanB1LoThd_C)
                  {
                     CoFan_stAcvCoFanCmd = COFANB1_VNULLE;
                     CoFan_bAcvCoFan1Cmd = 0;
                     CoFan_bAcvCoFan2Cmd = 0;
                     VEMS_vidSET(Cf_speed_for_air, 0);
                     CoFan_tiDlyTranActrProt = (uint16)CoFan_tiTqDly_C;
                  }
                  else
                  {
                     s32LocalTranActrProt =
                        (sint32)(CoFan_tiDlyTranActrProt - 1);
                     CoFan_tiDlyTranActrProt =
                        (uint16)MATHSRV_udtCLAMP(s32LocalTranActrProt, 0, 1000);
                  }
               }
            }
         }
         break;

      case COFANB1_GV:
         if (bLocalAcvNoSpdFanAppldB1 != 0)
         {
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_stAcvCoFanCmd = COFANB1_DEFAUT;
         }
         else
         {
            if (  (CoFan_rSpdFanPred < CoFan_rFanB1LoThd_C)
               && (CoFan_tiDlyTranActrProt <= 1))
            {
               CoFan_stAcvCoFanCmd = COFANB1_VNULLE;
               CoFan_bAcvCoFan1Cmd = 0;
               CoFan_bAcvCoFan2Cmd = 0;
               VEMS_vidSET(Cf_speed_for_air, 0);
               CoFan_tiDlyTranActrProt = (uint16)CoFan_tiTqDly_C;
            }
            else
            {
               s32LocalTranActrProt = (sint32)(CoFan_tiDlyTranActrProt - 1);
               CoFan_tiDlyTranActrProt =
                  (uint16)MATHSRV_udtCLAMP(s32LocalTranActrProt, 0, 1000);
            }
         }
         break;

      case COFANB1_DEFAUT:
         if (  (bLocalAcvHiSpdFanAppldB1 == 0)
            && (bLocalAcvNoSpdFanAppldB1 == 0))
         {
            CoFan_stAcvCoFanCmd = COFANB1_VNULLE;
            CoFan_bAcvCoFan1Cmd = 0;
            CoFan_bAcvCoFan2Cmd = 0;
            VEMS_vidSET(Cf_speed_for_air, 0);
            CoFan_tiDlyTranActrProt = (uint16)CoFan_tiTqDly_C;
         }
         break;

      case COFANB2_VNULLE:
      case COFANB2_ATTENTE:
      case COFANB2_PV:
      case COFANB2_GV:
      case COFANB2_DEFAUT:
      case COFANC_INIT:
      case COFANC_RO:
      case COFANC_RFAO:
      case COFANC_GMVP:
      case COFANC_RFGMVP:
      case COFANC_RF:
      case COFANC_DEFAUT:
         break;

      default:
         if (CoFan_stAcvCoFanCmd != COFAN_INIT)
         {
            SWFAIL_vidSoftwareErrorHook();
         }
         CoFan_stAcvCoFanCmd = COFANB1_VNULLE;
         CoFan_bAcvCoFan1Cmd = 0;
         CoFan_bAcvCoFan2Cmd = 0;
         VEMS_vidSET(Cf_speed_for_air, 0);
         CoFan_tiDlyTranActrProt = (uint16)CoFan_tiTqDly_C;
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanCtlMngB2                              */
/* !Description :  Cette fonction définie les états des commandes CMD_GMV1 en */
/*                 fonction de la vitesse GMV prédite (B2).                   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COFANCMDDIAG_vidCofanB2VNullTran();                      */
/*  extf argret void COFANCMDDIAG_vidCofanB2WaitTran();                       */
/*  extf argret void COFANCMDDIAG_vidCofanB2_PVTran();                        */
/*  extf argret void COFANCMDDIAG_vidCofanB2_GVTran();                        */
/*  extf argret void COFANCMDDIAG_vidCofanB2_DEFAUT();                        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st59 CoFan_stAcvCoFanCmd;                                           */
/*  input uint8 CoFan_tiTqDly_C;                                              */
/*  output boolean CoFan_bAcvCoFan1Cmd;                                       */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output boolean FanCtl_bReqIncVoltMin;                                     */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanCtlMngB2(void)
{
   switch(CoFan_stAcvCoFanCmd)
   {
      case COFANB2_VNULLE:
         COFANCMDDIAG_vidCofanB2VNullTran();
         break;

      case COFANB2_ATTENTE:
         COFANCMDDIAG_vidCofanB2WaitTran();
         break;

       case COFANB2_PV:
         COFANCMDDIAG_vidCofanB2_PVTran();
         break;

      case COFANB2_GV:
         COFANCMDDIAG_vidCofanB2_GVTran();
         break;

      case COFANB2_DEFAUT:
         COFANCMDDIAG_vidCofanB2_DEFAUT();
         break;

      case COFANB1_VNULLE:
      case COFANB1_ATTENTE:
      case COFANB1_GV:
      case COFANB1_DEFAUT:
      case COFANC_INIT:
      case COFANC_RO:
      case COFANC_RFAO:
      case COFANC_GMVP:
      case COFANC_RFGMVP:
      case COFANC_RF:
      case COFANC_DEFAUT:
         break;

      default:
         if (CoFan_stAcvCoFanCmd != COFAN_INIT)
         {
            SWFAIL_vidSoftwareErrorHook();
         }
         CoFan_bAcvCoFan1Cmd = 0;
         CoFan_bAcvCoFan2Cmd = 0;
         VEMS_vidSET(Cf_speed_for_air, 0);
         VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
         CoFan_tiDlyTranActrProt = (uint16) CoFan_tiTqDly_C;
         CoFan_stAcvCoFanCmd = COFANB2_VNULLE;
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanCtlMngC                               */
/* !Description :  Cette fonction définie les états des commandes CMD_GMV1 et */
/*                 CMD_GMV2 en fonction de la vitesse de consigne filtrée (C).*/
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COFANCMDDIAG_vidCofanc_Init_T();                         */
/*  extf argret void COFANCMDDIAG_vidCofanc_Ro_T();                           */
/*  extf argret void COFANCMDDIAG_vidCofanc_Rfao_T();                         */
/*  extf argret void COFANCMDDIAG_vidCofanc_Gmvp_T();                         */
/*  extf argret void COFANCMDDIAG_vidCofanc_Rfgmvp_T();                       */
/*  extf argret void COFANCMDDIAG_vidCofanc_Rf_T();                           */
/*  extf argret void COFANCMDDIAG_vidCofanc_Default_T();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st59 CoFan_stAcvCoFanCmd;                                           */
/*  input uint8 CoFan_tiInitDly_C;                                            */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanCtlMngC(void)
{
   switch (CoFan_stAcvCoFanCmd)
   {
      case COFANC_INIT:
         COFANCMDDIAG_vidCofanc_Init_T();
         break;

      case COFANC_RO:
         COFANCMDDIAG_vidCofanc_Ro_T();
         break;

      case COFANC_RFAO:
         COFANCMDDIAG_vidCofanc_Rfao_T();
         break;

      case COFANC_GMVP:
         COFANCMDDIAG_vidCofanc_Gmvp_T();
         break;

      case COFANC_RFGMVP:
         COFANCMDDIAG_vidCofanc_Rfgmvp_T();
         break;

      case COFANC_RF:
         COFANCMDDIAG_vidCofanc_Rf_T();
         break;

      case COFANC_DEFAUT:
         COFANCMDDIAG_vidCofanc_Default_T();
         break;

      case COFANB1_VNULLE:
      case COFANB1_ATTENTE:
      case COFANB1_GV:
      case COFANB1_DEFAUT:
      case COFANB2_VNULLE:
      case COFANB2_ATTENTE:
      case COFANB2_PV:
      case COFANB2_GV:
      case COFANB2_DEFAUT:
         break;

      default:
         if (CoFan_stAcvCoFanCmd != COFAN_INIT)
         {
            SWFAIL_vidSoftwareErrorHook();
         }
         CoFan_stAcvCoFanCmd = COFANC_INIT;
         CoFan_rAcvCoFan1Cmd = 32768;
         CoFan_bAcvCoFan2Cmd = 0;
         VEMS_vidSET(Cf_speed_for_air, 0);
         CoFan_tiDlyTranActrProt = (uint16)CoFan_tiInitDly_C;
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanc_Init_T                              */
/* !Description :  fonction de transition de l'état COFANC_INIT               */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 CoFan_tiDlyTranActrProt;                                     */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanc_Init_T(void)
{
   sint32 s32LocalTranActrProt;
   uint32 u32Local;


   if (CoFan_tiDlyTranActrProt <= 1)
   {
      CoFan_stAcvCoFanCmd = COFANC_RO;
      u32Local = (uint32)((CoFan_LoStFan1_C * 8192) / 25);
      CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local, 32768);
      CoFan_bAcvCoFan2Cmd = 0;
      VEMS_vidSET(Cf_speed_for_air, 0);
   }
   else
   {
      s32LocalTranActrProt = (sint32)(CoFan_tiDlyTranActrProt - 1);
      CoFan_tiDlyTranActrProt =
         (uint16)MATHSRV_udtMIN(s32LocalTranActrProt, 1000);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCofanc_Default_T                           */
/* !Description :  Fonction de transition de l'état COFANC_DEFAULT            */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoFan_ctRskCritScFanC;                                        */
/*  input uint8 CoFan_noThdCntRskCritScFanC_C;                                */
/*  input uint8 CoFan_ctCritScFanC;                                           */
/*  input uint8 CoFan_noThdCntCritScFanC_C;                                   */
/*  input uint16 CoFan_ctDftStFanC;                                           */
/*  input uint8 CoFan_rSpdFanCReqFil;                                         */
/*  input uint8 CoFan_rSpdFanCThd_C;                                          */
/*  input uint8 CoFan_rRCOFanC;                                               */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input uint8 Cf_speed_for_air;                                             */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output uint8 Cf_speed_for_air;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCofanc_Default_T(void)
{
   boolean bLocalAcvHiSpdFanAppldC;
   boolean bLocalAcvErrSpdFanAppldC;
   boolean bLocalAcvNoSpdFanAppldC;
   boolean bLocalAcvCritScFanAppldC;
   uint8   u8LocalCfSpeedAir;
   uint32  u32Local;


   bLocalAcvCritScFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVCRITSCFANAPPLDC);
   bLocalAcvNoSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVNOSPDFANAPPLDC);
   bLocalAcvHiSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVHISPDFANAPPLDC);
   bLocalAcvErrSpdFanAppldC = GDGAR_bGetFRM(FRM_FRM_ACVERRSPDFANAPPLDC);
   if (CoFan_ctRskCritScFanC < CoFan_noThdCntRskCritScFanC_C)
   {
      if (  (bLocalAcvCritScFanAppldC == 0)
         && (bLocalAcvNoSpdFanAppldC == 0)
         && (bLocalAcvHiSpdFanAppldC == 0)
         && (bLocalAcvErrSpdFanAppldC == 0)
         && (CoFan_ctCritScFanC < CoFan_noThdCntCritScFanC_C)
         && (CoFan_ctDftStFanC == 0))
      {
         if (CoFan_rSpdFanCReqFil >= CoFan_rSpdFanCThd_C)
         {
            CoFan_stAcvCoFanCmd = COFANC_GMVP;
            u32Local = (uint32)((CoFan_rRCOFanC * 8192) / 25);
            CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local, 32768);
            CoFan_bAcvCoFan2Cmd = 1;
            u8LocalCfSpeedAir = (uint8)((CoFan_rSpdFanPred + 1) / 2);
            u8LocalCfSpeedAir = (uint8)MATHSRV_udtMIN(u8LocalCfSpeedAir, 63);
            VEMS_vidSET(Cf_speed_for_air, u8LocalCfSpeedAir);
         }
         else
         {
            CoFan_stAcvCoFanCmd = COFANC_RO;
            u32Local = (uint32)((CoFan_LoStFan1_C * 8192) / 25);
            CoFan_rAcvCoFan1Cmd = (uint16)MATHSRV_udtMIN(u32Local, 32768);
            CoFan_bAcvCoFan2Cmd = 0;
            VEMS_vidSET(Cf_speed_for_air, 0);
         }
      }
   }
   else
   {
      VEMS_vidGET(Cf_speed_for_air, u8LocalCfSpeedAir);
      if (u8LocalCfSpeedAir == 63)
      {
         VEMS_vidSET(Cf_speed_for_air, 0);
         CoFan_bAcvCoFan2Cmd = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanCmd                                   */
/* !Description :  Cette fonction envoie les commandes CMD_GMV1 et CMD_GMV2 au*/
/*                 LdB selon l’équipement et leur type.                       */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void COFANCMDDIAG_vidCoFanCmdB1();                            */
/*  extf argret void COFANCMDDIAG_vidCoFanCmdB2();                            */
/*  extf argret void COFANCMDDIAG_vidCoFanCmdC();                             */
/*  input boolean Crash_fps_confirmed;                                        */
/*  input boolean CoFan_bAcvCrashCond_C;                                      */
/*  input boolean CoFan_bActrTstInProgs;                                      */
/*  input boolean CoFan_bActrTstFan1BCmd;                                     */
/*  input boolean CoFan_bActrTstFan2Cmd;                                      */
/*  input uint16 CoFan_rActrTstFan1CCmd;                                      */
/*  input boolean CoFan_bAcvCoFan1Cmd;                                        */
/*  input boolean CoFan_bAcvCoFan2Cmd;                                        */
/*  input uint16 CoFan_rAcvCoFan1Cmd;                                         */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*  output boolean CoFan_bAcvCoFan1CmdAppld;                                  */
/*  output boolean ThMgt_bCmdHiSpdFan;                                        */
/*  output boolean CoFan_bAcvCoFan2CmdAppld;                                  */
/*  output boolean ThMgt_bCmdLowSpdFan;                                       */
/*  output uint16 CoFan_rAcvCoFan1CmdAppld;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanCmd(void)
{
   boolean bLocalCrash_fps_confirmed;
   boolean bLocalTempCofan1;
   boolean bLocalTempCofan2;
   boolean bLocalInhCoFanCmd;
   boolean bLocalAcvCoFan1Cmd;
   boolean bLocalAcvCoFan2Cmd;
   boolean bLocalActrTstInProgs;
   uint8   u8LocalCfEquipment;
   uint16  u16LocalrActrTstFan1CCmd;
   uint16  u16LocalCoFan_rAcvCoFan1CmdAppld;


   VEMS_vidGET(Crash_fps_confirmed, bLocalCrash_fps_confirmed);
   bLocalInhCoFanCmd = GDGAR_bGetFRM(FRM_FRM_INHCOFANCMD);
   if (  (  (bLocalCrash_fps_confirmed != 0)
         && (CoFan_bAcvCrashCond_C != 0))
      || (bLocalInhCoFanCmd != 0))
   {
      bLocalTempCofan1 = 0;
      bLocalTempCofan2 = 0;
      u16LocalCoFan_rAcvCoFan1CmdAppld = 0;
   }
   else
   {
      VEMS_vidGET(CoFan_bActrTstInProgs, bLocalActrTstInProgs);
      if (bLocalActrTstInProgs != 0)
      {
         VEMS_vidGET(CoFan_bActrTstFan1BCmd, bLocalTempCofan1);
         VEMS_vidGET(CoFan_bActrTstFan2Cmd, bLocalTempCofan2);
         VEMS_vidGET(CoFan_rActrTstFan1CCmd, u16LocalrActrTstFan1CCmd);
         u16LocalCoFan_rAcvCoFan1CmdAppld =
            (uint16)MATHSRV_udtMIN(u16LocalrActrTstFan1CCmd, 32768);
      }
      else
      {
         bLocalAcvCoFan1Cmd = GDGAR_bGetFRM(FRM_FRM_ACVCOFAN1CMD);
         bLocalAcvCoFan2Cmd = GDGAR_bGetFRM(FRM_FRM_ACVCOFAN2CMD);
         if (bLocalAcvCoFan1Cmd != 0)
         {
            bLocalTempCofan1 = 1;
         }
         else
         {
            bLocalTempCofan1 = CoFan_bAcvCoFan1Cmd;
         }
         if (bLocalAcvCoFan2Cmd != 0)
         {
            bLocalTempCofan2 = 1;
         }
         else
         {
            bLocalTempCofan2 = CoFan_bAcvCoFan2Cmd;
         }
         u16LocalCoFan_rAcvCoFan1CmdAppld =
            (uint16)MATHSRV_udtMIN(CoFan_rAcvCoFan1Cmd, 32768);
      }
   }
   VEMS_vidSET(CoFan_bAcvCoFan1CmdAppld, bLocalTempCofan1);
   VEMS_vidSET(ThMgt_bCmdHiSpdFan, bLocalTempCofan1);
   VEMS_vidSET(CoFan_bAcvCoFan2CmdAppld, bLocalTempCofan2);
   VEMS_vidSET(ThMgt_bCmdLowSpdFan, bLocalTempCofan2);
   VEMS_vidSET(CoFan_rAcvCoFan1CmdAppld, u16LocalCoFan_rAcvCoFan1CmdAppld);

   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfEquipment);
   if (u8LocalCfEquipment == EQUIPMENT_B1)
   {
      COFANCMDDIAG_vidCoFanCmdB1();
   }
   else
   {
      if (u8LocalCfEquipment == EQUIPMENT_B2)
      {
         COFANCMDDIAG_vidCoFanCmdB2();
      }
      else
      {
         if (u8LocalCfEquipment == EQUIPMENT_C)
         {
            COFANCMDDIAG_vidCoFanCmdC();
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanCmdB1                                 */
/* !Description :  Cette fonction se charge d’envoyer les commandes CMD_GMV1. */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoFan_bAcvCoFan1CmdAppld;                                   */
/*  output boolean Commande_GMV_B1;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanCmdB1(void)
{
   boolean bLocalCoFan_bAcvCoFan1CmdAppld;


   VEMS_vidGET(CoFan_bAcvCoFan1CmdAppld, bLocalCoFan_bAcvCoFan1CmdAppld);
   VEMS_vidSET(Commande_GMV_B1, bLocalCoFan_bAcvCoFan1CmdAppld);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanCmdB2                                 */
/* !Description :  Cette fonction se charge d’envoyer les commandes  CMD_GMV2.*/
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoFan_bAcvCoFan1CmdAppld;                                   */
/*  input boolean CoFan_bAcvCoFan2CmdAppld;                                   */
/*  output boolean Commande_GMV_B1;                                           */
/*  output boolean Commande_GMV_B2;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanCmdB2(void)
{
   boolean bLocalCoFan_bAcvCoFan1CmdAppld;
   boolean bLocalCoFan_bAcvCoFan2CmdAppld;


   VEMS_vidGET(CoFan_bAcvCoFan1CmdAppld, bLocalCoFan_bAcvCoFan1CmdAppld);
   VEMS_vidGET(CoFan_bAcvCoFan2CmdAppld, bLocalCoFan_bAcvCoFan2CmdAppld);
   VEMS_vidSET(Commande_GMV_B1, bLocalCoFan_bAcvCoFan1CmdAppld);
   VEMS_vidSET(Commande_GMV_B2, bLocalCoFan_bAcvCoFan2CmdAppld);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanCmdC                                  */
/* !Description :  Cette fonction envoie les commandes CMD_GMV1 et CMD_GMV2 au*/
/*                 LdB selon l’équipement (C).                                */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoFan_bAcvCoFan2CmdAppld;                                   */
/*  input uint16 CoFan_rAcvCoFan1CmdAppld;                                    */
/*  output boolean Commande_GMV_B2;                                           */
/*  output uint16 Commande_GMV_C;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanCmdC(void)
{
   boolean bLocalCoFan_bAcvCoFan2CmdAppld;
   uint16  u16LocalCoFan_rAcvCoFan1CmdAppld;


   VEMS_vidGET(CoFan_bAcvCoFan2CmdAppld, bLocalCoFan_bAcvCoFan2CmdAppld);
   VEMS_vidGET(CoFan_rAcvCoFan1CmdAppld, u16LocalCoFan_rAcvCoFan1CmdAppld);
   VEMS_vidSET(Commande_GMV_B2, bLocalCoFan_bAcvCoFan2CmdAppld);
   VEMS_vidSET(Commande_GMV_C, u16LocalCoFan_rAcvCoFan1CmdAppld);

}
/*----------------------------------end of file-------------------------------*/