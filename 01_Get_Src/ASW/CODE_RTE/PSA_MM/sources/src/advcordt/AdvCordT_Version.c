/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AdvCordT                                             */ 
/* !Description     : AdvCordT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AdvCordT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AdvCordT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M07-AdvCordT/5-$*/ 
/* $Revision::   1.4                                                         $*/ 
/* $Author::   adelvare                      $$Date::   12 Jul 2012 11:42:32 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AdvCordT_Version.h" 
#define AdvCordT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvCordT_MemMap.h" 

CONST(UInt8,ADVCORDT_CONST) AdvCordT_ModuleVersion_Major_MP = (UInt8)ADVCORDT_MAJOR_VERSION; 
CONST(UInt8,ADVCORDT_CONST) AdvCordT_ModuleVersion_Minor_MP = (UInt8)ADVCORDT_MINOR_VERSION; 
CONST(UInt8,ADVCORDT_CONST) AdvCordT_ModuleVersion_Patch_MP = (UInt8)ADVCORDT_PATCH_VERSION; 
#define AdvCordT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvCordT_MemMap.h" 
