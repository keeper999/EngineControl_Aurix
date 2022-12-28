/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT                                                 */
/* !Description     : Public declarations                                     */
/*                                                                            */
/* !File            : AFAMgtT.h                                               */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AFAMgtT_SWC.mdl                                       */
/*   Root subsystem   : /AFAMgtT                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   22 Aug 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFAMgtT_h_
#define RTW_HEADER_AFAMgtT_h_
#ifndef AFAMgtT_COMMON_INCLUDES_
# define AFAMgtT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AFAMgtT.h"
#include "AFAMgtT_import.h"
#include "Std_Types.h"
#include "AFAMgtT_nvm.h"
#endif                                 /* AFAMgtT_COMMON_INCLUDES_ */

#include "AFAMgtT_types.h"

/* Child system includes */
#define AFAMgtT_Init_MDLREF_HIDE_CHILD_
#include "AFAMgtT_Init.h"
#undef AFAMgtT_Init_MDLREF_HIDE_CHILD_
#include "AFAMgtT_F04_check_petrol_mode_stability.h"
#include "AFAMgtT_F03_check_air_mode_stability.h"
#define AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_
#include "AFAMgtT_F02_command_observation.h"
#undef AFAMgtT_F02_command_observation_MDLREF_HIDE_CHILD_
#include "AFAMgtT_F02_check_stability_SdlMid.h"
#define AFAMgtT_F01_init_adaptation_manager_MDLREF_HIDE_CHILD_
#include "AFAMgtT_F01_init_adaptation_manager.h"
#undef AFAMgtT_F01_init_adaptation_manager_MDLREF_HIDE_CHILD_
#define AFAMgtT_F01_adaptation_observations_delay_MDLREF_HIDE_CHILD_
#include "AFAMgtT_F01_adaptation_observations_delay.h"
#undef AFAMgtT_F01_adaptation_observations_delay_MDLREF_HIDE_CHILD_
#define AFAMgtT_F01_AFAAdpCndChk_MDLREF_HIDE_CHILD_
#include "AFAMgtT_F01_AFAAdpCndChk.h"
#undef AFAMgtT_F01_AFAAdpCndChk_MDLREF_HIDE_CHILD_

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define AFAMgt_tiSampleMid_SC          ((UInt16) 400U)
#define AFAMgt_tiSampleSlow_SC         ((UInt16) 400U)

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Block signals (auto storage) */
typedef struct {
  UInt32 TmpSignalConversionAtInjrSys_pr[4];
  UInt32 TmpSignalConversionAtAFAMgt_tiC;
  UInt32 TmpSignalConversionAtAFAMgt_t_h;
  UInt32 TmpSignalConversionAtAFAMgt_t_l;
  UInt32 TmpSignalConversionAtAFAMgt_t_k;
  UInt32 TmpSignalConversionAtAFAMgt_t_b;
  UInt32 TmpSignalConversionAtAFAMgt_t_m;
  UInt32 TmpSignalConversionAtAFAMgt_t_f;
  UInt32 TmpSignalConversionAtAFAMgt_t_a;
  UInt32 AFAMgtT_F04_check_petrol_mode_s;/* '<S41>/AFAMgtT_F04_check_petrol_mode_stability' */
  UInt32 AFAMgtT_F03_check_air_mode_stab;/* '<S40>/AFAMgtT_F03_check_air_mode_stability' */
  UInt32 AFAMgtT_F02_check_stability_Sdl;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt32 AFAMgtT_F02_check_stability_S_n;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt32 AFAMgtT_F02_check_stability_S_b;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt32 AFAMgtT_F02_check_stability_S_g;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt32 AFAMgtT_F02_check_stability_S_d;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt32 AFAMgtT_F02_check_stability_S_f;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt32 TmpSignalConversionAtAFAMgt__lf;
  UInt32 TmpSignalConversionAtAFAMgt__me;
  UInt32 Merge6;                     /* '<S11>/Merge6' */
  UInt32 TmpSignalConversionAtAFA_tiDlyL;
  UInt32 Merge5;                     /* '<S11>/Merge5' */
  UInt32 Merge1;                     /* '<S11>/Merge1' */
  SInt16 TmpSignalConversionAtExt_tDsThr;
  SInt16 TmpSignalConversionAtExt_tCoMes;
  UInt16 TmpSignalConversionAtExt_nEngOu;
  UInt16 TmpSignalConversionAtAFA_nEngLs;
  UInt16 TmpSignalConversionAtAFA_noAdpE;
  UInt16 TmpSignalConversionAtEGRSys_rEG;
  UInt16 TmpSignalConversionAtEngM_rAirL;
  UInt16 TmpSignalConversionAtAFAMgt_rAi;
  UInt16 TmpSignalConversionAtAFAMgt_r_j;
  UInt16 AFAMgtT_F02_check_stability_S_c;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt16 AFAMgtT_F02_check_stability_S_o;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt16 TmpSignalConversionAtEngM_rTotL;
  UInt16 TmpSignalConversionAtAFA_rTotLd;
  UInt16 TmpSignalConversionAtInjSys_prm[6];
  UInt16 TmpSignalConversionAtFARSp_rMix;
  SInt16 TmpSignalConversionAtInM_pDynCo;
  SInt16 TmpSignalConversionAtEngM_rDelt;
  UInt16 TmpSignalConversionAtInjrM_prm_[4];
  UInt16 TmpSignalConversionAtInjrM_pr_o[4];
  UInt16 TmpSignalConversionAtEngM_rltMa;
  UInt16 TmpSignalConversionAtCanPurg_co;
  UInt16 TmpSignalConversionAtCanPurg__h;
  UInt16 TmpSignalConversionAtExt_pDsThr;
  UInt16 TmpSignalConversionAtUsThrM_pAi;
  UInt8 TmpSignalConversionAtEGRVlv_stE;
  UInt8 TmpSignalConversionAtCoPt_noEgd;
  UInt8 TmpSignalConversionAtAFAMgt_noE;
  UInt8 AFAMgtT_F02_check_stability_S_l;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt8 TmpSignalConversionAtAFA_noObsD;
  Boolean TmpSignalConversionAtEOM_bTranM;
  Boolean Merge;                     /* '<S9>/Merge' */
  Boolean TmpSignalConversionAtAFAMgt_bIn;
  Boolean TmpSignalConversionAtAFAMgt_bTr;
  Boolean TmpSignalConversionAtInjSys_bAc;
  Boolean Not;                       /* '<S42>/Not' */
  Boolean TmpSignalConversionAtAFAMgt_b_p;
  Boolean AFAMgtT_F04_check_petrol_mode_d;/* '<S41>/AFAMgtT_F04_check_petrol_mode_stability' */
  Boolean AFAMgtT_F03_check_air_mode_st_e;/* '<S40>/AFAMgtT_F03_check_air_mode_stability' */
  Boolean AFAMgtT_F03_check_air_mode_st_p;/* '<S40>/AFAMgtT_F03_check_air_mode_stability' */
  Boolean AFAMgtT_F02_check_stability__gh;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  Boolean AFAMgtT_F02_check_stability__ng;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  Boolean AFAMgtT_F02_check_stability__f1;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  Boolean AFAMgtT_F02_check_stability_S_j;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  Boolean AFAMgtT_F02_check_stability_S_a;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  Boolean AFAMgtT_F02_check_stability__c2;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  Boolean AFAMgtT_F02_check_stability__n1;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  Boolean TmpSignalConversionAtAFAMgt_b_h;
  Boolean TmpSignalConversionAtInjSys_b_k;
  Boolean Merge4_p;                  /* '<S11>/Merge4' */
  Boolean Not_m;                     /* '<S89>/Not' */
  Boolean TmpSignalConversionAtAFAMgt_b_j;
  Boolean TmpSignalConversionAtAFAMgt_bSt;
  Boolean TmpSignalConversionAtAFAMgt_bId;
  Boolean TmpSignalConversionAtAFAMgt_b_c;
  Boolean TmpSignalConversionAtAFAMgt_b_m;
  Boolean Merge7_b;                  /* '<S11>/Merge7' */
  Boolean Merge8_p;                  /* '<S11>/Merge8' */
  Boolean TmpSignalConversionAtGSM_bAcvAF;
  Boolean Not_p;                     /* '<S87>/Not' */
  Boolean TmpSignalConversionAtAFA_bAuthC;
  Boolean TmpSignalConversionAtAFAMgt__j2;
  Boolean TmpSignalConversionAtAFAMgt_b_g;
  Boolean TmpSignalConversionAtBlby_bIdcW;
  Boolean TmpSignalConversionAtAFA_bIdcCo;
  Boolean Merge2_c;                  /* '<S11>/Merge2' */
  Boolean Merge_m;                   /* '<S107>/Merge' */
  Boolean AFAMgt_bAdpClcRstReq;      /* '<S106>/F01_supervise_adaptation_manager_chart' */
  Boolean AFAMgtT_F01_AFAAdpCndChk_h;/* '<S76>/AFAMgtT_F01_AFAAdpCndChk' */
  Boolean AFAMgtT_F02_command_observati_i;/* '<S78>/AFAMgtT_F02_command_observation' */
  Boolean AFAMgtT_F02_command_observati_k;/* '<S78>/AFAMgtT_F02_command_observation' */
  Boolean AFAMgtT_F02_command_observati_p;/* '<S78>/AFAMgtT_F02_command_observation' */
  Boolean AFAMgtT_F02_command_observati_o;/* '<S78>/AFAMgtT_F02_command_observation' */
  Boolean AFAMgtT_F02_command_observat_k4;/* '<S78>/AFAMgtT_F02_command_observation' */
  Boolean AFAMgtT_F02_command_observati_g;/* '<S78>/AFAMgtT_F02_command_observation' */
  Boolean EepromReadAccess;          /* '<S10>/EepromReadAccess' */
  Boolean AFAMgtT_F01_init_adaptation_man;/* '<S69>/AFAMgtT_F01_init_adaptation_manager' */
  UInt8 TmpSignalConversionAtAFAMgt_rEG;
  UInt8 TmpSignalConversionAtAFAMgt_r_f;
  UInt8 AFAMgtT_F02_check_stability__d0;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
  UInt8 AFAMgtT_F02_check_stability_S_h;/* '<S39>/AFAMgtT_F02_check_stability_SdlMid' */
} BlockIO_AFAMgtT;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Boolean Memory_PreviousInput;      /* '<S111>/Memory' */
  Boolean AFAMgt_bActAFAAdpRstPrev;  /* '<S106>/F01_supervise_adaptation_manager_chart' */
} D_Work_AFAMgtT;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */


#define AFAMgtT_START_SEC_INTERNAL_VAR_32BIT
#include "AFAMgtT_MemMap.h"


/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  RTW declares the memory for these signals
 * and exports their symbols.
 *
 */
extern UInt32 AFAMgt_tiCntStabRatOpEGR_IRV_MP;
extern UInt32 AFAMgt_tiCntNotDynCorPres_IRV_MP;
extern UInt32 AFAMgt_tiCntStabEgdGear_IRV_MP;
extern UInt32 AFAMgt_tiCntStabEOM_IRV_MP;
extern UInt32 AFAMgt_tiCntStabFacStrt_IRV_MP;
extern UInt32 AFAMgt_tiCntStabAirLd_IRV_MP;
extern UInt32 AFAMgt_tiCntStabFuMod_IRV_MP;
extern UInt32 AFAMgt_tiCntStabAirMod_IRV_MP;
extern UInt32 AFAMgt_tiDlyLstObsThd_IRV_MP;

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAMgtT_MemMap.h"

extern UInt16 AFAMgt_rAirLdMax_IRV_MP;
extern UInt16 AFAMgt_rAirLdMin_IRV_MP;

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_INTERNAL_VAR_8BIT
#include "AFAMgtT_MemMap.h"

extern UInt8 AFAMgt_noEgdGearCordHld_IRV_MP;
extern UInt8 AFAMgt_rEGRMin_IRV_MP;  
extern UInt8 AFAMgt_rEGRMax_IRV_MP;  

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAMgtT_MemMap.h"

extern Boolean AFAMgt_bIdcNotDynCorPres_IRV_MP;
extern Boolean AFAMgt_bIdcStabRatOpEGR_IRV_MP;
extern Boolean AFAMgt_bIdcInhChk;    
extern Boolean AFAMgt_bTranModHld_IRV_MP;
extern Boolean AFAMgt_bStabAirLdCor_IRV_MP;
extern Boolean AFAMgt_bStabEgdGear_IRV_MP;
extern Boolean AFAMgt_bStabEOM_IRV_MP;
extern Boolean AFAMgt_bStabFacStrtCor_IRV_MP;
extern Boolean AFAMgt_bIdcStabAirMod_IRV_MP;
extern Boolean AFAMgt_bIdcStabFuMod_IRV_MP;
extern Boolean AFAMgt_bEveRstStabChk_IRV_MP;
extern Boolean AFAMgt_bInhAirModTmp_IRV_MP;
extern Boolean AFAMgt_bInhAdpEfc;    
extern Boolean AFAMgt_bAcvAdpRstDiagRaw;

#define AFAMgtT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAMgtT_MemMap.h"


#define AFAMgtT_START_SEC_VAR_UNSPECIFIED
#include "AFAMgtT_MemMap.h"


/* Block signals (auto storage) */
extern BlockIO_AFAMgtT AFAMgtT_B;

/* Block states (auto storage) */
extern D_Work_AFAMgtT AFAMgtT_DWork;


#define AFAMgtT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAMgtT_MemMap.h"

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

/* Model init function */
extern void RE_AFAMgtT_Init(void);

/* Model entry point functions */
extern void RE_AFAMgtT_001_MSE(void);
extern void RE_AFAMgtT_007_TEV(void);
extern void RE_AFAMgtT_004_MSE(void);
extern void RE_AFAMgtT_003_TEV(void);
extern void RE_AFAMgtT_002_MSE(void);

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"


/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CARTO_32BIT" */
#define AFAMgtT_START_SEC_CARTO_32BIT
#include "AFAMgtT_MemMap.h"

/* Type:    UInt32                                                          */
/* Slope:   781.25                                                            */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.12E+007                                                         */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_pDifInjr_A[9];

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyCanPurgClsFast_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyCanPurgClsSlow_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.6777208E+004                                                    */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyLstObsDftThd_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyNotDynCorPres_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabAirLd_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabEOM_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabEgdGear_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabFacStrt_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabFuMod_C;

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiDlyStabRatOpEGR_C;

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895343999990E+004                                           */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiInjLoThd_T[9];

/* Type:    UInt32                                                          */
/* Slope:   0.005                                                             */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 5.24288E+002                                                      */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiMinDlyStabAirMod_C;

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895343999990E+004                                           */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiObsThd1_C;

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895343999990E+004                                           */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiObsThd2_C;

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895343999990E+004                                           */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiObsThd3_C;

/* Type:    UInt32                                                          */
/* Slope:   3.2E-006                                                          */
/* Bias:    0.0                                                               */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.3743895343999990E+004                                           */
extern CONST(UInt32, AFAMGTT_CARTO) AFAMgt_tiObsThd4_C;

#define AFAMgtT_STOP_SEC_CARTO_32BIT
#include "AFAMgtT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define AFAMgtT_START_SEC_CARTO_16BIT
#include "AFAMgtT_MemMap.h"

/* Type:    UInt16                                                          */
/* Slope:   3.0517578125000000E-005                                           */
/* Bias:    0.0                                                               */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.9999694824218750E+000                                           */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_facCorGainLnrThd_T[9];

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_facStrtCorCylThd_C;

/* Type:    UInt16                                                          */
/* Units:   RPM                                                               */
/* PhysMin: 0                                                                 */
/* PhysMax: 7500.0                                                            */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_nEngLstObsThd_C;

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 256.0                                                             */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_noFirstObsDoneThd_C;

/* Type:    UInt16                                                          */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 256.0                                                             */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_noObsDoneThd_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_pDsThrMaxThd_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 524280.0                                                          */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_pDsThrMinThd_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    0.0                                                               */
/* Units:   Pa                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 262136.0                                                          */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_pDynCorMaxThd_C;

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.9999389648437500E+000                                           */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rAirLdDeltaMaxThd_C;

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.9999389648437500E+000                                           */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rTotLdCorLstObsThd_C;

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rlamReqMaxThd_C;

/* Type:    UInt16                                                          */
/* Slope:   2.2888183593750000E-004                                           */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.4999771118164061E+001                                           */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rlamReqMinThd_C;

/* Type:    UInt16                                                          */
/* Slope:   6.103515625E-005                                                  */
/* Bias:    0.0                                                               */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 2.9999389648437500E+000                                           */
extern CONST(UInt16, AFAMGTT_CARTO) AFAMgt_rltMassAirScvMaxThd_C;

/* Type:    UInt16                                                          */
/* Slope:   8.0                                                               */
/* Bias:    1.0E+005                                                          */
/* Units:   Pa                                                                */
/* PhysMin: 1.0E+005                                                          */
/* PhysMax: 1.1E+005                                                          */
extern CONST(UInt16, AFAMGTT_CARTO) Air_pRef_C;

#define AFAMgtT_STOP_SEC_CARTO_16BIT
#include "AFAMgtT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define AFAMgtT_START_SEC_CARTO_8BIT
#include "AFAMgtT_MemMap.h"

/* Type:    UInt8                                                           */
/* Slope:   0.00390625                                                        */
/* Bias:    0.0                                                               */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.99609375                                                        */
extern CONST(UInt8, AFAMGTT_CARTO) AFAMgt_rDeltaLdInjPhaObsThd_C;

/* Type:    UInt8                                                           */
/* Slope:   0.001953125                                                       */
/* Bias:    0.0                                                               */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 0.498046875                                                       */
extern CONST(UInt8, AFAMGTT_CARTO) AFAMgt_rOpEGRDeltaMaxThd_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -50.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 199.0                                                             */
extern CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tAirMaxThd_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -50.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -50.0                                                             */
/* PhysMax: 199.0                                                             */
extern CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tAirMinThd_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 213.0                                                             */
extern CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tCoMaxThd_C;

/* Type:    UInt8                                                           */
/* Slope:   1.0                                                               */
/* Bias:    -40.0                                                             */
/* Units:   °C                                                                */
/* PhysMin: -40.0                                                             */
/* PhysMax: 213.0                                                             */
extern CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tCoMinThd_C;

/* Type:    UInt8                                                           */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tiDecAdpObsDft_C;

/* Type:    UInt8                                                           */
/* Units:   s                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 255.0                                                             */
extern CONST(UInt8, AFAMGTT_CARTO) AFAMgt_tiIncAdpObsDft_C;

#define AFAMgtT_STOP_SEC_CARTO_8BIT
#include "AFAMgtT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define AFAMgtT_START_SEC_CALIB_BOOLEAN
#include "AFAMgtT_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMGTT_ACTIVE_BYP_C;

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAcvAdpRstDiag_B;

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAdpClcRstReq_B;

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAdpEfcReq_B;

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAdpObsReq_B;

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAdpOfsRstReq_B;

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bAuthAdpReq_B;

/* Type:    Boolean                                                         */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bIdcInjrMdlCnd_B;

/* Type:    Boolean                                                         */
/* Units:                                                                     */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bIdcTmpObsCnd_B;

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CALIB) AFAMgt_bInhAFA_B;

#define AFAMgtT_STOP_SEC_CALIB_BOOLEAN
#include "AFAMgtT_MemMap.h"

/* !Comment: Declare data in section "CARTO_BOOLEAN" */
#define AFAMgtT_START_SEC_CARTO_BOOLEAN
#include "AFAMgtT_MemMap.h"

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CARTO) AFAMgt_bInhAFA_C;

/* Type:    Boolean                                                         */
/* Units:   -                                                                 */
/* PhysMin: 0                                                                 */
/* PhysMax: 1.0                                                               */
extern CONST(Boolean, AFAMGTT_CARTO) AFAMgt_bInhAdpEfc_C;

#define AFAMgtT_STOP_SEC_CARTO_BOOLEAN
#include "AFAMgtT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S68>/copy' : Eliminate redundant signal conversion block
 * Block '<S43>/copy' : Eliminate redundant signal conversion block
 * Block '<S45>/copy' : Eliminate redundant signal conversion block
 * Block '<S46>/copy' : Eliminate redundant signal conversion block
 * Block '<S47>/copy' : Eliminate redundant signal conversion block
 * Block '<S48>/copy' : Eliminate redundant signal conversion block
 * Block '<S49>/copy' : Eliminate redundant signal conversion block
 * Block '<S50>/copy' : Eliminate redundant signal conversion block
 * Block '<S51>/copy' : Eliminate redundant signal conversion block
 * Block '<S52>/copy' : Eliminate redundant signal conversion block
 * Block '<S53>/copy' : Eliminate redundant signal conversion block
 * Block '<S54>/copy' : Eliminate redundant signal conversion block
 * Block '<S60>/copy' : Eliminate redundant signal conversion block
 * Block '<S61>/copy' : Eliminate redundant signal conversion block
 * Block '<S62>/copy' : Eliminate redundant signal conversion block
 * Block '<S63>/copy' : Eliminate redundant signal conversion block
 * Block '<S64>/copy' : Eliminate redundant signal conversion block
 * Block '<S65>/copy' : Eliminate redundant signal conversion block
 * Block '<S66>/copy' : Eliminate redundant signal conversion block
 * Block '<S73>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S75>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S79>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S79>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S90>/copy' : Eliminate redundant signal conversion block
 * Block '<S91>/copy' : Eliminate redundant signal conversion block
 * Block '<S92>/copy' : Eliminate redundant signal conversion block
 * Block '<S93>/copy' : Eliminate redundant signal conversion block
 * Block '<S94>/copy' : Eliminate redundant signal conversion block
 * Block '<S95>/copy' : Eliminate redundant signal conversion block
 * Block '<S96>/copy' : Eliminate redundant signal conversion block
 * Block '<S97>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S98>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S99>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S100>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S102>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S103>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S104>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('AFAMgtT_SWC/AFAMgtT')    - opens subsystem AFAMgtT_SWC/AFAMgtT
 * hilite_system('AFAMgtT_SWC/AFAMgtT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AFAMgtT_SWC
 * '<S1>'   : AFAMgtT_SWC/AFAMgtT
 * '<S7>'   : AFAMgtT_SWC/AFAMgtT/Runnable_0
 * '<S8>'   : AFAMgtT_SWC/AFAMgtT/Runnable_1
 * '<S9>'   : AFAMgtT_SWC/AFAMgtT/Runnable_2
 * '<S10>'  : AFAMgtT_SWC/AFAMgtT/Runnable_3
 * '<S11>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4
 * '<S12>'  : AFAMgtT_SWC/AFAMgtT/Runnable_0/convertout1
 * '<S13>'  : AFAMgtT_SWC/AFAMgtT/Runnable_0/convertout2
 * '<S14>'  : AFAMgtT_SWC/AFAMgtT/Runnable_0/convertout3
 * '<S15>'  : AFAMgtT_SWC/AFAMgtT/Runnable_0/convertout4
 * '<S16>'  : AFAMgtT_SWC/AFAMgtT/Runnable_0/convertout5
 * '<S17>'  : AFAMgtT_SWC/AFAMgtT/Runnable_0/convertout6
 * '<S18>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/F02_check_stability_SdlMid
 * '<S19>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint
 * '<S20>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint1
 * '<S21>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint10
 * '<S22>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint11
 * '<S23>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint12
 * '<S24>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint14
 * '<S25>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint15
 * '<S26>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint16
 * '<S27>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint17
 * '<S28>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint18
 * '<S29>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint19
 * '<S30>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint2
 * '<S31>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint3
 * '<S32>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint4
 * '<S33>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint5
 * '<S34>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint6
 * '<S35>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint7
 * '<S36>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint8
 * '<S37>'  : AFAMgtT_SWC/AFAMgtT/Runnable_1/autosar_testpoint9
 * '<S38>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/F01_InitStabChk
 * '<S39>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/F02_check_stability_SdlMid
 * '<S40>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/F03_check_air_mode_stability
 * '<S41>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/F04_check_petrol_mode_stability
 * '<S42>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/Rte_Call_R_FRM_bInhInMNomMod_GetFunctionPermission
 * '<S43>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint
 * '<S44>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint1
 * '<S45>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint10
 * '<S46>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint11
 * '<S47>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint12
 * '<S48>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint13
 * '<S49>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint14
 * '<S50>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint15
 * '<S51>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint16
 * '<S52>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint17
 * '<S53>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint18
 * '<S54>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint19
 * '<S55>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint2
 * '<S56>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint20
 * '<S57>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint21
 * '<S58>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint22
 * '<S59>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint23
 * '<S60>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint3
 * '<S61>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint4
 * '<S62>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint5
 * '<S63>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint6
 * '<S64>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint7
 * '<S65>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint8
 * '<S66>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/autosar_testpoint9
 * '<S67>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/F01_InitStabChk/Task_sceduler
 * '<S68>'  : AFAMgtT_SWC/AFAMgtT/Runnable_2/F02_check_stability_SdlMid/autosar_testpoint11
 * '<S69>'  : AFAMgtT_SWC/AFAMgtT/Runnable_3/F01_init_adaptation_manager
 * '<S70>'  : AFAMgtT_SWC/AFAMgtT/Runnable_3/Rte_Call_R_FRM_bAcvAdpClcStRstReq_GetFunctionPermission
 * '<S71>'  : AFAMgtT_SWC/AFAMgtT/Runnable_3/Rte_Call_R_FRM_bAcvAdpValRstReq_GetFunctionPermission
 * '<S72>'  : AFAMgtT_SWC/AFAMgtT/Runnable_3/autosar_testpoint
 * '<S73>'  : AFAMgtT_SWC/AFAMgtT/Runnable_3/convertout
 * '<S74>'  : AFAMgtT_SWC/AFAMgtT/Runnable_3/convertout1
 * '<S75>'  : AFAMgtT_SWC/AFAMgtT/Runnable_3/convertout2
 * '<S76>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/F01_AFAAdpCndChk
 * '<S77>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/F01_adaptation_observations_delay
 * '<S78>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/F02_command_observation
 * '<S79>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/F02_supervise_adaptation_manager
 * '<S80>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/F03_check_air_mode_stability
 * '<S81>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/F03_check_air_mode_stability1
 * '<S82>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/F04_check_petrol_mode_stability
 * '<S83>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/F04_check_petrol_mode_stability1
 * '<S84>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus
 * '<S85>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_FRM_bActAFAAdpRst_GetFunctionPermission
 * '<S86>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_FRM_bActAFAInjGainRst_GetFunctionPermission
 * '<S87>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_FRM_bInhAFAObsAdp_GetFunctionPermission
 * '<S88>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_FRM_bInhAFA_GetFunctionPermission
 * '<S89>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_FRM_bInhInMNomMod_GetFunctionPermission
 * '<S90>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/autosar_testpoint
 * '<S91>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/autosar_testpoint1
 * '<S92>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/autosar_testpoint2
 * '<S93>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/autosar_testpoint20
 * '<S94>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/autosar_testpoint21
 * '<S95>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/autosar_testpoint22
 * '<S96>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/autosar_testpoint3
 * '<S97>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/convertout
 * '<S98>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/convertout1
 * '<S99>'  : AFAMgtT_SWC/AFAMgtT/Runnable_4/convertout2
 * '<S100>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/convertout3
 * '<S101>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/convertout4
 * '<S102>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/convertout5
 * '<S103>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/convertout6
 * '<S104>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/convertout7
 * '<S105>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/F02_supervise_adaptation_manager/F01_Inhibition_management
 * '<S106>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/F02_supervise_adaptation_manager/F02_supervise_adaptation_manager_chart
 * '<S107>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/F02_supervise_adaptation_manager/F03_After_sale_management
 * '<S108>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/F02_supervise_adaptation_manager/F02_supervise_adaptation_manager_chart/F01_supervise_adaptation_manager_chart
 * '<S109>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/F02_supervise_adaptation_manager/F03_After_sale_management/F01_After_sale_action
 * '<S110>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/F02_supervise_adaptation_manager/F03_After_sale_management/F02_No_after_sale_action
 * '<S111>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus/If_s
 * '<S112>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus/If_s/if_s1
 * '<S113>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus/If_s/if_s2
 * '<S114>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus/If_s/if_s1/if_s1
 * '<S115>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus/If_s/if_s1/if_s2
 * '<S116>' : AFAMgtT_SWC/AFAMgtT/Runnable_4/Rte_Call_R_AFAMgt_ObsAdp_SetEventStatus/If_s/if_s2/If Action Subsystem
 */

/*-
 * Requirements for '<Root>': AFAMgtT
 *
 * Inherited requirements for '<S1>/Runnable_0':
 *  1. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_113.01 ;
 *  2. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_114.01 ;
 *  3. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_116.01 ;
 *  4. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_115.01 ;
 *  5. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_117.01 ;
 *  6. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_118.01 ;
 *  7. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_144.01 ;
 *  8. SubSystem "Runnable_0" !Trace_To : VEMS_R_11 _04434_136.02 ;
 *
 * Inherited requirements for '<S1>/Runnable_1':
 *  1. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_083.01 ;
 *  2. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_082.01 ;
 *  3. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_081.01 ;
 *  4. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_087.01 ;
 *  5. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_080.01 ;
 *  6. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_084.01 ;
 *  7. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_086.01 ;
 *  8. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_145.01 ;
 *  9. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_146.01 ;
 *  10. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_147.01 ;
 *  11. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_148.01 ;
 *  12. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_159.01 ;
 *  13. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_149.01 ;
 *  14. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_160.01 ;
 *  15. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_150.01 ;
 *  16. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_151.01 ;
 *  17. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_152.01 ;
 *  18. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_153.01 ;
 *  19. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_154.01 ;
 *  20. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_155.01 ;
 *  21. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_075.01 ;
 *  22. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_126.02 ;
 *  23. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_125.02 ;
 *  24. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_124.02 ;
 *  25. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_119.02 ;
 *  26. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_122.02 ;
 *  27. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_123.02 ;
 *  28. SubSystem "Runnable_1" !Trace_To : VEMS_R_11 _04434_140.02 ;
 *
 * Inherited requirements for '<S1>/Runnable_2':
 *  1. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_157.01 ;
 *  2. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_158.01 ;
 *  3. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_085.01 ;
 *  4. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_156.01 ;
 *  5. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_083.01 ;
 *  6. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_082.01 ;
 *  7. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_081.01 ;
 *  8. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_087.01 ;
 *  9. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_080.01 ;
 *  10. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_084.01 ;
 *  11. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_086.01 ;
 *  12. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_075.01 ;
 *  13. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_145.01 ;
 *  14. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_146.01 ;
 *  15. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_147.01 ;
 *  16. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_148.01 ;
 *  17. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_159.01 ;
 *  18. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_149.01 ;
 *  19. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_160.01 ;
 *  20. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_150.01 ;
 *  21. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_151.01 ;
 *  22. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_152.01 ;
 *  23. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_153.01 ;
 *  24. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_154.01 ;
 *  25. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_120.01 ;
 *  26. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_121.01 ;
 *  27. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_155.01 ;
 *  28. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_156.01 ;
 *  29. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_123.02 ;
 *  30. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_122.02 ;
 *  31. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_119.02 ;
 *  32. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_124.02 ;
 *  33. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_125.02 ;
 *  34. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_126.02 ;
 *  35. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_139.02 ;
 *  36. SubSystem "Runnable_2" !Trace_To : VEMS_R_11 _04434_135.02 ;
 *
 * Inherited requirements for '<S1>/Runnable_3':
 *  1. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_112.01 ;
 *  2. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_144.01 ;
 *  3. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_111.01 ;
 *  4. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_110.01 ;
 *  5. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_137.02 ;
 *  6. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_131.02 ;
 *  7. SubSystem "Runnable_3" !Trace_To : VEMS_R_11 _04434_130.02 ;
 *
 * Inherited requirements for '<S1>/Runnable_4':
 *  1. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_157.01 ;
 *  2. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_158.01 ;
 *  3. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_085.01 ;
 *  4. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_156.01 ;
 *  5. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_093.01 ;
 *  6. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_099.01 ;
 *  7. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_100.01 ;
 *  8. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_072.01 ;
 *  9. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_073.01 ;
 *  10. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_071.01 ;
 *  11. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_123.02 ;
 *  12. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_122.02 ;
 *  13. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_119.02 ;
 *  14. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_124.02 ;
 *  15. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_120.01 ;
 *  16. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_121.01 ;
 *  17. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_108.01 ;
 *  18. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_144.01 ;
 *  19. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_103.01 ;
 *  20. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_096.02 ;
 *  21. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_102.01 ;
 *  22. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_104.01 ;
 *  23. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_106.01 ;
 *  24. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_105.01 ;
 *  25. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_107.01 ;
 *  26. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_094.01 ;
 *  27. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_095.01 ;
 *  28. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_109.01 ;
 *  29. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_125.02 ;
 *  30. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_089.02 ;
 *  31. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_090.01 ;
 *  32. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_091.01 ;
 *  33. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_092.01 ;
 *  34. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_126.02 ;
 *  35. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_088.01 ;
 *  36. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_101.01 ;
 *  37. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_075.01 ;
 *  38. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_110.01 ;
 *  39. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_111.01 ;
 *  40. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_118.01 ;
 *  41. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_117.01 ;
 *  42. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_115.01 ;
 *  43. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_116.01 ;
 *  44. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_114.01 ;
 *  45. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_113.01 ;
 *  46. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_156.01 ;
 *  47. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_155.01 ;
 *  48. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_121.01 ;
 *  49. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_158.01 ;
 *  50. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_157.01 ;
 *  51. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_120.01 ;
 *  52. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_138.02 ;
 *  53. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_128.02 ;
 *  54. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_129.02 ;
 *  55. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_130.02 ;
 *  56. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_133.02 ;
 *  57. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_134.02 ;
 *  58. SubSystem "Runnable_4" !Trace_To : VEMS_R_11 _04434_135.02 ;

 */
#endif                                 /* RTW_HEADER_AFAMgtT_h_ */

/*-------------------------------- end of file -------------------------------*/
