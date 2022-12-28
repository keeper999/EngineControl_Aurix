/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : UsThrMT                                             */ 
/* !Description     : UsThrMT Software Component                          */ 
/*                                                                            */ 
/* !Module          : UsThrMT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : UsThrMT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M01-UsThrMT/5-SO$*/ 
/* $Revision::   1.1                                                         $*/ 
/* $Author::   adelvare                      $$Date::   03 Oct 2012 17:20:50 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "UsThrMT_Version.h" 
#define UsThrMT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "UsThrMT_MemMap.h" 
CONST(UInt8,USTHRMT_CONST) UsThrMT_ModuleVersion_Major_MP = (UInt8)USTHRMT_MAJOR_VERSION; 
CONST(UInt8,USTHRMT_CONST) UsThrMT_ModuleVersion_Minor_MP = (UInt8)USTHRMT_MINOR_VERSION; 
CONST(UInt8,USTHRMT_CONST) UsThrMT_ModuleVersion_Patch_MP = (UInt8)USTHRMT_PATCH_VERSION; 
#define UsThrMT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "UsThrMT_MemMap.h" 
