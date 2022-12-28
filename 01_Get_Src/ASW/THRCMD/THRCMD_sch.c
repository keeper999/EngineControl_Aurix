/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRCMD                                                  */
/* !Description     : THRCMD Component                                        */
/*                                                                            */
/* !Module          : THRCMD                                                  */
/* !Description     : Commande et diagnostics du driver du papillon motorisé  */
/*                                                                            */
/* !File            : THRCMD_SCH.c                                            */
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
/*   1 / Thr_EveRst_ThrCmd                                                    */
/*   2 / Thr_EveClcnServo_ThrCmd                                              */
/*   3 / Thr_SdlMid_ThrCmd                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_6587801 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRCMD/THRCMD_SCH.c_v         $*/
/* $Revision::   1.7      $$Author::   wbouach        $$Date::   02 Jun 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRCMD.h"
#include "THRCMD_L.h"
#include "THRCMD_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_ThrCmd                                          */
/* !Description :  Function call on the reset CMM.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_08_06318_001.01                                     */
/*                 VEMS_E_08_06318_002.01                                     */
/*                 VEMS_E_08_06318_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRCMD_vidInitOutput();                                  */
/*  extf argret void THRCMD_vidDriverInh();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_ThrCmd                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_ThrCmd(void)
{
   THRCMD_vidInitOutput();
   THRCMD_vidDriverInh();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_ThrCmd                                    */
/* !Description :  function which allows to make the some calculation for the */
/*                 throttle.                                                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_08_06318_001.01                                     */
/*                 VEMS_E_08_06318_002.01                                     */
/*                 VEMS_E_08_06318_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRCMD_vidComptagePanne();                               */
/*  extf argret void THRCMD_vidCommandTpac();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 THRCMD_u8Inhib;                                               */
/*  input boolean Thr_bDgoOvld_ThrCmd;                                        */
/*  input boolean Thr_bMonRunOvld_ThrCmd;                                     */
/*  input boolean Thr_bDgoCpt_ThrCmd;                                         */
/*  input boolean Thr_bMonRunCpt_ThrCmd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_ThrCmd                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_ThrCmd(void)
{
   if (THRCMD_u8Inhib != 0x5A)
   {
      THRCMD_vidComptagePanne();
      THRCMD_vidCommandTpac();
      GDGAR_vidGdu(GD_DFT_OVLD_THRCMD,
                     Thr_bDgoOvld_ThrCmd,
                     Thr_bMonRunOvld_ThrCmd,
                     DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_CPT_THRCMD,
                     Thr_bDgoCpt_ThrCmd,
                     Thr_bMonRunCpt_ThrCmd,
                     DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_ThrCmd                                          */
/* !Description :  Moniteur moyen de la fonction papillon                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_08_06318_001.01                                     */
/*                 VEMS_E_08_06318_002.01                                     */
/*                 VEMS_E_08_06318_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRCMD_vidDriverInh();                                   */
/*  input uint8 THRCMD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_ThrCmd                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_ThrCmd(void)
{
   if (THRCMD_u8Inhib != 0x5A)
   {
      THRCMD_vidDriverInh();
   }
}
/*------------------------------ end of file ---------------------------------*/