/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGMEMECU                                              */
/* !Description     : DIAGMEMECU component                                    */
/*                                                                            */
/* !Module          : DIAGMEMECU                                              */
/* !Description     : Diagnostic des Mémoires Flash et EEPROM du Calculateur  */
/*                                                                            */
/* !File            : DIAGMEMECU_FCT1.C                                       */
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
/*   1 / DIAGMEMECU_vidEcuStEepromEna                                         */
/*   2 / DIAGMEMECU_vidEcuStEepromOK                                          */
/*   3 / DIAGMEMECU_vidEepromOK                                               */
/*   4 / DIAGMEMECU_vidEcuStFlashChk                                          */
/*                                                                            */
/* !Reference   : V02 NT 10 02966 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/DIAGMEMECU/diagmemecu_fct1.c_v    $*/
/* $Revision::   1.1      $$Author::   vvoyer         $$Date::   10 Jun 2010 $*/
/* $Author::   vvoyer                                 $$Date::   10 Jun 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "DIAGMEMECU.h"
#include "DIAGMEMECU_L.h"
#include "DIAGMEMECU_IM.h"
#include "DGOHAL.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGMEMECU_vidEcuStEepromEna                               */
/* !Description :  Fonction d'in itialisation du enable pour le diagnostic de */
/*                 EEPROM                                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  BCHINI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean EcuSt_bDftEepromEna;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGMEMECU_vidEcuStEepromEna(void)
{
   EcuSt_bDftEepromEna = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGMEMECU_vidEcuStEepromOK                                */
/* !Description :  Fonction d'activiation du diagnostic de l'eeprom           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  BCHINI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGMEMECU_vidEepromOK();                                */
/*  input boolean EcuSt_bDftEepromEna;                                        */
/*  output boolean EcuSt_bMonRunDftEeprom;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGMEMECU_vidEcuStEepromOK(void)
{
   if (EcuSt_bDftEepromEna != 0)
   {
      EcuSt_bMonRunDftEeprom = 1;
      DIAGMEMECU_vidEepromOK();
   }
   else
   {
      EcuSt_bMonRunDftEeprom = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGMEMECU_vidEepromOK                                     */
/* !Description :  EcuSt_bDgoDftEeprom indique (quand il est VRAI) un défaut  */
/*                 EEPROM (absence, endommagement physique ou pas accessible  */
/*                 (problème de communication SPI)) pour un calculateur non   */
/*                 vierge.                                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  BCHINI                                                     */
/* !Trace_To    :  VEMS_R_10_02699_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NVMSRV_bIsVirgin();                                  */
/*  extf argret boolean  NVMSRV_bIsOk();                                      */
/*  output boolean EcuSt_bDgoDftEeprom;                                       */
/*  output boolean EcuSt_bDftEepromEna;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGMEMECU_vidEepromOK(void)
{
   boolean bLocalbIsVirgin;
   boolean bLocalbIsOk;


   bLocalbIsVirgin = NVMSRV_bIsVirgin();
   bLocalbIsOk = NVMSRV_bIsOk();

   if (  (bLocalbIsVirgin == 0)
      && (bLocalbIsOk == 0))
   {
      EcuSt_bDgoDftEeprom = 1;
   }
   else
   {
      EcuSt_bDgoDftEeprom = 0;
   }

   EcuSt_bDftEepromEna = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGMEMECU_vidEcuStFlashChk                                */
/* !Description :  Lorsqu’il y a un défaut sur la mémoire Flash (calibration  */
/*                 ou Checksum), le booléen EcuSt_bDgoFlashChk passe à 1.     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  BCHINI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  output boolean EcuSt_bMonRunFlashChk;                                     */
/*  output boolean EcuSt_bDgoFlashChk;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGMEMECU_vidEcuStFlashChk(void)
{
   DGOHAL_tbfStatus bfLocalFaultValue;


   bfLocalFaultValue = DGOHAL_bfRead(DGOHAL_udtMMCDGN);
   if ( ( bfLocalFaultValue
        & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_MMCDGN_CKS)) != 0)
   {
      EcuSt_bMonRunFlashChk = 1;
      if ( ( bfLocalFaultValue
           & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_MMCDGN_CKS)) != 0)
      {
         EcuSt_bDgoFlashChk = 1;
      }
      else
      {
         EcuSt_bDgoFlashChk = 0;
      }
   }
   else
   {
      EcuSt_bMonRunFlashChk = 0;
   }
}
/*--------------------------------- end of file ------------------------------*/