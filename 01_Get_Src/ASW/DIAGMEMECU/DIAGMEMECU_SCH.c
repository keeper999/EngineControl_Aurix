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
/* !File            : DIAGMEMECU_SCH.C                                        */
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
/*   1 / EcuSt_EveRst_DiagMem                                                 */
/*   2 / EcuSt_SdlMid_DiagMem                                                 */
/*   3 / EcuSt_SdlSlow_DiagMem                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 02966 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/DIAGMEMECU/DIAGMEMECU_SCH.C_v     $*/
/* $Revision::   1.0      $$Author::   lthibaud       $$Date::   25 May 2010 $*/
/* $Author::   lthibaud                               $$Date::   25 May 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "DIAGMEMECU.h"
#include "DIAGMEMECU_L.h"
#include "DIAGMEMECU_IM.h"
#include "GDGAR.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveRst_DiagMem                                       */
/* !Description :  Reset du Calculateur                                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BCHINI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGMEMECU_vidEcuStEepromEna();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : EcuSt_EveRst_DiagMem                                           */
/* !Trigger  : EcuSt_EveRst_DiagMem                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveRst_DiagMem(void)
{
   DIAGMEMECU_vidEcuStEepromEna();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_SdlMid_DiagMem                                       */
/* !Description :  Moniteur moyen du diagnostic des mémoires EEPROM           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  BCHINI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGMEMECU_vidEcuStEepromOK();                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 DIAGMEMECU_u8Inhib;                                           */
/*  input boolean EcuSt_bDgoDftEeprom;                                        */
/*  input boolean EcuSt_bMonRunDftEeprom;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : EcuSt_SdlMid_DiagMem                                           */
/* !Trigger  : EcuSt_SdlMid_DiagMem                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_SdlMid_DiagMem(void)
{
   if (DIAGMEMECU_u8Inhib != 0x5A)
   {
      DIAGMEMECU_vidEcuStEepromOK();
      GDGAR_vidGdu(GD_DFT_DFTEEPROM,
                   EcuSt_bDgoDftEeprom,
                   EcuSt_bMonRunDftEeprom,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_SdlSlow_DiagMem                                      */
/* !Description :  Moniteur lent du diagnostic des mémoires Flash             */
/* !Number      :  SCH.3                                                      */
/* !Author      :  BCHINI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGMEMECU_vidEcuStFlashChk();                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 DIAGMEMECU_u8Inhib;                                           */
/*  input boolean EcuSt_bDgoFlashChk;                                         */
/*  input boolean EcuSt_bMonRunFlashChk;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : EcuSt_SdlSlow_DiagMem                                          */
/* !Trigger  : EcuSt_SdlSlow_DiagMem                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_SdlSlow_DiagMem(void)
{
   if (DIAGMEMECU_u8Inhib != 0x5A)
   {
      DIAGMEMECU_vidEcuStFlashChk();
      GDGAR_vidGdu(GD_DFT_FLASHCHK,
                   EcuSt_bDgoFlashChk,
                   EcuSt_bMonRunFlashChk,
                   DIAG_DISPO);
   }
}
/*--------------------------------- end of file ------------------------------*/