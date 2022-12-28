/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROPFUPMP                                               */
/* !Description     : PROPFUPMP component.                                    */
/*                                                                            */
/* !Module          : PROPFUPMP                                               */
/* !Description     : PROPORTIONAL FUEL PUMP COMMAND AND DIAGNOSIS            */
/*                                                                            */
/* !File            : PROPFUPMP_FCT2.C                                        */
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
/*   1 / PROPFUPMP_vidCmdPropFuPmpNull                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6562300 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/PROPFUPMP/PROPFUPMP_FCT2.C_v      $*/
/* $Revision::   1.0      $$Author::   hmelloul       $$Date::   02 Jun 2014 $*/
/* $Author::   hmelloul                               $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "PROPFUPMP.h"
#include "PROPFUPMP_L.h"
#include "PROPFUPMP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROPFUPMP_vidCmdPropFuPmpNull                              */
/* !Description :  When Ctrl_bAcv_FuTnkPmp = 0  a Null PWM command is sent.   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 FuPmp_rFlowFuTnkPmpDft_C;                                    */
/*  output uint16 Ext_rFlowFuTnkPmp;                                          */
/*  output uint16 Commande_pompe_ess_pwm;                                     */
/*  output uint8 Ext_stDftFuTnkPmp;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROPFUPMP_vidCmdPropFuPmpNull(void)
{
   uint16  u16LocalExt_rFlowFuTnkPmp;


   u16LocalExt_rFlowFuTnkPmp = (uint16)MATHSRV_udtMIN(FuPmp_rFlowFuTnkPmpDft_C,
                                                      32768);
   VEMS_vidSET(Ext_rFlowFuTnkPmp, u16LocalExt_rFlowFuTnkPmp);
   VEMS_vidSET(Commande_pompe_ess_pwm, u16LocalExt_rFlowFuTnkPmp);
   VEMS_vidSET(Ext_stDftFuTnkPmp, 0);
}
/*-------------------------------- end of file -------------------------------*/