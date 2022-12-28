/***************************************************************************
;**
;** FILE NAME      : IFRTE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IFRTE_H
#define IFRTE_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "Rte_Type.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AFA_PRM_COVERRESTIM_COLS               ( 8 )
#define AIRSYS_PRM_MFAIRTHRREQ_COLS            ( 2 )
#define AIRSYS_PRM_PINMNFREQ_COLS              ( 2 )
#define ENGM_PRM_MAIRPREDINCYL_COLS            ( 6 )
#define ENGM_PRM_MAIRSCVCORCYL_COLS            ( 6 )
#define ENGM_PRM_MFAIRCORCYL_COLS              ( 6 )
#define ENGM_PRM_MFAIRPREDINCYL_COLS           ( 6 )
#define ENGM_PRM_MFAIRSCVCORCYL_COLS           ( 6 )
#define ENGM_PRM_MFTOTEXCORCYL_COLS            ( 6 )
#define ENGM_PRM_RAIRLDPREDINCYL_COLS          ( 6 )
#define ENGM_PRM_RTOTLDEXCORCYL_COLS           ( 6 )
#define EOM_PRM_FACBASMODCUR_COLS              ( 16 )
#define EOM_PRM_FACBASMODTAR_COLS              ( 16 )
#define EOM_PRM_FACTRANMOD_COLS                ( 16 )
#define EOM_PRM_IDXBAS1MODCUR_COLS             ( 16 )
#define EOM_PRM_IDXBAS1MODTAR_COLS             ( 16 )
#define EOM_PRM_IDXBAS2MODCUR_COLS             ( 16 )
#define EOM_PRM_IDXBAS2MODTAR_COLS             ( 16 )
#define EXM_PRM_FACFLEX_COLS                   ( 5 )
#define EXM_PRM_FACGAS_COLS                    ( 5 )
#define EXM_PRM_PEG_COLS                       ( 12 )
#define EXM_PRM_PEGFLT_COLS                    ( 12 )
#define EXM_PRM_PEXMNFESTIMOVLPCYL_COLS        ( 6 )
#define EXM_PRM_TEG_COLS                       ( 12 )
#define EXM_PRM_TEGFLT_COLS                    ( 12 )
#define EXM_PRM_TEXMNFESTIMCYL_COLS            ( 6 )
#define EXM_PRM_TWALL_COLS                     ( 12 )
#define FARSP_PRM_BRLAMSPACV_COLS              ( 20 )
#define FARSP_PRM_RMIXTCYLSP_COLS              ( 6 )
#define IGSYS_PRM_AGIGLIMKNK_COLS              ( 6 )
#define IGSYS_PRM_AGIGMAXWIPREVADPCYL_COLS     ( 6 )
#define IGSYS_PRM_AGIGSPCYL_COLS               ( 6 )
#define IGSYS_PRM_FACFLEX_COLS                 ( 10 )
#define INM_PRM_CONCAIRPREDCYL_COLS            ( 6 )
#define INM_PRM_CONCFUPREDCYL_COLS             ( 6 )
#define INM_PRM_PDSTHRPREDCYL_COLS             ( 6 )
#define INM_PRM_PDSTHRPREDOVLPCYL_COLS         ( 6 )
#define TQDEM_TQEFCNREGTAKEOFFECO_COLS         ( 2 )
#define TQDEM_TQEFCNREGTAKEOFFNORM_COLS        ( 2 )
#define TQSYS_PRM_AOSCONF3_COLS                ( 6 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean AFAMgt_bDgoObsAdp;
extern boolean AFAMgt_bMonRunObsAdp;
extern boolean AFAT_bDgoAFA_AdpArEffEGRVlvLim;
extern boolean AFAT_bDgoAFA_AdpArEffThrOfs1Lim;
extern boolean AFAT_bDgoAFA_AdpArEffThrOfs2Lim;
extern boolean AFAT_bDgoAFA_AdpArEffThrOfs3Lim;
extern boolean AFAT_bDgoAFA_AdpArEffThrOfsLim;
extern boolean AFAT_bDgoAFA_AdpClsExOfsLim;
extern boolean AFAT_bDgoAFA_AdpInjOfsLim;
extern boolean AFAT_bDgoAFA_AdpIvsInjConLim;
extern boolean AFAT_bDgoAFA_AdpOpInOfsLim;
extern boolean AFAT_bDgoAFA_AdpSlopInjConLim;
extern boolean AFAT_bMonRunAFA_AdpArEffEGRVlvLim;
extern boolean AFAT_bMonRunAFA_AdpArEffThrOfs1Lim;
extern boolean AFAT_bMonRunAFA_AdpArEffThrOfs2Lim;
extern boolean AFAT_bMonRunAFA_AdpArEffThrOfs3Lim;
extern boolean AFAT_bMonRunAFA_AdpArEffThrOfsLim;
extern boolean AFAT_bMonRunAFA_AdpClsExOfsLim;
extern boolean AFAT_bMonRunAFA_AdpInjOfsLim;
extern boolean AFAT_bMonRunAFA_AdpIvsInjConLim;
extern boolean AFAT_bMonRunAFA_AdpOpInOfsLim;
extern boolean AFAT_bMonRunAFA_AdpSlopInjConLim;
extern boolean BatMgt_bDgo_iBattMaxCkg;
extern boolean BatMgt_bDgo_iBattMes;
extern boolean BatMgt_bDgo_rBattSoC;
extern boolean BatMgt_bDgo_resBattIt;
extern boolean BatMgt_bDgo_tBattMes;
extern boolean BatMgt_bDgo_uBattMes;
extern boolean BatMgt_bDgo_uBattMinCkg;
extern boolean BatMgt_bDgo_uBattOc;
extern boolean BatMgt_bDgo_uBattRstrt;
extern boolean BatMgt_bDgo_uBattStrt;
extern boolean BatMgt_bMonRun_iBattMaxCkg;
extern boolean BatMgt_bMonRun_iBattMes;
extern boolean BatMgt_bMonRun_rBattSoC;
extern boolean BatMgt_bMonRun_resBattIt;
extern boolean BatMgt_bMonRun_tBattMes;
extern boolean BatMgt_bMonRun_uBattMes;
extern boolean BatMgt_bMonRun_uBattMinCkg;
extern boolean BatMgt_bMonRun_uBattOc;
extern boolean BatMgt_bMonRun_uBattRstrt;
extern boolean BatMgt_bMonRun_uBattStrt;
extern boolean CatMon_bDgoORng_Cat;
extern boolean CatMon_bDgoORng_CatApv;
extern boolean CatMon_bMonRunORng_Cat;
extern boolean CatMon_bMonRunORng_CatApv;
extern boolean CoOptmEl_bDgoTqAlt;
extern boolean CoOptmEl_bMonRunTqAlt;
extern boolean CoPTSt_bDgoORngMplReq;
extern boolean CoPTSt_bMonRunORngMplReq;
extern boolean CoPtUH_bDgoBlt;
extern boolean CoPtUH_bDgoCutReq;
extern boolean CoPtUH_bDgoLgEngRStrtInh;
extern boolean CoPtUH_bDgoORngGcClu;
extern boolean CoPtUH_bDgoORngGcMinClu;
extern boolean CoPtUH_bDgoORngGcNeut;
extern boolean CoPtUH_bDgoORngGearEnaClu;
extern boolean CoPtUH_bDgoORngGearMinClu;
extern boolean CoPtUH_bDgoORngGearNeut;
extern boolean CoPtUH_bMonRunBlt;
extern boolean CoPtUH_bMonRunCutReq;
extern boolean CoPtUH_bMonRunLgEngRStrtInh;
extern boolean CoPtUH_bMonRunORngGcClu;
extern boolean CoPtUH_bMonRunORngGcMinClu;
extern boolean CoPtUH_bMonRunORngGcNeut;
extern boolean CoPtUH_bMonRunORngGearEnaClu;
extern boolean CoPtUH_bMonRunORngGearMinClu;
extern boolean CoPtUH_bMonRunORngGearNeut;
extern boolean CoSTT_bDgoORngCutOffReq;
extern boolean CoSTT_bDgoORngStopReq;
extern boolean CoSTT_bMonRunORngCutOffReq;
extern boolean CoSTT_bMonRunORngStopReq;
extern boolean DfwCtl_bDgoProtAdp;
extern boolean DfwCtl_bMonRunProtAdp;
extern boolean ElProdMgt_bDgoCorLoss;
extern boolean ElProdMgt_bDgoCorSpCur;
extern boolean ElProdMgt_bMonRunCorLoss;
extern boolean ElProdMgt_bMonRunCorSpCur;
extern boolean OilSys_bDgoDftOnOffHi;
extern boolean OilSys_bDgoDftOnOffLo;
extern boolean OilSys_bDgoDftOscCfm;
extern boolean OilSys_bDgoDftRegHi;
extern boolean OilSys_bDgoDftRegHiCfm;
extern boolean OilSys_bDgoDftRegLo;
extern boolean OilSys_bDgoDftRegLoCfm;
extern boolean OilSys_bDgoPresMesFrz;
extern boolean OilSys_bDgoPresToHi;
extern boolean OilSys_bDgoPresToLo;
extern boolean OilSys_bMonRunDftOnOffHi;
extern boolean OilSys_bMonRunDftOnOffLo;
extern boolean OilSys_bMonRunDftOscCfm;
extern boolean OilSys_bMonRunDftRegHi;
extern boolean OilSys_bMonRunDftRegHiCfm;
extern boolean OilSys_bMonRunDftRegLo;
extern boolean OilSys_bMonRunDftRegLoCfm;
extern boolean OilSys_bMonRunPresMesFrz;
extern boolean OilSys_bMonRunPresToHi;
extern boolean OilSys_bMonRunPresToLo;
extern boolean StaStrtMgt_bDgoStaAcvThd1;
extern boolean StaStrtMgt_bDgoStaAcvThd2;
extern boolean StaStrtMgt_bDgoStaCmd;
extern boolean StaStrtMgt_bDgoStaCmdInfo;
extern boolean StaStrtMgt_bDgoStaElCmd;
extern boolean StaStrtMgt_bDgoStuckMec;
extern boolean StaStrtMgt_bMonRunStaAcvThd1;
extern boolean StaStrtMgt_bMonRunStaAcvThd2;
extern boolean StaStrtMgt_bMonRunStaCmd;
extern boolean StaStrtMgt_bMonRunStaCmdInfo;
extern boolean StaStrtMgt_bMonRunStaElCmd;
extern boolean StaStrtMgt_bMonRunStuckMec;
extern boolean ThMgt_bDgoAntiBoil;
extern boolean ThMgt_bDgoCoSysDfct;
extern boolean ThMgt_bDgoFSFBlockCls;
extern boolean ThMgt_bDgoFSFBlockOp;
extern boolean ThMgt_bDgoTCoBlock;
extern boolean ThMgt_bDgoTCoOverEstim;
extern boolean ThMgt_bDgoTCoSlowRise;
extern boolean ThMgt_bDgoTCoUndEstim;
extern boolean ThMgt_bDgoTCoWarn;
extern boolean ThMgt_bDgoThermoStuckCls;
extern boolean ThMgt_bDgoThermoStuckOp;
extern boolean ThMgt_bMonRunAntiBoil;
extern boolean ThMgt_bMonRunCoSysDfct;
extern boolean ThMgt_bMonRunFSFBlockCls;
extern boolean ThMgt_bMonRunFSFBlockOp;
extern boolean ThMgt_bMonRunTCoBlock;
extern boolean ThMgt_bMonRunTCoOverEstim;
extern boolean ThMgt_bMonRunTCoSlowRise;
extern boolean ThMgt_bMonRunTCoUndEstim;
extern boolean ThMgt_bMonRunTCoWarn;
extern boolean ThMgt_bMonRunThermoStuckCls;
extern boolean ThMgt_bMonRunThermoStuckOp;
extern boolean TqAdp_bDgoORngHiDragRed;
extern boolean TqAdp_bDgoORngHiNeut;
extern boolean TqAdp_bDgoORngLoDragRed;
extern boolean TqAdp_bDgoORngLoNeut;
extern boolean TqAdp_bMonRunORngHiDragRed;
extern boolean TqAdp_bMonRunORngHiNeut;
extern boolean TqAdp_bMonRunORngLoDragRed;
extern boolean TqAdp_bMonRunORngLoNeut;
extern boolean TqCmp_bDgotqAltRv;
extern boolean TqCmp_bMonRuntqAltRv;
extern boolean TrbAct_bDgoArDeltaCorLim;
extern boolean TrbAct_bMonRunArDeltaCorLim;
extern boolean UCE_bDgoMainWkuDisrd;
extern boolean UCE_bDgoMainWkuIncst;
extern boolean UCE_bDgoRCDLineScg;
extern boolean UCE_bMonRunMainWkuDisrd;
extern boolean UCE_bMonRunMainWkuIncst;
extern boolean UCE_bMonRunRCDLineScg;
extern boolean VSCtl_bDgoRatConvTraClc;
extern boolean VSCtl_bDgoSpdVehClc;
extern boolean VSCtl_bDgoVSLim;
extern boolean VSCtl_bDgoVSLimBody;
extern boolean VSCtl_bDgoVSMax;
extern boolean VSCtl_bDgoVSMaxp;
extern boolean VSCtl_bDgoVSReg;
extern boolean VSCtl_bDgoVSRegBody;
extern boolean VSCtl_bDgoVSRegVeh;
extern boolean VSCtl_bMonRunRatConvTraClc;
extern boolean VSCtl_bMonRunSpdVehClc;
extern boolean VSCtl_bMonRunVSLim;
extern boolean VSCtl_bMonRunVSLimBody;
extern boolean VSCtl_bMonRunVSMax;
extern boolean VSCtl_bMonRunVSMaxp;
extern boolean VSCtl_bMonRunVSReg;
extern boolean VSCtl_bMonRunVSRegBody;
extern boolean VSCtl_bMonRunVSRegVeh;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void rte_MainFunction(void);
void rte_RE_ACCmd_001_MSE(void);
void rte_RE_ACCmd_002_TEV(void);
void rte_RE_ACCmd_003_DRE(void);
void rte_RE_ACCmd_004_TEV(void);
void rte_RE_AdvCordT_001_MSE(void);
void rte_RE_AdvCordT_002_DRE(void);
void rte_RE_AdvCordT_003_MSE(void);
void rte_RE_AdvCordT_005_DRE(void);
void rte_RE_AdvCordT_007_DRE(void);
void rte_RE_AdvMaxT_001_MSE(void);
void rte_RE_AdvMaxT_002_DRE(void);
void rte_RE_AdvMinT_001_MSE(void);
void rte_RE_AdvMinT_002_DRE(void);
void rte_RE_AdvMinT_005_MSE(void);
void rte_RE_AdvMinT_006_DRE(void);
void rte_RE_AdvMinT_008_DRE(void);
void rte_RE_AdvOptmT_001_MSE(void);
void rte_RE_AdvOptmT_002_DRE(void);
void rte_RE_AdvOptmT_003_DRE(void);
void rte_RE_AdvOptmT_004_MSE(void);
void rte_RE_AdvPrevKnkT_001_MSE(void);
void rte_RE_AdvPrevKnkT_002(void);
void rte_RE_AdvSpT_001_MSE(void);
void rte_RE_AdvSpT_002_DRE(void);
void rte_RE_AdvSpT_003_MSE(void);
void rte_RE_AdvSpT_004_DRE(void);
void rte_RE_AdvSpT_005_MSE(void);
void rte_RE_AdvSpT_006_DRE(void);
void rte_RE_AFAMgtT_001_MSE(void);
void rte_RE_AFAMgtT_002_MSE(void);
void rte_RE_AFAMgtT_003_TEV(void);
void rte_RE_AFAMgtT_004_MSE(void);
void rte_RE_AFAMgtT_007_TEV(void);
void rte_RE_AFAMgtT_AftrsInit(void);
void rte_RE_AFAMgtT_AftsNvm(void);
void rte_RE_AFAT_001_MSE(void);
void rte_RE_AFAT_002_MSE(void);
void rte_RE_AFAT_003_MSE(void);
void rte_RE_AFAT_004_TEV(void);
void rte_RE_AFAT_005_TEV(void);
void rte_RE_AFAT_006_TEV(void);
void rte_RE_AFAT_007_TEV(void);
void rte_RE_AirSysAir_001_MSE(void);
void rte_RE_AirSysAir_002_TEV(void);
void rte_RE_AirSysAir_003_TEV(void);
void rte_RE_AirSysAir_004_TEV(void);
void rte_RE_AirSysAir_005_TEV(void);
void rte_RE_AirSysAir_006_TEV(void);
void rte_RE_AirSysAir_007_TEV(void);
void rte_RE_AirSysTrb_001_MSE(void);
void rte_RE_AirSysTrb_002_TEV(void);
void rte_RE_AirSysTrb_003_TEV(void);
void rte_RE_AirSysTrb_004_TEV(void);
void rte_RE_AirSysTrb_005_TEV(void);
void rte_RE_ASE_001_MSE(void);
void rte_RE_ASE_002_TEV(void);
void rte_RE_ASE_003_MSE(void);
void rte_RE_ASE_004_TEV(void);
void rte_RE_ASE_005_MSE(void);
void rte_RE_ASE_006_TEV(void);
void rte_RE_ASE_007_MSE(void);
void rte_RE_ASE_008_TEV(void);
void rte_RE_ASE_009_MSE(void);
void rte_RE_ASE_010_TEV(void);
void rte_RE_ASE_011_MSE(void);
void rte_RE_ASE_012_TEV(void);
void rte_RE_CatMon_EveRst_CatAcvDiag(void);
void rte_RE_CatMon_EveRst_CatPasDiag(void);
void rte_RE_CatMon_SdlFast_CatAcvDiag(void);
void rte_RE_CatMon_SdlMid_CatAcvDiag(void);
void rte_RE_CatMon_SdlMid_CatPasDiag(void);
void rte_RE_CatMon_SdlSlow_CatAcvDiag(void);
void rte_RE_CoClLASl_001_MSE(void);
void rte_RE_CoEmSTT_001_MSE(void);
void rte_RE_CoEmSTT_002_TEV(void);
void rte_RE_CoGBx_001_MSE(void);
void rte_RE_CoStopStart_003_MSE(void);
void rte_RE_CoStopStart_004_TEV(void);
void rte_RE_CoStopStart_007_MSE(void);
void rte_RE_CoStopStart_008_TEV(void);
void rte_RE_CoStopStart_009_MSE(void);
void rte_RE_CoStopStart_010_TEV(void);
void rte_RE_CoStopStart_011_MSE(void);
void rte_RE_CoStopStart_012_TEV(void);
void rte_RE_CoStopStart_013_MSE(void);
void rte_RE_CoStopStart_014_TEV(void);
void rte_RE_CoStopStart_015_MSE(void);
void rte_RE_CoStopStart_016_TEV(void);
void rte_RE_CoStopStart_017_MSE(void);
void rte_RE_CoStopStart_018_TEV(void);
void rte_RE_CoStopStart_019_MSE(void);
void rte_RE_CoStopStart_020_TEV(void);
void rte_RE_CoStopStart_021_MSE(void);
void rte_RE_CoStopStart_022_TEV(void);
void rte_RE_CoStopStart_023_MSE(void);
void rte_RE_CoStopStart_024_TEV(void);
void rte_RE_CoStopStart_025_MSE(void);
void rte_RE_CoStopStart_026_TEV(void);
void rte_RE_CoStopStart_027_MSE(void);
void rte_RE_CoStopStart_028_TEV(void);
void rte_RE_CoStopStart_029_MSE(void);
void rte_RE_CoStopStart_030_TEV(void);
void rte_RE_CoStopStart_031_MSE(void);
void rte_RE_CoStopStart_032_TEV(void);
void rte_RE_CoTq_001_MSE(void);
void rte_RE_CoTq_002_TEV(void);
void rte_RE_CoTq_003_MSE(void);
void rte_RE_CoTq_004_TEV(void);
void rte_RE_CoTq_005_MSE(void);
void rte_RE_CoTq_006_TEV(void);
void rte_RE_CoTq_007_MSE(void);
void rte_RE_CoTq_008_TEV(void);
void rte_RE_CoTq_009_MSE(void);
void rte_RE_CoTq_010_TEV(void);
void rte_RE_CoTq_011_DRE(void);
void rte_RE_CurDrivFil_001_MSE(void);
void rte_RE_DCM_MANU_StubServiceAftS(void);
void rte_RE_DfwCtl_001_MSE(void);
void rte_RE_DfwCtl_002_TEV(void);
void rte_RE_DmpVlv_H_001_MSE(void);
void rte_RE_DmpVlv_H_002_TEV(void);
void rte_RE_EBStub_001_MSE(void);
void rte_RE_EngLim_001_MSE(void);
void rte_RE_EngLimTqT_001_MSE(void);
void rte_RE_EngLimTqT_002_DRE(void);
void rte_RE_EngLimTqT_003_MSE(void);
void rte_RE_EngLimTqT_004_DRE(void);
void rte_RE_EngLimTqT_005_MSE(void);
void rte_RE_EngLimTqT_006_DRE(void);
void rte_RE_EngLimTqT_007_MSE(void);
void rte_RE_EngLimTqT_008_DRE(void);
void rte_RE_EngLimTqT_009_MSE(void);
void rte_RE_EngLimTqT_010_TEV(void);
void rte_RE_EngLimTqT_011_MSE(void);
void rte_RE_EngLimTqT_012_DRE(void);
void rte_RE_EngLimTqT_013_MSE(void);
void rte_RE_EngLimTqT_014_DRE(void);
void rte_RE_EngMGslLim_001_MSE(void);
void rte_RE_EngMGslLim_002_TEV(void);
void rte_RE_EngMGslLim_003_TEV(void);
void rte_RE_EngMGslT_001_MSE(void);
void rte_RE_EngMGslT_002_TEV(void);
void rte_RE_EngMGslT_004_TEV(void);
void rte_RE_EngMGslT_008_TEV(void);
void rte_RE_EngMGslT_012_TEV(void);
void rte_RE_EngMGslT_018_TEV(void);
void rte_RE_EngMGslT_020_TEV(void);
void rte_RE_EngMGslT_022_TEV(void);
void rte_RE_EngMGslT_024_TEV(void);
void rte_RE_EngMGslT_026_TEV(void);
void rte_RE_EOMGsl_001_MSE(void);
void rte_RE_EOMGsl_002_TEV(void);
void rte_RE_EOMGsl_003_TEV(void);
void rte_RE_EOMGsl_004_TEV(void);
void rte_RE_ExMGslT1_002_TEV(void);
void rte_RE_ExMGslT1_003_TEV(void);
void rte_RE_ExMGslT1_004_MSE(void);
void rte_RE_ExMGslT1_005_MSE(void);
void rte_RE_ExMGslT2_001_MSE(void);
void rte_RE_ExMGslT2_006_TEV(void);
void rte_RE_ExMGslT2_007_TEV(void);
void rte_RE_FARSp_001_MSE(void);
void rte_RE_FARSp_002_TEV(void);
void rte_RE_FARSp_003_MSE(void);
void rte_RE_FARSp_004_TEV(void);
void rte_RE_FARSp_005_MSE(void);
void rte_RE_FARSp_006_TEV(void);
void rte_RE_FARSp_007_MSE(void);
void rte_RE_FARSp_008_TEV(void);
void rte_RE_FARSp_009_MSE(void);
void rte_RE_FARSp_010_TEV(void);
void rte_RE_FARSp_011_MSE(void);
void rte_RE_FARSp_012_TEV(void);
void rte_RE_FARSp_013_MSE(void);
void rte_RE_FARSp_014_TEV(void);
void rte_RE_FARSp_015_MSE(void);
void rte_RE_FARSp_016_TEV(void);
void rte_RE_FARSp_017_MSE(void);
void rte_RE_FARSp_018_TEV(void);
void rte_RE_FARSp_021_MSE(void);
void rte_RE_FARSp_022_TEV(void);
void rte_RE_FARSp_023_MSE(void);
void rte_RE_FARSp_024_TEV(void);
void rte_RE_FARSp_025_MSE(void);
void rte_RE_FARSp_026_TEV(void);
void rte_RE_FISA_CrankSync(void);
void rte_RE_FISA_init(void);
void rte_RE_GSI_001_MSE(void);
void rte_RE_GSI_002_TEV(void);
void rte_RE_InMdlT_001_MSE(void);
void rte_RE_InMdlT_002_TEV(void);
void rte_RE_InMdlT_004_TEV(void);
void rte_RE_InMdlT_006_TEV(void);
void rte_RE_InMdlT_008_TEV(void);
void rte_RE_InMdlT_010_TEV(void);
void rte_RE_InMdlT_012_TEV(void);
void rte_RE_InMdlT_013_DRE(void);
void rte_RE_InMdlT_014_TEV(void);
void rte_RE_InMdlT_015_DRE(void);
void rte_RE_InMdlT_016_TEV(void);
void rte_RE_InMdlT_018_TEV(void);
void rte_RE_InMdlT_020_TEV(void);
void rte_RE_InMdlT_022_TEV(void);
void rte_RE_InMdlT_024_DRE(void);
void rte_RE_InMdlT_026_TEV(void);
void rte_RE_InMdlT_027_TEV(void);
void rte_RE_InMdlT_028_TEV(void);
void rte_RE_InMdlT_029_TEV(void);
void rte_RE_InMdlT_031_TEV(void);
void rte_RE_InMdlT_032_TEV(void);
void rte_RE_InMdlT_033_TEV(void);
void rte_RE_InMdlT_034_TEV(void);
void rte_RE_InMdlT_035_MSE(void);
void rte_RE_InMdlT_036_MSE(void);
void rte_RE_InMdlT_037_MSE(void);
void rte_RE_InMdlT_037_TEV(void);
void rte_RE_InMdlT_038_MSE(void);
void rte_RE_InMdlT_039_MSE(void);
void rte_RE_InMdlT_040_MSE(void);
void rte_RE_InMdlT_041_MSE(void);
void rte_RE_InMdlT_042_MSE(void);
void rte_RE_InMdlT_043_MSE(void);
void rte_RE_InMdlT_044_MSE(void);
void rte_RE_InMdlT_045_MSE(void);
void rte_RE_InMdlT_046_MSE(void);
void rte_RE_InMdlT_047_MSE(void);
void rte_RE_InThMdlT_001_MSE(void);
void rte_RE_InThMdlT_002_TEV(void);
void rte_RE_InThMdlT_004_TEV(void);
void rte_RE_InThMdlT_005_TEV(void);
void rte_RE_InThMdlT_006_TEV(void);
void rte_RE_InThMdlT_007_TEV(void);
void rte_RE_InThMdlT_008_TEV(void);
void rte_RE_MPM_001_MSE(void);
void rte_RE_MPM_002_TEV(void);
void rte_RE_MPM_003_TEV(void);
void rte_RE_MPM_004_TEV(void);
void rte_RE_MPM_005_TEV(void);
void rte_RE_MPM_006_DRE(void);
void rte_RE_MPM_007_TEV(void);
void rte_RE_MPM_AftrsInit(void);
void rte_RE_MPM_AftsNvm(void);
void rte_RE_OilSys_001_MSE(void);
void rte_RE_OilSys_002_TEV(void);
void rte_RE_PFilFast_001_MSE(void);
void rte_RE_PFilSlow_008_MSE(void);
void rte_RE_PnmAct_001_MSE(void);
void rte_RE_PnmAct_002_TEV(void);
void rte_RE_ProdElEm_001_MSE(void);
void rte_RE_ProdElEm_002_TEV(void);
void rte_RE_ProdElEm_003_MSE(void);
void rte_RE_ProdElEm_004_TEV(void);
void rte_RE_ProdElEm_005_MSE(void);
void rte_RE_ProdElEm_006_TEV(void);
void rte_RE_ProdElEng_001_MSE(void);
void rte_RE_ProdElEng_002_TEV(void);
void rte_RE_ProdElEng_003_MSE(void);
void rte_RE_ProdElEng_004_TEV(void);
void rte_RE_ProdElEng_005_MSE(void);
void rte_RE_ProdElEng_006_TEV(void);
void rte_RE_ProdElEng_007_MSE(void);
void rte_RE_ProdElEng_008_TEV(void);
void rte_RE_ProdElEng_009_MSE(void);
void rte_RE_ProdElEng_010_TEV(void);
void rte_RE_ProdElEng_011_MSE(void);
void rte_RE_ProdElEng_012_TEV(void);
void rte_RE_ProdElEng_013_MSE(void);
void rte_RE_ProdElEng_014_TEV(void);
void rte_RE_ProdElEng_015_MSE(void);
void rte_RE_ProdElEng_016_TEV(void);
void rte_RE_RCD_001_MSE(void);
void rte_RE_RCD_002_TEV(void);
void rte_RE_StopStrtEm_001_MSE(void);
void rte_RE_StopStrtEm_002_TEV(void);
void rte_RE_StopStrtEm_003_MSE(void);
void rte_RE_StopStrtEm_004_TEV(void);
void rte_RE_StopStrtEm_005_MSE(void);
void rte_RE_StopStrtEm_006_TEV(void);
void rte_RE_StopStrtEng_003_MSE(void);
void rte_RE_StopStrtEng_004_TEV(void);
void rte_RE_StopStrtEng_005_MSE(void);
void rte_RE_StopStrtEng_006_TEV(void);
void rte_RE_StopStrtEng_007_MSE(void);
void rte_RE_StopStrtEng_008_TEV(void);
void rte_RE_StopStrtEng_009_MSE(void);
void rte_RE_StopStrtEng_010_TEV(void);
void rte_RE_StopStrtEng_011_MSE(void);
void rte_RE_StopStrtEng_012_TEV(void);
void rte_RE_StopStrtEng_013_MSE(void);
void rte_RE_StopStrtEng_014_TEV(void);
void rte_RE_StopStrtEng_015_MSE(void);
void rte_RE_StopStrtEng_016_TEV(void);
void rte_RE_StopStrtEng_017_MSE(void);
void rte_RE_StopStrtEng_018_TEV(void);
void rte_RE_StopStrtEng_019_MSE(void);
void rte_RE_StopStrtEng_020_TEV(void);
void rte_RE_StopStrtEng_021_MSE(void);
void rte_RE_StopStrtEng_022_TEV(void);
void rte_RE_StopStrtEng_023_MSE(void);
void rte_RE_StopStrtEng_024_TEV(void);
void rte_RE_ThMgt_001_MSE(void);
void rte_RE_ThMgt_002_TEV(void);
void rte_RE_ThMgt_003_TEV(void);
void rte_RE_ThMgt_004_TEV(void);
void rte_RE_ThrSpT_001_MSE(void);
void rte_RE_ThrSpT_002_TEV(void);
void rte_RE_ThrSpT_003_TEV(void);
void rte_RE_TPM_001_MSE(void);
void rte_RE_TPM_002_TEV(void);
void rte_RE_TPM_003_TEV(void);
void rte_RE_TPM_004_TEV(void);
void rte_RE_TPM_005_TEV(void);
void rte_RE_TPM_006_TEV(void);
void rte_RE_TPM_007_TEV(void);
void rte_RE_TPM_008_TEV(void);
void rte_RE_TPM_009_DRE(void);
void rte_RE_TqAdp_Sdl10ms_TqAdpLossClc(void);
void rte_RE_TqAdpCmp_001_MSE(void);
void rte_RE_TqDem_001_MSE(void);
void rte_RE_TqDem_002_TEV(void);
void rte_RE_TqDem_003_TEV(void);
void rte_RE_TqDem_004_TEV(void);
void rte_RE_TqDem_005_TEV(void);
void rte_RE_TqDem_006_TEV(void);
void rte_RE_TqDem_007_TEV(void);
void rte_RE_TqDem_008_TEV(void);
void rte_RE_TqEM_001_MSE(void);
void rte_RE_TqEM_002_TEV(void);
void rte_RE_TqEM_004_TEV(void);
void rte_RE_TqEM_006_DRE(void);
void rte_RE_TqSys_EveSync_AntiStallReg(void);
void rte_RE_TqSys_EveSync_AOS(void);
void rte_RE_TqSys_EveSync_CoPtAntiStall(void);
void rte_RE_TqSys_EveSync_CurCor(void);
void rte_RE_TqSys_EveSync_CurCord(void);
void rte_RE_TqSys_EveSync_CurDrivFil(void);
void rte_RE_TqSys_EveSync_CurStCalc(void);
void rte_RE_TqSys_EveSync_CutDyn(void);
void rte_RE_TqSys_EveSync_IdlCordLim(void);
void rte_RE_TqSys_EveSync_TqCll(void);
void rte_RE_TqSys_EveSync_TqClrCros(void);
void rte_RE_TqSys_EveSync_TqCordLim(void);
void rte_RE_TqSys_EveSync_Tra(void);
void rte_RE_TqSys_EveSync_VarAntiStall(void);
void rte_RE_TqSys_EveSyncFrame30D_Tra(void);
void rte_RE_TqSys_EveSyncFrame38D_Tra(void);
void rte_RE_TqSys_Sdl100ms_TqCmpTAir(void);
void rte_RE_TqSys_Sdl10ms_CluPCord(void);
void rte_RE_TqSys_Sdl10ms_CoCha(void);
void rte_RE_TqSys_Sdl10ms_CoChaTqSlow(void);
void rte_RE_TqSys_Sdl10ms_CoPtGearCord(void);
void rte_RE_TqSys_Sdl10ms_EfcAirFil(void);
void rte_RE_TqSys_Sdl10ms_EngLimStat(void);
void rte_RE_TqSys_Sdl10ms_IdlCordLim(void);
void rte_RE_TqSys_Sdl10ms_TqCmpAccCord(void);
void rte_RE_TqSys_Sdl10ms_TqCmpEngLoss(void);
void rte_RE_TqSys_Sdl10ms_TqCmpGlbCord(void);
void rte_RE_TqSys_Sdl10ms_TqCmpTqAC(void);
void rte_RE_TqSys_Sdl10ms_TqCmpTqAC3(void);
void rte_RE_TqSys_Sdl10ms_TqCmpTqAC4(void);
void rte_RE_TqSys_Sdl10ms_TqCmpTqAlt(void);
void rte_RE_TqSys_Sdl10ms_TqCmpTqCnv(void);
void rte_RE_TqSys_Sdl10ms_TqCmpTqStg(void);
void rte_RE_TqSys_Sdl10ms_TqCordLim(void);
void rte_RE_TqSys_Sdl10ms_tqEfcFil(void);
void rte_RE_TqSys_Sdl10ms_TqLimFwdRvs(void);
void rte_RE_TqSys_Sdl10ms_Tra(void);
void rte_RE_TqSys_Sdl20ms_Tra(void);
void rte_RE_TqTreat_001_MSE(void);
void rte_RE_TqTreat_002_TEV(void);
void rte_RE_TqTreat_003_MSE(void);
void rte_RE_TqTreat_004_TEV(void);
void rte_RE_TqTreat_005_MSE(void);
void rte_RE_TqTreat_006_DRE(void);
void rte_RE_TqTreat_007_MSE(void);
void rte_RE_TqTreat_008_DRE(void);
void rte_RE_TqTreat_009_MSE(void);
void rte_RE_TqTreat_010_TEV(void);
void rte_RE_TraBVx_001_MSE(void);
void rte_RE_TraBVx_016_DRE(void);
void rte_RE_TraBVx_018_DRE(void);
void rte_RE_TraBVx_020_DRE(void);
void rte_RE_TraBVx_028_TEV(void);
void rte_RE_TraBVx_030_TEV(void);
void rte_RE_TraBVx_032_TEV(void);
void rte_RE_TrbActGsl_001_MSE(void);
void rte_RE_TrbActGsl_002_TEV(void);
void rte_RE_TrbActGsl_003_TEV(void);
void rte_RE_TrbActGsl_004_TEV(void);
void rte_RE_TrbActMgt_001_MSE(void);
void rte_RE_TrbActMgt_002_TEV(void);
void rte_RE_TrbActMgt_003_TEV(void);
void rte_RE_TrbActSys_001_MSE(void);
void rte_RE_TrbActSys_002_TEV(void);
void rte_RE_TrbActSys_003_TEV(void);
void rte_RE_TrbActSys_004_TEV(void);
void rte_RE_TrbActSys_005_TEV(void);
void rte_RE_TrbActSys_AftrsInit(void);
void rte_RE_TrbActSys_AftsNvm(void);
void rte_RE_UsThrMT_001_MSE(void);
void rte_RE_UsThrMT_002_TEV(void);
void rte_RE_UsThrMT_004_MSE(void);
void rte_RE_UsThrMT_005_TEV(void);
void rte_RE_UsThrMT_006_TEV(void);
void rte_RE_UsThrMT_007_TEV(void);
void rte_RE_UsThrMT_008_DRE(void);
void rte_RE_UsThrMT_008_TEV(void);
void rte_RE_UsThrMT_009_DRE(void);
void rte_RE_UsThrMT_010_TEV(void);
void rte_RE_UsThrMT_011_TEV(void);
void rte_RE_UsThrMT_012_TEV(void);
void rte_RE_VSCo_001_MSE(void);
void rte_RE_VSCo_002_TEV(void);
void rte_RE_VSInfo_001_MSE(void);
void rte_RE_VSInfo_002_TEV(void);
void rte_RE_VSInfo_003_TEV(void);
void rte_RE_VSInfo_004_TEV(void);
void rte_RE_VSLim_001_MSE(void);
void rte_RE_VSLim_002_TEV(void);
void rte_RE_VSMax_001_MSE(void);
void rte_RE_VSMax_002_TEV(void);
void rte_RE_VSReg_001_MSE(void);
void rte_RE_VSReg_002_TEV(void);
void rte_RE_VSSp_001_MSE(void);
void rte_RE_VSSp_002_TEV(void);
void rte_RE_VSSp_003_TEV(void);
void rte_RE_VSSp_004_MSE(void);


#endif /* IFRTE_H */

/*-------------------------------- end of file -------------------------------*/
