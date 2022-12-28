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
/* !File            : IFAIRSYSIGSYS_FCT5.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidIntfacIsCanIf1                                      */
/*   2 / IFAIRSYSIGSYS_vidIntfacIsCanIf2                                      */
/*   3 / IFAIRSYSIGSYS_vidOutputThMgt                                         */
/*   4 / IFAIRSYSIGSYS_vidIntfacIsCanIf17                                     */
/*   5 / IFAIRSYSIGSYS_vidIntfacIsCanIf5                                      */
/*   6 / IFAIRSYSIGSYS_vidOutAtmphPress                                       */
/*   7 / IFAIRSYSIGSYS_vidOutOCHeatPhaReq                                     */
/*   8 / IFAIRSYSIGSYS_vidSTTIf                                               */
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
                                     temp.mde producing this kind of error   */
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidIntfacIsCanIf1                            */
/* !Description :  Interface function for VSCtl_bVSLimReg                     */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VSCtl_bVSCtlDft;                                            */
/*  output boolean VSCtl_bVSLimReg;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidIntfacIsCanIf1(void)
{
   /*f1_interfacing_IsCanIf */
   boolean bLocalVSCtl_bVSCtlDft;


   VEMS_vidGET(VSCtl_bVSCtlDft, bLocalVSCtl_bVSCtlDft);
   VEMS_vidSET(VSCtl_bVSLimReg, bLocalVSCtl_bVSCtlDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidIntfacIsCanIf2                            */
/* !Description :  Interface function for CsCtl_stVSReg                       */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ctrl_bTraNoTarGear;                                         */
/*  input sint8 Tra_noTarGear_F349;                                           */
/*  input sint8 Tra_noTarGear_F3C9;                                           */
/*  output sint8 Tra_noTarGear;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidIntfacIsCanIf2(void)
{
   /*f2_interfacing_IsCanIf */
   boolean bLocalCtrl_bTraNoTarGear;
   sint8   s8LocalTra_noTarGear_F349;
   sint8   s8LocalTra_noTarGear_F3C9;


   VEMS_vidGET(Ctrl_bTraNoTarGear, bLocalCtrl_bTraNoTarGear);
   if (bLocalCtrl_bTraNoTarGear != 0)
   {
      VEMS_vidGET(Tra_noTarGear_F349, s8LocalTra_noTarGear_F349);
      s8LocalTra_noTarGear_F349 =
         (sint8)MATHSRV_udtCLAMP(s8LocalTra_noTarGear_F349, -1, 9);
      VEMS_vidSET(Tra_noTarGear, s8LocalTra_noTarGear_F349);
   }
   else
   {
      VEMS_vidGET(Tra_noTarGear_F3C9, s8LocalTra_noTarGear_F3C9);
      s8LocalTra_noTarGear_F3C9 =
         (sint8)MATHSRV_udtCLAMP(s8LocalTra_noTarGear_F3C9, -1, 9);
      VEMS_vidSET(Tra_noTarGear, s8LocalTra_noTarGear_F3C9);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputThMgt                               */
/* !Description :  Fonction qui permet la production des variables            */
/*                 ThMgt_bWarn_tCo et ThMgt_bPwrHldReq.                       */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ThMgt_bTCoWarnReq;                                          */
/*  input boolean ThMgt_bPwrHldMainFanReq;                                    */
/*  input boolean ThMgt_bPwrHldAdFanReq;                                      */
/*  input boolean ThMgt_bPwrHldCoVlvReq;                                      */
/*  input boolean ThMgt_bPwrHldFSFReq;                                        */
/*  output boolean ThMgt_bWarn_tCo;                                           */
/*  output boolean ThMgt_bPwrHldReq;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputThMgt(void)
{
   /* F18_Output_ThMgt */
   boolean  bLocalThMgt_bTCoWarnReq;
   boolean  bLocalThMgt_bPwrHldMainFanReq;
   boolean  bLocalThMgt_bPwrHldAdFanReq;
   boolean  bLocalThMgt_bPwrHldCoVlvReq;
   boolean  bLocalThMgt_bPwrHldFSFReq;
   boolean  bLocalThMgt_bPwrHldReq;


   VEMS_vidGET(ThMgt_bTCoWarnReq, bLocalThMgt_bTCoWarnReq);
   VEMS_vidSET(ThMgt_bWarn_tCo, bLocalThMgt_bTCoWarnReq);

   VEMS_vidGET(ThMgt_bPwrHldMainFanReq, bLocalThMgt_bPwrHldMainFanReq);
   VEMS_vidGET(ThMgt_bPwrHldAdFanReq, bLocalThMgt_bPwrHldAdFanReq);
   VEMS_vidGET(ThMgt_bPwrHldCoVlvReq, bLocalThMgt_bPwrHldCoVlvReq);
   VEMS_vidGET(ThMgt_bPwrHldFSFReq, bLocalThMgt_bPwrHldFSFReq);
   if (  (bLocalThMgt_bPwrHldMainFanReq != 0)
      || (bLocalThMgt_bPwrHldAdFanReq != 0)
      || (bLocalThMgt_bPwrHldCoVlvReq != 0)
      || (bLocalThMgt_bPwrHldFSFReq != 0))
   {
      bLocalThMgt_bPwrHldReq = 1;
   }
   else
   {
      bLocalThMgt_bPwrHldReq = 0;
   }
   VEMS_vidSET(ThMgt_bPwrHldReq, bLocalThMgt_bPwrHldReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidIntfacIsCanIf17                           */
/* !Description :  Fonction appelé à la réception d'une trame CAN 7F2         */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ISCAN_u8N8F7F2P849;                                           */
/*  output uint8 ISCAN_u8N8F7F2V003;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidIntfacIsCanIf17(void)
{
   uint8  u8LocalISCAN_u8N8F7F2P849;


   VEMS_vidGET(ISCAN_u8N8F7F2P849, u8LocalISCAN_u8N8F7F2P849);
   VEMS_vidSET(ISCAN_u8N8F7F2V003, u8LocalISCAN_u8N8F7F2P849);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidIntfacIsCanIf5                            */
/* !Description :  Interface function for Ext_bDrvCyGlbl                      */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean DC_bSyncGlbDC;                                              */
/*  output boolean Ext_bDrvCyGlbl;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidIntfacIsCanIf5(void)
{
   /*f5_interfacing_IsCanIf */
   boolean bLocalDC_bSyncGlbDC;


   VEMS_vidGET(DC_bSyncGlbDC, bLocalDC_bSyncGlbDC);
   VEMS_vidSET(Ext_bDrvCyGlbl, bLocalDC_bSyncGlbDC);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutAtmphPress                             */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Atmospheric_pressure.                                      */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pAirExtMesSIIf;                                          */
/*  output uint16 Atmospheric_pressure;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutAtmphPress(void)
{
   /*F16_Output_Atmospheric_pressure */
   uint16 u16LocalExt_pAirExtMesSIIf;


   VEMS_vidGET(Ext_pAirExtMesSIIf, u16LocalExt_pAirExtMesSIIf);
   VEMS_vidSET(Atmospheric_pressure, u16LocalExt_pAirExtMesSIIf);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutOCHeatPhaReq                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 OxC_bOxCHeatPhaReq.                                        */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean EOM_bTWCHeatPha;                                            */
/*  output boolean OxC_bOxCHeatPhaReq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutOCHeatPhaReq(void)
{
   /*F14_Output_bOxCHeatPhaReq */
   boolean bLocalEOM_bTWCHeatPha;


   VEMS_vidGET(EOM_bTWCHeatPha, bLocalEOM_bTWCHeatPha);
   VEMS_vidSET(OxC_bOxCHeatPhaReq , bLocalEOM_bTWCHeatPha);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidSTTIf                                     */
/* !Description :  Fontion appelé sur evenement 100ms                         */
/* !Number      :  FCT5.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 Ext_tAir;                                                     */
/*  output sint8 TqCmp_tAir;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidSTTIf(void)
{
   /*F01_STTIf */
   sint8  s8LocalExt_tAir;


   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s8LocalExt_tAir, -40, 100);
   VEMS_vidSET(TqCmp_tAir, s8LocalExt_tAir);
}

/*-------------------------------- end of file -------------------------------*/