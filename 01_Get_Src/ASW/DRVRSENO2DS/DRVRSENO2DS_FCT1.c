/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DRVRSENO2DS                                             */
/* !Description     : DRVRSENO2DS component                                   */
/*                                                                            */
/* !Module          : DRVRSENO2DS                                             */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA SORTIE LOGIQUE SONDE A     */
/*                    OXYGENE AVAL                                            */
/*                                                                            */
/* !File            : DRVRSENO2DS_FCT1.c                                      */
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
/*   1 / DRVRSENO2DS_vidInitOutput                                            */
/*   2 / DRVRSENO2DS_vidHeatSenO2DsCmd                                        */
/*   3 / DRVRSENO2DS_vidSdlDiag                                               */
/*   4 / DRVRSENO2DS_vidDiag                                                  */
/*   5 / DRVRSENO2DS_vidDiagEna                                               */
/*   6 / DRVRSENO2DS_vidDiagTest                                              */
/*   7 / DRVRSENO2DS_vidUAcqn                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6545446 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#047678                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/DRVRSENO2DS/DRVRSENO2DS_$*/
/* $Revision::   1.12     $$Author::   hmelloul       $$Date::   19 May 2014 $*/
/* $Author::   hmelloul                               $$Date::   19 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "Std_Limits.h"
#include "DRVRSENO2DS.h"
#include "DRVRSENO2DS_L.h"
#include "DRVRSENO2DS_IM.h"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2DS_vidInitOutput                                  */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_uEcuDsMes;                                              */
/*  output uint16 Ichauff_SO2Ds;                                              */
/*  output uint16 Rchauff_SO2Ds;                                              */
/*  output boolean Commande_chauffage_drvrseno2ds;                            */
/*  output boolean Ext_bDgoHi_DrvrSenO2Ds;                                    */
/*  output boolean Ext_bDgoLo_DrvrSenO2Ds;                                    */
/*  output uint8 DRVRSENO2DS_u8SdlDiagCall;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2DS_vidInitOutput(void)
{
   VEMS_vidSET(Ext_uEcuDsMes, 0);
   VEMS_vidSET(Ichauff_SO2Ds, 0);
   VEMS_vidSET(Rchauff_SO2Ds, 0);
   VEMS_vidSET(Commande_chauffage_drvrseno2ds, 0);
   Ext_bDgoHi_DrvrSenO2Ds = 0;
   Ext_bDgoLo_DrvrSenO2Ds = 0;
   DRVRSENO2DS_u8SdlDiagCall = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2DS_vidHeatSenO2DsCmd                              */
/* !Description :  Le booléen chauf_o2_aval_demande_on est directement envoyé */
/*                 au LdB.                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Chauf_o2_aval_demande_on;                                   */
/*  output boolean Commande_chauffage_drvrseno2ds;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2DS_vidHeatSenO2DsCmd(void)
{
   /* F01_DrvrSenO2Ds_HeatSenO2DsCmd */
   boolean bLocalChauf_o2_aval_demande_on;


   VEMS_vidGET(Chauf_o2_aval_demande_on, bLocalChauf_o2_aval_demande_on);
   VEMS_vidSET(Commande_chauffage_drvrseno2ds, bLocalChauf_o2_aval_demande_on);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2DS_vidSdlDiag                                     */
/* !Description :  On génère un nouveau function call (SdlDiag_DrvrSenO2Ds)   */
/*                 basé sur SdlFast. Ce nouveau function call ne sera émis    */
/*                 qu’un SdlFast sur 2                                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2DS_vidDiag();                                   */
/*  input uint8 DRVRSENO2DS_u8SdlDiagCall;                                    */
/*  output uint8 DRVRSENO2DS_u8SdlDiagCall;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2DS_vidSdlDiag(void)
{
   /* F02_DrvrSenO2Ds_SdlDiag */
   DRVRSENO2DS_u8SdlDiagCall = (uint8)((DRVRSENO2DS_u8SdlDiagCall + 1) % 2);
   if (DRVRSENO2DS_u8SdlDiagCall == 0)
   {
      DRVRSENO2DS_vidDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2DS_vidDiag                                        */
/* !Description :  Fonction du traitement diagnostic.                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2DS_vidDiagEna();                                */
/*  extf argret void DRVRSENO2DS_vidDiagTest();                               */
/*  input boolean DRVRSENO2DS_bDiagEnable;                                    */
/*  output boolean Ext_bMonRunLo_DrvrSenO2Ds;                                 */
/*  output boolean Ext_bMonRunHi_DrvrSenO2Ds;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2DS_vidDiag(void)
{
   /* F03_DrvrSenO2Ds_Diag */
   DRVRSENO2DS_vidDiagEna();

   if (DRVRSENO2DS_bDiagEnable != 0)
   {
      DRVRSENO2DS_vidDiagTest();
   }
   else
   {
      Ext_bMonRunLo_DrvrSenO2Ds = 0;
      Ext_bMonRunHi_DrvrSenO2Ds = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2DS_vidDiagEna                                     */
/* !Description :  Le diagnostic ne sera autorisé que si la variable «        */
/*                 Lshd_down_lbda_s_heat_diag_inh » est à 0 et la tension     */
/*                 batterie est comprise entre « Lshd_min_voltage_diag_thresh */
/*                 » et « Lshd_max_voltage_diag_thresh ».                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 Lshd_min_voltage_diag_thresh;                                */
/*  input uint16 Lshd_max_voltage_diag_thresh;                                */
/*  output boolean DRVRSENO2DS_bDiagEnable;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2DS_vidDiagEna(void)
{
   /* F01_DrvrSenO2Ds_DiagEna */
   boolean bLocalAcvInhDrvrSenO2Ds;
   boolean bLocalAcvInhDrvrSenO2DsElDiag;
   sint16  s16LocalExt_uBattMes;


   bLocalAcvInhDrvrSenO2Ds = GDGAR_bGetFRM(FRM_FRM_INHDRVRSENO2DS);
   bLocalAcvInhDrvrSenO2DsElDiag = GDGAR_bGetFRM(FRM_FRM_INHDRVRSENO2DSELDIAG);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   s16LocalExt_uBattMes = (sint16)((sint32)(s16LocalExt_uBattMes * 100) / 236);

   if (  (s16LocalExt_uBattMes > Lshd_min_voltage_diag_thresh)
      && (s16LocalExt_uBattMes < Lshd_max_voltage_diag_thresh)
      && (bLocalAcvInhDrvrSenO2Ds == 0)
      && (bLocalAcvInhDrvrSenO2DsElDiag == 0))
   {
      DRVRSENO2DS_bDiagEnable = 1;
   }
   else
   {
      DRVRSENO2DS_bDiagEnable = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2DS_vidDiagTest                                    */
/* !Description :  Nous utilisons directement les informations de détection de*/
/*                 pannes électriques fournies par le bloc masqué « DGO_OUTPUT*/
/*                 » (Bloc d’interface entre la détection des défauts sous la */
/*                 responsabilité du LdB et le comptage panne sous la         */
/*                 responsabilité du LdA).                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean EcuSt_bInhDiagOcCmdActr;                                    */
/*  input boolean Dena_oc_drvrseno2ds;                                        */
/*  input boolean Dena_scg_drvrseno2ds;                                       */
/*  input boolean Dft_scg_drvrseno2ds;                                        */
/*  input boolean Dft_oc_drvrseno2ds;                                         */
/*  input boolean Dena_scw_drvrseno2ds;                                       */
/*  input boolean Dft_scw_drvrseno2ds;                                        */
/*  output boolean Ext_bMonRunLo_DrvrSenO2Ds;                                 */
/*  output boolean Ext_bDgoLo_DrvrSenO2Ds;                                    */
/*  output boolean Ext_bMonRunHi_DrvrSenO2Ds;                                 */
/*  output boolean Ext_bDgoHi_DrvrSenO2Ds;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2DS_vidDiagTest(void)
{
   /* F02_DrvrSenO2Ds_DiagTest */
   boolean          bLocalEcuSt_bInhDiagOcCmdActr;
   boolean          bLocalDena_oc_drvrseno2ds;
   boolean          bLocalDena_scg_drvrseno2ds;
   boolean          bLocalDft_scg_drvrseno2ds;
   boolean          bLocalDft_oc_drvrseno2ds;
   boolean          bLocalDena_scw_drvrseno2ds;
   boolean          bLocalDft_scw_drvrseno2ds;


   VEMS_vidGET(EcuSt_bInhDiagOcCmdActr, bLocalEcuSt_bInhDiagOcCmdActr);
   VEMS_vidGET(Dena_oc_drvrseno2ds, bLocalDena_oc_drvrseno2ds);
   VEMS_vidGET(Dena_scg_drvrseno2ds, bLocalDena_scg_drvrseno2ds);
   VEMS_vidGET(Dft_scg_drvrseno2ds, bLocalDft_scg_drvrseno2ds);
   VEMS_vidGET(Dft_oc_drvrseno2ds, bLocalDft_oc_drvrseno2ds);
   VEMS_vidGET(Dena_scw_drvrseno2ds, bLocalDena_scw_drvrseno2ds);
   VEMS_vidGET(Dft_scw_drvrseno2ds, bLocalDft_scw_drvrseno2ds);

   if (  ((bLocalDena_oc_drvrseno2ds != 0) || (bLocalDena_scg_drvrseno2ds != 0))
      && (bLocalEcuSt_bInhDiagOcCmdActr == 0))
   {
      Ext_bMonRunLo_DrvrSenO2Ds = 1;
   }
   else
   {
      Ext_bMonRunLo_DrvrSenO2Ds = 0;
   }
   if (  ((bLocalDena_scg_drvrseno2ds != 0) && (bLocalDft_scg_drvrseno2ds != 0))
      || (  (bLocalDena_oc_drvrseno2ds != 0)
         && (bLocalDft_oc_drvrseno2ds != 0)))
   {
      Ext_bDgoLo_DrvrSenO2Ds = 1;
   }
   else
   {
      Ext_bDgoLo_DrvrSenO2Ds = 0;
   }
   if (bLocalDena_scw_drvrseno2ds != 0)
   {
      Ext_bMonRunHi_DrvrSenO2Ds = 1;
   }
   else
   {
      Ext_bMonRunHi_DrvrSenO2Ds = 0;
   }
   if (bLocalDft_scw_drvrseno2ds != 0)
   {
      Ext_bDgoHi_DrvrSenO2Ds = 1;
   }
   else
   {
      Ext_bDgoHi_DrvrSenO2Ds = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2DS_vidUAcqn                                       */
/* !Description :  La tension du chauffage sonde est acquise pour des besoins */
/*                 de diagnostic fonctionnel.                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Courant_chauf_seno2ds;                                       */
/*  input uint16 Tension_commande_chauf_seno2ds;                              */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 Ichauff_min_SenO2Ds;                                         */
/*  output uint16 Ext_uEcuDsMes;                                              */
/*  output uint16 Ichauff_SO2Ds;                                              */
/*  output uint16 Rchauff_SO2Ds;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2DS_vidUAcqn(void)
{
   /* F04_DrvrSenO2Ds_UAcqn */
   uint16 u16LocalCourant_seno2ds;
   uint16 u16LocalTension_seno2ds;
   uint16 u16LocalRchauff_SO2Ds;
   uint16 u16LocalCourant;
   sint16 s16LocalExt_uBattMes;
   uint32 u32LocalAdcVolt;
   uint32 u32LocalNum;
   uint32 u32LocalCourant;
   uint32 u32LocalIchauff_min;
   sint32 s32LocalBattMes;
   sint32 s32LocalNum1;


   VEMS_vidGET(Courant_chauf_seno2ds, u16LocalCourant_seno2ds);
   VEMS_vidGET(Tension_commande_chauf_seno2ds, u16LocalTension_seno2ds);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidSET(Ext_uEcuDsMes, u16LocalTension_seno2ds);
   u32LocalCourant = (uint32)(u16LocalCourant_seno2ds * 10);
   u16LocalCourant = (uint16)MATHSRV_udtMIN(u32LocalCourant, 65535);
   VEMS_vidSET(Ichauff_SO2Ds, u16LocalCourant);

   u32LocalIchauff_min = (10 * Ichauff_min_SenO2Ds);

   if (u16LocalCourant > u32LocalIchauff_min)
   {
      s32LocalBattMes = (sint32)(s16LocalExt_uBattMes * 1024);
      u32LocalAdcVolt = (uint32)(u16LocalTension_seno2ds * 125);
      s32LocalNum1 = s32LocalBattMes - (sint32)u32LocalAdcVolt;
      if (s32LocalNum1 >= 0)
      {
         u32LocalNum = (uint32)s32LocalNum1;
         if (u32LocalNum >= ((UINT32_MAX) / (uint32)8192))
         {
            u32LocalNum = ((u32LocalNum + 62) / 125);
            u32LocalNum = (u32LocalNum * 8192) / u16LocalCourant;
            /*le dénominateur ne peut jamais avoir la valeur zéro*/
         }
         else
         {
            u32LocalNum = ((u32LocalNum * 8192) / u16LocalCourant);
            /*le dénominateur ne peut jamais avoir la valeur zéro*/
            u32LocalNum = ((u32LocalNum + 62) / 125);
         }
      }
      else
      {
         u32LocalNum = 0;
      }
   }
   else
   {
      u32LocalNum = 0;
   }
   u16LocalRchauff_SO2Ds = (uint16)MATHSRV_udtMIN(u32LocalNum, 65535);
   VEMS_vidSET(Rchauff_SO2Ds, u16LocalRchauff_SO2Ds);
}
/*------------------------------- End of file --------------------------------*/