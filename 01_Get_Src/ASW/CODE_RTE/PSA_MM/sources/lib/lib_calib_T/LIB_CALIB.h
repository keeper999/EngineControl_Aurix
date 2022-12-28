/***************************************************************************/
/* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT           */
/* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS        */
/* L'AUTORISATION DU G.I.E PSA PEUGEOT CITROEN OU DE LA SOCIETE GENERALE   */
/* D'ACHATS (SOGEDAC) AGISSANT COMME LEUR MANDATAIRE                       */
/***************************************************************************/
/*   Copyright (C) 2009                                                    */
/*-------------------------------------------------------------------------*/
/*   File name      :   LIB_CALIB.h                                        */
/*-------------------------------------------------------------------------*/
/*   Description    :   Fichier de definition des calibrations             */
/*-------------------------------------------------------------------------*/
/*   History                                                               */
/*   Version   Author     Date            Modification                     */
/*                                                                         */
/***************************************************************************/

#ifndef _LIB_CALIB_H_
#define _LIB_CALIB_H_

#include "Rte_Type.h"
#include "LIB_CALIB_Defines.h"

/***************************************************************************/
/* CALIBRATION UInt8                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CALIB_8BIT
#include "LIB_CALIB_MemMap.h"

#ifdef IGSYS_AGCKDELTAINVLVTHD_C
extern CONST(UInt8,LIB_CALIB_CONST) IgSys_agCkDeltaInVlvThd_C;
#endif

#ifdef IGSYS_AGCKDELTAEXVLVTHD_C
extern CONST(UInt8,LIB_CALIB_CONST) IgSys_agCkDeltaExVlvThd_C;
#endif

#ifdef AIREFC_NOCYLENG_C
extern CONST(UInt8,LIB_CALIB_CONST) AirEfc_noCylEng_C;
#endif

#ifdef ACVMP_NOENGMDL_C
extern CONST(UInt8,LIB_CALIB_CONST) AcvMP_noEngMdl_C;
#endif

#ifdef AFA_AGCKVLVEXREF_C
extern CONST(UInt8,LIB_CALIB_CONST) AFA_agCkVlvExRef_C;
#endif

#ifdef AFA_AGCKVLVINREF_C
extern CONST(UInt8,LIB_CALIB_CONST) AFA_agCkVlvInRef_C;
#endif

#ifdef AFA_FACAREFFTHROFS1REF_C
extern CONST(UInt8,LIB_CALIB_CONST) AFA_facArEffThrOfs1Ref_C;
#endif

#ifdef AFA_FACAREFFTHROFS2REF_C
extern CONST(UInt8,LIB_CALIB_CONST) AFA_facArEffThrOfs2Ref_C;
#endif

#ifdef AFA_FACAREFFTHROFS3REF_C
extern CONST(UInt8,LIB_CALIB_CONST) AFA_facArEffThrOfs3Ref_C;
#endif

#ifdef AFA_RCORAREFFEGRVLVREQREF_C
extern CONST(UInt8,LIB_CALIB_CONST) AFA_rCorArEffEGRVlvReqRef_C;
#endif

#ifdef AFA_TIOFFINJREF_C
extern CONST(UInt8,LIB_CALIB_CONST) AFA_tiOffInjRef_C;
#endif

#ifdef AIREFC_AGCKVLVOVLPLIM_C
extern CONST(UInt8,LIB_CALIB_CONST) AirEfc_agCkVlvOvlpLim_C;
#endif

#ifdef INM_RKK2_C
extern CONST(UInt8,LIB_CALIB_CONST) InM_rKk2_C;
#endif

#ifdef EXM_NOPRESSENPRES_C
extern CONST(UInt8,LIB_CALIB_CONST) ExM_noPresSenPres_C;
#endif

#ifdef VLVSYS_FACBASMODCURBEDMOD_C
extern CONST(UInt8,LIB_CALIB_CONST) VlvSys_facBasModCurBedMod_C;
#endif

#ifdef VLVSYS_FACBASMODTARBEDMOD_C
extern CONST(UInt8,LIB_CALIB_CONST) VlvSys_facBasModTarBedMod_C;
#endif

#ifdef VLVSYS_FACTRANMODBEDMOD_C
extern CONST(UInt8,LIB_CALIB_CONST) VlvSys_facTranModBedMod_C;
#endif

#ifdef VLVSYS_IDXBAS1MODCURBEDMOD_C
extern CONST(UInt8,LIB_CALIB_CONST) VlvSys_idxBas1ModCurBedMod_C;
#endif

#ifdef VLVSYS_IDXBAS1MODTARBEDMOD_C
extern CONST(UInt8,LIB_CALIB_CONST) VlvSys_idxBas1ModTarBedMod_C;
#endif

#ifdef VLVSYS_IDXBAS2MODCURBEDMOD_C
extern CONST(UInt8,LIB_CALIB_CONST) VlvSys_idxBas2ModCurBedMod_C;
#endif

#ifdef VLVSYS_IDXBAS2MODTARBEDMOD_C
extern CONST(UInt8,LIB_CALIB_CONST) VlvSys_idxBas2ModTarBedMod_C;
#endif

#ifdef INJSYS_NOCYL_C
extern CONST(UInt8,LIB_CALIB_CONST) InjSys_noCyl_C;
#endif

#define LIB_CALIB_STOP_SEC_CALIB_8BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION SInt8                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CALIB_8BIT
#include "LIB_CALIB_MemMap.h"

#ifdef VLVSYS_AGCKCLSEXVLVREQREF0MIN_C
extern CONST(SInt8,LIB_CALIB_CONST) VlvSys_agCkClsExVlvReqRef0Min_C;
#endif

#ifdef VLVSYS_AGCKOPINVLVREQREF0MAX_C
extern CONST(SInt8,LIB_CALIB_CONST) VlvSys_agCkOpInVlvReqRef0Max_C;
#endif

#define LIB_CALIB_STOP_SEC_CALIB_8BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION UInt16                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CALIB_16BIT
#include "LIB_CALIB_MemMap.h"

#ifdef ENG_MREF_C
extern CONST(UInt16,LIB_CALIB_CONST) Eng_mRef_C;
#endif

#ifdef AIREFC_PREF_C
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_pRef_C;
#endif

#ifdef AFA_ROPTHRREF2_C
extern CONST(UInt16,LIB_CALIB_CONST) AFA_rOpThrRef2_C;
#endif

#ifdef AFA_ROPTHRREF3_C
extern CONST(UInt16,LIB_CALIB_CONST) AFA_rOpThrRef3_C;
#endif

#ifdef AIR_PUSTHRREF_C
extern CONST(UInt16,LIB_CALIB_CONST) Air_pUsThrRef_C;
#endif

#ifdef AFA_AREFFTHROFSREF_C
extern CONST(UInt16,LIB_CALIB_CONST) AFA_arEffThrOfsRef_C;
#endif

#ifdef AFA_FACIVSINJGAINREF_C
extern CONST(UInt16,LIB_CALIB_CONST) AFA_facIvsInjGainRef_C;
#endif

#ifdef AFA_FACLAMERRREF_C
extern CONST(UInt16,LIB_CALIB_CONST) AFA_facLamErrRef_C;
#endif

#ifdef AFA_FACPRESDSTHRERRREF_C
extern CONST(UInt16,LIB_CALIB_CONST) AFA_facPresDsThrErrRef_C;
#endif

#ifdef AFA_ROPTHRMAX_C
extern CONST(UInt16,LIB_CALIB_CONST) AFA_rOpThrMax_C;
#endif

#ifdef AIR_RLDMIN_C
extern CONST(UInt16,LIB_CALIB_CONST) Air_rLdMin_C;
#endif

#ifdef AIREFC_GMAIVSAIR_C
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_gmaIvsAir_C;
#endif

#ifdef AIREFC_NENGTHDVAL_C
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_nEngThdVal_C;
#endif

#ifdef AIREFC_TREF_C
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_tRef_C;
#endif

#ifdef ENGM_MREF_C
extern CONST(UInt16,LIB_CALIB_CONST) EngM_mRef_C;
#endif

#ifdef INM_FACKK2_C
extern CONST(UInt16,LIB_CALIB_CONST) InM_facKk2_C;
#endif

#ifdef ENGM_RTOTLDEXMIN_C
extern CONST(UInt16,LIB_CALIB_CONST) EngM_rTotLdExMin_C;
#endif

#ifdef ENG_FACSTOICH_C
extern CONST(UInt16,LIB_CALIB_CONST) Eng_facStoich_C;
#endif

#define LIB_CALIB_STOP_SEC_CALIB_16BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION SInt16                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CALIB_16BIT
#include "LIB_CALIB_MemMap.h"

#ifdef VLV_AGCKEXVLVREFMAX_C
extern CONST(SInt16,LIB_CALIB_CONST) Vlv_agCkExVlvRefMax_C;
#endif

#ifdef VLV_AGCKEXVLVREFMIN_C
extern CONST(SInt16,LIB_CALIB_CONST) Vlv_agCkExVlvRefMin_C;
#endif

#ifdef VLV_AGCKINVLVREFMAX_C
extern CONST(SInt16,LIB_CALIB_CONST) Vlv_agCkInVlvRefMax_C;
#endif

#ifdef VLV_AGCKINVLVREFMIN_C
extern CONST(SInt16,LIB_CALIB_CONST) Vlv_agCkInVlvRefMin_C;
#endif

#define LIB_CALIB_STOP_SEC_CALIB_16BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION UInt32                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CALIB_32BIT
#include "LIB_CALIB_MemMap.h"

#ifdef AIREFC_VOLREF_C
extern CONST(UInt32,LIB_CALIB_CONST) AirEfc_volRef_C;
#endif

#ifdef AIREFC_DENSAIR_C
extern CONST(UInt32,LIB_CALIB_CONST) AirEfc_densAir_C;
#endif

#ifdef AFA_FACSLOPINJGAINREF_C
extern CONST(UInt32,LIB_CALIB_CONST) AFA_facSlopInjGainRef_C;
#endif

#define LIB_CALIB_STOP_SEC_CALIB_32BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION Boolean                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CALIB_BOOLEAN
#include "LIB_CALIB_MemMap.h"

#ifdef IGSYS_BACVETBMOD_C
extern CONST(Boolean,LIB_CALIB_CONST) IgSys_bAcvETBMod_C;
#endif

#ifdef AFA_BACVVVTADP_C
extern CONST(Boolean,LIB_CALIB_CONST) AFA_bAcvVVTAdp_C;
#endif

#ifdef AIREFC_BBOOST_C
extern CONST(Boolean,LIB_CALIB_CONST) AirEfc_bBoost_C;
#endif

#ifdef AIREFC_BBOOSTCF_C
extern CONST(Boolean,LIB_CALIB_CONST) AirEfc_bBoostCf_C;
#endif

#ifdef AIREFC_BRHOAIR_C
extern CONST(Boolean,LIB_CALIB_CONST) AirEfc_bRhoAir_C;
#endif

#ifdef AIREFC_BVOLBURNRGTOT_C
extern CONST(Boolean,LIB_CALIB_CONST) AirEfc_bVolBurnRgTot_C;
#endif

#ifdef INM_BINHPRED_C
extern CONST(Boolean,LIB_CALIB_CONST) InM_bInhPred_C;
#endif

#ifdef EXM_BSENPRESTYP_C
extern CONST(Boolean,LIB_CALIB_CONST) ExM_bSenPresTyp_C;
#endif

#ifdef AFA_BSELADPTYP_C
extern CONST(Boolean,LIB_CALIB_CONST) AFA_bSelAdpTyp_C;
#endif

#ifdef ENGM_BTOTLDEX_C
extern CONST(Boolean,LIB_CALIB_CONST) EngM_bTotLdEx_C;
#endif

#ifdef ENGMTRB_BMPMACV_C
extern CONST(Boolean,LIB_CALIB_CONST) EngMTrb_bMPMAcv_C;
#endif

#ifdef VLVSYS_BACVOEMBEDMOD_C
extern CONST(Boolean,LIB_CALIB_CONST) VlvSys_bAcvOEMBedMod_C;
#endif

#ifdef VLVSYS_BPRESEXSERVO_C
extern CONST(Boolean,LIB_CALIB_CONST) VlvSys_bPresExServo_C;
#endif

#ifdef VLVSYS_BPRESINSERVO_C
extern CONST(Boolean,LIB_CALIB_CONST) VlvSys_bPresInServo_C;
#endif

#ifdef IGSYS_BACVLIMTARAGCOR_C
extern CONST(Boolean,LIB_CALIB_CONST) IgSys_bAcvLimTarAgCor_C;
#endif

#ifdef AIREFC_BACVAIRLDCOR_C
extern CONST(Boolean,LIB_CALIB_CONST) AirEfc_bAcvAirLdCor_C;
#endif

#define LIB_CALIB_STOP_SEC_CALIB_BOOLEAN
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION Carto 1D UInt8                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_8BIT
#include "LIB_CALIB_MemMap.h"

#ifdef INM_FACCYLREF2_T
extern CONST(UInt8,LIB_CALIB_CONST) InM_facCylRef2_T[6];
#endif

#ifdef INM_FACRELAX_T
extern CONST(UInt8,LIB_CALIB_CONST) InM_facRelax_T[30];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_8BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION Carto 1D UInt16                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

#ifdef AIREFC_FACCHGCORSLOPEFC_T
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facChgCorSlopEfc_T[11];
#endif

#ifdef AIREFC_FACCHREXP_T
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facChrExp_T[11];
#endif

#ifdef AIREFC_FACTBURNCYL_T
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facTBurnCyl_T[16];
#endif

#ifdef AIREFC_FACTINSQRT_T
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facTInSqrt_T[16];
#endif

#ifdef AIREFC_PDELTACORSLOPEFC_T
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_pDeltaCorSlopEfc_T[18];
#endif

#ifdef AIREFC_RVOLCYL_T
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_rVolCyl_T[20];
#endif

#ifdef INM_FACCFETHR_T
extern CONST(UInt16,LIB_CALIB_CONST) InM_facCfeThr_T[22];
#endif

#ifdef AIR_AREFFTHR_T
extern CONST(UInt16,LIB_CALIB_CONST) Air_arEffThr_T[33];
#endif

#ifdef INM_FACCFEVLV_T
extern CONST(UInt16,LIB_CALIB_CONST) InM_facCfeVlv_T[22];
#endif

#ifdef INM_RAIRPRESFULLLD_T
extern CONST(UInt16,LIB_CALIB_CONST) InM_rAirPresFullLd_T[9];
#endif

#ifdef AIR_ROPTHR_T
extern CONST(UInt16,LIB_CALIB_CONST) Air_rOpThr_T[33];
#endif

#ifdef EXM_CPPEG_T
extern CONST(UInt16,LIB_CALIB_CONST) ExM_cppEg_T[11];
#endif

#ifdef INM_FACCFEGRADTHR_T
extern CONST(UInt16,LIB_CALIB_CONST) InM_facCfeGradThr_T[22];
#endif

#ifdef AIREFC_FACTAIRUSINVLV_T
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facTAirUsInVlv_T[16];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION Carto 1D UInt32                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_32BIT
#include "LIB_CALIB_MemMap.h"

#ifdef AIREFC_FACTEXSQRT_T
extern CONST(UInt32,LIB_CALIB_CONST) AirEfc_facTExSqrt_T[16];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_32BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION Carto 2D UInt16                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

#ifdef AIREFC_FACAIRSCV_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facAirScv_M[8][11];
#endif

#ifdef AIREFC_FACCORATMSLOPEFC_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facCorAtmSlopEfc_M[18][13];
#endif

#ifdef AIREFC_FACCORBOOSTSLOPEFC_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facCorBoostSlopEfc_M[18][13];
#endif

#ifdef AIREFC_FACCORMASSBURNRG_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facCorMassBurnRg_M[18][13];
#endif

#ifdef AIREFC_FACMASSFLOWCOR_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facMassFlowCor_M[18][13];
#endif

#ifdef AIREFC_FACTAIRUSINVLV_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facTAirUsInVlv_M[18][16];
#endif

#ifdef AIREFC_FACTCO_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facTCo_M[18][10];
#endif

#ifdef AIREFC_MFAIRSCVRED_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_mfAirScvRed_M[8][25];
#endif

#ifdef AIREFC_MFBURNRSPGREDBAS_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_mfBurnRspgRedBas_M[18][25];
#endif

#ifdef AIREFC_MFBURNRSPGREDCOR_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_mfBurnRspgRedCor_M[18][25];
#endif

#ifdef AIREFC_PBEGCORBOOSTSLOPEFC_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_pBegCorBoostSlopEfc_M[18][13];
#endif

#ifdef AIREFC_RVOLCYL_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_rVolCyl_M[13][13];
#endif

#ifdef AIREFC_RFUSTMMASS_M
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_rFuStmMass_M[18][20];
#endif

#ifdef ENGM_RTOTLDEX_M
extern CONST(UInt16,LIB_CALIB_CONST) EngM_rTotLdEx_M[18][16];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION Carto 2D SInt16                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

#ifdef IGSYS_AGCKCLSEXVLVWRMDFT_M
extern CONST(SInt16,LIB_CALIB_CONST) IgSys_agCkClsExVlvWrmDft_M[16][16];
#endif

#ifdef IGSYS_AGCKOPINVLVWRMDFT_M
extern CONST(SInt16,LIB_CALIB_CONST) IgSys_agCkOpInVlvWrmDft_M[16][16];
#endif

#ifdef ENGM_FACD_M
extern CONST(SInt16,LIB_CALIB_CONST) EngM_facD_M[16][16];
#endif

#ifdef ENGM_FACDGAS_M
extern CONST(SInt16,LIB_CALIB_CONST) EngM_facDGas_M[16][16];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION Carto 2D UInt32                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_32BIT
#include "LIB_CALIB_MemMap.h"

#ifdef AFAMGT_TIDLYLSTOBSTHD_M
extern CONST(UInt32,LIB_CALIB_CONST) AFAMgt_tiDlyLstObsThd_M[9][9];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_32BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION AxeUInt8                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_8BIT
#include "LIB_CALIB_MemMap.h"

#ifdef AIREFC_TCOX_A
extern CONST(UInt8,LIB_CALIB_CONST) AirEfc_tCoX_A[10];
#endif

#ifdef INM_NOCYLENG_A
extern CONST(UInt8,LIB_CALIB_CONST) InM_noCylEng_A[6];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_8BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION AxeUInt16                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

#ifdef EXT_NENG_A
extern CONST(UInt16,LIB_CALIB_CONST) Ext_nEng_A[16];
#endif

#ifdef ENG_RAIRLD_A
extern CONST(UInt16,LIB_CALIB_CONST) Eng_rAirLd_A[16];
#endif

#ifdef EXT_NENGREF4_A
extern CONST(UInt16,LIB_CALIB_CONST) Ext_nEngRef4_A[20];
#endif

#ifdef EXT_NENGREF1_A
extern CONST(UInt16,LIB_CALIB_CONST) Ext_nEngRef1_A[16];
#endif

#ifdef AIREFC_TEXMNF_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_tExMnf_A[16];
#endif

#ifdef AIR_MFEGR_A
extern CONST(UInt16,LIB_CALIB_CONST) Air_mfEGR_A[9];
#endif

#ifdef AIR_PAIR_A
extern CONST(UInt16,LIB_CALIB_CONST) Air_pAir_A[16];
#endif

#ifdef AIR_RAIRPRES_A
extern CONST(UInt16,LIB_CALIB_CONST) Air_rAirPres_A[22];
#endif

#ifdef EXT_NENGREF2_A
extern CONST(UInt16,LIB_CALIB_CONST) Ext_nEngRef2_A[9];
#endif

#ifdef AIR_MFAIR_A
extern CONST(UInt16,LIB_CALIB_CONST) Air_mfAir_A[9];
#endif

#ifdef AIREFC_AGCK_FACTDC_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_agCk_facTDC_A[20];
#endif

#ifdef AIREFC_AGCKCLSINVLVX_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_agCkClsInVlvX_A[13];
#endif

#ifdef AIREFC_FACAIRSCVX_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facAirScvX_A[11];
#endif

#ifdef AIREFC_FACCHGCORSLOPEFC_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_facChgCorSlopEfc_A[11];
#endif

#ifdef AIREFC_NDELTACORSLOPEFC_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_nDeltaCorSlopEfc_A[18];
#endif

#ifdef AIREFC_NENG2Y_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_nEng2Y_A[8];
#endif

#ifdef AIREFC_NENGY_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_nEngY_A[18];
#endif

#ifdef AIREFC_TAIRUSINVLV_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_tAirUsInVlv_A[16];
#endif

#ifdef AIREFC_TBURNCYL_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_tBurnCyl_A[16];
#endif

#ifdef INJ_CONCFUSTM_A
extern CONST(UInt16,LIB_CALIB_CONST) Inj_concFuStm_A[9];
#endif

#ifdef INJ_CONCFUSTMERR_A
extern CONST(UInt16,LIB_CALIB_CONST) Inj_concFuStmErr_A[9];
#endif

#ifdef AIR_MFAIRREF1_A
extern CONST(UInt16,LIB_CALIB_CONST) Air_mfAirRef1_A[16];
#endif

#ifdef INM_FACRELAX_A
extern CONST(UInt16,LIB_CALIB_CONST) InM_facRelax_A[30];
#endif

#ifdef TRBACT_FACPRESALTICOR_A
extern CONST(UInt16,LIB_CALIB_CONST) TrbAct_facPresAltiCor_A[9];
#endif

#ifdef TRBACT_NENG_A
extern CONST(UInt16,LIB_CALIB_CONST) TrbAct_nEng_A[9];
#endif

#ifdef AIREFC_TFU_A
extern CONST(UInt16,LIB_CALIB_CONST) AirEfc_tFu_A[16];
#endif

#ifdef ENGM_NENGY_A
extern CONST(UInt16,LIB_CALIB_CONST) EngM_nEngY_A[18];
#endif

#ifdef ENGM_PDSTHR_A
extern CONST(UInt16,LIB_CALIB_CONST) EngM_pDsThr_A[16];
#endif

#ifdef EXM_TEG_A
extern CONST(UInt16,LIB_CALIB_CONST) ExM_tEg_A[11];
#endif

#ifdef VLVSYS_NENG16_A
extern CONST(UInt16,LIB_CALIB_CONST) VlvSys_nEng16_A[16];
#endif

#ifdef VLVSYS_NENG8_A
extern CONST(UInt16,LIB_CALIB_CONST) VlvSys_nEng8_A[8];
#endif

#ifdef VLVSYS_RAIRLD16_A
extern CONST(UInt16,LIB_CALIB_CONST) VlvSys_rAirLd16_A[16];
#endif

#ifdef VLVSYS_RAIRLD8_A
extern CONST(UInt16,LIB_CALIB_CONST) VlvSys_rAirLd8_A[8];
#endif

#ifdef AIR_AREFFTHR_A
extern CONST(UInt16,LIB_CALIB_CONST) Air_arEffThr_A[33];
#endif

#ifdef AIR_ROPTHR_A
extern CONST(UInt16,LIB_CALIB_CONST) Air_rOpThr_A[33];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION AxeSInt16                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

#ifdef AIREFC_AGCKCLSEXVLVX_A
extern CONST(SInt16,LIB_CALIB_CONST) AirEfc_agCkClsExVlvX_A[13];
#endif

#ifdef AIREFC_AGCKOPINVLVY_A
extern CONST(SInt16,LIB_CALIB_CONST) AirEfc_agCkOpInVlvY_A[13];
#endif

#ifdef AIREFC_AGCKPOSNVLVOVLPX_A
extern CONST(SInt16,LIB_CALIB_CONST) AirEfc_agCkPosnVlvOvlpX_A[13];
#endif

#ifdef AIREFC_AGCKVLVOVLPX_A
extern CONST(SInt16,LIB_CALIB_CONST) AirEfc_agCkVlvOvlpX_A[25];
#endif

#ifdef TRBACT_PDIFMAXPNMACTREQ_A
extern CONST(SInt16,LIB_CALIB_CONST) TrbAct_pDifMaxPnmActReq_A[9];
#endif

#ifdef TRBACT_PDIFTRBESTIM_A
extern CONST(SInt16,LIB_CALIB_CONST) TrbAct_pDifTrbEstim_A[16];
#endif

#ifdef AIREFC_AGINJPHA_A
extern CONST(SInt16,LIB_CALIB_CONST) AirEfc_agInjPha_A[20];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_16BIT
#include "LIB_CALIB_MemMap.h"

/***************************************************************************/
/* CALIBRATION AxeUInt32                                                       */
/***************************************************************************/

#define LIB_CALIB_START_SEC_CARTO_32BIT
#include "LIB_CALIB_MemMap.h"

#ifdef AIREFC_RPRESENGX_A
extern CONST(UInt32,LIB_CALIB_CONST) AirEfc_rPresEngX_A[11];
#endif

#define LIB_CALIB_STOP_SEC_CARTO_32BIT
#include "LIB_CALIB_MemMap.h"

#endif /* _LIB_CALIB_H_ */
