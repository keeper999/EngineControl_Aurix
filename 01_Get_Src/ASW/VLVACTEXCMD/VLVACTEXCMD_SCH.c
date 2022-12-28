/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXCMD                                             */
/* !Description     : VLVACTEXCMD component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXCMD                                             */
/* !Description     : DRIVER DE LA COMMANDE VVT ECHAPPEMENT                   */
/*                                                                            */
/* !File            : VLVACTEXCMD_SCH.C                                       */
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
/*   1 / VlvAct_EveRst_ExCmd                                                  */
/*   2 / VlvAct_SdlMid_ExCmd                                                  */
/*   3 / VlvAct_SdlFast_ExCmd                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6588622 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTEX/VLVACTEXCMD/VLVACT$*/
/* $Revision::   1.8      $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VLVACTEXCMD.h"
#include "VLVACTEXCMD_L.h"
#include "VLVACTEXCMD_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_ExCmd                                        */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05880_002.01                                     */
/*                 VEMS_R_08_05880_003.01                                     */
/*                 VEMS_R_08_05880_004.01                                     */
/*                 VEMS_R_08_05880_005.01                                     */
/*                 VEMS_R_08_05880_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCMD_vidInitOutput();                             */
/*  extf argret void VLVACTEXCMD_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_ExCmd                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_ExCmd(void)
{
   VLVACTEXCMD_vidInitOutput();
   VLVACTEXCMD_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlMid_ExCmd                                        */
/* !Description :  Moniteur moyen pour la fonction VVT                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05880_002.01                                     */
/*                 VEMS_R_08_05880_003.01                                     */
/*                 VEMS_R_08_05880_004.01                                     */
/*                 VEMS_R_08_05880_005.01                                     */
/*                 VEMS_R_08_05880_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCMD_vidEnablePwm();                              */
/*  input uint8 VLVACTEXCMD_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlMid_ExCmd                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlMid_ExCmd(void)
{
   if (VLVACTEXCMD_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXCMD_vidEnablePwm();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExCmd                                       */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05880_002.01                                     */
/*                 VEMS_R_08_05880_003.01                                     */
/*                 VEMS_R_08_05880_004.01                                     */
/*                 VEMS_R_08_05880_005.01                                     */
/*                 VEMS_R_08_05880_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCMD_vidBatteryComp();                            */
/*  extf argret void VLVACTEXCMD_vidPwmCommand();                             */
/*  extf argret void VLVACTEXCMD_vidDiagnostic();                             */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VLVACTEXCMD_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*  input boolean VlvAct_bDgoLoVlvActExDrv;                                   */
/*  input boolean VlvActIn_bMonRunLoVlvActExDrv;                              */
/*  input boolean VlvAct_bDgoHiVlvActExDrv;                                   */
/*  input boolean VlvActIn_bMonRunHiVlvActExDrv;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExCmd                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExCmd(void)
{
   if (VLVACTEXCMD_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXCMD_vidBatteryComp();
         VLVACTEXCMD_vidPwmCommand();
         VLVACTEXCMD_vidDiagnostic();
         GDGAR_vidGdu(GD_DFT_LOVLVACTEXDRV,
                      VlvAct_bDgoLoVlvActExDrv,
                      VlvActIn_bMonRunLoVlvActExDrv,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_HIVLVACTEXDRV,
                      VlvAct_bDgoHiVlvActExDrv,
                      VlvActIn_bMonRunHiVlvActExDrv,
                      DIAG_DISPO);
      }
   }
}
/*------------------------------- end of file --------------------------------*/