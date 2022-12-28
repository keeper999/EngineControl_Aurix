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
/* !File            : IFAIRSYSIGSYS_FCT7.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidDiag_Trim                                           */
/*   2 / IFAIRSYSIGSYS_vidFuTnk                                               */
/*   3 / IFAIRSYSIGSYS_vidFrstCrk                                             */
/*   4 / IFAIRSYSIGSYS_vidCtTDC                                               */
/*   5 / IFAIRSYSIGSYS_vidAntiFlood                                           */
/*   6 / IFAIRSYSIGSYS_vidInjrMSys1                                           */
/*   7 / IFAIRSYSIGSYS_vidInit_tOil                                           */
/*   8 / IFAIRSYSIGSYS_vidOutputGearRatio                                     */
/*   9 / IFAIRSYSIGSYS_vidOutput_IdlLim                                       */
/*   10 / IFAIRSYSIGSYS_vidOutputStrtEnd                                      */
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
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidDiag_Trim                                 */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 InjCtl_rDiagTrim.                                          */
/* !Number      :  FCT7.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 Diag_trim;                                                    */
/*  output sint8 InjCtl_rDiagTrim;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidDiag_Trim(void)
{
   /*02_Diag_Trim*/
   sint8 s8LocalDiag_trim;


   VEMS_vidGET(Diag_trim, s8LocalDiag_trim);
   VEMS_vidSET(InjCtl_rDiagTrim, s8LocalDiag_trim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidFuTnk                                     */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Flev_fuel_level_mux.                                       */
/* !Number      :  FCT7.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_rFuTnkPerc;                                               */
/*  output uint8 Flev_fuel_level_mux;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidFuTnk(void)
{
   /*03_fFuTnk*/
   uint8 u8LocalExt_rFuTnkPerc;


   VEMS_vidGET(Ext_rFuTnkPerc, u8LocalExt_rFuTnkPerc);
   VEMS_vidSET(Flev_fuel_level_mux, u8LocalExt_rFuTnkPerc);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidFrstCrk                                   */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_bFrstCrk.                                              */
/* !Number      :  FCT7.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean First_crank;                                                */
/*  output boolean Ext_bFrstCrk;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidFrstCrk(void)
{
   /*04_FrstCrk */
   boolean bLocalFirst_crank;


   VEMS_vidGET(First_crank, bLocalFirst_crank);
   if (bLocalFirst_crank != 0)
   {
      VEMS_vidSET(Ext_bFrstCrk, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bFrstCrk, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidCtTDC                                     */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_ctTDCTot.                                              */
/* !Number      :  FCT7.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Sync_ctTDC;                                                   */
/*  output uint8 Ext_ctTDCTot;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidCtTDC(void)
{
   /*05_ctTDC */
   uint8   u8LocalSync_ctTDC;


   VEMS_vidGET(Sync_ctTDC, u8LocalSync_ctTDC);
   VEMS_vidSET(Ext_ctTDCTot, u8LocalSync_ctTDC);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidAntiFlood                                 */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 InjSys_bInhInjAntiFlood.                                   */
/* !Number      :  FCT7.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Disable_inj_for_anti_flood;                                 */
/*  output boolean InjSys_bInhInjAntiFlood;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidAntiFlood(void)
{
   /*07_AntiFlood */
   boolean bLocalDisable_inj_for_anti_flood;


   VEMS_vidGET(Disable_inj_for_anti_flood, bLocalDisable_inj_for_anti_flood);
   VEMS_vidSET(InjSys_bInhInjAntiFlood, bLocalDisable_inj_for_anti_flood);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInjrMSys1                                 */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Injector_constant.                                         */
/* !Number      :  FCT7.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 InjrM_prm_facGainInj[4];                                     */
/*  output uint16 Injector_constant;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInjrMSys1(void)
{
   /*F01_InjrMSys1 */
   uint16  u16LocalInjector_constant;
   sint32  s32LocalInjector_constant;


   VEMS_vidGET1DArrayElement(InjrM_prm_facGainInj,
                             0,
                             u16LocalInjector_constant);
   s32LocalInjector_constant = (sint32)(u16LocalInjector_constant - 1);
   u16LocalInjector_constant =
      (uint16)MATHSRV_udtMAX(s32LocalInjector_constant, 0);
   VEMS_vidSET(Injector_constant, u16LocalInjector_constant);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInit_tOil                                 */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_bStrtEnd et Ext_bTOilChk .                             */
/* !Number      :  FCT7.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Eng_bTOilChk;                                               */
/*  output boolean Ext_bTOilChk;                                              */
/*  output boolean Ext_bStrtEnd;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInit_tOil(void)
{
   /*F01_Init_tOil*/
   boolean bLocalEng_bTOilChk;


   VEMS_vidGET(Eng_bTOilChk, bLocalEng_bTOilChk);
   VEMS_vidSET(Ext_bTOilChk, bLocalEng_bTOilChk);
   VEMS_vidSET(Ext_bStrtEnd, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputGearRatio                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Gear_engagedet CoPt_noGearCord_Sfty.                       */
/* !Number      :  FCT7.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean CoPt_bSIPCord;                                              */
/*  input uint8 CoPt_noGearCord_Sfty_C;                                       */
/*  output uint8 CoPt_noGearCord_Sfty;                                        */
/*  output uint8 Ext_noEgdGearCord;                                           */
/*  output uint8 Gear_engaged;                                                */
/*  output boolean Changement_rapport_bvm;                                    */
/*  output boolean Bv_changement_rapport;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputGearRatio(void)
{
   /*F04_Output_GearRatio */
   boolean bLocalFRM_FRM_AcvSftynoGearByp;
   boolean bLocalCoPt_bSIPCord;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalCoPt_noGearCord_Sfty;
   uint8   u8LocalExt_noEgdGearCord;


   bLocalFRM_FRM_AcvSftynoGearByp = GDGAR_bGetFRM(FRM_FRM_ACVSFTYNOGEARBYP);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(CoPt_bSIPCord, bLocalCoPt_bSIPCord);

   if (bLocalFRM_FRM_AcvSftynoGearByp != 0)
   {
      u8LocalCoPt_noGearCord_Sfty = CoPt_noGearCord_Sfty_C;
   }
   else
   {
      u8LocalCoPt_noGearCord_Sfty = u8LocalCoPt_noEgdGearCord;
   }
   u8LocalCoPt_noGearCord_Sfty =
      (uint8)MATHSRV_udtMIN(u8LocalCoPt_noGearCord_Sfty, 7);
   VEMS_vidSET(CoPt_noGearCord_Sfty, u8LocalCoPt_noGearCord_Sfty);

   u8LocalExt_noEgdGearCord = (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord,
                                                    15);
   VEMS_vidSET(Ext_noEgdGearCord, u8LocalExt_noEgdGearCord);

   if (u8LocalCoPt_noEgdGearCord != 7)
   {
      u8LocalCoPt_noEgdGearCord =
         (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord, 5);
   }
   else
   {
      u8LocalCoPt_noEgdGearCord = 1;
   }
   VEMS_vidSET(Gear_engaged, u8LocalCoPt_noEgdGearCord);

   if (u8LocalExt_stGBxCf == 0)
   {
      VEMS_vidSET(Changement_rapport_bvm, bLocalCoPt_bSIPCord);
      VEMS_vidSET(Bv_changement_rapport, 0);
   }
   else
   {
      VEMS_vidSET(Changement_rapport_bvm, 0);
      VEMS_vidSET(Bv_changement_rapport, bLocalCoPt_bSIPCord);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_IdlLim                             */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 EngSt_bCtlEngNOnIdl.                                       */
/* !Number      :  FCT7.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input boolean TqSys_bIdlAcvCmn;                                           */
/*  output boolean EngSt_bCtlEngNOnIdl;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_IdlLim(void)
{
   /*F05_Output_IdlLim */
   boolean bLocalTqSys_bEngNOnIdl;
   boolean bLocalTqSys_bIdlAcvCmn;


   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);
   VEMS_vidGET(TqSys_bIdlAcvCmn, bLocalTqSys_bIdlAcvCmn);
   if (  (bLocalTqSys_bEngNOnIdl != 0)
      && (bLocalTqSys_bIdlAcvCmn != 0))
   {
      VEMS_vidSET(EngSt_bCtlEngNOnIdl, 1);
   }
   else
   {
      VEMS_vidSET(EngSt_bCtlEngNOnIdl, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputStrtEnd                             */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_bStrtEnd.                                              */
/* !Number      :  FCT7.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st12 Dtc_etat_structure;                                            */
/*  input boolean TqSys_bTqSysAcv;                                            */
/*  input bool DTC_VERS_ET_DEBOUCLEE;                                         */
/*  output boolean Ext_bStrtEnd;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputStrtEnd(void)
{
   /*F08_Output_bStrtEnd */
   boolean bLocalTqSys_bTqSysAcv;
   uint8   u8LocalDtc_etat_structure;


   VEMS_vidGET(Dtc_etat_structure, u8LocalDtc_etat_structure);
   VEMS_vidGET(TqSys_bTqSysAcv, bLocalTqSys_bTqSysAcv);
   if (u8LocalDtc_etat_structure != DTC_VERS_ET_DEBOUCLEE)
   {
      VEMS_vidSET(Ext_bStrtEnd, bLocalTqSys_bTqSysAcv);
   }
   else
   {
      VEMS_vidSET(Ext_bStrtEnd, 1);
   }
}

/*-------------------------------- end of file -------------------------------*/