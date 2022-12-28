/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSTOPCLCN                                             */
/* !Description     : THRSTOPCLCN component.                                  */
/*                                                                            */
/* !Module          : THRSTOPCLCN                                             */
/* !Description     : Calcul des butees du papillon.                          */
/*                                                                            */
/* !File            : THRSTOPCLCN_FCT2.C                                      */
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
/*   1 / THRSTOPCLCN_vidCheckLimpHome                                         */
/*   2 / THRSTOPCLCN_vidLimpHome                                              */
/*   3 / THRSTOPCLCN_vidCalcLoThrustLHNeg                                     */
/*   4 / THRSTOPCLCN_vidLihDiag                                               */
/*   5 / THRSTOPCLCN_vidEndStopDiag                                           */
/*   6 / THRSTOPCLCN_vidStuckThr                                              */
/*   7 / THRSTOPCLCN_vidIniLrnLimpHome                                        */
/*   8 / THRSTOPCLCN_vidReinitSrvDiag                                         */
/*   9 / pap_mot_NVMSRV_vidInit                                               */
/*   10 / THRSTOPCLCN_vidCalc_Lih_prec                                        */
/*                                                                            */
/* !Reference   : V02 NT 08 04799 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#061157                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSTOPCLCN/THRSTOPCLCN_fct2$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   20 Apr 2012 $*/
/* $Author::   etsasson                               $$Date::   20 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRSTOPCLCN.h"
#include "THRSTOPCLCN_L.h"
#include "THRSTOPCLCN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidCheckLimpHome                               */
/* !Description :  Le microcontrôleur principal vérifie que la fonction       */
/*                 d’inhibit du microcontrôleur watchdog est opérationnelle.  */
/*                 Il procède à la lecture de la position de repos. Il        */
/*                 s'assure ainsi que le papillon est bien en position de     */
/*                 limp-home.                                                 */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Thr_bInhStopThrLihChk;                                      */
/*  input uint16 Tpac_1_filt_filt_position;                                   */
/*  input uint16 Tpac_1_limp_home_max;                                        */
/*  input uint16 Tpac_1_limp_home_min;                                        */
/*  input uint16 Tpac_2_filt_filt_position;                                   */
/*  input uint16 Tpac_2_limp_home_max;                                        */
/*  input uint16 Tpac_2_limp_home_min;                                        */
/*  output boolean Tpac_1_ChkLih_dft;                                         */
/*  output boolean Tpac_2_ChkLih_dft;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidCheckLimpHome(void)
{
   boolean bLocalInhStopThrLihChk;
   boolean bLocalInhSecuMngThrPosnSen1;
   boolean bLocalInhSecuMngThrPosnSen2;
   uint16  u16LocalTpac_1_filt_filtposition;
   uint16  u16LocalTpac_2_filt_filtposition;

   bLocalInhStopThrLihChk = GDGAR_bGetFRM(FRM_FRM_INHSTOPTHRLIHCHK);
   if (  (bLocalInhStopThrLihChk == 0)
      && (Thr_bInhStopThrLihChk == 0))
   {
      bLocalInhSecuMngThrPosnSen1 =
         GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN1);
      if (bLocalInhSecuMngThrPosnSen1 == 0)
      {  /*  bloc check_limh_1 */
         Tpac_1_ChkLih_dft = 0;
         VEMS_vidGET(Tpac_1_filt_filt_position,
                     u16LocalTpac_1_filt_filtposition);
         if (  (u16LocalTpac_1_filt_filtposition >= Tpac_1_limp_home_max)
         || (u16LocalTpac_1_filt_filtposition <= Tpac_1_limp_home_min))
         {
            Tpac_1_ChkLih_dft = 1;
         }
      }
      bLocalInhSecuMngThrPosnSen2 =
         GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN2);
      if (bLocalInhSecuMngThrPosnSen2 == 0)
      {  /*  bloc check_limh_2 */
         Tpac_2_ChkLih_dft = 0;
         VEMS_vidGET(Tpac_2_filt_filt_position,
                     u16LocalTpac_2_filt_filtposition);
         if (  (u16LocalTpac_2_filt_filtposition >= Tpac_2_limp_home_max)
         || (u16LocalTpac_2_filt_filtposition <= Tpac_2_limp_home_min) )
         {
            Tpac_2_ChkLih_dft = 1;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidLimpHome                                    */
/* !Description :  Cette fonction est appelée par l’automate d'asservissement.*/
/*                 Elle procède à la lecture de la position de repos, dite de */
/*                 limp-home, sur les capteurs n°1 e t n°2. Si les valeurs de */
/*                 position obtenues sont hor s gamme, une panne « tpac_lhome */
/*                 » est mémorisée.                                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRSTOPCLCN_vidCalcLoThrustLHNeg();                      */
/*  input boolean Thr_bStopsLrnInProgs;                                       */
/*  input uint16 Tpac_1_filt_filt_position;                                   */
/*  input uint16 Tpac_1_limp_home_max;                                        */
/*  input uint16 Tpac_1_limp_home_min;                                        */
/*  input uint16 Tpac_1_limp_home_pos_prec;                                   */
/*  input uint16 Tpac_1_limp_home_pos_temp;                                   */
/*  input uint16 Tpac_2_filt_filt_position;                                   */
/*  input uint16 Tpac_2_limp_home_max;                                        */
/*  input uint16 Tpac_2_limp_home_min;                                        */
/*  input uint16 Tpac_2_limp_home_pos_prec;                                   */
/*  input uint16 Tpac_2_limp_home_pos_temp;                                   */
/*  input boolean Tpac_throttle_lh_pos;                                       */
/*  input boolean Thr_bRstStopsLrnReq;                                        */
/*  input uint16 Thr_FLrn_posDriftLihMeasThd_C;                               */
/*  output boolean Tpac_1_Lih_dft;                                            */
/*  output uint16 Tpac_1_limp_home_pos_temp;                                  */
/*  output uint16 Tpac_1_limp_home_pos;                                       */
/*  output boolean Tpac_2_Lih_dft;                                            */
/*  output uint16 Tpac_2_limp_home_pos_temp;                                  */
/*  output uint16 Tpac_2_limp_home_pos;                                       */
/*  output boolean Thr_FLrn_bAcv_PwrOn;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidLimpHome(void)
{
   boolean bLocalInhSecuMngThrPosnSen1;
   boolean bLocalInhSecuMngThrPosnSen2;
   boolean bLocalThr_bRstStopsLrnReq;
   boolean bLocalThr_bStopsLrnInProgs;
   uint16  u16LocalTpac_1_filt_filtposition;
   uint16  u16LocalTpac_1_limp_home_pos;
   uint16  u16LocalTpac_1Limp_home_pos_temp;
   uint16  u16LocalTpac_2_limp_home_pos;
   uint16  u16LocalTpac_2Limp_home_pos_temp;
   uint16  u16LocalTpac_2_filt_filtposition;
   uint32  u32VarTempCal;              /* variable servant au calcul          */
   sint32  s32LocalDiff;


   bLocalInhSecuMngThrPosnSen1 =
      GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN1);
   VEMS_vidGET(Thr_bStopsLrnInProgs, bLocalThr_bStopsLrnInProgs);

   if (bLocalInhSecuMngThrPosnSen1 == 0)
   {  /* 1_Limp_Home_1 */
      VEMS_vidGET(Tpac_1_filt_filt_position, u16LocalTpac_1_filt_filtposition);
      if (  (u16LocalTpac_1_filt_filtposition >= Tpac_1_limp_home_max)
         || (u16LocalTpac_1_filt_filtposition <= Tpac_1_limp_home_min) )
      {
         Tpac_1_Lih_dft= 1;
         u16LocalTpac_1Limp_home_pos_temp = Tpac_1_limp_home_pos_prec;
      }
      else
      {
         Tpac_1_Lih_dft = 0;
         u16LocalTpac_1Limp_home_pos_temp = u16LocalTpac_1_filt_filtposition;
      }
      Tpac_1_limp_home_pos_temp =
         (uint16)MATHSRV_udtMIN(u16LocalTpac_1Limp_home_pos_temp, 1023);

      if (bLocalThr_bStopsLrnInProgs == 0)
      {
         u16LocalTpac_1_limp_home_pos =
            (uint16)MATHSRV_udtMIN(Tpac_1_limp_home_pos_prec, 1023);
      }
      else
      {
         u16LocalTpac_1_limp_home_pos = Tpac_1_limp_home_pos_temp;
      }
      VEMS_vidSET(Tpac_1_limp_home_pos, u16LocalTpac_1_limp_home_pos);
   }

   bLocalInhSecuMngThrPosnSen2 =
      GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN2);
   if (bLocalInhSecuMngThrPosnSen2 == 0)
   {  /* 2_Limp_Home_2 */
      VEMS_vidGET(Tpac_2_filt_filt_position, u16LocalTpac_2_filt_filtposition);
      if (  (u16LocalTpac_2_filt_filtposition >= Tpac_2_limp_home_max)
         || (u16LocalTpac_2_filt_filtposition <= Tpac_2_limp_home_min))
      {
         Tpac_2_Lih_dft = 1;
         u16LocalTpac_2Limp_home_pos_temp = Tpac_2_limp_home_pos_prec;
      }
      else
      {
         Tpac_2_Lih_dft = 0;
         u16LocalTpac_2Limp_home_pos_temp = u16LocalTpac_2_filt_filtposition;
      }
      Tpac_2_limp_home_pos_temp =
         (uint16)MATHSRV_udtMIN(u16LocalTpac_2Limp_home_pos_temp, 1023);

      if (bLocalThr_bStopsLrnInProgs == 0)
      {
         u16LocalTpac_2_limp_home_pos =
            (uint16)MATHSRV_udtMIN(Tpac_2_limp_home_pos_prec, 1023);
      }
      else
      {
         u16LocalTpac_2_limp_home_pos = Tpac_2_limp_home_pos_temp;
      }
      VEMS_vidSET(Tpac_2_limp_home_pos, u16LocalTpac_2_limp_home_pos);
   }

   if (Tpac_throttle_lh_pos == 0)
   {  /* 2_Calcul_low_thrust_lh_neg */
      THRSTOPCLCN_vidCalcLoThrustLHNeg();
   }

   /* 3_Forcage_app_butees */
   VEMS_vidGET(Thr_bRstStopsLrnReq, bLocalThr_bRstStopsLrnReq);

   if (bLocalThr_bRstStopsLrnReq == 0)
   {
      s32LocalDiff = (sint32)( Tpac_1_limp_home_pos_temp
                             - Tpac_1_limp_home_pos_prec);
      u32VarTempCal = (uint32)MATHSRV_udtABS(s32LocalDiff);

      if (u32VarTempCal > Thr_FLrn_posDriftLihMeasThd_C)
      {
         VEMS_vidSET(Thr_FLrn_bAcv_PwrOn, 1);
      }
      else
      {
         s32LocalDiff = (sint32)( Tpac_2_limp_home_pos_temp
                                - Tpac_2_limp_home_pos_prec);
         u32VarTempCal = (uint32)MATHSRV_udtABS(s32LocalDiff);

         if (u32VarTempCal > Thr_FLrn_posDriftLihMeasThd_C)
         {
            VEMS_vidSET(Thr_FLrn_bAcv_PwrOn, 1);
         }
         else
         {
            VEMS_vidSET(Thr_FLrn_bAcv_PwrOn, 0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidCalcLoThrustLHNeg                           */
/* !Description :  La position d’écoulement mini, dite de butée basse         */
/*                 d’asservissement, correspond à la position de repos        */
/*                 mécanique finale plus un offset de position, noté «        */
/*                 Tpac_lhome_to_closed_thrust_cal ».                         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tpac_1_limp_home_pos;                                        */
/*  input uint16 Tpac_lhome_to_closed_thrust_cal;                             */
/*  input uint16 Tpac_2_limp_home_pos;                                        */
/*  output uint16 Tpac_1_clo_throttle_filt_pos;                               */
/*  output uint16 Tpac_1_closed_throttle_ref;                                 */
/*  output uint16 Tpac_1_closed_throttle_pos;                                 */
/*  output uint16 Tpac_2_clo_throttle_filt_pos;                               */
/*  output uint16 Tpac_2_closed_throttle_ref;                                 */
/*  output uint16 Tpac_2_closed_throttle_pos;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidCalcLoThrustLHNeg(void)
{
   uint16 u16LocalThrPos;
   uint16 u16LocalThrPos1;
   uint16 u16LocalTpac_1_limp_home_pos;
   uint16 u16LocalTpac_2_limp_home_pos;


   VEMS_vidGET(Tpac_1_limp_home_pos, u16LocalTpac_1_limp_home_pos);
   u16LocalThrPos = (uint16)MATHSRV_udtMIN( ( u16LocalTpac_1_limp_home_pos
                                            + Tpac_lhome_to_closed_thrust_cal),
                                          1024);
   u16LocalThrPos1 = (uint16)MATHSRV_udtMIN(u16LocalThrPos, 1023);
   VEMS_vidSET(Tpac_1_clo_throttle_filt_pos, u16LocalThrPos);
   VEMS_vidSET(Tpac_1_closed_throttle_ref, u16LocalThrPos1);
   VEMS_vidSET(Tpac_1_closed_throttle_pos, u16LocalThrPos1);
   VEMS_vidGET(Tpac_2_limp_home_pos, u16LocalTpac_2_limp_home_pos);
   u16LocalThrPos = (uint16)MATHSRV_udtMIN( ( u16LocalTpac_2_limp_home_pos
                                            + Tpac_lhome_to_closed_thrust_cal),
                                          1024);
   u16LocalThrPos1 = (uint16)MATHSRV_udtMIN(u16LocalThrPos, 1023);
   VEMS_vidSET(Tpac_2_clo_throttle_filt_pos, u16LocalThrPos);
   VEMS_vidSET(Tpac_2_closed_throttle_ref, u16LocalThrPos1);
   VEMS_vidSET(Tpac_2_closed_throttle_pos, u16LocalThrPos1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidLihDiag                                     */
/* !Description :  Positionne les paramètres de diagnostic (GDU) avant de     */
/*                 réaliser l'appel au GDU.                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Tpac_1_ChkLih_dft;                                          */
/*  input boolean Tpac_1_Lih_dft;                                             */
/*  input boolean Tpac_2_ChkLih_dft;                                          */
/*  input boolean Tpac_2_Lih_dft;                                             */
/*  output boolean Thr_bMonRunLihReq1;                                        */
/*  output boolean Thr_bMonWaitLihReq1;                                       */
/*  output boolean Thr_bDgoLihReq1;                                           */
/*  output boolean Thr_bMonRunLihReq2;                                        */
/*  output boolean Thr_bMonWaitLihReq2;                                       */
/*  output boolean Thr_bDgoLihReq2;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidLihDiag(void)
{
   /* --- LihReq1 --- */
   Thr_bMonRunLihReq1 = 1;
   Thr_bMonWaitLihReq1 = DIAG_DISPO;
   if ((Tpac_1_ChkLih_dft != 0) || (Tpac_1_Lih_dft != 0))
   {
      Thr_bDgoLihReq1 = 1;
   }
   else
   {
      Thr_bDgoLihReq1 = 0;
   }

   /* --- LihReq2 --- */
   Thr_bMonRunLihReq2 = 1;
   Thr_bMonWaitLihReq2 = DIAG_DISPO;
   if ((Tpac_2_ChkLih_dft != 0) || (Tpac_2_Lih_dft != 0))
   {
      Thr_bDgoLihReq2 = 1;
   }
   else
   {
      Thr_bDgoLihReq2 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidEndStopDiag                                 */
/* !Description :  Fonction positionnant les paramètres de diagnostic (GDU)   */
/*                 avant l'appel au GDU.                                      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Tpac_1_open_pos_dft;                                        */
/*  input boolean Tpac_1_closed_pos_dft;                                      */
/*  input boolean Tpac_2_open_pos_dft;                                        */
/*  input boolean Tpac_2_closed_pos_dft;                                      */
/*  output boolean Thr_bMonRunEndStopReq1;                                    */
/*  output boolean Thr_bMonWaitEndStopReq1;                                   */
/*  output boolean Thr_bDgoEndStopReq1;                                       */
/*  output boolean Thr_bMonRunEndStopReq2;                                    */
/*  output boolean Thr_bMonWaitEndStopReq2;                                   */
/*  output boolean Thr_bDgoEndStopReq2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidEndStopDiag(void)
{
   /* --- EndStopReq1 --- */
   Thr_bMonRunEndStopReq1 = 1;
   Thr_bMonWaitEndStopReq1 = DIAG_DISPO;
   if ((Tpac_1_open_pos_dft != 0) || (Tpac_1_closed_pos_dft != 0))
   {
      Thr_bDgoEndStopReq1 = 1;
   }
   else
   {
      Thr_bDgoEndStopReq1 = 0;
   }

   /* --- EndStopReq2 --- */
   Thr_bMonRunEndStopReq2 = 1;
   Thr_bMonWaitEndStopReq2 = DIAG_DISPO;
   if ((Tpac_2_open_pos_dft != 0) || (Tpac_2_closed_pos_dft != 0))
   {
      Thr_bDgoEndStopReq2 = 1;
   }
   else
   {
      Thr_bDgoEndStopReq2 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidStuckThr                                    */
/* !Description :  Si les mesures sur les deux pistes sont hors-gamme alors le*/
/*                 papillon est considéré bloqué mécaniquement. Le booléen «  */
/*                 Tpac_throttle_locked » est placé à 1, ce qui déclenche le  */
/*                 mode dégradé limp-home                                     */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bDgoEndStopReq1;                                        */
/*  input boolean Thr_bDgoEndStopReq2;                                        */
/*  output boolean Tpac_throttle_locked;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidStuckThr(void)
{
   if((Thr_bDgoEndStopReq1 != 0) && (Thr_bDgoEndStopReq2 != 0))
   {
      VEMS_vidSET(Tpac_throttle_locked, 1);
   }
   else
   {
      VEMS_vidSET(Tpac_throttle_locked, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidIniLrnLimpHome                              */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Thr_FLrn_bAcv_PwrOn;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidIniLrnLimpHome(void)
{
   VEMS_vidSET(Thr_FLrn_bAcv_PwrOn, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidReinitSrvDiag                               */
/* !Description :  L’événement Thr_EveRstThr_stopClcn correspond à un service */
/*                 après-vente permettant le recentrage des adaptatifs.       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Thr_posnThrCls1_C;                                           */
/*  input uint16 Thr_posnThrCls2_C;                                           */
/*  input uint16 Thr_posnThrClsFil1_C;                                        */
/*  input uint16 Thr_posnThrClsFil2_C;                                        */
/*  input uint16 Thr_posnThrClsRef1_C;                                        */
/*  input uint16 Thr_posnThrClsRef2_C;                                        */
/*  input uint16 Thr_posnThrOp1_C;                                            */
/*  input uint16 Thr_posnThrOp2_C;                                            */
/*  input uint16 Thr_posnThrLih1_C;                                           */
/*  input uint16 Thr_posnThrLih2_C;                                           */
/*  output uint16 Tpac_1_closed_throttle_pos;                                 */
/*  output uint16 Tpac_2_closed_throttle_pos;                                 */
/*  output uint16 Tpac_1_clo_throttle_filt_pos;                               */
/*  output uint16 Tpac_2_clo_throttle_filt_pos;                               */
/*  output uint16 Tpac_1_closed_throttle_ref;                                 */
/*  output uint16 Tpac_2_closed_throttle_ref;                                 */
/*  output uint16 Tpac_1_open_throttle_pos;                                   */
/*  output uint16 Tpac_2_open_throttle_pos;                                   */
/*  output uint16 Tpac_1_limp_home_pos;                                       */
/*  output uint16 Tpac_2_limp_home_pos;                                       */
/*  output boolean Thr_bNewThrCpt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidReinitSrvDiag(void)
{
   uint16 u16LocalTpac_1_closed_throt_pos;
   uint16 u16LocalTpac_2_closed_throt_pos;
   uint16 u16LocalTpac_1_clo_throt_filt;
   uint16 u16LocalTpac_2_clo_throt_filt;
   uint16 u16LocalTpac_1_closed_throt_ref;
   uint16 u16LocalTpac_2_closed_throt_ref;
   uint16 u16LocalTpac_1_open_throt_pos;
   uint16 u16LocalTpac_2_open_throt_pos;
   uint16 u16LocalTpac_1_limp_home_pos;
   uint16 u16LocalTpac_2_limp_home_pos;


   u16LocalTpac_1_closed_throt_pos =
      (uint16)MATHSRV_udtMIN(Thr_posnThrCls1_C, 1023);
   VEMS_vidSET(Tpac_1_closed_throttle_pos, u16LocalTpac_1_closed_throt_pos);
   u16LocalTpac_2_closed_throt_pos =
      (uint16)MATHSRV_udtMIN(Thr_posnThrCls2_C, 1023);
   VEMS_vidSET(Tpac_2_closed_throttle_pos, u16LocalTpac_2_closed_throt_pos);
   u16LocalTpac_1_clo_throt_filt =
      (uint16)MATHSRV_udtMIN(Thr_posnThrClsFil1_C, 1024);
   VEMS_vidSET(Tpac_1_clo_throttle_filt_pos, u16LocalTpac_1_clo_throt_filt);
   u16LocalTpac_2_clo_throt_filt =
      (uint16)MATHSRV_udtMIN(Thr_posnThrClsFil2_C, 1024);
   VEMS_vidSET(Tpac_2_clo_throttle_filt_pos, u16LocalTpac_2_clo_throt_filt);
   u16LocalTpac_1_closed_throt_ref =
      (uint16)MATHSRV_udtMIN(Thr_posnThrClsRef1_C, 1023);
   VEMS_vidSET(Tpac_1_closed_throttle_ref, u16LocalTpac_1_closed_throt_ref);
   u16LocalTpac_2_closed_throt_ref =
      (uint16)MATHSRV_udtMIN(Thr_posnThrClsRef2_C, 1023);
   VEMS_vidSET(Tpac_2_closed_throttle_ref, u16LocalTpac_2_closed_throt_ref);
   u16LocalTpac_1_open_throt_pos =
      (uint16)MATHSRV_udtMIN(Thr_posnThrOp1_C, 1023);
   VEMS_vidSET(Tpac_1_open_throttle_pos, u16LocalTpac_1_open_throt_pos);
   u16LocalTpac_2_open_throt_pos =
      (uint16)MATHSRV_udtMIN(Thr_posnThrOp2_C, 1023);
   VEMS_vidSET(Tpac_2_open_throttle_pos, u16LocalTpac_2_open_throt_pos);

   u16LocalTpac_1_limp_home_pos =
      (uint16)MATHSRV_udtMIN(Thr_posnThrLih1_C, 1023);
   VEMS_vidSET(Tpac_1_limp_home_pos, u16LocalTpac_1_limp_home_pos);
   u16LocalTpac_2_limp_home_pos =
      (uint16)MATHSRV_udtMIN(Thr_posnThrLih2_C, 1023);
   VEMS_vidSET(Tpac_2_limp_home_pos, u16LocalTpac_2_limp_home_pos);
   Thr_bNewThrCpt = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  pap_mot_NVMSRV_vidInit                                     */
/* !Description :  l’initialisation, on vient lire toutes les données         */
/*                 enregistrées en EEPROM. Dans le cas d’une première mise    */
/*                 sous tension, on utilise les valeurs par défaut.           */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Thr_posnThrCls1_C;                                           */
/*  input uint16 Thr_posnThrCls2_C;                                           */
/*  input uint16 Thr_posnThrClsFil1_C;                                        */
/*  input uint16 Thr_posnThrClsFil2_C;                                        */
/*  input uint16 Thr_posnThrClsRef1_C;                                        */
/*  input uint16 Thr_posnThrClsRef2_C;                                        */
/*  input uint16 Thr_posnThrOp1_C;                                            */
/*  input uint16 Thr_posnThrOp2_C;                                            */
/*  input uint16 Thr_posnThrLih1_C;                                           */
/*  input uint16 Thr_posnThrLih2_C;                                           */
/*  output uint16 Tpac_1_closed_throttle_pos;                                 */
/*  output uint16 Thr_posnThrCls1_C;                                          */
/*  output uint16 Tpac_2_closed_throttle_pos;                                 */
/*  output uint16 Thr_posnThrCls2_C;                                          */
/*  output uint16 Tpac_1_clo_throttle_filt_pos;                               */
/*  output uint16 Thr_posnThrClsFil1_C;                                       */
/*  output uint16 Tpac_2_clo_throttle_filt_pos;                               */
/*  output uint16 Thr_posnThrClsFil2_C;                                       */
/*  output uint16 Tpac_1_closed_throttle_ref;                                 */
/*  output uint16 Thr_posnThrClsRef1_C;                                       */
/*  output uint16 Tpac_2_closed_throttle_ref;                                 */
/*  output uint16 Thr_posnThrClsRef2_C;                                       */
/*  output uint16 Tpac_1_open_throttle_pos;                                   */
/*  output uint16 Thr_posnThrOp1_C;                                           */
/*  output uint16 Tpac_2_open_throttle_pos;                                   */
/*  output uint16 Thr_posnThrOp2_C;                                           */
/*  output uint16 Tpac_1_limp_home_pos;                                       */
/*  output uint16 Thr_posnThrLih1_C;                                          */
/*  output uint16 Tpac_2_limp_home_pos;                                       */
/*  output uint16 Thr_posnThrLih2_C;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void pap_mot_NVMSRV_vidInit(void)
{
   VEMS_vidSET(Tpac_1_closed_throttle_pos, Thr_posnThrCls1_C);
   VEMS_vidSET(Tpac_2_closed_throttle_pos, Thr_posnThrCls2_C);
   VEMS_vidSET(Tpac_1_clo_throttle_filt_pos, Thr_posnThrClsFil1_C);
   VEMS_vidSET(Tpac_2_clo_throttle_filt_pos, Thr_posnThrClsFil2_C);
   VEMS_vidSET(Tpac_1_closed_throttle_ref, Thr_posnThrClsRef1_C);
   VEMS_vidSET(Tpac_2_closed_throttle_ref, Thr_posnThrClsRef2_C);
   VEMS_vidSET(Tpac_1_open_throttle_pos, Thr_posnThrOp1_C);
   VEMS_vidSET(Tpac_2_open_throttle_pos, Thr_posnThrOp2_C);
   VEMS_vidSET(Tpac_1_limp_home_pos, Thr_posnThrLih1_C);
   VEMS_vidSET(Tpac_2_limp_home_pos, Thr_posnThrLih2_C);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidCalc_Lih_prec                               */
/* !Description :  Production des variables précédentes des variables         */
/*                 Tpac_1_limp_home_pos et Tpac_2_limp_home_pos.              */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tpac_1_limp_home_pos;                                        */
/*  input uint16 Tpac_2_limp_home_pos;                                        */
/*  output uint16 Tpac_1_limp_home_pos_prec;                                  */
/*  output uint16 Tpac_2_limp_home_pos_prec;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidCalc_Lih_prec(void)
{
   uint16 u16LocalTpac_1_limp_home_pos;
   uint16 u16LocalTpac_2_limp_home_pos;


   VEMS_vidGET(Tpac_1_limp_home_pos, u16LocalTpac_1_limp_home_pos);
   VEMS_vidGET(Tpac_2_limp_home_pos, u16LocalTpac_2_limp_home_pos);
   Tpac_1_limp_home_pos_prec =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_1_limp_home_pos, 1023);
   Tpac_2_limp_home_pos_prec =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_2_limp_home_pos, 1023);
}
/*------------------------------- End of file --------------------------------*/