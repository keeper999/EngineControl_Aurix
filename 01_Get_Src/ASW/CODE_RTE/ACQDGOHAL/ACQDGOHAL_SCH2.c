/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQDGOHAL                                               */
/* !Description     : ACQDGOHAL component.                                    */
/*                                                                            */
/* !Module          : ACQDGOHAL                                               */
/* !Description     : Spécification des acquisitions des états et résultats   */
/*                    des diagnostics                                         */
/*                                                                            */
/* !File            : ACQDGOHAL_SCH2.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / FuPmp_SdlFast_CmdDiagPropFuPmp                                       */
/*   2 / Pwr_SdlMid_CmdDiagDmtr                                               */
/*   3 / Rly_SdlFast_CmdDiagRly                                               */
/*   4 / EngSt_SdlMid_CmdDiagStrtr                                            */
/*   5 / CoFan_SdlMid_CmdDiagGMV1GMV2                                         */
/*   6 / CoFan_SdlSlow_CmdDiagECTReq                                          */
/*   7 / Thr_EveClcnServo_CmdDiagThrCmd                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6669624 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQDGOHAL/ACQDGOHAL_SCH2.c_v      $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   17 Sep 2014 $*/
/* $Author::   wbouach                                $$Date::   17 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H

#include "STD_TYPES.h"
#include "ACQDGOHAL.h"
#include "ACQDGOHAL_L.h"
#include "ACQDGOHAL_IM.h"
#include "GDGAR.h"
#include "DGOHAL.h"
#include "ACQDGOHAL_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_SdlFast_CmdDiagPropFuPmp                             */
/* !Description :  Moniteur rapide de la fonction FuPmp.                      */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_vidCmdDiagPropFuPmp();                         */
/*  input boolean Ctrl_bAcv_FuTnkPmp;                                         */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_SdlFast_CmdDiagPropFuPmp                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_SdlFast_CmdDiagPropFuPmp(void)
{
   boolean bLocalCtrl_bAcv_FuTnkPmp;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalECU_bImmoUnlockWkuSt;


   VEMS_vidGET(Ctrl_bAcv_FuTnkPmp, bLocalCtrl_bAcv_FuTnkPmp);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (  (bLocalCtrl_bAcv_FuTnkPmp != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalUCE_bPwrlAcv != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0)))
      {
         ACQDGOHAL_vidCmdDiagPropFuPmp();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlMid_CmdDiagDmtr                                     */
/* !Description :  Moniteur moyen de la fonction DMTR.                        */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_vidCmdDiagDmtr();                              */
/*  input boolean Pwr_bAcvDMTRAcq;                                            */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_SdlMid_CmdDiagDmtr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlMid_CmdDiagDmtr(void)
{
   boolean bLocalPwr_bAcvDMTRAcq;
   boolean bLocalIntegratioElectronique;


   VEMS_vidGET(Pwr_bAcvDMTRAcq, bLocalPwr_bAcvDMTRAcq);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (  (bLocalPwr_bAcvDMTRAcq != 0)
         && (bLocalIntegratioElectronique == 0))
      {
         ACQDGOHAL_vidCmdDiagDmtr();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Rly_SdlFast_CmdDiagRly                                     */
/* !Description :  Moniteur rapide du relais puissance.                       */
/* !Number      :  SCH2.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void ACQDGOHAL_vidCmdDiagRly();                               */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Rly_SdlFast_CmdDiagRly                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Rly_SdlFast_CmdDiagRly(void)
{
   boolean bLocalInhPwrRlyElDiag;


   bLocalInhPwrRlyElDiag = GDGAR_bGetFRM(FRM_FRM_INHPWRRLYELDIAG);
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (bLocalInhPwrRlyElDiag == 0)
      {
         ACQDGOHAL_vidCmdDiagRly();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlMid_CmdDiagStrtr                                  */
/* !Description :  Recurence du diagnostic électrique du DML.                 */
/* !Number      :  SCH2.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void ACQDGOHAL_vidCmdDiagStrtr();                             */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlMid_CmdDiagStrtr                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlMid_CmdDiagStrtr(void)
{
   boolean bLocalInhDmlDiagEl;


   bLocalInhDmlDiagEl = GDGAR_bGetFRM(FRM_FRM_INHDMLDIAGEL);
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (bLocalInhDmlDiagEl == 0)
      {
         ACQDGOHAL_vidCmdDiagStrtr();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlMid_CmdDiagGMV1GMV2                               */
/* !Description :  Moniteur moyen de la fonction CoFan.                       */
/* !Number      :  SCH2.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_vidCmdDiagGMV1GMV2();                          */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlMid_CmdDiagGMV1GMV2                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlMid_CmdDiagGMV1GMV2(void)
{
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      ACQDGOHAL_vidCmdDiagGMV1GMV2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlSlow_CmdDiagECTReq                                */
/* !Description :  Moniteur lent de la fonction CoFan.                        */
/* !Number      :  SCH2.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQDGOHAL_vidCmdDiagECTReq();                            */
/*  input boolean Ctrl_bAcv_ECTReq;                                           */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlSlow_CmdDiagECTReq                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlSlow_CmdDiagECTReq(void)
{
   boolean bLocalCtrl_bAcv_ECTReq;
   boolean bLocalECU_bWkuMain;


   VEMS_vidGET(Ctrl_bAcv_ECTReq, bLocalCtrl_bAcv_ECTReq);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      if (  (bLocalCtrl_bAcv_ECTReq != 0)
         && (bLocalECU_bWkuMain != 0))
      {
         ACQDGOHAL_vidCmdDiagECTReq();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_CmdDiagThrCmd                             */
/* !Description :  Evenement ClcnServo de la fonction Thr.                    */
/* !Number      :  SCH2.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQDGOHAL_vidCmdDiagThrOverload();                       */
/*  input uint8 ACQDGOHAL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_CmdDiagThrCmd                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_CmdDiagThrCmd(void)
{
   if (ACQDGOHAL_u8Inhib != 0x5A)
   {
      ACQDGOHAL_vidCmdDiagThrOverload();
   }
}
/*------------------------------- end of file --------------------------------*/