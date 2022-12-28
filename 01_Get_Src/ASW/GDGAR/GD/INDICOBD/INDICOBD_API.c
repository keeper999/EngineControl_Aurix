/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INDICOBD                                                */
/* !Description     : INDICOBD Component                                      */
/*                                                                            */
/* !Module          : INDICOBD                                                */
/* !Description     : REGULATEUR DES INDICATEURS OBD                          */
/*                                                                            */
/* !File            : INDICOBD_API.c                                          */
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
/*   1 / GD_EveRstDft_IndicOBD                                                */
/*   2 / GD_EveRstDftObd_IndicOBD                                             */
/*   3 / INDICOBD_RstDftCal                                                   */
/*   4 / INDICOBD_vidMngEveStObdRec                                           */
/*   5 / INDICOBD_vidMngEveStObdClear                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5075367 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065277                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/INDICOBD/INDICOBD_API.C_v    $*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   28 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "INDICOBD.h"
#include "INDICOBD_L.h"
#include "INDICOBD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDft_IndicOBD                                      */
/* !Description :  After-sale tool request for a clear failure                */
/* !Number      :  API.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidF04_RstCnt();                                */
/*  extf argret void INDICOBD_vidDftMILCntPrev();                             */
/*  input uint8 INDICOBD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDft_IndicOBD(void)
{
   if(INDICOBD_u8Inhib != 0x5A)
   {
      INDICOBD_vidF04_RstCnt();
      INDICOBD_vidDftMILCntPrev();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDftObd_IndicOBD                                   */
/* !Description :  After-sale tool request for an OBD clear failure           */
/* !Number      :  API.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidF04_RstCnt();                                */
/*  extf argret void INDICOBD_vidDftMILCntPrev();                             */
/*  input uint8 INDICOBD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDftObd_IndicOBD(void)
{
   if(INDICOBD_u8Inhib != 0x5A)
   {
      INDICOBD_vidF04_RstCnt();
      INDICOBD_vidDftMILCntPrev();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_RstDftCal                                         */
/* !Description :  Manual clear failure request                               */
/* !Number      :  API.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidF04_RstCnt();                                */
/*  extf argret void INDICOBD_vidDftMILCntPrev();                             */
/*  input uint8 INDICOBD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_RstDftCal(void)
{
   if(INDICOBD_u8Inhib != 0x5A)
   {
      INDICOBD_vidF04_RstCnt();
      INDICOBD_vidDftMILCntPrev();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidMngEveStObdRec                                 */
/* !Description :  Evènement entrée du Gestionnaire OBD dans l'état           */
/*                 GOBD_ST_ENREGISTRE                                         */
/* !Number      :  API.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidDftMILCntPrev();                             */
/*  extf argret void INDICOBD_vidMngDftMILCntInc(argin uint16 u16IdxDft);     */
/*  input uint8 INDICOBD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidMngEveStObdRec
(
   uint16 u16IdxDft
)
{
   if (INDICOBD_u8Inhib != 0x5A)
   {
      INDICOBD_vidDftMILCntPrev();
      INDICOBD_vidMngDftMILCntInc(u16IdxDft);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INDICOBD_vidMngEveStObdClear                               */
/* !Description :  Evènement entrée du Gestionnaire OBD dans l'état GOBD      */
/*                 effacé                                                     */
/* !Number      :  API.5                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidDftMILCntPrev();                             */
/*  extf argret void INDICOBD_vidMngDftMILCntDec(argin uint16 u16IdxDft);     */
/*  extf argret void INDICOBD_vidDftMILRstCnt();                              */
/*  input uint8 INDICOBD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INDICOBD_vidMngEveStObdClear
(
   uint16 u16IdxDft
)
{
   if (INDICOBD_u8Inhib != 0x5A)
   {
      INDICOBD_vidDftMILCntPrev();
      INDICOBD_vidMngDftMILCntDec(u16IdxDft);
      INDICOBD_vidDftMILRstCnt();
   }
}
/*-------------------------------- end of file -------------------------------*/