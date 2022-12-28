/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGREQH                                                 */
/* !Description     : ENGREQH component.                                      */
/*                                                                            */
/* !Module          : ENGREQH                                                 */
/* !Description     : ERH                                                     */
/*                                                                            */
/* !File            : ENGREQH_FCT3.C                                          */
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
/*   1 / ENGREQH_vidSelectActivFonctions                                      */
/*   2 / ENGREQH_vidDemandeRedemarrage                                        */
/*   3 / ENGREQH_vidRedemBesoinThermCapot                                     */
/*   4 / ENGREQH_vidRedemSeuilTempEssence                                     */
/*   5 / ENGREQH_vidObserTempsMinimumStop                                     */
/*   6 / ENGREQH_vidAutorisMoteurSTOP                                         */
/*   7 / ENGREQH_vidCondRedemaAutonomeSTT                                     */
/*   8 / ENGREQH_vidConditionRegimeMoteur                                     */
/*   9 / ENGREQH_vidCondNombrePMHRestant                                      */
/*   10 / ENGREQH_vidCondRedemarrAutonome                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 05960 / 08                                        */
/* !OtherRefs   : CSMT_CGMT08_2303 / 2.6                                      */
/* !OtherRefs   : VEMS V02 ECU#058179                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/ENGREQH/ENGREQH_FCT3.C$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "GDGAR.h"
#include "MATHSRV.h"
#include "ENGREQH.h"
#include "ENGREQH_L.h"
#include "ENGREQH_IM.h"
#include "VEMS.h"
#include "Std_Limits.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidSelectActivFonctions                            */
/* !Description :  Cette fonction permet de désactiver par calibration chacune*/
/*                 des conditions d’autorisation du STOP. Sur demande d’un    */
/*                 outil test de fin d’assemblage, une sélection calibrable   */
/*                 des conditions d’autorisation peut être réalisée.          */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_002.04                                     */
/*                 VEMS_R_09_05960_025.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPtUH_bFbSpcFactSTTReq1;                                   */
/*  input boolean EngReqH_bTestDeacCdnTCo_C;                                  */
/*  input boolean EngReqH_bAcvStopAuthTCo_C;                                  */
/*  input boolean EngReqH_bAuthStopSTTTCo;                                    */
/*  input boolean EngReqH_bTestDeacCdnTOil_C;                                 */
/*  input boolean EngReqH_bAcvStopAuthTOil_C;                                 */
/*  input boolean EngReqH_bAuthStopSTTTOil;                                   */
/*  input boolean EngReqH_bTestDeacCdnStrtDly_C;                              */
/*  input boolean EngReqH_bAcvStopAuthStrtDly_C;                              */
/*  input boolean EngReqH_bAuthStopSTTStrtDly;                                */
/*  input boolean EngReqH_bTestDeacCdnLsOk_C;                                 */
/*  input boolean EngReqH_bAcvStopAuthLsOk_C;                                 */
/*  input boolean EngReqH_bAuthStopSTTLsOk;                                   */
/*  input boolean EngReqH_bTestDeacCdnTAir_C;                                 */
/*  input boolean EngReqH_bAcvStopAuthTAir_C;                                 */
/*  input boolean EngReqH_bAuthStopSTTTAir;                                   */
/*  input boolean EngReqH_bTestDeacCdnTOxC_C;                                 */
/*  input boolean EngReqH_bAcvStopAuthTOxC_C;                                 */
/*  input boolean EngReqH_bAuthStopSTTTOxC;                                   */
/*  input boolean EngReqH_bTestDeacCdnTTrb_C;                                 */
/*  input boolean EngReqH_bAcvStopAuthTTrb_C;                                 */
/*  input boolean EngReqH_bAuthStopSTTTTrb;                                   */
/*  input boolean EngReqH_bTestDeacCdnPOil_C;                                 */
/*  input boolean EngReqH_bAcvStopAuthPOil_C;                                 */
/*  input boolean EngReqH_bAuthStopSTTPOil;                                   */
/*  input boolean EngReqH_bGlblStopSTTTCo_MP;                                 */
/*  input boolean EngReqH_bGlblStopSTTTOil_MP;                                */
/*  input boolean EngReqH_bGlblStopSTTStrtDly_MP;                             */
/*  input boolean EngReqH_bGlblStopSTTLsOk_MP;                                */
/*  input boolean EngReqH_bGlblStopSTTTAir_MP;                                */
/*  input boolean EngReqH_bGlblStopSTTTOxC_MP;                                */
/*  input boolean EngReqH_bGlblStopSTTTTrb_MP;                                */
/*  input boolean EngReqH_bGlblStopSTTPOil_MP;                                */
/*  output boolean EngReqH_bGlblStopSTTTCo_MP;                                */
/*  output boolean EngReqH_bGlblStopSTTTOil_MP;                               */
/*  output boolean EngReqH_bGlblStopSTTStrtDly_MP;                            */
/*  output boolean EngReqH_bGlblStopSTTLsOk_MP;                               */
/*  output boolean EngReqH_bGlblStopSTTTAir_MP;                               */
/*  output boolean EngReqH_bGlblStopSTTTOxC_MP;                               */
/*  output boolean EngReqH_bGlblStopSTTTTrb_MP;                               */
/*  output boolean EngReqH_bGlblStopSTTPOil_MP;                               */
/*  output boolean EngReqH_bCdnAuthStopSTT;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidSelectActivFonctions(void)
{
   boolean bLocalCoPtUH_bFbSpcFactSTTReq1;


   VEMS_vidGET(CoPtUH_bFbSpcFactSTTReq1,bLocalCoPtUH_bFbSpcFactSTTReq1);
   /*Production of EngReqH_bGlblStopSTTTCo_MP*/
   if ( (EngReqH_bTestDeacCdnTCo_C != 0)
      &&(bLocalCoPtUH_bFbSpcFactSTTReq1 != 0))
   {
      EngReqH_bGlblStopSTTTCo_MP = 1;
   }
   else
   {
      if  (EngReqH_bAcvStopAuthTCo_C != 0)
      {
         EngReqH_bGlblStopSTTTCo_MP = EngReqH_bAuthStopSTTTCo;
      }
      else
      {
         EngReqH_bGlblStopSTTTCo_MP = 1;
      }
   }

   /*Production of EngReqH_bGlblStopSTTTOil_MP*/
   if ( (EngReqH_bTestDeacCdnTOil_C != 0)
      &&(bLocalCoPtUH_bFbSpcFactSTTReq1 != 0))
   {
      EngReqH_bGlblStopSTTTOil_MP = 1;
   }
   else
   {
      if (EngReqH_bAcvStopAuthTOil_C != 0)
      {
         EngReqH_bGlblStopSTTTOil_MP = EngReqH_bAuthStopSTTTOil;
      }
      else
      {
         EngReqH_bGlblStopSTTTOil_MP = 1;
      }
   }

   /*Production of EngReqH_bGlblStopSTTStrtDly_MP */
   if ( (EngReqH_bTestDeacCdnStrtDly_C != 0)
      &&(bLocalCoPtUH_bFbSpcFactSTTReq1 != 0))
   {
      EngReqH_bGlblStopSTTStrtDly_MP = 1;
   }
   else
   {
      if (EngReqH_bAcvStopAuthStrtDly_C != 0)
      {
         EngReqH_bGlblStopSTTStrtDly_MP = EngReqH_bAuthStopSTTStrtDly;
      }
      else
      {
         EngReqH_bGlblStopSTTStrtDly_MP = 1;
      }
   }

   /*Production of EngReqH_bGlblStopSTTLsOk_MP*/
   if ( (EngReqH_bTestDeacCdnLsOk_C != 0)
      &&(bLocalCoPtUH_bFbSpcFactSTTReq1 != 0))
   {
      EngReqH_bGlblStopSTTLsOk_MP = 1;
   }
   else
   {
      if (EngReqH_bAcvStopAuthLsOk_C != 0)
      {
         EngReqH_bGlblStopSTTLsOk_MP = EngReqH_bAuthStopSTTLsOk;
      }
      else
      {
         EngReqH_bGlblStopSTTLsOk_MP = 1;
      }
   }

   /*Production of EngReqH_bGlblStopSTTTAir_MP*/
   if ( (EngReqH_bTestDeacCdnTAir_C != 0)
      &&(bLocalCoPtUH_bFbSpcFactSTTReq1 != 0))
   {
      EngReqH_bGlblStopSTTTAir_MP = 1;
   }
   else
   {
      if (EngReqH_bAcvStopAuthTAir_C != 0)
      {
         EngReqH_bGlblStopSTTTAir_MP = EngReqH_bAuthStopSTTTAir;
      }
      else
      {
         EngReqH_bGlblStopSTTTAir_MP = 1;
      }
   }

   /*Production of EngReqH_bGlblStopSTTTOxC_MP*/
   if ( (EngReqH_bTestDeacCdnTOxC_C != 0)
      &&(bLocalCoPtUH_bFbSpcFactSTTReq1 != 0))
   {
      EngReqH_bGlblStopSTTTOxC_MP = 1;
   }
   else
   {
      if(EngReqH_bAcvStopAuthTOxC_C != 0)
      {
         EngReqH_bGlblStopSTTTOxC_MP = EngReqH_bAuthStopSTTTOxC;
      }
      else
      {
         EngReqH_bGlblStopSTTTOxC_MP = 1;
      }
   }

   /*Production of EngReqH_bGlblStopSTTTTrb_MP*/
   if ( (EngReqH_bTestDeacCdnTTrb_C != 0)
      &&(bLocalCoPtUH_bFbSpcFactSTTReq1 != 0))
   {
      EngReqH_bGlblStopSTTTTrb_MP = 1;
   }
   else
   {
      if (EngReqH_bAcvStopAuthTTrb_C != 0)
      {
         EngReqH_bGlblStopSTTTTrb_MP = EngReqH_bAuthStopSTTTTrb;
      }
      else
      {
         EngReqH_bGlblStopSTTTTrb_MP = 1;
      }
   }

   /*Production of EngReqH_bGlblStopSTTPOil_MP*/
   if ( (EngReqH_bTestDeacCdnPOil_C != 0)
      &&(bLocalCoPtUH_bFbSpcFactSTTReq1 != 0))
   {
      EngReqH_bGlblStopSTTPOil_MP = 1;
   }
   else
   {
      if (EngReqH_bAcvStopAuthPOil_C != 0)
      {
         EngReqH_bGlblStopSTTPOil_MP = EngReqH_bAuthStopSTTPOil;
      }
      else
      {
         EngReqH_bGlblStopSTTPOil_MP = 1;
      }
   }

   /*Production of EngReqH_bCdnAuthStopSTT*/
   if ( (EngReqH_bGlblStopSTTTCo_MP != 0)
      &&(EngReqH_bGlblStopSTTTOil_MP != 0)
      &&(EngReqH_bGlblStopSTTStrtDly_MP != 0)
      &&(EngReqH_bGlblStopSTTLsOk_MP != 0)
      &&(EngReqH_bGlblStopSTTTAir_MP != 0)
      &&(EngReqH_bGlblStopSTTTOxC_MP != 0)
      &&(EngReqH_bGlblStopSTTTTrb_MP != 0)
      &&(EngReqH_bGlblStopSTTPOil_MP != 0))
   {
      EngReqH_bCdnAuthStopSTT = 1;
   }
   else
   {
      EngReqH_bCdnAuthStopSTT = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidDemandeRedemarrage                              */
/* !Description :  Cette fonction fait la synthèse de toutes les demandes de  */
/*                 redémarrage STT.                                           */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_031.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void ENGREQH_vidRedemBesoinThermCapot();                      */
/*  extf argret void ENGREQH_vidRedemSeuilTempEssence();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGREQH_vidObserTempsMinimumStop();                      */
/*  input boolean CoPtUH_bFbSpcFactSTTReq1;                                   */
/*  input boolean EngReqH_bSTTRstrtReqCdnThMgt;                               */
/*  input boolean EngReqH_bSTTRstrtReqCdnTFu;                                 */
/*  output boolean EngReqH_bSyntSTTRstrtReq;                                  */
/*  output boolean EngReqH_bSyntNotSTTRstrtReq;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidDemandeRedemarrage(void)
{
   boolean bLocalAcvEngRstrtSTT;
   boolean bLocalCoPtUH_bFbSpcFactSTTReq1;


   bLocalAcvEngRstrtSTT = GDGAR_bGetFRM(FRM_FRM_ACVENGRSTRTSTT);
   ENGREQH_vidRedemBesoinThermCapot();
   ENGREQH_vidRedemSeuilTempEssence();
   VEMS_vidGET(CoPtUH_bFbSpcFactSTTReq1,bLocalCoPtUH_bFbSpcFactSTTReq1);
   if (bLocalCoPtUH_bFbSpcFactSTTReq1 != 0)
   {
      EngReqH_bSyntSTTRstrtReq = 0;
      EngReqH_bSyntNotSTTRstrtReq = 1;
   }
   else
   {
      if ( (EngReqH_bSTTRstrtReqCdnThMgt != 0)
         ||(bLocalAcvEngRstrtSTT != 0)
         ||(EngReqH_bSTTRstrtReqCdnTFu != 0))
      {
         EngReqH_bSyntSTTRstrtReq = 1;
         EngReqH_bSyntNotSTTRstrtReq = 0;
      }
      else
      {
         EngReqH_bSyntSTTRstrtReq = 0;
         EngReqH_bSyntNotSTTRstrtReq = 1;
      }
   }
   ENGREQH_vidObserTempsMinimumStop();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidRedemBesoinThermCapot                           */
/* !Description :  Cette fonction émet un besoin de redémarrage STT à  partir */
/*                 de l’information en provenance de la fonction de  gestion  */
/*                 de la thermique sous capot.                                */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_032.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean ThMgt_bRstrtReq;                                            */
/*  input boolean EngReqH_bDeacCdnRstrtThMgt_C;                               */
/*  output boolean EngReqH_bSTTRstrtReqCdnThMgt;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidRedemBesoinThermCapot(void)
{
   boolean bLocalThMgt_bRstrtReq;


   VEMS_vidGET(ThMgt_bRstrtReq,bLocalThMgt_bRstrtReq);
   if (EngReqH_bDeacCdnRstrtThMgt_C != 0)
   {
      EngReqH_bSTTRstrtReqCdnThMgt = 0;
   }
   else
   {
      EngReqH_bSTTRstrtReqCdnThMgt = bLocalThMgt_bRstrtReq;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidRedemSeuilTempEssence                           */
/* !Description :  Cette fonction surveille la température d’essence par      */
/*                 rapport à un seuil haut. Si ce seuil est dépassé durant une*/
/*                  phase de STOP, un redémarrage STT est demandé.            */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_033.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input uint16 FuSysM_tFu;                                                  */
/*  input sint16 EngReqH_tFuHiLimSTTRstrtReq_C;                               */
/*  input sint16 EngReqH_tFuHysLimSTTRstrtReq_C;                              */
/*  input boolean EngReqH_bDeacCdnSTTRstrtTFu_C;                              */
/*  input boolean EngReqH_bSTTRstrtReqCdnTFu_MP;                              */
/*  output boolean EngReqH_bSTTRstrtReqCdnTFu_MP;                             */
/*  output boolean EngReqH_bSTTRstrtReqCdnTFu;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidRedemSeuilTempEssence(void)
{
   boolean bLocalInhCdnRstrtTFu;
   uint16  u16LocalFuSysM_tFu;
   sint32  s32LocalFuSysM_tFu;
   sint32  s32LocalLow;


   VEMS_vidGET(FuSysM_tFu, u16LocalFuSysM_tFu);
   bLocalInhCdnRstrtTFu = GDGAR_bGetFRM(FRM_FRM_INHCDNRSTRTTFU);
   s32LocalLow =
      (sint32)(EngReqH_tFuHiLimSTTRstrtReq_C - EngReqH_tFuHysLimSTTRstrtReq_C);
   s32LocalFuSysM_tFu = (sint32)(u16LocalFuSysM_tFu - 40);
    /*Production of EngReqH_bSTTRstrtReqCdnTFu_MP*/
   if (s32LocalFuSysM_tFu <= s32LocalLow)
   {
      EngReqH_bSTTRstrtReqCdnTFu_MP = 0;
   }
   else
   {
      if (s32LocalFuSysM_tFu >= EngReqH_tFuHiLimSTTRstrtReq_C)
      {
         EngReqH_bSTTRstrtReqCdnTFu_MP = 1;
      }
   }
   /*Production of EngReqH_bSTTRstrtReqCdnTFu*/
   if ( (bLocalInhCdnRstrtTFu != 0)
      ||(EngReqH_bDeacCdnSTTRstrtTFu_C != 0))
   {
      EngReqH_bSTTRstrtReqCdnTFu = 0;
   }
   else
   {
      EngReqH_bSTTRstrtReqCdnTFu = EngReqH_bSTTRstrtReqCdnTFu_MP;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidObserTempsMinimumStop                           */
/* !Description :  Cette fonction interdit l’émission d’une demande de        */
/*                 redémarrage STT tant que le système n’est pas resté un     */
/*                 temps  minimum calibrable en phase de STOP.                */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_034.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 ENGREQH_u8CoPTStEngPrev;                                      */
/*  input uint8 EngReqH_tiDlyAutSTTRstrt_C;                                   */
/*  input uint8 ENGREQH_u8STTRstrtReqCount;                                   */
/*  input boolean EngReqH_bSyntSTTRstrtReq;                                   */
/*  input boolean ENGREQH_bOutTurnOnDelay;                                    */
/*  output uint8 ENGREQH_u8STTRstrtReqCount;                                  */
/*  output boolean ENGREQH_bOutTurnOnDelay;                                   */
/*  output uint8 ENGREQH_u8CoPTStEngPrev;                                     */
/*  output boolean EngReqH_bEngRunReq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidObserTempsMinimumStop(void)
{
   uint8  u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   /*Turn_On_Delay*/
   if (u8LocalCoPTSt_stEng == 6)
   {
      if (ENGREQH_u8CoPTStEngPrev != 6)
      {
         ENGREQH_u8STTRstrtReqCount =
            (uint8)MATHSRV_udtMIN(EngReqH_tiDlyAutSTTRstrt_C, 250);
      }
      else
      {
         if (ENGREQH_u8STTRstrtReqCount > 0)
         {
            ENGREQH_u8STTRstrtReqCount =
               (uint8)(ENGREQH_u8STTRstrtReqCount - 1);
         }
      }
      if (ENGREQH_u8STTRstrtReqCount == 0)
      {
         ENGREQH_bOutTurnOnDelay = 1;
      }
      else
      {
         ENGREQH_bOutTurnOnDelay = 0;
      }
   }
   else
   {
      ENGREQH_bOutTurnOnDelay = 0;
   }
   ENGREQH_u8CoPTStEngPrev = (uint8)MATHSRV_udtCLAMP(u8LocalCoPTSt_stEng,
                                                     1,
                                                     15);

   /*Production of EngReqH_bEngRunReq*/
   if ( (EngReqH_bSyntSTTRstrtReq != 0)
      &&(ENGREQH_bOutTurnOnDelay != 0))
   {
      VEMS_vidSET(EngReqH_bEngRunReq, 1);
   }
   else
   {
      VEMS_vidSET(EngReqH_bEngRunReq, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidAutorisMoteurSTOP                               */
/* !Description :  Cette fonction fait la synthèse de toutes les demandes     */
/*                 moteur autorisant le STOP. Chaque demande extérieure peut  */
/*                 être désactivée par calibration.                           */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_026.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqAdp_bInhEngStop;                                          */
/*  input boolean InjSys_bInjSpNotAccu;                                       */
/*  input boolean AFA_bEngStopAuth;                                           */
/*  input boolean CanPurg_bEngStopAuth;                                       */
/*  input boolean CoPtUH_bFbSpcFactSTTReq1;                                   */
/*  input boolean EngReqH_bDeacInhEngStopTqAdp_C;                             */
/*  input uint16 EngReqH_tiInhEngStopTqAdp_C;                                 */
/*  input boolean EngReqH_bDeacInhEngStopAFA_C;                               */
/*  input uint16 EngReqH_tiInhEngStopAFA_C;                                   */
/*  input boolean EngReqH_bDeacInhEngStopCanPurg_C;                           */
/*  input uint16 EngReqH_tiInhEngStopCanPurg_C;                               */
/*  input uint16 EngReqH_tiInhEngStopDft_C;                                   */
/*  input boolean EngReqH_bCdnAuthStopSTT;                                    */
/*  input uint16 EngReqH_tiInhEngStopAuthSTT_C;                               */
/*  input boolean EngReqH_bSyntNotSTTRstrtReq;                                */
/*  input uint16 EngReqH_tiInhEngStopRstrtReq_C;                              */
/*  input boolean EngReqH_bDeacInhEngStopInjSys_C;                            */
/*  input uint16 EngReqH_tiInhEngStopInjSys_C;                                */
/*  input uint16 EngReqH_tiInhEngStopRStrtReq_MP;                             */
/*  input uint16 EngReqH_tiInhEngStopTqAdp_MP;                                */
/*  input uint16 EngReqH_tiInhEngStopAFA_MP;                                  */
/*  input uint16 EngReqH_tiInhEngStopCanPurg_MP;                              */
/*  input uint16 EngReqH_tiInhEngStopDft_MP;                                  */
/*  input uint16 EngReqH_tiInhEngStopAuthSTT_MP;                              */
/*  input uint16 EngReqH_tiInhEngStopInjSys_MP;                               */
/*  input uint16 EngReqH_tiInhEngStop_MP;                                     */
/*  input uint16 EngReqH_tiInhEngStopThdHi_C;                                 */
/*  input uint16 EngReqH_tiInhEngStopThdLo_C;                                 */
/*  output uint16 EngReqH_tiInhEngStopTqAdp_MP;                               */
/*  output uint16 EngReqH_tiInhEngStopAFA_MP;                                 */
/*  output uint16 EngReqH_tiInhEngStopCanPurg_MP;                             */
/*  output uint16 EngReqH_tiInhEngStopDft_MP;                                 */
/*  output uint16 EngReqH_tiInhEngStopAuthSTT_MP;                             */
/*  output uint16 EngReqH_tiInhEngStopRStrtReq_MP;                            */
/*  output uint16 EngReqH_tiInhEngStopInjSys_MP;                              */
/*  output uint16 EngReqH_tiInhEngStop_MP;                                    */
/*  output uint8 EngReqH_stEngStopAuth;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidAutorisMoteurSTOP(void)
{
   boolean bLocalTqAdp_bInhEngStop;
   boolean bLocalAFA_bEngStopAuth;
   boolean bLocalCanPurg_bEngStopAuth;
   boolean bLocalInhEngStopSTT;
   boolean bLocalCoPtUH_bFbSpcFactSTTReq1;
   boolean bLocalInjSys_bInjSpNotAccu;
   uint16  u16LocalMAX_1;
   uint16  u16LocalMAX_2;
   uint16  u16LocalMAX_3;
   uint16  u16LocalMAX_4;
   uint16  u16LocalMAX_5;


   VEMS_vidGET(TqAdp_bInhEngStop, bLocalTqAdp_bInhEngStop);
   VEMS_vidGET(InjSys_bInjSpNotAccu, bLocalInjSys_bInjSpNotAccu);
   VEMS_vidGET(AFA_bEngStopAuth, bLocalAFA_bEngStopAuth);
   VEMS_vidGET(CanPurg_bEngStopAuth, bLocalCanPurg_bEngStopAuth);
   VEMS_vidGET(CoPtUH_bFbSpcFactSTTReq1, bLocalCoPtUH_bFbSpcFactSTTReq1);
   bLocalInhEngStopSTT = GDGAR_bGetFRM(FRM_FRM_INHENGSTOPSTT);

   /*Production of EngReqH_tiInhEngStopTqAdp_MP*/
   if (EngReqH_bDeacInhEngStopTqAdp_C != 0)
   {
      EngReqH_tiInhEngStopTqAdp_MP = 0;
   }
   else
   {
      if (bLocalTqAdp_bInhEngStop == 0)
      {
         EngReqH_tiInhEngStopTqAdp_MP = 0;
      }
      else
      {
         EngReqH_tiInhEngStopTqAdp_MP =
            (uint16)MATHSRV_udtMIN(EngReqH_tiInhEngStopTqAdp_C, 2000);
      }
   }

   /*Production of EngReqH_tiInhEngStopAFA_MP*/
   if (EngReqH_bDeacInhEngStopAFA_C != 0)
   {
      EngReqH_tiInhEngStopAFA_MP = 0;
   }
   else
   {
      if (bLocalAFA_bEngStopAuth != 0)
      {
         EngReqH_tiInhEngStopAFA_MP = 0;
      }
      else
      {
         EngReqH_tiInhEngStopAFA_MP =
            (uint16)MATHSRV_udtMIN(EngReqH_tiInhEngStopAFA_C, 2000);
      }
   }

   /*Production of EngReqH_tiInhEngStopCanPurg_MP*/
   if (EngReqH_bDeacInhEngStopCanPurg_C != 0)
   {
      EngReqH_tiInhEngStopCanPurg_MP = 0;
   }
   else
   {
      if (bLocalCanPurg_bEngStopAuth != 0)
      {
         EngReqH_tiInhEngStopCanPurg_MP = 0;
      }
      else
      {
         EngReqH_tiInhEngStopCanPurg_MP =
            (uint16)MATHSRV_udtMIN(EngReqH_tiInhEngStopCanPurg_C, 2000);
      }
   }

   /*Production of EngReqH_tiInhEngStopDft_MP*/
   if (bLocalInhEngStopSTT == 0)
   {
      EngReqH_tiInhEngStopDft_MP = 0;
   }
   else
   {
      EngReqH_tiInhEngStopDft_MP =
         (uint16)MATHSRV_udtMIN(EngReqH_tiInhEngStopDft_C, 2000);
   }

   /*Production of EngReqH_tiInhEngStopAuthSTT_MP*/
   if (EngReqH_bCdnAuthStopSTT != 0)
   {
      EngReqH_tiInhEngStopAuthSTT_MP = 0;
   }
   else
   {
      EngReqH_tiInhEngStopAuthSTT_MP =
         (uint16)MATHSRV_udtMIN(EngReqH_tiInhEngStopAuthSTT_C, 2000);
   }

   /*Production of EngReqH_tiInhEngStopRStrtReq_MP*/
   if (EngReqH_bSyntNotSTTRstrtReq != 0)
   {
      EngReqH_tiInhEngStopRStrtReq_MP = 0;
   }
   else
   {
      EngReqH_tiInhEngStopRStrtReq_MP =
         (uint16)MATHSRV_udtMIN(EngReqH_tiInhEngStopRstrtReq_C, 2000);
   }

   /*Production of EngReqH_tiInhEngStopInjSys_MP*/
   if (EngReqH_bDeacInhEngStopInjSys_C != 0)
   {
      EngReqH_tiInhEngStopInjSys_MP = 0;
   }
   else
   {
      if (bLocalInjSys_bInjSpNotAccu == 0)
      {
         EngReqH_tiInhEngStopInjSys_MP = 0;
      }
      else
      {
         EngReqH_tiInhEngStopInjSys_MP =
            (uint16)MATHSRV_udtMIN(EngReqH_tiInhEngStopInjSys_C, 2000);
      }
   }

   /*Production of EngReqH_tiInhEngStop_MP*/
   u16LocalMAX_1 = (uint16)MATHSRV_udtMAX(EngReqH_tiInhEngStopRStrtReq_MP,
                                          EngReqH_tiInhEngStopTqAdp_MP);
   u16LocalMAX_2 = (uint16)MATHSRV_udtMAX(EngReqH_tiInhEngStopAFA_MP,
                                          EngReqH_tiInhEngStopCanPurg_MP);
   u16LocalMAX_3 = (uint16)MATHSRV_udtMAX(EngReqH_tiInhEngStopDft_MP,
                                          EngReqH_tiInhEngStopAuthSTT_MP);
   u16LocalMAX_4 = (uint16)MATHSRV_udtMAX(EngReqH_tiInhEngStopInjSys_MP,
                                          u16LocalMAX_1);
   u16LocalMAX_5 = (uint16)MATHSRV_udtMAX(u16LocalMAX_4,u16LocalMAX_2);
   EngReqH_tiInhEngStop_MP = (uint16)MATHSRV_udtMAX(u16LocalMAX_3,
                                                    u16LocalMAX_5);

   /*Production of EngReqH_stEngStopAuth */
   if (bLocalCoPtUH_bFbSpcFactSTTReq1 != 0)
   {
      VEMS_vidSET(EngReqH_stEngStopAuth, 1);
   }
   else
   {
      if (EngReqH_tiInhEngStop_MP == 0)
      {
         VEMS_vidSET(EngReqH_stEngStopAuth, 1);
      }
      else
      {
         if (EngReqH_tiInhEngStop_MP > EngReqH_tiInhEngStopThdHi_C)
         {
            VEMS_vidSET(EngReqH_stEngStopAuth, 0);
         }
         else
         {
            if (EngReqH_tiInhEngStop_MP > EngReqH_tiInhEngStopThdLo_C)
            {
               VEMS_vidSET(EngReqH_stEngStopAuth, 3);
            }
            else
            {
               VEMS_vidSET(EngReqH_stEngStopAuth, 2);
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondRedemaAutonomeSTT                           */
/* !Description :  Cette fonction calcule la condition de redémarrage autonome*/
/*                 lors d’une phase d’arrêt STT.                              */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_037.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGREQH_vidFiltreRegimeMoteur();                         */
/*  extf argret void ENGREQH_vidConditionRegimeMoteur();                      */
/*  extf argret void ENGREQH_vidCondNombrePMHRestant();                       */
/*  extf argret void ENGREQH_vidCondRedemarrAutonome();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondRedemaAutonomeSTT(void)
{
   ENGREQH_vidFiltreRegimeMoteur();
   ENGREQH_vidConditionRegimeMoteur();
   ENGREQH_vidCondNombrePMHRestant();
   ENGREQH_vidCondRedemarrAutonome();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidConditionRegimeMoteur                           */
/* !Description :  La condition de redémarrage autonome lors d’une phase      */
/*                 d’arrêt STT est autorisée si le régime moteur est supérieur*/
/*                 à un seuil fonction de la température moteur et de la      */
/*                 pression atmosphérique.                                    */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_038.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input boolean EngReqH_bCfTEngRstrtAutn_C;                                 */
/*  input sint16 ENGREQH_s16nEngRstrtAutn;                                    */
/*  input uint8 EngReqH_nEngRstrtAutnX_A[12];                                 */
/*  input uint16 EngReqH_nEngRstrtAutn_T[12];                                 */
/*  input uint16 EngReqH_nOfsRstrtAutnX_A[8];                                 */
/*  input uint16 EngReqH_nOfsRstrtAutn_T[8];                                  */
/*  input uint16 EngReqH_nEngFil;                                             */
/*  output sint16 ENGREQH_s16nEngRstrtAutn;                                   */
/*  output boolean EngReqH_bNEngRstrtAutnAvl;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidConditionRegimeMoteur(void)
{
   uint8  u8LocalSiteInterpolation;
   uint16 u16LocalExt_pAirExtMes;
   uint16 u16LocalCalcPara_1;
   uint16 u16LocalCalcPara_2;
   uint16 u16Localinterp_1;
   uint16 u16Localinterp_2;
   sint16 s16LocalExt_tOilMes;
   sint16 s16LocalExt_tCoMes;
   sint16 s16LocalResult;
   uint32 u32LocalSum;


   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   if (EngReqH_bCfTEngRstrtAutn_C != 0)
   {
      s16LocalResult = (sint16)(s16LocalExt_tOilMes / 10);
   }
   else
   {
      s16LocalResult = s16LocalExt_tCoMes;
   }
   ENGREQH_s16nEngRstrtAutn =
      (sint16)MATHSRV_udtCLAMP(s16LocalResult, -50, 200);
   u8LocalSiteInterpolation = (uint8)(ENGREQH_s16nEngRstrtAutn + 50);
   u16LocalCalcPara_1 = MATHSRV_u16CalcParaIncAryU8(EngReqH_nEngRstrtAutnX_A,
                                                    u8LocalSiteInterpolation,
                                                    12);
   u16Localinterp_1 =
      MATHSRV_u16Interp1d(EngReqH_nEngRstrtAutn_T,u16LocalCalcPara_1);

   u16LocalCalcPara_2 = MATHSRV_u16CalcParaIncAryU16(EngReqH_nOfsRstrtAutnX_A,
                                                     u16LocalExt_pAirExtMes,
                                                     8);
   u16Localinterp_2 =
      MATHSRV_u16Interp1d(EngReqH_nOfsRstrtAutn_T, u16LocalCalcPara_2);
   u32LocalSum = (uint32)(u16Localinterp_1 + u16Localinterp_2);
   u32LocalSum = u32LocalSum * 4;

   if ((uint32)EngReqH_nEngFil > u32LocalSum)
   {
      EngReqH_bNEngRstrtAutnAvl = 1;
   }
   else
   {
      EngReqH_bNEngRstrtAutnAvl = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondNombrePMHRestant                            */
/* !Description :  La condition de redémarrage autonome lors d’une phase      */
/*                 d’arrêt STT est autorisée si le nombre de PMH restant      */
/*                 avant l’atteinte du régime nul est supérieur ou égal à un  */
/*                 seuil.                                                     */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_039.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input uint16 EngReqH_nEngFil;                                             */
/*  input uint16 EngReqH_facCorCntTDCX_A[8];                                  */
/*  input uint16 EngReqH_facCorCntTDC_T[8];                                   */
/*  input uint16 EngReqH_jEng_C;                                              */
/*  input uint8 EngReqH_noCyl_C;                                              */
/*  input uint16 EngReqH_facCorCntTDC_MP;                                     */
/*  input uint16 EngReqH_ctTDCPndRaw_MP;                                      */
/*  input uint8 EngReqH_ctTDCPnd_MP;                                          */
/*  input uint8 EngReqH_ctTDCRstrtAutnAvl_C;                                  */
/*  output uint16 EngReqH_facCorCntTDC_MP;                                    */
/*  output uint16 EngReqH_ctTDCPndRaw_MP;                                     */
/*  output uint8 EngReqH_ctTDCPnd_MP;                                         */
/*  output boolean EngReqH_bCntTDCRstrtAutnAvl;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondNombrePMHRestant(void)
{
   boolean bLocal;
   uint16  u16LocalCalcPara;
   uint16  u16Localinterp;
   uint16  u16LocalnEngFil;
   uint16  u16Local;
   uint16  u16LocalTqCmp_tqSumLossCmp;
   sint16  s16LocalTqCmp_tqSumLossCmp;
   uint32  u32LocalMulti;
   uint32  u32LocalDiv;
   uint32  u32LocalFirstValue;
   uint32  u32LocalDenominator;
   uint32  u32LocalProd;
   uint32  u32LocalProd2;
   uint32  u32LocalDiv2;
   uint32  u32LocalResult;


   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);
   /*Production of EngReqH_facCorCntTDC_MP*/
   u16LocalnEngFil = (uint16)(EngReqH_nEngFil / 4);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(EngReqH_facCorCntTDCX_A,
                                                   u16LocalnEngFil,
                                                   8);
   u16Localinterp =
      MATHSRV_u16Interp1d(EngReqH_facCorCntTDC_T, u16LocalCalcPara);
   EngReqH_facCorCntTDC_MP = (uint16)MATHSRV_udtMIN(u16Localinterp, 2000);

   /*Production of EngReqH_ctTDCPndRaw_MP*/
   u32LocalFirstValue = (uint32)( EngReqH_nEngFil
                                * EngReqH_nEngFil);
   if (  (EngReqH_nEngFil == 0)
      || (EngReqH_jEng_C == 0)
      || (EngReqH_noCyl_C == 0))
   {
      bLocal = 0;
   }
   else
   {
      bLocal = 1;
   }
   if (s16LocalTqCmp_tqSumLossCmp <= 0)
   {
      u16LocalTqCmp_tqSumLossCmp = 0;
      u32LocalDenominator = 0;
   }
   else
   {
      u16LocalTqCmp_tqSumLossCmp = (uint16)s16LocalTqCmp_tqSumLossCmp;
      u32LocalDenominator = (uint32)(u16LocalTqCmp_tqSumLossCmp * 60000);
   }

   if (u32LocalDenominator != 0)
   {
      if (bLocal != 0)
      {
         if (u32LocalFirstValue <= (UINT32_MAX / (uint32)EngReqH_jEng_C))
         {
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
            u32LocalProd = u32LocalFirstValue * EngReqH_jEng_C;
            u16Local = (uint16)(EngReqH_noCyl_C * 157);
            if (u32LocalProd <= (UINT32_MAX / (uint32)u16Local))
            {
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
               u32LocalProd2 = u32LocalProd * u16Local;
               u32LocalDiv = u32LocalProd2 / u32LocalDenominator;
               u32LocalResult = u32LocalDiv / 60;
            }
            else
            {
               u32LocalDiv = u32LocalProd / 60000;
               u32LocalProd2 = u32LocalDiv * u16Local;
               u32LocalDiv2 = u16LocalTqCmp_tqSumLossCmp * 60;
               u32LocalResult = u32LocalProd2 / u32LocalDiv2;
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
            }
         }
         else
         {
            u32LocalDiv = u32LocalFirstValue / 72000;
            u32LocalProd = u32LocalDiv * EngReqH_jEng_C;
            u16Local = (uint16)(EngReqH_noCyl_C * 157);
            if (u32LocalProd <= (UINT32_MAX / (uint32)u16Local))
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
            {
               u32LocalProd2 = u32LocalProd * u16Local;
               u32LocalDiv2 = (uint32)(u16LocalTqCmp_tqSumLossCmp * 50);
               u32LocalResult = u32LocalProd2 / u32LocalDiv2;
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
            }
            else
            {
               u32LocalProd2 = u32LocalProd / 50;
               if (u32LocalProd2 <= (UINT32_MAX / (uint32)u16Local))
               {
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
                  u32LocalResult = ( (u32LocalProd2 * u16Local)
                                   / u16LocalTqCmp_tqSumLossCmp);
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
               }
               else
               {
                  u32LocalDiv2 = u32LocalProd2 / u16LocalTqCmp_tqSumLossCmp;
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
                  if (u32LocalDiv2 <= (UINT32_MAX / (uint32)u16Local))
                  {
/*Msg(4:0585) [U] Division by value that is apparently zero.*/
                     u32LocalResult = u32LocalDiv2 * u16Local;
                  }
                  else
                  {
                     u32LocalResult = 25500;
                  }
               }
            }
         }
      }
      else
      {
         u32LocalResult = 0;
      }
   }
   else
   {
      if (s16LocalTqCmp_tqSumLossCmp < 0)
      {
         u32LocalResult = 0;
      }
      else
      {
         u32LocalResult = 25500;
      }
   }
   EngReqH_ctTDCPndRaw_MP = (uint16)MATHSRV_udtMIN(u32LocalResult, 25500);

   u32LocalMulti = (uint32)(( EngReqH_facCorCntTDC_MP
                           * EngReqH_ctTDCPndRaw_MP)
                          / 100000);
   EngReqH_ctTDCPnd_MP = (uint8)MATHSRV_udtMIN(u32LocalMulti, 255);
   /*Production of EngReqH_bCntTDCRstrtAutnAvl*/
   if (EngReqH_ctTDCPnd_MP >= EngReqH_ctTDCRstrtAutnAvl_C)
   {
      EngReqH_bCntTDCRstrtAutnAvl = 1;
   }
   else
   {
      EngReqH_bCntTDCRstrtAutnAvl = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCondRedemarrAutonome                            */
/* !Description :  La condition de redémarrage autonome est calculée à partir */
/*                 des deux conditions calculées précédemment, ainsi  qu’en   */
/*                 fonction de l’état de fonctionnement du moteur.            */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_040.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean EngReqH_bNEngRstrtAutnAvl;                                  */
/*  input boolean EngReqH_bCntTDCRstrtAutnAvl;                                */
/*  input boolean EngReqH_bEngRStrtAutnAvl;                                   */
/*  input boolean EngReqH_bEngRstrtAutnAvlTmp_MP;                             */
/*  output boolean EngReqH_bEngRstrtAutnAvlTmp_MP;                            */
/*  output boolean EngReqH_bEngRStrtAutnAvl;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCondRedemarrAutonome(void)
{
   boolean bLocalEngReqH_bEngRStrtAutnAvl;
   uint8   u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng,u8LocalCoPTSt_stEng);

   if (  (EngReqH_bNEngRstrtAutnAvl != 0)
      && (EngReqH_bCntTDCRstrtAutnAvl != 0))
   {
      EngReqH_bEngRstrtAutnAvlTmp_MP = 1;
   }
   else
   {
      EngReqH_bEngRstrtAutnAvlTmp_MP = 0;
   }

   VEMS_vidGET(EngReqH_bEngRStrtAutnAvl, bLocalEngReqH_bEngRStrtAutnAvl);
   if (  (EngReqH_bEngRstrtAutnAvlTmp_MP != 0)
      || (  (  (u8LocalCoPTSt_stEng == 7)
            || (u8LocalCoPTSt_stEng == 8))
         && (bLocalEngReqH_bEngRStrtAutnAvl != 0)))
   {
      VEMS_vidSET(EngReqH_bEngRStrtAutnAvl,1);
   }
   else
   {
      VEMS_vidSET(EngReqH_bEngRStrtAutnAvl,0);
   }
}
/*-------------------------------- end of file -------------------------------*/