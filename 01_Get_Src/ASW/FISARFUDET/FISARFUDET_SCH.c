/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FISARFUDET                                              */
/* !Description     : FISARFUDET component.                                   */
/*                                                                            */
/* !Module          : FISARFUDET                                              */
/* !Description     : DETECTION DE REMPLISSAGE CARBURANT POUR LA FONCTION     */
/*                    FISA.                                                   */
/*                                                                            */
/* !File            : FISARFUDET_SCH.C                                        */
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
/*   1 / Fisa_EveInit                                                         */
/*   2 / Fisa_EveRTSt_FisaRFuDet                                              */
/*   3 / Fisa_EveKOn_FisaRFuDet                                               */
/*   4 / Fisa_EveTDC_FisaRFuDet                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 07467 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#060865                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/FISARFUDET/FISARFUDET_SCH.C_v     $*/
/* $Revision::   1.5      $$Author::   bbris          $$Date::   16 Apr 2012 $*/
/* $Author::   bbris                                  $$Date::   16 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "FISARFUDET.h"
#include "FISARFUDET_L.h"
#include "FISARFUDET_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fisa_EveInit                                               */
/* !Description :  Evénement init                                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Imen.Barrak                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FISARFUDET_vidInit();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  Fisa_EveInit                                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_EveInit(void)
{
   FISARFUDET_vidInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fisa_EveRTSt_FisaRFuDet                                    */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_08_07467_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FISARFUDET_vidArretMoteur();                             */
/*  input uint8 FISARFUDET_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fisa_EveRTSt_FisaRFuDet                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_EveRTSt_FisaRFuDet(void)
{
   if (FISARFUDET_u8Inhib != 0x5A)
   {
      FISARFUDET_vidArretMoteur();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fisa_EveKOn_FisaRFuDet                                     */
/* !Description :  Evénement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_08_07467_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FISARFUDET_vidClefOn();                                  */
/*  extf argret void FISARFUDET_vidCndCalcCoefLissage();                      */
/*  input uint8 FISARFUDET_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  Fisa_EveKOn_FisaRFuDet                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_EveKOn_FisaRFuDet(void)
{
   if (FISARFUDET_u8Inhib != 0x5A)
   {
      FISARFUDET_vidClefOn();
      FISARFUDET_vidCndCalcCoefLissage();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fisa_EveTDC_FisaRFuDet                                     */
/* !Description :  Interruption PMH                                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Imen.Barrak                                                */
/* !Trace_To    :  VEMS_R_08_07467_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FISARFUDET_vidCalculValeursReset();                      */
/*  extf argret void FISARFUDET_vidCndCalcCoefLissage();                      */
/*  input uint8 FISARFUDET_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  Fisa_EveKOn_FisaRFuDet                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_EveTDC_FisaRFuDet(void)
{
   if (FISARFUDET_u8Inhib != 0x5A)
   {
      FISARFUDET_vidCalculValeursReset();
      FISARFUDET_vidCndCalcCoefLissage();
   }
}
/*------------------------------ end of file ---------------------------------*/