/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STTMO2CLC                                               */
/* !Description     : STTMO2CLC Component                                     */
/*                                                                            */
/* !Module          : STTMO2CLC                                               */
/* !Description     : Calcul de la masse O2 dans le catalyseur                */
/*                                                                            */
/* !File            : STTMO2CLC_SCH.C                                         */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BITS                                                  */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / STT_EveRst_STTmO2Clc                                                 */
/*   2 / STT_EveTDC_STTmO2Clc                                                 */
/*   3 / STT_SdlFast_STTmO2Clc                                                */
/*                                                                            */
/* !Reference   : V02 NT 11 05704 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                 */
/* $Revision::                                                                */
/* $Author::                                                                  */
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STTMO2CLC.h"
#include "STTMO2CLC_L.h"
#include "STTMO2CLC_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_EveRst_STTmO2Clc                                       */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_E_11_05704_001.01                                     */
/*                 VEMS_E_11_05704_002.01                                     */
/*                 VEMS_E_11_05704_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTMO2CLC_vidInit();                                     */
/*  extf argret void STTMO2CLC_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_EveRst_STTmO2Clc                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_EveRst_STTmO2Clc(void)
{
   STTMO2CLC_vidInit();
   STTMO2CLC_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_EveTDC_STTmO2Clc                                       */
/* !Description :  Evènement TDC                                              */
/* !Number      :  SCH.2                                                      */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_E_11_05704_001.01                                     */
/*                 VEMS_E_11_05704_002.01                                     */
/*                 VEMS_E_11_05704_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTMO2CLC_vidCompteur_TDC_STT();                         */
/*  input uint8 STTMO2CLC_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_EveRst_STTmO2Clc                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_EveTDC_STTmO2Clc(void)
{
   if (STTMO2CLC_u8Inhib != 0x5A)
   {
      STTMO2CLC_vidCompteur_TDC_STT();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_SdlFast_STTmO2Clc                                      */
/* !Description :  Moniteur rapide de la fonction STT                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_E_11_05704_001.01                                     */
/*                 VEMS_E_11_05704_002.01                                     */
/*                 VEMS_E_11_05704_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTMO2CLC_vidCalcul_mO2_cata();                          */
/*  input uint8 STTMO2CLC_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_SdlFast_STTmO2Clc                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_SdlFast_STTmO2Clc(void)
{
   if (STTMO2CLC_u8Inhib != 0x5A)
   {
      STTMO2CLC_vidCalcul_mO2_cata();
   }
}
/*------------------------------- end of file --------------------------------*/