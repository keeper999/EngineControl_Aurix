/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AirSysAir                                             */ 
/* !Description     : AirSysAir Software Component                          */ 
/*                                                                            */ 
/* !Module          : AirSysAir                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AirSysAir_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M17-AirSysAir/5-$*/ 
/* $Revision::   1.3                                                         $*/ 
/* $Author::   adelvare                      $$Date::   24 Jul 2012 15:53:40 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AirSysAir_Version.h" 
#define AirSysAir_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AirSysAir_MemMap.h" 
CONST(UInt8,AIRSYSAIR_CONST) AirSysAir_ModuleVersion_Major_MP = (UInt8)AIRSYSAIR_MAJOR_VERSION; 
CONST(UInt8,AIRSYSAIR_CONST) AirSysAir_ModuleVersion_Minor_MP = (UInt8)AIRSYSAIR_MINOR_VERSION; 
CONST(UInt8,AIRSYSAIR_CONST) AirSysAir_ModuleVersion_Patch_MP = (UInt8)AIRSYSAIR_PATCH_VERSION; 
#define AirSysAir_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AirSysAir_MemMap.h" 
