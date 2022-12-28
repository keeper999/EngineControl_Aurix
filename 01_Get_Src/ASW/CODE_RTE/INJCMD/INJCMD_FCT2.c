/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCMD                                                  */
/* !Description     : INJCMD Component                                        */
/*                                                                            */
/* !Module          : INJCMD                                                  */
/* !Description     : INTERFACE COMMANDE INJECTEURS ESSENCE                   */
/*                                                                            */
/* !File            : INJCMD_FCT2.C                                           */
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
/*   1 / INJCMD_vidInjectorsDiagnostic                                        */
/*   2 / INJCMD_vidDiagnosticInjecteur1                                       */
/*   3 / INJCMD_vidDiagnosticInjecteur2                                       */
/*   4 / INJCMD_vidDiagnosticInjecteur3                                       */
/*   5 / INJCMD_vidDiagnosticInjecteur4                                       */
/*   6 / INJCMD_vidManCutByCylinder                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6886136 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJCMD/INJCMD_FCT2.C_v    $*/
/* $Revision::   1.13     $$Author::   mbenfrad       $$Date::   17 Sep 2014 $*/
/* $Author::   mbenfrad                               $$Date::   17 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "INJCMD.h"
#include "INJCMD_L.h"
#include "INJCMD_IM.h"
#include "VEMS.h"
#include "INJCMD_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidInjectorsDiagnostic                              */
/* !Description :  Le diagnostic fournit une information de panne présente,   */
/*                 utilisée par la gestion des défauts unitaire pour générer  */
/*                 les éventuelles  demande de reconfiguration et définir les */
/*                 modes dégradés associés.                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCMD_vidDiagnosticInjecteur1();                        */
/*  extf argret void INJCMD_vidDiagnosticInjecteur3();                        */
/*  extf argret void INJCMD_vidDiagnosticInjecteur2();                        */
/*  extf argret void INJCMD_vidDiagnosticInjecteur4();                        */
/*  input uint8 Ext_noCylEng;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidInjectorsDiagnostic(void)
{
   uint8   u8LocalExt_noCylEng;

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);

   INJCMD_vidDiagnosticInjecteur1();
   INJCMD_vidDiagnosticInjecteur3();
   INJCMD_vidDiagnosticInjecteur2();

   if (u8LocalExt_noCylEng == 4)
   {
      INJCMD_vidDiagnosticInjecteur4();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidDiagnosticInjecteur1                             */
/* !Description :  Diagnostique du premier injecteur                          */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DGOHAL_bfRead(argin uint8 u8Channel)DGOHAL_tbfStatus;    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_scw_Inj1Cmd;                                          */
/*  output boolean Dft_scw_Inj1Cmd;                                           */
/*  output boolean Dena_oc_Inj1Cmd;                                           */
/*  output boolean Dft_oc_Inj1Cmd;                                            */
/*  output boolean Dena_scg_Inj1Cmd;                                          */
/*  output boolean Dft_scg_Inj1Cmd;                                           */
/*  output boolean Dena_ovld_Inj1Cmd;                                         */
/*  output boolean Dft_ovld_Inj1Cmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidDiagnosticInjecteur1(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtINJ_1);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_Inj1Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_Inj1Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_Inj1Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_Inj1Cmd, 0);
      VEMS_vidSET(Dft_scw_Inj1Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_Inj1Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_Inj1Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_Inj1Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_Inj1Cmd, 0);
      VEMS_vidSET(Dft_oc_Inj1Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_Inj1Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_Inj1Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_Inj1Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_Inj1Cmd, 0);
      VEMS_vidSET(Dft_scg_Inj1Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OVERLOAD) != 0)
   {
      VEMS_vidSET(Dena_ovld_Inj1Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OVERLOAD) != 0)
      {
         VEMS_vidSET(Dft_ovld_Inj1Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_ovld_Inj1Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_ovld_Inj1Cmd, 0);
      VEMS_vidSET(Dft_ovld_Inj1Cmd, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidDiagnosticInjecteur2                             */
/* !Description :  Diagnostique du deuxième injecteur                         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DGOHAL_bfRead(argin uint8 u8Channel)DGOHAL_tbfStatus;    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_scw_Inj2Cmd;                                          */
/*  output boolean Dft_scw_Inj2Cmd;                                           */
/*  output boolean Dena_oc_Inj2Cmd;                                           */
/*  output boolean Dft_oc_Inj2Cmd;                                            */
/*  output boolean Dena_scg_Inj2Cmd;                                          */
/*  output boolean Dft_scg_Inj2Cmd;                                           */
/*  output boolean Dena_ovld_Inj2Cmd;                                         */
/*  output boolean Dft_ovld_Inj2Cmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidDiagnosticInjecteur2(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtINJ_2);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_Inj2Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_Inj2Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_Inj2Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_Inj2Cmd, 0);
      VEMS_vidSET(Dft_scw_Inj2Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_Inj2Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_Inj2Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_Inj2Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_Inj2Cmd, 0);
      VEMS_vidSET(Dft_oc_Inj2Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_Inj2Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_Inj2Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_Inj2Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_Inj2Cmd, 0);
      VEMS_vidSET(Dft_scg_Inj2Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OVERLOAD) != 0)
   {
      VEMS_vidSET(Dena_ovld_Inj2Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OVERLOAD) != 0)
      {
         VEMS_vidSET(Dft_ovld_Inj2Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_ovld_Inj2Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_ovld_Inj2Cmd, 0);
      VEMS_vidSET(Dft_ovld_Inj2Cmd, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidDiagnosticInjecteur3                             */
/* !Description :  Diagnostique du troisième injecteur                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DGOHAL_bfRead(argin uint8 u8Channel)DGOHAL_tbfStatus;    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_scw_Inj3Cmd;                                          */
/*  output boolean Dft_scw_Inj3Cmd;                                           */
/*  output boolean Dena_oc_Inj3Cmd;                                           */
/*  output boolean Dft_oc_Inj3Cmd;                                            */
/*  output boolean Dena_scg_Inj3Cmd;                                          */
/*  output boolean Dft_scg_Inj3Cmd;                                           */
/*  output boolean Dena_ovld_Inj3Cmd;                                         */
/*  output boolean Dft_ovld_Inj3Cmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidDiagnosticInjecteur3(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtINJ_3);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_Inj3Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_Inj3Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_Inj3Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_Inj3Cmd, 0);
      VEMS_vidSET(Dft_scw_Inj3Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_Inj3Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_Inj3Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_Inj3Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_Inj3Cmd, 0);
      VEMS_vidSET(Dft_oc_Inj3Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_Inj3Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_Inj3Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_Inj3Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_Inj3Cmd, 0);
      VEMS_vidSET(Dft_scg_Inj3Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OVERLOAD) != 0)
   {
      VEMS_vidSET(Dena_ovld_Inj3Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OVERLOAD) != 0)
      {
         VEMS_vidSET(Dft_ovld_Inj3Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_ovld_Inj3Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_ovld_Inj3Cmd, 0);
      VEMS_vidSET(Dft_ovld_Inj3Cmd, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidDiagnosticInjecteur4                             */
/* !Description :  Diagnostique du quatrième injecteur                        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DGOHAL_bfRead(argin uint8 u8Channel)DGOHAL_tbfStatus;    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_scw_Inj4Cmd;                                          */
/*  output boolean Dft_scw_Inj4Cmd;                                           */
/*  output boolean Dena_oc_Inj4Cmd;                                           */
/*  output boolean Dft_oc_Inj4Cmd;                                            */
/*  output boolean Dena_scg_Inj4Cmd;                                          */
/*  output boolean Dft_scg_Inj4Cmd;                                           */
/*  output boolean Dena_ovld_Inj4Cmd;                                         */
/*  output boolean Dft_ovld_Inj4Cmd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidDiagnosticInjecteur4(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtINJ_4);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_Inj4Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_Inj4Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_Inj4Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_Inj4Cmd, 0);
      VEMS_vidSET(Dft_scw_Inj4Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_Inj4Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_Inj4Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_Inj4Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_Inj4Cmd, 0);
      VEMS_vidSET(Dft_oc_Inj4Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_Inj4Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_Inj4Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_Inj4Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_Inj4Cmd, 0);
      VEMS_vidSET(Dft_scg_Inj4Cmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OVERLOAD) != 0)
   {
      VEMS_vidSET(Dena_ovld_Inj4Cmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OVERLOAD) != 0)
      {
         VEMS_vidSET(Dft_ovld_Inj4Cmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_ovld_Inj4Cmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_ovld_Inj4Cmd, 0);
      VEMS_vidSET(Dft_ovld_Inj4Cmd, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCMD_vidManCutByCylinder                                 */
/* !Description :  Deux entrées contrôlent la coupure (totale ou partielle) de*/
/*                 l'injection: Auto_injection = 0 (lâché de pied ou véhicule */
/*                 arrêté) : coupure totale (sur les 3 cylindres),            */
/*                 Coupure_decel_progr_inj ? 0 : coupure de l’injecteur       */
/*                 concerné                                                   */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJHAL_vidInhibit(uint8 u8InstanceId,                    */
/* INJHAL_tbfInhibitMask bfInhibitMask);                                      */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 IMMO_stEcuLockStTyp;                                         */
/*  input boolean Coupure_inj_ess_1;                                          */
/*  input boolean Coupure_inj_ess_2;                                          */
/*  input boolean Coupure_inj_ess_3;                                          */
/*  input boolean Coupure_inj_ess_4;                                          */
/*  input boolean SftyMgt_bDgoIrvEngStop;                                     */
/*  input boolean Manu_coupure_inj_1;                                         */
/*  input boolean Manu_coupure_inj_2;                                         */
/*  input boolean Manu_coupure_inj_3;                                         */
/*  input boolean Manu_coupure_inj_4;                                         */
/*  input uint8 Coupure_inj_ess_appl;                                         */
/*  output boolean Inj_bInhInjr1;                                             */
/*  output boolean Inj_bInhInjr2;                                             */
/*  output boolean Inj_bInhInjr3;                                             */
/*  output boolean Inj_bInhInjr4;                                             */
/*  output uint8 Coupure_inj_ess_appl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCMD_vidManCutByCylinder(void)
{
   boolean bLocalCoupure_inj_ess_1;
   boolean bLocalCoupure_inj_ess_2;
   boolean bLocalCoupure_inj_ess_3;
   boolean bLocalCoupure_inj_ess_4;
   boolean bLocalSftyMgt_bDgoIrvEngStop;
   boolean bLocalLockStTypCdnEngStopReq;
   uint8   u8LocalDisableMask;
   uint8   u8LocalExt_noCylEng;
   uint16  u16LocalIMMO_stEcuLockStTyp;

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   VEMS_vidGET(IMMO_stEcuLockStTyp, u16LocalIMMO_stEcuLockStTyp);
   VEMS_vidGET(Coupure_inj_ess_1, bLocalCoupure_inj_ess_1);
   VEMS_vidGET(Coupure_inj_ess_2, bLocalCoupure_inj_ess_2);
   VEMS_vidGET(Coupure_inj_ess_3, bLocalCoupure_inj_ess_3);
   VEMS_vidGET(Coupure_inj_ess_4, bLocalCoupure_inj_ess_4);
   VEMS_vidGET(SftyMgt_bDgoIrvEngStop, bLocalSftyMgt_bDgoIrvEngStop);

   u8LocalDisableMask = 0x00;
   /*value INJ_HAL_CYLINDER_2_MASK and INJ_HAL_CYLINDER_3_MASK are imposed
   by VEMS V02 ECU#058776*/

   if (  (u16LocalIMMO_stEcuLockStTyp == IMMO_ECU_LOCKED)
      ||(bLocalSftyMgt_bDgoIrvEngStop != 0))
   {
      bLocalLockStTypCdnEngStopReq = 1;
   }
   else
   {
      bLocalLockStTypCdnEngStopReq = 0;
   }

   if (  (bLocalLockStTypCdnEngStopReq != 0)
      ||(Manu_coupure_inj_1 != 0)
      ||(bLocalCoupure_inj_ess_1 != 0))
   {
      VEMS_vidSET(Inj_bInhInjr1, 1);
      u8LocalDisableMask |= INJ_HAL_CYLINDER_1_MASK;
   }
   else
   {
      VEMS_vidSET(Inj_bInhInjr1, 0);
   }

   if (  (bLocalLockStTypCdnEngStopReq != 0)
      ||(Manu_coupure_inj_2 != 0)
      ||(bLocalCoupure_inj_ess_2 != 0))
   {
      VEMS_vidSET(Inj_bInhInjr2, 1);
      if (u8LocalExt_noCylEng == 4)
      {
         u8LocalDisableMask |= INJ_HAL_CYLINDER_4_MASK;
      }
      else
      {
         u8LocalDisableMask |= INJ_HAL_CYLINDER_2_MASK;
      }
   }
   else
   {
      VEMS_vidSET(Inj_bInhInjr2, 0);
   }

   if (  (bLocalLockStTypCdnEngStopReq != 0)
      || (Manu_coupure_inj_3 != 0)
      || (bLocalCoupure_inj_ess_3 != 0))
   {
      VEMS_vidSET(Inj_bInhInjr3, 1);
      u8LocalDisableMask |= INJ_HAL_CYLINDER_3_MASK;
   }
   else
   {
      VEMS_vidSET(Inj_bInhInjr3, 0);
   }

   if (  (  (bLocalLockStTypCdnEngStopReq != 0)
         || (Manu_coupure_inj_4 != 0)
         || (bLocalCoupure_inj_ess_4 != 0))
      || (u8LocalExt_noCylEng != 4))
   {
      VEMS_vidSET(Inj_bInhInjr4, 1);
      if (u8LocalExt_noCylEng == 4)
      {
         u8LocalDisableMask |= INJ_HAL_CYLINDER_2_MASK;
      }
      else
      {
         u8LocalDisableMask |= INJ_HAL_CYLINDER_4_MASK;
      }
   }
   else
   {
      VEMS_vidSET(Inj_bInhInjr4, 0);
   }
   Coupure_inj_ess_appl = u8LocalDisableMask;
   INJHAL_vidInhibit(INS_INJ_GDI, Coupure_inj_ess_appl);
}

/*------------------------------- end of file --------------------------------*/
