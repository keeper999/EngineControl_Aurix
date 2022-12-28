/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichierXML : SC.h
* Description   : Gestion des diversites pour le projet EB2ADT
* Auteur        : E2PH/SEPH  F. BULTEAU
* Creation      : 04/07/2014
* Version       : 1.0
*******************************************************************************
* History
* Version   Author        Date          Modification
* 1.0       F. BULTEAU    04/07/2014    Création
*******************************************************************************/

#ifndef _SC_H_
#define _SC_H_

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Strate Moteur */
#define AFA_stEfc_SC                   								2U
#define AFA_stObs_SC                   								4U
#define AFA_stWait_SC                  								8U
#define CrkMgt_stCllTq_SC              								32U
#define CrkMgt_stOplTq_SC              								128U
#define EGRVlv_stEgrPrvtFoul_SC        								32U
#define Ext_noCylEng_SC                								3U
#define Ext_noCylRev_SC                								120U
#define Ext_rSqrtOfsRef2_SC            								3287636404U
#define Ext_rSqrtOfs_SC                								2374553200U
#define Ext_rSqrtGainRef2_SC           								87670590U
#define Ext_rSqrtGain_SC               								121384366U
#define Ext_stRun_SC                   								32U
#define Ext_stStall_SC                 								128U
#define Ext_stWaitRstrt_SC             								64U
#define InM_stDynCorMode_SC            								2U
#define InM_stPPurMode_SC              								4U
#define InM_stPresSenDftMod_SC         								8U
#define Eng_bEGRVlvCf_SC               								0
#define Eng_bExVlvCf_SC                								1
#define Eng_bInVlvCf_SC                								1
#define Eng_bSelDI_SC                  								1
#define Ext_stAcceTranLd_SC     									64U
#define Ext_stDeceTranLd_SC     									32U
#define Ext_stStabTranLd_SC     									128U
#define Eng_stOverRun_SC                							8
#define Ext_bEngTrbMod_SC              								1
#define Ext_bPresSen_pAirExt_SC         							1
#define Ext_bPresSen_pUsThr_SC          							1
#define Ext_stTypInjSysGDI_SC                                       1
#define FARSp_rMixtAfs_SC                                           4096U
#define InjSys_stAstAutn_SC                                         3
#define InjSys_stAstStrt_SC                                         1
#define InjSys_stAstSTT_SC                                          2
#define InjSys_stIni_SC                                             0
#define LamCtl_tiMinDlyEgTrf_SC                                     82
#define OxC_stMonORngCf_SC                                          3
#define TrbAct_bPresSenTrbActCf_SC                                  0
#define TrbAct_bTrbActCf_SC                                         1
#define TrbAct_facEgTrb_SC                                          -612032839

/* Strate GMP */
#define TraBVx_bDCTAcv_SC              								0
#define TraBVx_bHybAcv_SC              								0
#define TraBVx_bTypFu_SC               								1
#define OPTIM_TQADPCMP_CSMT_CGMT06_1806_INTERNAL_TORQUE_SC          1
#define VSCtl_bCtlCmdPTTqCf_SC          							0

/* Timers */
#define MaxTimer100us_SC               								4294967295
#define MaxTimer1ms_SC                 								4294967295
#define MaxTimer100ms_SC               								4294967295
#define MaxTimer1s_SC                  								4294967295
#define MaxTimer1min_SC                								4294967295

#endif    /* _SC_H_ */

