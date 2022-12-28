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
/* !File            : IFAIRSYSIGSYS_FCT1.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidInitOutput                                          */
/*   2 / IFAIRSYSIGSYS_vidOutput_pFuMes                                       */
/*   3 / IFAIRSYSIGSYS_vidInterfISLin                                         */
/*   4 / IFAIRSYSIGSYS_vidISLinInterf                                         */
/*   5 / IFAIRSYSIGSYS_vidOutputLoad                                          */
/*   6 / IFAIRSYSIGSYS_vidInterfEngStrt                                       */
/*   7 / IFAIRSYSIGSYS_vidOutAmbPressEep                                      */
/*   8 / IFAIRSYSIGSYS_vidTDsThr                                              */
/*   9 / IFAIRSYSIGSYS_vidPhyM                                                */
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
/* !Function    :  IFAIRSYSIGSYS_vidInitOutput                                */
/* !Description :  Initialisation des sorties du module IFAIRSYSIGSYS.        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Ext_idxCtlAltLINProvIdf;                                     */
/*  output uint8 Acceleration_vehicule_mux;                                   */
/*  output uint16 AFReg_facCorRichPrec;                                       */
/*  output boolean CoCha_bTqReq;                                              */
/*  output sint16 EngLim_tqEngCur_Sfty;                                       */
/*  output boolean Ext_bDrvCyGlbl;                                            */
/*  output uint16 Ext_pFuMes;                                                 */
/*  output uint8 Ext_uLsDsMes;                                                */
/*  output boolean InjSys_bInhInjAntiFlood;                                   */
/*  output uint8 ISCAN_u8N3F34DPM1413;                                        */
/*  output uint8 ISCAN_u8N8F7F2P301;                                          */
/*  output boolean MonMisf_bDetInstMisf;                                      */
/*  output uint16 ThrLrn_rOpClsThrBol;                                        */
/*  output sint8 TqCmp_tAir;                                                  */
/*  output sint16 TqSys_tqCkAntiOscCord;                                      */
/*  output uint16 Vitesse_vehicule_ard_mux;                                   */
/*  output uint16 Vitesse_vehicule_arg_mux;                                   */
/*  output uint16 Vitesse_vehicule_avd_mux;                                   */
/*  output uint16 Vitesse_vehicule_avg_mux;                                   */
/*  output uint16 Vitesse_vehicule_mux;                                       */
/*  output boolean VSCtl_bVSLimReg;                                           */
/*  output boolean Crash_fps_mux;                                             */
/*  output uint8 Ext_idxAltClas;                                              */
/*  output sint16 Ext_tqAlt;                                                  */
/*  output uint8 CoPTSt_stEngNew;                                             */
/*  output boolean ISCAN_bF572PM1375;                                         */
/*  output boolean ISCAN_bN10F4F2P437NotAvl;                                  */
/*  output uint8 ISCAN_u8N8F7F2V003;                                          */
/*  output uint8 Ext_uLsUsMes;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInitOutput(void)
{
   VEMS_vidSET(Ext_idxCtlAltLINProvIdf, 0);
   VEMS_vidSET(Acceleration_vehicule_mux, 0);
   VEMS_vidSET(AFReg_facCorRichPrec, 0);
   VEMS_vidSET(CoCha_bTqReq, 0);
   VEMS_vidSET(EngLim_tqEngCur_Sfty, 0);
   VEMS_vidSET(Ext_bDrvCyGlbl, 0);
   VEMS_vidSET(Ext_pFuMes, 0);
   VEMS_vidSET(Ext_uLsDsMes, 0);
   VEMS_vidSET(InjSys_bInhInjAntiFlood, 0);
   VEMS_vidSET(ISCAN_u8N3F34DPM1413, 0);
   VEMS_vidSET(ISCAN_u8N8F7F2P301, 0);
   VEMS_vidSET(MonMisf_bDetInstMisf, 0);
   VEMS_vidSET(ThrLrn_rOpClsThrBol, 0);
   VEMS_vidSET(TqCmp_tAir, 0);
   VEMS_vidSET(TqSys_tqCkAntiOscCord, 0);
   VEMS_vidSET(Vitesse_vehicule_ard_mux, 0);
   VEMS_vidSET(Vitesse_vehicule_arg_mux, 0);
   VEMS_vidSET(Vitesse_vehicule_avd_mux, 0);
   VEMS_vidSET(Vitesse_vehicule_avg_mux, 0);
   VEMS_vidSET(Vitesse_vehicule_mux, 0);
   VEMS_vidSET(VSCtl_bVSLimReg, 0);
   VEMS_vidSET(Crash_fps_mux, 0);
   VEMS_vidSET(Ext_idxAltClas, 0);
   VEMS_vidSET(Ext_tqAlt, 0);
   VEMS_vidSET(CoPTSt_stEngNew, 0);
   VEMS_vidSET(ISCAN_bF572PM1375, 0);
   VEMS_vidSET(ISCAN_bN10F4F2P437NotAvl, 0);
   VEMS_vidSET(ISCAN_u8N8F7F2V003, 0);
   VEMS_vidSET(Ext_uLsUsMes, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_pFuMes                             */
/* !Description :  Cette fonction permet l'acquisition de la pression rail.   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pFuRailMesRef;                                           */
/*  output uint16 Ext_pFuMes;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_pFuMes(void)
{
   /*F1_Output_pFuMes */
   uint16 u16LocalExt_pFuRailMesRef;


   VEMS_vidGET(Ext_pFuRailMesRef, u16LocalExt_pFuRailMesRef);
   u16LocalExt_pFuRailMesRef = (uint16)( (u16LocalExt_pFuRailMesRef + 64)
                                       / 128);
   VEMS_vidSET(Ext_pFuMes, u16LocalExt_pFuRailMesRef);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInterfISLin                               */
/* !Description :  Fonction qui permet la production des variables            */
/*                 Ext_iCtlAltLINExct, Ext_iRvAltExct, Ext_rCtlAltLINCycOp,   */
/*                 Ext_rAltCycOpStd et Ext_rRvAltCycOp.                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 AltCtl_iAlt;                                                  */
/*  input uint8 AltCtl_rAltCycOpRate;                                         */
/*  output uint8 Ext_iCtlAltLINExct;                                          */
/*  output uint8 Ext_iRvAltExct;                                              */
/*  output uint8 Ext_rCtlAltLINCycOp;                                         */
/*  output uint8 Ext_rAltCycOpStd;                                            */
/*  output uint8 Ext_rRvAltCycOp;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInterfISLin(void)
{
   /*F01_InterfISLin*/
   uint8 u8LocalAltCtl_iAlt;
   uint8 u8LocalAltCtl_rAltCycOpRate;
   uint8 u8LocalExt_iCtlAltLINExct;
   uint8 u8LocalExt_iRvAltExct;
   uint8 u8LocalExt_rCtlAltLINCycOp;
   uint8 u8LocalExt_rAltCycOpStd;
   uint8 u8LocalExt_rRvAltCycOp;


   VEMS_vidGET(AltCtl_iAlt, u8LocalAltCtl_iAlt);
   u8LocalExt_iCtlAltLINExct = (uint8)(u8LocalAltCtl_iAlt / 2);
   u8LocalExt_iCtlAltLINExct =
      (uint8)MATHSRV_udtMIN(u8LocalExt_iCtlAltLINExct, 63);
   VEMS_vidSET(Ext_iCtlAltLINExct, u8LocalExt_iCtlAltLINExct);

   u8LocalExt_iRvAltExct = (uint8)( (u8LocalAltCtl_iAlt * 5)
                                  / 8);
   VEMS_vidSET(Ext_iRvAltExct, u8LocalExt_iRvAltExct);

   VEMS_vidGET(AltCtl_rAltCycOpRate, u8LocalAltCtl_rAltCycOpRate);
   u8LocalExt_rCtlAltLINCycOp =
      (uint8) MATHSRV_udtMIN(u8LocalAltCtl_rAltCycOpRate, 100);
   VEMS_vidSET(Ext_rCtlAltLINCycOp, u8LocalExt_rCtlAltLINCycOp);

   u8LocalExt_rAltCycOpStd =
      (uint8) MATHSRV_udtMIN(u8LocalAltCtl_rAltCycOpRate, 100);
   VEMS_vidSET(Ext_rAltCycOpStd, u8LocalExt_rAltCycOpStd);

   u8LocalExt_rRvAltCycOp = (uint8)( (u8LocalAltCtl_rAltCycOpRate * 10)
                                   / 143);
   u8LocalExt_rRvAltCycOp =
      (uint8) MATHSRV_udtMIN(u8LocalExt_rRvAltCycOp, 6);
   VEMS_vidSET(Ext_rRvAltCycOp, u8LocalExt_rRvAltCycOp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidISLinInterf                               */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 Ext_idxCtlAltLINProvIdf et Ext_idxAltClas.                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 AltCtl_idxAltProv;                                            */
/*  input uint8 IsLin_idxAltClas;                                             */
/*  output uint8 Ext_idxCtlAltLINProvIdf;                                     */
/*  output uint8 Ext_idxAltClas;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidISLinInterf(void)
{
   /*F02_ISLinInterf */
   uint8 u8LocalAltCtl_idxAltProv;
   uint8 u8LocalIsLin_idxAltClas;
   uint8 u8LocalExt_idxCtlAltLINProvIdf;
   uint8 u8LocalExt_idxAltClas;


   VEMS_vidGET(AltCtl_idxAltProv, u8LocalAltCtl_idxAltProv);
   u8LocalExt_idxCtlAltLINProvIdf =
      (uint8)MATHSRV_udtMIN(u8LocalAltCtl_idxAltProv, 7);
   VEMS_vidSET(Ext_idxCtlAltLINProvIdf, u8LocalExt_idxCtlAltLINProvIdf);

   VEMS_vidGET(IsLin_idxAltClas, u8LocalIsLin_idxAltClas);
   u8LocalExt_idxAltClas = (uint8)MATHSRV_udtMIN(u8LocalIsLin_idxAltClas, 100);
   VEMS_vidSET(Ext_idxAltClas, u8LocalExt_idxAltClas);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputLoad                                */
/* !Description :  Ce bloc contient les sortie de la chaine d’air utilisés par*/
/*                 les modules projets Ebx.                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 EngM_rTotLdExCor;                                            */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  output uint16 Engine_load;                                                */
/*  output uint16 Engine_air_load;                                            */
/*  output uint16 Ext_rAirLd;                                                 */
/*  output uint16 Ext_rTotLd;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputLoad(void)
{
   /*f3_output_load */
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalEngM_rTotLdExCor;
   uint16 u16LocalEngine_load;
   uint16 u16LocalEngine_air_load;
   uint16 u16LocalExt_rAirLd;
   uint16 u16LocalExt_rTotLd;
   uint32 u32LocalVar;
   uint32 u32LocalExt_rAirLd;
   uint32 u32LocalExt_rTotLd;


   VEMS_vidGET(EngM_rTotLdExCor, u16LocalEngM_rTotLdExCor);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u32LocalVar = (uint32)(2 * u16LocalEngM_rTotLdExCor);
   u16LocalEngine_load = (uint16)MATHSRV_udtMIN(u32LocalVar, 65535);
   VEMS_vidSET(Engine_load, u16LocalEngine_load);

   u32LocalVar = (uint32)(2 * u16LocalEngM_rAirLdCor);
   u16LocalEngine_air_load = (uint16)MATHSRV_udtMIN(u32LocalVar, 65535);
   VEMS_vidSET(Engine_air_load, u16LocalEngine_air_load);
    /* production of Ext_rAirLd & Ext_rTotLd */
   u32LocalExt_rAirLd =  (uint32)((u16LocalEngM_rAirLdCor * 4) / 3);
   u16LocalExt_rAirLd =  (uint16)MATHSRV_udtMIN(u32LocalExt_rAirLd, 65535);
   VEMS_vidSET(Ext_rAirLd, u16LocalExt_rAirLd);

   u32LocalExt_rTotLd =  (uint32)((u16LocalEngM_rTotLdExCor * 4) / 3);
   u16LocalExt_rTotLd =  (uint16)MATHSRV_udtMIN(u32LocalExt_rTotLd, 65535);
   VEMS_vidSET(Ext_rTotLd, u16LocalExt_rTotLd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInterfEngStrt                             */
/* !Description :  Fonction qui permet la production des variables            */
/*                 VoltCtl_IexctMax, VoltCtl_tiAltPrgCh,                      */
/*                 VoltCtl_AltPrgChDi_nEng et VoltCtl_uReqProdElec.           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ElProdMgt_iExctMax;                                          */
/*  input uint8 ElProdMgt_stProdPrgCh;                                        */
/*  input uint8 ElProdMgt_stProdPrgChDi_nEng;                                 */
/*  input uint16 ElProdMgt_uElProdSp;                                         */
/*  output uint16 VoltCtl_IexctMax;                                           */
/*  output uint8 VoltCtl_tiAltPrgCh;                                          */
/*  output uint8 VoltCtl_AltPrgChDi_nEng;                                     */
/*  output uint16 VoltCtl_uReqProdElec;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInterfEngStrt(void)
{
   /*F03_InterfEngStrt */

   uint8  u8LocalElProdMgt_stProdPrgCh;
   uint8  u8LocalElProdMgt_stPdrgChDi_nEng;
   uint16 u16LocalElProdMgt_iExctMax;
   uint16 u16LocalElProdMgt_uElProdSp;
   uint16 u16LocalVoltCtl_uReqProdElec;


   VEMS_vidGET(ElProdMgt_iExctMax, u16LocalElProdMgt_iExctMax);
   VEMS_vidGET(ElProdMgt_stProdPrgCh, u8LocalElProdMgt_stProdPrgCh);
   VEMS_vidGET(ElProdMgt_stProdPrgChDi_nEng, u8LocalElProdMgt_stPdrgChDi_nEng);
   VEMS_vidGET(ElProdMgt_uElProdSp, u16LocalElProdMgt_uElProdSp);

   u16LocalElProdMgt_iExctMax =
      (uint16)MATHSRV_udtMIN(u16LocalElProdMgt_iExctMax, 256);
   u8LocalElProdMgt_stProdPrgCh =
      (uint8)MATHSRV_udtMIN(u8LocalElProdMgt_stProdPrgCh, 15);
   u8LocalElProdMgt_stPdrgChDi_nEng =
      (uint8)MATHSRV_udtMIN(u8LocalElProdMgt_stPdrgChDi_nEng, 15);
   u16LocalVoltCtl_uReqProdElec =
      (uint16)(((uint32)(u16LocalElProdMgt_uElProdSp * 25) + 16) / 32);
   u16LocalVoltCtl_uReqProdElec =
      (uint16)MATHSRV_udtCLAMP(u16LocalVoltCtl_uReqProdElec,
                               1060,
                               1600);
   VEMS_vidSET(VoltCtl_IexctMax, u16LocalElProdMgt_iExctMax);
   VEMS_vidSET(VoltCtl_tiAltPrgCh, u8LocalElProdMgt_stProdPrgCh);
   VEMS_vidSET(VoltCtl_AltPrgChDi_nEng, u8LocalElProdMgt_stPdrgChDi_nEng);
   VEMS_vidSET(VoltCtl_uReqProdElec, u16LocalVoltCtl_uReqProdElec);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutAmbPressEep                            */
/* !Description :  Fonction de copie de la valeur eeprom de                   */
/*                 UsThrM_pAirExtEstim dans Eep_UsThrM_pAirExtEstim           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 UsThrM_pAirExtEstim;                                         */
/*  output uint16 Eep_UsThrM_pAirExtEstim;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutAmbPressEep(void)
{
   /*f6_output_ambient_pressure_eeprom*/
   uint16 u16LocalUsThrM_pAirExtEstim;


   VEMS_vidGET(UsThrM_pAirExtEstim, u16LocalUsThrM_pAirExtEstim);
   Eep_UsThrM_pAirExtEstim = u16LocalUsThrM_pAirExtEstim;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidTDsThr                                    */
/* !Description :  Ce bloc contient les entrées de la chaine d’air issus des  */
/*                 modules projets Ebx.                                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Temperature_air;                                              */
/*  output sint16 Ext_tDsThrMes;                                              */
/*  output sint16 Ext_tAirUsCmprMes;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidTDsThr(void)
{
   /*f3_tDsThr */
   uint8  u8LocalTemperature_air;
   sint16 s16LocalExt_tDsThrMes;


   VEMS_vidGET(Temperature_air, u8LocalTemperature_air);

   s16LocalExt_tDsThrMes = (sint16)( ( ((5 * u8LocalTemperature_air) + 4)
                                     / 8) - 40);
   VEMS_vidSET(Ext_tDsThrMes, s16LocalExt_tDsThrMes);
   VEMS_vidSET(Ext_tAirUsCmprMes, s16LocalExt_tDsThrMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidPhyM                                      */
/* !Description :  cette fonction permet d'interfacer PhyM_tTrbCaseEstim avec */
/*                 PhyMSI_tTrbCaseEstim.                                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 PhyMSI_tTrbCaseEstim;                                        */
/*  output sint16 PhyM_tTrbCaseEstim;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidPhyM(void)
{
   /*F09_PhyM*/
   uint16  u16LocalPhyMSI_tTrbCaseEstim;
   sint16  s16LocalPhyMSI_tTrbCaseEstim;


   VEMS_vidGET(PhyMSI_tTrbCaseEstim, u16LocalPhyMSI_tTrbCaseEstim);
   s16LocalPhyMSI_tTrbCaseEstim =
      (sint16)((u16LocalPhyMSI_tTrbCaseEstim / 32) - 273);
   s16LocalPhyMSI_tTrbCaseEstim =
      (sint16)MATHSRV_udtCLAMP(s16LocalPhyMSI_tTrbCaseEstim,
                               0,
                               1000);
   VEMS_vidSET(PhyM_tTrbCaseEstim, s16LocalPhyMSI_tTrbCaseEstim);
}
/*-------------------------------- end of file -------------------------------*/