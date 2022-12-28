/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AdvMinT                                             */ 
/* !Description     : AdvMinT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AdvMinT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AdvMinT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M02-AdvMinT/5-S$*/ 
/* $Revision::   1.3                                                         $*/ 
/* $Author::   adelvare                      $$Date::   24 Jul 2012 17:12:36 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AdvMinT_Version.h" 
#define AdvMinT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvMinT_MemMap.h" 
CONST(UInt8,ADVMINT_CONST) AdvMinT_ModuleVersion_Major_MP = (UInt8)ADVMINT_MAJOR_VERSION; 
CONST(UInt8,ADVMINT_CONST) AdvMinT_ModuleVersion_Minor_MP = (UInt8)ADVMINT_MINOR_VERSION; 
CONST(UInt8,ADVMINT_CONST) AdvMinT_ModuleVersion_Patch_MP = (UInt8)ADVMINT_PATCH_VERSION; 
#define AdvMinT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvMinT_MemMap.h" 
