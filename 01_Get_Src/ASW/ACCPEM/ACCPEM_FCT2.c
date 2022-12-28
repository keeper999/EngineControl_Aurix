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
/* !File            : ACCPEM_FCT2.C                                           */
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
/*   1 / ACCPEM_vidAccPReinfPos                                               */
/*   2 / ACCPEM_vidAccPSatPos                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5021748 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCPEM/ACCPEM_FCT2.c_v            $*/
/* $Revision::   1.0      $$Author::   hmelloul       $$Date::   26 Sep 2014 $*/
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
#include "GDGAR.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidAccPReinfPos                                     */
/* !Description :  Cete fonction permet de calculer une position pédale       */
/*                 robuste à partir du minimum des 3 dernières valeurs des    */
/*                 positions pédales brutes recalées des capteurs 1 et 2.     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  PTS_R_5021748_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 AccP_rAccPSens1;                                             */
/*  input uint16 AccP_rAccPSens2;                                             */
/*  input boolean AccP_bCycPosPedClc_C;                                       */
/*  input uint16 ACCPEM_u16AccPRAccPSens1Prev;                                */
/*  input uint16 ACCPEM_u16AccPRAccPSens1Prev2;                               */
/*  input uint16 ACCPEM_u16AccPRAccPSens2Prev;                                */
/*  input uint16 ACCPEM_u16AccPRAccPSens2Prev2;                               */
/*  output uint16 AccP_rAccPRobust;                                           */
/*  output uint16 ACCPEM_u16AccPRAccPSens1Prev2;                              */
/*  output uint16 ACCPEM_u16AccPRAccPSens1Prev;                               */
/*  output uint16 ACCPEM_u16AccPRAccPSens2Prev2;                              */
/*  output uint16 ACCPEM_u16AccPRAccPSens2Prev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidAccPReinfPos(void)
{
   uint16 u16LocalOutSwitch1;
   uint16 u16LocalOutSwitch2;
   uint16 u16LocalAccPRAccPRobust;
   uint16 u16LocalAccP_rAccPSens1;
   uint16 u16LocalAccP_rAccPSens2;
   uint32 u32LocalAccPRAccPRobust;


   VEMS_vidGET(AccP_rAccPSens1, u16LocalAccP_rAccPSens1);
   VEMS_vidGET(AccP_rAccPSens2, u16LocalAccP_rAccPSens2);

   if (AccP_bCycPosPedClc_C != 0)
   {
      u16LocalOutSwitch1 =
         (uint16)MATHSRV_udtMIN(ACCPEM_u16AccPRAccPSens1Prev,
                                ACCPEM_u16AccPRAccPSens1Prev2);
      u16LocalOutSwitch2 =
         (uint16)MATHSRV_udtMIN(ACCPEM_u16AccPRAccPSens2Prev,
                                ACCPEM_u16AccPRAccPSens2Prev2);
   }
   else
   {
      u16LocalOutSwitch1 = ACCPEM_u16AccPRAccPSens1Prev;
      u16LocalOutSwitch2 = ACCPEM_u16AccPRAccPSens2Prev;
   }
   u16LocalAccPRAccPRobust =
      (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccPSens1,
                             u16LocalOutSwitch1);
   u16LocalAccPRAccPRobust =
      (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccPSens2,
                             u16LocalAccPRAccPRobust);
   u16LocalAccPRAccPRobust =
      (uint16)MATHSRV_udtMIN(u16LocalAccPRAccPRobust,
                             u16LocalOutSwitch2);
   u32LocalAccPRAccPRobust = (uint32)((u16LocalAccPRAccPRobust * 25) / 2);
   AccP_rAccPRobust = (uint16)MATHSRV_udtMIN(u32LocalAccPRAccPRobust, 12800);

   ACCPEM_u16AccPRAccPSens1Prev2 =
      (uint16)MATHSRV_udtMIN(ACCPEM_u16AccPRAccPSens1Prev, 1024);
   ACCPEM_u16AccPRAccPSens1Prev =
      (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccPSens1, 1024);
   ACCPEM_u16AccPRAccPSens2Prev2 =
      (uint16)MATHSRV_udtMIN(ACCPEM_u16AccPRAccPSens2Prev, 1024);
   ACCPEM_u16AccPRAccPSens2Prev =
      (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccPSens2, 1024);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPEM_vidAccPSatPos                                       */
/* !Description :  Cette fonction  permet d’effectuer un bouclage de la       */
/*                 position pédale robuste à sa dernière valeur lorsqu’un     */
/*                 défaut électrique sur les capteurs de position pédale est  */
/*                 en état ponctuel présent et de saturer cette position      */
/*                 pédale à 99.5                                              */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  PTS_R_5021748_002.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean AccP_bInhDiagCoh_C;                                         */
/*  input uint16 AccP_rAccPLim;                                               */
/*  input uint16 AccP_rAccPRobust;                                            */
/*  output uint16 AccP_rAccPLim;                                              */
/*  output boolean AccP_bDftElAccP;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPEM_vidAccPSatPos(void)
{
   boolean            bLocalAccP_bDftElAccP;
   uint16             u16LocalOutSwitch;
   GDFRM_tenuGDUState LocalstDgoCoh_Ped;
   GDFRM_tenuGDUState LocalstDgoScg_Ped1;
   GDFRM_tenuGDUState LocalstDgoScg_Ped2;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped1;
   GDFRM_tenuGDUState LocalstDgoScpOc_Ped2;


   LocalstDgoScg_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED1);
   LocalstDgoScpOc_Ped1 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED1);
   LocalstDgoCoh_Ped = GDGAR_tenuGetStDgo(GD_DFT_COH_PED);
   LocalstDgoScpOc_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCPOC_PED2);
   LocalstDgoScg_Ped2 = GDGAR_tenuGetStDgo(GD_DFT_SCG_PED2);

   if (  (LocalstDgoScg_Ped1 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScg_Ped1 == GDU_ETAT_PCTL_ABSENT)
      || (LocalstDgoScpOc_Ped1 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScpOc_Ped1 == GDU_ETAT_PCTL_ABSENT)
      || (LocalstDgoScpOc_Ped2 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScpOc_Ped2 == GDU_ETAT_PCTL_ABSENT)
      || (LocalstDgoScg_Ped2 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScg_Ped2 == GDU_ETAT_PCTL_ABSENT)
      || (  (AccP_bInhDiagCoh_C == 0)
         && (  (LocalstDgoCoh_Ped == GDU_ETAT_PCTL_PRESENT)
            || (LocalstDgoCoh_Ped == GDU_ETAT_PCTL_ABSENT))))
   {
      bLocalAccP_bDftElAccP = 1;
   }
   else
   {
      bLocalAccP_bDftElAccP = 0;
   }

   if (bLocalAccP_bDftElAccP != 0)
   {
      u16LocalOutSwitch =
         (uint16)MATHSRV_udtMIN(AccP_rAccPLim, AccP_rAccPRobust);
   }
   else
   {
      u16LocalOutSwitch = AccP_rAccPRobust;
   }
   AccP_rAccPLim = (uint16)MATHSRV_udtMIN(u16LocalOutSwitch, 12736);
   VEMS_vidSET(AccP_bDftElAccP, bLocalAccP_bDftElAccP);
}
/*------------------------------end of file-----------------------------------*/