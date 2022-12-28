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
* %name: FARSp_002_TEV_fct.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:46 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_002_TEV_fct.c-3.0:csrc:5 %
*
*******************************************************************************/


#ifndef _FARSP_002_TEV_FCT_C_
#define _FARSP_002_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_002_TEV_fct.h"
#include "FARSp_002_calibrations.h"
#include "dsfxp.h"
#include "FARSp_calibrations.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE002_EngM_mfAirCor_in;AR_IF_GLOBAL_16BIT UInt16
 FARSp_RE002_EngM_mfAirScvCor_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE002_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT UInt16 FARSp_RE002_Ext_nEng_in;
AR_IF_GLOBAL_16BIT UInt16 FARSp_rMixtBasSp_out;AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtScvExAfs_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE002_Ext_stTypInjSysCf_in;
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bAcvAflScvGDI_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z1c155195391733ea26853e5eddeaafd1;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z8f0d51c699f6e0186d648af974bc512f;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 zbff10dbca11e1bccd6da60376722d3a3;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
static UInt32 z2d1ede864293834484411868eddf6fec;static UInt32 
z7548c1daa7caaa1dd0f4f1f52296d9ee;
#define FARSP_STOP_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
static Boolean zbdb399ceb642087db1ee08dc3c4b5ed0;static Boolean 
zcfb05c41ee2f81f31df908fa99150ba0;static Boolean 
z63485aedeb36be0ceed8ef8926d66353;static Boolean 
zd24d05ebe26a005f22d23c21cdec1529;static Boolean 
zae77198195b32e72dc5111896b808e49;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 z09326ad33e3bc4d748009b148200ac21;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_001_MSE_ini(Void){FARSp_002_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_002_TEV_fct(Void){UInt32 z0ea8a64c788fe9b3a01f64f384e72135;UInt32 
z39e23785225f522c2e9bed7efa024bd5;UInt16 z6adfb973b7a427376a8957c8a3dfdab0;
Boolean z9116111e52851879ed46249877f53b57;Boolean 
z83eb07749d831d9b1acbbe5ab710291c;UInt32 z21fed86397a19bfad54bda2cfdaa9d19;
UInt32 z598fc83d17c7afbb99b61c2115312c40;TabIdxS50T513((const UInt16*)
FARSp_nEngAirLdThdAflScv_A,8,FARSp_RE002_Ext_nEng_in,&(
z09326ad33e3bc4d748009b148200ac21),&(zbff10dbca11e1bccd6da60376722d3a3));
z1c155195391733ea26853e5eddeaafd1=Tab1DIntp2I1T65((const UInt16*)
FARSp_rAirLdThdAflScv_T,z09326ad33e3bc4d748009b148200ac21,
zbff10dbca11e1bccd6da60376722d3a3);if(zae77198195b32e72dc5111896b808e49){Boolean
 zd4151b130e3b0d46a23ac6f506a2907b;Boolean zd5a643ec6fc0240692cd61cccd29e939;
zd4151b130e3b0d46a23ac6f506a2907b=FARSp_RE002_EngM_rAirLdCor_in>=
z1c155195391733ea26853e5eddeaafd1;zd5a643ec6fc0240692cd61cccd29e939=((SInt32)
FARSp_RE002_EngM_rAirLdCor_in)<=((SInt32)(((UInt32)
z1c155195391733ea26853e5eddeaafd1)-((UInt32)FARSp_rAirLdThdAflScvHys_C)));
z83eb07749d831d9b1acbbe5ab710291c=(zd4151b130e3b0d46a23ac6f506a2907b&&(!(
zd5a643ec6fc0240692cd61cccd29e939)))||((!(zd4151b130e3b0d46a23ac6f506a2907b))&&(
!(zd5a643ec6fc0240692cd61cccd29e939))&&zd24d05ebe26a005f22d23c21cdec1529);}else{
z83eb07749d831d9b1acbbe5ab710291c=0;}z9116111e52851879ed46249877f53b57=
FARSp_RE002_EngM_mfAirCor_in!=0;if(z9116111e52851879ed46249877f53b57){if(
FARSp_RE002_EngM_mfAirCor_in!=0){UInt32 ze84bbf5804a061df0ddc77007b0965b7;
ze84bbf5804a061df0ddc77007b0965b7=((UInt32)FARSp_RE002_EngM_mfAirScvCor_in)+((
UInt32)FARSp_RE002_EngM_mfAirCor_in);C__U64SHLU32C6_LT32(
ze84bbf5804a061df0ddc77007b0965b7,16,16,z21fed86397a19bfad54bda2cfdaa9d19,
z598fc83d17c7afbb99b61c2115312c40);C__U32DIVU64U32(
z21fed86397a19bfad54bda2cfdaa9d19,z598fc83d17c7afbb99b61c2115312c40,(UInt32)
FARSp_RE002_EngM_mfAirCor_in,z2d1ede864293834484411868eddf6fec);}else{
z2d1ede864293834484411868eddf6fec=4294967295U;}}if(
z9116111e52851879ed46249877f53b57){z0ea8a64c788fe9b3a01f64f384e72135=
z2d1ede864293834484411868eddf6fec;}else{z0ea8a64c788fe9b3a01f64f384e72135=65536;
}z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)(z0ea8a64c788fe9b3a01f64f384e72135>>4
);FARSp_rMixtScvExAfs=C__U16SATU32_SATu(z21fed86397a19bfad54bda2cfdaa9d19,61440)
;FARSp_bAcvAflScvGDI=z83eb07749d831d9b1acbbe5ab710291c;if(
z83eb07749d831d9b1acbbe5ab710291c&&(!(zbdb399ceb642087db1ee08dc3c4b5ed0))){
z39e23785225f522c2e9bed7efa024bd5=(UInt32)(((UInt32)
z8f0d51c699f6e0186d648af974bc512f)<<2);}else{UInt32 
zdaa362bd58658b42f72ea1c5c0e3634c;UInt16 z4de83d1791a351205f18c25301b94591;if(
FARSp_facFilBasAfs_C){z4de83d1791a351205f18c25301b94591=FARSp_facFilBasAfs_C;}
else{z4de83d1791a351205f18c25301b94591=0;}if(z63485aedeb36be0ceed8ef8926d66353){
zdaa362bd58658b42f72ea1c5c0e3634c=z7548c1daa7caaa1dd0f4f1f52296d9ee;}else{
zdaa362bd58658b42f72ea1c5c0e3634c=(UInt32)(((UInt32)
z8f0d51c699f6e0186d648af974bc512f)<<2);}F__U64MULU32U32((UInt32)(UInt16)(((
UInt16)(-z4de83d1791a351205f18c25301b94591))+16384),
zdaa362bd58658b42f72ea1c5c0e3634c,&(z21fed86397a19bfad54bda2cfdaa9d19),&(
z598fc83d17c7afbb99b61c2115312c40));z39e23785225f522c2e9bed7efa024bd5=((UInt32)
z4de83d1791a351205f18c25301b94591)+C__U32SHRU64C6_LT32(
z21fed86397a19bfad54bda2cfdaa9d19,z598fc83d17c7afbb99b61c2115312c40,14,18);}if(
z83eb07749d831d9b1acbbe5ab710291c){UInt16 z2c7f6793e84c148a61636804ebcda638;if(
zcfb05c41ee2f81f31df908fa99150ba0){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)(
z39e23785225f522c2e9bed7efa024bd5>>2);z2c7f6793e84c148a61636804ebcda638=
C__U16SATU32_SATu(z21fed86397a19bfad54bda2cfdaa9d19,61440);}else{
z2c7f6793e84c148a61636804ebcda638=z8f0d51c699f6e0186d648af974bc512f;}if(
z2c7f6793e84c148a61636804ebcda638<=FARSp_rMixtAfsTran_C){
z6adfb973b7a427376a8957c8a3dfdab0=4096;}else{z6adfb973b7a427376a8957c8a3dfdab0=
z2c7f6793e84c148a61636804ebcda638;}}else{z6adfb973b7a427376a8957c8a3dfdab0=
FARSp_rMixtScvExAfs;}if(FARSp_RE002_Ext_stTypInjSysCf_in==0){FARSp_rMixtBasSp=
4096;}else{FARSp_rMixtBasSp=z6adfb973b7a427376a8957c8a3dfdab0;}
zae77198195b32e72dc5111896b808e49=1;zd24d05ebe26a005f22d23c21cdec1529=
z83eb07749d831d9b1acbbe5ab710291c;zbdb399ceb642087db1ee08dc3c4b5ed0=
z83eb07749d831d9b1acbbe5ab710291c;z8f0d51c699f6e0186d648af974bc512f=
z6adfb973b7a427376a8957c8a3dfdab0;z63485aedeb36be0ceed8ef8926d66353=1;
z7548c1daa7caaa1dd0f4f1f52296d9ee=z39e23785225f522c2e9bed7efa024bd5;
zcfb05c41ee2f81f31df908fa99150ba0=1;FARSp_rMixtScvExAfs_out=FARSp_rMixtScvExAfs;
FARSp_bAcvAflScvGDI_out=FARSp_bAcvAflScvGDI;FARSp_rMixtBasSp_out=
FARSp_rMixtBasSp;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_002_FctVarInit(Void){FARSp_bAcvAflScvGDI_out=1;FARSp_rMixtBasSp_out=
4096;FARSp_rMixtScvExAfs_out=4096;z2d1ede864293834484411868eddf6fec=0;
zbff10dbca11e1bccd6da60376722d3a3=0;z09326ad33e3bc4d748009b148200ac21=0;
zbdb399ceb642087db1ee08dc3c4b5ed0=0;zcfb05c41ee2f81f31df908fa99150ba0=0;
z7548c1daa7caaa1dd0f4f1f52296d9ee=0;z63485aedeb36be0ceed8ef8926d66353=0;
z8f0d51c699f6e0186d648af974bc512f=4096;zd24d05ebe26a005f22d23c21cdec1529=0;
zae77198195b32e72dc5111896b808e49=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

