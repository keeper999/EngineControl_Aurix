/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TUNCFG                                                  */
/* !Description     : TUNCFG component.                                       */
/*                                                                            */
/* !Module          : TUNCFG                                                  */
/* !Description     : GESTION DES DIVERSITES                                  */
/*                                                                            */
/* !File            : TUNCFG_FCT1.C                                           */
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
/*   1 / TUNCFG_vidTunCfg                                                     */
/*   2 / TUNCFG_vidTunCfg1                                                    */
/*   3 / TUNCFG_vidProdCfg                                                    */
/*   4 / TUNCFG_vidFRICSel                                                    */
/*   5 / TUNCFG_vidCLIMSel                                                    */
/*   6 / TUNCFG_vidBVSel                                                      */
/*   7 / TUNCFG_vidALTSel                                                     */
/*   8 / TUNCFG_vidCARSel                                                     */
/*   9 / TUNCFG_vidCHASel                                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5304544 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TUNCFG/TUNCFG_FCT1.C_v          $*/
/* $Revision::   1.17     $$Author::   pbakabad       $$Date::   Jun 28 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 28 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TUNCFG.h"
#include "TUNCFG_L.h"
#include "TUNCFG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidTunCfg                                           */
/* !Description :  Configuration des variables: type  de  carburant ,  nombre */
/*                 de  cylindres  ainsi que le type de boite automatique ou   */
/*                 piloté                                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_001.04                                     */
/*                 VEMS_R_11_02421_002.01                                     */
/*                 VEMS_R_11_02421_003.01                                     */
/*                 VEMS_R_11_02421_004.01                                     */
/*                 VEMS_R_11_02421_005.02                                     */
/*                 VEMS_R_11_02421_006.01                                     */
/*                 VEMS_R_11_02421_007.01                                     */
/*                 VEMS_R_11_02421_008.01                                     */
/*                 VEMS_R_11_02421_009.03                                     */
/*                 VEMS_R_11_02421_010.01                                     */
/*                 VEMS_R_11_02421_011.01                                     */
/*                 VEMS_R_11_02421_012.01                                     */
/*                 VEMS_R_11_02421_013.02                                     */
/*                 VEMS_R_11_02421_014.01                                     */
/*                 VEMS_R_11_02421_015.02                                     */
/*                 VEMS_R_11_02421_025.02                                     */
/*                 VEMS_R_11_02421_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stFuTypCf_C;                                              */
/*  input boolean Ext_bCf_nAvrFrntWhl_C;                                      */
/*  input boolean Ext_bFilCf_spdVehAvrFrntWhl_C;                              */
/*  input boolean Ext_bSTTCf_C;                                               */
/*  input boolean Ext_bArchiCf_C;                                             */
/*  input boolean Ext_bTTCf_C;                                                */
/*  input boolean Ext_bStrtDrvIfTypCf_C;                                      */
/*  input boolean Ext_bTyreWarnCf_C;                                          */
/*  input boolean Ext_bLowFuelLevelSel_C;                                     */
/*  input boolean Ext_bPresExCmSen_C;                                         */
/*  input boolean Ext_bPresInCmSen_C;                                         */
/*  input boolean Ext_bPresEGRVlv_C;                                          */
/*  input boolean Cf_bSecBrkPedPrss_C;                                        */
/*  input boolean Cf_bSecBrkPedPrssDiag_C;                                    */
/*  input boolean Ext_bPresGaz_C;                                             */
/*  input uint8 Ext_stStaCf_C;                                                */
/*  input uint8 Ext_stVSSCf_C;                                                */
/*  input boolean Ext_bCoReqVehCf_bEngStrtReq_C;                              */
/*  input uint8 Ext_stBattTypCf_C;                                            */
/*  input boolean Ext_bElASRESPCf_C;                                          */
/*  input boolean Ext_bVSMaxfCf_C;                                            */
/*  input uint8 Ext_stElEMgtCf_C;                                             */
/*  input uint8 Ext_stDrivAltMgt_Cf_C;                                        */
/*  input boolean Ext_bBrkMainInfoCf_C;                                       */
/*  input boolean Ext_bFanDiagCf_C;                                           */
/*  input boolean Ext_bOilLvlCf_C;                                            */
/*  input boolean Ext_bSpdCf_C;                                               */
/*  input uint8 Ext_stEOBDCf_C;                                               */
/*  input boolean Ext_bDftLogCf_C;                                            */
/*  input uint8 Ext_stECUTypCf_C;                                             */
/*  input boolean Ext_bG3G4Cf_C;                                              */
/*  input uint8 Ext_stStrtRstrtDevCf_C;                                       */
/*  input uint8 Ext_stUcapTypCf_C;                                            */
/*  input boolean Ext_bBrkDiagRelbCf_C;                                       */
/*  input boolean Ext_bDAE_DAEHCf_C;                                          */
/*  input uint8 Ext_stTypInjSysCf_C;                                          */
/*  input uint8 Ext_stOilTCf_C;                                               */
/*  input uint8 Ext_stStgPmpCf_C;                                             */
/*  input boolean Ext_bACCf_C;                                                */
/*  input boolean Ext_bASECf_C;                                               */
/*  input boolean Ext_bReadBrkParkCf_C;                                       */
/*  input uint8 Ext_stOilPresCf_C;                                            */
/*  output uint8 Ext_noCylEng;                                                */
/*  output uint8 Ext_stFuTypCf;                                               */
/*  output boolean Ext_bCf_nAvrFrntWhl;                                       */
/*  output boolean Ext_bCf_nAvrFrntWhl_C;                                     */
/*  output boolean Ext_bFilCf_spdVehAvrFrntWhl;                               */
/*  output boolean Ext_bFilCf_spdVehAvrFrntWhl_C;                             */
/*  output boolean Ext_bSTTCf;                                                */
/*  output boolean Ext_bSTTCf_C;                                              */
/*  output boolean CoSTT_bAcv;                                                */
/*  output boolean Ext_bArchiCf;                                              */
/*  output boolean Ext_bArchiCf_C;                                            */
/*  output boolean Ext_bTTCf;                                                 */
/*  output boolean Ext_bTTCf_C;                                               */
/*  output boolean Ext_bStrtDrvIfTypCf;                                       */
/*  output boolean Ext_bStrtDrvIfTypCf_C;                                     */
/*  output boolean Ext_bTyreWarnCf;                                           */
/*  output boolean Ext_bTyreWarnCf_C;                                         */
/*  output boolean Ext_bLowFuelLevelSel;                                      */
/*  output boolean Ext_bLowFuelLevelSel_C;                                    */
/*  output boolean Ext_bPresExCmSen;                                          */
/*  output boolean Ext_bPresExCmSen_C;                                        */
/*  output boolean Ext_bPresInCmSen;                                          */
/*  output boolean Ext_bPresInCmSen_C;                                        */
/*  output boolean Ext_bPresEGRVlv;                                           */
/*  output boolean Ext_bPresEGRVlv_C;                                         */
/*  output boolean Cf_bSecBrkPedPrss;                                         */
/*  output boolean Cf_bSecBrkPedPrss_C;                                       */
/*  output boolean Cf_bSecBrkPedPrssDiag;                                     */
/*  output boolean Cf_bSecBrkPedPrssDiag_C;                                   */
/*  output boolean Ext_bPresGaz;                                              */
/*  output boolean Ext_bPresGaz_C;                                            */
/*  output uint8 Ext_stStaCf;                                                 */
/*  output uint8 Ext_stVSSCf;                                                 */
/*  output boolean Ext_bCoReqVehCf_bEngStrtReq;                               */
/*  output boolean Ext_bCoReqVehCf_bEngStrtReq_C;                             */
/*  output uint8 Ext_stBattTypCf;                                             */
/*  output boolean Ext_bElASRESPCf;                                           */
/*  output boolean Ext_bElASRESPCf_C;                                         */
/*  output boolean Ext_bVSMaxfCf;                                             */
/*  output boolean Ext_bVSMaxfCf_C;                                           */
/*  output uint8 Ext_stElEMgtCf;                                              */
/*  output uint8 Ext_stDrivAltMgt_Cf;                                         */
/*  output boolean Ext_bBrkMainInfoCf;                                        */
/*  output boolean Ext_bBrkMainInfoCf_C;                                      */
/*  output boolean Ext_bFanDiagCf;                                            */
/*  output boolean Ext_bFanDiagCf_C;                                          */
/*  output boolean Ext_bOilLvlCf;                                             */
/*  output boolean Ext_bOilLvlCf_C;                                           */
/*  output boolean Ext_bSpdCf;                                                */
/*  output boolean Ext_bSpdCf_C;                                              */
/*  output uint8 Ext_stEOBDCf;                                                */
/*  output uint8 Ext_stEOBDCf_C;                                              */
/*  output boolean Ext_bDftLogCf;                                             */
/*  output boolean Ext_bDftLogCf_C;                                           */
/*  output uint8 Ext_stECUTypCf;                                              */
/*  output boolean Ext_bG3G4Cf;                                               */
/*  output boolean Ext_bG3G4Cf_C;                                             */
/*  output uint8 Ext_stStrtRstrtDevCf;                                        */
/*  output uint8 Ext_stUcapTypCf;                                             */
/*  output boolean Ext_bBrkDiagRelbCf;                                        */
/*  output boolean Ext_bBrkDiagRelbCf_C;                                      */
/*  output boolean Ext_bDAE_DAEHCf;                                           */
/*  output boolean Ext_bDAE_DAEHCf_C;                                         */
/*  output uint8 Ext_stTypInjSysCf;                                           */
/*  output uint8 Ext_stOilTCf;                                                */
/*  output uint8 Ext_stStgPmpCf;                                              */
/*  output boolean Ext_bACCf;                                                 */
/*  output boolean Ext_bACCf_C;                                               */
/*  output boolean Ext_bASECf;                                                */
/*  output boolean Ext_bASECf_C;                                              */
/*  output boolean Ext_bReadBrkParkCf;                                        */
/*  output boolean Ext_bReadBrkParkCf_C;                                      */
/*  output uint8 Ext_stOilPresCf;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidTunCfg(void)
{
   uint8 u8LocalExt_stFuTypCf;
   uint8 u8LocalExt_stBattTypCf;
   uint8 u8LocalExt_stStaCf;
   uint8 u8LocalExt_stVSSCf;
   uint8 u8LocalExt_stElEMgtCf;
   uint8 u8LocalExt_stUcapTypCf;
   uint8 u8LocalExt_stOilTCf;
   uint8 u8LocalExt_stDrivAltMgt;
   uint8 u8LocalExt_stTypInjSysCf;
   uint8 u8LocalExt_stECUTypCf;
   uint8 u8LocalExt_stStrtRstrtDevCf;
   uint8 u8LocalExt_stStgPmpCf;
   uint8 u8LocalExt_stOilPresCf;


   VEMS_vidSET(Ext_noCylEng, Ext_noCylEng_SC);

   u8LocalExt_stFuTypCf = (uint8)MATHSRV_udtMIN(Ext_stFuTypCf_C, 7);
   VEMS_vidSET(Ext_stFuTypCf, u8LocalExt_stFuTypCf);

   VEMS_vidSET(Ext_bCf_nAvrFrntWhl, Ext_bCf_nAvrFrntWhl_C);

   VEMS_vidSET(Ext_bFilCf_spdVehAvrFrntWhl, Ext_bFilCf_spdVehAvrFrntWhl_C);

   VEMS_vidSET(Ext_bSTTCf, Ext_bSTTCf_C);

   VEMS_vidSET(CoSTT_bAcv, Ext_bSTTCf_C);

   VEMS_vidSET(Ext_bArchiCf, Ext_bArchiCf_C);

   VEMS_vidSET(Ext_bTTCf, Ext_bTTCf_C);

   VEMS_vidSET(Ext_bStrtDrvIfTypCf, Ext_bStrtDrvIfTypCf_C);

   VEMS_vidSET(Ext_bTyreWarnCf, Ext_bTyreWarnCf_C);

   VEMS_vidSET(Ext_bLowFuelLevelSel, Ext_bLowFuelLevelSel_C);

   VEMS_vidSET(Ext_bPresExCmSen, Ext_bPresExCmSen_C);

   VEMS_vidSET(Ext_bPresInCmSen, Ext_bPresInCmSen_C);

   VEMS_vidSET(Ext_bPresEGRVlv, Ext_bPresEGRVlv_C);

   VEMS_vidSET(Cf_bSecBrkPedPrss, Cf_bSecBrkPedPrss_C);

   VEMS_vidSET(Cf_bSecBrkPedPrssDiag, Cf_bSecBrkPedPrssDiag_C);

   VEMS_vidSET(Ext_bPresGaz, Ext_bPresGaz_C);

   u8LocalExt_stStaCf = (uint8)MATHSRV_udtMIN(Ext_stStaCf_C ,7);
   VEMS_vidSET(Ext_stStaCf, u8LocalExt_stStaCf);

   u8LocalExt_stVSSCf = (uint8)MATHSRV_udtMIN(Ext_stVSSCf_C ,3);
   VEMS_vidSET(Ext_stVSSCf, u8LocalExt_stVSSCf);

   VEMS_vidSET(Ext_bCoReqVehCf_bEngStrtReq, Ext_bCoReqVehCf_bEngStrtReq_C);

   u8LocalExt_stBattTypCf = (uint8)MATHSRV_udtMIN(Ext_stBattTypCf_C ,15);
   VEMS_vidSET(Ext_stBattTypCf, u8LocalExt_stBattTypCf);

   VEMS_vidSET(Ext_bElASRESPCf, Ext_bElASRESPCf_C);

   VEMS_vidSET(Ext_bVSMaxfCf, Ext_bVSMaxfCf_C);

   u8LocalExt_stElEMgtCf = (uint8)MATHSRV_udtMIN(Ext_stElEMgtCf_C ,7);
   VEMS_vidSET(Ext_stElEMgtCf, u8LocalExt_stElEMgtCf);

   u8LocalExt_stDrivAltMgt = (uint8)MATHSRV_udtMIN(Ext_stDrivAltMgt_Cf_C ,3);
   VEMS_vidSET(Ext_stDrivAltMgt_Cf ,u8LocalExt_stDrivAltMgt );

   VEMS_vidSET(Ext_bBrkMainInfoCf, Ext_bBrkMainInfoCf_C);

   VEMS_vidSET(Ext_bFanDiagCf, Ext_bFanDiagCf_C);

   VEMS_vidSET(Ext_bOilLvlCf, Ext_bOilLvlCf_C);

   VEMS_vidSET(Ext_bSpdCf, Ext_bSpdCf_C);

   VEMS_vidSET(Ext_stEOBDCf, Ext_stEOBDCf_C);

   VEMS_vidSET(Ext_bDftLogCf, Ext_bDftLogCf_C);

   u8LocalExt_stECUTypCf = (uint8)MATHSRV_udtMIN(Ext_stECUTypCf_C, 2);
   VEMS_vidSET(Ext_stECUTypCf, u8LocalExt_stECUTypCf);

   VEMS_vidSET(Ext_bG3G4Cf, Ext_bG3G4Cf_C);
   u8LocalExt_stStrtRstrtDevCf =
      (uint8)MATHSRV_udtMIN(Ext_stStrtRstrtDevCf_C, 8);
   VEMS_vidSET(Ext_stStrtRstrtDevCf, u8LocalExt_stStrtRstrtDevCf);

   u8LocalExt_stUcapTypCf = (uint8)MATHSRV_udtMIN(Ext_stUcapTypCf_C ,7);
   VEMS_vidSET(Ext_stUcapTypCf, u8LocalExt_stUcapTypCf);

   VEMS_vidSET(Ext_bBrkDiagRelbCf, Ext_bBrkDiagRelbCf_C);

   VEMS_vidSET(Ext_bDAE_DAEHCf, Ext_bDAE_DAEHCf_C);

   u8LocalExt_stTypInjSysCf = (uint8)MATHSRV_udtMIN(Ext_stTypInjSysCf_C ,7);
   VEMS_vidSET(Ext_stTypInjSysCf, u8LocalExt_stTypInjSysCf);

   u8LocalExt_stOilTCf = (uint8)MATHSRV_udtMIN(Ext_stOilTCf_C ,2);
   VEMS_vidSET(Ext_stOilTCf, u8LocalExt_stOilTCf);

   u8LocalExt_stStgPmpCf = (uint8)MATHSRV_udtMIN(Ext_stStgPmpCf_C ,7);
   VEMS_vidSET(Ext_stStgPmpCf, u8LocalExt_stStgPmpCf);

   VEMS_vidSET(Ext_bACCf, Ext_bACCf_C);

   VEMS_vidSET(Ext_bASECf, Ext_bASECf_C);

   VEMS_vidSET(Ext_bReadBrkParkCf, Ext_bReadBrkParkCf_C);

   u8LocalExt_stOilPresCf = (uint8)MATHSRV_udtMIN(Ext_stOilPresCf_C ,2);
   VEMS_vidSET(Ext_stOilPresCf, u8LocalExt_stOilPresCf);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidTunCfg1                                          */
/* !Description :  Configuration des variables: type  de  carburant ,  nombre */
/*                 de  cylindres  ainsi que le type de boite automatique ou   */
/*                 piloté                                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_001.04                                     */
/*                 VEMS_R_11_02421_002.01                                     */
/*                 VEMS_R_11_02421_003.01                                     */
/*                 VEMS_R_11_02421_004.01                                     */
/*                 VEMS_R_11_02421_005.02                                     */
/*                 VEMS_R_11_02421_006.01                                     */
/*                 VEMS_R_11_02421_007.01                                     */
/*                 VEMS_R_11_02421_008.01                                     */
/*                 VEMS_R_11_02421_009.03                                     */
/*                 VEMS_R_11_02421_010.01                                     */
/*                 VEMS_R_11_02421_011.01                                     */
/*                 VEMS_R_11_02421_012.01                                     */
/*                 VEMS_R_11_02421_013.02                                     */
/*                 VEMS_R_11_02421_014.01                                     */
/*                 VEMS_R_11_02421_015.02                                     */
/*                 VEMS_R_11_02421_025.02                                     */
/*                 VEMS_R_11_02421_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cf_bPresPAirExtSens_C;                                      */
/*  input boolean Ctrl_bSelWgCmdSpCf_C;                                       */
/*  input boolean Ext_bEngTrbMode_C;                                          */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng_C;                                  */
/*  input boolean Ext_bCf_nAvrFrntWhl_C;                                      */
/*  input boolean Ext_bPACKDYNCf_C;                                           */
/*  input uint16 Ext_facRatTqAltCf_C;                                         */
/*  input boolean Ext_bCtlCmdPTTqCf_C;                                        */
/*  input boolean Ext_bDetLoWhlGripCf_C;                                      */
/*  input boolean Ext_bTqWhlBrkCf_C;                                          */
/*  input boolean Ext_bVSMaxsCf_C;                                            */
/*  input uint8 Ext_stPTCf_C;                                                 */
/*  input boolean Ext_bBrkAutoCf_C;                                           */
/*  input boolean Ext_stDirMoveVehCf_C;                                       */
/*  input boolean Ctrl_bTraNoTarGear_C;                                       */
/*  input boolean Ext_bEgrCf_C;                                               */
/*  input uint8 Ext_stVSCtlRegCf_C;                                           */
/*  output boolean Cf_bPresPAirExtSens;                                       */
/*  output boolean Cf_bPresPAirExtSens_C;                                     */
/*  output boolean Ctrl_bSelWgCmdSpCf;                                        */
/*  output boolean Ctrl_bSelWgCmdSpCf_C;                                      */
/*  output boolean Ext_bEngTrbMode;                                           */
/*  output boolean Ext_bEngTrbMode_C;                                         */
/*  output boolean EcuSt_bAcvRcdMod_EcuMng;                                   */
/*  output boolean EcuSt_bAcvRcdMod_EcuMng_C;                                 */
/*  output boolean Ext_bRotSpdFrntWhlCf;                                      */
/*  output boolean Ext_bCf_nAvrFrntWhl_C;                                     */
/*  output boolean Ext_bPACKDYNCf;                                            */
/*  output boolean Ext_bPACKDYNCf_C;                                          */
/*  output uint16 Ext_facRatTqAltCf;                                          */
/*  output boolean Ext_bCtlCmdPTTqCf;                                         */
/*  output boolean Ext_bCtlCmdPTTqCf_C;                                       */
/*  output boolean Ext_bDetLoWhlGripCf;                                       */
/*  output boolean Ext_bDetLoWhlGripCf_C;                                     */
/*  output boolean Ext_bTqWhlBrkCf;                                           */
/*  output boolean Ext_bTqWhlBrkCf_C;                                         */
/*  output boolean Ext_bVSMaxsCf;                                             */
/*  output boolean Ext_bVSMaxsCf_C;                                           */
/*  output uint8 Ext_stPTCf;                                                  */
/*  output boolean Ext_bBrkAutoCf;                                            */
/*  output boolean Ext_bBrkAutoCf_C;                                          */
/*  output boolean Ext_stDirMoveVehCf;                                        */
/*  output boolean Ext_stDirMoveVehCf_C;                                      */
/*  output boolean Ctrl_bTraNoTarGear;                                        */
/*  output boolean Ctrl_bTraNoTarGear_C;                                      */
/*  output boolean Ext_bEgrCf;                                                */
/*  output boolean Ext_bEgrCf_C;                                              */
/*  output uint8 Ext_stVSCtlRegCf;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidTunCfg1(void)
{
   uint8  u8LocalExt_stPTCf;
   uint8  u8LocalExt_stVSCtlRegCf;
   uint16 u16LocalExt_facRatTqAltCf;


   VEMS_vidSET(Cf_bPresPAirExtSens, Cf_bPresPAirExtSens_C);

   VEMS_vidSET(Ctrl_bSelWgCmdSpCf, Ctrl_bSelWgCmdSpCf_C);

   VEMS_vidSET(Ext_bEngTrbMode, Ext_bEngTrbMode_C);

   VEMS_vidSET(EcuSt_bAcvRcdMod_EcuMng, EcuSt_bAcvRcdMod_EcuMng_C);

   VEMS_vidSET(Ext_bRotSpdFrntWhlCf, Ext_bCf_nAvrFrntWhl_C);

   VEMS_vidSET(Ext_bPACKDYNCf, Ext_bPACKDYNCf_C);

   u16LocalExt_facRatTqAltCf =
      (uint16)MATHSRV_udtMIN(Ext_facRatTqAltCf_C ,1280);
   VEMS_vidSET(Ext_facRatTqAltCf, u16LocalExt_facRatTqAltCf);

   VEMS_vidSET(Ext_bCtlCmdPTTqCf, Ext_bCtlCmdPTTqCf_C);
   VEMS_vidSET(Ext_bDetLoWhlGripCf, Ext_bDetLoWhlGripCf_C);
   VEMS_vidSET(Ext_bTqWhlBrkCf, Ext_bTqWhlBrkCf_C);
   VEMS_vidSET(Ext_bVSMaxsCf, Ext_bVSMaxsCf_C);

   u8LocalExt_stPTCf = (uint8)MATHSRV_udtMIN(Ext_stPTCf_C ,2);
   VEMS_vidSET(Ext_stPTCf, u8LocalExt_stPTCf);

   VEMS_vidSET(Ext_bBrkAutoCf, Ext_bBrkAutoCf_C);

   VEMS_vidSET(Ext_stDirMoveVehCf, Ext_stDirMoveVehCf_C);

   VEMS_vidSET(Ctrl_bTraNoTarGear, Ctrl_bTraNoTarGear_C);
   VEMS_vidSET(Ext_bEgrCf, Ext_bEgrCf_C);

   u8LocalExt_stVSCtlRegCf = (uint8)MATHSRV_udtMIN(Ext_stVSCtlRegCf_C ,3);
   VEMS_vidSET(Ext_stVSCtlRegCf, u8LocalExt_stVSCtlRegCf);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidProdCfg                                          */
/* !Description :  Appel des fonctions de configuration des sorties CMM  par  */
/*                 défaut                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TUNCFG_vidFRICSel();                                     */
/*  extf argret void TUNCFG_vidCLIMSel();                                     */
/*  extf argret void TUNCFG_vidBVSel();                                       */
/*  extf argret void TUNCFG_vidALTSel();                                      */
/*  extf argret void TUNCFG_vidCARSel();                                      */
/*  extf argret void TUNCFG_vidCHASel();                                      */
/*  extf argret void TUNCFG_vidUCSelLsb();                                    */
/*  extf argret void TUNCFG_vidUCSelMsb();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidProdCfg(void)
{
   TUNCFG_vidFRICSel();
   TUNCFG_vidCLIMSel();
   TUNCFG_vidBVSel();
   TUNCFG_vidALTSel();
   TUNCFG_vidCARSel();
   TUNCFG_vidCHASel();
   TUNCFG_vidUCSelLsb();
   TUNCFG_vidUCSelMsb();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidFRICSel                                          */
/* !Description :  configuration des sorties CMM  par défaut Partie Fric      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Tele_program_fric;                                            */
/*  input bool EQUIPMENT_A;                                                   */
/*  input bool EQUIPMENT_B1;                                                  */
/*  input bool EQUIPMENT_C;                                                   */
/*  input bool EQUIPMENT_B2;                                                  */
/*  output st45 Cf_cooling_fan_equipment;                                     */
/*  output bool EQUIPMENT_A;                                                  */
/*  output uint8 Ext_stCfFan;                                                 */
/*  output bool EQUIPMENT_B1;                                                 */
/*  output bool EQUIPMENT_C;                                                  */
/*  output bool EQUIPMENT_B2;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidFRICSel(void)
{
   uint8 u8LocalTele_fric;


   VEMS_vidGET(Tele_program_fric, u8LocalTele_fric);
   switch (u8LocalTele_fric)
   {
      case FRIC_EQUIPMENT_A:
         VEMS_vidSET(Cf_cooling_fan_equipment, EQUIPMENT_A);
         VEMS_vidSET(Ext_stCfFan, 1);
         break;

      case FRIC_EQUIPMENT_B1:
         VEMS_vidSET(Cf_cooling_fan_equipment, EQUIPMENT_B1);
         VEMS_vidSET(Ext_stCfFan, 0);
         break;

      case FRIC_EQUIPMENT_C:
         VEMS_vidSET(Cf_cooling_fan_equipment, EQUIPMENT_C);
         VEMS_vidSET(Ext_stCfFan, 3);
         break;

      case FRIC_EQUIPMENT_B2:
         VEMS_vidSET(Cf_cooling_fan_equipment, EQUIPMENT_B2);
         VEMS_vidSET(Ext_stCfFan, 1);
         break;

      default:
         VEMS_vidSET(Cf_cooling_fan_equipment, EQUIPMENT_B1);
         VEMS_vidSET(Ext_stCfFan, 1);
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidCLIMSel                                          */
/* !Description :  Le type de climatisation est sélectionné parmis les types  */
/*                 possibles par télécodage.                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Tele_program_press_clim;                                      */
/*  output boolean Cl_config_pression_refri_3;                                */
/*  output boolean Cl_config_pression_refri_0;                                */
/*  output uint8 Ext_stACTypCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidCLIMSel(void)
{
   uint8 u8LocalTele_press_clim;


   VEMS_vidGET(Tele_program_press_clim, u8LocalTele_press_clim);
   switch (u8LocalTele_press_clim)
   {
      case PRESS_CLIM_CONFIG_3:
         VEMS_vidSET(Cl_config_pression_refri_3, 1);
         VEMS_vidSET(Cl_config_pression_refri_0, 0);
         VEMS_vidSET(Ext_stACTypCf, 2);
         break;

      case PRESS_CLIM_CONFIG_0:
         VEMS_vidSET(Cl_config_pression_refri_3, 0);
         VEMS_vidSET(Cl_config_pression_refri_0, 1);
         VEMS_vidSET(Ext_stACTypCf, 0);
         break;

      default:
         VEMS_vidSET(Cl_config_pression_refri_3, 1);
         VEMS_vidSET(Cl_config_pression_refri_0, 0);
         VEMS_vidSET(Ext_stACTypCf, 1);
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidBVSel                                            */
/* !Description :  configuration des sorties CMM  par défaut, Partie boîte de */
/*                 vitesse                                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Tele_program_gear_box;                                        */
/*  input boolean TunCfg_bva_kickdown_C;                                      */
/*  input boolean TunCfg_bvmp_kickdown_C;                                     */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 Ext_stTraTypCf;                                               */
/*  input uint8 Ext_stCtlCmdPTTqPot_C;                                        */
/*  output uint8 Ext_stTraTypCf;                                              */
/*  output uint8 Ext_stGBxCf;                                                 */
/*  output boolean Presence_bvmp;                                             */
/*  output boolean Presence_bva;                                              */
/*  output boolean Presence_bva_pt_dur;                                       */
/*  output boolean Presence_bvmp_pt_dur;                                      */
/*  output boolean Ext_bPosnGBxCf;                                            */
/*  output boolean Ext_bRatConvTraCf;                                         */
/*  output uint8 Ext_stCtlCmdPTTqPotCf;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidBVSel(void)
{
   boolean bLocalPresence_bvmp;
   boolean bLocalPresence_bva;
   boolean bLocalPresenceBvaPtDur;
   boolean bLocalPresenceBvmpPtDur;
   uint8   u8LocalTele_gear_box;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalExt_stTraTypCf;
   uint8   u8LocalExtCtlCmdPTTqPotCf;


   VEMS_vidGET(Tele_program_gear_box, u8LocalTele_gear_box);
   bLocalPresence_bvmp = 0;
   bLocalPresence_bva = 0;
   switch (u8LocalTele_gear_box)
   {
      case PRESENCE_BV_BE:
         VEMS_vidSET(Ext_stTraTypCf, BVM_BE);
         break;

      case PRESENCE_BV_MCM:
         VEMS_vidSET(Ext_stTraTypCf, BVM_MCM);
         break;

      case PRESENCE_BV_MCP:
         VEMS_vidSET(Ext_stTraTypCf, BVMP_MCP);
         bLocalPresence_bvmp = 1;
         break;

      case PRESENCE_BV_DCT:
         VEMS_vidSET(Ext_stTraTypCf, BVA_DCT);
         bLocalPresence_bvmp = 1;
         break;

      case PRESENCE_BV_AT6:
         VEMS_vidSET(Ext_stTraTypCf, BVA_AT6);
         bLocalPresence_bva = 1;
         break;

      default:
         VEMS_vidSET(Ext_stTraTypCf, BVM_BE);
         break;
   }
   if (bLocalPresence_bva != 0)
   {
      VEMS_vidSET(Ext_stGBxCf, 1);
   }
   else
   {
      if (bLocalPresence_bvmp != 0)
      {
         VEMS_vidSET(Ext_stGBxCf, 2);
      }
      else
      {
         VEMS_vidSET(Ext_stGBxCf, 0);
      }
   }
   VEMS_vidSET(Presence_bvmp, bLocalPresence_bvmp);
   VEMS_vidSET(Presence_bva, bLocalPresence_bva);

   if (TunCfg_bva_kickdown_C != 0)
   {
      bLocalPresenceBvaPtDur = bLocalPresence_bva;
   }
   else
   {
      bLocalPresenceBvaPtDur = 0;
   }

   if (TunCfg_bvmp_kickdown_C != 0)
   {
      bLocalPresenceBvmpPtDur = bLocalPresence_bvmp;
   }
   else
   {
      bLocalPresenceBvmpPtDur = 0;
   }
   VEMS_vidSET(Presence_bva_pt_dur, bLocalPresenceBvaPtDur);
   VEMS_vidSET(Presence_bvmp_pt_dur, bLocalPresenceBvmpPtDur);

   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (u8LocalExt_stGBxCf == 0)
   {
      VEMS_vidSET(Ext_bPosnGBxCf, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bPosnGBxCf, 1);
   }

   VEMS_vidGET(Ext_stTraTypCf, u8LocalExt_stTraTypCf);
   if (u8LocalExt_stTraTypCf == 1)
   {
      VEMS_vidSET(Ext_bRatConvTraCf, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bRatConvTraCf, 0);
   }

   if (u8LocalExt_stTraTypCf == 7)
   {
      u8LocalExtCtlCmdPTTqPotCf = 0;
   }
   else
   {
      if (u8LocalExt_stTraTypCf == 4)
      {
         u8LocalExtCtlCmdPTTqPotCf = 1;
      }
      else
      {
         u8LocalExtCtlCmdPTTqPotCf =
            (uint8)MATHSRV_udtMIN(Ext_stCtlCmdPTTqPot_C ,3);
      }
   }
   VEMS_vidSET(Ext_stCtlCmdPTTqPotCf, u8LocalExtCtlCmdPTTqPotCf);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidALTSel                                           */
/* !Description :  configuration des sorties CMM  par défaut , Partie         */
/*                 Alternateur                                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_019.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tele_program_alternator;                                     */
/*  output uint8 Ext_stAltClasVarCf;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidALTSel(void)
{
   uint16 u16LocalTele_alternator;


   VEMS_vidGET(Tele_program_alternator, u16LocalTele_alternator);
   switch (u16LocalTele_alternator)
   {
      case ALT_CLASSE_8p:
         VEMS_vidSET(Ext_stAltClasVarCf, ALTERNATEUR_8p);
         break;

      case ALT_CLASSE_12:
         VEMS_vidSET(Ext_stAltClasVarCf, ALTERNATEUR_12);
         break;

      case ALT_CLASSE_15:
         VEMS_vidSET(Ext_stAltClasVarCf, ALTERNATEUR_15);
         break;

      default:
         VEMS_vidSET(Ext_stAltClasVarCf, ALTERNATEUR_7);
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidCARSel                                           */
/* !Description :  Le type de carrosserie est sélectionné parmis les classes  */
/*                 possibles par télécodage                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Tele_program_car;                                             */
/*  output uint8 Ext_stBodyCf;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidCARSel(void)
{
   uint8 u8LocalTele_car;


   VEMS_vidGET(Tele_program_car, u8LocalTele_car);
   switch (u8LocalTele_car)
   {
      case PRESENCE_CAR0:
         VEMS_vidSET(Ext_stBodyCf, CAR0);
         break;

      case PRESENCE_CAR1:
         VEMS_vidSET(Ext_stBodyCf, CAR1);
         break;

      case PRESENCE_CAR2:
         VEMS_vidSET(Ext_stBodyCf, CAR2);
         break;

      case PRESENCE_CAR3:
         VEMS_vidSET(Ext_stBodyCf, CAR3);
         break;

      case PRESENCE_CAR4:
         VEMS_vidSET(Ext_stBodyCf, CAR4);
         break;

      case PRESENCE_CAR5:
         VEMS_vidSET(Ext_stBodyCf, CAR5);
         break;

      case PRESENCE_CAR6:
         VEMS_vidSET(Ext_stBodyCf, CAR6);
         break;

      case PRESENCE_CAR7:
         VEMS_vidSET(Ext_stBodyCf, CAR7);
         break;

      default:
         VEMS_vidSET(Ext_stBodyCf, CAR0);
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidCHASel                                           */
/* !Description :  Le type de chauffage additionnel est sélectionné parmis les*/
/*                 classes possibles par télécodage                           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Tele_program_add_heat;                                        */
/*  output uint8 Ext_stCabHeatVarCf;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidCHASel(void)
{
   uint8 u8LocalTele_add_heat;


   VEMS_vidGET(Tele_program_add_heat, u8LocalTele_add_heat);
   switch (u8LocalTele_add_heat)
   {
      case PRESENCE_CHA0:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA0);
         break;

      case PRESENCE_CHA1:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA1);
         break;

      case PRESENCE_CHA2:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA2);
         break;

      case PRESENCE_CHA3:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA3);
         break;

      case PRESENCE_CHA4:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA4);
         break;

      case PRESENCE_CHA5:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA5);
         break;

      case PRESENCE_CHA6:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA6);
         break;

      case PRESENCE_CHA7:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA7);
         break;

      default:
         VEMS_vidSET(Ext_stCabHeatVarCf, CHA0);
         break;
   }
}
/*----------------------------- end of file ----------------------------------*/