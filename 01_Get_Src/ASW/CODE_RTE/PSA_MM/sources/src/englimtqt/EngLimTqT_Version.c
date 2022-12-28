/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : EngLimTqT                                             */ 
/* !Description     : EngLimTqT Software Component                          */ 
/*                                                                            */ 
/* !Module          : EngLimTqT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : EngLimTqT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M01-EngLimTqT/5$*/ 
/* $Revision::   1.4                                                         $*/ 
/* $Author::   adelvare                      $$Date::   24 Jul 2012 14:14:06 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "EngLimTqT_Version.h" 
#define EngLimTqT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "EngLimTqT_MemMap.h" 
CONST(UInt8,ENGLIMTQT_CONST) EngLimTqT_ModuleVersion_Major_MP = (UInt8)ENGLIMTQT_MAJOR_VERSION; 
CONST(UInt8,ENGLIMTQT_CONST) EngLimTqT_ModuleVersion_Minor_MP = (UInt8)ENGLIMTQT_MINOR_VERSION; 
CONST(UInt8,ENGLIMTQT_CONST) EngLimTqT_ModuleVersion_Patch_MP = (UInt8)ENGLIMTQT_PATCH_VERSION; 
#define EngLimTqT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "EngLimTqT_MemMap.h" 
