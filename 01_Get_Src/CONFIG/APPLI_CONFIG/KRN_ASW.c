/******************************************************************************/
/* !Layer           : APPLI                                                   */
/* !Component       : KRN                                                     */
/* !Description     : Kernel Layer                                            */
/*                                                                            */
/* !File            : KRN_ASW.c                                               */
/* !Description     : Defines ASW macros directly called by the tasks         */
/*                                                                            */
/* !Reference       : PTS_DOC_XXXXXXX                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A93484.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

 /* Inclusion BSW */
#include "CCP.h"
#include "Os.h"
/* Inclusion BSW */

/* Inclusion ASW */
#include "ACCPACQPOS.h"
#include "ACCPCALCRPOS.h"
#include "ACCPEM.h"
#include "ACCPFRM.h"
#include "ACCPLRNPOS.h"
#include "ACCPMNGMODSECU.h"
#include "ACCPSTUCKDIAG.h"
#include "ACCPSWTACQDIAG.h"
#include "ACPRESACQ.h"
#include "ACQAIRT.h"
#include "ACQCLUPED.h"
#include "ACQCOT.h"
#include "ACQWKUSIG.h"
#include "ACTRTSTBLOWBY.h"
#include "ACTRTSTECT.h"
#include "ACTRTSTFARSP.h"
#include "ACTTSTFUPMP.h"
#include "ADDONADVMAX.h"
#include "ADDONADVMIN.h"
#include "ADDONADVOPTM.h"
#include "ADDONAGCOR.h"
#include "AGINJSP.h"
#include "AIREXTPRESACQ.h"
#include "AIRTFONCDIAG.h"
#include "AIRTHRARCRKSP.h"
#include "AIRTQEFF.h"
#include "AIRTQSTRUCTMNGT.h"
#include "ALDALTCOR.h"
#include "AUTHSTRTSTT.h"
#include "AVRMISFCNT.h"
#include "BATTVOLTACQ.h"
#include "BATTVOLTREQ.h"
#include "BICD.h"
#include "BLOWBYCMD.h"
#include "BRKASIACQ.h"
#include "BRKASIACT.h"
#include "BRKASIFONCDIAG.h"
#include "BRKPEDBVH2P.h"
#include "BUFNES.h"
#include "CANSECUCHKDATA.h"
#include "CATAGIESTIM.h"
#include "CATMONIF.h"
#include "CHAADVMINUNLIM.h"
#include "CHATQAIRCORD.h"
#include "CKMNGIF.h"
#include "CLCNFISAGAIN.h"
#include "CLUPEDFREQACQ.h"
#include "CLUPEDPOSNDIAG.h"
#include "CLUSWTDIAG.h"
#include "COES.h"
#include "COFANACTEST.h"
#include "COFANCMDDIAG.h"
#include "COHCAN.h"
#include "CONFIGLIN.h"
#include "COMSTMNG.H"
#include "COPTST.h"
#include "COSYNC.h"
#include "COTDIAG.h"
#include "CRC.h"
#include "CRSCTLBSITREAT.h"
#include "CRSCTLINTREATIF.h"
#include "CRSCTLOUTTREAT.h"
#include "CSTRACTEST.h"
#include "CSTRCMD.h"
#include "CSTRDYNLIM.h"
#include "CSTREFCRED.h"
#include "CSTRFUCONCESTIM.h"
#include "CSTRMGR.h"
#include "CTRLCFG.h"
#include "DFTLIMSGMGT.h"
#include "DFTMGT.h"
#include "DGOTEST.h"
#include "DIAGAIREXTPRES.h"
#include "DIAGBRKPED.h"
#include "DIAGBRKPEDNOBVH2P.h"
#include "DIAGMEMECU.h"
#include "DIAGSFTYLVL2.h"
#include "DRVRSENO2DS.h"
#include "DRVRSENO2US.h"
#include "DSO2SEN.h"
#include "ECTREQ.h"
#include "ECUMNG.h"
#include "EEPMNG.h"
#include "ENGIDLEINTERFACE.h"
#include "ENGLIMEFCCORD.h"
#include "ENGREQH.h"
#include "ENGRUNST.h"
#include "ENGSTAB.h"
#include "ENGSTOUTPIDC.h"
#include "ENGSTRTSTOP.h"
#include "facFuTran.h"
#include "FARSTRAMON.h"
#include "FAR_FARSPMGRONOFF.h"
#include "FFGEN.h"
#include "FHCANF305.h"
#include "FHCANF30D.h"
#include "FHCANF329.h"
#include "FHCANF349.h"
#include "FHCANF34D.h"
#include "FHCANF38D.h"
#include "FHCANF3AD.h"
#include "FHCANF3C9.h"
#include "FHCANF3CD.h"
#include "FHCANF412.h"
#include "FHCANF432.h"
#include "FHCANF44D.h"
#include "FHCANF489.h"
#include "FHCANF495.h"
#include "FHCANF4F2.h"
#include "FHCANF50D.h"
#include "FHCANF50E.h"
#include "FHCANF532.h"
#include "FHCANF552.h"
#include "FHCANF572.h"
#include "FHCANF57C.h"
#include "FHCANF592.h"
#include "FHCANF5B2.h"
#include "FHCANF612.h"
#include "FHCANF7F2.h"
#include "FISAINHMGR.h"
#include "FISARFUDET.h"
#include "FLOWMNG.h"
#include "FRM.h"
#include "FTPCTL.h"
#include "FUCNS.h"
#include "FULVL.h"
#include "FUPMPMNG.h"
#include "GDGAR.h"
#include "HEATSENO2DS.h"
#include "HEATSENO2DSCMD.h"
#include "HEATSENO2DSDERIDIAG.h"
#include "HEATSENO2DSFONCDIAG.h"
#include "HEATSENO2HOTDIAG.h"
#include "HEATSENO2UPFONCDIAG.h"
#include "HEATSENO2UPPERDDIAG.h"
#include "HEATSENO2US.h"
#include "HEATSENO2USCMD.h"
#include "HOTSENO2FLG.h"
#include "HRDRCVMNG.h"
#include "IDLCMDMOD.h"
#include "IDLCTRL.h"
#include "IDLMGR.h"
#include "IDLSYSCUTOFF.h"
#include "IFADV.h"
#include "IFAIRSYS.h"
#include "IFAIRSYSIGSYS.h"
#include "IFAUTHDFTSTT.h"
#include "IFCATMDLSYS.h"
#include "IFELECMOTESS.h"
#include "IFEOMINJSP.h"
#include "IFFAR.h"
#include "IFNENGCLC.h"
#include "IFTQSTRUCT_TQMON.h"
#include "IGARB.h"
#include "IGCMDMISFGENR.h"
#include "IGCOILACTEST.h"
#include "IGCOILMNG.h"
#include "IGCRK.h"
#include "IGEXTHERMOPROT.h"
#include "IGVOLTADJ.h"
#include "INAIRFLOWDIAG.h"
#include "INFOCRASH.h"
#include "INJASTWUPCMP.h"
#include "INJCTL_INJFARCTLMGR.h"
#include "INJCUTOFFMGR.h"
#include "INJFARCTLDSCTL.h"
#include "INJFARCTLUSCTL.h"
#include "INJRESUCMP.h"
#include "INJSPMGT.h"
#include "INJSYSMGRCRK.h"
#include "INJSYSSPCRK.h"
#include "INJTICOR.h"
#include "INJVOLTADJ.h"
#include "INMNFPRESACQ.h"
#include "INMNFPRESDIAG.h"
#include "INTERFACAGE_BA_SC.h"
#include "INTOBDSRV.h"
#include "IFRTE.H"
#include "ISCAN.h"
#include "ISLIN.h"
#include "KEYPUSHINFO.h"
#include "KNKACQ.h"
#include "KNKACQFILT.h"
#include "KNKADPCOR.h"
#include "KNKBENCHMOD.h"
#include "KNKCRITZONE.h"
#include "KNKDET.h"
#include "KNKDIAG.h"
#include "KNKFASTCOR.h"
#include "KNKINHADP.h"
#include "KNKINSTNOISE.h"
#include "KNKLDLIM.h"
#include "KNKNOISEADP.h"
#include "KNKSHDCOR.h"
#include "KNKSHDDET.h"
#include "LAMCLMPD.h"
#include "LIBSFTYLVL2.h"
#include "LIHCHK.h"
#include "MEM_CONF.h"
#include "MFUINJ.h"
#include "MFUSP.h"
#include "MFUSPCRK.h"
#include "MISFDET.h"
#include "MISFDETCFM.h"
#include "MISFDETIDLE.h"
#include "MISFDFTLRN.h"
#include "MISFDFTLRNOUT.h"
#include "MISFDIAGSTABCDN.h"
#include "MISFFAICTR.h"
#include "MISFROUGHNSROAD.h"
#include "MISFROUGHNSROADCAN.h"
#include "MISFSUCDET.h"
#include "MISFSUCDETIDLE.h"
#include "MISFWINACQ.h"
#include "MISFWINADP.h"
#include "MNGBRKPED.h"
#include "MONAUTHOSTT.h"
#include "MONENGSTRT.h"
#include "MUXDIAGON.h"
#include "MUXTQREQ.h"
#include "NEUTPOSNACQ.h"
#include "NTARIDLCHK.h"
#include "OBDSRV.h"
#include "OBDSRV06.h"
#include "OFSVLV.h"
#include "OILDSP.h"
#include "OILPRESACQ.h"
#include "OILTQCF.h"
#include "OSCDET.h"
#include "PDSTHRCHK.h"
#include "PFCMNG.h"
#include "POSTEQUSRV.h"
#include "PREDES.h"
#include "PREDESCHG.h"
#include "PROPFUPMP.h"
#include "PROTDFTLCLC.h"
#include "PROTMANCLU.h"
#include "PWRLMRK.h"
#include "PWRLRLY.h"
#include "PWRRLYCMDDIAG.h"
#include "PWRSEN_ACQ.h"
#include "REFIDETA.h"
#include "RELBRKASIACQ.h"
#include "REQADJVLTCTL.h"
#include "RICHBOOST.h"
#include "RLYACTEST.h"
#include "RLYPWR.h"
#include "RND.h"
#include "RVSSTDIAG.h"
#include "SAIMMO.h"
#include "SBPAGEN.h"
#include "SECUBV.h"
#include "SECUR.h"
#include "SENO2DLYGENR.h"
#include "SENO2DSACTEST.h"
#include "SENO2USACTEST.h"
#include "SFTYCPUDIAG.h"
#include "SFTYMGTIFTQ.h"
#include "SFTYMNGR.h"
#include "SPDVEHSECU.h"
#include "SPTMOD.h"
#include "SPYEMSTT.h"
#include "SPYSTT.h"
#include "SRVACTESTMNG.h"
#include "STRTLOCKACQ.h"
#include "STRTRCMDDIAG.h"
#include "STTIF.h"
#include "STTMO2CLC.h"
#include "STTRALD.h"
#include "SUMRAT.h"
#include "SYNCCKCMCOHDIAG.h"
#include "SYNCCKCMMONDIAG.h"
#include "SYNCCKDIAG.h"
#include "SYNCENGCLC.h"
#include "SYNCENGMNG.h"
#include "SYNCEXCMDIAG.h"
#include "SYNCINCMDIAG.h"
#include "SYNCSTT.h"
#include "TARIDLSTA.h"
#include "TCOREGKNK.h"
#include "TELECODAGE.h"
#include "THRABSSPPOSN.h"
#include "THRACTEST.h"
#include "THRBENCHAUT.h"
#include "THRBENCHMODE.h"
#include "THRBOOSTSP.h"
#include "THRCMD.h"
#include "THRCORRDPOSN.h"
#include "THRFULLRNGPOSN.h"
#include "THRMCUT.h"
#include "THRMNGSERVO.h"
#include "THROPLCTL.h"
#include "THRPOSMES.h"
#include "THRPOSNSPLRN.h"
#include "THRSECUMNG.h"
#include "THRSERVO.h"
#include "THRSERVODIAG.h"
#include "THRSFTYCPUIFINH.h"
#include "THRSFTYMNG.h"
#include "THRSPPOSN.h"
#include "THRSTOPCLCN.h"
#include "THRTHERMOPROT.h"
#include "TIENGSTOP.h"
#include "TOILEST.h"
#include "TQACRES.h"
#include "TQADVMIN.h"
#include "TQALTRES.h"
#include "TQANTISTALLBVM.h"
#include "TQCATHEATRES.h"
#include "TQCKEFCFIL.h"
#include "TQCKENGLIMCORD.h"
#include "TQCMPMANGBX.h"
#include "TQCNVRES.h"
#include "TQCOHEATRES.h"
#include "TQCOMON.h"
#include "TQCOMP.h"
#include "TQCRWLRES.h"
#include "TQDRIVMON.h"
#include "TQEIPMPRES.h"
#include "TQENGRES.h"
#include "TQESTMAX.h"
#include "TQFANRES.h"
#include "TQIDCENGREAL.h"
#include "TQIDLCHK.h"
#include "TQLIMSFTY.h"
#include "TQLNCHRES.h"
#include "TQLOSSMON.h"
#include "TQRESCORD.h"
#include "TQSTGPMPRES.h"
#include "TQSYSIDC.h"
#include "TQSYSSPBENCHMOD.h"
#include "TQSYSVLD.h"
#include "TQVSCTLCHK.h"
#include "TUNCFG.h"
#include "TWCMGT.h"
#include "UPLSACQ.h"
#include "VEHMNG.h"
#include "VEHMUX.h"
#include "VEHSPDACQ.h"
#include "VEHSPDDIAG.h"
#include "VEHST.h"
#include "VLVACTEXACQ.h"
#include "VLVACTEXACTRTEST.h"
#include "VLVACTEXCLN.h"
#include "VLVACTEXCMD.h"
#include "VLVACTEXENDSTOP.h"
#include "VLVACTEXESTIM.h"
#include "VLVACTEXIF.h"
#include "VLVACTEXMNG.h"
#include "VLVACTEXMON.h"
#include "VLVACTEXSERVO.h"
#include "VLVACTEXVLVBENCHMOD.h"
#include "VLVACTINACQ.h"
#include "VLVACTINACTRTEST.h"
#include "VLVACTINCLN.h"
#include "VLVACTINCMD.h"
#include "VLVACTINENDSTOP.h"
#include "VLVACTINESTIM.h"
#include "VLVACTINIF.h"
#include "VLVACTINMNG.h"
#include "VLVACTINMON.h"
#include "VLVACTINSERVO.h"
#include "VLVACTINVLVBENCHMOD.h"
#include "VLVEXSPMGT.h"
#include "VLVINSPMGT.h"
#include "VSC.h"
#include "VSSNWDMTRACV.h"
#include "VVTSPLIMCORD.h"
#include "WKU.h"
/* Inclusion ASW */

/* Inclusion CONFIG */
#include "NOPROD.h"
/* Inclusion CONFIG */

#include "KRN_ASW.h"

#define TST_START_SEC_TST_CODE
#include "TST_MemMap.h"

/******************************************************************************/
/* !FuncName    : KRN_vidINIT_ASW_1                                           */
/* !Description : First ASW function called by the INIT task                  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINIT_ASW_1(void)
{
   INITPROTECT_vidInitProtectEnable(); /* Cette accroche doit toujours être la premiere de l'init */
   GDGAR_EepromRamCpyUnpack();         /* not in OS */
   FRunTime_Init();                    /* not in OS */

   FHCAN_EveRst_Init();

   ComStMng_EveRst();
   DIAGCAN_EveRst();
   Can_EveRst_CanTxMixMod();
   ISFHCAN_EveRst_IniPrm();
   SAIMMO_EveRst();
   AcqAdc_EveRst_AcqAdc();
   Oil_EveRst_AcqAdc();
   Ext_EveRst_AcqDgoHaL();
   Ext_EveRst_AcqPwd();
   Ext_EveRst_OutPutCmdDiag();
   OILLVLHALACQ_DT_vidEntryInit();
   CoFan_EveRst_CmdDiagCoFanAcqPwd();
   RE_EBStub_001_MSE();
   Srv_EveRst_TeleSrv();
   Srv_EveRst_ActrTstMng();
   Srv_EveRst_RefIdEta();
   /* Srv_EveRst_SrvDiagConst(); */
   Srv_EveRst_PostEqu();
   Cf_EveRst_TunCfg();
   
   COHCAN_vidEntryInit(); /* Not in OS */
   
   IFAIRSYSIGSYS_vidEntryInit();       /* not in OS */
   FLOWMNG_vidEntryInit();             /* not in OS */
   ISFHCAN_EveRst_IniPrm();
   DIAGCAN_EveRst_If();
   Can_EveRst_FHCanF432If();
   Can_EveRst_FHCanF495If();
   Can_EveRst_FHCanF592If();
   Can_EveRst_FHCanF612If();
   Can_EveRst_FHCanF3C9If();
   Can_EveRst_FHCanF349If_2();
   Cf_EveRst_CtrlCfg();
   Cf_EveRst_CtrlCfgIf();
   Cf_EveRst_FlowMngClu_1();
   Cf_EveRst_FlowMngBrkAsi();
   Cf_EveRst_FlowMngBatt();
   Cf_EveRst_FlowMngDayCt();
   Cf_EveRst_FlowMngTqSel();
   Cf_EveRst_FlowMngAlt();
   Cf_EveRst_FlowMngPwt();
   Cf_EveRst_FlowMngGmv();
   Cf_EveRst_FlowMngBrk();
   Cf_EveRst_FlowMngPedPrss();
   Cf_EveRst_FlowMngGear();
   Cf_EveRst_FlowMngOilPres();
   Can_EveRst_FHCanF349_FlowMng();
   Can_EveRst_FHCanF552_FlowMng();
   Srv_EveRst_ObdSrvPid();
   Srv_EveRst_PwrlMrk();
   Srv_EveRst_ObdSrv06();
   Thr_EveRst_CmdPwmThrCmd();
   /* Srv_EveRst_SrvRc not define yet */
   /* Srv_EveRst_DiagSrv not define yet */
   ThMgt_EveRst_ActrTstTrbWaPmp();
   Cf_EveRst_FlowMngIf();
   Cf_EveRst_NoProd();
   SenAct_EveRst_tIGBTAcq();
   BoostReq_EveIni_BattVoltReq();
   INJVOLTADJ_vidEntryInit();
   IGVOLTADJ_vidEntryInit();
   IFELECMOTESS_vidEntryInit();
   Can_EveRst_FHCanF34DIf();
   CrsCtl_EveRst_CrsCtlInTreatIf();
   /* CRSCTL_u8RunCounter = 0; à voir avec FTOU */
   Can_EveRst_FHCanF50EIf2();
   CONFIGLIN_vidMngEveRst();            /* CONFIGLIN_EveRst in OS */
   GD_EveRst_SumRat();
   GDGAR_EveRst();                     /* GD_EveRst in OS */
   /* GD_EveRst_HrdRcvMng in GDGAR_EveRst */
   GD_EveRst_GJDDIf();
   SenAct_EveRst_tECUAcq();
}

/******************************************************************************/
/* !FuncName    : KRN_vidINIT_ASW_2                                           */
/* !Description : Second ASW function called by the INIT task                 */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINIT_ASW_2(void)
{

   boolean bLocalCtrl_bAcv_FuTnkPmp;

   SenAct_EveRst_tECUAcqIf();
   EcuSt_EveRst_DiagMem();
   EcuSt_EveRst_AcqWkuSig();
   EcuSt_EveRst_Wku();
   rte_RE_RCD_001_MSE();
   EcuSt_EveRst_EcuMng();
   EcuSt_EveRst_EcuMngIf();
   Pwr_EveRst_Acq();
   Thr_EveRst_AcqAdcThr();
   Pwr_EveRst_BattVoltAcqAdc();
   Pwr_EveRst_BattVoltAcq();
   Pwr_EveRst_AcqAdc();
   VSSNWDMTRACV_vidEntryInit();
   Pwr_EveRst_BattVoltAcqIf();
   CTP_EveRst_ActrTstCTP();
   
   PwrlRly_EveRst_IfCmdDiag();
   RlyPwr_EveRst_CrashVeh();
   Rly_EveRst_ActTstPwrRly();
   RlyPwr_EveRst_Mng();
   PwrRly_EveRst_IfCmdDiag();
   
   PREDESCHG_vidEntryInit();
   Sync_EveRst_InCmSts();
   Sync_EveRst_ExCmSts();
   Sync_EveRst_CkDiagSts();
   Sync_EveRst_SyncSTT();
   Sync_EveRst_CmCkMon();
   Sync_EveRst_EngSyncMng();
   Sync_EveRst_NEngClc();
   COSYNC_vidEntryInit();
   Sync_EveRst_CkMngIf();
   SYNCCKCMCOHDIAG_vidEntryInit();
   BufNEs_vidEntryInit();
   PredEs_vidEntryInit();
   IFNENGCLC_vidEntryInit();

   Sync_EveRst_AcqSyncSTT();
   Sync_EveRst_ExCmStsIf();
   Sync_EveRst_InCmStsIf();
   
   Sync_EveRst_IfAirSysIgSys();
   Sync_EveRst_FuSysCkMngIf();
   Sync_EveRst_CkMngIfIf();
   Sync_EveRst_CkMngIfIfAir();
   /* BUFNES_vidEntryInit include in Sync_EveRst */
   AirT_EveRst_AcqAirTAdc();
   AirT_EveRst_AcqAirT();
   AIRTFONCDIAG_vidEntryInit();
   AirT_EveRst_AcqAirTIfAir();
   AirT_EveRst_AcqAirTIf();
   CoT_EveRst_AcqCoTAdc();
   CoT_EveRst_AcqCoT();
   COTDIAG_vidEntryInit();             /* not in OS but link with CoT_EveRst_FctDiagCoT */
   CoT_EveRst_FctDiagCoT();
   AirPres_EveRst_AirExtPresAcq();
   AirPres_EveRst_InMnfPresAcq();
   AirPres_EveRst_BrkAsiAcq();
   AirPres_EveRst_RelBrkAsiAcq();
   AirPres_EveRst_AirExtPresAcqIf();
   AirPres_EveRst_SpgPresAcqif();
   AirPres_EveRst_SpgPresSp();
   AirPres_EveRst_InMnfPresDiag();
   AirPres_EveRst_DiagAirExtPres();
   BRKASIFONCDIAG_vidEntryInit();
   AirPres_EveRst_FctDiagTrbPres();
   Wg_EveRst_WgCmdOplBenchMod();
   Wg_EveRst_WgCmdSp();
   Wg_EveRst_WgActrTest();
   Wg_EveRst_WgCmdSpArb();
   Wg_EveRst_WgcCmd();
   Wg_EveRst_FctDiagWg();
   AC_EveRst_ACPresAcqAdc();
   AC_EveRst_ACPresAcq();
   AC_EveRst_ACPresAcqIf();
   
   Brk_EveRst_DiagBrkPed();
   Brk_EveRst_MngBrkPed();
   Brk_EveRst_DiagBrkPedNoBVH2p();
   BRKPEDBVH2P_vidEntryInit();
   
   Clu_EveRst_CluPed();
   Clu_EveRst_CluSwtDiag();
   Clu_EveRst_CluPedFreqAcq();
   CLUPEDPOSNDIAG_vidEntryInit();
   /* CLUPEDPOSNDIAG_vidEntryInit include in Clu_EveRst*/
   
   SenO2Us_EveRst_UpLsAcq();
   SenO2Us_EveRst_PerDiag();
   SenO2Us_EveRst_UsPlaus();
   SENO2DLYGENR_vidEntryInit();
   
   SenO2Ds_EveRst_DsLsAcq();
   SenO2Ds_EveRst_SigGrdDiag();
   SenO2Ds_EveRst_DsPlaus();
   /* Pb Inte RTAS-OS*/
   /* FuPmp_EveRst(); */
   /* VEMS_vidGET(Ctrl_bAcv_FuTnkPmp, bLocalCtrl_bAcv_FuTnkPmp);
   if (bLocalCtrl_bAcv_FuTnkPmp == 0)
   {
      FuPmp_EveRst_Mng();
   }
   FuPmp_EveRst_ActrTstFuTnkPmp();
   FTPCTL_vidEntryInit();
   FuPmp_EveRst_PropFuPmp(); */
   
   Cf_EveRst_FuPmp();
   AccP_EveRst_AcqPosnAdc();
   AccP_EveRst_AcqPosn();
   AccP_EveRst_FLrng();
   AccP_EveRst_MngModSecu();
   AccP_EveRst_AccPMngModSec();
   AccP_EveRst_Clc();
   ACCPCALCRPOS_vidEntryReset();
   AccP_EveRst_SwtAcqDiag();
   ACCPFRM_vidEntryInit();
   AccP_EveRst_MonStuckAccP();
   AccP_EveRst_AccPEM();
}

/******************************************************************************/
/* !FuncName    : KRN_vidINIT_ASW_1                                           */
/* !Description : Third ASW function called by the INIT task                  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINIT_ASW_3(void)
{

   boolean bLocalEcuSt_bDetHotRst;

   /*Init of hysteresis output for event STT_SdlFast_2*/
   /* CoReqRstrt_bAcvFunc = 0; à voir FTOU */
   /*Call of events*/
   ENGREQH_vidEntryInit();
   STT_EveRst_KeyPushInfo();
   /*RE_StopStrtEng_007_MSE();*/
   rte_RE_StopStrtEng_007_MSE();
   /*RE_StopStrtEng_003_MSE*/
   rte_RE_StopStrtEng_003_MSE();
   /*RE_StopStrtEng_023_MSE*/
   rte_RE_StopStrtEng_023_MSE();
   /*RE_CoStopStart_003_MSE*/
   rte_RE_CoStopStart_003_MSE();
   /*RE_CoStopStart_023_MSE*/
   rte_RE_CoStopStart_023_MSE();
   /*RE_CoStopStart_025_MSE*/
   rte_RE_CoStopStart_025_MSE();
   /*RE_CoStopStart_027_MSE*/
   rte_RE_CoStopStart_027_MSE();
   /*RE_CoStopStart_029_MSE*/
   rte_RE_CoStopStart_029_MSE();
   /*RE_CoStopStart_031_MSE*/
   rte_RE_CoStopStart_031_MSE();
   /*RE_CoStopStart_007_MSE*/
   rte_RE_CoStopStart_007_MSE();
   /*RE_CoStopStart_009_MSE*/
   rte_RE_CoStopStart_009_MSE();
   /*RE_CoStopStart_011_MSE*/
   rte_RE_CoStopStart_011_MSE();
   /*RE_CoStopStart_013_MSE*/
   rte_RE_CoStopStart_013_MSE();
   /*RE_CoStopStart_015_MSE*/
   rte_RE_CoStopStart_015_MSE();
   /*RE_CoStopStart_017_MSE*/
   rte_RE_CoStopStart_017_MSE();
   /*RE_CoStopStart_019_MSE*/
   rte_RE_CoStopStart_019_MSE();
   /*RE_CoStopStart_021_MSE*/
   rte_RE_CoStopStart_021_MSE();
   /*RE_StopStrtEng_015_MSE*/
   rte_RE_StopStrtEng_015_MSE();
   /*RE_StopStrtEng_011_MSE*/
   rte_RE_StopStrtEng_011_MSE();
   /*RE_StopStrtEng_013_MSE*/
   rte_RE_StopStrtEng_013_MSE();
   /*RE_StopStrtEng_005_MSE*/
   rte_RE_StopStrtEng_005_MSE();
   /*RE_StopStrtEng_017_MSE*/
   rte_RE_StopStrtEng_017_MSE();
   /*RE_ASE_001_MSE*/
   rte_RE_ASE_001_MSE();
   /*RE_ASE_003_MSE*/
   rte_RE_ASE_003_MSE();
   /*RE_ASE_005_MSE*/
   rte_RE_ASE_005_MSE();
   /*RE_ASE_007_MSE*/
   rte_RE_ASE_007_MSE();
   /*RE_ASE_009_MSE*/
   rte_RE_ASE_009_MSE();
   /*RE_ASE_011_MSE*/
   rte_RE_ASE_011_MSE();
   /*RE_StopStrtEng_009_MSE*/
   rte_RE_StopStrtEng_009_MSE();
   /*RE_StopStrtEng_019_MSE*/
   rte_RE_StopStrtEng_019_MSE();
   /*RE_StopStrtEng_021_MSE*/
   rte_RE_StopStrtEng_021_MSE();
   /*RE_CoEmSTT_001_MSE*/
   rte_RE_CoEmSTT_001_MSE();
   STT_EveRst_SpyEmSTT();
   /*RE_StopStrtEm_001_MSE*/
   rte_RE_StopStrtEm_001_MSE();
   /*RE_StopStrtEm_005_MSE*/
   rte_RE_StopStrtEm_005_MSE();
   /*RE_STOPSTRTEM_003_MSE*/
   rte_RE_StopStrtEm_003_MSE();
   COES_vidEntryInit();
   COPTST_vidEntryInit();
   STT_EveRst_SpySTT();
   STT_EveRst_STTmO2Clc();
   
   Sync_EveRst_CkMngIfIf_2();
   
   RE_StopStrtEng_023_MSEIf();
   RE_StopStrtEng_013_MSEIf();
   RE_StopStrtEm_003_MSEIf();
   rte_RE_ProdElEng_013_MSE();
   rte_RE_ProdElEng_009_MSE();
   rte_RE_ProdElEng_001_MSE();
   rte_RE_ProdElEng_005_MSE();
   rte_RE_ProdElEng_003_MSE();
   rte_RE_ProdElEng_015_MSE();
   rte_RE_ProdElEng_007_MSE();
   rte_RE_ProdElEng_011_MSE();
   rte_RE_ProdElEm_001_MSE();
   rte_RE_ProdElEm_005_MSE();
   rte_RE_ProdElEm_003_MSE();
   /* COES_vidEntryInit include in STT_EveRst_1 but not in doc archi */
   /* CoPTSt_EveRst_RStrtSTT not find in code */
   RE_ProdElEm_005_MSEIf();
   
   EngSt_EveRst_EngStrtStop();
   EngSt_EveRst_VehSt();
   EngSt_EveRst_EngrunSt();
   EngSt_EveRst_EngStOutIdc();
   Strtr_EveRst_IfCmdDiag();
   EngSt_EveRst_TiEngStop();
   EngSt_EveRst_EngStab();
   EngSt_EveRst_MonEngStrt();
   EngSt_EveRst_DftStaCmd();
   EngSt_EveRst_AuthStrtSTT();
   EngSt_EveRst_OscDet();
   
   EngSt_EveRst_EngStrtStopIf();
   EngSt_EveRst_EngrunStIfAir();
   
   TqSys_EveRst_MuxTqReq();
   rte_RE_MPM_001_MSE();
   rte_RE_TPM_001_MSE();
   TQADVMIN_vidEntryInit();
   rte_RE_DfwCtl_001_MSE();
   
   RE_TPM_001_MSEIf();
   
   CHATQAIRCORD_vidEntryInit();
   TQESTMAX_vidEntryInit();
   rte_RE_TqTreat_001_MSE();
   rte_RE_TqTreat_003_MSE();
   rte_RE_TqTreat_005_MSE();
   rte_RE_TqTreat_007_MSE();
   rte_RE_TqTreat_009_MSE();
   TQCMPMANGBX_vidEntryInit();
   rte_RE_TraBVx_001_MSE();
   rte_RE_CurDrivFil_001_MSE();
   rte_RE_TqAdpCmp_001_MSE();
   rte_RE_CoGBx_001_MSE();
   rte_RE_ACCmd_001_MSE();
   OilTqCf_EveRst_OilTqCf();     /*OILTQCF_vidEntryInit*/
   rte_RE_CoTq_001_MSE();
   rte_RE_CoTq_003_MSE();
   rte_RE_CoTq_005_MSE();
   rte_RE_CoTq_007_MSE();
   rte_RE_CoTq_009_MSE();
   rte_RE_EngLim_001_MSE();
   rte_RE_TqDem_001_MSE();
   rte_RE_PFilFast_001_MSE();
   rte_RE_PFilSlow_008_MSE();
   rte_RE_CoClLASl_001_MSE();
   SPTMOD_vidEntryInit();
   
   RE_TqTreat_003_MSEIf();
   RE_TraBVx_001_MSEIf();
   RE_CoGBx_001_MSEIf();
   RE_CoClLASl_001_MSEIf();
   Cf_EveRst_FlowMngClu_2();
   
   rte_RE_TqEM_001_MSE();
   BRKASIACT_vidEntryInit();
   
   IDLMGR_vidEntryInit();
   IDLCTRL_vidEntryInit();
   TQALTRES_vidEntryInit();
   SBPAGEN_vidEntryInit();
   ENGIDLEINTERFACE_vidEntryInit();
   TQANTISTALLBVM_vidEntryInit();
   IDLSYSCUTOFF_vidEntryInit();
   TQENGRES_vidEntryInit();
   TQLNCHRES_vidEntryInit();
   IDLCMDMOD_vidEntryInit();
   TQSTGPMPRES_vidEntryInit();
   TQCRWLRES_vidEntryInit();
   TQCNVRES_vidEntryInit();
   TQFANRES_vidEntryInit();
   TQEIPMPRES_vidEntryInit();
   TQCOHEATRES_vidEntryInit();
   PROTDFTLCLC_vidEntryInit();
   TQACRES_vidEntryInit();
   PROTMANCLU_vidEntryInit();
   ENGLIMEFCCORD_vidEntryInit();
   TQRESCORD_vidEntryInit();
   TARIDLSTA_vidEntryInit();
   TQCATHEATRES_vidEntryInit();
   
   RICHBOOST_vidEntryInit();
   
   TqSys_EveRst_SpBenchMod();
   TqSys_EveRst_TqSysIdc();
   TqSys_EveRst_tqLimSfty();
   TqSys_EveRst_TqSysVld();
   rte_RE_MPM_AftrsInit();
   
   TqSys_EveRst_tqLimSftyIf();
   Oil_EveRst_OilPropPresAcq();
   Cf_EveRst_AirTFlowMng();
   
   Oil_EveRst_OilPresAcq();
   Oil_EveRst_PresDiagCoh();
   Eng_EveIni_tOilEstim();
   Oil_EveRst_OilLvlAcq();
   rte_RE_OilSys_001_MSE();
   Oil_EveRst_ActrTstCtlPmp();
   OilSysHw_EveRst_CtlPmpReq();
   Oil_EveRst_ActrTstBlowBy();
   Oil_EveRst_BlowByCmd();
   
   OilSys_EveRst_OilDsp();
   
   Eng_EveIni_tOilEstimIf();
   Oil_EveRst_ActrTstCtlPmpIf();
   CrsCtl_EveRst_CrsCtlBsiTreat();
   rte_RE_VSInfo_001_MSE();
   rte_RE_VSReg_001_MSE();
   rte_RE_VSLim_001_MSE();
   rte_RE_VSMax_001_MSE();
   rte_RE_VSCo_001_MSE();
   CrsCtl_EveRst_CrsCtlOutTreat();
   VSCTL_EveRst_LstCrsCtlDeacCaus();
   
   VEMS_vidGET(EcuSt_bDetHotRst, bLocalEcuSt_bDetHotRst);
   if (bLocalEcuSt_bDetHotRst != 0)
   {
      rte_RE_VSSp_004_MSE();
   }
   else
   {
      rte_RE_VSSp_001_MSE();
   }

   Thr_EveRst_MngServo();
   Thr_EveRst_BenchAut();
   Thr_EveRst_SpBenchMod();
   Thr_EveRst_ActrTstThr();
   Thr_EveRst_ThrPosnSpSpc();
   Thr_EveRst_SpPosn();
   Thr_EveRst_BoostSp();
   Thr_EveRst_AbsSpPosn();
   Thr_EveRst_PosnMes();
   Thr_EveRst_mCut();
   Thr_EveRst_StopClcn();
   Thr_EveRst_SecuMng();
   Thr_EveRst_ThrCpuSftyMng();
   Thr_EveRst_IfInhThrCpuSfty();
   Thr_EveRst_Servo();
   Thr_EveRst_ThermoProt();
   Thr_EveRst_OplCtl();
   Thr_EveRst_ThrCmd();
   THRSERVODIAG_vidEntryInit();
   THRCORRDPOSN_vidEntryInit();
   THRFULLRNGPOSN_vidEntryInit();
   
   VlvAct_EveRst_InIf();
   VLVACTINACQ_vidEntryInit();
   VlvAct_EveRst_InEndStop();
   VlvAct_EveRst_InServo();
   VlvAct_EveRst_InCln();
   VlvAct_EveRst_InCmd();
   VlvAct_EveRst_InActrTest();
   VlvAct_EveRst_InVlvSpBenchMod();
   VLVACTINMNG_vidEntryInit();
   VLVACTINESTIM_vidEntryInit();
   VLVACTINMON_vidEntryInit();
   
   /* VlvAct_EveRst in OS */
   VlvAct_EveRst_ExIf();
   VLVACTEXACQ_vidEntryInit();
   VlvAct_EveRst_ExEndStop();
   VlvAct_EveRst_ExServo();
   VlvAct_EveRst_ExCln();
   VlvAct_EveRst_ExCmd();
   VlvAct_EveRst_ExActrTest();
   VlvAct_EveRst_ExVlvSpBenchMod();
   VLVACTEXMNG_vidEntryInit();
   VLVACTEXESTIM_vidEntryInit();
   VLVACTEXMON_vidEntryInit();
   
   VlvAct_EveRst_AcqVlVActPos();
   Mux_EveRst_MuxDiagOn();
   Can_EveRst_DftLiMsgMgt();
   SftyMgt_EveRst_SpdVehSecu();
   VehSpd_EveRst_VehMux();
   VehSpd_EveRst_AcqVehSpdSen();
   VehSpd_EveRst_VehMng();
   VehSpd_EveRst_MonVehSpd();
   
   Sfty_EveRst_DiagCpuSfty();
   Sfty_EveRst_PfcMng();
   SftyMgt_EveRst_ifTqMon();
   IFTQSTRUCT_TQMON_vidEntryInit();
   MONAUTHOSTT_vidEntryInit();
   PDSTHRCHK_vidEntryInit();
   TQIDCENGREAL_vidEntryInit();
   SftyMgt_Init_tqCkEngLimCord();
   NTARIDLCHK_vidEntryInit();
   TQCKEFCFIL_vidEntryInit();
   SFTYMNGR_vidEntryInit();
   TQLOSSMON_vidEntryInit();
   SftyMgt_EveRst_DiagSftyLvl2();
   LIHCHK_vidEntryInit();
   TQDRIVMON_vidEntryInit();
   TQVSCTLCHK_vidEntryInit();
   TQCOMON_vidEntryInit();
   SECUBV_vidEntryInit();
   TQIDLCHK_vidEntryInit();
   TQCOMP_vidEntryInit();
   DFTMGT_vidEntryInit();
   FFGEN_vidEntryInit();
   IFAUTHDFTSTT_vidEntryInit();
   
   /*Sfty_EveRst_TaskOvrrunCnt(); Inte RTAS-OS*/
   
   rte_RE_GSI_001_MSE();
   Gear_EveRst_NeutPosnAcq();
   Gear_EveRst_StrtLockAcq();
   RVSSTDIAG_vidEntryInit();
   
   CrkMgt_EveRst_AirTqStructMngt();
   AIRTHRARCRKSP_vidEntryInit();
   CrkMgt_EveRst_AirTqStructMngtIf();
   
   Fisa_EveInit();
   CLCNFISAGAIN_vidEntryInit();
   FISAINHMGR_vidEntryInit();
   
   rte_RE_FISA_init();                    /* RE_FISA_Init in OS */
   VVTSPLIMCORD_vidEntryInit(); /*EXOFS_vidEntryInit*/
   rte_RE_UsThrMT_001_MSE();
   rte_RE_UsThrMT_004_MSE();
   VlvSys_EveIni_VlvIn();
   VlvSys_EveIni_VlvEx();
   VlvSys_EveIni_VlvArb();
   rte_RE_InMdlT_001_MSE();
   rte_RE_InMdlT_037_MSE();
   rte_RE_InMdlT_039_MSE();
   rte_RE_InMdlT_038_MSE();
   rte_RE_InMdlT_045_MSE();
   rte_RE_InMdlT_035_MSE();
   rte_RE_InMdlT_040_MSE();
   rte_RE_InMdlT_036_MSE();
   rte_RE_InMdlT_041_MSE();
   rte_RE_InMdlT_042_MSE();
   rte_RE_InMdlT_046_MSE();
   rte_RE_InMdlT_047_MSE();
   rte_RE_InMdlT_044_MSE();
   rte_RE_InMdlT_043_MSE();
   rte_RE_ExMGslT1_004_MSE();
   rte_RE_ExMGslT1_005_MSE();
   rte_RE_ExMGslT2_001_MSE();
   rte_RE_InThMdlT_001_MSE();
   rte_RE_EngMGslLim_001_MSE();
   rte_RE_EngMGslT_001_MSE();
   TWCMgt_EveIni_TWCMgt();
   RE_ExMGslT2_001_MSEIfTWC();
   CATAGIESTIM_vidEntryInit();
   CATAGIESTIM_vidEntryInit();            /* not in OS but link the CatMdl_EveRst */
   
   HeatSenO2_EveRst_ActrTSO2Us();
   HeatSenO2_EveRst_ActrTSO2Ds();
   HeatSenO2_EveRst_UsMgr();
   HeatSenO2_EveRst_DsMgr();
   HEATSENO2USCMD_vidEntryInit();
   HEATSENO2DSCMD_vidEntryInit();
   DRVRSENO2US_vidEntryInit();
   DRVRSENO2DS_vidEntryInit();
   HeatSenO2_EveRst_HeatSenO2Mon();
   HeatSenO2_EveRst_HotSenO2Flg();
   HeatSenO2_EveRst_ReqAdjVltCtl();
   
   VlvSys_EveIni_VlvInIf();
   VlvSys_EveIni_VlvExIf();
}

/******************************************************************************/
/* !FuncName    : KRN_vidINIT_ASW_1                                           */
/* !Description : Fourth ASW function called by the INIT task                 */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINIT_ASW_4(void)
{
   RE_EngM_initIf();
   RE_InMdlT_043_MSEIf();
   RE_ExMGslT2_001_MSEIf();
   rte_RE_EngLimTqT_009_MSE();
   AirSys_EveIni_AirTqEff();
   rte_RE_AirSysAir_001_MSE();
   STTRALD_vidEntryInit();
   IFAIRSYS_vidEntryInit();
   ALDALTCOR_vidEntryInit();
   rte_RE_ThrSpT_001_MSE();
   rte_RE_AFAMgtT_001_MSE();
   rte_RE_AFAMgtT_002_MSE();
   rte_RE_AFAMgtT_004_MSE();
   rte_RE_AFAT_001_MSE();
   rte_RE_AFAT_002_MSE();
   INTERFACAGE_BA_SC_vidEntryInit();
   rte_RE_AFAMgtT_AftrsInit();
   AirSys_EveRst_InAirflowDiag();
   RE_AirSysAir_001_MSEIf();
   DmpVlvAct_EveRst_DmpVlvOplCmd();
   DmpVlv_EveRst_ActrTstDV();
   DmpVlv_EveRst_DmpVlvCmdSpArb();
   DmpVlvAct_EveRst_DmpVlvCmd();
   DmpVlv_EveRst_FctDiagDmpVlv();
   rte_RE_EOMGsl_001_MSE();
   rte_RE_AdvOptmT_001_MSE();
   rte_RE_AdvPrevKnkT_001_MSE();
   rte_RE_AdvCordT_001_MSE();
   rte_RE_AdvMinT_005_MSE();
   RE_AdvMinT_005_MSEIf();
   TqSys_EveRst_ChaAdvMinUnlim();
   rte_RE_AdvOptmT_004_MSE();
   rte_RE_AdvMinT_001_MSE();
   rte_RE_AdvMaxT_001_MSE();
   rte_RE_AdvSpT_001_MSE();
   rte_RE_AdvSpT_005_MSE();
   rte_RE_AdvCordT_003_MSE();
   rte_RE_EngLimTqT_011_MSE();
   rte_RE_EngLimTqT_013_MSE();
   rte_RE_AdvSpT_003_MSE();
   rte_RE_EngLimTqT_001_MSE();
   rte_RE_EngLimTqT_003_MSE();
   rte_RE_EngLimTqT_005_MSE();
   rte_RE_EngLimTqT_007_MSE();
   RE_OEMGsl_001_MSEIf();
   RE_AdvMaxT_001_MSEIf();
   IgSys_EveRst_IgCrk();
   IgSys_EveRst_IgArb();
   IgCmd_EveRst_ActrTstCoil();
   IgCmd_EveRst_IgCoilMng();
   ADDONADVMAX_vidEntryInit();
   ADDONADVMIN_vidEntryInit();
   ADDONAGCOR_vidEntryInit();
   ADDONADVOPTM_vidEntryInit();
   TCOREGKNK_vidEntryInit();
   IGEXTHERMOPROT_vidEntryInit();
   Cstr_EveRst_FuConcEstim();
   Cstr_EveRst_CstrEfcRed();
   Cstr_EveRst_ActrTstCstr();
   Cstr_EveRst_CstrMgr();
   Cstr_EveRst_CstrDynLim();
   Cstr_EveRst_CstrCmd();
   Cstr_EveRst_CmdPwmCstr();
   
   FarSp_EveRst_ActrTstFarSp();
   Far_EveRst_IfFar();
   rte_RE_FARSp_023_MSE();
   rte_RE_FARSp_001_MSE();
   rte_RE_FARSp_003_MSE();
   rte_RE_FARSp_005_MSE();
   rte_RE_FARSp_007_MSE();
   rte_RE_FARSp_009_MSE();
   rte_RE_FARSp_011_MSE();
   rte_RE_FARSp_013_MSE();
   rte_RE_FARSp_015_MSE();
   rte_RE_FARSp_017_MSE();
   rte_RE_FARSp_021_MSE();
   rte_RE_FARSp_025_MSE();
   FAR_FARSPMGRONOFF_vidEntryInit();
   
   InjCtl_EveRst_FarCtlMgr();
   InjCtl_EveRst_InjFarCtlUsCtl();
   InjCtl_EveRst_InjFarCtlDsCtl();
   InjCtl_EveRst_LamClmpd();
   Inj_EveRst_InjTiCor();
   StraMon_EveRst_FarStraMon();
   
   InjCtl_EveRst_IfAirSysIgSys();
   Inj_EveRst_InjTiCorIf();
   
   FuAcq_EveRst_PFuAcq();
   InjCutOff_EveRst_InjCutOffBvmp();
   
   InjCutOff_EveRst_CutOff();
   InjSys_EveRst_InjSysMgrCrk();
   InjSys_EveRst_InjSysSpCrk();
   InjSys_EveRst_mFuSpCrk();
   InjSys_EveRst_IfEOMInjSp();
   InjSys_EveRst_agInjSp();
   InjSys_EveRst_InjResuCmp();
   InjSys_EveRst_InjAstWupCmp();
   
   InjSys_EveRst_facFuTran();
   
   InjSys_EveRst_facFuTranIf();
   
   InjSys_EveRst_mFuSp();
   InjSys_EveRst_InjSpMgt();
   InjSys_EveRst_mFuInj();
   
   FuSysM_EveRst_tFuM();
   FuSysM_EveRst_pFuM();
   CylM_EveRst_pCylM();
   InjrM_EveRst_InjrPrmMdl();
   InjrM_EveRst_InjrMdl();
   InjrSys_EveRst_tiFuSp();
      
   Inj_EveRst_ActrTstInj();
   
   InjCutOff_EveRst_CutOffIf();
   
   InjSys_EveRst_mFuInjIf();
   FuSysM_EveRst_tFuMIf();
   InjrM_EveRst_InjrMdlIf();
   
   PFuCtl_EveRst_FuRailCtlMgr();
   PFuCtl_EveRst_HPPmpCtl();
   PFuCtl_EveRst_HPPmpVlvCmdLrn();
   PFuCtl_EveRst_ActrTstHPPmp();
   PFuCtl_EveRst_HPPmpMdl();
   
   PFuCtl_EveRst_HPPmpActCmdAcq();
   PFuCtl_EveRst_HPPmpActCmd();
   
   /* PFuCtl_EveRst_HPPmpFctDiag(); // lecture en EEPROM pas implémentation cote CODE_AUTO */
   
   Fu_EveRst_FuCns();
   Fu_EveRst_FuLvl();
   Fu_EveRst_HPSensDiag();
   DmpVlvAct_EveRst_CmdPwmAct();
   Fu_EveRst_ExtLeakDiag();
   
   Inj_EveRst_FuTiRunIf2();
   
   Misf_EveRst_MisfWinAcq();
   Misf_EveRst_MisfDiagStabCdn();
   Misf_EveRst_MisfDftLrn();
   Misf_EveRst_MisfDetIdle();
   Misf_EveRst_MisfSucDetIdle();
   IgCmd_EveRst_MisfGenr();
   Misf_EveRst_MisfFaiCtr();
   Misf_EveRst_AvrMisfCnt();
   MEAP_EveRst_ActrTstMEAP();
   MISFDFTLRNOUT_vidEntryInit();
   MISFWINADP_vidEntryInit();
   MISFDET_vidEntryInit();
   MISFSUCDET_vidEntryInit();
   MISFMISFDETCFM_vidEntryInit();
   MISFROUGHNSROADCAN_vidEntryInit();
   MISFROUGHNSROAD_vidEntryInit();
   
   rte_RE_ThMgt_001_MSE();
   CoFan_EveRst_ActrTstGMV();
   CoFan_EveRst_CmdDiagCoFan();
   ThMgt_EveRst_ActrTstECT();
   CoFan_EveRst_ECTReq();
   RE_ThMgt_001_MSEIf();
   CoFan_EveRst_CmdDiagCoFanIf();
   
   KnkTreat_EveRst_KnkAcqFilt();
   KnkTreat_EveRst_KnkAcq();
   KnkTreat_EveRst_InstNoise();
   KnkTreat_EveRst_KnkDet();
   KnkTreat_EveRst_NoiseAdp();
   KnkTreat_EveRst_ShdDet();
   KnkTreat_EveRst_RblPvt();
   KnkTreat_EveRst_KnkMgrCorRbl();
   KnkTreat_EveRst_LdLim();
   KNKDIAG_vidEntryInit();
   KNKBENCHMOD_vidEntryInit();
   
   KnkTreat_EveRst_KnkMgrCorRblIf();
   IgLim_EveRst_CritZone();
   IgLim_EveRst_KnkInhAdp();
   IgLim_EveRst_KnkAdpCor();
   IgLim_EveRst_ShdCor();
   IgLim_EveRst_FastCor();
   IgLim_EveRst_CritZoneIf();
   ISLIN_vidEveRst();                     /* Lin_EveRst_IsLin in OS */
   Lin_EveRst_IsLinIf();
   CatMon_EveRst_CatMonIf();
   rte_RE_CatMon_EveRst_CatPasDiag();
   rte_RE_CatMon_EveRst_CatAcvDiag();
   CatMon_EveRst_CatAcvDiagIf();
   CCP_vidIni(NULL_PTR);                  /* not in OS , add for CCP*/
   DCM_CONFIG_EveRst();                   /* not in OS */
   ASIC_EveRst_diagasicgdi();
   Strtr_EveRst_IfCmdDiagDio();
   EngSt_EveRst_EngStOutIdcDio();
   EngSt_EveRst_AuthStrtSTTDio();
   PwrRly_EveRst_IfCmdDiagDio();
   PwrlRly_EveRst_IfCmdDiagDio();
   Ext_EveRst_AcqCmdDio();
   AC_EveRst_AdHeatCmd();
   
   Ext_EveRst_CmdPwm();
   
   Ext_EveRst_AcqAdc();
   Clu_EveRst_CluPedFreqAcqPwd();
   FuPmp_EveRst_PropFuPmpPwd();
   Gear_EveRst_NeutPosnAcqPwd();
   EcuSt_EveIni_Wku();
   Wg_EveRst_CmdPwmAct();
   AC_EveRst_CmdDio();
   INITPROTECT_vidInitProtectDisable();   /* Cette accroche doit toujours être la derniere de l'init */
   
   ActrTstBlowBy_initialize();
   ActTstFuPmp_initialize();
   agInjSp_initialize();
   OilTqCf_initialize();
   TqCkEngLimCord_initialize();
   facFuTran_initialize();
   FuSysExtLeakDiag_initialize();
   HPPmpFctDiag_initialize();
   IfEOMInjSp_initialize();
   InjAstWupCmp_initialize();
   InjCutOffMgr_initialize();
   InjResuCmp_initialize();
   InjSpMgt_initialize();
   InjSysMgrCrk_initialize();
   InjSysSpCrk_initialize();
   KnkLdLim_initialize();
   mFuInj_initialize();
   mFuSp_initialize();
   mFuSpCrk_initialize();
   MonEngStrt_initialize();
   
   KNKINSTNOISERBL_vidEntryInit();
   RBLDETBENCH_vidEntryInit();
   KnkMgrCorRbl_initialize();
   INJCRK_ANTIFLOOD_vidEntryInit();
   ACCPFRM_vidEntryInit();
   AIRTFONCDIAG_vidEntryInit();
   AIRTHRARCRKSP_vidEntryInit();
   BRKASIFONCDIAG_vidEntryInit();
   BRKPEDBVH2P_vidEntryInit();
   CATAGIESTIM_vidEntryInit();
   CLCNFISAGAIN_vidEntryInit();
   OILLVLHALACQ_DT_vidEntryInit();
   COHCAN_vidEntryInit();
   COTDIAG_vidEntryInit();
   DRVRSENO2DS_vidEntryInit();
   DRVRSENO2US_vidEntryInit();
   ADDONADVMAX_vidEntryInit();
   ADDONADVMIN_vidEntryInit();
   ADDONADVOPTM_vidEntryInit();
   ADDONAGCOR_vidEntryInit();
   ALDALTCOR_vidEntryInit();
   BRKASIACT_vidEntryInit();
   BufNEs_vidEntryInit();
   CHATQAIRCORD_vidEntryInit();
   CLUPEDPOSNDIAG_vidEntryInit();
   COES_vidEntryInit();
   COPTST_vidEntryInit();
   COSYNC_vidEntryInit();
   DFTMGT_vidEntryInit();
   ENGIDLEINTERFACE_vidEntryInit();
   ENGLIMEFCCORD_vidEntryInit();
   ENGREQH_vidEntryInit();
   FFGEN_vidEntryInit();
   FTPCTL_vidEntryInit();
   IDLCMDMOD_vidEntryInit();
   IDLCTRL_vidEntryInit();
   IDLMGR_vidEntryInit();
   IDLSYSCUTOFF_vidEntryInit();
   IFAUTHDFTSTT_vidEntryInit();
   IFELECMOTESS_vidEntryInit();
   IFTQSTRUCT_TQMON_vidEntryInit();
   INTERFACAGE_BA_SC_vidEntryInit();
   LIHCHK_vidEntryInit();
   MONAUTHOSTT_vidEntryInit();
   NTARIDLCHK_vidEntryInit();
   PDSTHRCHK_vidEntryInit();
   PredEs_vidEntryInit();
   PREDESCHG_vidEntryInit();
   PROTDFTLCLC_vidEntryInit();
   PROTMANCLU_vidEntryInit();
   RICHBOOST_vidEntryInit();
   SBPAGEN_vidEntryInit();
   SECUBV_vidEntryInit();
   SFTYMNGR_vidEntryInit();
   SPTMOD_vidEntryInit();
   TARIDLSTA_vidEntryInit();
   TCOREGKNK_vidEntryInit();
   TQACRES_vidEntryInit();
   TQADVMIN_vidEntryInit();
   TQALTRES_vidEntryInit();
   TQANTISTALLBVM_vidEntryInit();
   TQCATHEATRES_vidEntryInit();
   TQCKEFCFIL_vidEntryInit();
   TQCMPMANGBX_vidEntryInit();
   TQCNVRES_vidEntryInit();
   TQCOHEATRES_vidEntryInit();
   TQCOMON_vidEntryInit();
   TQCOMP_vidEntryInit();
   TQCRWLRES_vidEntryInit();
   TQDRIVMON_vidEntryInit();
   TQEIPMPRES_vidEntryInit();
   TQENGRES_vidEntryInit();
   TQESTMAX_vidEntryInit();
   TQFANRES_vidEntryInit();
   TQIDCENGREAL_vidEntryInit();
   TQIDLCHK_vidEntryInit();
   TQLNCHRES_vidEntryInit();
   TQLOSSMON_vidEntryInit();
   TQRESCORD_vidEntryInit();
   TQSTGPMPRES_vidEntryInit();
   TQVSCTLCHK_vidEntryInit();
   VVTSPLIMCORD_vidEntryInit();
   FAR_FARSPMGRONOFF_vidEntryInit();
   FISAINHMGR_vidEntryInit();
   FLOWMNG_vidEntryInit();
   HEATSENO2DSCMD_vidEntryInit();
   HEATSENO2USCMD_vidEntryInit();
   IFAIRSYS_vidEntryInit();
   IFAIRSYSIGSYS_vidEntryInit();
   IFNENGCLC_vidEntryInit();
   IGEXTHERMOPROT_vidEntryInit();
   IGVOLTADJ_vidEntryInit();
   INJVOLTADJ_vidEntryInit();
   KNKBENCHMOD_vidEntryInit();
   KNKDIAG_vidEntryInit();
   MISFDET_vidEntryInit();
   MISFMISFDETCFM_vidEntryInit();
   MISFDFTLRNOUT_vidEntryInit();
   MISFROUGHNSROAD_vidEntryInit();
   MISFROUGHNSROADCAN_vidEntryInit();
   MISFSUCDET_vidEntryInit();
   MISFWINADP_vidEntryInit();
   RVSSTDIAG_vidEntryInit();
   SENO2DLYGENR_vidEntryInit();
   STTRALD_vidEntryInit();
   SYNCCKCMCOHDIAG_vidEntryInit();
   THRCORRDPOSN_vidEntryInit();
   THRFULLRNGPOSN_vidEntryInit();
   THRSERVODIAG_vidEntryInit();
   VLVACTEXACQ_vidEntryInit();
   VLVACTEXESTIM_vidEntryInit();
   VLVACTEXMNG_vidEntryInit();
   VLVACTEXMON_vidEntryInit();
   VLVACTINACQ_vidEntryInit();
   VLVACTINESTIM_vidEntryInit();
   VLVACTINMNG_vidEntryInit();
   VLVACTINMON_vidEntryInit();
   VSSNWDMTRACV_vidEntryInit();
   
}

/******************************************************************************/
/* !FuncName    : KRN_vidINIT_ASW_POST                                        */
/* !Description : ASW function called at the end of the INIT task             */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINIT_ASW_POST(void)
{
   ISCAN_vidEve_Tx_108(); /* same call that Can_EvePostRst(); */
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_A_ASW                                    */
/* !Description : ASW function called by the S_DIAG_COIL_A_ASW task           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_A_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_B_ASW                                    */
/* !Description : ASW function called by the S_DIAG_COIL_B_ASW task           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_B_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_C_ASW                                    */
/* !Description : ASW function called by the S_DIAG_COIL_C_ASW task           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_C_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_D_ASW                                    */
/* !Description : ASW function called by the S_DIAG_COIL_D_ASW task           */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_D_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_A_C_ASW                                  */
/* !Description : ASW function called by the S_DIAG_COIL_A_C_ASW task         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_A_C_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidS_DIAG_COIL_B_D_ASW                                  */
/* !Description : ASW function called by the S_DIAG_COIL_B_D_ASW task         */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidS_DIAG_COIL_B_D_ASW(void)
{
}


/******************************************************************************/
/* !FuncName    : KRN_vidINCAM_DOWN_MODE_ASW                                  */
/* !Description : ASW function called by the KRN_vidInCamDwnModeEntry task    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINCAM_DOWN_MODE_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidINCAM_NORMAL_MODE_ASW                                */
/* !Description : ASW function called by the KRN_vidInCamNormalModeEntry task */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidINCAM_NORMAL_MODE_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidEXCAM_DOWN_MODE_ASW                                  */
/* !Description : ASW function called by the KRN_vidExCamDwnModeEntry task    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidEXCAM_DOWN_MODE_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidEXCAM_NORMAL_MODE_ASW                                */
/* !Description : ASW function called by the KRN_vidExCamNormalModeEntry task */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidEXCAM_NORMAL_MODE_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidCRK_DOWN_MODE_ASW                                    */
/* !Description : ASW function called by the KRN_vidCrkDwnModeEntry callback  */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidCRK_DOWN_MODE_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidCRK_NORMAL_MODE_ASW                                  */
/* !Description : ASW function called by the KRN_vidCrkNormalModeEntry        */
/*                callback                                                    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidCRK_NORMAL_MODE_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : KRN_vidSYNC_FOUND_ASW                                       */
/* !Description : ASW function called by the KRN_vidSyncFoundEntry callback   */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void KRN_vidSYNC_FOUND_ASW(void)
{
}

/******************************************************************************/
/* !FuncName    : EcuSt_EveFrstKOn_Wku                                        */
/* !Description : ASW function called by the S_IGK_ON task                    */
/*                                                                            */
/* !LastAuthor  : F. Tournaire                                                */
/******************************************************************************/
void EcuSt_EveFrstKOn_Wku(void)
{
    GDGAR_EveKeyOn();
    VlvAct_EveKOn_ExAcq();
    VlvAct_EveKOn_ExEndStop();
    VlvAct_EveKOn_ExServo();
    VlvAct_EveKOn_InAcq();
    VlvAct_EveKOn_InEndStop();
    VlvAct_EveKOn_InServo();
    Clu_EveKOn_CluSwtDiag();
    Fu_EveKOn_FuLvl();
    Fisa_EveKOn_FisaRFuDet();
    EngSt_EveKOn_EngStrtStop();
    EcuSt_EveKOn_EcuMng();
    EngSt_EveKOn_VehSt();
    EngSt_EveKOn_EngrunSt();
    Cf_FuPmp_EveKOn_Mng();
    PwrlRly_EveKOn_IfCmdDiag();
    PwrlRly_EveKOn_IfCmdDiagDio();
    RlyPwr_EveKOn_Mng();
    PwrRly_EveKOn_IfCmdDiag();
    PwrRly_EveKOn_IfCmdDiagDio();
    FuPmp_EveKOn_Mng();
    InjCrk_EveKOn_AntiFloodIf();
    Sync_EveKOn_CkDiagSts();
    Sync_EveKOn_EngSyncMng();
    Sync_EveKOn_InCmSts();
    Sync_EveKOn_ExCmSts();
    Sync_EveKOn_CmCkMon();
    AirPres_EveKOn_DiagAirExtPres();
    Thr_EveTestStart_ThrSftyMng();
}




#define TST_STOP_SEC_TST_CODE
#include "TST_MemMap.h"


/*-------------------------------- end of file -------------------------------*/
