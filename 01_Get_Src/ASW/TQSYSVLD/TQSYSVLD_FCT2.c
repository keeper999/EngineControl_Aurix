/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSYSVLD                                                */
/* !Description     : TQSYSVLD component.                                     */
/*                                                                            */
/* !Module          : TQSYSVLD                                                */
/* !Description     : VALIDITE DES INFORMATIONS COUPLE.                       */
/*                                                                            */
/* !File            : TQSYSVLD_FCT2.C                                         */
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
/*   1 / TQSYSVLD_vidNoWght1                                                  */
/*   2 / TQSYSVLD_vidNoWght2                                                  */
/*   3 / TQSYSVLD_vidNoWght3                                                  */
/*   4 / TQSYSVLD_vidNoWght4                                                  */
/*   5 / TQSYSVLD_vidNoWght5                                                  */
/*                                                                            */
/* !Reference   : V02 NT 09 04105 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/TQSYSVLD/TQSYSVLD_FCT2.C_v        $*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   08 Mar 2010 $*/
/* $Author::   hmelloul                               $$Date::   08 Mar 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQSYSVLD.h"
#include "TQSYSVLD_L.h"
#include "TQSYSVLD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidNoWght1                                        */
/* !Description :  Fonction qui consomme les Flux suivants issus du GAR :     */
/*                 Information couple incertain et couple invalide,           */
/*                 Information couple Easy Move incertain et couple Easy Move */
/*                 invalide et Réalisation consignes ESP impossible et        */
/*                 consignes ESP imprécise                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint8 TqDiag_wghtUncrtTqCkEngReal_C;                                */
/*  input uint8 TqDiag_wghtInvldTqCkEngReal_C;                                */
/*  input uint8 TqDiag_wghtUncrtTqEM_C;                                       */
/*  input uint8 TqDiag_wghtInvldTqEM_C;                                       */
/*  input uint8 TqDiag_wghtInvldTqESPReq_C;                                   */
/*  input uint8 TqDiag_wghtUncrtTqESPReq_C;                                   */
/*  input boolean Diag_misfire_bas_EM;                                        */
/*  input uint8 TqDiag_wghtMisfLoEM_C;                                        */
/*  input boolean Diag_misfire_haut_EM;                                       */
/*  input uint8 TqDiag_wghtMisfHiEM_C;                                        */
/*  input boolean Diag_misfire_bas;                                           */
/*  input uint8 TqDiag_wghtMisfLo_C;                                          */
/*  input boolean Diag_misfire_haut;                                          */
/*  input uint8 TqDiag_wghtMisfHi_C;                                          */
/*  output uint16 TqDiag_noWght1;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidNoWght1(void)
{
   boolean bLocalUncrt_tqCkEngReal;
   boolean bLocalInvld_tqCkEngReal;
   boolean bLocalUncrt_tqEM;
   boolean bLocalInvld_tqEM;
   boolean bLocalInvld_tqESPReq;
   boolean bLocalUncrt_tqESPReq;
   uint32  u32LocalTqDiagNoWght1;


   bLocalUncrt_tqCkEngReal = GDGAR_bGetFRM(FRM_FRM_UNCRT_TQCKENGREAL);
   bLocalInvld_tqCkEngReal = GDGAR_bGetFRM(FRM_FRM_INVLD_TQCKENGREAL);
   bLocalUncrt_tqEM = GDGAR_bGetFRM(FRM_FRM_UNCRT_TQEM);
   bLocalInvld_tqEM = GDGAR_bGetFRM(FRM_FRM_INVLD_TQEM);
   bLocalInvld_tqESPReq = GDGAR_bGetFRM(FRM_FRM_INVLD_TQESPREQ);
   bLocalUncrt_tqESPReq = GDGAR_bGetFRM(FRM_FRM_UNCRT_TQESPREQ);
   u32LocalTqDiagNoWght1 = 0;
   if (bLocalUncrt_tqCkEngReal != 0)
   {
      u32LocalTqDiagNoWght1 = TqDiag_wghtUncrtTqCkEngReal_C;
   }
   if (bLocalInvld_tqCkEngReal != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1
                            + TqDiag_wghtInvldTqCkEngReal_C;
   }
   if (bLocalUncrt_tqEM != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1 + TqDiag_wghtUncrtTqEM_C;
   }
   if (bLocalInvld_tqEM != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1 + TqDiag_wghtInvldTqEM_C;
   }
   if (bLocalInvld_tqESPReq != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1
                            + TqDiag_wghtInvldTqESPReq_C;
   }
   if (bLocalUncrt_tqESPReq != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1
                            + TqDiag_wghtUncrtTqESPReq_C;
   }
   if (Diag_misfire_bas_EM != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1 + TqDiag_wghtMisfLoEM_C;
   }
   if (Diag_misfire_haut_EM != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1 + TqDiag_wghtMisfHiEM_C;
   }
   if (Diag_misfire_bas != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1 + TqDiag_wghtMisfLo_C;
   }
   if (Diag_misfire_haut != 0)
   {
      u32LocalTqDiagNoWght1 = u32LocalTqDiagNoWght1 + TqDiag_wghtMisfHi_C;
   }
   TqDiag_noWght1 = (uint16)MATHSRV_udtMIN(u32LocalTqDiagNoWght1, 1000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidNoWght2                                        */
/* !Description :  Cette fonction consomme les flux issus de l'inter système  */
/*                 qui sont des défaillances portant sur les informations     */
/*                 suivantes : vitesse véhicule, position pédale d'embrayage, */
/*                 puissance consommée par le compresseur de climatisation et */
/*                 charge alternateur.                                        */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean ISCAN_bF38DP010Invld;                                       */
/*  input uint8 TqDiag_wghtIsCanF38DP010Invld_C;                              */
/*  input boolean ISCAN_bF30DP265Invld;                                       */
/*  input uint8 TqDiag_wghtIsCanF30DP265Invld_C;                              */
/*  input boolean ISCAN_bF30DP266Invld;                                       */
/*  input uint8 TqDiag_wghtIsCanF30DP266Invld_C;                              */
/*  input uint8 TqDiag_wghtIsCanP388InvldTx_C;                                */
/*  input boolean ISCAN_bF50EP210Invld;                                       */
/*  input uint8 TqDiag_wghtIsCanF50EP210Invld_C;                              */
/*  input boolean AltCtl_dftComAlt;                                           */
/*  input uint8 TqDiag_wghtdftComAlt_C;                                       */
/*  output uint16 TqDiag_noWght2;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidNoWght2(void)
{
   boolean bLocalAcvIsCanP388InvldTx;
   boolean bLocalAltCtl_dftComAlt;
   boolean bLocalISCAN_bF38DP010Invld;
   boolean bLocalISCAN_bF30DP265Invld;
   boolean bLocalISCAN_bF30DP266Invld;
   boolean bLocalISCAN_bF50EP210Invld;
   uint32  u32LocalTqDiagNoWght2;


   bLocalAcvIsCanP388InvldTx = GDGAR_bGetFRM(FRM_FRM_ACVISCANP388INVLDTX);
   u32LocalTqDiagNoWght2 = 0;
   VEMS_vidGET(ISCAN_bF38DP010Invld, bLocalISCAN_bF38DP010Invld);
   if (bLocalISCAN_bF38DP010Invld != 0)
   {
      u32LocalTqDiagNoWght2 = TqDiag_wghtIsCanF38DP010Invld_C;
   }
   VEMS_vidGET(ISCAN_bF30DP265Invld, bLocalISCAN_bF30DP265Invld);
   if (bLocalISCAN_bF30DP265Invld != 0)
   {
      u32LocalTqDiagNoWght2 = u32LocalTqDiagNoWght2
                            + TqDiag_wghtIsCanF30DP265Invld_C;
   }
   VEMS_vidGET(ISCAN_bF30DP266Invld, bLocalISCAN_bF30DP266Invld);
   if (bLocalISCAN_bF30DP266Invld != 0)
   {
      u32LocalTqDiagNoWght2 = u32LocalTqDiagNoWght2
                           + TqDiag_wghtIsCanF30DP266Invld_C;
   }
   if (bLocalAcvIsCanP388InvldTx != 0)
   {
      u32LocalTqDiagNoWght2 = u32LocalTqDiagNoWght2
                            + TqDiag_wghtIsCanP388InvldTx_C;
   }
   VEMS_vidGET(ISCAN_bF50EP210Invld, bLocalISCAN_bF50EP210Invld);
   if (bLocalISCAN_bF50EP210Invld != 0)
   {
      u32LocalTqDiagNoWght2 = u32LocalTqDiagNoWght2
                            + TqDiag_wghtIsCanF50EP210Invld_C;
   }
   VEMS_vidGET(AltCtl_dftComAlt, bLocalAltCtl_dftComAlt);
   if (bLocalAltCtl_dftComAlt != 0)
   {
      u32LocalTqDiagNoWght2 = u32LocalTqDiagNoWght2
                            + TqDiag_wghtdftComAlt_C;
   }
   TqDiag_noWght2 = (uint16)MATHSRV_udtMIN(u32LocalTqDiagNoWght2, 1000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidNoWght3                                        */
/* !Description :  Cette fonction permet la consommation des lignes de défaut */
/*                 actionneurs suivants : Commande BPM et Commande "          */
/*                 déphaseurs arbre à cames " admission et échappement.       */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint8 TqDiag_wghtThrCmd_C;                                          */
/*  input uint8 TqDiag_wghtVlvActServo_C;                                     */
/*  output uint16 TqDiag_noWght3;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidNoWght3(void)
{
   boolean bLocalAcvWghtThrCmd;
   boolean bLocalAcvWghtVlvActServo;
   uint16  u16LocalTqDiagNoWght3;


   bLocalAcvWghtThrCmd = GDGAR_bGetFRM(FRM_FRM_ACVWGHTTHRCMD);
   bLocalAcvWghtVlvActServo = GDGAR_bGetFRM(FRM_FRM_ACVWGHTVLVACTSERVO);
   u16LocalTqDiagNoWght3 = 0;
   if (bLocalAcvWghtThrCmd != 0)
   {
      u16LocalTqDiagNoWght3 = TqDiag_wghtThrCmd_C;
   }
   if (bLocalAcvWghtVlvActServo != 0)
   {
      u16LocalTqDiagNoWght3 =
            (uint16)(u16LocalTqDiagNoWght3 + TqDiag_wghtVlvActServo_C);
   }
   TqDiag_noWght3 = u16LocalTqDiagNoWght3;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidNoWght4                                        */
/* !Description :  Fonction qui permet la consommation des lignes de défaut   */
/*                 capteurs.                                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint8 TqDiag_wghtSenSync_C;                                         */
/*  input uint8 TqDiag_wghtSentCo_C;                                          */
/*  input uint8 TqDiag_wghtSentAir_C;                                         */
/*  input uint8 TqDiag_wghtSenVlvAct_C;                                       */
/*  input uint8 TqDiag_wghtSenpAir_C;                                         */
/*  input uint8 TqDiag_wghtSenUpLs_C;                                         */
/*  input uint8 TqDiag_wghtPosnSnsr_C;                                        */
/*  input uint8 TqDiag_wghtSenKnk_C;                                          */
/*  input uint8 TqDiag_wghtSenpCircDA_C;                                      */
/*  input uint8 TqDiag_wghtLrnVlvAct_C;                                       */
/*  input uint8 TqDiag_wghtLrnThr_C;                                          */
/*  output uint16 TqDiag_noWght4;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidNoWght4(void)
{
   boolean bLocalAcvWghtSenSync;
   boolean bLocalAcvWghtSentC;
   boolean bLocalAcvWghtSentAir;
   boolean bLocalAcvWghtSenVlvAct;
   boolean bLocalAcvWghtSenpAir;
   boolean bLocalAcvWghtSenUpLs;
   boolean bLocalAcvWghtPosnSnsr;
   boolean bLocalAcvWghtSenKnk;
   boolean bLocalAcvWghtSenpCircDA;
   boolean bLocalAcvWghtLrnVlvAc;
   boolean bLocalAcvWghtLrnThr;
   uint32  u32LocalTqDiagNoWght4;


   bLocalAcvWghtSenSync = GDGAR_bGetFRM(FRM_FRM_ACVWGHTSENSYNC);
   bLocalAcvWghtSentC = GDGAR_bGetFRM(FRM_FRM_ACVWGHTSENTCO);
   bLocalAcvWghtSentAir = GDGAR_bGetFRM(FRM_FRM_ACVWGHTSENTAIR);
   bLocalAcvWghtSenVlvAct = GDGAR_bGetFRM(FRM_FRM_ACVWGHTSENVLVACT);
   bLocalAcvWghtSenpAir = GDGAR_bGetFRM(FRM_FRM_ACVWGHTSENPAIR);
   bLocalAcvWghtSenUpLs = GDGAR_bGetFRM(FRM_FRM_ACVWGHTSENUPLS);
   bLocalAcvWghtPosnSnsr = GDGAR_bGetFRM(FRM_FRM_ACVWGHTPOSNSNSR);
   bLocalAcvWghtSenKnk = GDGAR_bGetFRM(FRM_FRM_ACVWGHTSENKNK);
   bLocalAcvWghtSenpCircDA = GDGAR_bGetFRM(FRM_FRM_ACVWGHTSENPCIRCDA);
   bLocalAcvWghtLrnVlvAc = GDGAR_bGetFRM(FRM_FRM_ACVWGHTLRNVLVACT);
   bLocalAcvWghtLrnThr = GDGAR_bGetFRM(FRM_FRM_ACVWGHTLRNTHR);
   u32LocalTqDiagNoWght4 = 0;
   if (bLocalAcvWghtSenSync != 0)
   {
      u32LocalTqDiagNoWght4 = TqDiag_wghtSenSync_C;
   }
   if (bLocalAcvWghtSentC != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtSentCo_C;
   }
   if (bLocalAcvWghtSentAir != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtSentAir_C;
   }
   if (bLocalAcvWghtSenVlvAct != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtSenVlvAct_C;
   }
   if (bLocalAcvWghtSenpAir != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtSenpAir_C;
   }
   if (bLocalAcvWghtSenUpLs != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtSenUpLs_C;
   }
   if (bLocalAcvWghtPosnSnsr != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtPosnSnsr_C;
   }
   if (bLocalAcvWghtSenKnk != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtSenKnk_C;
   }
   if (bLocalAcvWghtSenpCircDA != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtSenpCircDA_C;
   }
   if (bLocalAcvWghtLrnVlvAc != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtLrnVlvAct_C;
   }
   if (bLocalAcvWghtLrnThr != 0)
   {
      u32LocalTqDiagNoWght4 = u32LocalTqDiagNoWght4 + TqDiag_wghtLrnThr_C;
   }
   TqDiag_noWght4 = (uint16)MATHSRV_udtMIN(u32LocalTqDiagNoWght4, 1000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidNoWght5                                        */
/* !Description :  Fonction qui permet la consommation des informations liées */
/*                 à la gestion carburant                                     */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Coupure_inj_ess_1;                                          */
/*  input boolean Coupure_inj_ess_2;                                          */
/*  input boolean Coupure_inj_ess_3;                                          */
/*  input boolean Coupure_inj_ess_4;                                          */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Nb_Cyl_NoProd;                                                */
/*  input boolean Flev_low_fuel_level_mux;                                    */
/*  input uint8 TqDiag_wghtLoFuLvl_C;                                         */
/*  input uint8 TqDiag_wghtLfbkAfl_C;                                         */
/*  input uint8 TqDiag_wghtLfbkAfr_C;                                         */
/*  input uint8 TqDiag_wghtRatCylNoProd_C;                                    */
/*  input uint8 Rat_Cyl_NoProd;                                               */
/*  output uint8 Nb_Cyl_NoProd;                                               */
/*  output uint8 Rat_Cyl_NoProd;                                              */
/*  output uint16 TqDiag_noWght5;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidNoWght5(void)
{
   boolean bLocalAcvWghtInj1;
   boolean bLocalAcvWghtInj2;
   boolean bLocalAcvWghtInj3;
   boolean bLocalAcvWghtInj4;
   boolean bLocalAcvWghtLfbkAfl;
   boolean bLocalAcvWghtLfbkAfr;
   boolean bLocalCoupure_inj_ess_1;
   boolean bLocalCoupure_inj_ess_2;
   boolean bLocalCoupure_inj_ess_3;
   boolean bLocalCoupure_inj_ess_4;
   boolean bLocalFlev_low_fuel_level_mux;
   uint8   u8LocalNoProd;
   uint8   u8LocalExt_noCylEng;
   uint16  u16LocalNoProd;
   uint16  u16LocalRatCylNoProd;
   uint32  u32LocalTqDiagNoWght5;


   bLocalAcvWghtInj1 = GDGAR_bGetFRM(FRM_FRM_ACVWGHTINJ1);
   bLocalAcvWghtInj2 = GDGAR_bGetFRM(FRM_FRM_ACVWGHTINJ2);
   bLocalAcvWghtInj3 = GDGAR_bGetFRM(FRM_FRM_ACVWGHTINJ3);
   bLocalAcvWghtInj4 = GDGAR_bGetFRM(FRM_FRM_ACVWGHTINJ4);
   bLocalAcvWghtLfbkAfl = GDGAR_bGetFRM(FRM_FRM_ACVWGHTLFBKAFL);
   bLocalAcvWghtLfbkAfr = GDGAR_bGetFRM(FRM_FRM_ACVWGHTLFBKAFR);
   u8LocalNoProd = 0;
   u32LocalTqDiagNoWght5 = 0;
   VEMS_vidGET(Coupure_inj_ess_1, bLocalCoupure_inj_ess_1);
   if (  (bLocalAcvWghtInj1 != 0)
      || (bLocalCoupure_inj_ess_1 != 0))
   {
      u8LocalNoProd = (uint8)(u8LocalNoProd + 1);
   }
   VEMS_vidGET(Coupure_inj_ess_2, bLocalCoupure_inj_ess_2);
   if (  (bLocalAcvWghtInj2 != 0)
      || (bLocalCoupure_inj_ess_2 != 0))
   {
      u8LocalNoProd = (uint8)(u8LocalNoProd + 1);
   }
   VEMS_vidGET(Coupure_inj_ess_3, bLocalCoupure_inj_ess_3);
   if (  (bLocalAcvWghtInj3 != 0)
      || (bLocalCoupure_inj_ess_3 != 0))
   {
      u8LocalNoProd = (uint8)(u8LocalNoProd + 1);
   }
   VEMS_vidGET(Coupure_inj_ess_4, bLocalCoupure_inj_ess_4);
   if (  (bLocalAcvWghtInj4 != 0)
      || (bLocalCoupure_inj_ess_4 != 0))
   {
      u8LocalNoProd = (uint8)(u8LocalNoProd + 1);
   }
   Nb_Cyl_NoProd = u8LocalNoProd;
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   if (u8LocalExt_noCylEng != 0)
   {
      u16LocalRatCylNoProd = (uint16)( (Nb_Cyl_NoProd * 255)
                                     / u8LocalExt_noCylEng);
      Rat_Cyl_NoProd = (uint8)MATHSRV_udtMIN(u16LocalRatCylNoProd, 255);
   }
   else
   {
      Rat_Cyl_NoProd = 255;
   }
   VEMS_vidGET(Flev_low_fuel_level_mux, bLocalFlev_low_fuel_level_mux);
   if (bLocalFlev_low_fuel_level_mux != 0)
   {
      u32LocalTqDiagNoWght5 = TqDiag_wghtLoFuLvl_C;
   }
   if (bLocalAcvWghtLfbkAfl != 0)
   {
      u32LocalTqDiagNoWght5 = u32LocalTqDiagNoWght5 + TqDiag_wghtLfbkAfl_C;
   }
   if (bLocalAcvWghtLfbkAfr != 0)
   {
      u32LocalTqDiagNoWght5 = u32LocalTqDiagNoWght5 + TqDiag_wghtLfbkAfr_C;
   }
   u16LocalNoProd = (uint16)( ( ( TqDiag_wghtRatCylNoProd_C * Rat_Cyl_NoProd)
                                + 128)
                              / 255);
   u32LocalTqDiagNoWght5 = u16LocalNoProd
                         + u32LocalTqDiagNoWght5;

   TqDiag_noWght5 = (uint16)MATHSRV_udtMIN(u32LocalTqDiagNoWght5, 1000);
}

/*------------------------------- end of file --------------------------------*/