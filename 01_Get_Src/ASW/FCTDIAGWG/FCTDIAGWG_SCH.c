/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FCTDIAGWG                                               */
/* !Description     : FCTDIAGWG component                                     */
/*                                                                            */
/* !Module          : FCTDIAGWG                                               */
/* !Description     : FUNCTIONAL DIAGNOSIS OF WASTEGATE                       */
/*                                                                            */
/* !File            : FCTDIAGWG_SCH.C                                         */
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
/*   1 / Wg_EveRst_FctDiagWg                                                  */
/*   2 / Wg_SdlFast_FctDiagWg                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5070705 / 03                                        */
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
#include "FCTDIAGWG.h"
#include "FCTDIAGWG_L.h"
#include "FCTDIAGWG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_EveRst_FctDiagWg                                        */
/* !Description :  Reset event for the ECU                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_E_11_02722_005.01                                     */
/*                 VEMS_E_11_02722_006.01                                     */
/*                 VEMS_E_11_02722_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGWG_vidInitOutput();                               */
/*  extf argret void FCTDIAGWG_vidInit();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_EveRst_FctDiagWg                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_EveRst_FctDiagWg(void)
{
   FCTDIAGWG_vidInitOutput();
   FCTDIAGWG_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_SdlFast_FctDiagWg                                       */
/* !Description :  Fast monitoring for Waste Gate function                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_E_11_02722_005.01                                     */
/*                 VEMS_E_11_02722_006.01                                     */
/*                 VEMS_E_11_02722_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGWG_vidClcpUsThrNat();                             */
/*  extf argret void FCTDIAGWG_vidCls_pTrbAct();                              */
/*  extf argret void FCTDIAGWG_vidOp_pTrbAct();                               */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean  bDiagStWait);                        */
/*  input uint8 FCTDIAGWG_u8Inhib;                                            */
/*  input boolean Wg_bDgoStuckCls_pTrbAct;                                    */
/*  input boolean Wg_bMonRunStuckCls_pTrbAct;                                 */
/*  input boolean Wg_bDgoStuckOp_pTrbAct;                                     */
/*  input boolean Wg_bMonRunStuckOp_pTrbAct;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_SdlFast_FctDiagWg                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_SdlFast_FctDiagWg(void)
{
   if (FCTDIAGWG_u8Inhib != 0x5A)
   {
      FCTDIAGWG_vidClcpUsThrNat();
      FCTDIAGWG_vidCls_pTrbAct();
      FCTDIAGWG_vidOp_pTrbAct();
      GDGAR_vidGdu(GD_DFT_STUCKCLS_PTRBACT,
                   Wg_bDgoStuckCls_pTrbAct,
                   Wg_bMonRunStuckCls_pTrbAct,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_STUCKOP_PTRBACT,
                   Wg_bDgoStuckOp_pTrbAct,
                   Wg_bMonRunStuckOp_pTrbAct,
                   DIAG_DISPO);
   }
}
/*-------------------------------end of file----------------------------------*/