/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTFONCDIAG                                            */
/* !Description     : AIRTFONCDIAG component.                                 */
/*                                                                            */
/* !Module          : AIRTFONCDIAG                                            */
/* !Description     : Diagnostic fonctionnel de la température d’admission    */
/*                    d’air.                                                  */
/*                                                                            */
/* !File            : AIRTFONCDIAG_SCH.C                                      */
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
/*   1 / AIRTFONCDIAG_vidEntryInit                                            */
/*   2 / AirT_SdlMid_MonAirT                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5070969 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/AIRTFONCDIAG/AIRTFONCDIAG_SCH.C_v $*/
/* $Revision::   1.1      $$Author::   CROCHE         $$Date::   27 Jun 2011 $*/
/* $Author::   CROCHE                                 $$Date::   27 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "AIRTFONCDIAG.h"
#include "AIRTFONCDIAG_L.h"
#include "AIRTFONCDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTFONCDIAG_vidEntryInit                                  */
/* !Description :  Evènement Reset du module AIRTFONCDIAG.                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTFONCDIAG_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AIRTFONCDIAG_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTFONCDIAG_vidEntryInit(void)
{
   AIRTFONCDIAG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_SdlMid_MonAirT                                        */
/* !Description :  Moniteur moyen de la fonction AirT                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTFONCDIAG_vidBeforeStartCoh();                        */
/*  extf argret void AIRTFONCDIAG_vidOutRngDtct();                            */
/*  extf argret void AIRTFONCDIAG_vidPosOfsDtct();                            */
/*  extf argret void AIRTFONCDIAG_vidNegOfsDtct();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 AIRTFONCDIAG_u8Inhib;                                         */
/*  input boolean AirT_bDgoStallCoh_tAirMes;                                  */
/*  input boolean AirT_bMonRunStallCoh_tAirMes;                               */
/*  input boolean AirT_bDgoORng_tAirMes;                                      */
/*  input boolean AirT_bMonRunORng_tAirMes;                                   */
/*  input boolean AirT_bDgoPosOfs_tAirMes;                                    */
/*  input boolean AirT_bMonRunPosOfs_tAirMes;                                 */
/*  input boolean AirT_bDgoNegOfs_tAirMes;                                    */
/*  input boolean AirT_bMonRunNegOfs_tAirMes;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_SdlMid_MonAirT                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_SdlMid_MonAirT(void)
{
   if (AIRTFONCDIAG_u8Inhib != 0x5A)
   {
      AIRTFONCDIAG_vidBeforeStartCoh();
      AIRTFONCDIAG_vidOutRngDtct();
      AIRTFONCDIAG_vidPosOfsDtct();
      AIRTFONCDIAG_vidNegOfsDtct();

      GDGAR_vidGdu(GD_DFT_STALLCOH_TAIRMES,
                   AirT_bDgoStallCoh_tAirMes,
                   AirT_bMonRunStallCoh_tAirMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_TAIRMES,
                   AirT_bDgoORng_tAirMes,
                   AirT_bMonRunORng_tAirMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_POSOFS_TAIRMES,
                   AirT_bDgoPosOfs_tAirMes,
                   AirT_bMonRunPosOfs_tAirMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_NEGOFS_TAIRMES,
                   AirT_bDgoNegOfs_tAirMes,
                   AirT_bMonRunNegOfs_tAirMes,
                   DIAG_DISPO);
   }
}
/*-------------------------------- end of file -------------------------------*/