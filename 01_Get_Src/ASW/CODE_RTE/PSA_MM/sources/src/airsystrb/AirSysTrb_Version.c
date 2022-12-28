/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AirSysTrb                                             */ 
/* !Description     : AirSysTrb Software Component                          */ 
/*                                                                            */ 
/* !Module          : AirSysTrb                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AirSysTrb_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M18-AirSysTrb/5-$*/ 
/* $Revision::   1.1                                                         $*/ 
/* $Author::   ADELVARE                      $$Date::   14 Jan 2011 14:46:18 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AirSysTrb_Version.h" 
#define AirSysTrb_START_SEC_CONST_8BIT 
#include "AirSysTrb_MemMap.h" 
CONST(UInt8,AIRSYSTRB_CONST) AirSysTrb_ModuleVersion_Major_MP = (UInt8)AIRSYSTRB_MAJOR_VERSION; 
CONST(UInt8,AIRSYSTRB_CONST) AirSysTrb_ModuleVersion_Minor_MP = (UInt8)AIRSYSTRB_MINOR_VERSION; 
CONST(UInt8,AIRSYSTRB_CONST) AirSysTrb_ModuleVersion_Patch_MP = (UInt8)AIRSYSTRB_PATCH_VERSION; 
#define AirSysTrb_STOP_SEC_CONST_8BIT 
#include "AirSysTrb_MemMap.h" 
