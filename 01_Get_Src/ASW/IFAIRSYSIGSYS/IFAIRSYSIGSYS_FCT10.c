/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_FCT10.C                                   */
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
/*   1 / IFAIRSYSIGSYS_vidOutMaxPrevAdpCy                                     */
/*   2 / IFAIRSYSIGSYS_vidOutInjCutOffPtl                                     */
/*   3 / IFAIRSYSIGSYS_vidOutEngStopAuth                                      */
/*   4 / IFAIRSYSIGSYS_vidOutput_tFuMes                                       */
/*   5 / IFAIRSYSIGSYS_vidOutput_tiAst                                        */
/*   6 / IFAIRSYSIGSYS_vidOutbCtlPmpReq                                       */
/*   7 / IFAIRSYSIGSYS_vidOutputObdSrv                                        */
/*   8 / IFAIRSYSIGSYS_vidOutfacVlvOvlp                                       */
/*   9 / IFAIRSYSIGSYS_vidKnk                                                 */
/*   10 / IFAIRSYSIGSYS_vidMFuTranCor                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
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
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutMaxPrevAdpCy                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 IgSys_prm_agIgMaxWiPrevAdpCy.                              */
/* !Number      :  FCT10.1                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint8 IgSys_prm_agIgMaxWiPrevAdpCyl[6];                             */
/*  output uint8 IgSys_prm_agIgMaxWiPrevAdpCy[6];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutMaxPrevAdpCy(void)
{
   /*F02_Output_prm_agIgMaxWiPrevAdpCy */
   uint8  u8LocalIdx;
   uint8  u8LocalIgMaxWiPrevAdpCyl;


   for (u8LocalIdx = 0; u8LocalIdx < 6; u8LocalIdx++)
   {
      VEMS_vidGET1DArrayElement(IgSys_prm_agIgMaxWiPrevAdpCyl,
                                u8LocalIdx,
                                u8LocalIgMaxWiPrevAdpCyl);
      VEMS_vidSET1DArrayElement(IgSys_prm_agIgMaxWiPrevAdpCy,
                                u8LocalIdx,
                                u8LocalIgMaxWiPrevAdpCyl);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutInjCutOffPtl                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 KnkMgt_prm_ctRblInjCutOffPtl.                              */
/* !Number      :  FCT10.2                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 KnkMgt_ctInjCutOffRbl[4];                                    */
/*  output uint8 KnkMgt_prm_ctRblInjCutOffPtl[6];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutInjCutOffPtl(void)
{
   /*F03_Output_prm_ctRblInjCutOffPtl */
   uint8  u8LocalIdx;
   uint8  u8LocalKnkMgt_ctInjCutOffRbl;
   uint16 u16LocalKnkMgt_ctInjCutOffRbl;


   for (u8LocalIdx = 0; u8LocalIdx < 4; u8LocalIdx++)
   {
      VEMS_vidGET1DArrayElement(KnkMgt_ctInjCutOffRbl,
                                u8LocalIdx,
                                u16LocalKnkMgt_ctInjCutOffRbl);
      u8LocalKnkMgt_ctInjCutOffRbl =
         (uint8)MATHSRV_udtMIN(u16LocalKnkMgt_ctInjCutOffRbl, 255);
      VEMS_vidSET1DArrayElement(KnkMgt_prm_ctRblInjCutOffPtl,
                                u8LocalIdx,
                                u8LocalKnkMgt_ctInjCutOffRbl);
   }
   VEMS_vidSET1DArrayElement(KnkMgt_prm_ctRblInjCutOffPtl, 4, 0);
   VEMS_vidSET1DArrayElement(KnkMgt_prm_ctRblInjCutOffPtl, 5, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutEngStopAuth                            */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 CoReqStg_stEngStopAuth.                                    */
/* !Number      :  FCT10.3                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoReqStg_bEngStopAuth;                                      */
/*  output uint8 CoReqStg_stEngStopAuth;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutEngStopAuth(void)
{
   /*F04_Output_stEngStopAuth */
   boolean bLocalCoReqStg_bEngStopAuth;


   VEMS_vidGET(CoReqStg_bEngStopAuth, bLocalCoReqStg_bEngStopAuth);
   if (bLocalCoReqStg_bEngStopAuth == 1)
   {
      VEMS_vidSET(CoReqStg_stEngStopAuth, 1);
   }
   else
   {
      VEMS_vidSET(CoReqStg_stEngStopAuth, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_tFuMes                             */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_tFuMes.                                                */
/* !Number      :  FCT10.4                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 FuSysM_tFu;                                                  */
/*  input uint8 FuSysM_tFuUsPmp;                                              */
/*  output sint16 Ext_tFuMes;                                                 */
/*  output sint16 Ext_tFuRailMes;                                             */
/*  output sint16 Ext_tFuUsPmpMes;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_tFuMes(void)
{
   /*F05_Output_tFuMes */
   uint8  u8LocalFuSysM_tFuUsPmp;
   uint16 u16LocalFuSysM_tFu;
   sint16 s16LocalFuSysM_tFu;
   sint16 s16LocalExt_tFuUsPmpMes;
   sint32 s32LocalFuSysM_tFu;


   VEMS_vidGET(FuSysM_tFu, u16LocalFuSysM_tFu);
   s32LocalFuSysM_tFu = (sint32)(u16LocalFuSysM_tFu - 40);
   s16LocalFuSysM_tFu =
      (sint16)MATHSRV_udtMIN(s32LocalFuSysM_tFu, 214);
   VEMS_vidSET(Ext_tFuMes, s16LocalFuSysM_tFu);
   VEMS_vidSET(Ext_tFuRailMes, s16LocalFuSysM_tFu);

   VEMS_vidGET(FuSysM_tFuUsPmp, u8LocalFuSysM_tFuUsPmp);
   s16LocalExt_tFuUsPmpMes = (sint16)(u8LocalFuSysM_tFuUsPmp - 40);
   s16LocalExt_tFuUsPmpMes = (sint16)MATHSRV_udtMIN(s16LocalExt_tFuUsPmpMes,
                                                    214);
   VEMS_vidSET(Ext_tFuUsPmpMes, s16LocalExt_tFuUsPmpMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_tiAst                              */
/* !Description :  Fonction qui permet la production de la variable Ext_tiAst.*/
/* !Number      :  FCT10.5                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 EOM_tiEngRun;                                                */
/*  output uint32 Ext_tiAst;                                                  */
/*  output uint16 Ext_tiStrt;                                                 */
/*  output uint32 Ext_tiAstTot;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_tiAst(void)
{
   /*F06_Output_tiAst */
   uint16  u16LocalExt_tiStrt;
   uint32  u32LocalEOM_tiEngRun;
   uint32  u32LocalExt_tiStrt;


   VEMS_vidGET(EOM_tiEngRun, u32LocalEOM_tiEngRun);
   u32LocalExt_tiStrt = ((u32LocalEOM_tiEngRun * 125) + 64) / 128;
   u32LocalEOM_tiEngRun = MATHSRV_udtMIN(u32LocalEOM_tiEngRun, 43000000);
   VEMS_vidSET(Ext_tiAst, u32LocalEOM_tiEngRun);
   u16LocalExt_tiStrt = (uint16)MATHSRV_udtMIN(u32LocalExt_tiStrt, 65535);
   VEMS_vidSET(Ext_tiStrt, u16LocalExt_tiStrt);
   VEMS_vidSET(Ext_tiAstTot, u32LocalEOM_tiEngRun);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutbCtlPmpReq                             */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 IgCmd_bCtlPmpReqTstCmpl.                                   */
/* !Number      :  FCT10.6                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Oil_bCtlPmpTstCmpl;                                         */
/*  output boolean IgCmd_bCtlPmpReqTstCmpl;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutbCtlPmpReq(void)
{
   /* F04_Output_bCtlPmpReq */
   boolean  bLocalOil_bCtlPmpTstCmpl;


   VEMS_vidGET(Oil_bCtlPmpTstCmpl, bLocalOil_bCtlPmpTstCmpl);
   VEMS_vidSET(IgCmd_bCtlPmpReqTstCmpl, bLocalOil_bCtlPmpTstCmpl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputObdSrv                              */
/* !Description :  Output ObdSrv                                              */
/* !Number      :  FCT10.7                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ctrl_VDS_BSI_492;                                           */
/*  input boolean Ctrl_VIS_BSI_4B2;                                           */
/*  input boolean Ctrl_WMI_BSI_4D2;                                           */
/*  output boolean Ctrl_IS_VIN_VDS_BSI_492;                                   */
/*  output boolean Ctrl_IS_VIN_VIS_BSI_4B2;                                   */
/*  output boolean Ctrl_IS_VIN_WMI_BSI_4D2;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputObdSrv(void)
{
   /* f01_Output_ObdSrv */
   boolean bLocalCtrl_VDS_BSI_492;
   boolean bLocalCtrl_VIS_BSI_4B2;
   boolean bLocalCtrl_WMI_BSI_4D2;

   VEMS_vidGET(Ctrl_VDS_BSI_492, bLocalCtrl_VDS_BSI_492);
   VEMS_vidGET(Ctrl_VIS_BSI_4B2, bLocalCtrl_VIS_BSI_4B2);
   VEMS_vidGET(Ctrl_WMI_BSI_4D2, bLocalCtrl_WMI_BSI_4D2);
   VEMS_vidSET(Ctrl_IS_VIN_VDS_BSI_492, bLocalCtrl_VDS_BSI_492);
   VEMS_vidSET(Ctrl_IS_VIN_VIS_BSI_4B2, bLocalCtrl_VIS_BSI_4B2);
   VEMS_vidSET(Ctrl_IS_VIN_WMI_BSI_4D2, bLocalCtrl_WMI_BSI_4D2);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutfacVlvOvlp                             */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 InM_pDsThr_facVlvOvlp.                                     */
/* !Number      :  FCT10.8                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 InM_pDsThrPred_facVlvOvlp;                                   */
/*  output uint16 InM_pDsThr_facVlvOvlp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutfacVlvOvlp(void)
{
   /* F08_Output_facVlvOvlp */
   uint16  u16LocalInM_pDsThrPredfacVlvOvlp;


   VEMS_vidGET(InM_pDsThrPred_facVlvOvlp, u16LocalInM_pDsThrPredfacVlvOvlp);
   VEMS_vidSET(InM_pDsThr_facVlvOvlp, u16LocalInM_pDsThrPredfacVlvOvlp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidKnk                                       */
/* !Description :  cette fonction permet d'interfacer  KnkMgt_bAcvKnkReg avec */
/*                 Zone_Critique.                                             */
/* !Number      :  FCT10.9                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Zone_critique;                                              */
/*  output boolean KnkMgt_bAcvKnkReg;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidKnk(void)
{
   /*F08_Knk*/
   boolean  bLocalZone_critique;


   VEMS_vidGET(Zone_critique, bLocalZone_critique);
   VEMS_vidSET(KnkMgt_bAcvKnkReg, bLocalZone_critique);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidMFuTranCor                                */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 InjSys_prm_facTranCmpCyl                                   */
/* !Number      :  FCT10.10                                                   */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input boolean InjSys_bAcvWfCmp;                                           */
/*  input uint16 InjSys_facFuTranCor;                                         */
/*  input uint16 InjSys_prm_facTranCmpCylRaw[6];                              */
/*  output uint16 InjSys_prm_facTranCmpCyl[6];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidMFuTranCor(void)
{
   /*08_MFuTranCor*/
   boolean bLocalInjSys_bAcvWfCmp;
   uint8   u8LocalIdx;
   uint16  u16LocalInjSys_facFuTranCor;
   uint16  u16LocalInjSys_prm_facTrCmpCyRaw;
   uint16  u16LocalInjSys_prm_facTranCmpCyl;
   uint32  u32LocalResult;

   VEMS_vidGET(InjSys_bAcvWfCmp, bLocalInjSys_bAcvWfCmp);
   if (bLocalInjSys_bAcvWfCmp != 0)
   {
      VEMS_vidGET(InjSys_facFuTranCor, u16LocalInjSys_facFuTranCor);
   }
   else
   {
      u16LocalInjSys_facFuTranCor = 1000;
   }
   for (u8LocalIdx = 0; u8LocalIdx < 6; u8LocalIdx++)
   {
      VEMS_vidGET1DArrayElement(InjSys_prm_facTranCmpCylRaw,
                                u8LocalIdx,
                                u16LocalInjSys_prm_facTrCmpCyRaw);
      u32LocalResult = (uint32) ( ( ( u16LocalInjSys_facFuTranCor
                                    * u16LocalInjSys_prm_facTrCmpCyRaw)
                                  + 500)
                                / 1000);
      u16LocalInjSys_prm_facTranCmpCyl =
         (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
      VEMS_vidSET1DArrayElement(InjSys_prm_facTranCmpCyl,
                                u8LocalIdx,
                                u16LocalInjSys_prm_facTranCmpCyl);
   }
}
/*-------------------------------- end of file -------------------------------*/