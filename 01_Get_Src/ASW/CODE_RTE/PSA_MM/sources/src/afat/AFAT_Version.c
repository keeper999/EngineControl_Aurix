/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AFAT                                             */ 
/* !Description     : AFAT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AFAT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AFAT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/ 
/* $Revision::   1.2                                                         $*/ 
/* $Author::   adelvare                      $$Date::   21 Jul 2014 15:19:10 $*/ 
/******************************************************************************/ 
#include "AFAT_Version.h" 
#include "Rte_Type.h" 
#define AFAT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AFAT_MemMap.h" 
CONST(UInt8,AFAT_CONST) AFAT_ModuleVersion_Major_MP = (UInt8)AFAT_MAJOR_VERSION; 
CONST(UInt8,AFAT_CONST) AFAT_ModuleVersion_Minor_MP = (UInt8)AFAT_MINOR_VERSION; 
CONST(UInt8,AFAT_CONST) AFAT_ModuleVersion_Patch_MP = (UInt8)AFAT_PATCH_VERSION; 
#define AFAT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AFAT_MemMap.h" 
