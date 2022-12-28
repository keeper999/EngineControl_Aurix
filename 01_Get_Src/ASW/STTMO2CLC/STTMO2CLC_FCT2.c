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
/* !File            : STTMO2CLC_FCT2.C                                        */
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
/*   1 / STTMO2CLC_vidAct_tens_sond_basse                                     */
/*   2 / STTMO2CLC_vidDesac_tens_sond_bas                                     */
/*   3 / STTMO2CLC_vidAct_tens_sond_haute                                     */
/*   4 / STTMO2CLC_vidDesac_tens_sond_hau                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 05704 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                 */
/* $Revision::                                                                */
/* $Author:                                        */
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
/* !Function    :  STTMO2CLC_vidAct_tens_sond_basse                           */
/* !Description :  Conditions de l'activation de la sonde à basse tension     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Eng_VoltDownLsLow;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidAct_tens_sond_basse(void)
{
   /* 1_Active_tension_sonde_basse */
   Eng_VoltDownLsLow = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidDesac_tens_sond_bas                           */
/* !Description :  Conditions de la désactivation de la sonde à basse tension */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Eng_VoltDownLsLow;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidDesac_tens_sond_bas(void)
{
   /* 2_Desactive_tension_sonde_basse */
   Eng_VoltDownLsLow = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidAct_tens_sond_haute                           */
/* !Description :  Conditions de l'activation de la sonde à haute tension     */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Eng_VoltDownLsHigh;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidAct_tens_sond_haute(void)
{
   /* 3_Active_tension_sonde_haute */
   Eng_VoltDownLsHigh = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidDesac_tens_sond_hau                           */
/* !Description :  Conditions de la désactivation de la sonde à haute tension */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Eng_VoltDownLsHigh;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidDesac_tens_sond_hau(void)
{
   /* 4_Desactive_tension_sonde_haute */
   Eng_VoltDownLsHigh = 0;
}

/*------------------------------- end of file --------------------------------*/