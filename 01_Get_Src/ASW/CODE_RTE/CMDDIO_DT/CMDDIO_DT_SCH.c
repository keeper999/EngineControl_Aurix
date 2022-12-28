/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CMDDIO_DT                                               */
/* !Description     : CMDDIO_DT Component.                                    */
/*                                                                            */
/* !Module          : CMDDIO_DT                                               */
/* !Description     :  SPECIFICATION OF LOGICAL COMMANDS (DIOHAL) SENT TO BSW */
/*                                                                            */
/* !File            : CMDDIO_DT_SCH.C                                         */
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
/*   1 / AC_EveRst_CmdDio                                                     */
/*   2 / AC_SdlSlow_CmdDio                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_6913275 / 01                                        */
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

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "CMDDIO_DT_IM.h"
#include "CMDDIO_DT.h"
#include "CMDDIO_DT_L.h"
#include "CMDDIO_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_EveRst_CmdDio                                           */
/* !Description :  Reset event for additional heating command                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDDIO_DT_vidCmdDio_CTP1();                              */
/*  extf argret void CMDDIO_DT_vidCmdDio_CTP2();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_EveRst_CmdDio                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_EveRst_CmdDio(void)
{
   CMDDIO_DT_vidCmdDio_CTP1();
   CMDDIO_DT_vidCmdDio_CTP2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_SdlSlow_CmdDio                                          */
/* !Description :  Slow monitoring for additional heating command function.   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CMDDIO_DT_vidCmdDio_CTP1();                              */
/*  extf argret void CMDDIO_DT_vidCmdDio_CTP2();                              */
/*  input boolean Ctrl_bTreatAdHeatRly;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 CMDDIO_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_SdlSlow_CmdDio                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_SdlSlow_CmdDio(void)
{
   boolean bLocalCtrl_bTreatAdHeatRly;
   boolean bLocalECU_bWkuMain;


   if (CMDDIO_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bTreatAdHeatRly, bLocalCtrl_bTreatAdHeatRly);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

      if (  (bLocalCtrl_bTreatAdHeatRly != 0)
         && (bLocalECU_bWkuMain != 0))
      {
         CMDDIO_DT_vidCmdDio_CTP1();
         CMDDIO_DT_vidCmdDio_CTP2();
      }
   }
}
/*---------------------------- end of file -----------------------------------*/