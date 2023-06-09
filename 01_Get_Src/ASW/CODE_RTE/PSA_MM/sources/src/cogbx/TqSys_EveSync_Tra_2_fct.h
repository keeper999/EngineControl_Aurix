/**************************************************************************************************\
 *** 
 ***                            P. C. A.
 *** 
 ***                     Peugeot Citroen Automobile
 *** 
 ***         This file is the property of PCA. All rights are reserved
 ***         by PCA and this file must not be copied or disclosed
 ***        (in whole or in part) without prior written consent of PCA.
 *** 
 *** *******************************************************************************
 *** 
 ***  %name: TqSys_EveSync_Tra_2_fct.h %
 *** 
 ***  %version: 11.0.build4 %
 *** 
 ***  %date_modified: Fri Apr 26 10:29:19 2013 %
 *** 
 *** 
 ***  %derived_by: u383015 %
 ***  %release: TqStruct/10.1 %
 ***  %full_filespec: TqSys_EveSync_Tra_2_fct.h-11.0.build4:incl:3 %
 *** 
 *** *******************************************************************************
 *** 
 *** Simulink model       : CSMT_CGMT06_2096
 *** TargetLink subsystem : CSMT_CGMT06_2096/F0_CSMT_CGMT06_2096_V7_0
 *** Codefile             : tqsys_evesync_tra_2_fct.h
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2013-04-24 15:16:51
 ***
 *** CODE GENERATOR OPTIONS:
 *** Compiler                            : <unknown>
 *** Target                              : Generic
 *** ANSI-C compatible code              : yes
 *** Optimization level                  : 2
 *** Constant style                      : decimal
 *** Clean code option                   : enabled
 *** Logging mode                        : Do not log anything
 *** Linker sections                     : enabled
 *** Assembler statements                : disabled
 *** Variable name length                : 31 chars
 *** Use global bitfields                : disabled
 *** Stateflow: use of bitfields         : enabled
 *** State activity encoding limit       : 5
 *** Omit zero inits in restart function : disabled
 *** Share fcns between TL subsystems    : enabled
 *** Generate 64bit functions            : enabled
 *** Inlining Threshold                  : 6
 *** Line break limit                    : 100
 *** Target optimized boolean data type  : enabled
 *** Keep saturation elements            : disabled
 *** Extended variable sharing           : enabled
 *** Style definition file               : C:\Dspace301\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\Dspace301\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSource
 ***                                       CodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _TQSYS_EVESYNC_TRA_2_FCT_H_
#define _TQSYS_EVESYNC_TRA_2_FCT_H_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
#define COGBX_START_SEC_VAR_UNSPECIFIED
#include "CoGBx_MemMap.h"
struct tag_SBFS_Activation_Detection_Validation2_2096_tp {
   unsigned int C209622_Valid2 : 1;
   unsigned int C209623_Invalid2 : 1;
}; /* Type of structure containing bitfields for Stateflow chart  */
struct tag_SBFS_Activation_Detection_Validation3_2096_tp {
   unsigned int C209625_Valid3 : 1;
   unsigned int C209626_Invalid3 : 1;
}; /* Type of structure containing bitfields for Stateflow chart  */
struct tag_SBFS_Activation_Detection_Validation_2096_tp {
   unsigned int C209628_Valid : 1;
   unsigned int C209629_Invalid : 1;
}; /* Type of structure containing bitfields for Stateflow chart  */
struct tag_SBFS_Overshoot_Control_2096_tp {
   unsigned int C209630_Overshoot_Control_ns : 3;
}; /* Type of structure containing bitfields for Stateflow chart  */
#define COGBX_STOP_SEC_VAR_UNSPECIFIED
#include "CoGBx_MemMap.h"
/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

/******************************************************************************\
   UserSFGlobal: SFGlobal = { ref_GlobalInit } | Width: N.A.
\******************************************************************************/
#define COGBX_START_SEC_VAR_UNSPECIFIED
#include "CoGBx_MemMap.h"
extern struct tag_SBFS_Activation_Detection_Validation_2096_tp SBFS_Activatio__Validation_2096 /* De
   scription: Structure containing bitfields for Stateflow chart  */;

extern struct tag_SBFS_Activation_Detection_Validation2_2096_tp SBFS_Activatio__alidation2_2096 /* D
   escription: Structure containing bitfields for Stateflow chart  */;

extern struct tag_SBFS_Activation_Detection_Validation3_2096_tp SBFS_Activatio__alidation3_2096 /* D
   escription: Structure containing bitfields for Stateflow chart  */;

extern struct tag_SBFS_Overshoot_Control_2096_tp SBFS_Overshoot_Control_2096 /* Description: Structu
   re containing bitfields for Stateflow chart  */;
#define COGBX_STOP_SEC_VAR_UNSPECIFIED
#include "CoGBx_MemMap.h"

/******************************************************************************\
   UserSFGlobalInit: SFGlobalInit = { ref_GlobalInit } | Width: 8
\******************************************************************************/
#define COGBX_START_SEC_VAR_BOOLEAN
#include "CoGBx_MemMap.h"
extern Boolean C209621_TqDem_bGearRatCdnVld2 /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern Boolean C209624_TqDem_bGearRatCdnVld3 /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern Boolean C209627_TqDem_bGearRatCdnVld /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
#define COGBX_STOP_SEC_VAR_BOOLEAN
#include "CoGBx_MemMap.h"

#define COGBX_START_SEC_VAR_8BIT
#include "CoGBx_MemMap.h"
extern UInt8 C209621_TqDem_tiGearRatCntVld2 /* LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2.55 */;
extern UInt8 C209624_TqDem_tiGearRatCntVld3 /* LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2.55 */;
extern UInt8 C209630_TqDem___earRatOverNRise /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern UInt8 C209630_TqDem_stOverNRise /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 4 */;
extern UInt8 C209630_TqDem_tiCntPed /* LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2.55 */;
extern UInt8 C209630_TqDem_tiLimTranGearRat /* LSB: 0.01 OFF:  0 MIN/MAX:  0 .. 2.55 */;
#define COGBX_STOP_SEC_VAR_8BIT
#include "CoGBx_MemMap.h"

/******************************************************************************\
   UserSLGlobalInit: SLGlobalInit = { ref_GlobalInit } | Width: 32
\******************************************************************************/
#define COGBX_START_SEC_VAR_32BIT
#include "CoGBx_MemMap.h"
extern UInt32 X_S2096101_Unit_Delay2 /* LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 4294967.295 */;
extern UInt32 X_S209693_Unit_Delay2 /* LSB: 0.001 OFF:  0 MIN/MAX:  0 .. 4294967.295 */;
#define COGBX_STOP_SEC_VAR_32BIT
#include "CoGBx_MemMap.h"
/******************************************************************************\
   UserSLGlobalInit: SLGlobalInit = { ref_GlobalInit } | Width: 16
\******************************************************************************/
#define COGBX_START_SEC_VAR_16BIT
#include "CoGBx_MemMap.h"
extern SInt16 X_S209683_UnitDelay /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209683_UnitDelay1 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209683_UnitDelay2 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209683_UnitDelay3 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209683_UnitDelay4 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209683_UnitDelay5 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209685_Unit_Delay /* LSB: 2^-4 OFF:  0 MIN/MAX:  -100 .. 510 */;
extern SInt16 X_S209690_Unit_Delay /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209690_Unit_Delay1 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209690_Unit_Delay2 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209690_Unit_Delay3 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209690_Unit_Delay4 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209690_Unit_Delay5 /* LSB: 2^-4 OFF:  0 MIN/MAX:  -2048 .. 2047.9375 */;
extern SInt16 X_S209691_Unit_Delay /* LSB: 2^-2 OFF:  0 MIN/MAX:  -8192 .. 8191.75 */;
extern SInt16 X_S209691_Unit_Delay1 /* LSB: 2^-2 OFF:  0 MIN/MAX:  -8192 .. 8191.75 */;
extern SInt16 X_S209691_Unit_Delay2 /* LSB: 2^-2 OFF:  0 MIN/MAX:  -8192 .. 8191.75 */;
extern SInt16 X_S209691_Unit_Delay3 /* LSB: 2^-2 OFF:  0 MIN/MAX:  -8192 .. 8191.75 */;
extern SInt16 X_S209691_Unit_Delay4 /* LSB: 2^-2 OFF:  0 MIN/MAX:  -8192 .. 8191.75 */;
extern SInt16 X_S209691_Unit_Delay5 /* LSB: 2^-2 OFF:  0 MIN/MAX:  -8192 .. 8191.75 */;
#define COGBX_STOP_SEC_VAR_16BIT
#include "CoGBx_MemMap.h"
/******************************************************************************\
   UserSLGlobalInit: SLGlobalInit = { ref_GlobalInit } | Width: 8
\******************************************************************************/
#define COGBX_START_SEC_VAR_BOOLEAN
#include "CoGBx_MemMap.h"
extern Boolean X_S2096100_UnitDelay;
extern Boolean X_S2096106_UnitDelay;
extern Boolean X_S2096107_Unit_Delay1;
extern Boolean X_S2096107_Unit_Delay2;
#define COGBX_STOP_SEC_VAR_BOOLEAN
#include "CoGBx_MemMap.h"

#define COGBX_START_SEC_VAR_8BIT
#include "CoGBx_MemMap.h"
extern UInt8 X_S209686_Unit_Delay;
extern UInt8 X_S209687_Unit_Delay;
#define COGBX_STOP_SEC_VAR_8BIT
#include "CoGBx_MemMap.h"

#define COGBX_START_SEC_GLOBAL_16BIT
#include "CoGBx_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
extern AR_IF_GLOBAL_16BIT SInt16 TqSys_EveSync_Tra_TqDem_rPedPrssGrd_irv_in /* 
   Unit       : N.m
   Description: La deriv�e de la position p�dale
   LSB: 2^0 OFF:  0 MIN/MAX:  -10000 .. 10000 */;
extern AR_IF_GLOBAL_16BIT SInt16 TqSys_EveSync_Tra_TqDem_tqTqRealSyncFuseMv_irv_out /* 
   Unit       : -
   Description: Moyenne glissante du couple r�el synchronis� et correl�
   LSB: 2^-4 OFF:  0 MIN/MAX:  -2000 .. 2000 */;

#define COGBX_STOP_SEC_GLOBAL_16BIT
#include "CoGBx_MemMap.h"

#define COGBX_START_SEC_GLOBAL_BOOLEAN
#include "CoGBx_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
extern AR_IF_GLOBAL_BOOLEAN Boolean TqSys_EveSync_Tra_TqDem_bGearRatCdnVld1_irv_in /* 
   Description: Validation de la premi�re condition d activation de d�tection d overshoot
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
extern AR_IF_GLOBAL_BOOLEAN Boolean TqSys_EveSync_Tra_TqDem_stGearRatOverNRise_irv_out /* 
   Description: Variable utilis�e pour d�tecter l'overshoot
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define COGBX_STOP_SEC_GLOBAL_BOOLEAN
#include "CoGBx_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/******************************************************************************\
   AR_GLOBAL_FCN: Function class
\******************************************************************************/
extern Void TqSys_EveSync_Tra_2_fct(Void);


#endif/*_TQSYS_EVESYNC_TRA_2_FCT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
