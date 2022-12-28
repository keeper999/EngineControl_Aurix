
#ifndef _EOMGSL_002_TEV_FCT_C_
#define _EOMGSL_002_TEV_FCT_C_
#include "library_lut.h"
#include "EOMGsl_002_TEV_fct.h"
#include "EOMGsl_002_calibrations.h"
#include "EOMGsl_003_calibrations.h"
#include "EOMGsl_nvm.h"
#define C00224_Mode_Blowby_dilution1_id (UInt8) 10 
#define C00225_Mode_De__T_importante_id (UInt8) 7 
#define C00226_Mode_Defaut_faible_id (UInt8) 4 
#define C00227_Mode_Defaut_eleve_id (UInt8) 3 
#define C00228_Mode_Arret_STT_id (UInt8) 5 
#define C00229_Mode_Opti_vide_id (UInt8) 8 
#define C0022_Modes_id (UInt8) 2 
#define C00230_Mode_Blowby_dilution2_id (UInt8) 11 
#define C00231_Mode_Ru__decalage_VVT_id (UInt8) 6 
#define C00232_Mode_Refuge_SIJ_id (UInt8) 1 
#define C00233_Mode_Webasto_id (UInt8) 9 
#define EOMGSL_START_SEC_GLOBAL_16BIT
#include "EOMGsl_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 EOMGsl_RE002_AirSys_rAirLdReq_in;AR_IF_GLOBAL_16BIT 
UInt16 EOMGsl_RE002_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT UInt16 
EOMGsl_RE002_ExM_pExMnfEstim_facVlvOvlp_in;AR_IF_GLOBAL_16BIT SInt16 
EOMGsl_RE002_Ext_agCkClsExVlvEstimRef0_in;AR_IF_GLOBAL_16BIT SInt16 
EOMGsl_RE002_Ext_agCkOpInVlvEstimRef0_in;AR_IF_GLOBAL_16BIT UInt16 
EOMGsl_RE002_Ext_nEng_in;AR_IF_GLOBAL_16BIT SInt16 EOMGsl_RE002_Ext_tCoMes_in;
AR_IF_GLOBAL_16BIT UInt16 EOMGsl_RE002_InM_pDsThrCor_in;
#define EOMGSL_STOP_SEC_GLOBAL_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_GLOBAL_32BIT
#include "EOMGsl_MemMap.h"
AR_IF_GLOBAL_32BIT UInt32 EOMGsl_RE002_Ext_dstVehTotMes_in;
#define EOMGSL_STOP_SEC_GLOBAL_32BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_GLOBAL_8BIT
#include "EOMGsl_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 EOMGsl_RE002_CoVSCtl_stAccP_in;AR_IF_GLOBAL_8BIT UInt8 
EOMGsl_RE002_Ext_stSysGas_in;AR_IF_GLOBAL_8BIT UInt8 
EOMGsl_RE002_TWCMgt_stHeatPhaReq_in;AR_IF_GLOBAL_8BIT UInt8 
EOMGsl_RE002_VlvSys_agCkClsExVlvReqRef0_in;AR_IF_GLOBAL_8BIT SInt8 
EOMGsl_RE002_VlvSys_agCkClsExVlvSatCorReq_in;AR_IF_GLOBAL_8BIT UInt8 
EOMGsl_RE002_VlvSys_agCkOpInVlvReqRef0_in;AR_IF_GLOBAL_8BIT SInt8 
EOMGsl_RE002_VlvSys_agCkOpInVlvSatCorReq_in;
#define EOMGSL_STOP_SEC_GLOBAL_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_GLOBAL_BOOLEAN
#include "EOMGsl_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean EOMGsl_RE002_AFA_bAcvSpcInjMod_in;
AR_IF_GLOBAL_BOOLEAN Boolean EOMGsl_RE002_Blby_bCfHiMfBlby_in;
AR_IF_GLOBAL_BOOLEAN Boolean EOMGsl_RE002_Blby_bDecPfu_in;AR_IF_GLOBAL_BOOLEAN 
Boolean EOMGsl_RE002_Blby_bIncIdlSpd_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_CoEs_bAcvVlvSysLockPosnSTTEs_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_CoHeat_bAcvHeatMgt_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_CoPt_bPrfModReq_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_Ext_bAcvSpcInjModProtECU_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_FRM_bAcvCmbModDft_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_FRM_bAcvCmbModHiLvlDft_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_FRM_bAcvNomModPrio_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_FRM_bAcvTCoMesDft_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_FRM_bInhCmbModPrf_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_InjSys_bAcvSpcInjModCmdInjr_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_InjSys_bAcvSpcInjModOvlp_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_InjSys_bAcvSpcInjMod_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_KnkMgt_bAcvVlvPosnRblReq_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_TPM_bInhOvbReq_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_TqSys_bAcvVlvSysOptmVac_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_TqSys_bEngNOnIdl_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_VlvAct_bAcvExServo_in;AR_IF_GLOBAL_BOOLEAN Boolean 
EOMGsl_RE002_VlvAct_bAcvInServo_in;
#define EOMGSL_STOP_SEC_GLOBAL_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_16BIT
#include "EOMGsl_MemMap.h"
static UInt16 z9467faf124a846a77bb3e7001ee28318;static UInt16 
z57b4bb83e2eaca8f9637bd2ffa0e5e16;static UInt16 
zd59c750c1e975f84783307b554107e0e;static UInt16 
z4b18d7211a20dc8403c42297e7b7c262;static UInt16 
zc7b2d9057c13816604019570194a00d8;static UInt16 
z759eb04c66e2d00c62a7c70b1aa61a86;static UInt16 
z08632c555cb065e5cf629701a12c66f9;static SInt16 
z0ef64ee666bb7d55c41058e6936739aa;static SInt16 
z16b7cdf5e54cebc041a3416f6cedc051;static UInt16 
z83f30abfc1163eb26f0e787e3c1af0d4;static SInt16 
zba820ea6a6a92237f50f525188c4b24a;
#define EOMGSL_STOP_SEC_VAR_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_32BIT
#include "EOMGsl_MemMap.h"
static UInt32 z04ce00eaaee8f0d86c3595c8e1c0bc70;
#define EOMGSL_STOP_SEC_VAR_32BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
static UInt8 zcef73afae6ffde57c5f66a2e220460ab;
#define EOMGSL_STOP_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
static Boolean z1b478ee9f1966502b640148eb8bd3d69;
#define EOMGSL_STOP_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_STOP_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
static Boolean z5f388d3df1c54b8266091563d45048b8;
#define EOMGSL_STOP_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
static UInt8 zd3df90cc2db82e5ba76785b9e2e2cae5;static UInt8 
zda7d5d1ede7aad9a93cdab2743586916;
#define EOMGSL_STOP_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
static Boolean zfc90f78b44087e778959e08e6a57d071;static Boolean 
z70e794736efead1b90c318e491f54eb5;static Boolean 
zf85a23132b8e32ec6bade9fd1335e94f;static Boolean 
z05d75e7a672a4ff2fa22080397f1fa68;static Boolean 
z98819e73ab2c0a839e0ad6f977ee2dfc;static Boolean 
z11b88b7474181b5794f89004769ac0ae;static Boolean 
z805bb6c38d2ee7370c5a84e344687ec3;static Boolean 
z4d65e94c3df1b8f348fbc71a0fa8ba04;static Boolean 
zdd1d4d96b2643af56598e4d211882866;static Boolean 
z15d0a650f676ec13c58a858024fc7058;
#define EOMGSL_STOP_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
static UInt8 z1c843c79bfdf14288d32b1b5e9907a37;static UInt8 
z3f5950dcef7537293221584892b76518;static UInt8 z3b5faa50d9829bfcb25545247beb3920
;static UInt8 ze71008f8893d0dcf184e1c5da9c9a072;static UInt8 
z7efcaa5468b3acf5461bb140e8993021;
#define EOMGSL_STOP_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "EOMGSL_MemMap.h"
AR_EXT_VAR_SAVED_Z1CST_32BIT EOMGsl_SNV_Z1_CST_32BIT EOMGsl_sNV_Z1_CST_32BIT;
#define EOMGSL_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "EOMGSL_MemMap.h"
#define EOMGSL_START_SEC_VAR_UNSPECIFIED
#include "EOMGsl_MemMap.h"
static struct ze36f568433bac459369363dc2771f9d0 
zb185a6ea22aa4a7b51c8f59af5e02ce8;
#define EOMGSL_STOP_SEC_VAR_UNSPECIFIED
#include "EOMGsl_MemMap.h"
static Void zf87ab759ec4e26edd72ea435f3f3dc14(Void);static Void 
zbefc806215a5e84cc9ab28047c96162f(Void);static Void 
z756d379d69070d05b4cc9ed4ca20f541(Void);static Void 
zc8ad7da64a3eaa2abcd8bf36cd21f922(Void);static Void 
za2bf8914781167d53a682568f4cbd3e7(Void);static Void 
z7cd91b6fcdfdada4657b6b193258870f(Void);static Void 
zd15ec8632355d8c47b9382eb165b43ae(Void);static Void 
z311aee2a7a2f9fae3f7719ca1a0e39ae(Void);static Void 
z3cad2e75c42f7299bf9df4d551d009ed(Void);static Void 
zf27d9f9c425aba193ee61435f1dd6438(Void);static Void 
z647566f665c22683b441e327f4b6450b(Void);static Void 
z14a67a7546c7a9b700179d6bcd815940(Void);static Void 
z702b2efc12bbddea0c7239b5ec6a5ccf(Void);static Void 
z4c651ae130567e96eab4e9165a56189f(Void);
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
Void EOMGsl_002_TEV_fct(Void){UInt16 z9ffea521053ec11550a862243b8fa10a;UInt16 
z7518f1b87c17a66dd56a6fa5f2982946;UInt16 z232e5f2c6e3ebfdf1d951180e3caf1e6;
UInt16 zefc6efd29ba9e853c3794e5de6a2ed26;UInt16 
zf541671086e43b7d54365324a7c1455b;UInt32 z65815b02d2612f2977423349eb1bca08;
UInt32 z7ed29fd2eebd5b648ce62f26a8deecb8;UInt32 
zc4b97f3e5adea773f69d21da532c4857;SInt16 zf48d06a23f15c7c7fc7422ad9d8504f6;
SInt16 z094c17d78fa9e1173c7b4087cddd218a;UInt16 
zcad0ccc3cc3747d652b15273278aede6;UInt16 z7d76aaf3bad89725ac0accf4bce2e2c4;
UInt16 z8a569c2baf898e6475721f174759755b;UInt16 
zc230f5b954b6011053e3174a43efb530;UInt16 z1f80939da490fec2f5e52d82a3ed04c8;
UInt16 z0e1bc2f2dd89c34c711fdd3cd4123bd8;UInt16 
zb4d4a2252957979e04ccbf6b1ab78d79;UInt16 z0f0b346d70d091f8f07de265ab31506d;
UInt16 z070ac1552105df1add3d082d7f3019a3;UInt16 
zc968a8c8a60090a167d46f56da90c23f;UInt16 z4698aab1f569f6d287820d2a8ea4a856;
UInt16 zc2ad12d996b2503c1cb5b67dafb60d1b;UInt16 
z5135401cd2b10291b1b028720829de19;UInt16 zd1dcacc1a6adfd9842c07fa4d59da096;
UInt16 zdba2920bf257d5f3215a638c1b3b221d;SInt16 
z4beac38e6f41d265cbc4a9effc39acc1;SInt16 z925e258d3d9abc023d8081f0fdce6884;
SInt16 z72973ec325f21988379acf0dc7cfafbb;SInt16 
zce05871497b75a80a788c90403736a2e;UInt16 z188ef18f136483a2797cdd44351f19db;
UInt16 zb94e0584362eea4a3b110425f24ab6fd;UInt16 
zaf773b57194ffed71db5ecee9a571201;UInt16 z04e661c38bb6fe8f872c091c115b8eae;
SInt16 zdffeec7feb0c9c8e7d5d2b23d32a0ea6;SInt16 
z1fbc13a450b6f596a200f9e18f38601d;UInt16 zd8c126a080585bdeb73a57166f9b8f74;
UInt16 zebae56d2e4f1f9e25826c4794bdef7f6;UInt16 
z324bd06375435ee8660719550183e6a0;UInt16 z047e2a999764709320907bfcdf6969f3;
UInt16 zefe6aea985b576914f2f27afd0f14d54;SInt16 
z1e939266f64c3c3cd148186084991eab;SInt16 ze29481ca0115fbc3beb7a4f4d03c9f12;
SInt16 zb3c168b4d94e74fbcc728430b71e2b46;SInt16 
z0496cd7b5b4a746c598ac28d848bc2ff;UInt8 zf5d681949fd9c94f1f2e20f1cca586af;UInt8 
z4076e8d9f65d70a677c88c3ac67c0bd1;UInt8 zdf761e95f43b63864b7942bfaa64e50c;
Boolean z6281d1b4221a1350e30eedae1670f708;Boolean 
z81216a9b128ee23b075afbe0daa6ba92;Boolean z1014f2ef78e9bd89cf97b0a489151c31;
Boolean z89cb3d3f406b769b4f44f8f64c7e8f41;UInt16 
ze5aed13a5b01444f5678c6825a5c30fc;if(z805bb6c38d2ee7370c5a84e344687ec3){SInt16 
z4c249156c46638343cbea4ed46c2d621;if(EOM_nEngThdHiModPrf_C!=
EOM_nEngThdLoModPrf_C){z4c249156c46638343cbea4ed46c2d621=(SInt16)(((UInt16)(
EOMGsl_RE002_Ext_nEng_in<=EOM_nEngThdLoModPrf_C))<<14);}else{
z4c249156c46638343cbea4ed46c2d621=(SInt16)(((UInt16)(EOMGsl_RE002_Ext_nEng_in<
EOM_nEngThdLoModPrf_C))<<14);}z1014f2ef78e9bd89cf97b0a489151c31=(
z11b88b7474181b5794f89004769ac0ae||(EOM_nEngThdHiModPrf_C<=
EOMGsl_RE002_Ext_nEng_in))&&(!(z4c249156c46638343cbea4ed46c2d621));}else{
z1014f2ef78e9bd89cf97b0a489151c31=1;}TabIdxS50T513((const UInt16*)
EOM_rAirLdCor_A,8,EOMGsl_RE002_EngM_rAirLdCor_in,&(
z7efcaa5468b3acf5461bb140e8993021),&(zf541671086e43b7d54365324a7c1455b));
TabIdxS50T513((const UInt16*)EOM_nEng_A,8,EOMGsl_RE002_Ext_nEng_in,&(
ze71008f8893d0dcf184e1c5da9c9a072),&(zefc6efd29ba9e853c3794e5de6a2ed26));if(
z05d75e7a672a4ff2fa22080397f1fa68){SInt32 zd9a2c2c61e914139df23ca8153986ac8;
zd9a2c2c61e914139df23ca8153986ac8=(SInt32)(((UInt32)
EOMGsl_RE002_AirSys_rAirLdReq_in)-((UInt32)EOMGsl_RE002_EngM_rAirLdCor_in));
EOM_deltaRatAirLdThdPrf_MP=Tab2DIntp2I1T33285((const SInt32*)&(
EOM_deltaRatAirLdThdModPrf_M[0][0]),8,z7efcaa5468b3acf5461bb140e8993021,
zf541671086e43b7d54365324a7c1455b,ze71008f8893d0dcf184e1c5da9c9a072,
zefc6efd29ba9e853c3794e5de6a2ed26);z81216a9b128ee23b075afbe0daa6ba92=(
zf85a23132b8e32ec6bade9fd1335e94f||(zd9a2c2c61e914139df23ca8153986ac8>(
EOM_deltaRatAirLdThdPrf_MP+EOM_deltaRatAirThdHysModPrf_C)))&&(!(
zd9a2c2c61e914139df23ca8153986ac8<EOM_deltaRatAirLdThdPrf_MP));}else{
z81216a9b128ee23b075afbe0daa6ba92=1;}if(z70e794736efead1b90c318e491f54eb5){
z6281d1b4221a1350e30eedae1670f708=(zfc90f78b44087e778959e08e6a57d071||(
EOM_nIdlEngLoThd_C>=EOMGsl_RE002_Ext_nEng_in))&&(!(EOMGsl_RE002_Ext_nEng_in>=
EOM_nIdlEngHiThd_C));}else{z6281d1b4221a1350e30eedae1670f708=1;}if(
EOMGsl_RE002_TqSys_bAcvVlvSysOptmVac_in){z047e2a999764709320907bfcdf6969f3=0;}
else{z047e2a999764709320907bfcdf6969f3=(UInt16)(
z83f30abfc1163eb26f0e787e3c1af0d4+1);}zefe6aea985b576914f2f27afd0f14d54=(UInt16)
((((UInt32)EOM_tiDlyOffVlvVacModInjSys_C)*52429)>>18);if(
z047e2a999764709320907bfcdf6969f3<zefe6aea985b576914f2f27afd0f14d54){
z324bd06375435ee8660719550183e6a0=z047e2a999764709320907bfcdf6969f3;}else{
z324bd06375435ee8660719550183e6a0=zefe6aea985b576914f2f27afd0f14d54;}
TabIdxS50T513((const UInt16*)EOM_nEng_A,8,EOMGsl_RE002_Ext_nEng_in,&(
z3b5faa50d9829bfcb25545247beb3920),&(z232e5f2c6e3ebfdf1d951180e3caf1e6));
z094c17d78fa9e1173c7b4087cddd218a=(SInt16)(((SInt16)(((UInt16)(SInt16)(((UInt16)
(((UInt16)EOMGsl_RE002_VlvSys_agCkOpInVlvReqRef0_in)*3))-((UInt16)(((SInt16)
EOMGsl_RE002_VlvSys_agCkOpInVlvSatCorReq_in)*3))))-384))>>1);if(
zd3df90cc2db82e5ba76785b9e2e2cae5!=0){zdffeec7feb0c9c8e7d5d2b23d32a0ea6=
z094c17d78fa9e1173c7b4087cddd218a;}else{zdffeec7feb0c9c8e7d5d2b23d32a0ea6=
z0ef64ee666bb7d55c41058e6936739aa;}z4beac38e6f41d265cbc4a9effc39acc1=(SInt16)(((
SInt16)(EOM_deltaAgCkHysInVlv_C>>1))+z094c17d78fa9e1173c7b4087cddd218a);
z925e258d3d9abc023d8081f0fdce6884=(SInt16)(((UInt16)
z094c17d78fa9e1173c7b4087cddd218a)-((UInt16)(SInt16)(EOM_deltaAgCkHysInVlv_C>>1)
));if((zdffeec7feb0c9c8e7d5d2b23d32a0ea6<=z4beac38e6f41d265cbc4a9effc39acc1)&&(
zdffeec7feb0c9c8e7d5d2b23d32a0ea6>=z925e258d3d9abc023d8081f0fdce6884)){
EOM_agCkDeltaPosnInVlvReq_MP=zdffeec7feb0c9c8e7d5d2b23d32a0ea6;}else{if(
zdffeec7feb0c9c8e7d5d2b23d32a0ea6>z4beac38e6f41d265cbc4a9effc39acc1){
EOM_agCkDeltaPosnInVlvReq_MP=z4beac38e6f41d265cbc4a9effc39acc1;}else{
EOM_agCkDeltaPosnInVlvReq_MP=z925e258d3d9abc023d8081f0fdce6884;}}TabIdxS50T516((
const SInt16*)EOM_agCkDeltaPosnInVlvReq_A,8,EOM_agCkDeltaPosnInVlvReq_MP,&(
z1c843c79bfdf14288d32b1b5e9907a37),&(z9ffea521053ec11550a862243b8fa10a));
zf5d681949fd9c94f1f2e20f1cca586af=Tab2DIntp2I1T33280((const UInt8*)&(
EOM_bDeltaPosnInVlvReq_M[0][0]),8,z3b5faa50d9829bfcb25545247beb3920,
z232e5f2c6e3ebfdf1d951180e3caf1e6,z1c843c79bfdf14288d32b1b5e9907a37,
z9ffea521053ec11550a862243b8fa10a);if(zf5d681949fd9c94f1f2e20f1cca586af!=0){
z04e661c38bb6fe8f872c091c115b8eae=0;}else{z04e661c38bb6fe8f872c091c115b8eae=(
UInt16)(z08632c555cb065e5cf629701a12c66f9+1);}zebae56d2e4f1f9e25826c4794bdef7f6=
(UInt16)(EOM_tiDlyOffDeltaPosnInVlv_C/EOM_tiSdlFast_C);if(
z04e661c38bb6fe8f872c091c115b8eae<zebae56d2e4f1f9e25826c4794bdef7f6){
zaf773b57194ffed71db5ecee9a571201=z04e661c38bb6fe8f872c091c115b8eae;}else{
zaf773b57194ffed71db5ecee9a571201=zebae56d2e4f1f9e25826c4794bdef7f6;}
zf48d06a23f15c7c7fc7422ad9d8504f6=(SInt16)(((SInt16)(((UInt16)(SInt16)(((UInt16)
(((UInt16)EOMGsl_RE002_VlvSys_agCkClsExVlvReqRef0_in)*3))-((UInt16)(((SInt16)
EOMGsl_RE002_VlvSys_agCkClsExVlvSatCorReq_in)*3))))-384))>>1);if(
zda7d5d1ede7aad9a93cdab2743586916!=0){z1fbc13a450b6f596a200f9e18f38601d=
zf48d06a23f15c7c7fc7422ad9d8504f6;}else{z1fbc13a450b6f596a200f9e18f38601d=
z16b7cdf5e54cebc041a3416f6cedc051;}z72973ec325f21988379acf0dc7cfafbb=(SInt16)(((
SInt16)(EOM_deltaAgCkHysExVlv_C>>1))+zf48d06a23f15c7c7fc7422ad9d8504f6);
zce05871497b75a80a788c90403736a2e=(SInt16)(((UInt16)
zf48d06a23f15c7c7fc7422ad9d8504f6)-((UInt16)(SInt16)(EOM_deltaAgCkHysExVlv_C>>1)
));if((z1fbc13a450b6f596a200f9e18f38601d<=z72973ec325f21988379acf0dc7cfafbb)&&(
z1fbc13a450b6f596a200f9e18f38601d>=zce05871497b75a80a788c90403736a2e)){
EOM_agCkDeltaPosnExVlvReq_MP=z1fbc13a450b6f596a200f9e18f38601d;}else{if(
z1fbc13a450b6f596a200f9e18f38601d>z72973ec325f21988379acf0dc7cfafbb){
EOM_agCkDeltaPosnExVlvReq_MP=z72973ec325f21988379acf0dc7cfafbb;}else{
EOM_agCkDeltaPosnExVlvReq_MP=zce05871497b75a80a788c90403736a2e;}}TabIdxS50T516((
const SInt16*)EOM_agCkDeltaPosnExVlvReq_A,8,EOM_agCkDeltaPosnExVlvReq_MP,&(
z3f5950dcef7537293221584892b76518),&(z7518f1b87c17a66dd56a6fa5f2982946));
z4076e8d9f65d70a677c88c3ac67c0bd1=Tab2DIntp2I1T33280((const UInt8*)&(
EOM_bDeltaPosnExVlvReq_M[0][0]),8,z3b5faa50d9829bfcb25545247beb3920,
z232e5f2c6e3ebfdf1d951180e3caf1e6,z3f5950dcef7537293221584892b76518,
z7518f1b87c17a66dd56a6fa5f2982946);if(z4076e8d9f65d70a677c88c3ac67c0bd1!=0){
zb94e0584362eea4a3b110425f24ab6fd=0;}else{zb94e0584362eea4a3b110425f24ab6fd=(
UInt16)(z759eb04c66e2d00c62a7c70b1aa61a86+1);}zd8c126a080585bdeb73a57166f9b8f74=
(UInt16)(EOM_tiDlyOffDeltaPosnExVlv_C/EOM_tiSdlFast_C);if(
zb94e0584362eea4a3b110425f24ab6fd<zd8c126a080585bdeb73a57166f9b8f74){
z188ef18f136483a2797cdd44351f19db=zb94e0584362eea4a3b110425f24ab6fd;}else{
z188ef18f136483a2797cdd44351f19db=zd8c126a080585bdeb73a57166f9b8f74;}if(
EOMGsl_RE002_KnkMgt_bAcvVlvPosnRblReq_in){zd1dcacc1a6adfd9842c07fa4d59da096=0;}
else{zd1dcacc1a6adfd9842c07fa4d59da096=(UInt16)(
zc7b2d9057c13816604019570194a00d8+1);}zdba2920bf257d5f3215a638c1b3b221d=(UInt16)
(EOM_tiDlyOffVlvRblModInjSys_C/EOM_tiSdlFast_C);if(
zd1dcacc1a6adfd9842c07fa4d59da096<zdba2920bf257d5f3215a638c1b3b221d){
z5135401cd2b10291b1b028720829de19=zd1dcacc1a6adfd9842c07fa4d59da096;}else{
z5135401cd2b10291b1b028720829de19=zdba2920bf257d5f3215a638c1b3b221d;}if(
EOMGsl_RE002_Ext_bAcvSpcInjModProtECU_in){z0f0b346d70d091f8f07de265ab31506d=0;}
else{z0f0b346d70d091f8f07de265ab31506d=(UInt16)(
z4b18d7211a20dc8403c42297e7b7c262+1);}zc2ad12d996b2503c1cb5b67dafb60d1b=(UInt16)
(EOM_tiDlyOffSpcInjModInjSys4_C/EOM_tiSdlFast_C);if(
z0f0b346d70d091f8f07de265ab31506d<zc2ad12d996b2503c1cb5b67dafb60d1b){
zb4d4a2252957979e04ccbf6b1ab78d79=z0f0b346d70d091f8f07de265ab31506d;}else{
zb4d4a2252957979e04ccbf6b1ab78d79=zc2ad12d996b2503c1cb5b67dafb60d1b;}if(
EOMGsl_RE002_InjSys_bAcvSpcInjModCmdInjr_in){z0e1bc2f2dd89c34c711fdd3cd4123bd8=0
;}else{z0e1bc2f2dd89c34c711fdd3cd4123bd8=(UInt16)(
zd59c750c1e975f84783307b554107e0e+1);}z4698aab1f569f6d287820d2a8ea4a856=(UInt16)
(EOM_tiDlyOffSpcInjModInjSys3_C/EOM_tiSdlFast_C);if(
z0e1bc2f2dd89c34c711fdd3cd4123bd8<z4698aab1f569f6d287820d2a8ea4a856){
z1f80939da490fec2f5e52d82a3ed04c8=z0e1bc2f2dd89c34c711fdd3cd4123bd8;}else{
z1f80939da490fec2f5e52d82a3ed04c8=z4698aab1f569f6d287820d2a8ea4a856;}if(
EOMGsl_RE002_InjSys_bAcvSpcInjModOvlp_in){zc230f5b954b6011053e3174a43efb530=0;}
else{zc230f5b954b6011053e3174a43efb530=(UInt16)(
z57b4bb83e2eaca8f9637bd2ffa0e5e16+1);}zc968a8c8a60090a167d46f56da90c23f=(UInt16)
(EOM_tiDlyOffSpcInjModInjSys2_C/EOM_tiSdlFast_C);if(
zc230f5b954b6011053e3174a43efb530<zc968a8c8a60090a167d46f56da90c23f){
z8a569c2baf898e6475721f174759755b=zc230f5b954b6011053e3174a43efb530;}else{
z8a569c2baf898e6475721f174759755b=zc968a8c8a60090a167d46f56da90c23f;}if(
EOMGsl_RE002_InjSys_bAcvSpcInjMod_in){z7d76aaf3bad89725ac0accf4bce2e2c4=0;}else{
z7d76aaf3bad89725ac0accf4bce2e2c4=(UInt16)(z9467faf124a846a77bb3e7001ee28318+1);
}z070ac1552105df1add3d082d7f3019a3=(UInt16)(EOM_tiDlyOffSpcInjModInjSys1_C/
EOM_tiSdlFast_C);if(z7d76aaf3bad89725ac0accf4bce2e2c4<
z070ac1552105df1add3d082d7f3019a3){zcad0ccc3cc3747d652b15273278aede6=
z7d76aaf3bad89725ac0accf4bce2e2c4;}else{zcad0ccc3cc3747d652b15273278aede6=
z070ac1552105df1add3d082d7f3019a3;}EOM_bLdTranModReqRaw_MP=
EOMGsl_RE002_CoPt_bPrfModReq_in&&(!(EOMGsl_RE002_TPM_bInhOvbReq_in))&&(
EOMGsl_RE002_Ext_tCoMes_in>EOM_tCoThdCmbModPrf_C)&&
z81216a9b128ee23b075afbe0daa6ba92&&(((SInt32)(((UInt32)
EOMGsl_RE002_InM_pDsThrCor_in)-((UInt32)
EOMGsl_RE002_ExM_pExMnfEstim_facVlvOvlp_in)))>EOM_deltaPThdCmbModPrf_C)&&
z1014f2ef78e9bd89cf97b0a489151c31&&EOM_bAcvCmbPrfMod_C&&(!(
EOMGsl_RE002_FRM_bInhCmbModPrf_in));if(EOM_bLdTranModReqRaw_MP&&(!(
z98819e73ab2c0a839e0ad6f977ee2dfc))){z65815b02d2612f2977423349eb1bca08=0;}else{
if(EOM_bAcvTmpSecu_C){UInt32 z206d3d7296b470a25d1dfb411dc2d6f1;
ze5aed13a5b01444f5678c6825a5c30fc=EOM_tiSdlFast_C;if(
ze5aed13a5b01444f5678c6825a5c30fc){z206d3d7296b470a25d1dfb411dc2d6f1=(UInt32)
ze5aed13a5b01444f5678c6825a5c30fc;}else{z206d3d7296b470a25d1dfb411dc2d6f1=0;}
z65815b02d2612f2977423349eb1bca08=z206d3d7296b470a25d1dfb411dc2d6f1+
z04ce00eaaee8f0d86c3595c8e1c0bc70;}else{z65815b02d2612f2977423349eb1bca08=
z04ce00eaaee8f0d86c3595c8e1c0bc70;}}if(zdd1d4d96b2643af56598e4d211882866){
z5f388d3df1c54b8266091563d45048b8=z15d0a650f676ec13c58a858024fc7058;}else{
z5f388d3df1c54b8266091563d45048b8=EOMGsl_sNV_Z1_CST_32BIT.Ext_dstVehTotMes_NV>=
EOM_dstVehFoutMod_C;}RE002_EOM_bFdoutModReq_out=
z5f388d3df1c54b8266091563d45048b8;if(EOM_bManEngModReq_C){EOMGSL_stEngModReq=
EOM_stManEngModReq_C;}else{UInt8 ze78d699636398d12d9dd4d0b17a33b1f;UInt8 
z92abe2715a9b9119536af034eef2b936;UInt8 z6b21bd672d1765c32da1ddeed6fe0be4;UInt8 
z8a4aa00da273441d7a4ff28676209d89;UInt8 z82de086ef452405655ad84ade051594a;UInt8 
z194d7f0e595c482ecc6cee669d008c78;UInt8 z85cc3bdc37318841103376163d22f41f;UInt8 
z15a2b8e2fd7538ec04d3ff86a9a6432c;UInt8 z605746aa18f4870d2b6de99350c2bbb3;UInt8 
zbdba1e144402f963c619ffd27394a336;UInt8 ze4700994aad3ca9cab49913c3fd567b3;UInt8 
zc92b7e0e6fcf3a51f6730ba87655c701;UInt8 zf6bf4387e0912cc9a51e5a285dfdcc96;UInt8 
zf8635f895ab6e3cc668d1c7f434ec2de[13];UInt8 z9fa28a9bfa43562a13245ecfa3963a8c;
zf6bf4387e0912cc9a51e5a285dfdcc96=EOM_noAcvNomModPrio_C*((UInt8)
EOMGsl_RE002_FRM_bAcvNomModPrio_in);EOM_bTWCHeatPhaModReq=
EOMGsl_RE002_TWCMgt_stHeatPhaReq_in!=0;z92abe2715a9b9119536af034eef2b936=
EOM_noTWCHeatPhaPrio_C*((UInt8)EOM_bTWCHeatPhaModReq);if(EOM_bInhGasModReq_C){
EOM_bGasModReq=0;}else{Boolean zf8e009de91e4ac13fc266b9ed419698d;switch(
EOMGsl_RE002_Ext_stSysGas_in){case 0:{zf8e009de91e4ac13fc266b9ed419698d=1;break;
}case 1:{zf8e009de91e4ac13fc266b9ed419698d=0;break;}case 2:{
zf8e009de91e4ac13fc266b9ed419698d=1;break;}case 3:{
zf8e009de91e4ac13fc266b9ed419698d=0;break;}}EOM_bGasModReq=
zf8e009de91e4ac13fc266b9ed419698d;}z85cc3bdc37318841103376163d22f41f=
EOM_noGasPrio_C*((UInt8)EOM_bGasModReq);if(EOM_bInhSpcInjModReq_C){
EOM_bAcvSpcInjModReq=0;}else{EOM_bAcvSpcInjModReq=
EOMGsl_RE002_AFA_bAcvSpcInjMod_in||EOMGsl_RE002_InjSys_bAcvSpcInjMod_in||(
z7d76aaf3bad89725ac0accf4bce2e2c4<=z070ac1552105df1add3d082d7f3019a3)||
EOMGsl_RE002_InjSys_bAcvSpcInjModOvlp_in||(zc230f5b954b6011053e3174a43efb530<=
zc968a8c8a60090a167d46f56da90c23f)||EOMGsl_RE002_InjSys_bAcvSpcInjModCmdInjr_in
||(z0e1bc2f2dd89c34c711fdd3cd4123bd8<=z4698aab1f569f6d287820d2a8ea4a856)||
EOMGsl_RE002_Ext_bAcvSpcInjModProtECU_in||(z0f0b346d70d091f8f07de265ab31506d<=
zc2ad12d996b2503c1cb5b67dafb60d1b);}z194d7f0e595c482ecc6cee669d008c78=
EOM_noSpcInjPrio_C*((UInt8)EOM_bAcvSpcInjModReq);
ze78d699636398d12d9dd4d0b17a33b1f=EOM_noSTTStopPrio_C*((UInt8)
EOMGsl_RE002_CoEs_bAcvVlvSysLockPosnSTTEs_in);z15a2b8e2fd7538ec04d3ff86a9a6432c=
EOM_noDftPrio_C*((UInt8)EOMGsl_RE002_FRM_bAcvCmbModDft_in);
z605746aa18f4870d2b6de99350c2bbb3=EOM_noHiLvlDftPrio_C*((UInt8)
EOMGsl_RE002_FRM_bAcvCmbModHiLvlDft_in);if(
EOMGsl_RE002_CoEs_bAcvVlvSysLockPosnSTTEs_in){EOM_bDeltaPosnVlvModReq=0;}else{
Boolean z9c5eabbc20a9112b58b62af6d04a2059;Boolean 
z9e231536577b92bea9fcf4030d24b08b;if(EOMGsl_RE002_VlvAct_bAcvInServo_in){
z9c5eabbc20a9112b58b62af6d04a2059=zf5d681949fd9c94f1f2e20f1cca586af||(
z04e661c38bb6fe8f872c091c115b8eae<=zebae56d2e4f1f9e25826c4794bdef7f6);}else{
z9c5eabbc20a9112b58b62af6d04a2059=0;}if(EOMGsl_RE002_VlvAct_bAcvExServo_in){
z9e231536577b92bea9fcf4030d24b08b=z4076e8d9f65d70a677c88c3ac67c0bd1||(
zb94e0584362eea4a3b110425f24ab6fd<=zd8c126a080585bdeb73a57166f9b8f74);}else{
z9e231536577b92bea9fcf4030d24b08b=0;}EOM_bDeltaPosnVlvModReq=
z9c5eabbc20a9112b58b62af6d04a2059||z9e231536577b92bea9fcf4030d24b08b;}
zbdba1e144402f963c619ffd27394a336=EOM_noDeltaPosnVlvPrio_C*((UInt8)
EOM_bDeltaPosnVlvModReq);if(EOM_bInhVlvPosnRblModReq_C){EOM_bVlvPosnRblModReq=0;
}else{EOM_bVlvPosnRblModReq=EOMGsl_RE002_KnkMgt_bAcvVlvPosnRblReq_in||(
zd1dcacc1a6adfd9842c07fa4d59da096<=zdba2920bf257d5f3215a638c1b3b221d);}
ze4700994aad3ca9cab49913c3fd567b3=EOM_noVlvposnRblPrio_C*((UInt8)
EOM_bVlvPosnRblModReq);if(EOM_bInhVlvPosnVacModReq_C){EOM_bVlvPosnVacModReq=0;}
else{EOM_bVlvPosnVacModReq=EOMGsl_RE002_TqSys_bAcvVlvSysOptmVac_in||(
z047e2a999764709320907bfcdf6969f3<=zefe6aea985b576914f2f27afd0f14d54);}
zc92b7e0e6fcf3a51f6730ba87655c701=EOM_noVlvposnVacPrio_C*((UInt8)
EOM_bVlvPosnVacModReq);z6b21bd672d1765c32da1ddeed6fe0be4=
EOM_noCoHeat_bAcvHeatPrio_C*((UInt8)EOMGsl_RE002_CoHeat_bAcvHeatMgt_in);
z8a4aa00da273441d7a4ff28676209d89=EOM_noBlby_bdilution1Prio_C*((UInt8)(
EOMGsl_RE002_Blby_bCfHiMfBlby_in||EOMGsl_RE002_Blby_bDecPfu_in));
z82de086ef452405655ad84ade051594a=EOM_noBlby_bdilution2Prio_C*((UInt8)
EOMGsl_RE002_Blby_bIncIdlSpd_in);if(zf6bf4387e0912cc9a51e5a285dfdcc96>
z92abe2715a9b9119536af034eef2b936){EOM_noPrioMax_MP=
zf6bf4387e0912cc9a51e5a285dfdcc96;}else{EOM_noPrioMax_MP=
z92abe2715a9b9119536af034eef2b936;}if(z85cc3bdc37318841103376163d22f41f>
EOM_noPrioMax_MP){EOM_noPrioMax_MP=z85cc3bdc37318841103376163d22f41f;}if(
z194d7f0e595c482ecc6cee669d008c78>EOM_noPrioMax_MP){EOM_noPrioMax_MP=
z194d7f0e595c482ecc6cee669d008c78;}if(ze78d699636398d12d9dd4d0b17a33b1f>
EOM_noPrioMax_MP){EOM_noPrioMax_MP=ze78d699636398d12d9dd4d0b17a33b1f;}if(
z15a2b8e2fd7538ec04d3ff86a9a6432c>EOM_noPrioMax_MP){EOM_noPrioMax_MP=
z15a2b8e2fd7538ec04d3ff86a9a6432c;}if(z605746aa18f4870d2b6de99350c2bbb3>
EOM_noPrioMax_MP){EOM_noPrioMax_MP=z605746aa18f4870d2b6de99350c2bbb3;}if(
zbdba1e144402f963c619ffd27394a336>EOM_noPrioMax_MP){EOM_noPrioMax_MP=
zbdba1e144402f963c619ffd27394a336;}if(ze4700994aad3ca9cab49913c3fd567b3>
EOM_noPrioMax_MP){EOM_noPrioMax_MP=ze4700994aad3ca9cab49913c3fd567b3;}if(
zc92b7e0e6fcf3a51f6730ba87655c701>EOM_noPrioMax_MP){EOM_noPrioMax_MP=
zc92b7e0e6fcf3a51f6730ba87655c701;}if(z6b21bd672d1765c32da1ddeed6fe0be4>
EOM_noPrioMax_MP){EOM_noPrioMax_MP=z6b21bd672d1765c32da1ddeed6fe0be4;}if(
z8a4aa00da273441d7a4ff28676209d89>EOM_noPrioMax_MP){EOM_noPrioMax_MP=
z8a4aa00da273441d7a4ff28676209d89;}if(z82de086ef452405655ad84ade051594a>
EOM_noPrioMax_MP){EOM_noPrioMax_MP=z82de086ef452405655ad84ade051594a;}if(
EOM_noAcvNomModPrio_C==EOM_noPrioMax_MP){z9fa28a9bfa43562a13245ecfa3963a8c=0;}
else{z9fa28a9bfa43562a13245ecfa3963a8c=0;}if(EOM_noGasPrio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[2]=2;}else{zf8635f895ab6e3cc668d1c7f434ec2de[2
]=0;}if(EOM_noSpcInjPrio_C==EOM_noPrioMax_MP){zf8635f895ab6e3cc668d1c7f434ec2de[
3]=3;}else{zf8635f895ab6e3cc668d1c7f434ec2de[3]=0;}if(EOM_noSTTStopPrio_C==
EOM_noPrioMax_MP){zf8635f895ab6e3cc668d1c7f434ec2de[4]=4;}else{
zf8635f895ab6e3cc668d1c7f434ec2de[4]=0;}if(EOM_noDftPrio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[5]=5;}else{zf8635f895ab6e3cc668d1c7f434ec2de[5
]=0;}if(EOM_noHiLvlDftPrio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[6]=6;}else{zf8635f895ab6e3cc668d1c7f434ec2de[6
]=0;}if(EOM_noDeltaPosnVlvPrio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[7]=7;}else{zf8635f895ab6e3cc668d1c7f434ec2de[7
]=0;}if(EOM_noVlvposnRblPrio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[8]=8;}else{zf8635f895ab6e3cc668d1c7f434ec2de[8
]=0;}if(EOM_noVlvposnVacPrio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[9]=9;}else{zf8635f895ab6e3cc668d1c7f434ec2de[9
]=0;}if(EOM_noCoHeat_bAcvHeatPrio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[10]=10;}else{zf8635f895ab6e3cc668d1c7f434ec2de
[10]=0;}if(EOM_noBlby_bdilution1Prio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[11]=11;}else{zf8635f895ab6e3cc668d1c7f434ec2de
[11]=0;}if(EOM_noBlby_bdilution2Prio_C==EOM_noPrioMax_MP){
zf8635f895ab6e3cc668d1c7f434ec2de[12]=12;}else{zf8635f895ab6e3cc668d1c7f434ec2de
[12]=0;}z9fa28a9bfa43562a13245ecfa3963a8c+=(EOM_noTWCHeatPhaPrio_C==
EOM_noPrioMax_MP);z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[2];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[3];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[4];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[5];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[6];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[7];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[8];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[9];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[10];z9fa28a9bfa43562a13245ecfa3963a8c+=
zf8635f895ab6e3cc668d1c7f434ec2de[11];EOMGSL_stEngModReq=(UInt8)(
z9fa28a9bfa43562a13245ecfa3963a8c+zf8635f895ab6e3cc668d1c7f434ec2de[12]);}
z89cb3d3f406b769b4f44f8f64c7e8f41=(EOMGsl_RE002_CoVSCtl_stAccP_in==0)&&
z6281d1b4221a1350e30eedae1670f708;switch(EOM_idxIdlTypSel_C){case 0:{
EOM_bIdlModReq=z89cb3d3f406b769b4f44f8f64c7e8f41&&
EOMGsl_RE002_TqSys_bEngNOnIdl_in;break;}case 1:{EOM_bIdlModReq=
z89cb3d3f406b769b4f44f8f64c7e8f41||EOMGsl_RE002_TqSys_bEngNOnIdl_in;break;}case 
2:{EOM_bIdlModReq=z89cb3d3f406b769b4f44f8f64c7e8f41;break;}case 3:{
EOM_bIdlModReq=EOMGsl_RE002_TqSys_bEngNOnIdl_in;break;}}if(
z65815b02d2612f2977423349eb1bca08){z7ed29fd2eebd5b648ce62f26a8deecb8=
z65815b02d2612f2977423349eb1bca08;}else{z7ed29fd2eebd5b648ce62f26a8deecb8=0;}if(
127500<z7ed29fd2eebd5b648ce62f26a8deecb8){zc4b97f3e5adea773f69d21da532c4857=
127500;}else{zc4b97f3e5adea773f69d21da532c4857=z7ed29fd2eebd5b648ce62f26a8deecb8
;}ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)(zc4b97f3e5adea773f69d21da532c4857/
500);if(((UInt16)EOM_tiDlyInhCmbPrfMod_C)<ze5aed13a5b01444f5678c6825a5c30fc){
zdf761e95f43b63864b7942bfaa64e50c=EOM_tiDlyInhCmbPrfMod_C;}else{
zdf761e95f43b63864b7942bfaa64e50c=(UInt8)ze5aed13a5b01444f5678c6825a5c30fc;}if(
EOMGsl_RE002_FRM_bAcvTCoMesDft_in){z1e939266f64c3c3cd148186084991eab=
EOM_tCoDft_C;}else{z1e939266f64c3c3cd148186084991eab=EOMGsl_RE002_Ext_tCoMes_in;
}if(z4d65e94c3df1b8f348fbc71a0fa8ba04){z0496cd7b5b4a746c598ac28d848bc2ff=
z1e939266f64c3c3cd148186084991eab;}else{z0496cd7b5b4a746c598ac28d848bc2ff=
zba820ea6a6a92237f50f525188c4b24a;}ze29481ca0115fbc3beb7a4f4d03c9f12=(SInt16)(((
SInt16)(EOM_tCoHysBand1_C>>1))+z1e939266f64c3c3cd148186084991eab);
zb3c168b4d94e74fbcc728430b71e2b46=(SInt16)(((UInt16)
z1e939266f64c3c3cd148186084991eab)-((UInt16)(SInt16)(EOM_tCoHysBand1_C>>1)));if(
(z0496cd7b5b4a746c598ac28d848bc2ff<=ze29481ca0115fbc3beb7a4f4d03c9f12)&&(
z0496cd7b5b4a746c598ac28d848bc2ff>=zb3c168b4d94e74fbcc728430b71e2b46)){
EOM_tCoCor_Cold=z0496cd7b5b4a746c598ac28d848bc2ff;}else{if(
z0496cd7b5b4a746c598ac28d848bc2ff>ze29481ca0115fbc3beb7a4f4d03c9f12){
EOM_tCoCor_Cold=ze29481ca0115fbc3beb7a4f4d03c9f12;}else{EOM_tCoCor_Cold=
zb3c168b4d94e74fbcc728430b71e2b46;}}EOM_bColdModReq=EOM_tCoCor_Cold<=
EOM_ColdMod_C;switch(zb185a6ea22aa4a7b51c8f59af5e02ce8.
zf7e546f1593d7cf83116b8753807ad52){case C0022_Modes_id:{if((EOMGSL_stEngModReq==
12)&&RE002_EOM_bEnaCmbModChg_in){z647566f665c22683b441e327f4b6450b();
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=(unsigned 
int)C00230_Mode_Blowby_dilution2_id;zcef73afae6ffde57c5f66a2e220460ab=18;
z1b478ee9f1966502b640148eb8bd3d69=1;}else{if((EOMGSL_stEngModReq==11)&&
RE002_EOM_bEnaCmbModChg_in){z647566f665c22683b441e327f4b6450b();
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=(unsigned 
int)C00224_Mode_Blowby_dilution1_id;zcef73afae6ffde57c5f66a2e220460ab=17;
z1b478ee9f1966502b640148eb8bd3d69=1;}else{if((EOMGSL_stEngModReq==10)&&
RE002_EOM_bEnaCmbModChg_in){z647566f665c22683b441e327f4b6450b();
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=(unsigned 
int)C00233_Mode_Webasto_id;zcef73afae6ffde57c5f66a2e220460ab=
EOM_stCoHeat_bAcvHeatMod_C;z1b478ee9f1966502b640148eb8bd3d69=1;}else{if((
EOMGSL_stEngModReq==7)&&RE002_EOM_bEnaCmbModChg_in){
z647566f665c22683b441e327f4b6450b();zb185a6ea22aa4a7b51c8f59af5e02ce8.
zf7e546f1593d7cf83116b8753807ad52=(unsigned int)C00225_Mode_De__T_importante_id;
zcef73afae6ffde57c5f66a2e220460ab=EOM_stDeltaPosnVlvMod_C;}else{if(
EOMGSL_stEngModReq==8){z647566f665c22683b441e327f4b6450b();
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=(unsigned 
int)C00231_Mode_Ru__decalage_VVT_id;zcef73afae6ffde57c5f66a2e220460ab=
EOM_stVlvPosnRblMod_C;z1b478ee9f1966502b640148eb8bd3d69=1;}else{if(
EOMGSL_stEngModReq==4){z647566f665c22683b441e327f4b6450b();
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=(unsigned 
int)C00228_Mode_Arret_STT_id;zcef73afae6ffde57c5f66a2e220460ab=14;
z1b478ee9f1966502b640148eb8bd3d69=1;}else{if(EOMGSL_stEngModReq==3){
z647566f665c22683b441e327f4b6450b();zb185a6ea22aa4a7b51c8f59af5e02ce8.
zf7e546f1593d7cf83116b8753807ad52=(unsigned int)C00232_Mode_Refuge_SIJ_id;
zcef73afae6ffde57c5f66a2e220460ab=13;z1b478ee9f1966502b640148eb8bd3d69=1;}else{
if(EOMGSL_stEngModReq==6){z647566f665c22683b441e327f4b6450b();
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=(unsigned 
int)C00227_Mode_Defaut_eleve_id;zcef73afae6ffde57c5f66a2e220460ab=16;
z1b478ee9f1966502b640148eb8bd3d69=1;}else{if(EOMGSL_stEngModReq==5){
z647566f665c22683b441e327f4b6450b();zb185a6ea22aa4a7b51c8f59af5e02ce8.
zf7e546f1593d7cf83116b8753807ad52=(unsigned int)C00226_Mode_Defaut_faible_id;
zcef73afae6ffde57c5f66a2e220460ab=15;z1b478ee9f1966502b640148eb8bd3d69=1;}else{
if(EOMGSL_stEngModReq==9){z647566f665c22683b441e327f4b6450b();
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=(unsigned 
int)C00229_Mode_Opti_vide_id;zcef73afae6ffde57c5f66a2e220460ab=
EOM_stVlvPosnVacMod_C;z1b478ee9f1966502b640148eb8bd3d69=1;}else{if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.zfcdf8c6c3dab3c42171a533e1fe93b90){if((
EOMGSL_stEngModReq!=1)&&RE002_EOM_bEnaCmbModChg_in){
z14a67a7546c7a9b700179d6bcd815940();zf87ab759ec4e26edd72ea435f3f3dc14();}else{if
(zb185a6ea22aa4a7b51c8f59af5e02ce8.z276a0795145a005af3f98426df018a2d){if(
EOMGsl_RE002_TWCMgt_stHeatPhaReq_in==2){z702b2efc12bbddea0c7239b5ec6a5ccf();
zd15ec8632355d8c47b9382eb165b43ae();}else{if(EOMGsl_RE002_TWCMgt_stHeatPhaReq_in
==3){z702b2efc12bbddea0c7239b5ec6a5ccf();zb185a6ea22aa4a7b51c8f59af5e02ce8.
z4f8f816adbe941c8b288d94bfa416694=1;zcef73afae6ffde57c5f66a2e220460ab=9;}else{if
(zb185a6ea22aa4a7b51c8f59af5e02ce8.zde23632acf3e2c6e8417410651265d2e){if((!(
EOM_bIdlModReq))&&RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
zde23632acf3e2c6e8417410651265d2e=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
z2aae937916457b45a39c39b316266201=1;zcef73afae6ffde57c5f66a2e220460ab=5;}}else{
if(zb185a6ea22aa4a7b51c8f59af5e02ce8.z2aae937916457b45a39c39b316266201){if(
EOM_bIdlModReq&&RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z2aae937916457b45a39c39b316266201=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
zde23632acf3e2c6e8417410651265d2e=1;zcef73afae6ffde57c5f66a2e220460ab=6;}}}}}}
else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.zc475841cb98be6ccf632215c74a26e2c){if(
EOMGsl_RE002_TWCMgt_stHeatPhaReq_in==1){z4c651ae130567e96eab4e9165a56189f();
z7cd91b6fcdfdada4657b6b193258870f();}else{if(EOMGsl_RE002_TWCMgt_stHeatPhaReq_in
==3){z4c651ae130567e96eab4e9165a56189f();zb185a6ea22aa4a7b51c8f59af5e02ce8.
z4f8f816adbe941c8b288d94bfa416694=1;zcef73afae6ffde57c5f66a2e220460ab=9;}else{if
(zb185a6ea22aa4a7b51c8f59af5e02ce8.z9c9e39781048e019c6c88cdd3e88aafa){if((!(
EOM_bIdlModReq))&&RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z9c9e39781048e019c6c88cdd3e88aafa=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
z6b3f53454c7e7e622335235b43b6a032=1;zcef73afae6ffde57c5f66a2e220460ab=7;}}else{
if(zb185a6ea22aa4a7b51c8f59af5e02ce8.z6b3f53454c7e7e622335235b43b6a032){if(
EOM_bIdlModReq&&RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z6b3f53454c7e7e622335235b43b6a032=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
z9c9e39781048e019c6c88cdd3e88aafa=1;zcef73afae6ffde57c5f66a2e220460ab=8;}}}}}}
else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.z4f8f816adbe941c8b288d94bfa416694){if(
EOMGsl_RE002_TWCMgt_stHeatPhaReq_in==2){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z4f8f816adbe941c8b288d94bfa416694=0;zd15ec8632355d8c47b9382eb165b43ae();}else{if
(EOMGsl_RE002_TWCMgt_stHeatPhaReq_in==1){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z4f8f816adbe941c8b288d94bfa416694=0;z7cd91b6fcdfdada4657b6b193258870f();}}}else{
if(zb185a6ea22aa4a7b51c8f59af5e02ce8.za8e03c931497941a3ff0e0c939ad3324){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z9f917ffc6502de9f0e90b86ba12d3b00){if((!(
EOM_bIdlModReq))&&RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z9f917ffc6502de9f0e90b86ba12d3b00=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
zfa7726df6a99a080acf17095570104e9=1;zcef73afae6ffde57c5f66a2e220460ab=10;}}else{
if(zb185a6ea22aa4a7b51c8f59af5e02ce8.zfa7726df6a99a080acf17095570104e9){if(
EOM_bIdlModReq&&RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
zfa7726df6a99a080acf17095570104e9=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
z9f917ffc6502de9f0e90b86ba12d3b00=1;zcef73afae6ffde57c5f66a2e220460ab=11;}}}}}}}
}}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.zdd196d45c55aee7031114c7ce55357e4){
if(EOMGsl_RE002_TWCMgt_stHeatPhaReq_in!=0){z311aee2a7a2f9fae3f7719ca1a0e39ae();
za2bf8914781167d53a682568f4cbd3e7();}else{if((EOMGSL_stEngModReq==1)&&
RE002_EOM_bEnaCmbModChg_in){z311aee2a7a2f9fae3f7719ca1a0e39ae();
za2bf8914781167d53a682568f4cbd3e7();}else{if((EOMGSL_stEngModReq==2)&&
RE002_EOM_bEnaCmbModChg_in){z311aee2a7a2f9fae3f7719ca1a0e39ae();
zb185a6ea22aa4a7b51c8f59af5e02ce8.z8384b614cbebfdd15aada018dc2df1ec=1;
zcef73afae6ffde57c5f66a2e220460ab=12;}else{EOM_bLdTranModReq=
EOM_bLdTranModReqRaw_MP&&(EOM_tiDlyInhCmbPrfMod_C!=
zdf761e95f43b63864b7942bfaa64e50c);if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
z6fe8ca649377e7631e73fbf2c76cac23){if(RE002_EOM_bEnaCmbModChg_in&&
z5f388d3df1c54b8266091563d45048b8){z3cad2e75c42f7299bf9df4d551d009ed();
z756d379d69070d05b4cc9ed4ca20f541();}else{if(RE002_EOM_bEnaCmbModChg_in&&
EOM_bLdTranModReq){z3cad2e75c42f7299bf9df4d551d009ed();
zb185a6ea22aa4a7b51c8f59af5e02ce8.z5442d6955b3c530971880f6d4a855154=1;
zcef73afae6ffde57c5f66a2e220460ab=4;}else{if(RE002_EOM_bEnaCmbModChg_in&&
EOM_bColdModReq){z3cad2e75c42f7299bf9df4d551d009ed();
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2fff441a02ac434327912f504ed3e199=1;
zcef73afae6ffde57c5f66a2e220460ab=19;}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
z8c733f33d58671836bd9e777a02c1965){if((!(EOM_bIdlModReq))&&
RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z8c733f33d58671836bd9e777a02c1965=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
z5a15e67d437de0686dbfe2b61aca10a4=1;zcef73afae6ffde57c5f66a2e220460ab=0;
z1b478ee9f1966502b640148eb8bd3d69=0;}}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
z5a15e67d437de0686dbfe2b61aca10a4){if(EOM_bIdlModReq&&RE002_EOM_bEnaCmbModChg_in
){zb185a6ea22aa4a7b51c8f59af5e02ce8.z5a15e67d437de0686dbfe2b61aca10a4=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z8c733f33d58671836bd9e777a02c1965=1;
zcef73afae6ffde57c5f66a2e220460ab=1;}}}}}}}else{if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2fff441a02ac434327912f504ed3e199){if(
RE002_EOM_bEnaCmbModChg_in&&(!(z5f388d3df1c54b8266091563d45048b8))&&(!(
EOM_bColdModReq))){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z2fff441a02ac434327912f504ed3e199=0;zbefc806215a5e84cc9ab28047c96162f();}else{if
(RE002_EOM_bEnaCmbModChg_in&&EOM_bLdTranModReq){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2fff441a02ac434327912f504ed3e199=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z5442d6955b3c530971880f6d4a855154=1;
zcef73afae6ffde57c5f66a2e220460ab=4;}else{if(RE002_EOM_bEnaCmbModChg_in&&
z5f388d3df1c54b8266091563d45048b8&&(!(EOM_bColdModReq))){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2fff441a02ac434327912f504ed3e199=0;
z756d379d69070d05b4cc9ed4ca20f541();}}}}else{if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z5442d6955b3c530971880f6d4a855154){if(
RE002_EOM_bEnaCmbModChg_in&&(!(z5f388d3df1c54b8266091563d45048b8))&&(!(
EOM_bColdModReq))&&(!(EOM_bLdTranModReq))){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z5442d6955b3c530971880f6d4a855154=0;zbefc806215a5e84cc9ab28047c96162f();}else{if
(RE002_EOM_bEnaCmbModChg_in&&z5f388d3df1c54b8266091563d45048b8&&(!(
EOM_bColdModReq))&&(!(EOM_bLdTranModReq))){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z5442d6955b3c530971880f6d4a855154=0;z756d379d69070d05b4cc9ed4ca20f541();}else{if
(RE002_EOM_bEnaCmbModChg_in&&EOM_bColdModReq&&(!(EOM_bLdTranModReq))){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z5442d6955b3c530971880f6d4a855154=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2fff441a02ac434327912f504ed3e199=1;
zcef73afae6ffde57c5f66a2e220460ab=19;}}}}else{if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z08507fcd25b9c7696146871631827b72){if(
RE002_EOM_bEnaCmbModChg_in&&EOM_bLdTranModReq){zf27d9f9c425aba193ee61435f1dd6438
();zb185a6ea22aa4a7b51c8f59af5e02ce8.z5442d6955b3c530971880f6d4a855154=1;
zcef73afae6ffde57c5f66a2e220460ab=4;}else{if(RE002_EOM_bEnaCmbModChg_in&&(!(
z5f388d3df1c54b8266091563d45048b8))){zf27d9f9c425aba193ee61435f1dd6438();
zbefc806215a5e84cc9ab28047c96162f();}else{if(RE002_EOM_bEnaCmbModChg_in&&
EOM_bColdModReq){zf27d9f9c425aba193ee61435f1dd6438();
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2fff441a02ac434327912f504ed3e199=1;
zcef73afae6ffde57c5f66a2e220460ab=19;}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
z896e91f6f4a0fa5b571afc22fbb6a5ea){if((!(EOM_bIdlModReq))&&
RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z896e91f6f4a0fa5b571afc22fbb6a5ea=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
za427e559eb844206c9b1dd3e505e5dc1=1;zcef73afae6ffde57c5f66a2e220460ab=2;}}else{
if(zb185a6ea22aa4a7b51c8f59af5e02ce8.za427e559eb844206c9b1dd3e505e5dc1){if(
EOM_bIdlModReq&&RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
za427e559eb844206c9b1dd3e505e5dc1=0;zb185a6ea22aa4a7b51c8f59af5e02ce8.
z896e91f6f4a0fa5b571afc22fbb6a5ea=1;zcef73afae6ffde57c5f66a2e220460ab=3;}}}}}}}}
}}}}}}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
z8384b614cbebfdd15aada018dc2df1ec){if((EOMGSL_stEngModReq!=2)&&
RE002_EOM_bEnaCmbModChg_in){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z8384b614cbebfdd15aada018dc2df1ec=0;zf87ab759ec4e26edd72ea435f3f3dc14();}}}}}}}}
}}}}}}break;}case C00224_Mode_Blowby_dilution1_id:{if((EOMGSL_stEngModReq!=11)&&
RE002_EOM_bEnaCmbModChg_in){z1b478ee9f1966502b640148eb8bd3d69=0;
zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}case C00225_Mode_De__T_importante_id
:{if((EOMGSL_stEngModReq!=7)&&RE002_EOM_bEnaCmbModChg_in){
zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}case C00226_Mode_Defaut_faible_id:{
if((EOMGSL_stEngModReq!=5)&&(EOMGSL_stEngModReq!=6)&&RE002_EOM_bEnaCmbModChg_in)
{z1b478ee9f1966502b640148eb8bd3d69=0;zc8ad7da64a3eaa2abcd8bf36cd21f922();}else{
if(EOMGSL_stEngModReq==6){zb185a6ea22aa4a7b51c8f59af5e02ce8.
zf7e546f1593d7cf83116b8753807ad52=(unsigned int)C00227_Mode_Defaut_eleve_id;
zcef73afae6ffde57c5f66a2e220460ab=16;z1b478ee9f1966502b640148eb8bd3d69=1;}}break
;}case C00227_Mode_Defaut_eleve_id:{if((EOMGSL_stEngModReq!=6)&&
RE002_EOM_bEnaCmbModChg_in){z1b478ee9f1966502b640148eb8bd3d69=0;
zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}case C00228_Mode_Arret_STT_id:{if((
EOMGSL_stEngModReq!=4)&&RE002_EOM_bEnaCmbModChg_in){
z1b478ee9f1966502b640148eb8bd3d69=0;zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}
case C00229_Mode_Opti_vide_id:{if((EOMGSL_stEngModReq!=9)&&
RE002_EOM_bEnaCmbModChg_in){z1b478ee9f1966502b640148eb8bd3d69=0;
zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}case C00230_Mode_Blowby_dilution2_id
:{if((EOMGSL_stEngModReq!=12)&&RE002_EOM_bEnaCmbModChg_in){
z1b478ee9f1966502b640148eb8bd3d69=0;zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}
case C00231_Mode_Ru__decalage_VVT_id:{if((EOMGSL_stEngModReq!=8)&&
RE002_EOM_bEnaCmbModChg_in){z1b478ee9f1966502b640148eb8bd3d69=0;
zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}case C00232_Mode_Refuge_SIJ_id:{if((
EOMGSL_stEngModReq!=3)&&RE002_EOM_bEnaCmbModChg_in){
z1b478ee9f1966502b640148eb8bd3d69=0;zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}
case C00233_Mode_Webasto_id:{if((EOMGSL_stEngModReq!=10)&&
RE002_EOM_bEnaCmbModChg_in){z1b478ee9f1966502b640148eb8bd3d69=0;
zc8ad7da64a3eaa2abcd8bf36cd21f922();}break;}default:{
zc8ad7da64a3eaa2abcd8bf36cd21f922();break;}}if(EOM_bEnaDiTranManSel_C){
RE002_EOM_bDiTran_out=1;}else{EOM_bDiTranNotSel=
z1b478ee9f1966502b640148eb8bd3d69;RE002_EOM_bDiTran_out=EOM_bDiTranNotSel;}if(
EOM_bEnaCmbModManSel_C){RE002_EOM_stCmbModReq_out=EOM_stCmbModManSel_C;}else{
EOM_stCmbModReqNotSel=zcef73afae6ffde57c5f66a2e220460ab;
RE002_EOM_stCmbModReq_out=EOM_stCmbModReqNotSel;}
z805bb6c38d2ee7370c5a84e344687ec3=1;z11b88b7474181b5794f89004769ac0ae=
z1014f2ef78e9bd89cf97b0a489151c31;z05d75e7a672a4ff2fa22080397f1fa68=1;
zf85a23132b8e32ec6bade9fd1335e94f=z81216a9b128ee23b075afbe0daa6ba92;
z70e794736efead1b90c318e491f54eb5=1;zfc90f78b44087e778959e08e6a57d071=
z6281d1b4221a1350e30eedae1670f708;z83f30abfc1163eb26f0e787e3c1af0d4=
z324bd06375435ee8660719550183e6a0;zd3df90cc2db82e5ba76785b9e2e2cae5=0;
z0ef64ee666bb7d55c41058e6936739aa=EOM_agCkDeltaPosnInVlvReq_MP;
z08632c555cb065e5cf629701a12c66f9=zaf773b57194ffed71db5ecee9a571201;
zda7d5d1ede7aad9a93cdab2743586916=0;z16b7cdf5e54cebc041a3416f6cedc051=
EOM_agCkDeltaPosnExVlvReq_MP;z759eb04c66e2d00c62a7c70b1aa61a86=
z188ef18f136483a2797cdd44351f19db;zc7b2d9057c13816604019570194a00d8=
z5135401cd2b10291b1b028720829de19;z4b18d7211a20dc8403c42297e7b7c262=
zb4d4a2252957979e04ccbf6b1ab78d79;zd59c750c1e975f84783307b554107e0e=
z1f80939da490fec2f5e52d82a3ed04c8;z57b4bb83e2eaca8f9637bd2ffa0e5e16=
z8a569c2baf898e6475721f174759755b;z9467faf124a846a77bb3e7001ee28318=
zcad0ccc3cc3747d652b15273278aede6;z98819e73ab2c0a839e0ad6f977ee2dfc=
EOM_bLdTranModReqRaw_MP;z04ce00eaaee8f0d86c3595c8e1c0bc70=
zc4b97f3e5adea773f69d21da532c4857;zdd1d4d96b2643af56598e4d211882866=1;
EOMGsl_sNV_Z1_CST_32BIT.Ext_dstVehTotMes_NV=EOMGsl_RE002_Ext_dstVehTotMes_in;
z15d0a650f676ec13c58a858024fc7058=z5f388d3df1c54b8266091563d45048b8;
z4d65e94c3df1b8f348fbc71a0fa8ba04=0;zba820ea6a6a92237f50f525188c4b24a=
EOM_tCoCor_Cold;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
Void EOMGsl_002_TEV_ini(Void){EOMGsl_002_FctVarInit();}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
Void EOMGsl_002_FctVarInit(Void){z1b478ee9f1966502b640148eb8bd3d69=0;
zcef73afae6ffde57c5f66a2e220460ab=0;z1c843c79bfdf14288d32b1b5e9907a37=0;
z3f5950dcef7537293221584892b76518=0;z3b5faa50d9829bfcb25545247beb3920=0;
ze71008f8893d0dcf184e1c5da9c9a072=0;z7efcaa5468b3acf5461bb140e8993021=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z4f8f816adbe941c8b288d94bfa416694=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.za8e03c931497941a3ff0e0c939ad3324=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z9f917ffc6502de9f0e90b86ba12d3b00=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.zfa7726df6a99a080acf17095570104e9=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.zdd196d45c55aee7031114c7ce55357e4=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z6fe8ca649377e7631e73fbf2c76cac23=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z8c733f33d58671836bd9e777a02c1965=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z5a15e67d437de0686dbfe2b61aca10a4=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2fff441a02ac434327912f504ed3e199=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z5442d6955b3c530971880f6d4a855154=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z08507fcd25b9c7696146871631827b72=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z896e91f6f4a0fa5b571afc22fbb6a5ea=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.za427e559eb844206c9b1dd3e505e5dc1=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z8384b614cbebfdd15aada018dc2df1ec=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.zfcdf8c6c3dab3c42171a533e1fe93b90=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z276a0795145a005af3f98426df018a2d=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.zde23632acf3e2c6e8417410651265d2e=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2aae937916457b45a39c39b316266201=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.zc475841cb98be6ccf632215c74a26e2c=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z9c9e39781048e019c6c88cdd3e88aafa=0;
zb185a6ea22aa4a7b51c8f59af5e02ce8.z6b3f53454c7e7e622335235b43b6a032=0;
zfc90f78b44087e778959e08e6a57d071=1;z70e794736efead1b90c318e491f54eb5=0;
z9467faf124a846a77bb3e7001ee28318=65534;z57b4bb83e2eaca8f9637bd2ffa0e5e16=65534;
zd59c750c1e975f84783307b554107e0e=65534;z4b18d7211a20dc8403c42297e7b7c262=65534;
zc7b2d9057c13816604019570194a00d8=65534;z759eb04c66e2d00c62a7c70b1aa61a86=65534;
z08632c555cb065e5cf629701a12c66f9=65534;z0ef64ee666bb7d55c41058e6936739aa=0;
zd3df90cc2db82e5ba76785b9e2e2cae5=128;z16b7cdf5e54cebc041a3416f6cedc051=0;
zda7d5d1ede7aad9a93cdab2743586916=128;zf85a23132b8e32ec6bade9fd1335e94f=1;
z05d75e7a672a4ff2fa22080397f1fa68=0;z04ce00eaaee8f0d86c3595c8e1c0bc70=0;
z98819e73ab2c0a839e0ad6f977ee2dfc=0;z11b88b7474181b5794f89004769ac0ae=1;
z805bb6c38d2ee7370c5a84e344687ec3=0;z83f30abfc1163eb26f0e787e3c1af0d4=65534;
zba820ea6a6a92237f50f525188c4b24a=0;z4d65e94c3df1b8f348fbc71a0fa8ba04=1;
zdd1d4d96b2643af56598e4d211882866=0;z15d0a650f676ec13c58a858024fc7058=0;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void zf87ab759ec4e26edd72ea435f3f3dc14(Void){
zb185a6ea22aa4a7b51c8f59af5e02ce8.zdd196d45c55aee7031114c7ce55357e4=1;if(
EOM_bColdModReq){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z2fff441a02ac434327912f504ed3e199=1;zcef73afae6ffde57c5f66a2e220460ab=19;}else{
if(z5f388d3df1c54b8266091563d45048b8&&(!(EOM_bColdModReq))){
z756d379d69070d05b4cc9ed4ca20f541();}else{if((!(
z5f388d3df1c54b8266091563d45048b8))&&(!(EOM_bColdModReq))){
zbefc806215a5e84cc9ab28047c96162f();}}}}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void zbefc806215a5e84cc9ab28047c96162f(Void){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z6fe8ca649377e7631e73fbf2c76cac23=1;if(
EOM_bIdlModReq){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z8c733f33d58671836bd9e777a02c1965=1;zcef73afae6ffde57c5f66a2e220460ab=1;}else{if
(!(EOM_bIdlModReq)){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z5a15e67d437de0686dbfe2b61aca10a4=1;zcef73afae6ffde57c5f66a2e220460ab=0;
z1b478ee9f1966502b640148eb8bd3d69=0;}}}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z756d379d69070d05b4cc9ed4ca20f541(Void){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z08507fcd25b9c7696146871631827b72=1;if(
EOM_bIdlModReq){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z896e91f6f4a0fa5b571afc22fbb6a5ea=1;zcef73afae6ffde57c5f66a2e220460ab=3;}else{if
(!(EOM_bIdlModReq)){zb185a6ea22aa4a7b51c8f59af5e02ce8.
za427e559eb844206c9b1dd3e505e5dc1=1;zcef73afae6ffde57c5f66a2e220460ab=2;}}}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void zc8ad7da64a3eaa2abcd8bf36cd21f922(Void){
zb185a6ea22aa4a7b51c8f59af5e02ce8.zf7e546f1593d7cf83116b8753807ad52=(unsigned 
int)C0022_Modes_id;if(EOMGSL_stEngModReq==1){za2bf8914781167d53a682568f4cbd3e7()
;}else{if(EOMGsl_RE002_TWCMgt_stHeatPhaReq_in!=0){
za2bf8914781167d53a682568f4cbd3e7();}else{if(EOMGSL_stEngModReq!=1){
zf87ab759ec4e26edd72ea435f3f3dc14();}}}}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void za2bf8914781167d53a682568f4cbd3e7(Void){
zb185a6ea22aa4a7b51c8f59af5e02ce8.zfcdf8c6c3dab3c42171a533e1fe93b90=1;if(
EOMGsl_RE002_TWCMgt_stHeatPhaReq_in==1){z7cd91b6fcdfdada4657b6b193258870f();}
else{if(EOMGsl_RE002_TWCMgt_stHeatPhaReq_in==4){
zb185a6ea22aa4a7b51c8f59af5e02ce8.za8e03c931497941a3ff0e0c939ad3324=1;if(
EOM_bIdlModReq){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z9f917ffc6502de9f0e90b86ba12d3b00=1;zcef73afae6ffde57c5f66a2e220460ab=11;}else{
if(!(EOM_bIdlModReq)){zb185a6ea22aa4a7b51c8f59af5e02ce8.
zfa7726df6a99a080acf17095570104e9=1;zcef73afae6ffde57c5f66a2e220460ab=10;}}}else
{if(EOMGsl_RE002_TWCMgt_stHeatPhaReq_in==3){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z4f8f816adbe941c8b288d94bfa416694=1;zcef73afae6ffde57c5f66a2e220460ab=9;}else{if
(EOMGsl_RE002_TWCMgt_stHeatPhaReq_in==2){zd15ec8632355d8c47b9382eb165b43ae();}}}
}}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z7cd91b6fcdfdada4657b6b193258870f(Void){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z276a0795145a005af3f98426df018a2d=1;if(
EOM_bIdlModReq){zb185a6ea22aa4a7b51c8f59af5e02ce8.
zde23632acf3e2c6e8417410651265d2e=1;zcef73afae6ffde57c5f66a2e220460ab=6;}else{if
(!(EOM_bIdlModReq)){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z2aae937916457b45a39c39b316266201=1;zcef73afae6ffde57c5f66a2e220460ab=5;}}}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void zd15ec8632355d8c47b9382eb165b43ae(Void){
zb185a6ea22aa4a7b51c8f59af5e02ce8.zc475841cb98be6ccf632215c74a26e2c=1;if(
EOM_bIdlModReq){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z9c9e39781048e019c6c88cdd3e88aafa=1;zcef73afae6ffde57c5f66a2e220460ab=8;}else{if
(!(EOM_bIdlModReq)){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z6b3f53454c7e7e622335235b43b6a032=1;zcef73afae6ffde57c5f66a2e220460ab=7;}}}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z311aee2a7a2f9fae3f7719ca1a0e39ae(Void){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z6fe8ca649377e7631e73fbf2c76cac23){
z3cad2e75c42f7299bf9df4d551d009ed();}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
z2fff441a02ac434327912f504ed3e199){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z2fff441a02ac434327912f504ed3e199=0;}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
z5442d6955b3c530971880f6d4a855154){zb185a6ea22aa4a7b51c8f59af5e02ce8.
z5442d6955b3c530971880f6d4a855154=0;}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
z08507fcd25b9c7696146871631827b72){zf27d9f9c425aba193ee61435f1dd6438();}}}}
zb185a6ea22aa4a7b51c8f59af5e02ce8.zdd196d45c55aee7031114c7ce55357e4=0;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z3cad2e75c42f7299bf9df4d551d009ed(Void){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z8c733f33d58671836bd9e777a02c1965){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z8c733f33d58671836bd9e777a02c1965=0;}else{
zb185a6ea22aa4a7b51c8f59af5e02ce8.z5a15e67d437de0686dbfe2b61aca10a4=0;}
zb185a6ea22aa4a7b51c8f59af5e02ce8.z6fe8ca649377e7631e73fbf2c76cac23=0;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void zf27d9f9c425aba193ee61435f1dd6438(Void){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z896e91f6f4a0fa5b571afc22fbb6a5ea){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z896e91f6f4a0fa5b571afc22fbb6a5ea=0;}else{
zb185a6ea22aa4a7b51c8f59af5e02ce8.za427e559eb844206c9b1dd3e505e5dc1=0;}
zb185a6ea22aa4a7b51c8f59af5e02ce8.z08507fcd25b9c7696146871631827b72=0;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z647566f665c22683b441e327f4b6450b(Void){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.zfcdf8c6c3dab3c42171a533e1fe93b90){
z14a67a7546c7a9b700179d6bcd815940();}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
zdd196d45c55aee7031114c7ce55357e4){z311aee2a7a2f9fae3f7719ca1a0e39ae();}else{
zb185a6ea22aa4a7b51c8f59af5e02ce8.z8384b614cbebfdd15aada018dc2df1ec=0;}}}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z14a67a7546c7a9b700179d6bcd815940(Void){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z276a0795145a005af3f98426df018a2d){
z702b2efc12bbddea0c7239b5ec6a5ccf();}else{if(zb185a6ea22aa4a7b51c8f59af5e02ce8.
zc475841cb98be6ccf632215c74a26e2c){z4c651ae130567e96eab4e9165a56189f();}else{if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z4f8f816adbe941c8b288d94bfa416694){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z4f8f816adbe941c8b288d94bfa416694=0;}else{if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.za8e03c931497941a3ff0e0c939ad3324){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z9f917ffc6502de9f0e90b86ba12d3b00){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z9f917ffc6502de9f0e90b86ba12d3b00=0;}else{
zb185a6ea22aa4a7b51c8f59af5e02ce8.zfa7726df6a99a080acf17095570104e9=0;}
zb185a6ea22aa4a7b51c8f59af5e02ce8.za8e03c931497941a3ff0e0c939ad3324=0;}}}}
zb185a6ea22aa4a7b51c8f59af5e02ce8.zfcdf8c6c3dab3c42171a533e1fe93b90=0;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z702b2efc12bbddea0c7239b5ec6a5ccf(Void){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.zde23632acf3e2c6e8417410651265d2e){
zb185a6ea22aa4a7b51c8f59af5e02ce8.zde23632acf3e2c6e8417410651265d2e=0;}else{
zb185a6ea22aa4a7b51c8f59af5e02ce8.z2aae937916457b45a39c39b316266201=0;}
zb185a6ea22aa4a7b51c8f59af5e02ce8.z276a0795145a005af3f98426df018a2d=0;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z4c651ae130567e96eab4e9165a56189f(Void){if(
zb185a6ea22aa4a7b51c8f59af5e02ce8.z9c9e39781048e019c6c88cdd3e88aafa){
zb185a6ea22aa4a7b51c8f59af5e02ce8.z9c9e39781048e019c6c88cdd3e88aafa=0;}else{
zb185a6ea22aa4a7b51c8f59af5e02ce8.z6b3f53454c7e7e622335235b43b6a032=0;}
zb185a6ea22aa4a7b51c8f59af5e02ce8.zc475841cb98be6ccf632215c74a26e2c=0;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#endif

