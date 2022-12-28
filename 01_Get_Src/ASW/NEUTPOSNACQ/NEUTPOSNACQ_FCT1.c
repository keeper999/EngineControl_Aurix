/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : NEUTPOSNACQ                                             */
/* !Description     : NEUTPOSNACQ component.                                  */
/*                                                                            */
/* !Module          : NEUTPOSNACQ                                             */
/* !Description     : ACQUISITION DE LA POSITION POINT MORT                   */
/*                                                                            */
/* !File            : NEUTPOSNACQ_FCT1.C                                      */
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
/*   1 / NEUTPOSNACQ_vidInitialization                                        */
/*   2 / NEUTPOSNACQ_vidInitOutput                                            */
/*   3 / NEUTPOSNACQ_vidOS                                                    */
/*   4 / NEUTPOSNACQ_vidNeutPosnAcq                                           */
/*   5 / NEUTPOSNACQ_vidNeutPosnDiag                                          */
/*   6 / NEUTPOSNACQ_vidbDgoScpCalcn                                          */
/*   7 / NEUTPOSNACQ_vidbDgoScgCalcn                                          */
/*   8 / NEUTPOSNACQ_vidbDgoORngCalcn                                         */
/*   9 / NEUTPOSNACQ_vidNeutPosnTreat                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6533527 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/NEUTPOSNACQ/NEUTPOSNACQ_FCT1.C_v  $*/
/* $Revision::   1.6      $$Author::   achebino       $$Date::   27 May 2014 $*/
/* $Author::   achebino                               $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "NEUTPOSNACQ.h"
#include "NEUTPOSNACQ_L.h"
#include "NEUTPOSNACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidInitialization                              */
/* !Description :  Ce bloc permet d’initialiser l’information « boîte de      */
/*                 vitesse au point mort » au réveil calculateur lorsque le   */
/*                 capteur n’est pas encore fonctionnel.                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bNeut;                                                 */
/*  output uint8 Ext_tiPerNeut;                                               */
/*  output uint16 Ext_rNeut;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidInitialization(void)
{

   VEMS_vidSET(Ext_bNeut, 0);
   VEMS_vidSET(Ext_tiPerNeut, 0);
   VEMS_vidSET(Ext_rNeut, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidInitOutput                                  */
/* !Description :  Ce bloc permet l'initialisation des sorties.               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean NeutPosnAcq_bDftSftyORng_bNeut;                            */
/*  output boolean NeutPosnAcq_bDftSftyScg_bNeut;                             */
/*  output boolean NeutPosnAcq_bDftSftyScp_bNeut;                             */
/*  output boolean Ext_bDgoScp_bNeut;                                         */
/*  output boolean Ext_bDgoScg_bNeut;                                         */
/*  output boolean Ext_bDgoORng_bNeut;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidInitOutput(void)
{
   VEMS_vidSET(NeutPosnAcq_bDftSftyORng_bNeut, 0);
   VEMS_vidSET(NeutPosnAcq_bDftSftyScg_bNeut, 0);
   VEMS_vidSET(NeutPosnAcq_bDftSftyScp_bNeut, 0);
   Ext_bDgoScp_bNeut = 0;
   Ext_bDgoScg_bNeut = 0;
   Ext_bDgoORng_bNeut = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidOS                                          */
/* !Description :  Le démultiplexage de  l’évènement Gear_SdlFast_NeutPosnAcq */
/*                 est autorisé si et seulement si  le véhicule est équipé    */
/*                 d’une boîte de vitesse manuelle et de la fonctionnalité    */
/*                 STOP & START.                                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_03229_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void NEUTPOSNACQ_vidNeutPosnAcq();                            */
/*  extf argret void NEUTPOSNACQ_vidNeutPosnDiag();                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  extf argret void NEUTPOSNACQ_vidNeutPosnTreat();                          */
/*  input boolean Gear_bAcvNeutPosnAcq;                                       */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Ext_bDgoScp_bNeut;                                          */
/*  input boolean Ext_bMonRunScp_bNeut;                                       */
/*  input boolean Ext_bDgoScg_bNeut;                                          */
/*  input boolean Ext_bMonRunScg_bNeut;                                       */
/*  input boolean Ext_bDgoORng_bNeut;                                         */
/*  input boolean Ext_bMonRunORng_bNeut;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidOS(void)
{
   boolean bLocalGear_bAcvNeutPosnAcq;
   boolean bLocalDIAG_bIntegElect;

   VEMS_vidGET(Gear_bAcvNeutPosnAcq, bLocalGear_bAcvNeutPosnAcq);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAG_bIntegElect);

   if (  (bLocalGear_bAcvNeutPosnAcq != 0)
      && (bLocalDIAG_bIntegElect  == 0) )
   {
      NEUTPOSNACQ_vidNeutPosnAcq();
      NEUTPOSNACQ_vidNeutPosnDiag();
      GDGAR_vidGdu(GD_DFT_SCP_BNEUT,
            Ext_bDgoScp_bNeut,
            Ext_bMonRunScp_bNeut,
            DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_BNEUT,
            Ext_bDgoScg_bNeut,
            Ext_bMonRunScg_bNeut,
            DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_BNEUT,
            Ext_bDgoORng_bNeut,
            Ext_bMonRunORng_bNeut,
            DIAG_DISPO);
      NEUTPOSNACQ_vidNeutPosnTreat();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidNeutPosnAcq                                 */
/* !Description :  Ce bloc met à la disposition du LDA le rapport cyclique du */
/*                 signal délivré par le capteur de position point mort. Le   */
/*                 calcul du rapport cyclique de ce signal est effectué par le*/
/*                 LDB.                                                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acquis_point_mort_rco;                                       */
/*  input uint16 Acquis_point_mort_periode;                                   */
/*  input uint16 Ext_PerNeut;                                                 */
/*  output uint16 Ext_PerNeut;                                                */
/*  output uint16 Ext_rNeut;                                                  */
/*  output uint8 Ext_tiPerNeut;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidNeutPosnAcq(void)
{
   uint8   u8LocalExt_tiPerNeut;
   uint16  u16LocalAcquisPointMortRco;
   uint16  u16LocalAcquisPointMortPeriode;


   VEMS_vidGET(Acquis_point_mort_rco, u16LocalAcquisPointMortRco);
   VEMS_vidGET(Acquis_point_mort_periode, u16LocalAcquisPointMortPeriode);

   u16LocalAcquisPointMortRco =
      (uint16)(((u16LocalAcquisPointMortRco * 625) + 1024) / 2048);
   u16LocalAcquisPointMortRco =
      (uint16)MATHSRV_udtMIN(u16LocalAcquisPointMortRco, 10000);

   Ext_PerNeut = u16LocalAcquisPointMortPeriode;
   u8LocalExt_tiPerNeut = (uint8)MATHSRV_udtMIN(Ext_PerNeut, 50);

   VEMS_vidSET(Ext_rNeut, u16LocalAcquisPointMortRco);
   VEMS_vidSET(Ext_tiPerNeut, u8LocalExt_tiPerNeut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidNeutPosnDiag                                */
/* !Description :  Ce bloc permet de vérifier si les conditions de chaque     */
/*                 diagnostic sont satisfaites et le cas échéant d’autoriser  */
/*                 la détection d’une éventuelle défaillance.                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void NEUTPOSNACQ_vidbDgoScgCalcn();                           */
/*  extf argret void NEUTPOSNACQ_vidbDgoScpCalcn();                           */
/*  extf argret void NEUTPOSNACQ_vidbDgoORngCalcn();                          */
/*  output boolean Ext_bMonRunScp_bNeut;                                      */
/*  output boolean Ext_bMonRunScg_bNeut;                                      */
/*  output boolean Ext_bMonRunORng_bNeut;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidNeutPosnDiag(void)
{
   boolean bLocalInhDiag_bNeut;


   bLocalInhDiag_bNeut = GDGAR_bGetFRM(FRM_FRM_INHDIAG_BNEUT);

   if (bLocalInhDiag_bNeut == 0)
   {
      Ext_bMonRunScp_bNeut  = 1;
      Ext_bMonRunScg_bNeut  = 1;
      Ext_bMonRunORng_bNeut = 1;

      NEUTPOSNACQ_vidbDgoScgCalcn();
      NEUTPOSNACQ_vidbDgoScpCalcn();
      NEUTPOSNACQ_vidbDgoORngCalcn();
   }
   else
   {
      Ext_bMonRunScp_bNeut  = 0;
      Ext_bMonRunScg_bNeut  = 0;
      Ext_bMonRunORng_bNeut = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidbDgoScpCalcn                                */
/* !Description :  Ce bloc permet de détecter un court circuit à la masse du  */
/*                 capteur de position point mort.                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rNeut;                                                   */
/*  input uint16 Ext_rDgoScp_bNeut_C;                                         */
/*  output boolean Ext_bDgoScp_bNeut;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidbDgoScpCalcn(void)
{
   uint16 u16LocalExt_rNeut;


   VEMS_vidGET(Ext_rNeut, u16LocalExt_rNeut);

   if (u16LocalExt_rNeut > Ext_rDgoScp_bNeut_C)
   {
      Ext_bDgoScp_bNeut = 1;
   }
   else
   {
      Ext_bDgoScp_bNeut = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidbDgoScgCalcn                                */
/* !Description :  Ce bloc permet de détecter un court-circuit au plus du     */
/*                 capteur de position point mort.                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rNeut;                                                   */
/*  input uint16 Ext_rDgoScg_bNeut_C;                                         */
/*  output boolean Ext_bDgoScg_bNeut;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidbDgoScgCalcn(void)
{
   uint16 u16LocalExt_rNeut;


   VEMS_vidGET(Ext_rNeut, u16LocalExt_rNeut);

   if (u16LocalExt_rNeut < Ext_rDgoScg_bNeut_C)
   {
      Ext_bDgoScg_bNeut = 1;
   }
   else
   {
      Ext_bDgoScg_bNeut = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidbDgoORngCalcn                               */
/* !Description :  Ce bloc permet de détecter une fréquence du signal capteur */
/*                 de position point mort hors gabarit.                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_PerNeut;                                                 */
/*  input uint16 Ext_frqMinNeut_C;                                            */
/*  input uint16 Ext_frqMaxNeut_C;                                            */
/*  output boolean Ext_bDgoORng_bNeut;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidbDgoORngCalcn(void)
{
   uint32  u32LocalExt_MaxNeut;
   uint32  u32LocalExt_MinNeut;


   if (Ext_PerNeut == 0)
   {
      if (Ext_frqMinNeut_C > 0)
      {
         Ext_bDgoORng_bNeut = 1;
      }
      else
      {
         Ext_bDgoORng_bNeut = 0;
      }
   }
   else
   {
      u32LocalExt_MaxNeut = (uint32)(Ext_frqMaxNeut_C * Ext_PerNeut);
      u32LocalExt_MinNeut = (uint32)(Ext_frqMinNeut_C * Ext_PerNeut);
      if (  (10000 > u32LocalExt_MaxNeut)
         || (10000 < u32LocalExt_MinNeut) )
      {
         Ext_bDgoORng_bNeut = 1;
      }
      else
      {
         Ext_bDgoORng_bNeut = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidNeutPosnTreat                               */
/* !Description :  Ce  bloc  décrit  la  consolidation  du  booléen  position */
/*                 point mort  en  fonction  des  résultats  des  diagnostics */
/*                 du capteur.                                                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_03229_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf argret void NEUTPOSNACQ_vidBneutNom();                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bNeutFault_C;                                           */
/*  input boolean Ext_bNeutNom;                                               */
/*  output boolean Ext_bNeut;                                                 */
/*  output boolean Ext_bNeutFault_C;                                          */
/*  output boolean Ext_bNeutNom;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidNeutPosnTreat(void)
{
   GDFRM_tenuGDUState LocalstDgoScp_bNeut;
   GDFRM_tenuGDUState LocalstDgoScg_bNeut;
   GDFRM_tenuGDUState LocalstDgoORng_bNeut;


   LocalstDgoScp_bNeut = GDGAR_tenuGetStDgo(GD_DFT_SCP_BNEUT);
   LocalstDgoScg_bNeut = GDGAR_tenuGetStDgo(GD_DFT_SCG_BNEUT);
   LocalstDgoORng_bNeut = GDGAR_tenuGetStDgo(GD_DFT_ORNG_BNEUT);

   NEUTPOSNACQ_vidBneutNom();

   if (  (LocalstDgoScp_bNeut == GDU_ETAT_PRESENT)
      || (LocalstDgoScp_bNeut == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoScg_bNeut == GDU_ETAT_PRESENT)
      || (LocalstDgoScg_bNeut == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoORng_bNeut == GDU_ETAT_PRESENT)
      || (LocalstDgoORng_bNeut == GDU_ETAT_DEVALIDATION))
   {
      VEMS_vidSET(Ext_bNeut, Ext_bNeutFault_C);
   }
   else
   {
      if (  (LocalstDgoScp_bNeut != GDU_ETAT_PCTL_PRESENT)
         && (LocalstDgoScp_bNeut != GDU_ETAT_PCTL_ABSENT)
         && (LocalstDgoScg_bNeut != GDU_ETAT_PCTL_PRESENT)
         && (LocalstDgoScg_bNeut != GDU_ETAT_PCTL_ABSENT)
         && (LocalstDgoORng_bNeut != GDU_ETAT_PCTL_PRESENT)
         && (LocalstDgoORng_bNeut != GDU_ETAT_PCTL_ABSENT))
      {
         VEMS_vidSET(Ext_bNeut, Ext_bNeutNom);
      }
   }
}

/*---------------------------- end of file -----------------------------------*/