/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACPRESACQ                                               */
/* !Description     : ACPRESACQ component                                     */
/*                                                                            */
/* !Module          : ACPRESACQ                                               */
/* !Description     : ACQUISITION DE LA PRESSION DU FLUIDE REFRIGERANT        */
/*                                                                            */
/* !File            : ACPRESACQ_SCH.C                                         */
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
/*   1 / AC_EveRst_ACPresAcq                                                  */
/*   2 / AC_SdlFast_ACPresAcq                                                 */
/*   3 / AC_SdlMid_ACPresAcq                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6545428 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACPRESACQ/ACPRESACQ_SCH.C_v       $*/
/* $Revision::   1.4      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACPRESACQ.h"
#include "ACPRESACQ_L.h"
#include "ACPRESACQ_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_EveRst_ACPresAcq                                        */
/* !Description :  Fonction d'accroche à l'event AC_EveRst_ACPresAcq          */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_06201_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACPRESACQ_vidInitOutput();                               */
/*  extf argret void ACPRESACQ_vidInit();                                     */
/*  extf argret void ACPRESACQ_vidPressure_refri();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_EveRst_ACPresAcq                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_EveRst_ACPresAcq(void)
{
   ACPRESACQ_vidInitOutput();
   ACPRESACQ_vidInit();
   ACPRESACQ_vidPressure_refri();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_SdlFast_ACPresAcq                                       */
/* !Description :  Fonction d'accroche à l'event AC_SdlFast_ACPresAcq         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_06201_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACPRESACQ_vidPressure_refri();                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 ACPRESACQ_u8Inhib;                                            */
/*  input boolean Ext_bDgoHi_pACMes;                                          */
/*  input boolean Ext_bMonRunHi_pACMes;                                       */
/*  input boolean Ext_bDgoLo_pACMes;                                          */
/*  input boolean Ext_bMonRunLo_pACMes;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_SdlFast_ACPresAcq                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_SdlFast_ACPresAcq(void)
{
   if (ACPRESACQ_u8Inhib != 0x5A)
   {
      ACPRESACQ_vidPressure_refri();
      GDGAR_vidGdu(GD_DFT_HI_PACMES,
                   Ext_bDgoHi_pACMes,
                   Ext_bMonRunHi_pACMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_LO_PACMES,
                   Ext_bDgoLo_pACMes,
                   Ext_bMonRunLo_pACMes,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_SdlMid_ACPresAcq                                        */
/* !Description :  Fonction d'accroche à l'event AC_SdlMid_ACPresAcq          */
/* !Number      :  SCH.3                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_06201_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACPRESACQ_VidPressRefriDiagFunc();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 ACPRESACQ_u8Inhib;                                            */
/*  input boolean Ext_bDgoGrd_pACMes;                                         */
/*  input boolean Ext_bMonRunGrd_pACMes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_SdlMid_ACPresAcq                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_SdlMid_ACPresAcq(void)
{
   if (ACPRESACQ_u8Inhib != 0x5A)
   {
      ACPRESACQ_VidPressRefriDiagFunc();
      GDGAR_vidGdu(GD_DFT_GRD_PACMES,
                   Ext_bDgoGrd_pACMes,
                   Ext_bMonRunGrd_pACMes,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/