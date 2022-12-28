/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FLOWMNG                                                 */
/* !Description     : FLOWMNG Component                                       */
/*                                                                            */
/* !Module          : FLOWMNG                                                 */
/* !Description     : Management of the configurable information flow         */
/*                                                                            */
/* !File            : FLOWMNG_FCT6.C                                          */
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
/*   1 / FLOWMNG_vidOutput_posnGBxLev                                         */
/*   2 / FLOWMNG_vidOutput_GBxLev1                                            */
/*   3 / FLOWMNG_vidOutput_GBxLev2                                            */
/*   4 / FLOWMNG_vidTemporisation                                             */
/*   5 / FLOWMNG_vidDstVeh                                                    */
/*   6 / FLOWMNG_CtCoBatt                                                     */
/*   7 / FLOWMNG_vidClu2                                                      */
/*   8 / FLOWMNG_vidLoFuPmp                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5068508 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#067763                                         */
/* !OtherRefs   : VEMS V02 ECU#067819                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FLOWMNG/FLOWMNG_FCT6.c_v        $*/
/* $Revision::   1.7      $$Author::   HHAMLAOU       $$Date::   10 Dec 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   10 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FLOWMNG.h"
#include "FLOWMNG_L.h"
#include "FLOWMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidOutput_posnGBxLev                               */
/* !Description :  Fonction de selection de la position levier.               */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidOutput_GBxLev1();                             */
/*  extf argret void FLOWMNG_vidOutput_GBxLev2();                             */
/*  extf argret void FLOWMNG_vidTemporisation();                              */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean FLOWMNG_bFgigb_T1;                                          */
/*  input boolean FLOWMNG_bFgigb_T2;                                          */
/*  input boolean FLOWMNG_bFgigb_T3;                                          */
/*  input boolean FLOWMNG_bFgigb_T4;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidOutput_posnGBxLev(void)
{
   uint8 u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (u8LocalExt_stGBxCf == 1)
   {
      FLOWMNG_vidOutput_GBxLev1();
   }
   else
   {
      FLOWMNG_vidOutput_GBxLev2();
   }

   if (  (FLOWMNG_bFgigb_T1 != 0)
      || (FLOWMNG_bFgigb_T2 != 0)
      || (FLOWMNG_bFgigb_T3 != 0)
      || (FLOWMNG_bFgigb_T4 != 0))
   {
      FLOWMNG_vidTemporisation();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidOutput_GBxLev1                                  */
/* !Description :  Fonction de selection de la position levier lorsque        */
/*                 Ext_stGBxCf = 1                                            */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stTraTypCf;                                               */
/*  input uint8 Ext_stPosATLevExtdCAN;                                        */
/*  input boolean Tra_bLevMod;                                                */
/*  input boolean Fgigb_b_VsctlDiagIniGb;                                     */
/*  output boolean FLOWMNG_bFgigb_T1;                                         */
/*  output boolean FLOWMNG_bFgigb_T2;                                         */
/*  output boolean FLOWMNG_bFgigb_T3;                                         */
/*  output boolean FLOWMNG_bFgigb_T4;                                         */
/*  output uint8 Ext_posnGBxLev;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidOutput_GBxLev1(void)
{
   boolean bLocalTra_bLevMod;
   uint8   u8LocalExt_stTraTypCf;
   uint8   u8LocalExt_stPosATLevExtdCAN;
   uint8   u8LocalExtExt_posnGBxLev;


   FLOWMNG_bFgigb_T1 = 0;
   FLOWMNG_bFgigb_T2 = 0;
   FLOWMNG_bFgigb_T3 = 0;
   FLOWMNG_bFgigb_T4 = 0;
   VEMS_vidGET(Ext_stTraTypCf, u8LocalExt_stTraTypCf);
   VEMS_vidGET(Ext_stPosATLevExtdCAN, u8LocalExt_stPosATLevExtdCAN);
   VEMS_vidGET(Tra_bLevMod, bLocalTra_bLevMod);

   if (u8LocalExt_stPosATLevExtdCAN == 0)
   {
      u8LocalExtExt_posnGBxLev = 8;
   }
   else
   {
      if (u8LocalExt_stPosATLevExtdCAN == 2)
      {
         u8LocalExtExt_posnGBxLev = 0;
      }
      else
      {
         if (u8LocalExt_stPosATLevExtdCAN == 1)
         {
            u8LocalExtExt_posnGBxLev = 7;
         }
         else
         {
            if (  (u8LocalExt_stPosATLevExtdCAN == 3)
               && (bLocalTra_bLevMod == 0))
            {
               u8LocalExtExt_posnGBxLev = 9;
            }
            else
            {
               if (  (u8LocalExt_stPosATLevExtdCAN == 3)
                  && (bLocalTra_bLevMod != 0))
               {
                  u8LocalExtExt_posnGBxLev = 10;
               }
               else
               {
                  if (  (u8LocalExt_stTraTypCf == 1)
                     && (u8LocalExt_stPosATLevExtdCAN == 11))
                  {
                     u8LocalExtExt_posnGBxLev = 10;
                  }
                  else
                  {
                     if (  (u8LocalExt_stPosATLevExtdCAN == 15)
                        && (Fgigb_b_VsctlDiagIniGb != 0))
                     {
                        u8LocalExtExt_posnGBxLev = 13;
                     }
                     else
                     {
                        if (  (u8LocalExt_stPosATLevExtdCAN == 15)
                           && (Fgigb_b_VsctlDiagIniGb == 0))
                        {
                           u8LocalExtExt_posnGBxLev = 12;
                           if (u8LocalExt_stTraTypCf == 1)
                           {
                              FLOWMNG_bFgigb_T1 = 1;
                           }
                           else
                           {
                              FLOWMNG_bFgigb_T2 = 1;
                           }
                        }
                        else
                        {
                           u8LocalExtExt_posnGBxLev = 11;
                        }
                     }
                  }
               }
            }
         }
      }
   }
   VEMS_vidSET(Ext_posnGBxLev, u8LocalExtExt_posnGBxLev);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidOutput_GBxLev2                                  */
/* !Description :  Fonction de selection de la position levier lorsque        */
/*                 Ext_stGBxCf = 0.                                           */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stFuTypCf;                                                */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 Ext_posnAMTLev;                                               */
/*  input boolean Fgigb_b_VsctlDiagIniGb;                                     */
/*  input uint8 Ext_posnGBxLevDft_C;                                          */
/*  output boolean FLOWMNG_bFgigb_T1;                                         */
/*  output boolean FLOWMNG_bFgigb_T2;                                         */
/*  output boolean FLOWMNG_bFgigb_T3;                                         */
/*  output boolean FLOWMNG_bFgigb_T4;                                         */
/*  output uint8 Ext_posnGBxLev;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidOutput_GBxLev2(void)
{
   uint8 u8LocalExt_stFuTypCf;
   uint8 u8LocalExt_stGBxCf;
   uint8 u8LocalExt_posnAMTLev;
   uint8 u8LocalExtExt_posnGBxLev;

   FLOWMNG_bFgigb_T1 = 0;
   FLOWMNG_bFgigb_T2 = 0;
   FLOWMNG_bFgigb_T3 = 0;
   FLOWMNG_bFgigb_T4 = 0;
   VEMS_vidGET(Ext_stFuTypCf, u8LocalExt_stFuTypCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Ext_posnAMTLev, u8LocalExt_posnAMTLev);

   if (u8LocalExt_stGBxCf == 2)
   {
      if (u8LocalExt_posnAMTLev == 2)
      {
         u8LocalExtExt_posnGBxLev = 0;
      }
      else
      {
         if (u8LocalExt_posnAMTLev == 1)
         {
            u8LocalExtExt_posnGBxLev = 7;
         }
         else
         {
            if (u8LocalExt_posnAMTLev == 3)
            {
               u8LocalExtExt_posnGBxLev = 9;
            }
            else
            {
               if (u8LocalExt_stFuTypCf == 2)
               {
                  if (  (u8LocalExt_posnAMTLev == 4)
                     || (u8LocalExt_posnAMTLev == 5)
                     || (u8LocalExt_posnAMTLev == 6))
                  {
                     u8LocalExtExt_posnGBxLev = 10;
                  }
                  else
                  {
                     if (  (u8LocalExt_posnAMTLev == 15)
                        && (Fgigb_b_VsctlDiagIniGb != 0))
                     {
                        u8LocalExtExt_posnGBxLev = 13;
                     }
                     else
                     {
                        if (  (u8LocalExt_posnAMTLev == 15)
                           && (Fgigb_b_VsctlDiagIniGb == 0))
                        {
                           u8LocalExtExt_posnGBxLev = 12;
                           FLOWMNG_bFgigb_T4 = 1;
                        }
                        else
                        {
                           u8LocalExtExt_posnGBxLev = 11;
                        }
                     }
                  }
               }
               else
               {
                  if (u8LocalExt_posnAMTLev == 4)
                  {
                     u8LocalExtExt_posnGBxLev = 10;
                  }
                  else
                  {
                     if (  (u8LocalExt_posnAMTLev == 7)
                        && (Fgigb_b_VsctlDiagIniGb != 0))
                     {
                        u8LocalExtExt_posnGBxLev = 13;
                     }
                     else
                     {
                        if (  (u8LocalExt_posnAMTLev == 7)
                           && (Fgigb_b_VsctlDiagIniGb == 0))
                        {
                           u8LocalExtExt_posnGBxLev = 12;
                           FLOWMNG_bFgigb_T3 = 1;
                        }
                        else
                        {
                           u8LocalExtExt_posnGBxLev = 11;
                        }
                     }
                  }
               }
            }
         }
      }
   }
   else
   {
      u8LocalExtExt_posnGBxLev = Ext_posnGBxLevDft_C;
   }

   u8LocalExtExt_posnGBxLev =
      (uint8)MATHSRV_udtMIN(u8LocalExtExt_posnGBxLev, 13);
   VEMS_vidSET(Ext_posnGBxLev, u8LocalExtExt_posnGBxLev);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidTemporisation                                   */
/* !Description :  Fonction de temporisation de la position levier.           */
/* !Number      :  FCT6.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Fgigb_ti_VsctlDiagIniGb;                                     */
/*  input uint8 Fgigb_ti_VsctlDiagIniGb_C;                                    */
/*  output uint16 Fgigb_ti_VsctlDiagIniGb;                                    */
/*  output boolean Fgigb_b_VsctlDiagIniGb;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidTemporisation(void)
{
   uint16 u16LocalFgig_VsctlDiagIniGb;


   if (Fgigb_ti_VsctlDiagIniGb < 65535)
   {
      u16LocalFgig_VsctlDiagIniGb = (uint16)(Fgigb_ti_VsctlDiagIniGb + 1);
   }
   else
   {
      u16LocalFgig_VsctlDiagIniGb = Fgigb_ti_VsctlDiagIniGb;
   }
   Fgigb_ti_VsctlDiagIniGb = (uint16)MATHSRV_udtMIN(u16LocalFgig_VsctlDiagIniGb,
                                                   1000);
   u16LocalFgig_VsctlDiagIniGb = (uint16)(10 * Fgigb_ti_VsctlDiagIniGb_C);
   if (Fgigb_ti_VsctlDiagIniGb == u16LocalFgig_VsctlDiagIniGb)
   {
      Fgigb_b_VsctlDiagIniGb = 1;
   }
   else
   {
      Fgigb_b_VsctlDiagIniGb = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidDstVeh                                          */
/* !Description :  Cette fonction permet de d'affecter le kilometrage selon la*/
/*                 valeur de Ext_bArchiCf.                                    */
/* !Number      :  FCT6.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint32 Km_vehicle_mux_552h;                                         */
/*  input uint32 Km_vehicle_mux_7F2h;                                         */
/*  output uint32 Km_vehicle_mux;                                             */
/*  output uint32 Ext_dstVehTotMes;                                           */
/*  output uint32 Ext_dstVehMes;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidDstVeh(void)
{
   boolean bLocalExt_bArchiCf;
   uint32  u32LocalKm_vehicle_mux;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   if (bLocalExt_bArchiCf != 0)
   {
      VEMS_vidGET(Km_vehicle_mux_552h, u32LocalKm_vehicle_mux);
   }
   else
   {
      VEMS_vidGET(Km_vehicle_mux_7F2h, u32LocalKm_vehicle_mux);
   }

   u32LocalKm_vehicle_mux = MATHSRV_udtMIN(u32LocalKm_vehicle_mux, 16777214);
   VEMS_vidSET(Km_vehicle_mux, u32LocalKm_vehicle_mux);
   VEMS_vidSET(Ext_dstVehTotMes, u32LocalKm_vehicle_mux);

   u32LocalKm_vehicle_mux = MATHSRV_udtMIN(u32LocalKm_vehicle_mux, 500000);
   VEMS_vidSET(Ext_dstVehMes, u32LocalKm_vehicle_mux);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_CtCoBatt                                           */
/* !Description :  Fonction qui gère le défaut déconnexion batterie.          */
/* !Number      :  FCT6.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint32 Ext_ctVehPwrl;                                               */
/*  input uint32 Ext_tiCurVehTmr;                                             */
/*  input uint32 Tpsveh_seuil_haut_C;                                         */
/*  input uint32 Tpsveh_seuil_bas_C;                                          */
/*  output boolean Ext_bdftCoBatt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_CtCoBatt(void)
{
   boolean bLocalExt_bArchiCf;
   uint32  u32LocalExt_ctVehPwrl;
   uint32  u32LocalExt_tiCurVehTmr;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_ctVehPwrl, u32LocalExt_ctVehPwrl);
   VEMS_vidGET(Ext_tiCurVehTmr, u32LocalExt_tiCurVehTmr);


   if (  (u32LocalExt_ctVehPwrl < Tpsveh_seuil_haut_C)
      && (u32LocalExt_tiCurVehTmr < Tpsveh_seuil_bas_C)
      && (bLocalExt_bArchiCf != 0))
   {
      Ext_bdftCoBatt = 1;
   }
   else
   {
      Ext_bdftCoBatt = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidClu2                                            */
/* !Description :  Ce bloc 2 traite les différents cas pour les signaux       */
/*                 d'embrayage                                                */
/* !Number      :  FCT6.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean Clu_bCluPedEng;                                             */
/*  input boolean Ext_bCluPedPrssMes;                                         */
/*  input boolean Ctrl_bCluPedPrssSen;                                        */
/*  input boolean Ctrl_rCluPedPrssMes;                                        */
/*  input boolean Ctrl_CMMPropSnsrOnly_PTT;                                   */
/*  input boolean Ctrl_ESPPropSnsr_CMMPropSnsr;                               */
/*  input boolean Ctrl_ESPPropSnsr_CMMSwt;                                    */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  output boolean Ext_bCluPedPrss;                                           */
/*  output boolean Cps_clutch_pedal_input;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FLOWMNG_vidClu2                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidClu2(void)
{
   boolean bLocalExt_bCluPedPrss;
   boolean bLocalClu_bCluPedEng;
   boolean bLocalExt_bCluPedPrssMes;
   boolean bLocalFRM_bINHCLUCLCNBCLUDFT;
   boolean bLocalCtrl_bCluPedPrssSen;
   boolean bLocalCtrl_rCluPedPrssMes;
   boolean bLocalCtrl_CMMPropSnsrOnly_PTT;
   boolean bLocalCtrl_ESPPropSnsr_CMMSwt;
   boolean bLocalCtrl_ESPPropSnsr_CMMPrSnsr;
   uint8   u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Clu_bCluPedEng, bLocalClu_bCluPedEng);
   VEMS_vidGET(Ext_bCluPedPrssMes, bLocalExt_bCluPedPrssMes);
   VEMS_vidGET(Ctrl_bCluPedPrssSen, bLocalCtrl_bCluPedPrssSen);
   VEMS_vidGET(Ctrl_rCluPedPrssMes, bLocalCtrl_rCluPedPrssMes);
   VEMS_vidGET(Ctrl_CMMPropSnsrOnly_PTT, bLocalCtrl_CMMPropSnsrOnly_PTT);
   VEMS_vidGET(Ctrl_ESPPropSnsr_CMMPropSnsr, bLocalCtrl_ESPPropSnsr_CMMPrSnsr);
   VEMS_vidGET(Ctrl_ESPPropSnsr_CMMSwt, bLocalCtrl_ESPPropSnsr_CMMSwt);

   bLocalFRM_bINHCLUCLCNBCLUDFT = GDGAR_bGetFRM(FRM_FRM_INHCLUCLCNBCLUDFT);
   /*production of Ext_bCluPedPrss and Cps_clutch_pedal_input*/

   if (u8LocalExt_stGBxCf != 0)
   {
      bLocalExt_bCluPedPrss = 0;
   }
   else
   {
      if (bLocalCtrl_bCluPedPrssSen !=0)
      {
         bLocalExt_bCluPedPrss = bLocalExt_bCluPedPrssMes;
      }
      else
      {
         if (  (bLocalCtrl_rCluPedPrssMes != 0)
            || (bLocalCtrl_CMMPropSnsrOnly_PTT != 0)
            || (bLocalCtrl_ESPPropSnsr_CMMPrSnsr != 0))
         {
            bLocalExt_bCluPedPrss = bLocalClu_bCluPedEng;
         }
         else
         {
            if (bLocalCtrl_ESPPropSnsr_CMMSwt != 0)
            {
               if (bLocalFRM_bINHCLUCLCNBCLUDFT != 0)
               {
                  bLocalExt_bCluPedPrss = bLocalClu_bCluPedEng;
               }
               else
               {
                  bLocalExt_bCluPedPrss = bLocalExt_bCluPedPrssMes;
               }
            }
            else
            {
               VEMS_vidGET(Ext_bCluPedPrss, bLocalExt_bCluPedPrss);
            }
         }
      }
   }
   VEMS_vidSET(Ext_bCluPedPrss, bLocalExt_bCluPedPrss);
   VEMS_vidSET(Cps_clutch_pedal_input, bLocalExt_bCluPedPrss);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidLoFuPmp                                         */
/* !Description :  Fonction qui gère la commande de la pompe à essence.       */
/* !Number      :  FCT6.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ctrl_bAcv_FuTnkPmp;                                         */
/*  input boolean ECU_bPrepIgEngWkuSt;                                        */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint16 Ext_rFlowFuTnkPmp;                                           */
/*  input boolean Commande_pompe_ess;                                         */
/*  input uint16 FuPmp_rLoAcvFuTnkPmp_C;                                      */
/*  input boolean FuPmp_bTypFuTnkPmp_C;                                       */
/*  output boolean Ext_bAcvLoFuPmp;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidLoFuPmp(void)
{
   boolean bLocalCtrl_bAcv_FuTnkPmp;
   boolean bLocalExt_bAcvLoFuPmp;
   boolean bLocalECU_bPrepIgEngWkuSt;
   boolean bLocalECU_bWkuMain;
   boolean bLocalCommande_pompe_ess;
   boolean bLocalComp;
   boolean bLocalCalc;
   boolean bLocalSwitch;
   uint16  u16LocalExt_rFlowFuTnkPmp;


   VEMS_vidGET(Ctrl_bAcv_FuTnkPmp, bLocalCtrl_bAcv_FuTnkPmp);
   VEMS_vidGET(ECU_bPrepIgEngWkuSt, bLocalECU_bPrepIgEngWkuSt);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   if (bLocalCtrl_bAcv_FuTnkPmp != 0)
   {
      bLocalSwitch = 1;
   }
   else
   {
      VEMS_vidGET(Ext_rFlowFuTnkPmp, u16LocalExt_rFlowFuTnkPmp);
      VEMS_vidGET(Commande_pompe_ess, bLocalCommande_pompe_ess);
      if (u16LocalExt_rFlowFuTnkPmp >= FuPmp_rLoAcvFuTnkPmp_C)
      {
         bLocalComp = 1;
      }
      else
      {
         bLocalComp = 0;
      }

      if (FuPmp_bTypFuTnkPmp_C != 0)
      {
         bLocalCalc = bLocalComp;
      }
      else
      {
         bLocalCalc = !(bLocalComp);
      }

      if (  (bLocalCalc != 0)
         && (bLocalCommande_pompe_ess != 0))
      {
         bLocalSwitch = 1;
      }
      else
      {
         bLocalSwitch = 0;
      }
   }

   if (  (bLocalSwitch != 0)
      && (  (bLocalECU_bWkuMain != 0)
         || (bLocalECU_bPrepIgEngWkuSt != 0)))
   {
      bLocalExt_bAcvLoFuPmp = 1;
   }
   else
   {
      bLocalExt_bAcvLoFuPmp = 0;
   }
   VEMS_vidSET(Ext_bAcvLoFuPmp, bLocalExt_bAcvLoFuPmp);
}
/*------------------------------- end of file --------------------------------*/