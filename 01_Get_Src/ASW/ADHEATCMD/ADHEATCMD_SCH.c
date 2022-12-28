/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADHEATCMD                                               */
/* !Description     : ADHEATCMD Component                                     */
/*                                                                            */
/* !Module          : ADHEATCMD                                               */
/* !Description     : CTP additional heaters command and diagnosis            */
/*                                                                            */
/* !File            : ADHEATCMD_SCH.C                                         */
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
/*   1 / AC_EveRst_AdHeatCmd                                                  */
/*   2 / AC_SdlSlow_AdHeatCmd                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6851368 / 01                                        */
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
#include "ADHEATCMD.h"
#include "ADHEATCMD_L.h"
#include "ADHEATCMD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_EveRst_AdHeatCmd                                        */
/* !Description :  Reset event for additional heating command                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_12_04449_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADHEATCMD_vidInit();                                     */
/*  extf argret void ADHEATCMD_vidCmdCTP1();                                  */
/*  extf argret void ADHEATCMD_vidCmdCTP2();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_EveRst_AdHeatCmd                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_EveRst_AdHeatCmd(void)
{
   ADHEATCMD_vidInit();
   ADHEATCMD_vidCmdCTP1();
   ADHEATCMD_vidCmdCTP2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_SdlSlow_AdHeatCmd                                       */
/* !Description :  Slow monitoring for additional heating command function    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_12_04449_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ADHEATCMD_vidAdHeatCmdCalc();                            */
/*  extf argret void ADHEATCMD_vidCmdCTP1();                                  */
/*  extf argret void ADHEATCMD_vidCmdCTP2();                                  */
/*  extf argret void ADHEATCMD_vidDiagCTP1();                                 */
/*  extf argret void ADHEATCMD_vidDiagCTP2();                                 */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 ADHEATCMD_u8Inhib;                                            */
/*  input boolean Ctrl_bTreatAdHeatRly;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean AC_bDgoScg_CTP1;                                            */
/*  input boolean AC_bMonRunScg_CTP1;                                         */
/*  input boolean AC_bDgoScp_CTP1;                                            */
/*  input boolean AC_bMonRunScp_CTP1;                                         */
/*  input boolean AC_bDgoOc_CTP1;                                             */
/*  input boolean AC_bMonRunOc_CTP1;                                          */
/*  input boolean AC_bDgoScg_CTP2;                                            */
/*  input boolean AC_bMonRunScg_CTP2;                                         */
/*  input boolean AC_bDgoScp_CTP2;                                            */
/*  input boolean AC_bMonRunScp_CTP2;                                         */
/*  input boolean AC_bDgoOc_CTP2;                                             */
/*  input boolean AC_bMonRunOc_CTP2;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_SdlSlow_AdHeatCmd                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_SdlSlow_AdHeatCmd(void)
{
   boolean   bLocalCtrl_bTreatAdHeatRly;
   boolean   bLocalECU_bWkuMain;

   if (ADHEATCMD_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bTreatAdHeatRly, bLocalCtrl_bTreatAdHeatRly);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

      if (  (bLocalCtrl_bTreatAdHeatRly !=0)
         && (bLocalECU_bWkuMain !=0))
      {
         ADHEATCMD_vidAdHeatCmdCalc();
         ADHEATCMD_vidCmdCTP1();
         ADHEATCMD_vidCmdCTP2();
         ADHEATCMD_vidDiagCTP1();
         ADHEATCMD_vidDiagCTP2();
         GDGAR_vidGdu(GD_DFT_SCG_CTP1,
                      AC_bDgoScg_CTP1,
                      AC_bMonRunScg_CTP1,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_SCP_CTP1,
                      AC_bDgoScp_CTP1,
                      AC_bMonRunScp_CTP1,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_OC_CTP1,
                      AC_bDgoOc_CTP1,
                      AC_bMonRunOc_CTP1,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_SCG_CTP2,
                      AC_bDgoScg_CTP2,
                      AC_bMonRunScg_CTP2,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_SCP_CTP2,
                      AC_bDgoScp_CTP2,
                      AC_bMonRunScp_CTP2,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_OC_CTP2,
                      AC_bDgoOc_CTP2,
                      AC_bMonRunOc_CTP2,
                      DIAG_DISPO);
      }
   }
}