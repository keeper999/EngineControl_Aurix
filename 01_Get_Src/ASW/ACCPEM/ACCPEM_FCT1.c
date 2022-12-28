/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPEM                                                  */
/* !Description     : ACCPEM Component                                        */
/*                                                                            */
/* !Module          : ACCPEM                                                  */
/* !Description     : Calcul de l’enfoncement de la pédale d’accélérateur pour*/
/*                    Easy Move                                               */
/*                                                                            */
/* !File            : ACCPEM_FCT1.C                                           */
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
/*   1 / ACCPEM_vidInitOutput                                                 */
/*   2 / ACCPEM_vidPosPedFinale                                               */
/*   3 / ACCPEM_vidDiagCoh                                                    */
/*   4 / ACCPEM_vidPosPedValid                                                */
/*   5 / ACCPEM_vidPosPedKOff                                                 */
/*   6 / ACCPEM_vidAccPCohAuth                                                */
/*   7 / ACCPEM_vidAccPCohDiag                                                */
/*   8 / ACCPEM_vidInit                                                       */
/*   9 / ACCPEM_vidPosPedRst                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5021748 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCPEM/ACCPEM_FCT1.c_v            $*/
/* $Revision::   1.4      $$Author::   hmelloul       $$Date::   26 Sep 2014 $*/
/* $Author::   hmelloul                               $$Date::   26 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "ACCPEM.H"
#include "ACCPEM_L.H"
#include "ACCPEM_IM.H"
#include "MATHSRV.H"
#include "NVMSRV.h"
#include "GDGAR.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidInitOutput                                       */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 ACCPEM_u16AccP_tiInhCohTest;                                */
/*  output boolean ACCPEM_bFRM_InhDiagCohrAccPrev;                            */
/*  output boolean ACCPEM_bRstSwReqAntPrev;                                   */
/*  output boolean ACCPEM_bRstHwReqAntPrev;                                   */
/*  output boolean ACCPEM_bAcvSaveAccPInvldPrev;                              */
/*  output uint16 ACCPEM_u16AccPRAccPSens1Prev2;                              */
/*  output uint16 ACCPEM_u16AccPRAccPSens1Prev;                               */
/*  output uint16 ACCPEM_u16AccPRAccPSens2Prev2;                              */
/*  output uint16 ACCPEM_u16AccPRAccPSens2Prev;                               */
/*  output boolean AccP_bDgoCoh_rAccP;                                        */
/*  output uint16 AccP_rAccPLim;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidInitOutput(void)
{
   ACCPEM_u16AccP_tiInhCohTest = 0;
   ACCPEM_bFRM_InhDiagCohrAccPrev = 0;
   ACCPEM_bRstSwReqAntPrev = 0;
   ACCPEM_bRstHwReqAntPrev = 0;
   ACCPEM_bAcvSaveAccPInvldPrev = 0;
   ACCPEM_u16AccPRAccPSens1Prev2 = 0;
   ACCPEM_u16AccPRAccPSens1Prev = 0;
   ACCPEM_u16AccPRAccPSens2Prev2 = 0;
   ACCPEM_u16AccPRAccPSens2Prev = 0;
   AccP_bDgoCoh_rAccP = 0;
   AccP_rAccPLim = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidPosPedFinale                                     */
/* !Description :  En cas de défaut pédale bloquée confirmé l’enfoncement     */
/*                 pédale est forcé à 0.                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_05596_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void ACCPEM_vidAccPReinfPos();                                */
/*  extf argret void ACCPEM_vidAccPSatPos();                                  */
/*  input uint16 AccP_rAccPLim;                                               */
/*  output uint16 AccP_rAccPFinal;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidPosPedFinale(void)
{
   boolean bLocalInhDiagCoh_rAccP;


   bLocalInhDiagCoh_rAccP = GDGAR_bGetFRM(FRM_FRM_INHDIAGCOH_RACCP);

   ACCPEM_vidAccPReinfPos();
   ACCPEM_vidAccPSatPos();

   if (bLocalInhDiagCoh_rAccP != 0)
   {
      AccP_rAccPFinal = 0;
   }
   else
   {
      AccP_rAccPFinal = (uint16)MATHSRV_udtMIN(AccP_rAccPLim, 12800);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidDiagCoh                                          */
/* !Description :  test de cohérence des enfoncements pédale entre la variable*/
/*                 position pédale et la position pédale pour Easy Move.      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_05596_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPEM_vidAccPCohAuth();                                 */
/*  extf argret void ACCPEM_vidAccPCohDiag();                                 */
/*  input boolean AccP_bMonRunCoh_rAccP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidDiagCoh(void)
{
   ACCPEM_vidAccPCohAuth();
   if (AccP_bMonRunCoh_rAccP != 0)
   {
      ACCPEM_vidAccPCohDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidPosPedValid                                      */
/* !Description :  Forcer la variable AccPEM_rAccP à sa valeur invalide avant */
/*                 de la transmettre sur le CAN en cas de défaut électrique , */
/*                 ou en cas de  défaut de cohérence entre les enfoncements   */
/*                 pédale,                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_05596_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AccP_rAccPFinal;                                             */
/*  input uint8 AccPEM_rAccP;                                                 */
/*  output boolean AccPEM_bAccPInvld;                                         */
/*  output uint8 AccPEM_rAccP;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidPosPedValid(void)
{
   boolean bLocalCohAccP;
   uint8   u8LocalAccPEM_rPosPed;
   uint16  u16LocalAccPEM_rPosPed;


   bLocalCohAccP = GDGAR_bGetFRM(FRM_FRM_COHACCP);
   VEMS_vidSET(AccPEM_bAccPInvld, bLocalCohAccP);
   if (bLocalCohAccP == 0)
   {
      u16LocalAccPEM_rPosPed = (uint16)(AccP_rAccPFinal / 64);
      u8LocalAccPEM_rPosPed =
         (uint8)MATHSRV_udtMIN(u16LocalAccPEM_rPosPed, 200);
   }
   else
   {
      VEMS_vidGET(AccPEM_rAccP, u8LocalAccPEM_rPosPed);
      u8LocalAccPEM_rPosPed = (uint8)MATHSRV_udtMIN(u8LocalAccPEM_rPosPed, 200);
   }
   VEMS_vidSET(AccPEM_rAccP, u8LocalAccPEM_rPosPed);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidPosPedKOff                                       */
/* !Description :  Au Key-Off, si le paramètre P334 n’est pas à sa valeur     */
/*                 invalide alors on force sa valeur à 0.                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_05596_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 AccPEM_rAccP;                                                */
/*  output boolean AccPEM_bAccPInvld;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidPosPedKOff(void)
{
   VEMS_vidSET(AccPEM_rAccP, 0);
   VEMS_vidSET(AccPEM_bAccPInvld, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidAccPCohAuth                                      */
/* !Description :  Le test de cohérence est autorisé lorsqu’on est au Key ON. */
/*                 Il est inhibé lorsque le défaut pédale bloquée passe en    */
/*                 état fugitif pendant un temps calibrable.                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean ACCPEM_bFRM_InhDiagCohrAccPrev;                             */
/*  input uint8 AccP_tiInhCohTest_C;                                          */
/*  input uint16 ACCPEM_u16AccP_tiInhCohTest;                                 */
/*  output uint16 ACCPEM_u16AccP_tiInhCohTest;                                */
/*  output boolean ACCPEM_bFRM_InhDiagCohrAccPrev;                            */
/*  output boolean AccP_bMonRunCoh_rAccP;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidAccPCohAuth(void)
{
   boolean bLocalInhDiagCoh_rAccP;
   boolean bLocalClef_de_contact;
   sint32  s32LocalACCPEM_AccP_tiInhCoh;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   bLocalInhDiagCoh_rAccP = GDGAR_bGetFRM(FRM_FRM_INHDIAGCOH_RACCP);
   if(  (ACCPEM_bFRM_InhDiagCohrAccPrev != 0)
     && (bLocalInhDiagCoh_rAccP == 0))
   {
      ACCPEM_u16AccP_tiInhCohTest = (uint16)(AccP_tiInhCohTest_C * 10);
   }
   else
   {
      s32LocalACCPEM_AccP_tiInhCoh = (sint32)(ACCPEM_u16AccP_tiInhCohTest - 1);
      ACCPEM_u16AccP_tiInhCohTest =
         (uint16) MATHSRV_udtMAX(s32LocalACCPEM_AccP_tiInhCoh, 0);
   }
   ACCPEM_bFRM_InhDiagCohrAccPrev = bLocalInhDiagCoh_rAccP;
   if (  (ACCPEM_u16AccP_tiInhCohTest == 0)
      && (bLocalClef_de_contact != 0)
      && (bLocalInhDiagCoh_rAccP == 0))
   {
      AccP_bMonRunCoh_rAccP = 1;
   }
   else
   {
      AccP_bMonRunCoh_rAccP = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidAccPCohDiag                                      */
/* !Description :  Si la position pédale pour Easy Move est supérieure à la   */
/*                 position pédale AccP_rAccP et si le paramètre P334 n’est   */
/*                 pas à la valeur invalide, on lève un diagnostic de         */
/*                 cohérence.                                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean AccPEM_bAccPInvld;                                          */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint16 AccPEM_rPosPedCohThd_C;                                      */
/*  input uint16 AccP_rAccPFinal;                                             */
/*  output boolean AccP_bDgoCoh_rAccP;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidAccPCohDiag(void)
{
   boolean bLocalAccPEM_bAccPInvld;
   uint16  u16LocalAccP_rAccP;
   uint32  u32LocalSum;


   VEMS_vidGET(AccPEM_bAccPInvld, bLocalAccPEM_bAccPInvld);
   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   u32LocalSum = (uint32)(u16LocalAccP_rAccP + AccPEM_rPosPedCohThd_C);

   if (  (AccP_rAccPFinal > u32LocalSum)
      && (bLocalAccPEM_bAccPInvld == 0))
   {
      AccP_bDgoCoh_rAccP = 1;
   }
   else
   {
      AccP_bDgoCoh_rAccP = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidInit                                             */
/* !Description :  Cette fonction permet d'initialiser l'indicateur de        */
/*                 l'invalidité et la sortie AccPEM_rAccP.                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 AccPEM_rAccP;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidInit(void)
{
   VEMS_vidSET(AccPEM_rAccP, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidPosPedRst                                        */
/* !Description :  Cette fonction permet d'ecrire en mémoire sur évènement.   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/* argin boolean bMode);                                                      */
/*  input boolean SftyMgt_bRstSwReqAnt;                                       */
/*  input boolean SftyMgt_bRstHwReqAnt;                                       */
/*  input boolean ACCPEM_bRstSwReqAntPrev;                                    */
/*  input boolean ACCPEM_bRstHwReqAntPrev;                                    */
/*  input boolean ACCPEM_bAcvSaveAccPInvldPrev;                               */
/*  output boolean ACCPEM_bRstSwReqAntPrev;                                   */
/*  output boolean ACCPEM_bRstHwReqAntPrev;                                   */
/*  output boolean ACCPEM_bAcvSaveAccPInvldPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidPosPedRst(void)
{
   boolean bLocalSftyMgt_bRstSwReqAnt;
   boolean bLocalSftyMgt_bRstHwReqAnt;
   boolean bLocalAcvSaveAccPInvld;


   VEMS_vidGET(SftyMgt_bRstSwReqAnt, bLocalSftyMgt_bRstSwReqAnt);
   VEMS_vidGET(SftyMgt_bRstHwReqAnt, bLocalSftyMgt_bRstHwReqAnt);
   bLocalAcvSaveAccPInvld = GDGAR_bGetFRM(FRM_FRM_ACVSAVEACCPINVLD);
   if (  (  (bLocalSftyMgt_bRstSwReqAnt != 0)
            && (ACCPEM_bRstSwReqAntPrev == 0))
         || (  (bLocalSftyMgt_bRstHwReqAnt != 0)
            && (ACCPEM_bRstHwReqAntPrev == 0))
         || (  (bLocalAcvSaveAccPInvld != 0)
            && (ACCPEM_bAcvSaveAccPInvldPrev == 0)))
   {
      NVMSRV_vidWrite(NVMSRV_u16OBJ_ACCPEM, NVMSRV_bSAVE_NOW);
   }
   ACCPEM_bRstSwReqAntPrev = bLocalSftyMgt_bRstSwReqAnt;
   ACCPEM_bRstHwReqAntPrev = bLocalSftyMgt_bRstHwReqAnt;
   ACCPEM_bAcvSaveAccPInvldPrev = bLocalAcvSaveAccPInvld;
}
/*------------------------------end of file-----------------------------------*/