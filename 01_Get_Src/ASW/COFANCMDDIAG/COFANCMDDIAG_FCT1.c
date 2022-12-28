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
/* !File            : COFANCMDDIAG_FCT1.C                                     */
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
/*   1 / COFANCMDDIAG_vidInitOutput                                           */
/*   2 / COFANCMDDIAG_vidInit                                                 */
/*   3 / COFANCMDDIAG_vidInitFricC                                            */
/*   4 / COFANCMDDIAG_vidRstCoFanCtlMng                                       */
/*   5 / COFANCMDDIAG_vidRstDft                                               */
/*   6 / COFANCMDDIAG_vidRstDftFricC                                          */
/*   7 / COFANCMDDIAG_vidCoFanSpdMng                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6722439 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/COFANCMDDIAG/COFANCMDDIAG_FCT1.C_v$*/
/* $Revision::   1.16     $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "COFANCMDDIAG_IM.H"
#include "COFANCMDDIAG_L.H"
#include "COFANCMDDIAG.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidInitOutput                                 */
/* !Description :  Fonction d'intialisation                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 CoFan_rSpdFanCReqFil;                                        */
/*  output boolean CoFan_bFanB2HiSpd2;                                        */
/*  output uint8 CoFan_rSpdFanPred;                                           */
/*  output uint8 COFANCMDDIAG_u8SchmitOutput1;                                */
/*  output boolean Ext_bStFanFil;                                             */
/*  output boolean CoFan_bAcvCoFan1CmdAppld;                                  */
/*  output boolean CoFan_bAcvCoFan2CmdAppld;                                  */
/*  output uint16 CoFan_rAcvCoFan1CmdAppld;                                   */
/*  output uint16 Ext_rStFanC;                                                */
/*  output boolean ThMgt_bCmdHiSpdFan;                                        */
/*  output boolean ThMgt_bCmdLowSpdFan;                                       */
/*  output boolean ThMgt_bTarHiSpdFan;                                        */
/*  output boolean ThMgt_bTarLowSpdFan;                                       */
/*  output boolean Ext_bStFanB1Raw;                                           */
/*  output boolean Ext_bStFanB2Raw;                                           */
/*  output uint8 COFANCMDDIAG_u8LocalCount;                                   */
/*  output boolean COFANCMDDIAG_bStFanCPrev;                                  */
/*  output boolean COFANCMDDIAG_bNoRecThdPrev;                                */
/*  output boolean COFANCMDDIAG_bNoThdPrev;                                   */
/*  output boolean COFANCMDDIAG_bNoMaxThdPrev;                                */
/*  output boolean CoFan_bDgoECI_StFanC;                                      */
/*  output boolean CoFan_bDgoEl_StFanC;                                       */
/*  output boolean COFANCMDDIAG_bFaultOpen1;                                  */
/*  output boolean COFANCMDDIAG_bFaultOpen2;                                  */
/*  output boolean COFANCMDDIAG_bFaultGround1;                                */
/*  output boolean COFANCMDDIAG_bFaultGround2;                                */
/*  output boolean COFANCMDDIAG_bMonRunCoh_B2NoSpd;                           */
/*  output boolean COFANCMDDIAG_bLocalInpTimer1prev;                          */
/*  output boolean COFANCMDDIAG_bLocalInpTimer2prev;                          */
/*  output boolean COFANCMDDIAG_bLocalInpTimer5prev;                          */
/*  output boolean COFANCMDDIAG_bLocalCoFan2Cmdprev;                          */
/*  output boolean COFANCMDDIAG_bLocalCoFan1Cmdprev;                          */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer1;                             */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer3;                             */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer2;                             */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer4;                             */
/*  output uint8 COFANCMDDIAG_u8LocalcountTimer5;                             */
/*  output boolean COFANCMDDIAG_bMonRunCoh_Output;                            */
/*  output boolean Commande_GMV_B1;                                           */
/*  output boolean Commande_GMV_B2;                                           */
/*  output uint16 Commande_GMV_C;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidInitOutput(void)
{
   CoFan_rSpdFanCReqFil = 0;
   CoFan_bFanB2HiSpd2 = 0;
   CoFan_rSpdFanPred = 0;
   COFANCMDDIAG_u8SchmitOutput1 = 0;
   VEMS_vidSET(Ext_bStFanFil, 0);
   VEMS_vidSET(CoFan_bAcvCoFan1CmdAppld, 0);
   VEMS_vidSET(CoFan_bAcvCoFan2CmdAppld, 0);
   VEMS_vidSET(CoFan_rAcvCoFan1CmdAppld, 0);
   VEMS_vidSET(Ext_rStFanC, 0);
   VEMS_vidSET(ThMgt_bCmdHiSpdFan, 0);
   VEMS_vidSET(ThMgt_bCmdLowSpdFan, 0);
   VEMS_vidSET(ThMgt_bTarHiSpdFan, 0);
   VEMS_vidSET(ThMgt_bTarLowSpdFan, 0);
   VEMS_vidSET(Ext_bStFanB1Raw, 0);
   VEMS_vidSET(Ext_bStFanB2Raw, 0);
   COFANCMDDIAG_u8LocalCount = 0;
   COFANCMDDIAG_bStFanCPrev = 1;
   COFANCMDDIAG_bNoRecThdPrev = 1;
   COFANCMDDIAG_bNoThdPrev = 1;
   COFANCMDDIAG_bNoMaxThdPrev = 1;
   CoFan_bDgoECI_StFanC = 0;
   CoFan_bDgoEl_StFanC = 0;
   COFANCMDDIAG_bFaultOpen1 = 0;
   COFANCMDDIAG_bFaultOpen2 = 0;
   COFANCMDDIAG_bFaultGround1 = 0;
   COFANCMDDIAG_bFaultGround2 = 0;
   COFANCMDDIAG_bMonRunCoh_B2NoSpd = 1;
   COFANCMDDIAG_bLocalInpTimer1prev = 0;
   COFANCMDDIAG_bLocalInpTimer2prev = 0;
   COFANCMDDIAG_bLocalInpTimer5prev = 0;
   COFANCMDDIAG_bLocalCoFan2Cmdprev = 0;
   COFANCMDDIAG_bLocalCoFan1Cmdprev = 0;
   COFANCMDDIAG_u8LocalcountTimer1 = 0;
   COFANCMDDIAG_u8LocalcountTimer3 = 0;
   COFANCMDDIAG_u8LocalcountTimer2 = 0;
   COFANCMDDIAG_u8LocalcountTimer4 = 0;
   COFANCMDDIAG_u8LocalcountTimer5 = 0;
   COFANCMDDIAG_bMonRunCoh_Output = 0;
   VEMS_vidSET(Commande_GMV_B1, 0);
   VEMS_vidSET(Commande_GMV_B2 , 0);
   VEMS_vidSET(Commande_GMV_C , 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidInit                                       */
/* !Description :  Cette fonction se charge de récupérer les variables        */
/*                 enregistrées en EEPROM au Réveil Partiel de l’ECU. Il      */
/*                 s’agit des données liées à la stratégie de confirmation    */
/*                 d’un défaut CCA en FRIC C’ qui est définie sur un DC.      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COFANCMDDIAG_vidInitFricC();                             */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidInit(void)
{
   uint8 u8LocalCfCoolFan;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfCoolFan);
   if (u8LocalCfCoolFan == EQUIPMENT_C)
   {
      COFANCMDDIAG_vidInitFricC();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidInitFricC                                  */
/* !Description :  il est nécessaire également d’activer l’entrée ETAT_GMV en */
/*                 mode RCO (API PWDHAL) et de switcher sur la CMD_GMV1 de    */
/*                 type RCO (API PFCHAL).                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 CoFan_noThdCntRskCritScFanC_C;                                */
/*  input uint8 CoFan_ctRskCritScFanC;                                        */
/*  output uint16 CoFan_ctDftStFanC;                                          */
/*  output uint8 CoFan_ctRskCritScFanC;                                       */
/*  output boolean CoFan_bDCDftStFanC;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidInitFricC(void)
{

   CoFan_ctDftStFanC = 0;

   if (CoFan_noThdCntRskCritScFanC_C <= CoFan_ctRskCritScFanC)
   {
      CoFan_ctRskCritScFanC = 0;
   }

   CoFan_bDCDftStFanC = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidRstCoFanCtlMng                             */
/* !Description :  Fonction d'initialisation du manager                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean CoFan_bAcvCoFan1Cmd;                                       */
/*  output uint16 CoFan_rAcvCoFan1Cmd;                                        */
/*  output boolean CoFan_bAcvCoFan2Cmd;                                       */
/*  output uint8 Cf_speed_for_air;                                            */
/*  output boolean FanCtl_bReqIncVoltMin;                                     */
/*  output uint16 CoFan_tiDlyTranActrProt;                                    */
/*  output st59 CoFan_stAcvCoFanCmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidRstCoFanCtlMng(void)
{
   CoFan_bAcvCoFan1Cmd = 0;
   CoFan_rAcvCoFan1Cmd = 0;
   CoFan_bAcvCoFan2Cmd = 0;
   VEMS_vidSET (Cf_speed_for_air, 0);
   VEMS_vidSET(FanCtl_bReqIncVoltMin, 0);
   CoFan_tiDlyTranActrProt = 0;
   CoFan_stAcvCoFanCmd = COFAN_INIT;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidRstDft                                     */
/* !Description :  Fonction de réinitialisation des variables liées à la      */
/*                 stratégie de confirmation d’un défaut CCA en FRIC C.       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COFANCMDDIAG_vidRstDftFricC();                           */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidRstDft(void)
{
   uint8 u8LocalCfCoolFan;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfCoolFan);
   if (u8LocalCfCoolFan == EQUIPMENT_C)
   {
      COFANCMDDIAG_vidRstDftFricC();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidRstDftFricC                                */
/* !Description :  Réinitialisation des variables liées à la stratégie de     */
/*                 confirmation d’un défaut CCA en FRIC C.                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 CoFan_ctDftStFanC;                                          */
/*  output uint8 CoFan_ctRskCritScFanC;                                       */
/*  output uint8 CoFan_ctCritScFanC;                                          */
/*  output boolean CoFan_bDCDftStFanC;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidRstDftFricC(void)
{
   CoFan_ctDftStFanC = 0;
   CoFan_ctRskCritScFanC = 0;
   CoFan_ctCritScFanC = 0;
   CoFan_bDCDftStFanC = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCoFanSpdMng                                */
/* !Description :  Fonction de calcule des vitesses prédites à partir de la   */
/*                 consigne de vitesse GMV.                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COFANCMDDIAG_vidSpdFanB1Mng();                           */
/*  extf argret void COFANCMDDIAG_vidSpdFanB2Mng();                           */
/*  extf argret void COFANCMDDIAG_vidSpdFanCMng();                            */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*  output uint8 CoFan_rSpdFanPred;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCoFanSpdMng(void)
{
   uint8  u8LocalCfCoolFan;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfCoolFan);
   if (u8LocalCfCoolFan == EQUIPMENT_B1)
   {
      COFANCMDDIAG_vidSpdFanB1Mng();
   }
   else
   {
      if (u8LocalCfCoolFan == EQUIPMENT_B2)
      {
         COFANCMDDIAG_vidSpdFanB2Mng();
      }
      else
      {
         if (u8LocalCfCoolFan == EQUIPMENT_C)
         {
            COFANCMDDIAG_vidSpdFanCMng();
         }
         else
         {
            CoFan_rSpdFanPred = 0;
         }
      }
   }
}
/*----------------------------------end of file-------------------------------*/