/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPSTUCKDIAG                                           */
/* !Description     : ACCPSTUCKDIAG component.                                */
/*                                                                            */
/* !Module          : ACCPSTUCKDIAG                                           */
/* !Description     : Diagnostic fonctionnel pedale accelerateur bloquée      */
/*                                                                            */
/* !File            : ACCPSTUCKDIAG_FCT1.C                                    */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / ACCPSTUCKDIAG_vidInitOutput                                          */
/*   2 / ACCPSTUCKDIAG_vidStuckAccPPdlin                                      */
/*   3 / ACCPSTUCKDIAG_vidStuckAccPMonRun                                     */
/*   4 / ACCPSTUCKDIAG_vidMngMonRun                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 01550 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCP/ACCPSTUCKDIAG/ACCPSTUCKDIAG_F$*/
/* $Revision::   1.5      $$Author::   ACHEBINO       $$Date::   22 Feb 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   22 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACCPSTUCKDIAG.h"
#include "ACCPSTUCKDIAG_L.h"
#include "ACCPSTUCKDIAG_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSTUCKDIAG_vidInitOutput                                */
/* !Description :  Initialisation des variables produites dans ce module      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_precise_pedal_position;                                  */
/*  output st32 ACCPSTUCKDIAG_stDiag;                                         */
/*  output uint16 Aps_lck_pdl_pos_fix;                                        */
/*  output uint16 ACCPSTUCKDIAG_u16SsmPrPedPosPrev;                           */
/*  output boolean Aps_lck_brk_pdl_in_prev;                                   */
/*  output boolean AccP_bDgoStuckAccP;                                        */
/*  output boolean Aps_lck_brk_pdl_in;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSTUCKDIAG_vidInitOutput(void)
{
   uint16 u16LocalSsm_precise_pedal_pos;


   /* State machine Initialization */
   VEMS_vidGET(Ssm_precise_pedal_position, u16LocalSsm_precise_pedal_pos);
   ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8INIT;
   Aps_lck_pdl_pos_fix = (uint16)MATHSRV_udtMIN(u16LocalSsm_precise_pedal_pos,
                                               1024);
   /* Previous values Initialization */
   ACCPSTUCKDIAG_u16SsmPrPedPosPrev = 0;
   Aps_lck_brk_pdl_in_prev = 0;

   AccP_bDgoStuckAccP = 0;
   Aps_lck_brk_pdl_in = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSTUCKDIAG_vidStuckAccPPdlin                            */
/* !Description :  Cette fonction donne l’état «frein appuyé ».               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Bps_brake_pedal_can_input;                                  */
/*  input boolean Ext_bSecBrkPedPrssMes;                                      */
/*  input boolean Bps_brake_pedal_can_hs;                                     */
/*  input boolean Aps_lck_brk_pdl_in;                                         */
/*  output boolean Aps_lck_brk_pdl_in_prev;                                   */
/*  output boolean Aps_lck_brk_pdl_in;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSTUCKDIAG_vidStuckAccPPdlin(void)
{
   boolean bLocalBps_brake_pedal_can_input;
   boolean bLocalExt_bSecBrkPedPrssMes;
   boolean bLocalBps_brake_pedal_can_hs;

   VEMS_vidGET(Bps_brake_pedal_can_input, bLocalBps_brake_pedal_can_input);
   VEMS_vidGET(Ext_bSecBrkPedPrssMes, bLocalExt_bSecBrkPedPrssMes);
   VEMS_vidGET(Bps_brake_pedal_can_hs, bLocalBps_brake_pedal_can_hs);

   Aps_lck_brk_pdl_in_prev = Aps_lck_brk_pdl_in;

   if (  (bLocalBps_brake_pedal_can_input != 0)
      && (bLocalExt_bSecBrkPedPrssMes != 0)
      && (bLocalBps_brake_pedal_can_hs == 0))
   {
      Aps_lck_brk_pdl_in = 1;
   }
   else
   {
      Aps_lck_brk_pdl_in = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSTUCKDIAG_vidStuckAccPMonRun                           */
/* !Description :  Cette fonction gère les phases d’activation du diagnostic. */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPSTUCKDIAG_vidMngMonRun();                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_precise_pedal_position;                                  */
/*  output uint16 ACCPSTUCKDIAG_u16SsmPrPedPosPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSTUCKDIAG_vidStuckAccPMonRun(void)
{
   uint16 u16LocalSsm_precise_pedal_pos;


   ACCPSTUCKDIAG_vidMngMonRun();

   VEMS_vidGET(Ssm_precise_pedal_position, u16LocalSsm_precise_pedal_pos);
   ACCPSTUCKDIAG_u16SsmPrPedPosPrev =
      (uint16)MATHSRV_udtMIN(u16LocalSsm_precise_pedal_pos, 1024);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSTUCKDIAG_vidMngMonRun                                 */
/* !Description :  Cette fonction gère les phases d’activation du diagnostic. */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_09_01550_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Ssm_precise_pedal_position;                                  */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Aps_lck_pdl_pos_fix;                                         */
/*  input st32 ACCPSTUCKDIAG_stDiag;                                          */
/*  input uint16 ACCPSTUCKDIAG_u16SsmPrPedPosPrev;                            */
/*  input uint16 Aps_lck_pdl_pos_min_thresh;                                  */
/*  input uint16 Aps_lck_vs_min_thresh;                                       */
/*  input uint16 Aps_lck_n_min_thresh;                                        */
/*  input uint16 Aps_lck_pdl_pos_delta;                                       */
/*  input boolean Aps_lck_brk_pdl_in;                                         */
/*  input boolean Aps_lck_brk_pdl_in_prev;                                    */
/*  input uint16 Aps_lck_pdl_pos_hyst;                                        */
/*  input uint16 Aps_lck_vs_hyst;                                             */
/*  input uint16 Aps_lck_n_hyst;                                              */
/*  input uint16 Aps_lck_pdl_pos_devalid_delta;                               */
/*  output st32 ACCPSTUCKDIAG_stDiag;                                         */
/*  output boolean AccP_bMonRunStuckAccP;                                     */
/*  output boolean AccP_bDgoStuckAccP;                                        */
/*  output uint16 Aps_lck_pdl_pos_fix;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSTUCKDIAG_vidMngMonRun(void)
{
   boolean bLocalInhMonStuckAccP;
   boolean bLocalCfmStuckAccP;
   uint8   u8LocalVitesse_vehicule;
   uint16  u16LocalVitesse_vehicule;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalSsm_precise_pedal_pos;
   uint16  u16LocalSsmPrecisePedalDiff;
   uint16  u16LocalAps_lck_pdl_pos_fix;
   uint32  u32LocalSsmPrecisePedalDiff;
   uint32  u32LocalAps_lck_pdl_pos_fix;
   sint32  s32LocalSsmPrecisePedalDiff;
   sint32  s32LocalAps_lck_pdl_pos_Diff;
   sint32  s32LocalAps_lck_vs_Diff;
   sint32  s32LocalAps_lck_n_Diff;
   sint32  s32LocalAps_lck_pdl_pos_fix;


   VEMS_vidGET(Ssm_precise_pedal_position, u16LocalSsm_precise_pedal_pos);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);

   bLocalInhMonStuckAccP = GDGAR_bGetFRM(FRM_FRM_INHMONSTUCKACCP);
   bLocalCfmStuckAccP = GDGAR_bGetFRM(FRM_FRM_CFMSTUCKACCP);
   u16LocalAps_lck_pdl_pos_fix = Aps_lck_pdl_pos_fix;
   u16LocalVitesse_vehicule = (uint16)(128 * u8LocalVitesse_vehicule);

   switch (ACCPSTUCKDIAG_stDiag)
   {
      case ACCPSTUCKDIAG_u8INIT:
         ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8DIAG_NON_ACTIF;
         AccP_bMonRunStuckAccP = 0;
         AccP_bDgoStuckAccP = 0 ;
         u16LocalAps_lck_pdl_pos_fix = u16LocalSsm_precise_pedal_pos;
         break;

      case ACCPSTUCKDIAG_u8DIAG_NON_ACTIF:

         if (bLocalCfmStuckAccP != 0)
         {
            AccP_bMonRunStuckAccP = 1;
            ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8DEFAUT_CONFIRME;
            AccP_bDgoStuckAccP = 1;
         }
         else
         {
            s32LocalSsmPrecisePedalDiff =
               (sint32)( u16LocalSsm_precise_pedal_pos
                       - ACCPSTUCKDIAG_u16SsmPrPedPosPrev);
            u32LocalSsmPrecisePedalDiff =
               (uint32)MATHSRV_udtABS(s32LocalSsmPrecisePedalDiff);
            u16LocalSsmPrecisePedalDiff =
               (uint16)MATHSRV_udtMIN(u32LocalSsmPrecisePedalDiff, 1024);
            if (  (u16LocalSsm_precise_pedal_pos > Aps_lck_pdl_pos_min_thresh)
               && (u16LocalVitesse_vehicule > Aps_lck_vs_min_thresh)
               && (u16LocalRegime_moteur > Aps_lck_n_min_thresh)
               && ( u16LocalSsmPrecisePedalDiff < Aps_lck_pdl_pos_delta)
               && (Aps_lck_brk_pdl_in != 0)
               && (Aps_lck_brk_pdl_in_prev == 0)
               && (bLocalInhMonStuckAccP == 0))
            {
               AccP_bMonRunStuckAccP = 1;
               ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8DEFAUT_NON_CONFIRME;
               u16LocalAps_lck_pdl_pos_fix = u16LocalSsm_precise_pedal_pos;
               AccP_bDgoStuckAccP = 1;
            }
         }
         break;

      case ACCPSTUCKDIAG_u8DEFAUT_NON_CONFIRME:
         if ( bLocalCfmStuckAccP != 0)
         {
            AccP_bMonRunStuckAccP = 1;
            ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8DEFAUT_CONFIRME;
            AccP_bDgoStuckAccP = 1;
         }
         else
         {
            s32LocalAps_lck_pdl_pos_Diff = ( Aps_lck_pdl_pos_min_thresh
                                           - Aps_lck_pdl_pos_hyst);
            s32LocalAps_lck_vs_Diff = (Aps_lck_vs_min_thresh - Aps_lck_vs_hyst);
            s32LocalAps_lck_n_Diff = (Aps_lck_n_min_thresh - Aps_lck_n_hyst);
            s32LocalAps_lck_pdl_pos_fix = ( u16LocalSsm_precise_pedal_pos
                                          - Aps_lck_pdl_pos_fix);
            u32LocalAps_lck_pdl_pos_fix =
                  (uint32)MATHSRV_udtABS(s32LocalAps_lck_pdl_pos_fix);
            if (  (  (  u16LocalSsm_precise_pedal_pos
                     <= s32LocalAps_lck_pdl_pos_Diff)
                  || (u16LocalVitesse_vehicule <= s32LocalAps_lck_vs_Diff)
                  || (u16LocalRegime_moteur <= s32LocalAps_lck_n_Diff)
                  || (  u32LocalAps_lck_pdl_pos_fix
                     >= Aps_lck_pdl_pos_devalid_delta)
                  || (Aps_lck_brk_pdl_in == 0)
                  || (bLocalInhMonStuckAccP != 0)))
            {
               ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8DIAG_NON_ACTIF;
               AccP_bMonRunStuckAccP = 0;
               AccP_bDgoStuckAccP = 0;
               u16LocalAps_lck_pdl_pos_fix = u16LocalSsm_precise_pedal_pos;
            }
         }
         break;

      case ACCPSTUCKDIAG_u8DEFAUT_CONFIRME:
         s32LocalAps_lck_pdl_pos_fix = ( u16LocalSsm_precise_pedal_pos
                                       - Aps_lck_pdl_pos_fix);
         u32LocalAps_lck_pdl_pos_fix =
            (uint32)MATHSRV_udtABS(s32LocalAps_lck_pdl_pos_fix);
         if (  (u32LocalAps_lck_pdl_pos_fix >= Aps_lck_pdl_pos_devalid_delta)
            && (Aps_lck_brk_pdl_in == 0))
         {
            ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8DEVALIDATION;
            AccP_bDgoStuckAccP = 0;
         }
         break;

      case ACCPSTUCKDIAG_u8DEVALIDATION:
         if ( bLocalCfmStuckAccP == 0)
         {
            ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8DIAG_NON_ACTIF;
            AccP_bMonRunStuckAccP = 0;
            AccP_bDgoStuckAccP = 0 ;
            u16LocalAps_lck_pdl_pos_fix = u16LocalSsm_precise_pedal_pos;
         }
         else
         {
            s32LocalAps_lck_pdl_pos_fix = ( u16LocalSsm_precise_pedal_pos
                                          - Aps_lck_pdl_pos_fix);
            u32LocalAps_lck_pdl_pos_fix =
               (uint32)MATHSRV_udtABS(s32LocalAps_lck_pdl_pos_fix);
            if (  (u32LocalAps_lck_pdl_pos_fix < Aps_lck_pdl_pos_devalid_delta)
               || (Aps_lck_brk_pdl_in != 0))
            {
               AccP_bMonRunStuckAccP = 1;
               ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8DEFAUT_CONFIRME;
               AccP_bDgoStuckAccP = 1;
            }
         }
         break;

      default:
         ACCPSTUCKDIAG_stDiag = ACCPSTUCKDIAG_u8INIT;
         u16LocalAps_lck_pdl_pos_fix = u16LocalSsm_precise_pedal_pos;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   Aps_lck_pdl_pos_fix =
      (uint16)MATHSRV_udtMIN(u16LocalAps_lck_pdl_pos_fix, 1024);
}
/*------------------------------- end of file --------------------------------*/