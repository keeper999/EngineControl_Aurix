/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXCMD                                             */
/* !Description     : VLVACTEXCMD component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXCMD                                             */
/* !Description     : DRIVER DE LA COMMANDE VVT ECHAPPEMENT                   */
/*                                                                            */
/* !File            : VLVACTEXCMD_FCT1.C                                      */
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
/*   1 / VLVACTEXCMD_vidInitOutput                                            */
/*   2 / VLVACTEXCMD_vidInitialization                                        */
/*   3 / VLVACTEXCMD_vidEnablePwm                                             */
/*   4 / VLVACTEXCMD_vidBatteryComp                                           */
/*   5 / VLVACTEXCMD_vidPwmCommand                                            */
/*   6 / VLVACTEXCMD_vidDiagnostic                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6588622 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTEX/VLVACTEXCMD/VLVACT$*/
/* $Revision::   1.12     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXCMD.h"
#include "VLVACTEXCMD_L.h"
#include "VLVACTEXCMD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCMD_vidInitOutput                                  */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Commande_vvt_ech_pwm_rco;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCMD_vidInitOutput(void)
{
   VEMS_vidSET(Commande_vvt_ech_pwm_rco, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCMD_vidInitialization                              */
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
/*  output uint16 Rco_applique_vvt_echap;                                     */
/*  output boolean Autorisation_pwm_echap;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCMD_vidInitialization(void)
{
   VEMS_vidSET(Rco_applique_vvt_echap, 0);
   Autorisation_pwm_echap = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCMD_vidEnablePwm                                   */
/* !Description :  Lors de la demande de fonctionnement de la VVT echappement */
/*                 (Demande_vvt_adm_dormant = 0), on active le driver de la   */
/*                 VVT echappement (Autorisation_pwm_echap = 1) si la tension */
/*                 batterie se situe dans la plage de fonctionnement          */
/*                 prédéfinie.                                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 Seuil_mini_vbatt_activ_vvt_echap;                             */
/*  input uint8 Seuil_maxi_vbatt_activ_vvt_echap;                             */
/*  output boolean Autorisation_pwm_echap;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCMD_vidEnablePwm(void)
{
   uint16 u16LocalPMin;
   uint16 u16LocalPMax;
   sint16 s16LocalExtuBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExtuBattMes);
   u16LocalPMin = (uint16)(Seuil_mini_vbatt_activ_vvt_echap * 8);
   u16LocalPMax = (uint16)(Seuil_maxi_vbatt_activ_vvt_echap * 8);

   if (  (s16LocalExtuBattMes > u16LocalPMin)
      && (s16LocalExtuBattMes < u16LocalPMax))
   {
      Autorisation_pwm_echap = 1;
   }
   else
   {
      Autorisation_pwm_echap = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCMD_vidBatteryComp                                 */
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
/*  input uint16 VlvAct_ExMngStCmd;                                           */
/*  input uint8 Kevcpe_u_voltage_comp;                                        */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 Kfvcpe_u_reference_voltage;                                   */
/*  output uint16 VlvAct_ExCmpCmd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCMD_vidBatteryComp(void)
{
   uint16 u16LocalVlvAct_ExMngStCmd;
   sint16 s16LocalExtuBattMes;
   sint32 s32LocalEchapVolt;


   VEMS_vidGET(VlvAct_ExMngStCmd, u16LocalVlvAct_ExMngStCmd);
   if (Kevcpe_u_voltage_comp == BATT_LINEAR_EX)
   {
      VEMS_vidGET(Ext_uBattMes, s16LocalExtuBattMes);

      if (s16LocalExtuBattMes != 0)
      {
         s32LocalEchapVolt = (sint32)( ( u16LocalVlvAct_ExMngStCmd
                                       * Kfvcpe_u_reference_voltage
                                       * 8)
                                     / (s16LocalExtuBattMes));
         VlvAct_ExCmpCmd = (uint16)MATHSRV_udtCLAMP(s32LocalEchapVolt,
                                                    0,
                                                    1023);
      }
      else
      {
         VlvAct_ExCmpCmd = 1023;
      }
   }
   else
   {
      VlvAct_ExCmpCmd = (uint16)MATHSRV_udtMIN(u16LocalVlvAct_ExMngStCmd, 1023);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCMD_vidPwmCommand                                  */
/* !Description :  Lorsque le driver est activé, le module PWM correspondant à*/
/*                 la commande VVT echappement est réglé pour générer le      */
/*                 signal RCO désiré.                                         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05880_001.01                                     */
/*                 VEMS_R_08_05880_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16channel)boolean;                 */
/*  input uint16 VlvAct_ExCmpCmd;                                             */
/*  input boolean Demande_vvt_echap_dormant;                                  */
/*  input boolean Autorisation_pwm_echap;                                     */
/*  input uint8 Consigne_rco_vvt_echap_min;                                   */
/*  input uint8 Consigne_rco_vvt_echap_max;                                   */
/*  input boolean Sens_rco_vvt_echap;                                         */
/*  input boolean Clef_de_contact;                                            */
/*  output boolean Demande_vvt_echap_dormant;                                 */
/*  output uint16 Rco_applique_vvt_echap;                                     */
/*  output uint16 Commande_vvt_ech_pwm_rco;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCMD_vidPwmCommand(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalInhVlvActExCmd;
   uint16  u16LocalCmd;
   uint16  u16LocalVvtFreq;
   uint16  u16LocalConsigneMin;
   uint16  u16LocalConsigneMax;
   uint16  u16LocalRco_app_vvt_echap;


   if ( VlvAct_ExCmpCmd !=0 )
   {
      Demande_vvt_echap_dormant = 0;
   }
   else
   {
      Demande_vvt_echap_dormant = 1;
   }

   if (  (Demande_vvt_echap_dormant == 0)
      && (Autorisation_pwm_echap != 0)
      && (  (Consigne_rco_vvt_echap_min > 0)
         || (VlvAct_ExCmpCmd > 0)))
   {
      u16LocalConsigneMin = (uint16)(Consigne_rco_vvt_echap_min * 4);
      u16LocalConsigneMax = (uint16)(Consigne_rco_vvt_echap_max * 4);
      u16LocalCmd = (uint16)MATHSRV_udtCLAMP(VlvAct_ExCmpCmd,
                                             u16LocalConsigneMin,
                                             u16LocalConsigneMax);
   }
   else
   {
      u16LocalCmd = 0;
   }

   if (Sens_rco_vvt_echap == 0)
   {
      u16LocalRco_app_vvt_echap = u16LocalCmd;
   }
   else
   {
      u16LocalCmd = (uint16)(1024 - u16LocalCmd);
      u16LocalRco_app_vvt_echap = (uint16)MATHSRV_udtMIN(u16LocalCmd, 1023);
   }
   VEMS_vidSET(Rco_applique_vvt_echap, u16LocalRco_app_vvt_echap);
   u16LocalVvtFreq =
      (uint16)(u16LocalRco_app_vvt_echap * VVT_EXHAUST_100_PERC_LDA_TO_LDB);

   VEMS_vidGET(Clef_de_contact,bLocalClef_de_contact);
   bLocalInhVlvActExCmd = GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXCMD);
   if (  (bLocalClef_de_contact != 0)
      && (bLocalInhVlvActExCmd == 0))
   {
      VEMS_vidSET(Commande_vvt_ech_pwm_rco, u16LocalVvtFreq);
   }
   else
   {
      VEMS_vidSET(Commande_vvt_ech_pwm_rco, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCMD_vidDiagnostic                                  */
/* !Description :  Fonction de diagnostique défaut du driver de la VVT        */
/*                 échappement.                                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05880_006.01                                     */
/*                 VEMS_R_08_05880_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16channel)boolean;                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_driver_vvt_ech;                                      */
/*  input boolean Dena_oc_driver_vvt_ech;                                     */
/*  input boolean Dft_scg_driver_vvt_ech;                                     */
/*  input boolean Dena_scg_driver_vvt_ech;                                    */
/*  input boolean Dena_scp_driver_vvt_ech;                                    */
/*  input boolean Dft_scp_driver_vvt_ech;                                     */
/*  input boolean EcuSt_bInhDiagOcCmdActr;                                    */
/*  output boolean VlvAct_bDgoLoVlvActExDrv;                                  */
/*  output boolean VlvActIn_bMonRunLoVlvActExDrv;                             */
/*  output boolean VlvActIn_bMonRunHiVlvActExDrv;                             */
/*  output boolean VlvAct_bDgoHiVlvActExDrv;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCMD_vidDiagnostic(void)
{
   boolean bLocalEcuSt_bInhDiagOcCmdActr;
   boolean bLocalInhVlvActExCmdDiagEl;
   boolean bLocalDft_oc_driver_vvt_ech;
   boolean bLocalDena_oc_driver_vvt_ech;
   boolean bLocalDft_scg_driver_vvt_ech;
   boolean bLocalDena_scg_driver_vvt_ech;
   boolean bLocalDena_scp_driver_vvt_ech;
   boolean bLocalDft_scp_driver_vvt_ech;


   bLocalInhVlvActExCmdDiagEl = GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXCMDDIAGEL);
   VEMS_vidGET(Dft_oc_driver_vvt_ech, bLocalDft_oc_driver_vvt_ech);
   VEMS_vidGET(Dena_oc_driver_vvt_ech, bLocalDena_oc_driver_vvt_ech);
   VEMS_vidGET(Dft_scg_driver_vvt_ech, bLocalDft_scg_driver_vvt_ech);
   VEMS_vidGET(Dena_scg_driver_vvt_ech, bLocalDena_scg_driver_vvt_ech);
   VEMS_vidGET(Dena_scp_driver_vvt_ech, bLocalDena_scp_driver_vvt_ech);
   VEMS_vidGET(Dft_scp_driver_vvt_ech, bLocalDft_scp_driver_vvt_ech);

   if (  (  (bLocalDft_oc_driver_vvt_ech != 0)
         && (bLocalDena_oc_driver_vvt_ech != 0))
      || (  (bLocalDft_scg_driver_vvt_ech != 0)
         && (bLocalDena_scg_driver_vvt_ech != 0)))
   {
      VlvAct_bDgoLoVlvActExDrv = 1;
   }
   else
   {
      VlvAct_bDgoLoVlvActExDrv = 0;
   }

   VEMS_vidGET(EcuSt_bInhDiagOcCmdActr, bLocalEcuSt_bInhDiagOcCmdActr);

   if (bLocalInhVlvActExCmdDiagEl == 0)
   {
      if (  (  (bLocalDena_oc_driver_vvt_ech != 0)
            || (bLocalDena_scg_driver_vvt_ech != 0))
         && (bLocalEcuSt_bInhDiagOcCmdActr == 0))
      {
         VlvActIn_bMonRunLoVlvActExDrv = 1;
      }
      else
      {
         VlvActIn_bMonRunLoVlvActExDrv = 0;
      }
      if (bLocalDena_scp_driver_vvt_ech != 0)
      {
         VlvActIn_bMonRunHiVlvActExDrv = 1;
      }
      else
      {
         VlvActIn_bMonRunHiVlvActExDrv = 0;
      }
   }
   else
   {
      VlvActIn_bMonRunLoVlvActExDrv = 0;
      VlvActIn_bMonRunHiVlvActExDrv = 0;
   }

   VlvAct_bDgoHiVlvActExDrv = bLocalDft_scp_driver_vvt_ech;
}
/*------------------------------- end of file --------------------------------*/