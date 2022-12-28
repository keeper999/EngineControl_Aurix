/***************************************************************************
;**
;** FILE NAME      : IFRTE.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "Rte_Type.h"
#include "IFRTE.H"
#include "IFRTE_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

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
const uint8  ACCMD_u8Inhib = 0;
const uint8  ADVCORDT_u8Inhib = 0;
const uint8  ADVMAXT_u8Inhib = 0;
const uint8  ADVMINT_u8Inhib = 0;
const uint8  ADVOPTMT_u8Inhib = 0;
const uint8  ADVPREVKNKT_u8Inhib = 0;
const uint8  ADVSPT_u8Inhib = 0;
const uint8  AFAMGTT_u8Inhib = 0;
const uint8  AFAT_u8Inhib = 0;
const uint8  AIRSYSAIR_u8Inhib = 0;
const uint8  AIRSYSTRB_u8Inhib = 0;
const uint8  ASE_u8Inhib = 0;
const uint8  CatAcvDiagT_u8Inhib = 0;
const uint8  CatPasDiagT_u8Inhib = 0;
const uint8  COCLLASL_u8Inhib = 0;
const uint8  COEMSTT_u8Inhib = 0;
const uint8  COGBX_u8Inhib = 0;
const uint8  COSTOPSTART_u8Inhib = 0;
const uint8  COTQ_u8Inhib = 0;
const uint8  CURDRIVFIL_u8Inhib = 0;
const uint8  DCM_MANU_u8Inhib = 0;
const uint8  DCM_u8Inhib = 0;
const uint8  DFWCTL_u8Inhib = 0;
const uint8  DMPVLV_H_u8Inhib = 0;
const uint8  EBSTUB_u8Inhib = 0;
const uint8  ENGLIM_u8Inhib = 0;
const uint8  ENGLIMTQT_u8Inhib = 0;
const uint8  ENGMGSLLIM_u8Inhib = 0;
const uint8  ENGMGSLT_u8Inhib = 0;
const uint8  EOMGSL_u8Inhib = 0;
const uint8  EXMGSLT1_u8Inhib = 0;
const uint8  EXMGSLT2_u8Inhib = 0;
const uint8  FARSP_u8Inhib = 0;
const uint8  FISA_u8Inhib = 0;
const uint8  GSI_u8Inhib = 0;
const uint8  INMDLT_u8Inhib = 0;
const uint8  INTHMDLT_u8Inhib = 0;
const uint8  MPM_u8Inhib = 0;
const uint8  OILSYS_u8Inhib = 0;
const uint8  PFILFAST_u8Inhib = 0;
const uint8  PFILSLOW_u8Inhib = 0;
const uint8  PNMACT_u8Inhib = 0;
const uint8  PRODELEM_u8Inhib = 0;
const uint8  PRODELENG_u8Inhib = 0;
const uint8  RCD_u8Inhib = 0;
const uint8  STOPSTRTEM_u8Inhib = 0;
const uint8  STOPSTRTENG_u8Inhib = 0;
const uint8  THMGT_u8Inhib = 0;
const uint8  THRSPT_u8Inhib = 0;
const uint8  TPM_u8Inhib = 0;
const uint8  TQADPCMP_u8Inhib = 0;
const uint8  TQDEM_u8Inhib = 0;
const uint8  TQEM_u8Inhib = 0;
const uint8  TQTREAT_u8Inhib = 0;
const uint8  TRABVX_u8Inhib = 0;
const uint8  TRBACTGSL_u8Inhib = 0;
const uint8  TRBACTMGT_u8Inhib = 0;
const uint8  TRBACTSYS_u8Inhib = 0;
const uint8  USTHRMT_u8Inhib = 0;
const uint8  VSCO_u8Inhib = 0;
const uint8  VSINFO_u8Inhib = 0;
const uint8  VSLIM_u8Inhib = 0;
const uint8  VSMAX_u8Inhib = 0;
const uint8  VSREG_u8Inhib = 0;
const uint8  VSSP_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
boolean AFAMgt_bDgoObsAdp;
boolean AFAMgt_bMonRunObsAdp;
boolean AFAT_bDgoAFA_AdpArEffEGRVlvLim;
boolean AFAT_bDgoAFA_AdpArEffThrOfs1Lim;
boolean AFAT_bDgoAFA_AdpArEffThrOfs2Lim;
boolean AFAT_bDgoAFA_AdpArEffThrOfs3Lim;
boolean AFAT_bDgoAFA_AdpArEffThrOfsLim;
boolean AFAT_bDgoAFA_AdpClsExOfsLim;
boolean AFAT_bDgoAFA_AdpInjOfsLim;
boolean AFAT_bDgoAFA_AdpIvsInjConLim;
boolean AFAT_bDgoAFA_AdpOpInOfsLim;
boolean AFAT_bDgoAFA_AdpSlopInjConLim;
boolean AFAT_bMonRunAFA_AdpArEffEGRVlvLim;
boolean AFAT_bMonRunAFA_AdpArEffThrOfs1Lim;
boolean AFAT_bMonRunAFA_AdpArEffThrOfs2Lim;
boolean AFAT_bMonRunAFA_AdpArEffThrOfs3Lim;
boolean AFAT_bMonRunAFA_AdpArEffThrOfsLim;
boolean AFAT_bMonRunAFA_AdpClsExOfsLim;
boolean AFAT_bMonRunAFA_AdpInjOfsLim;
boolean AFAT_bMonRunAFA_AdpIvsInjConLim;
boolean AFAT_bMonRunAFA_AdpOpInOfsLim;
boolean AFAT_bMonRunAFA_AdpSlopInjConLim;
boolean BatMgt_bDgo_iBattMaxCkg;
boolean BatMgt_bDgo_iBattMes;
boolean BatMgt_bDgo_rBattSoC;
boolean BatMgt_bDgo_resBattIt;
boolean BatMgt_bDgo_tBattMes;
boolean BatMgt_bDgo_uBattMes;
boolean BatMgt_bDgo_uBattMinCkg;
boolean BatMgt_bDgo_uBattOc;
boolean BatMgt_bDgo_uBattRstrt;
boolean BatMgt_bDgo_uBattStrt;
boolean BatMgt_bMonRun_iBattMaxCkg;
boolean BatMgt_bMonRun_iBattMes;
boolean BatMgt_bMonRun_rBattSoC;
boolean BatMgt_bMonRun_resBattIt;
boolean BatMgt_bMonRun_tBattMes;
boolean BatMgt_bMonRun_uBattMes;
boolean BatMgt_bMonRun_uBattMinCkg;
boolean BatMgt_bMonRun_uBattOc;
boolean BatMgt_bMonRun_uBattRstrt;
boolean BatMgt_bMonRun_uBattStrt;
boolean CatMon_bDgoORng_Cat;
boolean CatMon_bDgoORng_CatApv;
boolean CatMon_bMonRunORng_Cat;
boolean CatMon_bMonRunORng_CatApv;
boolean CoOptmEl_bDgoTqAlt;
boolean CoOptmEl_bMonRunTqAlt;
boolean CoPTSt_bDgoORngMplReq;
boolean CoPTSt_bMonRunORngMplReq;
boolean CoPtUH_bDgoBlt;
boolean CoPtUH_bDgoCutReq;
boolean CoPtUH_bDgoLgEngRStrtInh;
boolean CoPtUH_bDgoORngGcClu;
boolean CoPtUH_bDgoORngGcMinClu;
boolean CoPtUH_bDgoORngGcNeut;
boolean CoPtUH_bDgoORngGearEnaClu;
boolean CoPtUH_bDgoORngGearMinClu;
boolean CoPtUH_bDgoORngGearNeut;
boolean CoPtUH_bMonRunBlt;
boolean CoPtUH_bMonRunCutReq;
boolean CoPtUH_bMonRunLgEngRStrtInh;
boolean CoPtUH_bMonRunORngGcClu;
boolean CoPtUH_bMonRunORngGcMinClu;
boolean CoPtUH_bMonRunORngGcNeut;
boolean CoPtUH_bMonRunORngGearEnaClu;
boolean CoPtUH_bMonRunORngGearMinClu;
boolean CoPtUH_bMonRunORngGearNeut;
boolean CoSTT_bDgoORngCutOffReq;
boolean CoSTT_bDgoORngStopReq;
boolean CoSTT_bMonRunORngCutOffReq;
boolean CoSTT_bMonRunORngStopReq;
boolean DfwCtl_bDgoProtAdp;
boolean DfwCtl_bMonRunProtAdp;
boolean ElProdMgt_bDgoCorLoss;
boolean ElProdMgt_bDgoCorSpCur;
boolean ElProdMgt_bMonRunCorLoss;
boolean ElProdMgt_bMonRunCorSpCur;
boolean OilSys_bDgoDftOnOffHi;
boolean OilSys_bDgoDftOnOffLo;
boolean OilSys_bDgoDftOscCfm;
boolean OilSys_bDgoDftRegHi;
boolean OilSys_bDgoDftRegHiCfm;
boolean OilSys_bDgoDftRegLo;
boolean OilSys_bDgoDftRegLoCfm;
boolean OilSys_bDgoPresMesFrz;
boolean OilSys_bDgoPresToHi;
boolean OilSys_bDgoPresToLo;
boolean OilSys_bMonRunDftOnOffHi;
boolean OilSys_bMonRunDftOnOffLo;
boolean OilSys_bMonRunDftOscCfm;
boolean OilSys_bMonRunDftRegHi;
boolean OilSys_bMonRunDftRegHiCfm;
boolean OilSys_bMonRunDftRegLo;
boolean OilSys_bMonRunDftRegLoCfm;
boolean OilSys_bMonRunPresMesFrz;
boolean OilSys_bMonRunPresToHi;
boolean OilSys_bMonRunPresToLo;
boolean StaStrtMgt_bDgoStaAcvThd1;
boolean StaStrtMgt_bDgoStaAcvThd2;
boolean StaStrtMgt_bDgoStaCmd;
boolean StaStrtMgt_bDgoStaCmdInfo;
boolean StaStrtMgt_bDgoStaElCmd;
boolean StaStrtMgt_bDgoStuckMec;
boolean StaStrtMgt_bMonRunStaAcvThd1;
boolean StaStrtMgt_bMonRunStaAcvThd2;
boolean StaStrtMgt_bMonRunStaCmd;
boolean StaStrtMgt_bMonRunStaCmdInfo;
boolean StaStrtMgt_bMonRunStaElCmd;
boolean StaStrtMgt_bMonRunStuckMec;
boolean ThMgt_bDgoAntiBoil;
boolean ThMgt_bDgoCoSysDfct;
boolean ThMgt_bDgoFSFBlockCls;
boolean ThMgt_bDgoFSFBlockOp;
boolean ThMgt_bDgoTCoBlock;
boolean ThMgt_bDgoTCoOverEstim;
boolean ThMgt_bDgoTCoSlowRise;
boolean ThMgt_bDgoTCoUndEstim;
boolean ThMgt_bDgoTCoWarn;
boolean ThMgt_bDgoThermoStuckCls;
boolean ThMgt_bDgoThermoStuckOp;
boolean ThMgt_bMonRunAntiBoil;
boolean ThMgt_bMonRunCoSysDfct;
boolean ThMgt_bMonRunFSFBlockCls;
boolean ThMgt_bMonRunFSFBlockOp;
boolean ThMgt_bMonRunTCoBlock;
boolean ThMgt_bMonRunTCoOverEstim;
boolean ThMgt_bMonRunTCoSlowRise;
boolean ThMgt_bMonRunTCoUndEstim;
boolean ThMgt_bMonRunTCoWarn;
boolean ThMgt_bMonRunThermoStuckCls;
boolean ThMgt_bMonRunThermoStuckOp;
boolean TqAdp_bDgoORngHiDragRed;
boolean TqAdp_bDgoORngHiNeut;
boolean TqAdp_bDgoORngLoDragRed;
boolean TqAdp_bDgoORngLoNeut;
boolean TqAdp_bMonRunORngHiDragRed;
boolean TqAdp_bMonRunORngHiNeut;
boolean TqAdp_bMonRunORngLoDragRed;
boolean TqAdp_bMonRunORngLoNeut;
boolean TqCmp_bDgotqAltRv;
boolean TqCmp_bMonRuntqAltRv;
boolean TrbAct_bDgoArDeltaCorLim;
boolean TrbAct_bMonRunArDeltaCorLim;
boolean UCE_bDgoMainWkuDisrd;
boolean UCE_bDgoMainWkuIncst;
boolean UCE_bDgoRCDLineScg;
boolean UCE_bMonRunMainWkuDisrd;
boolean UCE_bMonRunMainWkuIncst;
boolean UCE_bMonRunRCDLineScg;
boolean VSCtl_bDgoRatConvTraClc;
boolean VSCtl_bDgoSpdVehClc;
boolean VSCtl_bDgoVSLim;
boolean VSCtl_bDgoVSLimBody;
boolean VSCtl_bDgoVSMax;
boolean VSCtl_bDgoVSMaxp;
boolean VSCtl_bDgoVSReg;
boolean VSCtl_bDgoVSRegBody;
boolean VSCtl_bDgoVSRegVeh;
boolean VSCtl_bMonRunRatConvTraClc;
boolean VSCtl_bMonRunSpdVehClc;
boolean VSCtl_bMonRunVSLim;
boolean VSCtl_bMonRunVSLimBody;
boolean VSCtl_bMonRunVSMax;
boolean VSCtl_bMonRunVSMaxp;
boolean VSCtl_bMonRunVSReg;
boolean VSCtl_bMonRunVSRegBody;
boolean VSCtl_bMonRunVSRegVeh;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

