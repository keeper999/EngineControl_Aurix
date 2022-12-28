/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLCNFISAGAIN                                            */
/* !Description     : CLCNFISAGAIN Component.                                 */
/*                                                                            */
/* !Module          : CLCNFISAGAIN                                            */
/* !Description     : Calcul des coefficients de correction liés à la FISA.   */
/*                                                                            */
/* !File            : CLCNFISAGAIN_SCH.C                                      */
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
/*   1 / CLCNFISAGAIN_vidEntryInit                                            */
/*   2 / Fisa_EveStTR_ClcnFisaGain                                            */
/*   3 / Fisa_EveTDC_ClcnFisaGain                                             */
/*   4 / Fisa_EvePwrl_ClcnFisaGain                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 04650 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CLCNFISAGAIN/CLCNFISAGAIN_SCH.C_v $*/
/* $Revision::   1.3      $$Author::   achebino       $$Date::   27 Nov 2013 $*/
/* $Author::   achebino                               $$Date::   27 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "CLCNFISAGAIN.h"
#include "CLCNFISAGAIN_L.h"
#include "CLCNFISAGAIN_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLCNFISAGAIN_vidEntryInit                                  */
/* !Description :  Evennement d'initialisation.                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLCNFISAGAIN_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CLCNFISAGAIN_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLCNFISAGAIN_vidEntryInit(void)
{
   CLCNFISAGAIN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fisa_EveStTR_ClcnFisaGain                                  */
/* !Description :  Evénement correspondant au passage à 1 de la  variable     */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_04650_001.01                                     */
/*                 VEMS_R_08_04650_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLCNFISAGAIN_vidCalculCoeff();                           */
/*  input uint8 CLCNFISAGAIN_u8inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fisa_EveStTR_ClcnFisaGain                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_EveStTR_ClcnFisaGain(void)
{
   if ( CLCNFISAGAIN_u8inhib != 0x5A )
   {
      CLCNFISAGAIN_vidCalculCoeff();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fisa_EveTDC_ClcnFisaGain                                   */
/* !Description :  Evènement interruption PMH                                 */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_04650_001.01                                     */
/*                 VEMS_R_08_04650_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLCNFISAGAIN_vidCalculCoeff();                           */
/*  input uint8 CLCNFISAGAIN_u8inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fisa_EveTDC_ClcnFisaGain                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_EveTDC_ClcnFisaGain(void)
{
   if ( CLCNFISAGAIN_u8inhib != 0x5A )
   {
      CLCNFISAGAIN_vidCalculCoeff();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fisa_EvePwrl_ClcnFisaGain                                  */
/* !Description :  Evènement power latch                                      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_04650_001.01                                     */
/*                 VEMS_R_08_04650_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLCNFISAGAIN_vidAllowedWrite();                          */
/*  input uint8 CLCNFISAGAIN_u8inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fisa_EvePwrl_ClcnFisaGain                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_EvePwrl_ClcnFisaGain(void)
{
   if ( CLCNFISAGAIN_u8inhib != 0x5A )
   {
      CLCNFISAGAIN_vidAllowedWrite();
   }
}

/*------------------------------- end of file --------------------------------*/