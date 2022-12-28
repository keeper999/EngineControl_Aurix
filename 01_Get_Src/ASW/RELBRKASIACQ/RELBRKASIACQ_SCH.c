/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RELBRKASIACQ                                            */
/* !Description     : RELBRKASIACQ Component                                  */
/*                                                                            */
/* !Module          : RELBRKASIACQ                                            */
/* !Description     : Relative Mastervac Pressure Acquisition                 */
/*                                                                            */
/* !File            : RELBRKASIACQ_SCH.C                                      */
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
/*   1 / AirPres_EveRst_RelBrkAsiAcq                                          */
/*   2 / AirPres_SdlFast_RelBrkAsiAcq                                         */
/*   3 / AirPres_SdlSfty_RelBrkAsiAcq                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6547160 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RELBRKASIACQ/RELBRKASIACQ_SCH.C_v $*/
/* $Revision::   1.4      $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "RELBRKASIACQ.h"
#include "RELBRKASIACQ_L.h"
#include "RELBRKASIACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_RelBrkAsiAcq                                */
/* !Description :  Reset event for AirPres function                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_001.01                                     */
/*                 VEMS_E_11_07345_002.01                                     */
/*                 VEMS_E_11_07345_003.01                                     */
/*                 VEMS_E_11_07345_004.01                                     */
/*                 VEMS_E_11_07345_005.01                                     */
/*                 VEMS_E_11_07345_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RELBRKASIACQ_vidInit();                                  */
/*  extf argret void RELBRKASIACQ_VidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_RelBrkAsiAcq                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_RelBrkAsiAcq(void)
{
   RELBRKASIACQ_vidInit();
   RELBRKASIACQ_VidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_RelBrkAsiAcq                               */
/* !Description :  Fast monitor for AirPres function                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_001.01                                     */
/*                 VEMS_E_11_07345_002.01                                     */
/*                 VEMS_E_11_07345_003.01                                     */
/*                 VEMS_E_11_07345_004.01                                     */
/*                 VEMS_E_11_07345_005.01                                     */
/*                 VEMS_E_11_07345_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void RELBRKASIACQ_vidCalc();                                  */
/*  input uint8 RELBRKASIACQ_u8Inhib;                                         */
/*  input boolean Ctrl_bAcv_pRelBrkAsi;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input boolean UCE_bPwrlAcv;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_RelBrkAsiAcq                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_RelBrkAsiAcq(void)
{
   boolean  bLocalCtrl_bAcv_pRelBrkAsi;
   boolean  bLocalECU_bWkuMain;
   boolean  bLocalECU_bImmoUnlockWkuSt;
   boolean  bLocalUCE_bPwrlAcv;


   if (RELBRKASIACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pRelBrkAsi, bLocalCtrl_bAcv_pRelBrkAsi);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
      VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);

      if (  (bLocalCtrl_bAcv_pRelBrkAsi != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0)
            || (bLocalUCE_bPwrlAcv != 0)))
      {
         RELBRKASIACQ_vidCalc();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlSfty_RelBrkAsiAcq                               */
/* !Description :  Calculation event of safety level 2 functions              */
/* !Number      :  SCH.3                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_001.01                                     */
/*                 VEMS_E_11_07345_002.01                                     */
/*                 VEMS_E_11_07345_003.01                                     */
/*                 VEMS_E_11_07345_004.01                                     */
/*                 VEMS_E_11_07345_005.01                                     */
/*                 VEMS_E_11_07345_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void RELBRKASIACQ_vidSftLvl2();                               */
/*  input uint8 RELBRKASIACQ_u8Inhib;                                         */
/*  input boolean Ctrl_bAcv_pRelBrkAsi;                                       */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean Ext_bAcv_RelBrkAsiSftyLvl2;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlSfty_RelBrkAsiAcq                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlSfty_RelBrkAsiAcq(void)
{
   boolean  bLocalCtrl_bAcv_pRelBrkAsi;
   boolean  bLocalECU_bWkuMain;
   boolean  bLocalECU_bImmoUnlockWkuSt;
   boolean  bLocalUCE_bPwrlAcv;
   boolean  bLocalExtbAcvRelBrkAsiSftyLvl2;


   if (RELBRKASIACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pRelBrkAsi, bLocalCtrl_bAcv_pRelBrkAsi);
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
      VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
      VEMS_vidGET(Ext_bAcv_RelBrkAsiSftyLvl2, bLocalExtbAcvRelBrkAsiSftyLvl2);

      if (  (bLocalCtrl_bAcv_pRelBrkAsi != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0)
            || (bLocalUCE_bPwrlAcv != 0))
         && (bLocalExtbAcvRelBrkAsiSftyLvl2 != 0))
      {
         RELBRKASIACQ_vidSftLvl2();
      }
   }
}
/*---------------------------- end of file -----------------------------------*/