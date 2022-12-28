/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKCMCOHDIAG                                         */
/* !Description     : SYNCCKCMCOHDIAG component.                              */
/*                                                                            */
/* !Module          : SYNCCKCMCOHDIAG                                         */
/* !Description     : Cohérence de synchronisation des régimes Arbres à Cames */
/*                    et Vilebrequin                                          */
/*                                                                            */
/* !File            : SYNCCKCMCOHDIAG_FCT1.C                                  */
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
/*   1 / SYNCCKCMCOHDIAG_vidInitOutput                                        */
/*   2 / SYNCCKCMCOHDIAG_vidMonEngSpd                                         */
/*   3 / SYNCCKCMCOHDIAG_vidInCmExCm                                          */
/*   4 / SYNCCKCMCOHDIAG_vidExCm                                              */
/*   5 / SYNCCKCMCOHDIAG_vidInCm                                              */
/*   6 / SYNCCKCMCOHDIAG_vidCondMonitor                                       */
/*                                                                            */
/* !Reference   : V02 NT 09 04172 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKCMCOHDIAG/SYNCCKCMCOHDI$*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   26 May 2010 $*/
/* $Author::   hmelloul                               $$Date::   26 May 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SYNCCKCMCOHDIAG.h"
#include "SYNCCKCMCOHDIAG_L.h"
#include "SYNCCKCMCOHDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMCOHDIAG_vidInitOutput                              */
/* !Description :  Fonction d'initialisation des variables du module          */
/*                 SYNCCKCMCOHDIAG.                                           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B.KBOUBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean SYNCCKCMCOHDIAG_bEngineSyncPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMCOHDIAG_vidInitOutput(void)
{
   SYNCCKCMCOHDIAG_bEngineSyncPrev = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMCOHDIAG_vidMonEngSpd                               */
/* !Description :  Les tests de cohérence de régime ne sont autorisés que s'il*/
/*                 n'y a aucune demande de reconfiguration n’est présente et  */
/*                 que le moteur soit synchronisé avec un retard d’une        */
/*                 récurrence de calcul sur de la détection de la             */
/*                 synchronisation.                                           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B.KBOUBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCCKCMCOHDIAG_vidInCmExCm();                           */
/*  extf argret void SYNCCKCMCOHDIAG_vidExCm();                               */
/*  extf argret void SYNCCKCMCOHDIAG_vidInCm();                               */
/*  extf argret void SYNCCKCMCOHDIAG_vidCondMonitor();                        */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Ext_bPresExCmSen;                                           */
/*  input boolean Ext_bPresInCmSen;                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean SYNCCKCMCOHDIAG_bEngineSyncPrev;                            */
/*  input uint16 Sync_nEngInhMonEngSpd_C;                                     */
/*  output boolean Sync_bMonRunEngSpdCohCk;                                   */
/*  output boolean Sync_bMonRunEngSpdCohExCm;                                 */
/*  output boolean Sync_bMonRunEngSpdCohInCm;                                 */
/*  output boolean SYNCCKCMCOHDIAG_bEngineSyncPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMCOHDIAG_vidMonEngSpd(void)
{
   boolean bLocalInhMonEngSpd;
   boolean bLocalMoteur_synchronise;
   boolean bLocalExt_bPresExCmSen;
   boolean bLocalExt_bPresInCmSen;
   uint16  u16LocalRegime_moteur;

   bLocalInhMonEngSpd = GDGAR_bGetFRM(FRM_FRM_INHMONENGSPD);
   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(Ext_bPresExCmSen, bLocalExt_bPresExCmSen);
   VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);

   if (  (bLocalMoteur_synchronise != 0)
      && (SYNCCKCMCOHDIAG_bEngineSyncPrev != 0)
      && (bLocalInhMonEngSpd == 0)
      && (u16LocalRegime_moteur >= Sync_nEngInhMonEngSpd_C))
   {
   /* Comparing exhaust camshaft's signal to intake camshaft's signal */
      if (  (bLocalExt_bPresExCmSen != 0)
         && (bLocalExt_bPresInCmSen != 0))
      {
         Sync_bMonRunEngSpdCohCk = 1;
         SYNCCKCMCOHDIAG_vidInCmExCm();
      }
      else
      {
         Sync_bMonRunEngSpdCohCk = 0;
      }
   /* Comparing exhaust camshaft's signal to filtered vehicle speed's signal */
      if (bLocalExt_bPresExCmSen != 0)
      {
         Sync_bMonRunEngSpdCohExCm = 1;
         SYNCCKCMCOHDIAG_vidExCm();
      }
      else
      {
         Sync_bMonRunEngSpdCohExCm = 0;
      }
   /* Comparing intake camshaft's signal to filtered vehicle speed's signal */
      if (bLocalExt_bPresInCmSen != 0)
      {
         Sync_bMonRunEngSpdCohInCm = 1;
         SYNCCKCMCOHDIAG_vidInCm();
      }
      else
      {
         Sync_bMonRunEngSpdCohInCm = 0;
      }
   }
   else
   {
      Sync_bMonRunEngSpdCohCk = 0;
      Sync_bMonRunEngSpdCohExCm = 0;
      Sync_bMonRunEngSpdCohInCm = 0;
   }
   SYNCCKCMCOHDIAG_vidCondMonitor();
   SYNCCKCMCOHDIAG_bEngineSyncPrev = bLocalMoteur_synchronise;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMCOHDIAG_vidInCmExCm                                */
/* !Description :  Ce bloc évalue les écarts possibles entre les régimes AAC  */
/*                 admission et AAC échappement. Le calcul ne se fait que si  */
/*                 les capteurs AAC échappement et admission sont présents.   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B.KBOUBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_nEngExCmFil;                                          */
/*  input uint16 VlvAct_nEngInCmFil;                                          */
/*  input uint16 Sync_nEngDifMaxInCmExCm_C;                                   */
/*  output boolean Sync_bEngSpdDIfInCmExCm;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMCOHDIAG_vidInCmExCm(void)
{
   uint16 u16LocalCalcAbs;
   uint16 u16LocalVlvAct_nEngExCmFil;
   uint16 u16LocalVlvAct_nEngInCmFil;
   sint32 s32LocalCalcDiff;


   VEMS_vidGET(VlvAct_nEngExCmFil, u16LocalVlvAct_nEngExCmFil);
   VEMS_vidGET(VlvAct_nEngInCmFil, u16LocalVlvAct_nEngInCmFil);

   s32LocalCalcDiff = (sint32)( u16LocalVlvAct_nEngInCmFil
                              - u16LocalVlvAct_nEngExCmFil);
   u16LocalCalcAbs = (uint16)MATHSRV_udtABS(s32LocalCalcDiff);
   if (u16LocalCalcAbs > Sync_nEngDifMaxInCmExCm_C)
   {
      Sync_bEngSpdDIfInCmExCm = 1;
   }
   else
   {
      Sync_bEngSpdDIfInCmExCm = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMCOHDIAG_vidExCm                                    */
/* !Description :  Ce bloc évalue les écarts possibles entre les régimes AAC  */
/*                 échappement et vilebrequin. Ce calcul n’est autorisé que si*/
/*                 le capteur AAC échappement est présent.                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B.KBOUBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur_filtre;                                        */
/*  input uint16 VlvAct_nEngExCmFil;                                          */
/*  input uint16 Sync_nEngDifMaxExCmCk_C;                                     */
/*  output boolean Sync_bEngSpdDIfExCmCk;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMCOHDIAG_vidExCm(void)
{
   uint16 u16LocalCalcAbs;
   uint16 u16LocalRegime_moteur_filtre;
   uint16 u16LocalVlvAct_nEngExCmFil;
   sint32 s32LocalCalcDiff;


   VEMS_vidGET(Regime_moteur_filtre, u16LocalRegime_moteur_filtre);
   VEMS_vidGET(VlvAct_nEngExCmFil, u16LocalVlvAct_nEngExCmFil);

   s32LocalCalcDiff = (sint32)( u16LocalVlvAct_nEngExCmFil
                              - u16LocalRegime_moteur_filtre);
   u16LocalCalcAbs = (uint16)MATHSRV_udtABS(s32LocalCalcDiff);
   if (u16LocalCalcAbs > Sync_nEngDifMaxExCmCk_C)
   {
      Sync_bEngSpdDIfExCmCk = 1;
   }
   else
   {
      Sync_bEngSpdDIfExCmCk = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMCOHDIAG_vidInCm                                    */
/* !Description :  Ce bloc évalue les écarts possibles entre les régimes AAC  */
/*                 admission et vilebrequin. Ce calcul n’est autorisé que si  */
/*                 le capteur AAC admission est présent.                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B.KBOUBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur_filtre;                                        */
/*  input uint16 VlvAct_nEngInCmFil;                                          */
/*  input uint16 Sync_nEngDifMaxInCmCk_C;                                     */
/*  output boolean Sync_bEngSpdDIfInCmCk;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMCOHDIAG_vidInCm(void)
{
   uint16 u16LocalCalcAbs;
   uint16 u16LocalRegime_moteur_filtre;
   uint16 u16LocalVlvAct_nEngInCmFil;
   sint32 s32LocalCalcDiff;


   VEMS_vidGET(Regime_moteur_filtre, u16LocalRegime_moteur_filtre);
   VEMS_vidGET(VlvAct_nEngInCmFil, u16LocalVlvAct_nEngInCmFil);

   s32LocalCalcDiff = (sint32)( u16LocalVlvAct_nEngInCmFil
                              - u16LocalRegime_moteur_filtre);
   u16LocalCalcAbs = (uint16)MATHSRV_udtABS(s32LocalCalcDiff);
   if (u16LocalCalcAbs > Sync_nEngDifMaxInCmCk_C)
   {
      Sync_bEngSpdDIfInCmCk = 1;
   }
   else
   {
      Sync_bEngSpdDIfInCmCk = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCCKCMCOHDIAG_vidCondMonitor                             */
/* !Description :  Fonction qui décrit la logique de détection des défauts    */
/*                 régime vilebrequin, régime AAC échappement et régime AAC   */
/*                 admission.                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B.KBOUBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Sync_bEngSpdDIfExCmCk;                                      */
/*  input boolean Sync_bEngSpdDIfInCmCk;                                      */
/*  input boolean Sync_bEngSpdDIfInCmExCm;                                    */
/*  output boolean Sync_bDgoEngSpdCohCk;                                      */
/*  output boolean Sync_bDgoEngSpdCohInCm;                                    */
/*  output boolean Sync_bDgoEngSpdCohExCm;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCCKCMCOHDIAG_vidCondMonitor(void)
{
   if (  (Sync_bEngSpdDIfExCmCk != 0)
      && (Sync_bEngSpdDIfInCmCk != 0))
   {
      Sync_bDgoEngSpdCohCk = 1;
      if (Sync_bEngSpdDIfInCmExCm != 0)
      {
         Sync_bDgoEngSpdCohInCm = 1;
         Sync_bDgoEngSpdCohExCm = 1;
      }
      else
      {
         Sync_bDgoEngSpdCohInCm = 0;
         Sync_bDgoEngSpdCohExCm = 0;
      }
   }
   else
   {
      Sync_bDgoEngSpdCohCk = 0;
      if (Sync_bEngSpdDIfExCmCk == 0)
      {
         Sync_bDgoEngSpdCohExCm = 0;
         if (Sync_bEngSpdDIfInCmCk != 0)
         {
            Sync_bDgoEngSpdCohInCm = 1;
         }
         else
         {
            Sync_bDgoEngSpdCohInCm = 0;
         }
      }
      else
      {
         Sync_bDgoEngSpdCohExCm = 1;
         Sync_bDgoEngSpdCohInCm = 0;
      }
   }
}
/*-------------------------------- end of file -------------------------------*/