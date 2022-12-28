/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINCMD                                             */
/* !Description     : VLVACTINCMD component.                                  */
/*                                                                            */
/* !Module          : VLVACTINCMD                                             */
/* !Description     : DRIVER DE LA COMMANDE VVT ADMISSION                     */
/*                                                                            */
/* !File            : VLVACTINCMD_FCT1.C                                      */
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
/*   1 / VLVACTINCMD_vidInitOutput                                            */
/*   2 / VLVACTINCMD_vidInitialization                                        */
/*   3 / VLVACTINCMD_vidEnablePwm                                             */
/*   4 / VLVACTINCMD_vidBatteryComp                                           */
/*   5 / VLVACTINCMD_vidPwmCommand                                            */
/*   6 / VLVACTINCMD_vidDiagnostic                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6588664 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTIN/VLVACTINCMD/VLVACT$*/
/* $Revision::   1.10     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINCMD.h"
#include "VLVACTINCMD_L.h"
#include "VLVACTINCMD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCMD_vidInitOutput                                  */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Commande_vvt_adm_pwm_rco;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCMD_vidInitOutput(void)
{
   VEMS_vidSET(Commande_vvt_adm_pwm_rco, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCMD_vidInitialization                              */
/* !Description :  A l’initialisation de l’ECU, la valeur de consigne RCO     */
/*                 appliquée est nulle ; la fréquence du signal RCO est       */
/*                 configurable par calibration et mise à jour uniquement à ce*/
/*                 moment.                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Rco_applique_vvt_adm;                                       */
/*  output boolean Autorisation_pwm_adm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCMD_vidInitialization(void)
{
   VEMS_vidSET(Rco_applique_vvt_adm, 0);
   Autorisation_pwm_adm = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCMD_vidEnablePwm                                   */
/* !Description :  Lors de la demande de fonctionnement de la VVT admission   */
/*                 (Demande_vvt_adm_dormant = 0), on active le driver de la   */
/*                 VVT admission (Autorisation_pwm_adm = 1) si la tension     */
/*                 batterie se situe dans la plage de fonctionnement          */
/*                 prédéfinie.                                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 Seuil_mini_vbatt_activ_vvt_adm;                               */
/*  input uint8 Seuil_maxi_vbatt_activ_vvt_adm;                               */
/*  output boolean Autorisation_pwm_adm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCMD_vidEnablePwm(void)
{
   uint16 u16LocalPMin;
   uint16 u16LocalPMax;
   sint16 s16LocalExtuBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExtuBattMes);
   u16LocalPMin = (uint16)(Seuil_mini_vbatt_activ_vvt_adm * 8);
   u16LocalPMax = (uint16)(Seuil_maxi_vbatt_activ_vvt_adm * 8);

   if (  (s16LocalExtuBattMes > u16LocalPMin)
      && (s16LocalExtuBattMes < u16LocalPMax))
   {
      Autorisation_pwm_adm = 1;
   }
   else
   {
      Autorisation_pwm_adm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCMD_vidBatteryComp                                 */
/* !Description :  Pour éviter que les variations de la tension batterie ne   */
/*                 perturbent la commande on a trois mode de compensation: pas*/
/*                 de compensation, compensation linéaire, compensation du    */
/*                 second ordre.                                              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_InMngStCmd;                                           */
/*  input uint8 Kevcpi_u_voltage_comp;                                        */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 Kfvcpi_u_reference_voltage;                                   */
/*  output uint16 VlvAct_InCmpCmd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCMD_vidBatteryComp(void)
{
   uint16 u16LocalVlvAct_InMngStCmd;
   sint16 s16LocalExtuBattMes;
   sint16 s16LocalAdmVolt;


   VEMS_vidGET(VlvAct_InMngStCmd, u16LocalVlvAct_InMngStCmd);
   if (Kevcpi_u_voltage_comp == BATT_LINEAR)
   {
      VEMS_vidGET(Ext_uBattMes, s16LocalExtuBattMes);

      if (s16LocalExtuBattMes != 0)
      {
         s16LocalAdmVolt =
            (sint16)( ( u16LocalVlvAct_InMngStCmd * Kfvcpi_u_reference_voltage
                      * 8)
                    / (s16LocalExtuBattMes));

         VlvAct_InCmpCmd = (uint16)MATHSRV_udtCLAMP(s16LocalAdmVolt, 0, 1023);
      }
      else
      {
         VlvAct_InCmpCmd = 1023;
      }
   }
   else
   {
      VlvAct_InCmpCmd = (uint16)MATHSRV_udtMIN(u16LocalVlvAct_InMngStCmd, 1023);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCMD_vidPwmCommand                                  */
/* !Description :  Lorsque le driver est activé, le module PWM correspondant à*/
/*                 la commande VVT admission est réglé pour générer le signal */
/*                 RCO désiré.                                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05879_001.01                                     */
/*                 VEMS_R_08_05879_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint16 VlvAct_InCmpCmd;                                             */
/*  input boolean Demande_vvt_adm_dormant;                                    */
/*  input boolean Autorisation_pwm_adm;                                       */
/*  input uint8 Consigne_rco_vvt_adm_min;                                     */
/*  input uint8 Consigne_rco_vvt_adm_max;                                     */
/*  input boolean Sens_rco_vvt_adm;                                           */
/*  input boolean Clef_de_contact;                                            */
/*  output boolean Demande_vvt_adm_dormant;                                   */
/*  output uint16 Rco_applique_vvt_adm;                                       */
/*  output uint16 Commande_vvt_adm_pwm_rco;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCMD_vidPwmCommand(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalInhVlvActInCmd;
   uint16  u16LocalCmd;
   uint16  u16LocalVvtFreq;
   uint16  u16LocalConsigneMin;
   uint16  u16LocalConsigneMax;
   uint16  u16LocalRco_app_vvt_adm;


   if (VlvAct_InCmpCmd != 0)
   {
      Demande_vvt_adm_dormant = 0;
   }
   else
   {
      Demande_vvt_adm_dormant = 1;
   }

   if (  (Demande_vvt_adm_dormant == 0)
      && (Autorisation_pwm_adm != 0)
      && (  (Consigne_rco_vvt_adm_min > 0)
         || (VlvAct_InCmpCmd > 0)))
   {
      u16LocalConsigneMin = (uint16)(Consigne_rco_vvt_adm_min * 4);
      u16LocalConsigneMax = (uint16)(Consigne_rco_vvt_adm_max * 4);
      u16LocalCmd = (uint16)MATHSRV_udtCLAMP(VlvAct_InCmpCmd,
                                             u16LocalConsigneMin,
                                             u16LocalConsigneMax);
   }
   else
   {
      u16LocalCmd = 0;
   }

   if (Sens_rco_vvt_adm == 0)
   {
      u16LocalRco_app_vvt_adm = u16LocalCmd;
   }
   else
   {
      u16LocalCmd = (uint16)(1024 - u16LocalCmd);
      u16LocalRco_app_vvt_adm = (uint16)MATHSRV_udtMIN(u16LocalCmd, 1023);
   }
   VEMS_vidSET(Rco_applique_vvt_adm,u16LocalRco_app_vvt_adm);
   u16LocalVvtFreq =
      (uint16)(u16LocalRco_app_vvt_adm * VVT_INTAKE_100_PERC_LDA_TO_LDB);

   VEMS_vidGET(Clef_de_contact,bLocalClef_de_contact);
   bLocalInhVlvActInCmd = GDGAR_bGetFRM(FRM_FRM_INHVLVACTINCMD);
   if (  (bLocalClef_de_contact != 0)
      && (bLocalInhVlvActInCmd == 0 ))
   {
      VEMS_vidSET(Commande_vvt_adm_pwm_rco, u16LocalVvtFreq);
   }
   else
   {
      VEMS_vidSET(Commande_vvt_adm_pwm_rco, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCMD_vidDiagnostic                                  */
/* !Description :  Fonction de diagnostique défaut du driver de la VVT        */
/*                 admission.                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05879_005.01                                     */
/*                 VEMS_R_08_05879_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_driver_vvt_adm;                                      */
/*  input boolean Dena_oc_driver_vvt_adm;                                     */
/*  input boolean Dft_scg_driver_vvt_adm;                                     */
/*  input boolean Dena_scg_driver_vvt_adm;                                    */
/*  input boolean Dena_scp_driver_vvt_adm;                                    */
/*  input boolean Dft_scp_driver_vvt_adm;                                     */
/*  input boolean EcuSt_bInhDiagOcCmdActr;                                    */
/*  output boolean VlvAct_bDgoLoVlvActInDrv;                                  */
/*  output boolean VlvActIn_bMonRunLoVlvActInDrv;                             */
/*  output boolean VlvActIn_bMonRunHiVlvActInDrv;                             */
/*  output boolean VlvAct_bDgoHiVlvActInDrv;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCMD_vidDiagnostic(void)
{
   boolean bLocalEcuSt_bInhDiagOcCmdActr;
   boolean bLocalInhVlvActInCmdDiagEl;
   boolean bLocalDft_oc_driver_vvt_adm;
   boolean bLocalDena_oc_driver_vvt_adm;
   boolean bLocalDft_scg_driver_vvt_adm;
   boolean bLocalDena_scg_driver_vvt_adm;
   boolean bLocalDena_scp_driver_vvt_adm;
   boolean bLocalDft_scp_driver_vvt_adm;


   bLocalInhVlvActInCmdDiagEl = GDGAR_bGetFRM(FRM_FRM_INHVLVACTINCMDDIAGEL);
   VEMS_vidGET(Dft_oc_driver_vvt_adm, bLocalDft_oc_driver_vvt_adm);
   VEMS_vidGET(Dena_oc_driver_vvt_adm, bLocalDena_oc_driver_vvt_adm);
   VEMS_vidGET(Dft_scg_driver_vvt_adm, bLocalDft_scg_driver_vvt_adm);
   VEMS_vidGET(Dena_scg_driver_vvt_adm, bLocalDena_scg_driver_vvt_adm);
   VEMS_vidGET(Dena_scp_driver_vvt_adm, bLocalDena_scp_driver_vvt_adm);
   VEMS_vidGET(Dft_scp_driver_vvt_adm, bLocalDft_scp_driver_vvt_adm);

   if (  (  (bLocalDft_oc_driver_vvt_adm != 0)
         && (bLocalDena_oc_driver_vvt_adm != 0))
      || (  (bLocalDft_scg_driver_vvt_adm != 0)
         && (bLocalDena_scg_driver_vvt_adm != 0)))
   {
      VlvAct_bDgoLoVlvActInDrv = 1;
   }
   else
   {
      VlvAct_bDgoLoVlvActInDrv = 0;
   }

   VEMS_vidGET(EcuSt_bInhDiagOcCmdActr, bLocalEcuSt_bInhDiagOcCmdActr);

   if (bLocalInhVlvActInCmdDiagEl == 0)
   {
      if (  (  (bLocalDena_oc_driver_vvt_adm != 0)
            || (bLocalDena_scg_driver_vvt_adm != 0))
         && (bLocalEcuSt_bInhDiagOcCmdActr == 0))
      {
         VlvActIn_bMonRunLoVlvActInDrv = 1;
      }
      else
      {
         VlvActIn_bMonRunLoVlvActInDrv = 0;
      }
      if (bLocalDena_scp_driver_vvt_adm != 0)
      {
         VlvActIn_bMonRunHiVlvActInDrv = 1;
      }
      else
      {
         VlvActIn_bMonRunHiVlvActInDrv = 0;
      }
   }
   else
   {
      VlvActIn_bMonRunLoVlvActInDrv = 0;
      VlvActIn_bMonRunHiVlvActInDrv = 0;
   }

   VlvAct_bDgoHiVlvActInDrv = bLocalDft_scp_driver_vvt_adm;
}
/*------------------------------- end of file --------------------------------*/