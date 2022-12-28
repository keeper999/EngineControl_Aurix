/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : ExMGslT2                                             */ 
/* !Description     : ExMGslT2 Software Component                          */ 
/*                                                                            */ 
/* !Module          : ExMGslT2                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : ExMGslT2_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M06-ExMGslT2/5-S$*/ 
/* $Revision::   1.2                                                         $*/ 
/* $Author::   adelvare                      $$Date::   12 Jun 2012 16:23:02 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "ExMGslT2_Version.h" 
#define ExMGslT2_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "ExMGslT2_MemMap.h" 

CONST(UInt8,EXMGSLT2_CONST) ExMGslT2_ModuleVersion_Major_MP = (UInt8)EXMGSLT2_MAJOR_VERSION; 
CONST(UInt8,EXMGSLT2_CONST) ExMGslT2_ModuleVersion_Minor_MP = (UInt8)EXMGSLT2_MINOR_VERSION; 
CONST(UInt8,EXMGSLT2_CONST) ExMGslT2_ModuleVersion_Patch_MP = (UInt8)EXMGSLT2_PATCH_VERSION; 
#define ExMGslT2_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "ExMGslT2_MemMap.h" 
