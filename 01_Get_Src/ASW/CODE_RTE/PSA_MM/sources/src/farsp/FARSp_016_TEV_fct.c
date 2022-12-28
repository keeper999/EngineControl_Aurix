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
* %name: FARSp_016_TEV_fct.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:56 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_016_TEV_fct.c-3.0:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_016_TEV_FCT_C_
#define _FARSP_016_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_016_TEV_fct.h"
#include "FARSp_016_calibrations.h"
#include "dsfxp.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE016_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE016_Ext_nEng_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE016_FARSp_prm_rMixtGasFlexSp_in[24];AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtAgIgMinProtSp_out;AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtAutIgPrvtSp_out;AR_IF_GLOBAL_16BIT UInt16 FARSp_rMixtLoTqReqSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE016_FARSp_prm_facGasFlexSp_in[24];
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE016_IgSys_agIgLimKnkMin_in;AR_IF_GLOBAL_8BIT 
UInt8 FARSp_RE016_IgSys_agIgLimKnkMv_in;AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE016_IgSys_agIgLimMinKnk_in;AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE016_IgSys_agIgLimMinRef_in;AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE016_IgSys_agIgMinCmb_in;AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE016_IgSys_agIgSp_in;
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE016_TPM_bExThermoProt_in;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z2d69cf511cf23dc92f1411a339a36913;static UInt16 
z65c86d978e87cbf8e300288ccf8f134f;static UInt16 
z4b987e4cca964cc34f0c0ab5506628d0;static UInt16 
zbe1806616b35957a3de9ed9600f705b4;static UInt16 
z12cc4285fb303a9b7c06833deffd8116;static UInt16 
z99e8c3f07e2fae12c2b8e70b60d30ca4;static UInt16 
zb681f194967361f721269596957c08ce;static UInt16 
z3717bd776864a5d4dadaf47b92e9dd7d;static UInt16 
z5fcc11ef7c78d95426b7e949d31fccc0;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 z4ca1a21de06a80f4ab646c96e2236b18;static UInt8 
z7c2d969271b69d2714756281e572a835;static UInt8 zb8b903ca5d2fd20f22a706cefb284a08
;static UInt8 z85b4de0afd7459edfd9c727bccee4b73;static UInt8 
z96f75a46fd8f8fdc8549f271be8705f6;static UInt8 z2625f809e83b5ce062d394d64aca7888
;static UInt8 ze51ac887a5af13fd36026ee7f90441f2;static UInt8 
zf6b92da356b451bf9b008464f529b3f4;static UInt8 zd4923cd98891831d0f672435e0a15e3c
;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_015_MSE_ini(Void){FARSp_016_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_016_TEV_fct(Void){SInt32 z657452f7d84edb023862778d9097e655;UInt32 
z442959254be3a5431636932a86c05be0;SInt32 z34147d18e963f618051f461607a6abd1;
SInt32 z1a9f74cb3842a296b706b53995cd97a3;SInt32 
z9a770ea5b9942f2e95049ee2eb36c4a5;SInt32 zd444ba085a84c05909ad835a444409d5;
SInt32 z7caa0642ad8d97657d9d062b31d81118;SInt32 
z0743278f499b93db3403bba8cec0dcc3;SInt32 z2c729fedf113c763b9bae025965eb5c7;
SInt32 z00906c8a36854045abcb4640c042c7d0;SInt32 
z41006d612cb03bc8307cfa19bdda5cb8;SInt32 z313556cbc9559b66307c60eb03e9be58;
SInt32 zc83cabdaebc00924555fc924e04124c1;SInt32 
z29da238e83a4ec799deadd018b1ff8aa;SInt32 zfb203f7223d22296c0fe9155f443e59f;
SInt32 z55f023fb8362f883ef56ad667b90bec0;SInt32 
z981421acbcde8855269a02de48dc7186;SInt32 z53b0423794cf527c64ba36a169ce50d3;
SInt32 zbcf721e392a8cbe5ef7bad2b3392524c;SInt32 
zf9298914e692c9ac8ffa05218724d95a;SInt32 z658e5db388cc0081392f2574144ba481;
SInt32 zb722bb15d85ece782a2f01cb5259c30d;SInt16 
zca7bf51ed761f59a35ba9260f4f26800;UInt16 z92e93f138d30aabaa60a1b7438fba5d8;
UInt16 z8420b44dd79bd31ee4b28b6c679fc3fa;UInt16 
z299a23972d9c863b6cf54041f6128243;SInt16 za0891648ea350211534c1d888ae1595e;
SInt16 z5585149af7bd995c4911b8e69337c969;UInt16 
zdc8b97afd4ae5a93fbf4ecf6e26a9aef;SInt16 z60571f3c3e5dc33776c551b1d08e17ff;
UInt16 z0737dca69fbf3e85a160954432dac685;SInt16 
zed4ae59395b5009d960603d049ed1e4c;UInt16 z42e85cc9fe8dee86fec6890b0bef5aa3;UInt8
 zbcebd62188f6b5fac2128836d59e5f27;UInt8 ze938daa7715adafc0484262f0b97a648;
Boolean z407c43fcd09dd004bb4302b8feef7108;Boolean 
zb938f300f4ca9d9e346e55abe33edfa3;UInt8 z4ec1a87d04da97b49bf1f83c9329aad2;UInt8 
zd884bd9c933ba7e350b1a99058dea4cd;Boolean z37691f265fe78e793f9e5eee21302f67;
Boolean z505b0a1a40b966ab3cb61c54c6f69620;UInt8 
z9b84611e96114ed46cce230b28081c03;UInt8 z7955d83d064f5a82bcbb65330ef0d5f8;
Boolean z3927ae1d06709d73e678b30dedd2e52f;Boolean 
zaf3963dae3eb8c0f1d80e90f2a9e8f05;UInt8 zee8074862f7be59b7c2585545915f632;UInt8 
z94d2025d38c1557094c1e0c79bb71a5c;Boolean zd19488ae8fa086dc2dc146fbd66a2d72;
Boolean z0123fe0e6399e81461ae256ff83072cf;UInt8 
z2c037e525234abef8ef09666d6b27ca2;UInt8 z3e4b9d66a95cac2f93d6795c1ed0ba6a;
Boolean zad3b47f7894f70908b019dc5f69fcd2c;Boolean 
zc833e9cc018552d0fe74e50893dad4d6;UInt8 z294e92835dc15a00154e21f966d9ec90;UInt8 
z8697b988e3fe74948af63dc6f7956811;Boolean zb77112d76c7002149ea1a86fc174cf4d;
Boolean z1e68c850a281970044f52d3a50882fb8;Boolean 
z68e9839f7c76ba4f56ff3f8545d5cee8;Boolean z9dd88a8e42e81b3b4ae8de8e34c47f7d;
Boolean zc0fb9e110cf0155119901640e6814e5b;Boolean 
z3ef73c0331d006be76f482fd23d2f478;Boolean z35210b2399cd35426e0dbac67b2d1c3a;
Boolean z221b42c3e537a86498eaab2f06951847;UInt8 
z014ebc3c069c3fbe596937238599d69f;UInt8 zf405fa2642427c35cd68d39625dd37ea;
Boolean z95beb51b873b2efeebda170d3b9d120d;Boolean 
za7cb3b5a746dc1e13bcfe26da503cbdd;Boolean z9fa40ba5bf83a2dff1a604054258abae;
Boolean z745efee7a580c7bebb91d8547c1a4edf;SInt32 
zcb4212a0d00d75016670ed5391d4bb1d;UInt32 z1cb1a1497410b13813fdd4a83b2f0925;
SInt32 z1f8568e2a312eeded13d6e88817fdf9c;UInt32 
zcf8c1dcf09c7e455cb239c5fc102b1bb;UInt32 z8e51e4591fcc685001532289e452bd62;
FARSp_facAutIgPrvtSpGas=FARSp_RE016_FARSp_prm_facGasFlexSp_in[10];if(
FARSp_facAutIgPrvtSpGas<=0){zaf3963dae3eb8c0f1d80e90f2a9e8f05=1;}else{
zaf3963dae3eb8c0f1d80e90f2a9e8f05=0;}FARSp_facAutIgPrvtSpFlex=
FARSp_RE016_FARSp_prm_facGasFlexSp_in[11];if(FARSp_facAutIgPrvtSpFlex<=0){
z505b0a1a40b966ab3cb61c54c6f69620=1;}else{z505b0a1a40b966ab3cb61c54c6f69620=0;}
zed4ae59395b5009d960603d049ed1e4c=(SInt16)(((UInt16)
FARSp_RE016_IgSys_agIgLimKnkMin_in)-((UInt16)FARSp_RE016_IgSys_agIgMinCmb_in));
TabIdxS50T516((const SInt16*)FARSp_agIgDif_facAutIgPrvt_A,10,
zed4ae59395b5009d960603d049ed1e4c,&(zd4923cd98891831d0f672435e0a15e3c),&(
z5fcc11ef7c78d95426b7e949d31fccc0));FARSp_facRichAutIgPrvtCor_MP=Tab1DIntp2I1T64
((const UInt8*)FARSp_facAutIgPrvtCor_T,zd4923cd98891831d0f672435e0a15e3c,
z5fcc11ef7c78d95426b7e949d31fccc0);if(FARSp_facRichAutIgPrvtCor_MP<=0){
zb938f300f4ca9d9e346e55abe33edfa3=1;}else{zb938f300f4ca9d9e346e55abe33edfa3=0;}
if(128<=FARSp_facAutIgPrvtSpGas){z3927ae1d06709d73e678b30dedd2e52f=1;}else{
z3927ae1d06709d73e678b30dedd2e52f=0;}if(128<=FARSp_facAutIgPrvtSpFlex){
z37691f265fe78e793f9e5eee21302f67=1;}else{z37691f265fe78e793f9e5eee21302f67=0;}
if(128<=FARSp_facRichAutIgPrvtCor_MP){z407c43fcd09dd004bb4302b8feef7108=1;}else{
z407c43fcd09dd004bb4302b8feef7108=0;}if(FARSp_RE016_IgSys_agIgLimKnkMv_in<
FARSp_RE016_IgSys_agIgLimMinRef_in){z68e9839f7c76ba4f56ff3f8545d5cee8=1;}else{
z68e9839f7c76ba4f56ff3f8545d5cee8=0;}if(FARSp_RE016_TPM_bExThermoProt_in&&
z68e9839f7c76ba4f56ff3f8545d5cee8){FARSp_bRichAgIgMinProt=1;}else{
FARSp_bRichAgIgMinProt=0;}if(FARSp_bRichAgIgMinProt>0){SInt32 
zf2db5999c2eb295c38ea65e87793add2;UInt32 z7a5324c7539cb46c4a9459c152a42e3f;
UInt16 z6aef5c1bd1b6e842408a5c8546f4670a;SInt16 
z9e8893cbbbf79c6c88d6ce42c26ffe2b;UInt8 z8a32e8d845d1f17c84c918e08dcfca18;
z5585149af7bd995c4911b8e69337c969=(SInt16)(((UInt16)
FARSp_RE016_IgSys_agIgLimMinRef_in)-((UInt16)FARSp_RE016_IgSys_agIgLimMinKnk_in)
);if(z5585149af7bd995c4911b8e69337c969>=0){z35210b2399cd35426e0dbac67b2d1c3a=1;}
else{z35210b2399cd35426e0dbac67b2d1c3a=0;}za0891648ea350211534c1d888ae1595e=(
SInt16)(((UInt16)FARSp_RE016_IgSys_agIgLimMinRef_in)-((UInt16)
FARSp_RE016_IgSys_agIgLimKnkMv_in));z60571f3c3e5dc33776c551b1d08e17ff=6144;
z6aef5c1bd1b6e842408a5c8546f4670a=(UInt16)z5585149af7bd995c4911b8e69337c969;if(
z5585149af7bd995c4911b8e69337c969<0){z6aef5c1bd1b6e842408a5c8546f4670a=-((SInt16
)z6aef5c1bd1b6e842408a5c8546f4670a);}zdc8b97afd4ae5a93fbf4ecf6e26a9aef=
z6aef5c1bd1b6e842408a5c8546f4670a;z8a32e8d845d1f17c84c918e08dcfca18=(UInt8)(
UInt16)(z60571f3c3e5dc33776c551b1d08e17ff/6144);if(
z8a32e8d845d1f17c84c918e08dcfca18>((UInt8)zdc8b97afd4ae5a93fbf4ecf6e26a9aef)){
z0737dca69fbf3e85a160954432dac685=(UInt16)z8a32e8d845d1f17c84c918e08dcfca18;}
else{z0737dca69fbf3e85a160954432dac685=zdc8b97afd4ae5a93fbf4ecf6e26a9aef;}
zf9298914e692c9ac8ffa05218724d95a=((SInt32)(((SInt32)
za0891648ea350211534c1d888ae1595e)<<16))/z0737dca69fbf3e85a160954432dac685;
z55f023fb8362f883ef56ad667b90bec0=-zf9298914e692c9ac8ffa05218724d95a;if(
z35210b2399cd35426e0dbac67b2d1c3a!=0){z981421acbcde8855269a02de48dc7186=
zf9298914e692c9ac8ffa05218724d95a;}else{z981421acbcde8855269a02de48dc7186=
z55f023fb8362f883ef56ad667b90bec0;}if(z981421acbcde8855269a02de48dc7186>-327680)
{z53b0423794cf527c64ba36a169ce50d3=z981421acbcde8855269a02de48dc7186;}else{
z53b0423794cf527c64ba36a169ce50d3=-327680;}if(327680<
z53b0423794cf527c64ba36a169ce50d3){zbcf721e392a8cbe5ef7bad2b3392524c=327680;}
else{zbcf721e392a8cbe5ef7bad2b3392524c=z53b0423794cf527c64ba36a169ce50d3;}if(
zbcf721e392a8cbe5ef7bad2b3392524c<=0){zc0fb9e110cf0155119901640e6814e5b=1;}else{
zc0fb9e110cf0155119901640e6814e5b=0;}if(zbcf721e392a8cbe5ef7bad2b3392524c>0){
zfb203f7223d22296c0fe9155f443e59f=zbcf721e392a8cbe5ef7bad2b3392524c;}else{
zfb203f7223d22296c0fe9155f443e59f=0;}z9e8893cbbbf79c6c88d6ce42c26ffe2b=(SInt16)(
zfb203f7223d22296c0fe9155f443e59f>>9);if(128<z9e8893cbbbf79c6c88d6ce42c26ffe2b){
FARSp_rAgIgMinLim_MP=128;}else{FARSp_rAgIgMinLim_MP=(UInt8)
z9e8893cbbbf79c6c88d6ce42c26ffe2b;}TabIdxS50T512((const UInt8*)
FARSp_rAgIg_facAgIgMinProt_A,10,FARSp_rAgIgMinLim_MP,&(
z2625f809e83b5ce062d394d64aca7888),&(z99e8c3f07e2fae12c2b8e70b60d30ca4));
FARSp_facRichAgIgMinProt_MP=Tab1DIntp2I1T64((const UInt8*)
FARSp_facAgIgMinProtCor_T,z2625f809e83b5ce062d394d64aca7888,
z99e8c3f07e2fae12c2b8e70b60d30ca4);if(FARSp_facRichAgIgMinProt_MP<=0){
za7cb3b5a746dc1e13bcfe26da503cbdd=1;}else{za7cb3b5a746dc1e13bcfe26da503cbdd=0;}
if(65536<=zbcf721e392a8cbe5ef7bad2b3392524c){z9dd88a8e42e81b3b4ae8de8e34c47f7d=1
;}else{z9dd88a8e42e81b3b4ae8de8e34c47f7d=0;}if(128<=FARSp_facRichAgIgMinProt_MP)
{z95beb51b873b2efeebda170d3b9d120d=1;}else{z95beb51b873b2efeebda170d3b9d120d=0;}
if(327680<=z981421acbcde8855269a02de48dc7186){z9fa40ba5bf83a2dff1a604054258abae=
1;}else{z9fa40ba5bf83a2dff1a604054258abae=0;}if(
z981421acbcde8855269a02de48dc7186<=-327680){z745efee7a580c7bebb91d8547c1a4edf=1;
}else{z745efee7a580c7bebb91d8547c1a4edf=0;}if(z9fa40ba5bf83a2dff1a604054258abae
||z745efee7a580c7bebb91d8547c1a4edf){z3ef73c0331d006be76f482fd23d2f478=1;}else{
z3ef73c0331d006be76f482fd23d2f478=0;}if(z3ef73c0331d006be76f482fd23d2f478!=0){
z221b42c3e537a86498eaab2f06951847=1;}else{z221b42c3e537a86498eaab2f06951847=0;}
if(FARSp_facRichAgIgMinProt_MP>0){z014ebc3c069c3fbe596937238599d69f=
FARSp_facRichAgIgMinProt_MP;}else{z014ebc3c069c3fbe596937238599d69f=0;}if(128<
z014ebc3c069c3fbe596937238599d69f){zf405fa2642427c35cd68d39625dd37ea=128;}else{
zf405fa2642427c35cd68d39625dd37ea=z014ebc3c069c3fbe596937238599d69f;}
TabIdxS50T513((const UInt16*)FARSp_nEng_AgIgMinProtX_A,10,
FARSp_RE016_Ext_nEng_in,&(z85b4de0afd7459edfd9c727bccee4b73),&(
zbe1806616b35957a3de9ed9600f705b4));TabIdxS50T513((const UInt16*)
FARSp_rAirLd_AgIgMinProtY_A,10,FARSp_RE016_EngM_rAirLdCor_in,&(
z96f75a46fd8f8fdc8549f271be8705f6),&(z12cc4285fb303a9b7c06833deffd8116));
FARSp_rMixtAgIgMinProtMax_MP=Tab2DIntp2I1T33281((const UInt16*)&(
FARSp_rMixtAgIgMinProtMax_M[0][0]),10,z85b4de0afd7459edfd9c727bccee4b73,
zbe1806616b35957a3de9ed9600f705b4,z96f75a46fd8f8fdc8549f271be8705f6,
z12cc4285fb303a9b7c06833deffd8116);z29da238e83a4ec799deadd018b1ff8aa=(SInt32)(((
SInt32)(((UInt32)FARSp_rMixtAgIgMinProtMax_MP)-((UInt32)
FARSp_rMixtAgIgMinProtMin_C)))<<14);F__I64MULU32I32((UInt32)
zf405fa2642427c35cd68d39625dd37ea,z29da238e83a4ec799deadd018b1ff8aa,&(
zf2db5999c2eb295c38ea65e87793add2),&(z7a5324c7539cb46c4a9459c152a42e3f));
zc83cabdaebc00924555fc924e04124c1=C__I32SHRI64C6_LT32(
zf2db5999c2eb295c38ea65e87793add2,z7a5324c7539cb46c4a9459c152a42e3f,7,25);
FARSp_rMixtAgIgMinProtRaw=(UInt32)(zc83cabdaebc00924555fc924e04124c1+((UInt32)((
(UInt32)FARSp_rMixtAgIgMinProtMin_C)<<14)));}if(FARSp_bRichAgIgMinProt!=0){
FARSp_rMixtAgIgMinProtSp_irv_MP=(UInt16)(FARSp_rMixtAgIgMinProtRaw>>14);}else{
FARSp_rMixtAgIgMinProtSp_irv_MP=FARSp_rMixtAgIgMinProtMin_C;}if(
FARSp_RE016_IgSys_agIgSp_in<FARSp_RE016_IgSys_agIgMinCmb_in){FARSp_bRichLoTqReq=
1;}else{FARSp_bRichLoTqReq=0;}if(FARSp_bRichLoTqReq>0){SInt32 
z71034583e7ad0155ef8aa49c512a61b3;UInt32 z86c4d0ac8c46ee4e1c9d7163c0584249;
zca7bf51ed761f59a35ba9260f4f26800=(SInt16)(((UInt16)
FARSp_RE016_IgSys_agIgMinCmb_in)-((UInt16)FARSp_RE016_IgSys_agIgSp_in));
TabIdxS50T516((const SInt16*)FARSp_agIgDif_LoTqReq_A,10,
zca7bf51ed761f59a35ba9260f4f26800,&(zb8b903ca5d2fd20f22a706cefb284a08),&(
z4b987e4cca964cc34f0c0ab5506628d0));FARSp_facRichLoTqReqCor_MP=Tab1DIntp2I1T64((
const UInt8*)FARSp_facRichLoTqReqCor_T,zb8b903ca5d2fd20f22a706cefb284a08,
z4b987e4cca964cc34f0c0ab5506628d0);if(FARSp_facRichLoTqReqCor_MP<=0){
z0123fe0e6399e81461ae256ff83072cf=1;}else{z0123fe0e6399e81461ae256ff83072cf=0;}
if(128<=FARSp_facRichLoTqReqCor_MP){zd19488ae8fa086dc2dc146fbd66a2d72=1;}else{
zd19488ae8fa086dc2dc146fbd66a2d72=0;}if(FARSp_facRichLoTqReqCor_MP>0){
zee8074862f7be59b7c2585545915f632=FARSp_facRichLoTqReqCor_MP;}else{
zee8074862f7be59b7c2585545915f632=0;}if(128<zee8074862f7be59b7c2585545915f632){
z94d2025d38c1557094c1e0c79bb71a5c=128;}else{z94d2025d38c1557094c1e0c79bb71a5c=
zee8074862f7be59b7c2585545915f632;}TabIdxS50T513((const UInt16*)
FARSp_nEng_LoTqReqMaxX_A,10,FARSp_RE016_Ext_nEng_in,&(
z4ca1a21de06a80f4ab646c96e2236b18),&(z2d69cf511cf23dc92f1411a339a36913));
TabIdxS50T513((const UInt16*)FARSp_rAirLd_LoTqReqMaxY_A,10,
FARSp_RE016_EngM_rAirLdCor_in,&(z7c2d969271b69d2714756281e572a835),&(
z65c86d978e87cbf8e300288ccf8f134f));FARSp_rMixtLoTqReqMax_MP=Tab2DIntp2I1T33281(
(const UInt16*)&(FARSp_rMixtLoTqReqMax_M[0][0]),10,
z4ca1a21de06a80f4ab646c96e2236b18,z2d69cf511cf23dc92f1411a339a36913,
z7c2d969271b69d2714756281e572a835,z65c86d978e87cbf8e300288ccf8f134f);
z0743278f499b93db3403bba8cec0dcc3=(SInt32)(((SInt32)(((UInt32)
FARSp_rMixtLoTqReqMax_MP)-((UInt32)FARSp_rMixtLoTqReqRef_C)))<<12);
F__I64MULU32I32((UInt32)z94d2025d38c1557094c1e0c79bb71a5c,
z0743278f499b93db3403bba8cec0dcc3,&(z71034583e7ad0155ef8aa49c512a61b3),&(
z86c4d0ac8c46ee4e1c9d7163c0584249));z7caa0642ad8d97657d9d062b31d81118=
C__I32SHRI64C6_LT32(z71034583e7ad0155ef8aa49c512a61b3,
z86c4d0ac8c46ee4e1c9d7163c0584249,7,25);FARSp_rMixtLoTqReqSpGsl=(UInt32)(
z7caa0642ad8d97657d9d062b31d81118+((UInt32)(((UInt32)FARSp_rMixtLoTqReqRef_C)<<
12)));}if(FARSp_bRichLoTqReq>0){FARSp_facLoTqReqGas=
FARSp_RE016_FARSp_prm_facGasFlexSp_in[12];if(FARSp_facLoTqReqGas<=0){
z1e68c850a281970044f52d3a50882fb8=1;}else{z1e68c850a281970044f52d3a50882fb8=0;}
FARSp_facLoTqReqFlex=FARSp_RE016_FARSp_prm_facGasFlexSp_in[13];if(
FARSp_facLoTqReqFlex<=0){zc833e9cc018552d0fe74e50893dad4d6=1;}else{
zc833e9cc018552d0fe74e50893dad4d6=0;}if(128<=FARSp_facLoTqReqGas){
zb77112d76c7002149ea1a86fc174cf4d=1;}else{zb77112d76c7002149ea1a86fc174cf4d=0;}
if(128<=FARSp_facLoTqReqFlex){zad3b47f7894f70908b019dc5f69fcd2c=1;}else{
zad3b47f7894f70908b019dc5f69fcd2c=0;}if(FARSp_facLoTqReqGas>0){
z294e92835dc15a00154e21f966d9ec90=FARSp_facLoTqReqGas;}else{
z294e92835dc15a00154e21f966d9ec90=0;}if(128<z294e92835dc15a00154e21f966d9ec90){
z8697b988e3fe74948af63dc6f7956811=128;}else{z8697b988e3fe74948af63dc6f7956811=
z294e92835dc15a00154e21f966d9ec90;}FARSp_rMixtLoTqReqSpGas=
FARSp_RE016_FARSp_prm_rMixtGasFlexSp_in[12];if(FARSp_facLoTqReqFlex>0){
z2c037e525234abef8ef09666d6b27ca2=FARSp_facLoTqReqFlex;}else{
z2c037e525234abef8ef09666d6b27ca2=0;}if(128<z2c037e525234abef8ef09666d6b27ca2){
z3e4b9d66a95cac2f93d6795c1ed0ba6a=128;}else{z3e4b9d66a95cac2f93d6795c1ed0ba6a=
z2c037e525234abef8ef09666d6b27ca2;}FARSp_rMixtLoTqReqSpFlex=
FARSp_RE016_FARSp_prm_rMixtGasFlexSp_in[13];z00906c8a36854045abcb4640c042c7d0=(
SInt32)(((UInt32)FARSp_rMixtLoTqReqSpFlex)-((UInt32)(SInt32)(
FARSp_rMixtLoTqReqSpGsl>>12)));z2c729fedf113c763b9bae025965eb5c7=(SInt32)((((
SInt32)z3e4b9d66a95cac2f93d6795c1ed0ba6a)*z00906c8a36854045abcb4640c042c7d0)>>7)
;FARSp_rMixtLoTqReqFlex_MP=(UInt16)(((UInt16)z2c729fedf113c763b9bae025965eb5c7)+
((UInt16)(FARSp_rMixtLoTqReqSpGsl>>12)));z299a23972d9c863b6cf54041f6128243=
FARSp_rMixtLoTqReqFlex_MP;z313556cbc9559b66307c60eb03e9be58=(SInt32)(((UInt32)
FARSp_rMixtLoTqReqSpGas)-((UInt32)z299a23972d9c863b6cf54041f6128243));
z41006d612cb03bc8307cfa19bdda5cb8=(SInt32)((((SInt32)
z8697b988e3fe74948af63dc6f7956811)*z313556cbc9559b66307c60eb03e9be58)>>7);
FARSp_rMixtLoTqReqSpRaw=(UInt16)(((UInt16)z41006d612cb03bc8307cfa19bdda5cb8)+
z299a23972d9c863b6cf54041f6128243);}if(FARSp_bRichLoTqReq!=0){
FARSp_rMixtLoTqReqSp=FARSp_rMixtLoTqReqSpRaw;}else{FARSp_rMixtLoTqReqSp=
FARSp_rMixtLoTqReqRef_C;}if(FARSp_facAutIgPrvtSpGas>0){
z9b84611e96114ed46cce230b28081c03=FARSp_facAutIgPrvtSpGas;}else{
z9b84611e96114ed46cce230b28081c03=0;}if(128<z9b84611e96114ed46cce230b28081c03){
z7955d83d064f5a82bcbb65330ef0d5f8=128;}else{z7955d83d064f5a82bcbb65330ef0d5f8=
z9b84611e96114ed46cce230b28081c03;}FARSp_rMixtAutIgPrvtSpGas=
FARSp_RE016_FARSp_prm_rMixtGasFlexSp_in[10];if(FARSp_facAutIgPrvtSpFlex>0){
z4ec1a87d04da97b49bf1f83c9329aad2=FARSp_facAutIgPrvtSpFlex;}else{
z4ec1a87d04da97b49bf1f83c9329aad2=0;}if(128<z4ec1a87d04da97b49bf1f83c9329aad2){
zd884bd9c933ba7e350b1a99058dea4cd=128;}else{zd884bd9c933ba7e350b1a99058dea4cd=
z4ec1a87d04da97b49bf1f83c9329aad2;}FARSp_rMixtAutIgPrvtSpFlex=
FARSp_RE016_FARSp_prm_rMixtGasFlexSp_in[11];if(FARSp_facRichAutIgPrvtCor_MP>0){
zbcebd62188f6b5fac2128836d59e5f27=FARSp_facRichAutIgPrvtCor_MP;}else{
zbcebd62188f6b5fac2128836d59e5f27=0;}if(128<zbcebd62188f6b5fac2128836d59e5f27){
ze938daa7715adafc0484262f0b97a648=128;}else{ze938daa7715adafc0484262f0b97a648=
zbcebd62188f6b5fac2128836d59e5f27;}TabIdxS50T513((const UInt16*)
FARSp_nEng_AutIgPrvtMaxX_A,10,FARSp_RE016_Ext_nEng_in,&(
ze51ac887a5af13fd36026ee7f90441f2),&(zb681f194967361f721269596957c08ce));
TabIdxS50T513((const UInt16*)FARSp_rAirLd_AutIgPrvtMaxY_A,10,
FARSp_RE016_EngM_rAirLdCor_in,&(zf6b92da356b451bf9b008464f529b3f4),&(
z3717bd776864a5d4dadaf47b92e9dd7d));FARSp_rMixtAutIgPrvtMax_MP=
Tab2DIntp2I1T33281((const UInt16*)&(FARSp_rMixtAutIgPrvtMax_M[0][0]),10,
ze51ac887a5af13fd36026ee7f90441f2,zb681f194967361f721269596957c08ce,
zf6b92da356b451bf9b008464f529b3f4,z3717bd776864a5d4dadaf47b92e9dd7d);
zb722bb15d85ece782a2f01cb5259c30d=(SInt32)(((UInt32)FARSp_rMixtAutIgPrvtMax_MP)-
((UInt32)FARSp_rMixtAutIgPrvtRef_C));z658e5db388cc0081392f2574144ba481=(SInt32)(
(((SInt32)ze938daa7715adafc0484262f0b97a648)*zb722bb15d85ece782a2f01cb5259c30d)
>>7);FARSp_rMixtAutIgPrvtSpGsl=(UInt16)(((UInt16)
z658e5db388cc0081392f2574144ba481)+FARSp_rMixtAutIgPrvtRef_C);
z42e85cc9fe8dee86fec6890b0bef5aa3=FARSp_rMixtAutIgPrvtSpGsl;
z34147d18e963f618051f461607a6abd1=(SInt32)(((SInt32)(((UInt32)
FARSp_rMixtAutIgPrvtSpFlex)-((UInt32)z42e85cc9fe8dee86fec6890b0bef5aa3)))<<12);
F__I64MULU32I32((UInt32)zd884bd9c933ba7e350b1a99058dea4cd,
z34147d18e963f618051f461607a6abd1,&(zcb4212a0d00d75016670ed5391d4bb1d),&(
z1cb1a1497410b13813fdd4a83b2f0925));z657452f7d84edb023862778d9097e655=
C__I32SHRI64C6_LT32(zcb4212a0d00d75016670ed5391d4bb1d,
z1cb1a1497410b13813fdd4a83b2f0925,7,25);FARSp_rMixtAutIgPrvtFlex_MP=(UInt32)(
z657452f7d84edb023862778d9097e655+((UInt32)(((UInt32)
z42e85cc9fe8dee86fec6890b0bef5aa3)<<12)));z442959254be3a5431636932a86c05be0=
FARSp_rMixtAutIgPrvtFlex_MP;z9a770ea5b9942f2e95049ee2eb36c4a5=(SInt32)(((UInt32)
(SInt32)(((UInt32)FARSp_rMixtAutIgPrvtSpGas)<<12))-
z442959254be3a5431636932a86c05be0);F__I64MULU32I32((UInt32)
z7955d83d064f5a82bcbb65330ef0d5f8,z9a770ea5b9942f2e95049ee2eb36c4a5,&(
z1f8568e2a312eeded13d6e88817fdf9c),&(zcf8c1dcf09c7e455cb239c5fc102b1bb));
z1a9f74cb3842a296b706b53995cd97a3=C__I32SHRI64C6_LT32(
z1f8568e2a312eeded13d6e88817fdf9c,zcf8c1dcf09c7e455cb239c5fc102b1bb,7,25);
zd444ba085a84c05909ad835a444409d5=(SInt32)(z1a9f74cb3842a296b706b53995cd97a3+
z442959254be3a5431636932a86c05be0);FARSp_rMixtAutIgPrvtSp=C__U32SATI32_SATb(
zd444ba085a84c05909ad835a444409d5,251658240,0);FARSp_rMixtAgIgMinProtSp_out=
FARSp_rMixtAgIgMinProtSp_irv_MP;z92e93f138d30aabaa60a1b7438fba5d8=
FARSp_rMixtLoTqReqSp;FARSp_rMixtLoTqReqSp_out=z92e93f138d30aabaa60a1b7438fba5d8;
z8e51e4591fcc685001532289e452bd62=(UInt32)(FARSp_rMixtAutIgPrvtSp>>12);
z8420b44dd79bd31ee4b28b6c679fc3fa=C__U16SATU32_SATu(
z8e51e4591fcc685001532289e452bd62,61440);FARSp_rMixtAutIgPrvtSp_out=
z8420b44dd79bd31ee4b28b6c679fc3fa;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_016_FctVarInit(Void){FARSp_rMixtAgIgMinProtRaw=0;
FARSp_rMixtAutIgPrvtSp_out=4096;FARSp_rMixtLoTqReqSpGsl=0;
FARSp_rMixtLoTqReqSpRaw=0;z2d69cf511cf23dc92f1411a339a36913=0;
z4ca1a21de06a80f4ab646c96e2236b18=0;z65c86d978e87cbf8e300288ccf8f134f=0;
z7c2d969271b69d2714756281e572a835=0;z4b987e4cca964cc34f0c0ab5506628d0=0;
zb8b903ca5d2fd20f22a706cefb284a08=0;zbe1806616b35957a3de9ed9600f705b4=0;
z85b4de0afd7459edfd9c727bccee4b73=0;z12cc4285fb303a9b7c06833deffd8116=0;
z96f75a46fd8f8fdc8549f271be8705f6=0;z99e8c3f07e2fae12c2b8e70b60d30ca4=0;
z2625f809e83b5ce062d394d64aca7888=0;zb681f194967361f721269596957c08ce=0;
ze51ac887a5af13fd36026ee7f90441f2=0;z3717bd776864a5d4dadaf47b92e9dd7d=0;
zf6b92da356b451bf9b008464f529b3f4=0;z5fcc11ef7c78d95426b7e949d31fccc0=0;
zd4923cd98891831d0f672435e0a15e3c=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

