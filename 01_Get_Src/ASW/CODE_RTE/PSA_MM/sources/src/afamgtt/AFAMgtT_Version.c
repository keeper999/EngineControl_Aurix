/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : AFAMgtT                                             */ 
/* !Description     : AFAMgtT Software Component                          */ 
/*                                                                            */ 
/* !Module          : AFAMgtT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : AFAMgtT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/ 
/* $Revision::   1.4                                                         $*/ 
/* $Author::   adelvare                      $$Date::   22 Aug 2013 10:42:02 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "AFAMgtT_Version.h" 
#define AFAMgtT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "AFAMgtT_MemMap.h" 
CONST(UInt8,AFAMGTT_CONST) AFAMgtT_ModuleVersion_Major_MP = (UInt8)AFAMGTT_MAJOR_VERSION; 
CONST(UInt8,AFAMGTT_CONST) AFAMgtT_ModuleVersion_Minor_MP = (UInt8)AFAMGTT_MINOR_VERSION; 
CONST(UInt8,AFAMGTT_CONST) AFAMgtT_ModuleVersion_Patch_MP = (UInt8)AFAMGTT_PATCH_VERSION; 
#define AFAMgtT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "AFAMgtT_MemMap.h" 
