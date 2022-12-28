/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : EngMGslT                                             */ 
/* !Description     : EngMGslT Software Component                          */ 
/*                                                                            */ 
/* !Module          : EngMGslT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : EngMGslT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M05-EngMGslT/5-S$*/ 
/* $Revision::   1.2                                                         $*/ 
/* $Author::   adelvare                      $$Date::   31 May 2012 17:11:42 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "EngMGslT_Version.h" 
#define EngMGslT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "EngMGslT_MemMap.h" 

CONST(UInt8,ENGMGSLT_CONST) EngMGslT_ModuleVersion_Major_MP = (UInt8)ENGMGSLT_MAJOR_VERSION; 
CONST(UInt8,ENGMGSLT_CONST) EngMGslT_ModuleVersion_Minor_MP = (UInt8)ENGMGSLT_MINOR_VERSION; 
CONST(UInt8,ENGMGSLT_CONST) EngMGslT_ModuleVersion_Patch_MP = (UInt8)ENGMGSLT_PATCH_VERSION; 
#define EngMGslT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "EngMGslT_MemMap.h" 
