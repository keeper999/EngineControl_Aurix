/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGRUNST                                                */
/* !Description     : ENGRUNST component                                      */
/*                                                                            */
/* !Module          : ENGRUNST                                                */
/* !Description     : Etat moteur tournant                                    */
/*                                                                            */
/* !File            : ENGRUNST_SCH.C                                          */
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
/*   1 / EngSt_EveRst_EngrunSt                                                */
/*   2 / EngSt_SdlFast_EngrunSt                                               */
/*   3 / EngSt_EveCrTR_EngrunSt                                               */
/*   4 / EngSt_EveKOn_EngrunSt                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5489080 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ENGST/ENGRUNST/ENGRUNST_SCH.C_v $*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   13 Sep 2013 $*/
/* $Author::   mbenfrad                               $$Date::   13 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "ENGRUNST.H"
#include "ENGRUNST_L.H"
#include "ENGRUNST_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_EngrunSt                                      */
/* !Description :  évenement reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_08_05237_009.01                                     */
/*                 VEMS_E_08_05237_010.01                                     */
/*                 VEMS_E_08_05237_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGRUNST_vidInitOutput();                                */
/*  extf argret void ENGRUNST_vidInit();                                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ENGRUNST_vidEngrunst();                                  */
/*  extf argret void ENGRUNST_vidEngrunStInterface();                         */
/*  output boolean EngSt_bEngNOnIdl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_EngrunSt                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_EngrunSt(void)
{
   ENGRUNST_vidInitOutput();
   ENGRUNST_vidInit();

   VEMS_vidSET(EngSt_bEngNOnIdl, 0);

   ENGRUNST_vidEngrunst();
   ENGRUNST_vidEngrunStInterface();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_EngrunSt                                     */
/* !Description :  Moniteur Rapide de la fonction EngSt.                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_08_05237_009.01                                     */
/*                 VEMS_E_08_05237_010.01                                     */
/*                 VEMS_E_08_05237_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGRUNST_vidFullLoadEntryDelay();                        */
/*  extf argret void ENGRUNST_vidFcoMainConditions();                         */
/*  extf argret void ENGRUNST_vidCutOffInputMngt();                           */
/*  extf argret void ENGRUNST_vidOverpeedFcoCondEntry();                      */
/*  extf argret void ENGRUNST_vidEngrunst();                                  */
/*  extf argret void ENGRUNST_vidEngrunStInterface();                         */
/*  extf argret void ENGRUNST_vidDiag();                                      */
/*  extf argret void ENGRUNST_vidRstAcvTrqLim();                              */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 ENGRUNST_u8Inhib;                                             */
/*  input boolean EngSt_bDgoRedESLim;                                         */
/*  input boolean EngSt_bMonRunRedESLim;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_EngrunSt                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_EngrunSt(void)
{
   if (ENGRUNST_u8Inhib != 0x5A)
   {
      ENGRUNST_vidFullLoadEntryDelay();
      ENGRUNST_vidFcoMainConditions();
      ENGRUNST_vidCutOffInputMngt();
      ENGRUNST_vidOverpeedFcoCondEntry();
      ENGRUNST_vidEngrunst();
      ENGRUNST_vidEngrunStInterface();
      ENGRUNST_vidDiag();
      ENGRUNST_vidRstAcvTrqLim();

      GDGAR_vidGdu(GD_DFT_REDESLIM,
                   EngSt_bDgoRedESLim,
                   EngSt_bMonRunRedESLim,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveCrTR_EngrunSt                                     */
/* !Description :  Evénement CRANKING vers RUNNING.                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_08_05237_009.01                                     */
/*                 VEMS_E_08_05237_010.01                                     */
/*                 VEMS_E_08_05237_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGRUNST_vidDelayTimeout();                              */
/*  input uint8 ENGRUNST_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveCrTR_EngrunSt                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveCrTR_EngrunSt(void)
{
   if (ENGRUNST_u8Inhib != 0x5A)
   {
      ENGRUNST_vidDelayTimeout();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveKOn_EngrunSt                                      */
/* !Description :  Evénement clef Off_On                                      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_E_08_05237_009.01                                     */
/*                 VEMS_E_08_05237_010.01                                     */
/*                 VEMS_E_08_05237_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGRUNST_vidKeyOnCalc();                                 */
/*  input uint8 ENGRUNST_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveKOn_EngrunSt                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveKOn_EngrunSt(void)
{
   if (ENGRUNST_u8Inhib != 0x5A)
   {
      ENGRUNST_vidKeyOnCalc();
   }
}
/*------------------------------- end of file --------------------------------*/