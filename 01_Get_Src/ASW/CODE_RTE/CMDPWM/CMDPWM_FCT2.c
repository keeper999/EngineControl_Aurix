/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CMDPWM                                                  */
/* !Description     : CMDPWM component.                                       */
/*                                                                            */
/* !Module          : CMDPWM                                                  */
/* !Description     : SPECIFICATION DES COMMANDES EN PWM  ENVOYEES AU BSW     */
/*                                                                            */
/* !File            : CMDPWM_FCT2.c                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CMDPWM_vidDriverInh                                                  */
/*   2 / CMDPWM_vidF00_Init_CmdPwmECTCmd                                      */
/*   3 / CMDPWM_vidF00_Init_CmdPwmThrCmd                                      */
/*   4 / CMDPWM_vidInitOutput                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6669891 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CMDPWM/CMDPWM_FCT2.c_v            $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   29 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   29 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "CMDPWM.h"
#include "CMDPWM_L.h"
#include "CMDPWM_IM.h"
#include "PWMHAL.h"
#include "HBHAL.h"
#include "CMDPWM_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidDriverInh                                        */
/* !Description :  Ce bloc décrit l’activation et la désactivation par le LDA */
/*                 du composant LDB qui pilote le Hbridge HBHAL.              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HBHAL_vidDisable(uint8 u8Channel);                       */
/*  extf argret void HBHAL_vidEnable(uint8 u8Channel);                        */
/*  input boolean Demande_inhibition_hbridge;                                 */
/*  input boolean CMDPWM_bDemandeInhibHbridge_Prev;                           */
/*  output boolean CMDPWM_bDemandeInhibHbridge_Prev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidDriverInh(void)
{
   boolean  bLocalDemande_inhibition_hbridge;


   VEMS_vidGET(Demande_inhibition_hbridge, bLocalDemande_inhibition_hbridge);
   if (bLocalDemande_inhibition_hbridge != 0)
   {
      if (CMDPWM_bDemandeInhibHbridge_Prev == 0)
      {
         HBHAL_vidDisable(CH_HB_CMD_THR);
      }
   }
   else
   {
      if (CMDPWM_bDemandeInhibHbridge_Prev != 0)
      {
         HBHAL_vidEnable(CH_HB_CMD_THR);
      }
   }
   CMDPWM_bDemandeInhibHbridge_Prev = bLocalDemande_inhibition_hbridge;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidF00_Init_CmdPwmECTCmd                            */
/* !Description :  Initialisation de la valeur de la fréquence du signal RCO  */
/*                 de commande du thermostat envoyé au BSW.                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWMHAL_vidWriteFrequency(argin PWMHAL_tudtChannel        */
/*  udtChannel, argin PWMHAL_tudtFrequency udtFrequency);                     */
/*  input uint16 ECTReq_ECTReqFreq_C;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidF00_Init_CmdPwmECTCmd(void)
{
   PWMHAL_vidWriteFrequency(CH_PWM_THERMOSTAT_PILOTE, ECTReq_ECTReqFreq_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidF00_Init_CmdPwmThrCmd                            */
/* !Description :  Initialisation du throttle.                                */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HBHAL_vidWrite(argin uint8 u8Channel, argin              */
/*  HBHAL_tudtSetPoint udtSetPoint);                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidF00_Init_CmdPwmThrCmd(void)
{
   HBHAL_vidWrite(CH_HB_CMD_THR, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDPWM_vidInitOutput                                       */
/* !Description :  Initialisation des variables internes                      */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean CMDPWM_bDemandeInhibHbridge_Prev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDPWM_vidInitOutput(void)
{
   CMDPWM_bDemandeInhibHbridge_Prev = 0;
}
/*-------------------------------- end of file -------------------------------*/