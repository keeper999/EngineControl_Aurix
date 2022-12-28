/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FCTDIAGDMPVLV                                           */
/* !Description     : FCTDIAGDMPVLV Component                                 */
/*                                                                            */
/* !Module          : FCTDIAGDMPVLV                                           */
/* !Description     : Dump Valve Functional Diagnosis                         */
/*                                                                            */
/* !File            : FCTDIAGDMPVLV_SCH.C                                     */
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
/*   1 / DmpVlv_EveRst_FctDiagDmpVlv                                          */
/*   2 / DmpVlv_Eve14TDC_FctDiagDmpVlv                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5068534 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#065849                                         */
/* !OtherRefs   : VEMS V02 ECU#066089                                         */
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
#include "FCTDIAGDMPVLV.h"
#include "FCTDIAGDMPVLV_L.h"
#include "FCTDIAGDMPVLV_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlv_EveRst_FctDiagDmpVlv                                */
/* !Description :  Reset event for the ECU                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGDMPVLV_vidInitOutput();                           */
/*  extf argret void FCTDIAGDMPVLV_vidInit();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlv_EveRst_FctDiagDmpVlv                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlv_EveRst_FctDiagDmpVlv(void)
{
   FCTDIAGDMPVLV_vidInitOutput();
   FCTDIAGDMPVLV_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlv_Eve14TDC_FctDiagDmpVlv                              */
/* !Description :  A Quarter TDC crankshaft angular based event               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGDMPVLV_vidDmpVlvCls();                            */
/*  extf argret void FCTDIAGDMPVLV_vidDmpVlv_Op();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 FCTDIAGDMPVLV_u8Inhib;                                        */
/*  input boolean DmpVlv_bDgoStuckCls_DmpVlv;                                 */
/*  input boolean DmpVlv_bMonRunStuckCls_DmpVlv;                              */
/*  input boolean DmpVlv_bDgoStuckOp_DmpVlv;                                  */
/*  input boolean DmpVlv_bMonRunStuckOp_DmpVlv;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlv_Eve14TDC_FctDiagDmpVlv                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlv_Eve14TDC_FctDiagDmpVlv(void)
{
   if (FCTDIAGDMPVLV_u8Inhib != 0x5A)
   {
      FCTDIAGDMPVLV_vidDmpVlvCls();
      FCTDIAGDMPVLV_vidDmpVlv_Op();
      GDGAR_vidGdu(GD_DFT_STUCKCLS_DMPVLV,
                   DmpVlv_bDgoStuckCls_DmpVlv,
                   DmpVlv_bMonRunStuckCls_DmpVlv,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_STUCKOP_DMPVLV,
                   DmpVlv_bDgoStuckOp_DmpVlv,
                   DmpVlv_bMonRunStuckOp_DmpVlv,
                   DIAG_DISPO);
   }
}
/*------------------------------ end of file ---------------------------------*/