/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGBRKPEDNOBVH2P                                       */
/* !Description     : DIAGBRKPEDNOBVH2P component                             */
/*                                                                            */
/* !Module          : DIAGBRKPEDNOBVH2P                                       */
/* !Description     : DIAGNOSTIC DE LA PEDALE DE FREIN HORS BVH2PRIME         */
/*                                                                            */
/* !File            : DIAGBRKPEDNOBVH2P_FCT1.C                                */
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
/*   1 / DIAGBRKPEDNOBVH2P_vidInitOutput                                      */
/*   2 / DIAGBRKPEDNOBVH2P_vidFnctionCall                                     */
/*   3 / DIAGBRKPEDNOBVH2P_vidDiagBrkPMng                                     */
/*   4 / DIAGBRKPEDNOBVH2P_vidDiagManager                                     */
/*   5 / DIAGBRKPEDNOBVH2P_vidSftyNiv2                                        */
/*                                                                            */
/* !Reference   : V02 NT 10 02593 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#056351                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHIBRK/DIAGBRKPEDNOBVH2P/DIAGB$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   03 Jan 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   03 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "DIAGBRKPEDNOBVH2P.h"
#include "DIAGBRKPEDNOBVH2P_l.h"
#include "DIAGBRKPEDNOBVH2P_IM.h"
#include "LIBSFTYLVL2.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPEDNOBVH2P_vidInitOutput                            */
/* !Description :  Fontion d'initialisation des sorties au reset              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Bps_brake_pedal_can_hs;                                     */
/*  input boolean Bps_brake_pedal_can_input;                                  */
/*  input boolean Ext_bSecBrkPedPrssFilt;                                     */
/*  input boolean Ext_bMonRunDecelCoh_BrkPed;                                 */
/*  input boolean Ext_bMonRunAccelCoh_BrkPed;                                 */
/*  input boolean Ext_bMonRunInvCoh_BrkPed;                                   */
/*  output st05 Bps_diag_state;                                               */
/*  output boolean Ext_bMonRunDecelCoh_BrkPed;                                */
/*  output boolean Ext_bMonRunAccelCoh_BrkPed;                                */
/*  output boolean Ext_bMonRunInvCoh_BrkPed;                                  */
/*  output boolean Ext_bDgoDecelCoh_BrkPed;                                   */
/*  output boolean Ext_bDgoAccelCoh_BrkPed;                                   */
/*  output boolean Ext_bDgoInvCoh_BrkPed;                                     */
/*  output uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_1;                               */
/*  output uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_2;                               */
/*  output uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_3;                               */
/*  output boolean DIAGBRKPEDNOBVH2P_bFilSig_1;                               */
/*  output boolean DIAGBRKPEDNOBVH2P_bFilSig_2;                               */
/*  output boolean DIAGBRKPEDNOBVH2P_bFilSig_3;                               */
/*  output boolean DIAGBRKPEDNOBVH2P_bDecelCoh_BrkP;                          */
/*  output boolean DIAGBRKPEDNOBVH2P_bAccelCoh_BrkP;                          */
/*  output boolean DIAGBRKPEDNOBVH2P_bInvCoh_BrkP;                            */
/*  output uint8 Ext_ctDftSftyAccelCoh_BrkPed;                                */
/*  output uint8 Ext_ctDftSftyDecelCoh_BrkPed;                                */
/*  output uint8 Ext_ctDftSftyInvCoh_BrkPed;                                  */
/*  output boolean Ext_bDftSftyAccelCoh_BrkPed;                               */
/*  output boolean Ext_bDftSftyDecelCoh_BrkPed;                               */
/*  output boolean Ext_bDftSftyInvCoh_BrkPed;                                 */
/*  output uint16 DIAGBRKPEDNOBVH2P_u16CntFilt0;                              */
/*  output uint16 DIAGBRKPEDNOBVH2P_u16CntFilt1;                              */
/*  output uint16 DIAGBRKPEDNOBVH2P_u16CntFilt2;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPEDNOBVH2P_vidInitOutput(void)
{
   boolean bLocalBps_brake_pedal_can_hs;
   boolean bLocalBps_brake_pedal_can_input;
   boolean bLocalExt_bSecBrkPedPrssFilt;
   boolean bLocalTest;


   VEMS_vidGET(Bps_brake_pedal_can_hs, bLocalBps_brake_pedal_can_hs);
   VEMS_vidGET(Bps_brake_pedal_can_input, bLocalBps_brake_pedal_can_input);
   VEMS_vidGET(Ext_bSecBrkPedPrssFilt, bLocalExt_bSecBrkPedPrssFilt);

   Bps_diag_state = BPS_DIAG_INIT;
   Ext_bMonRunDecelCoh_BrkPed = 0;
   Ext_bMonRunAccelCoh_BrkPed = 0;
   Ext_bMonRunInvCoh_BrkPed = 0;

   if (  (bLocalBps_brake_pedal_can_hs == 0)
      && (bLocalBps_brake_pedal_can_input == bLocalExt_bSecBrkPedPrssFilt))
   {
      bLocalTest = 0;
   }
   else
   {
      bLocalTest = 1;
   }

   if (Ext_bMonRunDecelCoh_BrkPed != 0)
   {
      Ext_bDgoDecelCoh_BrkPed = bLocalTest;
   }
   else
   {
      Ext_bDgoDecelCoh_BrkPed = 0;
   }
   /* QAC Msg(3:3356) + Msg(3:3359) + Msg(3:3201) :
   keeping it in order to maintain reset filtre anti_rebond clear */

   if (Ext_bMonRunAccelCoh_BrkPed != 0)
   {
      if (  (  (bLocalExt_bSecBrkPedPrssFilt != 0)
            && (bLocalBps_brake_pedal_can_input == 0))
         || (bLocalBps_brake_pedal_can_hs != 0))
      {
         Ext_bDgoAccelCoh_BrkPed = 1;
      }
      else
      {
         Ext_bDgoAccelCoh_BrkPed = 0;
      }
   }
   else
   {
      Ext_bDgoAccelCoh_BrkPed = 0;
   }
   /* QAC Msg(3:3356) + Msg(3:3359) + Msg(3:3201) :
   keeping it in order to maintain reset filtre anti_rebond clear */

   if (Ext_bMonRunInvCoh_BrkPed != 0)
   {
      Ext_bDgoInvCoh_BrkPed = bLocalTest;
   }
   else
   {
      Ext_bDgoInvCoh_BrkPed = 0;
   }
   /* QAC Msg(3:3356) + Msg(3:3359) + Msg(3:3201) :
   keeping it in order to maintain reset filtre anti_rebond clear */

   DIAGBRKPEDNOBVH2P_u8CntFilt_1 = 0;
   DIAGBRKPEDNOBVH2P_u8CntFilt_2 = 0;
   DIAGBRKPEDNOBVH2P_u8CntFilt_3 = 0;
   DIAGBRKPEDNOBVH2P_bFilSig_1 = 0;
   DIAGBRKPEDNOBVH2P_bFilSig_2 = 0;
   DIAGBRKPEDNOBVH2P_bFilSig_3 = 0;
   DIAGBRKPEDNOBVH2P_bDecelCoh_BrkP = 0;
   DIAGBRKPEDNOBVH2P_bAccelCoh_BrkP = 0;
   DIAGBRKPEDNOBVH2P_bInvCoh_BrkP = 0;
   Ext_ctDftSftyAccelCoh_BrkPed = 0;
   Ext_ctDftSftyDecelCoh_BrkPed = 0;
   Ext_ctDftSftyInvCoh_BrkPed = 0;
   VEMS_vidSET(Ext_bDftSftyAccelCoh_BrkPed, 0);
   VEMS_vidSET(Ext_bDftSftyDecelCoh_BrkPed, 0);
   VEMS_vidSET(Ext_bDftSftyInvCoh_BrkPed, 0);
   DIAGBRKPEDNOBVH2P_u16CntFilt0 = 0;
   DIAGBRKPEDNOBVH2P_u16CntFilt1 = 0;
   DIAGBRKPEDNOBVH2P_u16CntFilt2 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPEDNOBVH2P_vidFnctionCall                           */
/* !Description :  Le diagnostic de la cohérence de la pédale de frein est    */
/*                 inhibé en mode intégration électronique.                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGBRKPEDNOBVH2P_vidDiagBrkPMng();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input boolean Cf_bSecBrkPedPrss;                                          */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Cf_bSecBrkPedPrssDiag;                                      */
/*  input boolean Ext_bDgoDecelCoh_BrkPed;                                    */
/*  input boolean Ext_bMonRunDecelCoh_BrkPed;                                 */
/*  input boolean Ext_bDgoAccelCoh_BrkPed;                                    */
/*  input boolean Ext_bMonRunAccelCoh_BrkPed;                                 */
/*  input boolean Ext_bDgoInvCoh_BrkPed;                                      */
/*  input boolean Ext_bMonRunInvCoh_BrkPed;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPEDNOBVH2P_vidFnctionCall(void)
{
   boolean bLocalCf_bSecBrkPedPrss;
   boolean bLocalDIAGCAN_bIntegratioElec;
   boolean bLocalCf_bSecBrkPedPrssDiag;


   VEMS_vidGET(Cf_bSecBrkPedPrss, bLocalCf_bSecBrkPedPrss);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegratioElec);
   VEMS_vidGET(Cf_bSecBrkPedPrssDiag, bLocalCf_bSecBrkPedPrssDiag);

   if (  (bLocalCf_bSecBrkPedPrss != 0)
      && (bLocalDIAGCAN_bIntegratioElec == 0)
      && (bLocalCf_bSecBrkPedPrssDiag != 0))
   {
      DIAGBRKPEDNOBVH2P_vidDiagBrkPMng();
      GDGAR_vidGdu(GD_DFT_DECELCOH_BRKPED,
                   Ext_bDgoDecelCoh_BrkPed,
                   Ext_bMonRunDecelCoh_BrkPed,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ACCELCOH_BRKPED,
                   Ext_bDgoAccelCoh_BrkPed,
                   Ext_bMonRunAccelCoh_BrkPed,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_INVCOH_BRKPED,
                   Ext_bDgoInvCoh_BrkPed,
                   Ext_bMonRunInvCoh_BrkPed,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPEDNOBVH2P_vidDiagBrkPMng                           */
/* !Description :  Le diagnostic de cohérence de l’information frein consiste */
/*                 en une interprétation de l’info CAN frein HS et un  test   */
/*                 entre  l’information provenant du CAN et celle par le      */
/*                 contrôle moteur.                                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_10_02593_001.01                                     */
/*                 VEMS_R_10_02593_002.01                                     */
/*                 VEMS_R_10_02593_003.01                                     */
/*                 VEMS_R_10_02593_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGBRKPEDNOBVH2P_vidDiagManager();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Bps_brake_pedal_can_hs;                                     */
/*  input boolean Bps_brake_pedal_can_input;                                  */
/*  input boolean Ext_bSecBrkPedPrssFilt;                                     */
/*  input boolean Ext_bMonRunDecelCoh_BrkPed;                                 */
/*  input boolean Ext_bDgoDecelCoh_BrkPed;                                    */
/*  input uint16 Brk_noPedNoBVH2pDecDecelCoh_C;                               */
/*  input uint16 Brk_noPedNoBVH2pIncDecelCoh_C;                               */
/*  input uint16 DIAGBRKPEDNOBVH2P_u16CntFilt0;                               */
/*  input boolean Ext_bMonRunAccelCoh_BrkPed;                                 */
/*  input boolean Ext_bDgoAccelCoh_BrkPed;                                    */
/*  input uint16 Brk_noPedNoBVH2pDecAccelCoh_C;                               */
/*  input uint16 Brk_noPedNoBVH2pIncAccelCoh_C;                               */
/*  input uint16 DIAGBRKPEDNOBVH2P_u16CntFilt1;                               */
/*  input boolean Ext_bMonRunInvCoh_BrkPed;                                   */
/*  input boolean Ext_bDgoInvCoh_BrkPed;                                      */
/*  input uint16 Brk_noPedNoBVH2pDecInvCoh_C;                                 */
/*  input uint16 Brk_noPedNoBVH2pIncInvCoh_C;                                 */
/*  input uint16 DIAGBRKPEDNOBVH2P_u16CntFilt2;                               */
/*  output uint16 DIAGBRKPEDNOBVH2P_u16CntFilt0;                              */
/*  output boolean Ext_bDgoDecelCoh_BrkPed;                                   */
/*  output uint16 DIAGBRKPEDNOBVH2P_u16CntFilt1;                              */
/*  output boolean Ext_bDgoAccelCoh_BrkPed;                                   */
/*  output uint16 DIAGBRKPEDNOBVH2P_u16CntFilt2;                              */
/*  output boolean Ext_bDgoInvCoh_BrkPed;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPEDNOBVH2P_vidDiagBrkPMng(void)
{
   boolean bLocalBps_brake_pedal_can_hs;
   boolean bLocalBps_brake_pedal_can_input;
   boolean bLocalExt_bSecBrkPedPrssFilt;
   boolean bLocalRawSigFilt_X;
   boolean bLocalTest;
   uint16  u16LocalTranThd;


   DIAGBRKPEDNOBVH2P_vidDiagManager();

   VEMS_vidGET(Bps_brake_pedal_can_hs, bLocalBps_brake_pedal_can_hs);
   VEMS_vidGET(Bps_brake_pedal_can_input, bLocalBps_brake_pedal_can_input);
   VEMS_vidGET(Ext_bSecBrkPedPrssFilt, bLocalExt_bSecBrkPedPrssFilt);

   if (  (bLocalBps_brake_pedal_can_hs == 0)
      && (bLocalBps_brake_pedal_can_input == bLocalExt_bSecBrkPedPrssFilt))
   {
      bLocalTest = 0;
   }
   else
   {
      bLocalTest = 1;
   }

   if (Ext_bMonRunDecelCoh_BrkPed != 0)
   {
      bLocalRawSigFilt_X = bLocalTest;
   }
   else
   {
      bLocalRawSigFilt_X = 0;
   }
   /* filtre anti_rebond */
   if (bLocalRawSigFilt_X != Ext_bDgoDecelCoh_BrkPed)
   {
      if (bLocalRawSigFilt_X == 0)
      {
         u16LocalTranThd = Brk_noPedNoBVH2pDecDecelCoh_C;
      }
      else
      {
         u16LocalTranThd = Brk_noPedNoBVH2pIncDecelCoh_C;
      }

      if (DIAGBRKPEDNOBVH2P_u16CntFilt0 < 65535)
      {
         DIAGBRKPEDNOBVH2P_u16CntFilt0 = (uint16)( DIAGBRKPEDNOBVH2P_u16CntFilt0
                                                 + 1);
      }
      if (DIAGBRKPEDNOBVH2P_u16CntFilt0 > u16LocalTranThd)
      {
         Ext_bDgoDecelCoh_BrkPed = bLocalRawSigFilt_X;
         DIAGBRKPEDNOBVH2P_u16CntFilt0 = 0;
      }
   }
   else
   {
      DIAGBRKPEDNOBVH2P_u16CntFilt0 = 0;
   }

   if (Ext_bMonRunAccelCoh_BrkPed != 0)
   {
      if (  (  (bLocalExt_bSecBrkPedPrssFilt != 0)
            && (bLocalBps_brake_pedal_can_input == 0))
         || (bLocalBps_brake_pedal_can_hs != 0))
      {
         bLocalRawSigFilt_X = 1;
      }
      else
      {
         bLocalRawSigFilt_X = 0;
      }
   }
   else
   {
      bLocalRawSigFilt_X = 0;
   }
   /* filtre anti_rebond1 */
   if (bLocalRawSigFilt_X != Ext_bDgoAccelCoh_BrkPed)
   {
      if (bLocalRawSigFilt_X == 0)
      {
         u16LocalTranThd = Brk_noPedNoBVH2pDecAccelCoh_C;
      }
      else
      {
         u16LocalTranThd = Brk_noPedNoBVH2pIncAccelCoh_C;
      }

      if (DIAGBRKPEDNOBVH2P_u16CntFilt1 < 65535)
      {
         DIAGBRKPEDNOBVH2P_u16CntFilt1 = (uint16)( DIAGBRKPEDNOBVH2P_u16CntFilt1
                                                 + 1);
      }
      if (DIAGBRKPEDNOBVH2P_u16CntFilt1 > u16LocalTranThd)
      {
         Ext_bDgoAccelCoh_BrkPed = bLocalRawSigFilt_X;
         DIAGBRKPEDNOBVH2P_u16CntFilt1 = 0;
      }
   }
   else
   {
      DIAGBRKPEDNOBVH2P_u16CntFilt1 = 0;
   }

   if (Ext_bMonRunInvCoh_BrkPed != 0)
   {
      bLocalRawSigFilt_X = bLocalTest;
   }
   else
   {
      bLocalRawSigFilt_X = 0;
   }
   /* filtre anti_rebond2 */
   if (bLocalRawSigFilt_X != Ext_bDgoInvCoh_BrkPed)
   {
      if (bLocalRawSigFilt_X == 0)
      {
         u16LocalTranThd = Brk_noPedNoBVH2pDecInvCoh_C;
      }
      else
      {
         u16LocalTranThd = Brk_noPedNoBVH2pIncInvCoh_C;
      }

      if (DIAGBRKPEDNOBVH2P_u16CntFilt2 < 65535)
      {
         DIAGBRKPEDNOBVH2P_u16CntFilt2 = (uint16)( DIAGBRKPEDNOBVH2P_u16CntFilt2
                                                 + 1);
      }
      if (DIAGBRKPEDNOBVH2P_u16CntFilt2 > u16LocalTranThd)
      {
         Ext_bDgoInvCoh_BrkPed = bLocalRawSigFilt_X;
         DIAGBRKPEDNOBVH2P_u16CntFilt2 = 0;
      }
   }
   else
   {
      DIAGBRKPEDNOBVH2P_u16CntFilt2 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPEDNOBVH2P_vidDiagManager                           */
/* !Description :  Diagnostique du frein                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st05 Bps_diag_state;                                                */
/*  input uint8 Acceleration_vehicule;                                        */
/*  input uint16 Bps_coh_seuil_accel;                                         */
/*  input uint16 Bps_coh_seuil_decel;                                         */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Diag_on;                                                    */
/*  output boolean Ext_bMonRunDecelCoh_BrkPed;                                */
/*  output boolean Ext_bMonRunAccelCoh_BrkPed;                                */
/*  output st05 Bps_diag_state;                                               */
/*  output boolean Ext_bMonRunInvCoh_BrkPed;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPEDNOBVH2P_vidDiagManager(void)
{
   boolean bLocalAcvBrkPedDiagInvld;
   boolean bLocalInhBrkPedDiagEl;
   boolean bLocalClef_de_contact;
   boolean bLocalDiag_on;
   uint8   u8LocalAcceleration_vehicule;


   bLocalAcvBrkPedDiagInvld = GDGAR_bGetFRM(FRM_FRM_ACVBRKPEDDIAGINVLD);
   bLocalInhBrkPedDiagEl = GDGAR_bGetFRM(FRM_FRM_INHBRKPEDDIAGEL);
   switch(Bps_diag_state)
   {
      case BPS_DIAG_INIT:
         if (bLocalAcvBrkPedDiagInvld != 0)
         {
            Ext_bMonRunDecelCoh_BrkPed = 0;
            Ext_bMonRunAccelCoh_BrkPed = 0;
            Bps_diag_state = BPS_DIAG_INVAL;
         }
         else
         {
            VEMS_vidGET(Acceleration_vehicule, u8LocalAcceleration_vehicule);
            if ((u8LocalAcceleration_vehicule * 4096) >
                ((Bps_coh_seuil_accel * 25) + 716800))
            {
               Bps_diag_state = BPS_DIAG_ACCEL;
            }
            else
            {
               if ((u8LocalAcceleration_vehicule * 4096) <
                   ((sint32)((-1) * Bps_coh_seuil_decel * 25) + 716800))
               {
                  Bps_diag_state = BPS_DIAG_DECEL;
               }
            }
         }
         break;

      case BPS_DIAG_ACCEL:
         if (bLocalAcvBrkPedDiagInvld != 0)
         {
            Ext_bMonRunDecelCoh_BrkPed = 0;
            Ext_bMonRunAccelCoh_BrkPed = 0;
            Bps_diag_state = BPS_DIAG_INVAL;
         }
         else
         {
            VEMS_vidGET(Acceleration_vehicule, u8LocalAcceleration_vehicule);
            if ((u8LocalAcceleration_vehicule * 4096) <=
                ((Bps_coh_seuil_accel * 25) + 716800))
            {
               Bps_diag_state = BPS_DIAG_INIT;
               Ext_bMonRunDecelCoh_BrkPed = 0;
               Ext_bMonRunAccelCoh_BrkPed = 0;
               Ext_bMonRunInvCoh_BrkPed = 0;
            }
            else
            {
               VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
               VEMS_vidGET(Diag_on, bLocalDiag_on);
               if (  (bLocalInhBrkPedDiagEl == 0)
                  && (bLocalDiag_on != 0)
                  && (bLocalClef_de_contact != 0))
               {
                  Ext_bMonRunAccelCoh_BrkPed = 1;
               }
               else
               {
                  Ext_bMonRunAccelCoh_BrkPed = 0;
               }
            }
         }
         break;

      case BPS_DIAG_DECEL:
         if (bLocalAcvBrkPedDiagInvld != 0)
         {
            Ext_bMonRunDecelCoh_BrkPed = 0;
            Ext_bMonRunAccelCoh_BrkPed = 0;
            Bps_diag_state = BPS_DIAG_INVAL;
         }
         else
         {
            VEMS_vidGET(Acceleration_vehicule, u8LocalAcceleration_vehicule);
            if ((u8LocalAcceleration_vehicule * 4096) >=
                ((sint32)((-1) * Bps_coh_seuil_decel * 25) + 716800))
            {
               Bps_diag_state = BPS_DIAG_INIT;
               Ext_bMonRunDecelCoh_BrkPed = 0;
               Ext_bMonRunAccelCoh_BrkPed = 0;
               Ext_bMonRunInvCoh_BrkPed = 0;
            }
            else
            {
               VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
               VEMS_vidGET(Diag_on, bLocalDiag_on);
               if (  (bLocalInhBrkPedDiagEl == 0)
                  && (bLocalDiag_on != 0)
                  && (bLocalClef_de_contact != 0))
               {
                  Ext_bMonRunDecelCoh_BrkPed = 1;
               }
               else
               {
                  Ext_bMonRunDecelCoh_BrkPed = 0;
               }
            }
         }
         break;

      case BPS_DIAG_INVAL:
         if (bLocalAcvBrkPedDiagInvld == 0)
         {
            Bps_diag_state = BPS_DIAG_INIT;
            Ext_bMonRunDecelCoh_BrkPed = 0;
            Ext_bMonRunAccelCoh_BrkPed = 0;
            Ext_bMonRunInvCoh_BrkPed = 0;
         }
         else
         {
            VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
            VEMS_vidGET(Diag_on, bLocalDiag_on);
            if (  (bLocalInhBrkPedDiagEl == 0)
               && (bLocalDiag_on != 0)
               && (bLocalClef_de_contact != 0))
            {
               Ext_bMonRunInvCoh_BrkPed = 1;
            }
            else
            {
               Ext_bMonRunInvCoh_BrkPed = 0;
            }
         }
         break;

      default:
         Bps_diag_state = BPS_DIAG_INIT;
         Ext_bMonRunDecelCoh_BrkPed = 0;
         Ext_bMonRunAccelCoh_BrkPed = 0;
         Ext_bMonRunInvCoh_BrkPed = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPEDNOBVH2P_vidSftyNiv2                              */
/* !Description :  Fonction de diagnostic niveau à partir d’un défaut detecté */
/*                 par le niveau 2                                            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bDgoDecelCoh_BrkPed;                                    */
/*  input uint8 Brk_nUpTranThd_DecelCoh_C;                                    */
/*  input uint8 Brk_nDownTranThd_DecelCoh_C;                                  */
/*  input uint8 Brk_nInitCpt_DecelCoh_C;                                      */
/*  input uint8 Brk_nDecCpt_DecelCoh_C;                                       */
/*  input uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_2;                                */
/*  input boolean DIAGBRKPEDNOBVH2P_bFilSig_2;                                */
/*  input uint8 Ext_ctDftSftyDecelCoh_BrkPed;                                 */
/*  input boolean DIAGBRKPEDNOBVH2P_bDecelCoh_BrkP;                           */
/*  input boolean Ext_bDgoAccelCoh_BrkPed;                                    */
/*  input uint8 Brk_nUpTranThd_AccelCoh_C;                                    */
/*  input uint8 Brk_nDownTranThd_AccelCoh_C;                                  */
/*  input uint8 Brk_nInitCpt_AccelCoh_C;                                      */
/*  input uint8 Brk_nDecCpt_AccelCoh_C;                                       */
/*  input uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_1;                                */
/*  input boolean DIAGBRKPEDNOBVH2P_bFilSig_1;                                */
/*  input uint8 Ext_ctDftSftyAccelCoh_BrkPed;                                 */
/*  input boolean DIAGBRKPEDNOBVH2P_bAccelCoh_BrkP;                           */
/*  input boolean Ext_bDgoInvCoh_BrkPed;                                      */
/*  input uint8 Brk_nUpTranThd_InvCoh_C;                                      */
/*  input uint8 Brk_nDownTranThd_InvCoh_C;                                    */
/*  input uint8 Brk_nInitCpt_InvCoh_C;                                        */
/*  input uint8 Brk_nDecCpt_InvCoh_C;                                         */
/*  input uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_3;                                */
/*  input boolean DIAGBRKPEDNOBVH2P_bFilSig_3;                                */
/*  input uint8 Ext_ctDftSftyInvCoh_BrkPed;                                   */
/*  input boolean DIAGBRKPEDNOBVH2P_bInvCoh_BrkP;                             */
/*  output boolean Ext_bDftSftyDecelCoh_BrkPed;                               */
/*  output boolean DIAGBRKPEDNOBVH2P_bDecelCoh_BrkP;                          */
/*  output boolean Ext_bDftSftyAccelCoh_BrkPed;                               */
/*  output boolean DIAGBRKPEDNOBVH2P_bAccelCoh_BrkP;                          */
/*  output boolean Ext_bDftSftyInvCoh_BrkPed;                                 */
/*  output boolean DIAGBRKPEDNOBVH2P_bInvCoh_BrkP;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPEDNOBVH2P_vidSftyNiv2(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoDecelCoh_BrkPed,
                                Brk_nUpTranThd_DecelCoh_C,
                                Brk_nDownTranThd_DecelCoh_C,
                                Brk_nInitCpt_DecelCoh_C,
                                Brk_nDecCpt_DecelCoh_C,
                                &DIAGBRKPEDNOBVH2P_u8CntFilt_2,
                                &DIAGBRKPEDNOBVH2P_bFilSig_2,
                                &Ext_ctDftSftyDecelCoh_BrkPed,
                                &DIAGBRKPEDNOBVH2P_bDecelCoh_BrkP);
   VEMS_vidSET(Ext_bDftSftyDecelCoh_BrkPed, DIAGBRKPEDNOBVH2P_bDecelCoh_BrkP);

   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoAccelCoh_BrkPed,
                                Brk_nUpTranThd_AccelCoh_C,
                                Brk_nDownTranThd_AccelCoh_C,
                                Brk_nInitCpt_AccelCoh_C,
                                Brk_nDecCpt_AccelCoh_C,
                                &DIAGBRKPEDNOBVH2P_u8CntFilt_1,
                                &DIAGBRKPEDNOBVH2P_bFilSig_1,
                                &Ext_ctDftSftyAccelCoh_BrkPed,
                                &DIAGBRKPEDNOBVH2P_bAccelCoh_BrkP);
   VEMS_vidSET(Ext_bDftSftyAccelCoh_BrkPed, DIAGBRKPEDNOBVH2P_bAccelCoh_BrkP);

   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoInvCoh_BrkPed,
                                Brk_nUpTranThd_InvCoh_C,
                                Brk_nDownTranThd_InvCoh_C,
                                Brk_nInitCpt_InvCoh_C,
                                Brk_nDecCpt_InvCoh_C,
                                &DIAGBRKPEDNOBVH2P_u8CntFilt_3,
                                &DIAGBRKPEDNOBVH2P_bFilSig_3,
                                &Ext_ctDftSftyInvCoh_BrkPed,
                                &DIAGBRKPEDNOBVH2P_bInvCoh_BrkP);
   VEMS_vidSET(Ext_bDftSftyInvCoh_BrkPed, DIAGBRKPEDNOBVH2P_bInvCoh_BrkP);
}
/*------------------------------- end of file --------------------------------*/