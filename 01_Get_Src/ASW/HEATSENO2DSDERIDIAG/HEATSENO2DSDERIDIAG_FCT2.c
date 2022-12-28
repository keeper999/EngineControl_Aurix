/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSDERIDIAG                                     */
/* !Description     : HEATSENO2DSDERIDIAG component.                          */
/*                                                                            */
/* !Module          : HEATSENO2DSDERIDIAG                                     */
/* !Description     : DIAGNOSTIC DERIVEE TENSION SONDE A OXYGENE AVAL.        */
/*                                                                            */
/* !File            : HEATSENO2DSDERIDIAG_FCT2.C                              */
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
/*   1 / HEATSENO2DSDERIDIAG_vidAvgEwma                                       */
/*   2 / HEATSENO2DSDERIDIAG_vidFirstTime                                     */
/*   3 / HEATSENO2DSDERIDIAG_vidFirstDiag                                     */
/*   4 / HEATSENO2DSDERIDIAG_vidDiagSO2Ok                                     */
/*   5 / HEATSENO2DSDERIDIAG_vidDiaSO2Nok                                     */
/*   6 / HEATSENO2DSDERIDIAG_vidTrkNormal                                     */
/*   7 / HEATSENO2DSDERIDIAG_vidDiag                                          */
/*   8 / HEATSENO2DSDERIDIAG_vidSeqDiag                                       */
/*   9 / HEATSENO2DSDERIDIAG_vidSavePwrl                                      */
/*   10 / HEATSENO2DSDERIDIAG_vidSwitch                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5012852 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2DS/HEATSENO2DSDERIDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   18 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   18 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2DSDERIDIAG.h"
#include "HEATSENO2DSDERIDIAG_L.h"
#include "HEATSENO2DSDERIDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidAvgEwma                             */
/* !Description :  Calcul de la moyenne de type EWMA (Exponentially Weighted  */
/*                 Moving Average)                                            */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSDERIDIAG_vidFirstTime();                      */
/*  extf argret void HEATSENO2DSDERIDIAG_vidFirstDiag();                      */
/*  extf argret void HEATSENO2DSDERIDIAG_vidTrkNormal();                      */
/*  extf argret void HEATSENO2DSDERIDIAG_vidFacMes();                         */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_trk_ewma_eep;                                           */
/*  input uint16 Ldsd_trk_voltage_pond_dif_max_g;                             */
/*  input uint16 Ldsd_trk_voltage_pond_dif_min_g;                             */
/*  input uint16 Ldsd_trk_ewma_thresh_gas;                                    */
/*  input uint16 Ldsd_trk_voltage_pond_dif_max;                               */
/*  input uint16 Ldsd_trk_voltage_pond_dif_min;                               */
/*  input uint16 Ldsd_trk_ewma_thresh;                                        */
/*  input uint16 Ldsd_trk_voltage_pond;                                       */
/*  input boolean Ldsd_trk_first_diag;                                        */
/*  input uint16 Ldsd_trk_ewma_first_diag;                                    */
/*  input boolean SenO2Ds_bMonRunRaw_SigGrdDiag;                              */
/*  output uint16 SenO2Ds_SigGrdFacMinRaw;                                    */
/*  output uint16 Ldsd_trk_voltage_pond;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidAvgEwma(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalLdsd_trk_ewma_eep;
   uint16 u16LocalClampMax;
   uint16 u16LocalClampMin;
   sint32 s32LocalClampMin;
   uint32 u32LocalClampMax;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u32LocalClampMax = (uint32)( u16LocalLdsd_trk_ewma_eep
                                 + Ldsd_trk_voltage_pond_dif_max_g);
      s32LocalClampMin = (sint32)( u16LocalLdsd_trk_ewma_eep
                                 - Ldsd_trk_voltage_pond_dif_min_g);
      SenO2Ds_SigGrdFacMinRaw = Ldsd_trk_ewma_thresh_gas;
   }
   else
   {
      u32LocalClampMax = (uint32)( u16LocalLdsd_trk_ewma_eep
                                 + Ldsd_trk_voltage_pond_dif_max);
      s32LocalClampMin = (sint32)( u16LocalLdsd_trk_ewma_eep
                                 - Ldsd_trk_voltage_pond_dif_min);
      SenO2Ds_SigGrdFacMinRaw = Ldsd_trk_ewma_thresh;
   }
   u16LocalClampMax = (uint16)MATHSRV_udtMIN(u32LocalClampMax, 65535);
   u16LocalClampMin = (uint16)MATHSRV_udtMAX(s32LocalClampMin, 0);
   Ldsd_trk_voltage_pond = (uint16)MATHSRV_udtCLAMP(Ldsd_trk_voltage_pond,
                                                    u16LocalClampMin,
                                                    u16LocalClampMax);
   if (Ldsd_trk_first_diag != 0)
   {
      if (Ldsd_trk_ewma_first_diag == 65535)
      {
         HEATSENO2DSDERIDIAG_vidFirstTime();
      }
      else
      {
         HEATSENO2DSDERIDIAG_vidFirstDiag();
      }
   }
   else
   {
      HEATSENO2DSDERIDIAG_vidTrkNormal();
   }
   if (SenO2Ds_bMonRunRaw_SigGrdDiag != 0)
   {
      HEATSENO2DSDERIDIAG_vidFacMes();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidFirstTime                           */
/* !Description :  Lors du premier roulage, la valeur initiale de la moyenne  */
/*                 EWMA est fixée à la première valeur calculée de la moyenne */
/*                 pondérée.                                                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_trk_voltage_pond;                                       */
/*  input uint8 Ldsd_trk_iteration;                                           */
/*  output uint16 Ldsd_trk_ewma_first_diag;                                   */
/*  output uint8 Ldsd_trk_iteration;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidFirstTime(void)
{
   uint16 u16LocalLdsdTrkIteration;


   Ldsd_trk_ewma_first_diag = Ldsd_trk_voltage_pond;
   u16LocalLdsdTrkIteration = (uint16)(Ldsd_trk_iteration + 1);
   Ldsd_trk_iteration = (uint8)MATHSRV_udtMIN(u16LocalLdsdTrkIteration, 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidFirstDiag                           */
/* !Description :  A la fin du roulage, la valeur de EWMA(t) est stockée en   */
/*                 EEPROM pour servir de conditions initiales pour le prochain*/
/*                 roulage.                                                   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void HEATSENO2DSDERIDIAG_vidDiagSO2Ok();                      */
/*  extf argret void HEATSENO2DSDERIDIAG_vidDiaSO2Nok();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_trk_coef_pond_gas;                                      */
/*  input uint16 Ldsd_trk_ewma_thresh_gas;                                    */
/*  input uint8 Ldsd_trk_iteration_thresh_gas;                                */
/*  input uint16 Ldsd_trk_coef_pond;                                          */
/*  input uint16 Ldsd_trk_ewma_thresh;                                        */
/*  input uint8 Ldsd_trk_iteration_thresh;                                    */
/*  input uint16 Ldsd_trk_voltage_pond;                                       */
/*  input uint16 Ldsd_trk_ewma_first_diag;                                    */
/*  input uint8 Ldsd_trk_iteration;                                           */
/*  output uint16 Ldsd_trk_ewma_eep;                                          */
/*  output uint16 Ldsd_trk_ewma_first_diag;                                   */
/*  output uint8 Ldsd_trk_iteration;                                          */
/*  output boolean Ldsd_trk_diag_end;                                         */
/*  output boolean SenO2Ds_bMonRunRaw_SigGrdDiag;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidFirstDiag(void)
{
   uint8  u8LocalExt_stSysGas;
   uint8  u8LocalModGas;
   uint16 u16LocalLdsdTrkCoefPond;
   uint16 u16LocalLdsdTrkIteration;
   uint16 u16LocalLdsd_trk_ewma_eep;
   uint16 u16LocalModGas;
   uint16 u16LocalModGas1;
   uint32 u32LocalLdsdTrk;
   uint32 u32LocalLdsdTrkEwma;
   uint32 u32LocalLdsdTrkPond;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalModGas = Ldsd_trk_coef_pond_gas;
      u16LocalModGas1 = Ldsd_trk_ewma_thresh_gas;
      u8LocalModGas = Ldsd_trk_iteration_thresh_gas;
   }
   else
   {
      u16LocalModGas = Ldsd_trk_coef_pond;
      u16LocalModGas1 = Ldsd_trk_ewma_thresh;
      u8LocalModGas = Ldsd_trk_iteration_thresh;
   }
   u16LocalLdsdTrkCoefPond =
      (uint16)MATHSRV_udtMIN(u16LocalModGas, 1000);
   u32LocalLdsdTrkPond = (uint32)( Ldsd_trk_voltage_pond
                                 * u16LocalLdsdTrkCoefPond);
   u32LocalLdsdTrkEwma =
      (uint32)( (uint16)(1000 - u16LocalLdsdTrkCoefPond)
              * Ldsd_trk_ewma_first_diag);
   u32LocalLdsdTrk = u32LocalLdsdTrkPond + u32LocalLdsdTrkEwma;
   u16LocalLdsd_trk_ewma_eep = (uint16)(u32LocalLdsdTrk / 1000);
   VEMS_vidSET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);
   Ldsd_trk_ewma_first_diag = u16LocalLdsd_trk_ewma_eep;

   if (u16LocalLdsd_trk_ewma_eep > u16LocalModGas1)
   {
      HEATSENO2DSDERIDIAG_vidDiagSO2Ok();
   }
   else
   {
      HEATSENO2DSDERIDIAG_vidDiaSO2Nok();
   }

   u16LocalLdsdTrkIteration = (uint16)(Ldsd_trk_iteration + 1);
   Ldsd_trk_iteration = (uint8)MATHSRV_udtMIN(u16LocalLdsdTrkIteration, 255);

   if (Ldsd_trk_iteration == u8LocalModGas)
   {
      Ldsd_trk_diag_end = 1;
      SenO2Ds_bMonRunRaw_SigGrdDiag = 1;
   }
   else
   {
      Ldsd_trk_diag_end = 0;
      SenO2Ds_bMonRunRaw_SigGrdDiag = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidDiagSO2Ok                           */
/* !Description :  Ce bloc renvoie la dernière valeur de la moyenne EWMA      */
/*                 supérieure au seuil Ldsd_trk_ewma_thresh.                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ldsd_trk_sonde_ok;                                            */
/*  input uint16 Ldsd_trk_ewma_eep;                                           */
/*  output uint8 Ldsd_trk_sonde_ok;                                           */
/*  output uint16 Ldsd_trk_ewma_no_fail;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidDiagSO2Ok(void)
{
   uint16 u16LocalLdsd_trk_ewma_eep;
   uint16 u16LocalLdsdTrkSondeOk;


   u16LocalLdsdTrkSondeOk = (uint16)(Ldsd_trk_sonde_ok + 1);
   Ldsd_trk_sonde_ok = (uint8)MATHSRV_udtMIN(u16LocalLdsdTrkSondeOk, 255);
   VEMS_vidGET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);
   VEMS_vidSET(Ldsd_trk_ewma_no_fail, u16LocalLdsd_trk_ewma_eep);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidDiaSO2Nok                           */
/* !Description :  Ce bloc renvoie la dernière valeur de la moyenne EWMA      */
/*                 inférieure au seuil Ldsd_trk_ewma_thresh.                  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ldsd_trk_ewma_eep;                                           */
/*  output uint16 Ldsd_trk_ewma_failure;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidDiaSO2Nok(void)
{
   uint16 u16LocalLdsd_trk_ewma_eep;


   VEMS_vidGET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);
   VEMS_vidSET(Ldsd_trk_ewma_failure, u16LocalLdsd_trk_ewma_eep);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidTrkNormal                           */
/* !Description :  A la fin du roulage, la valeur de EWMA(t) est stockée en   */
/*                 EEPROM pour servir de conditions initiales pour le prochain*/
/*                 roulage.                                                   */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void HEATSENO2DSDERIDIAG_vidDiagSO2Ok();                      */
/*  extf argret void HEATSENO2DSDERIDIAG_vidDiaSO2Nok();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_trk_coef_pond_gas;                                      */
/*  input uint16 Ldsd_trk_ewma_thresh_gas;                                    */
/*  input uint8 Ldsd_trk_iteration_thresh_gas;                                */
/*  input uint16 Ldsd_trk_coef_pond;                                          */
/*  input uint16 Ldsd_trk_ewma_thresh;                                        */
/*  input uint8 Ldsd_trk_iteration_thresh;                                    */
/*  input uint16 Ldsd_trk_ewma_eep;                                           */
/*  input uint16 Ldsd_trk_voltage_pond;                                       */
/*  input uint8 Ldsd_trk_iteration;                                           */
/*  output uint16 Ldsd_trk_ewma_eep;                                          */
/*  output uint8 Ldsd_trk_iteration;                                          */
/*  output boolean Ldsd_trk_diag_end;                                         */
/*  output boolean SenO2Ds_bMonRunRaw_SigGrdDiag;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidTrkNormal(void)
{
   uint8  u8LocalExt_stSysGas;
   uint8  u8LocalModGas;
   uint16 u16LocalLdsdTrkCoefPond;
   uint16 u16LocalLdsd_trk_ewma_eep;
   uint16 u16LocalLdsdTrkIteration;
   uint16 u16LocalModGas;
   uint16 u16LocalModGas1;
   uint32 u32LocalLdsdTrk;
   uint32 u32LocalLdsdTrkEwma;
   uint32 u32LocalLdsdTrkPond;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalModGas = Ldsd_trk_coef_pond_gas;
      u16LocalModGas1 = Ldsd_trk_ewma_thresh_gas;
      u8LocalModGas = Ldsd_trk_iteration_thresh_gas;
   }
   else
   {
      u16LocalModGas = Ldsd_trk_coef_pond;
      u16LocalModGas1 = Ldsd_trk_ewma_thresh;
      u8LocalModGas = Ldsd_trk_iteration_thresh;
   }
   VEMS_vidGET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);
   u16LocalLdsdTrkCoefPond = (uint16)MATHSRV_udtMIN(u16LocalModGas, 1000);
   u32LocalLdsdTrkPond = (uint32)( Ldsd_trk_voltage_pond
                                 * u16LocalLdsdTrkCoefPond);
   u32LocalLdsdTrkEwma = (uint32)( (uint16)(1000 - u16LocalLdsdTrkCoefPond)
                                 * u16LocalLdsd_trk_ewma_eep);
   u32LocalLdsdTrk = u32LocalLdsdTrkPond + u32LocalLdsdTrkEwma;
   u16LocalLdsd_trk_ewma_eep = (uint16)(u32LocalLdsdTrk / 1000);

   VEMS_vidSET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);

   if (u16LocalLdsd_trk_ewma_eep > u16LocalModGas1)
   {
      HEATSENO2DSDERIDIAG_vidDiagSO2Ok();
   }
   else
   {
      HEATSENO2DSDERIDIAG_vidDiaSO2Nok();
   }

   u16LocalLdsdTrkIteration = (uint16)(Ldsd_trk_iteration + 1);
   Ldsd_trk_iteration = (uint8)MATHSRV_udtMIN(u16LocalLdsdTrkIteration, 255);
   if (Ldsd_trk_iteration == u8LocalModGas)
   {
      Ldsd_trk_diag_end = 1;
      SenO2Ds_bMonRunRaw_SigGrdDiag = 1;
   }
   else
   {
      Ldsd_trk_diag_end = 0;
      SenO2Ds_bMonRunRaw_SigGrdDiag = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidDiag                                */
/* !Description :  Un nombre calibrable (Ldsd_trk_sonde_ok_thresh) indique le */
/*                 nombre de fois où le compteur (cf bloc 1_Ldsd_trk_pannes)  */
/*                 doit être incrémenté pour déclarer la sonde sans défaut.   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Ldsd_trk_sonde_ok_thresh_gas;                                 */
/*  input uint8 Ldsd_trk_sonde_ok_thresh;                                     */
/*  input uint8 Ldsd_trk_sonde_ok;                                            */
/*  output boolean Ldsd_trk_sonde_nok;                                        */
/*  output uint8 Ldsd_trk_iteration;                                          */
/*  output uint8 Ldsd_trk_sonde_ok;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidDiag(void)
{
   uint8 u8LocalExt_stSysGas;
   uint8 u8LocalModGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u8LocalModGas = Ldsd_trk_sonde_ok_thresh_gas;
   }
   else
   {
      u8LocalModGas = Ldsd_trk_sonde_ok_thresh;
   }
   if (Ldsd_trk_sonde_ok <= u8LocalModGas)
   {
      Ldsd_trk_sonde_nok = 1;
   }
   else
   {
      Ldsd_trk_sonde_nok = 0;
   }
   Ldsd_trk_iteration = 0;
   Ldsd_trk_sonde_ok = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidSeqDiag                             */
/* !Description :  Le booléen de calibration SenO2Ds_bAcvSeqSigGrdDiag_C      */
/*                 permet d'inhiber le séquencement.Le booléen                */
/*                 SenO2Ds_bAcvSeqSigGrdDiag indique que le séquenceur est    */
/*                 actif.                                                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SenO2Ds_bAcvSeqSigGrdDiag_C;                                */
/*  input boolean Ldsd_trk_sonde_nok;                                         */
/*  output boolean SenO2Ds_bDgoORng_SigGrdDiag;                               */
/*  output boolean SenO2Ds_bMonWaitRaw_SigGrdDiag;                            */
/*  output boolean SenO2Ds_bAcvSeqSigGrdDiag;                                 */
/*  output boolean SenO2Ds_bAcvSeqMemSigGrdDiag;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidSeqDiag(void)
{
   boolean            bLocalMonWaitSigGrdDiag;
   boolean            bLocalEndDiagStrtORng_DsHeat;
   boolean            bLocalEndDiagStrtORng_DsPlausFco;
   GDFRM_tenuGDUState u8LocalstDgoORng_DsHeat;
   GDFRM_tenuGDUState u8LocalstDgoORng_DsPlausFco;


   bLocalEndDiagStrtORng_DsHeat = GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   bLocalEndDiagStrtORng_DsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSPLAUSFCO);
   if (  (bLocalEndDiagStrtORng_DsHeat == 0)
      || (bLocalEndDiagStrtORng_DsPlausFco == 0))
   {
      bLocalMonWaitSigGrdDiag = 1;

   }
   else
   {
      bLocalMonWaitSigGrdDiag = 0;
   }

   if (SenO2Ds_bAcvSeqSigGrdDiag_C != 0)
   {
      u8LocalstDgoORng_DsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
      u8LocalstDgoORng_DsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSPLAUSFCO);
      if  ( ((u8LocalstDgoORng_DsHeat == GDU_ETAT_PRESENT)
          || (u8LocalstDgoORng_DsPlausFco == GDU_ETAT_PRESENT)) )
      {
         SenO2Ds_bDgoORng_SigGrdDiag = 0;
      }
      else
      {
         SenO2Ds_bDgoORng_SigGrdDiag = Ldsd_trk_sonde_nok;
      }
      SenO2Ds_bMonWaitRaw_SigGrdDiag = bLocalMonWaitSigGrdDiag;
   }
   else
   {
      SenO2Ds_bDgoORng_SigGrdDiag = Ldsd_trk_sonde_nok;
      SenO2Ds_bMonWaitRaw_SigGrdDiag = 0;
   }

   if (  (Ldsd_trk_sonde_nok != 0)
      && (bLocalMonWaitSigGrdDiag != 0))
   {
      VEMS_vidSET(SenO2Ds_bAcvSeqSigGrdDiag, 1);
      VEMS_vidSET(SenO2Ds_bAcvSeqMemSigGrdDiag, 1);
   }
   else
   {
      VEMS_vidSET(SenO2Ds_bAcvSeqSigGrdDiag, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidSavePwrl                            */
/* !Description :  Sauvegarde en  EEPROM de la moyenne de tension             */
/*                 Ldsd_trk_ewma_eep au powerlatch.                           */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_trk_ewma_eep;                                           */
/*  output uint16 Ldsd_trk_ewma_essence_eep;                                  */
/*  output uint16 Ldsd_trk_ewma_gaz_eep;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidSavePwrl(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalLdsd_trk_ewma_eep;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);

   if (  (u8LocalExt_stSysGas == Ext_stGslMod_SC)
      || (u8LocalExt_stSysGas == Ext_stTranGslGas_SC))
   {
      Ldsd_trk_ewma_essence_eep = u16LocalLdsd_trk_ewma_eep;
   }
   else
   {
      Ldsd_trk_ewma_gaz_eep = u16LocalLdsd_trk_ewma_eep;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidSwitch                              */
/* !Description :  Cette fonction permet d’initialiser les variables          */
/*                 dépendantes de la présence d’une application Gaz et le cas */
/*                 échéant, du mode carburant utilisé au moment de la         */
/*                 réception de la première trame Gaz.                        */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSDERIDIAG_vidInitGsl();                        */
/*  extf argret void HEATSENO2DSDERIDIAG_vidInitGaz();                        */
/*  input boolean Ext_bPresGaz;                                               */
/*  input uint8 ISCAN_u8Compteur_RX_26C;                                      */
/*  input boolean Ldsd_trk_init_fait;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidSwitch(void)
{
   uint8 u8LocalExt_bPresGaz;
   uint8 u8LocalISCAN_u8Compteur_RX_26C;


   VEMS_vidGET(Ext_bPresGaz, u8LocalExt_bPresGaz);
   VEMS_vidGET(ISCAN_u8Compteur_RX_26C, u8LocalISCAN_u8Compteur_RX_26C);

   if (Ldsd_trk_init_fait == 0)
   {
      if (u8LocalExt_bPresGaz == 0)
      {
         HEATSENO2DSDERIDIAG_vidInitGsl();
      }
      else
      {
         if (u8LocalISCAN_u8Compteur_RX_26C >= 1)
         {
            HEATSENO2DSDERIDIAG_vidInitGaz();
         }
      }
   }
}
/*------------------------------- end of file --------------------------------*/