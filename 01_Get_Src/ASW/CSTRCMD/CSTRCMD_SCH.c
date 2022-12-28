/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRCMD                                                 */
/* !Description     : CSTRCMD component.                                      */
/*                                                                            */
/* !Module          : CSTRCMD                                                 */
/* !Description     : STRATEGIE COMMANDE DE L’ELECTROVANNE PURGE CANISTER     */
/*                                                                            */
/* !File            : CSTRCMD_SCH.C                                           */
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
/*   1 / Cstr_EveRst_CstrCmd                                                  */
/*   2 / Cstr_SdlMid_CstrCmd                                                  */
/*   3 / Cstr_SdlFast_CstrCmd                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6562479 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTRCMD/CSTRCMD_SCH.C_v           $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   15 May 2014 $*/
/* $Author::   wbouach                                $$Date::   15 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CSTRCMD.h"
#include "CSTRCMD_L.h"
#include "CSTRCMD_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveRst_CstrCmd                                        */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_09_01860_001.01                                     */
/*                 VEMS_R_09_01860_002.01                                     */
/*                 VEMS_R_09_01860_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRCMD_vidInitOutput();                                 */
/*  extf argret void CSTRCMD_vidCmd();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveRst_CstrCmd                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveRst_CstrCmd(void)
{
   CSTRCMD_vidInitOutput();
   CSTRCMD_vidCmd();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlMid_CstrCmd                                        */
/* !Description :  Moniteur moyen pour la fonction purge canister             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_09_01860_001.01                                     */
/*                 VEMS_R_09_01860_002.01                                     */
/*                 VEMS_R_09_01860_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRCMD_vidCmd();                                        */
/*  input uint8 CSTRCMD_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlMid_CstrCmd                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlMid_CstrCmd(void)
{
   if (CSTRCMD_u8Inhib != 0x5A)
   {
      CSTRCMD_vidCmd();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlFast_CstrCmd                                       */
/* !Description :  Moniteur rapide pour la fonction purge canister            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_09_01860_001.01                                     */
/*                 VEMS_R_09_01860_002.01                                     */
/*                 VEMS_R_09_01860_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRCMD_vidDiag();                                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 CSTRCMD_u8Inhib;                                              */
/*  input boolean Cstr_bDgoLoCstrDrv;                                         */
/*  input boolean Cstr_bMonRunLoCstrDrv;                                      */
/*  input boolean Cstr_bDgoHiCstrDrv;                                         */
/*  input boolean Cstr_bMonRunHiCstrDrv;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlFast_CstrCmd                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlFast_CstrCmd(void)
{
   if (CSTRCMD_u8Inhib != 0x5A)
   {
      CSTRCMD_vidDiag();
      GDGAR_vidGdu(GD_DFT_LOCSTRDRV,
                   Cstr_bDgoLoCstrDrv,
                   Cstr_bMonRunLoCstrDrv,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_HICSTRDRV,
                   Cstr_bDgoHiCstrDrv,
                   Cstr_bMonRunHiCstrDrv,
                   DIAG_DISPO);
   }
}
/*------------------------------- End of file --------------------------------*/