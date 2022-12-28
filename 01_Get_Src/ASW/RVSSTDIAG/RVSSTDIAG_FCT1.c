/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RVSSTDIAG                                               */
/* !Description     : RVSSTDIAG component.                                    */
/*                                                                            */
/* !Module          : RVSSTDIAG                                               */
/* !Description     : Diagnostic fonctionnel de l’information marche arrière: */
/*                    détection du défaut et info MA.                         */
/*                                                                            */
/* !File            : RVSSTDIAG_FCT1.C                                        */
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
/*   1 / RVSSTDIAG_vidInitOutput                                              */
/*   2 / RVSSTDIAG_vidDiagMng                                                 */
/*   3 / RVSSTDIAG_vidCheckDiagRvs                                            */
/*                                                                            */
/* !Reference   : V02 NT 09 01180 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RVSSTDIAG/RVSSTDIAG_FCT1.C_v      $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   23 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   23 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "RVSSTDIAG.h"
#include "RVSSTDIAG_L.h"
#include "RVSSTDIAG_IM.h"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RVSSTDIAG_vidInitOutput                                    */
/* !Description :  Cette fonction initialise la sortie et le booléen de       */
/*                 signalisation  de panne  du module RVSSTDIAG               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bRvs;                                                  */
/*  output boolean Ext_bRvsVld;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RVSSTDIAG_vidInitOutput(void)
{
   VEMS_vidSET(Ext_bRvs, 0);
   VEMS_vidSET(Ext_bRvsVld, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RVSSTDIAG_vidDiagMng                                       */
/* !Description :  cette fonction permet l'activation et la déactivation  du  */
/*                 diagnostic fonctionnel " marche arrière"                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void RVSSTDIAG_vidCheckDiagRvs();                             */
/*  input boolean Ext_bRvsMux;                                                */
/*  input boolean Gear_bRvsFil;                                               */
/*  input boolean Cf_bRvsFilConf;                                             */
/*  input boolean Gear_bRvsRaw;                                               */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint32 Tra_spdVeh_nEng1000;                                         */
/*  input uint32 Rear_gear_ratio_filt_max_thresh;                             */
/*  output boolean Gear_bRvsRaw;                                              */
/*  output boolean Ext_bRvs;                                                  */
/*  output boolean Ext_bRvsVld;                                               */
/*  output boolean Gear_bMonRunRvsGear;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RVSSTDIAG_vidDiagMng(void)
{
   boolean bLocalInhRvsSt;
   boolean bLocalInhFctDiagRvsSt;
   boolean bLocalExt_bRvsMux;
   boolean bLocalExt_bCluPedPrss;
   boolean bLocalCf_bRvsFilConf;
   boolean bLocalGear_bRvsFil;
   uint8   u8LocalVehicle_active_state;
   uint32  u32LocalTra_spdVeh_nEng1000;


   bLocalInhRvsSt = GDGAR_bGetFRM(FRM_FRM_INHRVSST);
   VEMS_vidGET(Ext_bRvsMux, bLocalExt_bRvsMux);
   VEMS_vidGET(Gear_bRvsFil, bLocalGear_bRvsFil);
   VEMS_vidGET(Cf_bRvsFilConf, bLocalCf_bRvsFilConf);

   if (  (  (bLocalCf_bRvsFilConf != 0)
         && (bLocalGear_bRvsFil != 0))
      || (  (bLocalCf_bRvsFilConf == 0)
         && (bLocalExt_bRvsMux != 0)))
   {
      Gear_bRvsRaw = 1;
   }
   else
   {
      Gear_bRvsRaw = 0;
   }

   if (  (Gear_bRvsRaw != 0)
      && (bLocalInhRvsSt == 0))
   {
      VEMS_vidSET(Ext_bRvs, 1);
      VEMS_vidSET(Ext_bRvsVld, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bRvs, 0);
      VEMS_vidSET(Ext_bRvsVld, 0);
   }

   bLocalInhFctDiagRvsSt = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGRVSST);
   VEMS_vidGET(Ext_bCluPedPrss, bLocalExt_bCluPedPrss);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Tra_spdVeh_nEng1000, u32LocalTra_spdVeh_nEng1000);

   if (  (u32LocalTra_spdVeh_nEng1000 > Rear_gear_ratio_filt_max_thresh)
      && (u8LocalVehicle_active_state == VS_RUNNING)
      && (bLocalExt_bCluPedPrss == 0)
      && (bLocalInhFctDiagRvsSt == 0))
   {
      Gear_bMonRunRvsGear = 1;
      RVSSTDIAG_vidCheckDiagRvs();
   }
   else
   {
      Gear_bMonRunRvsGear = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RVSSTDIAG_vidCheckDiagRvs                                  */
/* !Description :  Cette fonction permet de sécuriser l'entrée Gear_bRvsRaw : */
/*                 si on reçoit du CAN l’information « MAR engagée » et qu'on */
/*                 sait que la chaine de traction est fermée (embrayage non   */
/*                 appuyé) et qu’on roule sur des rapports élevés, un défaut  */
/*                 est levé.                                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Gear_bRvsRaw;                                               */
/*  output boolean Gear_bDgoRvsGear;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RVSSTDIAG_vidCheckDiagRvs(void)
{
   Gear_bDgoRvsGear = Gear_bRvsRaw;
}
/*------------------------------ end of file ---------------------------------*/