/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINCMD                                             */
/* !Description     : VLVACTINCMD component.                                  */
/*                                                                            */
/* !Module          : VLVACTINCMD                                             */
/* !Description     : DRIVER DE LA COMMANDE VVT ADMISSION                     */
/*                                                                            */
/* !File            : VLVACTINCMD_SCH.C                                       */
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
/*   1 / VlvAct_EveRst_InCmd                                                  */
/*   2 / VlvAct_SdlMid_InCmd                                                  */
/*   3 / VlvAct_SdlFast_InCmd                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6588664 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTIN/VLVACTINCMD/VLVACT$*/
/* $Revision::   1.7      $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINCMD.h"
#include "VLVACTINCMD_L.h"
#include "VLVACTINCMD_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_InCmd                                        */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05879_002.01                                     */
/*                 VEMS_R_08_05879_003.01                                     */
/*                 VEMS_R_08_05879_004.01                                     */
/*                 VEMS_R_08_05879_007.01                                     */
/*                 VEMS_R_08_05879_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCMD_vidInitOutput();                             */
/*  extf argret void VLVACTINCMD_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_InCmd                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_InCmd(void)
{
   VLVACTINCMD_vidInitOutput();
   VLVACTINCMD_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlMid_InCmd                                        */
/* !Description :  Moniteur moyen pour la fonction VVT                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05879_002.01                                     */
/*                 VEMS_R_08_05879_003.01                                     */
/*                 VEMS_R_08_05879_004.01                                     */
/*                 VEMS_R_08_05879_007.01                                     */
/*                 VEMS_R_08_05879_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCMD_vidEnablePwm();                              */
/*  input uint8 VLVACTINCMD_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlMid_InCmd                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlMid_InCmd(void)
{
   if (VLVACTINCMD_u8Inhib != 0x5A)
   {
      if(VlvAct_bAcvVlvActInStr_C!= 0)
      {
         VLVACTINCMD_vidEnablePwm();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InCmd                                       */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_05879_002.01                                     */
/*                 VEMS_R_08_05879_003.01                                     */
/*                 VEMS_R_08_05879_004.01                                     */
/*                 VEMS_R_08_05879_007.01                                     */
/*                 VEMS_R_08_05879_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCMD_vidBatteryComp();                            */
/*  extf argret void VLVACTINCMD_vidPwmCommand();                             */
/*  extf argret void VLVACTINCMD_vidDiagnostic();                             */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VLVACTINCMD_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*  input boolean VlvAct_bDgoLoVlvActInDrv;                                   */
/*  input boolean VlvActIn_bMonRunLoVlvActInDrv;                              */
/*  input boolean VlvAct_bDgoHiVlvActInDrv;                                   */
/*  input boolean VlvActIn_bMonRunHiVlvActInDrv;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InCmd                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InCmd(void)
{
   if (VLVACTINCMD_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINCMD_vidBatteryComp();
         VLVACTINCMD_vidPwmCommand();
         VLVACTINCMD_vidDiagnostic();
         GDGAR_vidGdu(GD_DFT_LOVLVACTINDRV,
                      VlvAct_bDgoLoVlvActInDrv,
                      VlvActIn_bMonRunLoVlvActInDrv,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_HIVLVACTINDRV,
                      VlvAct_bDgoHiVlvActInDrv,
                      VlvActIn_bMonRunHiVlvActInDrv,
                      DIAG_DISPO);
      }
   }
}
/*------------------------------- end of file --------------------------------*/