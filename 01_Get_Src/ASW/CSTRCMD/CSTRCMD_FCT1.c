/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRCMD                                                 */
/* !Description     : CSTRCMD component.                                      */
/*                                                                            */
/* !Module          : CSTRCMD                                                 */
/* !Description     : STRATEGIE COMMANDE DE L’ELECTROVANNE PURGE CANISTER     */
/*                                                                            */
/* !File            : CSTRCMD_FCT1.C                                          */
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
/*   1 / CSTRCMD_vidInitOutput                                                */
/*   2 / CSTRCMD_vidCmd                                                       */
/*   3 / CSTRCMD_vidDiag                                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6562479 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTRCMD/CSTRCMD_FCT1.C_v          $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   15 May 2014 $*/
/* $Author::   wbouach                                $$Date::   15 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CSTRCMD.h"
#include "CSTRCMD_L.h"
#include "CSTRCMD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRCMD_vidInitOutput                                      */
/* !Description :  Initialisation des variables produites.                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean CSTRCMD_bMaxHysOut;                                        */
/*  output boolean CSTRCMD_bMinHysOut;                                        */
/*  output sint16 CSTRCMD_s16ExtuBattMesPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRCMD_vidInitOutput(void)
{
   CSTRCMD_bMaxHysOut = 0;
   CSTRCMD_bMinHysOut = 0;
   CSTRCMD_s16ExtuBattMesPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRCMD_vidCmd                                             */
/* !Description :  Le rapport cyclique d’ouverture de la purge canister pilote*/
/*                  la sortie purge canister de ECU.                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_E_09_01860_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Rco_applique_purge;                                           */
/*  input boolean Clef_de_contact;                                            */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 CSTRCMD_s16ExtuBattMesPrev;                                  */
/*  input uint8 Ext_uBattMes_Nom;                                             */
/*  input boolean Ext_bAcv_Cnstr_rCtlBattCor_C;                               */
/*  input uint8 Rco_applique_purge_corr;                                      */
/*  input uint8 Cstr_CtlCstrReq_DrvMax_C;                                     */
/*  input uint8 Cstr_CtlCstrReq_DrvMin_C;                                     */
/*  input uint8 rco_second_frequency_max;                                     */
/*  input uint8 rco_second_frequency_max_hys;                                 */
/*  input uint8 Rco_applique_purge_final;                                     */
/*  input boolean CSTRCMD_bMaxHysOut;                                         */
/*  input uint8 rco_second_frequency_min;                                     */
/*  input uint8 rco_second_frequency_min_hys;                                 */
/*  input boolean CSTRCMD_bMinHysOut;                                         */
/*  input uint16 Bsi_pwm_frequency_lo_cpc;                                    */
/*  input uint16 Bsi_pwm_frequency_hi_cpc;                                    */
/*  output uint8 Rco_applique_purge_corr;                                     */
/*  output uint8 Rco_applique_purge_final;                                    */
/*  output uint16 Commande_purge_pwm_freq;                                    */
/*  output uint16 Commande_purge_pwm_rco;                                     */
/*  output sint16 CSTRCMD_s16ExtuBattMesPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRCMD_vidCmd(void)
{
   boolean  bLocalClef_de_contact;
   boolean  bLocalInhCstrCmd;
   uint8    u8LocalRco_applique_purge;
   uint8    u8LocalRcoSecondFreqMaxDiff;
   uint8    u8LocalOut;
   uint16   u16LocalCommande_purge_pwm_freq;
   uint16   u16LocalRcoSecondFreqMinSum;
   uint16   u16LocalCommande_purge_pwm_rco;
   sint16   s16LocalRcoSecondFreqMaxDiff;
   sint16   s16LocalExtuBattMes;
   uint32   u32LocalNum;
   uint32   u32LocalDiv;
   sint32   s32LocalDen;


   bLocalInhCstrCmd = GDGAR_bGetFRM(FRM_FRM_INHCSTRCMD);
   VEMS_vidGET(Rco_applique_purge, u8LocalRco_applique_purge);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Ext_uBattMes, s16LocalExtuBattMes);
   s32LocalDen = (sint32)(s16LocalExtuBattMes + CSTRCMD_s16ExtuBattMesPrev);

   if (s32LocalDen <= 0)
   {
      Rco_applique_purge_corr = 0;
   }
   else
   {
      u32LocalNum =
         (uint32)(u8LocalRco_applique_purge * Ext_uBattMes_Nom * 20);
      u32LocalDiv = (u32LocalNum / (uint32)(s32LocalDen));
      Rco_applique_purge_corr = (uint8)MATHSRV_udtMIN(u32LocalDiv, 255);
   }

   if (Ext_bAcv_Cnstr_rCtlBattCor_C != 0)
   {
      u8LocalOut = Rco_applique_purge_corr;
   }
   else
   {
      u8LocalOut = u8LocalRco_applique_purge;
   }

   Rco_applique_purge_final =
      (uint8)( ( (uint16)(u8LocalOut * Cstr_CtlCstrReq_DrvMax_C)
               + (uint16)(Cstr_CtlCstrReq_DrvMin_C * (256 - u8LocalOut)))
             / 256);

   s16LocalRcoSecondFreqMaxDiff = (sint16)( rco_second_frequency_max
                                          - rco_second_frequency_max_hys);
   u8LocalRcoSecondFreqMaxDiff =
      (uint8)MATHSRV_udtMAX(s16LocalRcoSecondFreqMaxDiff, 0);

   MATHSRV_vidSchmittTriggerU16((uint16)Rco_applique_purge_final,
                                (uint16)u8LocalRcoSecondFreqMaxDiff,
                                (uint16)rco_second_frequency_max,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &CSTRCMD_bMaxHysOut);

   u16LocalRcoSecondFreqMinSum = (uint16)( rco_second_frequency_min
                                         + rco_second_frequency_min_hys);

   MATHSRV_vidSchmittTriggerU16((uint16)Rco_applique_purge_final,
                                (uint16)rco_second_frequency_min,
                                u16LocalRcoSecondFreqMinSum,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &CSTRCMD_bMinHysOut);

   if (  (CSTRCMD_bMaxHysOut != 0)
      || (CSTRCMD_bMinHysOut != 0))
   {
      u16LocalCommande_purge_pwm_freq  = Bsi_pwm_frequency_lo_cpc;
   }
   else
   {
      u16LocalCommande_purge_pwm_freq = Bsi_pwm_frequency_hi_cpc;
   }
   VEMS_vidSET(Commande_purge_pwm_freq , u16LocalCommande_purge_pwm_freq);

   if (  (bLocalClef_de_contact !=0)
      && (bLocalInhCstrCmd == 0))
   {
      u16LocalCommande_purge_pwm_rco = (uint16)(128 * Rco_applique_purge_final);
   }
   else
   {
      u16LocalCommande_purge_pwm_rco = 0;
   }
   VEMS_vidSET(Commande_purge_pwm_rco , u16LocalCommande_purge_pwm_rco);
   CSTRCMD_s16ExtuBattMesPrev = (sint16)MATHSRV_udtCLAMP(s16LocalExtuBattMes,
                                                         0,
                                                         3200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CSTRCMD_vidDiag                                            */
/* !Description :  Diagnostic circuit ouvert, circuit lié à la masse et       */
/*                 alimentation.                                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_09_01860_004.01                                     */
/*                 VEMS_R_09_01860_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean EcuSt_bInhDiagOcCmdActr;                                    */
/*  input boolean Dft_oc_cstrdrv;                                             */
/*  input boolean Dft_scg_cstrdrv;                                            */
/*  input boolean Dena_scg_cstrdrv;                                           */
/*  input boolean Dena_oc_cstrdrv;                                            */
/*  input boolean Dena_scw_cstrdrv;                                           */
/*  input boolean Dft_scw_cstrdrv;                                            */
/*  output boolean Cstr_bDgoLoCstrDrv;                                        */
/*  output boolean Cstr_bMonRunLoCstrDrv;                                     */
/*  output boolean Cstr_bMonRunHiCstrDrv;                                     */
/*  output boolean Cstr_bDgoHiCstrDrv;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CSTRCMD_vidDiag(void)
{
   boolean  bLocalInhCstrCmdDiagEl;
   boolean  bLocalREcuSt_bInhDiagOcCmdActr;
   boolean  bLocalDft_oc_cstrdrv;
   boolean  bLocalDft_scg_cstrdrv;
   boolean  bLocalDena_scg_cstrdrv;
   boolean  bLocalDena_oc_cstrdrv;
   boolean  bLocalDena_scw_cstrdrv;
   boolean  bLocalDft_scw_cstrdrv;


   bLocalInhCstrCmdDiagEl = GDGAR_bGetFRM(FRM_FRM_INHCSTRCMDDIAGEL);
   VEMS_vidGET(EcuSt_bInhDiagOcCmdActr, bLocalREcuSt_bInhDiagOcCmdActr);
   VEMS_vidGET(Dft_oc_cstrdrv, bLocalDft_oc_cstrdrv);
   VEMS_vidGET(Dft_scg_cstrdrv, bLocalDft_scg_cstrdrv);
   VEMS_vidGET(Dena_scg_cstrdrv, bLocalDena_scg_cstrdrv);
   VEMS_vidGET(Dena_oc_cstrdrv, bLocalDena_oc_cstrdrv);
   VEMS_vidGET(Dena_scw_cstrdrv, bLocalDena_scw_cstrdrv);
   VEMS_vidGET(Dft_scw_cstrdrv, bLocalDft_scw_cstrdrv);

   if (  (  (bLocalDft_oc_cstrdrv != 0)
         && (bLocalDena_oc_cstrdrv != 0))
      || (  (bLocalDft_scg_cstrdrv != 0)
         && (bLocalDena_scg_cstrdrv != 0)))
   {
      Cstr_bDgoLoCstrDrv = 1;
   }
   else
   {
      Cstr_bDgoLoCstrDrv = 0;
   }

   if (  (bLocalInhCstrCmdDiagEl == 0)
      && (bLocalREcuSt_bInhDiagOcCmdActr == 0)
      && (  (bLocalDena_scg_cstrdrv != 0)
         || (bLocalDena_oc_cstrdrv != 0)))
   {
      Cstr_bMonRunLoCstrDrv = 1;
   }
   else
   {
      Cstr_bMonRunLoCstrDrv = 0;
   }

   if (  (bLocalInhCstrCmdDiagEl == 0)
      && (bLocalDena_scw_cstrdrv != 0))
   {
      Cstr_bMonRunHiCstrDrv = 1;
   }
   else
   {
      Cstr_bMonRunHiCstrDrv = 0;
   }

   Cstr_bDgoHiCstrDrv = bLocalDft_scw_cstrdrv;

}
/*------------------------------- End of file --------------------------------*/