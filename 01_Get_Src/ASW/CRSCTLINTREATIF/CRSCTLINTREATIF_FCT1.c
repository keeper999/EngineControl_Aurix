/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CRSCTLINTREATIF                                         */
/* !Description     : CRSCTLINTREATIF component.                              */
/*                                                                            */
/* !Module          : CRSCTLINTREATIF                                         */
/* !Description     : SPECIFICATION D’INTERFACE POUR LES BESOINS DE LA XVV    */
/*                                                                            */
/* !File            : CRSCTLINTREATIF_FCT1.C                                  */
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
/*   1 / CRSCTLINTREATIF_vidInit                                              */
/*   2 / CRSCTLINTREATIF_vidInitOutput                                        */
/*   3 / CRSCTLINTREATIF_vidCrsCtl_Can                                        */
/*   4 / CRSCTLINTREATIF_vid50DTreatIf                                        */
/*   5 / CRSCTLINTREATIF_vid3ADTreatIf                                        */
/*   6 / CRSCTLINTREATIF_vid44DTreatIf                                        */
/*   7 / CRSCTLINTREATIF_vidOutClunGearEg                                     */
/*   8 / CRSCTLINTREATIF_vidAuth_clc                                          */
/*   9 / CRSCTLINTREATIF_vidCrsctl                                            */
/*                                                                            */
/* !Reference   : V02 NT 11 06065 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CRSCTL/CRSCTLINTREATIF/CRSCTLINT$*/
/* $Revision::   1.7      $$Author::   etsasson       $$Date::   03 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   03 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CRSCTLINTREATIF.h"
#include "CRSCTLINTREATIF_L.h"
#include "CRSCTLINTREATIF_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vidInit                                    */
/* !Description :  Fonction qui permet l'initialisation des sorties.          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean ECU_bAuthVSCtlIni;                                         */
/*  output boolean Brk_bBrkDyn;                                               */
/*  output uint8 Ext_spdVehVSMaxPrmaReq;                                      */
/*  output uint8 Ext_noGearEgd;                                               */
/*  output boolean Ext_bClu;                                                  */
/*  output uint8 Ext_stDirMoveVehReq;                                         */
/*  output boolean Ext_bABSReg;                                               */
/*  output uint16 Ext_nAvrFrntWhl;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vidInit(void)
{
   VEMS_vidSET(ECU_bAuthVSCtlIni, 0);
   VEMS_vidSET(Brk_bBrkDyn, 0);
   VEMS_vidSET(Ext_spdVehVSMaxPrmaReq, 255);
   VEMS_vidSET(Ext_noGearEgd, 0);
   VEMS_vidSET(Ext_bClu, 0);
   VEMS_vidSET(Ext_stDirMoveVehReq, 1);
   VEMS_vidSET(Ext_bABSReg, 0);
   VEMS_vidSET(Ext_nAvrFrntWhl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vidInitOutput                              */
/* !Description :  Fonction qui permet l'initalisation des variables.         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 CRSCTLINTREATIF_u16Timer;                                   */
/*  output boolean CRSCTLINTREATIF_bTimeOut;                                  */
/*  output boolean CRSCTLINTREATIF_Diag_onPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vidInitOutput(void)
{
   CRSCTLINTREATIF_u16Timer = 0;
   CRSCTLINTREATIF_bTimeOut = 0;
   CRSCTLINTREATIF_Diag_onPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vidCrsCtl_Can                              */
/* !Description :  Fonction qui permet l’initialisation  du flag              */
/*                 ECU_bAuthVSCtlIni .                                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLINTREATIF_vid50DTreatIf();                         */
/*  extf argret void CRSCTLINTREATIF_vid44DTreatIf();                         */
/*  extf argret void CRSCTLINTREATIF_vid3ADTreatIf();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vidCrsCtl_Can(void)
{
   CRSCTLINTREATIF_vid50DTreatIf();
   CRSCTLINTREATIF_vid44DTreatIf();
   CRSCTLINTREATIF_vid3ADTreatIf();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vid50DTreatIf                              */
/* !Description :  Cette fonction génère la variable Régulation ABS par       */
/*                 recopie du paramètre P351 provenant du CAN.                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bABSReg50D;                                             */
/*  output boolean Ext_bABSReg;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vid50DTreatIf(void)
{
   boolean bLocalExt_bABSReg50D;


   VEMS_vidGET(Ext_bABSReg50D, bLocalExt_bABSReg50D);
   VEMS_vidSET(Ext_bABSReg, bLocalExt_bABSReg50D);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vid3ADTreatIf                              */
/* !Description :  Fonction qui permet le calcul de Freinage dynamique en     */
/*                 cours (0 = Pas en cours / Faux 1 = En cours / Vrai)        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_06065_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bBrkDynCf;                                              */
/*  input boolean Cha_bInhVSCtl;                                              */
/*  output boolean Brk_bBrkDyn;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vid3ADTreatIf(void)
{
   boolean bLocalExt_bBrkDynCf;
   boolean bLocalCha_bInhVSCtl;


   VEMS_vidGET(Ext_bBrkDynCf, bLocalExt_bBrkDynCf);
   VEMS_vidGET(Cha_bInhVSCtl, bLocalCha_bInhVSCtl);

   if (  (bLocalExt_bBrkDynCf != 0)
      && (bLocalCha_bInhVSCtl != 0))
   {
      VEMS_vidSET(Brk_bBrkDyn, 1);
   }
   else
   {
      VEMS_vidSET(Brk_bBrkDyn, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vid44DTreatIf                              */
/* !Description :  Cette fonction génère la variable Régime moyen roues avant */
/*                 par recopie du paramètre P354 provenant du CAN.            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  maissa.abcha                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Ext_nAvrFrntWhlCAN;                                          */
/*  output uint16 Ext_nAvrFrntWhl;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vid44DTreatIf(void)
{
   uint16 u16LocalExt_nAvrFrntWhl;
   uint32 u32LocalExtAvrFrntWhlCAN;


   VEMS_vidGET(Ext_nAvrFrntWhlCAN, u32LocalExtAvrFrntWhlCAN);

   if (u32LocalExtAvrFrntWhlCAN < 83872)
   {
      u16LocalExt_nAvrFrntWhl = (uint16)((u32LocalExtAvrFrntWhlCAN * 25) / 32);
   }
   else
   {
      u16LocalExt_nAvrFrntWhl = 65525;
   }
   VEMS_vidSET(Ext_nAvrFrntWhl, u16LocalExt_nAvrFrntWhl);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vidOutClunGearEg                           */
/* !Description :  cette fonction génére la detection débrayage et le rapport */
/*                 engagé.                                                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_06065_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input sint8 Tra_noEgdGear;                                                */
/*  input sint8 CoPt_noEgdGearCordIt;                                         */
/*  input uint8 Tra_stDragRed;                                                */
/*  input uint8 Tra_stClu;                                                    */
/*  output uint8 Ext_noGearEgd;                                               */
/*  output boolean Ext_bClu;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vidOutClunGearEg(void)
{
   boolean bLocalExt_bClu;
   uint8   u8LocalExt_noGearEgd;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalTra_stClu;
   uint8   u8LocalTra_stDragRed;
   sint8   s8LocalTra_noEgdGear;
   sint8   s8LocalCoPt_noEgdGearCordIt;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (  (u8LocalExt_stGBxCf == 1)
      || (u8LocalExt_stGBxCf == 2))
   {
      VEMS_vidGET(Tra_noEgdGear, s8LocalTra_noEgdGear);
      if (s8LocalTra_noEgdGear == -1)
      {
         u8LocalExt_noGearEgd = 7;
      }
      else
      {
         if (  (s8LocalTra_noEgdGear >= 0)
            && (s8LocalTra_noEgdGear <= 6))
         {
            u8LocalExt_noGearEgd = (uint8)(s8LocalTra_noEgdGear);
         }
         else
         {
            u8LocalExt_noGearEgd = 8;
         }
      }
   }
   else
   {
      VEMS_vidGET(CoPt_noEgdGearCordIt, s8LocalCoPt_noEgdGearCordIt);
      if (s8LocalCoPt_noEgdGearCordIt == -1)
      {
         u8LocalExt_noGearEgd = 7;
      }
      else
      {
         if (  (s8LocalCoPt_noEgdGearCordIt >= 0)
            && (s8LocalCoPt_noEgdGearCordIt <= 6))
         {
            u8LocalExt_noGearEgd = (uint8)(s8LocalCoPt_noEgdGearCordIt);
         }
         else
         {
            u8LocalExt_noGearEgd = 8;
         }
      }
   }
   VEMS_vidSET(Ext_noGearEgd, u8LocalExt_noGearEgd);

   if (u8LocalExt_stGBxCf == 1)
   {
      VEMS_vidGET(Tra_stDragRed, u8LocalTra_stDragRed);
      if (u8LocalTra_stDragRed != 2)
      {
         bLocalExt_bClu = 0;
      }
      else
      {
         bLocalExt_bClu = 1;
      }
   }
   else
   {
      if (u8LocalExt_stGBxCf == 2)
      {
         VEMS_vidGET(Tra_stClu, u8LocalTra_stClu);
         if (u8LocalTra_stClu != 2)
         {
            bLocalExt_bClu = 0;
         }
         else
         {
            bLocalExt_bClu = 1;
         }
      }
      else
      {
         bLocalExt_bClu = 0;
      }
   }
   VEMS_vidSET(Ext_bClu, bLocalExt_bClu);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vidAuth_clc                                */
/* !Description :  Cette fonction permet de calculer le flag d’initialisation */
/*                 «ECU_bAuthVSCtlIni ».                                      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_06065_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Diag_on;                                                    */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean CRSCTLINTREATIF_Diag_onPrev;                                */
/*  input uint16 CrsCtl_tempo_init_diag_xVV_C;                                */
/*  input uint16 CRSCTLINTREATIF_u16Timer;                                    */
/*  input boolean CRSCTLINTREATIF_bTimeOut;                                   */
/*  input boolean ECU_bAuthVSCtlIni;                                          */
/*  output uint16 CRSCTLINTREATIF_u16Timer;                                   */
/*  output boolean CRSCTLINTREATIF_bTimeOut;                                  */
/*  output boolean ECU_bAuthVSCtlIni;                                         */
/*  output boolean CRSCTLINTREATIF_Diag_onPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vidAuth_clc(void)
{
   boolean bLocalDiag_on;
   boolean bLocalECU_bWkuMain;
   boolean bLocalClef_de_contact;
   boolean bLocalECU_bAuthVSCtlIni;

   VEMS_vidGET(Diag_on, bLocalDiag_on);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   /* timer */
   if (  (bLocalDiag_on != 0)
      && (CRSCTLINTREATIF_Diag_onPrev == 0))
   {
      CRSCTLINTREATIF_u16Timer = CrsCtl_tempo_init_diag_xVV_C;

      if (CRSCTLINTREATIF_u16Timer == 0)
      {
         CRSCTLINTREATIF_bTimeOut = 1;
      }
      else
      {
         CRSCTLINTREATIF_bTimeOut = 0;
      }
   }
   else
   {
      if (CRSCTLINTREATIF_u16Timer > 0)
      {
         CRSCTLINTREATIF_u16Timer = (uint16)(CRSCTLINTREATIF_u16Timer - 1);
         if (CRSCTLINTREATIF_u16Timer == 0)
         {
            CRSCTLINTREATIF_bTimeOut = 1;
         }
         else
         {
            CRSCTLINTREATIF_bTimeOut = 0;
         }
      }
   }
   if (  (bLocalDiag_on == 0)
      || (bLocalECU_bWkuMain == 0)
      || (bLocalClef_de_contact == 0))
   {
      bLocalECU_bAuthVSCtlIni = 0;
   }
   else
   {
      if (CRSCTLINTREATIF_bTimeOut != 0)
      {
         bLocalECU_bAuthVSCtlIni = 1;
      }
      else
      {
         VEMS_vidGET(ECU_bAuthVSCtlIni, bLocalECU_bAuthVSCtlIni);
      }
   }
   VEMS_vidSET(ECU_bAuthVSCtlIni, bLocalECU_bAuthVSCtlIni);
   CRSCTLINTREATIF_Diag_onPrev = bLocalDiag_on;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLINTREATIF_vidCrsctl                                  */
/* !Description :  Cette fonction génère la consigne de vitesse BVV           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  maissa.abcha                                               */
/* !Trace_To    :  VEMS_E_11_06065_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_spdVehVSMaxPrmaReq1;                                      */
/*  input uint8 Ext_spdVehVSMaxPrmaReq2;                                      */
/*  input uint8 DrvIf_stLevAuth;                                              */
/*  input uint8 Ext_SpdVehBVVMin_C;                                           */
/*  input uint8 Ext_SpdVehBVVMax_C;                                           */
/*  output uint8 Ext_spdVehVSMaxPrmaReq;                                      */
/*  output uint8 Ext_stDirMoveVehReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLINTREATIF_vidCrsctl(void)
{
   uint8 u8LocalExtVehVSMaxPrmaReq1;
   uint8 u8LocalExtVehVSMaxPrmaReq2;
   uint8 u8LocalDrvIf_stLevAuth;
   uint8 u8LocalExtDirMoveVehReq;
   uint8 u8LocalExtVehVSMaxPrmaReq;


   VEMS_vidGET(Ext_spdVehVSMaxPrmaReq1, u8LocalExtVehVSMaxPrmaReq1);
   VEMS_vidGET(Ext_spdVehVSMaxPrmaReq2, u8LocalExtVehVSMaxPrmaReq2);
   VEMS_vidGET(DrvIf_stLevAuth, u8LocalDrvIf_stLevAuth);

   if (  (u8LocalExtVehVSMaxPrmaReq1 == u8LocalExtVehVSMaxPrmaReq2)
      && (  (  (u8LocalExtVehVSMaxPrmaReq1 > Ext_SpdVehBVVMin_C)
            && (u8LocalExtVehVSMaxPrmaReq1 < Ext_SpdVehBVVMax_C))
         || (u8LocalExtVehVSMaxPrmaReq1 == 255)))
   {
      u8LocalExtVehVSMaxPrmaReq = u8LocalExtVehVSMaxPrmaReq1;
   }
   else
   {
      u8LocalExtVehVSMaxPrmaReq = 255;
   }
   VEMS_vidSET(Ext_spdVehVSMaxPrmaReq, u8LocalExtVehVSMaxPrmaReq);

   if (  (u8LocalDrvIf_stLevAuth == 4)
      || (u8LocalDrvIf_stLevAuth == 3))
   {
      u8LocalExtDirMoveVehReq = 1;
   }
   else
   {
      if (u8LocalDrvIf_stLevAuth == 1)
      {
         u8LocalExtDirMoveVehReq = 2;
      }
      else
      {
         u8LocalExtDirMoveVehReq = 0;
      }
   }
   VEMS_vidSET(Ext_stDirMoveVehReq, u8LocalExtDirMoveVehReq);
}
/*------------------------------- end of file --------------------------------*/