/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : EngMGslLim                                             */ 
/* !Description     : EngMGslLim Software Component                          */ 
/*                                                                            */ 
/* !Module          : EngMGslLim                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : EngMGslLim_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M16-EngMGslLim/5$*/ 
/* $Revision::   1.1                                                         $*/ 
/* $Author::   adelvare                      $$Date::   10 Dec 2012 11:56:50 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "EngMGslLim_Version.h" 
#define EngMGslLim_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "EngMGslLim_MemMap.h" 
CONST(UInt8,ENGMGSLLIM_CONST) EngMGslLim_ModuleVersion_Major_MP = (UInt8)ENGMGSLLIM_MAJOR_VERSION; 
CONST(UInt8,ENGMGSLLIM_CONST) EngMGslLim_ModuleVersion_Minor_MP = (UInt8)ENGMGSLLIM_MINOR_VERSION; 
CONST(UInt8,ENGMGSLLIM_CONST) EngMGslLim_ModuleVersion_Patch_MP = (UInt8)ENGMGSLLIM_PATCH_VERSION; 
#define EngMGslLim_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "EngMGslLim_MemMap.h" 
