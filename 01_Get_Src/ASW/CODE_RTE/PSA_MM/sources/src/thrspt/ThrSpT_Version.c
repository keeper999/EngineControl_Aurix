/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : ThrSpT                                             */ 
/* !Description     : ThrSpT Software Component                          */ 
/*                                                                            */ 
/* !Module          : ThrSpT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : ThrSpT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M09-ThrSpT/5-SOF$*/ 
/* $Revision::   1.1                                                         $*/ 
/* $Author::   ADELVARE                      $$Date::   19 Jan 2011 14:32:36 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "ThrSpT_Version.h" 
#define ThrSpT_START_SEC_CONST_8BIT 
#include "ThrSpT_MemMap.h" 
CONST(UInt8,THRSPT_CONST) ThrSpT_ModuleVersion_Major_MP = (UInt8)THRSPT_MAJOR_VERSION; 
CONST(UInt8,THRSPT_CONST) ThrSpT_ModuleVersion_Minor_MP = (UInt8)THRSPT_MINOR_VERSION; 
CONST(UInt8,THRSPT_CONST) ThrSpT_ModuleVersion_Patch_MP = (UInt8)THRSPT_PATCH_VERSION; 
#define ThrSpT_STOP_SEC_CONST_8BIT 
#include "ThrSpT_MemMap.h" 
