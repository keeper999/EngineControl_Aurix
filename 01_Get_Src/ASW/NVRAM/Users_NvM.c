/******************************************************************************/
/*                                                                            */
/* !Layer          : SRV                                                      */
/*                                                                            */
/* !Component      : NVRAM                                                    */
/*                                                                            */
/* !Module         : Users_NvM                                                */
/* !Description    : Contains Initialisation Callback of the blocks NVM       */
/*                                                                            */
/* !File           : Users_NvM.c                                              */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2014 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/NVRAM/Users_NvM.c_v               $*/
/* $Revision::   1.3      $$Author::   wbouach     $$Date::   19 Sep 2014 14:$*/
/******************************************************************************/
/*       THIS FILE IS GENERATED AUTOMATICALY BY GenGlueCfromXLS TOOL          */
/*       Generated date 19/09/14 at 14:21:18                                   */
/******************************************************************************/

#include "Std_Types.h"
#include "Users_NvM_L.h"

/******************************************************************************/
/*              CALLBACK D'INITIALISATION DES BLOCKS NVM                      */
/******************************************************************************/

/* Définition de la callback d'initialisation du block NVM SAIMMO_CODE: */
Std_ReturnType NVM_SAIMMO_CODE__nvmini(void)
{
   SAIMMO_CODE__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SAIMMO_ETAT: */
Std_ReturnType NVM_SAIMMO_ETAT__nvmini(void)
{
   SAIMMO_ETAT__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TELECODAGE: */
Std_ReturnType NVM_TELECODAGE_NVMSRV_vidInit(void)
{
   TELECODAGE_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ACCPLRNPOS: */
Std_ReturnType NVM_ACCPLRNPOS_NVMSRV_vidInit(void)
{
   ACCPLRNPOS_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ACQCOT: */
Std_ReturnType NVM_ACQCOT_NVMSRV_vidInit(void)
{
   ACQCOT_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFAMGTT_NVRAM_INT8_CONST: */
Std_ReturnType NVM_AFAMgtT_NVRAM_int8_const__nvmini(void)
{
   AFAMgtT_NVRAM_int8_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFAT_NVRAM_INT16_CALIB: */
Std_ReturnType NVM_AFAT_NVRAM_int16_calib__nvmini(void)
{
   AFAT_NVRAM_int16_calib__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFAT_NVRAM_INT32_CALIB: */
Std_ReturnType NVM_AFAT_NVRAM_int32_calib__nvmini(void)
{
   AFAT_NVRAM_int32_calib__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFAT_NVRAM_INT8_CALIB: */
Std_ReturnType NVM_AFAT_NVRAM_int8_calib__nvmini(void)
{
   AFAT_NVRAM_int8_calib__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFAT_NVRAM_BOOLEAN_CALIB: */
Std_ReturnType NVM_AFAT_NVRAM_boolean_calib__nvmini(void)
{
   AFAT_NVRAM_boolean_calib__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFAT_NVRAM_INT16_CONST: */
Std_ReturnType NVM_AFAT_NVRAM_int16_const__nvmini(void)
{
   AFAT_NVRAM_int16_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFAT_NVRAM_INT8_CONST: */
Std_ReturnType NVM_AFAT_NVRAM_int8_const__nvmini(void)
{
   AFAT_NVRAM_int8_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFAT_NVRAM_BOOLEAN_CONST: */
Std_ReturnType NVM_AFAT_NVRAM_boolean_const__nvmini(void)
{
   AFAT_NVRAM_boolean_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COEMSTT_NVRAM_INT16_CONST_1: */
Std_ReturnType NVM_COEMSTT_NVRAM_int16_const_1__nvmini(void)
{
   COEMSTT_NVRAM_int16_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COEMSTT_NVRAM_INT32_CONST_1: */
Std_ReturnType NVM_COEMSTT_NVRAM_int32_const_1__nvmini(void)
{
   COEMSTT_NVRAM_int32_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COEMSTT_NVRAM_INT8_CONST_1: */
Std_ReturnType NVM_COEMSTT_NVRAM_int8_const_1__nvmini(void)
{
   COEMSTT_NVRAM_int8_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_INT16_CONST_1: */
Std_ReturnType NVM_COSTOPSTART_NVRAM_int16_const_1__nvmini(void)
{
   COSTOPSTART_NVRAM_int16_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_INT8_CONST_1: */
Std_ReturnType NVM_COSTOPSTART_NVRAM_int8_const_1__nvmini(void)
{
   COSTOPSTART_NVRAM_int8_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_INT8_CONST_2: */
Std_ReturnType NVM_COSTOPSTART_NVRAM_int8_const_2__nvmini(void)
{
   COSTOPSTART_NVRAM_int8_const_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_INT8_CONST_3: */
Std_ReturnType NVM_COSTOPSTART_NVRAM_int8_const_3__nvmini(void)
{
   COSTOPSTART_NVRAM_int8_const_3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_BOOLEAN_CONST_1: */
Std_ReturnType NVM_COSTOPSTART_NVRAM_boolean_const_1__nvmini(void)
{
   COSTOPSTART_NVRAM_boolean_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COSTOPSTART_NVRAM_BOOLEAN_CONST_2: */
Std_ReturnType NVM_COSTOPSTART_NVRAM_boolean_const_2__nvmini(void)
{
   COSTOPSTART_NVRAM_boolean_const_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CSTRFUCONCESTIM: */
Std_ReturnType NVM_CSTRFUCONCESTIM_NVMSRV_vidInit(void)
{
   CSTRFUCONCESTIM_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFWCTL_NVRAM_INT16_CONST: */
Std_ReturnType NVM_DFWCTL_NVRAM_int16_const__nvmini(void)
{
   DFWCTL_NVRAM_int16_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ECUMNG: */
Std_ReturnType NVM_ECUMNG_NVMSRV_vidInit(void)
{
   ECUMNG_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM EOMGSL_NVRAM_INT32_CONST: */
Std_ReturnType NVM_EOMGSL_NVRAM_int32_const__nvmini(void)
{
   EOMGSL_NVRAM_int32_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM EXMGSLT2_NVRAM_INT16_CONST: */
Std_ReturnType NVM_ExMGslT2_NVRAM_int16_const__nvmini(void)
{
   ExMGslT2_NVRAM_int16_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FISA_NVRAM_INT8_CONST_1: */
Std_ReturnType NVM_FISA_NVRAM_int8_const_1__nvmini(void)
{
   FISA_NVRAM_int8_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AASTART_BIDON: */
Std_ReturnType NVM_AaStart_Bidon__nvmini(void)
{
   AaStart_Bidon__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_PED: */
Std_ReturnType NVM_Coh_Ped__nvmini(void)
{
   Coh_Ped__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCPOC_PED2: */
Std_ReturnType NVM_ScpOc_Ped2__nvmini(void)
{
   ScpOc_Ped2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_PED2: */
Std_ReturnType NVM_Scg_Ped2__nvmini(void)
{
   Scg_Ped2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCPOC_PED1: */
Std_ReturnType NVM_ScpOc_Ped1__nvmini(void)
{
   ScpOc_Ped1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_PED1: */
Std_ReturnType NVM_Scg_Ped1__nvmini(void)
{
   Scg_Ped1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKACCP: */
Std_ReturnType NVM_StuckAccP__nvmini(void)
{
   StuckAccP__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCPACCPSWT: */
Std_ReturnType NVM_ScpAccPSwt__nvmini(void)
{
   ScpAccPSwt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKACCPSWT: */
Std_ReturnType NVM_StuckAccPSwt__nvmini(void)
{
   StuckAccPSwt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCGACCPSWT: */
Std_ReturnType NVM_ScgAccPSwt__nvmini(void)
{
   ScgAccPSwt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COHACCPSWT: */
Std_ReturnType NVM_CohAccPSwt__nvmini(void)
{
   CohAccPSwt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_RACCP: */
Std_ReturnType NVM_Coh_rAccP__nvmini(void)
{
   Coh_rAccP__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_PACMES: */
Std_ReturnType NVM_Grd_pACMes__nvmini(void)
{
   Grd_pACMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_PACMES: */
Std_ReturnType NVM_Hi_pACMes__nvmini(void)
{
   Hi_pACMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_PACMES: */
Std_ReturnType NVM_Lo_pACMes__nvmini(void)
{
   Lo_pACMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_TCOMES: */
Std_ReturnType NVM_Grd_tCoMes__nvmini(void)
{
   Grd_tCoMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_TCOMES: */
Std_ReturnType NVM_Oc_tCoMes__nvmini(void)
{
   Oc_tCoMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_TCOMES: */
Std_ReturnType NVM_Scg_tCoMes__nvmini(void)
{
   Scg_tCoMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_TCOMES: */
Std_ReturnType NVM_Scp_tCoMes__nvmini(void)
{
   Scp_tCoMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_AIREXTPRESACQ: */
Std_ReturnType NVM_Scg_AirExtPresAcq__nvmini(void)
{
   Scg_AirExtPresAcq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_AIREXTPRESACQ: */
Std_ReturnType NVM_Scp_AirExtPresAcq__nvmini(void)
{
   Scp_AirExtPresAcq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_PDSTHRMES: */
Std_ReturnType NVM_Scp_pDsThrMes__nvmini(void)
{
   Scp_pDsThrMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_PDSTHRMES: */
Std_ReturnType NVM_Scg_pDsThrMes__nvmini(void)
{
   Scg_pDsThrMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_PBRKASI: */
Std_ReturnType NVM_Scp_pBrkAsi__nvmini(void)
{
   Scp_pBrkAsi__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_PBRKASI: */
Std_ReturnType NVM_Scg_pBrkAsi__nvmini(void)
{
   Scg_pBrkAsi__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_PBRKASI: */
Std_ReturnType NVM_Grd_pBrkAsi__nvmini(void)
{
   Grd_pBrkAsi__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STALLCOH_PDSTHR: */
Std_ReturnType NVM_StallCoh_pDsThr__nvmini(void)
{
   StallCoh_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CRKCOH_PDSTHR: */
Std_ReturnType NVM_CrkCoh_pDsThr__nvmini(void)
{
   CrkCoh_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STABCOH_PDSTHR: */
Std_ReturnType NVM_StabCoh_pDsThr__nvmini(void)
{
   StabCoh_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM THRCOH_PDSTHR: */
Std_ReturnType NVM_ThrCoh_pDsThr__nvmini(void)
{
   ThrCoh_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_PDSTHR: */
Std_ReturnType NVM_ORng_pDsThr__nvmini(void)
{
   ORng_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FLDCOH_PDSTHR: */
Std_ReturnType NVM_FldCoh_pDsThr__nvmini(void)
{
   FldCoh_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_PDSTHR: */
Std_ReturnType NVM_Grd_pDsThr__nvmini(void)
{
   Grd_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MAX_PAIREXT: */
Std_ReturnType NVM_Max_pAirExt__nvmini(void)
{
   Max_pAirExt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MIN_PAIREXT: */
Std_ReturnType NVM_Min_pAirExt__nvmini(void)
{
   Min_pAirExt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_PAIREXT: */
Std_ReturnType NVM_Grd_pAirExt__nvmini(void)
{
   Grd_pAirExt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_PAIREXTOLD: */
Std_ReturnType NVM_Grd_pAirExtOld__nvmini(void)
{
   Grd_pAirExtOld__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_PBRKASI: */
Std_ReturnType NVM_Coh_pBrkAsi__nvmini(void)
{
   Coh_pBrkAsi__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_PRELBRKASI: */
Std_ReturnType NVM_Scp_pRelBrkAsi__nvmini(void)
{
   Scp_pRelBrkAsi__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_PRELBRKASI: */
Std_ReturnType NVM_Scg_pRelBrkAsi__nvmini(void)
{
   Scg_pRelBrkAsi__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_PRELBRKASI: */
Std_ReturnType NVM_Grd_pRelBrkAsi__nvmini(void)
{
   Grd_pRelBrkAsi__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BOOST1_PDSTHR: */
Std_ReturnType NVM_Boost1_pDsThr__nvmini(void)
{
   Boost1_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BOOST2_PDSTHR: */
Std_ReturnType NVM_Boost2_pDsThr__nvmini(void)
{
   Boost2_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BOOST3_PDSTHR: */
Std_ReturnType NVM_Boost3_pDsThr__nvmini(void)
{
   Boost3_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BOOST4_PDSTHR: */
Std_ReturnType NVM_Boost4_pDsThr__nvmini(void)
{
   Boost4_pDsThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_TAIRMES: */
Std_ReturnType NVM_Oc_tAirMes__nvmini(void)
{
   Oc_tAirMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_TAIRMES: */
Std_ReturnType NVM_Scg_tAirMes__nvmini(void)
{
   Scg_tAirMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_TAIRMES: */
Std_ReturnType NVM_Scp_tAirMes__nvmini(void)
{
   Scp_tAirMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_TAIRMES: */
Std_ReturnType NVM_Grd_tAirMes__nvmini(void)
{
   Grd_tAirMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM NEGOFS_TAIRMES: */
Std_ReturnType NVM_NegOfs_tAirMes__nvmini(void)
{
   NegOfs_tAirMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_TAIRMES: */
Std_ReturnType NVM_ORng_tAirMes__nvmini(void)
{
   ORng_tAirMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM POSOFS_TAIRMES: */
Std_ReturnType NVM_PosOfs_tAirMes__nvmini(void)
{
   PosOfs_tAirMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STALLCOH_TAIRMES: */
Std_ReturnType NVM_StallCoh_tAirMes__nvmini(void)
{
   StallCoh_tAirMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DECELCOH_BRKPED: */
Std_ReturnType NVM_DecelCoh_BrkPed__nvmini(void)
{
   DecelCoh_BrkPed__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ACCELCOH_BRKPED: */
Std_ReturnType NVM_AccelCoh_BrkPed__nvmini(void)
{
   AccelCoh_BrkPed__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVCOH_BRKPED: */
Std_ReturnType NVM_InvCoh_BrkPed__nvmini(void)
{
   InvCoh_BrkPed__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DECELCOH_BRKPEDBVH2P: */
Std_ReturnType NVM_DecelCoh_BrkPedBVH2p__nvmini(void)
{
   DecelCoh_BrkPedBVH2p__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ACCELCOH_BRKPEDBVH2P: */
Std_ReturnType NVM_AccelCoh_BrkPedBVH2p__nvmini(void)
{
   AccelCoh_BrkPedBVH2p__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COHBIT7_STDFTOBD: */
Std_ReturnType NVM_CohBit7_stDftOBD__nvmini(void)
{
   CohBit7_stDftOBD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COHBIT4_STDFTOBD: */
Std_ReturnType NVM_CohBit4_stDftOBD__nvmini(void)
{
   CohBit4_stDftOBD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COHBIT3_STDFTOBD: */
Std_ReturnType NVM_CohBit3_stDftOBD__nvmini(void)
{
   CohBit3_stDftOBD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COHBIT2_STDFTOBD: */
Std_ReturnType NVM_CohBit2_stDftOBD__nvmini(void)
{
   CohBit2_stDftOBD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKBATTSYS_IBATTMES: */
Std_ReturnType NVM_ChkBattSys_iBattMes__nvmini(void)
{
   ChkBattSys_iBattMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKBATTSYS_TBATTMES: */
Std_ReturnType NVM_ChkBattSys_tBattMes__nvmini(void)
{
   ChkBattSys_tBattMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKBATTSYS_UBATTCLC: */
Std_ReturnType NVM_ChkBattSys_uBattClc__nvmini(void)
{
   ChkBattSys_uBattClc__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STFULVLDFT: */
Std_ReturnType NVM_StFuLvlDft__nvmini(void)
{
   StFuLvlDft__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_BMODSPTREQ: */
Std_ReturnType NVM_Coh_bModSptReq__nvmini(void)
{
   Coh_bModSptReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_STCLUAC: */
Std_ReturnType NVM_Coh_stCluAC__nvmini(void)
{
   Coh_stCluAC__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_STPWRAC: */
Std_ReturnType NVM_Coh_stPwrAC__nvmini(void)
{
   Coh_stPwrAC__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_UDSLS: */
Std_ReturnType NVM_Scp_uDsLs__nvmini(void)
{
   Scp_uDsLs__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_UDSLS: */
Std_ReturnType NVM_Oc_uDsLs__nvmini(void)
{
   Oc_uDsLs__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_UDSLS: */
Std_ReturnType NVM_Scg_uDsLs__nvmini(void)
{
   Scg_uDsLs__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_SIGGRDDIAG: */
Std_ReturnType NVM_ORng_SigGrdDiag__nvmini(void)
{
   ORng_SigGrdDiag__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_DSPLAUSFLD: */
Std_ReturnType NVM_ORng_DsPlausFld__nvmini(void)
{
   ORng_DsPlausFld__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_DSPLAUSFCO: */
Std_ReturnType NVM_ORng_DsPlausFco__nvmini(void)
{
   ORng_DsPlausFco__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_UUPLS: */
Std_ReturnType NVM_Oc_uUpLs__nvmini(void)
{
   Oc_uUpLs__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_UUPLS: */
Std_ReturnType NVM_Scg_uUpLs__nvmini(void)
{
   Scg_uUpLs__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_UUPLS: */
Std_ReturnType NVM_Scp_uUpLs__nvmini(void)
{
   Scp_uUpLs__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_OXYSENSPERD: */
Std_ReturnType NVM_ORng_OxySensPerd__nvmini(void)
{
   ORng_OxySensPerd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_OXYAPVPERD: */
Std_ReturnType NVM_ORng_OxyApvPerd__nvmini(void)
{
   ORng_OxyApvPerd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_USPLAUSFLD: */
Std_ReturnType NVM_ORng_UsPlausFld__nvmini(void)
{
   ORng_UsPlausFld__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_USPLAUSFCO: */
Std_ReturnType NVM_ORng_UsPlausFco__nvmini(void)
{
   ORng_UsPlausFco__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_CLUST: */
Std_ReturnType NVM_Coh_CluSt__nvmini(void)
{
   Coh_CluSt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCK_CLUST: */
Std_ReturnType NVM_Stuck_CluSt__nvmini(void)
{
   Stuck_CluSt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_RCLUPEDPRSSMES: */
Std_ReturnType NVM_Scp_rCluPedPrssMes__nvmini(void)
{
   Scp_rCluPedPrssMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_RCLUPEDPRSSMES: */
Std_ReturnType NVM_Scg_rCluPedPrssMes__nvmini(void)
{
   Scg_rCluPedPrssMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_RCLUPEDPRSSMES: */
Std_ReturnType NVM_ORng_rCluPedPrssMes__nvmini(void)
{
   ORng_rCluPedPrssMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRD_RCLUPEDPRSSMES: */
Std_ReturnType NVM_Grd_rCluPedPrssMes__nvmini(void)
{
   Grd_rCluPedPrssMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FCTCLUP: */
Std_ReturnType NVM_FctCluP__nvmini(void)
{
   FctCluP__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_DRVRFAN1: */
Std_ReturnType NVM_Oc_DrvrFan1__nvmini(void)
{
   Oc_DrvrFan1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_DRVRFAN1: */
Std_ReturnType NVM_Lo_DrvrFan1__nvmini(void)
{
   Lo_DrvrFan1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_DRVRFAN1: */
Std_ReturnType NVM_Hi_DrvrFan1__nvmini(void)
{
   Hi_DrvrFan1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_DRVRFAN2: */
Std_ReturnType NVM_Oc_DrvrFan2__nvmini(void)
{
   Oc_DrvrFan2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_DRVRFAN2: */
Std_ReturnType NVM_Lo_DrvrFan2__nvmini(void)
{
   Lo_DrvrFan2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_DRVRFAN2: */
Std_ReturnType NVM_Hi_DrvrFan2__nvmini(void)
{
   Hi_DrvrFan2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_STFANB1: */
Std_ReturnType NVM_Coh_StFanB1__nvmini(void)
{
   Coh_StFanB1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_STFANB2LOSPD: */
Std_ReturnType NVM_Coh_StFanB2LoSpd__nvmini(void)
{
   Coh_StFanB2LoSpd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_STFANB2HISPD: */
Std_ReturnType NVM_Coh_StFanB2HiSpd__nvmini(void)
{
   Coh_StFanB2HiSpd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_STFANB2NOSPD: */
Std_ReturnType NVM_Coh_StFanB2NoSpd__nvmini(void)
{
   Coh_StFanB2NoSpd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CLSDRLY_STFANC: */
Std_ReturnType NVM_ClsdRly_StFanC__nvmini(void)
{
   ClsdRly_StFanC__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM EL_STFANC: */
Std_ReturnType NVM_El_StFanC__nvmini(void)
{
   El_StFanC__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM UNVLD_STFANC: */
Std_ReturnType NVM_UnVld_StFanC__nvmini(void)
{
   UnVld_StFanC__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CRITSC_STFANC: */
Std_ReturnType NVM_CritSc_StFanC__nvmini(void)
{
   CritSc_StFanC__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ECI_STFANC: */
Std_ReturnType NVM_ECI_StFanC__nvmini(void)
{
   ECI_StFanC__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_ECTREQ: */
Std_ReturnType NVM_Scp_ECTReq__nvmini(void)
{
   Scp_ECTReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_ECTREQ: */
Std_ReturnType NVM_Scg_ECTReq__nvmini(void)
{
   Scg_ECTReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_ECTREQ: */
Std_ReturnType NVM_Oc_ECTReq__nvmini(void)
{
   Oc_ECTReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LINBLOCKEDBUS: */
Std_ReturnType NVM_LinBlockedBus__nvmini(void)
{
   LinBlockedBus__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ALTABSENTECU: */
Std_ReturnType NVM_AltAbsentEcu__nvmini(void)
{
   AltAbsentEcu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ETAT_ALT1: */
Std_ReturnType NVM_Etat_Alt1__nvmini(void)
{
   Etat_Alt1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ETAT_ALT2: */
Std_ReturnType NVM_Etat_Alt2__nvmini(void)
{
   Etat_Alt2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TRCK_TCOMES: */
Std_ReturnType NVM_Trck_tCoMes__nvmini(void)
{
   Trck_tCoMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM WUP_TCOMES: */
Std_ReturnType NVM_Wup_tCoMes__nvmini(void)
{
   Wup_tCoMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LOCSTRDRV: */
Std_ReturnType NVM_LoCstrDrv__nvmini(void)
{
   LoCstrDrv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HICSTRDRV: */
Std_ReturnType NVM_HiCstrDrv__nvmini(void)
{
   HiCstrDrv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELINFBSIDFT: */
Std_ReturnType NVM_ElInfBsiDft__nvmini(void)
{
   ElInfBsiDft__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCPTTRABSIDFT: */
Std_ReturnType NVM_ElCptTraBsiDft__nvmini(void)
{
   ElCptTraBsiDft__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCHKCONSDFT: */
Std_ReturnType NVM_ElChkConsDft__nvmini(void)
{
   ElChkConsDft__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCONSDEFDFTVSLIM: */
Std_ReturnType NVM_ElConsDefDftVSLim__nvmini(void)
{
   ElConsDefDftVSLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCONSVARDFTVSLIM: */
Std_ReturnType NVM_ElConsVarDftVSLim__nvmini(void)
{
   ElConsVarDftVSLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCONSDEFDFTVSREG: */
Std_ReturnType NVM_ElConsDefDftVSReg__nvmini(void)
{
   ElConsDefDftVSReg__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCONSVARDFTVSREG: */
Std_ReturnType NVM_ElConsVarDftVSReg__nvmini(void)
{
   ElConsVarDftVSReg__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCONSINITDFTVSREG: */
Std_ReturnType NVM_ElConsInitDftVSReg__nvmini(void)
{
   ElConsInitDftVSReg__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELDFTCRSCTL: */
Std_ReturnType NVM_ElDftCrsCtl__nvmini(void)
{
   ElDftCrsCtl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ZEROFRAMECNTDFT: */
Std_ReturnType NVM_ZeroFrameCntDft__nvmini(void)
{
   ZeroFrameCntDft__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM EVENFRAMECNTDFT: */
Std_ReturnType NVM_EvenFrameCntDft__nvmini(void)
{
   EvenFrameCntDft__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELFRAMECNTINCDFT: */
Std_ReturnType NVM_ElFrameCntIncDft__nvmini(void)
{
   ElFrameCntIncDft__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCONSCOHVSMAXP: */
Std_ReturnType NVM_ElConsCohVSMaxp__nvmini(void)
{
   ElConsCohVSMaxp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELCONSDEFDFTVSMAXP: */
Std_ReturnType NVM_ElConsDefDftVSMaxp__nvmini(void)
{
   ElConsDefDftVSMaxp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CRSCTLDFT: */
Std_ReturnType NVM_CrsCtlDft__nvmini(void)
{
   CrsCtlDft__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM F432LOST: */
Std_ReturnType NVM_F432Lost__nvmini(void)
{
   F432Lost__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTEEPROM: */
Std_ReturnType NVM_DftEeprom__nvmini(void)
{
   DftEeprom__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FLASHCHK: */
Std_ReturnType NVM_FlashChk__nvmini(void)
{
   FlashChk__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_BINHCRKALTHW: */
Std_ReturnType NVM_Scp_bInhCrkAltHw__nvmini(void)
{
   Scp_bInhCrkAltHw__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_BINHCRKALTHW: */
Std_ReturnType NVM_Scg_bInhCrkAltHw__nvmini(void)
{
   Scg_bInhCrkAltHw__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_UDFTSTACMD: */
Std_ReturnType NVM_Scp_uDftStaCmd__nvmini(void)
{
   Scp_uDftStaCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_UDFTSTACMD: */
Std_ReturnType NVM_Scg_uDftStaCmd__nvmini(void)
{
   Scg_uDftStaCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLD_UDFTSTACMD: */
Std_ReturnType NVM_Invld_uDftStaCmd__nvmini(void)
{
   Invld_uDftStaCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_ENGSTOUTIDC: */
Std_ReturnType NVM_Scp_EngStOutIdc__nvmini(void)
{
   Scp_EngStOutIdc__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_ENGSTOUTIDC: */
Std_ReturnType NVM_Scg_EngStOutIdc__nvmini(void)
{
   Scg_EngStOutIdc__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_ENGSTOUTIDC: */
Std_ReturnType NVM_Oc_EngStOutIdc__nvmini(void)
{
   Oc_EngStOutIdc__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGPFUENGST: */
Std_ReturnType NVM_ORngPFuEngSt__nvmini(void)
{
   ORngPFuEngSt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGUNLOCKENGST: */
Std_ReturnType NVM_ORngUnlockEngSt__nvmini(void)
{
   ORngUnlockEngSt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSYNCENGST: */
Std_ReturnType NVM_ORngSyncEngSt__nvmini(void)
{
   ORngSyncEngSt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSTRTENGST: */
Std_ReturnType NVM_ORngStrtEngSt__nvmini(void)
{
   ORngStrtEngSt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_DML: */
Std_ReturnType NVM_Scp_Dml__nvmini(void)
{
   Scp_Dml__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_DML: */
Std_ReturnType NVM_Oc_Dml__nvmini(void)
{
   Oc_Dml__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_DML: */
Std_ReturnType NVM_Scg_Dml__nvmini(void)
{
   Scg_Dml__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BLOCK_STRTR: */
Std_ReturnType NVM_Block_Strtr__nvmini(void)
{
   Block_Strtr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM REDESLIM: */
Std_ReturnType NVM_RedESLim__nvmini(void)
{
   RedESLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_FUGAUGELVL: */
Std_ReturnType NVM_ORng_FuGaugeLvl__nvmini(void)
{
   ORng_FuGaugeLvl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LOFULVL: */
Std_ReturnType NVM_LoFuLvl__nvmini(void)
{
   LoFuLvl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_FUGAUGE: */
Std_ReturnType NVM_Oc_FuGauge__nvmini(void)
{
   Oc_FuGauge__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_FUGAUGE: */
Std_ReturnType NVM_ORng_FuGauge__nvmini(void)
{
   ORng_FuGauge__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_FUGAUGE: */
Std_ReturnType NVM_Scg_FuGauge__nvmini(void)
{
   Scg_FuGauge__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_PROPFUPMP: */
Std_ReturnType NVM_Scg_PropFuPmp__nvmini(void)
{
   Scg_PropFuPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_PROPFUPMP: */
Std_ReturnType NVM_Scp_PropFuPmp__nvmini(void)
{
   Scp_PropFuPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_PROPFUPMP: */
Std_ReturnType NVM_Oc_PropFuPmp__nvmini(void)
{
   Oc_PropFuPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MAP_PROPFUPMP: */
Std_ReturnType NVM_Map_PropFuPmp__nvmini(void)
{
   Map_PropFuPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM GRAVSCP_PROPFUPMP: */
Std_ReturnType NVM_GravScp_PropFuPmp__nvmini(void)
{
   GravScp_PropFuPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRQ_PROPFUPMP: */
Std_ReturnType NVM_Frq_PropFuPmp__nvmini(void)
{
   Frq_PropFuPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM RVSGEAR: */
Std_ReturnType NVM_RvsGear__nvmini(void)
{
   RvsGear__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_BNEUT: */
Std_ReturnType NVM_Scp_bNeut__nvmini(void)
{
   Scp_bNeut__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_BNEUT: */
Std_ReturnType NVM_Scg_bNeut__nvmini(void)
{
   Scg_bNeut__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_BNEUT: */
Std_ReturnType NVM_ORng_bNeut__nvmini(void)
{
   ORng_bNeut__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_STRTLOCK: */
Std_ReturnType NVM_Coh_StrtLock__nvmini(void)
{
   Coh_StrtLock__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_DRVRSENO2DS: */
Std_ReturnType NVM_Hi_DrvrSenO2Ds__nvmini(void)
{
   Hi_DrvrSenO2Ds__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_DRVRSENO2DS: */
Std_ReturnType NVM_Lo_DrvrSenO2Ds__nvmini(void)
{
   Lo_DrvrSenO2Ds__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_DRVRSENO2US: */
Std_ReturnType NVM_Hi_DrvrSenO2Us__nvmini(void)
{
   Hi_DrvrSenO2Us__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_DRVRSENO2US: */
Std_ReturnType NVM_Lo_DrvrSenO2Us__nvmini(void)
{
   Lo_DrvrSenO2Us__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_USHEAT: */
Std_ReturnType NVM_ORng_UsHeat__nvmini(void)
{
   ORng_UsHeat__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_DSHEAT: */
Std_ReturnType NVM_ORng_DsHeat__nvmini(void)
{
   ORng_DsHeat__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_IGCOIL1CMD: */
Std_ReturnType NVM_Oc_IgCoil1Cmd__nvmini(void)
{
   Oc_IgCoil1Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_IGCOIL1CMD: */
Std_ReturnType NVM_Scp_IgCoil1Cmd__nvmini(void)
{
   Scp_IgCoil1Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_IGCOIL2CMD: */
Std_ReturnType NVM_Oc_IgCoil2Cmd__nvmini(void)
{
   Oc_IgCoil2Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_IGCOIL2CMD: */
Std_ReturnType NVM_Scp_IgCoil2Cmd__nvmini(void)
{
   Scp_IgCoil2Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_IGCOIL3CMD: */
Std_ReturnType NVM_Oc_IgCoil3Cmd__nvmini(void)
{
   Oc_IgCoil3Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_IGCOIL3CMD: */
Std_ReturnType NVM_Scp_IgCoil3Cmd__nvmini(void)
{
   Scp_IgCoil3Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_IGCOIL4CMD: */
Std_ReturnType NVM_Oc_IgCoil4Cmd__nvmini(void)
{
   Oc_IgCoil4Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_IGCOIL4CMD: */
Std_ReturnType NVM_Scp_IgCoil4Cmd__nvmini(void)
{
   Scp_IgCoil4Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CMMABSENT: */
Std_ReturnType NVM_CmmAbsent__nvmini(void)
{
   CmmAbsent__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CAPT_VOLABSENT: */
Std_ReturnType NVM_CAPT_VOLAbsent__nvmini(void)
{
   CAPT_VOLAbsent__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF305: */
Std_ReturnType NVM_MissF305__nvmini(void)
{
   MissF305__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF305: */
Std_ReturnType NVM_ShoF305__nvmini(void)
{
   ShoF305__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKF305: */
Std_ReturnType NVM_ChkF305__nvmini(void)
{
   ChkF305__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CNTF305: */
Std_ReturnType NVM_CntF305__nvmini(void)
{
   CntF305__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF305P537: */
Std_ReturnType NVM_InvldF305P537__nvmini(void)
{
   InvldF305P537__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF305P538: */
Std_ReturnType NVM_InvldF305P538__nvmini(void)
{
   InvldF305P538__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF305P537: */
Std_ReturnType NVM_FrbdF305P537__nvmini(void)
{
   FrbdF305P537__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF30D: */
Std_ReturnType NVM_MissF30D__nvmini(void)
{
   MissF30D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF30D: */
Std_ReturnType NVM_ShoF30D__nvmini(void)
{
   ShoF30D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF30DP263: */
Std_ReturnType NVM_InvldF30DP263__nvmini(void)
{
   InvldF30DP263__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF30DP264: */
Std_ReturnType NVM_InvldF30DP264__nvmini(void)
{
   InvldF30DP264__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF30DP265: */
Std_ReturnType NVM_InvldF30DP265__nvmini(void)
{
   InvldF30DP265__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF30DP266: */
Std_ReturnType NVM_InvldF30DP266__nvmini(void)
{
   InvldF30DP266__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF329: */
Std_ReturnType NVM_MissF329__nvmini(void)
{
   MissF329__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF329: */
Std_ReturnType NVM_ShoF329__nvmini(void)
{
   ShoF329__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKF329: */
Std_ReturnType NVM_ChkF329__nvmini(void)
{
   ChkF329__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CNTF329: */
Std_ReturnType NVM_CntF329__nvmini(void)
{
   CntF329__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF329P445: */
Std_ReturnType NVM_InvldF329P445__nvmini(void)
{
   InvldF329P445__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF329P445: */
Std_ReturnType NVM_FrbdF329P445__nvmini(void)
{
   FrbdF329P445__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF329P397: */
Std_ReturnType NVM_FrbdF329P397__nvmini(void)
{
   FrbdF329P397__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF349: */
Std_ReturnType NVM_MissF349__nvmini(void)
{
   MissF349__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF349: */
Std_ReturnType NVM_ShoF349__nvmini(void)
{
   ShoF349__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKF349: */
Std_ReturnType NVM_ChkF349__nvmini(void)
{
   ChkF349__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CNTF349: */
Std_ReturnType NVM_CntF349__nvmini(void)
{
   CntF349__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF349P007: */
Std_ReturnType NVM_InvldF349P007__nvmini(void)
{
   InvldF349P007__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF349P055: */
Std_ReturnType NVM_InvldF349P055__nvmini(void)
{
   InvldF349P055__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF349P360: */
Std_ReturnType NVM_FrbdF349P360__nvmini(void)
{
   FrbdF349P360__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF349P057: */
Std_ReturnType NVM_FrbdF349P057__nvmini(void)
{
   FrbdF349P057__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF349P008: */
Std_ReturnType NVM_FrbdF349P008__nvmini(void)
{
   FrbdF349P008__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF349P007: */
Std_ReturnType NVM_FrbdF349P007__nvmini(void)
{
   FrbdF349P007__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF349P287: */
Std_ReturnType NVM_FrbdF349P287__nvmini(void)
{
   FrbdF349P287__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF349PM1434: */
Std_ReturnType NVM_FrbdF349PM1434__nvmini(void)
{
   FrbdF349PM1434__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF349P166: */
Std_ReturnType NVM_FrbdF349P166__nvmini(void)
{
   FrbdF349P166__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF34D: */
Std_ReturnType NVM_MissF34D__nvmini(void)
{
   MissF34D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF34D: */
Std_ReturnType NVM_ShoF34D__nvmini(void)
{
   ShoF34D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CNTF34D: */
Std_ReturnType NVM_CntF34D__nvmini(void)
{
   CntF34D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF34DFP0593: */
Std_ReturnType NVM_InvldF34DFP0593__nvmini(void)
{
   InvldF34DFP0593__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF34DPM1413: */
Std_ReturnType NVM_InvldF34DPM1413__nvmini(void)
{
   InvldF34DPM1413__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF34DP047: */
Std_ReturnType NVM_FrbdF34DP047__nvmini(void)
{
   FrbdF34DP047__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF34DP043: */
Std_ReturnType NVM_FrbdF34DP043__nvmini(void)
{
   FrbdF34DP043__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF34DP044: */
Std_ReturnType NVM_FrbdF34DP044__nvmini(void)
{
   FrbdF34DP044__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF34DP045: */
Std_ReturnType NVM_FrbdF34DP045__nvmini(void)
{
   FrbdF34DP045__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF34DFP0593: */
Std_ReturnType NVM_FrbdF34DFP0593__nvmini(void)
{
   FrbdF34DFP0593__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF34DPM1413: */
Std_ReturnType NVM_FrbdF34DPM1413__nvmini(void)
{
   FrbdF34DPM1413__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM UC_FREINABSENT: */
Std_ReturnType NVM_UC_FREINAbsent__nvmini(void)
{
   UC_FREINAbsent__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF38D: */
Std_ReturnType NVM_MissF38D__nvmini(void)
{
   MissF38D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF38D: */
Std_ReturnType NVM_ShoF38D__nvmini(void)
{
   ShoF38D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKF38D: */
Std_ReturnType NVM_ChkF38D__nvmini(void)
{
   ChkF38D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CNTF38D: */
Std_ReturnType NVM_CntF38D__nvmini(void)
{
   CntF38D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF38DP010: */
Std_ReturnType NVM_InvldF38DP010__nvmini(void)
{
   InvldF38DP010__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF38DP052: */
Std_ReturnType NVM_InvldF38DP052__nvmini(void)
{
   InvldF38DP052__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF3AD: */
Std_ReturnType NVM_MissF3AD__nvmini(void)
{
   MissF3AD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF3AD: */
Std_ReturnType NVM_ShoF3AD__nvmini(void)
{
   ShoF3AD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKF3AD: */
Std_ReturnType NVM_ChkF3AD__nvmini(void)
{
   ChkF3AD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CNTF3AD: */
Std_ReturnType NVM_CntF3AD__nvmini(void)
{
   CntF3AD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF3ADP337: */
Std_ReturnType NVM_FrbdF3ADP337__nvmini(void)
{
   FrbdF3ADP337__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF3C9: */
Std_ReturnType NVM_MissF3C9__nvmini(void)
{
   MissF3C9__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF3C9: */
Std_ReturnType NVM_ShoF3C9__nvmini(void)
{
   ShoF3C9__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKF3C9: */
Std_ReturnType NVM_ChkF3C9__nvmini(void)
{
   ChkF3C9__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CNTF3C9: */
Std_ReturnType NVM_CntF3C9__nvmini(void)
{
   CntF3C9__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF3C9P363: */
Std_ReturnType NVM_InvldF3C9P363__nvmini(void)
{
   InvldF3C9P363__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF3C9P364: */
Std_ReturnType NVM_InvldF3C9P364__nvmini(void)
{
   InvldF3C9P364__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF3C9P482: */
Std_ReturnType NVM_InvldF3C9P482__nvmini(void)
{
   InvldF3C9P482__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF3C9P483: */
Std_ReturnType NVM_InvldF3C9P483__nvmini(void)
{
   InvldF3C9P483__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF3C9P481: */
Std_ReturnType NVM_FrbdF3C9P481__nvmini(void)
{
   FrbdF3C9P481__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF3C9P364: */
Std_ReturnType NVM_FrbdF3C9P364__nvmini(void)
{
   FrbdF3C9P364__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF3C9P482: */
Std_ReturnType NVM_FrbdF3C9P482__nvmini(void)
{
   FrbdF3C9P482__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF3C9P483: */
Std_ReturnType NVM_FrbdF3C9P483__nvmini(void)
{
   FrbdF3C9P483__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF3CD: */
Std_ReturnType NVM_MissF3CD__nvmini(void)
{
   MissF3CD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF3CD: */
Std_ReturnType NVM_ShoF3CD__nvmini(void)
{
   ShoF3CD__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF3CDP225: */
Std_ReturnType NVM_InvldF3CDP225__nvmini(void)
{
   InvldF3CDP225__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF3CDP515: */
Std_ReturnType NVM_InvldF3CDP515__nvmini(void)
{
   InvldF3CDP515__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF3CDP319: */
Std_ReturnType NVM_InvldF3CDP319__nvmini(void)
{
   InvldF3CDP319__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF3CDPM1387: */
Std_ReturnType NVM_FrbdF3CDPM1387__nvmini(void)
{
   FrbdF3CDPM1387__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF3CDP319: */
Std_ReturnType NVM_FrbdF3CDP319__nvmini(void)
{
   FrbdF3CDP319__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF412: */
Std_ReturnType NVM_MissF412__nvmini(void)
{
   MissF412__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF412: */
Std_ReturnType NVM_ShoF412__nvmini(void)
{
   ShoF412__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF412P040: */
Std_ReturnType NVM_InvldF412P040__nvmini(void)
{
   InvldF412P040__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF432: */
Std_ReturnType NVM_MissF432__nvmini(void)
{
   MissF432__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF432: */
Std_ReturnType NVM_ShoF432__nvmini(void)
{
   ShoF432__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF432P214: */
Std_ReturnType NVM_InvldF432P214__nvmini(void)
{
   InvldF432P214__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF432P249: */
Std_ReturnType NVM_FrbdF432P249__nvmini(void)
{
   FrbdF432P249__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF432P251: */
Std_ReturnType NVM_FrbdF432P251__nvmini(void)
{
   FrbdF432P251__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF432P402: */
Std_ReturnType NVM_FrbdF432P402__nvmini(void)
{
   FrbdF432P402__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF432P368: */
Std_ReturnType NVM_FrbdF432P368__nvmini(void)
{
   FrbdF432P368__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF432P369: */
Std_ReturnType NVM_FrbdF432P369__nvmini(void)
{
   FrbdF432P369__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF432PM1424: */
Std_ReturnType NVM_FrbdF432PM1424__nvmini(void)
{
   FrbdF432PM1424__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF44D: */
Std_ReturnType NVM_MissF44D__nvmini(void)
{
   MissF44D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF44D: */
Std_ReturnType NVM_ShoF44D__nvmini(void)
{
   ShoF44D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF44DFP0535: */
Std_ReturnType NVM_InvldF44DFP0535__nvmini(void)
{
   InvldF44DFP0535__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF44DP330: */
Std_ReturnType NVM_InvldF44DP330__nvmini(void)
{
   InvldF44DP330__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF44DP331: */
Std_ReturnType NVM_InvldF44DP331__nvmini(void)
{
   InvldF44DP331__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF44DP354: */
Std_ReturnType NVM_InvldF44DP354__nvmini(void)
{
   InvldF44DP354__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF44DP354: */
Std_ReturnType NVM_FrbdF44DP354__nvmini(void)
{
   FrbdF44DP354__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BVABSENT: */
Std_ReturnType NVM_BVAbsent__nvmini(void)
{
   BVAbsent__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF489: */
Std_ReturnType NVM_MissF489__nvmini(void)
{
   MissF489__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF489: */
Std_ReturnType NVM_ShoF489__nvmini(void)
{
   ShoF489__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF489P102: */
Std_ReturnType NVM_InvldF489P102__nvmini(void)
{
   InvldF489P102__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF489P254: */
Std_ReturnType NVM_InvldF489P254__nvmini(void)
{
   InvldF489P254__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF489P218: */
Std_ReturnType NVM_InvldF489P218__nvmini(void)
{
   InvldF489P218__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF489P254: */
Std_ReturnType NVM_FrbdF489P254__nvmini(void)
{
   FrbdF489P254__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF489P218: */
Std_ReturnType NVM_FrbdF489P218__nvmini(void)
{
   FrbdF489P218__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF492: */
Std_ReturnType NVM_MissF492__nvmini(void)
{
   MissF492__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF492: */
Std_ReturnType NVM_ShoF492__nvmini(void)
{
   ShoF492__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF495: */
Std_ReturnType NVM_MissF495__nvmini(void)
{
   MissF495__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF495: */
Std_ReturnType NVM_ShoF495__nvmini(void)
{
   ShoF495__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF4B2: */
Std_ReturnType NVM_MissF4B2__nvmini(void)
{
   MissF4B2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF4B2: */
Std_ReturnType NVM_ShoF4B2__nvmini(void)
{
   ShoF4B2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF4D2: */
Std_ReturnType NVM_MissF4D2__nvmini(void)
{
   MissF4D2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF4D2: */
Std_ReturnType NVM_ShoF4D2__nvmini(void)
{
   ShoF4D2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF4F2: */
Std_ReturnType NVM_MissF4F2__nvmini(void)
{
   MissF4F2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF4F2: */
Std_ReturnType NVM_ShoF4F2__nvmini(void)
{
   ShoF4F2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF4F2P434: */
Std_ReturnType NVM_InvldF4F2P434__nvmini(void)
{
   InvldF4F2P434__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF4F2P438: */
Std_ReturnType NVM_InvldF4F2P438__nvmini(void)
{
   InvldF4F2P438__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF4F2P429: */
Std_ReturnType NVM_InvldF4F2P429__nvmini(void)
{
   InvldF4F2P429__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF4F2P437: */
Std_ReturnType NVM_InvldF4F2P437__nvmini(void)
{
   InvldF4F2P437__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF4F2P490: */
Std_ReturnType NVM_InvldF4F2P490__nvmini(void)
{
   InvldF4F2P490__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF4F2P491: */
Std_ReturnType NVM_InvldF4F2P491__nvmini(void)
{
   InvldF4F2P491__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF4F2P492: */
Std_ReturnType NVM_InvldF4F2P492__nvmini(void)
{
   InvldF4F2P492__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF4F2P434: */
Std_ReturnType NVM_FrbdF4F2P434__nvmini(void)
{
   FrbdF4F2P434__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF4F2P438: */
Std_ReturnType NVM_FrbdF4F2P438__nvmini(void)
{
   FrbdF4F2P438__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF4F2P437: */
Std_ReturnType NVM_FrbdF4F2P437__nvmini(void)
{
   FrbdF4F2P437__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF4F2P490: */
Std_ReturnType NVM_FrbdF4F2P490__nvmini(void)
{
   FrbdF4F2P490__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF4F2P493: */
Std_ReturnType NVM_FrbdF4F2P493__nvmini(void)
{
   FrbdF4F2P493__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF4F2P491: */
Std_ReturnType NVM_FrbdF4F2P491__nvmini(void)
{
   FrbdF4F2P491__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF4F2P494: */
Std_ReturnType NVM_FrbdF4F2P494__nvmini(void)
{
   FrbdF4F2P494__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF4F2P492: */
Std_ReturnType NVM_FrbdF4F2P492__nvmini(void)
{
   FrbdF4F2P492__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF50D: */
Std_ReturnType NVM_MissF50D__nvmini(void)
{
   MissF50D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF50D: */
Std_ReturnType NVM_ShoF50D__nvmini(void)
{
   ShoF50D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CHKF50D: */
Std_ReturnType NVM_ChkF50D__nvmini(void)
{
   ChkF50D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CNTF50D: */
Std_ReturnType NVM_CntF50D__nvmini(void)
{
   CntF50D__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BSIABSENT: */
Std_ReturnType NVM_BSIAbsent__nvmini(void)
{
   BSIAbsent__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF50E: */
Std_ReturnType NVM_MissF50E__nvmini(void)
{
   MissF50E__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF50E: */
Std_ReturnType NVM_ShoF50E__nvmini(void)
{
   ShoF50E__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF50EPM1386: */
Std_ReturnType NVM_InvldF50EPM1386__nvmini(void)
{
   InvldF50EPM1386__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF50EP046: */
Std_ReturnType NVM_InvldF50EP046__nvmini(void)
{
   InvldF50EP046__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF50EP210: */
Std_ReturnType NVM_InvldF50EP210__nvmini(void)
{
   InvldF50EP210__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF50EP046: */
Std_ReturnType NVM_FrbdF50EP046__nvmini(void)
{
   FrbdF50EP046__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF50EP417: */
Std_ReturnType NVM_FrbdF50EP417__nvmini(void)
{
   FrbdF50EP417__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF50EP208: */
Std_ReturnType NVM_FrbdF50EP208__nvmini(void)
{
   FrbdF50EP208__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF532: */
Std_ReturnType NVM_MissF532__nvmini(void)
{
   MissF532__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF532: */
Std_ReturnType NVM_ShoF532__nvmini(void)
{
   ShoF532__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF532PM1414: */
Std_ReturnType NVM_InvldF532PM1414__nvmini(void)
{
   InvldF532PM1414__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF532PM1415: */
Std_ReturnType NVM_InvldF532PM1415__nvmini(void)
{
   InvldF532PM1415__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF532PM1416: */
Std_ReturnType NVM_InvldF532PM1416__nvmini(void)
{
   InvldF532PM1416__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF532PM1414: */
Std_ReturnType NVM_FrbdF532PM1414__nvmini(void)
{
   FrbdF532PM1414__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF532PM1415: */
Std_ReturnType NVM_FrbdF532PM1415__nvmini(void)
{
   FrbdF532PM1415__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF532PM1416: */
Std_ReturnType NVM_FrbdF532PM1416__nvmini(void)
{
   FrbdF532PM1416__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF552: */
Std_ReturnType NVM_MissF552__nvmini(void)
{
   MissF552__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF552: */
Std_ReturnType NVM_ShoF552__nvmini(void)
{
   ShoF552__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF552P255: */
Std_ReturnType NVM_InvldF552P255__nvmini(void)
{
   InvldF552P255__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF552P256: */
Std_ReturnType NVM_InvldF552P256__nvmini(void)
{
   InvldF552P256__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF552P257: */
Std_ReturnType NVM_InvldF552P257__nvmini(void)
{
   InvldF552P257__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF552P325: */
Std_ReturnType NVM_InvldF552P325__nvmini(void)
{
   InvldF552P325__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF552P015: */
Std_ReturnType NVM_InvldF552P015__nvmini(void)
{
   InvldF552P015__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF552P326: */
Std_ReturnType NVM_InvldF552P326__nvmini(void)
{
   InvldF552P326__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF552P255: */
Std_ReturnType NVM_FrbdF552P255__nvmini(void)
{
   FrbdF552P255__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF552P256: */
Std_ReturnType NVM_FrbdF552P256__nvmini(void)
{
   FrbdF552P256__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF552P257: */
Std_ReturnType NVM_FrbdF552P257__nvmini(void)
{
   FrbdF552P257__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF572: */
Std_ReturnType NVM_MissF572__nvmini(void)
{
   MissF572__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF572: */
Std_ReturnType NVM_ShoF572__nvmini(void)
{
   ShoF572__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF572PM1360: */
Std_ReturnType NVM_InvldF572PM1360__nvmini(void)
{
   InvldF572PM1360__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF572PM1360: */
Std_ReturnType NVM_FrbdF572PM1360__nvmini(void)
{
   FrbdF572PM1360__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DMTRABSENT: */
Std_ReturnType NVM_DMTRAbsent__nvmini(void)
{
   DMTRAbsent__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF57C: */
Std_ReturnType NVM_MissF57C__nvmini(void)
{
   MissF57C__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF57C: */
Std_ReturnType NVM_ShoF57C__nvmini(void)
{
   ShoF57C__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF57CPM1418: */
Std_ReturnType NVM_InvldF57CPM1418__nvmini(void)
{
   InvldF57CPM1418__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF592: */
Std_ReturnType NVM_MissF592__nvmini(void)
{
   MissF592__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF592: */
Std_ReturnType NVM_ShoF592__nvmini(void)
{
   ShoF592__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LIDF592: */
Std_ReturnType NVM_LIDF592__nvmini(void)
{
   LIDF592__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P272: */
Std_ReturnType NVM_InvldF592P272__nvmini(void)
{
   InvldF592P272__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P273: */
Std_ReturnType NVM_InvldF592P273__nvmini(void)
{
   InvldF592P273__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P349: */
Std_ReturnType NVM_InvldF592P349__nvmini(void)
{
   InvldF592P349__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P418: */
Std_ReturnType NVM_InvldF592P418__nvmini(void)
{
   InvldF592P418__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P419: */
Std_ReturnType NVM_InvldF592P419__nvmini(void)
{
   InvldF592P419__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P420: */
Std_ReturnType NVM_InvldF592P420__nvmini(void)
{
   InvldF592P420__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P421_1: */
Std_ReturnType NVM_InvldF592P421_1__nvmini(void)
{
   InvldF592P421_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P421_2: */
Std_ReturnType NVM_InvldF592P421_2__nvmini(void)
{
   InvldF592P421_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF592P421_3: */
Std_ReturnType NVM_InvldF592P421_3__nvmini(void)
{
   InvldF592P421_3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF592P272: */
Std_ReturnType NVM_FrbdF592P272__nvmini(void)
{
   FrbdF592P272__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF592P273: */
Std_ReturnType NVM_FrbdF592P273__nvmini(void)
{
   FrbdF592P273__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF592P349: */
Std_ReturnType NVM_FrbdF592P349__nvmini(void)
{
   FrbdF592P349__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF592P418: */
Std_ReturnType NVM_FrbdF592P418__nvmini(void)
{
   FrbdF592P418__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF592P419: */
Std_ReturnType NVM_FrbdF592P419__nvmini(void)
{
   FrbdF592P419__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF592P421_1: */
Std_ReturnType NVM_FrbdF592P421_1__nvmini(void)
{
   FrbdF592P421_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF592P421_2: */
Std_ReturnType NVM_FrbdF592P421_2__nvmini(void)
{
   FrbdF592P421_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF592P421_3: */
Std_ReturnType NVM_FrbdF592P421_3__nvmini(void)
{
   FrbdF592P421_3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF5B2: */
Std_ReturnType NVM_MissF5B2__nvmini(void)
{
   MissF5B2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF5B2: */
Std_ReturnType NVM_ShoF5B2__nvmini(void)
{
   ShoF5B2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF5B2P146: */
Std_ReturnType NVM_InvldF5B2P146__nvmini(void)
{
   InvldF5B2P146__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF5B2P146: */
Std_ReturnType NVM_FrbdF5B2P146__nvmini(void)
{
   FrbdF5B2P146__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF612: */
Std_ReturnType NVM_MissF612__nvmini(void)
{
   MissF612__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF612: */
Std_ReturnType NVM_ShoF612__nvmini(void)
{
   ShoF612__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF612P260: */
Std_ReturnType NVM_InvldF612P260__nvmini(void)
{
   InvldF612P260__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF612P436: */
Std_ReturnType NVM_InvldF612P436__nvmini(void)
{
   InvldF612P436__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF612P705: */
Std_ReturnType NVM_InvldF612P705__nvmini(void)
{
   InvldF612P705__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF612P927: */
Std_ReturnType NVM_FrbdF612P927__nvmini(void)
{
   FrbdF612P927__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF612P436: */
Std_ReturnType NVM_FrbdF612P436__nvmini(void)
{
   FrbdF612P436__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF792: */
Std_ReturnType NVM_MissF792__nvmini(void)
{
   MissF792__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF792: */
Std_ReturnType NVM_ShoF792__nvmini(void)
{
   ShoF792__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSF7F2: */
Std_ReturnType NVM_MissF7F2__nvmini(void)
{
   MissF7F2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SHOF7F2: */
Std_ReturnType NVM_ShoF7F2__nvmini(void)
{
   ShoF7F2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LIDF7F2: */
Std_ReturnType NVM_LIDF7F2__nvmini(void)
{
   LIDF7F2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF7F2P146: */
Std_ReturnType NVM_InvldF7F2P146__nvmini(void)
{
   InvldF7F2P146__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INVLDF7F2P015: */
Std_ReturnType NVM_InvldF7F2P015__nvmini(void)
{
   InvldF7F2P015__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF7F2P849: */
Std_ReturnType NVM_FrbdF7F2P849__nvmini(void)
{
   FrbdF7F2P849__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FRBDF7F2P146: */
Std_ReturnType NVM_FrbdF7F2P146__nvmini(void)
{
   FrbdF7F2P146__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_INJ1CMD: */
Std_ReturnType NVM_Scp_Inj1Cmd__nvmini(void)
{
   Scp_Inj1Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_INJ1CMD: */
Std_ReturnType NVM_Oc_Inj1Cmd__nvmini(void)
{
   Oc_Inj1Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_INJ2CMD: */
Std_ReturnType NVM_Scp_Inj2Cmd__nvmini(void)
{
   Scp_Inj2Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_INJ2CMD: */
Std_ReturnType NVM_Oc_Inj2Cmd__nvmini(void)
{
   Oc_Inj2Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_INJ3CMD: */
Std_ReturnType NVM_Scp_Inj3Cmd__nvmini(void)
{
   Scp_Inj3Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_INJ3CMD: */
Std_ReturnType NVM_Oc_Inj3Cmd__nvmini(void)
{
   Oc_Inj3Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_INJ4CMD: */
Std_ReturnType NVM_Scp_Inj4Cmd__nvmini(void)
{
   Scp_Inj4Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_INJ4CMD: */
Std_ReturnType NVM_Oc_Inj4Cmd__nvmini(void)
{
   Oc_Inj4Cmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGLFBK_AFL: */
Std_ReturnType NVM_ORngLfbk_Afl__nvmini(void)
{
   ORngLfbk_Afl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTFU_AFL: */
Std_ReturnType NVM_DftFu_Afl__nvmini(void)
{
   DftFu_Afl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTSENO2_AFL: */
Std_ReturnType NVM_DftSenO2_Afl__nvmini(void)
{
   DftSenO2_Afl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGLFBKGAS_AFL: */
Std_ReturnType NVM_ORngLfbkGas_Afl__nvmini(void)
{
   ORngLfbkGas_Afl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTFUGAS_AFL: */
Std_ReturnType NVM_DftFuGas_Afl__nvmini(void)
{
   DftFuGas_Afl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTSENO2GAS_AFL: */
Std_ReturnType NVM_DftSenO2Gas_Afl__nvmini(void)
{
   DftSenO2Gas_Afl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGLFBK_AFR: */
Std_ReturnType NVM_ORngLfbk_Afr__nvmini(void)
{
   ORngLfbk_Afr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTFU_AFR: */
Std_ReturnType NVM_DftFu_Afr__nvmini(void)
{
   DftFu_Afr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTSENO2_AFR: */
Std_ReturnType NVM_DftSenO2_Afr__nvmini(void)
{
   DftSenO2_Afr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGLFBKGAS_AFR: */
Std_ReturnType NVM_ORngLfbkGas_Afr__nvmini(void)
{
   ORngLfbkGas_Afr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTFUGAS_AFR: */
Std_ReturnType NVM_DftFuGas_Afr__nvmini(void)
{
   DftFuGas_Afr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTSENO2GAS_AFR: */
Std_ReturnType NVM_DftSenO2Gas_Afr__nvmini(void)
{
   DftSenO2Gas_Afr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HITALT_ALTCTL: */
Std_ReturnType NVM_HiTAlt_AltCtl__nvmini(void)
{
   HiTAlt_AltCtl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MECAALT_ALTCTL: */
Std_ReturnType NVM_MecaAlt_AltCtl__nvmini(void)
{
   MecaAlt_AltCtl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELECALT_ALTCTL: */
Std_ReturnType NVM_ElecAlt_AltCtl__nvmini(void)
{
   ElecAlt_AltCtl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COMALT_ALTCTL: */
Std_ReturnType NVM_ComAlt_AltCtl__nvmini(void)
{
   ComAlt_AltCtl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_KNKDIAG: */
Std_ReturnType NVM_ORng_KnkDiag__nvmini(void)
{
   ORng_KnkDiag__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HHIT_NOISEADP: */
Std_ReturnType NVM_HHit_NoiseAdp__nvmini(void)
{
   HHit_NoiseAdp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LHIT_NOISEADP: */
Std_ReturnType NVM_LHit_NoiseAdp__nvmini(void)
{
   LHit_NoiseAdp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HSLD_NOISEADP: */
Std_ReturnType NVM_HSld_NoiseAdp__nvmini(void)
{
   HSld_NoiseAdp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LSLD_NOISEADP: */
Std_ReturnType NVM_LSld_NoiseAdp__nvmini(void)
{
   LSld_NoiseAdp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_SHRTWINLRN: */
Std_ReturnType NVM_ORng_ShrtWinLrn__nvmini(void)
{
   ORng_ShrtWinLrn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_LONGWINLRN: */
Std_ReturnType NVM_ORng_LongWinLrn__nvmini(void)
{
   ORng_LongWinLrn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_SHRTWINLRNMAX: */
Std_ReturnType NVM_ORng_ShrtWinLrnMax__nvmini(void)
{
   ORng_ShrtWinLrnMax__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_LONGWINLRNMAX: */
Std_ReturnType NVM_ORng_LongWinLrnMax__nvmini(void)
{
   ORng_LongWinLrnMax__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LOSTMISFROUGHNSROAD: */
Std_ReturnType NVM_LostMisfRoughnsRoad__nvmini(void)
{
   LostMisfRoughnsRoad__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMD1: */
Std_ReturnType NVM_ORngDmgCatMD1__nvmini(void)
{
   ORngDmgCatMD1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMD2: */
Std_ReturnType NVM_ORngDmgCatMD2__nvmini(void)
{
   ORngDmgCatMD2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMD3: */
Std_ReturnType NVM_ORngDmgCatMD3__nvmini(void)
{
   ORngDmgCatMD3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMD4: */
Std_ReturnType NVM_ORngDmgCatMD4__nvmini(void)
{
   ORngDmgCatMD4__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMDALL: */
Std_ReturnType NVM_ORngDmgCatMDAll__nvmini(void)
{
   ORngDmgCatMDAll__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTC1: */
Std_ReturnType NVM_ORngDmgCatDTC1__nvmini(void)
{
   ORngDmgCatDTC1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTC2: */
Std_ReturnType NVM_ORngDmgCatDTC2__nvmini(void)
{
   ORngDmgCatDTC2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTC3: */
Std_ReturnType NVM_ORngDmgCatDTC3__nvmini(void)
{
   ORngDmgCatDTC3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTC4: */
Std_ReturnType NVM_ORngDmgCatDTC4__nvmini(void)
{
   ORngDmgCatDTC4__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTCALL: */
Std_ReturnType NVM_ORngDmgCatDTCAll__nvmini(void)
{
   ORngDmgCatDTCAll__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMI1: */
Std_ReturnType NVM_ORngMisfEmi1__nvmini(void)
{
   ORngMisfEmi1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMI2: */
Std_ReturnType NVM_ORngMisfEmi2__nvmini(void)
{
   ORngMisfEmi2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMI3: */
Std_ReturnType NVM_ORngMisfEmi3__nvmini(void)
{
   ORngMisfEmi3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMI4: */
Std_ReturnType NVM_ORngMisfEmi4__nvmini(void)
{
   ORngMisfEmi4__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMIALL: */
Std_ReturnType NVM_ORngMisfEmiAll__nvmini(void)
{
   ORngMisfEmiAll__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMDGAZ1: */
Std_ReturnType NVM_ORngDmgCatMDGaz1__nvmini(void)
{
   ORngDmgCatMDGaz1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMDGAZ2: */
Std_ReturnType NVM_ORngDmgCatMDGaz2__nvmini(void)
{
   ORngDmgCatMDGaz2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMDGAZ3: */
Std_ReturnType NVM_ORngDmgCatMDGaz3__nvmini(void)
{
   ORngDmgCatMDGaz3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMDGAZ4: */
Std_ReturnType NVM_ORngDmgCatMDGaz4__nvmini(void)
{
   ORngDmgCatMDGaz4__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATMDGAZALL: */
Std_ReturnType NVM_ORngDmgCatMDGazAll__nvmini(void)
{
   ORngDmgCatMDGazAll__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZ1: */
Std_ReturnType NVM_ORngDmgCatDTCGaz1__nvmini(void)
{
   ORngDmgCatDTCGaz1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZ2: */
Std_ReturnType NVM_ORngDmgCatDTCGaz2__nvmini(void)
{
   ORngDmgCatDTCGaz2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZ3: */
Std_ReturnType NVM_ORngDmgCatDTCGaz3__nvmini(void)
{
   ORngDmgCatDTCGaz3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZ4: */
Std_ReturnType NVM_ORngDmgCatDTCGaz4__nvmini(void)
{
   ORngDmgCatDTCGaz4__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGDMGCATDTCGAZALL: */
Std_ReturnType NVM_ORngDmgCatDTCGazAll__nvmini(void)
{
   ORngDmgCatDTCGazAll__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMIGAZ1: */
Std_ReturnType NVM_ORngMisfEmiGaz1__nvmini(void)
{
   ORngMisfEmiGaz1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMIGAZ2: */
Std_ReturnType NVM_ORngMisfEmiGaz2__nvmini(void)
{
   ORngMisfEmiGaz2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMIGAZ3: */
Std_ReturnType NVM_ORngMisfEmiGaz3__nvmini(void)
{
   ORngMisfEmiGaz3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMIGAZ4: */
Std_ReturnType NVM_ORngMisfEmiGaz4__nvmini(void)
{
   ORngMisfEmiGaz4__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMISFEMIGAZALL: */
Std_ReturnType NVM_ORngMisfEmiGazAll__nvmini(void)
{
   ORngMisfEmiGazAll__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTSENR_ACCP: */
Std_ReturnType NVM_DftSenr_AccP__nvmini(void)
{
   DftSenr_AccP__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_BINHCRKALTHW: */
Std_ReturnType NVM_Oc_bInhCrkAltHw__nvmini(void)
{
   Oc_bInhCrkAltHw__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_UBATTSPC: */
Std_ReturnType NVM_Lo_uBattSpc__nvmini(void)
{
   Lo_uBattSpc__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_VMES4: */
Std_ReturnType NVM_ORng_vMes4__nvmini(void)
{
   ORng_vMes4__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_VMES4_SFTY: */
Std_ReturnType NVM_ORng_vMes4_Sfty__nvmini(void)
{
   ORng_vMes4_Sfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ALTABSENT: */
Std_ReturnType NVM_AltAbsent__nvmini(void)
{
   AltAbsent__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BUSOFF: */
Std_ReturnType NVM_BusOff__nvmini(void)
{
   BusOff__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LINBLOCKED: */
Std_ReturnType NVM_LinBlocked__nvmini(void)
{
   LinBlocked__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_CAT: */
Std_ReturnType NVM_ORng_Cat__nvmini(void)
{
   ORng_Cat__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_CATAPV: */
Std_ReturnType NVM_ORng_CatApv__nvmini(void)
{
   ORng_CatApv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ABSESPMUTE: */
Std_ReturnType NVM_AbsEspMute__nvmini(void)
{
   AbsEspMute__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BSIMUTE: */
Std_ReturnType NVM_BsiMute__nvmini(void)
{
   BsiMute__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BVAMUTE: */
Std_ReturnType NVM_BvaMute__nvmini(void)
{
   BvaMute__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ECMMUTE: */
Std_ReturnType NVM_EcmMute__nvmini(void)
{
   EcmMute__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIRAMUTE: */
Std_ReturnType NVM_DiraMute__nvmini(void)
{
   DiraMute__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CAVMUTE: */
Std_ReturnType NVM_CAVMute__nvmini(void)
{
   CAVMute__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DMTRMUTE: */
Std_ReturnType NVM_DmtrMute__nvmini(void)
{
   DmtrMute__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM F552BISP325INVLD: */
Std_ReturnType NVM_F552bisP325Invld__nvmini(void)
{
   F552bisP325Invld__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM F552P255INVLD: */
Std_ReturnType NVM_F552P255Invld__nvmini(void)
{
   F552P255Invld__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM F552P256INVLD: */
Std_ReturnType NVM_F552P256Invld__nvmini(void)
{
   F552P256Invld__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM F552P257INVLD: */
Std_ReturnType NVM_F552P257Invld__nvmini(void)
{
   F552P257Invld__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_DMPVLVCMD: */
Std_ReturnType NVM_Hi_DmpVlvCmd__nvmini(void)
{
   Hi_DmpVlvCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_DMPVLVCMD: */
Std_ReturnType NVM_Lo_DmpVlvCmd__nvmini(void)
{
   Lo_DmpVlvCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_WGCCMD: */
Std_ReturnType NVM_Hi_WgcCmd__nvmini(void)
{
   Hi_WgcCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_WGCCMD: */
Std_ReturnType NVM_Lo_WgcCmd__nvmini(void)
{
   Lo_WgcCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_CTLPMPREQ: */
Std_ReturnType NVM_Oc_CtlPmpReq__nvmini(void)
{
   Oc_CtlPmpReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_CTP1: */
Std_ReturnType NVM_Oc_CTP1__nvmini(void)
{
   Oc_CTP1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_CTP2: */
Std_ReturnType NVM_Oc_CTP2__nvmini(void)
{
   Oc_CTP2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_TRBWAPMP: */
Std_ReturnType NVM_Oc_TrbWaPmp__nvmini(void)
{
   Oc_TrbWaPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_CTLPMPREQ: */
Std_ReturnType NVM_Scg_CtlPmpReq__nvmini(void)
{
   Scg_CtlPmpReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_CTP1: */
Std_ReturnType NVM_Scg_CTP1__nvmini(void)
{
   Scg_CTP1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_CTP1: */
Std_ReturnType NVM_Scp_CTP1__nvmini(void)
{
   Scp_CTP1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_CTP2: */
Std_ReturnType NVM_Scg_CTP2__nvmini(void)
{
   Scg_CTP2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_CTP2: */
Std_ReturnType NVM_Scp_CTP2__nvmini(void)
{
   Scp_CTP2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_TRBWAPMP: */
Std_ReturnType NVM_Scg_TrbWaPmp__nvmini(void)
{
   Scg_TrbWaPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_CTLPMPREQ: */
Std_ReturnType NVM_Scp_CtlPmpReq__nvmini(void)
{
   Scp_CtlPmpReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_TRBWAPMP: */
Std_ReturnType NVM_Scp_TrbWaPmp__nvmini(void)
{
   Scp_TrbWaPmp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_BLOWBY1: */
Std_ReturnType NVM_Scg_BlowBy1__nvmini(void)
{
   Scg_BlowBy1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_BLOWBY2: */
Std_ReturnType NVM_Scg_BlowBy2__nvmini(void)
{
   Scg_BlowBy2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_BLOWBY1: */
Std_ReturnType NVM_Scp_BlowBy1__nvmini(void)
{
   Scp_BlowBy1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_BLOWBY2: */
Std_ReturnType NVM_Scp_BlowBy2__nvmini(void)
{
   Scp_BlowBy2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_BLOWBY1: */
Std_ReturnType NVM_Oc_BlowBy1__nvmini(void)
{
   Oc_BlowBy1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_BLOWBY2: */
Std_ReturnType NVM_Oc_BlowBy2__nvmini(void)
{
   Oc_BlowBy2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGHITOILESTIM: */
Std_ReturnType NVM_ORngHiTOilEstim__nvmini(void)
{
   ORngHiTOilEstim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PWRLMRK: */
Std_ReturnType NVM_PwrlMrk__nvmini(void)
{
   PwrlMrk__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_VSSNWACVREQ: */
Std_ReturnType NVM_Scp_VSSNwAcvReq__nvmini(void)
{
   Scp_VSSNwAcvReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_VSSNWACVREQ: */
Std_ReturnType NVM_Scg_VSSNwAcvReq__nvmini(void)
{
   Scg_VSSNwAcvReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_UBATTMES: */
Std_ReturnType NVM_Hi_uBattMes__nvmini(void)
{
   Hi_uBattMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LO_UBATTMES: */
Std_ReturnType NVM_Lo_uBattMes__nvmini(void)
{
   Lo_uBattMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_VMES1: */
Std_ReturnType NVM_ORng_vMes1__nvmini(void)
{
   ORng_vMes1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_VMES1_SFTY: */
Std_ReturnType NVM_ORng_vMes1_Sfty__nvmini(void)
{
   ORng_vMes1_Sfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_VMES2: */
Std_ReturnType NVM_ORng_vMes2__nvmini(void)
{
   ORng_vMes2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_VMES2_SFTY: */
Std_ReturnType NVM_ORng_vMes2_Sfty__nvmini(void)
{
   ORng_vMes2_Sfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_VMES3: */
Std_ReturnType NVM_ORng_vMes3__nvmini(void)
{
   ORng_vMes3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_VMES3_SFTY: */
Std_ReturnType NVM_ORng_vMes3_Sfty__nvmini(void)
{
   ORng_vMes3_Sfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INV_CALID: */
Std_ReturnType NVM_Inv_CalId__nvmini(void)
{
   Inv_CalId__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCK_MAINRLY: */
Std_ReturnType NVM_Stuck_MainRly__nvmini(void)
{
   Stuck_MainRly__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCK_PWRRLY: */
Std_ReturnType NVM_Stuck_PwrRly__nvmini(void)
{
   Stuck_PwrRly__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCP_PWRRLY: */
Std_ReturnType NVM_Scp_PwrRly__nvmini(void)
{
   Scp_PwrRly__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OC_PWRRLY: */
Std_ReturnType NVM_Oc_PwrRly__nvmini(void)
{
   Oc_PwrRly__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCG_PWRRLY: */
Std_ReturnType NVM_Scg_PwrRly__nvmini(void)
{
   Scg_PwrRly__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFT_INFO_CRASH: */
Std_ReturnType NVM_Dft_Info_Crash__nvmini(void)
{
   Dft_Info_Crash__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPAREFFEGRVLVLIM: */
Std_ReturnType NVM_AFA_AdpArEffEGRVlvLim__nvmini(void)
{
   AFA_AdpArEffEGRVlvLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPAREFFTHROFS1LIM: */
Std_ReturnType NVM_AFA_AdpArEffThrOfs1Lim__nvmini(void)
{
   AFA_AdpArEffThrOfs1Lim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPAREFFTHROFS2LIM: */
Std_ReturnType NVM_AFA_AdpArEffThrOfs2Lim__nvmini(void)
{
   AFA_AdpArEffThrOfs2Lim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPAREFFTHROFS3LIM: */
Std_ReturnType NVM_AFA_AdpArEffThrOfs3Lim__nvmini(void)
{
   AFA_AdpArEffThrOfs3Lim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPAREFFTHROFSLIM: */
Std_ReturnType NVM_AFA_AdpArEffThrOfsLim__nvmini(void)
{
   AFA_AdpArEffThrOfsLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPCLSEXOFSLIM: */
Std_ReturnType NVM_AFA_AdpClsExOfsLim__nvmini(void)
{
   AFA_AdpClsExOfsLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPINJOFSLIM: */
Std_ReturnType NVM_AFA_AdpInjOfsLim__nvmini(void)
{
   AFA_AdpInjOfsLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPIVSINJCONLIM: */
Std_ReturnType NVM_AFA_AdpIvsInjConLim__nvmini(void)
{
   AFA_AdpIvsInjConLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPOPINOFSLIM: */
Std_ReturnType NVM_AFA_AdpOpInOfsLim__nvmini(void)
{
   AFA_AdpOpInOfsLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM AFA_ADPSLOPINJCONLIM: */
Std_ReturnType NVM_AFA_AdpSlopInjConLim__nvmini(void)
{
   AFA_AdpSlopInjConLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ANTIBOIL: */
Std_ReturnType NVM_AntiBoil__nvmini(void)
{
   AntiBoil__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM BLT: */
Std_ReturnType NVM_Blt__nvmini(void)
{
   Blt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CAT: */
Std_ReturnType NVM_Cat__nvmini(void)
{
   Cat__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CATAPV: */
Std_ReturnType NVM_CatApv__nvmini(void)
{
   CatApv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CKSIG: */
Std_ReturnType NVM_CkSig__nvmini(void)
{
   CkSig__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COSYSDFCT: */
Std_ReturnType NVM_CoSysDfct__nvmini(void)
{
   CoSysDfct__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CORLOSS: */
Std_ReturnType NVM_CorLoss__nvmini(void)
{
   CorLoss__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CORSPCUR: */
Std_ReturnType NVM_CorSpCur__nvmini(void)
{
   CorSpCur__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CUTREQ: */
Std_ReturnType NVM_CutReq__nvmini(void)
{
   CutReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FSFBLOCKCLS: */
Std_ReturnType NVM_FSFBlockCls__nvmini(void)
{
   FSFBlockCls__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM FSFBLOCKOP: */
Std_ReturnType NVM_FSFBlockOp__nvmini(void)
{
   FSFBlockOp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IRVENGSTOP: */
Std_ReturnType NVM_IrvEngStop__nvmini(void)
{
   IrvEngStop__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LGENGRSTRTINH: */
Std_ReturnType NVM_LgEngRStrtInh__nvmini(void)
{
   LgEngRStrtInh__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MAINWKUDISRD: */
Std_ReturnType NVM_MainWkuDisrd__nvmini(void)
{
   MainWkuDisrd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MAINWKUINCST: */
Std_ReturnType NVM_MainWkuIncst__nvmini(void)
{
   MainWkuIncst__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGCUTOFFREQ: */
Std_ReturnType NVM_ORngCutOffReq__nvmini(void)
{
   ORngCutOffReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGGCCLU: */
Std_ReturnType NVM_ORngGcClu__nvmini(void)
{
   ORngGcClu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGGCMINCLU: */
Std_ReturnType NVM_ORngGcMinClu__nvmini(void)
{
   ORngGcMinClu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGGCNEUT: */
Std_ReturnType NVM_ORngGcNeut__nvmini(void)
{
   ORngGcNeut__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGGEARENACLU: */
Std_ReturnType NVM_ORngGearEnaClu__nvmini(void)
{
   ORngGearEnaClu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGGEARMINCLU: */
Std_ReturnType NVM_ORngGearMinClu__nvmini(void)
{
   ORngGearMinClu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGGEARNEUT: */
Std_ReturnType NVM_ORngGearNeut__nvmini(void)
{
   ORngGearNeut__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGHIDRAGRED: */
Std_ReturnType NVM_ORngHiDragRed__nvmini(void)
{
   ORngHiDragRed__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGHINEUT: */
Std_ReturnType NVM_ORngHiNeut__nvmini(void)
{
   ORngHiNeut__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGLODRAGRED: */
Std_ReturnType NVM_ORngLoDragRed__nvmini(void)
{
   ORngLoDragRed__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGLONEUT: */
Std_ReturnType NVM_ORngLoNeut__nvmini(void)
{
   ORngLoNeut__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGMPLREQ: */
Std_ReturnType NVM_ORngMplReq__nvmini(void)
{
   ORngMplReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSTOPREQ: */
Std_ReturnType NVM_ORngStopReq__nvmini(void)
{
   ORngStopReq__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OBSADP: */
Std_ReturnType NVM_ObsAdp__nvmini(void)
{
   ObsAdp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PROTADP: */
Std_ReturnType NVM_ProtAdp__nvmini(void)
{
   ProtAdp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM RCDLINESCG: */
Std_ReturnType NVM_RCDLineScg__nvmini(void)
{
   RCDLineScg__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM RATCONVTRACLC: */
Std_ReturnType NVM_RatConvTraClc__nvmini(void)
{
   RatConvTraClc__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SFTYORNGAMT: */
Std_ReturnType NVM_SftyORngAMT__nvmini(void)
{
   SftyORngAMT__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SFTYORNGAT: */
Std_ReturnType NVM_SftyORngAT__nvmini(void)
{
   SftyORngAT__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SPDVEHCLC: */
Std_ReturnType NVM_SpdVehClc__nvmini(void)
{
   SpdVehClc__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STAACVTHD1: */
Std_ReturnType NVM_StaAcvThd1__nvmini(void)
{
   StaAcvThd1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STAACVTHD2: */
Std_ReturnType NVM_StaAcvThd2__nvmini(void)
{
   StaAcvThd2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STACMD: */
Std_ReturnType NVM_StaCmd__nvmini(void)
{
   StaCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STACMDINFO: */
Std_ReturnType NVM_StaCmdInfo__nvmini(void)
{
   StaCmdInfo__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STAELCMD: */
Std_ReturnType NVM_StaElCmd__nvmini(void)
{
   StaElCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKMEC: */
Std_ReturnType NVM_StuckMec__nvmini(void)
{
   StuckMec__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TCOBLOCK: */
Std_ReturnType NVM_TCoBlock__nvmini(void)
{
   TCoBlock__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TCOOVERESTIM: */
Std_ReturnType NVM_TCoOverEstim__nvmini(void)
{
   TCoOverEstim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TCOSLOWRISE: */
Std_ReturnType NVM_TCoSlowRise__nvmini(void)
{
   TCoSlowRise__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TCOUNDESTIM: */
Std_ReturnType NVM_TCoUndEstim__nvmini(void)
{
   TCoUndEstim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TCOWARN: */
Std_ReturnType NVM_TCoWarn__nvmini(void)
{
   TCoWarn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM THERMOSTUCKCLS: */
Std_ReturnType NVM_ThermoStuckCls__nvmini(void)
{
   ThermoStuckCls__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM THERMOSTUCKOP: */
Std_ReturnType NVM_ThermoStuckOp__nvmini(void)
{
   ThermoStuckOp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TQALT: */
Std_ReturnType NVM_TqAlt__nvmini(void)
{
   TqAlt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM VSLIM: */
Std_ReturnType NVM_VSLim__nvmini(void)
{
   VSLim__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM VSLIMBODY: */
Std_ReturnType NVM_VSLimBody__nvmini(void)
{
   VSLimBody__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM VSMAX: */
Std_ReturnType NVM_VSMax__nvmini(void)
{
   VSMax__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM VSMAXP: */
Std_ReturnType NVM_VSMaxp__nvmini(void)
{
   VSMaxp__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM VSREG: */
Std_ReturnType NVM_VSReg__nvmini(void)
{
   VSReg__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM VSREGBODY: */
Std_ReturnType NVM_VSRegBody__nvmini(void)
{
   VSRegBody__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM VSREGVEH: */
Std_ReturnType NVM_VSRegVeh__nvmini(void)
{
   VSRegVeh__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IBATTMAXCKG: */
Std_ReturnType NVM_iBattMaxCkg__nvmini(void)
{
   iBattMaxCkg__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IBATTMES: */
Std_ReturnType NVM_iBattMes__nvmini(void)
{
   iBattMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM RBATTSOC: */
Std_ReturnType NVM_rBattSoC__nvmini(void)
{
   rBattSoC__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM RESBATTIT: */
Std_ReturnType NVM_resBattIt__nvmini(void)
{
   resBattIt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TBATTMES: */
Std_ReturnType NVM_tBattMes__nvmini(void)
{
   tBattMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TQALTRV: */
Std_ReturnType NVM_tqAltRv__nvmini(void)
{
   tqAltRv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM UBATTMES: */
Std_ReturnType NVM_uBattMes__nvmini(void)
{
   uBattMes__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM UBATTMINCKG: */
Std_ReturnType NVM_uBattMinCkg__nvmini(void)
{
   uBattMinCkg__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM UBATTOC: */
Std_ReturnType NVM_uBattOc__nvmini(void)
{
   uBattOc__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM UBATTRSTRT: */
Std_ReturnType NVM_uBattRstrt__nvmini(void)
{
   uBattRstrt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM UBATTSTRT: */
Std_ReturnType NVM_uBattStrt__nvmini(void)
{
   uBattStrt__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM NOANSWCTLUNIT: */
Std_ReturnType NVM_NoAnswCtlUnit__nvmini(void)
{
   NoAnswCtlUnit__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM WRGANSWCTLUNIT: */
Std_ReturnType NVM_WrgAnswCtlUnit__nvmini(void)
{
   WrgAnswCtlUnit__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IMMOCODNOTREAD: */
Std_ReturnType NVM_ImmoCodNotRead__nvmini(void)
{
   ImmoCodNotRead__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM NOGAP_CKSTS: */
Std_ReturnType NVM_NoGap_CkSts__nvmini(void)
{
   NoGap_CkSts__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TOOTHCOH_CKSTS: */
Std_ReturnType NVM_ToothCoh_CkSts__nvmini(void)
{
   ToothCoh_CkSts__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HITOOTHCOH_CKSTS: */
Std_ReturnType NVM_HiToothCoh_CkSts__nvmini(void)
{
   HiToothCoh_CkSts__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IUPRSYNT1: */
Std_ReturnType NVM_IUPRSynt1__nvmini(void)
{
   IUPRSynt1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IUPRSYNT2: */
Std_ReturnType NVM_IUPRSynt2__nvmini(void)
{
   IUPRSynt2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IUPRSYNT3: */
Std_ReturnType NVM_IUPRSynt3__nvmini(void)
{
   IUPRSynt3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SFTYCHKPT_PFCMNG: */
Std_ReturnType NVM_SftyChkPt_PfcMng__nvmini(void)
{
   SftyChkPt_PfcMng__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IRVSTT: */
Std_ReturnType NVM_IrvSTT__nvmini(void)
{
   IrvSTT__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM RVLIH: */
Std_ReturnType NVM_RvLih__nvmini(void)
{
   RvLih__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IRVVSCTL: */
Std_ReturnType NVM_IrvVSCtl__nvmini(void)
{
   IrvVSCtl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INHCHKINITSFTY: */
Std_ReturnType NVM_InhChkInitSfty__nvmini(void)
{
   InhChkInitSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DRVTRA: */
Std_ReturnType NVM_DrvTra__nvmini(void)
{
   DrvTra__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INHENGSTOPSTT: */
Std_ReturnType NVM_InhEngStopSTT__nvmini(void)
{
   InhEngStopSTT__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IRVECU: */
Std_ReturnType NVM_IrvECU__nvmini(void)
{
   IrvECU__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IRVEM: */
Std_ReturnType NVM_IrvEM__nvmini(void)
{
   IrvEM__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COMSPI_CPU: */
Std_ReturnType NVM_ComSpi_Cpu__nvmini(void)
{
   ComSpi_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COMTOUT_CPU: */
Std_ReturnType NVM_ComTout_Cpu__nvmini(void)
{
   ComTout_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SYNCMON_CPU: */
Std_ReturnType NVM_SyncMon_Cpu__nvmini(void)
{
   SyncMon_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ACCP_CPU: */
Std_ReturnType NVM_AccP_Cpu__nvmini(void)
{
   AccP_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM THR_CPU: */
Std_ReturnType NVM_Thr_Cpu__nvmini(void)
{
   Thr_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CLK_CPU: */
Std_ReturnType NVM_Clk_Cpu__nvmini(void)
{
   Clk_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ALGO_CPU: */
Std_ReturnType NVM_Algo_Cpu__nvmini(void)
{
   Algo_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COMSPI_CPUSFTY: */
Std_ReturnType NVM_ComSpi_CpuSfty__nvmini(void)
{
   ComSpi_CpuSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COMTOUT_CPUSFTY: */
Std_ReturnType NVM_ComTout_CpuSfty__nvmini(void)
{
   ComTout_CpuSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SYNCMON_CPUSFTY: */
Std_ReturnType NVM_SyncMon_CpuSfty__nvmini(void)
{
   SyncMon_CpuSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CLK_CPUSFTY: */
Std_ReturnType NVM_Clk_CpuSfty__nvmini(void)
{
   Clk_CpuSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ALGO_CPUSFTY: */
Std_ReturnType NVM_Algo_CpuSfty__nvmini(void)
{
   Algo_CpuSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CKSROM_CPUSFTY: */
Std_ReturnType NVM_CksRom_CpuSfty__nvmini(void)
{
   CksRom_CpuSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DEGMOD_CPUSFTY: */
Std_ReturnType NVM_DegMod_CpuSfty__nvmini(void)
{
   DegMod_CpuSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_AENG: */
Std_ReturnType NVM_Hi_aEng__nvmini(void)
{
   Hi_aEng__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HI_NENG: */
Std_ReturnType NVM_Hi_nEng__nvmini(void)
{
   Hi_nEng__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DISTSIG: */
Std_ReturnType NVM_DistSig__nvmini(void)
{
   DistSig__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_INCM: */
Std_ReturnType NVM_Coh_InCm__nvmini(void)
{
   Coh_InCm__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_EXCM: */
Std_ReturnType NVM_Coh_ExCm__nvmini(void)
{
   Coh_ExCm__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ENGSPDCOHCK: */
Std_ReturnType NVM_EngSpdCohCk__nvmini(void)
{
   EngSpdCohCk__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ENGSPDCOHINCM: */
Std_ReturnType NVM_EngSpdCohInCm__nvmini(void)
{
   EngSpdCohInCm__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ENGSPDCOHEXCM: */
Std_ReturnType NVM_EngSpdCohExCm__nvmini(void)
{
   EngSpdCohExCm__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM NOSIGCK: */
Std_ReturnType NVM_NoSigCk__nvmini(void)
{
   NoSigCk__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SIGLOSSCK: */
Std_ReturnType NVM_SigLossCk__nvmini(void)
{
   SigLossCk__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM NOSIGINCM: */
Std_ReturnType NVM_NoSigInCm__nvmini(void)
{
   NoSigInCm__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SIGLOSSINCM: */
Std_ReturnType NVM_SigLossInCm__nvmini(void)
{
   SigLossInCm__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM NOSIGEXCM: */
Std_ReturnType NVM_NoSigExCm__nvmini(void)
{
   NoSigExCm__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SIGLOSSEXCM: */
Std_ReturnType NVM_SigLossExCm__nvmini(void)
{
   SigLossExCm__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_TIENGSTOP: */
Std_ReturnType NVM_ORng_tiEngStop__nvmini(void)
{
   ORng_tiEngStop__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_TIENGSTOP: */
Std_ReturnType NVM_Coh_tiEngStop__nvmini(void)
{
   Coh_tiEngStop__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INV_VARCOD: */
Std_ReturnType NVM_Inv_VarCod__nvmini(void)
{
   Inv_VarCod__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSERVO: */
Std_ReturnType NVM_ORngServo__nvmini(void)
{
   ORngServo__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSERVODIFPOS: */
Std_ReturnType NVM_ORngServoDifPos__nvmini(void)
{
   ORngServoDifPos__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSERVODIFNEG: */
Std_ReturnType NVM_ORngServoDifNeg__nvmini(void)
{
   ORngServoDifNeg__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ENDSTOPREQ1: */
Std_ReturnType NVM_EndStopReq1__nvmini(void)
{
   EndStopReq1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ENDSTOPREQ2: */
Std_ReturnType NVM_EndStopReq2__nvmini(void)
{
   EndStopReq2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CLSIDLCTL: */
Std_ReturnType NVM_ClsIdlCtl__nvmini(void)
{
   ClsIdlCtl__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LIHREQ1: */
Std_ReturnType NVM_LihReq1__nvmini(void)
{
   LihReq1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LIHREQ2: */
Std_ReturnType NVM_LihReq2__nvmini(void)
{
   LihReq2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COHPOSNSNSR: */
Std_ReturnType NVM_CohPosnSnsr__nvmini(void)
{
   CohPosnSnsr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCPPOSNSNSR1: */
Std_ReturnType NVM_ScpPosnSnsr1__nvmini(void)
{
   ScpPosnSnsr1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCGPOSNSNSR1: */
Std_ReturnType NVM_ScgPosnSnsr1__nvmini(void)
{
   ScgPosnSnsr1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCPPOSNSNSR2: */
Std_ReturnType NVM_ScpPosnSnsr2__nvmini(void)
{
   ScpPosnSnsr2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SCGPOSNSNSR2: */
Std_ReturnType NVM_ScgPosnSnsr2__nvmini(void)
{
   ScgPosnSnsr2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTSENR_THR: */
Std_ReturnType NVM_DftSenr_Thr__nvmini(void)
{
   DftSenr_Thr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OVLD_THRCMD: */
Std_ReturnType NVM_Ovld_ThrCmd__nvmini(void)
{
   Ovld_ThrCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CPT_THRCMD: */
Std_ReturnType NVM_Cpt_ThrCmd__nvmini(void)
{
   Cpt_ThrCmd__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM READPININHTHR_CPU: */
Std_ReturnType NVM_ReadPinInhThr_Cpu__nvmini(void)
{
   ReadPinInhThr_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM INHTHR_CPUSFTY: */
Std_ReturnType NVM_InhThr_CpuSfty__nvmini(void)
{
   InhThr_CpuSfty__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OVLDTHERMOTHR: */
Std_ReturnType NVM_OvldThermoThr__nvmini(void)
{
   OvldThermoThr__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSFTYDFTLIH: */
Std_ReturnType NVM_ORngSftyDftLih__nvmini(void)
{
   ORngSftyDftLih__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELDIAGINHPIN0_CPU: */
Std_ReturnType NVM_ElDiagInhPin0_Cpu__nvmini(void)
{
   ElDiagInhPin0_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ELDIAGINHPIN1_CPU: */
Std_ReturnType NVM_ElDiagInhPin1_Cpu__nvmini(void)
{
   ElDiagInhPin1_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MCPRAMTEST_CPU: */
Std_ReturnType NVM_McpRAMTest_Cpu__nvmini(void)
{
   McpRAMTest_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MCPFLASHCKS_CPU: */
Std_ReturnType NVM_McpFlashCks_Cpu__nvmini(void)
{
   McpFlashCks_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MCWCKSCALC_CPU: */
Std_ReturnType NVM_McwCksCalc_Cpu__nvmini(void)
{
   McwCksCalc_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MCWINITSFTYRSLT_CPU: */
Std_ReturnType NVM_McwInitSftyRslt_Cpu__nvmini(void)
{
   McwInitSftyRslt_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MCWFCTTEST_CPU: */
Std_ReturnType NVM_McwFctTest_Cpu__nvmini(void)
{
   McwFctTest_Cpu__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CLUDMGAFTS: */
Std_ReturnType NVM_CluDmgAfts__nvmini(void)
{
   CluDmgAfts__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM COH_SPDVEH: */
Std_ReturnType NVM_Coh_spdVeh__nvmini(void)
{
   Coh_spdVeh__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNG_SPDVEH: */
Std_ReturnType NVM_ORng_spdVeh__nvmini(void)
{
   ORng_spdVeh__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SERVOERRVLVACTEX: */
Std_ReturnType NVM_ServoErrVlvActEx__nvmini(void)
{
   ServoErrVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IMAXVLVACTEX: */
Std_ReturnType NVM_IMaxVlvActEx__nvmini(void)
{
   IMaxVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSPDVLVACTEX: */
Std_ReturnType NVM_ORngSpdVlvActEx__nvmini(void)
{
   ORngSpdVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSHIFTVLVACTEX: */
Std_ReturnType NVM_ORngShiftVlvActEx__nvmini(void)
{
   ORngShiftVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSTOOTHVLVACTEX: */
Std_ReturnType NVM_MissToothVlvActEx__nvmini(void)
{
   MissToothVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TDCDIAGVLVACTEX: */
Std_ReturnType NVM_TDCDiagVlvActEx__nvmini(void)
{
   TDCDiagVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CLNERRVLVACTEX: */
Std_ReturnType NVM_ClnErrVlvActEx__nvmini(void)
{
   ClnErrVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LRNENDSTOPVLVACTEX: */
Std_ReturnType NVM_LrnEndStopVlvActEx__nvmini(void)
{
   LrnEndStopVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ENDSTOPOLDVLVACTEX: */
Std_ReturnType NVM_EndStopOldVlvActEx__nvmini(void)
{
   EndStopOldVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LRNFAILIMVLVACTEX: */
Std_ReturnType NVM_LrnFaiLimVlvActEx__nvmini(void)
{
   LrnFaiLimVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OLDLRNVLVACTEX: */
Std_ReturnType NVM_OldLrnVlvActEx__nvmini(void)
{
   OldLrnVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LOVLVACTEXDRV: */
Std_ReturnType NVM_LoVlvActExDrv__nvmini(void)
{
   LoVlvActExDrv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HIVLVACTEXDRV: */
Std_ReturnType NVM_HiVlvActExDrv__nvmini(void)
{
   HiVlvActExDrv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTCVLVACTEX: */
Std_ReturnType NVM_DftCVlvActEx__nvmini(void)
{
   DftCVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGCVLVACTEX: */
Std_ReturnType NVM_ORngCVlvActEx__nvmini(void)
{
   ORngCVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CMDCVLVACTEX: */
Std_ReturnType NVM_CmdCVlvActEx__nvmini(void)
{
   CmdCVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SLOWC1VLVACTEX: */
Std_ReturnType NVM_SlowC1VlvActEx__nvmini(void)
{
   SlowC1VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SLOWC2VLVACTEX: */
Std_ReturnType NVM_SlowC2VlvActEx__nvmini(void)
{
   SlowC2VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTHVLVACTEX: */
Std_ReturnType NVM_DftHVlvActEx__nvmini(void)
{
   DftHVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGHVLVACTEX: */
Std_ReturnType NVM_ORngHVlvActEx__nvmini(void)
{
   ORngHVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CMDHVLVACTEX: */
Std_ReturnType NVM_CmdHVlvActEx__nvmini(void)
{
   CmdHVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKHVLVACTEX: */
Std_ReturnType NVM_StuckHVlvActEx__nvmini(void)
{
   StuckHVlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SLOWH1VLVACTEX: */
Std_ReturnType NVM_SlowH1VlvActEx__nvmini(void)
{
   SlowH1VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKH1VLVACTEX: */
Std_ReturnType NVM_StuckH1VlvActEx__nvmini(void)
{
   StuckH1VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SLOWH2VLVACTEX: */
Std_ReturnType NVM_SlowH2VlvActEx__nvmini(void)
{
   SlowH2VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKH2VLVACTEX: */
Std_ReturnType NVM_StuckH2VlvActEx__nvmini(void)
{
   StuckH2VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKH3VLVACTEX: */
Std_ReturnType NVM_StuckH3VlvActEx__nvmini(void)
{
   StuckH3VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIFPOS1VLVACTEX: */
Std_ReturnType NVM_DifPos1VlvActEx__nvmini(void)
{
   DifPos1VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIFPOS2VLVACTEX: */
Std_ReturnType NVM_DifPos2VlvActEx__nvmini(void)
{
   DifPos2VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIFNEG1VLVACTEX: */
Std_ReturnType NVM_DifNeg1VlvActEx__nvmini(void)
{
   DifNeg1VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIFNEG2VLVACTEX: */
Std_ReturnType NVM_DifNeg2VlvActEx__nvmini(void)
{
   DifNeg2VlvActEx__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SERVOERRVLVACTIN: */
Std_ReturnType NVM_ServoErrVlvActIn__nvmini(void)
{
   ServoErrVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM IMAXVLVACTIN: */
Std_ReturnType NVM_IMaxVlvActIn__nvmini(void)
{
   IMaxVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSPDVLVACTIN: */
Std_ReturnType NVM_ORngSpdVlvActIn__nvmini(void)
{
   ORngSpdVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGSHIFTVLVACTIN: */
Std_ReturnType NVM_ORngShiftVlvActIn__nvmini(void)
{
   ORngShiftVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MISSTOOTHVLVACTIN: */
Std_ReturnType NVM_MissToothVlvActIn__nvmini(void)
{
   MissToothVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TDCDIAGVLVACTIN: */
Std_ReturnType NVM_TDCDiagVlvActIn__nvmini(void)
{
   TDCDiagVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CLNERRVLVACTIN: */
Std_ReturnType NVM_ClnErrVlvActIn__nvmini(void)
{
   ClnErrVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LRNENDSTOPVLVACTIN: */
Std_ReturnType NVM_LrnEndStopVlvActIn__nvmini(void)
{
   LrnEndStopVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ENDSTOPOLDVLVACTIN: */
Std_ReturnType NVM_EndStopOldVlvActIn__nvmini(void)
{
   EndStopOldVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LRNFAILIMVLVACTIN: */
Std_ReturnType NVM_LrnFaiLimVlvActIn__nvmini(void)
{
   LrnFaiLimVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OLDLRNVLVACTIN: */
Std_ReturnType NVM_OldLrnVlvActIn__nvmini(void)
{
   OldLrnVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM LOVLVACTINDRV: */
Std_ReturnType NVM_LoVlvActInDrv__nvmini(void)
{
   LoVlvActInDrv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM HIVLVACTINDRV: */
Std_ReturnType NVM_HiVlvActInDrv__nvmini(void)
{
   HiVlvActInDrv__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTCVLVACTIN: */
Std_ReturnType NVM_DftCVlvActIn__nvmini(void)
{
   DftCVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGCVLVACTIN: */
Std_ReturnType NVM_ORngCVlvActIn__nvmini(void)
{
   ORngCVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CMDCVLVACTIN: */
Std_ReturnType NVM_CmdCVlvActIn__nvmini(void)
{
   CmdCVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SLOWC1VLVACTIN: */
Std_ReturnType NVM_SlowC1VlvActIn__nvmini(void)
{
   SlowC1VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SLOWC2VLVACTIN: */
Std_ReturnType NVM_SlowC2VlvActIn__nvmini(void)
{
   SlowC2VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DFTHVLVACTIN: */
Std_ReturnType NVM_DftHVlvActIn__nvmini(void)
{
   DftHVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ORNGHVLVACTIN: */
Std_ReturnType NVM_ORngHVlvActIn__nvmini(void)
{
   ORngHVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM CMDHVLVACTIN: */
Std_ReturnType NVM_CmdHVlvActIn__nvmini(void)
{
   CmdHVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKHVLVACTIN: */
Std_ReturnType NVM_StuckHVlvActIn__nvmini(void)
{
   StuckHVlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SLOWH1VLVACTIN: */
Std_ReturnType NVM_SlowH1VlvActIn__nvmini(void)
{
   SlowH1VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKH1VLVACTIN: */
Std_ReturnType NVM_StuckH1VlvActIn__nvmini(void)
{
   StuckH1VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SLOWH2VLVACTIN: */
Std_ReturnType NVM_SlowH2VlvActIn__nvmini(void)
{
   SlowH2VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKH2VLVACTIN: */
Std_ReturnType NVM_StuckH2VlvActIn__nvmini(void)
{
   StuckH2VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STUCKH3VLVACTIN: */
Std_ReturnType NVM_StuckH3VlvActIn__nvmini(void)
{
   StuckH3VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIFPOS1VLVACTIN: */
Std_ReturnType NVM_DifPos1VlvActIn__nvmini(void)
{
   DifPos1VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIFPOS2VLVACTIN: */
Std_ReturnType NVM_DifPos2VlvActIn__nvmini(void)
{
   DifPos2VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIFNEG1VLVACTIN: */
Std_ReturnType NVM_DifNeg1VlvActIn__nvmini(void)
{
   DifNeg1VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM DIFNEG2VLVACTIN: */
Std_ReturnType NVM_DifNeg2VlvActIn__nvmini(void)
{
   DifNeg2VlvActIn__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM ZZEND_BIDON: */
Std_ReturnType NVM_ZzEnd_Bidon__nvmini(void)
{
   ZzEnd_Bidon__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MPM_NVRAM_INT16_CONST: */
Std_ReturnType NVM_MPM_NVRAM_int16_const__nvmini(void)
{
   MPM_NVRAM_int16_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MPM_NVRAM_INT32_CONST: */
Std_ReturnType NVM_MPM_NVRAM_int32_const__nvmini(void)
{
   MPM_NVRAM_int32_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MPM_NVRAM_INT32_CONST_1: */
Std_ReturnType NVM_MPM_NVRAM_int32_const_1__nvmini(void)
{
   MPM_NVRAM_int32_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM MPM_NVRAM_INT32_CONST_2: */
Std_ReturnType NVM_MPM_NVRAM_int32_const_2__nvmini(void)
{
   MPM_NVRAM_int32_const_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM OBDSRV06: */
Std_ReturnType NVM_OBDSRV06_NVMSRV_vidInit(void)
{
   OBDSRV06_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT16_CONST_1: */
Std_ReturnType NVM_PRODELEM_NVRAM_int16_const_1__nvmini(void)
{
   PRODELEM_NVRAM_int16_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT16_CONST_2: */
Std_ReturnType NVM_PRODELEM_NVRAM_int16_const_2__nvmini(void)
{
   PRODELEM_NVRAM_int16_const_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT32_CONST_1: */
Std_ReturnType NVM_PRODELEM_NVRAM_int32_const_1__nvmini(void)
{
   PRODELEM_NVRAM_int32_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT32_CONST_2: */
Std_ReturnType NVM_PRODELEM_NVRAM_int32_const_2__nvmini(void)
{
   PRODELEM_NVRAM_int32_const_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT32_CONST_3: */
Std_ReturnType NVM_PRODELEM_NVRAM_int32_const_3__nvmini(void)
{
   PRODELEM_NVRAM_int32_const_3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT8_CONST_1: */
Std_ReturnType NVM_PRODELEM_NVRAM_int8_const_1__nvmini(void)
{
   PRODELEM_NVRAM_int8_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_INT8_CONST_2: */
Std_ReturnType NVM_PRODELEM_NVRAM_int8_const_2__nvmini(void)
{
   PRODELEM_NVRAM_int8_const_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_BOOLEAN_CONST_1: */
Std_ReturnType NVM_PRODELEM_NVRAM_boolean_const_1__nvmini(void)
{
   PRODELEM_NVRAM_boolean_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELEM_NVRAM_BOOLEAN_CONST_2: */
Std_ReturnType NVM_PRODELEM_NVRAM_boolean_const_2__nvmini(void)
{
   PRODELEM_NVRAM_boolean_const_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PRODELENG_NVRAM_INT32_CONST_1: */
Std_ReturnType NVM_PRODELENG_NVRAM_int32_const_1__nvmini(void)
{
   PRODELENG_NVRAM_int32_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SPYEMSTT: */
Std_ReturnType NVM_SPYEMSTT_NVMSRV_vidInit(void)
{
   SPYEMSTT_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM SPYSTT: */
Std_ReturnType NVM_SPYSTT_NVMSRV_vidInit(void)
{
   SPYSTT_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STOPSTRTEM_NVRAM_INT16_CONST_3: */
Std_ReturnType NVM_STOPSTRTEM_NVRAM_int16_const_3__nvmini(void)
{
   STOPSTRTEM_NVRAM_int16_const_3__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STOPSTRTEM_NVRAM_INT32_CONST_1: */
Std_ReturnType NVM_STOPSTRTEM_NVRAM_int32_const_1__nvmini(void)
{
   STOPSTRTEM_NVRAM_int32_const_1__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM STOPSTRTEM_NVRAM_INT32_CONST_2: */
Std_ReturnType NVM_STOPSTRTEM_NVRAM_int32_const_2__nvmini(void)
{
   STOPSTRTEM_NVRAM_int32_const_2__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM THMGT_NVRAM_INT8_CONST: */
Std_ReturnType NVM_THMGT_NVRAM_int8_const__nvmini(void)
{
   THMGT_NVRAM_int8_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM THMGT_NVRAM_BOOLEAN_CONST: */
Std_ReturnType NVM_THMGT_NVRAM_boolean_const__nvmini(void)
{
   THMGT_NVRAM_boolean_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM THRSPT_NVRAM_INT32_CONST: */
Std_ReturnType NVM_ThrSpT_NVRAM_int32_const__nvmini(void)
{
   ThrSpT_NVRAM_int32_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM PAP_MOT: */
Std_ReturnType NVM_pap_mot_NVMSRV_vidInit(void)
{
   pap_mot_NVMSRV_vidInit();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TPM_NVRAM_INT16_CONST: */
Std_ReturnType NVM_TPM_NVRAM_int16_const__nvmini(void)
{
   TPM_NVRAM_int16_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TQADPCMP_NVRAM_INT16_CONST: */
Std_ReturnType NVM_TQADPCMP_NVRAM_int16_const__nvmini(void)
{
   TQADPCMP_NVRAM_int16_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TQADPCMP_NVRAM_INT32_CONST: */
Std_ReturnType NVM_TQADPCMP_NVRAM_int32_const__nvmini(void)
{
   TQADPCMP_NVRAM_int32_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM TQADPCMP_NVRAM_INT8_CONST: */
Std_ReturnType NVM_TQADPCMP_NVRAM_int8_const__nvmini(void)
{
   TQADPCMP_NVRAM_int8_const__nvmini();
   return E_OK;
}

/* Définition de la callback d'initialisation du block NVM USTHRMT_NVRAM_INT16_CALIB: */
Std_ReturnType NVM_UsThrMT_NVRAM_int16_calib__nvmini(void)
{
   UsThrMT_NVRAM_int16_calib__nvmini();
   return E_OK;
}


/*------------------------------ end of file ---------------------------------*/
