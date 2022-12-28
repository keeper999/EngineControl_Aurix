/********************************** <HEADER> **********************************/ 
/*                                                                            */ 
/* !Layer           : SWC Layer                                               */ 
/*                                                                            */ 
/* !Component       : InMdlT                                             */ 
/* !Description     : InMdlT Software Component                          */ 
/*                                                                            */ 
/* !Module          : InMdlT                                             */ 
/* !Description     : Version file                                             */ 
/*                                                                            */ 
/* !File            : InMdlT_Version.c                                   */ 
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M02-InMdlT/5-SOF$*/ 
/* $Revision::   1.1                                                         $*/ 
/* $Author::   adelvare                      $$Date::   04 Jun 2012 14:40:08 $*/ 
/******************************************************************************/ 
#include "Rte_Type.h" 
#include "InMdlT_Version.h" 
#define InMdlT_START_SEC_CONST_VERSION_MODULE_8BIT 
#include "InMdlT_MemMap.h" 

CONST(UInt8,INMDLT_CONST) InMdlT_ModuleVersion_Major_MP = (UInt8)INMDLT_MAJOR_VERSION; 
CONST(UInt8,INMDLT_CONST) InMdlT_ModuleVersion_Minor_MP = (UInt8)INMDLT_MINOR_VERSION; 
CONST(UInt8,INMDLT_CONST) InMdlT_ModuleVersion_Patch_MP = (UInt8)INMDLT_PATCH_VERSION; 
#define InMdlT_STOP_SEC_CONST_VERSION_MODULE_8BIT 
#include "InMdlT_MemMap.h" 
