/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DMPVLVCMD                                               */
/* !Description     : DMPVLVCMD Component.                                    */
/*                                                                            */
/* !Module          : DMPVLVCMD                                               */
/* !Description     : DUMP-VALVE COMMAND AND DIAGNOSIS .                      */
/*                                                                            */
/* !File            : DMPVLVCMD_SCH.c                                         */
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
/*   1 / DmpVlvAct_EveRst_DmpVlvCmd                                           */
/*   2 / DmpVlvAct_SdlFast_DmpVlvCmd                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6851423 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DMPVLVCMD.h"
#include "DMPVLVCMD_L.h"
#include "DMPVLVCMD_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvAct_EveRst_DmpVlvCmd                                 */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_01324_001.01                                     */
/*                 VEMS_E_10_01324_002.01                                     */
/*                 VEMS_E_10_01324_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DmpVlvCmd_vidDmpVlvCmdAplication();                      */
/*  extf argret void DmpVlvCmd_vidInitEveRst();                               */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean DmpVlvAct_bDgoLo_DmpVlvCmd;                                 */
/*  input boolean DmpVlvAct_bMonRunLo_DmpVlvCmd;                              */
/*  input boolean DmpVlvAct_bDgoHi_DmpVlvCmd;                                 */
/*  input boolean DmpVlvAct_bMonRunHi_DmpVlvCmd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlvAct_EveRst_DmpVlvCmd                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvAct_EveRst_DmpVlvCmd(void)
{
   DmpVlvCmd_vidDmpVlvCmdAplication();
   DmpVlvCmd_vidInitEveRst();
   GDGAR_vidGdu(GD_DFT_LO_DMPVLVCMD,
                DmpVlvAct_bDgoLo_DmpVlvCmd,
                DmpVlvAct_bMonRunLo_DmpVlvCmd,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_HI_DMPVLVCMD,
                DmpVlvAct_bDgoHi_DmpVlvCmd,
                DmpVlvAct_bMonRunHi_DmpVlvCmd,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvAct_SdlFast_DmpVlvCmd                                */
/* !Description :  Moniteur rapide pour la fonction DmpVlvAct                 */
/* !Number      :  SCH.2                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_01324_001.01                                     */
/*                 VEMS_E_10_01324_002.01                                     */
/*                 VEMS_E_10_01324_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DmpVlvCmd_vidDmpVlvCmdAplication();                      */
/*  extf argret void DmpVlvCmd_vidDiagnostic();                               */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 DmpVlvCmd_u8Inhib;                                            */
/*  input boolean DmpVlvAct_bDgoLo_DmpVlvCmd;                                 */
/*  input boolean DmpVlvAct_bMonRunLo_DmpVlvCmd;                              */
/*  input boolean DmpVlvAct_bDgoHi_DmpVlvCmd;                                 */
/*  input boolean DmpVlvAct_bMonRunHi_DmpVlvCmd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlvAct_SdlFast_DmpVlvCmd                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvAct_SdlFast_DmpVlvCmd(void)
{
   if (DmpVlvCmd_u8Inhib != 0x5A)
   {
      DmpVlvCmd_vidDmpVlvCmdAplication();
      DmpVlvCmd_vidDiagnostic();
      GDGAR_vidGdu(GD_DFT_LO_DMPVLVCMD,
                   DmpVlvAct_bDgoLo_DmpVlvCmd,
                   DmpVlvAct_bMonRunLo_DmpVlvCmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_HI_DMPVLVCMD,
                   DmpVlvAct_bDgoHi_DmpVlvCmd,
                   DmpVlvAct_bMonRunHi_DmpVlvCmd,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/