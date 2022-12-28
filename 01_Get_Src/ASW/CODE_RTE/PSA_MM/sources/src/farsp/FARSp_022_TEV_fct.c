/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name: FARSp_022_TEV_fct.c %
*
* %version: 6.0.build1 %
*
* %date_modified: Wed Dec 19 11:24:26 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: FARSp_022_TEV_fct.c-6.0.build1:csrc:5 %
*
*******************************************************************************/


#ifndef _FARSP_022_TEV_FCT_C_
#define _FARSP_022_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_022_TEV_fct.h"
#include "FARSp_022_calibrations.h"
#include "dsfxp.h"
#include "FARSp_calibrations.h"
UInt32 X_S02233_UnitDelay[2];UInt32 X_S02240_Unit_Delay2[2];Boolean 
X_S02234_UnitDelay[2];Boolean X_S02234_UnitDelay1;Boolean X_S02236_UnitDelay;
Boolean X_S02239_UnitDelay;Boolean X_S02240_Unit_Delay1;
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE022_Afts_rMixtReqRlamSpTest_in;
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE022_Blby_facStiRich_in;AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE022_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_Ext_nEng_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_prm_rMixtGasFlexSp_in[24];AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rDeltaMixtStiTWCSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtAstWupSTTSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtBasSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtFullLdSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtLihSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtLoTqReqSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtMaxThermoProt_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtScvExAfs_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtSelCutOffSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtSpAntiStall_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtTWCHeatSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtTWCPurgeSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtThermoProtSp_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_LsMon_rMixtReqMonItrsv_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_OxC_rMixtReqMonItrsv_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_prm_rMixtCylSp_out[6];AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtCylSpWiStiTWC_out;AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtCylSpWoutStiBlby_out;AR_IF_GLOBAL_16BIT UInt16 FARSp_rMixtCylSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE022_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_Afts_bAcvRlamSpTest_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_Blby_bAcvStiRich_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bAcvAflScvGDI_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bAcvRatMixtTWCHeat_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bAcvRichFullLd_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bAcvSelCutOffSpcMixt_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bEnaAntiStall_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bInvldThermoProt_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bLihAcv_in;AR_IF_GLOBAL_BOOLEAN 
Boolean FARSp_RE022_FARSp_bThermoProtAuth_in;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_RE022_InjSys_bTotCutOff_in;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_RE022_InjSys_prm_bCylCutOff_in[6];AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_RE022_LsMon_bAcvReqMonItrsv_in;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_RE022_OxC_bAcvReqMonItrsv_in;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bRichLoTqReqNotAuth_out;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bRichMixtAcv_out;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bRichScvThermoInvld_out;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bSatMaxRatMixt_out;AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bSatMinRatMixt_out;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bStiBlbyNotAcv_out;AR_IF_GLOBAL_BOOLEAN 
Boolean FARSp_bThermoProtReqNotAuth_out;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_prm_bRlamSpAcv_out[20];
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z390e538ff95ba6ed49d261545b67dde2;static UInt16 
z6ea99540255b8247269758b32aab1197;static UInt16 
z025b1fb95a3eceaafeb8a39d30a6e589;static UInt16 
zcc03d6503b892710c34c33b3dc774c11;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
AR_SEC_VAR_32BIT UInt32 zaee69924ddb752158ce9a123f4e81ad8;AR_SEC_VAR_32BIT 
UInt32 z6ad21a6292b890e3892ccc743c529c9f;AR_SEC_VAR_32BIT UInt32 
z9907020dab386f55ab3c07f2c32c92e3;
#define FARSP_STOP_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 za8a70eb8dfd745961a45abbb5d71710d;static UInt8 
z8b2db8277f4448d8887022ca8bdb7672;static UInt8 zc11d3194732387acd8ac9ee4d1e3354e
;static UInt8 z7f25817fb08f9f57a7ef30f8bd55d04f;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_021_MSE_ini(Void){FARSp_022_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_022_TEV_fct(Void){UInt32 z978f4f1e209ef72cfe6b11bb18ab93f7;UInt32 
ze47cfbb0ac5330f262c0421f58538903;UInt32 zf4024bf843c1f4b23aed863bb909c007;
SInt32 z0960c8f62d98c1893ced86b326690c1e;SInt32 
z77488a1a3da0d367ca27b633701a10db;SInt32 ze34a6f104dfecf3495e3cdb9df7e1d87;
SInt32 z77ca54cd4470c66a169b4f9baee2f4a0;SInt32 
z75716271cfd9fe75e6ef71e71a1078b2;SInt32 zcb68e3aff9c0d2e7c9ba311d67500786;
SInt32 z858c330323bc9637e3a02a833cd0c15d;SInt32 
zf4e76d1563eb1f78807095ad991f6bac;SInt32 zdf0676817a03f13f34c95ed79fd2ef52;
SInt32 z7df3b8b6e1d34a18c2bf1be506d47fbb;SInt32 
z3948a5836b990f077fed9bbf442e02e4;SInt32 z2011378602790bb2fc371761e3dcb25e;
SInt32 z05b217391489bf2dcddcac8aca04ef04;SInt32 
z48f881d76a9025f5fd9d2f5897b37773;SInt32 z0263290860b5f264c8997d6f67cefcc6;
SInt32 z20093a8770ad7233750db9bee96cee2a;UInt32 
z4acab6fafa2a338bc792443a108ec84f[2];UInt32 z1b05777d8546efd3acd550b7c842500a[2]
;SInt32 z7b8e6204f3e6e1c4435ca84688a9a0cb[2];UInt32 
z6830b4f2fc4443218b95193abbe5e97c[2];UInt32 z985f2931e897c137b3c788fec5a793e1[2]
;UInt32 z4b7601b2e50cff0e3510c53e02362a61[2];UInt32 
zdd1b034b8341c264c3ddaf5e2c791670[2];UInt32 z2f4ee12cdb01dd88533b61c79be349c3[2]
;UInt32 z63bd4a2edb0f162d60bbe67abdfb5a73[2];UInt32 
z2c594a96f1c7cb73106a83d8e42c81c5[2];UInt32 z0da06aa7b2e97910149469d8e48219af;
UInt32 za2bce02a75edb0c5614070a633add65a;UInt32 
zf30876eeaa164a32faf3375e0c215a54;UInt32 ze704ec0bf1ef68e579c390a6d26058d4;
UInt32 z0dfe56d0e109e2266c7ed04d08e6216a;UInt32 
z08bf02af507c6b450c34204371fe6972;UInt32 z4abe3cb23b1d4c5f558ca835294001bc;
UInt32 z98f531d83b417f9e9c9b75c47cf29445;UInt32 
z94b743ece09631e85d7b36ee6095dd11;UInt32 z25d76b0e98a1254bda05a75557b5ae72;
SInt32 zfdc12a3fb17d38ce794212d337c8867f;UInt32 
z8d473184a357af3f0382a5be8c1ae13c;UInt16 zf7f0f961aa2d7697cf995bb3d898af92;
UInt16 zcb84e8d01e05ac581d1c4009f5d769db;UInt16 
z2872851cdbac18e992afccb49721aa69;UInt16 z650e9e49abe7bd3b1dbae2e7402b39e0;
UInt16 z4294380c52acfd323ca7ebcb033aed9d;UInt16 
z318cd0c8cb76a722f7b4d0fb784d64d1;UInt16 z10322309cd7e8b50fef4a23dd41e5a85;
UInt16 zd64552a5e5ae62674d0f0f0f91c7a1b9;UInt16 
z0514e9e5e3878e7e3570e777b63f3447;UInt16 zef941a86a607af1a5a8c773310c4215f;
UInt16 z87550e9dc25fe28f81dd71458f8f4fd2;UInt16 
z5ca375c26269c2d7991c38b580a17126;UInt16 z16c2efe04c8340ae2caabc3af1d3338c;
UInt16 z61d6e1f191de25b42122dc21d85b7277;UInt16 
z7fb34223ed08e2b9d98d85eca2a20f83;UInt16 z998eee2202a7e129098cd57681302540;
UInt16 z1e486bcc774973320c45a29f96e9704f;UInt16 
zefcd188dd55c7d8bb78728aeccb843a5;UInt16 zd38922da6ac1f480c8352ee44143dd84[2];
UInt16 ze53d403f44f55ef7d8d0f7d4995ffc4f[2];UInt16 
z1bfe017ef2e24b14a8aa4168ebb97e21[2];UInt16 zf02405cd020d5b482e0172a45fbec55f[2]
;UInt16 z69d0747ff8e805ae1b9cf6f1f2eeddd6;UInt16 
z30ce9255a09f7f9a4e7e221eaf0d8d0c;UInt16 za9c5b1760e057892123b941d4b965f19;
UInt16 zf9681e56599e5c7b4e4793bbcac5fba3;UInt16 
zac22fe3c59c3667dfcfd4f57c1c6b226;UInt16 zab85207380232f84f8a17682b9e0da67;
UInt16 z4e6aed9849b7c76708e01f07179100da[2];Boolean 
z9e2d6e9fddd5505a697c93c0204468d6;Boolean z6be3bc88c8cb5e520358450ea3d3b3a9;
Boolean za27f91ae28b5af26fc07cc6904ce7bf0;Boolean 
z1dd0b0441f8a07d377618d9dd7d86171;Boolean zad9cfb6a2f9ad4c28e118ac1b4bfefaf;
Boolean z7066109ac83947cdcb10412e335b5824;Boolean 
z2b9f85f33888f5e72fedeb37b8e7663d;Boolean ze4ab9a8ef9999df807b9fd6b224411de;
Boolean zda21bfacad6dd326bbc5529e5b7f37f2;Boolean 
z0af483b70f6b141a1aa23054875afc7c;Boolean z70989c0f9fced7600f5d844fa8878635;
Boolean z9513026f9c0d193475622cb89426a9bf;Boolean 
za1e7719fe0430051d9259406ea63bbdb;Boolean zbde7d66af1090601ddb7ecf618245aae;
Boolean zb13d9c95d6ccd9a815b562d95ff5a551;Boolean 
zf54e14dde5849195722c546b43fc721b;Boolean z280b90878937cfb49d08483941d57d26;
Boolean z09fa263f0a626e666f10446a2d114f4f;Boolean 
z8548d3e966f30adbe18088ef5fe7f251;Boolean zea4904e0f3040bfcccb3516cb323348d;
Boolean z9fa4760f10461c23ef4364104bfe8c22;Boolean 
zb0f5fd38fd208081fe776c79e791e4e0;Boolean z89df2603f52f55624be4a65bebf2aef9;
Boolean zc50f12b4763696611532602d97914281;Boolean 
z345dc2dda5b5370fd1d787aed2fdcae0;Boolean za748f3e812b46a81ed1d3bb365cc102a;
Boolean z36f0a4bc15e0f001d48d6702d6ab3a66;Boolean 
z7eaa44677e3faeba1e7e75291a13b77c;Boolean z5504cf659e330632b5d813855d87eb0c;
Boolean z6652d80e42916a56f421a666e3bda23e;Boolean 
zfa01277723f1527d65f54580e401e991;UInt8 z3761c7daf452b842781b24658426b5e0;UInt8 
z9f2fd290357ead5d7986a15ff41092c6;Boolean zd3131a31c150d8d0d23c7ddb44ecd39c;
Boolean zc3429f0d7a12a855a8f4842c4d41ffab;UInt8 
z3b9b0fd9b3a4ccd4722708a05c558606;UInt8 z885b85b9952846efa038e8f43e1c7582;
Boolean z87e5e4850109aa25248f0c5c1c410727;Boolean 
zae4dd815e43d54fb021e38ad880ff609;UInt8 z6198dc38284e387039ae738fba2c7a14;UInt8 
z6beda2882d37109aeb9461b519aee9c3;Boolean z22495aa19aec3e1587d94af517ec927d;
Boolean zfba3b1ee05ffedbe0eb5fe20577742a4;UInt8 
zb485cab3590c2b41e7cb38d18d11885e;UInt8 zec6b089cce1624be78d65fea3e00381b;
Boolean z9f878a955bd54952b7c4cdbd9c725386;Boolean 
zef8c3224c2342f0da107c88fc4033ff1;Boolean zf0d94c8cb548e2b7536585a2115255f2;
Boolean za7ea8ad209198b5ea48e26b2583afec2;Boolean 
zf4b8475b700b24d98961c7e7d298b77e;Boolean z1668089e5f487dfd2b1804517ed9e2df;
Boolean z91818304eb21f4a71fd4e2587b97ed92;Boolean 
z9849f32e4cfb6acdb11e0e72a1f0dfbc;Boolean z9ac6d28d468a54b9d2b9ce3bf9beaee5;
Boolean z313543dbe43e96254c2d58466c965475;Boolean 
zfee126b6d1050c4f1529c4d89a988633;Boolean z43ba82ccf77a6f0f350fd58f25db9ff0;
Boolean z2010ea35b00d79fa6e85b6f296f0ecc1;Boolean 
z5f16b6f56e925b61ca70116ffa3beedf[2];Boolean zd3ed77a646e572101c86cfc939bb07ea;
Boolean z0c17c0f99f666e3257117ff3fb833d29[2];Boolean 
za9a32c382849032be9b46ecb4698217b[2];Boolean z4b12dba74dbf413f3735475701022f8a[2
];Boolean z80b6eb1ab67e05265847ed1782c2180c[2];Boolean 
zc926c441ed894a1dc7278c3f09bcde78[2];Boolean z6837b9e17ec806666758cc4a4d07c2fa[2
];Boolean zf521768e7d40abcfd5133af123869e90[2];Boolean 
zf3d945b1a0b3a3bbc6f78b8f7df2484c;Boolean zaef4df9d1c4488853e8813f3be96412d;
Boolean zd074b4e296aa7d09569f22da751cc7a5;Boolean 
zf17fcd577034fa330d65861777339667;Boolean zcf1727ea9037e7d369f34d57304b9b5e;
Boolean zb8493af634b336a071a07f3fbe25f3da;Boolean 
z4db19efc85350248dd4c371c3b671230;Boolean zfc8c1c60124679d6fbcd842f36615054;
Boolean z867a39bf5d35184ca3ac2133d34f0a43;Boolean 
z0e6f934fbb91b982924f6595c85f5349;Boolean z9c45593bf39482df88980b1fb11b9c60;
Boolean zd7a218de450ac9409fb03e1c090fe5db;Boolean 
zd38720ad44c3500a479243d356fd0801;Boolean z2dc0370e08b384ad5999f09e02b93d6d;
Boolean zc0ec918a67ef56ab5a2f6ad9981e0b5c;Boolean 
zb217715506bd87ec5f412b74b4a6104f;Boolean z0ba0c693003e488503154d111c9819d3;
Boolean z0ba483887fd94532473be91baac1b28c;Boolean 
z34245aa2644cbd08269ff9755de13852;UInt32 z8a32e8d845d1f17c84c918e08dcfca18;
UInt32 z3da27aec5682a60504c205c59823dc29;UInt32 
zf3c7f0aba83acc2c1b87e32b60c76a08;UInt32 z9c35598b0d4ebe1f3861ece823b638e0;
UInt32 zdd4e44469c7ba977522b67d97628ca58;UInt32 
z39d3ec1b809acd518254c4c587a25596;UInt32 z722ca88bb5f93e7688336ec70a6cf27a;
UInt32 ze5465884ab04a5b5b716a0fb5897fffa;SInt32 
z665cd5405cc9916a74f654861211a790;UInt32 zae58750fdd9ec8e23860ec3bf7f0d512;
SInt32 z43c81f4756247ec5030fc2f228b0c3cd;UInt32 
zcf568c347c46cb58adf76370d9050d2c;SInt32 z1d10bfc6204c93073806dcff6909dfab;
UInt32 z224f9c06ec5228be533ca5a40a306020;SInt32 
z051ac6621796147a79ab78ad4afcefc3;UInt32 z0613f20a9dabe38a3f4cef5df59c3180;
UInt32 zaceb8d556b68673539d0ea59cc347013;UInt32 
z7122756e5f57a77d2db7411e5c20f21b;UInt32 z87d7f0efe3dd8757ef518e8b1087563e;
UInt32 z0693ceb69cd6c30836e4dc92d027c011;UInt32 
z818acdab736c146f390b59cd7a3817dc;UInt32 z3173fb7f73cab4eb45189ea6ca813c2a;
UInt16 z6aef5c1bd1b6e842408a5c8546f4670a;UInt16 
z9e8893cbbbf79c6c88d6ce42c26ffe2b;UInt16 z6e734a09d7304fa17b93518ecee7e65d;
UInt16 z5213e430c4516eeb20925e0e3195cd78;UInt16 
zd62d8fce3a37db7b665c4375b5b76dc8;UInt16 z8e51e4591fcc685001532289e452bd62;if(
FARSp_RE022_FARSp_prm_facGasFlexSp_in[18]>0){zb485cab3590c2b41e7cb38d18d11885e=
FARSp_RE022_FARSp_prm_facGasFlexSp_in[18];}else{
zb485cab3590c2b41e7cb38d18d11885e=0;}if(128<zb485cab3590c2b41e7cb38d18d11885e){
zec6b089cce1624be78d65fea3e00381b=128;}else{zec6b089cce1624be78d65fea3e00381b=
zb485cab3590c2b41e7cb38d18d11885e;}if(FARSp_RE022_FARSp_prm_facGasFlexSp_in[19]>
0){z6198dc38284e387039ae738fba2c7a14=FARSp_RE022_FARSp_prm_facGasFlexSp_in[19];}
else{z6198dc38284e387039ae738fba2c7a14=0;}if(128<
z6198dc38284e387039ae738fba2c7a14){z6beda2882d37109aeb9461b519aee9c3=128;}else{
z6beda2882d37109aeb9461b519aee9c3=z6198dc38284e387039ae738fba2c7a14;}
TabIdxS50T513((const UInt16*)FARSp_nEngLimSatMinX_A,8,FARSp_RE022_Ext_nEng_in,&(
z8b2db8277f4448d8887022ca8bdb7672),&(z6ea99540255b8247269758b32aab1197));
TabIdxS50T513((const UInt16*)FARSp_rAirLdCorLimSatMinY_A,8,
FARSp_RE022_EngM_rAirLdCor_in,&(zc11d3194732387acd8ac9ee4d1e3354e),&(
z025b1fb95a3eceaafeb8a39d30a6e589));FARSp_rMixtLimMinSpGsl=Tab2DIntp2I1T33281((
const UInt16*)&(FARSp_rMixtLimSatMin_M[0][0]),8,
z8b2db8277f4448d8887022ca8bdb7672,z6ea99540255b8247269758b32aab1197,
zc11d3194732387acd8ac9ee4d1e3354e,z025b1fb95a3eceaafeb8a39d30a6e589);
zf4e76d1563eb1f78807095ad991f6bac=(SInt32)(((SInt32)(((UInt32)
FARSp_RE022_FARSp_prm_rMixtGasFlexSp_in[19])-((UInt32)FARSp_rMixtLimMinSpGsl)))
<<12);F__I64MULU32I32((UInt32)z6beda2882d37109aeb9461b519aee9c3,
zf4e76d1563eb1f78807095ad991f6bac,&(z665cd5405cc9916a74f654861211a790),&(
zae58750fdd9ec8e23860ec3bf7f0d512));z858c330323bc9637e3a02a833cd0c15d=
C__I32SHRI64C6_LT32(z665cd5405cc9916a74f654861211a790,
zae58750fdd9ec8e23860ec3bf7f0d512,7,25);zdf0676817a03f13f34c95ed79fd2ef52=
z858c330323bc9637e3a02a833cd0c15d+((SInt32)(((UInt32)FARSp_rMixtLimMinSpGsl)<<12
));FARSp_rMixtLimMinFlex_MP=C__U32SATI32_SATb(zdf0676817a03f13f34c95ed79fd2ef52,
251658240,0);z3948a5836b990f077fed9bbf442e02e4=(SInt32)(((UInt32)(SInt32)(((
UInt32)FARSp_RE022_FARSp_prm_rMixtGasFlexSp_in[18])<<12))-
FARSp_rMixtLimMinFlex_MP);F__I64MULU32I32((UInt32)
zec6b089cce1624be78d65fea3e00381b,z3948a5836b990f077fed9bbf442e02e4,&(
z43c81f4756247ec5030fc2f228b0c3cd),&(zcf568c347c46cb58adf76370d9050d2c));
z7df3b8b6e1d34a18c2bf1be506d47fbb=C__I32SHRI64C6_LT32(
z43c81f4756247ec5030fc2f228b0c3cd,zcf568c347c46cb58adf76370d9050d2c,7,25);
z2011378602790bb2fc371761e3dcb25e=(SInt32)(z7df3b8b6e1d34a18c2bf1be506d47fbb+
FARSp_rMixtLimMinFlex_MP);FARSp_rMixtLimMin=C__U32SATI32_SATb(
z2011378602790bb2fc371761e3dcb25e,251658240,0);if(
FARSp_RE022_FARSp_rMixtLoTqReqSp_in>FARSp_RE022_FARSp_rMixtThermoProtSp_in){
z4294380c52acfd323ca7ebcb033aed9d=FARSp_RE022_FARSp_rMixtLoTqReqSp_in;}else{
z4294380c52acfd323ca7ebcb033aed9d=FARSp_RE022_FARSp_rMixtThermoProtSp_in;}if(
FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in>z4294380c52acfd323ca7ebcb033aed9d){
z4294380c52acfd323ca7ebcb033aed9d=FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in;}else{}
if(FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in>z4294380c52acfd323ca7ebcb033aed9d){
z4294380c52acfd323ca7ebcb033aed9d=FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in;}else{
}z6aef5c1bd1b6e842408a5c8546f4670a=(UInt16)(FARSp_rMixtLimMin>>12);if(
z6aef5c1bd1b6e842408a5c8546f4670a>z4294380c52acfd323ca7ebcb033aed9d){
z4294380c52acfd323ca7ebcb033aed9d=z6aef5c1bd1b6e842408a5c8546f4670a;}else{}if(
FARSp_RE022_FARSp_prm_facGasFlexSp_in[16]>0){z3b9b0fd9b3a4ccd4722708a05c558606=
FARSp_RE022_FARSp_prm_facGasFlexSp_in[16];}else{
z3b9b0fd9b3a4ccd4722708a05c558606=0;}if(128<z3b9b0fd9b3a4ccd4722708a05c558606){
z885b85b9952846efa038e8f43e1c7582=128;}else{z885b85b9952846efa038e8f43e1c7582=
z3b9b0fd9b3a4ccd4722708a05c558606;}if(FARSp_RE022_FARSp_prm_facGasFlexSp_in[17]>
0){z3761c7daf452b842781b24658426b5e0=FARSp_RE022_FARSp_prm_facGasFlexSp_in[17];}
else{z3761c7daf452b842781b24658426b5e0=0;}if(128<
z3761c7daf452b842781b24658426b5e0){z9f2fd290357ead5d7986a15ff41092c6=128;}else{
z9f2fd290357ead5d7986a15ff41092c6=z3761c7daf452b842781b24658426b5e0;}
TabIdxS50T513((const UInt16*)FARSp_nEngLimSatMaxX_A,8,FARSp_RE022_Ext_nEng_in,&(
z7f25817fb08f9f57a7ef30f8bd55d04f),&(zcc03d6503b892710c34c33b3dc774c11));
TabIdxS50T513((const UInt16*)FARSp_rAirLdCorLimSatMaxY_A,8,
FARSp_RE022_EngM_rAirLdCor_in,&(za8a70eb8dfd745961a45abbb5d71710d),&(
z390e538ff95ba6ed49d261545b67dde2));FARSp_rMixtLimMaxSpGsl=Tab2DIntp2I1T33281((
const UInt16*)&(FARSp_rMixtLimSatMax_M[0][0]),8,
z7f25817fb08f9f57a7ef30f8bd55d04f,zcc03d6503b892710c34c33b3dc774c11,
za8a70eb8dfd745961a45abbb5d71710d,z390e538ff95ba6ed49d261545b67dde2);
z77488a1a3da0d367ca27b633701a10db=(SInt32)(((SInt32)(((UInt32)
FARSp_RE022_FARSp_prm_rMixtGasFlexSp_in[17])-((UInt32)FARSp_rMixtLimMaxSpGsl)))
<<12);F__I64MULU32I32((UInt32)z9f2fd290357ead5d7986a15ff41092c6,
z77488a1a3da0d367ca27b633701a10db,&(z1d10bfc6204c93073806dcff6909dfab),&(
z224f9c06ec5228be533ca5a40a306020));z0960c8f62d98c1893ced86b326690c1e=
C__I32SHRI64C6_LT32(z1d10bfc6204c93073806dcff6909dfab,
z224f9c06ec5228be533ca5a40a306020,7,25);ze34a6f104dfecf3495e3cdb9df7e1d87=
z0960c8f62d98c1893ced86b326690c1e+((SInt32)(((UInt32)FARSp_rMixtLimMaxSpGsl)<<12
));FARSp_rMixtLimMaxFlex_MP=C__U32SATI32_SATb(ze34a6f104dfecf3495e3cdb9df7e1d87,
251658240,0);z75716271cfd9fe75e6ef71e71a1078b2=(SInt32)(((UInt32)(SInt32)(((
UInt32)FARSp_RE022_FARSp_prm_rMixtGasFlexSp_in[16])<<12))-
FARSp_rMixtLimMaxFlex_MP);F__I64MULU32I32((UInt32)
z885b85b9952846efa038e8f43e1c7582,z75716271cfd9fe75e6ef71e71a1078b2,&(
z051ac6621796147a79ab78ad4afcefc3),&(z0613f20a9dabe38a3f4cef5df59c3180));
z77ca54cd4470c66a169b4f9baee2f4a0=C__I32SHRI64C6_LT32(
z051ac6621796147a79ab78ad4afcefc3,z0613f20a9dabe38a3f4cef5df59c3180,7,25);
zcb68e3aff9c0d2e7c9ba311d67500786=(SInt32)(z77ca54cd4470c66a169b4f9baee2f4a0+
FARSp_rMixtLimMaxFlex_MP);FARSp_rMixtLimMax=C__U32SATI32_SATb(
zcb68e3aff9c0d2e7c9ba311d67500786,251658240,0);if(!(
FARSp_RE022_FARSp_bThermoProtAuth_in)){zd38720ad44c3500a479243d356fd0801=1;}else
{zd38720ad44c3500a479243d356fd0801=0;}if(FARSp_bInhProtManMod_C||
zd38720ad44c3500a479243d356fd0801){zd7a218de450ac9409fb03e1c090fe5db=1;}else{
zd7a218de450ac9409fb03e1c090fe5db=0;}if(zd7a218de450ac9409fb03e1c090fe5db&&
FARSp_bManModAcv_C){FARSp_bManModAcv=1;}else{FARSp_bManModAcv=0;}if(
FARSp_RE022_FARSp_rMixtBasSp_in>FARSp_RE022_FARSp_rMixtFullLdSp_in){
zefcd188dd55c7d8bb78728aeccb843a5=FARSp_RE022_FARSp_rMixtBasSp_in;}else{
zefcd188dd55c7d8bb78728aeccb843a5=FARSp_RE022_FARSp_rMixtFullLdSp_in;}if(
FARSp_RE022_FARSp_rMixtAstWupSTTSp_in>zefcd188dd55c7d8bb78728aeccb843a5){
zefcd188dd55c7d8bb78728aeccb843a5=FARSp_RE022_FARSp_rMixtAstWupSTTSp_in;}else{}
if(FARSp_RE022_FARSp_rMixtSpAntiStall_in>zefcd188dd55c7d8bb78728aeccb843a5){
zefcd188dd55c7d8bb78728aeccb843a5=FARSp_RE022_FARSp_rMixtSpAntiStall_in;}else{}
if(FARSp_RE022_FARSp_rMixtLoTqReqSp_in>zefcd188dd55c7d8bb78728aeccb843a5){
zefcd188dd55c7d8bb78728aeccb843a5=FARSp_RE022_FARSp_rMixtLoTqReqSp_in;}else{}if(
FARSp_RE022_FARSp_rMixtTWCPurgeSp_in>zefcd188dd55c7d8bb78728aeccb843a5){
zefcd188dd55c7d8bb78728aeccb843a5=FARSp_RE022_FARSp_rMixtTWCPurgeSp_in;}else{}
z25d76b0e98a1254bda05a75557b5ae72=((UInt32)
FARSp_RE022_FARSp_rDeltaMixtStiTWCSp_in)+((UInt32)
zefcd188dd55c7d8bb78728aeccb843a5);zfdc12a3fb17d38ce794212d337c8867f=(SInt32)(((
UInt32)zefcd188dd55c7d8bb78728aeccb843a5)-((UInt32)
FARSp_RE022_FARSp_rMixtScvExAfs_in));z8a32e8d845d1f17c84c918e08dcfca18=(UInt32)
zfdc12a3fb17d38ce794212d337c8867f;if(zfdc12a3fb17d38ce794212d337c8867f<0){
z8a32e8d845d1f17c84c918e08dcfca18=-((SInt32)z8a32e8d845d1f17c84c918e08dcfca18);}
z998eee2202a7e129098cd57681302540=(UInt16)z8a32e8d845d1f17c84c918e08dcfca18;if(
FARSp_rMixtAfsDeltaMax_C>=z998eee2202a7e129098cd57681302540){
z9c45593bf39482df88980b1fb11b9c60=1;}else{z9c45593bf39482df88980b1fb11b9c60=0;}
if(z9c45593bf39482df88980b1fb11b9c60&&FARSp_bSenO2PropUsTWC_C){FARSp_bAcvStiTWC=
1;}else{FARSp_bAcvStiTWC=0;}if(FARSp_bAcvStiTWC!=0){
z8d473184a357af3f0382a5be8c1ae13c=z25d76b0e98a1254bda05a75557b5ae72;}else{
z8d473184a357af3f0382a5be8c1ae13c=(UInt32)zefcd188dd55c7d8bb78728aeccb843a5;}
z1e486bcc774973320c45a29f96e9704f=C__U16SATU32_SATu(
z8d473184a357af3f0382a5be8c1ae13c,61440);FARSp_prm_rMixtCordRaw[0]=
z1e486bcc774973320c45a29f96e9704f;FARSp_prm_rMixtCordRaw[1]=
zefcd188dd55c7d8bb78728aeccb843a5;if(FARSp_RE022_OxC_bAcvReqMonItrsv_in!=0){
z1bfe017ef2e24b14a8aa4168ebb97e21[0]=FARSp_RE022_OxC_rMixtReqMonItrsv_in;
z1bfe017ef2e24b14a8aa4168ebb97e21[1]=FARSp_RE022_OxC_rMixtReqMonItrsv_in;}else{
z1bfe017ef2e24b14a8aa4168ebb97e21[0]=FARSp_prm_rMixtCordRaw[0];
z1bfe017ef2e24b14a8aa4168ebb97e21[1]=FARSp_prm_rMixtCordRaw[1];}if(
FARSp_RE022_LsMon_bAcvReqMonItrsv_in!=0){FARSp_prm_rMixtCordTWCMon_MP[0]=
FARSp_RE022_LsMon_rMixtReqMonItrsv_in;FARSp_prm_rMixtCordTWCMon_MP[1]=
FARSp_RE022_LsMon_rMixtReqMonItrsv_in;}else{FARSp_prm_rMixtCordTWCMon_MP[0]=
z1bfe017ef2e24b14a8aa4168ebb97e21[0];FARSp_prm_rMixtCordTWCMon_MP[1]=
z1bfe017ef2e24b14a8aa4168ebb97e21[1];}if(FARSp_RE022_FARSp_bAcvRatMixtTWCHeat_in
!=0){zf02405cd020d5b482e0172a45fbec55f[0]=FARSp_RE022_FARSp_rMixtTWCHeatSp_in;
zf02405cd020d5b482e0172a45fbec55f[1]=FARSp_RE022_FARSp_rMixtTWCHeatSp_in;}else{
zf02405cd020d5b482e0172a45fbec55f[0]=FARSp_prm_rMixtCordTWCMon_MP[0];
zf02405cd020d5b482e0172a45fbec55f[1]=FARSp_prm_rMixtCordTWCMon_MP[1];}if(
zf02405cd020d5b482e0172a45fbec55f[0]>FARSp_RE022_FARSp_rMixtThermoProtSp_in){
zd38922da6ac1f480c8352ee44143dd84[0]=zf02405cd020d5b482e0172a45fbec55f[0];}else{
zd38922da6ac1f480c8352ee44143dd84[0]=FARSp_RE022_FARSp_rMixtThermoProtSp_in;}if(
zf02405cd020d5b482e0172a45fbec55f[1]>FARSp_RE022_FARSp_rMixtThermoProtSp_in){
zd38922da6ac1f480c8352ee44143dd84[1]=zf02405cd020d5b482e0172a45fbec55f[1];}else{
zd38922da6ac1f480c8352ee44143dd84[1]=FARSp_RE022_FARSp_rMixtThermoProtSp_in;}if(
zd38922da6ac1f480c8352ee44143dd84[0]<FARSp_RE022_FARSp_rMixtMaxThermoProt_in){
FARSp_prm_rMixtCordThermo_MP[0]=zd38922da6ac1f480c8352ee44143dd84[0];}else{
FARSp_prm_rMixtCordThermo_MP[0]=FARSp_RE022_FARSp_rMixtMaxThermoProt_in;}if(
zd38922da6ac1f480c8352ee44143dd84[1]<FARSp_RE022_FARSp_rMixtMaxThermoProt_in){
FARSp_prm_rMixtCordThermo_MP[1]=zd38922da6ac1f480c8352ee44143dd84[1];}else{
FARSp_prm_rMixtCordThermo_MP[1]=FARSp_RE022_FARSp_rMixtMaxThermoProt_in;}if(
FARSp_RE022_FARSp_bAcvSelCutOffSpcMixt_in!=0){ze53d403f44f55ef7d8d0f7d4995ffc4f[
0]=FARSp_RE022_FARSp_rMixtSelCutOffSp_in;ze53d403f44f55ef7d8d0f7d4995ffc4f[1]=
FARSp_RE022_FARSp_rMixtSelCutOffSp_in;}else{ze53d403f44f55ef7d8d0f7d4995ffc4f[0]
=FARSp_prm_rMixtCordThermo_MP[0];ze53d403f44f55ef7d8d0f7d4995ffc4f[1]=
FARSp_prm_rMixtCordThermo_MP[1];}if(ze53d403f44f55ef7d8d0f7d4995ffc4f[0]>
FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in){FARSp_prm_rMixtCordCmb_MP[0]=
ze53d403f44f55ef7d8d0f7d4995ffc4f[0];}else{FARSp_prm_rMixtCordCmb_MP[0]=
FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in;}if(
FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in>FARSp_prm_rMixtCordCmb_MP[0]){
FARSp_prm_rMixtCordCmb_MP[0]=FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in;}else{}if(
ze53d403f44f55ef7d8d0f7d4995ffc4f[1]>FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in){
FARSp_prm_rMixtCordCmb_MP[1]=ze53d403f44f55ef7d8d0f7d4995ffc4f[1];}else{
FARSp_prm_rMixtCordCmb_MP[1]=FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in;}if(
FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in>FARSp_prm_rMixtCordCmb_MP[1]){
FARSp_prm_rMixtCordCmb_MP[1]=FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in;}else{}if(
FARSp_RE022_FARSp_bLihAcv_in!=0){FARSp_rMixtCordLih[0]=
FARSp_RE022_FARSp_rMixtLihSp_in;FARSp_rMixtCordLih[1]=
FARSp_RE022_FARSp_rMixtLihSp_in;}else{FARSp_rMixtCordLih[0]=
FARSp_prm_rMixtCordCmb_MP[0];FARSp_rMixtCordLih[1]=FARSp_prm_rMixtCordCmb_MP[1];
}if(FARSp_RE022_Afts_bAcvRlamSpTest_in!=0){FARSp_prm_rMixtCordLih[0]=
FARSp_RE022_Afts_rMixtReqRlamSpTest_in;FARSp_prm_rMixtCordLih[1]=
FARSp_RE022_Afts_rMixtReqRlamSpTest_in;}else{FARSp_prm_rMixtCordLih[0]=
FARSp_rMixtCordLih[0];FARSp_prm_rMixtCordLih[1]=FARSp_rMixtCordLih[1];}if(
FARSp_bManModAcv!=0){FARSp_prm_rMixtCordManModSp[0]=FARSp_rMixtManModSp_C;
FARSp_prm_rMixtCordManModSp[1]=FARSp_rMixtManModSp_C;}else{
FARSp_prm_rMixtCordManModSp[0]=FARSp_prm_rMixtCordLih[0];
FARSp_prm_rMixtCordManModSp[1]=FARSp_prm_rMixtCordLih[1];}
z9e8893cbbbf79c6c88d6ce42c26ffe2b=(UInt16)(FARSp_rMixtLimMin>>12);if(
FARSp_prm_rMixtCordManModSp[0]>z9e8893cbbbf79c6c88d6ce42c26ffe2b){
z2872851cdbac18e992afccb49721aa69=FARSp_prm_rMixtCordManModSp[0];}else{
z2872851cdbac18e992afccb49721aa69=z9e8893cbbbf79c6c88d6ce42c26ffe2b;}
z6e734a09d7304fa17b93518ecee7e65d=(UInt16)(FARSp_rMixtLimMax>>12);if(
z6e734a09d7304fa17b93518ecee7e65d<z2872851cdbac18e992afccb49721aa69){
z650e9e49abe7bd3b1dbae2e7402b39e0=z6e734a09d7304fa17b93518ecee7e65d;}else{
z650e9e49abe7bd3b1dbae2e7402b39e0=z2872851cdbac18e992afccb49721aa69;}
z5213e430c4516eeb20925e0e3195cd78=(UInt16)(FARSp_rMixtLimMin>>12);if(
FARSp_prm_rMixtCordManModSp[1]>z5213e430c4516eeb20925e0e3195cd78){
zf7f0f961aa2d7697cf995bb3d898af92=FARSp_prm_rMixtCordManModSp[1];}else{
zf7f0f961aa2d7697cf995bb3d898af92=z5213e430c4516eeb20925e0e3195cd78;}
zd62d8fce3a37db7b665c4375b5b76dc8=(UInt16)(FARSp_rMixtLimMax>>12);if(
zd62d8fce3a37db7b665c4375b5b76dc8<zf7f0f961aa2d7697cf995bb3d898af92){
zcb84e8d01e05ac581d1c4009f5d769db=zd62d8fce3a37db7b665c4375b5b76dc8;}else{
zcb84e8d01e05ac581d1c4009f5d769db=zf7f0f961aa2d7697cf995bb3d898af92;}
FARSp_prm_rMixtLimCmbSp[0]=z650e9e49abe7bd3b1dbae2e7402b39e0;
FARSp_prm_rMixtLimCmbSp[1]=zcb84e8d01e05ac581d1c4009f5d769db;
z05b217391489bf2dcddcac8aca04ef04=(SInt32)(((UInt32)FARSp_prm_rMixtLimCmbSp[1])-
((UInt32)z4294380c52acfd323ca7ebcb033aed9d));if(
z05b217391489bf2dcddcac8aca04ef04>=((SInt32)FARSp_rMixtAmpStiBlbyMin_C)){
z91818304eb21f4a71fd4e2587b97ed92=1;}else{z91818304eb21f4a71fd4e2587b97ed92=0;}
z8e51e4591fcc685001532289e452bd62=(UInt16)(FARSp_rMixtLimMax>>12);if(
z8e51e4591fcc685001532289e452bd62<FARSp_RE022_FARSp_rMixtMaxThermoProt_in){
z318cd0c8cb76a722f7b4d0fb784d64d1=z8e51e4591fcc685001532289e452bd62;}else{
z318cd0c8cb76a722f7b4d0fb784d64d1=FARSp_RE022_FARSp_rMixtMaxThermoProt_in;}
z48f881d76a9025f5fd9d2f5897b37773=(SInt32)(((UInt32)
z318cd0c8cb76a722f7b4d0fb784d64d1)-((UInt32)FARSp_prm_rMixtLimCmbSp[1]));if(
z48f881d76a9025f5fd9d2f5897b37773>=((SInt32)FARSp_rMixtAmpStiBlbyMax_C)){
z9849f32e4cfb6acdb11e0e72a1f0dfbc=1;}else{z9849f32e4cfb6acdb11e0e72a1f0dfbc=0;}
if(z91818304eb21f4a71fd4e2587b97ed92&&z9849f32e4cfb6acdb11e0e72a1f0dfbc){
FARSp_bAmpStiBlbyAuth=1;}else{FARSp_bAmpStiBlbyAuth=0;}if(FARSp_bManModAcv||
FARSp_RE022_FARSp_bEnaAntiStall_in||FARSp_RE022_OxC_bAcvReqMonItrsv_in||
FARSp_RE022_LsMon_bAcvReqMonItrsv_in||FARSp_RE022_FARSp_bAcvRatMixtTWCHeat_in||
FARSp_RE022_FARSp_bLihAcv_in||FARSp_RE022_Afts_bAcvRlamSpTest_in||
FARSp_bAcvStiTWC||FARSp_RE022_FARSp_bAcvSelCutOffSpcMixt_in||
FARSp_RE022_FARSp_bAcvRichFullLd_in){z9ac6d28d468a54b9d2b9ce3bf9beaee5=1;}else{
z9ac6d28d468a54b9d2b9ce3bf9beaee5=0;}if(!(z9ac6d28d468a54b9d2b9ce3bf9beaee5)){
FARSp_bExtReqStiBlbyAuth=1;}else{FARSp_bExtReqStiBlbyAuth=0;}
z0263290860b5f264c8997d6f67cefcc6=(SInt32)(((UInt32)
FARSp_RE022_FARSp_rMixtTWCPurgeSp_in)-4096);z3da27aec5682a60504c205c59823dc29=(
UInt32)z0263290860b5f264c8997d6f67cefcc6;if(z0263290860b5f264c8997d6f67cefcc6<0)
{z3da27aec5682a60504c205c59823dc29=-((SInt32)z3da27aec5682a60504c205c59823dc29);
}z10322309cd7e8b50fef4a23dd41e5a85=(UInt16)z3da27aec5682a60504c205c59823dc29;if(
z10322309cd7e8b50fef4a23dd41e5a85<=FARSp_rMixtBlbyAuthTWCOfs_C){
zfee126b6d1050c4f1529c4d89a988633=1;}else{zfee126b6d1050c4f1529c4d89a988633=0;}
if(FARSp_prm_rMixtLimCmbSp[1]<=FARSp_rMixtBlbyAuthBas_C){
z313543dbe43e96254c2d58466c965475=1;}else{z313543dbe43e96254c2d58466c965475=0;}
if(FARSp_RE022_FARSp_rMixtAstWupSTTSp_in>FARSp_RE022_FARSp_rMixtBasSp_in){
z0514e9e5e3878e7e3570e777b63f3447=FARSp_RE022_FARSp_rMixtAstWupSTTSp_in;}else{
z0514e9e5e3878e7e3570e777b63f3447=FARSp_RE022_FARSp_rMixtBasSp_in;}
z20093a8770ad7233750db9bee96cee2a=(SInt32)(((UInt32)
z0514e9e5e3878e7e3570e777b63f3447)-((UInt32)FARSp_prm_rMixtLimCmbSp[1]));
zf3c7f0aba83acc2c1b87e32b60c76a08=(UInt32)z20093a8770ad7233750db9bee96cee2a;if(
z20093a8770ad7233750db9bee96cee2a<0){zf3c7f0aba83acc2c1b87e32b60c76a08=-((SInt32
)zf3c7f0aba83acc2c1b87e32b60c76a08);}zd64552a5e5ae62674d0f0f0f91c7a1b9=(UInt16)
zf3c7f0aba83acc2c1b87e32b60c76a08;if(zd64552a5e5ae62674d0f0f0f91c7a1b9<=
FARSp_rMixtBlbyAuthBasOfs_C){z43ba82ccf77a6f0f350fd58f25db9ff0=1;}else{
z43ba82ccf77a6f0f350fd58f25db9ff0=0;}if(zfee126b6d1050c4f1529c4d89a988633&&
z313543dbe43e96254c2d58466c965475&&z43ba82ccf77a6f0f350fd58f25db9ff0){
FARSp_bRMixtStiBlbyAuth=1;}else{FARSp_bRMixtStiBlbyAuth=0;}if(
FARSp_bAmpStiBlbyAuth&&FARSp_bExtReqStiBlbyAuth&&FARSp_bRMixtStiBlbyAuth&&
FARSp_RE022_Blby_bAcvStiRich_in&&FARSp_bStiBlbyAcv_C){
zd3ed77a646e572101c86cfc939bb07ea=1;}else{zd3ed77a646e572101c86cfc939bb07ea=0;}
if(!(zd3ed77a646e572101c86cfc939bb07ea)){z2010ea35b00d79fa6e85b6f296f0ecc1=1;}
else{z2010ea35b00d79fa6e85b6f296f0ecc1=0;}if(!(X_S02236_UnitDelay)){
zaef4df9d1c4488853e8813f3be96412d=1;}else{zaef4df9d1c4488853e8813f3be96412d=0;}
if(z2010ea35b00d79fa6e85b6f296f0ecc1&&zaef4df9d1c4488853e8813f3be96412d){
zf3d945b1a0b3a3bbc6f78b8f7df2484c=1;}else{zf3d945b1a0b3a3bbc6f78b8f7df2484c=0;}
z87550e9dc25fe28f81dd71458f8f4fd2=FARSp_facFilStiBlby_C;if(2048<
z87550e9dc25fe28f81dd71458f8f4fd2){z5ca375c26269c2d7991c38b580a17126=2048;}else{
z5ca375c26269c2d7991c38b580a17126=z87550e9dc25fe28f81dd71458f8f4fd2;}
zdd1b034b8341c264c3ddaf5e2c791670[0]=(UInt32)((((UInt32)FARSp_prm_rMixtLimCmbSp[
0])*((UInt32)z5ca375c26269c2d7991c38b580a17126))<<3);
zdd1b034b8341c264c3ddaf5e2c791670[1]=(UInt32)((((UInt32)FARSp_prm_rMixtLimCmbSp[
1])*((UInt32)z5ca375c26269c2d7991c38b580a17126))<<3);
zef941a86a607af1a5a8c773310c4215f=(UInt16)(((UInt16)(-
z5ca375c26269c2d7991c38b580a17126))+2048);if(X_S02240_Unit_Delay1!=0){
z2c594a96f1c7cb73106a83d8e42c81c5[0]=X_S02240_Unit_Delay2[0];
z2c594a96f1c7cb73106a83d8e42c81c5[1]=X_S02240_Unit_Delay2[1];}else{
z2c594a96f1c7cb73106a83d8e42c81c5[0]=X_S02233_UnitDelay[0];
z2c594a96f1c7cb73106a83d8e42c81c5[1]=X_S02233_UnitDelay[1];}F__U64MULU32U32((
UInt32)zef941a86a607af1a5a8c773310c4215f,z2c594a96f1c7cb73106a83d8e42c81c5[0],&(
zaceb8d556b68673539d0ea59cc347013),&(z7122756e5f57a77d2db7411e5c20f21b));
z4b7601b2e50cff0e3510c53e02362a61[0]=C__U32SHRU64C6_LT32(
zaceb8d556b68673539d0ea59cc347013,z7122756e5f57a77d2db7411e5c20f21b,11,21);
F__U64MULU32U32((UInt32)zef941a86a607af1a5a8c773310c4215f,
z2c594a96f1c7cb73106a83d8e42c81c5[1],&(z87d7f0efe3dd8757ef518e8b1087563e),&(
z0693ceb69cd6c30836e4dc92d027c011));z4b7601b2e50cff0e3510c53e02362a61[1]=
C__U32SHRU64C6_LT32(z87d7f0efe3dd8757ef518e8b1087563e,
z0693ceb69cd6c30836e4dc92d027c011,11,21);z2f4ee12cdb01dd88533b61c79be349c3[0]=
zdd1b034b8341c264c3ddaf5e2c791670[0]+z4b7601b2e50cff0e3510c53e02362a61[0];
z2f4ee12cdb01dd88533b61c79be349c3[1]=zdd1b034b8341c264c3ddaf5e2c791670[1]+
z4b7601b2e50cff0e3510c53e02362a61[1];if(zf3d945b1a0b3a3bbc6f78b8f7df2484c!=0){
z63bd4a2edb0f162d60bbe67abdfb5a73[0]=X_S02233_UnitDelay[0];
z63bd4a2edb0f162d60bbe67abdfb5a73[1]=X_S02233_UnitDelay[1];}else{
z63bd4a2edb0f162d60bbe67abdfb5a73[0]=z2f4ee12cdb01dd88533b61c79be349c3[0];
z63bd4a2edb0f162d60bbe67abdfb5a73[1]=z2f4ee12cdb01dd88533b61c79be349c3[1];}if(
X_S02239_UnitDelay!=0){FARSp_prm_rMixtCmbSpFil_MP[0]=
z63bd4a2edb0f162d60bbe67abdfb5a73[0];FARSp_prm_rMixtCmbSpFil_MP[1]=
z63bd4a2edb0f162d60bbe67abdfb5a73[1];}else{FARSp_prm_rMixtCmbSpFil_MP[0]=
X_S02233_UnitDelay[0];FARSp_prm_rMixtCmbSpFil_MP[1]=X_S02233_UnitDelay[1];}
z7b8e6204f3e6e1c4435ca84688a9a0cb[0]=(SInt32)(((UInt32)(SInt32)(((UInt32)
FARSp_prm_rMixtLimCmbSp[0])<<14))-FARSp_prm_rMixtCmbSpFil_MP[0]);
z7b8e6204f3e6e1c4435ca84688a9a0cb[1]=(SInt32)(((UInt32)(SInt32)(((UInt32)
FARSp_prm_rMixtLimCmbSp[1])<<14))-FARSp_prm_rMixtCmbSpFil_MP[1]);
z9c35598b0d4ebe1f3861ece823b638e0=(UInt32)z7b8e6204f3e6e1c4435ca84688a9a0cb[0];
if(z7b8e6204f3e6e1c4435ca84688a9a0cb[0]<0){z9c35598b0d4ebe1f3861ece823b638e0=-((
SInt32)z9c35598b0d4ebe1f3861ece823b638e0);}z4acab6fafa2a338bc792443a108ec84f[0]=
z9c35598b0d4ebe1f3861ece823b638e0;zdd4e44469c7ba977522b67d97628ca58=(UInt32)
z7b8e6204f3e6e1c4435ca84688a9a0cb[1];if(z7b8e6204f3e6e1c4435ca84688a9a0cb[1]<0){
zdd4e44469c7ba977522b67d97628ca58=-((SInt32)zdd4e44469c7ba977522b67d97628ca58);}
z4acab6fafa2a338bc792443a108ec84f[1]=zdd4e44469c7ba977522b67d97628ca58;if(
z4acab6fafa2a338bc792443a108ec84f[0]>((UInt32)(((UInt32)FARSp_rMixtStiBlbyTran_C
)<<14))){FARSp_bRMixtDif_MP[0]=1;}else{FARSp_bRMixtDif_MP[0]=0;}if(
z4acab6fafa2a338bc792443a108ec84f[1]>((UInt32)(((UInt32)FARSp_rMixtStiBlbyTran_C
)<<14))){FARSp_bRMixtDif_MP[1]=1;}else{FARSp_bRMixtDif_MP[1]=0;}if(
FARSp_bRMixtDif_MP[0]&&zf3d945b1a0b3a3bbc6f78b8f7df2484c){
z0c17c0f99f666e3257117ff3fb833d29[0]=1;}else{z0c17c0f99f666e3257117ff3fb833d29[0
]=0;}if(FARSp_bRMixtDif_MP[1]&&zf3d945b1a0b3a3bbc6f78b8f7df2484c){
z0c17c0f99f666e3257117ff3fb833d29[1]=1;}else{z0c17c0f99f666e3257117ff3fb833d29[1
]=0;}if(X_S02234_UnitDelay[0]||z0c17c0f99f666e3257117ff3fb833d29[0]){
z6837b9e17ec806666758cc4a4d07c2fa[0]=1;}else{z6837b9e17ec806666758cc4a4d07c2fa[0
]=0;}if(X_S02234_UnitDelay[1]||z0c17c0f99f666e3257117ff3fb833d29[1]){
z6837b9e17ec806666758cc4a4d07c2fa[1]=1;}else{z6837b9e17ec806666758cc4a4d07c2fa[1
]=0;}if(FARSp_bRMixtDif_MP[0]||zf3d945b1a0b3a3bbc6f78b8f7df2484c){
za9a32c382849032be9b46ecb4698217b[0]=1;}else{za9a32c382849032be9b46ecb4698217b[0
]=0;}if(FARSp_bRMixtDif_MP[1]||zf3d945b1a0b3a3bbc6f78b8f7df2484c){
za9a32c382849032be9b46ecb4698217b[1]=1;}else{za9a32c382849032be9b46ecb4698217b[1
]=0;}if(!(za9a32c382849032be9b46ecb4698217b[0])){
z5f16b6f56e925b61ca70116ffa3beedf[0]=1;}else{z5f16b6f56e925b61ca70116ffa3beedf[0
]=0;}if(!(za9a32c382849032be9b46ecb4698217b[1])){
z5f16b6f56e925b61ca70116ffa3beedf[1]=1;}else{z5f16b6f56e925b61ca70116ffa3beedf[1
]=0;}if(!(z5f16b6f56e925b61ca70116ffa3beedf[0])){
zc926c441ed894a1dc7278c3f09bcde78[0]=1;}else{zc926c441ed894a1dc7278c3f09bcde78[0
]=0;}if(!(z5f16b6f56e925b61ca70116ffa3beedf[1])){
zc926c441ed894a1dc7278c3f09bcde78[1]=1;}else{zc926c441ed894a1dc7278c3f09bcde78[1
]=0;}if(z6837b9e17ec806666758cc4a4d07c2fa[0]&&zc926c441ed894a1dc7278c3f09bcde78[
0]){z80b6eb1ab67e05265847ed1782c2180c[0]=1;}else{
z80b6eb1ab67e05265847ed1782c2180c[0]=0;}if(z6837b9e17ec806666758cc4a4d07c2fa[1]
&&zc926c441ed894a1dc7278c3f09bcde78[1]){z80b6eb1ab67e05265847ed1782c2180c[1]=1;}
else{z80b6eb1ab67e05265847ed1782c2180c[1]=0;}if(X_S02234_UnitDelay1!=0){
zf521768e7d40abcfd5133af123869e90[0]=z80b6eb1ab67e05265847ed1782c2180c[0];
zf521768e7d40abcfd5133af123869e90[1]=z80b6eb1ab67e05265847ed1782c2180c[1];}else{
zf521768e7d40abcfd5133af123869e90[0]=0;zf521768e7d40abcfd5133af123869e90[1]=0;}
if(!(zf521768e7d40abcfd5133af123869e90[0])){z4b12dba74dbf413f3735475701022f8a[0]
=1;}else{z4b12dba74dbf413f3735475701022f8a[0]=0;}if(!(
zf521768e7d40abcfd5133af123869e90[1])){z4b12dba74dbf413f3735475701022f8a[1]=1;}
else{z4b12dba74dbf413f3735475701022f8a[1]=0;}if(
z4b12dba74dbf413f3735475701022f8a[0]!=0){z6830b4f2fc4443218b95193abbe5e97c[0]=(
UInt32)(((UInt32)FARSp_prm_rMixtLimCmbSp[0])<<14);}else{
z6830b4f2fc4443218b95193abbe5e97c[0]=FARSp_prm_rMixtCmbSpFil_MP[0];}if(
z4b12dba74dbf413f3735475701022f8a[1]!=0){z6830b4f2fc4443218b95193abbe5e97c[1]=(
UInt32)(((UInt32)FARSp_prm_rMixtLimCmbSp[1])<<14);}else{
z6830b4f2fc4443218b95193abbe5e97c[1]=FARSp_prm_rMixtCmbSpFil_MP[1];}
z1b05777d8546efd3acd550b7c842500a[0]=(UInt32)((((UInt32)
FARSp_RE022_Blby_facStiRich_in)*((UInt32)FARSp_prm_rMixtLimCmbSp[0]))>>1);
z1b05777d8546efd3acd550b7c842500a[1]=(UInt32)((((UInt32)
FARSp_RE022_Blby_facStiRich_in)*((UInt32)FARSp_prm_rMixtLimCmbSp[1]))>>1);if(
z2010ea35b00d79fa6e85b6f296f0ecc1!=0){z985f2931e897c137b3c788fec5a793e1[0]=
z6830b4f2fc4443218b95193abbe5e97c[0];z985f2931e897c137b3c788fec5a793e1[1]=
z6830b4f2fc4443218b95193abbe5e97c[1];}else{z985f2931e897c137b3c788fec5a793e1[0]=
z1b05777d8546efd3acd550b7c842500a[0];z985f2931e897c137b3c788fec5a793e1[1]=
z1b05777d8546efd3acd550b7c842500a[1];}z818acdab736c146f390b59cd7a3817dc=(UInt32)
(z985f2931e897c137b3c788fec5a793e1[0]>>14);FARSp_prm_rMixtStiBlbySp[0]=
C__U16SATU32_SATu(z818acdab736c146f390b59cd7a3817dc,61440);
z3173fb7f73cab4eb45189ea6ca813c2a=(UInt32)(z985f2931e897c137b3c788fec5a793e1[1]
>>14);FARSp_prm_rMixtStiBlbySp[1]=C__U16SATU32_SATu(
z3173fb7f73cab4eb45189ea6ca813c2a,61440);zf4024bf843c1f4b23aed863bb909c007=((
UInt32)FARSp_RE022_FARSp_rMixtMaxThermoProt_in)+((UInt32)
FARSp_rMixtRichScvInvldOfs_C);if(((UInt32)FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in)
>zf4024bf843c1f4b23aed863bb909c007){z2b9f85f33888f5e72fedeb37b8e7663d=1;}else{
z2b9f85f33888f5e72fedeb37b8e7663d=0;}if(FARSp_RE022_FARSp_bInvldThermoProt_in||
z2b9f85f33888f5e72fedeb37b8e7663d){z6be3bc88c8cb5e520358450ea3d3b3a9=1;}else{
z6be3bc88c8cb5e520358450ea3d3b3a9=0;}z98f531d83b417f9e9c9b75c47cf29445=
z9907020dab386f55ab3c07f2c32c92e3+1;if(z6be3bc88c8cb5e520358450ea3d3b3a9!=0){
z94b743ece09631e85d7b36ee6095dd11=0;}else{z94b743ece09631e85d7b36ee6095dd11=
z98f531d83b417f9e9c9b75c47cf29445;}if(FARSp_tiSdlFARSp_C!=0){
z7fb34223ed08e2b9d98d85eca2a20f83=(UInt16)(FARSp_tiDlyRichScvInvld_C/
FARSp_tiSdlFARSp_C);}else{z7fb34223ed08e2b9d98d85eca2a20f83=65535;}
z39d3ec1b809acd518254c4c587a25596=(UInt32)z7fb34223ed08e2b9d98d85eca2a20f83;if(
z94b743ece09631e85d7b36ee6095dd11<z39d3ec1b809acd518254c4c587a25596){
z4abe3cb23b1d4c5f558ca835294001bc=z94b743ece09631e85d7b36ee6095dd11;}else{
z4abe3cb23b1d4c5f558ca835294001bc=z39d3ec1b809acd518254c4c587a25596;}
z978f4f1e209ef72cfe6b11bb18ab93f7=((UInt32)FARSp_prm_rMixtStiBlbySp[0])+((UInt32
)FARSp_rMixtLoTqReqAuthOfs_C);if(((UInt32)FARSp_RE022_FARSp_rMixtLoTqReqSp_in)>
z978f4f1e209ef72cfe6b11bb18ab93f7){zad9cfb6a2f9ad4c28e118ac1b4bfefaf=1;}else{
zad9cfb6a2f9ad4c28e118ac1b4bfefaf=0;}z0dfe56d0e109e2266c7ed04d08e6216a=
z6ad21a6292b890e3892ccc743c529c9f+1;if(zad9cfb6a2f9ad4c28e118ac1b4bfefaf!=0){
z08bf02af507c6b450c34204371fe6972=0;}else{z08bf02af507c6b450c34204371fe6972=
z0dfe56d0e109e2266c7ed04d08e6216a;}z61d6e1f191de25b42122dc21d85b7277=(UInt16)(
FARSp_tiDlyLoTqReqNotAuth_C/FARSp_tiSdlFARSp_C);
z722ca88bb5f93e7688336ec70a6cf27a=(UInt32)z61d6e1f191de25b42122dc21d85b7277;if(
z08bf02af507c6b450c34204371fe6972<z722ca88bb5f93e7688336ec70a6cf27a){
ze704ec0bf1ef68e579c390a6d26058d4=z08bf02af507c6b450c34204371fe6972;}else{
ze704ec0bf1ef68e579c390a6d26058d4=z722ca88bb5f93e7688336ec70a6cf27a;}if(!(
FARSp_RE022_FARSp_bInvldThermoProt_in)){z1dd0b0441f8a07d377618d9dd7d86171=1;}
else{z1dd0b0441f8a07d377618d9dd7d86171=0;}ze47cfbb0ac5330f262c0421f58538903=((
UInt32)FARSp_prm_rMixtStiBlbySp[0])+((UInt32)FARSp_rMixtThermoProtAuthOfs_C);if(
((UInt32)FARSp_RE022_FARSp_rMixtThermoProtSp_in)>
ze47cfbb0ac5330f262c0421f58538903){z7066109ac83947cdcb10412e335b5824=1;}else{
z7066109ac83947cdcb10412e335b5824=0;}if(z1dd0b0441f8a07d377618d9dd7d86171&&
z7066109ac83947cdcb10412e335b5824){za27f91ae28b5af26fc07cc6904ce7bf0=1;}else{
za27f91ae28b5af26fc07cc6904ce7bf0=0;}za2bce02a75edb0c5614070a633add65a=
zaee69924ddb752158ce9a123f4e81ad8+1;if(za27f91ae28b5af26fc07cc6904ce7bf0!=0){
zf30876eeaa164a32faf3375e0c215a54=0;}else{zf30876eeaa164a32faf3375e0c215a54=
za2bce02a75edb0c5614070a633add65a;}if(FARSp_tiSdlFARSp_C!=0){
z16c2efe04c8340ae2caabc3af1d3338c=(UInt16)(FARSp_tiDlyThermoProtNotAuth_C/
FARSp_tiSdlFARSp_C);}else{z16c2efe04c8340ae2caabc3af1d3338c=65535;}
ze5465884ab04a5b5b716a0fb5897fffa=(UInt32)z16c2efe04c8340ae2caabc3af1d3338c;if(
zf30876eeaa164a32faf3375e0c215a54<ze5465884ab04a5b5b716a0fb5897fffa){
z0da06aa7b2e97910149469d8e48219af=zf30876eeaa164a32faf3375e0c215a54;}else{
z0da06aa7b2e97910149469d8e48219af=ze5465884ab04a5b5b716a0fb5897fffa;}if(
FARSp_facFilStiBlby_C<=0){zf17fcd577034fa330d65861777339667=1;}else{
zf17fcd577034fa330d65861777339667=0;}if(FARSp_prm_rMixtCordManModSp[0]<=((UInt16
)(FARSp_rMixtLimMin>>12))){z1668089e5f487dfd2b1804517ed9e2df=1;}else{
z1668089e5f487dfd2b1804517ed9e2df=0;}if(FARSp_RE022_FARSp_prm_facGasFlexSp_in[18
]<=0){zef8c3224c2342f0da107c88fc4033ff1=1;}else{
zef8c3224c2342f0da107c88fc4033ff1=0;}if(FARSp_RE022_FARSp_prm_facGasFlexSp_in[19
]<=0){zfba3b1ee05ffedbe0eb5fe20577742a4=1;}else{
zfba3b1ee05ffedbe0eb5fe20577742a4=0;}if(FARSp_RE022_FARSp_prm_facGasFlexSp_in[16
]<=0){zae4dd815e43d54fb021e38ad880ff609=1;}else{
zae4dd815e43d54fb021e38ad880ff609=0;}if(FARSp_RE022_FARSp_prm_facGasFlexSp_in[17
]<=0){zc3429f0d7a12a855a8f4842c4d41ffab=1;}else{
zc3429f0d7a12a855a8f4842c4d41ffab=0;}if(2048<=FARSp_facFilStiBlby_C){
zd074b4e296aa7d09569f22da751cc7a5=1;}else{zd074b4e296aa7d09569f22da751cc7a5=0;}
if(FARSp_rMixtLimMax<=((UInt32)(((UInt32)FARSp_prm_rMixtCordManModSp[0])<<12))){
zf4b8475b700b24d98961c7e7d298b77e=1;}else{zf4b8475b700b24d98961c7e7d298b77e=0;}
if(128<=FARSp_RE022_FARSp_prm_facGasFlexSp_in[18]){
z9f878a955bd54952b7c4cdbd9c725386=1;}else{z9f878a955bd54952b7c4cdbd9c725386=0;}
if(128<=FARSp_RE022_FARSp_prm_facGasFlexSp_in[19]){
z22495aa19aec3e1587d94af517ec927d=1;}else{z22495aa19aec3e1587d94af517ec927d=0;}
if(128<=FARSp_RE022_FARSp_prm_facGasFlexSp_in[16]){
z87e5e4850109aa25248f0c5c1c410727=1;}else{z87e5e4850109aa25248f0c5c1c410727=0;}
if(128<=FARSp_RE022_FARSp_prm_facGasFlexSp_in[17]){
zd3131a31c150d8d0d23c7ddb44ecd39c=1;}else{zd3131a31c150d8d0d23c7ddb44ecd39c=0;}
if(FARSp_RE022_InjSys_bTotCutOff_in!=0){z4e6aed9849b7c76708e01f07179100da[0]=0;
z4e6aed9849b7c76708e01f07179100da[1]=0;}else{z4e6aed9849b7c76708e01f07179100da[0
]=FARSp_prm_rMixtStiBlbySp[0];z4e6aed9849b7c76708e01f07179100da[1]=
FARSp_prm_rMixtStiBlbySp[1];}if(FARSp_RE022_FARSp_rMixtBasSp_in==
z4e6aed9849b7c76708e01f07179100da[1]){z280b90878937cfb49d08483941d57d26=1;}else{
z280b90878937cfb49d08483941d57d26=0;}if(FARSp_RE022_FARSp_rMixtFullLdSp_in==
z4e6aed9849b7c76708e01f07179100da[1]){zc50f12b4763696611532602d97914281=1;}else{
zc50f12b4763696611532602d97914281=0;}if(FARSp_RE022_FARSp_rMixtAstWupSTTSp_in==
z4e6aed9849b7c76708e01f07179100da[1]){z345dc2dda5b5370fd1d787aed2fdcae0=1;}else{
z345dc2dda5b5370fd1d787aed2fdcae0=0;}if(FARSp_RE022_FARSp_rMixtSpAntiStall_in==
z4e6aed9849b7c76708e01f07179100da[1]){za748f3e812b46a81ed1d3bb365cc102a=1;}else{
za748f3e812b46a81ed1d3bb365cc102a=0;}if(za748f3e812b46a81ed1d3bb365cc102a&&
FARSp_RE022_FARSp_bEnaAntiStall_in){zda21bfacad6dd326bbc5529e5b7f37f2=1;}else{
zda21bfacad6dd326bbc5529e5b7f37f2=0;}if(FARSp_RE022_FARSp_rMixtLoTqReqSp_in==
z4e6aed9849b7c76708e01f07179100da[1]){z36f0a4bc15e0f001d48d6702d6ab3a66=1;}else{
z36f0a4bc15e0f001d48d6702d6ab3a66=0;}if(FARSp_RE022_FARSp_rMixtTWCPurgeSp_in==
z4e6aed9849b7c76708e01f07179100da[1]){z7eaa44677e3faeba1e7e75291a13b77c=1;}else{
z7eaa44677e3faeba1e7e75291a13b77c=0;}if(FARSp_RE022_OxC_rMixtReqMonItrsv_in==
z4e6aed9849b7c76708e01f07179100da[1]){zf54e14dde5849195722c546b43fc721b=1;}else{
zf54e14dde5849195722c546b43fc721b=0;}if(zf54e14dde5849195722c546b43fc721b&&
FARSp_RE022_OxC_bAcvReqMonItrsv_in){zb13d9c95d6ccd9a815b562d95ff5a551=1;}else{
zb13d9c95d6ccd9a815b562d95ff5a551=0;}if(FARSp_RE022_LsMon_rMixtReqMonItrsv_in==
z4e6aed9849b7c76708e01f07179100da[1]){z89df2603f52f55624be4a65bebf2aef9=1;}else{
z89df2603f52f55624be4a65bebf2aef9=0;}if(z89df2603f52f55624be4a65bebf2aef9&&
FARSp_RE022_LsMon_bAcvReqMonItrsv_in){zbde7d66af1090601ddb7ecf618245aae=1;}else{
zbde7d66af1090601ddb7ecf618245aae=0;}if(FARSp_RE022_FARSp_rMixtTWCHeatSp_in==
z4e6aed9849b7c76708e01f07179100da[1]){z6652d80e42916a56f421a666e3bda23e=1;}else{
z6652d80e42916a56f421a666e3bda23e=0;}if(z6652d80e42916a56f421a666e3bda23e&&
FARSp_RE022_FARSp_bAcvRatMixtTWCHeat_in){z70989c0f9fced7600f5d844fa8878635=1;}
else{z70989c0f9fced7600f5d844fa8878635=0;}if(
FARSp_RE022_FARSp_rMixtThermoProtSp_in==z4e6aed9849b7c76708e01f07179100da[1]){
zfa01277723f1527d65f54580e401e991=1;}else{zfa01277723f1527d65f54580e401e991=0;}
if(FARSp_RE022_FARSp_rMixtMaxThermoProt_in==z4e6aed9849b7c76708e01f07179100da[1]
){z09fa263f0a626e666f10446a2d114f4f=1;}else{z09fa263f0a626e666f10446a2d114f4f=0;
}if(FARSp_RE022_FARSp_rMixtSelCutOffSp_in==z4e6aed9849b7c76708e01f07179100da[1])
{z5504cf659e330632b5d813855d87eb0c=1;}else{z5504cf659e330632b5d813855d87eb0c=0;}
if(z5504cf659e330632b5d813855d87eb0c&&FARSp_RE022_FARSp_bAcvSelCutOffSpcMixt_in)
{z0af483b70f6b141a1aa23054875afc7c=1;}else{z0af483b70f6b141a1aa23054875afc7c=0;}
if(FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in==z4e6aed9849b7c76708e01f07179100da[1]){
z8548d3e966f30adbe18088ef5fe7f251=1;}else{z8548d3e966f30adbe18088ef5fe7f251=0;}
if(FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in==z4e6aed9849b7c76708e01f07179100da[1]
){zea4904e0f3040bfcccb3516cb323348d=1;}else{zea4904e0f3040bfcccb3516cb323348d=0;
}if(FARSp_RE022_FARSp_rMixtLihSp_in==z4e6aed9849b7c76708e01f07179100da[1]){
z9fa4760f10461c23ef4364104bfe8c22=1;}else{z9fa4760f10461c23ef4364104bfe8c22=0;}
if(z9fa4760f10461c23ef4364104bfe8c22&&FARSp_RE022_FARSp_bLihAcv_in){
z9513026f9c0d193475622cb89426a9bf=1;}else{z9513026f9c0d193475622cb89426a9bf=0;}
if(FARSp_RE022_Afts_rMixtReqRlamSpTest_in==z4e6aed9849b7c76708e01f07179100da[1])
{zb0f5fd38fd208081fe776c79e791e4e0=1;}else{zb0f5fd38fd208081fe776c79e791e4e0=0;}
if(zb0f5fd38fd208081fe776c79e791e4e0&&FARSp_RE022_Afts_bAcvRlamSpTest_in){
za1e7719fe0430051d9259406ea63bbdb=1;}else{za1e7719fe0430051d9259406ea63bbdb=0;}
FARSp_prm_bRlamSpAcv_out[0]=z280b90878937cfb49d08483941d57d26;
FARSp_prm_bRlamSpAcv_out[1]=zc50f12b4763696611532602d97914281;
FARSp_prm_bRlamSpAcv_out[2]=z345dc2dda5b5370fd1d787aed2fdcae0;
FARSp_prm_bRlamSpAcv_out[3]=zda21bfacad6dd326bbc5529e5b7f37f2;
FARSp_prm_bRlamSpAcv_out[4]=z36f0a4bc15e0f001d48d6702d6ab3a66;
FARSp_prm_bRlamSpAcv_out[5]=z7eaa44677e3faeba1e7e75291a13b77c;
FARSp_prm_bRlamSpAcv_out[6]=zb13d9c95d6ccd9a815b562d95ff5a551;
FARSp_prm_bRlamSpAcv_out[7]=zbde7d66af1090601ddb7ecf618245aae;
FARSp_prm_bRlamSpAcv_out[8]=z70989c0f9fced7600f5d844fa8878635;
FARSp_prm_bRlamSpAcv_out[9]=zfa01277723f1527d65f54580e401e991;
FARSp_prm_bRlamSpAcv_out[10]=z09fa263f0a626e666f10446a2d114f4f;
FARSp_prm_bRlamSpAcv_out[11]=z0af483b70f6b141a1aa23054875afc7c;
FARSp_prm_bRlamSpAcv_out[12]=z8548d3e966f30adbe18088ef5fe7f251;
FARSp_prm_bRlamSpAcv_out[13]=zea4904e0f3040bfcccb3516cb323348d;
FARSp_prm_bRlamSpAcv_out[14]=z9513026f9c0d193475622cb89426a9bf;
FARSp_prm_bRlamSpAcv_out[15]=za1e7719fe0430051d9259406ea63bbdb;
FARSp_prm_bRlamSpAcv_out[16]=0;FARSp_prm_bRlamSpAcv_out[17]=0;
FARSp_prm_bRlamSpAcv_out[18]=0;FARSp_prm_bRlamSpAcv_out[19]=0;
FARSp_bStiBlbyNotAcv_out=z2010ea35b00d79fa6e85b6f296f0ecc1;
FARSp_rMixtCylSpWoutStiBlby_out=FARSp_prm_rMixtLimCmbSp[1];if(
FARSp_RE022_FARSp_bThermoProtAuth_in||FARSp_RE022_FARSp_bAcvRichFullLd_in||
FARSp_RE022_FARSp_bAcvAflScvGDI_in){ze4ab9a8ef9999df807b9fd6b224411de=1;}else{
ze4ab9a8ef9999df807b9fd6b224411de=0;}FARSp_bRichMixtAcv_out=
ze4ab9a8ef9999df807b9fd6b224411de;if(zf30876eeaa164a32faf3375e0c215a54<=((UInt32
)z16c2efe04c8340ae2caabc3af1d3338c)){zb8493af634b336a071a07f3fbe25f3da=1;}else{
zb8493af634b336a071a07f3fbe25f3da=0;}if(za27f91ae28b5af26fc07cc6904ce7bf0||
zb8493af634b336a071a07f3fbe25f3da){zcf1727ea9037e7d369f34d57304b9b5e=1;}else{
zcf1727ea9037e7d369f34d57304b9b5e=0;}FARSp_bThermoProtReqNotAuth_out=
zcf1727ea9037e7d369f34d57304b9b5e;if(z08bf02af507c6b450c34204371fe6972<=((UInt32
)z61d6e1f191de25b42122dc21d85b7277)){zfc8c1c60124679d6fbcd842f36615054=1;}else{
zfc8c1c60124679d6fbcd842f36615054=0;}if(zad9cfb6a2f9ad4c28e118ac1b4bfefaf||
zfc8c1c60124679d6fbcd842f36615054){z4db19efc85350248dd4c371c3b671230=1;}else{
z4db19efc85350248dd4c371c3b671230=0;}if(z4db19efc85350248dd4c371c3b671230||
FARSp_RE022_FARSp_bLihAcv_in||FARSp_RE022_FARSp_bAcvSelCutOffSpcMixt_in||
FARSp_RE022_FARSp_bAcvRatMixtTWCHeat_in){z9e2d6e9fddd5505a697c93c0204468d6=1;}
else{z9e2d6e9fddd5505a697c93c0204468d6=0;}FARSp_bRichLoTqReqNotAuth_out=
z9e2d6e9fddd5505a697c93c0204468d6;if(z94b743ece09631e85d7b36ee6095dd11<=((UInt32
)z7fb34223ed08e2b9d98d85eca2a20f83)){z0e6f934fbb91b982924f6595c85f5349=1;}else{
z0e6f934fbb91b982924f6595c85f5349=0;}if(z6be3bc88c8cb5e520358450ea3d3b3a9||
z0e6f934fbb91b982924f6595c85f5349){z867a39bf5d35184ca3ac2133d34f0a43=1;}else{
z867a39bf5d35184ca3ac2133d34f0a43=0;}FARSp_bRichScvThermoInvld_out=
z867a39bf5d35184ca3ac2133d34f0a43;if(FARSp_prm_rMixtCordManModSp[1]<=((UInt16)(
FARSp_rMixtLimMin>>12))){za7ea8ad209198b5ea48e26b2583afec2=1;}else{
za7ea8ad209198b5ea48e26b2583afec2=0;}FARSp_bSatMinRatMixt_out=
za7ea8ad209198b5ea48e26b2583afec2;if(FARSp_rMixtLimMax<=((UInt32)(((UInt32)
FARSp_prm_rMixtCordManModSp[1])<<12))){zf0d94c8cb548e2b7536585a2115255f2=1;}else
{zf0d94c8cb548e2b7536585a2115255f2=0;}FARSp_bSatMaxRatMixt_out=
zf0d94c8cb548e2b7536585a2115255f2;FARSp_rMixtCylSpWiStiTWC_out=
z4e6aed9849b7c76708e01f07179100da[0];if(FARSp_RE022_InjSys_prm_bCylCutOff_in[0]
||FARSp_RE022_InjSys_bTotCutOff_in){z2dc0370e08b384ad5999f09e02b93d6d=1;}else{
z2dc0370e08b384ad5999f09e02b93d6d=0;}if(z2dc0370e08b384ad5999f09e02b93d6d!=0){
z30ce9255a09f7f9a4e7e221eaf0d8d0c=0;}else{z30ce9255a09f7f9a4e7e221eaf0d8d0c=
FARSp_prm_rMixtStiBlbySp[0];}if(FARSp_RE022_InjSys_prm_bCylCutOff_in[1]||
FARSp_RE022_InjSys_bTotCutOff_in){zc0ec918a67ef56ab5a2f6ad9981e0b5c=1;}else{
zc0ec918a67ef56ab5a2f6ad9981e0b5c=0;}if(zc0ec918a67ef56ab5a2f6ad9981e0b5c!=0){
z69d0747ff8e805ae1b9cf6f1f2eeddd6=0;}else{z69d0747ff8e805ae1b9cf6f1f2eeddd6=
FARSp_prm_rMixtStiBlbySp[0];}if(FARSp_RE022_InjSys_prm_bCylCutOff_in[2]||
FARSp_RE022_InjSys_bTotCutOff_in){zb217715506bd87ec5f412b74b4a6104f=1;}else{
zb217715506bd87ec5f412b74b4a6104f=0;}if(zb217715506bd87ec5f412b74b4a6104f!=0){
za9c5b1760e057892123b941d4b965f19=0;}else{za9c5b1760e057892123b941d4b965f19=
FARSp_prm_rMixtStiBlbySp[0];}if(FARSp_RE022_InjSys_prm_bCylCutOff_in[3]||
FARSp_RE022_InjSys_bTotCutOff_in){z0ba0c693003e488503154d111c9819d3=1;}else{
z0ba0c693003e488503154d111c9819d3=0;}if(z0ba0c693003e488503154d111c9819d3!=0){
zf9681e56599e5c7b4e4793bbcac5fba3=0;}else{zf9681e56599e5c7b4e4793bbcac5fba3=
FARSp_prm_rMixtStiBlbySp[0];}if(FARSp_RE022_InjSys_prm_bCylCutOff_in[4]||
FARSp_RE022_InjSys_bTotCutOff_in){z0ba483887fd94532473be91baac1b28c=1;}else{
z0ba483887fd94532473be91baac1b28c=0;}if(z0ba483887fd94532473be91baac1b28c!=0){
zac22fe3c59c3667dfcfd4f57c1c6b226=0;}else{zac22fe3c59c3667dfcfd4f57c1c6b226=
FARSp_prm_rMixtStiBlbySp[0];}if(FARSp_RE022_InjSys_prm_bCylCutOff_in[5]||
FARSp_RE022_InjSys_bTotCutOff_in){z34245aa2644cbd08269ff9755de13852=1;}else{
z34245aa2644cbd08269ff9755de13852=0;}if(z34245aa2644cbd08269ff9755de13852!=0){
zab85207380232f84f8a17682b9e0da67=0;}else{zab85207380232f84f8a17682b9e0da67=
FARSp_prm_rMixtStiBlbySp[0];}FARSp_prm_rMixtCylSp_out[0]=
z30ce9255a09f7f9a4e7e221eaf0d8d0c;FARSp_prm_rMixtCylSp_out[1]=
z69d0747ff8e805ae1b9cf6f1f2eeddd6;FARSp_prm_rMixtCylSp_out[2]=
za9c5b1760e057892123b941d4b965f19;FARSp_prm_rMixtCylSp_out[3]=
zf9681e56599e5c7b4e4793bbcac5fba3;FARSp_prm_rMixtCylSp_out[4]=
zac22fe3c59c3667dfcfd4f57c1c6b226;FARSp_prm_rMixtCylSp_out[5]=
zab85207380232f84f8a17682b9e0da67;FARSp_rMixtCylSp_out=
z4e6aed9849b7c76708e01f07179100da[1];X_S02234_UnitDelay[0]=
zf521768e7d40abcfd5133af123869e90[0];X_S02234_UnitDelay[1]=
zf521768e7d40abcfd5133af123869e90[1];X_S02236_UnitDelay=
z2010ea35b00d79fa6e85b6f296f0ecc1;X_S02240_Unit_Delay2[0]=
z63bd4a2edb0f162d60bbe67abdfb5a73[0];X_S02240_Unit_Delay2[1]=
z63bd4a2edb0f162d60bbe67abdfb5a73[1];X_S02240_Unit_Delay1=1;X_S02233_UnitDelay[0
]=z985f2931e897c137b3c788fec5a793e1[0];X_S02233_UnitDelay[1]=
z985f2931e897c137b3c788fec5a793e1[1];X_S02239_UnitDelay=1;X_S02234_UnitDelay1=1;
z9907020dab386f55ab3c07f2c32c92e3=z4abe3cb23b1d4c5f558ca835294001bc;
z6ad21a6292b890e3892ccc743c529c9f=ze704ec0bf1ef68e579c390a6d26058d4;
zaee69924ddb752158ce9a123f4e81ad8=z0da06aa7b2e97910149469d8e48219af;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_022_FctVarInit(Void){FARSp_RE022_FARSp_bAcvAflScvGDI_in=1;
FARSp_RE022_FARSp_rMixtBasSp_in=4096;FARSp_RE022_OxC_bAcvReqMonItrsv_in=1;
FARSp_bRichLoTqReqNotAuth_out=0;FARSp_bRichMixtAcv_out=0;
FARSp_bRichScvThermoInvld_out=0;FARSp_bSatMaxRatMixt_out=0;
FARSp_bSatMinRatMixt_out=0;FARSp_bThermoProtReqNotAuth_out=0;
FARSp_rMixtCylSp_out=4096;z390e538ff95ba6ed49d261545b67dde2=0;
za8a70eb8dfd745961a45abbb5d71710d=0;z6ea99540255b8247269758b32aab1197=0;
z8b2db8277f4448d8887022ca8bdb7672=0;z025b1fb95a3eceaafeb8a39d30a6e589=0;
zc11d3194732387acd8ac9ee4d1e3354e=0;zcc03d6503b892710c34c33b3dc774c11=0;
z7f25817fb08f9f57a7ef30f8bd55d04f=0;X_S02233_UnitDelay[0]=67108864;
X_S02233_UnitDelay[1]=67108864;X_S02234_UnitDelay[0]=0;X_S02234_UnitDelay[1]=0;
X_S02234_UnitDelay1=0;X_S02236_UnitDelay=0;X_S02239_UnitDelay=0;
X_S02240_Unit_Delay1=0;X_S02240_Unit_Delay2[0]=0;X_S02240_Unit_Delay2[1]=0;
zaee69924ddb752158ce9a123f4e81ad8=65535;z6ad21a6292b890e3892ccc743c529c9f=65535;
z9907020dab386f55ab3c07f2c32c92e3=65535;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

