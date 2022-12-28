/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CRSCTLBSITREAT                                          */
/* !Description     : CRSCTLBSITREAT Component                                */
/*                                                                            */
/* !Module          : CRSCTLBSITREAT                                          */
/* !Description     : TRAITEMENT DES INFORMATIONS BSI POUR LES BESOINS DE LA  */
/*                    XVV                                                     */
/*                                                                            */
/* !File            : CRSCTLBSITREAT_FCT2.C                                   */
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
/*   1 / CRSCTLBSITREAT_vidRegSpdSpCoh                                        */
/*   2 / CRSCTLBSITREAT_vidCksCoh                                             */
/*   3 / CRSCTLBSITREAT_vidDiag_2                                             */
/*   4 / CRSCTLBSITREAT_vidNVRAMmanagemnt                                     */
/*   5 / CRSCTLBSITREAT_vidInfoTreat                                          */
/*   6 / CRSCTLBSITREAT_vidOutspdVehLimRq                                     */
/*   7 / CRSCTLBSITREAT_vidspdVehVSRegReq                                     */
/*   8 / CRSCTLBSITREAT_vidOutAcvRgVSCtRq                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5206188 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CRSCTL/CRSCTLBSITREAT/CRSCTLBSIT$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   19 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CRSCTLBSITREAT.h"
#include "CRSCTLBSITREAT_I.h"
#include "CRSCTLBSITREAT_L.h"
#include "CRSCTLBSITREAT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidRegSpdSpCoh                              */
/* !Description :  Cette fonction teste la cohérence de la consigne de vitesse*/
/*                 envoyée par la BSI dans le cas où la RVV est sélectionnée  */
/*                 et à condition que l’ensemble des informations envoyées    */
/*                 soient cohérentes entre-elles                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Cc_regulation_speed_on_mux;                                 */
/*  input uint8 Ext_spdVehVSCtlReq;                                           */
/*  input boolean Ext_bVSRegDVSRegReq;                                        */
/*  input boolean Ext_bKeyOff;                                                */
/*  input boolean VSCtl_bMonRunElDft;                                         */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 VSCtl_spdVSRegReqMinThd_C;                                    */
/*  input uint8 VSCtl_spdVSRegReqMaxThd_C;                                    */
/*  input uint8 Ext_spdVehReqVSRegMem;                                        */
/*  input uint8 VSCtl_spdVSRegReqDeltaMin2_C;                                 */
/*  input uint8 VSCtl_spdVSRegReqDeltaMax2_C;                                 */
/*  input uint8 VSCtl_spdVSRegReqDeltaMin1_C;                                 */
/*  input uint8 VSCtl_spdVSRegReqDeltaMax1_C;                                 */
/*  input boolean Ext_bVSRegDVSRegReqMem;                                     */
/*  input uint8 VSCtl_spdVSRegReqDeltaMin4_C;                                 */
/*  input uint8 VSCtl_spdVSRegReqDeltaMax4_C;                                 */
/*  input uint8 VSCtl_spdVSRegReqDeltaMin3_C;                                 */
/*  input uint8 VSCtl_spdVSRegReqDeltaMax3_C;                                 */
/*  input boolean VSCtl_bDgoElConsDefDftVSReg;                                */
/*  input boolean VSCtl_bDgoElConsVarDftVSReg;                                */
/*  input boolean VSCtl_bDgoElConsInitDftVSReg;                               */
/*  input boolean VSCtl_bSpdVehReqVSRegDft;                                   */
/*  output boolean VSCtl_bDgoElConsDefDftVSReg;                               */
/*  output boolean VSCtl_bDgoElConsVarDftVSReg;                               */
/*  output boolean VSCtl_bDgoElConsInitDftVSReg;                              */
/*  output boolean VSCtl_bSpdVehReqVSRegDft;                                  */
/*  output uint8 Ext_spdVehReqVSRegMem;                                       */
/*  output boolean Ext_bVSRegDVSRegReqMem;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidRegSpdSpCoh(void)
{
   boolean bLocalExt_bVSRegDVSRegReq;
   boolean bLocalCc_regulation_speed_on_mux;
   boolean bLocalExt_bKeyOff;
   boolean bLocalbDgoElConsDefDftVSReg;
   boolean bLocalbDgoElConsVarDftVSReg;
   boolean bLocalbDgoElConsInitDftVSReg;
   boolean bLocalbSpdVehReqVSRegDft;
   uint8   u8LocalExt_spdVehVSCtlReq;
   uint8   u8LocalVitesse_vehicule;
   uint16  u16LocalSom1;
   uint16  u16LocalSom2;
   sint16  s16LocalDiff1;
   sint16  s16LocalDiff2;

   VEMS_vidGET(Cc_regulation_speed_on_mux, bLocalCc_regulation_speed_on_mux);
   VEMS_vidGET(Ext_spdVehVSCtlReq, u8LocalExt_spdVehVSCtlReq);
   VEMS_vidGET(Ext_bVSRegDVSRegReq, bLocalExt_bVSRegDVSRegReq);
   VEMS_vidGET(Ext_bKeyOff, bLocalExt_bKeyOff);

   if (bLocalExt_bVSRegDVSRegReq != 0)
   {
      VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);
      if (  (u8LocalExt_spdVehVSCtlReq < VSCtl_spdVSRegReqMinThd_C)
         || (u8LocalExt_spdVehVSCtlReq > VSCtl_spdVSRegReqMaxThd_C))
      {
         bLocalbDgoElConsDefDftVSReg = 1;
      }
      else
      {
         bLocalbDgoElConsDefDftVSReg = 0;
      }
      s16LocalDiff1 =
         (sint16)(Ext_spdVehReqVSRegMem - VSCtl_spdVSRegReqDeltaMin2_C);
      u16LocalSom1 =
         (uint16)(Ext_spdVehReqVSRegMem + VSCtl_spdVSRegReqDeltaMax2_C);
      s16LocalDiff2 =
         (sint16)(u8LocalVitesse_vehicule - VSCtl_spdVSRegReqDeltaMin1_C);
      u16LocalSom2 =
         (uint16)(u8LocalVitesse_vehicule + VSCtl_spdVSRegReqDeltaMax1_C);
      if (  (Ext_bVSRegDVSRegReqMem != 0)
         && (  ((sint16)u8LocalExt_spdVehVSCtlReq < s16LocalDiff1)
            || ((uint16)u8LocalExt_spdVehVSCtlReq > u16LocalSom1))
         && (  ((sint16)u8LocalExt_spdVehVSCtlReq < s16LocalDiff2)
            || ((uint16)u8LocalExt_spdVehVSCtlReq > u16LocalSom2)))
      {
         bLocalbDgoElConsVarDftVSReg = 1;
      }
      else
      {
         bLocalbDgoElConsVarDftVSReg = 0;
      }
      s16LocalDiff1 =
         (sint16)(Ext_spdVehReqVSRegMem - VSCtl_spdVSRegReqDeltaMin4_C);
      u16LocalSom1 =
         (uint16)(Ext_spdVehReqVSRegMem + VSCtl_spdVSRegReqDeltaMax4_C);
      s16LocalDiff2 =
         (sint16)(u8LocalVitesse_vehicule - VSCtl_spdVSRegReqDeltaMin3_C);
      u16LocalSom2 =
         (uint16)(u8LocalVitesse_vehicule + VSCtl_spdVSRegReqDeltaMax3_C);
      if (  (Ext_bVSRegDVSRegReqMem == 0)
         && (  ((sint16)u8LocalExt_spdVehVSCtlReq < s16LocalDiff1)
            || ((uint16)u8LocalExt_spdVehVSCtlReq > u16LocalSom1)
            || (Ext_spdVehReqVSRegMem  == 255))
         && (  ((sint16)u8LocalExt_spdVehVSCtlReq < s16LocalDiff2)
            || ((uint16)u8LocalExt_spdVehVSCtlReq > u16LocalSom2)))
      {
         bLocalbDgoElConsInitDftVSReg = 1;
      }
      else
      {
         bLocalbDgoElConsInitDftVSReg = 0;
      }
      if (  (bLocalbDgoElConsDefDftVSReg != 0)
         || (bLocalbDgoElConsVarDftVSReg != 0)
         || (bLocalbDgoElConsInitDftVSReg != 0))
      {
         bLocalbSpdVehReqVSRegDft = 1;
      }
      else
      {
         bLocalbSpdVehReqVSRegDft = 0;
      }
   }
   else
   {
      bLocalbDgoElConsDefDftVSReg = 0;
      bLocalbDgoElConsVarDftVSReg = 0;
      bLocalbDgoElConsInitDftVSReg = 0;
      bLocalbSpdVehReqVSRegDft = 0;
   }

   if (VSCtl_bMonRunElDft != 0)
   {
      VSCtl_bDgoElConsDefDftVSReg = bLocalbDgoElConsDefDftVSReg;
      VSCtl_bDgoElConsVarDftVSReg = bLocalbDgoElConsVarDftVSReg;
      VSCtl_bDgoElConsInitDftVSReg = bLocalbDgoElConsInitDftVSReg;
      VSCtl_bSpdVehReqVSRegDft = bLocalbSpdVehReqVSRegDft;
   }
   else
   {
      VSCtl_bDgoElConsDefDftVSReg = 0;
      VSCtl_bDgoElConsVarDftVSReg = 0;
      VSCtl_bDgoElConsInitDftVSReg = 0;
      VSCtl_bSpdVehReqVSRegDft = 0;
   }
   /*Ext_spdVehReqVSRegMem*/
   if (bLocalExt_bKeyOff != 0)
   {
      Ext_spdVehReqVSRegMem = 255;
      Ext_bVSRegDVSRegReqMem = 0;
   }
   else
   {
      Ext_bVSRegDVSRegReqMem = bLocalExt_bVSRegDVSRegReq;
      if (  (bLocalbSpdVehReqVSRegDft == 0)
         && (bLocalCc_regulation_speed_on_mux != 0))
      {
         if (bLocalExt_bVSRegDVSRegReq != 0)
         {
            Ext_spdVehReqVSRegMem = u8LocalExt_spdVehVSCtlReq;
         }
      }
      else
      {
         Ext_spdVehReqVSRegMem = 255;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidCksCoh                                   */
/* !Description :  Cette fonction réalise la cohérence des cheksums en        */
/*                 comparant le checksum interne (recalculé par l’ECU) à celui*/
/*                 reçu par la trame de la BSI                                */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ISCAN_u8N8F50EP219;                                           */
/*  input uint8 ISCAN_u8N2F50EP232;                                           */
/*  input uint8 Cc_coh_internal_checksum;                                     */
/*  output uint8 Cc_coh_internal_checksum;                                    */
/*  output boolean VSCtl_bDgoElChkConsDft;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidCksCoh(void)
{
   uint8 u8LocalISCAN_u8N8F50EP219;
   uint8 u8LocalISCAN_u8N2F50EP232;
   uint8 u8LocalVar1;
   uint8 u8LocalVar2;


   VEMS_vidGET(ISCAN_u8N8F50EP219, u8LocalISCAN_u8N8F50EP219);
   VEMS_vidGET(ISCAN_u8N2F50EP232, u8LocalISCAN_u8N2F50EP232);
   /*QAC Warning :Msg(2:3892) : the result of the cast never exceed uint8*/
   u8LocalVar1 = (uint8)(( ( ((u8LocalISCAN_u8N8F50EP219 & 0x80) >> 7)
                           + ((u8LocalISCAN_u8N8F50EP219 & 0x40) >> 6)
                           + ((u8LocalISCAN_u8N8F50EP219 & 0x20) >> 5)
                           + ((u8LocalISCAN_u8N8F50EP219 & 0x10) >> 4))
                         &  0x01) << 1);
   u8LocalVar2 = (uint8)( ( ((u8LocalISCAN_u8N8F50EP219 & 0x08) >> 3)
                          + ((u8LocalISCAN_u8N8F50EP219 & 0x04) >> 2)
                          + ((u8LocalISCAN_u8N8F50EP219 & 0x02) >> 1)
                          + ((u8LocalISCAN_u8N8F50EP219 & 0x01)))
                        & 0x01);
   Cc_coh_internal_checksum = (uint8)(u8LocalVar1 + u8LocalVar2);
   if (Cc_coh_internal_checksum != u8LocalISCAN_u8N2F50EP232)
   {
      VSCtl_bDgoElChkConsDft = 1;
   }
   else
   {
      VSCtl_bDgoElChkConsDft = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidDiag_2                                   */
/* !Description :  Fonction de diagnostic sur cohérence des informations de   */
/*                 BVVP                                                       */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_spdVehVSMaxPrmaReq1;                                      */
/*  input uint8 Ext_spdVehVSMaxPrmaReq2;                                      */
/*  input boolean VSCtl_bDgoElConsCohVSMaxp;                                  */
/*  input uint8 Ext_SpdVehBVVMax_C;                                           */
/*  input uint8 Ext_SpdVehBVVMin_C;                                           */
/*  output boolean VSCtl_bDgoElConsCohVSMaxp;                                 */
/*  output boolean VSCtl_bDgoElConsDefDftVSMaxp;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidDiag_2(void)
{
   uint8 u8LocalExt_spdVehVSMaxPrmaReq1;
   uint8 u8LocalExt_spdVehVSMaxPrmaReq2;


   VEMS_vidGET(Ext_spdVehVSMaxPrmaReq1, u8LocalExt_spdVehVSMaxPrmaReq1);
   VEMS_vidGET(Ext_spdVehVSMaxPrmaReq2, u8LocalExt_spdVehVSMaxPrmaReq2);
   if (u8LocalExt_spdVehVSMaxPrmaReq1 != u8LocalExt_spdVehVSMaxPrmaReq2)
   {
      VSCtl_bDgoElConsCohVSMaxp = 1;
   }
   else
   {
      VSCtl_bDgoElConsCohVSMaxp = 0;
   }

   if (  (u8LocalExt_spdVehVSMaxPrmaReq1 != 255)
      && (  (VSCtl_bDgoElConsCohVSMaxp != 0)
         || (u8LocalExt_spdVehVSMaxPrmaReq1 >= Ext_SpdVehBVVMax_C)
         || (u8LocalExt_spdVehVSMaxPrmaReq1 <= Ext_SpdVehBVVMin_C)))
   {
      VSCtl_bDgoElConsDefDftVSMaxp = 1;
   }
   else
   {
      VSCtl_bDgoElConsDefDftVSMaxp = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidNVRAMmanagemnt                           */
/* !Description :  Fonction qui gère l’écriture en RAM non volatile de la     */
/*                 consigne de vitesse RVV.                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Ext_spdVehReqVSRegMem;                                        */
/*  output uint8 XVV_Cc_rvv_drv_vh_spd_sp_mux_mem;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidNVRAMmanagemnt(void)
{
   XVV_Cc_rvv_drv_vh_spd_sp_mux_mem = Ext_spdVehReqVSRegMem;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidInfoTreat                                */
/* !Description :  Fonction qui traite les différentes informations.          */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLBSITREAT_vidOutspdVehLimRq();                      */
/*  extf argret void CRSCTLBSITREAT_vidspdVehVSRegReq();                      */
/*  extf argret void CRSCTLBSITREAT_vidOutAcvRgVSCtRq();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidInfoTreat(void)
{
   CRSCTLBSITREAT_vidOutspdVehLimRq();
   CRSCTLBSITREAT_vidspdVehVSRegReq();
   CRSCTLBSITREAT_vidOutAcvRgVSCtRq();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidOutspdVehLimRq                           */
/* !Description :  Production de la consigne de limitation de vitesse LVV.    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_spdVehVSCtlReq_2;                                         */
/*  input uint8 Ext_stVSCtlReq_2;                                             */
/*  output uint8 Ext_spdVehVSLimReq;                                          */
/*  output uint8 Ext_spdVehVSCtlReq_2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidOutspdVehLimRq(void)
{
   boolean bLocalInhvehvslimreq;


   bLocalInhvehvslimreq = GDGAR_bGetFRM(FRM_FRM_INHVEHVSLIMREQ);
   /*QAC : Msg(3:3355) :  Code imposed by Specification*/
   if (  (Ext_spdVehVSCtlReq_2 < 255)
      && (Ext_spdVehVSCtlReq_2 >= 0)
      && (bLocalInhvehvslimreq == 0)
      && (Ext_stVSCtlReq_2 == 2))
   {
      VEMS_vidSET(Ext_spdVehVSLimReq, Ext_spdVehVSCtlReq_2);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidspdVehVSRegReq                           */
/* !Description :  Fonction qui produit la consigne vitesse RVV.              */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_R_11_06467_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_spdVehVSCtlReq_2;                                         */
/*  input uint8 Ext_stVSCtlReq_2;                                             */
/*  output uint8 Ext_spdVehVSRegReq;                                          */
/*  output uint8 Ext_spdVehVSCtlReq_2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidspdVehVSRegReq(void)
{
   boolean bLocalInhVehVSRegReq;


   bLocalInhVehVSRegReq = GDGAR_bGetFRM(FRM_FRM_INHVEHVSREGREQ);
   if (  (Ext_spdVehVSCtlReq_2 < 255)
      && (Ext_spdVehVSCtlReq_2 >= 35)
      && (bLocalInhVehVSRegReq == 0)
      && (Ext_stVSCtlReq_2 == 1))
   {
      VEMS_vidSET(Ext_spdVehVSRegReq, Ext_spdVehVSCtlReq_2);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLBSITREAT_vidOutAcvRgVSCtRq                           */
/* !Description :  Fonction qui détermine le type de Régulation longitudinale */
/*                 du Véhicule demandée.                                      */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 index)boolean;                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stVSCtlReq_2;                                             */
/*  input boolean Ext_bVSRegDVSRegReq_2;                                      */
/*  input boolean Ext_bVSLimReq_2;                                            */
/*  input uint8 Ext_spdVehVSCtlReq_2;                                         */
/*  output uint8 Ext_stAcvRegVSCtlReq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLBSITREAT_vidOutAcvRgVSCtRq(void)
{
   boolean bLocalInhRegVSCtlReq;
   uint8   u8Localout;


   bLocalInhRegVSCtlReq = GDGAR_bGetFRM(FRM_FRM_INHREGVSCTLREQ);
   if (bLocalInhRegVSCtlReq != 0)
   {
      u8Localout = 0;
   }
   else
   {
      if (  (Ext_stVSCtlReq_2 == 1)
         && (Ext_bVSRegDVSRegReq_2 != 0)
         && (Ext_bVSLimReq_2 == 0)
         && (Ext_spdVehVSCtlReq_2 < 255))
      {
         u8Localout = 1;
      }
      else
      {
         if (  (Ext_stVSCtlReq_2 == 2)
            && (Ext_bVSRegDVSRegReq_2 == 0)
            && (Ext_bVSLimReq_2 != 0)
            && (Ext_spdVehVSCtlReq_2 < 255))
         {
            u8Localout = 2;
         }
         else
         {
            if (  (Ext_stVSCtlReq_2 == 3)
               && (Ext_bVSRegDVSRegReq_2 != 0)
               && (Ext_bVSLimReq_2 == 0)
               && (Ext_spdVehVSCtlReq_2 < 255))
            {
               u8Localout = 3;
            }
            else
            {
               u8Localout = 0;
            }
         }
      }
   }
   VEMS_vidSET(Ext_stAcvRegVSCtlReq, u8Localout);
}
/*------------------------------- end of file --------------------------------*/