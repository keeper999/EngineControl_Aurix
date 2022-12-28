/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU component.                                     */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !File            : DCM_CONFIG_IM.H                                         */
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
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   $*/
/******************************************************************************/
/* FICHIER GENERE AUTOMATIQUEMENT PAR L'OUTIL ImHeaderFactory 1.00            */
/* génére le jeudi 24 mars 2011 a 09:55:31                                   */
/******************************************************************************/
#ifndef DCM_CONFIG_IM_H
#define DCM_CONFIG_IM_H


#include "ACCPACQPOS.H"
#include "ACCPFRM.H"
#include "ACCPLRNPOS.H"
#include "ACPRESACQ.H"
#include "ACQAIRT.H"
#include "ACQCOT.h"
#include "AIREXTPRESACQ.H"
#include "BLOWBYCMD.H"
#include "CLUPEDFREQACQ.H"
#include "CLUPEDPOSNDIAG.H"
#include "COFANACTEST.H"
#include "COFANCMDDIAG.H"
#include "CRSCTLBSITREAT.H"
#include "CSTRMGR.H"
#include "CTRLCFG.H"
#include "DCM.H"
#include "DCM_MANU.H"
#include "DMPVLVOPLCMD.H"
#include "DSO2SEN.H"
#include "ENGSTRTSTOP.H"
#include "FLOWMNG.H"
#include "FRM.H"
#include "FTPCTL.H"
#include "FULVL.H"
#include "GDEXTINT.H"
#include "GDFRM.H"
#include "GDGAR.H"
#include "HEATSENO2DSCMD.H"
#include "HEATSENO2USCMD.H"
#include "IFAIRSYSIGSYS.H"
#include "IGARB.H"
#include "INJCTL_INJFARCTLMGR.H"
#include "INJFARCTLDSCTL.H"
#include "INMNFPRESACQ.H"
#include "ISFHCAN.H"
#include "IUPRRATIO.H"
#include "KNKACQ.H"
#include "KNKACQFILT.H"
#include "KNKADPCOR.H"
#include "KNKDET.H"
#include "MISFDFTLRN.H"
#include "MUXDIAGON.H"
#include "NEUTPOSNACQ.H"
#include "NOPROD.H"
#include "NVMSRV.H"
#include "OBDSRV.H"
#include "OBDSRV06.H"
#include "OFSVLV.H"
#include "OILLVLACQ.H"
#include "OILPRESACQ.H"
#include "OILPROPPRESACQ.H"
#include "PFUACQ.H"
#include "POSTEQUSRV.H"
#include "PWRLMRK.H"
#include "PWRSEN_ACQ.H"
#include "RC01.H"
#include "REFIDETA.H"
#include "RLYPWR.H"
#include "RND.H"
#include "RSTSRV.h"
#include "SAIMMO.H"
#include "SECUR.H"
#include "SFTYMGTIFTQ.H"
#include "SFTYMNGR.H"
#include "SPYEMSTT.H"
#include "SPYSTT.H"
#include "SRVACTESTMNG.H"
#include "STRTLOCKACQ.H"
#include "SUPSRV.H"
#include "SWFAIL.H"
#include "TELECODAGE.H"
#include "THRSFTYCPUIFINH.H"
#include "THRSTOPCLCN.H"
#include "TUNCFG.H"
#include "UPLSACQ.H"
#include "VLVACTEXACQ.H"
#include "VLVACTEXCMD.H"
#include "VLVACTEXENDSTOP.H"
#include "VLVACTEXIF.H"
#include "VLVACTINACQ.H"
#include "VLVACTINCMD.H"
#include "VLVACTINENDSTOP.H"
#include "VLVACTINIF.H"
#include "VLVEXSPMGT.H"
#include "VLVINSPMGT.H"


/* VEMS V02 ECU#059239 */
// #include "MonEngStrt.h"
extern VAR(UInt16, MONENGSTRT_VAR) EngSt_tiDlySync;

// #include "tifusp.h"
extern VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH1ReqCyl[6];

// #include "hppmpmdl.h"
extern CONST(UInt16, HPPMPMDL_CALIB) PFuCtl_agWdPmpCmdMax_C;
extern VAR(UInt16, HPPMPMDL_VAR) PFuCtl_agWdPmpCmdReq;

// #include "pfusp.h"
extern VAR(UInt16, PFUSP_VAR) InjSys_pFuSp;

// #include "ISCAN.h"
extern uint8 ISCAN_u8N2F4F2P429;

/* evenement EveTele in OS, produce by DCM_MANU */
#define DCM_MANU_SrvEveTele()\
{\
   Srv_EveTele_TeleSrv();\
   Cf_EveTele_TunCfg();\
   Cf_EveTele_TunCfgIf();\
   Cf_EveTele_TunCfg_FlowMng();\
}

/* evenement EveErrTeleWr in OS, produce by DCM_MANU */
#define DCM_MANU_EveErrTeleWr()\
{\
   Srv_EveErrTeleWr_TeleSrv();\
}

/* evenement EveErrPosEquWr in OS, produce by DCM_MANU */
#define DCM_MANU_EveErrPostEquWr()\
{\
   Srv_EveErrPostEquWr_PostEquSrv();\
}

/* evenement Srv_EveSa in OS */
#define DCM_MANU_SrvEveSa()\
{\
   Srv_EveSa_TeleSrv();\
   Srv_EveSa_PostEquSrv();\
}

/* evenement EveErrPosEquWr in OS, produce by DCM_MANU */
#define DCM_MANU_SrvEvePostEquWrt()\
{\
   Srv_EvePostEqu_PostEquSrv();\
}

/* evenement EveRstThr in OS, produce by DCM_MANU */
#define DCM_MANU_EveRstThr_SrvRc()\
{\
   Thr_EveRstThr_stopClcn();\
   Thr_EveRstThr_MngServo();\
}

/* evenement EveRstVVT in OS, produce by DCM_MANU */
#define DCM_MANU_EveRstVVT_SrvRc()\
{\
   VlvAct_EveRstVVT_InEndStop();\
   VlvAct_EveRstVVT_ExEndStop();\
}

/* evenement EveRstPed in OS, produce by DCM_MANU */
#define DCM_MANU_AccP_EveRstPed()\
{\
   AccP_EveRstPed_FLrng();\
}

/* evènement EveRstMisf is OS */
#define DCM_MANU_EveRstLrn_MisfDftLrn()\
{\
   Misf_EveRstLrn_MisfDftLrn();\
}

/* patch pb outils T4 : déclaration de DCM_MANU_u8inhib ds IFRTE et DCM_Manu */
#include "IFRTE_L.h"

/* redirection */
#define DCM_MANU_EveInhBoostGDI_SrvRc()\
{\
}

#define DCM_MANU_EveAcvBoostGDI_SrvRc()\
{\
}



#endif /* DCM_CONFIG_IM_H */
/* Fin de generation de code automatique */

