/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AdvSpT                                             */ 
/* !Description     : AdvSpT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AdvSpT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AdvSpT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M06-AdvSpT/5-SO$*/ 
/* $Revision::   1.6                                                         $*/ 
/* $Author::   adelvare                      $$Date::   17 Jan 2013 15:43:10 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AdvSpT_Version.h" 
#define AdvSpT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvSpT_MemMap.h" 
CONST(UInt8,ADVSPT_CONST) AdvSpT_ModuleVersion_Major_MP = (UInt8)ADVSPT_MAJOR_VERSION; 
CONST(UInt8,ADVSPT_CONST) AdvSpT_ModuleVersion_Minor_MP = (UInt8)ADVSPT_MINOR_VERSION; 
CONST(UInt8,ADVSPT_CONST) AdvSpT_ModuleVersion_Patch_MP = (UInt8)ADVSPT_PATCH_VERSION; 
#define AdvSpT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AdvSpT_MemMap.h" 
