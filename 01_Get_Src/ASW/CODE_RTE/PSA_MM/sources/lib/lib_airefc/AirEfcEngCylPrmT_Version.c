/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AirEfcEngCylPrmT                                             */ 
/* !Description     : AirEfcEngCylPrmT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AirEfcEngCylPrmT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AirEfcEngCylPrmT_Version.c                                   */ 
/*                                                                            */ 
/* !Target          : All (optimized for "Generic->Custom")                   */ 
/*                                                                            */ 
/* !Vendor          : Valeo                                                   */ 
/*                                                                            */ 
/* Coding language  : C                                                       */ 
/*                                                                            */ 
/* COPYRIGHT 2008 VALEO                                                       */ 
/* all rights reserved                                                        */ 
/******************************************************************************/ 
/* PVCS Information                                                           */ 
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M04-AirEfcEngCyl$*/ 
/* $Revision::   1.1                                                         $*/ 
/* $Author::   adelvare                      $$Date::   29 May 2012 17:25:42 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AirEfcEngCylPrmT_Version.h" 
#define AirEfcEngCylPrmT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AirEfcEngCylPrmT_MemMap.h" 
CONST(UInt8,AIREFCENGCYLPRMT_CONST) AirEfcEngCylPrmT_ModuleVersion_Major_MP = (UInt8)AIREFCENGCYLPRMT_MAJOR_VERSION; 
CONST(UInt8,AIREFCENGCYLPRMT_CONST) AirEfcEngCylPrmT_ModuleVersion_Minor_MP = (UInt8)AIREFCENGCYLPRMT_MINOR_VERSION; 
CONST(UInt8,AIREFCENGCYLPRMT_CONST) AirEfcEngCylPrmT_ModuleVersion_Patch_MP = (UInt8)AIREFCENGCYLPRMT_PATCH_VERSION; 
#define AirEfcEngCylPrmT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AirEfcEngCylPrmT_MemMap.h" 
