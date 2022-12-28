/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MNGBRKPED                                               */
/* !Description     : MNGBRKPED component.                                    */
/*                                                                            */
/* !Module          : MNGBRKPED                                               */
/* !Description     : Gestion de l’information pédale de frein                */
/*                                                                            */
/* !File            : MNGBRKPED_FCT1.C                                        */
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
/*   1 / MNGBRKPED_vidInitOutput                                              */
/*   2 / MNGBRKPED_vidFCall                                                   */
/*   3 / MNGBRKPED_vidDiagBrkPrdFil                                           */
/*   4 / MNGBRKPED_vidDiagBVH2p                                               */
/*   5 / MNGBRKPED_vidDiagNoBVH2p                                             */
/*                                                                            */
/* !Reference   : V02 NT 11 03796 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHIBRK/MNGBRKPED/MNGBRKPED_FCT$*/
/* $Revision::   1.3      $$Author::   HHAMLAOU       $$Date::   06 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MNGBRKPED.h"
#include "MNGBRKPED_L.h"
#include "MNGBRKPED_IM.h"
#include "MNGBRKPED_I.H"
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MNGBRKPED_vidInitOutput                                    */
/* !Description :  fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_10_02673_003.01                                     */
/*                 VEMS_R_10_02673_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 EcuSt_stTypRst;                                               */
/*  input boolean Ext_bSecBrkPedPrssMesMem;                                   */
/*  output boolean Ext_bSecBrkPedPrssMes;                                     */
/*  output boolean Ext_bSecBrkPedPrssMesMem;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MNGBRKPED_vidInitOutput(void)
{
   uint8  u8LocalEcuSt_stTypRst;


   VEMS_vidGET(EcuSt_stTypRst, u8LocalEcuSt_stTypRst);

   if (u8LocalEcuSt_stTypRst == RSTSRV_udtSOFTWARE_RESET)
   {
      VEMS_vidSET(Ext_bSecBrkPedPrssMes, Ext_bSecBrkPedPrssMesMem);
   }
   else
   {
      VEMS_vidSET(Ext_bSecBrkPedPrssMes, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MNGBRKPED_vidFCall                                         */
/* !Description :  fonction d'appel                                           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MNGBRKPED_vidDiagBrkPrdFil();                            */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Cf_bSecBrkPedPrss;                                          */
/*  input boolean ECU_bWkuMain;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MNGBRKPED_vidFCall(void)
{
   boolean  bLocalDIAGCAN_bIntegratioElec;
   boolean  bLocalCf_bSecBrkPedPrss;
   boolean  bLocalECU_bWkuMain;


   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegratioElec);
   VEMS_vidGET(Cf_bSecBrkPedPrss, bLocalCf_bSecBrkPedPrss);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   if (  (bLocalDIAGCAN_bIntegratioElec == 0)
      && (bLocalCf_bSecBrkPedPrss != 0)
      && (bLocalECU_bWkuMain != 0))
   {
      MNGBRKPED_vidDiagBrkPrdFil();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MNGBRKPED_vidDiagBrkPrdFil                                 */
/* !Description :  fonction de diagnostic pédale de frein                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_10_02673_004.01                                     */
/*                 VEMS_R_10_02673_005.01                                     */
/*                 VEMS_R_10_02673_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MNGBRKPED_vidDiagNoBVH2p();                              */
/*  extf argret void MNGBRKPED_vidDiagBVH2p();                                */
/*  input boolean Cf_bSecBrkPedPrssDiag;                                      */
/*  input boolean Ext_bSecBrkPedPrssMes;                                      */
/*  output boolean Ext_bSecBrkPedPrssMesMem;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MNGBRKPED_vidDiagBrkPrdFil(void)
{
   boolean  bLocalCf_bSecBrkPedPrssDiag;
   boolean  bLocalExt_bSecBrkPedPrssMes;


   VEMS_vidGET(Cf_bSecBrkPedPrssDiag, bLocalCf_bSecBrkPedPrssDiag);

   if(bLocalCf_bSecBrkPedPrssDiag != 0)
   {
      MNGBRKPED_vidDiagNoBVH2p();
   }
   else
   {
      MNGBRKPED_vidDiagBVH2p();
   }
   VEMS_vidGET(Ext_bSecBrkPedPrssMes, bLocalExt_bSecBrkPedPrssMes);
   Ext_bSecBrkPedPrssMesMem = bLocalExt_bSecBrkPedPrssMes;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MNGBRKPED_vidDiagBVH2p                                     */
/* !Description :  fonction Software diagnostic BVH2 pour l'information Frein */
/*                 Secondaire est activée                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bSecBrkPedPrssDefaut_C;                                 */
/*  input boolean Ext_bSecBrkPedPrssFilt;                                     */
/*  output boolean Ext_bSecBrkPedPrssMes;                                     */
/*  output boolean Ext_bSecBrkPedPrssDefaut_C;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MNGBRKPED_vidDiagBVH2p(void)
{
   boolean              bLocalExt_bSecBrkPedPrssFilt;
   GDFRM_tenuGDUState   LocalstDgoAccelCoh;
   GDFRM_tenuGDUState   LocalstDgoDecelCoh;


   LocalstDgoAccelCoh = GDGAR_tenuGetStDgo(GD_DFT_ACCELCOH_BRKPEDBVH2P);
   LocalstDgoDecelCoh = GDGAR_tenuGetStDgo(GD_DFT_DECELCOH_BRKPEDBVH2P);
   if (  (  (LocalstDgoAccelCoh == GDU_ETAT_PRESENT)
         || (LocalstDgoAccelCoh == GDU_ETAT_DEVALIDATION))
      || (  (LocalstDgoDecelCoh == GDU_ETAT_PRESENT)
         || (LocalstDgoDecelCoh == GDU_ETAT_DEVALIDATION))
      )
   {
      VEMS_vidSET(Ext_bSecBrkPedPrssMes, Ext_bSecBrkPedPrssDefaut_C);
   }
   else
   {
      if (  (  (LocalstDgoAccelCoh != GDU_ETAT_PCTL_PRESENT)
            && (LocalstDgoAccelCoh != GDU_ETAT_PCTL_ABSENT))
         && (  (LocalstDgoDecelCoh != GDU_ETAT_PCTL_PRESENT)
            && (LocalstDgoDecelCoh != GDU_ETAT_PCTL_ABSENT))
         )
      {
         VEMS_vidGET(Ext_bSecBrkPedPrssFilt, bLocalExt_bSecBrkPedPrssFilt);
         VEMS_vidSET(Ext_bSecBrkPedPrssMes, bLocalExt_bSecBrkPedPrssFilt);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MNGBRKPED_vidDiagNoBVH2p                                   */
/* !Description :  fonction Software diagnostic hors BVH2 pour l'information  */
/*                 Frein Secondaire est activée                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bSecBrkPedPrssDefaut_C;                                 */
/*  input boolean Ext_bSecBrkPedPrssFilt;                                     */
/*  output boolean Ext_bSecBrkPedPrssMes;                                     */
/*  output boolean Ext_bSecBrkPedPrssDefaut_C;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MNGBRKPED_vidDiagNoBVH2p(void)
{
   boolean              bLocalExt_bSecBrkPedPrssFilt;
   GDFRM_tenuGDUState   LocalstDgoAccelCoh;
   GDFRM_tenuGDUState   LocalstDgoDecelCoh;
   GDFRM_tenuGDUState   LocalstDgoInvCoh;


   LocalstDgoAccelCoh = GDGAR_tenuGetStDgo(GD_DFT_ACCELCOH_BRKPED);
   LocalstDgoDecelCoh = GDGAR_tenuGetStDgo(GD_DFT_DECELCOH_BRKPED);
   LocalstDgoInvCoh = GDGAR_tenuGetStDgo(GD_DFT_INVCOH_BRKPED);
   if (  (  (LocalstDgoAccelCoh == GDU_ETAT_PRESENT)
         || (LocalstDgoAccelCoh == GDU_ETAT_DEVALIDATION))
      || (  (LocalstDgoDecelCoh == GDU_ETAT_PRESENT)
         || (LocalstDgoDecelCoh == GDU_ETAT_DEVALIDATION))
      || (  (LocalstDgoInvCoh == GDU_ETAT_PRESENT)
         || (LocalstDgoInvCoh == GDU_ETAT_DEVALIDATION))
      )
   {
      VEMS_vidSET(Ext_bSecBrkPedPrssMes, Ext_bSecBrkPedPrssDefaut_C);
   }
   else
   {
      if (  (  (LocalstDgoAccelCoh != GDU_ETAT_PCTL_PRESENT)
            && (LocalstDgoAccelCoh != GDU_ETAT_PCTL_ABSENT))
         && (  (LocalstDgoDecelCoh != GDU_ETAT_PCTL_PRESENT)
            && (LocalstDgoDecelCoh != GDU_ETAT_PCTL_ABSENT))
         && (  (LocalstDgoInvCoh != GDU_ETAT_PCTL_PRESENT)
            && (LocalstDgoInvCoh != GDU_ETAT_PCTL_ABSENT))
         )
      {
         VEMS_vidGET(Ext_bSecBrkPedPrssFilt, bLocalExt_bSecBrkPedPrssFilt);
         VEMS_vidSET(Ext_bSecBrkPedPrssMes, bLocalExt_bSecBrkPedPrssFilt);
      }
   }
}
/*------------------------------end-of-file-----------------------------------*/