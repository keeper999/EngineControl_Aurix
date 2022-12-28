/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : ExMGslT1                                             */ 
/* !Description     : ExMGslT1 Software Component                          */ 
/*                                                                            */ 
/* !Module          : ExMGslT1                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : ExMGslT1_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M06-ExMGslT1/5-S$*/ 
/* $Revision::   1.2                                                         $*/ 
/* $Author::   adelvare                      $$Date::   29 Jun 2012 14:28:52 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "ExMGslT1_Version.h" 
#define ExMGslT1_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "ExMGslT1_MemMap.h" 

CONST(UInt8,EXMGSLT1_CONST) ExMGslT1_ModuleVersion_Major_MP = (UInt8)EXMGSLT1_MAJOR_VERSION; 
CONST(UInt8,EXMGSLT1_CONST) ExMGslT1_ModuleVersion_Minor_MP = (UInt8)EXMGSLT1_MINOR_VERSION; 
CONST(UInt8,EXMGSLT1_CONST) ExMGslT1_ModuleVersion_Patch_MP = (UInt8)EXMGSLT1_PATCH_VERSION; 
#define ExMGslT1_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "ExMGslT1_MemMap.h" 
