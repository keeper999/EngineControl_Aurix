/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DRVRSENO2US                                             */
/* !Description     : DRVRSENO2US Component                                   */
/*                                                                            */
/* !Module          : DRVRSENO2US                                             */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA SORTIE LOGIQUE SONDE A     */
/*                    OXYGENE AMONT                                           */
/*                                                                            */
/* !File            : DRVRSENO2US_FCT1.C                                      */
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
/*   1 / DRVRSENO2US_vidInitOutput                                            */
/*   2 / DRVRSENO2US_vidHeatSenO2DsCmd                                        */
/*   3 / DRVRSENO2US_vidSdlDiag                                               */
/*   4 / DRVRSENO2US_vidDiag                                                  */
/*   5 / DRVRSENO2US_vidDiagEna                                               */
/*   6 / DRVRSENO2US_vidDiagTest                                              */
/*   7 / DRVRSENO2US_vidUAcqn                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6559003 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#047678                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/DRVRSENO2US/DRVRSENO2US_$*/
/* $Revision::   1.12     $$Author::   hmelloul       $$Date::   19 May 2014 $*/
/* $Author::   hmelloul                               $$Date::   19 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Std_Limits.h"
#include "MATHSRV.h"
#include "DRVRSENO2US.h"
#include "DRVRSENO2US_L.h"
#include "DRVRSENO2US_IM.h"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2US_vidInitOutput                                  */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_uEcuUsMes;                                              */
/*  output uint16 Ichauff_SO2Us;                                              */
/*  output uint16 Rchauff_SO2Us;                                              */
/*  output boolean M_diag_chauffage_amont;                                    */
/*  output boolean Ext_bDgoHi_DrvrSenO2Us;                                    */
/*  output boolean Ext_bDgoLo_DrvrSenO2Us;                                    */
/*  output uint8 DRVRSENO2US_u8SdlDiagCall;                                   */
/*  output uint16 LsMon_resLsUsHeat;                                          */
/*  output boolean Commande_chauffage_drvrseno2us;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2US_vidInitOutput(void)
{
   VEMS_vidSET(Ext_uEcuUsMes, 0);
   VEMS_vidSET(Ichauff_SO2Us, 0);
   VEMS_vidSET(Rchauff_SO2Us, 0);
   VEMS_vidSET(M_diag_chauffage_amont, 0);
   Ext_bDgoHi_DrvrSenO2Us = 0;
   Ext_bDgoLo_DrvrSenO2Us = 0;
   DRVRSENO2US_u8SdlDiagCall = 0;
   VEMS_vidSET(LsMon_resLsUsHeat, 0);
   VEMS_vidSET(Commande_chauffage_drvrseno2us, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2US_vidHeatSenO2DsCmd                              */
/* !Description :  Le booléen Chauf_o2_amont_demande_on est directement envoyé*/
/*                 au LdB.                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Chauf_o2_amont_demande_on;                                  */
/*  output boolean Commande_chauffage_drvrseno2us;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2US_vidHeatSenO2DsCmd(void)
{
   /* F01_DrvrSenO2Us_HeatSenO2DsCmd */
   boolean bLocalChauf_o2_amont_demande_on;


   VEMS_vidGET(Chauf_o2_amont_demande_on, bLocalChauf_o2_amont_demande_on);
   VEMS_vidSET(Commande_chauffage_drvrseno2us, bLocalChauf_o2_amont_demande_on);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2US_vidSdlDiag                                     */
/* !Description :  On génère un nouveau function call (SdlDiag_DrvrSenO2Us)   */
/*                 basé sur SdlFast. Ce nouveau function call ne sera émis    */
/*                 qu’un SdlFast sur 2                                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2US_vidDiag();                                   */
/*  input uint8 DRVRSENO2US_u8SdlDiagCall;                                    */
/*  output uint8 DRVRSENO2US_u8SdlDiagCall;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2US_vidSdlDiag(void)
{
   /* F02_DrvrSenO2Us_SdlDiag */
   DRVRSENO2US_u8SdlDiagCall = (uint8)((DRVRSENO2US_u8SdlDiagCall + 1) % 2);
   if (DRVRSENO2US_u8SdlDiagCall == 0)
   {
      DRVRSENO2US_vidDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2US_vidDiag                                        */
/* !Description :  Fonction du traitement diagnostic.                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2US_vidDiagEna();                                */
/*  extf argret void DRVRSENO2US_vidDiagTest();                               */
/*  input boolean DRVRSENO2US_bDiagEnable;                                    */
/*  output boolean Ext_bMonRunLo_DrvrSenO2Us;                                 */
/*  output boolean Ext_bMonRunHi_DrvrSenO2Us;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2US_vidDiag(void)
{
   /* F03_DrvrSenO2Us_Diag */
   DRVRSENO2US_vidDiagEna();

   if(DRVRSENO2US_bDiagEnable !=0)
   {
      DRVRSENO2US_vidDiagTest();
   }
   else
   {
      Ext_bMonRunLo_DrvrSenO2Us = 0;
      Ext_bMonRunHi_DrvrSenO2Us = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2US_vidDiagEna                                     */
/* !Description :  Le diagnostic ne sera autorisé que si la variable «        */
/*                 FRM_bInhHeatSenO2Us » est à 0 et la tension batterie est   */
/*                 comprise entre « Lshd_min_voltage_diag_thresh » et «       */
/*                 Lshd_max_voltage_diag_thresh ».                            */
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
/*  output boolean DRVRSENO2US_bDiagEnable;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2US_vidDiagEna(void)
{
   /* F01_DrvrSenO2Us_DiagEna */
   boolean bLocalAcvInhDrvrSenO2Us;
   boolean bLocalAcvInhDrvrSenO2UsElDiag;
   sint16  s16LocalExt_uBattMes;


   bLocalAcvInhDrvrSenO2Us = GDGAR_bGetFRM(FRM_FRM_INHDRVRSENO2US);
   bLocalAcvInhDrvrSenO2UsElDiag = GDGAR_bGetFRM(FRM_FRM_INHDRVRSENO2USELDIAG);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   s16LocalExt_uBattMes = (sint16)((sint32)(s16LocalExt_uBattMes * 100) / 236);

   if (  (s16LocalExt_uBattMes > Lshd_min_voltage_diag_thresh)
      && (s16LocalExt_uBattMes < Lshd_max_voltage_diag_thresh)
      && (bLocalAcvInhDrvrSenO2Us == 0)
      && (bLocalAcvInhDrvrSenO2UsElDiag == 0))
   {
      DRVRSENO2US_bDiagEnable = 1;
   }
   else
   {
      DRVRSENO2US_bDiagEnable = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2US_vidDiagTest                                    */
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
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean EcuSt_bInhDiagOcCmdActr;                                    */
/*  input boolean Dena_oc_drvrseno2us;                                        */
/*  input boolean Dena_scg_drvrseno2us;                                       */
/*  input boolean Dft_oc_drvrseno2us;                                         */
/*  input boolean Dft_scg_drvrseno2us;                                        */
/*  input boolean Dena_scw_drvrseno2us;                                       */
/*  input boolean Dft_scw_drvrseno2us;                                        */
/*  input boolean Ext_bDgoLo_DrvrSenO2Us;                                     */
/*  output boolean Ext_bMonRunLo_DrvrSenO2Us;                                 */
/*  output boolean Ext_bDgoLo_DrvrSenO2Us;                                    */
/*  output boolean M_diag_chauffage_amont;                                    */
/*  output boolean Ext_bMonRunHi_DrvrSenO2Us;                                 */
/*  output boolean Ext_bDgoHi_DrvrSenO2Us;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2US_vidDiagTest(void)
{
   /* F02_DrvrSenO2Us_DiagTest */
   boolean          bLocalEcuSt_bInhDiagOcCmdActr;
   boolean          bLocalDena_oc_drvrseno2us;
   boolean          bLocalDena_scg_drvrseno2us;
   boolean          bLocalDft_oc_drvrseno2us;
   boolean          bLocalDft_scg_drvrseno2us;
   boolean          bLocalDena_scw_drvrseno2us;
   boolean          bLocalDft_scw_drvrseno2us;


   VEMS_vidGET(EcuSt_bInhDiagOcCmdActr, bLocalEcuSt_bInhDiagOcCmdActr);
   VEMS_vidGET(Dena_oc_drvrseno2us, bLocalDena_oc_drvrseno2us);
   VEMS_vidGET(Dena_scg_drvrseno2us, bLocalDena_scg_drvrseno2us);
   VEMS_vidGET(Dft_oc_drvrseno2us, bLocalDft_oc_drvrseno2us);
   VEMS_vidGET(Dft_scg_drvrseno2us, bLocalDft_scg_drvrseno2us);
   VEMS_vidGET(Dena_scw_drvrseno2us, bLocalDena_scw_drvrseno2us);
   VEMS_vidGET(Dft_scw_drvrseno2us, bLocalDft_scw_drvrseno2us);
   if (  ((bLocalDena_oc_drvrseno2us != 0) || (bLocalDena_scg_drvrseno2us != 0))
      && (bLocalEcuSt_bInhDiagOcCmdActr == 0))
   {
      Ext_bMonRunLo_DrvrSenO2Us = 1;
   }
   else
   {
      Ext_bMonRunLo_DrvrSenO2Us = 0;
   }
   if (  ((bLocalDft_oc_drvrseno2us != 0) && (bLocalDena_oc_drvrseno2us != 0))
      || (  (bLocalDena_scg_drvrseno2us != 0)
         && (bLocalDft_scg_drvrseno2us != 0)))
   {
      Ext_bDgoLo_DrvrSenO2Us = 1;
   }
   else
   {
      Ext_bDgoLo_DrvrSenO2Us = 0;
   }
   VEMS_vidSET(M_diag_chauffage_amont, Ext_bDgoLo_DrvrSenO2Us);
   if (bLocalDena_scw_drvrseno2us != 0)
   {
      Ext_bMonRunHi_DrvrSenO2Us = 1;
   }
   else
   {
      Ext_bMonRunHi_DrvrSenO2Us = 0;
   }
   if (bLocalDft_scw_drvrseno2us != 0)
   {
      Ext_bDgoHi_DrvrSenO2Us = 1;
   }
   else
   {
      Ext_bDgoHi_DrvrSenO2Us = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2US_vidUAcqn                                       */
/* !Description :  La tension du chauffage sonde est acquise pour des besoins */
/*                 de diagnostic fonctionnel.                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Courant_chauf_seno2us;                                       */
/*  input uint16 Tension_commande_chauf_seno2us;                              */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 Ichauff_min_SenO2Us;                                         */
/*  output uint16 Ext_uEcuUsMes;                                              */
/*  output uint16 Ichauff_SO2Us;                                              */
/*  output uint16 Rchauff_SO2Us;                                              */
/*  output uint16 LsMon_resLsUsHeat;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2US_vidUAcqn(void)
{
   /* F04_DrvrSenO2Us_UAcqn */
   uint16 u16LocalCourant_seno2us;
   uint16 u16LocalTension_seno2us;
   uint16 u16LocalRchauff_SO2Us;
   uint16 u16LocalNum;
   uint16 u16LocalCourant;
   sint16 s16LocalExt_uBattMes;
   uint32 u32LocalAdcVolt;
   uint32 u32LocalNum;
   uint32 u32LocalIchauff_min;
   uint32 u32LocalCourant;
   sint32 s32LocalBattMes;
   sint32 s32LocalNum;


   VEMS_vidGET(Courant_chauf_seno2us, u16LocalCourant_seno2us);
   VEMS_vidGET(Tension_commande_chauf_seno2us, u16LocalTension_seno2us);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   u32LocalCourant = (uint32)(u16LocalCourant_seno2us * 10);
   u16LocalCourant = (uint16)MATHSRV_udtMIN(u32LocalCourant, 65535);
   VEMS_vidSET(Ext_uEcuUsMes, u16LocalTension_seno2us);
   VEMS_vidSET(Ichauff_SO2Us, u16LocalCourant);

   u32LocalIchauff_min = Ichauff_min_SenO2Us * 10;

   if (u16LocalCourant > u32LocalIchauff_min)
   {
      s32LocalBattMes = (sint32)(s16LocalExt_uBattMes * 1024);
      u32LocalAdcVolt = (uint32)(u16LocalTension_seno2us * 125);
      s32LocalNum = s32LocalBattMes - (sint32)u32LocalAdcVolt;

      if (s32LocalNum >= 0)
      {
         u32LocalNum = (uint32)s32LocalNum;
         if (u32LocalNum >= ((UINT32_MAX) / (uint32)8192))
         {
            u32LocalNum = ((u32LocalNum + 62) / 125);
            u32LocalNum = (u32LocalNum * 8192) / u16LocalCourant;
               /* !Deviation: Violation of QAC_0584 rule.                     */
               /* !Reason :   u16LocalCourant is different from zero          */
         }
         else
         {
            u32LocalNum = ( (u32LocalNum * 8192) / u16LocalCourant);
               /* !Deviation: Violation of QAC_0584 rule.                     */
               /* !Reason :   u16LocalCourant is different from zero          */
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
   u16LocalRchauff_SO2Us = (uint16)MATHSRV_udtMIN(u32LocalNum, 65535);
   VEMS_vidSET(Rchauff_SO2Us, u16LocalRchauff_SO2Us);
   u32LocalNum = u32LocalNum * 4;
   u16LocalNum = (uint16)MATHSRV_udtMIN(u32LocalNum, 65535);
   VEMS_vidSET(LsMon_resLsUsHeat, u16LocalNum);
}
/*------------------------------- End of file --------------------------------*/