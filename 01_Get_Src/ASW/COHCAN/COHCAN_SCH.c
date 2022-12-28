/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COHCAN                                                  */
/* !Description     : COHCAN Component                                        */
/*                                                                            */
/* !Module          : COHCAN                                                  */
/* !Description     : COHERENCE CAN INFOS_EOBD_BSI                            */
/*                                                                            */
/* !File            : COHCAN_SCH.C                                            */
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
/*   1 / COHCAN_vidEntryInit                                                  */
/*   2 / Can_EveRxn7F2_CohCan                                                 */
/*   3 / Can_EveRxn5B2_CohCan                                                 */
/*   4 / Can_EveRxn572_CohCan                                                 */
/*   5 / Can_EveRxn412_CohCan                                                 */
/*   6 / Can_EveRxn50E_CohCan                                                 */
/*                                                                            */
/* !Reference   : V02 NT 12 00919 / 02                                        */
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
#include "COHCAN.h"
#include "COHCAN_L.h"
#include "COHCAN_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COHCAN_vidEntryInit                                        */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_12_00919_006.01                                     */
/*                 VEMS_R_12_00919_002.01                                     */
/*                 VEMS_R_12_00919_004.01                                     */
/*                 VEMS_R_12_00919_005.01                                     */
/*                 VEMS_R_12_00919_001.02                                     */
/*                 VEMS_R_12_00919_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : COHCAN_vidEntryInit                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COHCAN_vidEntryInit(void)
{
   COHCAN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn7F2_CohCan                                       */
/* !Description :  Evénement de réception de la trame 7F2h                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_12_00919_006.01                                     */
/*                 VEMS_R_12_00919_001.02                                     */
/*                 VEMS_R_12_00919_002.01                                     */
/*                 VEMS_R_12_00919_003.02                                     */
/*                 VEMS_R_12_00919_004.01                                     */
/*                 VEMS_R_12_00919_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidDiagOBD1();                                    */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 COHCAN_u8Inhib;                                               */
/*  input boolean Ext_bDgoCohBit7_stDftOBD;                                   */
/*  input boolean Ext_bMonRunCoh_stDftOBD;                                    */
/*  input boolean Ext_bDgoCohBit4_stDftOBD;                                   */
/*  input boolean Ext_bDgoCohBit3_stDftOBD;                                   */
/*  input boolean Ext_bDgoCohBit2_stDftOBD;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn7F2_CohCan                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn7F2_CohCan(void)
{
   if (COHCAN_u8Inhib != 0x5A)
   {
      COHCAN_vidDiagOBD1();
      GDGAR_vidGdu(GD_DFT_COHBIT7_STDFTOBD,
                   Ext_bDgoCohBit7_stDftOBD,
                   Ext_bMonRunCoh_stDftOBD,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COHBIT4_STDFTOBD,
                   Ext_bDgoCohBit4_stDftOBD,
                   Ext_bMonRunCoh_stDftOBD,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COHBIT3_STDFTOBD,
                   Ext_bDgoCohBit3_stDftOBD,
                   Ext_bMonRunCoh_stDftOBD,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COHBIT2_STDFTOBD,
                   Ext_bDgoCohBit2_stDftOBD,
                   Ext_bMonRunCoh_stDftOBD,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn5B2_CohCan                                       */
/* !Description :  Evénement de réception de la trame 5B2h                    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_12_00919_001.02                                     */
/*                 VEMS_R_12_00919_002.01                                     */
/*                 VEMS_R_12_00919_003.02                                     */
/*                 VEMS_R_12_00919_004.01                                     */
/*                 VEMS_R_12_00919_005.01                                     */
/*                 VEMS_R_12_00919_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidDiagOBD1();                                    */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 COHCAN_u8Inhib;                                               */
/*  input boolean Ext_bDgoCohBit7_stDftOBD;                                   */
/*  input boolean Ext_bMonRunCoh_stDftOBD;                                    */
/*  input boolean Ext_bDgoCohBit4_stDftOBD;                                   */
/*  input boolean Ext_bDgoCohBit3_stDftOBD;                                   */
/*  input boolean Ext_bDgoCohBit2_stDftOBD;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn5B2_CohCan                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn5B2_CohCan(void)
{
   if (COHCAN_u8Inhib != 0x5A)
   {
      COHCAN_vidDiagOBD1();
      GDGAR_vidGdu(GD_DFT_COHBIT7_STDFTOBD,
                   Ext_bDgoCohBit7_stDftOBD,
                   Ext_bMonRunCoh_stDftOBD,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COHBIT4_STDFTOBD,
                   Ext_bDgoCohBit4_stDftOBD,
                   Ext_bMonRunCoh_stDftOBD,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COHBIT3_STDFTOBD,
                   Ext_bDgoCohBit3_stDftOBD,
                   Ext_bMonRunCoh_stDftOBD,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COHBIT2_STDFTOBD,
                   Ext_bDgoCohBit2_stDftOBD,
                   Ext_bMonRunCoh_stDftOBD,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn572_CohCan                                       */
/* !Description :  Evénement de réception de la trame 572h                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_12_00919_006.01                                     */
/*                 VEMS_R_12_00919_001.02                                     */
/*                 VEMS_R_12_00919_002.01                                     */
/*                 VEMS_R_12_00919_003.02                                     */
/*                 VEMS_R_12_00919_004.01                                     */
/*                 VEMS_R_12_00919_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidDiagBattSys();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 COHCAN_u8Inhib;                                               */
/*  input boolean Ext_bDgoChkBattSys_iBattMes;                                */
/*  input boolean Ext_bMonRunChkBattSys;                                      */
/*  input boolean Ext_bDgoChkBattSys_tBattMes;                                */
/*  input boolean Ext_bDgoChkBattSys_uBattClc;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn572_CohCan                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn572_CohCan(void)
{
   if (COHCAN_u8Inhib != 0x5A)
   {
      COHCAN_vidDiagBattSys();
      GDGAR_vidGdu(GD_DFT_CHKBATTSYS_IBATTMES,
                   Ext_bDgoChkBattSys_iBattMes,
                   Ext_bMonRunChkBattSys,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_CHKBATTSYS_TBATTMES,
                   Ext_bDgoChkBattSys_tBattMes,
                   Ext_bMonRunChkBattSys,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_CHKBATTSYS_UBATTCLC,
                   Ext_bDgoChkBattSys_uBattClc,
                   Ext_bMonRunChkBattSys,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn412_CohCan                                       */
/* !Description :  Evnement de rception de la trame 412                       */
/* !Number      :  SCH.5                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_12_00919_006.01                                     */
/*                 VEMS_R_12_00919_001.02                                     */
/*                 VEMS_R_12_00919_002.01                                     */
/*                 VEMS_R_12_00919_003.02                                     */
/*                 VEMS_R_12_00919_004.01                                     */
/*                 VEMS_R_12_00919_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidDiagModSpd_FuLvl();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 COHCAN_u8Inhib;                                               */
/*  input boolean Ext_bDgoStFuLvlDft;                                         */
/*  input boolean Ext_bMonRunStFuLvlDft;                                      */
/*  input boolean Ext_bDgoCoh_bModSptReq;                                     */
/*  input boolean Ext_bMonRunCoh_bModSptReq;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn412_CohCan                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn412_CohCan(void)
{
   if (COHCAN_u8Inhib != 0x5A)
   {
      COHCAN_vidDiagModSpd_FuLvl();
      GDGAR_vidGdu(GD_DFT_STFULVLDFT,
                   Ext_bDgoStFuLvlDft,
                   Ext_bMonRunStFuLvlDft,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COH_BMODSPTREQ,
                   Ext_bDgoCoh_bModSptReq,
                   Ext_bMonRunCoh_bModSptReq,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn50E_CohCan                                       */
/* !Description :  Evnement de rception de la trame 50E                       */
/* !Number      :  SCH.6                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_12_00919_006.01                                     */
/*                 VEMS_R_12_00919_001.02                                     */
/*                 VEMS_R_12_00919_002.01                                     */
/*                 VEMS_R_12_00919_003.02                                     */
/*                 VEMS_R_12_00919_004.01                                     */
/*                 VEMS_R_12_00919_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COHCAN_vidDiagStCluAC();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 COHCAN_u8Inhib;                                               */
/*  input boolean Ext_bDgoCoh_stCluAC;                                        */
/*  input boolean Ext_bMonRunCoh_stCluAC;                                     */
/*  input boolean Ext_bDgoCoh_stPwrAC;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn50E_CohCan                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn50E_CohCan(void)
{
   if (COHCAN_u8Inhib != 0x5A)
   {
      COHCAN_vidDiagStCluAC();
      GDGAR_vidGdu(GD_DFT_COH_STCLUAC,
                   Ext_bDgoCoh_stCluAC,
                   Ext_bMonRunCoh_stCluAC,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_COH_STPWRAC,
                   Ext_bDgoCoh_stPwrAC,
                   Ext_bMonRunCoh_stCluAC,
                   DIAG_DISPO);
   }
}
/*----------------------------------end of file-------------------------------*/