/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : DCM_MANU_ROUTINE_CNTRL_FCT.c                            */
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
/*   1 / DCM_MANU_CheckCond4MkdPwrl                                           */
/*   2 / DCM_MANU_CheckCond4IniRealTiTroCnt                                   */
/*   3 / DCM_MANU_CheckCond4AcvUnloadRail                                     */
/*   4 / DCM_MANU_CheckCond4ProdTest                                          */
/*   5 / DCM_MANU_CheckCond4SftyLvl2                                          */
/*   6 / DCM_MANU_RcAcv_IniRealTiTroCnt                                       */
/*   7 / DCM_MANU_RcAcv_AcvUnloadRail                                         */
/*   8 / DCM_MANU_RcAcv_MkdPwrl                                               */
/*   9 / DCM_MANU_RcAcv_ProdTest                                              */
/*   10 / DCM_MANU_CheckRcCdn_MkdPwrl                                         */
/*   11 / DCM_MANU_RcCdn_IniRealTiTroCnt                                      */
/*   12 / DCM_MANU_RcCdn_4AcvUnloadRail                                       */
/*   13 / DCM_MANU_RcCdn_ProdTest                                             */
/*   14 / DCM_MANU_RcCdn_SftyLvl2                                             */
/*   15 / DCM_MANU_RcAcv_ThrInh                                               */
/*   16 / DCM_MANU_CheckCond4ThrInh                                           */
/*   17 / DCM_MANU_RcAcv_BattChg                                              */
/*   18 / DCM_MANU_CheckCond4BattChg                                          */
/*   19 / DCM_MANU_CheckRcCdn_BattChg                                         */
/*   20 / DCM_MANU_RcAcv_RstCurRdB                                            */
/*   21 / DCM_MANU_CheckCond4RstCurRdB                                        */
/*   22 / DCM_MANU_CheckRcCdn_RstCurRdB                                       */
/*   23 / DCM_MANU_RcAcv_RstCoReqRStrt                                        */
/*   24 / DCM_MANU_CheckCond4RstCoReqRStrt                                    */
/*   25 / DCM_MANU_CheckRcCdn_RstCoReqRStrt                                   */
/*   26 / DCM_MANU_CheckRcCdn_tiRcRstEnd                                      */
/*   27 / DCM_MANU_RcAcv_RstStaCnt                                            */
/*   28 / DCM_MANU_CheckCond4RstStaCnt                                        */
/*   29 / DCM_MANU_CheckRcCdn_RstStaCnt                                       */
/*   30 / DCM_MANU_RcAcv_RstCluDftCnt                                         */
/*   31 / DCM_MANU_CheckCond4RstCluDftCnt                                     */
/*   32 / DCM_MANU_CheckRcCdn_RstCluDftCnt                                    */
/*   33 / DCM_MANU_RcCdn_ThrInh                                               */
/*   34 / DCM_MANU_RcAcv_SftyLvl2                                             */
/*   35 / DCM_MANU_RcAcv_RstDfwChg                                            */
/*   36 / DCM_MANU_CheckRcCdn_RstDfwChg                                       */
/*   37 / DCM_MANU_CheckCond4RstDfwChg                                        */
/*   38 / DCM_MANU_RcAcv_RstAFAMgtT                                           */
/*   39 / DCM_MANU_CheckCond4RstAFAMgtT                                       */
/*   40 / DCM_MANU_CheckRcCdn_RstAFAMgtT                                      */
/*   41 / DCM_MANU_RcAcv_RstESLim                                             */
/*   42 / DCM_MANU_CheckCond4RstESLim                                         */
/*   43 / DCM_MANU_CheckRcCdn_RstESLim                                        */
/*   44 / DCM_MANU_RcAcv_RstCylHdDmgCnt                                       */
/*   45 / DCM_MANU_CheckCond4RstCylHdDmgCnt                                   */
/*   46 / DCM_MANU_CheckRcCdn_RstCylHdDmgCnt                                  */
/*   47 / DCM_MANU_RcAcv_RstMnfDmgCnt                                         */
/*   48 / DCM_MANU_CheckCond4RstMnfDmgCnt                                     */
/*   49 / DCM_MANU_CheckRcCdn_RstMnfDmgCnt                                    */
/*   50 / DCM_MANU_RcAcv_RstTrbDmgCnt                                         */
/*   51 / DCM_MANU_CheckCond4RstTrbDmgCnt                                     */
/*   52 / DCM_MANU_CheckRcCdn_RstTrbDmgCnt                                    */
/*   53 / DCM_MANU_RcAcv_RstCylHdDmgCplmCnt                                   */
/*   54 / DCM_MANU_CheckCond4RstCylHdDmgCplmCnt                               */
/*   55 / DCM_MANU_CheckRcCdn_RstCylHdDmgCplmCnt                              */
/*   56 / DCM_MANU_RcAcv_ModeSTTFactReq                                       */
/*   57 / DCM_MANU_CheckCond4ModeSTTFactReq                                   */
/*   58 / DCM_MANU_CheckRcCdn_ModeSTTFactReq                                  */
/*   59 / DCM_MANU_RcAcv_ModeSTTAftsReq                                       */
/*   60 / DCM_MANU_CheckCond4ModeSTTAftsReq                                   */
/*   61 / DCM_MANU_CheckRcCdn_ModeSTTAftsReq                                  */
/*   62 / DCM_MANU_RcAcv_ModeSTTBatt                                          */
/*   63 / DCM_MANU_CheckCond4ModeSTTBatt                                      */
/*   64 / DCM_MANU_CheckRcCdn_ModeSTTBatt                                     */
/*   65 / DCM_MANU_RcAcv_RstTrbActSys                                         */
/*   66 / DCM_MANU_CheckCond4RstTrbActSys                                     */
/*   67 / DCM_MANU_CheckRcCdn_RstTrbActSys                                    */
/*   68 / DCM_MANU_RcAcv_RstPed                                               */
/*   69 / DCM_MANU_CheckCond4RstPed                                           */
/*   70 / DCM_MANU_RcCdn_RstPed                                               */
/*   71 / DCM_MANU_RcAcv_RstReqStcBatt                                        */
/*   72 / DCM_MANU_CheckCond4RstReqStcBatt                                    */
/*   73 / DCM_MANU_RcCdn_RstReqStcBatt                                        */
/*   74 / DCM_MANU_RcAcv_RstLrn_Misf                                          */
/*   75 / DCM_MANU_CheckCond4RstLrn_Misf                                      */
/*   76 / DCM_MANU_RcCdn_RstLrn_Misf                                          */
/*   77 / DCM_MANU_CheckCond4InhBoostGDI                                      */
/*   78 / DCM_MANU_RcAcv_InhBoostGDI                                          */
/*   79 / DCM_MANU_RcCdn_InhBoostGDI                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5074350 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DCM$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"
#include "DCM_MANU_FIX.h"
#include "VEMS.H"



/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4MkdPwrl                                 */
/* !Description :  Fonction liée à l'init du marqueur power latch.            */
/* !Number      :  ROUTINE_CNTRL_FCT.1                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4MkdPwrl
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   uint16  u16localspdveh;
   boolean blocalextbrun;

   VEMS_vidGET(Ext_bRun, blocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);

   *Srv_bRcCondOk_Namefunc = (boolean)
      ( ( ( u16localspdveh <= (uint16)(Diag_seuil_vit_veh * 128)) &&
          ( FALSE == blocalextbrun                       ) ) ? TRUE : FALSE );


}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4IniRealTiTroCnt                         */
/* !Description :  Fonction liée à je ne sais plus quoi.                      */
/* !Number      :  ROUTINE_CNTRL_FCT.2                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4IniRealTiTroCnt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   *Srv_bRcCondOk_Namefunc = TRUE;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4AcvUnloadRail                           */
/* !Description :  Fonction liée à la décharge de pression rail.              */
/* !Number      :  ROUTINE_CNTRL_FCT.3                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Ext_bRun;                                                   */
/*  input boolean ECU_bWkuMain;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4AcvUnloadRail
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean bLocalECUWkuMain;
   boolean blocalextbrun;
   boolean bLocalInhUnloadRail;

   VEMS_vidGET(Ext_bRun, blocalextbrun);
   VEMS_vidGET(ECU_bWkuMain, bLocalECUWkuMain);
   bLocalInhUnloadRail = GDGAR_bGetFRM(FRM_FRM_INHUNLOADRAIL);

   *Srv_bRcCondOk_Namefunc =
      (boolean)( ( ( FALSE == bLocalInhUnloadRail ) &&
                   ( FALSE == blocalextbrun       ) &&
                   ( FALSE != bLocalECUWkuMain    ) ) ? TRUE : FALSE );
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4ProdTest                                */
/* !Description :  Fonction liée au saut dans les tests en prod.              */
/* !Number      :  ROUTINE_CNTRL_FCT.4                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  output Std_ReturnType DCM_MANU_TestProdReturnValue;                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4ProdTest
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean bLocalextbrun;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);

   *Srv_bRcCondOk_Namefunc = ( FALSE == bLocalextbrun ) ? TRUE : FALSE;

   /* Initialisation variable de retour API test en prod */
   DCM_MANU_TestProdReturnValue = E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4SftyLvl2                                */
/* !Description :  Fonction liée au Safety Niveau 2                           */
/* !Number      :  ROUTINE_CNTRL_FCT.5                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4SftyLvl2
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint8    u8localCoPTSt_stEng;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= (uint16)(Diag_seuil_vit_veh * 128))
      &&(FALSE == bLocalextbrun)
      &&( u8localCoPTSt_stEng == 1)
      &&( bLocalECU_bWkuMain == TRUE))
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_IniRealTiTroCnt                             */
/* !Description :  Fonction liée à je ne sais plus quoi.                      */
/* !Number      :  ROUTINE_CNTRL_FCT.6                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Sfty_EveInitCnt_TaskOvrrunCnt();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_IniRealTiTroCnt(void)
{
   Sfty_EveInitCnt_TaskOvrrunCnt();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_AcvUnloadRail                               */
/* !Description :  Fonction liée à la décharge de pression rail.              */
/* !Number      :  ROUTINE_CNTRL_FCT.7                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Srv_bAcvUnloadRail;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_AcvUnloadRail(void)
{
   VEMS_vidSET(Srv_bAcvUnloadRail, TRUE);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_MkdPwrl                                     */
/* !Description :  Fonction liée à l'initialisation du marqueur Power Latch.  */
/* !Number      :  ROUTINE_CNTRL_FCT.8                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Srv_EveRcReinit_PwrlMrk();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_MkdPwrl(void)
{
   Srv_EveRcReinit_PwrlMrk();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_ProdTest                                    */
/* !Description :  Fonction liée au tests en prod.                            */
/* !Number      :  ROUTINE_CNTRL_FCT.9                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  SUPSRV_udtJumpToIdentTest(argin uint8         */
/*  *pau8RequestBuffer, argin uint8 u8RequestSize);                           */
/*  input uint16 DCM_MANU_TestProdParam;                                      */
/*  output Std_ReturnType DCM_MANU_TestProdReturnValue;                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_ProdTest(void)
{
   uint8 au8LocalArray[6];

   au8LocalArray[0] = 0x31;
   au8LocalArray[1] = 0x01;
   au8LocalArray[2] = 0xF0;
   au8LocalArray[3] = 0x00;
   au8LocalArray[4] = (uint8)((DCM_MANU_TestProdParam & 0xFF00) >> 8);
   au8LocalArray[5] = (uint8)(DCM_MANU_TestProdParam & 0x00FF);

   DCM_MANU_TestProdReturnValue = SUPSRV_udtJumpToIdentTest( au8LocalArray, 6 );
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_MkdPwrl                                */
/* !Description :  Fonction liée au marqeur de powerlatch                     */
/* !Number      :  ROUTINE_CNTRL_FCT.10                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean EcuSt_SrvPwrlSt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_MkdPwrl
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   boolean bLocalEcuSt_SrvPwrlSt;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   VEMS_vidGET(EcuSt_SrvPwrlSt, bLocalEcuSt_SrvPwrlSt);

   if(bLocalEcuSt_SrvPwrlSt == FALSE)
   {
      *Srv_bRcCdnOk_NameFunc = TRUE;
   }
   else
   {
      *Srv_bRcCdnNok_NameFunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_IniRealTiTroCnt                             */
/* !Description :  function about Reset of realtime trouble counter           */
/* !Number      :  ROUTINE_CNTRL_FCT.11                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint16 Sfty_Count_TaskOvrrunCnt;                                    */
/*  input boolean Sfty_bRazCountComplet;                                      */
/*  input uint32 Sfty_prm_IdTaskOvrrunCnt[8];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_IniRealTiTroCnt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   uint16   u16LocalSfty_Count_TaskOvrrunCnt;
   boolean  bLocalSfty_bRazCountComplet;
   uint32   u8aLocalSfty_prm_IdTaskOvrrunCnt[8];
   uint8    u8LocalIndex;
   boolean  bLocalFlag;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;
   bLocalFlag = TRUE;

   VEMS_vidGET(Sfty_Count_TaskOvrrunCnt, u16LocalSfty_Count_TaskOvrrunCnt);
   VEMS_vidGET(Sfty_bRazCountComplet, bLocalSfty_bRazCountComplet);
   VEMS_vidGET1DArray(Sfty_prm_IdTaskOvrrunCnt,8,
                                 u8aLocalSfty_prm_IdTaskOvrrunCnt);

   for(u8LocalIndex = 0; (u8LocalIndex < 8) && bLocalFlag ; u8LocalIndex++)
   {
      if(u8aLocalSfty_prm_IdTaskOvrrunCnt[u8LocalIndex] != (uint32)0x00)
      {
         bLocalFlag = FALSE;
      }
   }

   if( (bLocalFlag == TRUE) &&
       (u16LocalSfty_Count_TaskOvrrunCnt == 0) &&
       (bLocalSfty_bRazCountComplet == TRUE)
     )
   {
      *Srv_bRcCdnOk_NameFunc = TRUE;
   }
   else
   {
      *Srv_bRcCdnNok_NameFunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_4AcvUnloadRail                              */
/* !Description :  Function about Diminution of pressure in rail              */
/* !Number      :  ROUTINE_CNTRL_FCT.12                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint16 PFuAcq_pFuRailMes;                                           */
/*  input boolean Arret_moteur_clef;                                          */
/*  input uint16 Srv_pFuRailAftsThd_C;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_4AcvUnloadRail
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   uint32  u32LocalFuRailAftsThd;
   uint16  u16LocalpFuRailMes;
   boolean bLocalArret_moteur_clef;
   boolean bLocalInhUnloadRail;

   VEMS_vidGET(PFuAcq_pFuRailMes, u16LocalpFuRailMes);
   VEMS_vidGET(Arret_moteur_clef, bLocalArret_moteur_clef);
   bLocalInhUnloadRail = GDGAR_bGetFRM(FRM_FRM_INHUNLOADRAIL);

   u32LocalFuRailAftsThd = (Srv_pFuRailAftsThd_C * 128);
   *Srv_bRcCdnNok_NameFunc =
      (boolean)( (  (  ( (uint32)u16LocalpFuRailMes >= u32LocalFuRailAftsThd )
                    || ( TRUE == bLocalArret_moteur_clef))
                 && ( FALSE == bLocalInhUnloadRail ))
               ? FALSE : TRUE );

   *Srv_bRcCdnOk_NameFunc = (boolean)
      ( ( ( (uint32)u16LocalpFuRailMes < u32LocalFuRailAftsThd ) &&
          ( FALSE == bLocalArret_moteur_clef                   ) &&
          ( FALSE == bLocalInhUnloadRail )                     ) ?
            TRUE : FALSE );
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_ProdTest                                    */
/* !Description :  Function about Tests in production of the ECU              */
/* !Number      :  ROUTINE_CNTRL_FCT.13                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input Std_ReturnType DCM_MANU_TestProdReturnValue;                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_ProdTest
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   /* Si API TP a répondu positivement */
   if( E_OK == DCM_MANU_TestProdReturnValue )
   {
      *Srv_bRcCdnOk_NameFunc = TRUE;
   }
   else
   {
      *Srv_bRcCdnNok_NameFunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_SftyLvl2                                    */
/* !Description :  Function about safety level 2                              */
/* !Number      :  ROUTINE_CNTRL_FCT.14                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Srv_bInhSftyLvl2;                                           */
/*  input uint8 DCM_MANU_Cntrl_Inhibition;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_SftyLvl2
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   boolean bLocalInhSftyLvl2;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;
   VEMS_vidGET(Srv_bInhSftyLvl2, bLocalInhSftyLvl2);

   if(( (bLocalInhSftyLvl2 == TRUE) && (0xFF == DCM_MANU_Cntrl_Inhibition ))
      || ( (bLocalInhSftyLvl2 == FALSE) && (0x00 == DCM_MANU_Cntrl_Inhibition ))
      )
   {
      *Srv_bRcCdnOk_NameFunc = TRUE;
   }
   else
   {
      *Srv_bRcCdnNok_NameFunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_ThrInh                                      */
/* !Description :  Function about throttle inhibition                         */
/* !Number      :  ROUTINE_CNTRL_FCT.15                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 DCM_MANU_Cntrl_Inhibition;                                    */
/*  output boolean Srv_bInhThr;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_ThrInh(void)
{
   if(DCM_MANU_Cntrl_Inhibition == 0xFF)
   {
      VEMS_vidSET(Srv_bInhThr, TRUE);
   }
   else
   {
      VEMS_vidSET(Srv_bInhThr, FALSE);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4ThrInh                                  */
/* !Description :  Function about throttle inhibition                         */
/* !Number      :  ROUTINE_CNTRL_FCT.16                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckCond4SftyLvl2(argout boolean               */
/*  *Srv_bRcCondOk_Namefunc);                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4ThrInh
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   DCM_MANU_CheckCond4SftyLvl2(Srv_bRcCondOk_Namefunc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_BattChg                                     */
/* !Description :  Function about battery changing                            */
/* !Number      :  ROUTINE_CNTRL_FCT.17                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bLrnRstReq_rOfsSoC;                                   */
/*  output boolean Afts_bLrnRstReq_uEmPredRstrt;                              */
/*  output boolean Afts_bRstReq_stSoHBatt;                                    */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_BattChg(void)
{
   VEMS_vidSET(Afts_bLrnRstReq_rOfsSoC, TRUE);
   VEMS_vidSET(Afts_bLrnRstReq_uEmPredRstrt, TRUE);
   VEMS_vidSET(Afts_bRstReq_stSoHBatt, TRUE);

   Srv_tiRcRstEnd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4BattChg                                 */
/* !Description :  Function about battery changing                            */
/* !Number      :  ROUTINE_CNTRL_FCT.18                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4BattChg
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint8    u8localCoPTSt_stEng;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= (uint16)(Diag_seuil_vit_veh * 128))
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg != RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys != RC_RUNNING)
      && (Srv_stRcEnd_RstESLim != RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_BattChg                                */
/* !Description :  Function about battery changing                            */
/* !Number      :  ROUTINE_CNTRL_FCT.19                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_BattChg
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
      Srv_bRcCdnNok_NameFunc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstCurRdB                                   */
/* !Description :  Function about reset learning RdB current                  */
/* !Number      :  ROUTINE_CNTRL_FCT.20                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bLrnRstReq_iElNwStop;                                 */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstCurRdB(void)
{
   VEMS_vidSET(Afts_bLrnRstReq_iElNwStop, TRUE);
   Srv_tiRcRstEnd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstCurRdB                               */
/* !Description :  Function about reset learning RdB current                  */
/* !Number      :  ROUTINE_CNTRL_FCT.21                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstCurRdB
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint8    u8localCoPTSt_stEng;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= (uint16)(Diag_seuil_vit_veh * 128))
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg != RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys != RC_RUNNING)
      && (Srv_stRcEnd_RstESLim != RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstCurRdB                              */
/* !Description :  Function about reset learning RdB current                  */
/* !Number      :  ROUTINE_CNTRL_FCT.22                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstCurRdB
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
      Srv_bRcCdnNok_NameFunc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstCoReqRStrt                               */
/* !Description :  Function about reset for learned value in function re-start*/
/* !Number      :  ROUTINE_CNTRL_FCT.23                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bRstMemCoReqRStrt;                                    */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstCoReqRStrt(void)
{
   VEMS_vidSET(Afts_bRstMemCoReqRStrt, TRUE);
   Srv_tiRcRstEnd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstCoReqRStrt                           */
/* !Description :  Function about reset for learned value in function re-start*/
/* !Number      :  ROUTINE_CNTRL_FCT.24                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstCoReqRStrt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint8    u8localCoPTSt_stEng;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= (uint16)(Diag_seuil_vit_veh * 128))
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg != RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys != RC_RUNNING)
      && (Srv_stRcEnd_RstESLim != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
      )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstCoReqRStrt                          */
/* !Description :  Function about reset for learned value in function re-start*/
/* !Number      :  ROUTINE_CNTRL_FCT.25                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstCoReqRStrt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
                                          Srv_bRcCdnNok_NameFunc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_tiRcRstEnd                             */
/* !Description :  Function about timer tiRcRstEnd                            */
/* !Number      :  ROUTINE_CNTRL_FCT.26                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Srv_tiRcRstEnd;                                              */
/*  input uint16 Srv_tiRcRstEnd_C;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_tiRcRstEnd
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   if(Srv_tiRcRstEnd >= Srv_tiRcRstEnd_C)
   {
      *Srv_bRcCdnOk_NameFunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstStaCnt                                   */
/* !Description :  Function about reset starter activation counter            */
/* !Number      :  ROUTINE_CNTRL_FCT.27                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bRstReq_ctStaAcv;                                     */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstStaCnt(void)
{
   VEMS_vidSET(Afts_bRstReq_ctStaAcv, TRUE);
   Srv_tiRcRstEnd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstStaCnt                               */
/* !Description :  Function about reset starter activation counter            */
/* !Number      :  ROUTINE_CNTRL_FCT.28                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstStaCnt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint8    u8localCoPTSt_stEng;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= (uint16)(Diag_seuil_vit_veh * 128))
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg != RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys != RC_RUNNING)
      && (Srv_stRcEnd_RstESLim != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
      )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstStaCnt                              */
/* !Description :  Function about reset starter activation counter            */
/* !Number      :  ROUTINE_CNTRL_FCT.29                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstStaCnt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
                                          Srv_bRcCdnNok_NameFunc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstCluDftCnt                                */
/* !Description :  Function about reset clutch default AFTS counter           */
/* !Number      :  ROUTINE_CNTRL_FCT.30                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bRstCntDiagCluP;                                      */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstCluDftCnt(void)
{
   VEMS_vidSET(Afts_bRstCntDiagCluP, TRUE);
   Srv_tiRcRstEnd = 0;
}

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstCluDftCnt                            */
/* !Description :  Function about reset clutch default AFTS counter           */
/* !Number      :  ROUTINE_CNTRL_FCT.31                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstCluDftCnt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint8    u8localCoPTSt_stEng;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= (uint16)(Diag_seuil_vit_veh * 128))
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg != RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT != RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys != RC_RUNNING)
      && (Srv_stRcEnd_RstESLim != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
      )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstCluDftCnt                           */
/* !Description :  Function about reset clutch default AFTS counter           */
/* !Number      :  ROUTINE_CNTRL_FCT.32                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstCluDftCnt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
                                          Srv_bRcCdnNok_NameFunc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_ThrInh                                      */
/* !Description :  Function about throttle inhibition                         */
/* !Number      :  ROUTINE_CNTRL_FCT.33                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Srv_bInhThr;                                                */
/*  input uint8 DCM_MANU_Cntrl_Inhibition;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_ThrInh
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   boolean bLocalInhThr;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;
   VEMS_vidGET(Srv_bInhThr, bLocalInhThr);

   if(( (bLocalInhThr == TRUE) && (0xFF == DCM_MANU_Cntrl_Inhibition ))
      || ( (bLocalInhThr == FALSE) && (0x00 == DCM_MANU_Cntrl_Inhibition ))
      )
   {
      *Srv_bRcCdnOk_NameFunc = TRUE;
   }
   else
   {
      *Srv_bRcCdnNok_NameFunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_SftyLvl2                                    */
/* !Description :  Fonction liée à la routine Safety Niveau 2                 */
/* !Number      :  ROUTINE_CNTRL_FCT.34                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 DCM_MANU_Cntrl_Inhibition;                                    */
/*  output boolean Srv_bInhSftyLvl2;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_SftyLvl2(void)
{
   if( 0xFF == DCM_MANU_Cntrl_Inhibition )
   {
      VEMS_vidSET(Srv_bInhSftyLvl2, TRUE);
   }
   else /* 0x00 == DCM_MANU_Cntrl_Inhibition */
   {
      VEMS_vidSET(Srv_bInhSftyLvl2, FALSE);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstDfwChg                                   */
/* !Description :  Action to realize for the Routine about engine flywheel    */
/*                 (DWA) exchange service                                     */
/* !Number      :  ROUTINE_CNTRL_FCT.35                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bRstDfwChg;                                           */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstDfwChg(void)
{
   VEMS_vidSET(Afts_bRstDfwChg, TRUE);
   Srv_tiRcRstEnd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstDfwChg                              */
/* !Description :  Action to indicate that the Routine about engine flywheel  */
/*                 (DWA) exchange service is finished OK or NOK               */
/* !Number      :  ROUTINE_CNTRL_FCT.36                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstDfwChg
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
                                       Srv_bRcCdnNok_NameFunc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstDfwChg                               */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about engine flywheel (DWA) exchange service       */
/* !Number      :  ROUTINE_CNTRL_FCT.37                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstDfwChg
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt!= RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf!= RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstAFAMgtT                                  */
/* !Description :  Action to realize for the Routine about reset AFAMgtT data */
/*                 service THR/INJ/VVT                                        */
/* !Number      :  ROUTINE_CNTRL_FCT.38                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_RcAcv_RstAFAMgtT(argin uint8    */
/*  *InBuffer, argin uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType     */
/*  *ErrorCode);                                                              */
/*  extf argret void DCM_MANU_EveRstThr_SrvRc();                              */
/*  extf argret void DCM_MANU_EveRstVVT_SrvRc();                              */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstAFAMgtT(void)
{
   Std_ReturnType                status;
   uint8                         InBuffer;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   status =
         DCM_MANU_CALL_RcAcv_RstAFAMgtT(&InBuffer,&OutBuffer,&ErrorCode);

   DCM_MANU_EveRstThr_SrvRc(); /* Thr_EveRstThr */
   DCM_MANU_EveRstVVT_SrvRc(); /*   VLVACTIN_EveRstVVT
                                    VLVACTEX_EveRstVVT   */

   if(status == E_OK)
   {
      if(OutBuffer != ROUTINE_EN_COURS)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;

   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstAFAMgtT                              */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about reset AFAMgtT data service THR/INJ/VVT       */
/* !Number      :  ROUTINE_CNTRL_FCT.39                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstAFAMgtT
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstAFAMgtT                             */
/* !Description :  Action to indicate that the Routine about reset AFAMgtT    */
/*                 data service THR/INJ/VVT is finished OK or NOK             */
/* !Number      :  ROUTINE_CNTRL_FCT.41                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_CheckRcCdn_RstAFAMgtT(argin     */
/*  uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType *ErrorCode);         */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstAFAMgtT
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   Std_ReturnType                status;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   status = DCM_MANU_CALL_CheckRcCdn_RstAFAMgtT(&OutBuffer,&ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer == TERMINE_OK)
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
      else if(OutBuffer == 0x00)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
      else if(OutBuffer == ROUTINE_EN_COURS)
      {
         *Srv_bRcCdnOk_NameFunc = FALSE;
         *Srv_bRcCdnNok_NameFunc = FALSE;
      }
      else
      {
         *Srv_bRcCdnNok_NameFunc = TRUE;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstESLim                                    */
/* !Description :  Action to realize for the Routine about reset TrbActSys    */
/*                 data service ESLim                                         */
/* !Number      :  ROUTINE_CNTRL_FCT.42                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bRstESLim;                                            */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstESLim(void)
{
   VEMS_vidSET(Afts_bRstESLim, TRUE);
   Srv_tiRcRstEnd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstESLim                                */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about reset TrbActSys data service ESLim           */
/* !Number      :  ROUTINE_CNTRL_FCT.43                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstESLim
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys!= RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstESLim                               */
/* !Description :  Action to indicate that the Routine about reset TrbActSys  */
/*                 data service ESLim is finished OK or NOK                   */
/* !Number      :  ROUTINE_CNTRL_FCT.44                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstESLim
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
                                       Srv_bRcCdnNok_NameFunc);
}

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstCylHdDmgCnt                              */
/* !Description :  Action to realize for the Routine about reset the damage   */
/*                 counter of the cylinder head                               */
/* !Number      :  ROUTINE_CNTRL_FCT.45                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_RcAcv_RstCylHdDmgCnt(argin uint8*/
/*  *InBuffer, argin uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType     */
/*  *ErrorCode);                                                              */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstCylHdDmgCnt(void)
{
   Std_ReturnType                status;
   uint8                         InBuffer;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   status =
         DCM_MANU_CALL_RcAcv_RstCylHdDmgCnt(&InBuffer,&OutBuffer, &ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer != ROUTINE_EN_COURS)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstCylHdDmgCnt                          */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about reset the damage counter of the cylinder head*/
/* !Number      :  ROUTINE_CNTRL_FCT.46                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstCylHdDmgCnt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys!= RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt!= RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf!= RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstCylHdDmgCnt                         */
/* !Description :  Action to indicate that the Routine about reset the damage */
/*                 counter of the cylinder head is finished OK or NOK         */
/* !Number      :  ROUTINE_CNTRL_FCT.47                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCnt(argin */
/*  uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType *ErrorCode);         */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstCylHdDmgCnt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   Std_ReturnType                status;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   status =
      DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCnt(&OutBuffer,&ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer == TERMINE_OK)
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
      else if(OutBuffer == 0x00)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
      else if(OutBuffer == ROUTINE_EN_COURS)
      {
         *Srv_bRcCdnOk_NameFunc = FALSE;
         *Srv_bRcCdnNok_NameFunc = FALSE;
      }
      else
      {
         *Srv_bRcCdnNok_NameFunc = TRUE;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstMnfDmgCnt                                */
/* !Description :  Action to realize for the Routine about reset the damage   */
/*                 counter of the exhaust manifold                            */
/* !Number      :  ROUTINE_CNTRL_FCT.48                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_RcAcv_RstMnfDmgCnt(argin uint8  */
/*  *InBuffer, argin uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType     */
/*  *ErrorCode);                                                              */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstMnfDmgCnt(void)
{
   Std_ReturnType                status;
   uint8                         InBuffer;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   status =
         DCM_MANU_CALL_RcAcv_RstMnfDmgCnt(&InBuffer,&OutBuffer, &ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer != ROUTINE_EN_COURS)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstMnfDmgCnt                            */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about reset the damage counter of the exhaust      */
/*                 manifold                                                   */
/* !Number      :  ROUTINE_CNTRL_FCT.49                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstMnfDmgCnt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys!= RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstMnfDmgCnt                           */
/* !Description :  Action to indicate that the Routine about reset the damage */
/*                 counter of the exhaust manifold is finished OK or NOK      */
/* !Number      :  ROUTINE_CNTRL_FCT.50                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_CheckRcCdn_RstMnfDmgCnt(argin   */
/*  uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType *ErrorCode);         */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstMnfDmgCnt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   Std_ReturnType                status;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   status = DCM_MANU_CALL_CheckRcCdn_RstMnfDmgCnt(&OutBuffer,&ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer == TERMINE_OK)
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
      else if(OutBuffer == 0x00)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
      else if(OutBuffer == ROUTINE_EN_COURS)
      {
         *Srv_bRcCdnOk_NameFunc = FALSE;
         *Srv_bRcCdnNok_NameFunc = FALSE;
      }
      else
      {
         *Srv_bRcCdnNok_NameFunc = TRUE;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstTrbDmgCnt                                */
/* !Description :  Action to realize for the Routine about reset the damage   */
/*                 counter of the turbo housing                               */
/* !Number      :  ROUTINE_CNTRL_FCT.51                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_RcAcv_RstTrbDmgCnt(argin uint8  */
/*  *InBuffer, argin uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType     */
/*  *ErrorCode);                                                              */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstTrbDmgCnt(void)
{
   Std_ReturnType                status;
   uint8                         InBuffer;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   status =
         DCM_MANU_CALL_RcAcv_RstTrbDmgCnt(&InBuffer,&OutBuffer, &ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer != ROUTINE_EN_COURS)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstTrbDmgCnt                            */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about reset the damage counter of the turbo housing*/
/* !Number      :  ROUTINE_CNTRL_FCT.52                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstTrbDmgCnt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys!= RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstTrbDmgCnt                           */
/* !Description :  Action to indicate that the Routine about reset the damage */
/*                 counter of the turbo housing is finished OK or NOK         */
/* !Number      :  ROUTINE_CNTRL_FCT.53                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_CheckRcCdn_RstTrbDmgCnt(argin   */
/*  uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType *ErrorCode);         */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstTrbDmgCnt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   Std_ReturnType                status;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   status =
      DCM_MANU_CALL_CheckRcCdn_RstTrbDmgCnt(&OutBuffer,&ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer == TERMINE_OK)
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
      else if(OutBuffer == 0x00)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
      else if(OutBuffer == ROUTINE_EN_COURS)
      {
         *Srv_bRcCdnOk_NameFunc = FALSE;
         *Srv_bRcCdnNok_NameFunc = FALSE;
      }
      else
      {
         *Srv_bRcCdnNok_NameFunc = TRUE;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstCylHdDmgCplmCnt                          */
/* !Description :  Action to realize for the Routine about reset the damage   */
/*                 counter of the cylinder head complementary                 */
/* !Number      :  ROUTINE_CNTRL_FCT.54                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_RcAcv_RstCylHdDmgCplmCnt(argin  */
/*  uint8 *InBuffer, argin uint8 *OutBuffer, argin                            */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstCylHdDmgCplmCnt(void)
{
   Std_ReturnType                status;
   uint8                         InBuffer;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   status = DCM_MANU_CALL_RcAcv_RstCylHdDmgCplmCnt(&InBuffer,&OutBuffer,
                                                      &ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer != ROUTINE_EN_COURS)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstCylHdDmgCplmCnt                      */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about reset the damage counter of the cylinder head*/
/*                 complementary                                              */
/* !Number      :  ROUTINE_CNTRL_FCT.55                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstCylHdDmgCplmCnt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys!= RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstCylHdDmgCplmCnt                     */
/* !Description :  Action to indicate that the Routine about reset the damage */
/*                 counter of the cylinder head complementary is finished OK  */
/*                 or NOK                                                     */
/* !Number      :  ROUTINE_CNTRL_FCT.56                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType                                                */
/*  DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCplmCnt(argin uint8 *OutBuffer, argin */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstCylHdDmgCplmCnt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   Std_ReturnType                status;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   status =
      DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCplmCnt(&OutBuffer,&ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer == TERMINE_OK)
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
      else if(OutBuffer == 0x00)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
      else if(OutBuffer == ROUTINE_EN_COURS)
      {
         *Srv_bRcCdnOk_NameFunc = FALSE;
         *Srv_bRcCdnNok_NameFunc = FALSE;
      }
      else
      {
         *Srv_bRcCdnNok_NameFunc = TRUE;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_ModeSTTFactReq                              */
/* !Description :  Action to realize for the Routine about STT factory stop   */
/*                 mode                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.57                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_Cntrl_ModeSTT;                                       */
/*  output uint8 Afts_stSpcFactSTTReq;                                        */
/*  output uint16 Srv_tiRcSttEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_ModeSTTFactReq(void)
{
   switch(DCM_MANU_Cntrl_ModeSTT)
   {
      case 0x00:
         VEMS_vidSET(Afts_stSpcFactSTTReq, 0);
         break;
      case 0x01:
         VEMS_vidSET(Afts_stSpcFactSTTReq, 1);
         break;
      case 0x02:
         VEMS_vidSET(Afts_stSpcFactSTTReq, 2);
         break;
      default:
         /* cas impossible */
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   Srv_tiRcSttEnd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4ModeSTTFactReq                          */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about STT factory stop mode                        */
/* !Number      :  ROUTINE_CNTRL_FCT.58                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_ModeSTTAftsReq;                                   */
/*  input uint8 Srv_stRcEnd_ModeSTTBatt;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4ModeSTTFactReq
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_ModeSTTAftsReq != RC_RUNNING)
      && (Srv_stRcEnd_ModeSTTBatt != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_ModeSTTFactReq                         */
/* !Description :  Action to indicate that the Routine about STT factory stop */
/*                 mode is finished OK or NOK                                 */
/* !Number      :  ROUTINE_CNTRL_FCT.59                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPtUH_bFbSpcFactSTTReq1;                                   */
/*  input boolean CoPtUH_bFbSpcFactSTTReq2;                                   */
/*  input uint16 Srv_tiRcSttEnd;                                              */
/*  input uint16 Srv_tiRcSttEnd_C;                                            */
/*  input uint8 DCM_MANU_Cntrl_ModeSTT;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_ModeSTTFactReq
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   boolean  bLocalCoPtUH_bFbSpcFactSTTReq1;
   boolean  bLocalCoPtUH_bFbSpcFactSTTReq2;

   VEMS_vidGET(CoPtUH_bFbSpcFactSTTReq1, bLocalCoPtUH_bFbSpcFactSTTReq1);
   VEMS_vidGET(CoPtUH_bFbSpcFactSTTReq2, bLocalCoPtUH_bFbSpcFactSTTReq2);

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   if(Srv_tiRcSttEnd < Srv_tiRcSttEnd_C)
   {
      if (     (  (DCM_MANU_Cntrl_ModeSTT == 0x00) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq1 == FALSE) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq2 == FALSE))
            || (  (DCM_MANU_Cntrl_ModeSTT == 0x01) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq1 == TRUE) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq2 == FALSE))
            || (  (DCM_MANU_Cntrl_ModeSTT == 0x02) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq1 == FALSE) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq2 == TRUE))
         )
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
   }
   else
   {
      if (     (  (DCM_MANU_Cntrl_ModeSTT == 0x00) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq1 == FALSE) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq2 == FALSE))
            || (  (DCM_MANU_Cntrl_ModeSTT == 0x01) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq1 == TRUE) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq2 == FALSE))
            || (  (DCM_MANU_Cntrl_ModeSTT == 0x02) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq1 == FALSE) &&
                  (bLocalCoPtUH_bFbSpcFactSTTReq2 == TRUE))
         )
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
      else
      {
         *Srv_bRcCdnNok_NameFunc = TRUE;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_ModeSTTAftsReq                              */
/* !Description :  Action to realize for the Routine about STT after sales    */
/*                 forced stop mode                                           */
/* !Number      :  ROUTINE_CNTRL_FCT.60                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_Cntrl_ModeSTT;                                       */
/*  output boolean Afts_bInhIniRunReq;                                        */
/*  output uint16 Srv_tiRcSttEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_ModeSTTAftsReq(void)
{
   switch(DCM_MANU_Cntrl_ModeSTT)
   {
      case 0x00:
         VEMS_vidSET(Afts_bInhIniRunReq, 0);
         break;
      case 0x01:
         VEMS_vidSET(Afts_bInhIniRunReq, 1);
         break;
      default:
         /* cas impossible */
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   Srv_tiRcSttEnd = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4ModeSTTAftsReq                          */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about STT after sales forced stop mode             */
/* !Number      :  ROUTINE_CNTRL_FCT.61                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_ModeSTTFactReq;                                   */
/*  input uint8 Srv_stRcEnd_ModeSTTBatt;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4ModeSTTAftsReq
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_ModeSTTFactReq != RC_RUNNING)
      && (Srv_stRcEnd_ModeSTTBatt != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_ModeSTTAftsReq                         */
/* !Description :  Action to indicate that the Routine about STT after sales  */
/*                 forced stop mode is finished OK or NOK                     */
/* !Number      :  ROUTINE_CNTRL_FCT.62                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Srv_tiRcSttEnd;                                              */
/*  input uint16 Srv_tiRcSttEnd_C;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_ModeSTTAftsReq
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   if(Srv_tiRcSttEnd >= Srv_tiRcSttEnd_C)
   {
      *Srv_bRcCdnOk_NameFunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_ModeSTTBatt                                 */
/* !Description :  Action to realize for the Routine about STT after sales    */
/*                 battery removal mode                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.63                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 DCM_MANU_Cntrl_ModeSTT;                                       */
/*  output boolean Afts_bInhStSoCBatt;                                        */
/*  output uint16 Srv_tiRcSttEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_ModeSTTBatt(void)
{
   switch(DCM_MANU_Cntrl_ModeSTT)
   {
      case 0x00:
         VEMS_vidSET(Afts_bInhStSoCBatt, 0);
         break;
      case 0x01:
         VEMS_vidSET(Afts_bInhStSoCBatt, 1);
         break;
      default:
         /* cas impossible */
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   Srv_tiRcSttEnd = 0;

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4ModeSTTBatt                             */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about STT after sales battery removal mode         */
/* !Number      :  ROUTINE_CNTRL_FCT.64                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_ModeSTTFactReq;                                   */
/*  input uint8 Srv_stRcEnd_ModeSTTAftsReq;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4ModeSTTBatt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalECU_bWkuMain;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_ModeSTTFactReq != RC_RUNNING)
      && (Srv_stRcEnd_ModeSTTAftsReq != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_ModeSTTBatt                            */
/* !Description :  Action to indicate that the Routine about STT after sales  */
/*                 battery removal mode is finished OK or NOK                 */
/* !Number      :  ROUTINE_CNTRL_FCT.65                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 BatMgt_stBattSoC;                                             */
/*  input uint8 ISCAN_u8N2F4F2P429;                                           */
/*  input uint16 Srv_tiRcSttEnd;                                              */
/*  input uint16 Srv_tiRcSttEnd_C;                                            */
/*  input uint8 DCM_MANU_Cntrl_ModeSTT;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_ModeSTTBatt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   uint8    u8localBatMgt_stBattSoC;
   uint8    u8localISCAN_u8N2F4F2P429;

   VEMS_vidGET(BatMgt_stBattSoC, u8localBatMgt_stBattSoC);
   VEMS_vidGET(ISCAN_u8N2F4F2P429, u8localISCAN_u8N2F4F2P429);

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   if(Srv_tiRcSttEnd < Srv_tiRcSttEnd_C)
   {
      if (     (  (DCM_MANU_Cntrl_ModeSTT == 0x00) &&
                  (u8localBatMgt_stBattSoC == u8localISCAN_u8N2F4F2P429))
            || (  (DCM_MANU_Cntrl_ModeSTT == 0x01) &&
                  (u8localBatMgt_stBattSoC != u8localISCAN_u8N2F4F2P429))
         )
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
   }
   else
   {
      if (     (  (DCM_MANU_Cntrl_ModeSTT == 0x00) &&
                  (u8localBatMgt_stBattSoC == u8localISCAN_u8N2F4F2P429))
            || (  (DCM_MANU_Cntrl_ModeSTT == 0x01) &&
                  (u8localBatMgt_stBattSoC != u8localISCAN_u8N2F4F2P429))
         )
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
      else
      {
         *Srv_bRcCdnNok_NameFunc = TRUE;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstTrbActSys                                */
/* !Description :  Action to realize for the Routine about reset TrbActSys    */
/*                 data service Waste Gate                                    */
/* !Number      :  ROUTINE_CNTRL_FCT.66                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_RcAcv_RstTrbActSys(argin uint8  */
/*  *InBuffer, argin uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType     */
/*  *ErrorCode);                                                              */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstTrbActSys(void)
{
   Std_ReturnType                status;
   uint8                         InBuffer;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   status = DCM_MANU_CALL_RcAcv_RstTrbActSys(&InBuffer,&OutBuffer, &ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer != ROUTINE_EN_COURS)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstTrbActSys                            */
/* !Description :  Action to performe the conditions to authorize or not the  */
/*                 Routine about reset TrbActSys data service Waste Gate      */
/* !Number      :  ROUTINE_CNTRL_FCT.67                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstTrbActSys
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckRcCdn_RstTrbActSys                           */
/* !Description :  Action to indicate that the Routine about reset TrbActSys  */
/*                 data service Waste Gate is finished OK or NOK              */
/* !Number      :  ROUTINE_CNTRL_FCT.68                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CALL_CheckRcCdn_RstTrbActSys(argin   */
/*  uint8 *OutBuffer, argin Dcm_NegativeResponseCodeType *ErrorCode);         */
/*  output boolean DCM_MANU_bEnaNack;                                         */
/*  output uint8 DCM_MANU_ErrorCode;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckRcCdn_RstTrbActSys
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   Std_ReturnType                status;
   uint8                         OutBuffer;
   Dcm_NegativeResponseCodeType  ErrorCode;

   *Srv_bRcCdnOk_NameFunc = FALSE;
   *Srv_bRcCdnNok_NameFunc = FALSE;

   status = DCM_MANU_CALL_CheckRcCdn_RstTrbActSys(&OutBuffer,&ErrorCode);

   if(status == E_OK)
   {
      if(OutBuffer == TERMINE_OK)
      {
         *Srv_bRcCdnOk_NameFunc = TRUE;
      }
      else if(OutBuffer == 0x00)
      {
         DCM_MANU_bEnaNack = TRUE;
         DCM_MANU_ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
      else if(OutBuffer == ROUTINE_EN_COURS)
      {
         *Srv_bRcCdnOk_NameFunc = FALSE;
         *Srv_bRcCdnNok_NameFunc = FALSE;
      }
      else
      {
         *Srv_bRcCdnNok_NameFunc = TRUE;
      }
   }
   else
   {
      DCM_MANU_bEnaNack = TRUE;
      DCM_MANU_ErrorCode = ErrorCode;
   }
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstPed                                      */
/* !Description :  Fonction liée au fonctionnel de la routine DF33            */
/* !Number      :  ROUTINE_CNTRL_FCT.69                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_AccP_EveRstPed();                               */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstPed(void)
{
   DCM_MANU_AccP_EveRstPed(); /* AccP_EveRstPed_FLrng */
   Srv_tiRcRstEnd = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstPed                                  */
/* !Description :  Fonction liée aux condiftions d'exécution de la routine    */
/*                 DF33                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.70                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstPed
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_RstPed                                      */
/* !Description :  Fonction liée aux conditions de terminaison de la routine  */
/*                 DF33                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.71                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_RstPed
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
      Srv_bRcCdnNok_NameFunc);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstReqStcBatt                               */
/* !Description :  Fonction liée au fonctionnel de la routine DF36            */
/* !Number      :  ROUTINE_CNTRL_FCT.6                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Afts_bRstReqStcBatt;                                       */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstReqStcBatt(void)
{
   VEMS_vidSET(Afts_bRstReqStcBatt, TRUE);
   Srv_tiRcRstEnd = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstReqStcBatt                           */
/* !Description :  Fonction liée aux condiftions d'exécution de la routine    */
/*                 DF36                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.2                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstReqStcBatt
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_RstReqStcBatt                               */
/* !Description :  Fonction liée aux conditions de terminaison de la routine  */
/*                 DF36                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.11                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_RstReqStcBatt
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
      Srv_bRcCdnNok_NameFunc);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_RstLrn_Misf                                 */
/* !Description :  Fonction liée au fonctionnel de la routine DF37            */
/* !Number      :  ROUTINE_CNTRL_FCT.6                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_EveRstLrn_MisfDftLrn();                         */
/*  output uint16 Srv_tiRcRstEnd;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_RstLrn_Misf(void)
{
   DCM_MANU_EveRstLrn_MisfDftLrn(); /* Misf_EveRstMisf */
   Srv_tiRcRstEnd = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4RstLrn_Misf                             */
/* !Description :  Fonction liée aux condiftions d'exécution de la routine    */
/*                 DF37                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.2                                        */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 Srv_stRcEnd_BattChg;                                          */
/*  input uint8 Srv_stRcEnd_RstCurRdB;                                        */
/*  input uint8 Srv_stRcEnd_RstCoReqRStrt;                                    */
/*  input uint8 Srv_stRcEnd_RstCluDftCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstStaCnt;                                        */
/*  input uint8 Srv_stRcEnd_RstESLim;                                         */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCnt;                                   */
/*  input uint8 Srv_stRcEnd_RstMnfDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstTrbDmgCnt;                                     */
/*  input uint8 Srv_stRcEnd_RstDfwChg;                                        */
/*  input uint8 Srv_stRcEnd_RstAFAMgtT;                                       */
/*  input uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;                               */
/*  input uint8 Srv_stRcEnd_RstTrbActSys;                                     */
/*  input uint8 Srv_stRcEnd_RstReqStcBatt;                                    */
/*  input uint8 Srv_stRcEnd_RstPed;                                           */
/*  input uint8 Srv_stRcEnd_RstLrn_Misf;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4RstLrn_Misf
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   uint8    u8localCoPTSt_stEng;
   uint16   u16localspdveh;
   uint16   u16localspdvehmul;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   u16localspdvehmul = (uint16)(Diag_seuil_vit_veh * 128);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= u16localspdvehmul)
      && (bLocalextbrun == FALSE)
      && (u8localCoPTSt_stEng == 1)
      && (bLocalECU_bWkuMain == TRUE)
      && (Srv_stRcEnd_BattChg != RC_RUNNING)
      && (Srv_stRcEnd_RstCurRdB != RC_RUNNING)
      && (Srv_stRcEnd_RstCoReqRStrt != RC_RUNNING)
      && (Srv_stRcEnd_RstCluDftCnt != RC_RUNNING)
      && (Srv_stRcEnd_RstStaCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstESLim!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstMnfDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbDmgCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstDfwChg!= RC_RUNNING)
      && (Srv_stRcEnd_RstAFAMgtT!= RC_RUNNING)
      && (Srv_stRcEnd_RstCylHdDmgCplmCnt!= RC_RUNNING)
      && (Srv_stRcEnd_RstTrbActSys != RC_RUNNING)
      && (Srv_stRcEnd_RstReqStcBatt != RC_RUNNING)
      && (Srv_stRcEnd_RstPed != RC_RUNNING)
      && (Srv_stRcEnd_RstLrn_Misf != RC_RUNNING)
   )
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_RstLrn_Misf                                 */
/* !Description :  Fonction liée aux conditions de terminaison de la routine  */
/*                 DF37                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.11                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_CheckRcCdn_tiRcRstEnd(argin boolean             */
/*  *Srv_bRcCdnOk_NameFunc, argin boolean *Srv_bRcCdnNok_NameFunc);           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_RstLrn_Misf
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   DCM_MANU_CheckRcCdn_tiRcRstEnd(Srv_bRcCdnOk_NameFunc,
      Srv_bRcCdnNok_NameFunc);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckCond4InhBoostGDI                             */
/* !Description :  Fonction liée aux condiftions d'exécution de la routine    */
/*                 DFA2                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.77                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Thr_bEndTestInh_CpuSfty;                                    */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CheckCond4InhBoostGDI
(
   boolean* Srv_bRcCondOk_Namefunc
)
{
   boolean  bLocalextbrun;
   boolean  bLocalECU_bWkuMain;
   boolean  bLocalThr_bEndTestInh_CpuSfty;
   boolean  bLocalInhRcBoostGDI;
   uint16   u16localspdveh;
   uint8    u8localCoPTSt_stEng;

   VEMS_vidGET(Ext_bRun, bLocalextbrun);
   VEMS_vidGET(Veh_spdVeh, u16localspdveh);
   VEMS_vidGET(CoPTSt_stEng, u8localCoPTSt_stEng);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(Thr_bEndTestInh_CpuSfty, bLocalThr_bEndTestInh_CpuSfty);
   bLocalInhRcBoostGDI = GDGAR_bGetFRM(FRM_FRM_INHRCBOOSTGDI);

   *Srv_bRcCondOk_Namefunc = FALSE;

   if(( u16localspdveh <= (uint16)(Diag_seuil_vit_veh * 128))
      &&(FALSE == bLocalextbrun)
      &&( u8localCoPTSt_stEng == 1)
      &&( bLocalECU_bWkuMain == TRUE)
      &&( bLocalThr_bEndTestInh_CpuSfty == 1)
      &&( bLocalInhRcBoostGDI == 0))
   {
      *Srv_bRcCondOk_Namefunc = TRUE;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcAcv_InhBoostGDI                                 */
/* !Description :  Fonction liée au fonctionnel de la routine DFA2            */
/* !Number      :  ROUTINE_CNTRL_FCT.78                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 DCM_MANU_Cntrl_Inhibition;                                    */
/*  output boolean Srv_bInhBoostGDI;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcAcv_InhBoostGDI(void)
{
   if(DCM_MANU_Cntrl_Inhibition == 0xFF)
   {
      VEMS_vidSET(Srv_bInhBoostGDI, TRUE);
   }
   else
   {
      VEMS_vidSET(Srv_bInhBoostGDI, FALSE);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_RcCdn_InhBoostGDI                                 */
/* !Description :  Fonction liée aux conditions de terminaison de la routine  */
/*                 DFA2                                                       */
/* !Number      :  ROUTINE_CNTRL_FCT.79                                       */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_RcCdn_InhBoostGDI
(
   boolean* Srv_bRcCdnOk_NameFunc,
   boolean* Srv_bRcCdnNok_NameFunc
)
{
   *Srv_bRcCdnOk_NameFunc = TRUE;
}
