/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : TrbActGsl                                             */ 
/* !Description     : TrbActGsl Software Component                          */ 
/*                                                                            */ 
/* !Module          : TrbActGsl                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : TrbActGsl_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M15-TrbActGsl/5-$*/ 
/* $Revision::   1.2                                                         $*/ 
/* $Author::   adelvare                      $$Date::   07 Sep 2012 11:14:44 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "TrbActGsl_Version.h" 
#define TrbActGsl_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "TrbActGsl_MemMap.h" 
CONST(UInt8,TRBACTGSL_CONST) TrbActGsl_ModuleVersion_Major_MP = (UInt8)TRBACTGSL_MAJOR_VERSION; 
CONST(UInt8,TRBACTGSL_CONST) TrbActGsl_ModuleVersion_Minor_MP = (UInt8)TRBACTGSL_MINOR_VERSION; 
CONST(UInt8,TRBACTGSL_CONST) TrbActGsl_ModuleVersion_Patch_MP = (UInt8)TRBACTGSL_PATCH_VERSION; 
#define TrbActGsl_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "TrbActGsl_MemMap.h" 
